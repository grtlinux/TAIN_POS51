//
//	$Id: suite_csp.h,v 1.18 2009/10/23 02:43:12 lovian Exp $
//

#ifndef _SUITE_CSP_H_
#define _SUITE_CSP_H_

#include "exp_global.h"

/**
 *	Constants
 */

// cipher

#define	XE_CSP_CIPHERID_AES					1
#define	XE_CSP_CIPHERID_BLOWFISH			2
#define	XE_CSP_CIPHERID_CAST128				3
#define	XE_CSP_CIPHERID_DES					4
#define	XE_CSP_CIPHERID_RC2					5
#define	XE_CSP_CIPHERID_RC4					6
#define	XE_CSP_CIPHERID_RC5					7
#define	XE_CSP_CIPHERID_SEED				8
#define	XE_CSP_CIPHERID_TDES				9
#define	XE_CSP_CIPHERID_ARIA				12
#define	XE_CSP_CIPHERID_ARIA128				13
#define	XE_CSP_CIPHERID_ARIA192				14
#define	XE_CSP_CIPHERID_ARIA256			    15
#define	XE_CSP_CIPHERID_NEAT				21
#define	XE_CSP_CIPHERID_NEAT_PENTA			22
#define XE_CSP_CIPHERID_NES					31

#define	XE_CSP_MODEID_ECB					1
#define	XE_CSP_MODEID_CBC					2
#define	XE_CSP_MODEID_CFB					3
#define	XE_CSP_MODEID_OFB					4
#define	XE_CSP_MODEID_CTR					5

#define	XE_CSP_PADDINGID_NO					1
#define	XE_CSP_PADDINGID_RFC1423			2

// hash

#define	XE_CSP_HASHID_MD2					1
#define	XE_CSP_HASHID_MD5					2
#define	XE_CSP_HASHID_SHA1					3
#define	XE_CSP_HASHID_HAS160				4
#define	XE_CSP_HASHID_RIPEMD160				5
#define	XE_CSP_HASHID_SHA256				6
#define	XE_CSP_HASHID_SHA384				7
#define	XE_CSP_HASHID_SHA512				8
#define	XE_CSP_HASHID_SHA224				9

// mac

#define	XE_CSP_MACID_HMAC_MD2				1
#define	XE_CSP_MACID_HMAC_MD5				2
#define	XE_CSP_MACID_HMAC_SHA1				3
#define	XE_CSP_MACID_HMAC_HAS160			4
#define	XE_CSP_MACID_HMAC_RIPEMD160			5
#define	XE_CSP_MACID_HMAC_SHA256			6
#define	XE_CSP_MACID_HMAC_SHA384			7
#define	XE_CSP_MACID_HMAC_SHA512			8
#define	XE_CSP_MACID_CBCMAC_AES				11
#define	XE_CSP_MACID_CBCMAC_BLOWFISH		12
#define	XE_CSP_MACID_CBCMAC_CAST128			13
#define	XE_CSP_MACID_CBCMAC_DES				14
#define	XE_CSP_MACID_CBCMAC_RC2				15
#define	XE_CSP_MACID_CBCMAC_RC5				16
#define	XE_CSP_MACID_CBCMAC_SEED			17
#define	XE_CSP_MACID_CBCMAC_SKIPJACK		18
#define	XE_CSP_MACID_CBCMAC_TDES			19
// for korea {{
#define	XE_CSP_MACID_CBCMAC_DES_WITHPAD		24
// }}
#define	XE_CSP_MACID_MD5MAC					25

// rsa, dh, dsa, kcdsa

#define	XE_CSP_PKEYID_RSA					1
#define	XE_CSP_PKEYID_DH					2
#define	XE_CSP_PKEYID_DSA					3
#define	XE_CSP_PKEYID_ECDH					4
#define	XE_CSP_PKEYID_ECDSA					5
#define	XE_CSP_PKEYID_KCDSA					11
#define	XE_CSP_PKEYID_ECKCDSA				12
#define	XE_CSP_PKEYID_RSA_PSS				13

