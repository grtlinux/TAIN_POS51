//
//	sf_des.h
//

#ifndef __SF_DES_H__
#define __SF_DES_H__

#include "sf_define.h"
#include "sf_error.h"

/**
 *	Constants
 */

#define	SF_DES_DIR_ENCRYPT					0
#define	SF_DES_DIR_DECRYPT					1

#define	SF_DES_KEY_SIZE						8		// BYTE

#define	SF_DES_BLOCK_SIZE					8		// BYTE
#define	SF_DES_IV_SIZE						8		// BYTE

/**
 *	Struct
 */

typedef struct {
	SF_WORD		roundKey[32];
} SF_DES_KEY;

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

int			SF_DES_IsWeakKey		(const SF_BYTE key[8]);

void		SF_DES_MakeKey			(SF_DES_KEY *desKey, const SF_BYTE key[8], 
									 const int dir);

void		SF_DES_IP				(SF_WORD *left, SF_WORD *right);
void		SF_DES_Core				(SF_WORD *left, SF_WORD *right, const SF_DES_KEY *desKey);
void		SF_DES_FP				(SF_WORD *left, SF_WORD *right);

void		SF_DES_Main				(SF_BYTE output[8], const SF_BYTE input[8], 
									 const SF_DES_KEY *desKey);

// mode

SF_ERROR	SF_DES_ECB				(SF_BYTE *output, SF_WORD *outputLength,
									 const SF_BYTE *input, const SF_WORD inputLength,
									 const SF_BYTE key[8], const int dir);

SF_ERROR	SF_DES_CBC				(SF_BYTE *output, SF_WORD *outputLength,
									 const SF_BYTE *input, const SF_WORD inputLength,
									 const SF_BYTE key[8], SF_BYTE iv[8], const int dir);

SF_ERROR	SF_DES_CFB				(SF_BYTE *output, SF_WORD *outputLength,
									 const SF_BYTE *input, const SF_WORD inputLength,
									 const SF_BYTE key[8], SF_BYTE iv[8], 
									 const SF_WORD modeSize, const int dir);

SF_ERROR	SF_DES_OFB				(SF_BYTE *output, SF_WORD *outputLength,
									 const SF_BYTE *input, const SF_WORD inputLength,
									 const SF_BYTE key[8], SF_BYTE iv[8], 
									 const SF_WORD modeSize, const int dir);

#ifdef __cplusplus
}
#endif

#endif
