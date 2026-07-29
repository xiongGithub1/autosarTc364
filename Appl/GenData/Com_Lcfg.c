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
 *              File: Com_Lcfg.c
 *   Generation Time: 2026-07-29 10:31:06
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
  MISRA / PClint JUSTIFICATIONS
**********************************************************************************************************************/

/**********************************************************************************************************************
  INCLUDES
**********************************************************************************************************************/
#define V_IL_ASRCOMCFG5_LCFG_SOURCE

#include "Com.h"
#include "Com_Timer.h"
#include "Com_TxModeHdlr.h"
#include "Com_LLIf.h"
#include "Com_MainFunctions.h"


#include "SchM_Com.h"

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
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: LOCAL DATA PROTOTYPES
**********************************************************************************************************************/

/**********************************************************************************************************************
  CONFIGURATION CLASS: LINK
  SECTION: LOCAL DATA PROTOTYPES
**********************************************************************************************************************/


/**********************************************************************************************************************
  LOCAL DATA
**********************************************************************************************************************/
/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: LOCAL DATA
**********************************************************************************************************************/

/**********************************************************************************************************************
  CONFIGURATION CLASS: LINK
  SECTION: LOCAL DATA
**********************************************************************************************************************/


/**********************************************************************************************************************
  GLOBAL DATA
**********************************************************************************************************************/
/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL DATA
**********************************************************************************************************************/
/**********************************************************************************************************************
  Com_ConstValueUInt8
**********************************************************************************************************************/
/** 
  \var    Com_ConstValueUInt8
  \brief  Optimized array of commonly used values like initial or invalid values. (BOOLEAN, UINT8)
*/ 
#define COM_START_SEC_CONST_8
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Com_ConstValueUInt8Type, COM_CONST) Com_ConstValueUInt8[1] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index     ConstValueUInt8      Referable Keys */
  /*     0 */            0x00u   /* [/ActiveEcuC/Com/ComConfig/sig_State_RearLeftDoor_omsg_Receive_oCAN00_84ad4140_RxInitValue, /ActiveEcuC/Com/ComConfig/sig_State_RearRightDoor_omsg_Receive_oCAN00_a8945098_RxInitValue] */
};
#define COM_STOP_SEC_CONST_8
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Com_IPduGroupInfo
**********************************************************************************************************************/
/** 
  \var    Com_IPduGroupInfo
  \brief  Contains all I-Pdu Group relevant information
  \details
  Element                                    Description
  IPduGroupInfoToSubIPduGroupsIndStartIdx    the start index of the 0:n relation pointing to Com_IPduGroupInfoToSubIPduGroupsInd
  PartitionsRxStructIdx                      the index of the 0:1 relation pointing to Com_PartitionsRxStruct
  PartitionsTxStructIdx                      the index of the 0:1 relation pointing to Com_PartitionsTxStruct
  RxPduInfoIndEndIdx                         the end index of the 0:n relation pointing to Com_RxPduInfoInd
  RxPduInfoIndStartIdx                       the start index of the 0:n relation pointing to Com_RxPduInfoInd
  TxPduInfoIndEndIdx                         the end index of the 0:n relation pointing to Com_TxPduInfoInd
  TxPduInfoIndStartIdx                       the start index of the 0:n relation pointing to Com_TxPduInfoInd
*/ 
#define COM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Com_IPduGroupInfoType, COM_CONST) Com_IPduGroupInfo[2] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    IPduGroupInfoToSubIPduGroupsIndStartIdx  PartitionsRxStructIdx  PartitionsTxStructIdx  RxPduInfoIndEndIdx                        RxPduInfoIndStartIdx                        TxPduInfoIndEndIdx                        TxPduInfoIndStartIdx                              Referable Keys */
  { /*     0 */                                      0u,                    0u,                    0u,                                       1u,                                         0u, COM_NO_TXPDUINFOINDENDIDXOFIPDUGROUPINFO, COM_NO_TXPDUINFOINDSTARTIDXOFIPDUGROUPINFO },  /* [/ActiveEcuC/Com/ComConfig/MyECU_oCAN00_Rx_4cbf71f7, /ActiveEcuC/Com/ComConfig/msg_Receive_oCAN00_2b456e3f_Rx] */
  { /*     1 */                                      1u,                    0u,                    0u, COM_NO_RXPDUINFOINDENDIDXOFIPDUGROUPINFO, COM_NO_RXPDUINFOINDSTARTIDXOFIPDUGROUPINFO,                                       5u,                                         0u }   /* [/ActiveEcuC/Com/ComConfig/MyECU_oCAN00_Tx_1ae5d671, /ActiveEcuC/Com/ComConfig/msg_MyECU_Lamp_MxA0_oCAN00_b76f77a4_Tx, /ActiveEcuC/Com/ComConfig/msg_MyECU_Lamp_MxA1_oCAN00_7bc5773a_Tx, /ActiveEcuC/Com/ComConfig/msg_MyECU_Lamp_MxA2_oCAN00_f54a70d9_Tx, /ActiveEcuC/Com/ComConfig/msg_MyECU_Lamp_Mx_oCAN00_e57ca999_Tx, /ActiveEcuC/Com/ComConfig/msg_Transmit_oCAN00_0723e95e_Tx] */
};
#define COM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Com_IPduGroupInfoOfTxPduInfoInd
**********************************************************************************************************************/
/** 
  \var    Com_IPduGroupInfoOfTxPduInfoInd
  \brief  the indexes of the 1:1 sorted relation pointing to Com_IPduGroupInfo
*/ 
#define COM_START_SEC_CONST_8
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Com_IPduGroupInfoOfTxPduInfoIndType, COM_CONST) Com_IPduGroupInfoOfTxPduInfoInd[5] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index     IPduGroupInfoOfTxPduInfoInd      Referable Keys */
  /*     0 */                           1u,  /* [/ActiveEcuC/Com/ComConfig/msg_MyECU_Lamp_MxA0_oCAN00_b76f77a4_Tx] */
  /*     1 */                           1u,  /* [/ActiveEcuC/Com/ComConfig/msg_MyECU_Lamp_MxA1_oCAN00_7bc5773a_Tx] */
  /*     2 */                           1u,  /* [/ActiveEcuC/Com/ComConfig/msg_MyECU_Lamp_MxA2_oCAN00_f54a70d9_Tx] */
  /*     3 */                           1u,  /* [/ActiveEcuC/Com/ComConfig/msg_MyECU_Lamp_Mx_oCAN00_e57ca999_Tx] */
  /*     4 */                           1u   /* [/ActiveEcuC/Com/ComConfig/msg_Transmit_oCAN00_0723e95e_Tx] */
};
#define COM_STOP_SEC_CONST_8
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Com_MainFunctionRxStruct
**********************************************************************************************************************/
/** 
  \var    Com_MainFunctionRxStruct
  \details
  Element                                 Description
  RxPduInfoOfMainFunctionRxIndStartIdx    the start index of the 0:n relation pointing to Com_RxPduInfoOfMainFunctionRxInd
*/ 
#define COM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Com_MainFunctionRxStructType, COM_CONST) Com_MainFunctionRxStruct[1] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    RxPduInfoOfMainFunctionRxIndStartIdx        Referable Keys */
  { /*     0 */                                   0u }   /* [ComMainFunctionRx] */
};
#define COM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Com_MainFunctionTxStruct
**********************************************************************************************************************/
/** 
  \var    Com_MainFunctionTxStruct
  \details
  Element                                   Description
  TxCyclicPduOfMainFunctionTxIndStartIdx    the start index of the 0:n relation pointing to Com_TxCyclicPduOfMainFunctionTxInd
  TxPduInfoOfMainFunctionTxIndStartIdx      the start index of the 0:n relation pointing to Com_TxPduInfoOfMainFunctionTxInd
*/ 
#define COM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Com_MainFunctionTxStructType, COM_CONST) Com_MainFunctionTxStruct[1] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    TxCyclicPduOfMainFunctionTxIndStartIdx  TxPduInfoOfMainFunctionTxIndStartIdx        Referable Keys */
  { /*     0 */                                     0u,                                   0u }   /* [ComMainFunctionTx] */
};
#define COM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Com_RxAccessInfo
**********************************************************************************************************************/
/** 
  \var    Com_RxAccessInfo
  \brief  Contains all signal layout information necessary for signal access within an I-PDU.
  \details
  Element               Description
  DynSignal             TRUE if the Signal is a dynamic length signal (UINT8_DYN), FALSE otherwise.
  Buffer                the enum value of the according target of the 0:1 relation pointing to Com_RxSigBufferUInt8,Com_RxSigBufferUInt16,Com_RxSigBufferUInt32,Com_RxSigBufferUInt64,Com_RxSigBufferZeroBit,Com_RxSigBufferSInt8,Com_RxSigBufferSInt16,Com_RxSigBufferSInt32,Com_RxSigBufferSInt64,Com_RxSigBufferFloat32,Com_RxSigBufferFloat64
  BufferIdx             the index of the 0:1 relation pointing to Com_RxSigBufferUInt8,Com_RxSigBufferUInt16,Com_RxSigBufferUInt32,Com_RxSigBufferUInt64,Com_RxSigBufferZeroBit,Com_RxSigBufferSInt8,Com_RxSigBufferSInt16,Com_RxSigBufferSInt32,Com_RxSigBufferSInt64,Com_RxSigBufferFloat32,Com_RxSigBufferFloat64
  InitValueIdx          the index of the 0:1 relation pointing to Com_ConstValueUInt8,Com_ConstValueUInt16,Com_ConstValueUInt32,Com_ConstValueUInt64,Com_ConstValueSInt8,Com_ConstValueSInt16,Com_ConstValueSInt32,Com_ConstValueSInt64,Com_ConstValueFloat32,Com_ConstValueFloat64
  SignalLengthInByte    The length of the Signal/GroupSignal in Byte
*/ 
#define COM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Com_RxAccessInfoType, COM_CONST) Com_RxAccessInfo[2] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    DynSignal  Buffer                                     BufferIdx  InitValueIdx  SignalLengthInByte        Referable Keys */
  { /*     0 */     FALSE, COM_RXSIGBUFFERUINT8_BUFFEROFRXACCESSINFO,        0u,           0u,                 1u },  /* [/ActiveEcuC/Com/ComConfig/sig_State_RearLeftDoor_omsg_Receive_oCAN00_84ad4140_Rx, /ActiveEcuC/Com/ComConfig/msg_Receive_oCAN00_2b456e3f_Rx] */
  { /*     1 */     FALSE, COM_RXSIGBUFFERUINT8_BUFFEROFRXACCESSINFO,        1u,           0u,                 1u }   /* [/ActiveEcuC/Com/ComConfig/sig_State_RearRightDoor_omsg_Receive_oCAN00_a8945098_Rx, /ActiveEcuC/Com/ComConfig/msg_Receive_oCAN00_2b456e3f_Rx] */
};
#define COM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Com_RxPduInfo
**********************************************************************************************************************/
/** 
  \var    Com_RxPduInfo
  \brief  Contains all relevant common information for Rx I-PDUs.
  \details
  Element                                Description
  HandleRxPduDeferredIdx                 the index of the 0:1 relation pointing to Com_HandleRxPduDeferred
  IPduGroupInfoOfRxPduInfoIndStartIdx    the start index of the 0:n relation pointing to Com_IPduGroupInfoOfRxPduInfoInd
  MainFunctionRxStructIdx                the index of the 0:1 relation pointing to Com_MainFunctionRxStruct
  RxAccessInfoIndStartIdx                the start index of the 0:n relation pointing to Com_RxAccessInfoInd
  RxDefPduBufferLength                   the number of relations pointing to Com_RxDefPduBuffer
  RxSigInfoStartIdx                      the start index of the 0:n relation pointing to Com_RxSigInfo
*/ 
#define COM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Com_RxPduInfoType, COM_CONST) Com_RxPduInfo[1] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    HandleRxPduDeferredIdx  IPduGroupInfoOfRxPduInfoIndStartIdx  MainFunctionRxStructIdx  RxAccessInfoIndStartIdx  RxDefPduBufferLength  RxSigInfoStartIdx        Referable Keys */
  { /*     0 */                     0u,                                  0u,                      0u,                      0u,                   1u,                0u }   /* [/ActiveEcuC/Com/ComConfig/msg_Receive_oCAN00_2b456e3f_Rx, /ActiveEcuC/Com/ComConfig/MyECU_oCAN00_Rx_4cbf71f7, ComMainFunctionRx] */
};
#define COM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Com_RxSigInfo
**********************************************************************************************************************/
/** 
  \var    Com_RxSigInfo
  \brief  Contains all relevant information for Rx signals.
  \details
  Element     Description
  ValidDlc    Minimum length of PDU required to completely receive the signal or signal group.
*/ 
#define COM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Com_RxSigInfoType, COM_CONST) Com_RxSigInfo[2] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    ValidDlc        Referable Keys */
  { /*     0 */       1u },  /* [/ActiveEcuC/Com/ComConfig/msg_Receive_oCAN00_2b456e3f_Rx] */
  { /*     1 */       1u }   /* [/ActiveEcuC/Com/ComConfig/msg_Receive_oCAN00_2b456e3f_Rx] */
};
#define COM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Com_TxAccessInfo
**********************************************************************************************************************/
/** 
  \var    Com_TxAccessInfo
  \brief  Contains all signal layout information necessary for signal access within an I-PDU.
  \details
  Element         Description
  TxSigInfoIdx    the index of the 0:1 relation pointing to Com_TxSigInfo
*/ 
#define COM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Com_TxAccessInfoType, COM_CONST) Com_TxAccessInfo[55] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    TxSigInfoIdx        Referable Keys */
  { /*     0 */           0u },  /* [/ActiveEcuC/Com/ComConfig/MotorFoc_AdcFilterAlpha_MxA2_omsg_MyECU_Lamp_oCAN00_4c48c598_Tx] */
  { /*     1 */           1u },  /* [/ActiveEcuC/Com/ComConfig/MotorFoc_AdcFilterEnabled_MxA2_omsg_MyECU_Lamp_oCAN00_bb1a16f8_Tx] */
  { /*     2 */           2u },  /* [/ActiveEcuC/Com/ComConfig/MotorFoc_AdcFilterReady_MxA2_omsg_MyECU_Lamp_oCAN00_dd22f986_Tx] */
  { /*     3 */           3u },  /* [/ActiveEcuC/Com/ComConfig/MotorFoc_AdcOffsetSampleCount_MxA2_omsg_MyECU_Lamp_oCAN00_98a9a073_Tx] */
  { /*     4 */           4u },  /* [/ActiveEcuC/Com/ComConfig/MotorFoc_AdcOffsetVo1_MxA2_omsg_MyECU_Lamp_oCAN00_7e4e712f_Tx] */
  { /*     5 */           5u },  /* [/ActiveEcuC/Com/ComConfig/MotorFoc_AdcOffsetVo2_MxA2_omsg_MyECU_Lamp_oCAN00_db461a43_Tx] */
  { /*     6 */           6u },  /* [/ActiveEcuC/Com/ComConfig/MotorFoc_AdcOffsetVo3_MxA2_omsg_MyECU_Lamp_oCAN00_b841c367_Tx] */
  { /*     7 */           7u },  /* [/ActiveEcuC/Com/ComConfig/MotorFoc_AdcSyncCounter_MxA2_omsg_MyECU_Lamp_oCAN00_8264daf6_Tx] */
  { /*     8 */           8u },  /* [/ActiveEcuC/Com/ComConfig/MotorFoc_AngleRaw_MxA0_omsg_MyECU_Lamp_oCAN00_7aec7e78_Tx] */
  { /*     9 */           9u },  /* [/ActiveEcuC/Com/ComConfig/MotorFoc_CurrentOffsetReady_MxA0_omsg_MyECU_Lamp_oCAN00_81ce1bc4_Tx] */
  { /*    10 */          10u },  /* [/ActiveEcuC/Com/ComConfig/MotorFoc_CurrentOffsetSampleCount_MxA0_omsg_MyECU_Lamp_oCAN00_6c5c0a81_Tx] */
  { /*    11 */          11u },  /* [/ActiveEcuC/Com/ComConfig/MotorFoc_ElectricalAngle_rad_MxA0_omsg_MyECU_Lamp_oCAN00_5447ad3f_Tx] */
  { /*    12 */          12u },  /* [/ActiveEcuC/Com/ComConfig/MotorFoc_FaultIu_A_MxA1_omsg_MyECU_Lamp_oCAN00_99a1880c_Tx] */
  { /*    13 */          13u },  /* [/ActiveEcuC/Com/ComConfig/MotorFoc_FaultIv_A_MxA1_omsg_MyECU_Lamp_oCAN00_8a89b17f_Tx] */
  { /*    14 */          14u },  /* [/ActiveEcuC/Com/ComConfig/MotorFoc_FaultIw_A_MxA1_omsg_MyECU_Lamp_oCAN00_846e59ae_Tx] */
  { /*    15 */          15u },  /* [/ActiveEcuC/Com/ComConfig/MotorFoc_FaultPwm_MxA1_omsg_MyECU_Lamp_oCAN00_e43e797b_Tx] */
  { /*    16 */          16u },  /* [/ActiveEcuC/Com/ComConfig/MotorFoc_FaultReasonPwm_MxA1_omsg_MyECU_Lamp_oCAN00_32050898_Tx] */
  { /*    17 */          17u },  /* [/ActiveEcuC/Com/ComConfig/MotorFoc_FaultReason_MxA0_omsg_MyECU_Lamp_oCAN00_0576dfc4_Tx] */
  { /*    18 */          18u },  /* [/ActiveEcuC/Com/ComConfig/MotorFoc_FaultVdc_V_MxA1_omsg_MyECU_Lamp_oCAN00_65447c06_Tx] */
  { /*    19 */          19u },  /* [/ActiveEcuC/Com/ComConfig/MotorFoc_Fault_MxA0_omsg_MyECU_Lamp_oCAN00_3dd6add5_Tx] */
  { /*    20 */          20u },  /* [/ActiveEcuC/Com/ComConfig/MotorFoc_GateDriverOutputEnabled_MxA0_omsg_MyECU_Lamp_oCAN00_6012a7f7_Tx] */
  { /*    21 */          21u },  /* [/ActiveEcuC/Com/ComConfig/MotorFoc_GateDriverState_MxA0_omsg_MyECU_Lamp_oCAN00_e2e4dde6_Tx] */
  { /*    22 */          22u },  /* [/ActiveEcuC/Com/ComConfig/MotorFoc_IdRef_A_MxA0_omsg_MyECU_Lamp_oCAN00_832c12be_Tx] */
  { /*    23 */          23u },  /* [/ActiveEcuC/Com/ComConfig/MotorFoc_Id_A_MxA0_omsg_MyECU_Lamp_oCAN00_888850f5_Tx] */
  { /*    24 */          24u },  /* [/ActiveEcuC/Com/ComConfig/MotorFoc_IqRef_A_MxA0_omsg_MyECU_Lamp_oCAN00_10111ef3_Tx] */
  { /*    25 */          25u },  /* [/ActiveEcuC/Com/ComConfig/MotorFoc_Iq_A_MxA0_omsg_MyECU_Lamp_oCAN00_538e9670_Tx] */
  { /*    26 */          26u },  /* [/ActiveEcuC/Com/ComConfig/MotorFoc_IuFiltered_A_MxA2_omsg_MyECU_Lamp_oCAN00_edadce4b_Tx] */
  { /*    27 */          27u },  /* [/ActiveEcuC/Com/ComConfig/MotorFoc_IuRaw_A_MxA2_omsg_MyECU_Lamp_oCAN00_ca30e9cf_Tx] */
  { /*    28 */          28u },  /* [/ActiveEcuC/Com/ComConfig/MotorFoc_Iu_A_MxA0_omsg_MyECU_Lamp_oCAN00_68113534_Tx] */
  { /*    29 */          29u },  /* [/ActiveEcuC/Com/ComConfig/MotorFoc_IvFiltered_A_MxA2_omsg_MyECU_Lamp_oCAN00_3e36d2b0_Tx] */
  { /*    30 */          30u },  /* [/ActiveEcuC/Com/ComConfig/MotorFoc_IvRaw_A_MxA2_omsg_MyECU_Lamp_oCAN00_a7b61a95_Tx] */
  { /*    31 */          31u },  /* [/ActiveEcuC/Com/ComConfig/MotorFoc_Iv_A_MxA0_omsg_MyECU_Lamp_oCAN00_7b390c47_Tx] */
  { /*    32 */          32u },  /* [/ActiveEcuC/Com/ComConfig/MotorFoc_IwFiltered_A_MxA2_omsg_MyECU_Lamp_oCAN00_70bfd919_Tx] */
  { /*    33 */          33u },  /* [/ActiveEcuC/Com/ComConfig/MotorFoc_IwRaw_A_MxA2_omsg_MyECU_Lamp_oCAN00_83344ba3_Tx] */
  { /*    34 */          34u },  /* [/ActiveEcuC/Com/ComConfig/MotorFoc_Iw_A_MxA0_omsg_MyECU_Lamp_oCAN00_75dee496_Tx] */
  { /*    35 */          35u },  /* [/ActiveEcuC/Com/ComConfig/MotorFoc_MechanicalSpeed_rpm_MxA0_omsg_MyECU_Lamp_oCAN00_04bd2026_Tx] */
  { /*    36 */          36u },  /* [/ActiveEcuC/Com/ComConfig/MotorFoc_MotorModePwm_MxA1_omsg_MyECU_Lamp_oCAN00_d3afa653_Tx] */
  { /*    37 */          37u },  /* [/ActiveEcuC/Com/ComConfig/MotorFoc_MotorMode_MxA0_omsg_MyECU_Lamp_oCAN00_aa7dbeca_Tx] */
  { /*    38 */          38u },  /* [/ActiveEcuC/Com/ComConfig/MotorFoc_Page_MxA0_omsg_MyECU_Lamp_oCAN00_9aab60ea_Tx] */
  { /*    39 */          39u },  /* [/ActiveEcuC/Com/ComConfig/MotorFoc_Page_MxA1_omsg_MyECU_Lamp_oCAN00_1b8e05cd_Tx] */
  { /*    40 */          40u },  /* [/ActiveEcuC/Com/ComConfig/MotorFoc_Page_MxA2_omsg_MyECU_Lamp_oCAN00_4390ace5_Tx] */
  { /*    41 */          41u },  /* [/ActiveEcuC/Com/ComConfig/MotorFoc_PwmPeriod_MxA1_omsg_MyECU_Lamp_oCAN00_d26baca6_Tx] */
  { /*    42 */          42u },  /* [/ActiveEcuC/Com/ComConfig/MotorFoc_PwmU_MxA1_omsg_MyECU_Lamp_oCAN00_c33fb364_Tx] */
  { /*    43 */          43u },  /* [/ActiveEcuC/Com/ComConfig/MotorFoc_PwmV_MxA1_omsg_MyECU_Lamp_oCAN00_6637d808_Tx] */
  { /*    44 */          44u },  /* [/ActiveEcuC/Com/ComConfig/MotorFoc_PwmW_MxA1_omsg_MyECU_Lamp_oCAN00_0530012c_Tx] */
  { /*    45 */          45u },  /* [/ActiveEcuC/Com/ComConfig/MotorFoc_Sequence_Mx_omsg_MyECU_Lamp_oCAN00_339a541d_Tx] */
  { /*    46 */          46u },  /* [/ActiveEcuC/Com/ComConfig/MotorFoc_ValphaRef_V_MxA1_omsg_MyECU_Lamp_oCAN00_dafa2b94_Tx] */
  { /*    47 */          47u },  /* [/ActiveEcuC/Com/ComConfig/MotorFoc_VbetaRef_V_MxA1_omsg_MyECU_Lamp_oCAN00_623c36a7_Tx] */
  { /*    48 */          48u },  /* [/ActiveEcuC/Com/ComConfig/MotorFoc_VdRef_V_MxA1_omsg_MyECU_Lamp_oCAN00_f0517bd4_Tx] */
  { /*    49 */          49u },  /* [/ActiveEcuC/Com/ComConfig/MotorFoc_VdcMax_V_MxA1_omsg_MyECU_Lamp_oCAN00_8d3d4389_Tx] */
    /* Index    TxSigInfoIdx        Referable Keys */
  { /*    50 */          50u },  /* [/ActiveEcuC/Com/ComConfig/MotorFoc_Vdc_V_MxA0_omsg_MyECU_Lamp_oCAN00_6919810c_Tx] */
  { /*    51 */          51u },  /* [/ActiveEcuC/Com/ComConfig/MotorFoc_Vinv_V_MxA2_omsg_MyECU_Lamp_oCAN00_bd00cc55_Tx] */
  { /*    52 */          52u },  /* [/ActiveEcuC/Com/ComConfig/MotorFoc_VqRef_V_MxA1_omsg_MyECU_Lamp_oCAN00_636c7799_Tx] */
  { /*    53 */          53u },  /* [/ActiveEcuC/Com/ComConfig/MotorFoc_Vro_V_MxA2_omsg_MyECU_Lamp_oCAN00_a894d119_Tx] */
  { /*    54 */          54u }   /* [/ActiveEcuC/Com/ComConfig/sig_RearInteriorLight_omsg_Transmit_oCAN00_49a633c1_Tx] */
};
#define COM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Com_TxCyclicPdu
**********************************************************************************************************************/
/** 
  \var    Com_TxCyclicPdu
  \details
  Element         Description
  TxPduInfoIdx    the index of the 1:1 relation pointing to Com_TxPduInfo
*/ 
#define COM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Com_TxCyclicPduType, COM_CONST) Com_TxCyclicPdu[4] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    TxPduInfoIdx        Referable Keys */
  { /*     0 */           0u },  /* [/ActiveEcuC/Com/ComConfig/msg_MyECU_Lamp_MxA0_oCAN00_b76f77a4_Tx, ComMainFunctionTx] */
  { /*     1 */           1u },  /* [/ActiveEcuC/Com/ComConfig/msg_MyECU_Lamp_MxA1_oCAN00_7bc5773a_Tx, ComMainFunctionTx] */
  { /*     2 */           2u },  /* [/ActiveEcuC/Com/ComConfig/msg_MyECU_Lamp_MxA2_oCAN00_f54a70d9_Tx, ComMainFunctionTx] */
  { /*     3 */           4u }   /* [/ActiveEcuC/Com/ComConfig/msg_Transmit_oCAN00_0723e95e_Tx, ComMainFunctionTx] */
};
#define COM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Com_TxModeFalse
**********************************************************************************************************************/
/** 
  \var    Com_TxModeFalse
  \brief  Contains all relevant information for transmission mode false.
  \details
  Element       Description
  TimePeriod    Cycle time factor.
*/ 
#define COM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Com_TxModeFalseType, COM_CONST) Com_TxModeFalse[2] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    TimePeriod        Referable Keys */
  { /*     0 */        20u },  /* [/ActiveEcuC/Com/ComConfig/msg_Transmit_oCAN00_0723e95e_Tx] */
  { /*     1 */         0u }   /* [/ActiveEcuC/Com/ComConfig/msg_MyECU_Lamp_MxA0_oCAN00_b76f77a4_Tx, /ActiveEcuC/Com/ComConfig/msg_MyECU_Lamp_MxA1_oCAN00_7bc5773a_Tx, /ActiveEcuC/Com/ComConfig/msg_MyECU_Lamp_MxA2_oCAN00_f54a70d9_Tx, /ActiveEcuC/Com/ComConfig/msg_MyECU_Lamp_Mx_oCAN00_e57ca999_Tx] */
};
#define COM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Com_TxModeInfo
**********************************************************************************************************************/
/** 
  \var    Com_TxModeInfo
  \brief  Contains all relevant information for transmission mode handling.
  \details
  Element           Description
  InitMode          Initial transmission mode selector of the Tx I-PDU.
  TxModeFalseIdx    the index of the 1:1 relation pointing to Com_TxModeFalse
*/ 
#define COM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Com_TxModeInfoType, COM_CONST) Com_TxModeInfo[5] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    InitMode  TxModeFalseIdx        Referable Keys */
  { /*     0 */     TRUE,             1u },  /* [/ActiveEcuC/Com/ComConfig/msg_MyECU_Lamp_MxA0_oCAN00_b76f77a4_Tx] */
  { /*     1 */     TRUE,             1u },  /* [/ActiveEcuC/Com/ComConfig/msg_MyECU_Lamp_MxA1_oCAN00_7bc5773a_Tx] */
  { /*     2 */     TRUE,             1u },  /* [/ActiveEcuC/Com/ComConfig/msg_MyECU_Lamp_MxA2_oCAN00_f54a70d9_Tx] */
  { /*     3 */     TRUE,             1u },  /* [/ActiveEcuC/Com/ComConfig/msg_MyECU_Lamp_Mx_oCAN00_e57ca999_Tx] */
  { /*     4 */     TRUE,             0u }   /* [/ActiveEcuC/Com/ComConfig/msg_Transmit_oCAN00_0723e95e_Tx] */
};
#define COM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Com_TxModeTrue
**********************************************************************************************************************/
/** 
  \var    Com_TxModeTrue
  \brief  Contains all relevant information for transmission mode true.
  \details
  Element       Description
  Periodic      TRUE if transmission mode contains a cyclic part.
  TimeOffset    Initial time offset factor for cyclic transmission.
  TimePeriod    Cycle time factor.
*/ 
#define COM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Com_TxModeTrueType, COM_CONST) Com_TxModeTrue[5] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    Periodic  TimeOffset  TimePeriod        Referable Keys */
  { /*     0 */     TRUE,         1u,         3u },  /* [/ActiveEcuC/Com/ComConfig/msg_MyECU_Lamp_MxA0_oCAN00_b76f77a4_Tx] */
  { /*     1 */     TRUE,         2u,         3u },  /* [/ActiveEcuC/Com/ComConfig/msg_MyECU_Lamp_MxA1_oCAN00_7bc5773a_Tx] */
  { /*     2 */     TRUE,         3u,         3u },  /* [/ActiveEcuC/Com/ComConfig/msg_MyECU_Lamp_MxA2_oCAN00_f54a70d9_Tx] */
  { /*     3 */    FALSE,         1u,         0u },  /* [/ActiveEcuC/Com/ComConfig/msg_MyECU_Lamp_Mx_oCAN00_e57ca999_Tx] */
  { /*     4 */     TRUE,         1u,        20u }   /* [/ActiveEcuC/Com/ComConfig/msg_Transmit_oCAN00_0723e95e_Tx] */
};
#define COM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Com_TxPduInfo
**********************************************************************************************************************/
/** 
  \var    Com_TxPduInfo
  \brief  Contains all relevant information for Tx I-PDUs.
  \details
  Element                                Description
  ExternalId                             External ID used to call PduR_ComTransmit().
  IPduGroupInfoOfTxPduInfoIndStartIdx    the start index of the 0:n relation pointing to Com_IPduGroupInfoOfTxPduInfoInd
  PartitionsTxStructIdx                  the index of the 1:1 relation pointing to Com_PartitionsTxStruct
  TxBufferLength                         the number of relations pointing to Com_TxBuffer
  TxPduInitValueEndIdx                   the end index of the 0:n relation pointing to Com_TxPduInitValue
  TxPduInitValueStartIdx                 the start index of the 0:n relation pointing to Com_TxPduInitValue
*/ 
#define COM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Com_TxPduInfoType, COM_CONST) Com_TxPduInfo[5] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    ExternalId                               IPduGroupInfoOfTxPduInfoIndStartIdx  PartitionsTxStructIdx  TxBufferLength  TxPduInitValueEndIdx  TxPduInitValueStartIdx        Referable Keys */
  { /*     0 */ PduRConf_PduRSrcPdu_PduRSrcPdu_991c8b02,                                  0u,                    0u,            32u,                  32u,                     0u },  /* [/ActiveEcuC/Com/ComConfig/msg_MyECU_Lamp_MxA0_oCAN00_b76f77a4_Tx, /ActiveEcuC/Com/ComConfig/MyECU_oCAN00_Tx_1ae5d671, ComMainFunctionTx] */
  { /*     1 */ PduRConf_PduRSrcPdu_PduRSrcPdu_f7c31f09,                                  1u,                    0u,            32u,                  64u,                    32u },  /* [/ActiveEcuC/Com/ComConfig/msg_MyECU_Lamp_MxA1_oCAN00_7bc5773a_Tx, /ActiveEcuC/Com/ComConfig/MyECU_oCAN00_Tx_1ae5d671, ComMainFunctionTx] */
  { /*     2 */ PduRConf_PduRSrcPdu_PduRSrcPdu_e44218bb,                                  2u,                    0u,            32u,                  96u,                    64u },  /* [/ActiveEcuC/Com/ComConfig/msg_MyECU_Lamp_MxA2_oCAN00_f54a70d9_Tx, /ActiveEcuC/Com/ComConfig/MyECU_oCAN00_Tx_1ae5d671, ComMainFunctionTx] */
  { /*     3 */ PduRConf_PduRSrcPdu_PduRSrcPdu_289484a7,                                  3u,                    0u,            32u,                 128u,                    96u },  /* [/ActiveEcuC/Com/ComConfig/msg_MyECU_Lamp_Mx_oCAN00_e57ca999_Tx, /ActiveEcuC/Com/ComConfig/MyECU_oCAN00_Tx_1ae5d671, ComMainFunctionTx] */
  { /*     4 */ PduRConf_PduRSrcPdu_PduRSrcPdu_087fd70d,                                  4u,                    0u,             1u,                 129u,                   128u }   /* [/ActiveEcuC/Com/ComConfig/msg_Transmit_oCAN00_0723e95e_Tx, /ActiveEcuC/Com/ComConfig/MyECU_oCAN00_Tx_1ae5d671, ComMainFunctionTx] */
};
#define COM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Com_TxPduInitValue
**********************************************************************************************************************/
/** 
  \var    Com_TxPduInitValue
  \brief  Initial values used for Tx I-PDU buffer initialization.
*/ 
#define COM_START_SEC_CONST_8
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Com_TxPduInitValueType, COM_CONST) Com_TxPduInitValue[129] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index     TxPduInitValue      Referable Keys */
  /*     0 */           0xA0u,  /* [/ActiveEcuC/Com/ComConfig/msg_MyECU_Lamp_MxA0_oCAN00_b76f77a4_Tx] */
  /*     1 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/msg_MyECU_Lamp_MxA0_oCAN00_b76f77a4_Tx] */
  /*     2 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/msg_MyECU_Lamp_MxA0_oCAN00_b76f77a4_Tx] */
  /*     3 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/msg_MyECU_Lamp_MxA0_oCAN00_b76f77a4_Tx] */
  /*     4 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/msg_MyECU_Lamp_MxA0_oCAN00_b76f77a4_Tx] */
  /*     5 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/msg_MyECU_Lamp_MxA0_oCAN00_b76f77a4_Tx] */
  /*     6 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/msg_MyECU_Lamp_MxA0_oCAN00_b76f77a4_Tx] */
  /*     7 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/msg_MyECU_Lamp_MxA0_oCAN00_b76f77a4_Tx] */
  /*     8 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/msg_MyECU_Lamp_MxA0_oCAN00_b76f77a4_Tx] */
  /*     9 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/msg_MyECU_Lamp_MxA0_oCAN00_b76f77a4_Tx] */
  /*    10 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/msg_MyECU_Lamp_MxA0_oCAN00_b76f77a4_Tx] */
  /*    11 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/msg_MyECU_Lamp_MxA0_oCAN00_b76f77a4_Tx] */
  /*    12 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/msg_MyECU_Lamp_MxA0_oCAN00_b76f77a4_Tx] */
  /*    13 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/msg_MyECU_Lamp_MxA0_oCAN00_b76f77a4_Tx] */
  /*    14 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/msg_MyECU_Lamp_MxA0_oCAN00_b76f77a4_Tx] */
  /*    15 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/msg_MyECU_Lamp_MxA0_oCAN00_b76f77a4_Tx] */
  /*    16 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/msg_MyECU_Lamp_MxA0_oCAN00_b76f77a4_Tx] */
  /*    17 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/msg_MyECU_Lamp_MxA0_oCAN00_b76f77a4_Tx] */
  /*    18 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/msg_MyECU_Lamp_MxA0_oCAN00_b76f77a4_Tx] */
  /*    19 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/msg_MyECU_Lamp_MxA0_oCAN00_b76f77a4_Tx] */
  /*    20 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/msg_MyECU_Lamp_MxA0_oCAN00_b76f77a4_Tx] */
  /*    21 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/msg_MyECU_Lamp_MxA0_oCAN00_b76f77a4_Tx] */
  /*    22 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/msg_MyECU_Lamp_MxA0_oCAN00_b76f77a4_Tx] */
  /*    23 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/msg_MyECU_Lamp_MxA0_oCAN00_b76f77a4_Tx] */
  /*    24 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/msg_MyECU_Lamp_MxA0_oCAN00_b76f77a4_Tx] */
  /*    25 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/msg_MyECU_Lamp_MxA0_oCAN00_b76f77a4_Tx] */
  /*    26 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/msg_MyECU_Lamp_MxA0_oCAN00_b76f77a4_Tx] */
  /*    27 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/msg_MyECU_Lamp_MxA0_oCAN00_b76f77a4_Tx] */
  /*    28 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/msg_MyECU_Lamp_MxA0_oCAN00_b76f77a4_Tx] */
  /*    29 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/msg_MyECU_Lamp_MxA0_oCAN00_b76f77a4_Tx] */
  /*    30 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/msg_MyECU_Lamp_MxA0_oCAN00_b76f77a4_Tx] */
  /*    31 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/msg_MyECU_Lamp_MxA0_oCAN00_b76f77a4_Tx] */
  /*    32 */           0xA1u,  /* [/ActiveEcuC/Com/ComConfig/msg_MyECU_Lamp_MxA1_oCAN00_7bc5773a_Tx] */
  /*    33 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/msg_MyECU_Lamp_MxA1_oCAN00_7bc5773a_Tx] */
  /*    34 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/msg_MyECU_Lamp_MxA1_oCAN00_7bc5773a_Tx] */
  /*    35 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/msg_MyECU_Lamp_MxA1_oCAN00_7bc5773a_Tx] */
  /*    36 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/msg_MyECU_Lamp_MxA1_oCAN00_7bc5773a_Tx] */
  /*    37 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/msg_MyECU_Lamp_MxA1_oCAN00_7bc5773a_Tx] */
  /*    38 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/msg_MyECU_Lamp_MxA1_oCAN00_7bc5773a_Tx] */
  /*    39 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/msg_MyECU_Lamp_MxA1_oCAN00_7bc5773a_Tx] */
  /*    40 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/msg_MyECU_Lamp_MxA1_oCAN00_7bc5773a_Tx] */
  /*    41 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/msg_MyECU_Lamp_MxA1_oCAN00_7bc5773a_Tx] */
  /*    42 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/msg_MyECU_Lamp_MxA1_oCAN00_7bc5773a_Tx] */
  /*    43 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/msg_MyECU_Lamp_MxA1_oCAN00_7bc5773a_Tx] */
  /*    44 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/msg_MyECU_Lamp_MxA1_oCAN00_7bc5773a_Tx] */
  /*    45 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/msg_MyECU_Lamp_MxA1_oCAN00_7bc5773a_Tx] */
  /*    46 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/msg_MyECU_Lamp_MxA1_oCAN00_7bc5773a_Tx] */
  /*    47 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/msg_MyECU_Lamp_MxA1_oCAN00_7bc5773a_Tx] */
  /*    48 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/msg_MyECU_Lamp_MxA1_oCAN00_7bc5773a_Tx] */
  /*    49 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/msg_MyECU_Lamp_MxA1_oCAN00_7bc5773a_Tx] */
  /* Index     TxPduInitValue      Referable Keys */
  /*    50 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/msg_MyECU_Lamp_MxA1_oCAN00_7bc5773a_Tx] */
  /*    51 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/msg_MyECU_Lamp_MxA1_oCAN00_7bc5773a_Tx] */
  /*    52 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/msg_MyECU_Lamp_MxA1_oCAN00_7bc5773a_Tx] */
  /*    53 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/msg_MyECU_Lamp_MxA1_oCAN00_7bc5773a_Tx] */
  /*    54 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/msg_MyECU_Lamp_MxA1_oCAN00_7bc5773a_Tx] */
  /*    55 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/msg_MyECU_Lamp_MxA1_oCAN00_7bc5773a_Tx] */
  /*    56 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/msg_MyECU_Lamp_MxA1_oCAN00_7bc5773a_Tx] */
  /*    57 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/msg_MyECU_Lamp_MxA1_oCAN00_7bc5773a_Tx] */
  /*    58 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/msg_MyECU_Lamp_MxA1_oCAN00_7bc5773a_Tx] */
  /*    59 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/msg_MyECU_Lamp_MxA1_oCAN00_7bc5773a_Tx] */
  /*    60 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/msg_MyECU_Lamp_MxA1_oCAN00_7bc5773a_Tx] */
  /*    61 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/msg_MyECU_Lamp_MxA1_oCAN00_7bc5773a_Tx] */
  /*    62 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/msg_MyECU_Lamp_MxA1_oCAN00_7bc5773a_Tx] */
  /*    63 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/msg_MyECU_Lamp_MxA1_oCAN00_7bc5773a_Tx] */
  /*    64 */           0xA2u,  /* [/ActiveEcuC/Com/ComConfig/msg_MyECU_Lamp_MxA2_oCAN00_f54a70d9_Tx] */
  /*    65 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/msg_MyECU_Lamp_MxA2_oCAN00_f54a70d9_Tx] */
  /*    66 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/msg_MyECU_Lamp_MxA2_oCAN00_f54a70d9_Tx] */
  /*    67 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/msg_MyECU_Lamp_MxA2_oCAN00_f54a70d9_Tx] */
  /*    68 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/msg_MyECU_Lamp_MxA2_oCAN00_f54a70d9_Tx] */
  /*    69 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/msg_MyECU_Lamp_MxA2_oCAN00_f54a70d9_Tx] */
  /*    70 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/msg_MyECU_Lamp_MxA2_oCAN00_f54a70d9_Tx] */
  /*    71 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/msg_MyECU_Lamp_MxA2_oCAN00_f54a70d9_Tx] */
  /*    72 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/msg_MyECU_Lamp_MxA2_oCAN00_f54a70d9_Tx] */
  /*    73 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/msg_MyECU_Lamp_MxA2_oCAN00_f54a70d9_Tx] */
  /*    74 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/msg_MyECU_Lamp_MxA2_oCAN00_f54a70d9_Tx] */
  /*    75 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/msg_MyECU_Lamp_MxA2_oCAN00_f54a70d9_Tx] */
  /*    76 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/msg_MyECU_Lamp_MxA2_oCAN00_f54a70d9_Tx] */
  /*    77 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/msg_MyECU_Lamp_MxA2_oCAN00_f54a70d9_Tx] */
  /*    78 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/msg_MyECU_Lamp_MxA2_oCAN00_f54a70d9_Tx] */
  /*    79 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/msg_MyECU_Lamp_MxA2_oCAN00_f54a70d9_Tx] */
  /*    80 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/msg_MyECU_Lamp_MxA2_oCAN00_f54a70d9_Tx] */
  /*    81 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/msg_MyECU_Lamp_MxA2_oCAN00_f54a70d9_Tx] */
  /*    82 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/msg_MyECU_Lamp_MxA2_oCAN00_f54a70d9_Tx] */
  /*    83 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/msg_MyECU_Lamp_MxA2_oCAN00_f54a70d9_Tx] */
  /*    84 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/msg_MyECU_Lamp_MxA2_oCAN00_f54a70d9_Tx] */
  /*    85 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/msg_MyECU_Lamp_MxA2_oCAN00_f54a70d9_Tx] */
  /*    86 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/msg_MyECU_Lamp_MxA2_oCAN00_f54a70d9_Tx] */
  /*    87 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/msg_MyECU_Lamp_MxA2_oCAN00_f54a70d9_Tx] */
  /*    88 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/msg_MyECU_Lamp_MxA2_oCAN00_f54a70d9_Tx] */
  /*    89 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/msg_MyECU_Lamp_MxA2_oCAN00_f54a70d9_Tx] */
  /*    90 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/msg_MyECU_Lamp_MxA2_oCAN00_f54a70d9_Tx] */
  /*    91 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/msg_MyECU_Lamp_MxA2_oCAN00_f54a70d9_Tx] */
  /*    92 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/msg_MyECU_Lamp_MxA2_oCAN00_f54a70d9_Tx] */
  /*    93 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/msg_MyECU_Lamp_MxA2_oCAN00_f54a70d9_Tx] */
  /*    94 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/msg_MyECU_Lamp_MxA2_oCAN00_f54a70d9_Tx] */
  /*    95 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/msg_MyECU_Lamp_MxA2_oCAN00_f54a70d9_Tx] */
  /*    96 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/msg_MyECU_Lamp_Mx_oCAN00_e57ca999_Tx] */
  /*    97 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/msg_MyECU_Lamp_Mx_oCAN00_e57ca999_Tx] */
  /*    98 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/msg_MyECU_Lamp_Mx_oCAN00_e57ca999_Tx] */
  /*    99 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/msg_MyECU_Lamp_Mx_oCAN00_e57ca999_Tx] */
  /* Index     TxPduInitValue      Referable Keys */
  /*   100 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/msg_MyECU_Lamp_Mx_oCAN00_e57ca999_Tx] */
  /*   101 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/msg_MyECU_Lamp_Mx_oCAN00_e57ca999_Tx] */
  /*   102 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/msg_MyECU_Lamp_Mx_oCAN00_e57ca999_Tx] */
  /*   103 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/msg_MyECU_Lamp_Mx_oCAN00_e57ca999_Tx] */
  /*   104 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/msg_MyECU_Lamp_Mx_oCAN00_e57ca999_Tx] */
  /*   105 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/msg_MyECU_Lamp_Mx_oCAN00_e57ca999_Tx] */
  /*   106 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/msg_MyECU_Lamp_Mx_oCAN00_e57ca999_Tx] */
  /*   107 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/msg_MyECU_Lamp_Mx_oCAN00_e57ca999_Tx] */
  /*   108 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/msg_MyECU_Lamp_Mx_oCAN00_e57ca999_Tx] */
  /*   109 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/msg_MyECU_Lamp_Mx_oCAN00_e57ca999_Tx] */
  /*   110 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/msg_MyECU_Lamp_Mx_oCAN00_e57ca999_Tx] */
  /*   111 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/msg_MyECU_Lamp_Mx_oCAN00_e57ca999_Tx] */
  /*   112 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/msg_MyECU_Lamp_Mx_oCAN00_e57ca999_Tx] */
  /*   113 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/msg_MyECU_Lamp_Mx_oCAN00_e57ca999_Tx] */
  /*   114 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/msg_MyECU_Lamp_Mx_oCAN00_e57ca999_Tx] */
  /*   115 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/msg_MyECU_Lamp_Mx_oCAN00_e57ca999_Tx] */
  /*   116 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/msg_MyECU_Lamp_Mx_oCAN00_e57ca999_Tx] */
  /*   117 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/msg_MyECU_Lamp_Mx_oCAN00_e57ca999_Tx] */
  /*   118 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/msg_MyECU_Lamp_Mx_oCAN00_e57ca999_Tx] */
  /*   119 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/msg_MyECU_Lamp_Mx_oCAN00_e57ca999_Tx] */
  /*   120 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/msg_MyECU_Lamp_Mx_oCAN00_e57ca999_Tx] */
  /*   121 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/msg_MyECU_Lamp_Mx_oCAN00_e57ca999_Tx] */
  /*   122 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/msg_MyECU_Lamp_Mx_oCAN00_e57ca999_Tx] */
  /*   123 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/msg_MyECU_Lamp_Mx_oCAN00_e57ca999_Tx] */
  /*   124 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/msg_MyECU_Lamp_Mx_oCAN00_e57ca999_Tx] */
  /*   125 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/msg_MyECU_Lamp_Mx_oCAN00_e57ca999_Tx] */
  /*   126 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/msg_MyECU_Lamp_Mx_oCAN00_e57ca999_Tx] */
  /*   127 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/msg_MyECU_Lamp_Mx_oCAN00_e57ca999_Tx] */
  /*   128 */           0x00u   /* [/ActiveEcuC/Com/ComConfig/msg_Transmit_oCAN00_0723e95e_Tx] */
};
#define COM_STOP_SEC_CONST_8
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Com_TxSigInfo
**********************************************************************************************************************/
/** 
  \var    Com_TxSigInfo
  \brief  Contains all relevant information for Tx signals signals.
  \details
  Element                   Description
  DynSignal                 TRUE if the Signal is a dynamic length signal (UINT8_DYN), FALSE otherwise.
  ApplType                  Application data type.
  BitLength                 Bit length of the signal or group signal.
  BitPosition               Little endian bit position of the signal or group signal within the I-PDU.
  ByteLength                Byte length of the signal or group signal.
  StartByteInPduPosition    Start Byte position of the signal or group signal within the I-PDU.
  TxBufferEndIdx            the end index of the 0:n relation pointing to Com_TxBuffer
  TxBufferStartIdx          the start index of the 0:n relation pointing to Com_TxBuffer
  TxPduInfoIdx              the index of the 1:1 relation pointing to Com_TxPduInfo
*/ 
#define COM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Com_TxSigInfoType, COM_CONST) Com_TxSigInfo[55] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    DynSignal  ApplType                        BitLength  BitPosition  ByteLength  StartByteInPduPosition  TxBufferEndIdx  TxBufferStartIdx  TxPduInfoIdx        Referable Keys */
  { /*     0 */     FALSE,  COM_UINT8_APPLTYPEOFTXSIGINFO,        8u,         24u,         1u,                     3u,            68u,              67u,           2u },  /* [/ActiveEcuC/Com/ComConfig/MotorFoc_AdcFilterAlpha_MxA2_omsg_MyECU_Lamp_oCAN00_4c48c598_Tx] */
  { /*     1 */     FALSE,  COM_UINT8_APPLTYPEOFTXSIGINFO,        8u,          8u,         1u,                     1u,            66u,              65u,           2u },  /* [/ActiveEcuC/Com/ComConfig/MotorFoc_AdcFilterEnabled_MxA2_omsg_MyECU_Lamp_oCAN00_bb1a16f8_Tx] */
  { /*     2 */     FALSE,  COM_UINT8_APPLTYPEOFTXSIGINFO,        8u,         16u,         1u,                     2u,            67u,              66u,           2u },  /* [/ActiveEcuC/Com/ComConfig/MotorFoc_AdcFilterReady_MxA2_omsg_MyECU_Lamp_oCAN00_dd22f986_Tx] */
  { /*     3 */     FALSE, COM_UINT16_APPLTYPEOFTXSIGINFO,       16u,        240u,         2u,                    30u,            96u,              94u,           2u },  /* [/ActiveEcuC/Com/ComConfig/MotorFoc_AdcOffsetSampleCount_MxA2_omsg_MyECU_Lamp_oCAN00_98a9a073_Tx] */
  { /*     4 */     FALSE, COM_SINT16_APPLTYPEOFTXSIGINFO,       16u,        144u,         2u,                    18u,            84u,              82u,           2u },  /* [/ActiveEcuC/Com/ComConfig/MotorFoc_AdcOffsetVo1_MxA2_omsg_MyECU_Lamp_oCAN00_7e4e712f_Tx] */
  { /*     5 */     FALSE, COM_SINT16_APPLTYPEOFTXSIGINFO,       16u,        160u,         2u,                    20u,            86u,              84u,           2u },  /* [/ActiveEcuC/Com/ComConfig/MotorFoc_AdcOffsetVo2_MxA2_omsg_MyECU_Lamp_oCAN00_db461a43_Tx] */
  { /*     6 */     FALSE, COM_SINT16_APPLTYPEOFTXSIGINFO,       16u,        176u,         2u,                    22u,            88u,              86u,           2u },  /* [/ActiveEcuC/Com/ComConfig/MotorFoc_AdcOffsetVo3_MxA2_omsg_MyECU_Lamp_oCAN00_b841c367_Tx] */
  { /*     7 */     FALSE, COM_UINT16_APPLTYPEOFTXSIGINFO,       16u,        224u,         2u,                    28u,            94u,              92u,           2u },  /* [/ActiveEcuC/Com/ComConfig/MotorFoc_AdcSyncCounter_MxA2_omsg_MyECU_Lamp_oCAN00_8264daf6_Tx] */
  { /*     8 */     FALSE, COM_UINT16_APPLTYPEOFTXSIGINFO,       16u,        176u,         2u,                    22u,            24u,              22u,           0u },  /* [/ActiveEcuC/Com/ComConfig/MotorFoc_AngleRaw_MxA0_omsg_MyECU_Lamp_oCAN00_7aec7e78_Tx] */
  { /*     9 */     FALSE,  COM_UINT8_APPLTYPEOFTXSIGINFO,        8u,        208u,         1u,                    26u,            27u,              26u,           0u },  /* [/ActiveEcuC/Com/ComConfig/MotorFoc_CurrentOffsetReady_MxA0_omsg_MyECU_Lamp_oCAN00_81ce1bc4_Tx] */
  { /*    10 */     FALSE,  COM_UINT8_APPLTYPEOFTXSIGINFO,        8u,        216u,         1u,                    27u,            28u,              27u,           0u },  /* [/ActiveEcuC/Com/ComConfig/MotorFoc_CurrentOffsetSampleCount_MxA0_omsg_MyECU_Lamp_oCAN00_6c5c0a81_Tx] */
  { /*    11 */     FALSE, COM_SINT16_APPLTYPEOFTXSIGINFO,       16u,        192u,         2u,                    24u,            26u,              24u,           0u },  /* [/ActiveEcuC/Com/ComConfig/MotorFoc_ElectricalAngle_rad_MxA0_omsg_MyECU_Lamp_oCAN00_5447ad3f_Tx] */
  { /*    12 */     FALSE, COM_SINT16_APPLTYPEOFTXSIGINFO,       16u,        192u,         2u,                    24u,            58u,              56u,           1u },  /* [/ActiveEcuC/Com/ComConfig/MotorFoc_FaultIu_A_MxA1_omsg_MyECU_Lamp_oCAN00_99a1880c_Tx] */
  { /*    13 */     FALSE, COM_SINT16_APPLTYPEOFTXSIGINFO,       16u,        208u,         2u,                    26u,            60u,              58u,           1u },  /* [/ActiveEcuC/Com/ComConfig/MotorFoc_FaultIv_A_MxA1_omsg_MyECU_Lamp_oCAN00_8a89b17f_Tx] */
  { /*    14 */     FALSE, COM_SINT16_APPLTYPEOFTXSIGINFO,       16u,        224u,         2u,                    28u,            62u,              60u,           1u },  /* [/ActiveEcuC/Com/ComConfig/MotorFoc_FaultIw_A_MxA1_omsg_MyECU_Lamp_oCAN00_846e59ae_Tx] */
  { /*    15 */     FALSE,  COM_UINT8_APPLTYPEOFTXSIGINFO,        8u,         16u,         1u,                     2u,            35u,              34u,           1u },  /* [/ActiveEcuC/Com/ComConfig/MotorFoc_FaultPwm_MxA1_omsg_MyECU_Lamp_oCAN00_e43e797b_Tx] */
  { /*    16 */     FALSE,  COM_UINT8_APPLTYPEOFTXSIGINFO,        8u,         24u,         1u,                     3u,            36u,              35u,           1u },  /* [/ActiveEcuC/Com/ComConfig/MotorFoc_FaultReasonPwm_MxA1_omsg_MyECU_Lamp_oCAN00_32050898_Tx] */
  { /*    17 */     FALSE,  COM_UINT8_APPLTYPEOFTXSIGINFO,        8u,         24u,         1u,                     3u,             4u,               3u,           0u },  /* [/ActiveEcuC/Com/ComConfig/MotorFoc_FaultReason_MxA0_omsg_MyECU_Lamp_oCAN00_0576dfc4_Tx] */
  { /*    18 */     FALSE, COM_SINT16_APPLTYPEOFTXSIGINFO,       16u,        240u,         2u,                    30u,            64u,              62u,           1u },  /* [/ActiveEcuC/Com/ComConfig/MotorFoc_FaultVdc_V_MxA1_omsg_MyECU_Lamp_oCAN00_65447c06_Tx] */
  { /*    19 */     FALSE,  COM_UINT8_APPLTYPEOFTXSIGINFO,        8u,         16u,         1u,                     2u,             3u,               2u,           0u },  /* [/ActiveEcuC/Com/ComConfig/MotorFoc_Fault_MxA0_omsg_MyECU_Lamp_oCAN00_3dd6add5_Tx] */
  { /*    20 */     FALSE,  COM_UINT8_APPLTYPEOFTXSIGINFO,        8u,        248u,         1u,                    31u,            32u,              31u,           0u },  /* [/ActiveEcuC/Com/ComConfig/MotorFoc_GateDriverOutputEnabled_MxA0_omsg_MyECU_Lamp_oCAN00_6012a7f7_Tx] */
  { /*    21 */     FALSE,  COM_UINT8_APPLTYPEOFTXSIGINFO,        8u,        240u,         1u,                    30u,            31u,              30u,           0u },  /* [/ActiveEcuC/Com/ComConfig/MotorFoc_GateDriverState_MxA0_omsg_MyECU_Lamp_oCAN00_e2e4dde6_Tx] */
  { /*    22 */     FALSE, COM_SINT16_APPLTYPEOFTXSIGINFO,       16u,         48u,         2u,                     6u,             8u,               6u,           0u },  /* [/ActiveEcuC/Com/ComConfig/MotorFoc_IdRef_A_MxA0_omsg_MyECU_Lamp_oCAN00_832c12be_Tx] */
  { /*    23 */     FALSE, COM_SINT16_APPLTYPEOFTXSIGINFO,       16u,         80u,         2u,                    10u,            12u,              10u,           0u },  /* [/ActiveEcuC/Com/ComConfig/MotorFoc_Id_A_MxA0_omsg_MyECU_Lamp_oCAN00_888850f5_Tx] */
  { /*    24 */     FALSE, COM_SINT16_APPLTYPEOFTXSIGINFO,       16u,         64u,         2u,                     8u,            10u,               8u,           0u },  /* [/ActiveEcuC/Com/ComConfig/MotorFoc_IqRef_A_MxA0_omsg_MyECU_Lamp_oCAN00_10111ef3_Tx] */
  { /*    25 */     FALSE, COM_SINT16_APPLTYPEOFTXSIGINFO,       16u,         96u,         2u,                    12u,            14u,              12u,           0u },  /* [/ActiveEcuC/Com/ComConfig/MotorFoc_Iq_A_MxA0_omsg_MyECU_Lamp_oCAN00_538e9670_Tx] */
  { /*    26 */     FALSE, COM_SINT16_APPLTYPEOFTXSIGINFO,       16u,         96u,         2u,                    12u,            78u,              76u,           2u },  /* [/ActiveEcuC/Com/ComConfig/MotorFoc_IuFiltered_A_MxA2_omsg_MyECU_Lamp_oCAN00_edadce4b_Tx] */
  { /*    27 */     FALSE, COM_SINT16_APPLTYPEOFTXSIGINFO,       16u,         48u,         2u,                     6u,            72u,              70u,           2u },  /* [/ActiveEcuC/Com/ComConfig/MotorFoc_IuRaw_A_MxA2_omsg_MyECU_Lamp_oCAN00_ca30e9cf_Tx] */
  { /*    28 */     FALSE, COM_SINT16_APPLTYPEOFTXSIGINFO,       16u,        112u,         2u,                    14u,            16u,              14u,           0u },  /* [/ActiveEcuC/Com/ComConfig/MotorFoc_Iu_A_MxA0_omsg_MyECU_Lamp_oCAN00_68113534_Tx] */
  { /*    29 */     FALSE, COM_SINT16_APPLTYPEOFTXSIGINFO,       16u,        112u,         2u,                    14u,            80u,              78u,           2u },  /* [/ActiveEcuC/Com/ComConfig/MotorFoc_IvFiltered_A_MxA2_omsg_MyECU_Lamp_oCAN00_3e36d2b0_Tx] */
  { /*    30 */     FALSE, COM_SINT16_APPLTYPEOFTXSIGINFO,       16u,         64u,         2u,                     8u,            74u,              72u,           2u },  /* [/ActiveEcuC/Com/ComConfig/MotorFoc_IvRaw_A_MxA2_omsg_MyECU_Lamp_oCAN00_a7b61a95_Tx] */
  { /*    31 */     FALSE, COM_SINT16_APPLTYPEOFTXSIGINFO,       16u,        128u,         2u,                    16u,            18u,              16u,           0u },  /* [/ActiveEcuC/Com/ComConfig/MotorFoc_Iv_A_MxA0_omsg_MyECU_Lamp_oCAN00_7b390c47_Tx] */
  { /*    32 */     FALSE, COM_SINT16_APPLTYPEOFTXSIGINFO,       16u,        128u,         2u,                    16u,            82u,              80u,           2u },  /* [/ActiveEcuC/Com/ComConfig/MotorFoc_IwFiltered_A_MxA2_omsg_MyECU_Lamp_oCAN00_70bfd919_Tx] */
  { /*    33 */     FALSE, COM_SINT16_APPLTYPEOFTXSIGINFO,       16u,         80u,         2u,                    10u,            76u,              74u,           2u },  /* [/ActiveEcuC/Com/ComConfig/MotorFoc_IwRaw_A_MxA2_omsg_MyECU_Lamp_oCAN00_83344ba3_Tx] */
  { /*    34 */     FALSE, COM_SINT16_APPLTYPEOFTXSIGINFO,       16u,        144u,         2u,                    18u,            20u,              18u,           0u },  /* [/ActiveEcuC/Com/ComConfig/MotorFoc_Iw_A_MxA0_omsg_MyECU_Lamp_oCAN00_75dee496_Tx] */
  { /*    35 */     FALSE, COM_SINT16_APPLTYPEOFTXSIGINFO,       16u,        224u,         2u,                    28u,            30u,              28u,           0u },  /* [/ActiveEcuC/Com/ComConfig/MotorFoc_MechanicalSpeed_rpm_MxA0_omsg_MyECU_Lamp_oCAN00_04bd2026_Tx] */
  { /*    36 */     FALSE,  COM_UINT8_APPLTYPEOFTXSIGINFO,        8u,          8u,         1u,                     1u,            34u,              33u,           1u },  /* [/ActiveEcuC/Com/ComConfig/MotorFoc_MotorModePwm_MxA1_omsg_MyECU_Lamp_oCAN00_d3afa653_Tx] */
  { /*    37 */     FALSE,  COM_UINT8_APPLTYPEOFTXSIGINFO,        8u,          8u,         1u,                     1u,             2u,               1u,           0u },  /* [/ActiveEcuC/Com/ComConfig/MotorFoc_MotorMode_MxA0_omsg_MyECU_Lamp_oCAN00_aa7dbeca_Tx] */
  { /*    38 */     FALSE,  COM_UINT8_APPLTYPEOFTXSIGINFO,        8u,          0u,         1u,                     0u,             1u,               0u,           0u },  /* [/ActiveEcuC/Com/ComConfig/MotorFoc_Page_MxA0_omsg_MyECU_Lamp_oCAN00_9aab60ea_Tx] */
  { /*    39 */     FALSE,  COM_UINT8_APPLTYPEOFTXSIGINFO,        8u,          0u,         1u,                     0u,            33u,              32u,           1u },  /* [/ActiveEcuC/Com/ComConfig/MotorFoc_Page_MxA1_omsg_MyECU_Lamp_oCAN00_1b8e05cd_Tx] */
  { /*    40 */     FALSE,  COM_UINT8_APPLTYPEOFTXSIGINFO,        8u,          0u,         1u,                     0u,            65u,              64u,           2u },  /* [/ActiveEcuC/Com/ComConfig/MotorFoc_Page_MxA2_omsg_MyECU_Lamp_oCAN00_4390ace5_Tx] */
  { /*    41 */     FALSE, COM_UINT16_APPLTYPEOFTXSIGINFO,       16u,        160u,         2u,                    20u,            54u,              52u,           1u },  /* [/ActiveEcuC/Com/ComConfig/MotorFoc_PwmPeriod_MxA1_omsg_MyECU_Lamp_oCAN00_d26baca6_Tx] */
  { /*    42 */     FALSE, COM_UINT16_APPLTYPEOFTXSIGINFO,       16u,        112u,         2u,                    14u,            48u,              46u,           1u },  /* [/ActiveEcuC/Com/ComConfig/MotorFoc_PwmU_MxA1_omsg_MyECU_Lamp_oCAN00_c33fb364_Tx] */
  { /*    43 */     FALSE, COM_UINT16_APPLTYPEOFTXSIGINFO,       16u,        128u,         2u,                    16u,            50u,              48u,           1u },  /* [/ActiveEcuC/Com/ComConfig/MotorFoc_PwmV_MxA1_omsg_MyECU_Lamp_oCAN00_6637d808_Tx] */
  { /*    44 */     FALSE, COM_UINT16_APPLTYPEOFTXSIGINFO,       16u,        144u,         2u,                    18u,            52u,              50u,           1u },  /* [/ActiveEcuC/Com/ComConfig/MotorFoc_PwmW_MxA1_omsg_MyECU_Lamp_oCAN00_0530012c_Tx] */
  { /*    45 */     FALSE, COM_UINT16_APPLTYPEOFTXSIGINFO,       16u,         32u,         2u,                     4u,           102u,             100u,           3u },  /* [/ActiveEcuC/Com/ComConfig/MotorFoc_Sequence_Mx_omsg_MyECU_Lamp_oCAN00_339a541d_Tx] */
  { /*    46 */     FALSE, COM_SINT16_APPLTYPEOFTXSIGINFO,       16u,         80u,         2u,                    10u,            44u,              42u,           1u },  /* [/ActiveEcuC/Com/ComConfig/MotorFoc_ValphaRef_V_MxA1_omsg_MyECU_Lamp_oCAN00_dafa2b94_Tx] */
  { /*    47 */     FALSE, COM_SINT16_APPLTYPEOFTXSIGINFO,       16u,         96u,         2u,                    12u,            46u,              44u,           1u },  /* [/ActiveEcuC/Com/ComConfig/MotorFoc_VbetaRef_V_MxA1_omsg_MyECU_Lamp_oCAN00_623c36a7_Tx] */
  { /*    48 */     FALSE, COM_SINT16_APPLTYPEOFTXSIGINFO,       16u,         48u,         2u,                     6u,            40u,              38u,           1u },  /* [/ActiveEcuC/Com/ComConfig/MotorFoc_VdRef_V_MxA1_omsg_MyECU_Lamp_oCAN00_f0517bd4_Tx] */
  { /*    49 */     FALSE, COM_SINT16_APPLTYPEOFTXSIGINFO,       16u,        176u,         2u,                    22u,            56u,              54u,           1u },  /* [/ActiveEcuC/Com/ComConfig/MotorFoc_VdcMax_V_MxA1_omsg_MyECU_Lamp_oCAN00_8d3d4389_Tx] */
    /* Index    DynSignal  ApplType                        BitLength  BitPosition  ByteLength  StartByteInPduPosition  TxBufferEndIdx  TxBufferStartIdx  TxPduInfoIdx        Referable Keys */
  { /*    50 */     FALSE, COM_SINT16_APPLTYPEOFTXSIGINFO,       16u,        160u,         2u,                    20u,            22u,              20u,           0u },  /* [/ActiveEcuC/Com/ComConfig/MotorFoc_Vdc_V_MxA0_omsg_MyECU_Lamp_oCAN00_6919810c_Tx] */
  { /*    51 */     FALSE, COM_SINT16_APPLTYPEOFTXSIGINFO,       16u,        208u,         2u,                    26u,            92u,              90u,           2u },  /* [/ActiveEcuC/Com/ComConfig/MotorFoc_Vinv_V_MxA2_omsg_MyECU_Lamp_oCAN00_bd00cc55_Tx] */
  { /*    52 */     FALSE, COM_SINT16_APPLTYPEOFTXSIGINFO,       16u,         64u,         2u,                     8u,            42u,              40u,           1u },  /* [/ActiveEcuC/Com/ComConfig/MotorFoc_VqRef_V_MxA1_omsg_MyECU_Lamp_oCAN00_636c7799_Tx] */
  { /*    53 */     FALSE, COM_SINT16_APPLTYPEOFTXSIGINFO,       16u,        192u,         2u,                    24u,            90u,              88u,           2u },  /* [/ActiveEcuC/Com/ComConfig/MotorFoc_Vro_V_MxA2_omsg_MyECU_Lamp_oCAN00_a894d119_Tx] */
  { /*    54 */     FALSE,  COM_UINT8_APPLTYPEOFTXSIGINFO,        1u,          0u,         0u,                     0u,           129u,             128u,           4u }   /* [/ActiveEcuC/Com/ComConfig/sig_RearInteriorLight_omsg_Transmit_oCAN00_49a633c1_Tx] */
};
#define COM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Com_CurrentTxMode
**********************************************************************************************************************/
/** 
  \var    Com_CurrentTxMode
  \brief  Current transmission mode state of all Tx I-PDUs.
*/ 
#define COM_START_SEC_VAR_NO_INIT_8
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(Com_CurrentTxModeUType, COM_VAR_NO_INIT) Com_CurrentTxMode;  /* PRQA S 0759, 1514, 1533 */  /* MD_CSL_Union, MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys */
  /*     0 */  /* [/ActiveEcuC/Com/ComConfig/msg_MyECU_Lamp_MxA0_oCAN00_b76f77a4_Tx] */
  /*     1 */  /* [/ActiveEcuC/Com/ComConfig/msg_MyECU_Lamp_MxA1_oCAN00_7bc5773a_Tx] */
  /*     2 */  /* [/ActiveEcuC/Com/ComConfig/msg_MyECU_Lamp_MxA2_oCAN00_f54a70d9_Tx] */
  /*     3 */  /* [/ActiveEcuC/Com/ComConfig/msg_MyECU_Lamp_Mx_oCAN00_e57ca999_Tx] */
  /*     4 */  /* [/ActiveEcuC/Com/ComConfig/msg_Transmit_oCAN00_0723e95e_Tx] */

