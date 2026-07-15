/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *
 *                 This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                 Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                 All other rights remain with Vector Informatik GmbH.
 *  \endverbatim
 *  -------------------------------------------------------------------------------------------------------------------
 *  LICENSE
 *  -------------------------------------------------------------------------------------------------------------------
 *            Module: EcuM
 *           Program: MSR_Vector_SLP4
 *          Customer: China Lithium Battery Technology Co., Ltd.
 *       Expiry Date: 2025-08-26
 *  Ordered Derivat.: SAK-TC387QP-160F300S AE
 *    License Scope : The usage is restricted to CBD2200508_D00
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: EcuM_Cfg.c
 *   Generation Time: 2024-07-09 14:04:08
 *           Project: last364 - Version 1.0
 *          Delivery: CBD2200508_D00
 *      Tool Version: DaVinci Configurator Classic (beta) 5.25.37 SP2
 *
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 ! BETA VERSION                                                                                                       !
 !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
 ! This version of DaVinci Configurator Classic and/or the related Basic Software Package is BETA software.               !
 ! BETA Software is basically operable, but not sufficiently tested, verified and/or qualified for use in series      !
 ! production and/or in vehicles operating on public or non-public roads.                                             !
 ! In particular, without limitation, BETA Software may cause unpredictable ECU behavior, may not provide all         !
 ! functions necessary for use in series production and/or may not comply with quality requirements which are         !
 ! necessary according to the state of the art. BETA Software must not be used in series production.                  !
 !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
**********************************************************************************************************************/




/***********************************************************************************************************************
 *  INCLUDES
 **********************************************************************************************************************/
/* PRQA S 0310 EOF */ /* MD_CSL_0310 */
#include "EcuM_Cbk.h"

#define ECUM_PRIVATE_CFG_PARTLY_INCLUDE
#include "EcuM_PrivateCfg.h"
#undef ECUM_PRIVATE_CFG_PARTLY_INCLUDE /* PRQA S 0841 */ /* MD_EcuM_0841 */

#if((ECUM_CHANNELOFWAKEUPSOURCELIST == STD_ON) ||(ECUM_PNCOFCOMMPNCS == STD_ON) || (ECUM_SUPPORT_COMM == STD_ON))
#include "ComM.h"
#endif

#if !defined (ECUM_LOCAL) /* COV_ECUM_LOCAL */
# define ECUM_LOCAL static
#endif

#if !defined (ECUM_LOCAL_INLINE) /* COV_ECUM_LOCAL_INLINE */
# define ECUM_LOCAL_INLINE LOCAL_INLINE
#endif 

/**********************************************************************************************************************
 *  LOCAL DATA PROTOTYPES
**********************************************************************************************************************/

/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: LOCAL DATA PROTOTYPES
**********************************************************************************************************************/


