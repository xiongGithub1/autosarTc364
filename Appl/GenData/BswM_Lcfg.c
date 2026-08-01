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
 *            Module: BswM
 *           Program: MSR_Vector_SLP4
 *          Customer: China Lithium Battery Technology Co., Ltd.
 *       Expiry Date: 2025-08-26
 *  Ordered Derivat.: SAK-TC387QP-160F300S AE
 *    License Scope : The usage is restricted to CBD2200508_D00
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: BswM_Lcfg.c
 *   Generation Time: 2026-07-31 20:00:46
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

#define BSWM_LCFG_SOURCE

/* -----------------------------------------------------------------------------
    &&&~ MISRA JUSTIFICATION
 ----------------------------------------------------------------------------- */
/* PRQA S 0785, 0786 EOF */ /* MD_CSL_DistinctIdentifiers */

/* -----------------------------------------------------------------------------
    &&&~ INCLUDE
 ----------------------------------------------------------------------------- */
/* PRQA S 0857 EOF */ /* MD_MSR_1.1_857 */
#include "BswM.h"
#include "BswM_Private_Cfg.h"
#include "SchM_BswM.h"

#if !defined (BSWM_LOCAL)
# define BSWM_LOCAL static
#endif

#if !defined (BSWM_LOCAL_INLINE) /* COV_BSWM_LOCAL_INLINE */
# define BSWM_LOCAL_INLINE LOCAL_INLINE
#endif



#define BSWM_START_SEC_CODE
/* PRQA S 5087 1 */ /* MD_MSR_MemMap */
#include "BswM_MemMap.h"

/* -----------------------------------------------------------------------------
    &&&~ LOCAL FUNCTION DECLARATIONS
 ----------------------------------------------------------------------------- */

/**********************************************************************************************************************
 *  BswM_UpdateRuleStates()
 **********************************************************************************************************************/
/*!
 * \brief       Updates the state of a rule.
 * \details     Set rule state of passed ruleId to passed state.
 * \param[in]   ruleId         Id of the rule to update.
 * \param[in]   state          New state of the rule.
 * \param[in]   partitionIdx   Current partition context.
 * \pre         -
 * \context     ANY
 * \reentrant   TRUE
 * \synchronous TRUE
 */
BSWM_LOCAL_INLINE FUNC(void, BSWM_CODE) BswM_UpdateRuleStates(BswM_SizeOfRuleStatesType ruleId, 
                                                              BswM_RuleStatesType state,
                                                              BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx);


/*! \addtogroup    BswMGeneratedFunctions BswM Generated Functions
 * \{
 */
/* PRQA S 0779 FUNCTIONDECLARATIONS */ /* MD_MSR_Rule5.2_0779 */

/**********************************************************************************************************************
 *  Init
 *********************************************************************************************************************/
/*! \defgroup    Init
 * \{
 */
/**********************************************************************************************************************
 *  BswM_InitGenVarAndInitAL_BSWM_SINGLEPARTITION
 *********************************************************************************************************************/
/*!
 * \brief       Initializes BswM.
 * \details     Part of the BswM_Init. Initializes all generated variables and executes action lists for initialization.
 * \pre         -
 * \reentrant   FALSE
 * \synchronous TRUE
 * \note        May only be called by BswM_Init.
 */
BSWM_LOCAL FUNC(void, BSWM_CODE) BswM_InitGenVarAndInitAL_BSWM_SINGLEPARTITION(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx);
/*! \} */ /* End of group Init */

/**********************************************************************************************************************
 *  BswMActionListFunctions
 *********************************************************************************************************************/
/*! \defgroup    BswMActionListFunctions
 * \{
 */

/*!
 * \{
 * \brief       Execute actions of action list.
 * \details     Generated function which depends on the configuration. Executes the actions of the action list in the
 *              configured order.
 * \return      E_OK      Action list was completely executed.
 * \return      E_NOT_OK  Action list was aborted because an action failed.
 * \pre         -
 * \context     ANY
 * \reentrant   TRUE
 * \synchronous TRUE
 */
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_ActionList_INIT_AL_Initialize(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx);
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_ActionList_CC_AL_CN_CAN00_5e566ad9_RX_Disable(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx);
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_ActionList_CC_AL_CN_CAN00_5e566ad9_RX_EnableNoinit(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx);
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_ActionList_CC_AL_CN_CAN00_5e566ad9_TX_Disable(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx);
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_ActionList_CC_AL_CN_CAN00_5e566ad9_TX_EnableNoinit(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx);
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_ActionList_CC_AL_CN_CAN00_5e566ad9_Disable_DM(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx);
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_ActionList_CC_AL_CN_CAN00_5e566ad9_Enable_DM(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx);
/*! \} */ /* End of sharing description for BswMActionListFunctions */
/*! \} */ /* End of group BswMActionListFunctions */