#define COM_STOP_SEC_VAR_NO_INIT_8
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Com_CycleTimeCnt
**********************************************************************************************************************/
/** 
  \var    Com_CycleTimeCnt
  \brief  Current counter value of cyclic transmission.
*/ 
#define COM_START_SEC_VAR_NO_INIT_8
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(Com_CycleTimeCntUType, COM_VAR_NO_INIT) Com_CycleTimeCnt;  /* PRQA S 0759, 1514, 1533 */  /* MD_CSL_Union, MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys */
  /*     0 */  /* [/ActiveEcuC/Com/ComConfig/msg_MyECU_Lamp_MxA0_oCAN00_b76f77a4_Tx] */
  /*     1 */  /* [/ActiveEcuC/Com/ComConfig/msg_MyECU_Lamp_MxA1_oCAN00_7bc5773a_Tx] */
  /*     2 */  /* [/ActiveEcuC/Com/ComConfig/msg_MyECU_Lamp_MxA2_oCAN00_f54a70d9_Tx] */
  /*     3 */  /* [/ActiveEcuC/Com/ComConfig/msg_MyECU_Lamp_Mx_oCAN00_e57ca999_Tx] */
  /*     4 */  /* [/ActiveEcuC/Com/ComConfig/msg_Transmit_oCAN00_0723e95e_Tx] */

