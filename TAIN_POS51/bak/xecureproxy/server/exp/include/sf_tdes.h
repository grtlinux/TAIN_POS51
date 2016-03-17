//
//	sf_tdes.h
//

#ifndef __SF_TDES_H__
#define __SF_TDES_H__

#include "sf_des.h"

/**
 *	Constants
 */

#define	SF_TDES_DIR_ENCRYPT					SF_DES_DIR_ENCRYPT
#define	SF_TDES_DIR_DECRYPT					SF_DES_DIR_DECRYPT

#define	SF_TDES_MAX_KEY_SIZE				(SF_DES_KEY_SIZE * 3)
#define	SF_TDES_MIN_KEY_SIZE				SF_DES_KEY_SIZE

#define	SF_TDES_BLOCK_SIZE					SF_DES_BLOCK_SIZE
#define	SF_TDES_IV_SIZE						SF_DES_IV_SIZE

/**
 *	Struct
 */

typedef struct {
	SF_DES_KEY		key1;
	SF_DES_KEY		key2;
	SF_DES_KEY		key3;
} SF_TDES_KEY;

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

int			SF_TDES_IsWeakKey		(const SF_BYTE *key, const SF_WORD keyLength);

SF_ERROR	SF_TDES_MakeKey			(SF_TDES_KEY *tdesKey, const SF_BYTE *key, 
									 const SF_WORD keyLength, const int dir);

void		SF_TDES_Main			(SF_BYTE output[8], const SF_BYTE input[8], 
									 const SF_TDES_KEY *tdesKey);

// mode

SF_ERROR	SF_TDES_ECB				(SF_BYTE *output, SF_WORD *outputLength,
									 const SF_BYTE *input, const SF_WORD inputLength,
									 const SF_BYTE *key, const SF_WORD keyLength,
									 const int dir);

SF_ERROR	SF_TDES_CBC				(SF_BYTE *output, SF_WORD *outputLength,
									 const SF_BYTE *input, const SF_WORD inputLength,
									 const SF_BYTE *key, const SF_WORD keyLength,
									 SF_BYTE iv[8], const int dir);

SF_ERROR	SF_TDES_CFB				(SF_BYTE *output, SF_WORD *outputLength,
									 const SF_BYTE *input, const SF_WORD inputLength,
									 const SF_BYTE *key, const SF_WORD keyLength,
									 SF_BYTE iv[8], const SF_WORD modeSize, const int dir);

SF_ERROR	SF_TDES_OFB				(SF_BYTE *output, SF_WORD *outputLength,
									 const SF_BYTE *input, const SF_WORD inputLength,
									 const SF_BYTE *key, const SF_WORD keyLength,
									 SF_BYTE iv[8], const SF_WORD modeSize, const int dir);

#ifdef __cplusplus
}
#endif

#endif
