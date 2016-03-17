//
//	$Id: suite_crl.h,v 1.5 2007-07-04 08:22:43 jhhong Exp $
//

#ifndef _SUITE_CRL_H_
#define _SUITE_CRL_H_

#include "suite_asn.h"

/**
 *	Constants
 */

// for compatibility with prev version {{
#define TYPE_ARL							1
#define TYPE_CRL							2
// }}

/**
 *	Struct
 */

/**
 *	Error codes
 */

#define CRL_ERR_INVALID_INPUT				(ERR_CRL + 1)
#define CRL_ERR_INTERNAL					(ERR_CRL + 2)
#define CRL_ERR_MALLOC_FAILED				(ERR_CRL + 3)

#define CRL_ERR_UNKNOWN_SIGNID				(ERR_CRL + 10)

#define CRL_ERR_BAD_CRL						(ERR_CRL + 30)

#define CRL_ERR_INVALID_SIGNATURE			(ERR_CRL + 50)
#define CRL_ERR_INVALID_TIME				(ERR_CRL + 51)

#define CRL_ERR_CRL_EXPIRED 				(ERR_CRL + 80)

/**
 *	Prototypes
 */

#ifdef	__cplusplus
extern "C" {
#endif

XFA_EXPORT_TYPE
int		XFA_CRL_VerifySignature				(const CertificateList *pAsnCRL,
											 const Certificate *pAsnIssCert);

XFA_EXPORT_TYPE
int		XFA_CRL_VerifyTime					(const CertificateList *pAsnCRL,
											 const time_t verifyTime);

XFA_EXPORT_TYPE
int		XFA_CRL_IsCertRevoked				(const CertificateList *pAsnCRL, 
											 const Certificate *pAsnCert);

// for compatibility with prev version {{
XFA_EXPORT_TYPE
int 	XFA_GetCRLCtx						(OssGlobal *ossCtx, 
											 const char *filename, 
											 CertificateList **ppAsnCRL);

XFA_EXPORT_TYPE
int 	XFA_GetCRLCtxBin					(OssGlobal *ossCtx, 
											 const BIN *crlBin, 
											 CertificateList **ppAsnCRL);
// }}

// check crl

XFA_EXPORT_TYPE
int 	XFA_VerifyCRL						(OssGlobal *ossCtx,
											 const Certificate *pAsnIssCert, 
											 const CertificateList *pAsnCRL);

XFA_EXPORT_TYPE
int 	XFA_IsCRLTimeOut					(OssGlobal *ossCtx, 
											 const BIN *crlBin);

XFA_EXPORT_TYPE
int 	XFA_IsCRLCtxTimeOut 				(const CertificateList *pAsnCRL);

// check revoked

XFA_EXPORT_TYPE
int 	XFA_IsCertRevoked					(OssGlobal *ossCtx,
											 const CertificateList *pAsnCRL, 
											 const Certificate *pAsnCert);

// 2007/5/3 jhhong HUGE -> XE_HUGE ·Î º¯°æ
XFA_EXPORT_TYPE
int 	XFA_IsCertRevokedSerial 			(OssGlobal *ossCtx,
											 const CertificateList *pAsnCRL, 
											 const XE_HUGE *pSerial);

XFA_EXPORT_TYPE
int 	XFA_IsCertRevokedSerialGetRevokedTime(OssGlobal *ossCtx,
											 const CertificateList *pAsnCRL, 
											 const XE_HUGE *pSerial,
											 time_t *ltime);

XFA_EXPORT_TYPE
int 	XFA_IsCertRevokedSerialAndGetRevokedInfo(OssGlobal *ossCtx,
											 const CertificateList *pAsnCRL, 
											 const XE_HUGE *pSerial,
											 time_t *ltime,
											 CRLReason *pAsnReason);

// version

XFA_EXPORT_TYPE 
char *	XFA_CRL_GetVersion					(void);

XFA_EXPORT_TYPE 
int		XFA_CRL_CheckVersion				(const char *version);			// optional

// error

XFA_EXPORT_TYPE 
char *	XFA_CRL_GetErrorReason				(const int code, 
											 const int locale);

// for compatibility with prev version {{
XFA_EXPORT_TYPE 
char *	XFA_GetVersionCRL					(void);

XFA_EXPORT_TYPE 
char *	XFA_GetErrReasonCRL 				(const int code, 
											 const int locale);
// }}

#ifdef	__cplusplus
}
#endif

#endif