#define COM_STOP_SEC_VAR_NO_INIT_8
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Com_CyclicSendRequest
**********************************************************************************************************************/
/** 
  \var    Com_CyclicSendRequest
  \brief  Cyclic send request flag used to indicate cyclic transmission mode for all Tx I-PDU.
*/ 
#define COM_START_SEC_VAR_NO_INIT_8
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(Com_CyclicSendRequestUType, COM_VAR_NO_INIT) Com_CyclicSendRequest;  /* PRQA S 0759, 1514, 1533 */  /* MD_CSL_Union, MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys */
  /*     0 */  /* [/ActiveEcuC/Com/ComConfig/msg_MyECU_Lamp_MxA0_oCAN00_b76f77a4_Tx] */
  /*     1 */  /* [/ActiveEcuC/Com/ComConfig/msg_MyECU_Lamp_MxA1_oCAN00_7bc5773a_Tx] */
  /*     2 */  /* [/ActiveEcuC/Com/ComConfig/msg_MyECU_Lamp_MxA2_oCAN00_f54a70d9_Tx] */
  /*     3 */  /* [/ActiveEcuC/Com/ComConfig/msg_MyECU_Lamp_Mx_oCAN00_e57ca999_Tx] */
  /*     4 */  /* [/ActiveEcuC/Com/ComConfig/msg_Transmit_oCAN00_0723e95e_Tx] */

