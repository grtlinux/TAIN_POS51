    //
//	$Id: suite_cmp.h,v 1.27 2008-11-03 08:05:34 crypto Exp $
//

#ifndef _SUITE_CMP_H_
#define _SUITE_CMP_H_

#include "suite_io.h"

/**
 *	Constants
 */

// opID
#define	XE_CMP_OPID_REQUEST					1
#define XE_CMP_OPID_KRR_SIGNGATE			2
#define	XE_CMP_OPID_UPDATE					3
#define	XE_CMP_OPID_REVOKE					5
#define	XE_CMP_OPID_RECOVER					7
#define	XE_CMP_OPID_POLICY					9

// sub opID - for signgate
#define XE_CMP_SUBOPID_KRR					1

// pkeyID
#define	XE_CMP_PKEYID_RSA					1
//	#define	XE_CMP_PKEYID_DSA				3
#define	XE_CMP_PKEYID_KCDSA					5
//	#define	XE_CMP_PKEYID_ECDSA				7
//	#define	XE_CMP_PKEYID_ECKCDSA			9
#define XE_CMP_PKEYID_RSA_SIGNGATE			11
#define XE_CMP_PKEYID_RSA_2048				12
#define XE_CMP_PKEYID_KCDSA_2048			13

// caTypeID
#define	XE_CMP_CATYPEID_XECURECA			1
#define	XE_CMP_CATYPEID_YESSIGNCA			2
#define	XE_CMP_CATYPEID_GPKIRA				5

//added by jhkim at 24/05/2006
#define XE_CMP_CATYPEID_SIGNGATE			6
#define XE_CMP_CATYPEID_SIGNKOREA	        7
#define XE_CMP_CATYPEID_CROSSCERT			8

// status
#define	XE_CMP_STATUS_GRANTED				0
#define	XE_CMP_STATUS_REJECTION				2

// reason
#define	XE_CMP_REASON_keyCompromise			1
#define	XE_CMP_REASON_cACompromise			2
#define	XE_CMP_REASON_affiliationChanged	3
#define	XE_CMP_REASON_superseded			4
#define	XE_CMP_REASON_cessationOfOperation	5
#define	XE_CMP_REASON_certificateHold		6

// for private key callback {{
// signID
#define	XE_CMP_SIGNID_RSA_V15_SHA1			1
//#define	XE_CMP_SIGNID_DSA_SHA1				3
#define	XE_CMP_SIGNID_KCDSA_SHA1			5	// for GPKIRA
#define	XE_CMP_SIGNID_KCDSA_HAS160			6
#define XE_CMP_SIGNID_RSA_V15_SHA256		7
#define XE_CMP_SIGNID_RSA_V15_SHA384		8
#define XE_CMP_SIGNID_RSA_V15_SHA512		9
#define XE_CMP_SIGNID_KCDSA_SHA256			10
#define XE_CMP_SIGNID_KCDSA_SHA384			11
#define XE_CMP_SIGNID_KCDSA_SHA512			12

// pencID
#define	XE_CMP_PENCID_RSA_V15				1
#define XE_CMP_PENCID_RSA_OAEP				5	// for GPKIRA
// privKeyID
#define	XE_CMP_PRIVKEYID_NEW				1
#define	XE_CMP_PRIVKEYID_OLD				2
// }}

/**
 *	Struct
 */
typedef struct _XE_CMP_KeyPair {
	BIN		*cert;					// der
	BIN		*privKey;				// der
	struct _XE_CMP_KeyPair	*next;	// optional
} XE_CMP_KeyPair;

// client
typedef struct {
	int		pkeyID;
	BIN		*pkeyParam;				// optional
} XE_CMP_PKEYID;

