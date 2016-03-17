//
//  sf_ec.h
//
//WIN32_CE
#ifndef _MIN_WCE

#ifndef __SF_EC_H__
#define __SF_EC_H__

#include "sf_bigint.h"

/**
 *	Constants
 */

//	The following named curves are implemented where m is mandatory.
//
//		c2pnb163v1				= wtls (m)				= kcmvp
//		prime192v1	= secp192r1				= fipsp192	= kcmvp
//		prime256v1	= secp256r1				= fipsp256	= kcmvp
//		secp160r1				= wtls (m)
//		sect163k1				= wtls (m)	= fipsk163	= kcmvp
//		sect163r2							= fipsb163	= kcmvp
//		sect283k1							= fipsk283	= kcmvp
//		sect283r1							= fipsb283	= kcmvp
//

#define	SF_CHAR2				0x000100
#define SF_PRIME				0x000200
#define	SF_KOBLIZ				0x000400
#define	SF_X962					0x010000
#define	SF_SEC					0x020000

// X9.62 named curve for GF(2^m)
//
#define SF_EC_NCID_c2pnb163v1	(0x01 | SF_CHAR2 | SF_X962)	// = wtls (m)
#define SF_EC_NCID_c2pnb163v2	(0x02 | SF_CHAR2 | SF_X962)
#define SF_EC_NCID_c2pnb163v3	(0x03 | SF_CHAR2 | SF_X962)
#define SF_EC_NCID_c2pnb176w1   (0x04 | SF_CHAR2 | SF_X962)
#define SF_EC_NCID_c2tnb191v1   (0x05 | SF_CHAR2 | SF_X962)
#define SF_EC_NCID_c2tnb191v2   (0x06 | SF_CHAR2 | SF_X962)
#define SF_EC_NCID_c2tnb191v3   (0x07 | SF_CHAR2 | SF_X962)
#define SF_EC_NCID_c2onb191v4   (0x08 | SF_CHAR2 | SF_X962)
#define SF_EC_NCID_c2onb191v5   (0x09 | SF_CHAR2 | SF_X962)
#define SF_EC_NCID_c2pnb208w1   (0x0A | SF_CHAR2 | SF_X962)
#define SF_EC_NCID_c2tnb239v1   (0x0B | SF_CHAR2 | SF_X962)
#define SF_EC_NCID_c2tnb239v2   (0x0C | SF_CHAR2 | SF_X962)
#define SF_EC_NCID_c2tnb239v3   (0x0D | SF_CHAR2 | SF_X962)
#define SF_EC_NCID_c2onb239v4   (0x0E | SF_CHAR2 | SF_X962)
#define SF_EC_NCID_c2onb239v5   (0x0F | SF_CHAR2 | SF_X962)
#define SF_EC_NCID_c2pnb272w1   (0x10 | SF_CHAR2 | SF_X962)
#define SF_EC_NCID_c2pnb304w1   (0x11 | SF_CHAR2 | SF_X962)
#define SF_EC_NCID_c2tnb359v1   (0x12 | SF_CHAR2 | SF_X962)
#define SF_EC_NCID_c2pnb368w1   (0x13 | SF_CHAR2 | SF_X962)
#define SF_EC_NCID_c2tnb431r1   (0x14 | SF_CHAR2 | SF_X962)

// X9.62 named curve for GF(p)
//
#define SF_EC_NCID_prime192v1	(0x01 | SF_PRIME | SF_X962)	// = secp192r1 = fipsp192
#define SF_EC_NCID_prime192v2	(0x02 | SF_PRIME | SF_X962)
#define SF_EC_NCID_prime192v3	(0x03 | SF_PRIME | SF_X962)
#define SF_EC_NCID_prime239v1	(0x04 | SF_PRIME | SF_X962)
#define SF_EC_NCID_prime239v2	(0x05 | SF_PRIME | SF_X962)
#define SF_EC_NCID_prime239v3	(0x06 | SF_PRIME | SF_X962)
#define SF_EC_NCID_prime256v1	(0x07 | SF_PRIME | SF_X962)	// = secp256r1 = fipsp256