#define COM_STOP_SEC_VAR_NO_INIT_8
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Com_HandleRxPduDeferred
**********************************************************************************************************************/
/** 
  \var    Com_HandleRxPduDeferred
  \brief  Array indicating received Rx I-PDUs to be processed deferred within the next call of Com_MainfunctionRx().
*/ 
#define COM_START_SEC_VAR_NO_INIT_8
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(Com_HandleRxPduDeferredUType, COM_VAR_NO_INIT) Com_HandleRxPduDeferred;  /* PRQA S 0759, 1514, 1533 */  /* MD_CSL_Union, MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys */
  /*     0 */  /* [/ActiveEcuC/Com/ComConfig/msg_Receive_oCAN00_2b456e3f_Rx] */

#define COM_STOP_SEC_VAR_NO_INIT_8
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Com_IPduGroupState
**********************************************************************************************************************/
#define COM_START_SEC_VAR_NO_INIT_8
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(Com_IPduGroupStateType, COM_VAR_NO_INIT) Com_IPduGroupState[2];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys */
  /*     0 */  /* [/ActiveEcuC/Com/ComConfig/MyECU_oCAN00_Rx_4cbf71f7, /ActiveEcuC/Com/ComConfig/msg_Receive_oCAN00_2b456e3f_Rx] */
  /*     1 */  /* [/ActiveEcuC/Com/ComConfig/MyECU_oCAN00_Tx_1ae5d671, /ActiveEcuC/Com/ComConfig/msg_MyECU_Lamp_MxA0_oCAN00_b76f77a4_Tx, /ActiveEcuC/Com/ComConfig/msg_MyECU_Lamp_MxA1_oCAN00_7bc5773a_Tx, /ActiveEcuC/Com/ComConfig/msg_MyECU_Lamp_MxA2_oCAN00_f54a70d9_Tx, /ActiveEcuC/Com/ComConfig/msg_MyECU_Lamp_Mx_oCAN00_e57ca999_Tx, /ActiveEcuC/Com/ComConfig/msg_Transmit_oCAN00_0723e95e_Tx] */

