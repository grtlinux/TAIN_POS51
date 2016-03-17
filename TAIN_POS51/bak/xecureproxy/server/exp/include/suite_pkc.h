//
//	$Id: suite_pkc.h,v 1.30 2007-07-04 08:22:44 jhhong Exp $
//

#ifndef _SUITE_PKC_H_
#define _SUITE_PKC_H_

#include "exp_global.h"
#include "suite_asn.h"

/**
 *	Constants
 */

/*Get Signature and Hash Algorithm*/
/*번호는 CSP 쪽 참조하여 정함.  */
#define XE_PKC_SIGNALGID_SHA1WithRSA			3
#define XE_PKC_SIGNALGID_SHA256WithRSA			4
#define XE_PKC_SIGNALGID_SHA384WithRSA			5
#define XE_PKC_SIGNALGID_SHA512WithRSA			6
#define XE_PKC_SIGNALGID_SHA1WithKCDSA			21
#define XE_PKC_SIGNALGID_HAS160WithKCDSA		22
/*2009-12-24 by yjvc80 Add: suite_csp.h 참고 */
#define XE_PKC_SIGNALGID_SHA1WithKCDSA1			25
#define XE_PKC_SIGNALGID_HAS160WithKCDSA1		26
/*2011-07-05 by cristyanne : add SID for expended version of KCDSA, KCDSA1*/
#define XE_PKC_SIGNALGID_SHA256WithKCDSA		27
#define XE_PKC_SIGNALGID_SHA384WithKCDSA		28
#define XE_PKC_SIGNALGID_SHA512WithKCDSA		29
#define XE_PKC_SIGNALGID_SHA256WithKCDSA1		30

/*2011-07-20 by cristyanne : add ID for expended version of KCDSA1 */
/*
#define XE_PKC_SIGNALGID_SHA384WithKCDSA1		35
#define XE_PKC_SIGNALGID_SHA512WithKCDSA1		36
// check suite_csp.h line120 
*/

#define XE_PKC_SIGNALGID_KCDSA					51
#define XE_PKC_SIGNALGID_KCDSA1					52

/*for compatibility with previous version {{*/

/*Certificate Class Flag Defined*/

#define CERT_CLASS_ROOT						0
#define	CERT_CLASS_CA						1
#define CERT_CLASS_USER						2

/*Certificate Usage*/

#define CERT_USAGE_KM						1
#define CERT_USAGE_SN						2
#define CERT_USAGE_TSA						3
#define CERT_USAGE_OCSPS					4
#define CERT_USAGE_CODESIGNING				5
#define CERT_USAGE_EMAIL					6
#define CERT_USAGE_SRVAUTH					7
#define CERT_USAGE_CLIAUTH					8

/*RFC 2459 Certificate Profile Readable Structure*/

#define	KU_DIGITAL_SIGNATURE				1
#define	KU_NON_REPUDIATION					2
#define	KU_KEY_ENCIPHERMENT					4
#define	KU_DATA_ENCIPHERMENT				8
#define	KU_KEY_AGREEMENT					16
#define	KU_KEY_CERT_SIGN					32
#define	KU_CRL_SIGN							64
#define	KU_ENCIPHER_ONLY					128
#define	KU_DECIPHER_ONLY					256

/*max length*/

#define MAX_DN_LEN							(200+1)	
#define MAX_SERIAL_LEN						20
#define MAX_ALGDESC_LEN 					50
#define MAX_RDN_LEN 						1024
#define MAX_SIGNATURE_LEN					1024
#define MAX_DATESTR_LEN 					50
#define MAX_KEYID_LEN						80
#define MAX_KUDESC_LEN						200
#define	MAX_HASH_LEN						65		/*// max 256 bits hash*/

/*// Xecure SSL Certificate Check Param Defined*/

#define SSLCHK_SIG							0x0001	/*// Signature Check Flag*/
#define SSLCHK_CRL							0x0010	/*// Revoked Or Not Check Flag*/
#define SSLCHK_TME							0x0100	/*// Expired Or Not Check Flag*/
#define SSLCHK_ITM							0x1000	/*// Issuer Expired Or Not Check Flag*/

