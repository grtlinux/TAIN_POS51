/**
 *
 *	Copyright (c) 1999-2004 SoftForum Co. LTD. All rights reserved.
 *
 *	exp_global.h
 *
 */

#ifndef _EXP_GLOBAL_H_
#define _EXP_GLOBAL_H_

/**
 *	Constants
 */

#define TRUE								1
#define FALSE								0

#define PKI_YES 							1
#define PKI_NO								0

#define LOCALE_HAN							0
#define LOCALE_ENG							1

// for compatibility with prev version {{
#define ERR_MSG_LOCALE_KOR					LOCALE_HAN
#define ERR_MSG_LOCALE_ENG					LOCALE_ENG

#define XFA_PKIX_UNDEFINED_ERR_REASON		"UnDefined Error Reason"
// }}

/**
 *	Struct
 */

typedef struct _BIN {
	unsigned int	length;
	unsigned char	*value;
} BIN;

typedef struct _BIN_LIST {
	struct _BIN_LIST	*next;
	BIN 	value;
} *BIN_LIST;

typedef struct {
	unsigned short	length;
	unsigned char	*value;
} XE_HUGE;

// for compatibility with prev version {{
#ifndef _MAC // 2007.5.3 매킨토시 GUI 라이브러리와 HUGE 구조체와 충돌 발생하여 수정 jhhong
#ifndef DISABLE_HUGE
typedef struct _HUGE {
	unsigned short	length;
	unsigned char	*value;
} HUGE;
#endif
#endif
// }}

typedef struct ERR_MSG_ST {
	int 	nCode;
	char	*pReason;
} ERR_MSG_DATA;

/**
 *	Error codes
 */

#define PKI_OK								0
#define PKI_ERR 							-1
#define PKI_UND_ERR 						-2

/* Primitive Layer : 1 ~ 29 */ 

#define ERR_PRIMITIVE						1000

#define ERR_ASN 							(ERR_PRIMITIVE *  1)
#define ERR_CB								(ERR_PRIMITIVE *  2)
#define ERR_CODEC							(ERR_PRIMITIVE *  3)
#define ERR_COMPRESS						(ERR_PRIMITIVE *  4)
#define ERR_CONFIG							(ERR_PRIMITIVE *  5)
#define ERR_CSP								(ERR_PRIMITIVE *  6)
#define	ERR_SSS								(ERR_PRIMITIVE *  6 + 200)
#define ERR_HSM								(ERR_PRIMITIVE *  7)
#define ERR_IO								(ERR_PRIMITIVE *  8)
#define ERR_LOG 							(ERR_PRIMITIVE *  9)
#define ERR_MISC							(ERR_PRIMITIVE * 11)
#define ERR_STL 							(ERR_PRIMITIVE * 13)

/* Service Layer : 30 ~ 59 */

#define ERR_AC								(ERR_PRIMITIVE * 30)
#define ERR_CMP 							(ERR_PRIMITIVE * 31)
#define ERR_CMS 							(ERR_PRIMITIVE * 32)
#define ERR_CRL 							(ERR_PRIMITIVE * 33)
#define ERR_LDAP							(ERR_PRIMITIVE * 34)
#define ERR_OCSP							(ERR_PRIMITIVE * 35)
#define ERR_PKC 							(ERR_PRIMITIVE * 36)
#define ERR_PKCS							(ERR_PRIMITIVE * 37)
#define ERR_TSP 							(ERR_PRIMITIVE * 38)
#define	ERR_SSL								(ERR_PRIMITIVE * 39)
#define ERR_PHP 							(ERR_PRIMITIVE * 40)
#define ERR_OPP 							(ERR_PRIMITIVE * 41)
#define ERR_OTP 							(ERR_PRIMITIVE * 42)
#define ERR_PVD 							(ERR_PRIMITIVE * 43)
#define ERR_ARC								(ERR_PRIMITIVE * 44) /* 전자문서 보관소 */
#define ERR_BIO								(ERR_PRIMITIVE * 45) /* BIO API */
#define ERR_MRTD							(ERR_PRIMITIVE * 46) /* 전자여권 */

/* Application Layer : 60 ~ 99 */

#define ERR_CC								(ERR_PRIMITIVE * 60)
#define ERR_LICENSE 						(ERR_PRIMITIVE * 61)
#define ERR_STC 							(ERR_PRIMITIVE * 62)
#define ERR_TP								(ERR_PRIMITIVE * 63)
#define ERR_XML 							(ERR_PRIMITIVE * 64)
#define ERR_RMP 							(ERR_PRIMITIVE * 70)
#define ERR_RAS 							(ERR_PRIMITIVE * 71)
#define ERR_CAS 							(ERR_PRIMITIVE * 72)

/**
 *	Prototypes
 */

#if defined(_WIN32) || defined(_WIN32_WCE)
#define XFA_EXPORT_TYPE 					__declspec(dllexport)
#else
#define XFA_EXPORT_TYPE
#endif

#endif
