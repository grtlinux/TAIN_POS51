//
//	$Id: suite_io.h,v 1.22 2009-05-14 07:15:02 ksyoon Exp $
//

#ifndef _SUITE_IO_H_
#define _SUITE_IO_H_

#	ifndef	_WIN32_WCE
#include <time.h>
#include <fcntl.h>
#	endif

#include "exp_global.h"

/**
 *	Constants
 */

// file

#ifdef _WIN32
#	ifndef	_WIN32_WCE
#define XE_FILE_MODE_RDWR					(_O_RDWR | _O_BINARY)
#define XE_FILE_MODE_APPEND					(_O_RDWR | _O_BINARY | _O_APPEND)
#define XE_FILE_MODE_READ					(_O_RDONLY | _O_BINARY)
#	endif
#else
#define XE_FILE_MODE_RDWR					(O_RDWR)
#define XE_FILE_MODE_APPEND					(O_RDWR | O_APPEND)
#define XE_FILE_MODE_READ					(O_RDONLY)
#endif

// for compatibility with prev version {{
#define OPEN_MODE							XE_FILE_MODE_RDWR
#define OPEN_APPEND_MODE					XE_FILE_MODE_APPEND
#define READ_MODE							XE_FILE_MODE_READ
// }}

/**
 *	Struct
 */

// bin

typedef struct _XE_BIN_LIST {
	struct _XE_BIN_LIST	*next;
	BIN		value;
} XE_BIN_LIST;

// socket

#ifdef	_WIN64
#define	XE_SOCKET							int *
#else
#define	XE_SOCKET							int
#endif

// WIN32_WCE Time struct {{
#ifdef _WIN32_WCE
struct tm {
	time_t	tm_year;
	time_t	tm_mon;
	time_t	tm_wday;
	time_t	tm_mday;
	time_t	tm_hour;
	time_t	tm_min;
	time_t	tm_sec;
};
#endif // WIN32_WCE Time struct }}

// mutex

typedef struct {
	char	opaque[256];
} XE_Mutex;

/**
 *	Error codes
 */

#define	IO_ERR_INVALID_INPUT				(ERR_IO + 1)
#define	IO_ERR_INTERNAL						(ERR_IO + 2)
#define	IO_ERR_MALLOC_FAILED				(ERR_IO + 3)

#define	IO_ERR_FILE_EOF						(ERR_IO + 30)
#define	IO_ERR_FILE_ACCESS_DENIED			(ERR_IO + 31)
#define	IO_ERR_FILE_NOT_FOUND				(ERR_IO + 32)
#define	IO_ERR_FILE_EXIST					(ERR_IO + 33)

#define	IO_ERR_SOCKET_CLOSED				(ERR_IO + 40)

#define	IO_ERR_MUTEX_FUNCTION				(ERR_IO + 50)

#define	IO_ERR_HUGE_TOO_LAGRE				(ERR_IO + 60)
#define	IO_ERR_HUGE_NEGATIVE				(ERR_IO + 61)

// for compatibility with prev version {{
#define PKI_IO_160							(ERR_IO+10*16)
#define PKI_IO_170							(ERR_IO+10*17)
#define PKI_IO_180							(ERR_IO+10*18)
#define PKI_IO_190							(ERR_IO+10*19)
#define PKI_IO_200							(ERR_IO+10*20)
#define PKI_IO_210							(ERR_IO+10*21)
#define PKI_IO_215							(ERR_IO+10*21+5)
#define PKI_IO_220							(ERR_IO+10*22)
#define PKI_IO_230							(ERR_IO+10*23)
#define PKI_IO_240							(ERR_IO+10*24)
#define PKI_IO_250							(ERR_IO+10*25)
#define PKI_IO_260							(ERR_IO+10*26)
#define PKI_IO_270							(ERR_IO+10*27)
// }}

/**
 *	Prototypes
 */