typedef struct {
	struct {
		// sign {{
		int		pkeyID;
		BIN		*cert;				// der
		BIN		*privKey;			// der, optional
		BIN		*pkeyParam;			// der, optional
		// }}
		// vid {{
		BIN		*vidRandom;			// optional
		// }}
		// km {{
		int		kmPkeyID;
		BIN		*kmCert;			// der, optional
		BIN		*kmPrivKey;			// der, optional
		BIN		*kmPkeyParam;		// der, optional
		// }}
		// ca {{
		char	*policy;
		BIN		*caCert;			// der
		BIN		*rootCert;			// der
		BIN		*caKmCert;			// der
		// }}
	} request;
	
	struct {
		// sign {{
		int		newPkeyID;
		BIN		*newCert;			// der
		BIN		*newPrivKey;		// der, optional
		BIN		*newPkeyParam;		// der, optional
		// }}
		// vid {{
		BIN		*vidRandom;			// optional
		// }}
		// km {{
		int		newKmPkeyID;
		BIN		*newKmCert;			// der, optional
		BIN		*newKmPrivKey;		// der, optional
		BIN		*newKmPkeyParam;	// der, optional
		// }}
		// ca {{
		char	*policy;
		BIN		*caCert;			// der
		BIN		*rootCert;			// der
		BIN		*caKmCert;			// der
		// }}
	} update;

	struct {
		// sign - for only signgate {{
		BIN		*cert;				// der
		BIN		*privKey;			// der, optional
		// }}
		
		// vid {{
		BIN		*vidRandom;			// optional
		// }}
		
		// km - for only signgate {{
		BIN		*kmCert;			// der, optional
		BIN		*kmPrivKey;			// der, optional
		// }}
		
		// ca {{
		char	*policy;
		BIN		*caCert;			// der
		BIN		*rootCert;			// der
		BIN		*caKmCert;			// der
		// }}

		// km {{
		XE_CMP_KeyPair	*kmKeyPairs;
		// }}
	} recover;

	struct {
		BIN		*keyPols;			// der, (for GPKIRA)
	} policy;

	struct {
		// sign {{
		int		status;				// granted (0), rejection (2)
		char	*string;
		// }}
		// km {{
		int		kmStatus;			// granted (0), rejection (2)
		char	*kmString;
		// }}
	} error;
} XE_CMP_OperationResult;

typedef struct {
	struct {
		char	*refNum;
		char	*authCode;
		char	*classId;			// optional (for XecureCA)
		// sign {{
		int		pkeyID;
		BIN		*pubKey;			// der, optional
		BIN		*privKey;			// der, optional if callback or popSign is provided
		BIN		*pkeyParam;			// der, optional
		BIN		*popSign;			// optional if privKey or callback is provied
		// }}
		// vid {{
		char	*vidIDN;			// optional (for GPKIRA)
		BIN		*vidRandom;			// optional
		// }}
		// hsm {{
		int		useHsm;
		// }}
		// km {{
		int		requestKmCert;		// true (1), false (0)
		int		cagenKmKey;			// true (1), false (0)
		int		backupKmKey;		// true (1), false (0)
		int		kmPkeyID;			// optional
		BIN		*kmPubKey;			// der, optional
		BIN		*kmPrivKey;			// der, optional
		BIN		*kmPkeyParam;		// der, optional
		// }}
		BIN		*keyPols;			// der, optional (for GPKIRA)
		BIN		*caCert;			// der, optional (for GPKIRA) (raCert if GPKIRA)
		BIN		*caKmCert;			// der, optional (for GPKIRA) (caCert if GPKIRA)
	} request;
	
	struct {
		// sign {{
		// new
		int		newPkeyID;
		BIN		*newPubKey;			// der, optional
		BIN		*newPrivKey;		// der, optional if callback or popSign is provided
		BIN		*newPkeyParam;		// der, optional
		BIN		*popSign;			// optional if newPrivKey or callback is provided
		// old
		BIN		*oldCert;			// der
		BIN		*oldPrivKey;		// der, optional if callback is provided
		// }}
		// vid {{
		char	*vidIDN;			// optional (for GPKIRA)
		BIN		*vidRandom;			// optional
		// }}
		// hsm {{
		int		useHsm;
		// }}
		// km {{
		int		updateKmCert;		// true (1), false (0)
		int		cagenKmKey;			// true (1), false (0)
		int		backupKmKey;		// true (1), false (0)
		// new
		int		newKmPkeyID;		// optional
		BIN		*newKmPubKey;		// der, optional
		BIN		*newKmPrivKey;		// der, optional
		BIN		*newKmPkeyParam;	// der, optional
		// old
		BIN		*oldKmCert;			// der, optional
		// }}
		BIN		*caCert;			// der, optional (for XecureCA, GPKIRA)	(raCert if GPKIRA)
		BIN		*caKmCert;			// der, optional (for GPKIRA)			(caCert if GPKIRA)
	} update;
	
	struct {
		// sign {{
		BIN		*cert;				// der
		BIN		*privKey;			// der, optional if callback is provided
		int		reason;
		// }}
		// km {{
		int		revokeKmCert;		// true (1), false (0)
		BIN		*kmCert;			// der, optional
		int		kmReason;
		// }}
		BIN		*caCert;			// der, optional (for XecureCA)
	} revoke;

	struct {
		char	*refNum;
		char	*authCode;
	} recover;

	struct {
		char	*refNum;
		char	*authCode;
		BIN		*caCert;			// der, (raCert if GPKIRA)
	} policy;						// (for GPKIRA)
} XE_CMP_OperationParam;

