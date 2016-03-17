//
//	suite_ssl_callback.h
//

#ifndef _SUITE_SSL_CALLBACK_H_
#define _SUITE_SSL_CALLBACK_H_

/**
 *	Constants
 */

// certificate format

#define	XE_SSLCB_CERTFORMAT_X509			1
#define	XE_SSLCB_CERTFORMAT_WTLS			3
#define	XE_SSLCB_CERTFORMAT_URL				5

// signature algorithm id

#define	XE_SSLCB_SIGNID_RSA					1
#define	XE_SSLCB_SIGNID_DSA					2
#define	XE_SSLCB_SIGNID_ECDSA				3

// encryption algorithm id

#define	XE_SSLCB_ENCID_RSA					1

// public key type

#define	XE_SSLCB_PUBKEYTYPE_RSA				1
#define	XE_SSLCB_PUBKEYTYPE_DH				2

#endif
