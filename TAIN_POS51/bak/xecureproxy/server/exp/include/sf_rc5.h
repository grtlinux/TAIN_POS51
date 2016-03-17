//
//	sf_rc5.h
//

#ifndef __SF_RC5_H__
#define __SF_RC5_H__

#include "sf_define.h"
#include "sf_error.h"

/**
 *	Constants
 */

#define	SF_RC5_DIR_ENCRYPT					0
#define	SF_RC5_DIR_DECRYPT					1

//	This version only support RC5-32.
//
//	RC5-w
//	RC5-w/r
//	RC5-w/r/b
//		w is word size
//		r is number of rounds (0 ~ 255)
///		b is the length of key (0 ~ 255)
//
//	block size = 64 = 2w
//
//	RC5-32/12/16
//	RC5-32/16/8
//
#define	SF_RC5_MAX_ROUNDS					255	// 0 ~ 255 rounds
#define	SF_RC5_DEFAULT_ROUNDS				12

#define	SF_RC5_MAX_KEY_SIZE					255	// 0 ~ 255
#define	SF_RC5_DEFAULT_KEY_SIZE				16
#define	SF_RC5_MIN_KEY_SIZE					0

#define SF_RC5_BLOCK_SIZE					8	// 64 bit = 2w
#define SF_RC5_IV_SIZE						8

/**
 *	Struct
 */

typedef struct {
	SF_WORD		rounds;
	SF_WORD		roundKey[2*(SF_RC5_MAX_ROUNDS+1)];	// 2(r+1)
} SF_RC5_KEY;

/**
 *	Prototypes
 */

#ifdef __cplusplus
extern "C" {
#endif

void		SF_RC5_MakeKey			(SF_RC5_KEY *rc5Key, const SF_BYTE *key, 
									 const SF_WORD keyLength, const int rounds);

void		SF_RC5_Main				(SF_BYTE *output, const SF_BYTE *input, 
									 const SF_RC5_KEY *rc5Key, const int dir);

// mode

SF_ERROR	SF_RC5_ECB				(SF_BYTE *output, SF_WORD *outputLength,
									 const SF_BYTE *input, const SF_WORD inputLength,
									 const SF_BYTE *key, const SF_WORD keyLength, 
									 const int rounds, const int dir);

SF_ERROR	SF_RC5_CBC				(SF_BYTE *output, SF_WORD *outputLength,
									 const SF_BYTE *input, const SF_WORD inputLength,
									 const SF_BYTE *key, const SF_WORD keyLength,
									 const int rounds, SF_BYTE iv[8], 
									 const int dir);

SF_ERROR	SF_RC5_CFB				(SF_BYTE *output, SF_WORD *outputLength,
									 const SF_BYTE *input, const SF_WORD inputLength,
									 const SF_BYTE *key, const SF_WORD keyLength,
									 const int rounds, SF_BYTE iv[8], 
									 const SF_WORD modeSize, const int dir);

SF_ERROR	SF_RC5_OFB				(SF_BYTE *output, SF_WORD *outputLength,
									 const SF_BYTE *input, const SF_WORD inputLength,
									 const SF_BYTE *key, const SF_WORD keyLength,
									 const int rounds, SF_BYTE iv[8], 
									 const SF_WORD modeSize, const int dir);

#ifdef __cplusplus
}
#endif

#endif