typedef struct {
	int		caTypeID;				// XecureCA, YessignCA, GPKIRA

	// #39 [2010/04/01 by hjkim] {{
	BIN		*p11signkID;
	int		*phSignPubKey;
	int		*phSignPrivKey;
	BIN		*p11kmkID;
	int		*phKmPubKey;
	int		*phKmPrivKey;
	// }}

	// #35 [2010/05/27 by hongma] for yessign 인증서 부정발급 방지. {{
	int		requestUserEnvInfo;	// true (1), false (0)
	BIN		*userEnvInfo;		// optional
	// }}

	// #45 [2010/10/12 by hongma] for Yessign
	/* 0: HDD, 1:FILE, 2:ICCARD, 3:CSP, 4:VSC, 5:USBTOKEN, 6:USBTOKEN_KOOKMIN, 7:USBTOKEN_KIUP, 8:PKCS11, 9:MPHONE*/
	int		nMedia;
	// }

	// {{
	// sign
	int		(*CB_ComputeSignature)			(BIN *signature, const BIN *message, 
											 const int signID, const int privKeyID);	// optional
	// km
	int		(*CB_PrivateDecrypt)			(BIN *plaintext, const BIN *ciphertext, 
											 const int pencID, const int null);		// optional
	// }}

	// #39 [2010/04/01 by hjkim] {{
	int		(*CB_GenerateKeyPair)			(BIN *privKey,
											BIN *pubKey,
											BIN *pkeyParam,				// optional
											BIN *p11kID,
											int *phPubKey,
											int *phPrivKey,
											const int caTypeID,
											const int policyKeySize,
											const XE_CMP_PKEYID *pPkeyIds,
											const int pkeyID,
											const BIN *inPkeyParam,		// optional (for GPKIRA)
											const int keyBitLength,		// optional (for GPKIRA)
											const int isSignKey);
	// }}
} XE_CMP_ClientParam;

// server
typedef struct {
	int		caTypeID;				// XecureCA, YessignCA, GPKIRA

	// usr {{
	XE_CMP_PKEYID	pkeyIds[4];		// RSA, KCDSA
	// }}
	
	// ca {{
	// sign
	BIN		*caCert;				// optional
	BIN		*caPrivKey;				// optional
	BIN		*rootCert;				// optional
	int		(*CB_GetCertificate)			(BIN *caCert, BIN *caPrivKey, 
											 BIN *rootCert, const int pkeyID);		// optional (only for XecureCA)
	int		(*CB_ComputeSignature)			(BIN *signature, const BIN *message, 
											 const int signID, const int null);		// optional
	// km
	BIN		*caKmCert;
	BIN		*caKmPrivKey;			// optional
	BIN		*rootKmCert;			// optional
	int		(*CB_PrivateDecrypt)			(BIN *plaintext, const BIN *ciphertext, 
											 const int pencID, const int null);		// optional
	// }}
	
	// error
	int		locale;					// LOCALE_ENG, LOCALE_HAN
	char	*(*CB_GetErrorString)			(const int errorID,
											 const int locale);						// optional
} XE_CMP_ServerParam;

