//
//	sf_pkey.h
//

#ifndef __SF_PKEY_H__
#define __SF_PKEY_H__

#include "sf_rsa.h"
#include "sf_pkcs1.h"
#include "sf_pkcs3.h"
#include "sf_dsa.h"
#include "sf_kcdsa.h"
#include "sf_ecdsa.h"
#include "sf_eckcdsa.h"

/**
 *	Constants
 */

#define	SF_PKEY_ID_RSA						1
#define	SF_PKEY_ID_DH						3
#define	SF_PKEY_ID_DSA						4
#define	SF_PKEY_ID_KCDSA					5
#define	SF_PKEY_ID_ECDSA					12
#define	SF_PKEY_ID_ECKCDSA					13

#define	SF_PKEY_SIGNID_RSA_V15_MD2			1
#define	SF_PKEY_SIGNID_RSA_V15_MD5			2
#define	SF_PKEY_SIGNID_RSA_V15_SHA1			3
#define	SF_PKEY_SIGNID_RSA_V15_SHA256		4
#define	SF_PKEY_SIGNID_RSA_V15_SHA384		5
#define	SF_PKEY_SIGNID_RSA_V15_SHA512		6
#define	SF_PKEY_SIGNID_RSA_V15_OTHER		9
#define	SF_PKEY_SIGNID_RSA_PSS				11
#define	SF_PKEY_SIGNID_DSA_SHA1				15
#define	SF_PKEY_SIGNID_KCDSA_SHA1			16
#define	SF_PKEY_SIGNID_KCDSA_HAS160			17
#define	SF_PKEY_SIGNID_KCDSA_SHA256			18
#define	SF_PKEY_SIGNID_KCDSA_SHA384			19
#define	SF_PKEY_SIGNID_KCDSA_SHA512			20
#define	SF_PKEY_SIGNID_ECDSA_SHA1			21
#define	SF_PKEY_SIGNID_ECKCDSA_SHA1			22
#define	SF_PKEY_SIGNID_ECKCDSA_HAS160		23

// 2007-12-17 by ssosuny: RFC 4055, Additional RSA Algorithms & Identifier {{
#define SF_PKEY_SIGNID_RSA_PSS_SHA224		31
#define SF_PKEY_SIGNID_RSA_PSS_SHA256		32
#define SF_PKEY_SIGNID_RSA_PSS_SHA384		33
#define SF_PKEY_SIGNID_RSA_PSS_SHA512		34
// }}

#define	SF_PKEY_PENCID_RSA_V15				1
#define	SF_PKEY_PENCID_RSA_OAEP				3

// 2007-12-17 by ssosuny: RFC 4055, Additional RSA Algorithms & Identifier {{
#define SF_PKEY_PENCID_RSA_OAEP_SHA224		11
#define SF_PKEY_PENCID_RSA_OAEP_SHA256		12
#define SF_PKEY_PENCID_RSA_OAEP_SHA384		13
#define SF_PKEY_PENCID_RSA_OAEP_SHA512		14
// }}

#define	SF_PKEY_MSGID_MESSAGE				0
#define	SF_PKEY_MSGID_HASH					1

/**
 *	Struct
 */

typedef struct {
	int			opID;
	void		*opCtx;
} SF_PKEY_CTX;

typedef struct {
	int			typeID;
	int			pkeyID;
	void		*params;
} SF_PKEY_Parameters;

typedef struct {
	int			typeID;
	int			pkeyID;
	void		*privKey;
} SF_PKEY_PrivateKey;

typedef struct {
	int			typeID;
	int			pkeyID;
	void		*pubKey;
} SF_PKEY_PublicKey;

// generate

