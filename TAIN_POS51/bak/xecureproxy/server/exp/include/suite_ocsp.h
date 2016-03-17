//
//	$Id: suite_ocsp.h,v 1.10 2006-03-23 08:38:32 ssosuny Exp $
//

#ifndef _SUITE_OCSP_H_
#define _SUITE_OCSP_H_

#include "suite_io.h"

/**
 *	Constants
 */

#define	XE_OCSP_HASHID_MD5					1
#define	XE_OCSP_HASHID_SHA1					2

#define XE_OCSP_CERTSTATUS_GOOD				1
#define XE_OCSP_CERTSTATUS_REVOKED			2
#define XE_OCSP_CERTSTATUS_UNKNOWN			3

#define XE_OCSP_CRLREASON_unspecified		0
#define XE_OCSP_CRLREASON_keyCompromise		1
#define XE_OCSP_CRLREASON_cACompromise		2
#define XE_OCSP_CRLREASON_affiliationChanged 	3
#define XE_OCSP_CRLREASON_superseded 		4
#define XE_OCSP_CRLREASON_cessationOfOperation	5
#define XE_OCSP_CRLREASON_certificateHold	6
#define XE_OCSP_CRLREASON_removeFromCRL		8

// params - 2006-03-23 by ssosuny
#define XE_OCSP_FLAG_DISABLE_SIGN_CHECK		1

/**
 *	Struct
 */

// request

#define	XE_OCSP_SIGNID_SHA1WithRSA			1
#define	XE_OCSP_SIGNID_KCDSA1WithSHA1		3
#define	XE_OCSP_SIGNID_SHA256WithRSA		4
#define	XE_OCSP_SIGNID_SHA384WithRSA		5
#define	XE_OCSP_SIGNID_SHA512WithRSA		6
//add kcdsa1_sha256, kcdsa_sha1, kcdsa_sha256 SIGNID by cristyanne : 20111024
#define XE_OCSP_SIGNID_KCDSA1WithSHA256		7
#define XE_OCSP_SIGNID_KCDSAWithSHA1 		8
#define XE_OCSP_SIGNID_KCDSAWithSHA256		9

typedef struct {
	// reqCerts
	struct _BIN_LIST	*reqCertList;
	// signature
	int		signatureAttach;		// true(1), or false(0)
	int		signID;
	int		signCertAttach;			// true(1), or false(0)
	BIN		*signCert;				// optional
} XE_OCSP_Request;

// response

typedef struct {
	// certID
	struct _XE_OCSP_CertID_ST {
		int		hashID;
		BIN		issuerNameHash;
		BIN		issuerKeyHash;
		BIN		serialNumber;
	} certID;
	// certStatus
	int		certStatus;
	struct {
		time_t	rTime;
		int		rReason;
	} revoked;
	// time
	time_t	thisUpdate;
	time_t	nextUpdate;
} XE_OCSP_SingleResponse;

typedef struct _XE_OCSP_SingleRespList_ST {
	XE_OCSP_SingleResponse	value;
	struct _XE_OCSP_SingleRespList_ST	*next;
} XE_OCSP_SingleRespList;

typedef struct {
	// responseData
	time_t	producedAt;
	BIN		responderKeyID;
	XE_OCSP_SingleRespList	*respList;

	BIN		*cert;					// optional
} XE_OCSP_Response;

// client param

typedef struct {
	// - request
	BIN		*privKey;
	int		(*CB_ComputeSignature)			(BIN *signature, const int signID, 
											 const BIN *message);
	// - response
	BIN		*serverCert;			// optional
	// - transfer
	int		useHTTP;				// true(1), or false(0)
	char	*proxyURL;				// optional

	// - check signature (optional)  2006-03-23 by ssosuny
	int		checkSign;
} XE_OCSP_ClientParam;

/**
 *	Error codes
 */

#define OCSP_ERR_INVALID_INPUT				(ERR_OCSP + 1)
#define OCSP_ERR_INTERNAL					(ERR_OCSP + 2)
#define OCSP_ERR_MALLOC_FAILED				(ERR_OCSP + 3)

#define OCSP_ERR_UNKNOWN_HASHID 			(ERR_OCSP + 10)
#define	OCSP_ERR_UNKNOWN_SIGNID				(ERR_OCSP + 11)

#define	OCSP_ERR_MISMATCH_RESPONDERID		(ERR_OCSP + 15)

#define	OCSP_ERR_BAD_REQUEST				(ERR_OCSP + 30)
#define	OCSP_ERR_BAD_RESPONSE				(ERR_OCSP + 31)
#define	OCSP_ERR_BAD_CERT					(ERR_OCSP + 32)

