//
//	sf_neat.h
//

#ifndef	__SF_NEAT_H__
#define __SF_NEAT_H__

#include "sf_define.h"
#include "sf_error.h"

/**
 *	Constants
 */

#define	SF_NEAT_DIR_ENCRYPT					0
#define	SF_NEAT_DIR_DECRYPT					1

#define	SF_NEAT_KEY_SIZE					16		// BYTE

#define	SF_NEAT_BLOCK_SIZE					16		// BYTE
#define	SF_NEAT_IV_SIZE						16		// BYTE

/**
 *	Struct
 */

typedef struct _SF_NEAT_KEY {
	SF_SHORT	rk[13][4];
	SF_SHORT	rsk[13];
} SF_NEAT_KEY;

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

void		SF_NEAT_SetPath			(const char *path);

SF_ERROR	SF_NEAT_MakeKey			(SF_NEAT_KEY *neatKey, const SF_BYTE key[16],
									 const int dir);

SF_ERROR	SF_NEAT_Main			(SF_BYTE output[16], const SF_BYTE input[16],
									 const SF_NEAT_KEY *neatKey, const int dir);

SF_ERROR	SF_NEAT_MainEx			(SF_BYTE output[16], const SF_BYTE input[16],
									 const SF_NEAT_KEY *neatKey, const int dir, 
									 const int endian);		// little (0), big (1)

#ifdef	__cplusplus
}
#endif

#endif