#define	XE_CSP_MGFID_MGF1_SHA1				1
#define	XE_CSP_MGFID_MGF1_SHA224			2
#define	XE_CSP_MGFID_MGF1_SHA256			3
#define	XE_CSP_MGFID_MGF1_SHA384			4
#define	XE_CSP_MGFID_MGF1_SHA512			5

#define	XE_CSP_SOURCEID_SPECIFIED			1

#define	XE_CSP_SIGNID_RSA_V15_MD2			1
#define	XE_CSP_SIGNID_RSA_V15_MD5			2
#define	XE_CSP_SIGNID_RSA_V15_SHA1			3
#define XE_CSP_SIGNID_RSA_V15_SHA256		4
#define XE_CSP_SIGNID_RSA_V15_SHA384		5
#define XE_CSP_SIGNID_RSA_V15_SHA512		6
#define	XE_CSP_SIGNID_RSA_V15_OTHER			9
#define XE_CSP_SIGNID_RSA_V15_HAS160		10
#define	XE_CSP_SIGNID_RSA_PSS				11
#define	XE_CSP_SIGNID_DSA_SHA1				15
#define XE_CSP_SIGNID_ECDSA_SHA1			16
#define	XE_CSP_SIGNID_KCDSA_SHA1			21
#define	XE_CSP_SIGNID_KCDSA_HAS160			22
#define XE_CSP_SIGNID_ECKCDSA_SHA1			23
#define XE_CSP_SIGNID_ECKCDSA_HAS160		24
//2099-12-24 by yjvc80: Add algorithm identifier
#define XE_CSP_SIGNID_KCDSA1_SHA1			25
#define XE_CSP_SIGNID_KCDSA1_HAS160		    26

//2011.06.30 by cristyanne: Add algorithm identifier
#define XE_CSP_SIGNID_KCDSA_SHA256			27
#define XE_CSP_SIGNID_KCDSA_SHA384			28
#define XE_CSP_SIGNID_KCDSA_SHA512			29
#define XE_CSP_SIGNID_KCDSA1_SHA256			30

// 2007-12-18 by ssosuny: RFC 4055, Additional RSA Algorithms & Identifier {{
#define XE_CSP_SIGNID_RSA_PSS_SHA224		31
#define XE_CSP_SIGNID_RSA_PSS_SHA256		32
#define XE_CSP_SIGNID_RSA_PSS_SHA384		33
#define XE_CSP_SIGNID_RSA_PSS_SHA512		34
// }}

#define XE_CSP_SIGNID_ECDSA_SHA224			41
#define XE_CSP_SIGNID_ECDSA_SHA256			42

#define	XE_CSP_PENCID_RSA_V15				1
#define	XE_CSP_PENCID_RSA_OAEP				5

// 2007-12-18 by ssosuny: RFC 4055, Additional RSA Algorithms & Identifier {{
#define XE_CSP_PENCID_RSA_OAEP_SHA224		11
#define XE_CSP_PENCID_RSA_OAEP_SHA256		12
#define XE_CSP_PENCID_RSA_OAEP_SHA384		13
#define XE_CSP_PENCID_RSA_OAEP_SHA512		14
// }}

#define	XE_CSP_KEYEXCHID_DH					1

// ecc named curve id

#define XE_CSP_NCID_c2pnb163v1				(0x01 | 0x0100 | 0x010000)	// mandatory
#define XE_CSP_NCID_secp160r1				(0x06 | 0x0200 | 0x020000)	// mandatory for WTLS
#define XE_CSP_NCID_sect163k1				(0x01 | 0x0100 | 0x020000)	// mandatory for WTLS

// for compatibility with prev version {{
#define ENCALGID_DES					0
#define ENCALGID_3DES					1
#define ENCALGID_RC4					3
#define ENCALGID_SEED					10

#define ENCMOD_ECB						0
#define ENCMOD_CBC						1
#define ENCMOD_CFB						2
#define ENCMOD_OFB						3

#define KEYTYPE_RSA 					0

#define SIGNALGID_MD2WithRSA			0
#define SIGNALGID_MD5WithRSA			1
#define SIGNALGID_SHA1WithRSA			2

// Hongma : 3,4,5 => 4,5,6 으로 수정 (PKC 와 호환성이 오류로 인해서리..)
#define SIGNALGID_SHA256WithRSA			4
#define SIGNALGID_SHA384WithRSA			5
#define SIGNALGID_SHA512WithRSA			6

