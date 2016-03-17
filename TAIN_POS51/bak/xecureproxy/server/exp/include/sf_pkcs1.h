//
//	sf_pkcs1.h
//

#ifndef __SF_PKCS1_H__
#define __SF_PKCS1_H__

#include "sf_hash.h"
#include "sf_rsa.h"

/**
 *	Constants
 */

#define	SF_PKCS1_HASHID_MD2					SF_HASH_ID_MD2
#define	SF_PKCS1_HASHID_MD5					SF_HASH_ID_MD5
#define	SF_PKCS1_HASHID_SHA1				SF_HASH_ID_SHA1
#define SF_PKCS1_HASHID_SHA224				SF_HASH_ID_SHA224
#define	SF_PKCS1_HASHID_SHA256				SF_HASH_ID_SHA256
#define	SF_PKCS1_HASHID_SHA384				SF_HASH_ID_SHA384
#define	SF_PKCS1_HASHID_SHA512				SF_HASH_ID_SHA512
#define SF_PKCS1_HASHID_HAS160				SF_HASH_ID_HAS160

#define	SF_PKCS1_MGFID_MGF1_SHA1			1
// 2007-12-17by ssosuny: RFC 4055, Additional RSA Algorithms & Identifier {{
#define	SF_PKCS1_MGFID_MGF1_SHA224			2
#define	SF_PKCS1_MGFID_MGF1_SHA256			3
#define	SF_PKCS1_MGFID_MGF1_SHA384			4
#define	SF_PKCS1_MGFID_MGF1_SHA512			5
// }}

#define	SF_PKCS1_SOURCEID_SPECIFIED			1

/**
 *	Struct
 */

typedef struct {
	int			hashID;
	int			mgfID;
	int			sourceID;
	SF_BYTE		*source;
	SF_WORD		sourceLength;
} SF_PKCS1_OAEP_PARAM;

typedef struct {
	int			hashID;
	int			mgfID;
} SF_PKCS1_PSS_PARAM;

/**
 *	Error codes
 */

//	SF_COMMON_ERROR_INVALID_INPUT
//	SF_COMMON_ERROR_INTERNAL
//	SF_COMMON_ERROR_MALLOC_FAILED
//
//	SF_ASN1_ERROR_BAD_DATA
//	SF_ASN1_ERROR_BAD_LENGTH
//
//	SF_PKCS1_ERROR_UNKNOWN_ID
//	SF_PKCS1_ERROR_DECODING_ERROR
//	SF_PKCS1_ERROR_DECRYPTION_ERROR
//	SF_PKCS1_ERROR_ENCODING_ERROR
//	SF_PKCS1_ERROR_INCONSISTENT
//	SF_PKCS1_ERROR_INTEGER_TOO_LARGE
//	SF_PKCS1_ERROR_INTENDED_MSG_LENGTH_TOO_SHORT
//	SF_PKCS1_ERROR_INVALID_SIGNATURE
//	SF_PKCS1_ERROR_MESSAGE_TOO_LONG
//	SF_PKCS1_ERROR_MODULUS_TOO_SHORT
//	SF_PKCS1_ERROR_PARAMETER_STRING_TOO_LONG

/**
 *	Prototypes
 */

