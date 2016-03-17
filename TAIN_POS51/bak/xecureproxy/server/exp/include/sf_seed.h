//
//	sf_seed.h
//

#ifndef __SF_SEED_H__
#define __SF_SEED_H__

#include "sf_define.h"
#include "sf_error.h"

/**
 *	Constants
 */

#define	SF_SEED_DIR_ENCRYPT					0
#define	SF_SEED_DIR_DECRYPT					1

#define	SF_SEED_KEY_SIZE					16		// BYTE

#define	SF_SEED_BLOCK_SIZE					16		// BYTE
#define	SF_SEED_IV_SIZE						16		// BYTE

/**
 *	Struct
 */

typedef struct {
	SF_WORD		roundKey[32];
} SF_SEED_KEY;

/**
 *	Error codes
 */

//	SF_COMMON_ERROR_INVALID_INPUT

/**
 *	Prototypes
 */

#ifdef __cplusplus
extern "C" {
#endif

void		SF_SEED_MakeKey			(SF_SEED_KEY *seedKey, const SF_BYTE key[16], 
									 const int dir);

void		SF_SEED_Main			(SF_BYTE output[16], const SF_BYTE input[16], 
									 const SF_SEED_KEY *seedKey);

// mode

SF_ERROR	SF_SEED_ECB				(SF_BYTE *output, SF_WORD *outputLength,
									 const SF_BYTE *input, const SF_WORD inputLength,
									 const SF_BYTE key[16], const int dir);

SF_ERROR	SF_SEED_CBC				(SF_BYTE *output, SF_WORD *outputLength,
									 const SF_BYTE *input, const SF_WORD inputLength,
									 const SF_BYTE key[16], SF_BYTE iv[16], 
									 const int dir);

#ifdef __cplusplus
}
#endif

#endif
