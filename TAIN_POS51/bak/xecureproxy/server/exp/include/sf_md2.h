//
//	sf_md2.h
//

#ifndef __SF_MD2_H__
#define __SF_MD2_H__

#include "sf_define.h"

/**
 *	Constants
 */

#define	SF_MD2_BLOCK_SIZE					16	// BYTE
#define SF_MD2_DIGEST_SIZE					16	// BYTE

/**
 *	Struct
 */

typedef struct {
	SF_WORD		state[5];
	SF_WORD		count[2];
	SF_BYTE		buffer[64];
} SF_MD2_CTX;

/**
 *	Prototypes
 */

#ifdef __cplusplus
extern "C" {
#endif

void		SF_MD2_Init				(SF_MD2_CTX *ctx);
void		SF_MD2_Update			(SF_MD2_CTX *ctx, const SF_BYTE *input, const SF_WORD inputLength);
void		SF_MD2_Final			(SF_MD2_CTX *ctx, SF_BYTE *hash);

void		SF_MD2					(SF_BYTE *hash, const SF_BYTE *input, const SF_WORD inputLength);

#ifdef __cplusplus
}
#endif

#endif
