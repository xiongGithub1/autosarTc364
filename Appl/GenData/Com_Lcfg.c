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
 *   Generation Time: 2024-08-11 18:29:24
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
  { /*     1 */                                      1u,                    0u,                    0u, COM_NO_RXPDUINFOINDENDIDXOFIPDUGROUPINFO, COM_NO_RXPDUINFOINDSTARTIDXOFIPDUGROUPINFO,                                       2u,                                         0u }   /* [/ActiveEcuC/Com/ComConfig/MyECU_oCAN00_Tx_1ae5d671, /ActiveEcuC/Com/ComConfig/msg_MotorStatus_oCAN00_71118836_Tx, /ActiveEcuC/Com/ComConfig/msg_Transmit_oCAN00_0723e95e_Tx] */
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
CONST(Com_IPduGroupInfoOfTxPduInfoIndType, COM_CONST) Com_IPduGroupInfoOfTxPduInfoInd[2] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index     IPduGroupInfoOfTxPduInfoInd      Referable Keys */
  /*     0 */                           1u,  /* [/ActiveEcuC/Com/ComConfig/msg_MotorStatus_oCAN00_71118836_Tx] */
  /*     1 */                           1u   /* [/ActiveEcuC/Com/ComConfig/msg_Transmit_oCAN00_0723e95e_Tx] */
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
CONST(Com_TxAccessInfoType, COM_CONST) Com_TxAccessInfo[13] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    TxSigInfoIdx        Referable Keys */
  { /*     0 */           0u },  /* [/ActiveEcuC/Com/ComConfig/ElectricAngle_omsg_MotorStatus_oCAN00_59d7c624_Tx] */
  { /*     1 */           1u },  /* [/ActiveEcuC/Com/ComConfig/Id_Ref_omsg_MotorStatus_oCAN00_d6855f80_Tx] */
  { /*     2 */           2u },  /* [/ActiveEcuC/Com/ComConfig/Iq_Ref_omsg_MotorStatus_oCAN00_64246970_Tx] */
  { /*     3 */           3u },  /* [/ActiveEcuC/Com/ComConfig/MotorMode_omsg_MotorStatus_oCAN00_b2c82a54_Tx] */
  { /*     4 */           4u },  /* [/ActiveEcuC/Com/ComConfig/Vbus_omsg_MotorStatus_oCAN00_85810386_Tx] */
  { /*     5 */           5u },  /* [/ActiveEcuC/Com/ComConfig/sig_NM_MyECU_UserData_0_omsg_nm_MyECU_oCAN00_acc1931e_Tx] */
  { /*     6 */           6u },  /* [/ActiveEcuC/Com/ComConfig/sig_NM_MyECU_UserData_1_omsg_nm_MyECU_oCAN00_bbe9f7de_Tx] */
  { /*     7 */           7u },  /* [/ActiveEcuC/Com/ComConfig/sig_NM_MyECU_UserData_2_omsg_nm_MyECU_oCAN00_82915a9e_Tx] */
  { /*     8 */           8u },  /* [/ActiveEcuC/Com/ComConfig/sig_NM_MyECU_UserData_3_omsg_nm_MyECU_oCAN00_95b93e5e_Tx] */
  { /*     9 */           9u },  /* [/ActiveEcuC/Com/ComConfig/sig_NM_MyECU_UserData_4_omsg_nm_MyECU_oCAN00_f060001e_Tx] */
  { /*    10 */          10u },  /* [/ActiveEcuC/Com/ComConfig/sig_NM_MyECU_UserData_5_omsg_nm_MyECU_oCAN00_e74864de_Tx] */
  { /*    11 */          11u },  /* [/ActiveEcuC/Com/ComConfig/sig_RearInteriorLight_omsg_Transmit_oCAN00_49a633c1_Tx] */
  { /*    12 */          12u }   /* [/ActiveEcuC/Com/ComConfig/tle9180_Ov_Fault_omsg_MotorStatus_oCAN00_fd6f0927_Tx] */
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
CONST(Com_TxModeFalseType, COM_CONST) Com_TxModeFalse[3] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    TimePeriod        Referable Keys */
  { /*     0 */         1u },  /* [/ActiveEcuC/Com/ComConfig/msg_MotorStatus_oCAN00_71118836_Tx] */
  { /*     1 */        20u },  /* [/ActiveEcuC/Com/ComConfig/msg_Transmit_oCAN00_0723e95e_Tx] */
  { /*     2 */         0u }   /* [/ActiveEcuC/Com/ComConfig/msg_nm_MyECU_oCAN00_92bb24c1_Tx] */
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
  Element     Description
  InitMode    Initial transmission mode selector of the Tx I-PDU.