/**********************************************************************************************************************
 *  BswMRuleFunctions
 *********************************************************************************************************************/
/*! \defgroup    BswMRuleFunctions
 * \{
 */

/*!
 * \{
 * \brief       Arbitrates the configured rule.
 * \details     Generated function which depends on the configuration. Arbitrates the rule and returns the action list
 *              which shall be executed.
 * \return      ID of action list to execute (BSWM_NO_ACTIONLIST if no ActionList shall be executed)
 * \pre         -
 * \context     ANY
 * \reentrant   TRUE
 * \synchronous TRUE
 */
BSWM_LOCAL FUNC(BswM_HandleType, BSWM_CODE) BswM_Rule_CC_CN_CAN00_5e566ad9_RX(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx);
BSWM_LOCAL FUNC(BswM_HandleType, BSWM_CODE) BswM_Rule_CC_CN_CAN00_5e566ad9_TX(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx);
BSWM_LOCAL FUNC(BswM_HandleType, BSWM_CODE) BswM_Rule_CC_CN_CAN00_5e566ad9_RX_DM(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx);
/*! \} */ /* End of sharing description for BswMRuleFunctions */
/*! \} */ /* End of group BswMRuleFunctions */
/* PRQA L:FUNCTIONDECLARATIONS */
/*! \} */ /* End of group BswMGeneratedFunctions */

#define BSWM_STOP_SEC_CODE
/* PRQA S 5087 1 */ /* MD_MSR_MemMap */
#include "BswM_MemMap.h"


/* -----------------------------------------------------------------------------
    &&&~ LOCAL VARIABLE DECLARATIONS
 ----------------------------------------------------------------------------- */

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