/**********************************************************************************************************************
 *  LOCAL DATA
**********************************************************************************************************************/
/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: LOCAL DATA
**********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA
**********************************************************************************************************************/
/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL DATA
**********************************************************************************************************************/
/**********************************************************************************************************************
  EcuM_DriverInitOne
**********************************************************************************************************************/
/** 
  \var    EcuM_DriverInitOne
  \details
  Element     Description
  Function
*/ 
#define ECUM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "EcuM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(EcuM_DriverInitOneType, ECUM_CONST) EcuM_DriverInitOne[1] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    Function              */
  { /*     0 */ EcuM_AL_DriverInitOne }
};
#define ECUM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "EcuM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  EcuM_DriverInitThree
**********************************************************************************************************************/
/** 
  \var    EcuM_DriverInitThree
  \details
  Element     Description
  Function
*/ 
#define ECUM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "EcuM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(EcuM_DriverInitThreeType, ECUM_CONST) EcuM_DriverInitThree[1] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    Function                */
  { /*     0 */ EcuM_AL_DriverInitThree }
};
#define ECUM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "EcuM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  EcuM_DriverInitTwo
**********************************************************************************************************************/
/** 
  \var    EcuM_DriverInitTwo
  \details
  Element     Description
  Function
*/ 
#define ECUM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "EcuM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(EcuM_DriverInitTwoType, ECUM_CONST) EcuM_DriverInitTwo[1] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    Function              */
  { /*     0 */ EcuM_AL_DriverInitTwo }
};
#define ECUM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "EcuM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  EcuM_WakeupSourceList
**********************************************************************************************************************/
/** 
  \var    EcuM_WakeupSourceList
  \brief  Contains all parameters configured for Wakeup Sources
  \details
  Element    Description
  Channel    Mapped ComM channel number - 255 if no ComM channel is assigned.
*/ 
#define ECUM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "EcuM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(EcuM_WakeupSourceListType, ECUM_CONST) EcuM_WakeupSourceList[6] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    Channel                                       Comment                                    Referable Keys */
  { /*     0 */ 255                                    },  /* [ECUM_WKSOURCE_POWER]          */  /* [/ActiveEcuC/EcuM/EcuMConfiguration/EcuMCommonConfiguration/ECUM_WKSOURCE_POWER, ECUM_WKSOURCE_POWER] */
  { /*     1 */ 255                                    },  /* [ECUM_WKSOURCE_RESET]          */  /* [/ActiveEcuC/EcuM/EcuMConfiguration/EcuMCommonConfiguration/ECUM_WKSOURCE_RESET, ECUM_WKSOURCE_RESET] */
  { /*     2 */ 255                                    },  /* [ECUM_WKSOURCE_INTERNAL_RESET] */  /* [/ActiveEcuC/EcuM/EcuMConfiguration/EcuMCommonConfiguration/ECUM_WKSOURCE_INTERNAL_RESET, ECUM_WKSOURCE_INTERNAL_RESET] */
  { /*     3 */ 255                                    },  /* [ECUM_WKSOURCE_INTERNAL_WDG]   */  /* [/ActiveEcuC/EcuM/EcuMConfiguration/EcuMCommonConfiguration/ECUM_WKSOURCE_INTERNAL_WDG, ECUM_WKSOURCE_INTERNAL_WDG] */
  { /*     4 */ 255                                    },  /* [ECUM_WKSOURCE_EXTERNAL_WDG]   */  /* [/ActiveEcuC/EcuM/EcuMConfiguration/EcuMCommonConfiguration/ECUM_WKSOURCE_EXTERNAL_WDG, ECUM_WKSOURCE_EXTERNAL_WDG] */
  { /*     5 */ ComMConf_ComMChannel_CN_CAN00_5e566ad9 }   /* [CN_CAN00_5e566ad9]            */  /* [/ActiveEcuC/EcuM/EcuMConfiguration/EcuMCommonConfiguration/CN_CAN00_5e566ad9, CN_CAN00_5e566ad9] */
};
#define ECUM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "EcuM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  EcuM_KillAllInProgress
**********************************************************************************************************************/
#define ECUM_START_SEC_VAR_NO_INIT_8
/*lint -save -esym(961, 19.1) */
#include "EcuM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(EcuM_KillAllInProgressType, ECUM_VAR_NO_INIT) EcuM_KillAllInProgress;  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
#define ECUM_STOP_SEC_VAR_NO_INIT_8
/*lint -save -esym(961, 19.1) */
#include "EcuM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  EcuM_ModuleState
**********************************************************************************************************************/
#define ECUM_START_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "EcuM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(EcuM_StateType, ECUM_VAR_NO_INIT) EcuM_ModuleState;  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
#define ECUM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "EcuM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  EcuM_PostRunRequestCounter
**********************************************************************************************************************/
#define ECUM_START_SEC_VAR_NO_INIT_8
/*lint -save -esym(961, 19.1) */
#include "EcuM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(EcuM_PostRunRequestCounterType, ECUM_VAR_NO_INIT) EcuM_PostRunRequestCounter;  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
#define ECUM_STOP_SEC_VAR_NO_INIT_8
/*lint -save -esym(961, 19.1) */
#include "EcuM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  EcuM_RunRequestCounter
**********************************************************************************************************************/
#define ECUM_START_SEC_VAR_NO_INIT_8
/*lint -save -esym(961, 19.1) */
#include "EcuM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(EcuM_RunRequestCounterType, ECUM_VAR_NO_INIT) EcuM_RunRequestCounter;  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
#define ECUM_STOP_SEC_VAR_NO_INIT_8
/*lint -save -esym(961, 19.1) */
#include "EcuM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  EcuM_Timer
**********************************************************************************************************************/
#define ECUM_START_SEC_VAR_NO_INIT_16
/*lint -save -esym(961, 19.1) */
#include "EcuM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(EcuM_TimerType, ECUM_VAR_NO_INIT) EcuM_Timer;  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
#define ECUM_STOP_SEC_VAR_NO_INIT_16
/*lint -save -esym(961, 19.1) */
#include "EcuM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  EcuM_UserTable
**********************************************************************************************************************/
/** 
  \var    EcuM_UserTable
  \brief  Contains a field for every configured EcuM User
*/ 
#define ECUM_START_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "EcuM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(EcuM_UserType, ECUM_VAR_NO_INIT) EcuM_UserTable[1];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
#define ECUM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "EcuM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */



/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL FUNCTIONS
**********************************************************************************************************************/




