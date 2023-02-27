#ifndef VS_ROCKET_DEFS_H
#define VS_ROCKET_DEFS_H

#include <string.h>

/////////////////////////////
//
//		DEFINES
//
/////////////////////////////

#define VS_MEMSET(a, b, c) (memset(a, b, c))
#define VS_MEMCPY(a, b, c) (memcpy(a, b, c))
#define VS_MEMMOVE(a, b, c) (memmove(a, b, c))
#define VS_MEMMEM(a, b, c, d) (memmem(a, b, c, d))
#define VS_MEMCHR(a, b, c) (memchr(a, b, c))
#define VS_STRLEN(a) (strlen(a))
#define VS_MEMCMP(a, b, c) (memcmp(a, b, c))
#define VS_PRINTF(a, ...) (printf(a, ...))
#define VS_ROCKET_SUCCESS(x) (x == 0)
#define VS_ROCKET_FAILED(x) (x != 0)

#endif
