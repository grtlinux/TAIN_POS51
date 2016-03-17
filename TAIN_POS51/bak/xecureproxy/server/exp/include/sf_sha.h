//
//	sf_sha.h
//

#ifndef __SF_SHA_H__
#define __SF_SHA_H__

#include "sf_define.h"

/**
 *	Constants
 */

#define	SF_SHA_BLOCK_SIZE					64	// BYTE
#define	SF_SHA_DIGEST_SIZE					20	// BYTE

/**
 *	Struct
 */

typedef struct {
	SF_WORD		state[5];
	SF_WORD		count[2];
	SF_BYTE		buffer[64];
} SF_SHA_CTX;

/**
 *	Prototypes
 */

#ifdef __cplusplus
extern "C" {
#endif

// sha0

void		SF_SHA0_Init			(SF_SHA_CTX *ctx);
void		SF_SHA0_Update			(SF_SHA_CTX *ctx, const SF_BYTE *input, const SF_WORD inputLength);
void		SF_SHA0_Final			(SF_SHA_CTX *ctx, SF_BYTE *hash);

void		SF_SHA0					(SF_BYTE *hash, const SF_BYTE *input, const SF_WORD inputLength);

// sha1

void		SF_SHA1_Init			(SF_SHA_CTX *ctx);
void		SF_SHA1_Update			(SF_SHA_CTX *ctx, const SF_BYTE *input, const SF_WORD inputLength);
void		SF_SHA1_Final			(SF_SHA_CTX *ctx, SF_BYTE *hash);

void		SF_SHA1					(SF_BYTE *hash, const SF_BYTE *input, const SF_WORD inputLength);

#ifdef __cplusplus
}
#endif

#endif
