//
//	$Id: sf_cipher.h,v 1.13 2006/07/10 08:56:00 ssosuny Exp $
//

#ifndef __SF_CIPHER_H__
#define __SF_CIPHER_H__

#include "sf_aes.h"
#include "sf_blowfish.h"
#include "sf_cast128.h"
#include "sf_des.h"
#include "sf_rc2.h"
#include "sf_rc4.h"
#include "sf_rc5.h"
#include "sf_seed.h"
#include "sf_skipjack.h"
#include "sf_tdes.h"
#include "sf_neat.h"
#include "sf_aria.h"

//2006-02-16 NES (대한주택공사)
#include "sf_nes.h"

/**
 *	Constants
 */

#define	SF_CIPHER_ID_AES					1
#define	SF_CIPHER_ID_BLOWFISH				2
#define	SF_CIPHER_ID_CAST128				3
#define	SF_CIPHER_ID_DES					4
#define SF_CIPHER_ID_RC2 					6
#define SF_CIPHER_ID_RC4 					7
#define SF_CIPHER_ID_RC5 					8
#define SF_CIPHER_ID_SEED					9
#define SF_CIPHER_ID_SKIPJACK				10
#define SF_CIPHER_ID_TDES					11
#define	SF_CIPHER_ID_ARIA					12
#define	SF_CIPHER_ID_NEAT					21
#define	SF_CIPHER_ID_NEAT_PENTA				22

//2006-02-16 NES (대한주택공사)
#define SF_CIPHER_ID_NES					31

#define	SF_CIPHER_DIR_ENCRYPT				0
#define	SF_CIPHER_DIR_DECRYPT				1

#define	SF_CIPHER_TYPE_STREAM				0
#define	SF_CIPHER_TYPE_BLOCK				1

#define	SF_CIPHER_MODE_ECB					1
#define	SF_CIPHER_MODE_CBC					2
#define	SF_CIPHER_MODE_CFB					3
#define	SF_CIPHER_MODE_OFB					4
#define	SF_CIPHER_MODE_CTR					5

#define	SF_CIPHER_PADDING_NO				1
#define	SF_CIPHER_PADDING_ZERO				2	// for CBCMAC
#define	SF_CIPHER_PADDING_HASH				3
#define	SF_CIPHER_PADDING_PKCS				4

#define	SF_CIPHER_MAX_KEY_SIZE				255	// RC5
#define	SF_CIPHER_MIN_KEY_SIZE				0	// RC5

//2006-07-10 by ssosuny
#define	SF_CIPHER_MAX_BLOCK_SIZE			32	// AES -> NES (32)
#define	SF_CIPHER_MAX_IV_SIZE				32	// AES -> NES (32)

/**
 *	Struct
 */

typedef struct {
	int			type;					// stream(0), block(1)
	SF_WORD		blockSize;
	SF_WORD		keyLength;				// default
	SF_WORD		minKeyLength;
	SF_WORD		maxKeyLength;
	SF_WORD		stepKeyLength;
} SF_CIPHER_INFO;

typedef union {
	struct {
		SF_WORD	effectiveBits;
	} rc2;
	struct {
		SF_WORD	rounds;
	} rc5;
} SF_CIPHER_SUITE_PARAM;

typedef struct {
	SF_BYTE		iv[SF_CIPHER_MAX_IV_SIZE];
	SF_WORD		ivLength;
	SF_WORD		modeSize;				// for CFB and OFB
} SF_CIPHER_MODE_PARAM;

typedef struct {
	SF_CIPHER_SUITE_PARAM	suiteParam;	// for RC2, RC5
	int			modeID;
	SF_CIPHER_MODE_PARAM	modeParam;	// for CBC, CFB, OFB
	int			paddingID;
} SF_CIPHER_PARAM;

