/* $Id: suite_ldap.h 3111 2011-12-21 05:29:17Z lovian $ */

#ifndef _SUITE_LDAP_H_
#define _SUITE_LDAP_H_

#include "suite_asn.h"

/**
 *	Constants
 */

// objID

// - cert
#define	XE_LDAP_OBJTYPE_CACERT				0x01
#define	XE_LDAP_OBJTYPE_USERCERT			0x02
// - crl
#define XE_LDAP_OBJTYPE_ARL					0x41
#define XE_LDAP_OBJTYPE_CRL					0x42
// - ctl
#define	XE_LDAP_OBJTYPE_CTL					0x51
// - 대법원용 인증서
#define XE_LDAP_CERTCLASS_SIGN				0x91

// for compatibility with prev version {{
#define	XE_LDAP_CERTCLASS_ROOT				0x00
#define	XE_LDAP_CERTCLASS_CA				0x01
#define	XE_LDAP_CERTCLASS_USER				0x02
#define	XE_LDAP_ARL							0x41
#define XE_LDAP_CRL							0x42
#define	XE_LDAP_DCRL						0x43
// }}

/**
 *	Struct
 */
// [2011/01/13 by dhson]
// XecureExpress E 지원, ldap ID/PWD 접속 지원을 위한 api 추가
typedef struct {
	struct timeval	*timeout;				// optional
	char	*authDn;
	char	*password;
} XE_LDAP_GET_PARAM;

/*
typedef struct {
	struct timeval	*timeout;				// optional
} XE_LDAP_GET_PARAM;
*/
//////////////////////////////////////////////////////////////////////
/**
 *	Error codes
 */

#define LDAP_ERR_NS_INIT					(ERR_LDAP + 1)
#define LDAP_ERR_NS_BIND_S					(ERR_LDAP + 2)
#define LDAP_ERR_NS_SET_OPTION				(ERR_LDAP + 3)
#define LDAP_ERR_NS_SEARCH_S				(ERR_LDAP + 4)
#define LDAP_ERR_NS_GET_VALUES_LEN			(ERR_LDAP + 5)
#define LDAP_ERR_NS_FIRST_ENTRY				(ERR_LDAP + 6)
#define LDAP_ERR_NS_URL_PARSE				(ERR_LDAP + 7)
#define LDAP_ERR_NS_TIMEOUT					(ERR_LDAP + 8)

#define LDAP_ERR_INVALID_CERTTYPE			(ERR_LDAP + 11)
#define LDAP_ERR_DECODE_BER					(ERR_LDAP + 12)
#define	LDAP_ERR_INVALID_INPUT				(ERR_LDAP + 13)
#define LDAP_ERR_NO_RESULT					(ERR_LDAP + 14)

/**
 *	Prototypes
 */

