//
//	sf_md5.h
//

#ifndef __SF_MD5_H__
#define __SF_MD5_H__

#include "sf_define.h"

/**
 *	Constants
 */

#define	SF_MD5_BLOCK_SIZE					64	// BYTE
#define SF_MD5_DIGEST_SIZE					16	// BYTE

/**
 *	Struct
 */

typedef struct {
	SF_WORD		state[5];
	SF_WORD		count[2];
	SF_BYTE		buffer[64];
} SF_MD5_CTX;

/**
 *	Prototypes
 */

#ifdef __cplusplus
extern "C" {
#endif

void		SF_MD5_Init				(SF_MD5_CTX *ctx);
void		SF_MD5_Update			(SF_MD5_CTX *ctx, const SF_BYTE *input, const SF_WORD inputLength);
void		SF_MD5_Final			(SF_MD5_CTX *ctx, SF_BYTE *hash);
void		SF_MD5MACTransform		(SF_WORD *state, const SF_WORD *kConst, const SF_BYTE *input);

void		SF_MD5					(SF_BYTE *hash, const SF_BYTE *input, const SF_WORD inputLength);

#ifdef __cplusplus
}
#endif

#endif