// SEC2 named curve for GF(p)
//
#define SF_EC_NCID_secp112r1	(0x01 | SF_PRIME | SF_SEC)
#define SF_EC_NCID_secp112r2	(0x02 | SF_PRIME | SF_SEC)
#define SF_EC_NCID_secp128r1	(0x03 | SF_PRIME | SF_SEC)
#define SF_EC_NCID_secp128r2	(0x04 | SF_PRIME | SF_SEC)
#define SF_EC_NCID_secp160k1	(0x05 | SF_PRIME | SF_SEC)
#define SF_EC_NCID_secp160r1	(0x06 | SF_PRIME | SF_SEC)	// = wtls (m)
#define SF_EC_NCID_secp160r2	(0x07 | SF_PRIME | SF_SEC)
#define SF_EC_NCID_secp192k1	(0x08 | SF_PRIME | SF_SEC)
#define SF_EC_NCID_secp192r1	(0x09 | SF_PRIME | SF_SEC)	// = prime192v1
#define SF_EC_NCID_secp224k1	(0x0A | SF_PRIME | SF_SEC)
#define SF_EC_NCID_secp224r1	(0x0B | SF_PRIME | SF_SEC)
#define SF_EC_NCID_secp256k1	(0x0C | SF_PRIME | SF_SEC)
#define SF_EC_NCID_secp256r1	(0x0D | SF_PRIME | SF_SEC)	// = prime256v1
#define SF_EC_NCID_secp384r1	(0x0E | SF_PRIME | SF_SEC)
#define SF_EC_NCID_secp521r1	(0x0F | SF_PRIME | SF_SEC)

// SEC2 named curve for GF(2^m)
//
#define SF_EC_NCID_sect113r1	(0x01 | SF_CHAR2 | SF_SEC)
#define SF_EC_NCID_sect113r2	(0x02 | SF_CHAR2 | SF_SEC)
#define SF_EC_NCID_sect131r1	(0x03 | SF_CHAR2 | SF_SEC)
#define SF_EC_NCID_sect131r2	(0x04 | SF_CHAR2 | SF_SEC)
#define SF_EC_NCID_sect163k1	(0x05 | SF_CHAR2 | SF_SEC)	// = wtls (m) = fipsk163
#define SF_EC_NCID_sect163r1	(0x06 | SF_CHAR2 | SF_SEC)
#define SF_EC_NCID_sect163r2	(0x07 | SF_CHAR2 | SF_SEC)	// = fipsb163
#define SF_EC_NCID_sect193r1	(0x08 | SF_CHAR2 | SF_SEC)
#define SF_EC_NCID_sect193r2	(0x09 | SF_CHAR2 | SF_SEC)
#define SF_EC_NCID_sect233k1	(0x0A | SF_CHAR2 | SF_SEC)
#define SF_EC_NCID_sect233r1	(0x0B | SF_CHAR2 | SF_SEC)
#define SF_EC_NCID_sect239k1	(0x0C | SF_CHAR2 | SF_SEC)
#define SF_EC_NCID_sect283k1	(0x0D | SF_CHAR2 | SF_SEC)	// = fipsk283
#define SF_EC_NCID_sect283r1	(0x0E | SF_CHAR2 | SF_SEC)	// = fipsb283
#define SF_EC_NCID_sect409k1	(0x0F | SF_CHAR2 | SF_SEC)
#define SF_EC_NCID_sect409r1	(0x10 | SF_CHAR2 | SF_SEC)
#define SF_EC_NCID_sect571k1	(0x11 | SF_CHAR2 | SF_SEC)
#define SF_EC_NCID_sect571r1	(0x12 | SF_CHAR2 | SF_SEC)

/**
 *	Struct
 */

typedef struct {
	SF_BigInt  *x;
	SF_BigInt  *y;
	SF_BigInt  *z;

	enum {
		EC_POINT_INFINITY = 0x1,
	} flag;
} SF_EC_Point;

typedef enum {
	// values as defined in X9.62 (ECDSA) and elsewhere
	POINT_CONV_COMPRESSED = 2,
	POINT_CONV_UNCOMPRESSED = 4,
	POINT_CONV_HYBRID = 6
} SF_EC_PointConv;

