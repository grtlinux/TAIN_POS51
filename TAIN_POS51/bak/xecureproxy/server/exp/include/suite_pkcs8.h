//
//	$Id: suite_pkcs8.h,v 1.7 2004-05-18 09:17:30 guspin Exp $
//

#ifndef _SUITE_PKCS8_H_
#define _SUITE_PKCS8_H_

#include "exp_global.h"

#include "suite_pkcs5.h"

/**
 *	Constants
 */

#define	XE_PKCS8_ALGID_RSA					1
#define	XE_PKCS8_ALGID_DSA					3
#define	XE_PKCS8_ALGID_KCDSA				11

/**
 *	Struct
 */

typedef struct {
	int		algID;
	BIN		*algParam;				// der, optional
	BIN		*privKey;				// der
	struct {
		BIN		*vidRandom;			// optional
	} attribs;
} XE_PKCS8_PRIVKEY_INFO;

typedef struct {
	XE_PKCS5_PBES_ALGID		pbesID;
	XE_PKCS8_PRIVKEY_INFO	info;
} XE_PKCS8_ENC_PRIVKEY_INFO;

/**
 *	Error codes
 */

#define	ERR_PKCS8							(ERR_PKCS + 400)

#define	PKCS8_ERR_INVALID_INPUT				(ERR_PKCS8 + 1)
#define	PKCS8_ERR_INTERNAL					(ERR_PKCS8 + 2)
#define	PKCS8_ERR_MALLOC_FAILED				(ERR_PKCS8 + 3)

#define	PKCS8_ERR_UNKNOWN_ALGID				(ERR_PKCS8 + 10)

#define	PKCS8_ERR_BAD_PRIVKEY				(ERR_PKCS8 + 20)
#define	PKCS8_ERR_BAD_PRIVKEYINFO			(ERR_PKCS8 + 21)
#define	PKCS8_ERR_BAD_ENCPRIVKEYINFO		(ERR_PKCS8 + 22)
#define	PKCS8_ERR_BAD_VIDRANDOM				(ERR_PKCS8 + 25)

#define	PKCS8_ERR_INVALID_PASSWORD			(ERR_PKCS8 + 30)

/**
 *	Prototypes
 */

#ifdef  __cplusplus
extern "C" {
#endif

// privkeyinfo

XFA_EXPORT_TYPE
XE_PKCS8_PRIVKEY_INFO *
		XFA_PKCS8_CreatePrivKeyInfo			(void);

XFA_EXPORT_TYPE
void	XFA_PKCS8_ResetPrivKeyInfo			(XE_PKCS8_PRIVKEY_INFO *privKeyInfo);

XFA_EXPORT_TYPE
void	XFA_PKCS8_DestroyPrivKeyInfo		(XE_PKCS8_PRIVKEY_INFO *privKeyInfo);

XFA_EXPORT_TYPE
int		XFA_PKCS8_EncodePrivKeyInfo			(BIN *output,
											 const XE_PKCS8_PRIVKEY_INFO *privKeyInfo);

XFA_EXPORT_TYPE
int		XFA_PKCS8_DecodePrivKeyInfo			(XE_PKCS8_PRIVKEY_INFO *privKeyInfo,
											 const BIN *input);

XFA_EXPORT_TYPE
int		XFA_PKCS8_IsPrivKeyInfo				(const BIN *input);

// encprivkeyinfo

XFA_EXPORT_TYPE
XE_PKCS8_ENC_PRIVKEY_INFO *
		XFA_PKCS8_CreateEncPrivKeyInfo		(void);

XFA_EXPORT_TYPE
void	XFA_PKCS8_ResetEncPrivKeyInfo		(XE_PKCS8_ENC_PRIVKEY_INFO *encPrivKeyInfo);

XFA_EXPORT_TYPE
void	XFA_PKCS8_DestroyEncPrivKeyInfo		(XE_PKCS8_ENC_PRIVKEY_INFO *encPrivKeyInfo);

XFA_EXPORT_TYPE
int		XFA_PKCS8_EncodeEncPrivKeyInfo		(BIN *pbe,
											 const XE_PKCS8_ENC_PRIVKEY_INFO *encPrivKeyInfo,
											 const BIN *password);

XFA_EXPORT_TYPE
int		XFA_PKCS8_DecodeEncPrivKeyInfo		(XE_PKCS8_ENC_PRIVKEY_INFO *encPrivKeyInfo,
											 const BIN *pbe,
											 const BIN *password);

XFA_EXPORT_TYPE
int		XFA_PKCS8_IsEncPrivKeyInfo			(const BIN *pbe);

XFA_EXPORT_TYPE
int		XFA_PKCS8_ChangeEncPrivKeyInfo		(BIN *outPBE,
											 const BIN *inPBE,
											 const BIN *password,
											 const XE_PKCS8_PRIVKEY_INFO *privKeyInfo);

XFA_EXPORT_TYPE
int		XFA_PKCS8_ChangePassword			(BIN *outPBE,
											 const BIN *inPBE,
											 const BIN *newPassword,
											 const BIN *oldPassword);

XFA_EXPORT_TYPE
int		XFA_PKCS8_VerifyPassword			(const BIN *pbe,
											 const BIN *password);

// version

XFA_EXPORT_TYPE 
char *	XFA_PKCS8_GetVersion				(void);

XFA_EXPORT_TYPE 
int		XFA_PKCS8_CheckVersion				(const char *version);			// optional

// error

XFA_EXPORT_TYPE 
char *	XFA_PKCS8_GetErrorReason			(const int code, 
											 const int locale);

#ifdef  __cplusplus
}
#endif

#endif