#define OCSP_ERR_INVALID_SIGNATURE			(ERR_OCSP + 40)

#define	OCSP_ERR_NO_AKI_IN_CERT				(ERR_OCSP + 50)
#define	OCSP_ERR_NO_AIA_IN_CERT				(ERR_OCSP + 51)
#define	OCSP_ERR_NO_CERT					(ERR_OCSP + 52)

#define	OCSP_ERR_RESPSTATE_MALFORMED_REQUEST	(ERR_OCSP + 71)
#define	OCSP_ERR_RESPSTATE_INTERNAL_ERROR	(ERR_OCSP + 72)
#define	OCSP_ERR_RESPSTATE_TRY_LATER		(ERR_OCSP + 73)
#define	OCSP_ERR_RESPSTATE_SIG_REQUIRED		(ERR_OCSP + 75)
#define	OCSP_ERR_RESPSTATE_UNAUTHORIZED		(ERR_OCSP + 76)
#define	OCSP_ERR_RESPSTATE_UNKNOWN			(ERR_OCSP + 79)

#define OCSP_ERR_ENCODE_ASN 				(ERR_OCSP + 90)
#define OCSP_ERR_DECODE_ASN 				(ERR_OCSP + 91)

#define OCSP_ERR_SOCKET_READ_FAILED 		(ERR_OCSP + 150)
#define OCSP_ERR_SOCKET_WRITE_FAILED		(ERR_OCSP + 151)

#define	OCSP_ERR_HTTP_NO_LENGTH				(ERR_OCSP + 160)
#define	OCSP_ERR_HTTP_BAD_HEADER			(ERR_OCSP + 161)
#define	OCSP_ERR_HTTP_BAD_URL				(ERR_OCSP + 162)
#define	OCSP_ERR_HTTP_GATEWAY_TIMEOUT		(ERR_OCSP + 163)
#define	OCSP_ERR_HTTP_ERROR_STATUS			(ERR_OCSP + 164)

/**
 *	Prototypes
 */

#ifdef	__cplusplus
extern "C" {
#endif

// request

XFA_EXPORT_TYPE 
XE_OCSP_Request *
		XFA_OCSP_CreateRequest				(void);

XFA_EXPORT_TYPE 
void	XFA_OCSP_ResetRequest				(XE_OCSP_Request *ocspReq);

XFA_EXPORT_TYPE 
void	XFA_OCSP_DestroyRequest				(XE_OCSP_Request *ocspReq);

XFA_EXPORT_TYPE 
int 	XFA_OCSP_EncodeRequest				(BIN *request,
											 const XE_OCSP_Request *ocspReq,
											 const BIN *privKey);

XFA_EXPORT_TYPE 
int		XFA_OCSP_EncodeRequest_Init			(BIN *tbsRequest,
											 const XE_OCSP_Request *ocspReq);

XFA_EXPORT_TYPE 
int		XFA_OCSP_EncodeRequest_Final		(BIN *request,
											 const BIN *tbsRequest,
											 const BIN *signature,
											 const XE_OCSP_Request *ocspReq);

// response

XFA_EXPORT_TYPE 
XE_OCSP_Response *
		XFA_OCSP_CreateResponse				(void);

XFA_EXPORT_TYPE 
void	XFA_OCSP_ResetResponse				(XE_OCSP_Response *ocspResp);

XFA_EXPORT_TYPE 
void	XFA_OCSP_DestroyResponse			(XE_OCSP_Response *ocspResp);

XFA_EXPORT_TYPE 
int 	XFA_OCSP_DecodeResponse 			(XE_OCSP_Response *ocspResp,
											 const BIN *response,
											 const BIN *serverCert);		// optional
XFA_EXPORT_TYPE 
int 	XFA_OCSP_DecodeResponseEx 			(XE_OCSP_Response *ocspResp,
											 const BIN *response,
											 const BIN *serverCert,		// optional
											 const int optionalFlag);		// optional

// client

XFA_EXPORT_TYPE 
int 	XFA_OCSP_Client 					(XE_OCSP_Response *ocspResp,
											 BIN *request,
											 BIN *response,
											 const int socket,
											 const XE_OCSP_Request *ocspReq,
											 const XE_OCSP_ClientParam *clientParam);

// version

XFA_EXPORT_TYPE 
char *	XFA_OCSP_GetVersion 				(void);

XFA_EXPORT_TYPE 
int		XFA_OCSP_CheckVersion				(const char *version);			// optional

// error

XFA_EXPORT_TYPE 
char *	XFA_OCSP_GetErrorReason 			(const int code, 
											 const int locale);

#ifdef	__cplusplus
}
#endif

#endif