/* PRQA S 0310 GLOBALDATADECLARATIONS */ /* MD_BSWM_0310 */ 
/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL DATA
**********************************************************************************************************************/
/**********************************************************************************************************************
  BswM_ActionLists
**********************************************************************************************************************/
/** 
  \var    BswM_ActionLists
  \details
  Element    Description
  FctPtr     Pointer to the array list function.
*/ 
#define BSWM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(BswM_ActionListsType, BSWM_CONST) BswM_ActionLists[7] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    FctPtr                                                         Comment                   Referable Keys */
  { /*     0 */ BswM_ActionList_INIT_AL_Initialize                      },  /* [Priority: 0] */  /* [AL_INIT_AL_Initialize] */
  { /*     1 */ BswM_ActionList_CC_AL_CN_CAN00_5e566ad9_RX_Disable      },  /* [Priority: 0] */  /* [AL_CC_AL_CN_CAN00_5e566ad9_RX_Disable] */
  { /*     2 */ BswM_ActionList_CC_AL_CN_CAN00_5e566ad9_RX_EnableNoinit },  /* [Priority: 0] */  /* [AL_CC_AL_CN_CAN00_5e566ad9_RX_EnableNoinit] */
  { /*     3 */ BswM_ActionList_CC_AL_CN_CAN00_5e566ad9_TX_Disable      },  /* [Priority: 0] */  /* [AL_CC_AL_CN_CAN00_5e566ad9_TX_Disable] */
  { /*     4 */ BswM_ActionList_CC_AL_CN_CAN00_5e566ad9_TX_EnableNoinit },  /* [Priority: 0] */  /* [AL_CC_AL_CN_CAN00_5e566ad9_TX_EnableNoinit] */
  { /*     5 */ BswM_ActionList_CC_AL_CN_CAN00_5e566ad9_Disable_DM      },  /* [Priority: 0] */  /* [AL_CC_AL_CN_CAN00_5e566ad9_Disable_DM] */
  { /*     6 */ BswM_ActionList_CC_AL_CN_CAN00_5e566ad9_Enable_DM       }   /* [Priority: 0] */  /* [AL_CC_AL_CN_CAN00_5e566ad9_Enable_DM] */
};
#define BSWM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  BswM_InitGenVarAndInitAL
**********************************************************************************************************************/
#define BSWM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(BswM_InitGenVarAndInitALType, BSWM_CONST) BswM_InitGenVarAndInitAL[1] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index     InitGenVarAndInitAL                            */
  /*     0 */ BswM_InitGenVarAndInitAL_BSWM_SINGLEPARTITION 
};
#define BSWM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  BswM_PartitionIdentifiers
**********************************************************************************************************************/
/** 
  \var    BswM_PartitionIdentifiers
  \brief  the partition context in Config
  \details
  Element                 Description
  PartitionSNV        
  PCPartitionConfigIdx    the index of the 1:1 relation pointing to BswM_PCPartitionConfig
*/ 
#define BSWM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(BswM_PartitionIdentifiersType, BSWM_CONST) BswM_PartitionIdentifiers[1] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    PartitionSNV          PCPartitionConfigIdx */
  { /*     0 */ BSWM_SINGLEPARTITION,                   0u }
};
#define BSWM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  BswM_Rules
**********************************************************************************************************************/
/** 
  \var    BswM_Rules
  \details
  Element          Description
  Id               External id of rule.
  RuleStatesIdx    the index of the 1:1 relation pointing to BswM_RuleStates
  FctPtr           Pointer to the rule function which does the arbitration.
*/ 
#define BSWM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(BswM_RulesType, BSWM_CONST) BswM_Rules[3] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    Id  RuleStatesIdx  FctPtr                                      Referable Keys */
  { /*     0 */ 0u,            0u, BswM_Rule_CC_CN_CAN00_5e566ad9_RX    },  /* [R_CC_CN_CAN00_5e566ad9_RX, MRP_CC_CanSMIndication_CN_CAN00_5e566ad9] */
  { /*     1 */ 2u,            1u, BswM_Rule_CC_CN_CAN00_5e566ad9_TX    },  /* [R_CC_CN_CAN00_5e566ad9_TX, MRP_CC_CanSMIndication_CN_CAN00_5e566ad9] */
  { /*     2 */ 1u,            2u, BswM_Rule_CC_CN_CAN00_5e566ad9_RX_DM }   /* [R_CC_CN_CAN00_5e566ad9_RX_DM, MRP_CC_CanSMIndication_CN_CAN00_5e566ad9] */
};
#define BSWM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  BswM_RulesInd
**********************************************************************************************************************/
/** 
  \var    BswM_RulesInd
  \brief  the indexes of the 1:1 sorted relation pointing to BswM_Rules
*/ 
#define BSWM_START_SEC_CONST_8
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(BswM_RulesIndType, BSWM_CONST) BswM_RulesInd[3] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index     RulesInd      Referable Keys */
  /*     0 */        0u,  /* [MRP_CC_CanSMIndication_CN_CAN00_5e566ad9] */
  /*     1 */        1u,  /* [MRP_CC_CanSMIndication_CN_CAN00_5e566ad9] */
  /*     2 */        2u   /* [MRP_CC_CanSMIndication_CN_CAN00_5e566ad9] */
};
#define BSWM_STOP_SEC_CONST_8
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  BswM_ActionListQueue
**********************************************************************************************************************/
/** 
  \var    BswM_ActionListQueue
  \brief  Variable to store action lists which shall be executed.
*/ 
#define BSWM_START_SEC_VAR_NO_INIT_8
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(BswM_ActionListQueueUType, BSWM_VAR_NO_INIT) BswM_ActionListQueue;  /* PRQA S 0759, 1514, 1533 */  /* MD_CSL_Union, MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys */
  /*     0 */  /* [AL_INIT_AL_Initialize] */
  /*     1 */  /* [AL_CC_AL_CN_CAN00_5e566ad9_RX_Disable] */
  /*     2 */  /* [AL_CC_AL_CN_CAN00_5e566ad9_RX_EnableNoinit] */
  /*     3 */  /* [AL_CC_AL_CN_CAN00_5e566ad9_TX_Disable] */
  /*     4 */  /* [AL_CC_AL_CN_CAN00_5e566ad9_TX_EnableNoinit] */
  /*     5 */  /* [AL_CC_AL_CN_CAN00_5e566ad9_Disable_DM] */
  /*     6 */  /* [AL_CC_AL_CN_CAN00_5e566ad9_Enable_DM] */

