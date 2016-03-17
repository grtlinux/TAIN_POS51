//
//	sf_rc4.h
//

#ifndef __SF_RC4_H__
#define __SF_RC4_H__

#include "sf_define.h"

/**
 *	Constants
 */

#define	SF_RC4_MAX_KEY_SIZE					256
#define	SF_RC4_MIN_KEY_SIZE					1

#define	SF_RC4_128_KEY_SIZE					16
#define	SF_RC4_40_KEY_SIZE					5

/**
 *	Struct
 */

typedef struct {
	SF_BYTE		x, y;
	SF_BYTE		rc4SBox[256];
} SF_RC4_KEY;

/**
 *	Prototypes
 */

#ifdef __cplusplus
extern "C" {
#endif

void		SF_RC4_MakeKey			(SF_RC4_KEY *rc4Key, const SF_BYTE *key, 
									 const SF_WORD keyLength);

void		SF_RC4_Main				(SF_BYTE *output, SF_WORD *outputLength,
									 const SF_BYTE *input, const SF_WORD inputLength,
									 SF_RC4_KEY *rc4Key);

void		SF_RC4					(SF_BYTE *output, SF_WORD *outputLength,
									 const SF_BYTE *input, const SF_WORD inputLength, 
									 const SF_BYTE *key, const SF_WORD keyLength);

#ifdef __cplusplus
}
#endif

#endif
