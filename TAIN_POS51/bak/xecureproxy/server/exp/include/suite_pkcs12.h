//
//	$Id: suite_pkcs12.h,v 1.11 2005-08-11 01:38:44 scian Exp $
//

#ifndef _SUITE_PKCS12_H_
#define _SUITE_PKCS12_H_

#include "exp_global.h"

/**
 *	Constants
 */

#define	XE_PKCS12_BAGID_KEY					1
#define	XE_PKCS12_BAGID_SHKEY				2
#define	XE_PKCS12_BAGID_CERT				3
#define	XE_PKCS12_BAGID_CRL					4
#define	XE_PKCS12_BAGID_SECRET				5
#define	XE_PKCS12_BAGID_SAFECTS				6

#define	XE_PKCS12_PVCID_NO					1
#define	XE_PKCS12_PVCID_PUBLICKEY			2
#define	XE_PKCS12_PVCID_PASSWORD			3

#define	XE_PKCS12_ITGID_PUBLICKEY			1
#define	XE_PKCS12_ITGID_PASSWORD			2

#define	XE_PKCS12_ENCID_DES_CBC				1
#define	XE_PKCS12_ENCID_DES_EDE3_CBC		2

#define	XE_PKCS12_PBEID_SHA_128_RC4			1
#define	XE_PKCS12_PBEID_SHA_40_RC4			2
#define	XE_PKCS12_PBEID_SHA_3KEY_TDES_CBC	3
#define	XE_PKCS12_PBEID_SHA_2KEY_TDES_CBC	4
#define	XE_PKCS12_PBEID_SHA_128_RC2_CBC		5
#define	XE_PKCS12_PBEID_SHA_40_RC2_CBC		6

/**
 *	Struct
 */

// Attribs, Bag, BagList

typedef struct {
	char	*friendlyName;				// optional
	BIN		*localKeyId;				// optional
} XE_PKCS12_ATTRIBS;

typedef struct {
	int		bagID;
	BIN		bagValue;					// der
	XE_PKCS12_ATTRIBS	*bagAttribs;	// optional
} XE_PKCS12_BAG;

typedef struct _XE_PKCS12_BAG_SET {
	XE_PKCS12_BAG	bag;
	struct _XE_PKCS12_BAG_SET	*next;
} XE_PKCS12_BAG_SET;

// privacy mode

typedef struct {
	int		pvcID;
	struct {
		int		encID;
		BIN		*recipCert;				// der
		BIN		*recipPrivKey;			// der
	} pubkeyParam;
	struct {
		int		pbeID;
		BIN		*password;
	} passwdParam;
} XE_PKCS12_PVC_MODE;

// integrity mode

typedef struct {
	int		itgID;
	struct {
		BIN		*signerCert;			// der
		BIN		*signerPrivKey;			// der
	} pubkeyParam;
	struct {
		BIN		*password;
	} passwdParam;
} XE_PKCS12_ITG_MODE;

// pfx

typedef struct {
	XE_PKCS12_BAG_SET	*bagSet;
	XE_PKCS12_PVC_MODE	pvcMode;
} XE_PKCS12_CTS;

typedef struct _XE_PKCS12_CTS_SET {
	XE_PKCS12_CTS	cts;
	struct _XE_PKCS12_CTS_SET	*next;
} XE_PKCS12_CTS_SET;

typedef struct {
	XE_PKCS12_CTS_SET	*ctsSet;
	XE_PKCS12_ITG_MODE	itgMode;
} XE_PKCS12_PFX;

// shkey

typedef struct {
	int		pbeID;
	BIN		*privKeyInfo;				// der
} XE_PKCS12_SHKEY;

// params 

typedef struct _XE_PKCS12_USERDATA {
	BIN userPrivKeyInfo;
	BIN userCert;
	struct _XE_PKCS12_USERDATA *next;	
} XE_PKCS12_USERDATA;

typedef struct _XE_PKCS12_PARAM {
	XE_PKCS12_USERDATA userData;
	XE_BIN_LIST caList;
	XE_BIN_LIST crlList;
} XE_PKCS12_PARAM;

/**
 *	Error codes
 */

#define	ERR_PKCS12							(ERR_PKCS + 700)

#define	PKCS12_ERR_INVALID_INPUT			(ERR_PKCS12 + 1)
#define	PKCS12_ERR_INTERNAL					(ERR_PKCS12 + 2)
#define	PKCS12_ERR_MALLOC_FAILED			(ERR_PKCS12 + 3)

#define	PKCS12_ERR_UNKNOWN_BAGID			(ERR_PKCS12 + 10)
#define	PKCS12_ERR_UNKNOWN_PVCID			(ERR_PKCS12 + 11)
#define	PKCS12_ERR_UNKNOWN_ITGID			(ERR_PKCS12 + 12)
#define	PKCS12_ERR_UNKNOWN_ENCID			(ERR_PKCS12 + 13)
#define	PKCS12_ERR_UNKNOWN_PBEID			(ERR_PKCS12 + 14)
#define	PKCS12_ERR_UNKNOWN_TYPEID			(ERR_PKCS12 + 15)
#define	PKCS12_ERR_UNKNOWN_VERSION			(ERR_PKCS12 + 18)

