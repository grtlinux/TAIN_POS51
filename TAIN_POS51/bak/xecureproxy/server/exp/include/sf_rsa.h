//
//	$Id: sf_rsa.h,v 1.5 2004/11/10 02:01:26 guspin Exp $
//

#ifndef __SF_RSA_H__
#define __SF_RSA_H__

#include "sf_bigint.h"

/**
 *	Struct
 */

typedef struct{
    SF_BigInt		*n;			// modulus
	SF_BigInt		*e;			// publicExponent
} SF_RSA_PublicKey;

typedef struct{
	SF_BigInt		*n;			//	modulus
	SF_BigInt		*e;			//	publicExponent
	SF_BigInt		*d;			//	privateExponent
	SF_BigInt		*p;			//	prime1 (optional)
	SF_BigInt		*q;			//	prime2 (optional)
	SF_BigInt		*dP;		//	exponent1 (optional)
	SF_BigInt		*dQ;		//	exponent2 (optional)
	SF_BigInt		*qInv;		//	coefficient (optional)
} SF_RSA_PrivateKey;

/**
 *	Error codes
 */

//	SF_COMMON_ERROR_INVALID_INPUT
//	SF_COMMON_ERROR_MALLOC_FAILED
//
//	SF_RSA_ERROR_INPUT_TOO_LARGE
//	SF_RSA_ERROR_INVALID_KEY_PAIR

/**
 *	Prototypes
 */

#ifdef __cplusplus
extern "C" {
#endif

SF_RSA_PublicKey *
			SF_RSA_PublicKey_New			(void);

void		SF_RSA_PublicKey_Free			(SF_RSA_PublicKey *pubKey);

SF_RSA_PrivateKey *
			SF_RSA_PrivateKey_New			(void);

void		SF_RSA_PrivateKey_Free			(SF_RSA_PrivateKey *privKey);

SF_ERROR	SF_RSA_GenerateKey				(SF_RSA_PrivateKey *privKey, 
											 SF_RSA_PublicKey *pubKey, 
											 const SF_WORD keyByteLength, 
											 const SF_BigInt *e);

SF_ERROR	SF_RSA_ProveKeyPair				(const SF_RSA_PrivateKey *privKey,
											 const SF_RSA_PublicKey *pubKey);

SF_ERROR	SF_RSA_PublicKeyExp				(SF_BigInt *output, 
											 const SF_BigInt *input, 
											 const SF_RSA_PublicKey *pubKey);

SF_ERROR	SF_RSA_PrivateKeyExp			(SF_BigInt *output, 
											 const SF_BigInt *input, 
											 const SF_RSA_PrivateKey *privKey);

#ifdef __cplusplus
}
#endif

#endif
