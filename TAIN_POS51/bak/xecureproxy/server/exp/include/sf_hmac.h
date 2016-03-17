//
//	sf_hmac.h
//

#ifndef	__SF_HMAC_H__
#define	__SF_HMAC_H__

#include "sf_hash.h"

/**
 *	Constants
 */

#define	SF_HMAC_ID_MD2						SF_HASH_ID_MD2
#define	SF_HMAC_ID_MD5						SF_HASH_ID_MD5
#define	SF_HMAC_ID_SHA0						SF_HASH_ID_SHA0
#define	SF_HMAC_ID_SHA1						SF_HASH_ID_SHA1
#define	SF_HMAC_ID_HAS160					SF_HASH_ID_HAS160
#define	SF_HMAC_ID_RIPEMD160				SF_HASH_ID_RIPEMD160
#define	SF_HMAC_ID_SHA256					SF_HASH_ID_SHA256
#define	SF_HMAC_ID_SHA384					SF_HASH_ID_SHA384
#define	SF_HMAC_ID_SHA512					SF_HASH_ID_SHA512
#define	SF_HMAC_ID_DEFAULT					SF_HASH_ID_DEFAULT

#define	SF_HMAC_MAX_BLOCK_SIZE				SF_HASH_MAX_BLOCK_SIZE
#define	SF_HMAC_MAX_DIGEST_SIZE				SF_HASH_MAX_DIGEST_SIZE

/**
 *	Struct
 */

typedef struct {
	int			hmacID;
	SF_BYTE		key[SF_HMAC_MAX_BLOCK_SIZE];
	SF_WORD		keyLength;
	SF_HASH_INFO hashInfo;
	SF_HASH_CTX	hashContext;
} SF_HMAC_CTX;

/**
 *	Error codes
 */

//	SF_COMMON_ERROR_INVALID_INPUT
//
//	SF_HASH_ERROR_UNKNOWN_ID

/**
 *	Prototypes
 */

#ifdef  __cplusplus
extern "C" {
#endif

SF_ERROR	SF_HMAC_Init			(SF_HMAC_CTX *ctx, 
									 const SF_BYTE *key, const SF_WORD keyLength,
									 const SF_WORD hmacID);

SF_ERROR	SF_HMAC_Update			(SF_HMAC_CTX *ctx, 
									 const SF_BYTE *input, const SF_WORD inputLength);

SF_ERROR	SF_HMAC_Final			(SF_HMAC_CTX *ctx, SF_BYTE *mac, SF_WORD *macLength);

SF_ERROR	SF_HMAC					(SF_BYTE *mac, SF_WORD *macLength, 
									 const SF_BYTE *input, const SF_WORD inputLength,
									 const SF_BYTE *key, const SF_WORD keyLength,
									 const SF_WORD hmacID);

SF_ERROR	SF_HMAC_MD5				(SF_BYTE *mac, SF_WORD *macLength, 
									 const SF_BYTE *input, const SF_WORD inputLength,
									 const SF_BYTE *key, const SF_WORD keyLength);

SF_ERROR	SF_HMAC_SHA1			(SF_BYTE *mac, SF_WORD *macLength, 
									 const SF_BYTE *input, const SF_WORD inputLength,
									 const SF_BYTE *key, const SF_WORD keyLength);

#ifdef  __cplusplus
}
#endif

#endif