typedef union {
	struct {
		SF_WORD		primeByteLength;		// 512/8, 1024/8, ...
		SF_WORD		factorByteLength;
	} dh;
	struct {
		SF_WORD		primeByteLength;		// 512/8, 1024/8, 2048/8
	} dsa, kcdsa;
//WIN32_CE
#ifndef _MIN_WCE
	struct {
		int			ncID;
	} ecdsa, eckcdsa;
#endif	//_MIN_WCE
} SF_PKEY_GenParamParam;

typedef union {
	struct {
		SF_WORD		keyByteLength;			// 512/8, 1024/8, 2048/8, ...
		SF_WORD		e;						// 3, 65537, optional
	} rsa;
} SF_PKEY_GenKeyPairParam;

// encrypt

typedef union {
	SF_PKCS1_OAEP_PARAM	rsa_oaep;
} SF_PKEY_PEncParam;

// sign

typedef union {
	SF_PKCS1_PSS_PARAM	rsa_pss;
	struct {
		SF_PKEY_PublicKey	*pkPubKey;
	} kcdsa, eckcdsa;
} SF_PKEY_SignParam;

/**
 *	Error codes
 */

//	SF_COMMON_ERROR_INVALID_INPUT
//
//	SF_HASH_ERROR_UNKNOWN_ID

/**
 *	Prototypes
 */