*/ 
#define COM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Com_TxModeInfoType, COM_CONST) Com_TxModeInfo[3] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    InitMode        Referable Keys */
  { /*     0 */     TRUE },  /* [/ActiveEcuC/Com/ComConfig/msg_MotorStatus_oCAN00_71118836_Tx] */
  { /*     1 */     TRUE },  /* [/ActiveEcuC/Com/ComConfig/msg_Transmit_oCAN00_0723e95e_Tx] */
  { /*     2 */     TRUE }   /* [/ActiveEcuC/Com/ComConfig/msg_nm_MyECU_oCAN00_92bb24c1_Tx] */
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
  TimePeriod    Cycle time factor.
*/ 
#define COM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Com_TxModeTrueType, COM_CONST) Com_TxModeTrue[3] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    TimePeriod        Referable Keys */
  { /*     0 */         1u },  /* [/ActiveEcuC/Com/ComConfig/msg_MotorStatus_oCAN00_71118836_Tx] */
  { /*     1 */        20u },  /* [/ActiveEcuC/Com/ComConfig/msg_Transmit_oCAN00_0723e95e_Tx] */
  { /*     2 */         0u }   /* [/ActiveEcuC/Com/ComConfig/msg_nm_MyECU_oCAN00_92bb24c1_Tx] */
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
  IPduGroupInfoOfTxPduInfoIndEndIdx      the end index of the 0:n relation pointing to Com_IPduGroupInfoOfTxPduInfoInd
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
CONST(Com_TxPduInfoType, COM_CONST) Com_TxPduInfo[3] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    ExternalId                               IPduGroupInfoOfTxPduInfoIndEndIdx                    IPduGroupInfoOfTxPduInfoIndStartIdx                    PartitionsTxStructIdx  TxBufferLength  TxPduInitValueEndIdx  TxPduInitValueStartIdx        Referable Keys */
  { /*     0 */ PduRConf_PduRSrcPdu_PduRSrcPdu_96a7407f,                                                  1u,                                                    0u,                    0u,            12u,                  12u,                     0u },  /* [/ActiveEcuC/Com/ComConfig/msg_MotorStatus_oCAN00_71118836_Tx, /ActiveEcuC/Com/ComConfig/MyECU_oCAN00_Tx_1ae5d671, ComMainFunctionTx] */
  { /*     1 */ PduRConf_PduRSrcPdu_PduRSrcPdu_087fd70d,                                                  2u,                                                    1u,                    0u,             1u,                  13u,                    12u },  /* [/ActiveEcuC/Com/ComConfig/msg_Transmit_oCAN00_0723e95e_Tx, /ActiveEcuC/Com/ComConfig/MyECU_oCAN00_Tx_1ae5d671, ComMainFunctionTx] */
  { /*     2 */ PduRConf_PduRSrcPdu_PduRSrcPdu_f11d45ed, COM_NO_IPDUGROUPINFOOFTXPDUINFOINDENDIDXOFTXPDUINFO, COM_NO_IPDUGROUPINFOOFTXPDUINFOINDSTARTIDXOFTXPDUINFO,                    0u,             7u,                  20u,                    13u }   /* [/ActiveEcuC/Com/ComConfig/msg_nm_MyECU_oCAN00_92bb24c1_Tx, ComMainFunctionTx] */
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
CONST(Com_TxPduInitValueType, COM_CONST) Com_TxPduInitValue[20] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index     TxPduInitValue      Referable Keys */
  /*     0 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/msg_MotorStatus_oCAN00_71118836_Tx] */
  /*     1 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/msg_MotorStatus_oCAN00_71118836_Tx] */
  /*     2 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/msg_MotorStatus_oCAN00_71118836_Tx] */
  /*     3 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/msg_MotorStatus_oCAN00_71118836_Tx] */
  /*     4 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/msg_MotorStatus_oCAN00_71118836_Tx] */
  /*     5 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/msg_MotorStatus_oCAN00_71118836_Tx] */
  /*     6 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/msg_MotorStatus_oCAN00_71118836_Tx] */
  /*     7 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/msg_MotorStatus_oCAN00_71118836_Tx] */
  /*     8 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/msg_MotorStatus_oCAN00_71118836_Tx] */
  /*     9 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/msg_MotorStatus_oCAN00_71118836_Tx] */
  /*    10 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/msg_MotorStatus_oCAN00_71118836_Tx] */
  /*    11 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/msg_MotorStatus_oCAN00_71118836_Tx] */
  /*    12 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/msg_Transmit_oCAN00_0723e95e_Tx] */
  /*    13 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/msg_nm_MyECU_oCAN00_92bb24c1_Tx] */
  /*    14 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/msg_nm_MyECU_oCAN00_92bb24c1_Tx] */
  /*    15 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/msg_nm_MyECU_oCAN00_92bb24c1_Tx] */
  /*    16 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/msg_nm_MyECU_oCAN00_92bb24c1_Tx] */
  /*    17 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/msg_nm_MyECU_oCAN00_92bb24c1_Tx] */
  /*    18 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/msg_nm_MyECU_oCAN00_92bb24c1_Tx] */
  /*    19 */           0x00u   /* [/ActiveEcuC/Com/ComConfig/msg_nm_MyECU_oCAN00_92bb24c1_Tx] */
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
CONST(Com_TxSigInfoType, COM_CONST) Com_TxSigInfo[13] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    DynSignal  ApplType                        BitLength  BitPosition  ByteLength  StartByteInPduPosition  TxBufferEndIdx  TxBufferStartIdx  TxPduInfoIdx        Referable Keys */
  { /*     0 */     FALSE, COM_SINT16_APPLTYPEOFTXSIGINFO,       16u,         64u,         2u,                     8u,            10u,               8u,           0u },  /* [/ActiveEcuC/Com/ComConfig/ElectricAngle_omsg_MotorStatus_oCAN00_59d7c624_Tx] */
  { /*     1 */     FALSE, COM_SINT16_APPLTYPEOFTXSIGINFO,       16u,         16u,         2u,                     2u,             4u,               2u,           0u },  /* [/ActiveEcuC/Com/ComConfig/Id_Ref_omsg_MotorStatus_oCAN00_d6855f80_Tx] */
  { /*     2 */     FALSE, COM_SINT16_APPLTYPEOFTXSIGINFO,       16u,         32u,         2u,                     4u,             6u,               4u,           0u },  /* [/ActiveEcuC/Com/ComConfig/Iq_Ref_omsg_MotorStatus_oCAN00_64246970_Tx] */
  { /*     3 */     FALSE,  COM_UINT8_APPLTYPEOFTXSIGINFO,        8u,          0u,         1u,                     0u,             1u,               0u,           0u },  /* [/ActiveEcuC/Com/ComConfig/MotorMode_omsg_MotorStatus_oCAN00_b2c82a54_Tx] */
  { /*     4 */     FALSE, COM_SINT16_APPLTYPEOFTXSIGINFO,       16u,         48u,         2u,                     6u,             8u,               6u,           0u },  /* [/ActiveEcuC/Com/ComConfig/Vbus_omsg_MotorStatus_oCAN00_85810386_Tx] */
  { /*     5 */     FALSE,  COM_UINT8_APPLTYPEOFTXSIGINFO,        8u,          8u,         1u,                     1u,            15u,              14u,           2u },  /* [/ActiveEcuC/Com/ComConfig/sig_NM_MyECU_UserData_0_omsg_nm_MyECU_oCAN00_acc1931e_Tx] */
  { /*     6 */     FALSE,  COM_UINT8_APPLTYPEOFTXSIGINFO,        8u,         16u,         1u,                     2u,            16u,              15u,           2u },  /* [/ActiveEcuC/Com/ComConfig/sig_NM_MyECU_UserData_1_omsg_nm_MyECU_oCAN00_bbe9f7de_Tx] */
  { /*     7 */     FALSE,  COM_UINT8_APPLTYPEOFTXSIGINFO,        8u,         24u,         1u,                     3u,            17u,              16u,           2u },  /* [/ActiveEcuC/Com/ComConfig/sig_NM_MyECU_UserData_2_omsg_nm_MyECU_oCAN00_82915a9e_Tx] */
  { /*     8 */     FALSE,  COM_UINT8_APPLTYPEOFTXSIGINFO,        8u,         32u,         1u,                     4u,            18u,              17u,           2u },  /* [/ActiveEcuC/Com/ComConfig/sig_NM_MyECU_UserData_3_omsg_nm_MyECU_oCAN00_95b93e5e_Tx] */
  { /*     9 */     FALSE,  COM_UINT8_APPLTYPEOFTXSIGINFO,        8u,         40u,         1u,                     5u,            19u,              18u,           2u },  /* [/ActiveEcuC/Com/ComConfig/sig_NM_MyECU_UserData_4_omsg_nm_MyECU_oCAN00_f060001e_Tx] */
  { /*    10 */     FALSE,  COM_UINT8_APPLTYPEOFTXSIGINFO,        8u,         48u,         1u,                     6u,            20u,              19u,           2u },  /* [/ActiveEcuC/Com/ComConfig/sig_NM_MyECU_UserData_5_omsg_nm_MyECU_oCAN00_e74864de_Tx] */
  { /*    11 */     FALSE,  COM_UINT8_APPLTYPEOFTXSIGINFO,        1u,          0u,         0u,                     0u,            13u,              12u,           1u },  /* [/ActiveEcuC/Com/ComConfig/sig_RearInteriorLight_omsg_Transmit_oCAN00_49a633c1_Tx] */
  { /*    12 */     FALSE,  COM_UINT8_APPLTYPEOFTXSIGINFO,        1u,          8u,         0u,                     1u,             2u,               1u,           0u }   /* [/ActiveEcuC/Com/ComConfig/tle9180_Ov_Fault_omsg_MotorStatus_oCAN00_fd6f0927_Tx] */
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
  /*     0 */  /* [/ActiveEcuC/Com/ComConfig/msg_MotorStatus_oCAN00_71118836_Tx] */
  /*     1 */  /* [/ActiveEcuC/Com/ComConfig/msg_Transmit_oCAN00_0723e95e_Tx] */
  /*     2 */  /* [/ActiveEcuC/Com/ComConfig/msg_nm_MyECU_oCAN00_92bb24c1_Tx] */

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
  /*     0 */  /* [/ActiveEcuC/Com/ComConfig/msg_MotorStatus_oCAN00_71118836_Tx] */
  /*     1 */  /* [/ActiveEcuC/Com/ComConfig/msg_Transmit_oCAN00_0723e95e_Tx] */
  /*     2 */  /* [/ActiveEcuC/Com/ComConfig/msg_nm_MyECU_oCAN00_92bb24c1_Tx] */

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
  /*     0 */  /* [/ActiveEcuC/Com/ComConfig/msg_MotorStatus_oCAN00_71118836_Tx] */
  /*     1 */  /* [/ActiveEcuC/Com/ComConfig/msg_Transmit_oCAN00_0723e95e_Tx] */
  /*     2 */  /* [/ActiveEcuC/Com/ComConfig/msg_nm_MyECU_oCAN00_92bb24c1_Tx] */

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
#define COM_START_SEC_VAR_NO_INIT_16
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(Com_HandleRxPduDeferredUType, COM_VAR_NO_INIT) Com_HandleRxPduDeferred;  /* PRQA S 0759, 1514, 1533 */  /* MD_CSL_Union, MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys */
  /*     0 */  /* [/ActiveEcuC/Com/ComConfig/msg_Receive_oCAN00_2b456e3f_Rx] */

