#ifndef _SUITE_ST_H_
#endif  _SUITE_ST_H_

#include "exp_global.h"
#include "suite_io.h"

/**
 * Constants 
 */

// Security Token Type 
#define XE_ST_TOKENID_USB			1
#define XE_ST_TOKENID_SMARTCARD		2

//Type
#define XE_ST_TYPE_IP			1
#define XE_ST_TYPE_URL			2
#define XE_ST_TYPE_OTHER		3

// Hash Algorithm
#define	XE_ST_HASHID_MD2			1
#define	XE_ST_HASHID_MD5			2
#define	XE_ST_HASHID_SHA1			3
#define	XE_ST_HASHID_HAS160			5
#define XE_ST_HASHID_SHA256			7
#define XE_ST_HASHID_SHA384			8
#define XE_ST_HASHID_SHA512			9

// Algorithm
#define	XE_ST_ALGID_RSA			1
#define	XE_ST_ALGID_DSA			3
#define	XE_ST_ALGID_KCDSA		11

/**
 * Structs 
 */
typedef struct {
	char *dllName;
	int hashID;
	BIN dll;		
} XE_ST_SIGNTOKEN;

typedef struct _XE_ST_SIGNTOKEN_SET {
	XE_ST_SIGNTOKEN	 value;
	struct _XE_ST_SIGNTOKEN_SET *next;
} XE_ST_SIGNTOKEN_SET;

typedef struct {
	char *supportOS;	// OS version
	char *version;		// 보안토큰 구동프로그램 버전 정보
	char *location;		//IP address or URL
	int locationType; 	//1: IP address, 2: URL
	
	int type;			//1: USB, 2: smartcard
	
	char *cp;			// 보안토큰 제작업체 정보 
	int cpType;			// type
		
	char *info;			//optional
} XE_ST_DRIVERINFO;

typedef struct _XE_ST_DRIVERINFO_SET {
	XE_ST_DRIVERINFO value;
	struct _XE_ST_DRIVERINFO_SET *next;
} XE_ST_DRIVERINFO_SET;

typedef struct {
	char *tokenID;	
	XE_ST_DRIVERINFO_SET *driverInfo;
} XE_ST_TOKENDISTURL;

typedef struct _XE_ST_TOKENDISTURL_SET {
	XE_ST_TOKENDISTURL	 value;
	struct _XE_ST_TOKENDISTURL_SET *next;
} XE_ST_TOKENDISTURL_SET;

/** 
 * Error Codes
 */
#define ERR_ST 						(ERR_PRIMITIVE * 45)
#define ST_ERR_INVALID_INPUT		(ERR_ST + 1)
#define	ST_ERR_MALLOC_FAILED		(ERR_ST + 3)

#define	ST_ERR_UNKNOWN_TOKENID		(ERR_ST + 10)
#define	ST_ERR_UNKNOWN_HASHID		(ERR_ST + 11)
#define	ST_ERR_UNKNOWN_ALGID		(ERR_ST + 12)
#define ST_ERR_UNKNOWN_DLLNAME		(ERR_ST + 13)
#define ST_ERR_UNKNOWN_LOCATION		(ERR_ST + 14)
#define ST_ERR_UNKNOWN_OS			(ERR_ST + 15)
#define ST_ERR_UNKNOWN_VERSION		(ERR_ST + 16)

#define ST_ERR_INVALID_SIGNATURE	(ERR_ST + 15)
#define ST_ERR_INVALID_DRIVERNAME	(ERR_ST + 16)
#define ST_ERR_INVALID_HASH			(ERR_ST + 17)

#define ST_ERR_ENCODE_ASN			(ERR_ST + 20)
#define ST_ERR_DECODE_ASN			(ERR_ST + 21)

#define ST_ERR_BAD_CERT				(ERR_ST + 30)
#define ST_ERR_BAD_SIGNTOKEN		(ERR_ST + 31)
#define ST_ERR_BAD_TOKENDISTURL		(ERR_ST + 32)
#define ST_ERR_BAD_SIGNATUREVALUE	(ERR_ST + 33)

#define ST_ERR_MISMATCH_ISSUER		(ERR_ST + 35)
#define ST_ERR_MISMATCH_SERIALNUM	(ERR_ST + 36)

