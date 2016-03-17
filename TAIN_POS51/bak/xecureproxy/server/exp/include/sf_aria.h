//
//	sf_aria.h
//

#ifndef __SF_ARIA_H__
#define __SF_ARIA_H__

#include "sf_define.h"
#include "sf_error.h"

/**
 *	Constants
 */

#define	SF_ARIA_DIR_ENCRYPT					0
#define	SF_ARIA_DIR_DECRYPT					1

#define	SF_ARIA_MAX_KEY_SIZE				32		// 256 bits, bytes Block
#define	SF_ARIA_MIN_KEY_SIZE				16		// 128 bits, bytes Block

#define	SF_ARIA_BLOCK_SIZE					16		// BYTE
#define	SF_ARIA_IV_SIZE						16		// BYTE

/**
 *	Struct
 */

typedef struct {
	SF_WORD		rounds;
	SF_WORD		keyLength;
	SF_WORD		roundKey[16*(16+1)];
} SF_ARIA_KEY;

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

SF_ERROR	SF_ARIA_MakeKey			(SF_ARIA_KEY *ariaKey, const SF_BYTE *key, 
									 const SF_WORD keyLength, const int dir);

void		SF_ARIA_Main			(SF_BYTE output[16], const SF_BYTE input[16], 
									 const SF_ARIA_KEY *ariaKey);

#ifdef __cplusplus
}
#endif

#endif