#ifdef __cplusplus
extern "C" {
#endif

// ctx

SF_PKEY_CTX *
			SF_PKEY_CTX_New					(void);

void		SF_PKEY_CTX_Free				(SF_PKEY_CTX *pkCtx);

// parameters

SF_PKEY_Parameters *
			SF_PKEY_Parameters_New			(void);

void		SF_PKEY_Parameters_Free			(SF_PKEY_Parameters *pkPrivKey);

SF_ERROR	SF_PKEY_Parameters_Encode		(SF_BYTE *output, 
											 SF_WORD *outputLength,
											 const SF_PKEY_Parameters *pkParams);

SF_ERROR	SF_PKEY_Parameters_Decode		(SF_PKEY_Parameters *pkParams,
											 const int pkeyID,
											 const SF_BYTE *input, 
											 const SF_WORD inputLength);

// privkey

SF_PKEY_PrivateKey *
			SF_PKEY_PrivateKey_New			(void);

void		SF_PKEY_PrivateKey_Free			(SF_PKEY_PrivateKey *pkPrivKey);

SF_ERROR	SF_PKEY_PrivateKey_Encode		(SF_BYTE *output, 
											 SF_WORD *outputLength,
											 const SF_PKEY_PrivateKey *pkPrivKey,
											 const void *param);					// optional

SF_ERROR	SF_PKEY_PrivateKey_Decode		(SF_PKEY_PrivateKey *pkPrivKey,
											 const int pkeyID,
											 const SF_BYTE *input, 
											 const SF_WORD inputLength,
											 const void *param);					// optional

// pubkey

SF_PKEY_PublicKey *
			SF_PKEY_PublicKey_New			(void);

void		SF_PKEY_PublicKey_Free			(SF_PKEY_PublicKey *pkPubKey);

SF_ERROR	SF_PKEY_PublicKey_Encode		(SF_BYTE *output, 
											 SF_WORD *outputLength,
											 const SF_PKEY_PublicKey *pkPubKey,
											 const SF_PKEY_Parameters *pkParams);

SF_ERROR	SF_PKEY_PublicKey_Decode		(SF_PKEY_PublicKey *pkPubKey,
											 const int pkeyID,
											 const SF_BYTE *input, 
											 const SF_WORD inputLength,
											 const SF_PKEY_Parameters *pkParams);

// generate

SF_ERROR	SF_PKEY_GenerateParameters		(SF_PKEY_Parameters *pkParams, 
											 const int pkeyID,
											 const SF_PKEY_GenParamParam *genParam);

SF_ERROR	SF_PKEY_VerifyParameters		(const SF_PKEY_Parameters *pkParams);

SF_ERROR	SF_PKEY_GenerateKeyPair			(SF_PKEY_PrivateKey *pkPrivKey, 
											 SF_PKEY_PublicKey *pkPubKey,
											 const int pkeyID,
											 const SF_PKEY_Parameters *pkParams,	// optional
											 const SF_PKEY_GenKeyPairParam *genParam);

SF_ERROR	SF_PKEY_VerifyPublicKey			(const SF_PKEY_PublicKey *pkPubKey,
											 const SF_PKEY_Parameters *pkParams);	// optional

SF_ERROR	SF_PKEY_ProveKeyPair			(const SF_PKEY_PrivateKey *pkPrivKey, 
											 const SF_PKEY_PublicKey *pkPubKey,
											 const SF_PKEY_Parameters *pkParams);

// encrypt

SF_ERROR	SF_PKEY_Encrypt					(SF_BYTE *cipher, 
											 SF_WORD *cipherLength, 
											 const SF_BYTE *plain, 
											 const SF_WORD plainLength,
											 const int pencID,
											 const SF_PKEY_PublicKey *pkPubKey,
											 const SF_PKEY_Parameters *pkParams,	// optional
											 const SF_PKEY_PEncParam *pencParam);	// optional

SF_ERROR	SF_PKEY_Decrypt					(SF_BYTE *plain, 
											 SF_WORD *plainLength, 
											 const SF_BYTE *cipher, 
											 const SF_WORD cipherLength,
											 const int pencID,
											 const SF_PKEY_PrivateKey *pkPrivKey,
											 const SF_PKEY_Parameters *pkParams,	// optional
											 const SF_PKEY_PEncParam *pencParam);	// optional

// sign

SF_ERROR	SF_PKEY_Sign					(SF_BYTE *signature, 
											 SF_WORD *signatureLength,
											 const int msgID,
											 const SF_BYTE *message, 
											 const SF_WORD messageLength,
											 const int signID,
											 const SF_PKEY_PrivateKey *pkPrivKey,
											 const SF_PKEY_Parameters *pkParams,	// optional
											 const SF_PKEY_SignParam *signParam);	// optional

SF_ERROR	SF_PKEY_Sign_Init				(SF_PKEY_CTX *pkCtx,
											 const int signID,
											 const SF_PKEY_PrivateKey *pkPrivKey,
											 const SF_PKEY_Parameters *pkParams,	// optional
											 const SF_PKEY_SignParam *signParam);	// optional

SF_ERROR	SF_PKEY_Sign_Update				(SF_PKEY_CTX *pkCtx,
											 const SF_BYTE *message, 
											 const SF_WORD messageLength);

SF_ERROR	SF_PKEY_Sign_Final				(SF_PKEY_CTX *pkCtx,
											 SF_BYTE *signature, 
											 SF_WORD *signatureLength);

SF_ERROR	SF_PKEY_Verify					(const SF_BYTE *signature, 
											 const SF_WORD signatureLength,
											 const int msgID,
											 const SF_BYTE *message, 
											 const SF_WORD messageLength,
											 const int signID,
											 const SF_PKEY_PublicKey *pkPubKey,
											 const SF_PKEY_Parameters *pkParams,	// optional
											 const SF_PKEY_SignParam *signParam);	// optional

SF_ERROR	SF_PKEY_Verify_Init				(SF_PKEY_CTX *pkCtx,
											 const int signID,
											 const SF_PKEY_PublicKey *pkPubKey,
											 const SF_PKEY_Parameters *pkParams,	// optional
											 const SF_PKEY_SignParam *signParam);	// optional

SF_ERROR	SF_PKEY_Verify_Update			(SF_PKEY_CTX *pkCtx,
											 const SF_BYTE *message, 
											 const SF_WORD messageLength);

SF_ERROR	SF_PKEY_Verify_Final			(SF_PKEY_CTX *pkCtx,
											 const SF_BYTE *signature, 
											 const SF_WORD signatureLength);

#ifdef __cplusplus
}
#endif

#endif
