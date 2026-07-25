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
 *            Module: IpduM
 *           Program: MSR_Vector_SLP4
 *          Customer: China Lithium Battery Technology Co., Ltd.
 *       Expiry Date: 2025-08-26
 *  Ordered Derivat.: SAK-TC387QP-160F300S AE
 *    License Scope : The usage is restricted to CBD2200508_D00
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: IpduM_Cfg.h
 *   Generation Time: 2024-07-16 16:49:58
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


#if !defined (IPDUM_CFG_H)
# define IPDUM_CFG_H

/**********************************************************************************************************************
 * MISRA JUSTIFICATION
 *********************************************************************************************************************/
/* PRQA S 0785, 0786 EOF */ /* MD_CSL_DistinctIdentifiers */

/**********************************************************************************************************************
  INCLUDES
**********************************************************************************************************************/
# include "Platform_Types.h"
# include "ComStack_Types.h"

/**********************************************************************************************************************
  GLOBAL CONSTANT MACROS
**********************************************************************************************************************/
#ifndef IPDUM_USE_DUMMY_STATEMENT
#define IPDUM_USE_DUMMY_STATEMENT STD_OFF /* /MICROSAR/vSet/vSetGeneral/vSetDummyStatementKind */
#endif
#ifndef IPDUM_DUMMY_STATEMENT
#define IPDUM_DUMMY_STATEMENT(v)  /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */  /* /MICROSAR/vSet/vSetGeneral/vSetDummyStatementKind */
#endif
#ifndef IPDUM_DUMMY_STATEMENT_CONST
#define IPDUM_DUMMY_STATEMENT_CONST(v)  /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */  /* /MICROSAR/vSet/vSetGeneral/vSetDummyStatementKind */
#endif
#ifndef IPDUM_ATOMIC_BIT_ACCESS_IN_BITFIELD
#define IPDUM_ATOMIC_BIT_ACCESS_IN_BITFIELD STD_OFF /* /MICROSAR/EcuC/EcucGeneral/AtomicBitAccessInBitfield */
#endif
#ifndef IPDUM_ATOMIC_VARIABLE_ACCESS
#define IPDUM_ATOMIC_VARIABLE_ACCESS 32u /* /MICROSAR/EcuC/EcucGeneral/AtomicVariableAccess */
#endif
#ifndef IPDUM_PROCESSOR_TC387Q
#define IPDUM_PROCESSOR_TC387Q
#endif
#ifndef IPDUM_COMP_TASKING
#define IPDUM_COMP_TASKING
#endif
#ifndef IPDUM_GEN_GENERATOR_MSR
#define IPDUM_GEN_GENERATOR_MSR
#endif
#ifndef IPDUM_CPUTYPE_BITORDER_LSB2MSB
#define IPDUM_CPUTYPE_BITORDER_LSB2MSB /* /MICROSAR/vSet/vSetPlatform/vSetBitOrder */
#endif
#ifndef IPDUM_CONFIGURATION_VARIANT_PRECOMPILE
#define IPDUM_CONFIGURATION_VARIANT_PRECOMPILE 1
#endif
#ifndef IPDUM_CONFIGURATION_VARIANT_LINKTIME
#define IPDUM_CONFIGURATION_VARIANT_LINKTIME 2
#endif
#ifndef IPDUM_CONFIGURATION_VARIANT_POSTBUILD_LOADABLE
#define IPDUM_CONFIGURATION_VARIANT_POSTBUILD_LOADABLE 3
#endif
#ifndef IPDUM_CONFIGURATION_VARIANT
#define IPDUM_CONFIGURATION_VARIANT IPDUM_CONFIGURATION_VARIANT_PRECOMPILE
#endif
#ifndef IPDUM_POSTBUILD_VARIANT_SUPPORT
#define IPDUM_POSTBUILD_VARIANT_SUPPORT STD_OFF
#endif


#define IPDUM_DEV_ERROR_DETECT                 STD_ON  /**< /ActiveEcuC/IpduM/IpduMGeneral[0:IpduMSafeBswChecks] || /ActiveEcuC/IpduM/IpduMGeneral[0:IpduMDevErrorDetect] */
#define IPDUM_DEV_ERROR_REPORT                 STD_ON  /**< /ActiveEcuC/IpduM/IpduMGeneral[0:IpduMDevErrorDetect] */

#define IPDUM_LITTLE_ENDIAN                    0
#define IPDUM_BIG_ENDIAN                       1
#define IPDUM_HEADER_BYTE_ORDER                IPDUM_BIG_ENDIAN /**< /ActiveEcuC/IpduM/IpduMGeneral[0:IpduMHeaderByteOrder] */

#define IPDUM_VERSION_INFO_API                 STD_OFF  /**< /ActiveEcuC/IpduM/IpduMGeneral[0:IpduMVersionInfoApi] */
#define IPDUM_TRIGGER_TRANSMIT_API             STD_OFF  /**< /ActiveEcuC/PduR/IpduM[0:PduRTriggertransmit] */
#define IPDUM_TX_CONFIRMATION_API              STD_ON  /**< /ActiveEcuC/PduR/IpduM[0:PduRTxConfirmation] */







/**
 * \defgroup IpduMHandleIds Handle IDs.
 * \{
 */

/* Handle IDs active in all predefined variants (the application has not to take the active variant into account) */
/*      Symbolic Name                                                 Value   Active in predefined variant(s) */
#define IpduMConf_IpduMTxDynamicPart_msg_MyECU_Lamp_oCAN00_67614e93   1u
#define IpduMConf_IpduMTxDynamicPart_msg_MyECU_Lamp_oCAN00_abcb4e0d   2u
#define IpduMConf_IpduMTxDynamicPart_msg_MyECU_Lamp_oCAN00_e9ee4970   3u
#define IpduMConf_IpduMTxStaticPart_msg_MyECU_Lamp_oCAN00_6ae678ab    0u
/**\} */




/**
 * \defgroup IpduMHandleIds Handle IDs.
 * \{
 */

/* Handle IDs active in all predefined variants (the application has not to take the active variant into account) */
/*      Symbolic Name                                                 Value   Active in predefined variant(s) */
#define IpduMConf_IpduMTxRequest_IpduMTxRequest_30b6d8a0              0u
/**\} */

/* User Config File Start */

/* User Config File End */


/**********************************************************************************************************************
  GLOBAL FUNCTION MACROS
**********************************************************************************************************************/

/**********************************************************************************************************************
  GLOBAL DATA TYPES AND STRUCTURES
**********************************************************************************************************************/

/**********************************************************************************************************************
  GLOBAL DATA PROTOTYPES
**********************************************************************************************************************/

/**********************************************************************************************************************
  GLOBAL FUNCTION PROTOTYPES
**********************************************************************************************************************/

#endif  /* IPDUM_CFG_H */
/**********************************************************************************************************************
  END OF FILE: IpduM_Cfg.h
**********************************************************************************************************************/