typedef struct {
	// request
	int		(*CB_Request_Start)				(int *sessionID,
											 char authCode[128], 
											 char **policy,
											 const char refNum[128],
											 const char classId[5]);	// optional (only for XecureCA)

	int		(*CB_Request_Process)			(BIN *cert, 
											 const int sessionID,
											 const int pkeyID,
											 const BIN *pubKey,
											 const BIN *pkeyParam,		// optional,
											 const char refNum[128],
											 const BIN *vidRandom,
											 const int bIsHsmCertReq,
											 const int requestKmCert);	// true (1), false (0)
	
	int		(*CB_Request_ProcessKm)			(BIN *kmCert,
											 BIN *kmPrivKey,			// optional
											 const int sessionID,
											 const int inKmPkeyID,		// optional
											 const BIN *inKmPubKey,		// optional
											 const BIN *inKmPrivKey,	// optional
											 const BIN *inKmPkeyParam);	// optional
	
	int		(*CB_Request_EndProcess)		(const int sessionID,
											 const int success);		

	int		(*CB_Request_End)				(const int sessionID,
											 const int success);		// true (1), false (0)

	// update
	int		(*CB_Update_Start)				(int *sessionID,
											 BIN *oldCert, 
											 char **policy,
											 const char oldSerial[128],
											 const BIN *caKeyHash);		// optional (only for XecureCA)
	
	int		(*CB_Update_Process)			(BIN *newCert, 
											 const int sessionID,
											 const int newPkeyID,
											 const BIN *newPubKey,
											 const BIN *newPkeyParam,	// optional
											 const BIN *oldSerialNum,
											 const BIN *vidRandom,
											 const int bIsHsmCertReq,
											 const int updateKmCert);	// true (1), false (0)
	
	int		(*CB_Update_ProcessKm)			(BIN *newKmCert,
											 BIN *newKmPrivKey,
											 const int sessionID,
											 const int inNewKmPkeyID,	// optional
											 const BIN *inNewKmPubKey,	// optional
											 const BIN *inNewKmPrivKey,	// optional
											 const BIN *inNewKmPkeyParam,	// optional
											 const BIN *oldKmSerialNum);
	
	int		(*CB_Update_EndProcess)			(const int sessionID,
											 const int success);

	int		(*CB_Update_End)				(const int sessionID,
											 const int success);		// true (1), false (0)

	// revoke
	int		(*CB_Revoke_Start)				(int *sessionID,
											 BIN *cert, 
											 const BIN *serialNum,
											 const BIN *caKeyHash);		// optional (only for XecureCA)
	
	int		(*CB_Revoke_Process)			(const int sessionID,
											 const BIN *serialNum,
											 const int reason,
											 const int revokeKmCert);	// true (1), false (0)
	
	int		(*CB_Revoke_ProcessKm)			(const int sessionID,
											 const BIN *kmSerialNum,
											 const int kmReason);
	
	int		(*CB_Revoke_EndProcess)			(const int sessionID,
											 const int success);

	int		(*CB_Revoke_End)				(const int sessionID,
											 const int success);		// true (1), false (0)

	// recover
	int		(*CB_Recover_Start)				(int *sessionID,
											 char authCode[128], 
											 const char refNum[128]);

	int		(*CB_Recover_ProcessKm)			(XE_CMP_KeyPair *kmKeyPairs,
											 const int sessionID);
	
	int		(*CB_Recover_EndProcess)		(const int sessionID,
											 const int success);
	
	int		(*CB_Recover_End)				(const int sessionID,
											 const int success);		// true (1), false (0)

	// debug
	int		(*CB_Debug_PrintMessage)		(const int msgID,
											 const BIN *msgData);
} XE_CMP_ServerCB;

// ctx
typedef struct {
	int		state;
	int		entity;					// client, server

	void	*tcpCtx;
	void	*cmpInfo;
	
	void	*clntArgs;
	void	*srvrArgs;

	int		opID;
	void	*opParam;
	void	*opResult;
	
	// client {{
	BIN		pubKey, privKey, pkeyParam;
	BIN		kmPubKey, kmPrivKey;
	BIN		protPubKey, protPrivKey;
	BIN		vidRandom;
	// }}

	/* added by jhkim 25/05/2006 - for signgate use making confirmation message */
	unsigned char symKey[8]; 

	// server {{
	char	authCode[128];
	char	*policy;
	BIN		cert, oldCert;
	BIN		kmCert;
	int		oldPkeyId;
	XE_CMP_KeyPair	kmKeyPairs;	// recover

	struct {
		int		sessionID;
		int		enableKrr;			// true (1), false (0);
		int		enableKm;			// true (1), false (0);
		int		res;				// return value of function
		int		success;			// true (1), false (0); true if operation was successful
		int		callback;			// true (1), false (0); true if callback was called
		int		enableEnd;			// true (1), false (0);
	} server;
	// }}
} XE_CMP_CTX;

/**
 *	Error codes
 */

#define CMP_ERR_INVALID_INPUT				(ERR_CMP + 1)
#define CMP_ERR_INTERNAL					(ERR_CMP + 2)
#define CMP_ERR_MALLOC_FAILED				(ERR_CMP + 3)

