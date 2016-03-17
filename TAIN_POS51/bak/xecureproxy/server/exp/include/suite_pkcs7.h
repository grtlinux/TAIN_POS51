//
//	$Id: suite_pkcs7.h,v 1.23 2009-04-13 04:57:52 ksyoon Exp $
//

#ifndef _SUITE_PKCS7_H_
#define _SUITE_PKCS7_H_

#ifndef _WIN32_WCE
#include <time.h>
#endif

#include "suite_io.h"

/**
 *	Constants
 */

#define	XE_PKCS7_TYPEID_DATA				1
#define	XE_PKCS7_TYPEID_SIGNED				2
#define	XE_PKCS7_TYPEID_ENVELOPED			3
#define	XE_PKCS7_TYPEID_SIGNENVELOPED		4
#define	XE_PKCS7_TYPEID_DIGESTED			5
#define	XE_PKCS7_TYPEID_ENCRYPTED			6
// for smime {{
#define	XE_PKCS7_TYPEID_TSTINFO				14
#define	XE_PKCS7_TYPEID_CONTENTINFO			16
#define	XE_PKCS7_TYPEID_DVCSREQUESTDATA		17
#define	XE_PKCS7_TYPEID_DVCSRESPONSEDATA	18
// }}

// for arccert {{
#define XE_PKCS7_TYPEID_KIEC_ARCCERTREQUEST		43
#define XE_PKCS7_TYPEID_KIEC_ARCCERTRESPONSE	44
#define XE_PKCS7_TYPEID_KIEC_ARCNAME			45
#define XE_PKCS7_TYPEID_KIEC_ARCIDN				46
//}}

// for ctl {{
#define	XE_PKCS7_TYPEID_CTL					30
// }}

#define	XE_PKCS7_DIGESTID_MD2				1
#define	XE_PKCS7_DIGESTID_MD5				2
#define	XE_PKCS7_DIGESTID_SHA1				3
#define	XE_PKCS7_DIGESTID_HAS160			5
//2007/01/25 by ssosuny: HASH OID 추가, 2010.9.2 by hongma 7,8,9==> 6,7,8 로 변경
#define XE_PKCS7_DIGESTID_SHA256			6
#define XE_PKCS7_DIGESTID_SHA384			7
#define XE_PKCS7_DIGESTID_SHA512			8

//2009/10/28 added by jhkim
#define XE_PKCS7_SIGNID_MODE				1000
#define XE_PKCS7_SIGNID_MODE_PSS			XE_PKCS7_SIGNID_MODE * 2

#define	XE_PKCS7_ENCID_DES_CBC				1
#define	XE_PKCS7_ENCID_DES_EDE3_CBC			2
#define	XE_PKCS7_ENCID_RC2_CBC				3
#define	XE_PKCS7_ENCID_NEAT_CBC				4
#define	XE_PKCS7_ENCID_SEED_CBC				8
//2009/03/31 by ksyoon: ARIA OID 추가
#define XE_PKCS7_ENCID_ARIA_CBC				9
//2009/09/07 by ok: ARIA OID 추가 (국세청 용도)			
#define XE_PKCS7_ENCID_ARIA_CBC128			16
#define XE_PKCS7_ENCID_ARIA_CBC192			17	
#define XE_PKCS7_ENCID_ARIA_CBC256			18  
// for pkcs12 {{
#define	XE_PKCS7_ENCID_PBE_SHA_128_RC4		10
#define	XE_PKCS7_ENCID_PBE_SHA_40_RC4		11
#define	XE_PKCS7_ENCID_PBE_SHA_3KEY_TDES_CBC	12
#define	XE_PKCS7_ENCID_PBE_SHA_2KEY_TDES_CBC	13
#define	XE_PKCS7_ENCID_PBE_SHA_128_RC2_CBC	14
#define	XE_PKCS7_ENCID_PBE_SHA_40_RC2_CBC	15
// }}

#define	XE_PKCS7_ALGID_RSA					1
#define XE_PKCS7_ALGID_RSA_PSS				2

#define	XE_PKCS7_ALGID_DSA					3
#define	XE_PKCS7_ALGID_KCDSA				11

#define	XE_PKCS7_ATTRIBID_CONTENT_TYPE		1
#define	XE_PKCS7_ATTRIBID_MESSAGE_DIGEST	2
#define	XE_PKCS7_ATTRIBID_SIGNING_TIME		3
#define	XE_PKCS7_ATTRIBID_RANDOM_NONCE		4
#define	XE_PKCS7_ATTRIBID_SEQUENCE_NUMBER	5
#define	XE_PKCS7_ATTRIBID_COUNTER_SIGNATURE	6
// for smime {{
#define	XE_PKCS7_ATTRIBID_SMIME_CAPABILITIES	10
// }}
#define	XE_PKCS7_ATTRIBID_CHAIN_HASH		20


// 2007/01/16 by ssosuny
#define	XE_PKCS7_STATUS_granted				0
#define	XE_PKCS7_STATUS_badSignature		1
#define	XE_PKCS7_STATUS_badCertificate		2
#define	XE_PKCS7_STATUS_illegalOperator		3

// 2007/01/25 by ssosuny : EnvelopedData의 RSAOAEP지원
#define XE_PKCS7_ENVELOPED_ENABLE_RSAOAEP	1

/**
 *	Struct
 */

// BIN

typedef struct _XE_PKCS7_BIN_SET {
	BIN		bin;
	struct _XE_PKCS7_BIN_SET	*next;
} XE_PKCS7_BIN_SET;

// ContentInfo

typedef struct {
	int		typeID;
	BIN		*content;				// der
} XE_PKCS7_CONTENT_INFO;