#ifdef	__cplusplus
extern "C" {
#endif

// mem

XFA_EXPORT_TYPE 
void *	XFA_malloc							(size_t size);

XFA_EXPORT_TYPE 
void *	XFA_calloc							(size_t nobj, size_t size);

XFA_EXPORT_TYPE 
void *	XFA_realloc							(void *p, size_t size);

XFA_EXPORT_TYPE 
void	XFA_free							(void *p);

// for compatibility with prev version {{
#	ifndef	_WIN32_WCE
XFA_EXPORT_TYPE void XFA_SafeFree			(void *p);
#	endif
// }}

// bin

XFA_EXPORT_TYPE 
BIN *	XFA_BIN_New							(void);

XFA_EXPORT_TYPE 
void	XFA_BIN_Reset						(BIN *bin);

XFA_EXPORT_TYPE 
void	XFA_BIN_Free						(BIN *bin);

XFA_EXPORT_TYPE 
int		XFA_BIN_Copy						(BIN *out, const BIN *in);

XFA_EXPORT_TYPE 
int		XFA_BIN_Set							(BIN *bin, const char *buffer, const int length);

XFA_EXPORT_TYPE 
int		XFA_BIN_Cmp							(const BIN *binA, const BIN *binB);

XFA_EXPORT_TYPE 
XE_BIN_LIST *	
		XFA_BIN_LIST_New					(void);

XFA_EXPORT_TYPE 
void	XFA_BIN_LIST_Reset					(XE_BIN_LIST *blist);

XFA_EXPORT_TYPE 
void	XFA_BIN_LIST_Free					(XE_BIN_LIST *blist);

XFA_EXPORT_TYPE 
int		XFA_BIN_LIST_Copy					(XE_BIN_LIST *outlist, const XE_BIN_LIST *inlist);

XFA_EXPORT_TYPE 
int		XFA_BIN_LIST_Add					(XE_BIN_LIST **blist, const BIN *bin);


#	ifndef	_WIN32_WCE // #if !defined( _WIN32_WCE ) {{

// for compatibility with prev version 
XFA_EXPORT_TYPE void XFA_FreeBin			(BIN *bin);
// }}

// file
XFA_EXPORT_TYPE 
int		XFA_File_Create						(const char *name);

XFA_EXPORT_TYPE 
int		XFA_File_Open						(const char *name, const int mode);

XFA_EXPORT_TYPE 
void	XFA_File_Close						(int fd);

XFA_EXPORT_TYPE 
int		XFA_File_Read						(int fd, void *buffer, const int length);

#endif // }}

/*
 *	파일 관련 함수는 wince용으로는 제공하지 않는다.
 *  다만 EXP 내부 함수에서 사용되어지는 XFA_File_ReadBin,
 *  XFA_File_WriteBin 만을 구현 하였다.
 */
XFA_EXPORT_TYPE 
int		XFA_File_ReadBin					(BIN *bin, const char *name);

XFA_EXPORT_TYPE 
int		XFA_File_WriteBin					(const char *name, const BIN *bin);

#ifndef _WIN32_WCE // #ifndef _WIN32_WCE {{

XFA_EXPORT_TYPE 
int		XFA_File_Write						(int fd, const void *buffer, const int length);

XFA_EXPORT_TYPE 
int		XFA_File_Truncate					(int fd, const int size);

XFA_EXPORT_TYPE 
int		XFA_File_SetReadLock				(int fd);

XFA_EXPORT_TYPE 
int		XFA_File_SetReadLockNB				(int fd);

XFA_EXPORT_TYPE 
int		XFA_File_SetWriteLock				(int fd);

XFA_EXPORT_TYPE 
int		XFA_File_SetWriteLockNB				(int fd);

XFA_EXPORT_TYPE 
int		XFA_File_ClearLock					(int fd);

// for compatibility with prev version {{

XFA_EXPORT_TYPE int	XFA_CreateFile			(char *name);
XFA_EXPORT_TYPE int	XFA_OpenFile			(char *name);
XFA_EXPORT_TYPE int	XFA_OpenFileAppend		(char *name);
XFA_EXPORT_TYPE void XFA_CloseFile			(int fd);
XFA_EXPORT_TYPE int	XFA_ReadOneChar			(int fd, char *pchar);
XFA_EXPORT_TYPE int XFA_ReadBinFromFd		(int fd, BIN *bin, int nLen);
XFA_EXPORT_TYPE int	XFA_ReadBin				(char *name, BIN *pbin);
XFA_EXPORT_TYPE int	XFA_WriteStrToFd		(int fd, char *pstr, int len);
XFA_EXPORT_TYPE int	XFA_WriteBinToFd		(int fd, BIN *pbin);
XFA_EXPORT_TYPE int	XFA_WriteBin			(char *name, BIN *pbin, int mode);
XFA_EXPORT_TYPE int	XFA_Truncate			(int fd, int size);

XFA_EXPORT_TYPE	int	XFA_SetFileReadLock		(int fd);
XFA_EXPORT_TYPE int	XFA_SetFileReadLockNoBlock	(int fd);
XFA_EXPORT_TYPE int	XFA_SetFileWriteLock	(int fd);
XFA_EXPORT_TYPE int	XFA_SetFileWriteLockNoBlock	(int fd);
XFA_EXPORT_TYPE int	XFA_ClearFileLock		(int fd);

// }}

// socket

XFA_EXPORT_TYPE 
int		XFA_Socket_Initialize				(void);

XFA_EXPORT_TYPE 
int		XFA_Socket_Finalize					(void);

XFA_EXPORT_TYPE 
XE_SOCKET
		XFA_Socket_Client					(const char *ip, const unsigned short port);

XFA_EXPORT_TYPE 
XE_SOCKET
		XFA_Socket_ClientEx					(const char *ip, const unsigned short port, const int timeOutSec);

XFA_EXPORT_TYPE 
XE_SOCKET
		XFA_Socket_Server					(const char *ip, const unsigned short port,
											 const void *param);

XFA_EXPORT_TYPE 
XE_SOCKET
		XFA_Socket_Accept					(XE_SOCKET srvr_sock, char clnt_ip[24]);

XFA_EXPORT_TYPE 
int		XFA_Socket_SendRecord				(XE_SOCKET sock, const char type, const BIN *bin);

XFA_EXPORT_TYPE 
int		XFA_Socket_RecvRecord				(XE_SOCKET sock, char *type, BIN *bin);

XFA_EXPORT_TYPE 
void	XFA_Socket_Close					(XE_SOCKET sock);

#endif //#ifndef _WIN32_WCE }}

XFA_EXPORT_TYPE 
int		XFA_Socket_Recv						(XE_SOCKET sock, char *buffer, const int length);

XFA_EXPORT_TYPE 
int		XFA_Socket_Send						(XE_SOCKET sock, const char *buffer, const int length);

XFA_EXPORT_TYPE 
int		XFA_Socket_SendAll					(XE_SOCKET sock, const char *buffer, const int length);

XFA_EXPORT_TYPE 
int		XFA_Socket_RecvAll					(XE_SOCKET sock, char *buffer, const int length);

XFA_EXPORT_TYPE 
unsigned int
		XFA_Socket_htonl					(unsigned int hostlong);

XFA_EXPORT_TYPE 
unsigned int
		XFA_Socket_ntohl					(unsigned int netlong);

#	ifndef _WIN32_WCE //#ifndef _WIN32_WCE {{

XFA_EXPORT_TYPE 
unsigned short
		XFA_Socket_htons					(unsigned short hostshort);

XFA_EXPORT_TYPE 
unsigned short
		XFA_Socket_ntohs					(unsigned short netshort);

// for compatibility with prev version {{
XFA_EXPORT_TYPE int	XFA_Bind				(char *ipAddr, unsigned short port);
XFA_EXPORT_TYPE int	XFA_SendRawData			(int sock, char *buffer, int length);
XFA_EXPORT_TYPE int	XFA_SendData			(int sock, char type, char *buffer, int length);
XFA_EXPORT_TYPE int	XFA_RecvData			(int sock, char **ppBuf, size_t nLen);
XFA_EXPORT_TYPE int	XFA_ReadRawData			(int sock, char **ppBuf, int length);
XFA_EXPORT_TYPE int	XFA_ReadData			(int sock, char **ppBuf, int *length);
XFA_EXPORT_TYPE void XFA_Close				(int sock);
XFA_EXPORT_TYPE unsigned int	XFA_htonl	(unsigned int hostlong);
XFA_EXPORT_TYPE unsigned short	XFA_htons	(unsigned short hostshort);
XFA_EXPORT_TYPE unsigned int	XFA_ntohl	(unsigned int netlong);
XFA_EXPORT_TYPE unsigned short	XFA_ntohs	(unsigned short netshort);
// }}

// for compatibility with prev version {{
XFA_EXPORT_TYPE time_t	XFA_GetLocalTime	();
XFA_EXPORT_TYPE time_t	XFA_GetUTCTime		();
XFA_EXPORT_TYPE time_t	XFA_GetUTCGap		();
XFA_EXPORT_TYPE char *	XFA_GetTimeRFCType	(time_t , int );
XFA_EXPORT_TYPE char *	XFA_GetTimeStr		(time_t , int );
XFA_EXPORT_TYPE int 	XFA_Time2Str		(time_t , char **);
XFA_EXPORT_TYPE int 	XFA_LocalTime2Str	(time_t , char **);
XFA_EXPORT_TYPE int 	XFA_Get14ByteTimeStr(time_t , char **);
XFA_EXPORT_TYPE time_t	XFA_Str2Time		(char *);

// trace
XFA_EXPORT_TYPE
void	XFA_Trace_Initialize				(void);

XFA_EXPORT_TYPE
void	XFA_Trace_Finalize					(void);

XFA_EXPORT_TYPE
void	XFA_Trace_PutError					(const char *func, const int res, const char *rstring,
											 const char *file, const int line);

#define	XFA_TRACE_PUTERROR(f, r, s)			XFA_Trace_PutError(f, r, s, __FILE__, __LINE__)

XFA_EXPORT_TYPE
void	XFA_Trace_GetError					(char **string);


XFA_EXPORT_TYPE
void	XFA_Trace_PrintError				(void);

XFA_EXPORT_TYPE
void	XFA_Trace_WriteError				(int fd);


XFA_EXPORT_TYPE
void	XFA_Trace_ClearError				(void);

// version

XFA_EXPORT_TYPE
char *	XFA_IO_GetVersion					(void);

XFA_EXPORT_TYPE
int		XFA_IO_CheckVersion					(const char *version);			// optional

// error

XFA_EXPORT_TYPE 
char *	XFA_IO_GetErrorReason				(const int code, const int locale);

// for compatibility with prev version {{
XFA_EXPORT_TYPE char *	XFA_GetVersionIO	();
XFA_EXPORT_TYPE char *	XFA_GetErrReasonIO	(int code, int locale);
// }}

#	endif
// }}


// number

// for compatibility with prev version {{
XFA_EXPORT_TYPE int		XFA_IncBinNumber	(BIN *, BIN *);
XFA_EXPORT_TYPE int		XFA_DecBinNumber	(BIN *, BIN *);
XFA_EXPORT_TYPE int		XFA_SetBinNumber	(char *, unsigned int[], int );
XFA_EXPORT_TYPE int		XFA_IncUp			(unsigned int[], int);
XFA_EXPORT_TYPE int		XFA_DecUp			(unsigned int[], int);
XFA_EXPORT_TYPE int		XFA_GetNewBinNum	(char *, int , BIN *);
XFA_EXPORT_TYPE int		XFA_BinToHex		(unsigned char *bin, int len, char **hex);
XFA_EXPORT_TYPE int		XFA_HexToBin		(char *hex, unsigned char **bin, int *len);
XFA_EXPORT_TYPE int		XFA_NumToHex		(unsigned int srcNum, char tgtHex[9]);
XFA_EXPORT_TYPE int		XFA_HexToNum		(char srcHex[9], unsigned int *tgtNum);
XFA_EXPORT_TYPE int		XFA_GetIntLen		(unsigned int num);
XFA_EXPORT_TYPE int		XFA_BinToHEX		(unsigned char *bin, int len, char **tgtHEX);

#ifndef _MAC
#ifndef DISABLE_HUGE
// huge
XFA_EXPORT_TYPE int		XFA_HugeToHex		(HUGE *srcHuge, char **tgtHex);
XFA_EXPORT_TYPE int		XFA_HexToHuge		(char *srcHex, HUGE *tgtHuge);
XFA_EXPORT_TYPE int		XFA_HugeToNum		(HUGE *srcHuge, unsigned int *num);
XFA_EXPORT_TYPE int		XFA_NumToHuge		(unsigned int num, HUGE *tgtHuge);
XFA_EXPORT_TYPE int		XFA_StrToHuge		(char *, HUGE *tgtHuge);
XFA_EXPORT_TYPE int		XFA_HugeToHEX		(HUGE *srcHuge, char **tgtHEX);
XFA_EXPORT_TYPE int		XFA_DupHuge			(HUGE *srcHuge, HUGE *tgtHuge);
XFA_EXPORT_TYPE int		XFA_CmpHuge			(HUGE *orgHuge, HUGE *cmpHuge);
#endif // DISABLE_HUGE
#endif

// HUGE -> XE_HUGE 로 변경된 함수 내부 구현은 동일. 2007/5/3 jhhong.
XFA_EXPORT_TYPE int		XFA_HugeToHexEx		(XE_HUGE *srcHuge, char **tgtHex);
XFA_EXPORT_TYPE int		XFA_HexToHugeEx		(char *srcHex, XE_HUGE *tgtHuge);
XFA_EXPORT_TYPE int		XFA_HugeToNumEx		(XE_HUGE *srcHuge, unsigned int *num);
XFA_EXPORT_TYPE int		XFA_NumToHugeEx		(unsigned int num, XE_HUGE *tgtHuge);
XFA_EXPORT_TYPE int		XFA_StrToHugeEx		(char *, XE_HUGE *tgtHuge);
XFA_EXPORT_TYPE int		XFA_HugeToHEXEx		(XE_HUGE *srcHuge, char **tgtHEX);
XFA_EXPORT_TYPE int		XFA_DupHugeEx		(XE_HUGE *srcHuge, XE_HUGE *tgtHuge);
XFA_EXPORT_TYPE int		XFA_CmpHugeEx		(XE_HUGE *orgHuge, XE_HUGE *cmpHuge);
// }}

// mutex

XFA_EXPORT_TYPE
XE_Mutex *
		XFA_Mutex_Create					(const void *params);

XFA_EXPORT_TYPE
int		XFA_Mutex_Destroy					(XE_Mutex *mutex);

XFA_EXPORT_TYPE
int		XFA_Mutex_Lock						(XE_Mutex *mutex);

XFA_EXPORT_TYPE
int		XFA_Mutex_Unlock					(XE_Mutex *mutex);

// time

XFA_EXPORT_TYPE
time_t	XFA_Time_GetTime					(void);

#ifdef	_WIN32_WCE 
/*
 *	ASN에 포함된 함수를 IO로 변경함.
 *  IO가 ASN보다 범용적이므로 타임과 관련된 함수 구현을 
 *  옮겼음.
 */
XFA_EXPORT_TYPE	
struct tm 
		*gmtime			(const time_t *clock);

XFA_EXPORT_TYPE	
time_t	mktime			(const struct tm *timeptr);

XFA_EXPORT_TYPE	
long	time			(long *tloc);

XFA_EXPORT_TYPE	
struct tm 
		*localtime		(const time_t *timer);

XFA_EXPORT_TYPE	
int		strftime		(char *str, size_t n, const char *format, const struct tm *tp);


/*
 *	기존 소스와 호환을 위해 더미 함수를 구현한다.
 *  wince에서는 불필요한 함수인데 많은 소스에 호출되므로 
 *  최대한 코드를 변경하지 않기 위해 구현함.
 */

XFA_EXPORT_TYPE 
char *	XFA_IO_GetErrorReason				(const int code, const int locale);

XFA_EXPORT_TYPE
void	XFA_Trace_PutError					(const char *func, const int res, const char *rstring,
											 const char *file, const int line);

#define	XFA_TRACE_PUTERROR(f, r, s)			XFA_Trace_PutError(f, r, s, __FILE__, __LINE__)

#	endif

#ifdef	__cplusplus
}
#endif

#endif

