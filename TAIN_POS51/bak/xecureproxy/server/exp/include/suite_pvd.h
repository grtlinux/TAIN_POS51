//
//	$Id: suite_pvd.h,v 1.14 2008-04-10 01:26:23 ssosuny Exp $
//

#ifndef _SUITE_PVD_H_
#define _SUITE_PVD_H_

#include "suite_io.h"

/**
 *	Constants
 */

// type

#define XE_PVD_TYPEID_USER_CERT				1
#define XE_PVD_TYPEID_CA_CERT				3
#define XE_PVD_TYPEID_ROOT_CERT				5
#define XE_PVD_TYPEID_CRL					11
#define XE_PVD_TYPEID_ARL					12
#define XE_PVD_TYPEID_DELTA_CRL				13
#define XE_PVD_TYPEID_CTL					21
#define	XE_PVD_TYPEID_OCSP					25

/**
 *	Struct
 */

// object

typedef struct {
	int		typeID;
	BIN		encObj;					// der
	void	*pAsnObj;				// optional
} XE_PVD_Object;

typedef struct _XE_PVD_ObjectList {
	XE_PVD_Object value;
	struct _XE_PVD_ObjectList *next;
} XE_PVD_ObjectList;

// certpath

typedef struct {
	XE_PVD_ObjectList *certPath;	// (ex: user_cert, ca_cert, root_cert, ctl)
	time_t	vrfyTime;
	XE_PVD_ObjectList *revInfos;	// optional, (ex: crl, arl, delta_crl, ocsp)
} XE_PVD_CertPathResult;

typedef struct {
	XE_PVD_Object tgtCert;
	time_t	vrfyTime;				// optional
	XE_PVD_ObjectList *trustCerts;	// optional, (ex: root_cert)
	XE_PVD_ObjectList *otherCerts;	// optional, (ex: ca_cert, ctl)
	XE_PVD_ObjectList *otherCRLs;	// optional, (ex: crl, arl, delta_crl, ocsp)
	char	*initPolicies;			// optional, (ex: "1.2.34567.8.9,1.2.34567.1.2")
	int		initPolicyMappingInhibit;	// optional
	int		initExplicitPolicy;		// optional, 0 if explicit-policy-indicator is set
	int		initAnyPolicyInhibit;	// optional
} XE_PVD_CertPathRequest;

// certstore

typedef struct {
	int		sessionID;
	int		storeID;
	char	*storePath;
	char	*trustPath;				// optional, (ROOT/CA (ENABLE_CLIENT)
	void	*extrnCtx;				// optional
} XE_PVD_CertStore;

// callback

typedef struct {
	int		status;					// good (0), revoked (1), unknown (2)
	time_t	thisUpdate;
	time_t	nextUpdate;
	BIN		response;
} XE_PVD_OCSPResult;

typedef struct {
	// store
	int		(*CB_Store_Start)				(XE_PVD_CertStore *sctx);

	int		(*CB_Store_GetObject)			(XE_PVD_CertStore *sctx,
											 XE_BIN_LIST *encObjs,
											 const int typeID,
											 const char *objDN,
											 const void *param);

	int		(*CB_Store_GetTrustObject)		(XE_PVD_CertStore *sctx, 
											 BIN *encObjs, 
											 const int typeID, 
											 const char *objDN,
											 const char *subjectKeyID,	//optional
											 const unsigned int serialNumber);		//optional

	int		(*CB_Store_AddObject)			(XE_PVD_CertStore *sctx,
											 const int typeID,
											 const char *objDN,
											 const BIN *encObj,
											 const void *param);

	int		(*CB_Store_End)					(XE_PVD_CertStore *sctx);

	// ldap
	int		(*CB_LDAP_GetObject)			(XE_BIN_LIST *encObjs,
											 const int typeID,
											 const char *ldapURI);
	
	// ocsp
	int		(*CB_OCSP_CheckCert)			(XE_PVD_OCSPResult *ocspRes,
											 const BIN *encCert, 
											 const char *ocspURL);

	// log
	int		(*CB_Log_PrintText)				(const char *text, 
											 const int length);
} XE_PVD_VerifyCB;

