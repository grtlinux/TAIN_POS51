//
//	suite_php.h
//

#ifndef _SUITE_PHP_H_
#define _SUITE_PHP_H_

#include "exp_global.h"

/**
 *	Constants
 */

#define	XE_PHP_CERTTYPE_X509_CERT			1
#define	XE_PHP_CERTTYPE_PHP_CERT			2

/**
 *	Struct
 */

typedef struct {
	BIN		*serverCert;					// der encoded server x509 cert
} XE_PHP_ClientParam;

typedef struct {
	int		(*CB_GetUserKeyNCert)			(BIN *privKey, unsigned char *certType, 
											 BIN *cert, const BIN *userID);
} XE_PHP_ServerParam;

typedef struct {
	int		socket;
} XE_PHP_CTX;

/**
 *	Error codes
 */

#define	PHP_ERR_INVALID_INPUT				(ERR_PHP + 1)
#define	PHP_ERR_INTERNAL					(ERR_PHP + 2)
#define	PHP_ERR_MALLOC_FAILED				(ERR_PHP + 3)

#define	PHP_ERR_SOCKET_READ_FAILED			(ERR_PHP + 10)
#define	PHP_ERR_SOCKET_WRITE_FAILED			(ERR_PHP + 11)
#define	PHP_ERR_SOCKET_CLOSED				(ERR_PHP + 12)
#define	PHP_ERR_SOCKET_READ_WAIT			(ERR_PHP + 13)
#define	PHP_ERR_SOCKET_WRITE_WAIT			(ERR_PHP + 14)

#define	PHP_ERR_UNKNOWN_VERSION				(ERR_PHP + 20)
#define	PHP_ERR_UNKNOWN_MESSAGE				(ERR_PHP + 21)
#define	PHP_ERR_UNKNOWN_CERT				(ERR_PHP + 22)
#define	PHP_ERR_UNKNOWN_USERID				(ERR_PHP + 23)
#define	PHP_ERR_BLOCKED_USERID				(ERR_PHP + 24)
#define	PHP_ERR_BAD_MESSAGE					(ERR_PHP + 25)
#define	PHP_ERR_BAD_CERTIFICATE				(ERR_PHP + 26)
#define	PHP_ERR_INVALID_STRONG				(ERR_PHP + 30)
#define	PHP_ERR_INVALID_PHPCERT				(ERR_PHP + 31)
#define	PHP_ERR_NO_CERTIFICATE				(ERR_PHP + 35)

#define	PHP_ERR_ASN_FUNCTION				(ERR_PHP + 50)
#define	PHP_ERR_BIGINT_FUNCTION				(ERR_PHP + 51)
#define	PHP_ERR_RSA_FUNCTION				(ERR_PHP + 52)
#define	PHP_ERR_PKCS1_FUNCTION				(ERR_PHP + 53)
#define	PHP_ERR_CSP_FUNCTION				(ERR_PHP + 54)

#define	PHP_ERR_AD_UNEXPECTED_MESSAGE		(ERR_PHP + 60)
#define	PHP_ERR_AD_ILLEGAL_PARAMETER		(ERR_PHP + 61)
#define	PHP_ERR_AD_UNKNOWN_USERID			(ERR_PHP + 62)
#define	PHP_ERR_AD_BLOCKED_USERID			(ERR_PHP + 66)
#define	PHP_ERR_AD_NO_CERTIFICATE			(ERR_PHP + 63)
#define	PHP_ERR_AD_BAD_CERTIFICATE			(ERR_PHP + 64)
#define	PHP_ERR_AD_INTERNAL_ERROR			(ERR_PHP + 65)

/**
 *	Prototypes
 */

#ifdef  __cplusplus
extern "C" {
#endif

// ctx

XFA_EXPORT_TYPE 
XE_PHP_CTX*
		XFA_PHP_CreateCTX					(void);

XFA_EXPORT_TYPE
int		XFA_PHP_ResetCTX					(XE_PHP_CTX *ctx);

XFA_EXPORT_TYPE
void	XFA_PHP_DestroyCTX					(XE_PHP_CTX *ctx);

// client

XFA_EXPORT_TYPE 
int		XFA_PHP_Connect						(XE_PHP_CTX *ctx, 
											 BIN *strong,
											 const int socket,
											 const BIN *userID,
											 const BIN *passwd,
											 const XE_PHP_ClientParam *param);

// server

XFA_EXPORT_TYPE 
int		XFA_PHP_Accept						(XE_PHP_CTX *ctx,
											 BIN *userID,
											 const int socket,
											 const XE_PHP_ServerParam *param);

// phpcert

XFA_EXPORT_TYPE 
int		XFA_PHP_EncodePHPCert				(BIN *phpCert,
											 const BIN *userID,
											 const BIN *userPubKey,
											 const BIN *signerPrivKey);

XFA_EXPORT_TYPE 
int		XFA_PHP_EncodePHPCert_Init			(BIN *toBeSignedCert,
											 const BIN *userID,
											 const BIN *userPubKey);

XFA_EXPORT_TYPE 
int		XFA_PHP_EncodePHPCert_Final			(BIN *phpCert,
											 const BIN *toBeSignedCert,
											 const BIN *signature);

XFA_EXPORT_TYPE 
int		XFA_PHP_DecodePHPCert				(BIN *userID,
											 BIN *userPubKey,
											 const BIN *phpCert);

XFA_EXPORT_TYPE 
int		XFA_PHP_VerifyPHPCert				(const BIN *phpCert,
											 const BIN *signerPubKey);

// comp

XFA_EXPORT_TYPE 
int		XFA_PHP_ComputeKDF					(BIN *output,
											 const unsigned int outputLength,
											 const BIN *input);

// error

XFA_EXPORT_TYPE 
char *	XFA_PHP_GetVersion					(void);

// error

XFA_EXPORT_TYPE 
char *	XFA_PHP_GetErrorReason				(const int code, 
											 const int locale);

#ifdef  __cplusplus
}
#endif

#endif