typedef struct {
	int			cipherID;
	
	// infomation
	SF_CIPHER_INFO	info;
	// parameter
	SF_CIPHER_PARAM	param;

	// user key
	SF_BYTE		key[SF_CIPHER_MAX_KEY_SIZE];
	SF_WORD		keyLength;

	// cipher subkeys
	union {
//WIN32_CE
#ifndef _MIN_WCE
		SF_AES_KEY		aes;
		SF_BLOWFISH_KEY	blowfish;
		SF_CAST128_KEY	cast128;
		SF_SKIPJACK_KEY	skipjack;
#endif
		SF_ARIA_KEY		aria;
		SF_DES_KEY		des;
		SF_RC2_KEY		rc2;
		SF_RC4_KEY		rc4;
		SF_RC5_KEY		rc5;
		SF_SEED_KEY		seed;
		SF_TDES_KEY		tdes;
		SF_NEAT_KEY		neat;
//2006-07-10 by ssosuny
		SF_NES_KEY		nes;
	} cipherKey;

	// working buffer
	SF_BYTE		remain[SF_CIPHER_MAX_BLOCK_SIZE];
	SF_WORD		remainLength;
	
	SF_BYTE		last[SF_CIPHER_MAX_BLOCK_SIZE];
	SF_WORD		lastLength;
} SF_CIPHER_CTX;

/**
 *	Error codes
 */

//	SF_COMMON_ERROR_INVALID_INPUT
//
//	SF_CIPHER_ERROR_UNKNOWN_ID
//	SF_CIPHER_ERROR_UNKNOWN_MODE
//	SF_CIPHER_ERROR_UNKNOWN_PADDING
//	SF_CIPHER_ERROR_INVALID_PADDING
//	SF_CIPHER_ERROR_ENCRYPT_FAILED
//	SF_CIPHER_ERROR_DECRYPT_FAILED

/**
 *	Prototypes
 */

#ifdef __cplusplus
extern "C" {
#endif

SF_CIPHER_CTX *
			SF_Cipher_CTX_New				(void);

void		SF_Cipher_CTX_Free				(SF_CIPHER_CTX *ctx);

SF_ERROR	SF_Cipher_GetInfo				(SF_CIPHER_INFO *info, const int cipherID);

SF_ERROR	SF_Cipher_Encrypt_Init			(SF_CIPHER_CTX *ctx, 
											 const SF_BYTE *key, const SF_WORD keyLength,
											 const int cipherID, const SF_CIPHER_PARAM *param);

SF_ERROR	SF_Cipher_Encrypt_Update		(SF_CIPHER_CTX *ctx, 
											 SF_BYTE *output, SF_WORD *outputLength,
											 const SF_BYTE *input, const SF_WORD inputLength);

SF_ERROR	SF_Cipher_Encrypt_Final			(SF_CIPHER_CTX *ctx, 
											 SF_BYTE *output, SF_WORD *outputLength);

SF_ERROR	SF_Cipher_Encrypt				(SF_BYTE *output, SF_WORD *outputLength, 
											 const SF_BYTE *input, const SF_WORD inputLength,
											 const SF_BYTE *key, const SF_WORD keyLength,
											 const int cipherID, const SF_CIPHER_PARAM *param);

SF_ERROR	SF_Cipher_Decrypt_Init			(SF_CIPHER_CTX *ctx, 
											 const SF_BYTE *key, const SF_WORD keyLength,
											 const int cipherID, const SF_CIPHER_PARAM *param);

SF_ERROR	SF_Cipher_Decrypt_Update		(SF_CIPHER_CTX *ctx, 
											 SF_BYTE *output, SF_WORD *outputLength,
											 const SF_BYTE *input, const SF_WORD inputLength);

SF_ERROR	SF_Cipher_Decrypt_Final			(SF_CIPHER_CTX *ctx, SF_WORD *paddingLength);

SF_ERROR	SF_Cipher_Decrypt				(SF_BYTE *output, SF_WORD *outputLength, 
											 const SF_BYTE *input, const SF_WORD inputLength,
											 const SF_BYTE *key, const SF_WORD keyLength,
											 const int cipherID, const SF_CIPHER_PARAM *param);

#ifdef __cplusplus
}
#endif

#endif
