//
//  $Id: sf_gf2m.h,v 1.4 2006/01/11 07:27:34 ssosuny Exp $
//
//WIN32_CE
#ifndef _MIN_WCE

#ifndef __SF_GF2M_H__
#define __SF_GF2M_H__

#include "sf_bigint.h"

/**
 *	Constants
 */

/**
 *	Struct
 */

/**
 *	Error codes
 */

//  SF_COMMOM_ERROR_INVALID_INPUT
//  SF_COMMOM_ERROR_MALLOC_FAILED

//  SF_GF2M_ERROR_DEGREE_IS_EVEN
//  SF_GF2M_ERROR_NO_SOLUTION

/**
 *	Prototypes
 */

#ifdef __cplusplus
extern      "C" {
#endif

// basic

SF_ERROR    SF_GF2M_Add					(SF_BigInt *r, const SF_BigInt *a, const SF_BigInt *b);
SF_ERROR    SF_GF2M_Sub					(SF_BigInt *r, const SF_BigInt *a, const SF_BigInt *b);
SF_ERROR    SF_GF2M_Mul					(SF_BigInt *r, const SF_BigInt *a, const SF_BigInt *b, 
										 SF_POOL_CTX * pool);

SF_ERROR    SF_GF2M_Sqr					(SF_BigInt *r, const SF_BigInt *a);

SF_ERROR    SF_GF2M_Inv					(SF_BigInt *r, const SF_BigInt *a, const SF_BigInt *m,
										 SF_POOL_CTX * pool);

SF_ERROR    SF_GF2M_Div					(SF_BigInt *q, SF_BigInt *r, const SF_BigInt *n,
										 const SF_BigInt *d, SF_POOL_CTX * pool);

SF_ERROR    SF_GF2M_Mod					(SF_BigInt *r, const SF_BigInt *a, const SF_BigInt *m,
										 SF_POOL_CTX * pool);

SF_ERROR    SF_GF2M_ModMul				(SF_BigInt *r, const SF_BigInt *a, const SF_BigInt *b,
										 const SF_BigInt *m, SF_POOL_CTX * pool);

SF_ERROR    SF_GF2M_ModSqr				(SF_BigInt *r, const SF_BigInt *a, const SF_BigInt *m,
										 SF_POOL_CTX * pool);
void        SF_GF2M_Print				(const char *fmt, const SF_BigInt *a);

SF_ERROR    SF_GF2M_InvMAIA				(SF_BigInt *r, const SF_BigInt *a, const SF_BigInt *m,
										 SF_POOL_CTX * pool);

SF_ERROR    SF_GF2M_HfTr				(SF_BigInt *r, const SF_BigInt *a, const SF_BigInt *f,
										 SF_POOL_CTX * pool);

SF_ERROR    SF_GF2M_Tr					(SF_BigInt *r, const SF_BigInt *a, const SF_BigInt *f,
										 SF_POOL_CTX * pool);

SF_ERROR    SF_GF2M_SolveQuadEq1		(SF_BigInt *r, const SF_BigInt *a, const SF_BigInt *f,
										 SF_POOL_CTX * pool);

SF_ERROR    SF_GF2M_Str2Int				(SF_BigInt *r, const char *str);

int			SF_GF2M_GetExtDegree		(const SF_BigInt *a);


#ifdef __cplusplus
}
#endif

#endif

#endif	//_MIN_WCE