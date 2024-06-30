//######################################################################################################################
// File Name  : TC_OSGen7.lsl                                                                                          #
// Description: Linker/Symbol Preprocessor command file for UseCase OS-Core Gen7                                       #
// Project    : Vector Basic Runtime System                                                                            #
// Module     : BrsHw for Platform Aurix                                                                               #
//                                                                                                                     #
//---------------------------------------------------------------------------------------------------------------------#
// COPYRIGHT                                                                                                           #
//---------------------------------------------------------------------------------------------------------------------#
// Copyright (c) 2017 by Vector Informatik GmbH.                                                  All rights reserved. #
//                                                                                                                     #
//---------------------------------------------------------------------------------------------------------------------#
// AUTHOR IDENTITY                                                                                                     #
//---------------------------------------------------------------------------------------------------------------------#
// Name                          Initials      Company                                                                 #
// ----------------------------  ------------  ------------------------------------------------------------------------#
// Benjamin Walter               visbwa        Vector Informatik GmbH                                                  #
// Thomas Bintz                  vistbi        Vector Informatik GmbH                                                  #
//---------------------------------------------------------------------------------------------------------------------#
// REVISION HISTORY                                                                                                    #
//---------------------------------------------------------------------------------------------------------------------#
// Version   Date        Author  Description                                                                           #
// --------  ----------  ------  --------------------------------------------------------------------------------------#
// 01.00.00  2016-05-24  visbwa  Initial creation, tested with Os_CoreGen7@root[1.01.01]                               #
// 01.00.01  2016-06-15  visbwa  Harmonized linkage with OS-Team and enhanced support for all Aurix derivatives        #
// 01.00.02  2016-09-13  vistbi  Changed groups Executable/Constants from (clustered) to (contiguous) restriction      #
// 01.00.03  2017-04-12  visbwa  Fixed support for derivatives with less than 3 Cores                                  #
// 01.00.04  2026-06-27        Added Aurix 2G (TC37X/TC38X/TC39X) multi-core support for TC364 project                #
// 01.00.05  2026-06-30        last364: OS kernel stacks via OS_LINK_KERNEL_STACKS; TC_OS_ENABLE_CORE1 dual-core switch #
//######################################################################################################################

/*
 * last364 / TC364 (2-core device, currently single-core OS in DaVinci):
 *
 *   TC_OS_ENABLE_CORE1 = 0  (default)
 *     - OsNumberOfCores = 1, only Core0 GenData (no Os_Link_Core1*.lsl)
 *     - Core0 OS stacks/vars in dspr0; CodeConst at 0x80110000
 *
 *   TC_OS_ENABLE_CORE1 = 1  (after dual-core migration)
 *     1) DaVinci: OsNumberOfCores = 2, add OsCore1, regenerate GenData
 *     2) EcuM: EcuMSlaveCoreHandling = true (if using EcuM multi-core start)
 *     3) Set TC_OS_ENABLE_CORE1 to 1 below (or -DTC_OS_ENABLE_CORE1=1 in project)
 *     4) Full rebuild
 */
#ifndef TC_OS_ENABLE_CORE1
#define TC_OS_ENABLE_CORE1  0
#endif

#if (TC_OS_ENABLE_CORE1 == 1)
#if defined(__PROC_TC39X__) || defined(__PROC_TC38X__) || defined(__PROC_TC37X__) || defined(__PROC_TC36X__) || defined(__CPU_TC36X__)
#define TC_OS_MULTICORE_AURIX2G
#endif
#endif

#if defined(__PROC_TC29X__) || defined(__PROC_TC27X__) || defined(__PROC_TC26X__) || defined(TC_OS_MULTICORE_AURIX2G)
#define TC_OS_MULTICORE
#endif

#if defined(__PROC_TC29X__) || defined(__PROC_TC27X__) || defined(__PROC_TC39X__)
#define TC_OS_THREE_CORE
#endif

