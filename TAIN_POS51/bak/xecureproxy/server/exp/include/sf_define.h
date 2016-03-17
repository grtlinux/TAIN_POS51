//
//	sf_define.h
//

#ifndef __SF_DEFINE_H__
#define __SF_DEFINE_H__

#define	SF_BOOL					unsigned char		//  1 bits
#define	SF_BYTE					unsigned char		//  8 bits
#define	SF_SHORT				unsigned short		// 16 bits
#define	SF_WORD					unsigned int		// 32 bits
#if (defined(WIN32) || defined(_WIN32))
#define	SF_DWORD				unsigned __int64	// 64 bits
#else
#define	SF_DWORD				unsigned long long	// for gcc
#endif

#define	SF_ERROR				int

#endif