#define COM_STOP_SEC_VAR_NO_INIT_8
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Com_Initialized
**********************************************************************************************************************/
/** 
  \var    Com_Initialized
  \brief  Initialization state of Com. TRUE, if Com_Init() has been called, else FALSE.
*/ 
#define COM_START_SEC_VAR_CLEARED_8
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(Com_InitializedType, COM_VAR_CLEARED) Com_Initialized = FALSE;  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
#define COM_STOP_SEC_VAR_CLEARED_8
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Com_RxDefPduBuffer
**********************************************************************************************************************/
/** 
  \var    Com_RxDefPduBuffer
  \brief  Rx I-PDU buffer for deferred signal processing.
*/ 
#define COM_START_SEC_VAR_NO_INIT_8
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(Com_RxDefPduBufferUType, COM_VAR_NO_INIT) Com_RxDefPduBuffer;  /* PRQA S 0759, 1514, 1533 */  /* MD_CSL_Union, MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys */
  /*     0 */  /* [/ActiveEcuC/Com/ComConfig/msg_Receive_oCAN00_2b456e3f_Rx] */

#define COM_STOP_SEC_VAR_NO_INIT_8
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Com_RxIPduGroupISRLockCounter
**********************************************************************************************************************/
#define COM_START_SEC_VAR_NO_INIT_16
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(Com_RxIPduGroupISRLockCounterUType, COM_VAR_NO_INIT) Com_RxIPduGroupISRLockCounter;  /* PRQA S 0759, 1514, 1533 */  /* MD_CSL_Union, MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys */
  /*     0 */  /* [noPartition] */