#define BSWM_STOP_SEC_VAR_NO_INIT_8
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  BswM_CanSMChannelState
**********************************************************************************************************************/
/** 
  \var    BswM_CanSMChannelState
  \brief  Variable to store current mode of BswMCanSMIndication mode request ports.
*/ 
#define BSWM_START_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(CanSM_BswMCurrentStateType, BSWM_VAR_NO_INIT) BswM_CanSMChannelState[1];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys */
  /*     0 */  /* [CANSM_CHANNEL_0, MRP_CC_CanSMIndication_CN_CAN00_5e566ad9] */

#define BSWM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  BswM_ForcedActionListPriority
**********************************************************************************************************************/
#define BSWM_START_SEC_VAR_NO_INIT_8
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(BswM_ForcedActionListPriorityType, BSWM_VAR_NO_INIT) BswM_ForcedActionListPriority;  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
#define BSWM_STOP_SEC_VAR_NO_INIT_8
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  BswM_Initialized
**********************************************************************************************************************/
#define BSWM_START_SEC_VAR_NO_INIT_8
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(BswM_InitializedType, BSWM_VAR_NO_INIT) BswM_Initialized;  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
#define BSWM_STOP_SEC_VAR_NO_INIT_8
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  BswM_ModeRequestQueue
**********************************************************************************************************************/
/** 
  \var    BswM_ModeRequestQueue
  \brief  Variable to store an immediate mode request which must be queued because of a current active arbitration.
*/ 
#define BSWM_START_SEC_VAR_NO_INIT_8
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(BswM_ModeRequestQueueType, BSWM_VAR_NO_INIT) BswM_ModeRequestQueue[1];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys */
  /*     0 */  /* [MRP_CC_CanSMIndication_CN_CAN00_5e566ad9, CANSM_CHANNEL_0] */

#define BSWM_STOP_SEC_VAR_NO_INIT_8
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  BswM_QueueSemaphore
**********************************************************************************************************************/
#define BSWM_START_SEC_VAR_NO_INIT_8
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(BswM_QueueSemaphoreType, BSWM_VAR_NO_INIT) BswM_QueueSemaphore;  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
#define BSWM_STOP_SEC_VAR_NO_INIT_8
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  BswM_QueueWritten
**********************************************************************************************************************/
#define BSWM_START_SEC_VAR_NO_INIT_8
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(BswM_QueueWrittenType, BSWM_VAR_NO_INIT) BswM_QueueWritten;  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
#define BSWM_STOP_SEC_VAR_NO_INIT_8
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  BswM_RuleStates
**********************************************************************************************************************/
/** 
  \var    BswM_RuleStates
  \brief  Stores the last execution state of the rule.
*/ 
#define BSWM_START_SEC_VAR_NO_INIT_8
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(BswM_RuleStatesUType, BSWM_VAR_NO_INIT) BswM_RuleStates;  /* PRQA S 0759, 1514, 1533 */  /* MD_CSL_Union, MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys */
  /*     0 */  /* [R_CC_CN_CAN00_5e566ad9_RX] */
  /*     1 */  /* [R_CC_CN_CAN00_5e566ad9_TX] */
  /*     2 */  /* [R_CC_CN_CAN00_5e566ad9_RX_DM] */

#define BSWM_STOP_SEC_VAR_NO_INIT_8
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */


/* PRQA L:GLOBALDATADECLARATIONS */

#define BSWM_START_SEC_VAR_NO_INIT_UNSPECIFIED
/* PRQA S 5087 1 */ /* MD_MSR_MemMap */
#include "BswM_MemMap.h"




VAR(boolean, BSWM_VAR_NO_INIT) BswM_PreInitialized;
#define BSWM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/* PRQA S 5087 1 */ /* MD_MSR_MemMap */
#include "BswM_MemMap.h"


#define BSWM_START_SEC_CODE
/* PRQA S 5087 1 */ /* MD_MSR_MemMap */
#include "BswM_MemMap.h"

/* -----------------------------------------------------------------------------
    &&&~ FUNCTIONS
 ----------------------------------------------------------------------------- */
 


