//
//	sf_skipjack.h
//

#ifndef __SF_SKIPJACK_H__
#define __SF_SKIPJACK_H__

#include "sf_define.h"
#include "sf_error.h"

/**
 *	Constants
 */

#define	SF_SKIPJACK_DIR_ENCRYPT				0
#define	SF_SKIPJACK_DIR_DECRYPT				1

#define	SF_SKIPJACK_KEY_SIZE				10	// BYTE

#define SF_SKIPJACK_BLOCK_SIZE				8	// BYTE
#define SF_SKIPJACK_IV_SIZE					8	// BYTE

/**
 *	Struct
 */

typedef struct {
	SF_WORD		roundKey[640];
} SF_SKIPJACK_KEY;

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

void		SF_Skipjack_MakeKey		(SF_SKIPJACK_KEY *skipjackKey, const SF_BYTE key[10]);

void		SF_Skipjack_Main		(SF_BYTE output[8], const SF_BYTE input[8],
									 const SF_SKIPJACK_KEY *skipjackKey, const int dir);

// mode

SF_ERROR	SF_Skipjack_ECB			(SF_BYTE *output, SF_WORD *outputLength,
									 const SF_BYTE *input, const SF_WORD inputLength,
									 const SF_BYTE key[10], const int dir);

SF_ERROR	SF_Skipjack_CBC			(SF_BYTE *output, SF_WORD *outputLength,
									 const SF_BYTE *input, const SF_WORD inputLength,
									 const SF_BYTE key[10], SF_BYTE iv[8], const int dir);

SF_ERROR	SF_Skipjack_CFB			(SF_BYTE *output, SF_WORD *outputLength,
									 const SF_BYTE *input, const SF_WORD inputLength,
									 const SF_BYTE key[10], SF_BYTE iv[8], 
									 const SF_WORD modeSize, const int dir);

SF_ERROR	SF_Skipjack_OFB			(SF_BYTE *output, SF_WORD *outputLength,
									 const SF_BYTE *input, const SF_WORD inputLength,
									 const SF_BYTE key[10], SF_BYTE iv[8], 
									 const SF_WORD modeSize, const int dir);

#ifdef __cplusplus
}
#endif

#endif
