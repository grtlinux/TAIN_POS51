//
//	suite_log.h
//

#ifndef _SUITE_LOG_H_
#define _SUITE_LOG_H_

#include "exp_global.h"
#ifdef WIN32
#include <windows.h>
#else
#include <pthread.h>
#endif

/**
 *	Error codes
 */
#define PKI_LOG_010 			(ERR_LOG+10*1)
#define PKI_LOG_020 			(ERR_LOG+10*2)
#define PKI_LOG_030 			(ERR_LOG+10*3)
#define PKI_LOG_040 			(ERR_LOG+10*4)

/**
 *	Prototypes
 */
#define LOG_ALERT				__FILE__,__LINE__,0
#define LOG_TRACE				__FILE__,__LINE__,1
#define LOG_DEBUG				__FILE__,__LINE__,2

#ifdef	__cplusplus
extern "C" {
#endif

XFA_EXPORT_TYPE 
int		XFA_LOG_Msg(char * src, int line, int log_level, char *format, ...);

XFA_EXPORT_TYPE 
int		XFA_LOG_Bin(char * src, int line, int log_level, char *format, int format_len);

XFA_EXPORT_TYPE 
int		XFA_LOG_BinST(char * src, int line, int log_level, const BIN *format );

#ifdef	__cplusplus
};
#endif

#endif

