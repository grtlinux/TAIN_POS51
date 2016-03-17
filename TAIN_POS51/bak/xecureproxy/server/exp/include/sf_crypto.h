//
//	sf_crypto.h
//

#ifndef __SF_CRYPTO_H__
#define __SF_CRYPTO_H__

#include "sf_define.h"
#include "sf_error.h"

#include "sf_cipher.h"
#include "sf_hash.h"
#include "sf_mac.h"
#include "sf_rand.h"
#include "sf_pkey.h"
#include "sf_cmvp.h"

/**
 *	Constants
 */

/**
 *	Prototypes
 */

#ifdef __cplusplus
extern "C" {
#endif

char *		SF_GetVersion					(void);

char *		SF_GetErrorString				(const SF_ERROR errorCode);

#ifdef __cplusplus
}
#endif

#endif
