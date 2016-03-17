//
//	suite_ssl_bin.h
//

#ifndef _SUITE_SSL_BIN_H_
#define _SUITE_SSL_BIN_H_

#include "exp_global.h"

/**
 *	Constants
 */

#define	uint8		unsigned char
#define	uint16		unsigned short
#define	uint24		unsigned int
#define	uint32		unsigned int

/**
 *	Struct
 */

typedef struct _XE_SSL_BLIST {
	BIN 			*bin;
	struct _XE_SSL_BLIST *next;
} XE_SSL_BLIST;

/**
 *	Prototypes
 */

#ifdef  __cplusplus
extern "C" {
#endif

// bin

XFA_EXPORT_TYPE
BIN *	XFA_SSL_BIN_New					(void);

XFA_EXPORT_TYPE
BIN *	XFA_SSL_BIN_Set					(const int len, const uint8 *data);

XFA_EXPORT_TYPE
BIN *	XFA_SSL_BIN_Copy				(const BIN *bin);

/*
XFA_EXPORT_TYPE
int	XFA_SSL_BIN_Cat					(BIN *bin1, const uint8 *bin2, const int length);
*/

XFA_EXPORT_TYPE
BIN *	XFA_SSL_BIN_Merge				(const BIN *bin1, const BIN *bin2);

XFA_EXPORT_TYPE
void	XFA_SSL_BIN_Free				(BIN *bin);

// blist

XFA_EXPORT_TYPE
XE_SSL_BLIST *	
		XFA_SSL_BLIST_New				(void);

XFA_EXPORT_TYPE
XE_SSL_BLIST *	
		XFA_SSL_BLIST_Copy				(const XE_SSL_BLIST *blist);

XFA_EXPORT_TYPE
void	XFA_SSL_BLIST_Free				(XE_SSL_BLIST *blist);

#ifdef  __cplusplus
}
#endif

#endif
