//
//	sf_xrng.h
//

#ifndef __SF_XRNG_H__
#define __SF_XRNG_H__

#include "sf_sha.h"

/**
 *	Constants
 */

#define	SF_XRNG_STAT_SIZE					8
#define	SF_XRNG_RAND_SIZE					(SF_SHA_DIGEST_SIZE * (SF_XRNG_STAT_SIZE - 1))

/**
 *	Struct
 */

typedef struct {
	SF_BYTE		stat[SF_XRNG_STAT_SIZE][SF_SHA_DIGEST_SIZE];
	SF_BYTE		rand[SF_XRNG_RAND_SIZE];
	SF_WORD		randIndex, statIndex;
} SF_XRNG_CTX;

/**
 *	Prototypes
 */

#ifdef __cplusplus
extern "C" {
#endif

void		SF_XRNG_Init				(SF_XRNG_CTX *ctx, 
										 const SF_BYTE *seed, const SF_WORD seedLength);
void		SF_XRNG_Update				(SF_XRNG_CTX *ctx, 
										 const SF_BYTE *seed, const SF_WORD seedLength);
void		SF_XRNG_GetRandom			(SF_XRNG_CTX *ctx, 
										 SF_BYTE *output, const SF_WORD outputLength);

#ifdef __cplusplus
}
#endif

#endif
