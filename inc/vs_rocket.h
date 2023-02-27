#ifndef VS_ROCKET_H
#define VS_ROCKET_H

#if defined(__WIN32)
#error "Coming soon !"
#endif

/////////////////////////////
//
//		INCLUDES
//
/////////////////////////////

#include <stddef.h>
#include <stdint.h>
#include "vs_rocket_defs.h"
#include "vs_rocket_decoder.h"
#include "vs_rocket_encoder.h"
#include "vs_rocket_formatter.h"

/////////////////////////////
//
//		TYPEDEFS
//
/////////////////////////////

typedef enum vs_arch_flags_t vs_arch_flags_t;

/* CISC : Complexe Instruction Set Computer */
/* RISC : Reduced Instruction Set Computer */
typedef enum vs_isa_cisc_t vs_isa_cisc_t;

/////////////////////////////
//
//		ENUM
//
/////////////////////////////

enum vs_arch_flags_t
{
	VS_ARCH_X86 = 1 << 0,
	VS_ARCH_X64 = 1 << 1,
};

enum vs_isa_cisc_t
{
	VS_ISA_SET_INVALID,
	VS_ISA_SET_I386,
	VS_ISA_SET_I486,
	VS_ISA_SET_I86,
	VS_ISA_SET_LONGMODE,
	VS_ISA_SET_AMD
};

#endif