#define MACALGID_DES					0
#define MACALGID_3DES					1
#define MACALGID_MD5					2

#define HASHALGID_MD2					0
#define HASHALGID_MD5					1
#define HASHALGID_SHA_1 				2
#define HASHALGID_MD4					3
#define HASHALGID_RIPEMD160 			4
#define HASHALGID_HAS160				5

#define RANDOMALGID_DES 				0
#define RANDOMALGID_MD5 				1
// }}

// CMVP constants{{
#define XE_CM_STATE_UNKNOWN						0
#define	XE_CM_STATE_ID_LOADED					1
#define	XE_CM_STATE_ID_GENERAL					3
#define	XE_CM_STATE_ID_KCMVP					5
#define	XE_CM_STATE_ID_ERROR					9
#define	XE_CM_STATE_ID_FINALIZED				11
//}}

/**
 *	Struct
 */

// ctx

typedef struct {
	int		ctxID;
	void	*ctx;
} XE_CSP_CTX;

// cipher

typedef struct {
	int		type;					// stream (0), block (1)
	int		blockLength;
	int		keyLength;				// default key length
	int		minKeyLength;			// minimum key length
	int		maxKeyLength;			// maximum key length
	int		stepKeyLength;
} XE_CSP_CipherInfo;

typedef union {
	struct {
		int		effectiveBits;
	} rc2;
	struct {
		int		rounds;
	} rc5;
} XE_CSP_SuiteParam;

typedef struct {
	XE_CSP_SuiteParam	suiteParam;
	
	int		modeID;
	struct {
		BIN		*iv;
		int		modeSize;
	} modeParam;
	
	int		paddingID;
} XE_CSP_CipherParam;

// hash

typedef struct {
	int		hashLength;
	int		blockLength;
} XE_CSP_HashInfo;

// mac

typedef struct {
	int		macLength;				// mac length
	int		keyLength;				// default key length
	int		minKeyLength;
	int		maxKeyLength;
	int		stepKeyLength;
} XE_CSP_MACInfo;

// rsa, dh, dsa

typedef union {
	struct {
		int		primeLength;
		int		factorLength;
	} dh;
	struct {
		int		primeLength;
	} dsa, kcdsa;
	struct {
		int		ncid;
	} ecdsa, eckcdsa;
} XE_CSP_GenParamParam;

typedef union {
	struct {
		int		keyLength;
		int		e;					// 3, 65537
	} rsa;
	struct {
		BIN		*pkeyParam;
	} dh, dsa, kcdsa, ecdsa, eckcdsa;
} XE_CSP_GenKeyPairParam;

typedef union {
	struct {
		int		hashID;
		int		mgfID;
	} rsa_pss;
	struct {
		BIN		*pkeyParam;
	} dsa, ecdsa;
	struct {
		BIN		*pkeyParam;
		BIN		*pubKey;
		BIN		*hash;
	} kcdsa, eckcdsa;
} XE_CSP_SignParam;

typedef union {
	struct {
		int		hashID;
		int		mgfID;
		int		sourceID;
		BIN		*source;
	} rsa_oaep;
} XE_CSP_PEncParam;

typedef union {
	struct {
		BIN		*pkeyParam;
	} dh;
} XE_CSP_DKeyParam;

/**
 *	Error codes
 */

#define	CSP_ERR_INVALID_INPUT				(ERR_CSP + 1)
#define	CSP_ERR_INTERNAL					(ERR_CSP + 2)
#define	CSP_ERR_MALLOC_FAILED				(ERR_CSP + 3)

#define	CSP_ERR_UNKNOWN_ID					(ERR_CSP + 10)

#define	CSP_ERR_INVALID_MAC					(ERR_CSP + 11)
#define	CSP_ERR_INVALID_SIGNATURE			(ERR_CSP + 12)
#define	CSP_ERR_INVALID_KEYPAIR				(ERR_CSP + 13)