#ifdef  __cplusplus
extern "C" {
#endif

XFA_EXPORT_TYPE 
int		XFA_LDAP_GetObject					(BIN *encObj,
											 const char *ds,
											 const char *dn,			// optional
											 const int objType,
											 const XE_LDAP_GET_PARAM *param);

XFA_EXPORT_TYPE 
int		XFA_LDAP_GetCert					(BIN *binCert,
											 const char *ds,
											 const char *dn,
											 const int certType,
											 struct timeval *timeout);

XFA_EXPORT_TYPE 
int		XFA_LDAP_GetCRL						(BIN *binCrl,
											 const char *ds,
											 const char *dn,
											 const BIN *binIssuerCert,
											 struct timeval *timeout);

XFA_EXPORT_TYPE 
int		XFA_LDAP_GetARL						(BIN *binArl,
											 const char *ds,
											 const char *dn,
											 const BIN *binIssuerCert,
											 struct timeval *timeout);

XFA_EXPORT_TYPE
int		XFA_LDAP_GetDCRL					(BIN *binDCrl,
											 const char *ds,
											 const char *dn,
											 const BIN *binIssuerCert,
											 struct timeval *timeout);

// for compatibility with prev version {{
XFA_EXPORT_TYPE 
int		XFA_LDAP_RetrieveCert				(OssGlobal * psOssCtx,
											 Certificate ** pCert,
											 const char *pDS,
											 const char *pDN,
											 const int nCertType);

XFA_EXPORT_TYPE 
int		XFA_LDAP_RetrieveCertBin			(OssGlobal * psOssCtx,
											 BIN * pCertBin,
											 const char *pDS,
											 const char *pDN,
											 const int nCertType);

XFA_EXPORT_TYPE 
int		XFA_LDAP_RetrieveARL				(OssGlobal * psOssCtx,
											 CertificateList ** pCrlCtx,
											 const char *pDS,
											 const char *pDN,
											 const Certificate * pIssCertCtx);

XFA_EXPORT_TYPE 
int		XFA_LDAP_RetrieveCRL				(OssGlobal * psOssCtx,
											 CertificateList ** pCrlCtx,
											 const char *pDS,
											 const char *pDN,
											 const Certificate * pIssCertCtx);

XFA_EXPORT_TYPE 
int		XFA_LDAP_RetrieveERL				(OssGlobal * psOssCtx,
											 BIN * pCRL,
											 const int nRLType,
											 const char *pDS,
											 const char *pDN,
											 const Certificate * pIssCertCtx);
// }}

// version

XFA_EXPORT_TYPE 
char *	XFA_LDAP_GetVersion					(void);

XFA_EXPORT_TYPE 
int		XFA_LDAP_CheckVersion				(const char *version);			// optional

// error

XFA_EXPORT_TYPE 
char *	XFA_LDAP_GetErrorReason				(const int code, const int locale);

// #27 [2009/10/20 by hjkim]
XFA_EXPORT_TYPE
int XFA_LDAP_GetObjectList(XE_BIN_LIST **encObjList,
				   const char *ds,
				   const char *dn,				// optional
				   const int objType,
				   const XE_LDAP_GET_PARAM *param);
XFA_EXPORT_TYPE
int XFA_LDAP_GetCertList(XE_BIN_LIST **encCertList,
				 const char *ds,
				 const char *dn,			// optional
				 const int certType,
				 struct timeval *timeout);
// --#27

// [2011/01/13 by dhson]
// XecureExpress E 지원, ldap ID/PWD 접속 지원을 위한 api 추가
// Functions to get extended parameters eg. authentication information..

XFA_EXPORT_TYPE
int
XFA_LDAP_GetObject_Ex(BIN *encObj,
					  const char *ds,
					  const char *dn,				// optional
					  const int objType,
					  const XE_LDAP_GET_PARAM *param);
XFA_EXPORT_TYPE
int
XFA_LDAP_GetCert_Ex(BIN *encCert,
					const char *ds,
					const char *dn,
					const int certType,
					const XE_LDAP_GET_PARAM *param);

XFA_EXPORT_TYPE
int
XFA_LDAP_GetCRL_Ex(BIN *binCrl,
				   const char *ds,
				   const char *dn,
				   const BIN *binIssuerCert,
				   const XE_LDAP_GET_PARAM *param);

XFA_EXPORT_TYPE
int
XFA_LDAP_GetARL_Ex(BIN *binArl,
				   const char *ds,
				   const char *dn,
				   const BIN *binIssuerCert,
				   const XE_LDAP_GET_PARAM *param);

XFA_EXPORT_TYPE
int
XFA_LDAP_GetDCRL_Ex(BIN *binDCrl,
					const char *ds,
					const char *dn,
					const BIN *binIssuerCert,
					const XE_LDAP_GET_PARAM *param);

XFA_EXPORT_TYPE
int
XFA_LDAP_GetObjectList_Ex(XE_BIN_LIST **encObjList,
						  const char *ds,
						  const char *dn,				// optional
						  const int objType,
						  const XE_LDAP_GET_PARAM *param);

XFA_EXPORT_TYPE
int
XFA_LDAP_GetCertList_Ex(XE_BIN_LIST **encCertList,
						const char *ds,
						const char *dn,
						const int certType,
						const XE_LDAP_GET_PARAM *param);


#ifdef  __cplusplus
}
#endif

#endif
