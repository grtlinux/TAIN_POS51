//
//	suite_asn.h
//

#ifndef _SUITE_ASN_H_
#define _SUITE_ASN_H_

#if	!(defined(_WIN32_WCE) && (_WIN32_WCE < 400))
#include <time.h>
#endif

#include "exp_global.h"
#include "suite_pkix_asn1.h"

/**
 *	Constants
 */

enum BAGTYPE_LIST {
	BAGTYPE_KEYBAG = 0,
	BAGTYPE_PKCS8SHROUDEDKEYBAG,
	BAGTYPE_CERTBAG,
	BAGTYPE_CRLBAG,
	BAGTYPE_SECRETBAG,
	BAGTYPE_SAFECONTENTSBAG,
	BAGTYPE_X509CERTIFICATE,
	BAGTYPE_SDSICERTIFICATE,
	BAGTYPE_X509CRL
};

enum OID_LIST {
	OBJID_ID_PKIP = 0,
	OBJID_ID_REGCTRL,
	OBJID_ID_REGCTRL_REGTOKEN,
	OBJID_ID_REGCTRL_AUTHENTICATOR,
	OBJID_ID_REGCTRL_PKIPUBLICATIONINFO,
	OBJID_ID_REGCTRL_PKIARCHIVEOPTIONS,
	OBJID_ID_REGCTRL_OLDCERTID,
	OBJID_ID_REGCTRL_PROTOCOLENCRKEY,
	OBJID_ID_REGINFO,
	OBJID_ID_REGINFO_UTF8PAIRS,
	OBJID_ID_REGINFO_CERTREQ,
	OBJID_SHA_1 = 11,
	OBJID_MD5,
	OBJID_RSAENCRYPTION,
	OBJID_DH_PUBLIC_NUMBER,
	OBJID_ID_ALG_ESDH,
	OBJID_ID_ALG_CMS3DESWRAP,
	OBJID_ID_ALG_CMSRC2WRAP,
	OBJID_DES_ECB,
	OBJID_DES_CBC,
	OBJID_DES_OFB,
	OBJID_DES_CFB,
	OBJID_DES_EDE3_CBC,
	OBJID_RC2_CBC,
	OBJID_HMAC_SHA1,
	OBJID_ID_CT_CONTENTINFO,
	OBJID_ID_DATA,
	OBJID_ID_SIGNEDDATA,
	OBJID_ID_ENVELOPEDDATA,
	OBJID_ID_SIGNEDANDENVELOPEDDATA,
	OBJID_ID_DIGESTEDDATA,
	OBJID_ID_ENCRYPTEDDATA,
	OBJID_ID_CT_AUTHDATA,
	OBJID_ID_CONTENTTYPE,
	OBJID_ID_MESSAGEDIGEST,
	OBJID_ID_SIGNINGTIME,
	OBJID_ID_COUNTERSIGNATURE,
	OBJID_ID_PASSWORDBASEDMAC = 37,
	OBJID_ID_DHBASEDMAC,
	OBJID_ID_IT,
	OBJID_ID_CAPROTENCCERT,
	OBJID_ID_SIGNKEYPAIRTYPES,
	OBJID_ID_ENCKEYPAIRTYPES,
	OBJID_ID_PREFERREDSYMMALG,
	OBJID_ID_CAKEYUPDATEINFO,
	OBJID_ID_CURRENTCRL,
	OBJID_ID_AA_RECEIPTREQUEST = 46,
	OBJID_ID_AA_CONTENTIDENTIFIER,
	OBJID_ID_CT_RECEIPT,
	OBJID_ID_AA_CONTENTHINT,
	OBJID_ID_AA_MSGSIGDIGEST,
	OBJID_ID_AA_CONTENTREFERENCE,
	OBJID_ID_AA_SECURITYLABEL,
	OBJID_ID_AA_EQUIVALENTLABELS,
	OBJID_ID_AA_MLEXPANDHISTORY,
	OBJID_ID_AA_SIGNINGCERTIFICATE,
	OBJID_PKCS5V2_0_RSADSI = 56,
	OBJID_PKCS5V2_0_PKCS,
	OBJID_PKCS_5,
	OBJID_ID_PBKDF2,
	OBJID_PBEWITHMD2ANDDES_CBC,
	OBJID_PBEWITHMD2ANDRC2_CBC,
	OBJID_PBEWITHMD5ANDDES_CBC,
	OBJID_PBEWITHMD5ANDRC2_CBC,
	OBJID_PBEWITHSHA1ANDDES_CBC,
	OBJID_PBEWITHSHA1ANDRC2_CBC,
	OBJID_ID_PBES2,
	OBJID_ID_PBMAC1,
	OBJID_DIGESTALGORITHM,
	OBJID_ENCRYPTIONALGORITHM,
	OBJID_ID_HMACWITHSHA1,
	OBJID_DESCBC,
	OBJID_RC2CBC,
	OBJID_RC5_CBC_PAD,
	OBJID_ID_KP_OCSPSIGNING = 74,
	OBJID_ID_PKIX_OCSP,
	OBJID_ID_PKIX_OCSP_BASIC,
	OBJID_ID_PKIX_OCSP_NONCE,
	OBJID_ID_PKIX_OCSP_CRL,
	OBJID_ID_PKIX_OCSP_RESPONSE,
	OBJID_ID_PKIX_OCSP_NOCHECK,
	OBJID_ID_PKIX_OCSP_ARCHIVE_CUTOFF,
	OBJID_ID_PKIX_OCSP_SERVICE_LOCATOR,
	OBJID_PKCS_9 = 83,
	OBJID_PKCS_9_MO,
	OBJID_PKCS_9_OC,
	OBJID_PKCS_9_AT,
	OBJID_PKCS_9_SX,
	OBJID_PKCS_9_MR,
	OBJID_PKCS_9_OC_PKCSENTITY,
	OBJID_PKCS_9_OC_NATURALPERSON,
	OBJID_PKCS_9_AT_EMAILADDRESS,
	OBJID_EMAILADDRESS,
	OBJID_PKCS_9_AT_UNSTRUCTUREDNAME,
	OBJID_PKCS_9_AT_CONTENTTYPE,
	OBJID_PKCS_9_AT_MESSAGEDIGEST,
	OBJID_PKCS_9_AT_SIGNINGTIME,
	OBJID_PKCS_9_AT_COUNTERSIGNATURE,
	OBJID_PKCS_9_AT_CHALLENGEPASSWORD,
	OBJID_PKCS_9_AT_UNSTRUCTUREDADDRESS,
	OBJID_PKCS_9_AT_EXTENDEDCERTIFICATEATTRIBUTES,
	OBJID_PKCS_9_AT_SIGNINGDESCRIPTION,
	OBJID_PKCS_9_AT_EXTENSIONREQUEST,
	OBJID_PKCS_9_AT_SMIMECAPABILITIES,
	OBJID_PKCS_9_AT_FRIENDLYNAME,
	OBJID_PKCS_9_AT_LOCALKEYID,
	OBJID_PKCS_9_AT_USERPKCS12,
	OBJID_PKCS_9_AT_PKCS15TOKEN,
	OBJID_PKCS_9_AT_ENCRYPTEDPRIVATEKEYINFO,
	OBJID_PKCS_9_AT_RANDOMNONCE,
	OBJID_PKCS_9_AT_SEQUENCENUMBER,
	OBJID_PKCS_9_AT_PKCS7PDU,
	OBJID_IETF_AT,
	OBJID_PKCS_9_AT_DATEOFBIRTH,
	OBJID_PKCS_9_AT_PLACEOFBIRTH,
	OBJID_PKCS_9_AT_GENDER,
	OBJID_PKCS_9_AT_COUNTRYOFCITIZENSHIP,
	OBJID_PKCS_9_AT_COUNTRYOFRESIDENCE,
	OBJID_PKCS_9_SX_PKCS9STRING,
	OBJID_PKCS_9_SX_SIGNINGTIME,
	OBJID_PKCS_9_MR_CASEIGNOREMATCH,
	OBJID_PKCS_9_MR_SIGNINGTIMEMATCH,
	OBJID_SMIME,
	OBJID_CERTTYPES,
	OBJID_CRLTYPES,
	OBJID_ID_CE = 125,
	OBJID_ID_CE_AUTHORITYKEYIDENTIFIER,
	OBJID_ID_CE_SUBJECTKEYIDENTIFIER,
	OBJID_ID_CE_KEYUSAGE,
	OBJID_ID_CE_PRIVATEKEYUSAGEPERIOD,
	OBJID_ID_CE_CERTIFICATEPOLICIES,
	OBJID_ID_CE_POLICYMAPPINGS,
	OBJID_ID_CE_SUBJECTALTNAME,
	OBJID_ID_CE_ISSUERALTNAME,
	OBJID_ID_CE_SUBJECTDIRECTORYATTRIBUTES,
	OBJID_ID_CE_BASICCONSTRAINTS,
	OBJID_ID_CE_NAMECONSTRAINTS,
	OBJID_ID_CE_POLICYCONSTRAINTS,
	OBJID_ID_CE_CRLDISTRIBUTIONPOINTS,
	OBJID_ID_CE_EXTKEYUSAGE,
	OBJID_ID_KP_SERVERAUTH,
	OBJID_ID_KP_CLIENTAUTH,
	OBJID_ID_KP_CODESIGNING,
	OBJID_ID_KP_EMAILPROTECTION,
	OBJID_ID_KP_IPSECENDSYSTEM,
	OBJID_ID_KP_IPSECTUNNEL,
	OBJID_ID_KP_IPSECUSER,
	OBJID_ID_KP_TIMESTAMPING,
	OBJID_ID_PE_AUTHORITYINFOACCESS,
	OBJID_ID_CE_CRLNUMBER,
	OBJID_ID_CE_ISSUINGDISTRIBUTIONPOINT,
	OBJID_ID_CE_DELTACRLINDICATOR,
	OBJID_ID_CE_CRLREASONS,
	OBJID_ID_CE_CERTIFICATEISSUER,
	OBJID_ID_CE_HOLDINSTRUCTIONCODE,
	OBJID_HOLDINSTRUCTION,
	OBJID_ID_HOLDINSTRUCTION_NONE,
	OBJID_ID_HOLDINSTRUCTION_CALLISSUER,
	OBJID_ID_HOLDINSTRUCTION_REJECT,
	OBJID_ID_CE_INVALIDITYDATE,
	OBJID_NETSCAPE,
	OBJID_NETSCAPE_CERT_EXTENSION,
	OBJID_NETSCAPE_CERT_TYPE,
	OBJID_NETSCAPE_BASE_URL,
	OBJID_NETSCAPE_REVOCATION_URL,
	OBJID_NETSCAPE_CA_REVOCATION_URL,
	OBJID_NETSCAPE_CERT_RENEWAL_URL,
	OBJID_NETSCAPE_CA_POLICY_URL,
	OBJID_NETSCAPE_SSL_SERVER_NAME,
	OBJID_NETSCAPE_COMMENT,
	OBJID_ID_PKIX = 170,
	OBJID_ID_PE,
	OBJID_ID_QT,
	OBJID_ID_KP,
	OBJID_ID_AD,
	OBJID_ID_QT_CPS,
	OBJID_ID_QT_UNOTICE,
	OBJID_ID_AD_OCSP,
	OBJID_ID_AD_CAISSUERS,
	OBJID_ID_AT,
	ATTRIB_ID_AT_NAME,
	ATTRIB_ID_AT_SURNAME,
	ATTRIB_ID_AT_GIVENNAME,
	ATTRIB_ID_AT_INITIALS,
	ATTRIB_ID_AT_GENERATIONQUALIFIER,
	ATTRIB_ID_AT_COMMONNAME,
	ATTRIB_ID_AT_LOCALITYNAME,
	ATTRIB_ID_AT_STATEORPROVINCENAME,
	ATTRIB_ID_AT_ORGANIZATIONNAME,
	ATTRIB_ID_AT_ORGANIZATIONALUNITNAME,
	ATTRIB_ID_AT_TITLE,
	ATTRIB_ID_AT_DNQUALIFIER,
	ATTRIB_ID_AT_COUNTRYNAME,
	OBJID_PKCS_1,
	OBJID_MD2,
	OBJID_MD2WITHRSAENCRYPTION,
	OBJID_MD5WITHRSAENCRYPTION,
	OBJID_SHA1WITHRSAENCRYPTION,
	OBJID_ID_DSA_WITH_SHA1,
	OBJID_DHPUBLICNUMBER,
	OBJID_ID_DSA,
	OBJID_ID_CT_TSTINFO = 201,
	OBJID_ID_DH_SIG_HMAC_SHA1 = 202,
	OBJID_ID_ALG_DH_POP,
	OBJID_ID_PE_AC_AUDITIDENTITY = 204,
	OBJID_ID_PE_AACONTROLS,
	OBJID_ID_PE_AC_PROXYING,
	OBJID_ID_CE_TARGETINFORMATION,
	OBJID_ID_ACA,
	OBJID_ID_ACA_AUTHENTICATIONINFO,
	OBJID_ID_ACA_ACCESSIDENTITY,
	OBJID_ID_ACA_CHARGINGIDENTITY,
	OBJID_ID_ACA_GROUP,
	OBJID_ID_ACA_ENCATTRS,
	OBJID_ID_AT_ROLE,
	OBJID_ID_AT_CLEARANCE,
	OBJID_PKCS_12_RSADSI = 216,
	OBJID_PKCS_12_PKCS,
	OBJID_PKCS_12,
	OBJID_PKCS_12PBEIDS,
	OBJID_PBEWITHSHAAND128BITRC4,
	OBJID_PBEWITHSHAAND40BITRC4,
	OBJID_PBEWITHSHAAND3_KEYTRIPLEDES_CBC,
	OBJID_PBEWITHSHAAND2_KEYTRIPLEDES_CBC,
	OBJID_PBEWITHSHAAND128BITRC2_CBC,
	OBJID_PBEWITHSHAAND40BITRC2_CBC,
	OBJID_BAGTYPES,
	OBJID_ID_AD_DVCS = 227,
	OBJID_ID_KP_DVCS,
	OBJID_ID_CT_DVCSREQUESTDATA,
	OBJID_ID_CT_DVCSRESPONSEDATA,
	OBJID_ID_AA_DVCS_DVC,
	OBJID_ID_KOREA = 232,
	OBJID_ID_SOFTFORUM,
	OBJID_ID_MISO_PKIX,
	OBJID_ID_MISO_ALGORITHM,
	OBJID_ID_MISO_USAGE,
	OBJID_ID_MISO_POLICY,
	OBJID_ID_MISO_TSA_POL,
	OBJID_ID_MISO_CA_POL,
	OBJID_ID_KISA,
	OBJID_ID_KISA_NPKI_ALG,
	OBJID_ID_KISA_NPKI_CP,
	OBJID_ID_KISA_NPKI_KP,
	OBJID_ID_KISA_NPKI_AT,
	OBJID_ID_KISA_NPKI_LCA,
	//2011-07-cristyanne {{
	OBJID_ID_GCMA,
	OBJID_ID_GCMA_GPKI_ALG,
	OBJID_NEAT,
	OBJID_NEATECB,
	OBJID_NEATCBC,
	OBJID_NEATOFB,
	OBJID_NEATCFB,
	OBJID_NEATMAC,
	OBJID_PBEWITHSHA1ANDNEAT_CBC,
	OBJID_PBEWITHHAS160ANDNEAT_CBC,
	OBJID_ARIA,
	OBJID_ARIAECB,
	OBJID_ARIACBC,
	OBJID_ARIAOFB,
	OBJID_ARIACFB,
	OBJID_ARIAMAC,
	OBJID_PBEWITHSHA1ANDARIA_CBC,
	OBJID_PBEWITHSHA256ANDARIA_CBC,
	OBJID_PBEWITHHAS160ANDARIA_CBC,
	//}}
	OBJID_ID_KISA_NPKI_ON,
	OBJID_KCDSA,
	OBJID_HASH160,
	OBJID_SEEDECB,
	OBJID_SEEDCBC,
	OBJID_SEEDOFB,
	OBJID_SEEDCFB,
	OBJID_SEEDMAC,
	OBJID_KCDSAWITHHAS160,
	OBJID_KCDSAWITHSHA1,
	// 2011.07.01 by cristyanne : Add OID for KCDSA using particular hash alg. that SHA256,384,512
	OBJID_KCDSAWITHSHA256,
	OBJID_KCDSAWITHSHA384,
	OBJID_KCDSAWITHSHA512,
	OBJID_SEEDCBCWITHHAS160,
	OBJID_SEEDCBCWITHSHA1,
	OBJID_RSAWITHHAS160,
	OBJID_NPKI_CP_SIGN,
	OBJID_SIGNKOREA,
	OBJID_SIGNKOREA_CP,
	OBJID_SIGNGATE,
	OBJID_SIGNGATE_CP,
	OBJID_ID_KFTC,
	OBJID_YESSIGNCA,
	OBJID_YESSIGN_CP,
	OBJID_PERSONAL_CERTIFICATES,
	OBJID_CORPORATION_CERTIFICATES,
	OBJID_SERVER_CERTIFICATES,
	OBJID_NSFORUM,
	OBJID_SEEDECBWITHHAS160,
	OBJID_SEEDOFBWITHHAS160,
	OBJID_SEEDCFBWITHHAS160,
	OBJID_SEEDECBWITHSHA1,
	OBJID_SEEDOFBWITHSHA1,
	OBJID_SEEDCFBWITHSHA1,
	OBJID_KCDSA1,
	OBJID_KCDSA1WITHHAS160,
	OBJID_KCDSA1WITHSHA1,
	//2011/07/01 by cristyanne : Add OID for KCDSA1 using particular hash alg. that SHA256,384,512
	OBJID_KCDSA1WITHSHA256,
	OBJID_KCDSA1WITHSHA384,
	OBJID_KCDSA1WITHSHA512,
	OBJID_ECDSAWITHHAS160,
	OBJID_ECC,
	OBJID_ID_REGISTEREDNUMBER,
	OBJID_ID_REPRESENTATIVENAME,
	OBJID_ID_REPRESENTATIVETITLE,
	OBJID_ELECTRONIC_CIVIL_APPLICATION = 330,
	OBJID_PKICTL,
	OBJID_CERTIFICATETRUSTLIST,
	OBJID_CTL,
	OBJID_ID_NPKI = 340,
	OBJID_ID_ATTRIBUTE,
	OBJID_ID_KISA_IDENTIFYDATA,
	OBJID_ID_VID,
	OBJID_ID_ENCRYPTEDVID,
	OBJID_ID_RANDOMNUM,
	OBJID_ID_AA_TIMESTAMPTOKEN = 350,
	//2007/01/27 by ssosuny : HASH, PKCS#1 OID 추가
	OBJID_SHA_256,
	OBJID_SHA_384,
	OBJID_SHA_512,
	OBJID_SHA256WITHRSAENCRYPTION,
	OBJID_SHA384WITHRSAENCRYPTION,
	OBJID_SHA512WITHRSAENCRYPTION,
	OBJID_RSAES_OAEP,
	OBJID_MGF1,
	OBJID_PSPECIFIED,
	OBJID_RSASSA_PSS,
	//2011-07-25 by cristyanne : add KIEC For DVCS
	OBJID_KIEC_ARCCERTREQUEST,
	OBJID_KIEC_HASHEDIDNINFO,
	OBJID_KIEC_QUALIFICATIONS,
	OBJID_KIEC_USAGETYPE,
	OBJID_KIEC_DATEOFEXPIRATION,
	OBJID_KIEC_CERTIFIEDTIME,
	OBJID_KIEC_ARCCERTRESPONSE,
	OBJID_ARC_RECORD,				
	OBJID_ARC_ARCCERT,			
	OBJID_ARC_REGISTER_POL,
	OBJID_ARC_ISSUE_POL,		
	OBJID_ARC_TRANSFER_POL,	
	OBJID_ARC_DELETE_POL,		
	OBJID_ARC_ORIGINAL_POL	
};


