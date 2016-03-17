//
//	$Id: suite_codec.h,v 1.6 2006-01-11 07:28:05 jhkim Exp $
//

#ifndef _SUITE_CODEC_H_
#define _SUITE_CODEC_H_

#include "exp_global.h"

/**
 *	Constants
 */

#define KR_EUC 								"ko_KR-euc"
#define KR_UTF8								"ko_KR-UTF-8"
#define	JP_EUC								"ja_JP-EUC"
#define	JP_SJIS								"ja_JP-SJIS"
#define	JP_UTF8								"ja_JP-UTF-8"

// for compatibility with prev version {{
#define KR_ANSI 							"ko_KR-euc"
#define KR_UNICODE							"ko_KR-UTF-8"
// }}

/**
 *	Struct
 */

/**
 *	Error codes
 */

#define	CODEC_ERR_INVALID_INPUT				(ERR_CODEC + 1)
#define CODEC_ERR_INTERNAL					(ERR_CODEC + 2)
#define CODEC_ERR_MALLOC_FAILED				(ERR_CODEC + 3)

#define CODEC_ERR_BAD_HEXSTR				(ERR_CODEC + 20)

/**
 *	Prototypes
 */

#ifdef  __cplusplus
extern "C" {
#endif

XFA_EXPORT_TYPE 
int 	XFA_ConvCodeSet						(const char *fromCode, const char *tocCode, 
											 const char *fromStr, char *toStr);
// utf8
XFA_EXPORT_TYPE 
int 	XFA_EncodeUTF8						(const unsigned char *, unsigned char **, int *);

XFA_EXPORT_TYPE 
int 	XFA_DecodeUTF8						(const unsigned char *, int, char **);

// bmp
XFA_EXPORT_TYPE 
int 	XFA_DecodeBMPStr					(const unsigned short bmpLength, 
											 const unsigned short *bmpValue, char *string);

// base64

XFA_EXPORT_TYPE 
int 	XFA_BinToBase64						(BIN *bin, char **base64);

XFA_EXPORT_TYPE 
int 	XFA_Base64ToBin 					(char *base64, BIN *bin);

// string

XFA_EXPORT_TYPE 
int 	XFA_IsASCII							(char *string);

XFA_EXPORT_TYPE 
int 	XFA_StrToBin						(char *hex, BIN *bin);

XFA_EXPORT_TYPE 
int 	XFA_BinToStr						(BIN *bin, char **hex);

#	ifndef	_WIN32_CE
// version

XFA_EXPORT_TYPE 
char *	XFA_Codec_GetVersion				(void);

XFA_EXPORT_TYPE 
int		XFA_Codec_CheckVersion				(const char *version);			// optional

// error

XFA_EXPORT_TYPE 
char *	XFA_Codec_GetErrorReason			(const int code, 
											 const int locale);

// for compatibility with prev version {{
XFA_EXPORT_TYPE	char * 	XFA_GetVersionCodec	(void);

XFA_EXPORT_TYPE char * 	XFA_GetErrReasonCodec	(int, int);
// }}
#endif

#ifdef  __cplusplus
}
#endif
#endif

