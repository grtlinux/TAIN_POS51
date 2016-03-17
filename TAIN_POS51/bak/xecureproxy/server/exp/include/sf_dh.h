//
//	$Id: sf_dh.h,v 1.6 2004/12/10 00:39:46 guspin Exp $
//

#ifndef __SF_DH_H__
#define __SF_DH_H__

#include "sf_bigint.h"

/**
 *	Struct
 */

typedef struct {
	SF_BigInt		*p;			// odd prime, p = j*q + 1
	SF_BigInt		*g;			// generator, g

	SF_BigInt		*q;			// factor of p-1
	SF_BigInt		*j;			// subgroup factor (optional)

	SF_WORD			privKeyBitLength;	// (optional)

	struct {
		SF_BYTE		*seed;
		SF_BigInt	*counter;
	} validation;				// (optional)
} SF_DH_Parameters;

/**
 *	Error codes
 */

//	SF_COMMOM_ERROR_INVALID_INPUT
//	SF_COMMOM_ERROR_MALLOC_FAILED
//
//	SF_ASN1_ERROR_BAD_DATA
//	SF_ASN1_ERROR_BAD_LENGTH
//
//	SF_DH_ERROR_INVALID_PARAMETERS
//	SF_DH_ERROR_INVALID_PUBLIC_KEY
//	SF_DH_ERROR_INVALID_KEY_PAIR

/**
 *	Prototypes
 */

#ifdef __cplusplus
extern "C" {
#endif

SF_DH_Parameters *
			SF_DH_Parameters_New			(void);

void		SF_DH_Parameters_Free			(SF_DH_Parameters *params);

SF_ERROR	SF_DH_GenerateParameters		(SF_DH_Parameters *params, 
											 const SF_WORD primeByteLength,
											 const SF_WORD factorByteLength);

SF_ERROR	SF_DH_VerifyParameters			(const SF_DH_Parameters *params);

SF_ERROR	SF_DH_GenerateKey				(SF_BigInt *privKey, 
											 SF_BigInt *pubKey,
											 const SF_DH_Parameters *params);

SF_ERROR	SF_DH_VerifyPublicKey			(const SF_BigInt *pubKey,
											 const SF_DH_Parameters *params);

SF_ERROR	SF_DH_ProveKeyPair				(const SF_BigInt *privKey,
											 const SF_BigInt *pubKey,
											 const SF_DH_Parameters *params);

SF_ERROR	SF_DH_ComputeSharedSecret		(SF_BigInt *secret, 
											 const SF_DH_Parameters *params, 
											 const SF_BigInt *privKey, 
											 const SF_BigInt *pubKey);

// asn.1

SF_ERROR	SF_DH_Parameters_Encode			(SF_BYTE *output, 
											 SF_WORD *outputLength,
											 const SF_DH_Parameters *params);

SF_ERROR	SF_DH_Parameters_Decode			(SF_DH_Parameters *params,
											 const SF_BYTE *input, 
											 const SF_WORD inputLength);

SF_ERROR	SF_DH_PublicKey_Encode			(SF_BYTE *output, 
											 SF_WORD *outputLength,
											 const SF_BigInt *pubKey);

SF_ERROR	SF_DH_PublicKey_Decode			(SF_BigInt *pubKey,
											 const SF_BYTE *input, 
											 const SF_WORD inputLength);

#ifdef __cplusplus
}
#endif

#endif
