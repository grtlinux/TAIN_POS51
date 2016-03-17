//
//	sf_cast128.h
//

#ifndef __SF_CAST128_H__
#define __SF_CAST128_H__

#include "sf_define.h"
#include "sf_error.h"

/**
 *	Constants
 */

#define	SF_CAST128_DIR_ENCRYPT				0
#define	SF_CAST128_DIR_DECRYPT				1

// variable key size (40 bits ~ 128 bits)
#define	SF_CAST128_MAX_KEY_SIZE				16		// BYTE
#define	SF_CAST128_MIN_KEY_SIZE				5		// BYTE

#define	SF_CAST128_BLOCK_SIZE				8		// BYTE
#define	SF_CAST128_IV_SIZE					8		// BYTE

/**
 *	Struct
 */

typedef struct {
	SF_WORD		roundKey[32];
	SF_WORD		keyLength;
} SF_CAST128_KEY;

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

void		SF_CAST128_MakeKey		(SF_CAST128_KEY *cast128Key, const SF_BYTE *key, 
									 const SF_WORD keyLength);

void		SF_CAST128_Main			(SF_BYTE output[8], const SF_BYTE input[8], 
									 const SF_CAST128_KEY *cast128Key, const int dir);

// mode

SF_ERROR	SF_CAST128_ECB			(SF_BYTE *output, SF_WORD *outputLength,
									 const SF_BYTE *input, const SF_WORD inputLength,
									 const SF_BYTE *key, const SF_WORD keyLength, 
									 const int dir);

SF_ERROR	SF_CAST128_CBC			(SF_BYTE *output, SF_WORD *outputLength,
									 const SF_BYTE *input, const SF_WORD inputLength,
									 const SF_BYTE *key, const SF_WORD keyLength, 
									 SF_BYTE iv[8], const int dir);

#ifdef __cplusplus
}
#endif

#endif
