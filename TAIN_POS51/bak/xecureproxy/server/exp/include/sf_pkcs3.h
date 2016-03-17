//
//	sf_pkcs3.h
//

#ifndef __SF_PKCS3_H__
#define __SF_PKCS3_H__

#include "sf_dh.h"

/**
 *	Error codes
 */

//	SF_COMMOM_ERROR_INVALID_INPUT
//	SF_COMMON_ERROR_INTERNAL
//	SF_COMMOM_ERROR_MALLOC_FAILED
//
//	SF_ASN1_ERROR_BAD_DATA
//	SF_ASN1_ERROR_BAD_LENGTH

/**
 *	Prototypes
 */

#ifdef __cplusplus
extern "C" {
#endif

SF_ERROR	SF_PKCS3_GenerateKey			(SF_BigInt *privKey, 
											 SF_BYTE *pubKey, 
											 SF_WORD *pubKeyLength,
											 const SF_DH_Parameters *params);

SF_ERROR	SF_PKCS3_ComputeSharedSecret	(SF_BYTE *secret, 
											 SF_WORD *secretLength,
											 const SF_DH_Parameters *params, 
											 const SF_BigInt *privKey, 
											 const SF_BYTE *pubKey, 
											 const SF_WORD pubKeyLength);

// asn.1

SF_ERROR	SF_PKCS3_Parameters_Encode		(SF_BYTE *output, 
											 SF_WORD *outputLength,
											 const SF_DH_Parameters *params);

SF_ERROR	SF_PKCS3_Parameters_Decode		(SF_DH_Parameters *params,
											 const SF_BYTE *input, 
											 const SF_WORD inputLength);

#ifdef __cplusplus
}
#endif

#endif