// params

#define	XE_PVD_FLAG_DISABLE_SIGN_CHECK		0x0001
#define	XE_PVD_FLAG_DISABLE_TIME_CHECK		0x0002
#define XE_PVD_FLAG_DISABLE_CRL_CHECK		0x0004
#define XE_PVD_FLAG_DISABLE_OCSP_CHECK		0x0008
#define XE_PVD_FLAG_DISABLE_X509_CHECK		0x0010
#define XE_PVD_FLAG_DISABLE_X509_POLICY_CHECK	0x0020
#define XE_PVD_FLAG_DISABLE_ARL_CHECK		0x0040
#define XE_PVD_FLAG_ENABLE_RFC2459_CHECK		0x1000
#define XE_PVD_FLAG_ENABLE_SF_DEFINED_CHECK		0x8000
#define XE_PVD_FLAG_ENABLE_GPKI_DEFINED_CHECK	0x0100
// jhhong added 2007.03.02 for Digital Cinema
#define XE_PVD_FLAG_ENABLE_DC_DEFINED_CHECK		0x4000

typedef struct {
	char	*srvrURL;		// (ex: "ldap://123.4.5.6:78/")
	char	*certDN;		// optional, (ex: "cn=abc,ou=def,c=kr")
	char	*crlDN;			// optional, (ex: "cn=abc,ou=def,c=kr")
	char	*ctlDN;			// optional, (ex: "cn=abc,ou=def,c=kr")
} XE_PVD_LDAPInfo;

typedef struct {
	int		flags;

	// build
	struct {
		int		disable;			// true (1), false (0)
	} cache;
	struct {
		int		disable;			// true (1), false (0)
		char	*storePath;			// optional, (ex: "..\\CertStore" or "../CertStore")
		char	*trustPath;			// Root, CA certStore, (ex: "/NPKI")
		int		distrustRoot;		// true (1), false (0)
	} store;
	struct {
		int		disable;			// true (1), false (0)
		int		ldapInfon;			// 0 ~ 8
		XE_PVD_LDAPInfo	ldapInfos[8];	// optional
	} ldap;

	// ocsp
//	struct {
//		int		ocspURLn;			// 0 ~ 4
//		char	*ocspURLs[4];		// optional, (ex: "http://123.4.5.6:78/")
//	} ocsp;

	// log
	struct {
		int		level;
	} log;

	// callback
	XE_PVD_VerifyCB	vrfyCB;
} XE_PVD_VerifyParam;

/**
 *	Error codes
 */

#ifndef ERR_PVD
#define	ERR_PVD								43000
#endif

#define PVD_ERR_INVALID_INPUT				(ERR_PVD + 1)
#define PVD_ERR_INTERNAL					(ERR_PVD + 2)
#define PVD_ERR_MALLOC_FAILED				(ERR_PVD + 3)

// cert
#define	PVD_ERR_CERT_INVALID				(ERR_PVD + 30)
#define	PVD_ERR_CERT_DN_INVALID				(ERR_PVD + 31)
#define	PVD_ERR_CERT_SIGN_INVALID			(ERR_PVD + 32)
#define	PVD_ERR_CERT_NOT_YET_VALID			(ERR_PVD + 33)
#define PVD_ERR_CERT_EXPIRED				(ERR_PVD + 34)
#define PVD_ERR_CERT_REVOKED				(ERR_PVD + 35)
#define PVD_ERR_CERT_NOT_FOUND				(ERR_PVD + 36)
#define PVD_ERR_CERT_SELF_SIGNED			(ERR_PVD + 37)