typedef struct _SF_EC_Method SF_EC_Method;
typedef struct _SF_EC_Group SF_EC_Group;

/**
 *	Macros
 */

#define	SF_EC_POINT_is_INFINITY(a)	((a)->flag & EC_POINT_INFINITY)
#define SF_EC_POINT_set_INFINITY(a) do { (a)->flag |= EC_POINT_INFINITY; SF_BigInt_SetWord((a)->z, 0); } while (0)
#define SF_EC_POINT_clear_INFINITY(a) ((a)->flag &= ~EC_POINT_INFINITY)

/**
 *	Error codes
 */

//  SF_COMMON_ERROR_INVALID_INPUT
//  SF_COMMON_ERROR_MALLOC_FAILED

//  SF_EC_ERROR_BAD_FIELD
//  SF_EC_ERROR_BAD_CONV_FORMAT
//  SF_EC_ERROR_POINT_INFINITY
//  SF_EC_ERROR_INPUT_TOO_LARGE

//  SF_EC_ERROR_NOT_IMPL_CURVE

/**
 *	Prototypes
 */

#ifdef __cplusplus
extern      "C" {
#endif

// basic
SF_EC_Group *SF_EC_Group_New			(const SF_EC_Method *meth);
void        SF_EC_Group_Reset			(SF_EC_Group *group);
void        SF_EC_Group_Free			(SF_EC_Group *group);

SF_ERROR    SF_EC_Group_Copy			(SF_EC_Group *dst, const SF_EC_Group *src);
SF_EC_Group *SF_EC_Group_Duplicate		(const SF_EC_Group *in);

SF_EC_Point *SF_EC_Point_New			(const SF_EC_Group *group);
void        SF_EC_Point_Clear			(SF_EC_Point *point);
void        SF_EC_Point_Reset			(SF_EC_Point *point);
void        SF_EC_Point_Free			(SF_EC_Point *point);

SF_ERROR    SF_EC_Point_Copy			(SF_EC_Point *dst, const SF_EC_Point *src);
SF_EC_Point *SF_EC_Point_Duplicate		(const SF_EC_Point *in);

SF_ERROR    SF_EC_SetGenerator			(SF_EC_Group *group, const SF_EC_Point *generator,
										 const SF_BigInt *order, const SF_BigInt *cofactor);
SF_ERROR    SF_EC_GetOrder				(const SF_EC_Group *group, SF_BigInt *order);
SF_ERROR    SF_EC_GetCofactor			(const SF_EC_Group *group, SF_BigInt *cofactor);
int         SF_EC_IsOnCurve				(const SF_EC_Group *group, const SF_EC_Point *point,
										 SF_POOL_CTX * pool);

// asn.1

SF_ERROR    SF_EC_Point_DerEncode		(SF_EC_Group *group, SF_BYTE * out, SF_WORD * outLen,
										 const int inSize, const SF_EC_Point *P);
SF_ERROR    SF_EC_Point_DerDecode		(SF_EC_Group *group, SF_EC_Point *P,
										 const SF_BYTE * in, const SF_WORD inLen);
SF_ERROR    SF_EC_Group_DerEncode		(SF_EC_Group *group, SF_BYTE * out, SF_WORD * outLen);
SF_ERROR    SF_EC_Group_DerDecode		(SF_EC_Group *group, const SF_BYTE * in, const SF_WORD inLen);

// arithmetic

SF_ERROR    SF_EC_Add					(const SF_EC_Group *group, SF_EC_Point *r,
										 const SF_EC_Point *a, const SF_EC_Point *b,
										 SF_POOL_CTX * pool);

SF_ERROR    SF_EC_Dbl					(const SF_EC_Group *group, SF_EC_Point *r,
										 const SF_EC_Point *a, SF_POOL_CTX * pool);

SF_ERROR    SF_EC_Inv					(const SF_EC_Group *group, SF_EC_Point *r,
										 const SF_EC_Point *a, SF_POOL_CTX * pool);

int         SF_EC_Cmp					(const SF_EC_Group *group, const SF_EC_Point *a,
										 const SF_EC_Point *b, SF_POOL_CTX * pool);

SF_ERROR    SF_EC_Mul					(const SF_EC_Group *group, SF_EC_Point *r,
										 const SF_EC_Point *a, const SF_BigInt *scalar,
										 SF_POOL_CTX * pool);
	
SF_ERROR    SF_EC_MulPre				(SF_EC_Group *group, SF_EC_Point *r,
										 const SF_EC_Point *a, const SF_BigInt *scalar,
										 SF_POOL_CTX * pool);
	
SF_ERROR    SF_EC_MulbNAF				(const SF_EC_Group *group, SF_EC_Point *r,
										 const SF_EC_Point *P, const SF_BigInt *scalar,
										 SF_POOL_CTX * pool);

SF_ERROR    SF_EC_MulwNAF				(const SF_EC_Group *group, SF_EC_Point *r,
										 const SF_EC_Point *P, const SF_BigInt *scalar,
										 SF_POOL_CTX * pool);

SF_ERROR    SF_EC_MulLL					(SF_EC_Group *group, SF_EC_Point *r,
										 const SF_EC_Point *P, const SF_BigInt *scalar,
										 SF_POOL_CTX * pool);

// utility

SF_ERROR    SF_EC_Point2Oct				(const SF_EC_Group *group, unsigned char *buf,
										 int *rlen, const int size,
										 const SF_EC_Point *point,
										 SF_EC_PointConv form,
										 SF_POOL_CTX * pool);

SF_ERROR    SF_EC_Oct2Point				(const SF_EC_Group *group, SF_EC_Point *point,
										 const unsigned char *buf, int len,
										 SF_POOL_CTX * pool);

int         SF_EC_GetFieldByteLength	(const SF_EC_Group *group);


SF_ERROR    SF_EC_SetAffCoordinate		(const SF_EC_Group *group, SF_EC_Point *point,
										 const SF_BigInt *x, const SF_BigInt *y,
										 SF_POOL_CTX * pool);

SF_ERROR    SF_EC_SetCompCoordinate		(const SF_EC_Group *group, SF_EC_Point *point,
										 const SF_BigInt *x, int y_bit,
										 SF_POOL_CTX * pool);

SF_ERROR    SF_EC_GetAffCoordinate		(const SF_EC_Group *group, SF_BigInt *x,
										 SF_BigInt *y, const SF_EC_Point *point,
										 SF_POOL_CTX * pool);

SF_ERROR    SF_EC_NCurve2OID			(SF_BYTE * oid, SF_WORD * rlen,
										 const SF_WORD size, const int ncid);

int         SF_EC_OID2NCurve			(const SF_BYTE * oid, const SF_WORD len);

SF_ERROR    SF_EC_SetNamedCurve			(SF_EC_Group *group, const int ncid,
										 SF_POOL_CTX * pool);

SF_EC_Point *SF_EC_GeneratorOf			(const SF_EC_Group *group);
SF_BigInt  *SF_EC_OrderOf				(const SF_EC_Group *group);

// GF(p)

SF_ERROR    SF_EC_GFp_SetCurve			(SF_EC_Group *group, const SF_BigInt *p,
										 const SF_BigInt *a, const SF_BigInt *b,
										 SF_POOL_CTX * pool);

// GF(2^m)

SF_ERROR    SF_EC_GF2m_SetCurve			(SF_EC_Group *group, const SF_BigInt *f,
										 const SF_BigInt *a, const SF_BigInt *b,
										 SF_POOL_CTX * pool);

void        SF_EC_Point_Print			(SF_EC_Group *group, const char c,
										 const SF_EC_Point *a);

const SF_EC_Method *SF_EC_Method_GF2m_PreComp();
const SF_EC_Method *SF_EC_Method_GF2m_Affine();
const SF_EC_Method *SF_EC_Method_GFp_PreComp();
const SF_EC_Method *SF_EC_Method_GFp_Affine();

#ifdef __cplusplus
}
#endif

#endif

#endif	//_MIN_WCE