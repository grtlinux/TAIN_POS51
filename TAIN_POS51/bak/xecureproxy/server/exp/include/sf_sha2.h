//
//	sf_sha2.h
//
//WIN32_CE
#ifndef _MIN_WCE

#ifndef __SF_SHA2_H__
#define __SF_SHA2_H__

#include "sf_define.h"

/**
 *	Constants
 */

#define	SF_SHA256_BLOCK_SIZE				64	// BYTE
#define	SF_SHA256_DIGEST_SIZE				32	// BYTE

#define	SF_SHA384_BLOCK_SIZE				128	// BYTE
#define	SF_SHA384_DIGEST_SIZE				48	// BYTE

#define	SF_SHA512_BLOCK_SIZE				128	// BYTE
#define	SF_SHA512_DIGEST_SIZE				64	// BYTE

/**
 *	Struct
 */

typedef struct {
	SF_WORD		state[8];
	SF_WORD		count[2];
	SF_BYTE		buffer[64];
} SF_SHA256_CTX;

typedef struct {
	SF_DWORD	state[8];
	SF_DWORD	count[2];
	SF_BYTE		buffer[128];
} SF_SHA512_CTX;

typedef SF_SHA512_CTX	SF_SHA384_CTX;

/**
 *	Prototypes
 */

#ifdef __cplusplus
extern "C" {
#endif

// sha256

void		SF_SHA256_Init					(SF_SHA256_CTX *ctx);
void		SF_SHA256_Update				(SF_SHA256_CTX *ctx, 
											 const SF_BYTE *input, const SF_WORD inputLength);
void		SF_SHA256_Final					(SF_SHA256_CTX *ctx, SF_BYTE *hash);

void		SF_SHA256						(SF_BYTE *hash,
											 const SF_BYTE *input, const SF_WORD inputLength);

// sha384

void		SF_SHA384_Init					(SF_SHA384_CTX *ctx);
void		SF_SHA384_Update				(SF_SHA384_CTX *ctx, 
											 const SF_BYTE *input, const SF_WORD inputLength);
void		SF_SHA384_Final					(SF_SHA384_CTX *ctx, SF_BYTE *hash);

void		SF_SHA384						(SF_BYTE *hash,
											 const SF_BYTE *input, const SF_WORD inputLength);

// sha512

void		SF_SHA512_Init					(SF_SHA512_CTX *ctx);
void		SF_SHA512_Update				(SF_SHA512_CTX *ctx, 
											 const SF_BYTE *input, const SF_WORD inputLength);
void		SF_SHA512_Final					(SF_SHA512_CTX *ctx, SF_BYTE *hash);

void		SF_SHA512						(SF_BYTE *hash,
											 const SF_BYTE *input, const SF_WORD inputLength);

#ifdef __cplusplus
}
#endif

#endif

#endif	//_MIN_WCE