// for compatibility with prev version {{
// NOTE: following ids are taken from csp. do not change value 
//		 of algorithm id for suppoting lower asn version.
//
#define HASHALGID_MD2						0
#define HASHALGID_MD5						1
#define HASHALGID_SHA_1 					2
#define HASHALGID_HAS160					5
// 2007/01/24 by ssosuny : HASH OID 추가
#define HASHALGID_SHA_256					7
#define HASHALGID_SHA_384					8
#define HASHALGID_SHA_512					9

//
#define ENCALGID_DES						0
#define ENCALGID_3DES						1
#define ENCALGID_RC2						2
#define ENCALGID_RC5						4
#define ENCALGID_RSA						7
#define ENCALGID_KCDSA						9
#define ENCALGID_SEED						10
// 2007/01/25 by ssosuny : RSA-OAEP 추가
#define ENCALGID_RSAES_OAEP					11

//
#define SIGNALGID_MD2WithRSA				0
#define SIGNALGID_MD5WithRSA				1
#define SIGNALGID_SHA1WithRSA				2
#define SIGNALGID_SHA1WithDSA				3

//2007/01/23 by ssosuny PKCS#1 OID 추가, RSASSA-PSS 추가
#define SIGNALGID_SHA256WithRSA				4
#define SIGNALGID_SHA384WithRSA				5
#define SIGNALGID_SHA512WithRSA				6
#define SIGNALGID_RSASSA_PSS				7
// }}