// SignedData

typedef struct {
	BIN		*issuerAndSerial;		// der
	BIN		*subjectKeyIdentifier;	// der
	int		digestID;
	BIN		*authAttribs;			// der, optional
	int		algID;
	BIN		*signature;
	BIN		*unauthAttribs;			// der, optional
	// {{
	BIN		*privKey;				// der
	BIN		*signerCert;			// der
	// }}
} XE_PKCS7_SIGNER_INFO;

typedef struct _XE_PKCS7_SIGNER_INFO_SET {
	XE_PKCS7_SIGNER_INFO	signerInfo;
	struct _XE_PKCS7_SIGNER_INFO_SET *next;
} XE_PKCS7_SIGNER_INFO_SET;

typedef struct {
	XE_PKCS7_CONTENT_INFO	ctInfo;
	XE_PKCS7_BIN_SET		*certs;
	XE_PKCS7_BIN_SET		*crls;
	XE_PKCS7_SIGNER_INFO_SET	*signerInfos;
} XE_PKCS7_SIGNED_DATA;

typedef union {
	struct {
		int		null;
	} sign;
	struct {
		int		null;
	} verify;
	struct {
		int		detach;				// false(0), true(1)
	} encode;
	struct {
		int		verify;				// false(0), true(1)
	} decode;
} XE_PKCS7_SIGNED_PARAM;

// EnvelopedData

typedef struct {
	BIN		*issuerAndSerial;		// der
	int		algID;
	BIN		*encryptedKey;
	// {{
	BIN		*pubKey;				// der
	// }}
} XE_PKCS7_RECIP_INFO;

typedef struct _XE_PKCS7_RECIP_INFO_SET {
	XE_PKCS7_RECIP_INFO		recipInfo;
	struct _XE_PKCS7_RECIP_INFO_SET	*next;
} XE_PKCS7_RECIP_INFO_SET;

typedef struct {
	int		typeID;
	int		encID;
	BIN		*encParam;
	BIN		*encData;
} XE_PKCS7_ENC_CONTENT;

typedef struct {
	XE_PKCS7_RECIP_INFO_SET	*recipInfos;
	XE_PKCS7_ENC_CONTENT	encContent;
} XE_PKCS7_ENVELOPED_DATA;

typedef union {
	struct {
		int		null;
		//2007/01/25 by ssosuny
		int		isoaep;				//optional: defalut(0) rsaoaep(1)
	} envelope;
	struct {
		BIN		*encData;			// optional
	} develope;
	struct {
		int		detach;				// false(0), true(1)
	} encode;
	struct {
		int		null;
	} decode;
} XE_PKCS7_ENVELOPED_PARAM;

// SignedAndEnvelopedData

typedef struct {
	XE_PKCS7_RECIP_INFO_SET	*recipInfos;
	XE_PKCS7_ENC_CONTENT	encContent;
	XE_PKCS7_BIN_SET		*certs;
	XE_PKCS7_BIN_SET		*crls;
	XE_PKCS7_SIGNER_INFO_SET	*signerInfos;
} XE_PKCS7_SIGNENVELOPED_DATA;

typedef union {
	struct {
		int		null;
	} signenvelope;
	struct {
		int		null;
	} developeverify;
	struct {
		int		detach;				// false(0), true(1)
	} encode;
	struct {
		int		null;
	} decode;
} XE_PKCS7_SIGNENVELOPED_PARAM;

// DigestedData

typedef struct {
	int		digestID;
	XE_PKCS7_CONTENT_INFO	ctInfo;
	BIN		*digest;
} XE_PKCS7_DIGESTED_DATA;

typedef union {
	struct {
		int		detach;				// false(0), true(1)
	} encode;
	struct {
		int		verify;				// false(0), true(1)
	} decode;
} XE_PKCS7_DIGESTED_PARAM;

// EncryptedData

typedef struct {
	XE_PKCS7_ENC_CONTENT	encContent;
} XE_PKCS7_ENCRYPTED_DATA;

typedef union {
	struct {
		int		detach;				// false(0), true(1)
	} encode;
	struct {
		int		null;
	} decode;
} XE_PKCS7_ENCRYPTED_PARAM;

// Attribute

typedef struct {
	int		attribID;
	union {
		int		contentType;
		BIN		messageDigest;
		time_t	signingTime;
		BIN		randomNonce;
		int		sequenceNumber;
		BIN		counterSignature;	// der
		BIN		smimeCapabilities;	// der
		BIN		chainHash;
	} attribValue;
} XE_PKCS7_ATTRIBUTE;

typedef struct _XE_PKCS7_ATTRIBUTE_SET {
	XE_PKCS7_ATTRIBUTE	attrib;
	struct _XE_PKCS7_ATTRIBUTE_SET	*next;
} XE_PKCS7_ATTRIBUTE_SET;

// 2007/01/16 by ssosuny
typedef struct {
	int status;
	BIN cert;
	BIN random;
} XE_PKCS7_GWConnRespData;

typedef struct {
	int encID;
	BIN encKey;
	BIN content;
	BIN recipCert;
} XE_PKCS7_GWEnvelopedData;

typedef struct {
	int encID;
	BIN encKey;
	BIN encParam;		// iv, optional
	BIN content;	
} XE_PKCS7_GWEncryptedData;

typedef struct _XE_PKCS7_GWConnRespData_SET {
	XE_PKCS7_GWConnRespData	value;
	struct _XE_PKCS7_GWConnRespData_SET *next;
} XE_PKCS7_GWConnRespData_SET;