/*X520 Name Abb. Defined*/

#define X520_COMMON_ABB						"CN"
#define X520_COUNTRY_ABB					"C"
#define X520_LOCALITY_ABB					"L"
#define X520_STATEORPROVINCE_ABB			"S"
#define X520_ORGANIZATION_ABB				"O"
#define X520_ORGANIZATIONALUNIT_ABB			"OU"
#define X520_TITLE_ABB						"T"
#define PKCS9_EMAIL_ABB						"E"
#define IBS_USERID_ABB						"ID"
#define PSS_UCLDOMAINCOMPO_ABB				"DC"
#define	X520_DNQUALIFIER_ABB				"DNQUALIFIER"

/*}}*/

/**
 *	Struct
 */

typedef struct _CertInfo {
	unsigned char	nBits;

/*	// - version*/
	int		nVersion;
	// - serial
	unsigned int nSerial;
	char	sSerial[MAX_SERIAL_LEN*2+1];
	// - signature
	char 	sSignatureAlgDesc[MAX_ALGDESC_LEN];
	// - issuer
	char 	sIssuerRDN[MAX_RDN_LEN];
	// - validity
	char 	sFrom[MAX_DATESTR_LEN];
	char 	sTo[MAX_DATESTR_LEN];
	// - subject
	char 	sSubjectRDN[MAX_RDN_LEN];
	// - subjectPublicKeyInfo
	char 	sSubjectKeyAlgDesc[MAX_ALGDESC_LEN];
	char 	sSubjectPublicKey[MAX_SIGNATURE_LEN];
	int	 	nPubKeyLen;
	// - signatureValue
	char 	sSignature[MAX_SIGNATURE_LEN];
	
	// - exts
	//   - akid
	char	sAuthorityKeyID[MAX_KEYID_LEN];
	//   - skid
	char	sSubjectKeyID[MAX_KEYID_LEN];
	//   - keyUsage
	char	sKeyUsageDesc[MAX_KUDESC_LEN];
	unsigned int	nKeyUsage;
	//   - privKeyUsagePeriod
	char	sPrivateKeyUsagePeriodFrom[MAX_DATESTR_LEN];
	char	sPrivateKeyUsagePeriodTo[MAX_DATESTR_LEN];
	//   - certPolicies
	int		nPolicyNum;
	char	sPolicyID[MAX_RDN_LEN];
	char	sCPSURI[MAX_DN_LEN];
	char	sUserNotice[MAX_DN_LEN];
	//   - subAltName
	char	sSubjectAltName[MAX_RDN_LEN];
	//     - vid
	char	sVIDHashAlgDesc[MAX_ALGDESC_LEN];
	char	sVID[MAX_HASH_LEN];
	//   - issAltName
	char	sIssuerAltName[MAX_RDN_LEN];
	//   - constraints
	char	sBasicConstraints[MAX_KEYID_LEN];
	//   - extKeyUsage
	char	sExtendedKeyUsage[MAX_RDN_LEN];
	//   - crlDPs
	char	sCrlDistributionPoints[MAX_RDN_LEN];
	//   - AIAs
	char	sAIAs[MAX_RDN_LEN];
	//   - netscape
	char	sNetscapeUsageDesc[MAX_KUDESC_LEN];

	char 	sMSFP[MAX_HASH_LEN];
} CertInfo;

typedef struct _CertInfoEx {
	CertInfo certInfo;
	
	//	-----------------------------------------
	char registeredNumber[20];

	char representativeName[20];

	char representativeTitle[20];

	char corporationName[180];

	char rsa_modulus[1000];

	char rsa_exponent[5];

#define MAX_KCDSA_KEY_VALUE 1024 

	char kcdsa_p[MAX_KCDSA_KEY_VALUE];

	char kcdsa_q[MAX_KCDSA_KEY_VALUE];

	char kcdsa_g[MAX_KCDSA_KEY_VALUE];

	char kcdsa_j[MAX_KCDSA_KEY_VALUE];

	char kcdsa_seed[MAX_KCDSA_KEY_VALUE];

	char kcdsa_counter[MAX_KCDSA_KEY_VALUE];

	unsigned int nIssuerSerial;
	char	sIssuerSerial[MAX_SERIAL_LEN*2+1];

	void *param1;

	void *param2;
	//	-----------------------------------------
} CertInfoEx;

