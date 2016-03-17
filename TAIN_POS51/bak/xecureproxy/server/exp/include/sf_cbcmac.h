//
//	sf_cbcmac.h
//

#ifndef __SF_CBCMAC_H__
#define __SF_CBCMAC_H__

#include "sf_cipher.h"

/**
 *	Constants
 */

#define	SF_CBCMAC_ID_AES					SF_CIPHER_ID_AES
#define	SF_CBCMAC_ID_BLOWFISH				SF_CIPHER_ID_BLOWFISH
#define	SF_CBCMAC_ID_CAST128				SF_CIPHER_ID_CAST128
#define	SF_CBCMAC_ID_DES					SF_CIPHER_ID_DES
#define SF_CBCMAC_ID_RC2					SF_CIPHER_ID_RC2
#define SF_CBCMAC_ID_RC5					SF_CIPHER_ID_RC5
#define SF_CBCMAC_ID_SEED					SF_CIPHER_ID_SEED
#define SF_CBCMAC_ID_SKIPJACK				SF_CIPHER_ID_SKIPJACK
#define SF_CBCMAC_ID_TDES					SF_CIPHER_ID_TDES
#define SF_CBCMAC_ID_DEFAULT			 	SF_CBCMAC_ID_DES
// for korea {{
#define	SF_CBCMAC_ID_DES_WITHPAD			63
// }}

#define	SF_CBCMAC_MAX_KEY_SIZE				SF_CIPHER_MAX_KEY_SIZE
#define SF_CBCMAC_MAX_DIGEST_SIZE			SF_CIPHER_MAX_BLOCK_SIZE

/**
 *	Struct
 */

typedef struct {
	int			cbcmacID;
	SF_CIPHER_CTX	cipherContext;
} SF_CBCMAC_CTX;

/**
 *	Error codes
 */

//	SF_COMMON_ERROR_INVALID_INPUT
//
//	SF_CBCMAC_ERROR_UNKNOWN_ID

/**
 *	Prototypes
 */

#ifdef __cplusplus
extern "C" {
#endif

SF_ERROR	SF_CBCMAC_Init			(SF_CBCMAC_CTX *ctx, 
									 const SF_BYTE *key, const SF_WORD keyLength,
									 const int cbcmacID, const SF_CIPHER_SUITE_PARAM *suiteParam);

SF_ERROR	SF_CBCMAC_Update		(SF_CBCMAC_CTX *ctx, 
									 const SF_BYTE *input, const SF_WORD inputLength);

SF_ERROR	SF_CBCMAC_Final			(SF_CBCMAC_CTX *ctx, SF_BYTE *mac, SF_WORD *macLength);

SF_ERROR	SF_CBCMAC				(SF_BYTE *mac, SF_WORD *macLength, 
									 const SF_BYTE *input, const SF_WORD inputLength,
									 const SF_BYTE *key, const SF_WORD keyLength,
									 const int cbcmacID, const SF_CIPHER_SUITE_PARAM *suiteParam);

#ifdef __cplusplus
}
#endif

#endif
