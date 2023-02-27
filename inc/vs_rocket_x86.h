#ifndef VS_ROCKET_X86_H
#define VS_ROCKET_X86_H

/////////////////////////////
//
//		TYPEDEFS
//
/////////////////////////////

/*Enum for x86 8 bits registers*/
typedef enum	vs_enum_r8_t	vs_enum_r8_t;
/*Enum for x86 8 bits registers*/
typedef enum	vs_enum_r8_rex_t	vs_enum_r8_rex_t;
/*Enum for x86 16 bits registers*/
typedef enum	vs_enum_r16_t	vs_enum_r16_t;
/*Enum for x86 32 bits registers*/
typedef enum	vs_enum_r32_t	vs_enum_r32_t;
/*Enum for x86 64 bits registers*/
typedef enum	vs_enum_r64_t	vs_enum_r64_t;
/*Enum for x86 MM 64 bits registers*/
typedef enum	vs_enum_rmm_t	vs_enum_rmm_t;
/*Enum for x86 XMM 128 bits registers*/
typedef enum	vs_enum_rxmm_t	vs_enum_rxmm_t;
/*Enum for x86 Segments 16 bits registers*/
typedef enum	vs_enum_rseg_t	vs_enum_rseg_t;
/*Enum for x86 Control 16 bits registers*/
typedef enum	vs_enum_rcr_t	vs_enum_rcr_t;
/*Enum for x86 Debug 16 bits registers*/
typedef enum	vs_enum_rdr_t	vs_enum_rdr_t;

typedef struct vs_reg32_t	vs_reg32_t;
typedef struct vs_reg64_t	vs_reg64_t;

/////////////////////////////
//
//		ENUM
//
/////////////////////////////

enum	vs_enum_r8_t
{
	VS_REG_AL,
	VS_REG_CL,
	VS_REG_DL,
	VS_REG_BL,
	VS_REG_AH,
	VS_REG_CH,
	VS_REG_DH,
	VS_REG_BH
};

enum	vs_enum_r8_rex_t
{
	VS_REG_REX_AL,
	VS_REG_REX_CL,
	VS_REG_REX_DL,
	VS_REG_REX_BL,
	VS_REG_REX_SPL,
	VS_REG_REX_BPL,
	VS_REG_REX_SIL,
	VS_REG_REX_DIL,
	VS_REG_REX_R8B,
	VS_REG_REX_R9B,
	VS_REG_REX_R10B,
	VS_REG_REX_R11B,
	VS_REG_REX_R12B,
	VS_REG_REX_R13B,
	VS_REG_REX_R14B,
	VS_REG_REX_R15B
};

enum	vs_enum_r16_t
{
	VS_REG_AX,
	VS_REG_CX,
	VS_REG_DX,
	VS_REG_BX,
	VS_REG_SP,
	VS_REG_BP,
	VS_REG_SI,
	VS_REG_DI,
	VS_REG_REX_R8W,
	VS_REG_REX_R9W,
	VS_REG_REX_R10W,
	VS_REG_REX_R11W,
	VS_REG_REX_R12W,
	VS_REG_REX_R13W,
	VS_REG_REX_R14W,
	VS_REG_REX_R15W
};

enum	vs_enum_r32_t
{
	VS_REG_EAX,
	VS_REG_ECX,
	VS_REG_EDX,
	VS_REG_EBX,
	VS_REG_ESP,
	VS_REG_EBP,
	VS_REG_ESI,
	VS_REG_EDI,
	VS_REG_REX_R8D,
	VS_REG_REX_R9D,
	VS_REG_REX_R10D,
	VS_REG_REX_R11D,
	VS_REG_REX_R12D,
	VS_REG_REX_R13D,
	VS_REG_REX_R14D,
	VS_REG_REX_R15D
};

enum	vs_enum_r64_t
{
	VS_REG_RAX,
	VS_REG_RCX,
	VS_REG_RDX,
	VS_REG_RBX,
	VS_REG_RSP,
	VS_REG_RBP,
	VS_REG_RSI,
	VS_REG_RDI,
	VS_REG_REX_R8,
	VS_REG_REX_R9,
	VS_REG_REX_R10,
	VS_REG_REX_R11,
	VS_REG_REX_R12,
	VS_REG_REX_R13,
	VS_REG_REX_R14,
	VS_REG_REX_R15
};

enum	vs_enum_rmm_t
{
	VS_REG_MM0,
	VS_REG_MM1,
	VS_REG_MM2,
	VS_REG_MM3,
	VS_REG_MM4,
	VS_REG_MM5,
	VS_REG_MM6,
	VS_REG_MM7,
	VS_REG_REX_MM0,
	VS_REG_REX_MM1,
	VS_REG_REX_MM2,
	VS_REG_REX_MM3,
	VS_REG_REX_MM4,
	VS_REG_REX_MM5,
	VS_REG_REX_MM6,
	VS_REG_REX_MM7
};

enum	vs_enum_xmm_t
{
	VS_REG_XMM0,
	VS_REG_XMM1,
	VS_REG_XMM2,
	VS_REG_XMM3,
	VS_REG_XMM4,
	VS_REG_XMM5,
	VS_REG_XMM6,
	VS_REG_XMM7,
	VS_REG_REX_XMM8,
	VS_REG_REX_XMM9,
	VS_REG_REX_XMM10,
	VS_REG_REX_XMM11,
	VS_REG_REX_XMM12,
	VS_REG_REX_XMM13,
	VS_REG_REX_XMM14,
	VS_REG_REX_XMM15
};

enum	vs_enum_rseg_t
{
	VS_REG_ES,
	VS_REG_CS,
	VS_REG_SS,
	VS_REG_DS,
	VS_REG_FS,
	VS_REG_GS
};

enum	vs_enum_rcr_t
{
	VS_REG_CR0,
	VS_REG_CR2 = 2,
	VS_REG_CR3,
	VS_REG_CR4,
	VS_REG_CR8 = 8
};

enum	vs_enum_rdr_t
{
	VS_REG_DR0,
	VS_REG_DR1,
	VS_REG_DR2,
	VS_REG_DR3,
	VS_REG_DR4,
	VS_REG_DR5,
	VS_REG_DR6,
	VS_REG_DR7
};

#endif