#define COM_STOP_SEC_VAR_NO_INIT_16
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Com_RxMainFunctionProcessingISRLockCounter
**********************************************************************************************************************/
#define COM_START_SEC_VAR_NO_INIT_16
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(Com_RxMainFunctionProcessingISRLockCounterUType, COM_VAR_NO_INIT) Com_RxMainFunctionProcessingISRLockCounter;  /* PRQA S 0759, 1514, 1533 */  /* MD_CSL_Union, MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys */
  /*     0 */  /* [ComMainFunctionRx] */

#define COM_STOP_SEC_VAR_NO_INIT_16
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Com_RxPduGrpActive
**********************************************************************************************************************/
/** 
  \var    Com_RxPduGrpActive
  \brief  Rx I-PDU based state (started/stopped) of the corresponding I-PDU-Group.
*/ 
#define COM_START_SEC_VAR_NO_INIT_8
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(Com_RxPduGrpActiveType, COM_VAR_NO_INIT) Com_RxPduGrpActive[1];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys */
  /*     0 */  /* [/ActiveEcuC/Com/ComConfig/msg_Receive_oCAN00_2b456e3f_Rx, /ActiveEcuC/Com/ComConfig/MyECU_oCAN00_Rx_4cbf71f7, ComMainFunctionRx] */

#define COM_STOP_SEC_VAR_NO_INIT_8
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Com_RxSigBufferUInt8
**********************************************************************************************************************/
/** 
  \var    Com_RxSigBufferUInt8
  \brief  Rx Signal and Group Signal Buffer. (BOOLEAN, UINT8)
*/ 
#define COM_START_SEC_VAR_NO_INIT_8
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(Com_RxSigBufferUInt8Type, COM_VAR_NO_INIT) Com_RxSigBufferUInt8[2];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys */
  /*     0 */  /* [/ActiveEcuC/Com/ComConfig/sig_State_RearLeftDoor_omsg_Receive_oCAN00_84ad4140_Rx, /ActiveEcuC/Com/ComConfig/sig_State_RearLeftDoor_omsg_Receive_oCAN00_84ad4140_Rx_RxSignalBufferRouting] */
  /*     1 */  /* [/ActiveEcuC/Com/ComConfig/sig_State_RearRightDoor_omsg_Receive_oCAN00_a8945098_Rx, /ActiveEcuC/Com/ComConfig/sig_State_RearRightDoor_omsg_Receive_oCAN00_a8945098_Rx_RxSignalBufferRouting] */

#define COM_STOP_SEC_VAR_NO_INIT_8
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Com_TransmitRequest
**********************************************************************************************************************/
/** 
  \var    Com_TransmitRequest
  \brief  Transmit request flag used for decoupled Tx I-PDU tranmission.
*/ 
#define COM_START_SEC_VAR_NO_INIT_8
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(Com_TransmitRequestUType, COM_VAR_NO_INIT) Com_TransmitRequest;  /* PRQA S 0759, 1514, 1533 */  /* MD_CSL_Union, MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys */
  /*     0 */  /* [/ActiveEcuC/Com/ComConfig/msg_MyECU_Lamp_MxA0_oCAN00_b76f77a4_Tx] */
  /*     1 */  /* [/ActiveEcuC/Com/ComConfig/msg_MyECU_Lamp_MxA1_oCAN00_7bc5773a_Tx] */
  /*     2 */  /* [/ActiveEcuC/Com/ComConfig/msg_MyECU_Lamp_MxA2_oCAN00_f54a70d9_Tx] */
  /*     3 */  /* [/ActiveEcuC/Com/ComConfig/msg_MyECU_Lamp_Mx_oCAN00_e57ca999_Tx] */
  /*     4 */  /* [/ActiveEcuC/Com/ComConfig/msg_Transmit_oCAN00_0723e95e_Tx] */