/**
 *	Error codes
 */

#define	PKC_ERR_INVALID_INPUT				(ERR_PKC + 1)
#define	PKC_ERR_INTERNAL					(ERR_PKC + 2)
#define	PKC_ERR_MALLOC_FAILED				(ERR_PKC + 3)

#define	PKC_ERR_UNKNOWN_ALGID				(ERR_PKC + 10)
#define	PKC_ERR_UNKNOWN_PKEYID				(ERR_PKC + 11)
#define	PKC_ERR_UNKNOWN_SIGNID				(ERR_PKC + 12)
#define	PKC_ERR_UNKNOWN_HASHID				(ERR_PKC + 13)

#define	PKC_ERR_BAD_CERT					(ERR_PKC + 30)
#define	PKC_ERR_BAD_RDN						(ERR_PKC + 32)
#define	PKC_ERR_BAD_EXTENSION				(ERR_PKC + 33)
#define	PKC_ERR_BAD_AUTHKEYID				(ERR_PKC + 34)
#define	PKC_ERR_BAD_SUBKEYID				(ERR_PKC + 35)
#define	PKC_ERR_BAD_KEYUSAGE				(ERR_PKC + 36)
#define	PKC_ERR_BAD_CERTPOLICIES			(ERR_PKC + 37)

#define PKC_ERR_INVALID_SIGNATURE			(ERR_PKC + 50)
#define PKC_ERR_INVALID_TIME				(ERR_PKC + 51)
#define PKC_ERR_INVALID_VID					(ERR_PKC + 52)

#define	PKC_ERR_NO_PUBKEY					(ERR_PKC + 60)
#define	PKC_ERR_NO_EXTENSION				(ERR_PKC + 61)
#define	PKC_ERR_NO_VIDINFO					(ERR_PKC + 62)

#define PKC_ERR_CERT_REVOKED				(ERR_PKC + 82)
#define PKC_ERR_USER_CERT_TIME				(ERR_PKC + 83)
#define PKC_ERR_ISSUER_CERT_TIME			(ERR_PKC + 84)

/**
 *	Prototypes
 */

