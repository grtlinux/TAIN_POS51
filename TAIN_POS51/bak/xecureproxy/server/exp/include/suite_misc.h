//
//	suite_misc.h
//

#ifndef _SUITE_MISC_H_
#define _SUITE_MISC_H_

#include "exp_global.h"

#ifdef  __cplusplus
extern "C" {
#endif

// UNIX Reliable Version Functions ;)
typedef void    Sigfunc(int);

XFA_EXPORT_TYPE int		XFA_GetPassWD(char *);
XFA_EXPORT_TYPE Sigfunc *XFA_SetSignal(int, Sigfunc *);

XFA_EXPORT_TYPE char *	XFA_GetVersionMisc(void);

XFA_EXPORT_TYPE char *	XFA_GetErrReasonMisc(int, int);

#ifdef  __cplusplus
}
#endif

#endif