#define COM_STOP_SEC_VAR_NO_INIT_16
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
  /*     1 */  /* [/ActiveEcuC/Com/ComConfig/MyECU_oCAN00_Tx_1ae5d671, /ActiveEcuC/Com/ComConfig/msg_MotorStatus_oCAN00_71118836_Tx, /ActiveEcuC/Com/ComConfig/msg_Transmit_oCAN00_0723e95e_Tx] */

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
  /*     0 */  /* [/ActiveEcuC/Com/ComConfig/msg_MotorStatus_oCAN00_71118836_Tx] */
  /*     1 */  /* [/ActiveEcuC/Com/ComConfig/msg_Transmit_oCAN00_0723e95e_Tx] */
  /*     2 */  /* [/ActiveEcuC/Com/ComConfig/msg_nm_MyECU_oCAN00_92bb24c1_Tx] */

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
VAR(Com_TxBufferType, COM_VAR_NO_INIT) Com_TxBuffer[20];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys */
  /*     0 */  /* [/ActiveEcuC/Com/ComConfig/msg_MotorStatus_oCAN00_71118836_Tx, /ActiveEcuC/Com/ComConfig/MotorMode_omsg_MotorStatus_oCAN00_b2c82a54_Tx] */
  /*     1 */  /* [/ActiveEcuC/Com/ComConfig/msg_MotorStatus_oCAN00_71118836_Tx, /ActiveEcuC/Com/ComConfig/tle9180_Ov_Fault_omsg_MotorStatus_oCAN00_fd6f0927_Tx] */
  /*     2 */  /* [/ActiveEcuC/Com/ComConfig/msg_MotorStatus_oCAN00_71118836_Tx, /ActiveEcuC/Com/ComConfig/Id_Ref_omsg_MotorStatus_oCAN00_d6855f80_Tx] */
  /*     3 */  /* [/ActiveEcuC/Com/ComConfig/msg_MotorStatus_oCAN00_71118836_Tx, /ActiveEcuC/Com/ComConfig/Id_Ref_omsg_MotorStatus_oCAN00_d6855f80_Tx] */
  /*     4 */  /* [/ActiveEcuC/Com/ComConfig/msg_MotorStatus_oCAN00_71118836_Tx, /ActiveEcuC/Com/ComConfig/Iq_Ref_omsg_MotorStatus_oCAN00_64246970_Tx] */
  /*     5 */  /* [/ActiveEcuC/Com/ComConfig/msg_MotorStatus_oCAN00_71118836_Tx, /ActiveEcuC/Com/ComConfig/Iq_Ref_omsg_MotorStatus_oCAN00_64246970_Tx] */
  /*     6 */  /* [/ActiveEcuC/Com/ComConfig/msg_MotorStatus_oCAN00_71118836_Tx, /ActiveEcuC/Com/ComConfig/Vbus_omsg_MotorStatus_oCAN00_85810386_Tx] */
  /*     7 */  /* [/ActiveEcuC/Com/ComConfig/msg_MotorStatus_oCAN00_71118836_Tx, /ActiveEcuC/Com/ComConfig/Vbus_omsg_MotorStatus_oCAN00_85810386_Tx] */
  /*     8 */  /* [/ActiveEcuC/Com/ComConfig/msg_MotorStatus_oCAN00_71118836_Tx, /ActiveEcuC/Com/ComConfig/ElectricAngle_omsg_MotorStatus_oCAN00_59d7c624_Tx] */
  /*     9 */  /* [/ActiveEcuC/Com/ComConfig/msg_MotorStatus_oCAN00_71118836_Tx, /ActiveEcuC/Com/ComConfig/ElectricAngle_omsg_MotorStatus_oCAN00_59d7c624_Tx] */
  /*    10 */  /* [/ActiveEcuC/Com/ComConfig/msg_MotorStatus_oCAN00_71118836_Tx] */
  /*    11 */  /* [/ActiveEcuC/Com/ComConfig/msg_MotorStatus_oCAN00_71118836_Tx] */
  /*    12 */  /* [/ActiveEcuC/Com/ComConfig/msg_Transmit_oCAN00_0723e95e_Tx, /ActiveEcuC/Com/ComConfig/sig_RearInteriorLight_omsg_Transmit_oCAN00_49a633c1_Tx] */
  /*    13 */  /* [/ActiveEcuC/Com/ComConfig/msg_nm_MyECU_oCAN00_92bb24c1_Tx] */
  /*    14 */  /* [/ActiveEcuC/Com/ComConfig/msg_nm_MyECU_oCAN00_92bb24c1_Tx, /ActiveEcuC/Com/ComConfig/sig_NM_MyECU_UserData_0_omsg_nm_MyECU_oCAN00_acc1931e_Tx] */
  /*    15 */  /* [/ActiveEcuC/Com/ComConfig/msg_nm_MyECU_oCAN00_92bb24c1_Tx, /ActiveEcuC/Com/ComConfig/sig_NM_MyECU_UserData_1_omsg_nm_MyECU_oCAN00_bbe9f7de_Tx] */
  /*    16 */  /* [/ActiveEcuC/Com/ComConfig/msg_nm_MyECU_oCAN00_92bb24c1_Tx, /ActiveEcuC/Com/ComConfig/sig_NM_MyECU_UserData_2_omsg_nm_MyECU_oCAN00_82915a9e_Tx] */
  /*    17 */  /* [/ActiveEcuC/Com/ComConfig/msg_nm_MyECU_oCAN00_92bb24c1_Tx, /ActiveEcuC/Com/ComConfig/sig_NM_MyECU_UserData_3_omsg_nm_MyECU_oCAN00_95b93e5e_Tx] */
  /*    18 */  /* [/ActiveEcuC/Com/ComConfig/msg_nm_MyECU_oCAN00_92bb24c1_Tx, /ActiveEcuC/Com/ComConfig/sig_NM_MyECU_UserData_4_omsg_nm_MyECU_oCAN00_f060001e_Tx] */
  /*    19 */  /* [/ActiveEcuC/Com/ComConfig/msg_nm_MyECU_oCAN00_92bb24c1_Tx, /ActiveEcuC/Com/ComConfig/sig_NM_MyECU_UserData_5_omsg_nm_MyECU_oCAN00_e74864de_Tx] */

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
VAR(Com_TxPduGrpActiveType, COM_VAR_NO_INIT) Com_TxPduGrpActive[3];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys */
  /*     0 */  /* [/ActiveEcuC/Com/ComConfig/msg_MotorStatus_oCAN00_71118836_Tx, /ActiveEcuC/Com/ComConfig/MyECU_oCAN00_Tx_1ae5d671, ComMainFunctionTx] */
  /*     1 */  /* [/ActiveEcuC/Com/ComConfig/msg_Transmit_oCAN00_0723e95e_Tx, /ActiveEcuC/Com/ComConfig/MyECU_oCAN00_Tx_1ae5d671, ComMainFunctionTx] */
  /*     2 */  /* [/ActiveEcuC/Com/ComConfig/msg_nm_MyECU_oCAN00_92bb24c1_Tx, ComMainFunctionTx] */

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
#define COM_START_SEC_VAR_NO_INIT_16
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(Com_TxSduLengthType, COM_VAR_NO_INIT) Com_TxSduLength[3];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys */
  /*     0 */  /* [/ActiveEcuC/Com/ComConfig/msg_MotorStatus_oCAN00_71118836_Tx, /ActiveEcuC/Com/ComConfig/MyECU_oCAN00_Tx_1ae5d671, ComMainFunctionTx] */
  /*     1 */  /* [/ActiveEcuC/Com/ComConfig/msg_Transmit_oCAN00_0723e95e_Tx, /ActiveEcuC/Com/ComConfig/MyECU_oCAN00_Tx_1ae5d671, ComMainFunctionTx] */
  /*     2 */  /* [/ActiveEcuC/Com/ComConfig/msg_nm_MyECU_oCAN00_92bb24c1_Tx, ComMainFunctionTx] */

#define COM_STOP_SEC_VAR_NO_INIT_16
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

