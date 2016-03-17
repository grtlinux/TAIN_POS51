//
//	sf_has160.h
//

#ifndef __SF_HAS160_H__
#define __SF_HAS160_H__

#include "sf_define.h"

/**
 *	Constants
 */

#define	SF_HAS160_BLOCK_SIZE				64	// BYTE
#define	SF_HAS160_DIGEST_SIZE				20	// BYTE

/**
 *	Struct
 */

typedef struct {
	SF_WORD		state[5];
	SF_WORD		count[2];
	SF_BYTE		buffer[64];
} SF_HAS160_CTX;

/**
 *	Prototypes
 */

#ifdef __cplusplus
extern "C" {
#endif

void		SF_HAS160_Init			(SF_HAS160_CTX *ctx);
void		SF_HAS160_Update		(SF_HAS160_CTX *ctx, const SF_BYTE *input, const SF_WORD inputLength);
void		SF_HAS160_Final			(SF_HAS160_CTX *ctx, SF_BYTE *hash);

void		SF_HAS160				(SF_BYTE *hash, const SF_BYTE *input, const SF_WORD inputLength);

#ifdef __cplusplus
}
#endif

#endif