#ifdef __cplusplus
extern "C" {
#endif

SF_ERROR	SF_PKCS1_I2OSP					(SF_BYTE *output, 
											 const SF_WORD outputLength, 
											 const SF_BigInt *input);

SF_ERROR	SF_PKCS1_OS2IP					(SF_BigInt *output, 
											 const SF_BYTE *input, 
											 const SF_WORD inputLength);

// mask generating functions

SF_ERROR	SF_PKCS1_MGF1					(SF_BYTE *output, 
											 const SF_WORD outputLength, 
											 const SF_BYTE *seed, 
											 const SF_WORD seedLength,
											 const SF_WORD hashID);

// encoding methods

SF_ERROR	SF_PKCS1_EME_V15_Encode			(SF_BYTE *output, 
											 const SF_WORD outputLength, 
											 const SF_BYTE *input, 
											 const SF_WORD inputLength);

SF_ERROR	SF_PKCS1_EME_V15_Decode			(SF_BYTE *output, 
											 SF_WORD *outputLength, 
											 const SF_BYTE *input, 
											 const SF_WORD inputLength);

SF_ERROR	SF_PKCS1_EME_OAEP_Encode		(SF_BYTE *output, 
											 const SF_WORD outputLength, 
											 const SF_BYTE *input, 
											 const SF_WORD inputLength,
											 const SF_PKCS1_OAEP_PARAM *oaepParam);

SF_ERROR	SF_PKCS1_EME_OAEP_Decode		(SF_BYTE *output, 
											 SF_WORD *outputLength, 
											 const SF_BYTE *input, 
											 const SF_WORD inputLength,
											 const SF_PKCS1_OAEP_PARAM *oaepParam);

SF_ERROR	SF_PKCS1_EMSA_V15_Encode		(SF_BYTE *output, 
											 const SF_WORD outputLength, 
											 const SF_WORD hashID, 
											 const SF_BYTE *hash, 
											 const SF_WORD hashLength);

SF_ERROR	SF_PKCS1_EMSA_PSS_Encode		(SF_BYTE *output, 
											 SF_WORD outputBitLength, 
											 const SF_BYTE *hash, 
											 const SF_WORD hashLength,
											 const SF_WORD saltLength,
											 const SF_PKCS1_PSS_PARAM *pssParam);

SF_ERROR	SF_PKCS1_EMSA_PSS_Verify		(const SF_BYTE *encMessage, 
											 const SF_WORD encMessageBitLength,
											 const SF_BYTE *hash, 
											 const SF_WORD hashLength,
											 const SF_PKCS1_PSS_PARAM *pssParam);

// encryption schemes

SF_ERROR	SF_PKCS1_V15_Encrypt			(SF_BYTE *cipher, 
											 SF_WORD *cipherLength, 
											 const SF_BYTE *plain, 
											 const SF_WORD plainLength, 
											 const SF_RSA_PublicKey *pubKey);

SF_ERROR	SF_PKCS1_V15_Decrypt			(SF_BYTE *plain, 
											 SF_WORD *plainLength, 
											 const SF_BYTE *cipher, 
											 const SF_WORD cipherLength, 
											 const SF_RSA_PrivateKey *privKey);

SF_ERROR	SF_PKCS1_OAEP_Encrypt			(SF_BYTE *cipher, 
											 SF_WORD *cipherLength, 
											 const SF_BYTE *plain, 
											 const SF_WORD plainLength,
											 const SF_RSA_PublicKey *pubKey,
											 const SF_PKCS1_OAEP_PARAM *oaepParam);

SF_ERROR	SF_PKCS1_OAEP_Decrypt			(SF_BYTE *plain, 
											 SF_WORD *plainLength, 
											 const SF_BYTE *cipher, 
											 const SF_WORD cipherLength,
											 const SF_RSA_PrivateKey *privKey,
											 const SF_PKCS1_OAEP_PARAM *oaepParam);

// signature schemes

SF_ERROR	SF_PKCS1_V15_Sign				(SF_BYTE *signature, 
											 SF_WORD *signatureLength,
											 const SF_WORD hashID, 
											 const SF_BYTE *hash, 
											 const SF_WORD hashLength, 
											 const SF_RSA_PrivateKey *privKey);

SF_ERROR	SF_PKCS1_V15_Verify				(const SF_BYTE *signature, 
											 const SF_WORD signatureLength, 
											 const SF_WORD hashID, 
											 const SF_BYTE *hash, 
											 const SF_WORD hashLength, 
											 const SF_RSA_PublicKey *pubKey);

SF_ERROR	SF_PKCS1_PSS_Sign				(SF_BYTE *signature, 
											 SF_WORD *signatureLength,
											 const SF_BYTE *hash, 
											 const SF_WORD hashLength, 
											 const SF_RSA_PrivateKey *privKey,
											 const SF_PKCS1_PSS_PARAM *pssParam);

SF_ERROR	SF_PKCS1_PSS_Verify				(const SF_BYTE *signature, 
											 const SF_WORD signatureLength, 
											 const SF_BYTE *hash, 
											 const SF_WORD hashLength, 
											 const SF_RSA_PublicKey *pubKey,
											 const SF_PKCS1_PSS_PARAM *pssParam);

// asn.1

SF_ERROR	SF_PKCS1_PrivateKey_Encode		(SF_BYTE *output, 
											 SF_WORD *outputLength, 
											 const SF_RSA_PrivateKey *privKey);

SF_ERROR	SF_PKCS1_PrivateKey_Decode		(SF_RSA_PrivateKey *privKey, 
											 const SF_BYTE *input, 
											 const SF_WORD inputLength);

SF_ERROR	SF_PKCS1_PublicKey_Encode		(SF_BYTE *output, 
											 SF_WORD *outputLength, 
											 const SF_RSA_PublicKey *pubKey);

SF_ERROR	SF_PKCS1_PublicKey_Decode		(SF_RSA_PublicKey *pubKey, 
											 const SF_BYTE *input, 
											 const SF_WORD inputLength);

#ifdef __cplusplus
}
#endif

#endif
