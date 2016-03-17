//
//	sf_bigint.h
//

#ifndef __SF_BIGINT_H__
#define __SF_BIGINT_H__

#include "sf_define.h"
#include "sf_error.h"

/**
 *	Constants
 */

#define SF_WORD_MASK08					0xFFL		//	8 bit mask
#define SF_WORD_MASK16					0xFFFFL		// 16 bit mask
#define SF_WORD_MASK32					0xFFFFFFFFL	// 32 bit mask
#define SF_WORD_MASKMSB 				0x80000000L	// MSB of 32bit

#define	SF_WORD_BITS					32
#define	SF_WORD_BYTES					4

/**
 *	Struct
 */

typedef struct {
	int			MemLength;
	int			Length;
	int 		Sign;
	SF_WORD 	*Data;
} SF_BigInt;


typedef struct {
	SF_WORD		modInv;
	SF_BigInt	*temp;
} SF_MONT_CTX;


#define	SF_BIGINT_POOL_MAX_NODE_NUM		64

typedef struct {
	struct _node {
		SF_BigInt		*pBigInt;
		struct _node	*pNextNode;
	} Node[SF_BIGINT_POOL_MAX_NODE_NUM];

	struct _node		*pValidNode;
	struct _node		*pFreeNode;
} SF_POOL_CTX;

/**
 *	Error codes
 */

//	SF_COMMON_ERROR_INVALID_INPUT
//	SF_COMMON_ERROR_MALLOC_FAILED
//
//	SF_ASN1_ERROR_BAD_DATA
//	SF_ASN1_ERROR_BAD_LENGTH
//
//	SF_BIGINT_ERROR_GCD_IS_NOT_ONE

/**
 *	Prototypes
 */

#define		SF_BigInt_IsZero(x)			(((x)->Length == 1) && ((x)->Data[0] == 0))
#define		SF_BigInt_IsOne(x)			(((x)->Length == 1) && ((x)->Data[0] == 1))
#define		SF_BigInt_IsOdd(x)			((x)->Data[0] & 1)
#define		SF_BigInt_IsEven(x)			(((x)->Data[0] & 1) == 0)
#define		SF_BigInt_SetZero(x)		SF_BigInt_SetWord((x), 0)
#define		SF_BigInt_SetOne(x)			SF_BigInt_SetWord((x), 1)
#define		SF_BigInt_SetTop(x)			for ( ;(x)->Length > 1 && (x)->Data[(x)->Length-1] == 0; (x)->Length--)

