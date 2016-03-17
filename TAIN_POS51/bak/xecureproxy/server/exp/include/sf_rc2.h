//
//	sf_rc2.h
//

#ifndef __SF_RC2_H__
#define __SF_RC2_H__

#include "sf_define.h"
#include "sf_error.h"

/**
 *	Constants
 */

#define	SF_RC2_DIR_ENCRYPT					0
#define	SF_RC2_DIR_DECRYPT					1

// variable key size (0 bits ~ 1024 bits)
#define	SF_RC2_MAX_KEY_SIZE					128
#define	SF_RC2_MIN_KEY_SIZE					1

#define	SF_RC2_BLOCK_SIZE					8		// BYTE
#define	SF_RC2_IV_SIZE						8		// BYTE

/**
 *	Struct
 */

typedef struct {
	SF_WORD		roundKey[64];
} SF_RC2_KEY;

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

void		SF_RC2_MakeKey			(SF_RC2_KEY *rc2Key, const SF_BYTE *key, 
									 const SF_WORD keyLength, const SF_WORD effectiveBits);

void		SF_RC2_Main				(SF_BYTE output[8], const SF_BYTE input[8], 
									 const SF_RC2_KEY *rc2Key, const int dir);

// mode

SF_ERROR	SF_RC2_ECB				(SF_BYTE *output, SF_WORD *outputLength,
									 const SF_BYTE *input, const SF_WORD inputLength,
									 const SF_BYTE *key, const SF_WORD keyLength, 
									 const SF_WORD effectiveBits,
									 const int dir);

SF_ERROR	SF_RC2_CBC				(SF_BYTE *output, SF_WORD *outputLength,
									 const SF_BYTE *input, const SF_WORD inputLength,
									 const SF_BYTE *key, const SF_WORD keyLength,
									 const SF_WORD effectiveBits,
									 SF_BYTE iv[8], const int dir);

#ifdef __cplusplus
}
#endif

#endif
