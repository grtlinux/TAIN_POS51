//
//	sf_md5mac.h
//

#ifndef __SF_MD5MAC_H__
#define __SF_MD5MAC_H__

#include "sf_md5.h"
#include "sf_error.h"

/**
 *	Constants
 */
#define SF_MD5MAC_KEY_SIZE					16	// BYTE
#define SF_MD5MAC_DIGEST_SIZE				8	// BYTE

/**
 *	Struct
 */

typedef struct {
	SF_MD5_CTX		md5ctx;
	SF_WORD			kConst[4];
	SF_BYTE			pad[20];
} SF_MD5MAC_CTX;

/**
 *	Error codes
 */

//	SF_COMMON_ERROR_INVALID_INPUT

/**
 *	Prototypes
 */

#ifdef __cplusplus
extern "C" {
#endif

SF_ERROR	SF_MD5MAC_Init		(SF_MD5MAC_CTX *ctx, const SF_BYTE *key, SF_WORD keyLen);
SF_ERROR	SF_MD5MAC_Update	(SF_MD5MAC_CTX *ctx, const SF_BYTE *in, const SF_WORD inLen);
SF_ERROR	SF_MD5MAC_Final		(SF_MD5MAC_CTX *ctx, SF_BYTE *mac, SF_WORD *macLen);

SF_ERROR	SF_MD5MAC			(SF_BYTE *mac, SF_WORD *macLen, 
								 const SF_BYTE *in, const SF_WORD inLen,
								 const SF_BYTE *key, const SF_WORD keyLen);

#ifdef __cplusplus
}
#endif

#endif
