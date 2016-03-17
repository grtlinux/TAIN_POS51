//
//	sf_cmvp.h
//
//WIN32_CE
#ifndef _MIN_WCE

#ifndef __SF_CMVP_H__
#define __SF_CMVP_H__

#include "sf_cipher.h"
#include "sf_hash.h"
#include "sf_mac.h"
#include "sf_rand.h"
#include "sf_pkey.h"


/**
 *	Constants
 */

// state

#define	SF_STATE_ID_LOADED					1
#define	SF_STATE_ID_GENERAL					3
#define	SF_STATE_ID_KCMVP					5
#define	SF_STATE_ID_ERROR					9
#define	SF_STATE_ID_FINALIZED				11

// key

#define	SF_KEY_ID_AES					SF_CIPHER_ID_AES
#define	SF_KEY_ID_BLOWFISH				SF_CIPHER_ID_BLOWFISH
#define	SF_KEY_ID_CAST128				SF_CIPHER_ID_CAST128
#define	SF_KEY_ID_DES					SF_CIPHER_ID_DES
#define SF_KEY_ID_RC2					SF_CIPHER_ID_RC2
#define SF_KEY_ID_RC4					SF_CIPHER_ID_RC4
#define SF_KEY_ID_RC5					SF_CIPHER_ID_RC5
#define SF_KEY_ID_SEED					SF_CIPHER_ID_SEED
#define SF_KEY_ID_SKIPJACK				SF_CIPHER_ID_SKIPJACK
#define SF_KEY_ID_TDES					SF_CIPHER_ID_TDES
#define	SF_KEY_ID_ARIA					SF_CIPHER_ID_ARIA

#define	SF_KEY_ID_HMAC_MD2				SF_MAC_ID_HMAC_MD2
#define	SF_KEY_ID_HMAC_MD5				SF_MAC_ID_HMAC_MD5
#define	SF_KEY_ID_HMAC_SHA1				SF_MAC_ID_HMAC_SHA1
#define	SF_KEY_ID_HMAC_HAS160			SF_MAC_ID_HMAC_HAS160
#define	SF_KEY_ID_HMAC_RIPEMD160		SF_MAC_ID_HMAC_RIPEMD160
#define	SF_KEY_ID_HMAC_SHA256			SF_MAC_ID_HMAC_SHA256
#define	SF_KEY_ID_HMAC_SHA384			SF_MAC_ID_HMAC_SHA384
#define	SF_KEY_ID_HMAC_SHA512			SF_MAC_ID_HMAC_SHA512
#define SF_KEY_ID_CBCMAC_AES			SF_MAC_ID_CBCMAC_AES
#define SF_KEY_ID_CBCMAC_BLOWFISH		SF_MAC_ID_CBCMAC_BLOWFISH
#define SF_KEY_ID_CBCMAC_CAST128		SF_MAC_ID_CBCMAC_CAST128
#define SF_KEY_ID_CBCMAC_DES			SF_MAC_ID_CBCMAC_DES
#define SF_KEY_ID_CBCMAC_RC2			SF_MAC_ID_CBCMAC_RC2
#define SF_KEY_ID_CBCMAC_RC5			SF_MAC_ID_CBCMAC_RC5
#define SF_KEY_ID_CBCMAC_SEED			SF_MAC_ID_CBCMAC_SEED
#define SF_KEY_ID_CBCMAC_SKIPJACK		SF_MAC_ID_CBCMAC_SKIPJACK
#define SF_KEY_ID_CBCMAC_TDES			SF_MAC_ID_CBCMAC_TDES
#define SF_KEY_ID_CBCMAC_DES_WITHPAD	SF_MAC_ID_CBCMAC_DES_WITHPAD
#define SF_KEY_ID_MD5MAC				SF_MAC_ID_MD5MAC

// cipher
#define SFC_CIPHER_ID_NEAT			SF_CIPHER_ID_NEAT
#define SFC_CIPHER_ID_NES			SF_CIPHER_ID_NES


// big integer
#define DEFAULT_MEMALLOC_LENGTH			(32+1)
// exp

