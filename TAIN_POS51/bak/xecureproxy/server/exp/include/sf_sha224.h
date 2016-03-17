//
//	sha224.h
//
//	1.	RFC 3874, A 224-bi One-way Hash Function: SHA-224, Sep. 2004
//WIN32_CE
#ifndef _MIN_WCE

#ifndef __SHA224_H__
#define __SHA224_H__

#include "sf_define.h"


/**
 *	Constants
 */
#define	SF_SHA224_BLOCK_SIZE				64	// BYTE
#define	SF_SHA224_DIGEST_SIZE				28	// BYTE

/**
 *	Struct
 */

typedef struct {
	SF_WORD		state[8];
	SF_WORD		count[2];
	SF_BYTE		buffer[64];
} SF_SHA224_CTX;

/**
 *	Prototypes
 */

#ifdef __cplusplus
extern "C" {
#endif

// sha224

void		SF_SHA224_Init					(SF_SHA224_CTX *ctx);
void		SF_SHA224_Update				(SF_SHA224_CTX *ctx, 
											 const SF_BYTE *input, const SF_WORD inputLength);
void		SF_SHA224_Final					(SF_SHA224_CTX *ctx, SF_BYTE *hash);

void		SF_SHA224						(SF_BYTE *hash,
											 const SF_BYTE *input, const SF_WORD inputLength);

#ifdef __cplusplus
}
#endif

#endif

#endif	//MAC_WCE