/**
 *	Struct
 */

//#if	(defined(_WIN32_WCE) && (_WIN32_WCE < 400))
//
//#define time_t		long
//
//struct tm {
//	WORD	tm_year;
//	WORD	tm_mon;
//	WORD	tm_mday;
//	WORD	tm_hour;
//	WORD	tm_min;
//	WORD	tm_sec;
//};
//
//#endif

/**
 *	Error codes
 */

#define ASN_ERR_INVALID_INPUT				(ERR_ASN + 1)
#define ASN_ERR_INTERNAL					(ERR_ASN + 2)
#define ASN_ERR_MALLOC_FAILED				(ERR_ASN + 3)

#define ASN_ERR_OSS_FUNCTION				(ERR_ASN + 20)
#define ASN_ERR_OSS_ENCODE					(ERR_ASN + 21)
#define ASN_ERR_OSS_DECODE					(ERR_ASN + 22)
#define ASN_ERR_OSS_COPY					(ERR_ASN + 23)
#define ASN_ERR_OSS_FREE					(ERR_ASN + 24)

#define	ASN_ERR_MUTEX_FUNCTION				(ERR_ASN + 30)

/**
 *	Prototypes
 */

#ifdef __cplusplus
extern "C" {
#endif

// ctx

XFA_EXPORT_TYPE
int		XFA_ASN_Initialize					(void);

XFA_EXPORT_TYPE
int		XFA_ASN_Finalize					(void);

XFA_EXPORT_TYPE
int		XFA_ASN_SetFlags					(unsigned long ossflags);

// pdu

XFA_EXPORT_TYPE
int		XFA_ASN_EncodePDU					(BIN *output,
											 const void *pduStruct,
											 const int pduNum);

XFA_EXPORT_TYPE
int		XFA_ASN_DecodePDU					(void **pduStruct,
											 const BIN *input,
											 const int pduNum);

XFA_EXPORT_TYPE
int		XFA_ASN_CmpPDU						(const void *pduStruct1,
											 const void *pduStruct2,
											 const int pduNum);

XFA_EXPORT_TYPE
int		XFA_ASN_CopyPDU						(void **tgtStruct,
											 const void *srcStruct,
											 const int pduNum);

XFA_EXPORT_TYPE
int		XFA_ASN_FreePDU						(void *pduStruct,
											 const int pduNum);

// oid

XFA_EXPORT_TYPE
ObjectID * 
		XFA_ASN_GetOID						(const int oidID);

XFA_EXPORT_TYPE
int		XFA_ASN_CmpOID						(const ObjectID *oid1, 
											 const ObjectID *oid2);

XFA_EXPORT_TYPE
int		XFA_ASN_CopyOID						(ObjectID *tgtOid, 
											 const ObjectID *srcOid);

XFA_EXPORT_TYPE
void	XFA_ASN_ResetOID					(ObjectID *oid);

XFA_EXPORT_TYPE
int		XFA_ASN_DotVal2OID					(ObjectID *oid,
											 const char *dotVal);

XFA_EXPORT_TYPE
int		XFA_ASN_OID2DotVal					(char **dotVal,
											 const ObjectID *oid);

XFA_EXPORT_TYPE
BAG_TYPE *
		XFA_ASN_GetBagType					(const int bagTypeID);

// alg

// time

XFA_EXPORT_TYPE
time_t	XFA_ASN_UTC2Time					(const UTCTime *utc);

XFA_EXPORT_TYPE
void	XFA_ASN_Time2UTC					(UTCTime *utc,
											 const time_t time);

XFA_EXPORT_TYPE
time_t	XFA_ASN_General2Time				(const GeneralizedTime *gen);

XFA_EXPORT_TYPE
void	XFA_ASN_Time2General				(GeneralizedTime *gen,
											 const time_t time);

XFA_EXPORT_TYPE 
int		XFA_ASN_ReleaseCTX					(OssGlobal *ctx);


#if	(defined(_WIN32_WCE) && (_WIN32_WCE < 400))

XFA_EXPORT_TYPE	struct tm *gmtime			(const time_t *clock);

XFA_EXPORT_TYPE	time_t	mktime				(const struct tm *timeptr);

XFA_EXPORT_TYPE	long	time				(long *tloc);

XFA_EXPORT_TYPE	struct tm *localtime		(const time_t *timer);

#endif

// version

XFA_EXPORT_TYPE
char *	XFA_ASN_GetVersion					(void);

XFA_EXPORT_TYPE
int		XFA_ASN_CheckVersion				(const char *version);			// optional

// error

XFA_EXPORT_TYPE
char *	XFA_ASN_GetErrorReason				(const int code, 
											 const int locale);

// for compatibility with prev version {{
XFA_EXPORT_TYPE int 	XFA_OssInit 		(OssGlobal *);
XFA_EXPORT_TYPE	int 	XFA_OssFinal		(OssGlobal *);
XFA_EXPORT_TYPE	int 	XFA_OssDupCtx		(const OssGlobal *, OssGlobal *);

XFA_EXPORT_TYPE int 	XFA_GetEncodedPDU	(OssGlobal *, const int, const void *, BIN *);
XFA_EXPORT_TYPE int 	XFA_GetDecodedPDU	(OssGlobal *, const int, const BIN *, void **);
XFA_EXPORT_TYPE int 	XFA_ComparePDU		(OssGlobal *, const int, const void *, const void *);
XFA_EXPORT_TYPE int 	XFA_CopyPDU 		(OssGlobal *, const int, const void *, void **);
XFA_EXPORT_TYPE void	XFA_FreePDU 		(OssGlobal *, const int, void *);

XFA_EXPORT_TYPE int 	XFA_DotValToEncodedOID(OssGlobal *, const char *, OssEncodedOID *);
XFA_EXPORT_TYPE int 	XFA_EncodedOIDToDotVal(OssGlobal *, const OssEncodedOID *, BIN *);
XFA_EXPORT_TYPE ObjectID *	XFA_GetObjectID (const int);
XFA_EXPORT_TYPE int 	XFA_CompareOID		(const ObjectID *, const ObjectID *);
XFA_EXPORT_TYPE int		XFA_DupOID			(ObjectID *, const ObjectID *);
XFA_EXPORT_TYPE void	XFA_OidFree 		(ObjectID *);
XFA_EXPORT_TYPE BAG_TYPE *	XFA_GetBagType	(const int);

XFA_EXPORT_TYPE int 	XFA_GetDigestAlg	(OssGlobal *, const ObjectID *);
XFA_EXPORT_TYPE int 	XFA_GetEncAlg		(OssGlobal *, const ObjectID *);
XFA_EXPORT_TYPE int 	XFA_GetSigAlg		(OssGlobal *, const ObjectID *);

XFA_EXPORT_TYPE int 	XFA_UTC2String		(const UTCTime *, const UTCTime *, char **, char **);
XFA_EXPORT_TYPE time_t	XFA_UTC2Time		(const UTCTime *);
XFA_EXPORT_TYPE void	XFA_Time2UTC		(const time_t, UTCTime *);
XFA_EXPORT_TYPE time_t	XFA_General2Time	(const UTCTime *);
XFA_EXPORT_TYPE void	XFA_Time2General	(const time_t , UTCTime *);

XFA_EXPORT_TYPE void	XFA_OssFreeBuf		(OssGlobal *ossCtx, char *buf);
XFA_EXPORT_TYPE	char *	XFA_GetVersionASN	(void);
XFA_EXPORT_TYPE char *	XFA_GetErrReasonASN (const int code, const int locale);
// }}

#ifdef __cplusplus
}
#endif

#endif