#define COM_STOP_SEC_VAR_NO_INIT_8
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Com_TxBuffer
**********************************************************************************************************************/
/** 
  \var    Com_TxBuffer
  \brief  Shared uint8 buffer for Tx I-PDUs and ComSignalGroup shadow buffer.
*/ 
#define COM_START_SEC_VAR_NO_INIT_8
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(Com_TxBufferType, COM_VAR_NO_INIT) Com_TxBuffer[129];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys */
  /*     0 */  /* [/ActiveEcuC/Com/ComConfig/msg_MyECU_Lamp_MxA0_oCAN00_b76f77a4_Tx, /ActiveEcuC/Com/ComConfig/MotorFoc_Page_MxA0_omsg_MyECU_Lamp_oCAN00_9aab60ea_Tx] */
  /*     1 */  /* [/ActiveEcuC/Com/ComConfig/msg_MyECU_Lamp_MxA0_oCAN00_b76f77a4_Tx, /ActiveEcuC/Com/ComConfig/MotorFoc_MotorMode_MxA0_omsg_MyECU_Lamp_oCAN00_aa7dbeca_Tx] */
  /*     2 */  /* [/ActiveEcuC/Com/ComConfig/msg_MyECU_Lamp_MxA0_oCAN00_b76f77a4_Tx, /ActiveEcuC/Com/ComConfig/MotorFoc_Fault_MxA0_omsg_MyECU_Lamp_oCAN00_3dd6add5_Tx] */
  /*     3 */  /* [/ActiveEcuC/Com/ComConfig/msg_MyECU_Lamp_MxA0_oCAN00_b76f77a4_Tx, /ActiveEcuC/Com/ComConfig/MotorFoc_FaultReason_MxA0_omsg_MyECU_Lamp_oCAN00_0576dfc4_Tx] */
  /*     4 */  /* [/ActiveEcuC/Com/ComConfig/msg_MyECU_Lamp_MxA0_oCAN00_b76f77a4_Tx] */
  /*     5 */  /* [/ActiveEcuC/Com/ComConfig/msg_MyECU_Lamp_MxA0_oCAN00_b76f77a4_Tx] */
  /*     6 */  /* [/ActiveEcuC/Com/ComConfig/msg_MyECU_Lamp_MxA0_oCAN00_b76f77a4_Tx, /ActiveEcuC/Com/ComConfig/MotorFoc_IdRef_A_MxA0_omsg_MyECU_Lamp_oCAN00_832c12be_Tx] */
  /*     7 */  /* [/ActiveEcuC/Com/ComConfig/msg_MyECU_Lamp_MxA0_oCAN00_b76f77a4_Tx, /ActiveEcuC/Com/ComConfig/MotorFoc_IdRef_A_MxA0_omsg_MyECU_Lamp_oCAN00_832c12be_Tx] */
  /*     8 */  /* [/ActiveEcuC/Com/ComConfig/msg_MyECU_Lamp_MxA0_oCAN00_b76f77a4_Tx, /ActiveEcuC/Com/ComConfig/MotorFoc_IqRef_A_MxA0_omsg_MyECU_Lamp_oCAN00_10111ef3_Tx] */
  /*     9 */  /* [/ActiveEcuC/Com/ComConfig/msg_MyECU_Lamp_MxA0_oCAN00_b76f77a4_Tx, /ActiveEcuC/Com/ComConfig/MotorFoc_IqRef_A_MxA0_omsg_MyECU_Lamp_oCAN00_10111ef3_Tx] */
  /*    10 */  /* [/ActiveEcuC/Com/ComConfig/msg_MyECU_Lamp_MxA0_oCAN00_b76f77a4_Tx, /ActiveEcuC/Com/ComConfig/MotorFoc_Id_A_MxA0_omsg_MyECU_Lamp_oCAN00_888850f5_Tx] */
  /*    11 */  /* [/ActiveEcuC/Com/ComConfig/msg_MyECU_Lamp_MxA0_oCAN00_b76f77a4_Tx, /ActiveEcuC/Com/ComConfig/MotorFoc_Id_A_MxA0_omsg_MyECU_Lamp_oCAN00_888850f5_Tx] */
  /*    12 */  /* [/ActiveEcuC/Com/ComConfig/msg_MyECU_Lamp_MxA0_oCAN00_b76f77a4_Tx, /ActiveEcuC/Com/ComConfig/MotorFoc_Iq_A_MxA0_omsg_MyECU_Lamp_oCAN00_538e9670_Tx] */
  /*    13 */  /* [/ActiveEcuC/Com/ComConfig/msg_MyECU_Lamp_MxA0_oCAN00_b76f77a4_Tx, /ActiveEcuC/Com/ComConfig/MotorFoc_Iq_A_MxA0_omsg_MyECU_Lamp_oCAN00_538e9670_Tx] */
  /*    14 */  /* [/ActiveEcuC/Com/ComConfig/msg_MyECU_Lamp_MxA0_oCAN00_b76f77a4_Tx, /ActiveEcuC/Com/ComConfig/MotorFoc_Iu_A_MxA0_omsg_MyECU_Lamp_oCAN00_68113534_Tx] */
  /*    15 */  /* [/ActiveEcuC/Com/ComConfig/msg_MyECU_Lamp_MxA0_oCAN00_b76f77a4_Tx, /ActiveEcuC/Com/ComConfig/MotorFoc_Iu_A_MxA0_omsg_MyECU_Lamp_oCAN00_68113534_Tx] */
  /*    16 */  /* [/ActiveEcuC/Com/ComConfig/msg_MyECU_Lamp_MxA0_oCAN00_b76f77a4_Tx, /ActiveEcuC/Com/ComConfig/MotorFoc_Iv_A_MxA0_omsg_MyECU_Lamp_oCAN00_7b390c47_Tx] */
  /*    17 */  /* [/ActiveEcuC/Com/ComConfig/msg_MyECU_Lamp_MxA0_oCAN00_b76f77a4_Tx, /ActiveEcuC/Com/ComConfig/MotorFoc_Iv_A_MxA0_omsg_MyECU_Lamp_oCAN00_7b390c47_Tx] */
  /*    18 */  /* [/ActiveEcuC/Com/ComConfig/msg_MyECU_Lamp_MxA0_oCAN00_b76f77a4_Tx, /ActiveEcuC/Com/ComConfig/MotorFoc_Iw_A_MxA0_omsg_MyECU_Lamp_oCAN00_75dee496_Tx] */
  /*    19 */  /* [/ActiveEcuC/Com/ComConfig/msg_MyECU_Lamp_MxA0_oCAN00_b76f77a4_Tx, /ActiveEcuC/Com/ComConfig/MotorFoc_Iw_A_MxA0_omsg_MyECU_Lamp_oCAN00_75dee496_Tx] */
  /*    20 */  /* [/ActiveEcuC/Com/ComConfig/msg_MyECU_Lamp_MxA0_oCAN00_b76f77a4_Tx, /ActiveEcuC/Com/ComConfig/MotorFoc_Vdc_V_MxA0_omsg_MyECU_Lamp_oCAN00_6919810c_Tx] */
  /*    21 */  /* [/ActiveEcuC/Com/ComConfig/msg_MyECU_Lamp_MxA0_oCAN00_b76f77a4_Tx, /ActiveEcuC/Com/ComConfig/MotorFoc_Vdc_V_MxA0_omsg_MyECU_Lamp_oCAN00_6919810c_Tx] */
  /*    22 */  /* [/ActiveEcuC/Com/ComConfig/msg_MyECU_Lamp_MxA0_oCAN00_b76f77a4_Tx, /ActiveEcuC/Com/ComConfig/MotorFoc_AngleRaw_MxA0_omsg_MyECU_Lamp_oCAN00_7aec7e78_Tx] */
  /*    23 */  /* [/ActiveEcuC/Com/ComConfig/msg_MyECU_Lamp_MxA0_oCAN00_b76f77a4_Tx, /ActiveEcuC/Com/ComConfig/MotorFoc_AngleRaw_MxA0_omsg_MyECU_Lamp_oCAN00_7aec7e78_Tx] */
  /*    24 */  /* [/ActiveEcuC/Com/ComConfig/msg_MyECU_Lamp_MxA0_oCAN00_b76f77a4_Tx, /ActiveEcuC/Com/ComConfig/MotorFoc_ElectricalAngle_rad_MxA0_omsg_MyECU_Lamp_oCAN00_5447ad3f_Tx] */
  /*    25 */  /* [/ActiveEcuC/Com/ComConfig/msg_MyECU_Lamp_MxA0_oCAN00_b76f77a4_Tx, /ActiveEcuC/Com/ComConfig/MotorFoc_ElectricalAngle_rad_MxA0_omsg_MyECU_Lamp_oCAN00_5447ad3f_Tx] */
  /*    26 */  /* [/ActiveEcuC/Com/ComConfig/msg_MyECU_Lamp_MxA0_oCAN00_b76f77a4_Tx, /ActiveEcuC/Com/ComConfig/MotorFoc_CurrentOffsetReady_MxA0_omsg_MyECU_Lamp_oCAN00_81ce1bc4_Tx] */
  /*    27 */  /* [/ActiveEcuC/Com/ComConfig/msg_MyECU_Lamp_MxA0_oCAN00_b76f77a4_Tx, /ActiveEcuC/Com/ComConfig/MotorFoc_CurrentOffsetSampleCount_MxA0_omsg_MyECU_Lamp_oCAN00_6c5c0a81_Tx] */
  /*    28 */  /* [/ActiveEcuC/Com/ComConfig/msg_MyECU_Lamp_MxA0_oCAN00_b76f77a4_Tx, /ActiveEcuC/Com/ComConfig/MotorFoc_MechanicalSpeed_rpm_MxA0_omsg_MyECU_Lamp_oCAN00_04bd2026_Tx] */
  /*    29 */  /* [/ActiveEcuC/Com/ComConfig/msg_MyECU_Lamp_MxA0_oCAN00_b76f77a4_Tx, /ActiveEcuC/Com/ComConfig/MotorFoc_MechanicalSpeed_rpm_MxA0_omsg_MyECU_Lamp_oCAN00_04bd2026_Tx] */
  /*    30 */  /* [/ActiveEcuC/Com/ComConfig/msg_MyECU_Lamp_MxA0_oCAN00_b76f77a4_Tx, /ActiveEcuC/Com/ComConfig/MotorFoc_GateDriverState_MxA0_omsg_MyECU_Lamp_oCAN00_e2e4dde6_Tx] */
  /*    31 */  /* [/ActiveEcuC/Com/ComConfig/msg_MyECU_Lamp_MxA0_oCAN00_b76f77a4_Tx, /ActiveEcuC/Com/ComConfig/MotorFoc_GateDriverOutputEnabled_MxA0_omsg_MyECU_Lamp_oCAN00_6012a7f7_Tx] */
  /*    32 */  /* [/ActiveEcuC/Com/ComConfig/msg_MyECU_Lamp_MxA1_oCAN00_7bc5773a_Tx, /ActiveEcuC/Com/ComConfig/MotorFoc_Page_MxA1_omsg_MyECU_Lamp_oCAN00_1b8e05cd_Tx] */
  /*    33 */  /* [/ActiveEcuC/Com/ComConfig/msg_MyECU_Lamp_MxA1_oCAN00_7bc5773a_Tx, /ActiveEcuC/Com/ComConfig/MotorFoc_MotorModePwm_MxA1_omsg_MyECU_Lamp_oCAN00_d3afa653_Tx] */
  /*    34 */  /* [/ActiveEcuC/Com/ComConfig/msg_MyECU_Lamp_MxA1_oCAN00_7bc5773a_Tx, /ActiveEcuC/Com/ComConfig/MotorFoc_FaultPwm_MxA1_omsg_MyECU_Lamp_oCAN00_e43e797b_Tx] */
  /*    35 */  /* [/ActiveEcuC/Com/ComConfig/msg_MyECU_Lamp_MxA1_oCAN00_7bc5773a_Tx, /ActiveEcuC/Com/ComConfig/MotorFoc_FaultReasonPwm_MxA1_omsg_MyECU_Lamp_oCAN00_32050898_Tx] */
  /*    36 */  /* [/ActiveEcuC/Com/ComConfig/msg_MyECU_Lamp_MxA1_oCAN00_7bc5773a_Tx] */
  /*    37 */  /* [/ActiveEcuC/Com/ComConfig/msg_MyECU_Lamp_MxA1_oCAN00_7bc5773a_Tx] */
  /*    38 */  /* [/ActiveEcuC/Com/ComConfig/msg_MyECU_Lamp_MxA1_oCAN00_7bc5773a_Tx, /ActiveEcuC/Com/ComConfig/MotorFoc_VdRef_V_MxA1_omsg_MyECU_Lamp_oCAN00_f0517bd4_Tx] */
  /*    39 */  /* [/ActiveEcuC/Com/ComConfig/msg_MyECU_Lamp_MxA1_oCAN00_7bc5773a_Tx, /ActiveEcuC/Com/ComConfig/MotorFoc_VdRef_V_MxA1_omsg_MyECU_Lamp_oCAN00_f0517bd4_Tx] */
  /*    40 */  /* [/ActiveEcuC/Com/ComConfig/msg_MyECU_Lamp_MxA1_oCAN00_7bc5773a_Tx, /ActiveEcuC/Com/ComConfig/MotorFoc_VqRef_V_MxA1_omsg_MyECU_Lamp_oCAN00_636c7799_Tx] */
  /*    41 */  /* [/ActiveEcuC/Com/ComConfig/msg_MyECU_Lamp_MxA1_oCAN00_7bc5773a_Tx, /ActiveEcuC/Com/ComConfig/MotorFoc_VqRef_V_MxA1_omsg_MyECU_Lamp_oCAN00_636c7799_Tx] */
  /*    42 */  /* [/ActiveEcuC/Com/ComConfig/msg_MyECU_Lamp_MxA1_oCAN00_7bc5773a_Tx, /ActiveEcuC/Com/ComConfig/MotorFoc_ValphaRef_V_MxA1_omsg_MyECU_Lamp_oCAN00_dafa2b94_Tx] */
  /*    43 */  /* [/ActiveEcuC/Com/ComConfig/msg_MyECU_Lamp_MxA1_oCAN00_7bc5773a_Tx, /ActiveEcuC/Com/ComConfig/MotorFoc_ValphaRef_V_MxA1_omsg_MyECU_Lamp_oCAN00_dafa2b94_Tx] */
  /*    44 */  /* [/ActiveEcuC/Com/ComConfig/msg_MyECU_Lamp_MxA1_oCAN00_7bc5773a_Tx, /ActiveEcuC/Com/ComConfig/MotorFoc_VbetaRef_V_MxA1_omsg_MyECU_Lamp_oCAN00_623c36a7_Tx] */
  /*    45 */  /* [/ActiveEcuC/Com/ComConfig/msg_MyECU_Lamp_MxA1_oCAN00_7bc5773a_Tx, /ActiveEcuC/Com/ComConfig/MotorFoc_VbetaRef_V_MxA1_omsg_MyECU_Lamp_oCAN00_623c36a7_Tx] */
  /*    46 */  /* [/ActiveEcuC/Com/ComConfig/msg_MyECU_Lamp_MxA1_oCAN00_7bc5773a_Tx, /ActiveEcuC/Com/ComConfig/MotorFoc_PwmU_MxA1_omsg_MyECU_Lamp_oCAN00_c33fb364_Tx] */
  /*    47 */  /* [/ActiveEcuC/Com/ComConfig/msg_MyECU_Lamp_MxA1_oCAN00_7bc5773a_Tx, /ActiveEcuC/Com/ComConfig/MotorFoc_PwmU_MxA1_omsg_MyECU_Lamp_oCAN00_c33fb364_Tx] */
  /*    48 */  /* [/ActiveEcuC/Com/ComConfig/msg_MyECU_Lamp_MxA1_oCAN00_7bc5773a_Tx, /ActiveEcuC/Com/ComConfig/MotorFoc_PwmV_MxA1_omsg_MyECU_Lamp_oCAN00_6637d808_Tx] */
  /*    49 */  /* [/ActiveEcuC/Com/ComConfig/msg_MyECU_Lamp_MxA1_oCAN00_7bc5773a_Tx, /ActiveEcuC/Com/ComConfig/MotorFoc_PwmV_MxA1_omsg_MyECU_Lamp_oCAN00_6637d808_Tx] */
  /* Index        Referable Keys */
  /*    50 */  /* [/ActiveEcuC/Com/ComConfig/msg_MyECU_Lamp_MxA1_oCAN00_7bc5773a_Tx, /ActiveEcuC/Com/ComConfig/MotorFoc_PwmW_MxA1_omsg_MyECU_Lamp_oCAN00_0530012c_Tx] */
  /*    51 */  /* [/ActiveEcuC/Com/ComConfig/msg_MyECU_Lamp_MxA1_oCAN00_7bc5773a_Tx, /ActiveEcuC/Com/ComConfig/MotorFoc_PwmW_MxA1_omsg_MyECU_Lamp_oCAN00_0530012c_Tx] */
  /*    52 */  /* [/ActiveEcuC/Com/ComConfig/msg_MyECU_Lamp_MxA1_oCAN00_7bc5773a_Tx, /ActiveEcuC/Com/ComConfig/MotorFoc_PwmPeriod_MxA1_omsg_MyECU_Lamp_oCAN00_d26baca6_Tx] */
  /*    53 */  /* [/ActiveEcuC/Com/ComConfig/msg_MyECU_Lamp_MxA1_oCAN00_7bc5773a_Tx, /ActiveEcuC/Com/ComConfig/MotorFoc_PwmPeriod_MxA1_omsg_MyECU_Lamp_oCAN00_d26baca6_Tx] */
  /*    54 */  /* [/ActiveEcuC/Com/ComConfig/msg_MyECU_Lamp_MxA1_oCAN00_7bc5773a_Tx, /ActiveEcuC/Com/ComConfig/MotorFoc_VdcMax_V_MxA1_omsg_MyECU_Lamp_oCAN00_8d3d4389_Tx] */
  /*    55 */  /* [/ActiveEcuC/Com/ComConfig/msg_MyECU_Lamp_MxA1_oCAN00_7bc5773a_Tx, /ActiveEcuC/Com/ComConfig/MotorFoc_VdcMax_V_MxA1_omsg_MyECU_Lamp_oCAN00_8d3d4389_Tx] */
  /*    56 */  /* [/ActiveEcuC/Com/ComConfig/msg_MyECU_Lamp_MxA1_oCAN00_7bc5773a_Tx, /ActiveEcuC/Com/ComConfig/MotorFoc_FaultIu_A_MxA1_omsg_MyECU_Lamp_oCAN00_99a1880c_Tx] */
  /*    57 */  /* [/ActiveEcuC/Com/ComConfig/msg_MyECU_Lamp_MxA1_oCAN00_7bc5773a_Tx, /ActiveEcuC/Com/ComConfig/MotorFoc_FaultIu_A_MxA1_omsg_MyECU_Lamp_oCAN00_99a1880c_Tx] */
  /*    58 */  /* [/ActiveEcuC/Com/ComConfig/msg_MyECU_Lamp_MxA1_oCAN00_7bc5773a_Tx, /ActiveEcuC/Com/ComConfig/MotorFoc_FaultIv_A_MxA1_omsg_MyECU_Lamp_oCAN00_8a89b17f_Tx] */
  /*    59 */  /* [/ActiveEcuC/Com/ComConfig/msg_MyECU_Lamp_MxA1_oCAN00_7bc5773a_Tx, /ActiveEcuC/Com/ComConfig/MotorFoc_FaultIv_A_MxA1_omsg_MyECU_Lamp_oCAN00_8a89b17f_Tx] */
  /*    60 */  /* [/ActiveEcuC/Com/ComConfig/msg_MyECU_Lamp_MxA1_oCAN00_7bc5773a_Tx, /ActiveEcuC/Com/ComConfig/MotorFoc_FaultIw_A_MxA1_omsg_MyECU_Lamp_oCAN00_846e59ae_Tx] */
  /*    61 */  /* [/ActiveEcuC/Com/ComConfig/msg_MyECU_Lamp_MxA1_oCAN00_7bc5773a_Tx, /ActiveEcuC/Com/ComConfig/MotorFoc_FaultIw_A_MxA1_omsg_MyECU_Lamp_oCAN00_846e59ae_Tx] */
  /*    62 */  /* [/ActiveEcuC/Com/ComConfig/msg_MyECU_Lamp_MxA1_oCAN00_7bc5773a_Tx, /ActiveEcuC/Com/ComConfig/MotorFoc_FaultVdc_V_MxA1_omsg_MyECU_Lamp_oCAN00_65447c06_Tx] */
  /*    63 */  /* [/ActiveEcuC/Com/ComConfig/msg_MyECU_Lamp_MxA1_oCAN00_7bc5773a_Tx, /ActiveEcuC/Com/ComConfig/MotorFoc_FaultVdc_V_MxA1_omsg_MyECU_Lamp_oCAN00_65447c06_Tx] */
  /*    64 */  /* [/ActiveEcuC/Com/ComConfig/msg_MyECU_Lamp_MxA2_oCAN00_f54a70d9_Tx, /ActiveEcuC/Com/ComConfig/MotorFoc_Page_MxA2_omsg_MyECU_Lamp_oCAN00_4390ace5_Tx] */
  /*    65 */  /* [/ActiveEcuC/Com/ComConfig/msg_MyECU_Lamp_MxA2_oCAN00_f54a70d9_Tx, /ActiveEcuC/Com/ComConfig/MotorFoc_AdcFilterEnabled_MxA2_omsg_MyECU_Lamp_oCAN00_bb1a16f8_Tx] */
  /*    66 */  /* [/ActiveEcuC/Com/ComConfig/msg_MyECU_Lamp_MxA2_oCAN00_f54a70d9_Tx, /ActiveEcuC/Com/ComConfig/MotorFoc_AdcFilterReady_MxA2_omsg_MyECU_Lamp_oCAN00_dd22f986_Tx] */
  /*    67 */  /* [/ActiveEcuC/Com/ComConfig/msg_MyECU_Lamp_MxA2_oCAN00_f54a70d9_Tx, /ActiveEcuC/Com/ComConfig/MotorFoc_AdcFilterAlpha_MxA2_omsg_MyECU_Lamp_oCAN00_4c48c598_Tx] */
  /*    68 */  /* [/ActiveEcuC/Com/ComConfig/msg_MyECU_Lamp_MxA2_oCAN00_f54a70d9_Tx] */
  /*    69 */  /* [/ActiveEcuC/Com/ComConfig/msg_MyECU_Lamp_MxA2_oCAN00_f54a70d9_Tx] */
  /*    70 */  /* [/ActiveEcuC/Com/ComConfig/msg_MyECU_Lamp_MxA2_oCAN00_f54a70d9_Tx, /ActiveEcuC/Com/ComConfig/MotorFoc_IuRaw_A_MxA2_omsg_MyECU_Lamp_oCAN00_ca30e9cf_Tx] */
  /*    71 */  /* [/ActiveEcuC/Com/ComConfig/msg_MyECU_Lamp_MxA2_oCAN00_f54a70d9_Tx, /ActiveEcuC/Com/ComConfig/MotorFoc_IuRaw_A_MxA2_omsg_MyECU_Lamp_oCAN00_ca30e9cf_Tx] */
  /*    72 */  /* [/ActiveEcuC/Com/ComConfig/msg_MyECU_Lamp_MxA2_oCAN00_f54a70d9_Tx, /ActiveEcuC/Com/ComConfig/MotorFoc_IvRaw_A_MxA2_omsg_MyECU_Lamp_oCAN00_a7b61a95_Tx] */
  /*    73 */  /* [/ActiveEcuC/Com/ComConfig/msg_MyECU_Lamp_MxA2_oCAN00_f54a70d9_Tx, /ActiveEcuC/Com/ComConfig/MotorFoc_IvRaw_A_MxA2_omsg_MyECU_Lamp_oCAN00_a7b61a95_Tx] */
  /*    74 */  /* [/ActiveEcuC/Com/ComConfig/msg_MyECU_Lamp_MxA2_oCAN00_f54a70d9_Tx, /ActiveEcuC/Com/ComConfig/MotorFoc_IwRaw_A_MxA2_omsg_MyECU_Lamp_oCAN00_83344ba3_Tx] */
  /*    75 */  /* [/ActiveEcuC/Com/ComConfig/msg_MyECU_Lamp_MxA2_oCAN00_f54a70d9_Tx, /ActiveEcuC/Com/ComConfig/MotorFoc_IwRaw_A_MxA2_omsg_MyECU_Lamp_oCAN00_83344ba3_Tx] */
  /*    76 */  /* [/ActiveEcuC/Com/ComConfig/msg_MyECU_Lamp_MxA2_oCAN00_f54a70d9_Tx, /ActiveEcuC/Com/ComConfig/MotorFoc_IuFiltered_A_MxA2_omsg_MyECU_Lamp_oCAN00_edadce4b_Tx] */
  /*    77 */  /* [/ActiveEcuC/Com/ComConfig/msg_MyECU_Lamp_MxA2_oCAN00_f54a70d9_Tx, /ActiveEcuC/Com/ComConfig/MotorFoc_IuFiltered_A_MxA2_omsg_MyECU_Lamp_oCAN00_edadce4b_Tx] */
  /*    78 */  /* [/ActiveEcuC/Com/ComConfig/msg_MyECU_Lamp_MxA2_oCAN00_f54a70d9_Tx, /ActiveEcuC/Com/ComConfig/MotorFoc_IvFiltered_A_MxA2_omsg_MyECU_Lamp_oCAN00_3e36d2b0_Tx] */
  /*    79 */  /* [/ActiveEcuC/Com/ComConfig/msg_MyECU_Lamp_MxA2_oCAN00_f54a70d9_Tx, /ActiveEcuC/Com/ComConfig/MotorFoc_IvFiltered_A_MxA2_omsg_MyECU_Lamp_oCAN00_3e36d2b0_Tx] */
  /*    80 */  /* [/ActiveEcuC/Com/ComConfig/msg_MyECU_Lamp_MxA2_oCAN00_f54a70d9_Tx, /ActiveEcuC/Com/ComConfig/MotorFoc_IwFiltered_A_MxA2_omsg_MyECU_Lamp_oCAN00_70bfd919_Tx] */
  /*    81 */  /* [/ActiveEcuC/Com/ComConfig/msg_MyECU_Lamp_MxA2_oCAN00_f54a70d9_Tx, /ActiveEcuC/Com/ComConfig/MotorFoc_IwFiltered_A_MxA2_omsg_MyECU_Lamp_oCAN00_70bfd919_Tx] */
  /*    82 */  /* [/ActiveEcuC/Com/ComConfig/msg_MyECU_Lamp_MxA2_oCAN00_f54a70d9_Tx, /ActiveEcuC/Com/ComConfig/MotorFoc_AdcOffsetVo1_MxA2_omsg_MyECU_Lamp_oCAN00_7e4e712f_Tx] */
  /*    83 */  /* [/ActiveEcuC/Com/ComConfig/msg_MyECU_Lamp_MxA2_oCAN00_f54a70d9_Tx, /ActiveEcuC/Com/ComConfig/MotorFoc_AdcOffsetVo1_MxA2_omsg_MyECU_Lamp_oCAN00_7e4e712f_Tx] */
  /*    84 */  /* [/ActiveEcuC/Com/ComConfig/msg_MyECU_Lamp_MxA2_oCAN00_f54a70d9_Tx, /ActiveEcuC/Com/ComConfig/MotorFoc_AdcOffsetVo2_MxA2_omsg_MyECU_Lamp_oCAN00_db461a43_Tx] */
  /*    85 */  /* [/ActiveEcuC/Com/ComConfig/msg_MyECU_Lamp_MxA2_oCAN00_f54a70d9_Tx, /ActiveEcuC/Com/ComConfig/MotorFoc_AdcOffsetVo2_MxA2_omsg_MyECU_Lamp_oCAN00_db461a43_Tx] */
  /*    86 */  /* [/ActiveEcuC/Com/ComConfig/msg_MyECU_Lamp_MxA2_oCAN00_f54a70d9_Tx, /ActiveEcuC/Com/ComConfig/MotorFoc_AdcOffsetVo3_MxA2_omsg_MyECU_Lamp_oCAN00_b841c367_Tx] */
  /*    87 */  /* [/ActiveEcuC/Com/ComConfig/msg_MyECU_Lamp_MxA2_oCAN00_f54a70d9_Tx, /ActiveEcuC/Com/ComConfig/MotorFoc_AdcOffsetVo3_MxA2_omsg_MyECU_Lamp_oCAN00_b841c367_Tx] */
  /*    88 */  /* [/ActiveEcuC/Com/ComConfig/msg_MyECU_Lamp_MxA2_oCAN00_f54a70d9_Tx, /ActiveEcuC/Com/ComConfig/MotorFoc_Vro_V_MxA2_omsg_MyECU_Lamp_oCAN00_a894d119_Tx] */
  /*    89 */  /* [/ActiveEcuC/Com/ComConfig/msg_MyECU_Lamp_MxA2_oCAN00_f54a70d9_Tx, /ActiveEcuC/Com/ComConfig/MotorFoc_Vro_V_MxA2_omsg_MyECU_Lamp_oCAN00_a894d119_Tx] */
  /*    90 */  /* [/ActiveEcuC/Com/ComConfig/msg_MyECU_Lamp_MxA2_oCAN00_f54a70d9_Tx, /ActiveEcuC/Com/ComConfig/MotorFoc_Vinv_V_MxA2_omsg_MyECU_Lamp_oCAN00_bd00cc55_Tx] */
  /*    91 */  /* [/ActiveEcuC/Com/ComConfig/msg_MyECU_Lamp_MxA2_oCAN00_f54a70d9_Tx, /ActiveEcuC/Com/ComConfig/MotorFoc_Vinv_V_MxA2_omsg_MyECU_Lamp_oCAN00_bd00cc55_Tx] */
  /*    92 */  /* [/ActiveEcuC/Com/ComConfig/msg_MyECU_Lamp_MxA2_oCAN00_f54a70d9_Tx, /ActiveEcuC/Com/ComConfig/MotorFoc_AdcSyncCounter_MxA2_omsg_MyECU_Lamp_oCAN00_8264daf6_Tx] */
  /*    93 */  /* [/ActiveEcuC/Com/ComConfig/msg_MyECU_Lamp_MxA2_oCAN00_f54a70d9_Tx, /ActiveEcuC/Com/ComConfig/MotorFoc_AdcSyncCounter_MxA2_omsg_MyECU_Lamp_oCAN00_8264daf6_Tx] */
  /*    94 */  /* [/ActiveEcuC/Com/ComConfig/msg_MyECU_Lamp_MxA2_oCAN00_f54a70d9_Tx, /ActiveEcuC/Com/ComConfig/MotorFoc_AdcOffsetSampleCount_MxA2_omsg_MyECU_Lamp_oCAN00_98a9a073_Tx] */
  /*    95 */  /* [/ActiveEcuC/Com/ComConfig/msg_MyECU_Lamp_MxA2_oCAN00_f54a70d9_Tx, /ActiveEcuC/Com/ComConfig/MotorFoc_AdcOffsetSampleCount_MxA2_omsg_MyECU_Lamp_oCAN00_98a9a073_Tx] */
  /*    96 */  /* [/ActiveEcuC/Com/ComConfig/msg_MyECU_Lamp_Mx_oCAN00_e57ca999_Tx] */
  /*   ... */  /* [/ActiveEcuC/Com/ComConfig/msg_MyECU_Lamp_Mx_oCAN00_e57ca999_Tx] */
  /*    99 */  /* [/ActiveEcuC/Com/ComConfig/msg_MyECU_Lamp_Mx_oCAN00_e57ca999_Tx] */
  /*   100 */  /* [/ActiveEcuC/Com/ComConfig/msg_MyECU_Lamp_Mx_oCAN00_e57ca999_Tx, /ActiveEcuC/Com/ComConfig/MotorFoc_Sequence_Mx_omsg_MyECU_Lamp_oCAN00_339a541d_Tx] */
  /*   101 */  /* [/ActiveEcuC/Com/ComConfig/msg_MyECU_Lamp_Mx_oCAN00_e57ca999_Tx, /ActiveEcuC/Com/ComConfig/MotorFoc_Sequence_Mx_omsg_MyECU_Lamp_oCAN00_339a541d_Tx] */
  /* Index        Referable Keys */
  /*   102 */  /* [/ActiveEcuC/Com/ComConfig/msg_MyECU_Lamp_Mx_oCAN00_e57ca999_Tx] */
  /*   ... */  /* [/ActiveEcuC/Com/ComConfig/msg_MyECU_Lamp_Mx_oCAN00_e57ca999_Tx] */
  /*   127 */  /* [/ActiveEcuC/Com/ComConfig/msg_MyECU_Lamp_Mx_oCAN00_e57ca999_Tx] */
  /*   128 */  /* [/ActiveEcuC/Com/ComConfig/msg_Transmit_oCAN00_0723e95e_Tx, /ActiveEcuC/Com/ComConfig/sig_RearInteriorLight_omsg_Transmit_oCAN00_49a633c1_Tx] */