#define	CSP_ERR_UNKNOWN_MODE				(ERR_CSP + 21)
#define	CSP_ERR_UNKNOWN_PADDING				(ERR_CSP + 22)
#define	CSP_ERR_INVALID_PADDING				(ERR_CSP + 23)
#define	CSP_ERR_IV_LENGTH					(ERR_CSP + 24)
#define	CSP_ERR_MODE_SIZE					(ERR_CSP + 25)
#define	CSP_ERR_KEY_LENGTH					(ERR_CSP + 26)

#define	CSP_ERR_BAD_PRIVKEY					(ERR_CSP + 30)
#define	CSP_ERR_BAD_PUBKEY					(ERR_CSP + 31)
#define	CSP_ERR_BAD_PKEYPARAM				(ERR_CSP + 32)
#define	CSP_ERR_BAD_SIGNATURE				(ERR_CSP + 33)

// for compatibility with prev version {{
#define	CSP_ERR_GENERATE_RSAKEY				(ERR_CSP + 100)
#define	CSP_ERR_ENCODE_RSAKEY				(ERR_CSP + 101)
#define	CSP_ERR_DECODE_RSAKEY				(ERR_CSP + 102)
#define	CSP_ERR_RSA_ENCRYPT					(ERR_CSP + 103)
#define	CSP_ERR_RSA_DECRYPT					(ERR_CSP + 104)
#define	CSP_ERR_RSA_SIGN					(ERR_CSP + 105)
#define	CSP_ERR_RSA_VERIFY					(ERR_CSP + 106)
// }}

#define	CSP_ERR_CRYPTO_FUNCTION				(ERR_CSP + 110)

// CMVP {{
#define CSP_ERR_CM_STATE_NOT_SUPPORTED		(ERR_CSP + 120)
//}}

/**
 *	Prototypes
 */

