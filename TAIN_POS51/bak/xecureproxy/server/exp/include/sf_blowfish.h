//
//	sf_blowfish.h
//

#ifndef __SF_BLOWFISH_H__
#define __SF_BLOWFISH_H__

#include "sf_define.h"
#include "sf_error.h"

/**
 *	Constants
 */

#define	SF_BLOWFISH_DIR_ENCRYPT				0
#define	SF_BLOWFISH_DIR_DECRYPT				1

// variable key size (32 bits ~ 448 bits)
#define SF_BLOWFISH_MAX_KEY_SIZE			56		// BYTE
#define SF_BLOWFISH_MIN_KEY_SIZE			4		// BYTE

#define	SF_BLOWFISH_BLOCK_SIZE				8		// BYTE
#define	SF_BLOWFISH_IV_SIZE					8		// BYTE

/**
 *	Struct
 */

typedef struct {
	SF_WORD		roundKey[18 + (4*256)];
} SF_BLOWFISH_KEY;

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

void		SF_Blowfish_MakeKey		(SF_BLOWFISH_KEY *blowfishKey, const SF_BYTE *key, 
									 const SF_WORD keyLength, const int dir);

void		SF_Blowfish_Main		(SF_BYTE output[8], const SF_BYTE input[8], 
									 const SF_BLOWFISH_KEY *blowfishKey);

// mode

SF_ERROR	SF_Blowfish_ECB			(SF_BYTE *output, SF_WORD *outputLength,
									 const SF_BYTE *input, const SF_WORD inputLength,
									 const SF_BYTE *key, const SF_WORD keyLength, 
									 const int dir);

SF_ERROR	SF_Blowfish_CBC			(SF_BYTE *output, SF_WORD *outputLength,
									 const SF_BYTE *input, const SF_WORD inputLength,
									 const SF_BYTE *key, const SF_WORD keyLength,
									 SF_BYTE iv[8], const int dir);

#ifdef __cplusplus
}
#endif

#endif