#define	PVD_ERR_CERT_EXT_INVALID			(ERR_PVD + 40)
#define	PVD_ERR_CERT_EXT_NOT_EXIST			(ERR_PVD + 41)
#define	PVD_ERR_CERT_NAME_MISMATCH			(ERR_PVD + 43)
#define	PVD_ERR_CERT_KEYID_MISMATCH			(ERR_PVD + 44)
#define	PVD_ERR_CERT_KEYUSAGE_INVALID		(ERR_PVD + 45)
#define	PVD_ERR_CERT_POLICY_INVALID			(ERR_PVD + 46)
#define	PVD_ERR_CERT_POLICY_EXCEED			(ERR_PVD + 47)
#define PVD_ERR_CERT_BASICCONSTS_INVALID	(ERR_PVD + 48)
#define PVD_ERR_CERT_CRLDP_INVALID			(ERR_PVD + 49)
#define PVD_ERR_CERT_AIA_INVALID			(ERR_PVD + 50)
#define PVD_ERR_CERT_NAMECONSTS_INVALID		(ERR_PVD + 52)
#define PVD_ERR_CERT_POLICYMAPPING_INVALID	(ERR_PVD + 53)
// jhhong Added 2007.03.02 for Digital Cinema
#define PVD_ERR_CERT_USERCERT_COMMONNAME_ROLE_INVALID	(ERR_PVD + 54)
#define PVD_ERR_CERT_CACERT_COMMONNAME_ROLE_INVALID		(ERR_PVD + 55)
#define PVD_ERR_CERT_DNQUAIFIER_INVALID		(ERR_PVD + 56)
#define PVD_ERR_CERT_DC_SIGNID_INVALID		(ERR_PVD + 57)

// root
#define	PVD_ERR_ROOT_SIGN_INVALID			(ERR_PVD + 60)
#define	PVD_ERR_ROOT_NOT_YET_VALID			(ERR_PVD + 61)
#define	PVD_ERR_ROOT_EXPIRED				(ERR_PVD + 62)
#define	PVD_ERR_ROOT_NOT_TRUSTED			(ERR_PVD + 63)

// trust

// ctl
#define	PVD_ERR_CTL_INVALID					(ERR_PVD + 70)
#define	PVD_ERR_CTL_SIGN_INVALID			(ERR_PVD + 71)
#define	PVD_ERR_CTL_NOT_YET_VALID			(ERR_PVD + 72)
#define	PVD_ERR_CTL_EXPIRED					(ERR_PVD + 73)
#define	PVD_ERR_CTL_NOT_FOUND				(ERR_PVD + 74)

// path
#define	PVD_ERR_PATH_NOT_FOUND				(ERR_PVD + 80)
#define	PVD_ERR_PATH_INVALID				(ERR_PVD + 81)
#define	PVD_ERR_PATH_LENGTH_EXCEED			(ERR_PVD + 85)

// crl
#define	PVD_ERR_CRL_INVALID					(ERR_PVD + 90)
#define	PVD_ERR_CRL_DN_INVALID				(ERR_PVD + 91)
#define	PVD_ERR_CRL_SIGN_INVALID			(ERR_PVD + 92)
#define PVD_ERR_CRL_EXPIRED					(ERR_PVD + 93)
#define	PVD_ERR_CRL_NOT_AVAIL				(ERR_PVD + 94)
#define	PVD_ERR_CRL_NOT_FOUND				(ERR_PVD + 95)

#define	PVD_ERR_CRL_EXT_INVALID				(ERR_PVD + 100)
#define	PVD_ERR_CRL_EXT_NOT_EXIST			(ERR_PVD + 101)
#define	PVD_ERR_CRL_ISSUERNAME_MISMATCH		(ERR_PVD + 102)
#define	PVD_ERR_CRL_KEYID_MISMATCH			(ERR_PVD + 103)
#define	PVD_ERR_CRL_ISSDPNAME_MISMATCH		(ERR_PVD + 104)

// store
#define	PVD_ERR_STORE_ERROR					(ERR_PVD + 140)
#define	PVD_ERR_STORE_NOT_FOUND				(ERR_PVD + 141)

// ldap
#define	PVD_ERR_LDAP_ERROR					(ERR_PVD + 160)