#ifdef  __cplusplus
extern "C" {
#endif

XFA_EXPORT_TYPE
int		
XFA_ST_EncodeSignToken_ToBeSigned(BIN *toBeSigned,
								 const XE_ST_SIGNTOKEN_SET *signTokenSet);

XFA_EXPORT_TYPE
int		
XFA_ST_EncodeSignToken_SignValue(BIN *signValue,
								 const int hashID,
								 const BIN *signCert,
								 const BIN *signature,
								 const BIN *toBeSigned);

XFA_EXPORT_TYPE
int		
XFA_ST_VerifySignToken_SignValue(const XE_ST_SIGNTOKEN_SET *signTokenSet,	//in
								 const BIN *signValue,					//in
								 const BIN *signCert);					//in

XFA_EXPORT_TYPE
XE_ST_SIGNTOKEN_SET *
XFA_ST_SignTokenSet_New(void);

XFA_EXPORT_TYPE
void	
XFA_ST_SignToken_Reset(XE_ST_SIGNTOKEN *signToken);

XFA_EXPORT_TYPE
void
XFA_ST_SignTokenSet_Reset(XE_ST_SIGNTOKEN_SET *signTokenSet);

XFA_EXPORT_TYPE
void	
XFA_ST_SignTokenSet_Free(XE_ST_SIGNTOKEN_SET *signTokenSet);

XFA_EXPORT_TYPE
int		
XFA_ST_SignTokenSet_Add(XE_ST_SIGNTOKEN_SET **signTokenSet,
								const XE_ST_SIGNTOKEN *signToken);

XFA_EXPORT_TYPE
int		
XFA_ST_EncodeTokenDistURL_ToBeSigned(BIN *toBeSigned,
								 const XE_ST_TOKENDISTURL_SET *tokenDistUrlSet);

XFA_EXPORT_TYPE
int		
XFA_ST_EncodeTokenDistURL_SignValue(BIN *signValue,
								 const int hashID,
								 const BIN *signCert,
								 const BIN *signature,
								 const BIN *toBeSigned);

XFA_EXPORT_TYPE
int		
XFA_ST_DecodeTokenDistURL_SignValue(XE_ST_TOKENDISTURL_SET **tokenDistUrlSet,	//in,out
								 int *hashID,							//out
								 const BIN *signValue,					//in
								 const BIN *signCert);					//in

XFA_EXPORT_TYPE
XE_ST_TOKENDISTURL_SET *
XFA_ST_TokenDistURLSet_New(void);

XFA_EXPORT_TYPE
void	
XFA_ST_TokenDistURL_Reset(XE_ST_TOKENDISTURL *tokenDistUrl);

XFA_EXPORT_TYPE
void	
XFA_ST_TokenDistURLSet_Reset(XE_ST_TOKENDISTURL_SET *tokenDistUrlSet);

XFA_EXPORT_TYPE
void	
XFA_ST_TokenDistURLSet_Free(XE_ST_TOKENDISTURL_SET *tokenDistUrlSet);

XFA_EXPORT_TYPE
int		
XFA_ST_TokenDistURLSet_Add(XE_ST_TOKENDISTURL_SET **tokenDistUrlSet,
								   const XE_ST_TOKENDISTURL *tokenDistUrl);

XFA_EXPORT_TYPE
XE_ST_DRIVERINFO_SET *
XFA_ST_DriverInfoSet_New(void);

XFA_EXPORT_TYPE
void	
XFA_ST_DriverInfo_Reset(XE_ST_DRIVERINFO *driverInfo);

XFA_EXPORT_TYPE
void	
XFA_ST_DriverInfoSet_Reset(XE_ST_DRIVERINFO_SET *driverInfoSet);

XFA_EXPORT_TYPE
void	
XFA_ST_DriverInfoSet_Free(XE_ST_DRIVERINFO_SET *driverInfoSet);

XFA_EXPORT_TYPE
int		
XFA_ST_DriverInfoSet_Add(XE_ST_DRIVERINFO_SET **driverInfoSet,
								   const XE_ST_DRIVERINFO *driverInfo);

XFA_EXPORT_TYPE	
char *	XFA_ST_GetVersion					(void);

XFA_EXPORT_TYPE 
char *	
XFA_ST_GetErrorReason			(const int code);

#ifdef  __cplusplus
}
#endif