typedef struct _XE_PKCS7_GWEnvelopedData_SET {
	XE_PKCS7_GWEnvelopedData value;
	struct _XE_PKCS7_GWEnvelopedData_SET *next;
} XE_PKCS7_GWEnvelopedData_SET;

typedef struct _XE_PKCS7_GWEncryptedData_SET {
	XE_PKCS7_GWEncryptedData value;
	struct _XE_PKCS7_GWEncryptedData_SET *next;
} XE_PKCS7_GWEncryptedData_SET;

/**
 *	Error codes
 */

#define	ERR_PKCS7							(ERR_PKCS + 300)

#define	PKCS7_ERR_INVALID_INPUT				(ERR_PKCS7 + 1)
#define	PKCS7_ERR_INTERNAL					(ERR_PKCS7 + 2)
#define	PKCS7_ERR_MALLOC_FAILED				(ERR_PKCS7 + 3)

#define	PKCS7_ERR_UNKNOWN_TYPEID			(ERR_PKCS7 + 10)
#define	PKCS7_ERR_UNKNOWN_DIGESTID			(ERR_PKCS7 + 11)
#define	PKCS7_ERR_UNKNOWN_ENCID				(ERR_PKCS7 + 12)
#define	PKCS7_ERR_UNKNOWN_ALGID				(ERR_PKCS7 + 13)
#define	PKCS7_ERR_UNKNOWN_ATTRIBID			(ERR_PKCS7 + 15)
#define	PKCS7_ERR_UNKNOWN_VERSION			(ERR_PKCS7 + 16)

#define	PKCS7_ERR_MISMATCH_TYPEID			(ERR_PKCS7 + 19)

#define	PKCS7_ERR_NOT_EXIST					(ERR_PKCS7 + 20)
#define	PKCS7_ERR_ALREADY_EXIST				(ERR_PKCS7 + 21)

#define	PKCS7_ERR_BAD_CONTENT_INFO			(ERR_PKCS7 + 30)
#define	PKCS7_ERR_BAD_SIGNED_DATA			(ERR_PKCS7 + 31)
#define	PKCS7_ERR_BAD_ENVELOPED_DATA		(ERR_PKCS7 + 32)
#define	PKCS7_ERR_BAD_SIGNENVELOPED_DATA	(ERR_PKCS7 + 33)
#define	PKCS7_ERR_BAD_DIGESTED_DATA			(ERR_PKCS7 + 34)
#define	PKCS7_ERR_BAD_ENCRYPTED_DATA		(ERR_PKCS7 + 35)
#define	PKCS7_ERR_BAD_ATTRIBS				(ERR_PKCS7 + 40)
#define	PKCS7_ERR_BAD_CERT					(ERR_PKCS7 + 41)
#define	PKCS7_ERR_BAD_CRL					(ERR_PKCS7 + 42)
#define	PKCS7_ERR_BAD_PRIVKEY				(ERR_PKCS7 + 43)
#define	PKCS7_ERR_BAD_SIGNER_INFO			(ERR_PKCS7 + 44)
#define	PKCS7_ERR_BAD_RECIP_INFO			(ERR_PKCS7 + 45)
#define	PKCS7_ERR_BAD_ENC_CONTENT			(ERR_PKCS7 + 46)
#define	PKCS7_ERR_BAD_KEY					(ERR_PKCS7 + 47)

#define	PKCS7_ERR_INVALID_SIGNATURE			(ERR_PKCS7 + 50)
#define	PKCS7_ERR_INVALID_DIGEST			(ERR_PKCS7 + 51)

#define	PKCS7_ERR_NO_CONTENT				(ERR_PKCS7 + 60)
#define	PKCS7_ERR_NO_CERT					(ERR_PKCS7 + 61)
#define	PKCS7_ERR_NO_PRIVKEY				(ERR_PKCS7 + 62)
#define	PKCS7_ERR_NO_SIGNATURE				(ERR_PKCS7 + 63)
#define	PKCS7_ERR_NO_SIGNER_INFO			(ERR_PKCS7 + 64)
#define	PKCS7_ERR_NO_RECIP_INFO				(ERR_PKCS7 + 65)
#define	PKCS7_ERR_NO_ATTRIBS				(ERR_PKCS7 + 69)
#define	PKCS7_ERR_NO_CONTENT_TYPE_ATTRIB	(ERR_PKCS7 + 70)
#define	PKCS7_ERR_NO_MESSAGE_DIGEST_ATTRIB	(ERR_PKCS7 + 71)

#define	PKCS7_ERR_ENCODE_ASN				(ERR_PKCS7 + 90)
#define	PKCS7_ERR_DECODE_ASN				(ERR_PKCS7 + 91)

#define PKCS7_ERR_BAD_GWCONNREQ				(ERR_PKCS7 + 80)
#define PKCS7_ERR_BAD_STATUS_GWCONNRESP		(ERR_PKCS7 + 81)
#define PKCS7_ERR_NO_GWENCDATAKEY			(ERR_PKCS7 + 82)

/**
 *	Prototypes
 */