/**********************************************************************************************************************
 *  BswM_UpdateRuleStates()
 **********************************************************************************************************************/
BSWM_LOCAL_INLINE FUNC(void, BSWM_CODE) BswM_UpdateRuleStates(BswM_SizeOfRuleStatesType ruleId, 
                                                                   BswM_RuleStatesType state,
                                                                   BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx)
{
  if (ruleId < BswM_GetSizeOfRuleStates(partitionIdx))
  {
    BswM_SetRuleStates(ruleId, state, partitionIdx); /* SBSW_BSWM_SETRULESTATE */
  }
  
  BSWM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
}


/**********************************************************************************************************************
 *  BswM_InitGenVarAndInitAL_BSWM_SINGLEPARTITION
 *********************************************************************************************************************/
BSWM_LOCAL FUNC(void, BSWM_CODE) BswM_InitGenVarAndInitAL_BSWM_SINGLEPARTITION(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx)
{

  (void)BswM_ActionList_INIT_AL_Initialize(partitionIdx);
  BSWM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
}

/**********************************************************************************************************************
 *  BswMActionListFunctions
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  BswM_ActionList_INIT_AL_Initialize
 *********************************************************************************************************************/
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_ActionList_INIT_AL_Initialize(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx)
{
  /*lint -save -e534 *//* PRQA S 3109, 3200 1 */ /* MD_MSR_14.3, MD_BSWM_3200 */
  Det_Init(Det_Config_Ptr);
  /*lint -restore */
  /*lint -save -e534 *//* PRQA S 3109, 3200 1 */ /* MD_MSR_14.3, MD_BSWM_3200 */
  ComM_PreInit(ComM_Config_Ptr);
  /*lint -restore */
  /*lint -save -e534 *//* PRQA S 3109, 3200 1 */ /* MD_MSR_14.3, MD_BSWM_3200 */
  E2EXf_Init(NULL_PTR);
  /*lint -restore */
  /*lint -save -e534 *//* PRQA S 3109, 3200 1 */ /* MD_MSR_14.3, MD_BSWM_3200 */
  Can_Init(Can_Config_Ptr);
  /*lint -restore */
  /*lint -save -e534 *//* PRQA S 3109, 3200 1 */ /* MD_MSR_14.3, MD_BSWM_3200 */
  CanIf_Init(CanIf_Config_Ptr);
  /*lint -restore */
  /*lint -save -e534 *//* PRQA S 3109, 3200 1 */ /* MD_MSR_14.3, MD_BSWM_3200 */
  Com_Init(Com_Config_Ptr);
  /*lint -restore */
  /*lint -save -e534 *//* PRQA S 3109, 3200 1 */ /* MD_MSR_14.3, MD_BSWM_3200 */
  PduR_Init(PduR_Config_Ptr);
  /*lint -restore */
  /*lint -save -e534 *//* PRQA S 3109, 3200 1 */ /* MD_MSR_14.3, MD_BSWM_3200 */
  CanSM_Init(CanSM_Config_Ptr);
  /*lint -restore */
  /*lint -save -e534 *//* PRQA S 3109, 3200 1 */ /* MD_MSR_14.3, MD_BSWM_3200 */
  NvM_Init();
  /*lint -restore */
  BswM_AL_SetProgrammableInterrupts();
  /*lint -save -e534 *//* PRQA S 3109, 3200 1 */ /* MD_MSR_14.3, MD_BSWM_3200 */
  ComM_Init(ComM_Config_Ptr);
  /*lint -restore */
  /*lint -save -e534 *//* PRQA S 3109, 3200 1 */ /* MD_MSR_14.3, MD_BSWM_3200 */
  ComM_PostInit();
  /*lint -restore */
  BSWM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  return E_OK;
}/* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/**********************************************************************************************************************
 *  BswM_ActionList_CC_AL_CN_CAN00_5e566ad9_RX_Disable
 *********************************************************************************************************************/
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_ActionList_CC_AL_CN_CAN00_5e566ad9_RX_Disable(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx)
{
  Com_IpduGroupStop(ComConf_ComIPduGroup_MyECU_oCAN00_Rx_4cbf71f7);
  BSWM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  return E_OK;
}/* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/**********************************************************************************************************************
 *  BswM_ActionList_CC_AL_CN_CAN00_5e566ad9_RX_EnableNoinit
 *********************************************************************************************************************/
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_ActionList_CC_AL_CN_CAN00_5e566ad9_RX_EnableNoinit(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx)
{
  Com_IpduGroupStart(ComConf_ComIPduGroup_MyECU_oCAN00_Rx_4cbf71f7, FALSE);
  BSWM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  return E_OK;
}/* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/**********************************************************************************************************************
 *  BswM_ActionList_CC_AL_CN_CAN00_5e566ad9_TX_Disable
 *********************************************************************************************************************/
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_ActionList_CC_AL_CN_CAN00_5e566ad9_TX_Disable(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx)
{
  Com_IpduGroupStop(ComConf_ComIPduGroup_MyECU_oCAN00_Tx_1ae5d671);
  BSWM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  return E_OK;
}/* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/**********************************************************************************************************************
 *  BswM_ActionList_CC_AL_CN_CAN00_5e566ad9_TX_EnableNoinit
 *********************************************************************************************************************/
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_ActionList_CC_AL_CN_CAN00_5e566ad9_TX_EnableNoinit(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx)
{
  Com_IpduGroupStart(ComConf_ComIPduGroup_MyECU_oCAN00_Tx_1ae5d671, FALSE);
  BSWM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  return E_OK;
}/* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/**********************************************************************************************************************
 *  BswM_ActionList_CC_AL_CN_CAN00_5e566ad9_Disable_DM
 *********************************************************************************************************************/
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_ActionList_CC_AL_CN_CAN00_5e566ad9_Disable_DM(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx)
{
  Com_DisableReceptionDM(ComConf_ComIPduGroup_MyECU_oCAN00_Rx_4cbf71f7);
  BSWM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  return E_OK;
}/* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/**********************************************************************************************************************
 *  BswM_ActionList_CC_AL_CN_CAN00_5e566ad9_Enable_DM
 *********************************************************************************************************************/
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_ActionList_CC_AL_CN_CAN00_5e566ad9_Enable_DM(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx)
{
  Com_EnableReceptionDM(ComConf_ComIPduGroup_MyECU_oCAN00_Rx_4cbf71f7);
  BSWM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  return E_OK;
}/* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/**********************************************************************************************************************
 *  BswMRuleFunctions
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  BswM_Rule_CC_CN_CAN00_5e566ad9_RX
 *********************************************************************************************************************/