#ifdef __cplusplus
extern "C" {
#endif

SF_BigInt  *SF_BigInt_New 				(const int wordLength);
void		SF_BigInt_Free				(SF_BigInt *x);

SF_ERROR 	SF_BigInt_Copy				(SF_BigInt *r, const SF_BigInt *a);
SF_BigInt  *SF_BigInt_Duplicate			(const SF_BigInt *a);
SF_ERROR	SF_BigInt_Realloc 			(SF_BigInt *x, const int wordLength);
SF_ERROR	SF_BigInt_Reset				(SF_BigInt *x, const int value);

int 		SF_BigInt_GetByteLength		(const SF_BigInt *a);
int 		SF_BigInt_GetBitLength		(const SF_BigInt *a);
int			SF_BigInt_IsBitSet			(const SF_BigInt *a, const int n);
SF_ERROR	SF_BigInt_SetBit			(SF_BigInt *a, const int n);
SF_ERROR	SF_BigInt_ClearBit			(SF_BigInt *a, const int n);
SF_ERROR	SF_BigInt_MaskBits			(SF_BigInt *a, const int n);

int 		SF_BigInt_AbsCmp		 	(const SF_BigInt *a, const SF_BigInt *b);
int 		SF_BigInt_Cmp	 			(const SF_BigInt *a, const SF_BigInt *b);

SF_ERROR	SF_BigInt_LeftShift			(SF_BigInt *r, const SF_BigInt *a, const int n);	// r = a << n
SF_ERROR	SF_BigInt_RightShift	 	(SF_BigInt *r, const SF_BigInt *a, const int n);	// r = a >> n

SF_ERROR	SF_BigInt_AbsInc			(SF_BigInt *x);	// x = x + 1
SF_ERROR	SF_BigInt_AbsDec			(SF_BigInt *x);	// x = x - 1
SF_ERROR	SF_BigInt_AbsAdd 			(SF_BigInt *r, const SF_BigInt *a, const SF_BigInt *b);
SF_ERROR	SF_BigInt_AbsSub 			(SF_BigInt *r, const SF_BigInt *a, const SF_BigInt *b);

SF_ERROR	SF_BigInt_Add 				(SF_BigInt *r, const SF_BigInt *a, const SF_BigInt *b);	// r = a + b
SF_ERROR	SF_BigInt_AddByWord			(SF_BigInt *r, const SF_BigInt *a, const SF_WORD w);
SF_ERROR	SF_BigInt_Sub 				(SF_BigInt *r, const SF_BigInt *a, const SF_BigInt *b);	// r = a - b
SF_ERROR	SF_BigInt_SubByWord			(SF_BigInt *r, const SF_BigInt *a, const SF_WORD w);
SF_ERROR	SF_BigInt_Mul				(SF_BigInt *r, const SF_BigInt *a, const SF_BigInt *b);	// r = a * b
SF_ERROR	SF_BigInt_MulByWord			(SF_BigInt *r, const SF_BigInt *a, const SF_WORD b);
SF_ERROR	SF_BigInt_Sqr				(SF_BigInt *r, const SF_BigInt *a);						// r = a^2
SF_ERROR	SF_BigInt_Div				(SF_BigInt *q, SF_BigInt *r, const SF_BigInt *a, 
										 const SF_BigInt *d, SF_POOL_CTX *pool);				// a = q * d + r
SF_ERROR	SF_BigInt_DivByWord			(SF_BigInt *q, SF_WORD *r, const SF_BigInt *a, 
										 const SF_WORD d);

// gcd

SF_ERROR	SF_BigInt_GCD 				(SF_BigInt *gcd, const SF_BigInt *a, const SF_BigInt *b,
										 SF_POOL_CTX *pool); 						// gcd = gcd(a, b)
SF_ERROR	SF_BigInt_ExtendedGCD 		(SF_BigInt *gcd, SF_BigInt *x, SF_BigInt *y, 
										 const SF_BigInt *a, const SF_BigInt *b,
										 SF_POOL_CTX *pool);						// xa + yb = gcd(a, b)

// mod

SF_ERROR	SF_BigInt_Mod				(SF_BigInt *r, const SF_BigInt *a, 
										 const SF_BigInt *m, SF_POOL_CTX *pool);	// r = a mod m
SF_WORD		SF_BigInt_ModByWord			(const SF_BigInt *a, const SF_WORD m);
SF_ERROR	SF_BigInt_ModAdd			(SF_BigInt *r, const SF_BigInt *a, const SF_BigInt *b,
										const SF_BigInt *m, SF_POOL_CTX *pool);		// r = a+b mod m
SF_ERROR	SF_BigInt_ModSub			(SF_BigInt *r, const SF_BigInt *a, const SF_BigInt *b,
										 const SF_BigInt *m, SF_POOL_CTX *pool);	// r = a+b mod m
SF_ERROR	SF_BigInt_ModMul			(SF_BigInt *r, const SF_BigInt *a, const SF_BigInt *b, 
										 const SF_BigInt *m, SF_POOL_CTX *pool);	// r = a*b mod m
SF_ERROR	SF_BigInt_ModExp			(SF_BigInt *r, const SF_BigInt *a, const SF_BigInt *e,
										 const SF_BigInt *m, SF_POOL_CTX *pool);	// r = a^e mod m
SF_ERROR	SF_BigInt_ModSqr			(SF_BigInt *r, const SF_BigInt *a, const SF_BigInt *m,
										SF_POOL_CTX *pool);							// r = a^2 mod m
SF_ERROR	SF_BigInt_ModSqrt			(SF_BigInt *r, const SF_BigInt *a, const SF_BigInt *m,
										SF_POOL_CTX *pool);							// r = a^{1/2} mod m

SF_ERROR	SF_BigInt_ModInverse		(SF_BigInt *r, const SF_BigInt *a, const SF_BigInt *m,
										 SF_POOL_CTX *pool); 						// r = a^{-1} mod m

// mont

SF_MONT_CTX *SF_MONT_CTX_New			(void);
void		SF_MONT_CTX_Free			(SF_MONT_CTX *mont);
SF_ERROR	SF_BigInt_MontInit			(SF_MONT_CTX *mont, SF_BigInt *r, const SF_BigInt *m, 
										 SF_POOL_CTX *pool);						// r = R^2 mod m, where R = b^(length od m)
SF_ERROR	SF_BigInt_MontReduction		(SF_MONT_CTX *mont, SF_BigInt *r, const SF_BigInt *a, 
										 const SF_BigInt *m);						// r = (a * R^{-1}) mod m
SF_ERROR	SF_BigInt_MontMul			(SF_MONT_CTX *mont, SF_BigInt *r, const SF_BigInt *a, 
										 const SF_BigInt *b, const SF_BigInt *m);	// r = (ab * R^{-1}) mod m
SF_ERROR	SF_BigInt_MontSqr			(SF_MONT_CTX *mont, SF_BigInt *r, const SF_BigInt *a, 
										 const SF_BigInt *m);						// r = (a^2 * R^{-1}) mod m

// prime

int			SF_BigInt_IsDivisible		(const SF_BigInt *input, const SF_WORD sieveSize);
int			SF_BigInt_IsPrime			(const SF_BigInt *prime, SF_POOL_CTX *pool);
SF_ERROR	SF_BigInt_GenerateRandom	(SF_BigInt *random, const SF_WORD byteLength);
SF_ERROR	SF_BigInt_GenerateRandomPrime(SF_BigInt *prime, const SF_WORD byteLength, 
										  SF_POOL_CTX *pool);
SF_ERROR	SF_BigInt_GenerateStrongPrime(SF_BigInt *prime, const SF_WORD byteLength, 
										  SF_POOL_CTX *pool);

// asn.1

int 		SF_BigInt_GetDerLength		(const SF_BigInt *input);
SF_ERROR	SF_BigInt_DerEncode			(SF_BYTE *output, SF_WORD *outputLength, const SF_BigInt *input);
SF_ERROR	SF_BigInt_DerDecode			(SF_BigInt *output, const SF_BYTE *input, const SF_WORD inputLength);

// pool

SF_POOL_CTX *SF_POOL_CTX_New			(void);
SF_BigInt  *SF_POOL_CTX_Pop				(SF_POOL_CTX *pool, const SF_WORD wordLength);
void		SF_POOL_CTX_Push			(SF_POOL_CTX *pool, SF_BigInt *input);
void		SF_POOL_CTX_Free			(SF_POOL_CTX *pool);

// misc
SF_ERROR	SF_BigInt_Lucas				(SF_BigInt *v, SF_BigInt *q, const SF_BigInt *P,
										const SF_BigInt *Q, const SF_BigInt *m,
										const SF_BigInt *k,	SF_POOL_CTX	*pool);

// util

int 		SF_BigInt_BinaryExpansion 	(SF_BYTE *x, const SF_BigInt *y);
SF_ERROR	SF_BigInt_BytesToInt		(SF_BigInt *x, const SF_BYTE *y, const int z);
SF_ERROR	SF_BigInt_IntToBytes		(SF_BYTE *x, const SF_BigInt *y, const int z);
SF_ERROR	SF_BigInt_Print				(char *output, const SF_BigInt *x);
SF_ERROR	SF_BigInt_HexToInt			(SF_BigInt *r, const char *hex);
SF_ERROR	SF_BigInt_SetWord			(SF_BigInt *a, const SF_WORD b);


#ifdef __cplusplus
}
#endif

#endif
