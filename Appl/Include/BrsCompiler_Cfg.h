#ifndef BRS_COMPILER_CFG_H
#define BRS_COMPILER_CFG_H

#include "Compiler_Cfg.h"

#if defined(_TASKING_C_TRICORE_)
# ifndef BRS_COMP_TASKING
#  define BRS_COMP_TASKING
# endif
# ifndef BRS_PLATFORM_AURIX
#  define BRS_PLATFORM_AURIX
# endif
#endif

#endif /* BRS_COMPILER_CFG_H */