section_layout mpe:vtc:linear
{
  group Core0_RAM( ordered, contiguous, fill, run_addr = mem:mpe:dspr0 )
  {
    // stacks core 0
    group osAllStacksCore0(ordered, contiguous, fill, align=8)
    {
     #define OS_LINK_KERNEL_STACKS
     #include "GenData/Os_Link_Core0_Stacks.lsl"
    }

    // Variables of OS Applications
    group Var_NOINIT_Core0
    {
     #define OS_LINK_NOINIT_FAST
     #define OS_LINK_NOINIT
     #include "GenData/Os_Link_Core0.lsl"
     #undef OS_LINK_NOINIT_FAST
     #undef OS_LINK_NOINIT
    }
    group Var_INIT_Core0
    {
     #define OS_LINK_INIT_FAST
     #define OS_LINK_INIT
     #define OS_LINK_ZERO_INIT
     #include "GenData/Os_Link_Core0.lsl"
     #undef OS_LINK_INIT_FAST
     #undef OS_LINK_INIT
     #undef OS_LINK_ZERO_INIT
    }
  }

#if defined(TC_OS_MULTICORE)
  group Core1_RAM( ordered, contiguous, fill, run_addr = mem:mpe:dspr1 )
  {
    // stacks core 1
    group osAllStacksCore1(ordered, contiguous, fill, align=8)
    {
     #define OS_LINK_KERNEL_STACKS
     #include "GenData/Os_Link_Core1_Stacks.lsl"
    }

    // Variables of OS Applications:
    group Var_NOINIT_Core1
    {
     #define OS_LINK_NOINIT_FAST
     #define OS_LINK_NOINIT
     #include "GenData/Os_Link_Core1.lsl"
     #undef OS_LINK_NOINIT_FAST
     #undef OS_LINK_NOINIT
    }
    group Var_INIT_Core1
    {
     #define OS_LINK_INIT_FAST
     #define OS_LINK_INIT
     #define OS_LINK_ZERO_INIT
     #include "GenData/Os_Link_Core1.lsl"
     #undef OS_LINK_INIT_FAST
     #undef OS_LINK_INIT
     #undef OS_LINK_ZERO_INIT
    }
  }
#endif

#if defined(TC_OS_THREE_CORE)
  group Core2_RAM( ordered, contiguous, fill, run_addr = mem:mpe:dspr2 )
  {
    // stacks core 2
    group osAllStacksCore2(ordered, contiguous, fill, align=8)
    {
     #define OS_LINK_KERNEL_STACKS
     #include "GenData/Os_Link_Core2_Stacks.lsl"
    }

    // Variables of OS Applications:
    group Var_NOINIT_Core2
    {
     #define OS_LINK_NOINIT_FAST
     #define OS_LINK_NOINIT
     #include "GenData/Os_Link_Core2.lsl"
     #undef OS_LINK_NOINIT_FAST
     #undef OS_LINK_NOINIT
    }
    group Var_INIT_Core2
    {
     #define OS_LINK_INIT_FAST
     #define OS_LINK_INIT
     #define OS_LINK_ZERO_INIT
     #include "GenData/Os_Link_Core2.lsl"
     #undef OS_LINK_INIT_FAST
     #undef OS_LINK_INIT
     #undef OS_LINK_ZERO_INIT
    }
  }
#endif

  group NOCACHE (run_addr = mem:mpe:dspr0 )
  {
    group Var_NOCACHE_NOINIT_Core0
    {
     #define OS_LINK_NOCACHE_INIT_FAST
     #define OS_LINK_NOCACHE_INIT
     #define OS_LINK_NOCACHE_ZERO_INIT
     #include "GenData/Os_Link_Core0.lsl"
     #undef OS_LINK_NOCACHE_INIT_FAST
     #undef OS_LINK_NOCACHE_INIT
     #undef OS_LINK_NOCACHE_ZERO_INIT
    }
    group Var_NOCACHE_INIT_Core0
    {
     #define OS_LINK_NOCACHE_NOINIT_FAST
     #define OS_LINK_NOCACHE_NOINIT
     #include "GenData/Os_Link_Core0.lsl"
     #undef OS_LINK_NOCACHE_NOINIT_FAST
     #undef OS_LINK_NOCACHE_NOINIT
    }
#if defined(TC_OS_MULTICORE)
    group Var_NOCACHE_NOINIT_Core1
    {
     #define OS_LINK_NOCACHE_INIT_FAST
     #define OS_LINK_NOCACHE_INIT
     #define OS_LINK_NOCACHE_ZERO_INIT
     #include "GenData/Os_Link_Core1.lsl"
     #undef OS_LINK_NOCACHE_INIT_FAST
     #undef OS_LINK_NOCACHE_INIT
     #undef OS_LINK_NOCACHE_ZERO_INIT
    }
    group Var_NOCACHE_INIT_Core1
    {
     #define OS_LINK_NOCACHE_NOINIT_FAST
     #define OS_LINK_NOCACHE_NOINIT
     #include "GenData/Os_Link_Core1.lsl"
     #undef OS_LINK_NOCACHE_NOINIT_FAST
     #undef OS_LINK_NOCACHE_NOINIT
    }
#endif
#if defined(TC_OS_THREE_CORE)
    group Var_NOCACHE_NOINIT_Core2
    {
     #define OS_LINK_NOCACHE_INIT_FAST
     #define OS_LINK_NOCACHE_INIT
     #define OS_LINK_NOCACHE_ZERO_INIT
     #include "GenData/Os_Link_Core2.lsl"
     #undef OS_LINK_NOCACHE_INIT_FAST
     #undef OS_LINK_NOCACHE_INIT
     #undef OS_LINK_NOCACHE_ZERO_INIT
    }
    group Var_NOCACHE_INIT_Core2
    {
     #define OS_LINK_NOCACHE_NOINIT_FAST
     #define OS_LINK_NOCACHE_NOINIT
     #include "GenData/Os_Link_Core2.lsl"
     #undef OS_LINK_NOCACHE_NOINIT_FAST
     #undef OS_LINK_NOCACHE_NOINIT
    }
#endif

    group GlobalShared_NOCACHE
    {
     #define OS_LINK_NOCACHE_INIT
     #define OS_LINK_NOCACHE_ZERO_INIT
     #define OS_LINK_NOCACHE_NOINIT
     #define OS_LINK_SPINLOCKS
     #include "GenData/Os_Link.lsl"
     #undef OS_LINK_NOCACHE_INIT
     #undef OS_LINK_NOCACHE_ZERO_INIT
     #undef OS_LINK_NOCACHE_NOINIT
     #undef OS_LINK_SPINLOCKS
    }
  }

  group GlobalShared_CACHED ( align = 4 )
  {
   #define OS_LINK_INIT
   #define OS_LINK_ZERO_INIT
   #define OS_LINK_NOINIT
   #include "GenData/Os_Link.lsl"
   #undef OS_LINK_INIT
   #undef OS_LINK_ZERO_INIT
   #undef OS_LINK_NOINIT
  }

#if defined(TC_OS_MULTICORE)
  group CodeConst( run_addr = mem:mpe:pflash1 )
#else
  group CodeConst( ordered, run_addr = 0x80110000 )
#endif
  {
    group Executable (contiguous)
    {
     #define OS_LINK_CODE
     #define OS_LINK_INTVEC_CODE
     #define OS_LINK_CALLOUT_CODE
     #define OS_LINK_EXCVEC_CODE
     #include "GenData/Os_Link.lsl"
     /* Os_Link.lsl undefs OS_LINK_INTVEC_CODE; re-define for Os_Link_Core0.lsl */
     #define OS_LINK_INTVEC_CODE
     #include "GenData/Os_Link_Core0.lsl"
#if defined(TC_OS_MULTICORE)
     #include "GenData/Os_Link_Core1.lsl"
#endif
#if defined(TC_OS_THREE_CORE)
     #include "GenData/Os_Link_Core2.lsl"
#endif
     #undef OS_LINK_CODE
     #undef OS_LINK_INTVEC_CODE
     #undef OS_LINK_CALLOUT_CODE
     #undef OS_LINK_EXCVEC_CODE
     
      select ".text.sec_general_code";
    }

    group Constants (contiguous)
    {
     #define OS_LINK_CONST_FAST
     #define OS_LINK_CONST
     #include "GenData/Os_Link.lsl"
     #include "GenData/Os_Link_Core0.lsl"
#if defined(TC_OS_MULTICORE)
     #include "GenData/Os_Link_Core1.lsl"
#endif
#if defined(TC_OS_THREE_CORE)
     #include "GenData/Os_Link_Core2.lsl"
#endif
     #undef OS_LINK_CONST_FAST
     #undef OS_LINK_CONST
    }
  }
}