#define	SF_EXP_ID_ARIA_CBC_SHA1				1

/**
 *	Struct
 */
// SFC_SKEY_SecretKey 구조 새로 정의
typedef struct {
	int			cipherID;
	SF_BYTE		key[SF_CIPHER_MAX_KEY_SIZE];
	SF_WORD		keyLength;
} SFC_SKEY_SecretKey;

// 별도의 BigInt 구현을 위한 구조체 새로 정의
typedef struct {
	int			MemLength;
	int			Length;
	int 		Sign;
	SF_WORD 	*Data;
} SFC_BigInt;

#define	SFC_CIPHER_SUITE_PARAM		SF_CIPHER_SUITE_PARAM	
#define SFC_CIPHER_PARAM			SF_CIPHER_PARAM			

#define SFC_CIPHER_CTX			SF_CIPHER_CTX
#define SFC_HASH_CTX			SF_HASH_CTX
#define SFC_MAC_CTX				SF_MAC_CTX

typedef struct {
	int			opID;
	void		*opCtx;
} SFC_PKEY_CTX;

#define SFC_PKEY_Parameters		SF_PKEY_Parameters
#define SFC_PKEY_PrivateKey		SF_PKEY_PrivateKey
#define SFC_PKEY_PublicKey		SF_PKEY_PublicKey

#define SFC_PKEY_GenParamParam		SF_PKEY_GenParamParam
#define SFC_PKEY_GenKeyPairParam	SF_PKEY_GenKeyPairParam
#define SFC_PKEY_PEncParam			SF_PKEY_PEncParam		

typedef union {
	SF_PKCS1_PSS_PARAM	rsa_pss;
	struct {
		SFC_PKEY_PublicKey	*cpkPubKey;
	} kcdsa, eckcdsa;
} SFC_PKEY_SignParam;

/**
 *	Prototypes
 */