#ifdef  __cplusplus
extern "C" {
#endif

// cert info

XFA_EXPORT_TYPE
int		XFA_GetCertificateCtxBin			(OssGlobal *, const BIN *, Certificate **);

XFA_EXPORT_TYPE
int		XFA_ExtractCertInfoNoExt			(OssGlobal *, const Certificate *, CertInfo *);

XFA_EXPORT_TYPE
int		XFA_DoExtractCertInfo				(OssGlobal *, const Certificate *,CertInfo *);

XFA_EXPORT_TYPE
int		XFA_ExtractCertInfo					(OssGlobal *, const char *, const char *, 
											 const int, const int, CertInfo *);

XFA_EXPORT_TYPE
int		XFA_ExtractCertInfoEx				(OssGlobal *, const char *, const char *, 
											 const int, const int, void *);

XFA_EXPORT_TYPE
int		XFA_ExtractCertExtension			(OssGlobal *, const Certificate *, CertInfo *);

// for compatibility with previous version {{

XFA_EXPORT_TYPE
int		XFA_GetCertPubKey					(BIN *, const BIN *);

XFA_EXPORT_TYPE
int		XFA_GetSubPubKeyInfo				(BIN *, int *, BIN *, const BIN *);

// }}

// name

XFA_EXPORT_TYPE
int		XFA_ExtractRDN						(OssGlobal *, const Name *, char **);

XFA_EXPORT_TYPE
int		XFA_ImplementRDN					(OssGlobal *, Name *, const char *);

XFA_EXPORT_TYPE
void	XFA_NameFree						(Name *);

// for compatibility with prev version {{

XFA_EXPORT_TYPE
int		XFA_GetRDNFromCert					(OssGlobal *, const Certificate *, char **);

XFA_EXPORT_TYPE
int		XFA_ExtractDN						(OssGlobal *, const BIN *, char **);

XFA_EXPORT_TYPE
int		XFA_GetIssuerRDNFromCert			(OssGlobal *, const Certificate *, char **);

// }}

// for compatibility with prev version {{

// extensions

XFA_EXPORT_TYPE
Extension * 
		XFA_GetExtension					(const Extensions , const ObjectID *);

// - authKeyId

XFA_EXPORT_TYPE
int		XFA_GetAuthorityKeyId				(OssGlobal *, const Extensions, char *);

// - subjectKeyId

XFA_EXPORT_TYPE
int		XFA_GetSubjectKeyId					(OssGlobal *, const Extensions , char *);

XFA_EXPORT_TYPE
int		XFA_GetSubjectKeyIDv				(OssGlobal *, const Certificate *, SubjectKeyIdentifier *);

XFA_EXPORT_TYPE
int		XFA_GetSubjectKeyID					(OssGlobal *, const BIN *, SubjectKeyIdentifier *);

XFA_EXPORT_TYPE
int		XFA_GetSubjectKeyIDBin				(OssGlobal *, const BIN *, BIN *);

XFA_EXPORT_TYPE
int		XFA_GenSubjectKeyID					(OssGlobal *, const BIN *, SubjectKeyIdentifier *);

// - keyUsage

XFA_EXPORT_TYPE
int		XFA_GetKeyUsage						(OssGlobal *, const Extensions , char *);

// - policy

XFA_EXPORT_TYPE
int		XFA_GetPolicy						(OssGlobal *, Extensions, int *, char *, char *, char *);

// - altName

XFA_EXPORT_TYPE
int		XFA_GetAltName						(OssGlobal *, Extensions, char *);

// - basicConst

XFA_EXPORT_TYPE
int		XFA_GetBC							(OssGlobal *, Extensions, char *);

// - extKeyUsage

XFA_EXPORT_TYPE
int		XFA_GetExtKeyUsage					(OssGlobal *, const Extensions, char *);

// - crlDPs

XFA_EXPORT_TYPE
int		XFA_GetDistributionPoints			(OssGlobal *, const Extensions, char *);

// - AIA

XFA_EXPORT_TYPE
int		XFA_GetAIA							(OssGlobal *, Extensions, char *);

// - netscapeCertType

XFA_EXPORT_TYPE
int		XFA_GetNetscapeCertType				(OssGlobal *, const Extensions , char *);

XFA_EXPORT_TYPE
int		XFA_GetVID							(char *realName, const int realLength, 
											 char *vidHex, const int vidLength, 
											 char *hashAlg, const int hashLength,
											 const Extensions pAsnExts);
// }}

// check

// for compatibility with previous version {{

XFA_EXPORT_TYPE
int		XFA_CheckSignature					(OssGlobal *, const Certificate *, const Certificate *);

XFA_EXPORT_TYPE
int		XFA_IsCertTimeValid					(const Certificate *);

XFA_EXPORT_TYPE
int		XFA_CertCheck						(OssGlobal *, const char *, const CertificateList *,
											 const Certificate *, const Certificate *, const unsigned short );

XFA_EXPORT_TYPE
int		XFA_CheckKeyUsage					(OssGlobal *, const Extension *, const KeyUsage );

XFA_EXPORT_TYPE
int		XFA_CheckExtKeyUsage				(OssGlobal *, const Extension *, const ObjectID *);

XFA_EXPORT_TYPE
int		XFA_CheckCaOrNot					(OssGlobal *, const Certificate *);

XFA_EXPORT_TYPE
int		XFA_CheckCertUsage					(OssGlobal *, const Certificate *, const int );

// }}

// check

XFA_EXPORT_TYPE
int		XFA_PKC_VerifySignature				(const Certificate *pAsnSubject,
											 const Certificate *pAsnIssuer);

XFA_EXPORT_TYPE
int		XFA_PKC_VerifyTime					(const Certificate *pAsnCert,
											 const time_t verifyTime);

XFA_EXPORT_TYPE
int 	XFA_PKC_GetSubPubKeyAlg			(int *pSignAlgID,
											 const BIN *pCert);

XFA_EXPORT_TYPE // 2009.12.14 Addedd by Hongma
int		XFA_PKC_GetSignAlg					(int *pSignAlgID,
											 const BIN *pCert);
XFA_EXPORT_TYPE // 2010.08.19 Addedd by Hongma
int		XFA_PKC_GetHashAlg					(int *pHashAlgID,
											 const BIN *pCert);

XFA_EXPORT_TYPE // 2010.3.16 Added by Hongma, VID 검증시 해쉬 알고리즘을 알 수 없기 때문에 요 함수 추가
int		XFA_PKC_GetVIDHashAlg				(int *pHashAlgID, 
											 const BIN *pCert);
// pubkey

XFA_EXPORT_TYPE
int		XFA_PKC_GetPubKeyInfo				(int *pkeyID,
											 BIN *pkeyParam,				// optional
											 BIN *pubKey,
											 const Certificate *pAsnCert);

// vid

XFA_EXPORT_TYPE
int		XFA_PKC_GetVIDInfo					(char *realName,
											 int *realLength,				// in/out
											 int *hashID,
											 BIN *vid,
											 const Certificate *pAsnCert);

XFA_EXPORT_TYPE
int		XFA_PKC_ComputeVID					(BIN *vid,
											 const int hashID,
											 const char idn[64],
											 const BIN *random);

XFA_EXPORT_TYPE
int		XFA_PKC_VerifyVID					(const BIN *vid,
											 const int hashID,
											 const char idn[64],
											 const BIN *random);

// gencert

typedef struct {
	// certPolicies
	char	*policyOid;				// optional
	char	*cpsUri;				// optional
	char	*userNotice;			// optional
	// subAltName
	char	*realName;				// optional
	BIN		*vid;					// optional
	// crlDPs
	char	*crlDPUri;				// optional
	// AIA
	char	*AIAUri;				// optional
} XE_PKC_GenCertExts;

typedef struct {
	// issuer
	int		issPkeyID;
	BIN		*issPkeyParam;			// optional
	BIN		*issPrivKey;
	int		(*CB_ComputeSignature)			(BIN *signature, const BIN *message, 
											 const int signID);			// optional
	// param
	int		isSelfSign;				// true (1), false (0)
	int		isCA;					// true (1) if CA, false (0) if EE.
} XE_PKC_GenCertParam;

XFA_EXPORT_TYPE
int		XFA_PKC_GenCertificate				(BIN *subCert,
											 const int serial,
											 const int signID,
											 const time_t startTime,
											 const time_t endTime,
											 const char *subDN,
											 const int subPkeyID,
											 const BIN *subPkeyParam,		// optional
											 const BIN *subPubKey,
											 const Certificate *pAsnIssCert,		// optional
											 const XE_PKC_GenCertExts *certExts,	// optional
											 const XE_PKC_GenCertParam *genParam);

// option

XFA_EXPORT_TYPE
int		XFA_PKC_SetOption					(const char *type,				// "locale", "dncase"
											 const char *value);

XFA_EXPORT_TYPE
char *	XFA_PKC_GetOption					(const char *type);				// "locale", "dncase"

// for compatibility with previous version {{

XFA_EXPORT_TYPE
void	XFA_SetLocalePKC					(const char *locale);

// }}

// version

XFA_EXPORT_TYPE
char *	XFA_PKC_GetVersion					(void);

XFA_EXPORT_TYPE
int		XFA_PKC_CheckVersion				(const char *version);			// optional

// error

XFA_EXPORT_TYPE
char *	XFA_PKC_GetErrorReason				(const int code,
											 const int locale);

// for compatibility with previous version {{

XFA_EXPORT_TYPE
char * XFA_GetVersionPKC					(void);

XFA_EXPORT_TYPE
char * XFA_GetErrReasonPKC					(const int , const int );

// }}


// for KT digital cinema (jhhong, 20070411)
XFA_EXPORT_TYPE
int XFA_PKC_GetCertThumbPrint(char *pThumbPrint, const int nAlgID, const BIN *pCert);

XFA_EXPORT_TYPE
int XFA_PKC_GetCertThumbPrintExcludeSig(char *pThumbPrint, const int nAlgID, const BIN *pCert);

#ifdef  __cplusplus
}
#endif

#endif
