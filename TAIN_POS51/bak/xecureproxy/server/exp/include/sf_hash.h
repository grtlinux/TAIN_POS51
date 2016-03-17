//
//	$Id: sf_hash.h,v 1.11 2007/12/17 01:01:24 ssosuny Exp $
//

#ifndef __SF_HASH_H__
#define __SF_HASH_H__

#include "sf_md2.h"
#include "sf_md5.h"
#include "sf_sha.h"
#include "sf_has160.h"
#include "sf_ripemd160.h"
#include "sf_sha2.h"
#include "sf_sha224.h"

#include "sf_error.h"

/**
 *	Constants
 */

#define	SF_HASH_ID_MD2						1
#define	SF_HASH_ID_MD5						2
#define	SF_HASH_ID_SHA0						3
#define	SF_HASH_ID_SHA1						4
#define	SF_HASH_ID_HAS160					5
#define	SF_HASH_ID_RIPEMD160				6
#define	SF_HASH_ID_SHA256					7
#define	SF_HASH_ID_SHA384					8
#define	SF_HASH_ID_SHA512					9
#define SF_HASH_ID_SHA224					10

#define	SF_HASH_ID_DEFAULT					SF_HASH_ID_SHA1

#define	SF_HASH_MAX_BLOCK_SIZE				128	// SHA512
#define	SF_HASH_MAX_DIGEST_SIZE				64	// SHA512

/**
 *	Struct
 */

typedef struct {
	SF_WORD		blockSize;
	SF_WORD		hashSize;
} SF_HASH_INFO;

typedef struct {
	int			hashID;
	SF_HASH_INFO	info;
	union {
		SF_MD2_CTX			md2;
		SF_MD5_CTX			md5;
		SF_SHA_CTX			sha;
		SF_HAS160_CTX		has160;
//WIN32_CE
#ifndef _MIN_WCE
		SF_RIPEMD160_CTX	ripemd160;
		SF_SHA256_CTX		sha256;
		SF_SHA384_CTX		sha384;
		SF_SHA512_CTX		sha512;
		SF_SHA224_CTX		sha224;
#endif	//_MIN_WCE
	} ctx;
} SF_HASH_CTX;

/**
 *	Error codes
 */

//	SF_COMMON_ERROR_INVALID_INPUT
//
//	SF_HASH_ERROR_UNKNOWN_ID

/**
 *	Prototypes
 */

#ifdef __cplusplus
extern "C" {
#endif

SF_HASH_CTX *
			SF_Hash_CTX_New					(void);

void		SF_Hash_CTX_Free				(SF_HASH_CTX *ctx);

SF_ERROR	SF_Hash_GetInfo					(SF_HASH_INFO *info, const int hashID);

SF_ERROR	SF_Hash_Init					(SF_HASH_CTX *ctx, const int hashID);

SF_ERROR	SF_Hash_Update					(SF_HASH_CTX *ctx, 
											 const SF_BYTE *input, const SF_WORD inputLength);

SF_ERROR	SF_Hash_Final					(SF_HASH_CTX *ctx, 
											 SF_BYTE *hash, SF_WORD *hashLength);

SF_ERROR	SF_Hash							(SF_BYTE *hash, SF_WORD *hashLength, 
											 const SF_BYTE *input, const SF_WORD inputLength,
											 const int hashID);

#ifdef __cplusplus
}
#endif

#endif
