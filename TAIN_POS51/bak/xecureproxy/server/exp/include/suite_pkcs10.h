//
//	suite_pkcs10.h
//

#ifndef _SUITE_PKCS10_H_
#define _SUITE_PKCS10_H_

#include "exp_global.h"

/**
 *	Constants
 */

#define	XE_PKCS10_PKEYID_RSA				1
#define XE_PKCS10_PKEYID_KCDSA				2

#define	XE_PKCS10_SIGNID_RSA_V15_MD2		1
#define	XE_PKCS10_SIGNID_RSA_V15_MD5		2
#define	XE_PKCS10_SIGNID_RSA_V15_SHA1		3
#define	XE_PKCS10_SIGNID_KCDSA_SHA1			4
#define	XE_PKCS10_SIGNID_KCDSA_HAS160		5
#define XE_PKCS10_SIGNID_RSA_V15_SHA256		6
#define XE_PKCS10_SIGNID_RSA_V15_SHA384		7
#define XE_PKCS10_SIGNID_RSA_V15_SHA512		8

/**
 *	Struct
 */

typedef struct {
	struct {
		int		pkeyID;						// algorithm id
		BIN		*pkeyParam;					// algorithm parameter (optional)
		char	*subjectDN;					// subject's distingushed name
		BIN		*subjectPubKey;				// subject's public key
		BIN		*attributes;				// attributes (optional)
	} info;
	int		(*CB_ComputeSignature)			(BIN *signature, const BIN *message, 
											 const int signID, const int privKeyID);
	int		signID;							// sign algorithm id
	BIN		*signParam;						// sign algorithm parameter (optional)
	
} XE_PKCS10_CERT_REQUEST;

/**
 *	Error codes
 */

#define	ERR_PKCS10							(ERR_PKCS + 600)

#define PKCS10_ERR_INVALID_INPUT			(ERR_PKCS10 + 1)
#define	PKCS10_ERR_INTERNAL					(ERR_PKCS10 + 2)
#define PKCS10_ERR_MALLOC_FAILED			(ERR_PKCS10 + 3)

#define	PKCS10_ERR_UNKNOWN_ALGID			(ERR_PKCS10 + 10)
#define	PKCS10_ERR_UNKNOWN_SIGNID			(ERR_PKCS10 + 11)
#define	PKCS10_ERR_UNKNOWN_VERSION			(ERR_PKCS10 + 12)

#define	PKCS10_ERR_BAD_CERT_REQUEST			(ERR_PKCS10 + 30)
#define	PKCS10_ERR_BAD_PUBKEY				(ERR_PKCS10 + 32)

#define	PKCS10_ERR_INVALID_SIGNATURE		(ERR_PKCS10 + 50)

#define	PKCS10_ERR_ENCODE_ASN				(ERR_PKCS10 + 90)
#define	PKCS10_ERR_DECODE_ASN				(ERR_PKCS10 + 91)
#define	PKCS10_ERR_ENCODE_SUBJECT			(ERR_PKCS10 + 92)
#define	PKCS10_ERR_DECODE_SUBJECT			(ERR_PKCS10 + 93)

#define	PKCS10_ERR_ASN_FUNCTION				(ERR_PKCS10 + 95)
#define	PKCS10_ERR_CSP_FUNCTION				(ERR_PKCS10 + 96)
#define PKCS10_ERR_NO_PRIVKEY				(ERR_PKCS10 + 97)
#define PKCS10_ERR_CB_COMPUTESIGNATURE		(ERR_PKCS10 + 98)

#define PKCS10_ERR_NO_PARAM					(ERR_PKCS10 + 99)
#define PKCS10_ERR_NO_PUBKEY				(ERR_PKCS10 + 100)

/**
 *	Prototypes
 */

#ifdef  __cplusplus
extern "C" {
#endif

// cert request

XFA_EXPORT_TYPE 
XE_PKCS10_CERT_REQUEST *
		XFA_PKCS10_CreateCertRequest		(void);

XFA_EXPORT_TYPE 
void	XFA_PKCS10_ResetCertRequest			(XE_PKCS10_CERT_REQUEST *certRequest);

XFA_EXPORT_TYPE 
void	XFA_PKCS10_DestroyCertRequest		(XE_PKCS10_CERT_REQUEST *certRequest);

XFA_EXPORT_TYPE 
int		XFA_PKCS10_EncodeCertRequest		(BIN *output,
											 const XE_PKCS10_CERT_REQUEST *certRequest,
											 const BIN *privKey);
XFA_EXPORT_TYPE 
int		XFA_PKCS10_EncodeCertRequest_Init	(BIN *certRequestInfo,
											 const XE_PKCS10_CERT_REQUEST *certRequest);

XFA_EXPORT_TYPE 
int		XFA_PKCS10_EncodeCertRequest_Final	(BIN *output,
											 const BIN *certRequestInfo,
											 const int signID,
											 const BIN *signParam,
											 const BIN *signature);

XFA_EXPORT_TYPE 
int		XFA_PKCS10_DecodeCertRequest		(XE_PKCS10_CERT_REQUEST *certRequest,
											 const BIN *input);

// version

XFA_EXPORT_TYPE 
char *	XFA_PKCS10_GetVersion				(void);

// error

XFA_EXPORT_TYPE 
char	*XFA_PKCS10_GetErrorReason			(const int code, 
											 const int locale);

#ifdef  __cplusplus
}
#endif

#endif
