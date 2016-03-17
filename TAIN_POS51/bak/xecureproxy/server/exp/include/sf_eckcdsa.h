//
//	$Id: sf_eckcdsa.h,v 1.4 2006/01/11 07:27:33 ssosuny Exp $
//
//WIN32_CE
#ifndef _MIN_WCE

#ifndef __SF_ECKCDSA_H__
#define __SF_ECKCDSA_H__

#include "sf_hash.h"
#include "sf_bigint.h"
#include "sf_ec.h"

/**
 *	Constants
 */

#define	SF_ECKCDSA_HASHID_SHA1				SF_HASH_ID_SHA1
#define	SF_ECKCDSA_HASHID_HAS160			SF_HASH_ID_HAS160

/**
 *	Struct
 */

typedef struct {
	SF_EC_Group		*group;		// EC group structure
} SF_ECKCDSA_Parameters;

typedef struct {
	SF_BYTE			r[SF_HAS160_DIGEST_SIZE];	// 20 bytes
	SF_BigInt		*s;
} SF_ECKCDSA_Signature;

/**
 *	Error codes
 */

//	SF_COMMOM_ERROR_INVALID_INPUT
//	SF_COMMOM_ERROR_MALLOC_FAILED
//
//	SF_ASN1_ERROR_BAD_DATA
//	SF_ASN1_ERROR_BAD_LENGTH
//
//	SF_ECKCDSA_ERROR_INVALID_PUBLIC_KEY
//	SF_ECKCDSA_ERROR_INVALID_KEY_PAIR
//	SF_ECKCDSA_ERROR_INVALID_SIGNATURE

/**
 *	Prototypes
 */

#ifdef __cplusplus
extern "C" {
#endif

SF_ECKCDSA_Parameters *
			SF_ECKCDSA_Parameters_New		(void);

void		SF_ECKCDSA_Parameters_Free		(SF_ECKCDSA_Parameters *params);

SF_ECKCDSA_Signature *
			SF_ECKCDSA_Signature_New		(void);

void		SF_ECKCDSA_Signature_Free		(SF_ECKCDSA_Signature *signature);

SF_ERROR	SF_ECKCDSA_GenerateKey			(SF_BigInt *privKey,
											 SF_EC_Point *pubKey,
											 const SF_ECKCDSA_Parameters *params);

SF_ERROR	SF_ECKCDSA_VerifyPublicKey		(const SF_EC_Point *pubKey,
											 const SF_ECKCDSA_Parameters *params);

SF_ERROR	SF_ECKCDSA_ProveKeyPair			(const SF_BigInt *privKey,
											 const SF_EC_Point *pubKey,
											 const SF_ECKCDSA_Parameters *params);

SF_ERROR	SF_ECKCDSA_Hash					(SF_BYTE *hash,
											 SF_WORD *hashLength,
											 const SF_BYTE *message,
											 const SF_WORD messageLength,
											 const int hashID,
											 const SF_EC_Point *pubKey,
											 const SF_ECKCDSA_Parameters *params);

SF_ERROR	SF_ECKCDSA_Sign					(SF_ECKCDSA_Signature *signature, 
											 const int hashID,
											 const SF_BYTE *hash, 
											 const SF_WORD hashLength,
											 const SF_ECKCDSA_Parameters *params, 
											 const SF_BigInt *privKey);

SF_ERROR	SF_ECKCDSA_Verify				(const SF_ECKCDSA_Signature *signature, 
											 const int hashID,
											 const SF_BYTE *hash, 
											 const SF_WORD hashLength,
											 const SF_ECKCDSA_Parameters *params, 
											 const SF_EC_Point *pubKey);

// asn.1

SF_ERROR	SF_ECKCDSA_Parameters_Encode	(SF_BYTE *output, 
											 SF_WORD *outputLength,
											 const SF_ECKCDSA_Parameters *params);

SF_ERROR	SF_ECKCDSA_Parameters_Decode	(SF_ECKCDSA_Parameters *params,
											 const SF_BYTE *input, 
											 const SF_WORD inputLength);

SF_ERROR	SF_ECKCDSA_Signature_Encode		(SF_BYTE *output, 
											 SF_WORD *outputLength,
											 const SF_ECKCDSA_Signature *signature);

SF_ERROR	SF_ECKCDSA_Signature_Decode		(SF_ECKCDSA_Signature *signature,
											 const SF_BYTE *input, 
											 const SF_WORD inputLength);

SF_ERROR	SF_ECKCDSA_PublicKey_Encode		(SF_BYTE *output, 
											 SF_WORD *outputLength,
											 const int inputSize,
											 const SF_EC_Point *pubKey,
											 const SF_ECKCDSA_Parameters *params);

SF_ERROR	SF_ECKCDSA_PublicKey_Decode		(SF_EC_Point *pubKey,
											 const SF_BYTE *input, 
											 const SF_WORD inputLength,
											 const SF_ECKCDSA_Parameters *params);

#ifdef __cplusplus
}
#endif

#endif

#endif	//_MIN_WCE