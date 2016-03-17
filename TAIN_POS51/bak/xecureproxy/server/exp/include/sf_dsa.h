//
//	$Id: sf_dsa.h,v 1.6 2006/01/11 07:27:33 ssosuny Exp $
//
//WIN32_CE
#ifndef _MIN_WCE

#ifndef __SF_DSA_H__
#define __SF_DSA_H__

#include "sf_bigint.h"

/**
 *	Struct
 */

typedef struct {
	SF_BigInt		*p;			// prime modulus
	SF_BigInt		*q;			// prime divisor of p-1
	SF_BigInt		*g;			// base (generator)
} SF_DSA_Parameters;

typedef struct {
	SF_BigInt		*r;
	SF_BigInt		*s;
} SF_DSA_Signature;

/**
 *	Error codes
 */

//	SF_COMMOM_ERROR_INVALID_INPUT
//	SF_COMMOM_ERROR_MALLOC_FAILED
//
//	SF_ASN1_ERROR_BAD_DATA
//	SF_ASN1_ERROR_BAD_LENGTH
//
//	SF_DSA_ERROR_INVALID_SIGNATURE

/**
 *	Prototypes
 */

#ifdef __cplusplus
extern "C" {
#endif

SF_DSA_Parameters *
			SF_DSA_Parameters_New			(void);

void		SF_DSA_Parameters_Free			(SF_DSA_Parameters *params);

SF_DSA_Signature *
			SF_DSA_Signature_New			(void);

void		SF_DSA_Signature_Free			(SF_DSA_Signature *signature);

SF_ERROR	SF_DSA_GenerateParameters		(SF_DSA_Parameters *params, 
											const SF_WORD primeByteLength);

SF_ERROR	SF_DSA_VerifyParameters			(const SF_DSA_Parameters *params);

SF_ERROR	SF_DSA_GenerateKey				(SF_BigInt *privKey, 
											 SF_BigInt *pubKey,
											 const SF_DSA_Parameters *params);

SF_ERROR	SF_DSA_VerifyPublicKey			(const SF_BigInt *pubKey,
											 const SF_DSA_Parameters *params);

SF_ERROR	SF_DSA_ProveKeyPair				(const SF_BigInt *privKey,
											 const SF_BigInt *pubKey,
											 const SF_DSA_Parameters *params);

SF_ERROR	SF_DSA_Sign						(SF_DSA_Signature *signature, 
											 const SF_BYTE *sha1Hash,
											 const SF_DSA_Parameters *params, 
											 const SF_BigInt *privKey);

SF_ERROR	SF_DSA_Verify					(const SF_DSA_Signature *signature, 
											 const SF_BYTE *sha1Hash,
											 const SF_DSA_Parameters *params, 
											 const SF_BigInt *pubKey);

// asn.1

SF_ERROR	SF_DSA_Parameters_Encode		(SF_BYTE *output, 
											 SF_WORD *outputLength,
											 const SF_DSA_Parameters *params);

SF_ERROR	SF_DSA_Parameters_Decode		(SF_DSA_Parameters *params,
											 const SF_BYTE *input, 
											 const SF_WORD inputLength);

SF_ERROR	SF_DSA_Signature_Encode			(SF_BYTE *output, 
											 SF_WORD *outputLength,
											 const SF_DSA_Signature *signature);

SF_ERROR	SF_DSA_Signature_Decode			(SF_DSA_Signature *signature,
											 const SF_BYTE *input, 
											 const SF_WORD inputLength);

SF_ERROR	SF_DSA_PublicKey_Encode			(SF_BYTE *output, 
											 SF_WORD *outputLength,
											 const SF_BigInt *pubKey);

SF_ERROR	SF_DSA_PublicKey_Decode			(SF_BigInt *pubKey,
											 const SF_BYTE *input, 
											 const SF_WORD inputLength);

#ifdef __cplusplus
}
#endif

#endif

#endif //_MIN_WCE