#define COM_STOP_SEC_VAR_NO_INIT_8
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Com_TxIPduGroupISRLockCounter
**********************************************************************************************************************/
#define COM_START_SEC_VAR_NO_INIT_16
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(Com_TxIPduGroupISRLockCounterUType, COM_VAR_NO_INIT) Com_TxIPduGroupISRLockCounter;  /* PRQA S 0759, 1514, 1533 */  /* MD_CSL_Union, MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys */
  /*     0 */  /* [noPartition] */

#define COM_STOP_SEC_VAR_NO_INIT_16
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Com_TxPduGrpActive
**********************************************************************************************************************/
/** 
  \var    Com_TxPduGrpActive
  \brief  Tx I-PDU based state (started/stopped) of the corresponding I-PDU-Group.
*/ 
#define COM_START_SEC_VAR_NO_INIT_8
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(Com_TxPduGrpActiveType, COM_VAR_NO_INIT) Com_TxPduGrpActive[5];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys */
  /*     0 */  /* [/ActiveEcuC/Com/ComConfig/msg_MyECU_Lamp_MxA0_oCAN00_b76f77a4_Tx, /ActiveEcuC/Com/ComConfig/MyECU_oCAN00_Tx_1ae5d671, ComMainFunctionTx] */
  /*     1 */  /* [/ActiveEcuC/Com/ComConfig/msg_MyECU_Lamp_MxA1_oCAN00_7bc5773a_Tx, /ActiveEcuC/Com/ComConfig/MyECU_oCAN00_Tx_1ae5d671, ComMainFunctionTx] */
  /*     2 */  /* [/ActiveEcuC/Com/ComConfig/msg_MyECU_Lamp_MxA2_oCAN00_f54a70d9_Tx, /ActiveEcuC/Com/ComConfig/MyECU_oCAN00_Tx_1ae5d671, ComMainFunctionTx] */
  /*     3 */  /* [/ActiveEcuC/Com/ComConfig/msg_MyECU_Lamp_Mx_oCAN00_e57ca999_Tx, /ActiveEcuC/Com/ComConfig/MyECU_oCAN00_Tx_1ae5d671, ComMainFunctionTx] */
  /*     4 */  /* [/ActiveEcuC/Com/ComConfig/msg_Transmit_oCAN00_0723e95e_Tx, /ActiveEcuC/Com/ComConfig/MyECU_oCAN00_Tx_1ae5d671, ComMainFunctionTx] */

#define COM_STOP_SEC_VAR_NO_INIT_8
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Com_TxProcessingISRLockCounter
**********************************************************************************************************************/
#define COM_START_SEC_VAR_NO_INIT_16
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(Com_TxProcessingISRLockCounterUType, COM_VAR_NO_INIT) Com_TxProcessingISRLockCounter;  /* PRQA S 0759, 1514, 1533 */  /* MD_CSL_Union, MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys */
  /*     0 */  /* [ComMainFunctionTx] */

#define COM_STOP_SEC_VAR_NO_INIT_16
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Com_TxSduLength
**********************************************************************************************************************/
/** 
  \var    Com_TxSduLength
  \brief  This var Array contains the Com Ipdu Length.
*/ 
#define COM_START_SEC_VAR_NO_INIT_8
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(Com_TxSduLengthType, COM_VAR_NO_INIT) Com_TxSduLength[5];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys */
  /*     0 */  /* [/ActiveEcuC/Com/ComConfig/msg_MyECU_Lamp_MxA0_oCAN00_b76f77a4_Tx, /ActiveEcuC/Com/ComConfig/MyECU_oCAN00_Tx_1ae5d671, ComMainFunctionTx] */
  /*     1 */  /* [/ActiveEcuC/Com/ComConfig/msg_MyECU_Lamp_MxA1_oCAN00_7bc5773a_Tx, /ActiveEcuC/Com/ComConfig/MyECU_oCAN00_Tx_1ae5d671, ComMainFunctionTx] */
  /*     2 */  /* [/ActiveEcuC/Com/ComConfig/msg_MyECU_Lamp_MxA2_oCAN00_f54a70d9_Tx, /ActiveEcuC/Com/ComConfig/MyECU_oCAN00_Tx_1ae5d671, ComMainFunctionTx] */
  /*     3 */  /* [/ActiveEcuC/Com/ComConfig/msg_MyECU_Lamp_Mx_oCAN00_e57ca999_Tx, /ActiveEcuC/Com/ComConfig/MyECU_oCAN00_Tx_1ae5d671, ComMainFunctionTx] */
  /*     4 */  /* [/ActiveEcuC/Com/ComConfig/msg_Transmit_oCAN00_0723e95e_Tx, /ActiveEcuC/Com/ComConfig/MyECU_oCAN00_Tx_1ae5d671, ComMainFunctionTx] */

#define COM_STOP_SEC_VAR_NO_INIT_8
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */


/**********************************************************************************************************************
  CONFIGURATION CLASS: LINK
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
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL FUNCTIONS
**********************************************************************************************************************/

/**********************************************************************************************************************
  CONFIGURATION CLASS: LINK
  SECTION: GLOBAL FUNCTIONS
**********************************************************************************************************************/



#define COM_START_SEC_CODE
#include "MemMap.h"    /* PRQA S 5087 */        /* MD_MSR_MemMap */


/**********************************************************************************************************************
 * Com_MainFunctionRx_ComMainFunctionRx
 *********************************************************************************************************************/
 /*!
 * \internal
 * - call Com_MainFunctionRx with the id referencing this main function.
 * \endinternal
 *********************************************************************************************************************/
FUNC(void, COM_CODE) Com_MainFunctionRx_ComMainFunctionRx(void)
{
#if ((COM_EXISTS_DEFERRED_SIGNALPROCESSINGOFRXPDUINFO == STD_ON)||(COM_RXTOUTINFO == STD_ON))
  Com_MainFunctionRxStructIterType id = 0;
  Com_MainFunctionRxInternal(id);
#endif
}

/**********************************************************************************************************************
 * Com_MainFunctionTx_ComMainFunctionTx
 *********************************************************************************************************************/
 /*!
 * \internal
 * - call Com_MainFunctionTx with the id referencing this main function.
 * \endinternal
 *********************************************************************************************************************/
FUNC(void, COM_CODE) Com_MainFunctionTx_ComMainFunctionTx(void)
{
#if (COM_TXMODEINFO == STD_ON)
  Com_MainFunctionTxStructIterType id = 0;
  Com_MainFunctionTxInternal(id);
#endif
}

#define COM_STOP_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */   /* MD_MSR_MemMap */

/**********************************************************************************************************************
  END OF FILE: Com_Lcfg.c
**********************************************************************************************************************/

