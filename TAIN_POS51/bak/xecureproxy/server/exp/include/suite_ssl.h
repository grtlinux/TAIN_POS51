//
//	suite_ssl.h
//

#ifndef _SUITE_SSL_H_
#define _SUITE_SSL_H_

#include "suite_ssl_bin.h"
#include "suite_ssl_callback.h"

/**
 *	Constants
 */

// cipher suite

#define	XE_SSL_RSA_WITH_NULL_MD5			1
#define	XE_SSL_RSA_WITH_NULL_SHA			2
#define	XE_SSL_RSA_EXPORT_WITH_RC4_40_MD5	3
#define	XE_SSL_RSA_WITH_RC4_128_MD5			4
#define	XE_SSL_RSA_WITH_RC4_128_SHA			5
#define	XE_SSL_RSA_EXPORT_WITH_RC2_CBC_40_MD5	6
#define	XE_SSL_RSA_EXPORT_WITH_DES40_CBC_SHA	8
#define	XE_SSL_RSA_WITH_DES_CBC_SHA			9
#define	XE_SSL_RSA_WITH_3DES_EDE_CBC_SHA	10
#define	XE_SSL_RSA_WITH_AES_128_CBC_SHA		11

#define XE_SSL_RSA_WITH_SEED_CBC_SHA		(100 + 9)
#define XE_SSL_RSA_WITH_SEED_CBC_HAS		(100 +10)

// compress method

#define	XE_SSL_COMPRESS_METHOD_NULL			0

// client certificate type

#define	XE_SSL_CCT_RSA_SIGN					1
#define	XE_SSL_CCT_ECC_SIGN					129

//	Protocol Version (SSL3.0/TLS1.0)

#define	XE_SSL_VERSION_MAJOR					 3
#define	XE_SSL_VERSION_MINOR					 0
#define	XE_TLS_VERSION_MINOR					 1

// debug level

#define	XE_SSL_DEBUG_LEVEL_NONE				0
#define	XE_SSL_DEBUG_LEVEL_INFO				3
#define	XE_SSL_DEBUG_LEVEL_TRACE			4
#define	XE_SSL_DEBUG_LEVEL_DEBUG			5

/**
 *	Struct
 */

// HJKIM, 2007.02.08, version 정보 추가
typedef struct {
	uint8		cipher_suites[16];
	int			cipher_suites_length;

	uint8		compress_methods[2];
	int			compress_methods_length;

	uint8		version[2];

	uint8		debug_level;
} XE_SSL_ClientParam;

typedef struct {
	uint8		cipher_suites[16];
	int			cipher_suites_length;

	uint8		compress_methods[2];
	int			compress_methods_length;

	uint8		client_auth;			// true(1), or false(0)

	uint8		client_cert_types[3];
	int			client_cert_types_length;

	uint8		debug_level;
} XE_SSL_ServerParam;

/**
 *	Error codes
 */

#include "suite_ssl_error.h"

/**
 *	Prototypes
 */

#include "suite_ssl_ctx.h"

#ifdef	__cplusplus
extern "C" {
#endif

// client

XFA_EXPORT_TYPE
int		XFA_SSL_InitClient					(XE_SSL_CTX *ssl_ctx, 
											 const XE_SSL_CallBack *callback,
											 const XE_SSL_ClientParam *param);

XFA_EXPORT_TYPE
int		XFA_SSL_Connect						(XE_SSL_CTX *ssl_ctx,
											 const int socket);

// server

XFA_EXPORT_TYPE
int		XFA_SSL_InitServer					(XE_SSL_CTX *ssl_ctx, 
											 const XE_SSL_CallBack *callback,
											 const XE_SSL_ServerParam *param);

XFA_EXPORT_TYPE
int		XFA_SSL_Accept						(XE_SSL_CTX *ssl_ctx,
											 const int socket);

// both

XFA_EXPORT_TYPE
int		XFA_SSL_Read						(XE_SSL_CTX *ssl_ctx, 
											 char *buf, 
											 int *length,
											 const int max_length);

XFA_EXPORT_TYPE
int		XFA_SSL_Write						(XE_SSL_CTX *ssl_ctx, 
											 const char *buf, 
											 const int len);

XFA_EXPORT_TYPE
int		XFA_SSL_Close						(XE_SSL_CTX *ssl_ctx);

// version

XFA_EXPORT_TYPE
char *	XFA_SSL_GetVersion					(void);

#ifdef	__cplusplus
}
#endif

#endif 