#define	PKCS12_ERR_MISMATCH_PVCID			(ERR_PKCS12 + 16)
#define	PKCS12_ERR_MISMATCH_ITGID			(ERR_PKCS12 + 17)

#define	PKCS12_ERR_BAD_KEY					(ERR_PKCS12 + 30)
#define	PKCS12_ERR_BAD_SHKEY				(ERR_PKCS12 + 31)
#define	PKCS12_ERR_BAD_CERT					(ERR_PKCS12 + 32)
#define	PKCS12_ERR_BAD_CRL					(ERR_PKCS12 + 33)
#define	PKCS12_ERR_BAD_PFX					(ERR_PKCS12 + 34)
#define	PKCS12_ERR_BAD_ENCRYPTED_DATA		(ERR_PKCS12 + 37)
#define	PKCS12_ERR_BAD_ENVELOPED_DATA		(ERR_PKCS12 + 38)
#define	PKCS12_ERR_BAD_SIGNED_DATA			(ERR_PKCS12 + 39)
#define	PKCS12_ERR_BAD_MAC_DATA				(ERR_PKCS12 + 40)
#define	PKCS12_ERR_BAD_ALGPARAM				(ERR_PKCS12 + 41)

#define	PKCS12_ERR_INVALID_MAC				(ERR_PKCS12 + 50)
#define	PKCS12_ERR_INVALID_SIGNATURE		(ERR_PKCS12 + 51)
#define	PKCS12_ERR_INVALID_PASSWORD			(ERR_PKCS12 + 52)

#define	PKCS12_ERR_NO_BAG					(ERR_PKCS12 + 60)
#define	PKCS12_ERR_NO_PRIVKEY				(ERR_PKCS12 + 61)
#define	PKCS12_ERR_NO_CERT					(ERR_PKCS12 + 62)

/**
 *	Prototypes
 */

