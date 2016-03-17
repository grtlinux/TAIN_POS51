//
//	sf_nes.h
//
//2006-02-16 by ssosuny (대한주택공사)
#ifndef	__SF_NES_H__
#define __SF_NES_H__

#include "sf_define.h"
#include "sf_error.h"

/**
 *	Constants
 */

#define	SF_NES_DIR_ENCRYPT					0
#define	SF_NES_DIR_DECRYPT					1

#define	SF_NES_KEY_SIZE						32		// BYTE (256-bit:32-byte)

#define	SF_NES_BLOCK_SIZE					32		// BYTE (256-bit:32-byte)
#define	SF_NES_IV_SIZE						32		// BYTE

/**
 *	Struct
 */

typedef struct _SF_NES_KEY {
	SF_WORD QK[7][2][8];
	SF_WORD SK[7][2][8];
} SF_NES_KEY;

/**
 *	Error codes
 */

//	SF_COMMON_ERROR_INVALID_INPUT

/**
 *	Prototypes
 */

#ifdef	__cplusplus
extern "C" {
#endif

void		SF_NES_SetPath			(const char *path);

SF_ERROR	SF_NES_MakeKey			(SF_NES_KEY *nesKey, const SF_BYTE key[32], const int dir);

SF_ERROR	SF_NES_Main			(SF_BYTE output[32], const SF_BYTE input[32],
									 const SF_NES_KEY *nesKey, const int dir);

#ifdef	__cplusplus
}
#endif

#endif
