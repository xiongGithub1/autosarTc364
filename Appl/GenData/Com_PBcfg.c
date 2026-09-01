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
 *            Module: Com
 *           Program: MSR_Vector_SLP4
 *          Customer: China Lithium Battery Technology Co., Ltd.
 *       Expiry Date: 2025-08-26
 *  Ordered Derivat.: SAK-TC387QP-160F300S AE
 *    License Scope : The usage is restricted to CBD2200508_D00
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: Com_PBcfg.c
 *   Generation Time: 2026-08-27 16:11:54
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

/**********************************************************************************************************************
 * WARNING: This code has been generated with reduced-severity errors. 
 * The created output files contain errors that have been ignored. Usage of the created files can lead to unpredictable behavior of the embedded code.
 * Usage of the created files happens at own risk!
 * 
 * [Warning] COM02205 - Inconsistent signal layout. 
 * - [Reduced Severity due to User-Defined Parameter] /ActiveEcuC/EcuC/EcucPduCollection/msg_nm_MyECU_oCAN00_92bb24c1_Tx[0:PduLength](value=6) of /ActiveEcuC/Com/ComConfig/msg_nm_MyECU_oCAN00_92bb24c1_Tx cannot hold contained ComSignals / ComGroupSignals.
 * 
 * Exceeding signals:
 * /ActiveEcuC/Com/ComConfig/sig_NM_MyECU_UserData_5_omsg_nm_MyECU_oCAN00_e74864de_Tx
 * Erroneous configuration elements:
 * /ActiveEcuC/Com/ComConfig/sig_NM_MyECU_UserData_5_omsg_nm_MyECU_oCAN00_e74864de_Tx[0:ComBitPosition](value=48) (DefRef: /MICROSAR/Com/ComConfig/ComSignal/ComBitPosition)
 * /ActiveEcuC/Com/ComConfig/sig_NM_MyECU_UserData_5_omsg_nm_MyECU_oCAN00_e74864de_Tx[0:ComBitSize](value=8) (DefRef: /MICROSAR/Com/ComConfig/ComSignal/ComBitSize)
 * /ActiveEcuC/EcuC/EcucPduCollection/msg_nm_MyECU_oCAN00_92bb24c1_Tx[0:PduLength](value=6) (DefRef: /MICROSAR/EcuC/EcucPduCollection/Pdu/PduLength)
 * /ActiveEcuC/Com/ComConfig/msg_nm_MyECU_oCAN00_92bb24c1_Tx[5:ComIPduSignalRef](value=/ActiveEcuC/Com/ComConfig/sig_NM_MyECU_UserData_5_omsg_nm_MyECU_oCAN00_e74864de_Tx) (DefRef: /MICROSAR/Com/ComConfig/ComIPdu/ComIPduSignalRef)
 * /ActiveEcuC/Com/ComConfig/sig_NM_MyECU_UserData_5_omsg_nm_MyECU_oCAN00_e74864de_Tx[0:ComSignalEndianness](value=LITTLE_ENDIAN) (DefRef: /MICROSAR/Com/ComConfig/ComSignal/ComSignalEndianness)
 * /ActiveEcuC/Com/ComConfig/sig_NM_MyECU_UserData_5_omsg_nm_MyECU_oCAN00_e74864de_Tx[0:ComSignalType](value=UINT8) (DefRef: /MICROSAR/Com/ComConfig/ComSignal/ComSignalType)
 *********************************************************************************************************************/

/**********************************************************************************************************************
  MISRA / PClint JUSTIFICATIONS
**********************************************************************************************************************/

/**********************************************************************************************************************
  INCLUDES
**********************************************************************************************************************/
#define V_IL_ASRCOMCFG5_PBCFG_SOURCE

#include "Com_PBcfg.h"
#include "PduR_Com.h"

/**********************************************************************************************************************
  LOCAL CONSTANT MACROS
**********************************************************************************************************************/

/**********************************************************************************************************************
  LOCAL FUNCTION MACROS
**********************************************************************************************************************/

/**********************************************************************************************************************
  LOCAL DATA TYPES AND STRUCTURES
**********************************************************************************************************************/

/**********************************************************************************************************************
  LOCAL DATA PROTOTYPES
**********************************************************************************************************************/
/**********************************************************************************************************************
  CONFIGURATION CLASS: POST_BUILD
  SECTION: LOCAL DATA PROTOTYPES
**********************************************************************************************************************/


/**********************************************************************************************************************
  LOCAL DATA
**********************************************************************************************************************/
/**********************************************************************************************************************
  CONFIGURATION CLASS: POST_BUILD
  SECTION: LOCAL DATA
**********************************************************************************************************************/


/**********************************************************************************************************************
  GLOBAL DATA
**********************************************************************************************************************/
/**********************************************************************************************************************
  CONFIGURATION CLASS: POST_BUILD
  SECTION: GLOBAL DATA
**********************************************************************************************************************/


/**********************************************************************************************************************
  LOCAL FUNCTION PROTOTYPES
**********************************************************************************************************************/

/**********************************************************************************************************************
  LOCAL FUNCTIONS
**********************************************************************************************************************/

/**********************************************************************************************************************
  GLOBAL FUNCTIONS
**********************************************************************************************************************/

/**********************************************************************************************************************
  END OF FILE: Com_PBcfg.c
**********************************************************************************************************************/

