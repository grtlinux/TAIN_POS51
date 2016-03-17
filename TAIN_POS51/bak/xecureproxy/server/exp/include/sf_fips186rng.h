//
//	sf_fips186rng.h
//

#ifndef __SF_FIPS186RNG_H__
#define __SF_FIPS186RNG_H__

#include "sf_define.h"
#include "sf_bigint.h"

/**
 *	Constants
 */

#define	SF_FIPS186RNG_ID_DSA				1
#define	SF_FIPS186RNG_ID_ECDSA				2

#define	SF_FIPS186RNG_GFID_SHA1				1
#define	SF_FIPS186RNG_GFID_HAS160			5
#define	SF_FIPS186RNG_GFID_SEED				6
#define	SF_FIPS186RNG_GFID_ARIA				7

#define	SF_FIPS186RNG_MAX_B_SIZE			64		// 512 bits
#define	SF_FIPS186RNG_MIN_B_SIZE			20		// 160 bits

/**
 *	Struct
 */

typedef struct {
	int		rngID;
	int		gfID;
	SF_POOL_CTX	*pool;
	SF_BigInt	*primeQ;
	SF_WORD		bSize;			// 160/4 ~ 512/4
	SF_BYTE		xkey[SF_FIPS186RNG_MAX_B_SIZE];
	SF_BYTE		xseed[SF_FIPS186RNG_MAX_B_SIZE];
	SF_WORD		xseedLength;
} SF_FIPS186RNG_CTX;

/**
 *	Prototypes
 */

#ifdef __cplusplus
extern "C" {
#endif

SF_ERROR	SF_FIPS186RNG_Init				(SF_FIPS186RNG_CTX *ctx, const int rngID, 
											 const int gfID, const SF_BigInt *primeQ,
											 const SF_BYTE *xkey, const SF_WORD xkeyLength,
											 const SF_BYTE *xseed, const SF_WORD xseedLength);

SF_ERROR	SF_FIPS186RNG_Update			(SF_FIPS186RNG_CTX *ctx, 
											 const SF_BYTE *xseed, const SF_WORD xseedLength);

SF_ERROR	SF_FIPS186RNG_GetRandom			(SF_FIPS186RNG_CTX *ctx, SF_BigInt *output);

SF_ERROR	SF_FIPS186RNG_Final				(SF_FIPS186RNG_CTX *ctx);

#ifdef __cplusplus
}
#endif

#endif
