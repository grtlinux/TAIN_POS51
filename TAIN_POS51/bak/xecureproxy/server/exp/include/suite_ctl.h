//
//	$Id: suite_ctl.h,v 1.1 2005-01-25 00:24:34 scian Exp $
//

#ifndef _SUITE_CTL_H_
#define _SUITE_CTL_H_

#include "suite_asn.h"

/**
 *	Constants
 */

/**
 *	Struct
 */
 
typedef struct {
	int		flags;
} XE_CTL_DECODE_PARAM;

/**
 *	Error codes
 */

#ifndef	ERR_CTL
#define ERR_CTL 							(ERR_PRIMITIVE * 44)
#endif

#define CTL_ERR_INVALID_INPUT				(ERR_CTL + 1)
#define CTL_ERR_INTERNAL					(ERR_CTL + 2)
#define CTL_ERR_MALLOC_FAILED				(ERR_CTL + 3)

#define CTL_ERR_UNKNOWN_HASHID				(ERR_CTL + 10)
#define CTL_ERR_BAD_SIGNED					(ERR_CTL + 20)
#define CTL_ERR_BAD_CTL						(ERR_CTL + 30)
// #27 [2009/10/20 by hjkim]
#define CTL_ERR_NOT_CERT_TRUSTED			(ERR_CTL + 40)

#define CTL_ERR_INVALID_TIME				(ERR_CTL + 52)
#define	CTL_ERR_INVALID_SUBJECT_USAGE		(ERR_CTL + 53)
#define	CTL_ERR_INVALID_VERSION				(ERR_CTL + 54)

#define CTL_ERR_CTL_EXPIRED 				(ERR_CTL + 80)

/**
 *	Prototypes
 */

#ifdef	__cplusplus
extern "C" {
#endif

// signed

XFA_EXPORT_TYPE
int		XFA_CTL_EncodeSigned				(BIN *pkcs7,
											 const BIN *ctl,
											 const BIN *signerCert,
											 const BIN *signerPrivKey,
											 const XE_BIN_LIST *otherCerts,   // optional
											 const BIN *crl,				// optional
											 const void *param);              // optional

XFA_EXPORT_TYPE
int		XFA_CTL_DecodeSigned				(BIN *ctl,
											 BIN *signerCert,
											 XE_BIN_LIST **otherCerts,
											 const BIN *pkcs7,
											 const BIN *extrnCert,			// optional, signer cert
											 const void *param);

// ctl

XFA_EXPORT_TYPE
int		XFA_CTL_Verify						(const CertificateTrustList *pAsnCTL,
											 const time_t verifyTime);

XFA_EXPORT_TYPE
int		XFA_CTL_IsCertTrusted				(const CertificateTrustList *pAsnCTL, 
											 const BIN *targetCert);

											 
// version

XFA_EXPORT_TYPE 
char *	XFA_CTL_GetVersion					(void);

XFA_EXPORT_TYPE 
int		XFA_CTL_CheckVersion				(const char *version);			// optional

// error

XFA_EXPORT_TYPE 
char *	XFA_CTL_GetErrorReason				(const int code, 
											 const int locale);

#ifdef	__cplusplus
}
#endif

#endif
