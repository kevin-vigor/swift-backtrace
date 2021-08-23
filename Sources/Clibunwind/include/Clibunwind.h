#define __OSX_AVAILABLE_STARTING(_osx, _ios)
#include "libunwind.h"

#if defined __i386__
#define UNW_TARGET      x86

typedef enum
{
    UNW_X86_EIP = 8,        /* frame-register */

    UNW_TDEP_IP = UNW_X86_EIP,
    UNW_TDEP_SP = UNW_X86_ESP,
    UNW_TDEP_EH = UNW_X86_EAX
}
x86_regnum_t;


#elif defined __x86_64__
#define UNW_TARGET              x86_64

typedef enum
{
    UNW_X86_64_RIP = 16,

    UNW_TDEP_IP = UNW_X86_64_RIP,
    UNW_TDEP_SP = UNW_X86_64_RSP,
    UNW_TDEP_BP = UNW_X86_64_RBP,
    UNW_TDEP_EH = UNW_X86_64_RAX
}
x86_64_regnum_t;

#elif defined __aarch64__

#define UNW_TARGET      aarch64
typedef enum
  {
    /* 64-bit general registers.  */
    UNW_AARCH64_X0,
    UNW_AARCH64_X1,
    UNW_AARCH64_X2,
    UNW_AARCH64_X3,
    UNW_AARCH64_X4,
    UNW_AARCH64_X5,
    UNW_AARCH64_X6,
    UNW_AARCH64_X7,
    UNW_AARCH64_X8,

    /* Temporary registers.  */
    UNW_AARCH64_X9,
    UNW_AARCH64_X10,
    UNW_AARCH64_X11,
    UNW_AARCH64_X12,
    UNW_AARCH64_X13,
    UNW_AARCH64_X14,
    UNW_AARCH64_X15,

    /* Intra-procedure-call temporary registers.  */
    UNW_AARCH64_X16,
    UNW_AARCH64_X17,

    /* Callee-saved registers.  */
    UNW_AARCH64_X18,
    UNW_AARCH64_X19,
    UNW_AARCH64_X20,
    UNW_AARCH64_X21,
    UNW_AARCH64_X22,
    UNW_AARCH64_X23,
    UNW_AARCH64_X24,
    UNW_AARCH64_X25,
    UNW_AARCH64_X26,
    UNW_AARCH64_X27,
    UNW_AARCH64_X28,

    /* 64-bit frame pointer.  */
    UNW_AARCH64_X29,

    /* 64-bit link register.  */
    UNW_AARCH64_X30,

    /* 64-bit stack pointer.  */
    UNW_AARCH64_SP =  31,
    UNW_AARCH64_PC,
    UNW_AARCH64_PSTATE,

    /* 128-bit FP/Advanced SIMD registers.  */
    UNW_AARCH64_V0 = 64,
    UNW_AARCH64_V1,
    UNW_AARCH64_V2,
    UNW_AARCH64_V3,
    UNW_AARCH64_V4,
    UNW_AARCH64_V5,
    UNW_AARCH64_V6,
    UNW_AARCH64_V7,
    UNW_AARCH64_V8,
    UNW_AARCH64_V9,
    UNW_AARCH64_V10,
    UNW_AARCH64_V11,
    UNW_AARCH64_V12,
    UNW_AARCH64_V13,
    UNW_AARCH64_V14,
    UNW_AARCH64_V15,
    UNW_AARCH64_V16,
    UNW_AARCH64_V17,
    UNW_AARCH64_V18,
    UNW_AARCH64_V19,
    UNW_AARCH64_V20,
    UNW_AARCH64_V21,
    UNW_AARCH64_V22,
    UNW_AARCH64_V23,
    UNW_AARCH64_V24,
    UNW_AARCH64_V25,
    UNW_AARCH64_V26,
    UNW_AARCH64_V27,
    UNW_AARCH64_V28,
    UNW_AARCH64_V29,
    UNW_AARCH64_V30,
    UNW_AARCH64_V31,

    UNW_AARCH64_FPSR,
    UNW_AARCH64_FPCR,

    /* For AArch64, the CFA is the value of SP (x31) at the call site of the
       previous frame.  */
    UNW_AARCH64_CFA = UNW_AARCH64_SP,

    UNW_TDEP_LAST_REG = UNW_AARCH64_FPCR,

    UNW_TDEP_IP = UNW_AARCH64_X30,
    UNW_TDEP_SP = UNW_AARCH64_SP,
    UNW_TDEP_EH = UNW_AARCH64_X0,

  }
aarch64_regnum_t;

#else
# error "Unsupported arch"
#endif

#define UNW_LOCAL_ONLY

#define UNW_PASTE2(x,y)    x##y
#define UNW_PASTE(x,y)    UNW_PASTE2(x,y)
#define UNW_OBJ(fn)    UNW_PASTE(UNW_PREFIX, fn)
#define UNW_ARCH_OBJ(fn) UNW_PASTE(UNW_PASTE(UNW_PASTE(_U,UNW_TARGET),_), fn)

#ifdef UNW_LOCAL_ONLY
# define UNW_PREFIX    UNW_PASTE(UNW_PASTE(_UL,UNW_TARGET),_)
#else /* !UNW_LOCAL_ONLY */
# define UNW_PREFIX    UNW_PASTE(UNW_PASTE(_U,UNW_TARGET),_)
#endif /* !UNW_LOCAL_ONLY */