#ifdef __cplusplus
extern "C" {
#endif

// crypto

 SF_ERROR	SFC_Initialize					(void);

 SF_ERROR	SFC_Finalize					(void);

 char *	SFC_GetVersion					(void);

 char *	SFC_GetErrorString				(const SF_ERROR errorCode);

 int		SFC_GetState					(void);

 SF_ERROR	SFC_ChangeState					(const int stateID);

 SF_ERROR	SFC_SelfTest					(void);

// skey

 SFC_SKEY_SecretKey *
				SFC_SKEY_SecretKey_New			(void);

 void		SFC_SKEY_SecretKey_Free			(SFC_SKEY_SecretKey *cskKey);

 SF_ERROR	SFC_SKEY_SecretKey_Copy			(SFC_SKEY_SecretKey *cskTgtKey,
											 const SFC_SKEY_SecretKey *cskSrcKey);


 SF_ERROR	SFC_SKEY_SecretKey_ToBinary		(SF_BYTE *output,					// optional
											 SF_WORD *outputLength,
											 const SFC_SKEY_SecretKey *cskKey);

 SF_ERROR	SFC_SKEY_SecretKey_FromBinary	(SFC_SKEY_SecretKey *cskKey,
											 const SF_BYTE *input,
											 const SF_WORD inputLength);

 SF_ERROR	SFC_SKEY_SecretKey_EncodeKey	(SFC_SKEY_SecretKey *csKey,
											 const int keyID,
											 const SF_BYTE *key,
											 const SF_WORD keyLength);

 SF_ERROR	SFC_SKEY_SecretKey_DecodeKey		(int *keyID,
											 SF_BYTE *key,
											 SF_WORD *keyLength,
											 const SFC_SKEY_SecretKey *csKey);

 SF_ERROR	SFC_SKEY_GenerateKey			(SFC_SKEY_SecretKey *cskKey,
											 const int keyID,
											 const SF_WORD keyLength,			// optional
											 const void *param);				// optional
// cipher

 SFC_CIPHER_CTX *
				SFC_CIPHER_CTX_New				(void);

 void		SFC_CIPHER_CTX_Free				(SFC_CIPHER_CTX *cpCtx);

 SF_ERROR	SFC_CIPHER_CTX_ToBinary			(SF_BYTE *output,					// optional
											 SF_WORD *outputLength,
											 const SFC_CIPHER_CTX *cpCtx);

 SF_ERROR	SFC_CIPHER_CTX_FromBinary		(SFC_CIPHER_CTX *cpCtx,
											 const SF_BYTE *input,
											 const SF_WORD inputLength);


 SF_ERROR	SFC_Cipher_Encrypt_Init			(SFC_CIPHER_CTX *cpCtx, 
											 const SFC_SKEY_SecretKey *cskKey,
											 const int cipherID, 
											 const SFC_CIPHER_PARAM *cparam);

 SF_ERROR	SFC_Cipher_Encrypt_Update		(SFC_CIPHER_CTX *cpCtx, 
											 SF_BYTE *output, 
											 SF_WORD *outputLength,
											 const SF_BYTE *input, 
											 const SF_WORD inputLength);

 SF_ERROR	SFC_Cipher_Encrypt_Final		(SFC_CIPHER_CTX *cpCtx, 
											 SF_BYTE *output, 
											 SF_WORD *outputLength);

 SF_ERROR	SFC_Cipher_Encrypt				(SF_BYTE *output, 
											 SF_WORD *outputLength, 
											 const SF_BYTE *input, 
											 const SF_WORD inputLength,
											 const SFC_SKEY_SecretKey *cskKey,
											 const int cipherID, 
											 const SFC_CIPHER_PARAM *cparam);

 SF_ERROR	SFC_Cipher_Decrypt_Init			(SFC_CIPHER_CTX *cpCtx, 
											 const SFC_SKEY_SecretKey *cskKey,
											 const int cipherID, 
											 const SFC_CIPHER_PARAM *cparam);

 SF_ERROR	SFC_Cipher_Decrypt_Update		(SFC_CIPHER_CTX *cpCtx, 
											 SF_BYTE *output, 
											 SF_WORD *outputLength,
											 const SF_BYTE *input, 
											 const SF_WORD inputLength);

 SF_ERROR	SFC_Cipher_Decrypt_Final		(SFC_CIPHER_CTX *cpCtx, 
											 SF_WORD *paddingLength);

 SF_ERROR	SFC_Cipher_Decrypt				(SF_BYTE *output, 
											 SF_WORD *outputLength, 
											 const SF_BYTE *input, 
											 const SF_WORD inputLength,
											 const SFC_SKEY_SecretKey *cskKey,
											 const int cipherID, 
											 const SFC_CIPHER_PARAM *cparam);
//added by hongma, 2009.10.06
 SF_ERROR SFC_Cipher_Set_Path				(int alg_id,
											 SF_BYTE *path);

// hash

 SFC_HASH_CTX *
				SFC_HASH_CTX_New				(void);

 void		SFC_HASH_CTX_Free				(SFC_HASH_CTX *hsCtx);

 SF_ERROR	SFC_HASH_CTX_ToBinary			(SF_BYTE *output,				// optional
											 SF_WORD *outputLength,
											 const SFC_HASH_CTX *hsCtx); //null check

 SF_ERROR	SFC_HASH_CTX_FromBinary			(SFC_HASH_CTX *hsCtx,
											 const SF_BYTE *input,
											const SF_WORD inputLength); // null check

 SF_ERROR	SFC_Hash_Init					(SFC_HASH_CTX *hsCtx, 
											 const int hashID);

 SF_ERROR	SFC_Hash_Update					(SFC_HASH_CTX *hsCtx, 
											 const SF_BYTE *input, 
											 const SF_WORD inputLength);

 SF_ERROR	SFC_Hash_Final					(SFC_HASH_CTX *hsCtx, 
											 SF_BYTE *hash, 
											 SF_WORD *hashLength); // NULL check

 SF_ERROR	SFC_Hash						(SF_BYTE *hash, 
											 SF_WORD *hashLength, 
											 const SF_BYTE *input, 
											 const SF_WORD inputLength,
											 const int hashID);

// mac

 SFC_MAC_CTX *
				SFC_MAC_CTX_New					(void);

 void		SFC_MAC_CTX_Free				(SFC_MAC_CTX *maCtx);

 SF_ERROR	SFC_MAC_CTX_ToBinary			(SF_BYTE *output,				// optional
											SF_WORD *outputLength,
											const SFC_MAC_CTX *maCtx); // null check

 SF_ERROR	SFC_MAC_CTX_FromBinary			(SFC_MAC_CTX *maCtx,
											const SF_BYTE *input,
											const SF_WORD inputLength); // null check

 SF_ERROR	SFC_MAC_Init					(SFC_MAC_CTX *maCtx, 
											 const SFC_SKEY_SecretKey *cskKey,
											 const int macID, 
											 const SFC_CIPHER_SUITE_PARAM *csuiteParam); // nullcheck

 SF_ERROR	SFC_MAC_Update					(SFC_MAC_CTX *maCtx, 
											 const SF_BYTE *input, 
											 const SF_WORD inputLength);

 SF_ERROR	SFC_MAC_Final					(SFC_MAC_CTX *maCtx, 
											 SF_BYTE *mac, 
											 SF_WORD *macLength);

 SF_ERROR	SFC_MAC							(SF_BYTE *mac, 
											 SF_WORD *macLength, 
											 const SF_BYTE *input, 
											 const SF_WORD inputLength,
											 const SFC_SKEY_SecretKey *cskKey,
											 const int macID, 
											 const SFC_CIPHER_SUITE_PARAM *csuiteParam); // null check

// rand
 SF_ERROR	SFC_InitRandom					(const SF_BYTE *primeQ,
										     const SF_WORD primeQLength,
											 const SF_BYTE *xkey, 
											 const SF_WORD xkeyLength,
											 const SF_BYTE *xseed,
											 const SF_WORD xseedLength);

 SF_ERROR	SFC_UpdateRandom				(const SF_BYTE *seed, 
											 const SF_WORD seedLength);

 SF_ERROR	SFC_GetRandom					(SF_BYTE *output, 
											 const SF_WORD outputLength); // null check

// pkey

// - ctx

 SFC_PKEY_CTX *SFC_PKEY_CTX_New				(void);
 void		   SFC_PKEY_CTX_Free			(SFC_PKEY_CTX *cpkCtx);



// - params

 SFC_PKEY_Parameters *
				SFC_PKEY_Parameters_New			(void);

 void		SFC_PKEY_Parameters_Free		(SFC_PKEY_Parameters *cpkPrivKey);

 SF_ERROR	SFC_PKEY_Parameters_Copy		(SFC_PKEY_Parameters *cpkTgtPrivKey,
											 const SFC_PKEY_Parameters *cpkSrcPrivKey);

 SF_ERROR	SFC_PKEY_Parameters_GetInfo		(int *pkeyID,
											 const SFC_PKEY_Parameters *cpkParams);

 SF_ERROR	SFC_PKEY_Parameters_Encode		(SF_BYTE *output,						// optional
											 SF_WORD *outputLength,
											 const SFC_PKEY_Parameters *cpkParams);

 SF_ERROR	SFC_PKEY_Parameters_Decode		(SFC_PKEY_Parameters *cpkParams,
											 const int pkeyID,
											 const SF_BYTE *input, 
											 const SF_WORD inputLength);
// - privkey

 SFC_PKEY_PrivateKey *
				SFC_PKEY_PrivateKey_New			(void);

 void		SFC_PKEY_PrivateKey_Free		(SFC_PKEY_PrivateKey *cpkPrivKey);

 SF_ERROR	SFC_PKEY_PrivateKey_Copy		(SFC_PKEY_PrivateKey *cpkTgtPrivKey,
											 const SFC_PKEY_PrivateKey *cpkSrcPrivKey);

 SF_ERROR	SFC_PKEY_PrivateKey_GetInfo		(int *pkeyID,
											 const SFC_PKEY_PrivateKey *cpkPrivKey);

 SF_ERROR	SFC_PKEY_PrivateKey_ToBinary	(SF_BYTE *output,						// optional
											 SF_WORD *outputLength,
											 const SFC_PKEY_PrivateKey *cpkPrivKey,
											 const void *param); // null check

 SF_ERROR	SFC_PKEY_PrivateKey_FromBinary	(SFC_PKEY_PrivateKey *cpkPrivKey,
											 const int pkeyID,
											 const SF_BYTE *input,
											 const SF_WORD inputLength,
											 const void *param); // null check

 SF_ERROR	SFC_PKEY_PrivateKey_EncodeKey	(SFC_PKEY_PrivateKey *cpkPrivKey,
											 const SF_PKEY_PrivateKey *pkPrivKey,
											 const void *param);			//optional

 SF_ERROR	SFC_PKEY_PrivateKey_DecodeKey	(SF_PKEY_PrivateKey *pkPrivKey,
											 const SFC_PKEY_PrivateKey *cpkPrivKey,
											 const void *param);	//optional

// - pubkey

 SFC_PKEY_PublicKey *
				SFC_PKEY_PublicKey_New			(void);

 void		SFC_PKEY_PublicKey_Free			(SFC_PKEY_PublicKey *cpkPubKey);

 SF_ERROR	SFC_PKEY_PublicKey_Copy			(SFC_PKEY_PublicKey *cpkTgtPubKey,
											 const SFC_PKEY_PublicKey *cpkSrcPubKey,
											 const SFC_PKEY_Parameters *pkParams);

 SF_ERROR	SFC_PKEY_PublicKey_GetInfo		(int *pkeyID,
											 const SFC_PKEY_PublicKey *cpkPubKey);

 SF_ERROR	SFC_PKEY_PublicKey_ToBinary		(SF_BYTE *output,						// optional
											 SF_WORD *outputLength,
											 const SFC_PKEY_PublicKey *cpkPubKey,
											 const SFC_PKEY_Parameters *pkParams); // null check

 SF_ERROR	SFC_PKEY_PublicKey_FromBinary	(SFC_PKEY_PublicKey *cpkPubKey,
											 const int pkeyID,
											 const SF_BYTE *input,
											 const SF_WORD inputLength,
											 const SFC_PKEY_Parameters *pkParams); // null check

 SF_ERROR	SFC_PKEY_PublicKey_EncodeKey	(SFC_PKEY_PublicKey *cpkPubKey,
											 const SF_PKEY_PublicKey *pkPubKey,
											 const SF_PKEY_Parameters *param);			// optional

 SF_ERROR	SFC_PKEY_PublicKey_DecodeKey	(SF_PKEY_PublicKey *pkPubKey,
											 const SFC_PKEY_PublicKey *cpkPubKey,
											 const void *param);		//optional

// - crypto

 SF_ERROR	SFC_PKEY_GenerateParameters		(SFC_PKEY_Parameters *cpkParams, 
											 const int pkeyID,
											 const SFC_PKEY_GenParamParam *cgenParam);

 SF_ERROR	SFC_PKEY_GenerateKeyPair		(SFC_PKEY_PrivateKey *cpkPrivKey, 
											 SFC_PKEY_PublicKey *cpkPubKey,
											 const int pkeyID,
											 const SFC_PKEY_Parameters *cpkParams,	// optional
											 const SFC_PKEY_GenKeyPairParam *cgenParam);

 SF_ERROR	SFC_PKEY_ProveKeyPair			(const SFC_PKEY_PrivateKey *cpkPrivKey, 
											 const SFC_PKEY_PublicKey *cpkPubKey,
											 const SFC_PKEY_Parameters *cpkParams);

 SF_ERROR	SFC_PKEY_Encrypt				(SF_BYTE *cipher, 
											 SF_WORD *cipherLength, 
											 const SF_BYTE *plain, 
											 const SF_WORD plainLength,
											 const int pencID,
											 const SFC_PKEY_PublicKey *cpkPubKey,
											 const SFC_PKEY_Parameters *cpkParams,	// optional
											 const SFC_PKEY_PEncParam *cpencParam);	// optional

 SF_ERROR	SFC_PKEY_Decrypt				(SF_BYTE *plain, 
											 SF_WORD *plainLength, 
											 const SF_BYTE *cipher, 
											 const SF_WORD cipherLength,
											 const int pencID,
											 const SFC_PKEY_PrivateKey *cpkPrivKey,
											 const SFC_PKEY_Parameters *cpkParams,	// optional
											 const SFC_PKEY_PEncParam *cpencParam);	// optional

 SF_ERROR	SFC_PKEY_Sign					(SF_BYTE *signature, 
											 SF_WORD *signatureLength,
											 const int msgID,
											 const SF_BYTE *message, 
											 const SF_WORD messageLength,
											 const int signID,
											 const SFC_PKEY_PrivateKey *cpkPrivKey,
											 const SFC_PKEY_Parameters *cpkParams,	// optional
											 const SFC_PKEY_SignParam *csignParam);	// optional

 SF_ERROR	SFC_PKEY_Sign_Init				(SFC_PKEY_CTX *cpkCtx,
											 const int signID,
											 const SFC_PKEY_PrivateKey *cpkPrivKey,
											 const SFC_PKEY_Parameters *cpkParams,	// optional
											 const SFC_PKEY_SignParam *csignParam);	// optional

 SF_ERROR	SFC_PKEY_Sign_Update			(SFC_PKEY_CTX *cpkCtx,
											 const SF_BYTE *message, 
											 const SF_WORD messageLength);

 SF_ERROR	SFC_PKEY_Sign_Final				(SFC_PKEY_CTX *cpkCtx,
											 SF_BYTE *signature, 
											 SF_WORD *signatureLength);

// Added by Hongma : 원문 메시지 대신 해쉬값을 받아 서명하는 API
 SF_ERROR	SFC_PKEY_Sign_Hash				(SF_BYTE *signature, 
												 SF_WORD *signatureLength,
												 const int hashID,
												 const SF_BYTE *hash, 
												 const SF_WORD hashLength,
												 const int signID,
												 const SFC_PKEY_PrivateKey *cpkPrivKey,
												 const SFC_PKEY_Parameters *cpkParams,	// optional
											 const SFC_PKEY_SignParam *csignParam);	// optional

 SF_ERROR	SFC_PKEY_Verify					(const SF_BYTE *signature, 
											 const SF_WORD signatureLength,
											 const int msgID,
											 const SF_BYTE *message, 
											 const SF_WORD messageLength,
											 const int signID,
											 const SFC_PKEY_PublicKey *cpkPubKey,
											 const SFC_PKEY_Parameters *cpkParams,	// optional
											 const SFC_PKEY_SignParam *csignParam);	// optional

 SF_ERROR	SFC_PKEY_Verify_Init			(SFC_PKEY_CTX *cpkCtx,
											 const int signID,
											 const SFC_PKEY_PublicKey *cpkPubKey,
											 const SFC_PKEY_Parameters *cpkParams,	// optional
											 const SFC_PKEY_SignParam *csignParam);	// optional

 SF_ERROR	SFC_PKEY_Verify_Update			(SFC_PKEY_CTX *cpkCtx,
											 const SF_BYTE *message, 
											 const SF_WORD messageLength);

 SF_ERROR	SFC_PKEY_Verify_Final			(SFC_PKEY_CTX *cpkCtx,
											 const SF_BYTE *signature, 
											 const SF_WORD signatureLength);

// Added by Hongma : 원문 메시지 대신 해쉬값을 받아 서명 검증하는 API
 SF_ERROR	SFC_PKEY_Verify_Hash			(const SF_BYTE *signature, 
												 const SF_WORD signatureLength,
												 const int hashID,
												 const SF_BYTE *hash, 
												 const SF_WORD hashLength,
												 const int signID,
												 const SFC_PKEY_PublicKey *cpkPubKey,
												 const SFC_PKEY_Parameters *cpkParams,	// optional
											 const SFC_PKEY_SignParam *csignParam);	// optional


#ifdef __cplusplus
}
#endif

#endif

#endif	 //_MIN_WCE