#ifdef  __cplusplus
extern "C" {
#endif

// pkcs7

XFA_EXPORT_TYPE
int		XFA_PKCS7_EncodeData				(BIN *pkcs7,
											 const BIN *data);

XFA_EXPORT_TYPE
int		XFA_PKCS7_DecodeData				(BIN *data,
											 const BIN *pkcs7);

//2005/12/21 ssosuny - DVCS Request/Response Encode
XFA_EXPORT_TYPE
int		XFA_PKCS7_DVCS_EncodeData			(BIN *pkcs7,
											 const BIN *data, const int dvcstype);

XFA_EXPORT_TYPE
int		XFA_PKCS7_EncodeSigned				(BIN *pkcs7,
											 const int digestID,
											 const BIN *content,
											 const BIN *signerCert,
											 const BIN *signerPrivKey,
											 const BIN *caCert,			// optional
											 const BIN *crl);			// optional

XFA_EXPORT_TYPE
int		XFA_PKCS7_EncodeSigned_Init			(BIN *toBeSignedData,
											 const int digestID,
											 const BIN *content);

XFA_EXPORT_TYPE
int		XFA_PKCS7_EncodeSigned_Final		(BIN *pkcs7,
											 const int digestID,
											 const BIN *content,
											 const BIN *toBeSignedData,
											 const BIN *signature,
											 const BIN *signerCert,
											 const BIN *caCert,			// optional
											 const BIN *crl);			// optional

XFA_EXPORT_TYPE
int		XFA_PKCS7_DecodeSigned				(int *digestID,
											 BIN *content,
											 BIN *signerCert,
											 BIN *caCert,				// optional
											 BIN *crl,					// optional
											 const BIN *pkcs7);

XFA_EXPORT_TYPE
int		XFA_PKCS7_EncodeEnveloped			(BIN *pkcs7,
											 const int encID,
											 const BIN *content,
											 const BIN *recipCert);

// 20110726 대용량 파일 암복호 위한 API
XFA_EXPORT_TYPE
int     	XFA_PKCS7_EncodeEnvelopedEx		 (BIN *pkcs7,
											  int encID,
											  BIN_LIST recipCert,
					                          const BIN *content);

// 20110726 대용량 파일 암복호 위한 API
XFA_EXPORT_TYPE
int		XFA_PKCS7_EncodeEnvelopedExBig			(BIN *pkcs7,
												 BIN *key,
												 BIN *iv,
												 int encID,
												 BIN_LIST recipCert,
			                          			 const BIN *content);

XFA_EXPORT_TYPE
int		XFA_PKCS7_DecodeEnveloped			(int *encID,
											 BIN *content,
											 const BIN *pkcs7,
											 const BIN *recipCert,
											 const BIN *recipPrivKey);

XFA_EXPORT_TYPE
int		XFA_PKCS7_DecodeEnveloped_Init		(BIN *toBeDecryptedData,
											 const BIN *pkcs7,
											 const BIN *recipCert);

XFA_EXPORT_TYPE
int		XFA_PKCS7_DecodeEnveloped_Final		(int *encID,
											 BIN *content,
											 const BIN *pkcs7,
											 const BIN *recipCert,
											 const BIN *decryptedData);

XFA_EXPORT_TYPE
int		XFA_PKCS7_EncodeSignEnveloped		(BIN *pkcs7,
											 const int digestID,
											 const int encID,
											 const BIN *content,
											 const BIN *signerCert,
											 const BIN *signerPrivKey,
											 const BIN *recipCert,
											 const BIN *caCert,			// optional
											 const BIN *crl);			// optional

XFA_EXPORT_TYPE
int		XFA_PKCS7_DecodeSignEnveloped		(int *digestID,
											 int *encID,
											 BIN *content,
											 BIN *signerCert,
											 BIN *caCert,				// optional
											 BIN *crl,					// optional
											 const BIN *pkcs7,
											 const BIN *recipCert,
											 const BIN *recipPrivKey);

XFA_EXPORT_TYPE
int		XFA_PKCS7_EncodeDigested			(BIN *pkcs7,
											 const int digestID,
											 const BIN *content);

XFA_EXPORT_TYPE
int		XFA_PKCS7_DecodeDigested			(int *digestID,
											 BIN *content,
											 const BIN *pkcs7);

XFA_EXPORT_TYPE
int		XFA_PKCS7_EncodeEncrypted			(BIN *pkcs7,
											 const int encID,
											 const BIN *content,
											 const BIN *key);

XFA_EXPORT_TYPE
int		XFA_PKCS7_DecodeEncrypted			(int *encID,
											 BIN *content,
											 const BIN *pkcs7,
											 const BIN *key);

// version

XFA_EXPORT_TYPE
char *	XFA_PKCS7_GetVersion				(void);

XFA_EXPORT_TYPE
int		XFA_PKCS7_CheckVersion				(const char *version);			// optional

// error

XFA_EXPORT_TYPE 
char *	XFA_PKCS7_GetErrorReason			(const int code, 
											 const int locale);

// for advanced user {{

// BIN

XFA_EXPORT_TYPE
XE_PKCS7_BIN_SET *
		XFA_PKCS7_BIN_SET_New				(void);

XFA_EXPORT_TYPE
void	XFA_PKCS7_BIN_SET_Reset				(XE_PKCS7_BIN_SET *bins);

XFA_EXPORT_TYPE
void	XFA_PKCS7_BIN_SET_Free				(XE_PKCS7_BIN_SET *bins);

XFA_EXPORT_TYPE
int		XFA_PKCS7_BIN_SET_Add				(XE_PKCS7_BIN_SET **bins,				// in/out
											 const BIN *bin);

// ContentInfo

XFA_EXPORT_TYPE
void	XFA_PKCS7_Content_Reset				(XE_PKCS7_CONTENT_INFO *ctInfo);

XFA_EXPORT_TYPE
int		XFA_PKCS7_Content_Encode			(BIN *output, 
											 const XE_PKCS7_CONTENT_INFO *ctInfo);

XFA_EXPORT_TYPE
int		XFA_PKCS7_Content_Decode			(XE_PKCS7_CONTENT_INFO *ctInfo, 
											 const BIN *input);

// Data

XFA_EXPORT_TYPE
int		XFA_PKCS7_Data_Encode				(XE_PKCS7_CONTENT_INFO *dataInfo,
											 const BIN *data);

XFA_EXPORT_TYPE
int		XFA_PKCS7_Data_Decode				(BIN *data,
											 const XE_PKCS7_CONTENT_INFO *dataInfo);

// 2005/12/21 ssosuny - DVCS Request/Response
XFA_EXPORT_TYPE
int		XFA_PKCS7_DVCS_Data_Encode			(XE_PKCS7_CONTENT_INFO *dataInfo,
											 const BIN *data, const int dvcstype);

// SignedData

XFA_EXPORT_TYPE
void	XFA_PKCS7_SignerInfo_Reset			(XE_PKCS7_SIGNER_INFO *signerInfo);

XFA_EXPORT_TYPE
int		XFA_PKCS7_SignerInfo_Set			(XE_PKCS7_SIGNER_INFO *signerInfo,
											 const int digestID,
											 const BIN *authAttribs,				// option
											 const BIN *signature,					// option
											 const BIN *unauthAttribs,				// option
											 const BIN *signerCert,
											 const BIN *privKey);					// option

XFA_EXPORT_TYPE
int		XFA_PKCS7_SignerInfo_Sign			(BIN *signature,
											 const XE_PKCS7_SIGNER_INFO *signerInfo,
											 const XE_PKCS7_CONTENT_INFO *ctInfo);

XFA_EXPORT_TYPE
int		XFA_PKCS7_SignerInfo_Verify			(const XE_PKCS7_SIGNER_INFO *signerInfo,
											 const XE_PKCS7_CONTENT_INFO *ctInfo,
											 const BIN *signerCert);

XFA_EXPORT_TYPE
XE_PKCS7_SIGNER_INFO_SET *
		XFA_PKCS7_SignerInfos_New			(void);

XFA_EXPORT_TYPE
void	XFA_PKCS7_SignerInfos_Reset			(XE_PKCS7_SIGNER_INFO_SET *signerInfos);

XFA_EXPORT_TYPE
void	XFA_PKCS7_SignerInfos_Free			(XE_PKCS7_SIGNER_INFO_SET *signerInfos);

XFA_EXPORT_TYPE
int		XFA_PKCS7_SignerInfos_Add			(XE_PKCS7_SIGNER_INFO_SET **signerInfos,	// in/out
											 const XE_PKCS7_SIGNER_INFO *signerInfo);

XFA_EXPORT_TYPE
XE_PKCS7_SIGNED_DATA *
		XFA_PKCS7_Signed_New				(void);

XFA_EXPORT_TYPE
void	XFA_PKCS7_Signed_Reset				(XE_PKCS7_SIGNED_DATA *signData);

XFA_EXPORT_TYPE
void	XFA_PKCS7_Signed_Free				(XE_PKCS7_SIGNED_DATA *signData);

XFA_EXPORT_TYPE
int		XFA_PKCS7_Signed_Sign				(XE_PKCS7_SIGNED_DATA *signData,		// in/out
											 const XE_PKCS7_CONTENT_INFO *ctInfo,
											 const XE_PKCS7_SIGNED_PARAM *param);

XFA_EXPORT_TYPE
int		XFA_PKCS7_Signed_Verify				(const XE_PKCS7_SIGNED_DATA *signData,
											 const XE_PKCS7_CONTENT_INFO *ctInfo,	// optional
											 const XE_PKCS7_BIN_SET *outerCerts,	// optional
											 const XE_PKCS7_SIGNED_PARAM *param);

XFA_EXPORT_TYPE
int		XFA_PKCS7_Signed_Encode				(XE_PKCS7_CONTENT_INFO *signInfo,
											 const XE_PKCS7_SIGNED_DATA *signData,
											 const XE_PKCS7_SIGNED_PARAM *param);

XFA_EXPORT_TYPE
int		XFA_PKCS7_Signed_Decode				(XE_PKCS7_SIGNED_DATA *signData,
											 const XE_PKCS7_CONTENT_INFO *signInfo,
											 const XE_PKCS7_SIGNED_PARAM *param);

// EnvelopedData

XFA_EXPORT_TYPE
void	XFA_PKCS7_RecipInfo_Reset			(XE_PKCS7_RECIP_INFO *recipInfo);

XFA_EXPORT_TYPE
int		XFA_PKCS7_RecipInfo_Set				(XE_PKCS7_RECIP_INFO *recipInfo,
											 const BIN *recipCert);

XFA_EXPORT_TYPE
int		XFA_PKCS7_RecipInfo_Develope		(XE_PKCS7_CONTENT_INFO *ctInfo,
											 const XE_PKCS7_ENC_CONTENT *encContent,
											 const XE_PKCS7_RECIP_INFO *recipInfo,
											 const BIN *privKey);

// 2007/01/27 by ssosuny: EnvelopedData의 RSA-OAEP 지원
XFA_EXPORT_TYPE
int		XFA_PKCS7_RecipInfo_DevelopeWithRSAOAEP(XE_PKCS7_CONTENT_INFO *ctInfo,
												const XE_PKCS7_ENC_CONTENT *encContent,
												const XE_PKCS7_RECIP_INFO *recipInfo,
												const BIN *privKey);

XFA_EXPORT_TYPE
XE_PKCS7_RECIP_INFO_SET *
		XFA_PKCS7_RecipInfos_New			(void);

XFA_EXPORT_TYPE
void	XFA_PKCS7_RecipInfos_Reset			(XE_PKCS7_RECIP_INFO_SET *recipInfos);

XFA_EXPORT_TYPE
void	XFA_PKCS7_RecipInfos_Free			(XE_PKCS7_RECIP_INFO_SET *recipInfos);

XFA_EXPORT_TYPE
int		XFA_PKCS7_RecipInfos_Add			(XE_PKCS7_RECIP_INFO_SET **recipInfos,	// in/out
											 const XE_PKCS7_RECIP_INFO *recipInfo);

XFA_EXPORT_TYPE
XE_PKCS7_RECIP_INFO *
		XFA_PKCS7_RecipInfos_Get			(const XE_PKCS7_RECIP_INFO_SET *recipInfos,
											 const BIN *recipCert);

XFA_EXPORT_TYPE
void	XFA_PKCS7_EncContent_Reset			(XE_PKCS7_ENC_CONTENT *encContent);

XFA_EXPORT_TYPE
int		XFA_PKCS7_EncContent_Encrypt		(XE_PKCS7_ENC_CONTENT *encContent,
											 const XE_PKCS7_CONTENT_INFO *ctInfo,
											 const BIN *key,
											 const int encID);

// 20110726, DVCS관련 대용량 파일 암복호(iv 값을 빼주기 위한 API)
XFA_EXPORT_TYPE
int		XFA_PKCS7_EncContent_EncryptEx		(XE_PKCS7_ENC_CONTENT *encContent,
											 BIN *iv,
											 const XE_PKCS7_CONTENT_INFO *ctInfo,
											 const BIN *key,
											const int encID);

XFA_EXPORT_TYPE
int		XFA_PKCS7_EncContent_Decrypt		(XE_PKCS7_CONTENT_INFO *ctInfo,
											 const XE_PKCS7_ENC_CONTENT *encContent,
											 const BIN *key);

XFA_EXPORT_TYPE
XE_PKCS7_ENVELOPED_DATA *
		XFA_PKCS7_Enveloped_New				(void);

XFA_EXPORT_TYPE
void	XFA_PKCS7_Enveloped_Reset			(XE_PKCS7_ENVELOPED_DATA *evpData);

XFA_EXPORT_TYPE
void	XFA_PKCS7_Enveloped_Free			(XE_PKCS7_ENVELOPED_DATA *evpData);

XFA_EXPORT_TYPE
int		XFA_PKCS7_Enveloped_Envelope		(XE_PKCS7_ENVELOPED_DATA *evpData,		// in/out
											 const XE_PKCS7_CONTENT_INFO *ctInfo,
											 const int encID,
											 const XE_PKCS7_ENVELOPED_PARAM *param);

// 20110726, DVCS관련 대용량 파일 암호 처리시 외부에서 암호화하기 위해 key 값을 빼주기 위해 만든 API
XFA_EXPORT_TYPE
int		XFA_PKCS7_Enveloped_EnvelopeEx		(XE_PKCS7_ENVELOPED_DATA *evpData,		// in/out
											 BIN *key,
											 BIN *iv,
											 const XE_PKCS7_CONTENT_INFO *ctInfo,
											 const int encID,
											 const XE_PKCS7_ENVELOPED_PARAM *evpParam);

XFA_EXPORT_TYPE
int		XFA_PKCS7_Enveloped_Develope		(XE_PKCS7_CONTENT_INFO *ctInfo,
											 const XE_PKCS7_ENVELOPED_DATA *evpData,
											 const BIN *recipCert,
											 const BIN *recipPrivKey,
											 const XE_PKCS7_ENVELOPED_PARAM *param);

XFA_EXPORT_TYPE
int		XFA_PKCS7_Enveloped_Encode			(XE_PKCS7_CONTENT_INFO *evpInfo,
											 const XE_PKCS7_ENVELOPED_DATA *evpData,
											 const XE_PKCS7_ENVELOPED_PARAM *param);

XFA_EXPORT_TYPE
int		XFA_PKCS7_Enveloped_Decode			(XE_PKCS7_ENVELOPED_DATA *evpData,
											 const XE_PKCS7_CONTENT_INFO *evpInfo,
											 const XE_PKCS7_ENVELOPED_PARAM *param);

// SignedAndEnvelopedData

XFA_EXPORT_TYPE
XE_PKCS7_SIGNENVELOPED_DATA *
		XFA_PKCS7_SignEnveloped_New			(void);

XFA_EXPORT_TYPE
void	XFA_PKCS7_SignEnveloped_Reset		(XE_PKCS7_SIGNENVELOPED_DATA *signEvpData);

XFA_EXPORT_TYPE
void	XFA_PKCS7_SignEnveloped_Free		(XE_PKCS7_SIGNENVELOPED_DATA *signEvpData);

XFA_EXPORT_TYPE
int		XFA_PKCS7_SignEnveloped_SignEnvelope(XE_PKCS7_SIGNENVELOPED_DATA *signEvpData,	// in/out
											 const XE_PKCS7_CONTENT_INFO *ctInfo,
											 const int encID,
											 const XE_PKCS7_SIGNENVELOPED_PARAM *param);

XFA_EXPORT_TYPE
int		XFA_PKCS7_SignEnveloped_DevelopeVerify(XE_PKCS7_CONTENT_INFO *ctInfo,
											 const XE_PKCS7_SIGNENVELOPED_DATA *signEvpData,
											 const BIN *recipCert,
											 const BIN *recipPrivKey,
											 const XE_PKCS7_BIN_SET *outerCerts,	// optional
											 const XE_PKCS7_SIGNENVELOPED_PARAM *param);

XFA_EXPORT_TYPE
int		XFA_PKCS7_SignEnveloped_Encode		(XE_PKCS7_CONTENT_INFO *signEvpInfo, 
											 const XE_PKCS7_SIGNENVELOPED_DATA *signEvpData,
											 const XE_PKCS7_SIGNENVELOPED_PARAM *param);

XFA_EXPORT_TYPE
int		XFA_PKCS7_SignEnveloped_Decode		(XE_PKCS7_SIGNENVELOPED_DATA *signEvpData, 
											 const XE_PKCS7_CONTENT_INFO *signEvpInfo,
											 const XE_PKCS7_SIGNENVELOPED_PARAM *param);

// DigestedData

XFA_EXPORT_TYPE
XE_PKCS7_DIGESTED_DATA *
		XFA_PKCS7_Digested_New				(void);

XFA_EXPORT_TYPE
void	XFA_PKCS7_Digested_Reset			(XE_PKCS7_DIGESTED_DATA *digestData);

XFA_EXPORT_TYPE
void	XFA_PKCS7_Digested_Free				(XE_PKCS7_DIGESTED_DATA *digestData);

XFA_EXPORT_TYPE
int		XFA_PKCS7_Digested_Digest			(XE_PKCS7_DIGESTED_DATA *digestData,
											 const XE_PKCS7_CONTENT_INFO *ctInfo,
											 const int digestID);

XFA_EXPORT_TYPE
int		XFA_PKCS7_Digested_Verify			(const XE_PKCS7_DIGESTED_DATA *digestData,
											 const XE_PKCS7_CONTENT_INFO *ctInfo);	// optional

XFA_EXPORT_TYPE
int		XFA_PKCS7_Digested_Encode			(XE_PKCS7_CONTENT_INFO *digestInfo,
											 const XE_PKCS7_DIGESTED_DATA *digestData,
											 const XE_PKCS7_DIGESTED_PARAM *param);

XFA_EXPORT_TYPE
int		XFA_PKCS7_Digested_Decode			(XE_PKCS7_DIGESTED_DATA *digestData,
											 const XE_PKCS7_CONTENT_INFO *digestInfo,
											 const XE_PKCS7_DIGESTED_PARAM *param);

// EncryptedData

XFA_EXPORT_TYPE
XE_PKCS7_ENCRYPTED_DATA *
		XFA_PKCS7_Encrypted_New				(void);

XFA_EXPORT_TYPE
void	XFA_PKCS7_Encrypted_Reset			(XE_PKCS7_ENCRYPTED_DATA *encData);

XFA_EXPORT_TYPE
void	XFA_PKCS7_Encrypted_Free			(XE_PKCS7_ENCRYPTED_DATA *encData);

XFA_EXPORT_TYPE
int		XFA_PKCS7_Encrypted_Encrypt			(XE_PKCS7_ENCRYPTED_DATA *encData,
											 const XE_PKCS7_CONTENT_INFO *ctInfo,
											 const BIN *key,
											 const int encID);

XFA_EXPORT_TYPE
int		XFA_PKCS7_Encrypted_Decrypt			(XE_PKCS7_CONTENT_INFO *ctInfo,
											 const XE_PKCS7_ENCRYPTED_DATA *encData,
											 const BIN *key);

XFA_EXPORT_TYPE
int		XFA_PKCS7_Encrypted_Encode			(XE_PKCS7_CONTENT_INFO *encInfo,
											 const XE_PKCS7_ENCRYPTED_DATA *encData,
											 const XE_PKCS7_ENCRYPTED_PARAM *param);

XFA_EXPORT_TYPE
int		XFA_PKCS7_Encrypted_Decode			(XE_PKCS7_ENCRYPTED_DATA *encData,
											 const XE_PKCS7_CONTENT_INFO *encInfo,
											 const XE_PKCS7_ENCRYPTED_PARAM *param);

// Attributes

XFA_EXPORT_TYPE 
void	XFA_PKCS7_Attribute_Reset			(XE_PKCS7_ATTRIBUTE *attrib);

XFA_EXPORT_TYPE 
XE_PKCS7_ATTRIBUTE_SET *
		XFA_PKCS7_Attributes_New			(void);

XFA_EXPORT_TYPE 
void	XFA_PKCS7_Attributes_Reset			(XE_PKCS7_ATTRIBUTE_SET *attribs);

XFA_EXPORT_TYPE 
void	XFA_PKCS7_Attributes_Free			(XE_PKCS7_ATTRIBUTE_SET *attribs);

XFA_EXPORT_TYPE 
int		XFA_PKCS7_Attributes_Add			(XE_PKCS7_ATTRIBUTE_SET **attribs,		// in/out
											 const XE_PKCS7_ATTRIBUTE *attrib);

XFA_EXPORT_TYPE 
int		XFA_PKCS7_Attributes_Get			(XE_PKCS7_ATTRIBUTE *attrib,
											 const XE_PKCS7_ATTRIBUTE_SET *attribs,
											 const int attribID);

XFA_EXPORT_TYPE 
int		XFA_PKCS7_Attributes_GetEx			(XE_BIN_LIST *attribsList, 
											 const BIN *input, 
											 const int oidID);

XFA_EXPORT_TYPE 
int		XFA_PKCS7_Attributes_GenAuth		(XE_PKCS7_ATTRIBUTE_SET **attribs,		// in/out
											 const XE_PKCS7_CONTENT_INFO *ctInfo,
											 const int digestID);

XFA_EXPORT_TYPE 
int		XFA_PKCS7_Attributes_CheckAuth		(const XE_PKCS7_ATTRIBUTE_SET *attribs,
											 const XE_PKCS7_CONTENT_INFO *ctInfo,
											 const int digestID);

XFA_EXPORT_TYPE 
int		XFA_PKCS7_Attributes_Encode			(BIN *output,
											 const XE_PKCS7_ATTRIBUTE_SET *attribs);

XFA_EXPORT_TYPE 
int		XFA_PKCS7_Attributes_Decode			(XE_PKCS7_ATTRIBUTE_SET *attribs,
											 const BIN *input);

// Certs

XFA_EXPORT_TYPE 
int		XFA_PKCS7_Certs_GetCert				(BIN *cert,
											 const XE_PKCS7_BIN_SET *certs,
											 const BIN *issuerSerial);
XFA_EXPORT_TYPE 
int		XFA_PKCS7_Certs_GetCert_SKI			(BIN *cert,
											 const XE_PKCS7_BIN_SET *certs,
											 const BIN *subjectKeyIdentifier);

XFA_EXPORT_TYPE 
int		XFA_PKCS7_Certs_GetParent			(BIN *parent,
											 const XE_PKCS7_BIN_SET *certs,
											 const BIN *cert);

XFA_EXPORT_TYPE 
int		XFA_PKCS7_Certs_GetChain			(XE_PKCS7_BIN_SET **chain,
											 const XE_PKCS7_BIN_SET *certs,
											 const BIN *cert);

// }}

// 2007/01/16 by ssosuny : 범용인증서 중계서비스 지원(금결원)
XFA_EXPORT_TYPE
int		XFA_PKCS7_EncodeGWConnReq		(BIN *request, 
											 const BIN *cert, 
											 const BIN *random);
XFA_EXPORT_TYPE
int		XFA_PKCS7_DecodeGWConnReq		(BIN *cert,
											 BIN *random,
											 const BIN *request);
XFA_EXPORT_TYPE
int		XFA_PKCS7_EncodeGWConnResp		(BIN *response,
											 const XE_PKCS7_GWConnRespData_SET *respParam);

XFA_EXPORT_TYPE
int		XFA_PKCS7_DecodeGWConnResp		(XE_PKCS7_GWConnRespData_SET **respDataSet,
										const BIN *response);

XFA_EXPORT_TYPE
int		XFA_PKCS7_EncodeGWEnvelopedData	(BIN *evpData,
										 const XE_PKCS7_GWEnvelopedData_SET *evpParam);

XFA_EXPORT_TYPE
int		XFA_PKCS7_DecodeGWEnvelopedData	(int *encID,
										 BIN *encKey,
										 BIN *content,
										 const BIN *evp,
										 const BIN *recipCert,
										 const BIN *recipPrivKey);
XFA_EXPORT_TYPE
int		XFA_PKCS7_EncodeGWEncryptedData	(BIN *encData,
										 const XE_PKCS7_GWEncryptedData_SET *encParam);

XFA_EXPORT_TYPE
int		XFA_PKCS7_DecodeGWEncryptedData(XE_PKCS7_GWEncryptedData_SET **encDataSet,	//in/out
										const BIN *enc);		

XFA_EXPORT_TYPE
XE_PKCS7_GWConnRespData_SET *XFA_PKCS7_GWConnRespDataSet_New(void);

XFA_EXPORT_TYPE
void	XFA_PKCS7_GWConnRespData_Reset	(XE_PKCS7_GWConnRespData *gwRespData);

XFA_EXPORT_TYPE
void	XFA_PKCS7_GWConnRespDataSet_Reset(XE_PKCS7_GWConnRespData_SET *gwRespDataSet);

XFA_EXPORT_TYPE
void	XFA_PKCS7_GWConnRespDataSet_Free(XE_PKCS7_GWConnRespData_SET *gwRespDataSet);

XFA_EXPORT_TYPE
int		XFA_PKCS7_GWConnRespDataSet_Add(XE_PKCS7_GWConnRespData_SET **gwRespDataSet,
						 const XE_PKCS7_GWConnRespData *gwRespData);


XFA_EXPORT_TYPE
XE_PKCS7_GWEnvelopedData_SET *XFA_PKCS7_GWEnvelopedDataSet_New(void);

XFA_EXPORT_TYPE
void	XFA_PKCS7_GWEnvelopedData_Reset(XE_PKCS7_GWEnvelopedData *evpData);

XFA_EXPORT_TYPE
void	XFA_PKCS7_GWEnvelopedDataSet_Reset(XE_PKCS7_GWEnvelopedData_SET *evpDataSet);

XFA_EXPORT_TYPE
void	XFA_PKCS7_GWEnvelopedDataSet_Free(XE_PKCS7_GWEnvelopedData_SET *evpDataSet);

XFA_EXPORT_TYPE
int		XFA_PKCS7_GWEnvelopedDataSet_Add(XE_PKCS7_GWEnvelopedData_SET **evpDataSet,
										 const XE_PKCS7_GWEnvelopedData *evpData);

XFA_EXPORT_TYPE
XE_PKCS7_GWEncryptedData_SET *	XFA_PKCS7_GWEncryptedDataSet_New(void);

XFA_EXPORT_TYPE
void	XFA_PKCS7_GWEncryptedData_Reset(XE_PKCS7_GWEncryptedData *encData);

XFA_EXPORT_TYPE
void	XFA_PKCS7_GWEncryptedDataSet_Reset(XE_PKCS7_GWEncryptedData_SET *encDataSet);

XFA_EXPORT_TYPE
void	XFA_PKCS7_GWEncryptedDataSet_Free(XE_PKCS7_GWEncryptedData_SET *encDataSet);

XFA_EXPORT_TYPE
int		XFA_PKCS7_GWEncryptedDataSet_Add(XE_PKCS7_GWEncryptedData_SET **encDataSet,
										 const XE_PKCS7_GWEncryptedData *encData);



#ifdef  __cplusplus
}
#endif

#endif