BSWM_LOCAL FUNC(BswM_HandleType, BSWM_CODE) BswM_Rule_CC_CN_CAN00_5e566ad9_RX(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx)
{
  BswM_HandleType retVal = BSWM_NO_ACTIONLIST(partitionIdx);
  /* Evaluate logical expression CC_LE_CN_CAN00_5e566ad9_RX. */
  if(BswM_GetCanSMChannelState(0, 0u) != CANSM_BSWM_NO_COMMUNICATION)
  {
    if( BswM_GetRuleStates(BSWM_ID_RULE_CC_CN_CAN00_5e566ad9_RX, partitionIdx) != BSWM_TRUE ) /* COV_BSWM_TRIGGEREDRULEEXECUTION */
    {
      BswM_UpdateRuleStates(BSWM_ID_RULE_CC_CN_CAN00_5e566ad9_RX, BSWM_TRUE, partitionIdx);
      /* Return triggered action list BswM_ActionList_CC_AL_CN_CAN00_5e566ad9_RX_EnableNoinit. */
      retVal = BSWM_ID_AL_CC_AL_CN_CAN00_5e566ad9_RX_EnableNoinit;
    }
  }
  else
  {
    if( BswM_GetRuleStates(BSWM_ID_RULE_CC_CN_CAN00_5e566ad9_RX, partitionIdx) != BSWM_FALSE ) /* COV_BSWM_TRIGGEREDRULEEXECUTION */
    {
      BswM_UpdateRuleStates(BSWM_ID_RULE_CC_CN_CAN00_5e566ad9_RX, BSWM_FALSE, partitionIdx);
      /* Return triggered action list BswM_ActionList_CC_AL_CN_CAN00_5e566ad9_RX_Disable. */
      retVal = BSWM_ID_AL_CC_AL_CN_CAN00_5e566ad9_RX_Disable;
    }
  }
  BSWM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  return retVal;
}

