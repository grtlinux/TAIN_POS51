//
//	sf_ripemd160.h
//

#ifndef __SF_RIPEMD160_H__
#define __SF_RIPEMD160_H__

#include "sf_define.h"

/**
 *	Constants
 */

#define	SF_RIPEMD160_BLOCK_SIZE				64	// BYTE
#define	SF_RIPEMD160_DIGEST_SIZE			20	// BYTE

/**
 *	Struct
 */

typedef struct {
	SF_WORD		state[5];
	SF_WORD		count[2];
	SF_BYTE		buffer[64];
} SF_RIPEMD160_CTX;

/**
 *	Prototypes
 */

#ifdef __cplusplus
extern "C" {
#endif

void		SF_RIPEMD160_Init		(SF_RIPEMD160_CTX *ctx);
void		SF_RIPEMD160_Update		(SF_RIPEMD160_CTX *ctx, const SF_BYTE *input, const SF_WORD inputLength);
void		SF_RIPEMD160_Final		(SF_RIPEMD160_CTX *ctx, SF_BYTE *hash);

void		SF_RIPEMD160			(SF_BYTE *hash, const SF_BYTE *input, const SF_WORD inputLength);

#ifdef __cplusplus
}
#endif

#endif
