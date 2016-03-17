//
//	$Id: suite_tsp.h,v 1.7 2005-07-13 06:07:08 scian Exp $
//

#ifndef _SUITE_TSP_H_
#define _SUITE_TSP_H_

#include <time.h>

#include "exp_global.h"

/**
 *	Constants
 */

// hashID

#define	XE_TSP_HASHID_MD5					1
#define	XE_TSP_HASHID_SHA1					2
#define	XE_TSP_HASHID_SHA256				3
#define	XE_TSP_HASHID_SHA384				4
#define	XE_TSP_HASHID_SHA512				5

// signID

#define	XE_TSP_SIGNID_RSA_V15_SHA1			1
#define	XE_TSP_SIGNID_RSA_V15_SHA256		2
#define	XE_TSP_SIGNID_RSA_V15_SHA384		3
#define	XE_TSP_SIGNID_RSA_V15_SHA512		4

/**
 *	Struct
 */

typedef struct {
	struct {
		int		hashID;
		BIN		hash;
	} message;
	
	int		nonceExist;				// true(1), or false(0)
	int		nonce;					// integer
	int		certReq;				// true(1), or false(0)
	
	struct {
		char	userid[64], passwd[64];	// optional
	} exts;
} XE_TSP_TSRequest;

typedef struct {
	struct {
		int		hashID;
		BIN		hash;
	} message;

	time_t	genTime;
	int		accuracyExist;			// true(1), or false(0)
	struct {
		int		seconds;
		int		millis;
		int		micros;
	} accuracy;

	int		nonceExist;				// true(1), or false(0)
	int		nonce;
} XE_TSP_TSTInfo;

// client

typedef struct {
	int		 digestID;				// optional
	BIN		*tsaCert;				// optional
} XE_TSP_ClientParam;

// server

typedef struct {
	// tsa {{
	BIN		*tsaPrivKey;			// optional
	int		(*CB_ComputeSignature)			(BIN *signature, const BIN *message, 
											 const int signID);			// optional
	BIN		*tsaCert;
	// }}
} XE_TSP_ServerParam;

typedef struct {
	// stamp
	int		(*CB_Stamp_Start)				(int *sessionID);

	int		(*CB_Stamp_Process)				(BIN *serialNum, 
											 const int sessionID,
											 const BIN *request);
	
	int		(*CB_Stamp_End)					(const int sessionID,
											 const int success,			// true (1), false (0)
											 const BIN *response);
} XE_TSP_ServerCB;

/**
 *	Error codes
 */

#define	TSP_ERR_INVALID_INPUT				(ERR_TSP + 1)
#define	TSP_ERR_INTERNAL					(ERR_TSP + 2)
#define	TSP_ERR_MALLOC_FAILED				(ERR_TSP + 3)

#define	TSP_ERR_UNKNOWN_HASHID				(ERR_TSP + 10)
#define	TSP_ERR_UNKNOWN_SIGNID				(ERR_TSP + 11)

#define	TSP_ERR_BAD_REQUEST					(ERR_TSP + 30)
#define	TSP_ERR_BAD_RESPONSE				(ERR_TSP + 31)
#define	TSP_ERR_BAD_SIGNED_DATA				(ERR_TSP + 32)
#define	TSP_ERR_BAD_TSTINFO					(ERR_TSP + 33)
#define	TSP_ERR_BAD_CERT					(ERR_TSP + 34)

#define	TSP_ERR_INVALID_SIGNATURE			(ERR_TSP + 50)
#define	TSP_ERR_INVALID_CONTENT_TYPE		(ERR_TSP + 51)
#define	TSP_ERR_INVALID_MSG_HASH			(ERR_TSP + 52)
#define	TSP_ERR_INVALID_NONCE				(ERR_TSP + 53)

#define	TSP_ERR_NO_TSTOKEN					(ERR_TSP + 60)
#define	TSP_ERR_NO_CONTENT					(ERR_TSP + 61)
#define	TSP_ERR_NO_CERT						(ERR_TSP + 62)
#define	TSP_ERR_NO_PRIVKEY					(ERR_TSP + 63)