#ifdef __cplusplus
extern "C" {
#endif

// ctx

XFA_EXPORT_TYPE	
XE_CSP_CTX *
		XFA_CSP_CreateCTX					(void);

XFA_EXPORT_TYPE	
void	XFA_CSP_ResetCTX					(XE_CSP_CTX *ctx);

XFA_EXPORT_TYPE	
void	XFA_CSP_DestroyCTX					(XE_CSP_CTX *ctx);

// cipher

XFA_EXPORT_TYPE	
int		XFA_CSP_GetCipherInfo				(XE_CSP_CipherInfo *cipherInfo,
											 const int cipherID);

XFA_EXPORT_TYPE	
int		XFA_CSP_Encrypt						(BIN *output,
											 const BIN *input,
											 const BIN *key,
											 const int cipherID,
											 const XE_CSP_CipherParam *cipherParam);

XFA_EXPORT_TYPE	
int		XFA_CSP_EncryptInit					(XE_CSP_CTX *ctx,
											 const BIN *key,
											 const int cipherID,
											 const XE_CSP_CipherParam *cipherParam);

XFA_EXPORT_TYPE	
int		XFA_CSP_EncryptUpdate				(XE_CSP_CTX *ctx,
											 BIN *output,
											 const BIN *input);

XFA_EXPORT_TYPE	
int		XFA_CSP_EncryptFinal				(XE_CSP_CTX *ctx,
											 BIN *output);

XFA_EXPORT_TYPE	
int		XFA_CSP_Decrypt						(BIN *output,
											 const BIN *input,
											 const BIN *key,
											 const int cipherID,
											 const XE_CSP_CipherParam *cipherParam);

XFA_EXPORT_TYPE	
int		XFA_CSP_DecryptInit					(XE_CSP_CTX *ctx,
											 const BIN *key,
											 const int cipherID,
											 const XE_CSP_CipherParam *cipherParam);

XFA_EXPORT_TYPE	
int		XFA_CSP_DecryptUpdate				(XE_CSP_CTX *ctx,
											 BIN *output,
											 const BIN *input);

XFA_EXPORT_TYPE	
int		XFA_CSP_DecryptFinal				(XE_CSP_CTX *ctx,
											 int *paddingLength);

// hash

XFA_EXPORT_TYPE	
int		XFA_CSP_GetHashInfo					(XE_CSP_HashInfo *hashInfo,
											 const int hashID);

XFA_EXPORT_TYPE	
int		XFA_CSP_Hash						(BIN *hash,
											 const BIN *input,
											 const int hashID);

XFA_EXPORT_TYPE	
int		XFA_CSP_HashInit					(XE_CSP_CTX *ctx,
											 const int hashID);

XFA_EXPORT_TYPE	
int		XFA_CSP_HashUpdate					(XE_CSP_CTX *ctx,
											 const BIN *input);

XFA_EXPORT_TYPE	
int		XFA_CSP_HashFinal					(XE_CSP_CTX *ctx,
											 BIN *hash);

// mac

XFA_EXPORT_TYPE	
int		XFA_CSP_GetMACInfo					(XE_CSP_MACInfo *macInfo,
											 const int macID);

XFA_EXPORT_TYPE	
int		XFA_CSP_MAC							(BIN *mac,
											 const BIN *input,
											 const BIN *key,
											 const int macID,
											 const XE_CSP_SuiteParam *suiteParam);

XFA_EXPORT_TYPE	
int		XFA_CSP_MACInit						(XE_CSP_CTX *ctx,
											 const BIN *key,
											 const int macID,
											 const XE_CSP_SuiteParam *suiteParam);

XFA_EXPORT_TYPE	
int		XFA_CSP_MACUpdate					(XE_CSP_CTX *ctx,
											 const BIN *input);

XFA_EXPORT_TYPE	
int		XFA_CSP_MACFinal					(XE_CSP_CTX *ctx,
											 BIN *mac);

// rsa, dh, dsa, kcdsa

XFA_EXPORT_TYPE	
int		XFA_CSP_GenerateParam				(BIN *pkeyParam,
											 const int pkeyID,
											 const XE_CSP_GenParamParam *param);

XFA_EXPORT_TYPE	
int		XFA_CSP_GenerateKeyPair				(BIN *privKey,
											 BIN *pubKey,
											 const int pkeyID,
											 const XE_CSP_GenKeyPairParam *param);

XFA_EXPORT_TYPE	
int		XFA_CSP_ProveKeyPair				(const BIN *privKey,
											 const BIN *pubKey,
											 const int pkeyID,
											 const BIN *pkeyParam);

XFA_EXPORT_TYPE	
int		XFA_CSP_GetKeyLength				(int *keyLength,
											 const BIN *pubKey,
											 const int pkeyID,
											 const BIN *pkeyParam);
// 2009.12.16 Hongma 
XFA_EXPORT_TYPE	
int		XFA_CSP_GetKeyLengthEx				(int *keyLength,
											 const BIN *privKey,
											 const int pkeyID,
											 const BIN *pkeyParam);

XFA_EXPORT_TYPE	
int		XFA_CSP_ComputeSignature			(BIN *signature,
											 const BIN *hash,		// NOTE: message if kcdsa
											 const BIN *privKey,
											 const int signID,
											 const XE_CSP_SignParam *param);

XFA_EXPORT_TYPE	
int		XFA_CSP_VerifySignature				(const BIN *signature,
											 const BIN *hash,		// NOTE: message if kcdsa
											 const BIN *pubKey,
											 const int signID,
											 const XE_CSP_SignParam *param);

XFA_EXPORT_TYPE	
int		XFA_CSP_PublicEncrypt				(BIN *cipher,
											 const BIN *plain,
											 const BIN *pubKey,
											 const int pencID,
											 const XE_CSP_PEncParam *param);

XFA_EXPORT_TYPE	
int		XFA_CSP_PrivateDecrypt				(BIN *plain,
											 const BIN *cipher,
											 const BIN *privKey,
											 const int pencID,
											 const XE_CSP_PEncParam *param);

XFA_EXPORT_TYPE	
int		XFA_CSP_DeriveKey					(BIN *secret,
											 const BIN *selfPrivKey,
											 const BIN *peerPubKey,
											 const int keyExchID,
											 const XE_CSP_DKeyParam *param);

// kcdsa
XFA_EXPORT_TYPE
int		XFA_CSP_KCDSA_ComputeZ				(BIN *z,
											 const BIN *privKey,
											 const BIN *pubKey,
											 const BIN *pkeyParam);
// rand

XFA_EXPORT_TYPE	
int		XFA_CSP_SeedRandom					(const BIN *seed);

XFA_EXPORT_TYPE	
int		XFA_CSP_GenerateRandom				(BIN *random,
											 const int length);

// version

XFA_EXPORT_TYPE	
char *	XFA_CSP_GetVersion					(void);

XFA_EXPORT_TYPE	
int		XFA_CSP_CheckVersion				(const char *version);			// optional

// error

XFA_EXPORT_TYPE	
char *	XFA_CSP_GetErrorReason				(const int code, const int locale);



// for compatibility with prev version {{
XFA_EXPORT_TYPE	int	XFA_EncryptionBin		(const int nAlg, const int nMode, const BIN *pKeyBin, 
											 const BIN *pIn, BIN *pOut);

XFA_EXPORT_TYPE	int	XFA_DecryptionBin		(const int nAlg, const int nMode, const BIN *pKeyBin, 
											 const BIN *pIn, BIN *pOut);

XFA_EXPORT_TYPE	int	XFA_EncryptionIVBin		(const int nAlg, const int nMode, const char *pIV, 
											 const BIN *pKeyBin, const BIN *pIn, BIN *pOut);

XFA_EXPORT_TYPE	int	XFA_DecryptionIVBin		(const int nAlg, const int nMode, const char *pIV, 
											 const BIN *pKeyBin, const BIN *pIn, BIN *pOut);

XFA_EXPORT_TYPE	int	XFA_HashBin				(const int nAlg, const BIN *pIn, BIN *pOut);

XFA_EXPORT_TYPE	int	XFA_MacBin				(const int nAlg, const int nBits, const BIN *pKeyBin, 
											 const BIN *pIn, BIN *pOut);

XFA_EXPORT_TYPE	int	XFA_MacVerifyBin		(const int nAlg, const int nBits, const BIN *pKeyBin, 
											 const BIN *pIn, const BIN *pMac);

XFA_EXPORT_TYPE	int	XFA_RandomBin			(const int nAlg, const int nLength, BIN *pOut);

XFA_EXPORT_TYPE	int	XFA_GenerateKeyPairBin	(const int nAlg, const int nBit, 
											 BIN *pPubKeyBin, BIN *pPrivKeyBin);

XFA_EXPORT_TYPE	int	XFA_GenSignatureBin		(const BIN *pPrivKeyBin, const int nAlg, 
											 const BIN *pIn, BIN *pOut);

XFA_EXPORT_TYPE	int	XFA_VerifySignBin		(const BIN *pPubKeyBin, const int nAlg, 
											 const BIN *pIn, const BIN *pSignature);

XFA_EXPORT_TYPE	int	XFA_PrivateDecryptBin	(const BIN *pPrivKeyBin, const BIN *pIn, BIN *pOut);

XFA_EXPORT_TYPE	int	XFA_PublicEncryptBin	(const BIN *pPubKeyBin, const BIN *pIn, BIN *pOut);

XFA_EXPORT_TYPE	int	XFA_ProveRSAKeyPairBin	(const BIN *pPrivKeyBin, const BIN *pPubKeyBin);

XFA_EXPORT_TYPE	int	XFA_GetRSAKeyLength		(const BIN *pPubKeyBin, int *pKeyLen);

XFA_EXPORT_TYPE	char *XFA_GetVersionCSP		(void);

XFA_EXPORT_TYPE	char *XFA_GetErrReasonCSP	(const int code, const int locale);

XFA_EXPORT_TYPE int
XFA_CSP_ComputeMsgSignature(BIN *signature,
						 const BIN *msg,				
						 const BIN *privKey,
						 const int signID,
						 const XE_CSP_SignParam *param);

XFA_EXPORT_TYPE int
XFA_CSP_VerifyMsgSignature(const BIN *signature,
						const BIN *msg,
						const BIN *pubKey,
						const int signID,
						const XE_CSP_SignParam *param);

XFA_EXPORT_TYPE int XFA_CSP_Initialize(void);

XFA_EXPORT_TYPE int XFA_CSP_ChangeState(const int stateID);

XFA_EXPORT_TYPE int XFA_CSP_Finalize(void);

XFA_EXPORT_TYPE int XFA_CSP_GetState(void);

// }}

#ifdef __cplusplus
}
#endif

#endif