#ifdef  __cplusplus
extern "C" {
#endif

// pfx

XFA_EXPORT_TYPE 
int		XFA_PKCS12_EncodePFX				(BIN *pkcs12,
											 const int pbeID,
											 const BIN *userPrivKeyInfo,	// privKeyInfo or shkey
											 const BIN *userCert,			// optional
											 const BIN *caCert,				// optional
											 const BIN *crl,				// optional
											 const BIN *passwd);

XFA_EXPORT_TYPE 
int		XFA_PKCS12_EncodePFXEx				(BIN *pkcs12,
											 const int pbeID,
											 const BIN *userPrivKeyInfo,	// privKeyInfo or shkey
											 const BIN *userCert,			// optional
											 const BIN *caCert,				// optional
											 const BIN *rootCert,			// optional
											 const BIN *crl,				// optional
											 const BIN *passwd,
											 const void *param);

XFA_EXPORT_TYPE 
int		XFA_PKCS12_DecodePFX				(int *pbeID,
											 BIN *userPrivKeyInfo,			// privKeyInfo or shkey
											 BIN *userCert,					// optional
											 BIN *caCert,					// optional
											 BIN *crl,						// optional
											 const BIN *pkcs12,
											 const BIN *passwd);

XFA_EXPORT_TYPE 
int		XFA_PKCS12_DecodePFXEx				(int *pbeID,
											 BIN *userPrivKeyInfo,			// privKeyInfo or shkey
											 BIN *userCert,					// optional
											 BIN *caCert,					// optional
											 BIN *rootCert,					// optional
											 BIN *crl,						// optional
											 const BIN *pkcs12,
											 const BIN *passwd,
											 const void *param);

XFA_EXPORT_TYPE 
int		XFA_PKCS12_IsPFX					(const BIN *pkcs12);

// param

XFA_EXPORT_TYPE 
void	XFA_PKCS12_ResetParam				(XE_PKCS12_PARAM *pParam);

XFA_EXPORT_TYPE 
XE_PKCS12_USERDATA *
		XFA_PKCS12_UserData_New				(void);

XFA_EXPORT_TYPE 
void	XFA_PKCS12_UserData_Reset			(XE_PKCS12_USERDATA *userData);

XFA_EXPORT_TYPE 
void	XFA_PKCS12_UserData_Free			(XE_PKCS12_USERDATA *userData);

// shkey

XFA_EXPORT_TYPE 
int		XFA_PKCS12_EncodeSHKey				(BIN *shkey,
											 const int pbeID,
											 const BIN *privKeyInfo,
											 const BIN *passwd);

XFA_EXPORT_TYPE 
int		XFA_PKCS12_DecodeSHKey				(int *pbeID,
											 BIN *privKeyInfo,
											 const BIN *shkey,
											 const BIN *passwd);

XFA_EXPORT_TYPE 
int		XFA_PKCS12_IsSHKey					(const BIN *shkey);

// version

XFA_EXPORT_TYPE 
char *	XFA_PKCS12_GetVersion				(void);

XFA_EXPORT_TYPE 
int		XFA_PKCS12_CheckVersion				(const char *version);			// optional

// error

XFA_EXPORT_TYPE 
char *	XFA_PKCS12_GetErrorReason			(const int code, 
											 const int locale);

// for advanced user {{

// attribs

XFA_EXPORT_TYPE 
XE_PKCS12_ATTRIBS *
		XFA_PKCS12_Attribs_New				(void);

XFA_EXPORT_TYPE 
void	XFA_PKCS12_Attribs_Reset			(XE_PKCS12_ATTRIBS *bagAttribs);

XFA_EXPORT_TYPE 
void	XFA_PKCS12_Attribs_Free				(XE_PKCS12_ATTRIBS *bagAttribs);

// bag

XFA_EXPORT_TYPE 
XE_PKCS12_BAG *
		XFA_PKCS12_Bag_New					(void);

XFA_EXPORT_TYPE 
void	XFA_PKCS12_Bag_Reset				(XE_PKCS12_BAG *bag);

XFA_EXPORT_TYPE 
void	XFA_PKCS12_Bag_Free					(XE_PKCS12_BAG *bag);

// bagSet

XFA_EXPORT_TYPE 
XE_PKCS12_BAG_SET *
		XFA_PKCS12_BagSet_New				(void);

XFA_EXPORT_TYPE 
void	XFA_PKCS12_BagSet_Reset				(XE_PKCS12_BAG_SET *bagSet);

XFA_EXPORT_TYPE 
void	XFA_PKCS12_BagSet_Free				(XE_PKCS12_BAG_SET *bagSet);

XFA_EXPORT_TYPE 
int		XFA_PKCS12_BagSet_Add				(XE_PKCS12_BAG_SET **bagSet,			// in/out
											 const XE_PKCS12_BAG *bag);

XFA_EXPORT_TYPE 
XE_PKCS12_BAG *
		XFA_PKCS12_BagSet_Get				(const XE_PKCS12_BAG_SET *bagSet,
											 const int bagID,
											 const BIN *localKeyId);				// optional

XE_PKCS12_BAG *
XFA_PKCS12_BagSet_GetEx						(const XE_PKCS12_BAG_SET *bagSet,
											 const XE_PKCS12_BAG 		*pStartingBag,
											 const int bagID,
											 const BIN *localKeyId);			// optional

// pfx

XFA_EXPORT_TYPE 
XE_PKCS12_PFX *
		XFA_PKCS12_PFX_New					(void);

XFA_EXPORT_TYPE 
void	XFA_PKCS12_PFX_Reset				(XE_PKCS12_PFX *pfx);

XFA_EXPORT_TYPE 
void	XFA_PKCS12_PFX_Free					(XE_PKCS12_PFX *pfx);

XFA_EXPORT_TYPE 
int		XFA_PKCS12_PFX_Add					(XE_PKCS12_PFX *pfx,					// in/out
											 const XE_PKCS12_BAG_SET *bagSet,
											 const XE_PKCS12_PVC_MODE *pvcMode);

XFA_EXPORT_TYPE 
int		XFA_PKCS12_PFX_Encode				(BIN *output,
											 const XE_PKCS12_PFX *pfx,
											 const XE_PKCS12_ITG_MODE *itgMode);

XFA_EXPORT_TYPE 
int		XFA_PKCS12_PFX_Decode				(XE_PKCS12_PFX *pfx,
											 const BIN *input,
											 const XE_PKCS12_PVC_MODE *pvcMode,
											 const XE_PKCS12_ITG_MODE *itgMode);

// shkey

XFA_EXPORT_TYPE 
XE_PKCS12_SHKEY *
		XFA_PKCS12_SHKey_New				(void);

XFA_EXPORT_TYPE 
void	XFA_PKCS12_SHKey_Reset				(XE_PKCS12_SHKEY *shKey);

XFA_EXPORT_TYPE 
void	XFA_PKCS12_SHKey_Free				(XE_PKCS12_SHKEY *shKey);

XFA_EXPORT_TYPE 
int		XFA_PKCS12_SHKey_Encode				(BIN *output,
											 const XE_PKCS12_SHKEY *shKey,
											 const BIN *passwd);

XFA_EXPORT_TYPE 
int		XFA_PKCS12_SHKey_Decode				(XE_PKCS12_SHKEY *shKey,
											 const BIN *input,
											 const BIN *passwd);

// }}

#ifdef  __cplusplus
}
#endif

#endif
