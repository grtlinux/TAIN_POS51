//
//	$Id: sf_ecdsa.h,v 1.6 2007/12/20 00:48:43 ssosuny Exp $
//
//WIN32_CE
#ifndef _MIN_WCE

#ifndef __SF_ECDSA_H__
#define __SF_ECDSA_H__

#include "sf_ec.h"

/**
 *	Struct
 */

typedef struct {
	SF_EC_Group		*group;		// EC group structure
} SF_ECDSA_Parameters;

typedef struct {
	SF_BigInt		*r;
	SF_BigInt		*s;
} SF_ECDSA_Signature;

/**
 *	Error codes
 */

//	SF_COMMOM_ERROR_INVALID_INPUT
//	SF_COMMOM_ERROR_MALLOC_FAILED
//
//	SF_ASN1_ERROR_BAD_DATA
//	SF_ASN1_ERROR_BAD_LENGTH
//
//	SF_ECDSA_ERROR_INVALID_PUBLIC_KEY
//	SF_ECDSA_ERROR_INVALID_KEY_PAIR
//	SF_ECDSA_ERROR_INVALID_SIGNATURE

/**
 *	Prototypes
 */

#ifdef __cplusplus
extern "C" {
#endif

SF_ECDSA_Parameters *
			SF_ECDSA_Parameters_New			(void);

void		SF_ECDSA_Parameters_Free		(SF_ECDSA_Parameters *params);

SF_ECDSA_Signature *
			SF_ECDSA_Signature_New			(void);

void		SF_ECDSA_Signature_Free			(SF_ECDSA_Signature *signature);

SF_ERROR	SF_ECDSA_GenerateKey			(SF_BigInt *privKey, 
											 SF_EC_Point *pubKey,
											 const SF_ECDSA_Parameters *params);

SF_ERROR	SF_ECDSA_VerifyPublicKey		(const SF_EC_Point *pubKey,
											 const SF_ECDSA_Parameters *params);

SF_ERROR	SF_ECDSA_ProveKeyPair			(const SF_BigInt *privKey,
											 const SF_EC_Point *pubKey,
											 const SF_ECDSA_Parameters *params);

SF_ERROR	SF_ECDSA_Sign					(SF_ECDSA_Signature *signature, 
											 const SF_BYTE *sha1Hash,
											 const SF_ECDSA_Parameters *params, 
											 const SF_BigInt *privKey);

SF_ERROR	SF_ECDSA_Verify					(const SF_ECDSA_Signature *signature, 
											 const SF_BYTE *sha1Hash,
											 const SF_ECDSA_Parameters *params, 
											 const SF_EC_Point *pubKey);

// asn.1

SF_ERROR	SF_ECDSA_Parameters_Encode		(SF_BYTE *output, 
											 SF_WORD *outputLength,
											 const SF_ECDSA_Parameters *params);

SF_ERROR	SF_ECDSA_Parameters_Decode		(SF_ECDSA_Parameters *params,
											 const SF_BYTE *input, 
											 const SF_WORD inputLength);

SF_ERROR	SF_ECDSA_Signature_Encode		(SF_BYTE *output, 
											 SF_WORD *outputLength,
											 const SF_ECDSA_Signature *signature);

SF_ERROR	SF_ECDSA_Signature_Decode		(SF_ECDSA_Signature *signature,
											 const SF_BYTE *input, 
											 const SF_WORD inputLength);

SF_ERROR	SF_ECDSA_PublicKey_Encode		(SF_BYTE *output, 
											 SF_WORD *outputLength,
											 const int inputSize,
											 const SF_EC_Point *pubKey,
											 const SF_ECDSA_Parameters *params);

SF_ERROR	SF_ECDSA_PublicKey_Decode		(SF_EC_Point *pubKey,
											 const SF_BYTE *input, 
											 const SF_WORD inputLength,
											 const SF_ECDSA_Parameters *params);

#ifdef __cplusplus
}
#endif

#endif

#endif	//_MIN_WCE