//
//	$Id: sf_kcdsa.h,v 1.7 2005/03/04 05:23:59 guspin Exp $
//

#ifndef __SF_KCDSA_H__
#define __SF_KCDSA_H__

#include "sf_hash.h"
#include "sf_bigint.h"

/**
 *	Constants
 */

#define	SF_KCDSA_HASHID_SHA1				SF_HASH_ID_SHA1
#define	SF_KCDSA_HASHID_HAS160				SF_HASH_ID_HAS160
#define SF_KCDSA_HASHID_SHA256				SF_HASH_ID_SHA256
#define SF_KCDSA_HASHID_SHA384				SF_HASH_ID_SHA384
#define SF_KCDSA_HASHID_SHA512				SF_HASH_ID_SHA512

/**
 *	Struct
 */

typedef struct {
	SF_BigInt		*p;			// prime modulus p = 2jq+1
	SF_BigInt		*q;			// prime divisor of p-1
	SF_BigInt		*g;			// base (generator)
	
	SF_BigInt		*j;			// subgroup factor (optional)
	struct {
		SF_BYTE		*seed;		// 160/8 ~ 256/8 bytes
		SF_WORD		seedLength;
		SF_BigInt	*counter;
	} validation;				// (optional)
} SF_KCDSA_Parameters;

typedef struct {
	SF_BYTE			r[64]; /* Expand array size for SHA256 ~ SHA512 */
	SF_BigInt		*s;
} SF_KCDSA_Signature;

/**
 *	Error codes
 */

//	SF_COMMOM_ERROR_INVALID_INPUT
//	SF_COMMOM_ERROR_MALLOC_FAILED
//
//	SF_ASN1_ERROR_BAD_DATA
//	SF_ASN1_ERROR_BAD_LENGTH
//
//	SF_KCDSA_ERROR_INVALID_PARAMETERS
//	SF_KCDSA_ERROR_INVALID_PUBLIC_KEY
//	SF_KCDSA_ERROR_INVALID_KEY_PAIR
//	SF_KCDSA_ERROR_INVALID_SIGNATURE

/**
 *	Prototypes
 */

#ifdef __cplusplus
extern "C" {
#endif

SF_KCDSA_Parameters *
			SF_KCDSA_Parameters_New			(void);

void		SF_KCDSA_Parameters_Free		(SF_KCDSA_Parameters *params);

SF_KCDSA_Signature *
			SF_KCDSA_Signature_New			(void);

void		SF_KCDSA_Signature_Free			(SF_KCDSA_Signature *signature);

SF_ERROR	SF_KCDSA_GenerateParameters		(SF_KCDSA_Parameters *params, 
											 const SF_WORD primeByteLength);

SF_ERROR	SF_KCDSA_VerifyParameters		(const SF_KCDSA_Parameters *params);

SF_ERROR	SF_KCDSA_GenerateKey			(SF_BigInt *privKey, 
											 SF_BigInt *pubKey,
											 const SF_KCDSA_Parameters *params);

SF_ERROR	SF_KCDSA_VerifyPublicKey		(const SF_BigInt *pubKey,
											 const SF_KCDSA_Parameters *params);

SF_ERROR	SF_KCDSA_ProveKeyPair			(const SF_BigInt *privKey, 
											 const SF_BigInt *pubKey,
											 const SF_KCDSA_Parameters *params);

SF_ERROR	SF_KCDSA_Hash					(SF_BYTE *hash, 
											 SF_WORD *hashLength,
											 const SF_BYTE *message,
											 const SF_WORD messageLength,
											 const int hashID,
											 const SF_BigInt *pubKey);

SF_ERROR	SF_KCDSA_Sign					(SF_KCDSA_Signature *signature, 
											 const int hashID,
											 const SF_BYTE *hash, 
											 const SF_WORD hashLength,
											 const SF_KCDSA_Parameters *params, 
											 const SF_BigInt *privKey);

SF_ERROR	SF_KCDSA_Verify					(const SF_KCDSA_Signature *signature, 
											 const int hashID,
											 const SF_BYTE *hash, 
											 const SF_WORD hashLength,
											 const SF_KCDSA_Parameters *params, 
											 const SF_BigInt *pubKey);

// asn.1

SF_ERROR	SF_KCDSA_Parameters_Encode		(SF_BYTE *output, 
											 SF_WORD *outputLength,
											 const SF_KCDSA_Parameters *params);

SF_ERROR	SF_KCDSA_Parameters_Decode		(SF_KCDSA_Parameters *params,
											 const SF_BYTE *input, 
											 const SF_WORD inputLength);

SF_ERROR	SF_KCDSA_Signature_Encode		(SF_BYTE *output, 
											 SF_WORD *outputLength,
											 const SF_KCDSA_Signature *signature,
											 const SF_WORD hashID);

SF_ERROR	SF_KCDSA_Signature_Decode		(SF_KCDSA_Signature *signature,
											 const SF_BYTE *input, 
											 const SF_WORD inputLength,
											 const SF_WORD hashID);

SF_ERROR	SF_KCDSA_PublicKey_Encode		(SF_BYTE *output, 
											 SF_WORD *outputLength,
											 const SF_BigInt *pubKey);

SF_ERROR	SF_KCDSA_PublicKey_Decode		(SF_BigInt *pubKey,
											 const SF_BYTE *input, 
											 const SF_WORD inputLength);

#ifdef __cplusplus
}
#endif

#endif