#define CMP_ERR_UNKNOWN_OPID				(ERR_CMP + 10)
#define	CMP_ERR_UNKNOWN_SIGNID				(ERR_CMP + 11)
#define	CMP_ERR_UNKNOWN_PKEYID				(ERR_CMP + 12)
#define	CMP_ERR_UNKNOWN_PENCID				(ERR_CMP + 13)
#define	CMP_ERR_UNKNOWN_SENCID				(ERR_CMP + 14)

#define	CMP_ERR_UNEXPECTED_PKIMSG			(ERR_CMP + 20)

#define CMP_ERR_CONTINUE					(ERR_CMP + 25)

#define CMP_ERR_BAD_PRIVKEY 				(ERR_CMP + 30)
#define CMP_ERR_BAD_PUBKEY					(ERR_CMP + 31)
#define CMP_ERR_BAD_CERT					(ERR_CMP + 32)
#define CMP_ERR_BAD_PKIMSG					(ERR_CMP + 33)
#define	CMP_ERR_BAD_ALG						(ERR_CMP + 34)
#define	CMP_ERR_BAD_POP						(ERR_CMP + 35)
#define	CMP_ERR_BAD_PROTECTION				(ERR_CMP + 36)
#define	CMP_ERR_BAD_REFNUM					(ERR_CMP + 40)
#define	CMP_ERR_BAD_SERIAL					(ERR_CMP + 41)
#define	CMP_ERR_BAD_CACLASS					(ERR_CMP + 42)
#define	CMP_ERR_BAD_POLICY					(ERR_CMP + 43)
// vid {{
#define	CMP_ERR_BAD_VID						(ERR_CMP + 44)
// }}
// km {{
#define	CMP_ERR_BAD_CERTID					(ERR_CMP + 45)
// }}
#define	CMP_ERR_BAD_KEYPOLICIES				(ERR_CMP + 46)
#define	CMP_ERR_NOT_UPDATE_PERIOD			(ERR_CMP + 47)

#define	CMP_ERR_INVALID_NONCE				(ERR_CMP + 50)
#define	CMP_ERR_INVALID_SIGNATURE			(ERR_CMP + 51)
#define	CMP_ERR_INVALID_MAC					(ERR_CMP + 52)
#define	CMP_ERR_INVALID_POP					(ERR_CMP + 53)
#define	CMP_ERR_INVALID_PROTECTION			(ERR_CMP + 54)
// vid {{
#define	CMP_ERR_INVALID_VID					(ERR_CMP + 55)
// }}
// km {{
#define	CMP_ERR_INVALID_KM_POP				(ERR_CMP + 56)
// }}

#define	CMP_ERR_NO_PRIVKEY					(ERR_CMP + 60)
#define	CMP_ERR_NO_PUBKEY					(ERR_CMP + 61)
#define	CMP_ERR_NO_PARAM					(ERR_CMP + 62)
#define	CMP_ERR_NO_CERT						(ERR_CMP + 63)
#define	CMP_ERR_NO_KID						(ERR_CMP + 64)
#define	CMP_ERR_NO_NONCE					(ERR_CMP + 65)
#define	CMP_ERR_NO_POP						(ERR_CMP + 66)
#define	CMP_ERR_NO_PROTECTION				(ERR_CMP + 67)
#define	CMP_ERR_NO_POLICY					(ERR_CMP + 68)
// vid {{
#define	CMP_ERR_NO_VID						(ERR_CMP + 69)
// }}
// km {{
#define	CMP_ERR_NO_KM_PRIVKEY				(ERR_CMP + 70)
#define	CMP_ERR_NO_KM_PUBKEY				(ERR_CMP + 71)
#define	CMP_ERR_NO_KM_CERT					(ERR_CMP + 72)
#define	CMP_ERR_NO_KM_POP					(ERR_CMP + 73)
#define	CMP_ERR_NO_PROTOENCRKEY				(ERR_CMP + 74)
// }}
#define	CMP_ERR_NO_OLDCERTID				(ERR_CMP + 75)
// {{
#define	CMP_ERR_NO_KEYPOLICIES				(ERR_CMP + 76)
// }}

#define	CMP_ERR_REJECTED					(ERR_CMP + 80)
#define CMP_ERR_RECEIVED_ERRORMSG			(ERR_CMP + 85)

