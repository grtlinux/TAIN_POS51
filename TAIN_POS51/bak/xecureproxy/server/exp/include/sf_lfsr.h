//
//	sf_lfsr.h
//

#ifndef __SF_LFSR_H__
#define __SF_LFSR_H__

#include "sf_define.h"

/**
 *	Struct
 */

typedef struct {
	SF_WORD		lfsrA[9];
	SF_WORD		lfsrB[9];
} SF_LFSR_CTX;

/**
 *	Prototypes
 */

#ifdef __cplusplus
extern "C" {
#endif

void		SF_LFSR_Init			(SF_LFSR_CTX *ctx, const SF_BYTE *seed, const SF_WORD seedLength);
void		SF_LFSR_Update			(SF_LFSR_CTX *ctx, const SF_BYTE *seed, const SF_WORD seedLength);
void		SF_LFSR_GetRandom		(SF_LFSR_CTX *ctx, SF_BYTE *output, const SF_WORD outputLength);

#ifdef __cplusplus
}
#endif

#endif
