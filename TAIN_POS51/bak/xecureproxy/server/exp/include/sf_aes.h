//
//	sf_aes.h
//

//WIN32_CE
#ifndef _MIN_WCE

#ifndef __SF_AES_H__
#define __SF_AES_H__

#include "sf_define.h"
#include "sf_error.h"

/**
 *	Constants
 */

#define	SF_AES_DIR_ENCRYPT					0
#define	SF_AES_DIR_DECRYPT					1

//	This version support AES-128, 192, 256
//
//	AES-key/block/rounds
//
//	AES-128/128/10
//  AES-192/128/12
//  AES-256/128/14
//
#define	SF_AES_MAX_ROUNDS					14
#define	SF_AES_DEFAULT_ROUNDS				10

#define	SF_AES_MAX_KEY_SIZE					32	// 256 bits, bytes block	
#define	SF_AES_DEFAULT_KEY_SIZE				16	// 128 bits, bytes block
#define	SF_AES_MIN_KEY_SIZE					16	// 128 bits

#define SF_AES_MAX_KC						8	// # of 32 bits key column

#define SF_AES_BLOCK_SIZE					16	// 128 bits, 192bits, 256bits ok
#define SF_AES_IV_SIZE						16

/**
 *	Struct
 */

typedef struct {
	SF_WORD		rounds;
	SF_WORD		roundKey[4*(SF_AES_MAX_ROUNDS+1)];	// Nb*(Nr + 1)
} SF_AES_KEY;

/**
 *	Prototypes
 */

#ifdef __cplusplus
extern "C" {
#endif

SF_ERROR	SF_AES_MakeKey			(SF_AES_KEY *aesKey, const SF_BYTE *key,
									 const SF_WORD keyLen, const int dir);

void		SF_AES_Main				(SF_BYTE out[16], const SF_BYTE in[16],
									 const SF_AES_KEY *aesKey, const int dir);

// mode

SF_ERROR	SF_AES_ECB				(SF_BYTE *out, SF_WORD *outLen,
									 const SF_BYTE *in, const SF_WORD inLen,
									 const SF_BYTE *key, const SF_WORD keyLen,
									 const int dir);

SF_ERROR	SF_AES_CBC				(SF_BYTE *out, SF_WORD *outLen,
									 const SF_BYTE *in, const SF_WORD inLen,
									 const SF_BYTE *key, const SF_WORD keyLen, 
									 SF_BYTE iv[16], const int dir);

SF_ERROR	SF_AES_CFB				(SF_BYTE *out, SF_WORD *outLen,
									 const SF_BYTE *in, const SF_WORD inLen,
									 const SF_BYTE *key, const SF_WORD keyLen, 
									 SF_BYTE iv[16], const SF_WORD modeSize,
									 const int dir);

SF_ERROR	SF_AES_OFB				(SF_BYTE *out, SF_WORD *outLen,
									 const SF_BYTE *in, const SF_WORD inLen,
									 const SF_BYTE *key, const SF_WORD keyLen, 
									 SF_BYTE iv[16], const SF_WORD modeSize,
									 const int dir);

#ifdef __cplusplus
}
#endif

#endif /* __SF_AES_H__ */

#endif //_MIN_WCE