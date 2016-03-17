//
// $Id: suite_license.h,v 1.10 2005-08-24 06:38:48 ssosuny Exp $
//

#ifndef	_LICENSE_H_
#define _LICENSE_H_

#include <stdio.h>
#include "exp_global.h"


/**
 *	Constants
 */

#define XE_LICENSE_KEY_FILE			"license.exp"
#define	XE_LICENSE_MAX_SYSID_LEN	12
#define XE_LICENSE_KEYSTR_LEN		26
#define XE_LICENSE_MAX_ADAPTER		10

/** 
 *	Structures
 */

typedef struct _XE_LICENSE_INFO {
	int		version;		// 1,2,3, ... default: 2
	char	key[80];
	char	sid[80];
	char	user[80];
	char	product[80];
	int		qty;			// # or 0 for unlimited
	char	expire[80];		// YYYY-MM-DD or unlimited
	char	issued[80];		// YYYY-MM-DD
	char	ext1[80];
	char	ext2[80];
	char	ext3[80];
} XE_LICENSE_INFO;


typedef struct _XE_LICENSE_SYSID {
#define XE_LICENSE_TYPE_HOSTID	0
#define XE_LICENSE_TYPE_MAC		1
	int		type;
	int		num;
	char	desc[XE_LICENSE_MAX_ADAPTER][80];
	char	sid[XE_LICENSE_MAX_ADAPTER][80];
	char	ext[XE_LICENSE_MAX_ADAPTER][80];

} XE_LICENSE_SYSID;

/**
 *	Macros
 */


/**
 * 	Prototypes
 */

#ifdef	__cplusplus
extern      "C" {
#endif
	
	const char * XFA_License_GetVersion(void);
	int			XFA_License_GetSysID(XE_LICENSE_SYSID *sysid);
	int			XFA_License_Check(XE_LICENSE_INFO *lc, const char *file);
	void		XFA_License_Print(FILE *fp, const XE_LICENSE_INFO *lc);
	char *		XFA_License_GetErrorReason(int nCode, int nLocale);
	int			lc_dtrace(const char *format, ...);
	extern int	g_lc_trace;

	void	XFA_LC_Trace_Initialize(void);
	void	XFA_LC_Trace_Finalize(void);
	void	XFA_LC_Trace_PutError(const char *func, const int res, const char *rstring, const char *file, const int line);
	void	XFA_LC_Trace_GetError(char **string);

	#define XFA_LC_Trace_PUTERROR(f, r, s)			XFA_LC_Trace_PutError(f, r, s, __FILE__, __LINE__)
	#define	XFA_LICENSE_PUTERROR(f, r)				XFA_LC_Trace_PUTERROR(f, r, XFA_License_GetErrorReason(r, LOCALE_ENG))
	
	#define XFA_LC_Trace_PUTWARN(f, r, s)			XFA_LC_Trace_PutError(f, r, s, __FILE__, __LINE__)
	#define XFA_LC_Trace_PUTINFO(f, r, s)			XFA_LC_Trace_PutError(f, r, s, __FILE__, __LINE__)
#ifdef	__cplusplus
}
#endif

/**
 *	Error Codes
 */
#define	LICENSE_ERR_MISMATCH		(ERR_LICENSE + 1)
#define LICENSE_ERR_EXPIRED			(ERR_LICENSE + 2)
#define LICENSE_ERR_GET_SYSTEMID	(ERR_LICENSE + 3)
#define	LICENSE_ERR_FILE_OPEN		(ERR_LICENSE + 4)
#define	LICENSE_ERR_SYNTAX			(ERR_LICENSE + 5)

#define LICENSE_ERR_INVALID_INPUT	(ERR_LICENSE + 10)

#define LICENSE_ERR_INVALID_SYNTAX	(ERR_LICENSE + 11)

#endif							/* _LICENSE_H_ */
