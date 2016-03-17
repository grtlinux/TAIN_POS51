//
//	sf_rand.h
//

#ifndef __SF_RAND_H__
#define __SF_RAND_H__

#include "sf_lfsr.h"
#include "sf_xrng.h"
#include "sf_error.h"

/**
 *	Constants
 */

#define	SF_RAND_ID_LFSR						1
#define	SF_RAND_ID_XRNG						2
#define	SF_RAND_ID_DEFAULT					SF_RAND_ID_XRNG

/**
 *	Struct
 */

typedef struct {
	SF_WORD		randID;
	union {
		SF_LFSR_CTX	lfsr;
		SF_XRNG_CTX	xrng;
	} ctx;
} SF_RAND_CTX;

/**
 *	Prototypes
 */

#ifdef __cplusplus
extern "C" {
#endif

SF_ERROR	SF_RAND_Init					(SF_RAND_CTX *ctx, const int randID, 
											 const SF_BYTE *seed, const SF_WORD seedLength);

SF_ERROR	SF_RAND_Update					(SF_RAND_CTX *ctx, 
											 const SF_BYTE *seed, const SF_WORD seedLength);

SF_ERROR	SF_RAND_GetRandom				(SF_RAND_CTX *ctx, 
											 SF_BYTE *output, const SF_WORD outputLength);

SF_ERROR	SF_RAND_StatTest				(const SF_BYTE *data, const SF_WORD dataLength); // 20000/8 bytes


void		SF_InitRandom					(const int randID,
											 const SF_BYTE *seed, const SF_WORD seedLength);

void		SF_UpdateRandom					(const SF_BYTE *seed, const SF_WORD seedLength);

void		SF_GetRandom					(SF_BYTE *output, const SF_WORD outputLength);

#ifdef __cplusplus
}
#endif

#endif
