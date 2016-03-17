//
//	suite_pkcs5.h
//

#ifndef _SUITE_PKCS5_H_
#define _SUITE_PKCS5_H_

#include "exp_global.h"

/**
 *	Constants
 */

// pbesID

// for pbe1 {{
#define	XE_PKCS5_PBESID_PBEWithMD2AndDES_CBC		1
#define	XE_PKCS5_PBESID_PBEWithMD5AndDES_CBC		2
#define	XE_PKCS5_PBESID_PBEWithSHA1AndDES_CBC		3
#define	XE_PKCS5_PBESID_PBEWithSHA1AndSEED_CBC		4
#define	XE_PKCS5_PBESID_PBEWithMD2AndRC2_CBC		6
#define	XE_PKCS5_PBESID_PBEWithMD5AndRC2_CBC		7
#define	XE_PKCS5_PBESID_PBEWithSHA1AndRC2_CBC		8
#define	XE_PKCS5_PBESID_PBEWithSHA1AndSEED_CBC_KSIGN 9
// }}
//2011-07-13 by cristyanne : add aria for gcma 
#define XE_PKCS5_PBESID_PBEWithSHA1AndARIA_CBC		10
#define XE_PKCS5_PBESID_PBEWithSHA256AndARIA_CBC	11
#define XE_PKCS5_PBESID_PBEWithHAS160AndARIA_CBC	12
//}}
// for pbe2 {{
#define	XE_PKCS5_PBESID_PBES2						5
// }}
// for pkcs12 {{
#define	XE_PKCS5_PBESID_P12PBE_SHA_128_RC4			(30+1)
#define	XE_PKCS5_PBESID_P12PBE_SHA_40_RC4			(30+2)
#define	XE_PKCS5_PBESID_P12PBE_SHA_3KEY_TDES_CBC	(30+3)
#define	XE_PKCS5_PBESID_P12PBE_SHA_2KEY_TDES_CBC	(30+4)
#define	XE_PKCS5_PBESID_P12PBE_SHA_128_RC2_CBC		(30+5)
#define	XE_PKCS5_PBESID_P12PBE_SHA_40_RC2_CBC		(30+6)
#define	XE_PKCS5_PBESID_P12PBE_SHA1_SEED_CBC		(30+11)
#define	XE_PKCS5_PBESID_P12PBE_SHA1_NEAT_CBC		(30+12)
#define	XE_PKCS5_PBESID_P12PBE_HAS160_NEAT_CBC		(30+13)
// 2011-07-13 by cristyanne : add aria for gcma
#define XE_PKCS5_PBESID_P12PBE_SHA1_ARIA_CBC		(30+14)
#define XE_PKCS5_PBESID_P12PBE_SHA256_ARIA_CBC		(30+15)
#define XE_PKCS5_PBESID_P12PBE_HAS160_ARIA_CBC		(30+16)
// }}

// kdfID

#define	XE_PKCS5_KDFID_PBKDF2						1

// prfID

#define	XE_PKCS5_PRFID_HMACWithSHA1					1

// encID

#define	XE_PKCS5_ENCID_DES_CBC						1
#define	XE_PKCS5_ENCID_DES_EDE3_CBC					2
#define	XE_PKCS5_ENCID_RC2_CBC						4
#define	XE_PKCS5_ENCID_RC5_CBC						6
#define	XE_PKCS5_ENCID_SEED_CBC						9
// 2011-07-15 cristyanne : add aria for gcma
#define XE_PKCS5_ENCID_ARIA_CBC						10

/**
 *	Struct
 */

typedef struct {
	int		pbesID;
	struct {
		int		kdfID;
		int		prfID;
		int		encID;
	} pbes2Param;
} XE_PKCS5_PBES_ALGID;

/**
 *	Error codes
 */

#define	ERR_PKCS5							(ERR_PKCS + 100)

#define	PKCS5_ERR_INVALID_INPUT				(ERR_PKCS5 + 1)
#define	PKCS5_ERR_INTERNAL					(ERR_PKCS5 + 2)
#define	PKCS5_ERR_MALLOC_FAILED				(ERR_PKCS5 + 3)

#define	PKCS5_ERR_UNKNOWN_ID				(ERR_PKCS5 + 10)
#define PKCS5_ERR_UNKNOWN_PBESID			(ERR_PKCS5 + 11)
#define PKCS5_ERR_UNKNOWN_ENCID				(ERR_PKCS5 + 12)
#define	PKCS5_ERR_UNKNOWN_SALT				(ERR_PKCS5 + 15)

#define PKCS5_ERR_BAD_ALGPARAM				(ERR_PKCS5 + 20)

#define	PKCS5_ERR_INVALID_MAC				(ERR_PKCS5 + 30)
#define	PKCS5_ERR_INVALID_PASSWORD			(ERR_PKCS5 + 31)

/**
 *	Prototypes
 */

#ifdef  __cplusplus
extern "C" {
#endif

// pbe

XFA_EXPORT_TYPE 
int		XFA_PKCS5_EncryptData				(BIN *encAlgId, 
											 BIN *output,
											 const XE_PKCS5_PBES_ALGID *pbesID,
											 const BIN *input, 
											 const BIN *password);

XFA_EXPORT_TYPE 
int		XFA_PKCS5_DecryptData				(XE_PKCS5_PBES_ALGID *pbesID,
											 BIN *output, 
											 const BIN *encAlgId,
											 const BIN *input, 
											 const BIN *password);

// version

XFA_EXPORT_TYPE	
char *	XFA_PKCS5_GetVersion				(void);

XFA_EXPORT_TYPE	
int		XFA_PKCS5_CheckVersion				(const char *version);			// optional

// error

XFA_EXPORT_TYPE	
char *	XFA_PKCS5_GetErrorReason			(const int code, 
											 const int locale);

#ifdef  __cplusplus
}
#endif

#endif

