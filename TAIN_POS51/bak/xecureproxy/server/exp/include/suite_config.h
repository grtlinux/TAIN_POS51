//
//	suite_config.h
//

#ifndef _SUITE_CONFIG_H_
#define _SUITE_CONFIG_H_

#include "exp_global.h"

/**
 *	Constants
 */

#define WORD_MAX		128
#define ONE_LINE_LEN	1024

#define CK_PORT         "PORT"
#define CK_DAILY		"LOG_DAILY"
#define CK_LOG_FN		"LOG_FN"
#define CK_LOG_DIR      "LOG_DIR"
#define CK_SPOOLING		"SPOOLING"
#define CK_REPO_DIR     "REPO_DIR"
#define CK_MI_FREE		"MI_COLLISTION"
#define CK_PREFIX       "LOG_PREFIX"
#define CK_PID_FN       "PID_FN"
#define CK_CERT_FN      "SC_FN"
#define CK_PBEK_FN      "SK_FN"
#define CK_TIME_OUT     "TIME_OUT"
#define CK_BINNUM_FN    "BINNUM_FN"

#ifdef _WIN32
#define	DIR_DIV			"\\"
#else
#define	DIR_DIV			"/"
#endif

#define DV_PORT         8246
#define DV_DAILY		"No"
#define DV_LOG_FN		".."DIR_DIV"log"DIR_DIV"Xecure-Default"
#define DV_LOG_DIR      ".."DIR_DIV"log"
#define DV_REPO_DIR     ".."DIR_DIV"repository"
#define DV_CONF_FN		".."DIR_DIV"etc"DIR_DIV"Xecure-Default.CF"
#define DV_PREFIX       "Xecure-Default"
#define DV_PID_FN       ".."DIR_DIV"etc"DIR_DIV"Xecure-Default.PID"
#define DV_CERT_FN      ".."DIR_DIV"etc"DIR_DIV"Xecure-Default.SC"
#define DV_PBEK_FN      ".."DIR_DIV"etc"DIR_DIV"Xecure-Default.SK"
#define DV_TIME_OUT     30
#define DV_BINNUM_FN    ".."DIR_DIV"etc"DIR_DIV"Xecure-Default.BN"

/**
 *	Struct
 */

typedef struct VALUELIST_ST VALUELIST;

struct VALUELIST_ST {
  char* 		pValue;
  VALUELIST* 	pNext;
};

typedef struct ENVLIST_ST AppEnvList;

struct ENVLIST_ST {
  char			*pKey;
  VALUELIST		*pValueList;
  AppEnvList	*pNext;
};

typedef short int Bool;

/**
 *	Error codes
 */

#define PKI_CONFIG_010				(ERR_CONFIG+10*1)
#define PKI_CONFIG_020				(ERR_CONFIG+10*2)
#define PKI_CONFIG_030				(ERR_CONFIG+10*3)
#define PKI_CONFIG_040				(ERR_CONFIG+10*4)
#define PKI_CONFIG_050				(ERR_CONFIG+10*5)
#define PKI_CONFIG_060				(ERR_CONFIG+10*6)
#define PKI_CONFIG_070				(ERR_CONFIG+10*7)
#define PKI_CONFIG_080				(ERR_CONFIG+10*8)
#define PKI_CONFIG_090				(ERR_CONFIG+10*9)
#define PKI_CONFIG_100				(ERR_CONFIG+10*10)
#define PKI_CONFIG_110				(ERR_CONFIG+10*11)
#define PKI_CONFIG_120				(ERR_CONFIG+10*12)
#define PKI_CONFIG_130				(ERR_CONFIG+10*13)
#define PKI_CONFIG_140				(ERR_CONFIG+10*14)
#define PKI_CONFIG_150				(ERR_CONFIG+10*15)
#define PKI_CONFIG_160				(ERR_CONFIG+10*16)
#define PKI_CONFIG_170				(ERR_CONFIG+10*17)
#define PKI_CONFIG_180				(ERR_CONFIG+10*18)
#define PKI_CONFIG_190				(ERR_CONFIG+10*19)
#define PKI_CONFIG_200				(ERR_CONFIG+10*20)

/**
 *	Prototypes
 */

#ifdef  __cplusplus
extern "C" {
#endif

XFA_EXPORT_TYPE int		XFA_InitEnvListElement(AppEnvList **);
XFA_EXPORT_TYPE int		XFA_InitValueListElement(VALUELIST **);
XFA_EXPORT_TYPE AppEnvList *XFA_SearchKeyFromEnvList(AppEnvList *, char *);
XFA_EXPORT_TYPE int		XFA_AddKeyIntoEnvList(AppEnvList *, char *);
XFA_EXPORT_TYPE int		XFA_AddValueIntoValueList(VALUELIST  *, char *);
XFA_EXPORT_TYPE VALUELIST* XFA_FirstValueElement(AppEnvList *);
XFA_EXPORT_TYPE VALUELIST* XFA_NextValueElement(VALUELIST *);
XFA_EXPORT_TYPE char *	XFA_GetEnvValue		(VALUELIST *);
XFA_EXPORT_TYPE void	XFA_RemoveLeadingSpace(FILE *);
XFA_EXPORT_TYPE int		XFA_GetOneLine		(FILE *, int , char **);
XFA_EXPORT_TYPE int		XFA_ParseLine		(AppEnvList *, char *);
XFA_EXPORT_TYPE void	XFA_FreeEnvList		(AppEnvList *);
XFA_EXPORT_TYPE int		XFA_ReadConfigFile	(char *, AppEnvList **);
XFA_EXPORT_TYPE char *	XFA_GetConfValue	(AppEnvList *, char *);
XFA_EXPORT_TYPE void	XFA_PrintEnvList	(AppEnvList *);

XFA_EXPORT_TYPE char *	XFA_GetVersionConfig(void);

XFA_EXPORT_TYPE char *	XFA_GetErrReasonConfig(int, int);

#ifdef  __cplusplus
}
#endif

#endif