/**********************************************************************************************************************
 *  BswM_Rule_CC_CN_CAN00_5e566ad9_TX
 *********************************************************************************************************************/
BSWM_LOCAL FUNC(BswM_HandleType, BSWM_CODE) BswM_Rule_CC_CN_CAN00_5e566ad9_TX(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx)
{
  BswM_HandleType retVal = BSWM_NO_ACTIONLIST(partitionIdx);
  /* Evaluate logical expression CC_LE_CN_CAN00_5e566ad9_TX. */
  if(BswM_GetCanSMChannelState(0, 0u) == CANSM_BSWM_FULL_COMMUNICATION)
  {
    if( BswM_GetRuleStates(BSWM_ID_RULE_CC_CN_CAN00_5e566ad9_TX, partitionIdx) != BSWM_TRUE ) /* COV_BSWM_TRIGGEREDRULEEXECUTION */
    {
      BswM_UpdateRuleStates(BSWM_ID_RULE_CC_CN_CAN00_5e566ad9_TX, BSWM_TRUE, partitionIdx);
      /* Return triggered action list BswM_ActionList_CC_AL_CN_CAN00_5e566ad9_TX_EnableNoinit. */
      retVal = BSWM_ID_AL_CC_AL_CN_CAN00_5e566ad9_TX_EnableNoinit;
    }
  }
  else
  {
    if( BswM_GetRuleStates(BSWM_ID_RULE_CC_CN_CAN00_5e566ad9_TX, partitionIdx) != BSWM_FALSE ) /* COV_BSWM_TRIGGEREDRULEEXECUTION */
    {
      BswM_UpdateRuleStates(BSWM_ID_RULE_CC_CN_CAN00_5e566ad9_TX, BSWM_FALSE, partitionIdx);
      /* Return triggered action list BswM_ActionList_CC_AL_CN_CAN00_5e566ad9_TX_Disable. */
      retVal = BSWM_ID_AL_CC_AL_CN_CAN00_5e566ad9_TX_Disable;
    }
  }
  BSWM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  return retVal;
}

/**********************************************************************************************************************
 *  BswM_Rule_CC_CN_CAN00_5e566ad9_RX_DM
 *********************************************************************************************************************/
BSWM_LOCAL FUNC(BswM_HandleType, BSWM_CODE) BswM_Rule_CC_CN_CAN00_5e566ad9_RX_DM(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx)
{
  BswM_HandleType retVal = BSWM_NO_ACTIONLIST(partitionIdx);
  /* Evaluate logical expression CC_LE_CN_CAN00_5e566ad9_RX_DM. */
  if(BswM_GetCanSMChannelState(0, 0u) == CANSM_BSWM_FULL_COMMUNICATION)
  {
    if( BswM_GetRuleStates(BSWM_ID_RULE_CC_CN_CAN00_5e566ad9_RX_DM, partitionIdx) != BSWM_TRUE ) /* COV_BSWM_TRIGGEREDRULEEXECUTION */
    {
      BswM_UpdateRuleStates(BSWM_ID_RULE_CC_CN_CAN00_5e566ad9_RX_DM, BSWM_TRUE, partitionIdx);
      /* Return triggered action list BswM_ActionList_CC_AL_CN_CAN00_5e566ad9_Enable_DM. */
      retVal = BSWM_ID_AL_CC_AL_CN_CAN00_5e566ad9_Enable_DM;
    }
  }
  else
  {
    if( BswM_GetRuleStates(BSWM_ID_RULE_CC_CN_CAN00_5e566ad9_RX_DM, partitionIdx) != BSWM_FALSE ) /* COV_BSWM_TRIGGEREDRULEEXECUTION */
    {
      BswM_UpdateRuleStates(BSWM_ID_RULE_CC_CN_CAN00_5e566ad9_RX_DM, BSWM_FALSE, partitionIdx);
      /* Return triggered action list BswM_ActionList_CC_AL_CN_CAN00_5e566ad9_Disable_DM. */
      retVal = BSWM_ID_AL_CC_AL_CN_CAN00_5e566ad9_Disable_DM;
    }
  }
  BSWM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  return retVal;
}


#define BSWM_STOP_SEC_CODE
/* PRQA S 5087 1 */ /* MD_MSR_MemMap */
#include "BswM_MemMap.h"

