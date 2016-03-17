//
//	$Id: sf_mac.h,v 1.7 2005/05/10 02:06:04 guspin Exp $
//

#ifndef __SF_MAC_H__
#define __SF_MAC_H__

#include "sf_cbcmac.h"
#include "sf_hmac.h"
#include "sf_md5mac.h"

#include "sf_error.h"

/**
 *	Constants
 */

#define	SF_MAC_CLASS_HMAC					0x100
#define	SF_MAC_CLASS_CBCMAC					0x200
#define	SF_MAC_CLASS_MD5MAC					0x400

#define	SF_MAC_ID_HMAC_MD2					(SF_MAC_CLASS_HMAC | SF_HMAC_ID_MD2)
#define	SF_MAC_ID_HMAC_MD5					(SF_MAC_CLASS_HMAC | SF_HMAC_ID_MD5)
#define	SF_MAC_ID_HMAC_SHA0					(SF_MAC_CLASS_HMAC | SF_HMAC_ID_SHA0)
#define	SF_MAC_ID_HMAC_SHA1					(SF_MAC_CLASS_HMAC | SF_HMAC_ID_SHA1)
#define	SF_MAC_ID_HMAC_HAS160				(SF_MAC_CLASS_HMAC | SF_HMAC_ID_HAS160)
#define	SF_MAC_ID_HMAC_RIPEMD160			(SF_MAC_CLASS_HMAC | SF_HMAC_ID_RIPEMD160)
#define	SF_MAC_ID_HMAC_SHA256				(SF_MAC_CLASS_HMAC | SF_HMAC_ID_SHA256)
#define	SF_MAC_ID_HMAC_SHA384				(SF_MAC_CLASS_HMAC | SF_HMAC_ID_SHA384)
#define	SF_MAC_ID_HMAC_SHA512				(SF_MAC_CLASS_HMAC | SF_HMAC_ID_SHA512)
#define	SF_MAC_ID_HMAC_DEFAULT				(SF_MAC_CLASS_HMAC | SF_HMAC_ID_DEFAULT)
#define SF_MAC_ID_CBCMAC_AES				(SF_MAC_CLASS_CBCMAC | SF_CBCMAC_ID_AES)
#define SF_MAC_ID_CBCMAC_BLOWFISH			(SF_MAC_CLASS_CBCMAC | SF_CBCMAC_ID_BLOWFISH)
#define SF_MAC_ID_CBCMAC_CAST128			(SF_MAC_CLASS_CBCMAC | SF_CBCMAC_ID_CAST128)
#define SF_MAC_ID_CBCMAC_DES				(SF_MAC_CLASS_CBCMAC | SF_CBCMAC_ID_DES)
#define SF_MAC_ID_CBCMAC_RC2				(SF_MAC_CLASS_CBCMAC | SF_CBCMAC_ID_RC2)
#define SF_MAC_ID_CBCMAC_RC5				(SF_MAC_CLASS_CBCMAC | SF_CBCMAC_ID_RC5)
#define SF_MAC_ID_CBCMAC_SEED				(SF_MAC_CLASS_CBCMAC | SF_CBCMAC_ID_SEED)
#define SF_MAC_ID_CBCMAC_SKIPJACK			(SF_MAC_CLASS_CBCMAC | SF_CBCMAC_ID_SKIPJACK)
#define SF_MAC_ID_CBCMAC_TDES				(SF_MAC_CLASS_CBCMAC | SF_CBCMAC_ID_TDES)
#define SF_MAC_ID_CBCMAC_DEFAULT			(SF_MAC_CLASS_CBCMAC | SF_CBCMAC_ID_DEFAULT)
// for korea {{
#define SF_MAC_ID_CBCMAC_DES_WITHPAD		(SF_MAC_CLASS_CBCMAC | SF_CBCMAC_ID_DES_WITHPAD)
// }}
#define SF_MAC_ID_MD5MAC					(SF_MAC_CLASS_MD5MAC)
#define	SF_MAC_ID_DEFAULT					SF_MAC_ID_HMAC_SHA1

#define	SF_MAC_MAX_DIGEST_SIZE				SF_HMAC_MAX_DIGEST_SIZE

/**
 *	Struct
 */

typedef struct {
	SF_WORD		macLength;
	SF_WORD		keyLength;				// default
	SF_WORD		minKeyLength;
	SF_WORD		maxKeyLength;
	SF_WORD		stepKeyLength;
} SF_MAC_INFO;

typedef struct {
	int			macID;
	union {
		SF_HMAC_CTX		hmac;
		SF_CBCMAC_CTX	cbcmac;
		SF_MD5MAC_CTX	md5mac;
	} ctx;
} SF_MAC_CTX;

/**
 *	Error codes
 */

//	SF_COMMON_ERROR_INVALID_INPUT
//
//	SF_MAC_ERROR_UNKNOWN_ID

/**
 *	Prototypes
 */

#ifdef __cplusplus
extern "C" {
#endif

SF_MAC_CTX *
			SF_MAC_CTX_New					(void);

void		SF_MAC_CTX_Free					(SF_MAC_CTX *ctx);

SF_ERROR	SF_MAC_GetInfo					(SF_MAC_INFO *macInfo, const int macID);

SF_ERROR	SF_MAC_Init						(SF_MAC_CTX *ctx, 
											 const SF_BYTE *key, const SF_WORD keyLength,
											 const int macID, const SF_CIPHER_SUITE_PARAM *suiteParam);

SF_ERROR	SF_MAC_Update					(SF_MAC_CTX *ctx, 
											 const SF_BYTE *input, const SF_WORD inputLength);

SF_ERROR	SF_MAC_Final					(SF_MAC_CTX *ctx, 
											 SF_BYTE *mac, SF_WORD *macLength);

SF_ERROR	SF_MAC							(SF_BYTE *mac, SF_WORD *macLength, 
											 const SF_BYTE *input, const SF_WORD inputLength,
											 const SF_BYTE *key, const SF_WORD keyLength,
											 const int macID, const SF_CIPHER_SUITE_PARAM *suiteParam);

#ifdef __cplusplus
}
#endif

#endif