#define	TSP_ERR_REJECTED					(ERR_TSP + 80)
#define	TSP_ERR_REJECTED_BAD_ALG			(ERR_TSP + 81)
#define	TSP_ERR_REJECTED_BAD_REQUEST		(ERR_TSP + 82)
#define	TSP_ERR_REJECTED_BAD_DATA_FORMAT	(ERR_TSP + 83)
#define	TSP_ERR_REJECTED_TIME_NOT_AVAILABLE	(ERR_TSP + 84)
#define	TSP_ERR_REJECTED_UNACCEPTED_POLICY	(ERR_TSP + 85)

#define	TSP_ERR_CB_COMPUTESIGNATURE			(ERR_TSP + 100)
#define	TSP_ERR_CB_STAMP_START				(ERR_TSP + 101)
#define	TSP_ERR_CB_STAMP_PROCESS			(ERR_TSP + 102)
#define	TSP_ERR_CB_STAMP_END				(ERR_TSP + 103)

#define	TSP_ERR_SOCKET_READ_FAILED			(ERR_TSP + 120)
#define	TSP_ERR_SOCKET_WRITE_FAILED			(ERR_TSP + 121)

/**
 *	Prototypes
 */

#ifdef  __cplusplus
extern "C" {
#endif

// request

XFA_EXPORT_TYPE
int		XFA_TSP_EncodeRequest				(BIN *request,
											 const XE_TSP_TSRequest *tsRequest);

XFA_EXPORT_TYPE
int		XFA_TSP_DecodeRequest				(XE_TSP_TSRequest *tsRequest,
											 const BIN *request);

// response

XFA_EXPORT_TYPE
XE_TSP_TSTInfo *
		XFA_TSP_TSTInfo_New					(void);

XFA_EXPORT_TYPE
void	XFA_TSP_TSTInfo_Reset				(XE_TSP_TSTInfo *tstInfo);

XFA_EXPORT_TYPE
void	XFA_TSP_TSTInfo_Free				(XE_TSP_TSTInfo *tstInfo);

XFA_EXPORT_TYPE
int		XFA_TSP_EncodeResponse				(BIN *response,
											 const BIN *request,
											 const BIN *serialNum,
											 const BIN *tsaCert,
											 const BIN *tsaPrivKey);

XFA_EXPORT_TYPE
int		XFA_TSP_EncodeResponse_Init			(BIN *eTstInfo,
											 BIN *toBeSignedData,
											 const BIN *request,
											 const BIN *serialNum,
											 const BIN *tsaCert);

XFA_EXPORT_TYPE
int		XFA_TSP_EncodeResponse_Final		(BIN *response,
											 const BIN *request,
											 const BIN *eTstInfo,
											 const BIN *toBeSignedData,
											 const BIN *signature,
											 const BIN *tsaCert);

XFA_EXPORT_TYPE
int		XFA_TSP_DecodeResponse				(XE_TSP_TSTInfo *tstInfo,
											 BIN *signerCert,
											 const BIN *response,
											 const BIN *request,			// optional
											 const BIN *tsaCert);			// optional

XFA_EXPORT_TYPE
int		XFA_TSP_DecodeResponseEx			(XE_TSP_TSTInfo *tstInfo,
											 BIN *signerCert,
											 BIN *timeStampToken,
											 const BIN *response,
											 const BIN *request,			// optional
											 const BIN *tsaCert,			// optional
											 const void *param);
// client

XFA_EXPORT_TYPE
int		XFA_TSP_Client						(XE_TSP_TSTInfo *tstInfo,
											 BIN *request,
											 BIN *response,
											 BIN *signerCert,
											 const int socket,
											 const BIN *message,
											 const XE_TSP_ClientParam *clntParam);

// server

XFA_EXPORT_TYPE
int		XFA_TSP_Server						(const int socket,
											 const XE_TSP_ServerParam *srvrParam,
											 const XE_TSP_ServerCB *srvrCB);

// version

XFA_EXPORT_TYPE
char *	XFA_TSP_GetVersion					(void);

XFA_EXPORT_TYPE
int		XFA_TSP_CheckVersion				(const char *version);			// optional

// error

XFA_EXPORT_TYPE
char *	XFA_TSP_GetErrorReason				(const int code, 
											 const int locale);

#ifdef  __cplusplus
}
#endif

#endif