// ocsp
#define	PVD_ERR_OCSP_ERROR					(ERR_PVD + 180)

/**
 *	Prototypes
 */

#ifdef  __cplusplus
extern "C" {
#endif

XFA_EXPORT_TYPE 
int		XFA_PVD_Initialize					(void);

XFA_EXPORT_TYPE 
int		XFA_PVD_Finalize					(void);

// object

XFA_EXPORT_TYPE 
XE_PVD_Object *
		XFA_PVD_Object_New					(void);

XFA_EXPORT_TYPE 
void	XFA_PVD_Object_Reset				(XE_PVD_Object *obj);

XFA_EXPORT_TYPE 
void	XFA_PVD_Object_Free					(XE_PVD_Object *obj);

XFA_EXPORT_TYPE 
XE_PVD_ObjectList *
		XFA_PVD_ObjectList_New				(void);

XFA_EXPORT_TYPE 
void	XFA_PVD_ObjectList_Reset			(XE_PVD_ObjectList *objList);

XFA_EXPORT_TYPE 
void	XFA_PVD_ObjectList_Free				(XE_PVD_ObjectList *objList);

// verify

XFA_EXPORT_TYPE 
XE_PVD_CertPathResult *
		XFA_PVD_CertPathResult_New			(void);

XFA_EXPORT_TYPE 
void	XFA_PVD_CertPathResult_Reset		(XE_PVD_CertPathResult *certPathRes);

XFA_EXPORT_TYPE 
void	XFA_PVD_CertPathResult_Free			(XE_PVD_CertPathResult *certPathRes);

XFA_EXPORT_TYPE 
int		XFA_PVD_VerifyCertPath				(XE_PVD_CertPathResult *certPathRes,	// optional
											 const XE_PVD_CertPathRequest *certPathReq,
											 const XE_PVD_VerifyParam *vrfyParam);

// certstore

XFA_EXPORT_TYPE 
XE_PVD_CertStore *
		XFA_PVD_CertStore_New				(void);

XFA_EXPORT_TYPE 
void	XFA_PVD_CertStore_Reset				(XE_PVD_CertStore *sctx);

XFA_EXPORT_TYPE 
void	XFA_PVD_CertStore_Free				(XE_PVD_CertStore *sctx);

XFA_EXPORT_TYPE 
int		XFA_PVD_CertStore_Open				(XE_PVD_CertStore *sctx,
											 const int storeID,				// optional
											 const char *storePath,
											 const void *param);			// optional

XFA_EXPORT_TYPE 
int		XFA_PVD_CertStore_GetObject			(XE_PVD_CertStore *sctx, 
											 XE_BIN_LIST *encObjs, 
											 const int typeID, 
											 const char *objDN,
											 const void *param);

XFA_EXPORT_TYPE 
int		XFA_PVD_CertStore_AddObject			(XE_PVD_CertStore *sctx,
											 const int typeID, 
											 const char *objDN,
											 const BIN *encObj,
											 const void *param);			// optional

XFA_EXPORT_TYPE 
int		XFA_PVD_CertStore_DelObject			(XE_PVD_CertStore *sctx,
											 const int typeID, 
											 const char *objDN,
											 const void *param);
XFA_EXPORT_TYPE 
int		XFA_PVD_CertStore_GetTrustObject	(XE_PVD_CertStore *sctx, 
											 BIN *encObj, 
											 const int typeID, 
											 const char *objDN,
											 const char *subjectKeyID,			//optional
											 const unsigned int serialNumber);		//optional
XFA_EXPORT_TYPE 
int		XFA_PVD_CertStore_Close				(XE_PVD_CertStore *sctx);

// version

XFA_EXPORT_TYPE 
char *	XFA_PVD_GetVersion					(void);

XFA_EXPORT_TYPE 
int		XFA_PVD_CheckVersion				(const char *version);			// optional

// error

XFA_EXPORT_TYPE 
char *	XFA_PVD_GetErrorReason				(const int code, 
											 const int locale);

#ifdef  __cplusplus
}
#endif

#endif