#define	CMP_ERR_CB_COMPUTESIGNATURE			(ERR_CMP + 101)
// km {{
#define	CMP_ERR_CB_PRIVATEDECRYPT			(ERR_CMP + 102)
// }}
#define	CMP_ERR_CB_GETCERTIFICATE			(ERR_CMP + 103)
#define CMP_ERR_CB_GENERATEKEYPAIR			(ERR_CMP + 104)	// #39 [2010/04/01 by hjkim] 

// tcp {{
#define	CMP_ERR_TCP_BAD_MSG					(ERR_CMP + 110)
#define	CMP_ERR_TCP_BAD_LENGTH				(ERR_CMP + 111)
#define	CMP_ERR_TCP_BAD_VERSION				(ERR_CMP + 112)
#define	CMP_ERR_TCP_BAD_FLAG				(ERR_CMP + 113)
#define	CMP_ERR_TCP_BAD_TYPE				(ERR_CMP + 114)
// }}

#define CMP_ERR_SOCKET_READ_FAILED			(ERR_CMP + 120)
#define CMP_ERR_SOCKET_WRITE_FAILED 		(ERR_CMP + 121)

#define CMP_ERR_CERT_EXIST					(ERR_CMP + 150)
#define CMP_ERR_CERT_NOT_EXIST				(ERR_CMP + 151)
#define CMP_ERR_CERT_CANNOT_ISSUED	 		(ERR_CMP + 152)
#define CMP_ERR_CERT_REVOKED 				(ERR_CMP + 153)
#define CMP_ERR_KM_KEYPAIR_NOT_EXIST		(ERR_CMP + 154)
#define CMP_ERR_KM_CERT_PROCESS_NEEDED		(ERR_CMP + 155)

/**
 *	Prototypes
 */

#ifdef	__cplusplus
extern "C" {
#endif

// ctx

XFA_EXPORT_TYPE 
XE_CMP_CTX *
		XFA_CMP_CreateCTX					(void);

XFA_EXPORT_TYPE 
void	XFA_CMP_ResetCTX					(XE_CMP_CTX *ctx);

XFA_EXPORT_TYPE 
void	XFA_CMP_DestroyCTX					(XE_CMP_CTX *ctx);

// client

XFA_EXPORT_TYPE 
XE_CMP_OperationResult *
		XFA_CMP_OpResult_New				(void);

XFA_EXPORT_TYPE 
void	XFA_CMP_OpResult_Reset				(XE_CMP_OperationResult *opResult);

XFA_EXPORT_TYPE 
void	XFA_CMP_OpResult_Free				(XE_CMP_OperationResult *opResult);

XFA_EXPORT_TYPE 
int		XFA_CMP_Client_Init					(XE_CMP_CTX *ctx,
											 const int opID,
											 const XE_CMP_OperationParam *opParam,
											 const XE_CMP_ClientParam *clntParam);

XFA_EXPORT_TYPE 
int		XFA_CMP_Client_Update				(XE_CMP_CTX *ctx,
											 BIN *output,
											 const BIN *input);

XFA_EXPORT_TYPE 
int		XFA_CMP_Client_Final				(XE_CMP_CTX *ctx,
											 XE_CMP_OperationResult *opResult);

XFA_EXPORT_TYPE 
int		XFA_CMP_Client						(XE_CMP_OperationResult *opResult,
											 const int socket,
											 const int opID,
											 const XE_CMP_OperationParam *opParam,
											 const XE_CMP_ClientParam *clntParam);

// server

XFA_EXPORT_TYPE 
int		XFA_CMP_Server_Init					(XE_CMP_CTX *ctx,
											 const XE_CMP_ServerParam *srvrParam,
											 const XE_CMP_ServerCB *srvrCB);

XFA_EXPORT_TYPE 
int		XFA_CMP_Server_Update				(XE_CMP_CTX *ctx,
											 BIN *output,
											 const BIN *input);

XFA_EXPORT_TYPE 
int		XFA_CMP_Server_Final				(XE_CMP_CTX *ctx);

XFA_EXPORT_TYPE 
int		XFA_CMP_Server						(const int socket,
											 const XE_CMP_ServerParam *srvrParam,
											 const XE_CMP_ServerCB *srvrCB);

// version

XFA_EXPORT_TYPE 
char *	XFA_CMP_GetVersion					(void);

XFA_EXPORT_TYPE 
int		XFA_CMP_CheckVersion				(const char *version);			// optional

// error

XFA_EXPORT_TYPE 
char *	XFA_CMP_GetErrorReason				(const int code, 
											 const int locale);


#ifdef	__cplusplus
}
#endif

#endif
