//
//	suite_sss.h
//

#ifndef	_SUITE_SSS_H_
#define	_SUITE_SSS_H_

#include "exp_global.h"

/**
 *	Constants
 */

#define	XE_SSS_ALGID_SIMPLE					1
#define	XE_SSS_ALGID_SHAMIR					2

/**
 *	Structs
 */

typedef struct {
	int		n;
	int		t;
} XE_SSS_SHARE_PARAM;

typedef struct {
	int		number;
	struct _BIN_LIST	*list;
} XE_SSS_SHARE;

/**
 *	Error codes
 */

#define	SSS_ERR_INVALID_INPUT				(ERR_SSS + 1)
#define	SSS_ERR_INTERNAL					(ERR_SSS + 2)
#define	SSS_ERR_MALLOC_FAILED				(ERR_SSS + 3)

#define	SSS_ERR_UNKNOWN_ALGID				(ERR_SSS + 10)
#define	SSS_ERR_BAD_PARAM					(ERR_SSS + 11)
#define	SSS_ERR_BAD_SHARE					(ERR_SSS + 12)
#define	SSS_ERR_BAD_SECRET					(ERR_SSS + 13)

#define	SSS_ERR_EVALUATE_POLY				(ERR_SSS + 50)
#define	SSS_ERR_GENERATE_POLY				(ERR_SSS + 51)
#define	SSS_ERR_ENCODE_BIGINT				(ERR_SSS + 52)
#define	SSS_ERR_DECODE_BIGINT				(ERR_SSS + 53)
#define	SSS_ERR_GENERATE_PRIME				(ERR_SSS + 54)

/**
 *	Prototypes
 */

#ifdef	__cplusplus
extern "C" {
#endif

// object functions

XFA_EXPORT_TYPE	
XE_SSS_SHARE *
		XFA_SSS_CreateShare					(void);

XFA_EXPORT_TYPE	
void	XFA_SSS_DestroyShare				(XE_SSS_SHARE *share);

// sss functions

XFA_EXPORT_TYPE	
int		XFA_SSS_ShareSecret					(XE_SSS_SHARE *share,
											 BIN *sssParam,
											 const BIN *secret,
											 const int algID,
											 const XE_SSS_SHARE_PARAM *shareParam);

XFA_EXPORT_TYPE	
int		XFA_SSS_RecoverSecret				(BIN *secret,
											 const XE_SSS_SHARE *share,
											 const int algID,
											 const BIN *sssParam);

// version function

XFA_EXPORT_TYPE	
char *	XFA_SSS_GetVersion					(void);

// error function

XFA_EXPORT_TYPE	
char *	XFA_SSS_GetErrorReason				(const int code, 
											 const int locale);

#ifdef	__cplusplus
}
#endif

#endif
