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
 *              File: IpduM_Lcfg.c
 *   Generation Time: 2026-07-29 10:31:08
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


#define IPDUM_LCFG_SOURCE
/**********************************************************************************************************************
 * MISRA JUSTIFICATION
 *********************************************************************************************************************/
/* PRQA S 0785, 0786 EOF */ /* MD_CSL_DistinctIdentifiers */

/**********************************************************************************************************************
  INCLUDES
**********************************************************************************************************************/
#include "IpduM.h"
#include "SchM_IpduM.h"
#include "IpduM_Cfg.h"
#include "IpduM_Lcfg.h"
#include "IpduM_PBcfg.h"

/* include headers with symbolic name values */
# include "PduR_Cfg.h"

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
  LOCAL DATA
**********************************************************************************************************************/

/**********************************************************************************************************************
  GLOBAL DATA
**********************************************************************************************************************/
/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL DATA
**********************************************************************************************************************/
/**********************************************************************************************************************
  IpduM_CTxLoInfo
**********************************************************************************************************************/
/** 
  \var    IpduM_CTxLoInfo
  \brief  all DefinitionRef: /MICROSAR/IpduM/IpduMConfig/IpduMTxPathway/IpduMTxRequest and DefinitionRef: /MICROSAR/IpduM/IpduMConfig/IpduMContainerTxPdu with DefinitionRef: /MICROSAR/IpduM/IpduMConfig/IpduMTxPathway/IpduMTxRequest/IpduMTxConfirmationPduId
  \details
  Element         Description
  TxPathwayIdx    the index of the 0:1 relation pointing to IpduM_CTxPathway
*/ 
#define IPDUM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "IpduM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(IpduM_CTxLoInfoType, IPDUM_CONST) IpduM_CTxLoInfo[1] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    TxPathwayIdx        Referable Keys */
  { /*     0 */           0u }   /* [validElement0, /ActiveEcuC/IpduM/IpduMConfig/msg_MyECU_Lamp_oCAN00_818e1651_Tx/IpduMTxRequest_30b6d8a0, DummyPartition] */
};
#define IPDUM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "IpduM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  IpduM_CTxPathway
**********************************************************************************************************************/
/** 
  \var    IpduM_CTxPathway
  \brief  All DefinitionRef: /MICROSAR/IpduM/IpduMConfig/IpduMTxPathway
  \details
  Element                Description
  TxStaticPduRefUsed     TRUE, if the index value in TxStaticPduRef is valid.
  TxLoInfoIdx            the index of the 0:1 relation pointing to IpduM_TxLoInfoWithInvalidIndexes
  TxPartStaticPartIdx    the index of the 0:1 relation pointing to IpduM_TxPart
*/ 
#define IPDUM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "IpduM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(IpduM_CTxPathwayType, IPDUM_CONST) IpduM_CTxPathway[1] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    TxStaticPduRefUsed  TxLoInfoIdx  TxPartStaticPartIdx        Referable Keys */
  { /*     0 */               TRUE,          0u,                  0u }   /* [/ActiveEcuC/IpduM/IpduMConfig/msg_MyECU_Lamp_oCAN00_818e1651_Tx/IpduMTxRequest_30b6d8a0] */
};
#define IPDUM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "IpduM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  IpduM_MainFunctionTxIndirection
**********************************************************************************************************************/
/** 
  \var    IpduM_MainFunctionTxIndirection
  \brief  Structure which refers the elements which have to be processed in the MainFunction context.
  \details
  Element                Description
  TxLoInfoIndStartIdx    the start index of the 0:n relation pointing to IpduM_TxLoInfoInd
*/ 
#define IPDUM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "IpduM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(IpduM_MainFunctionTxIndirectionType, IPDUM_CONST) IpduM_MainFunctionTxIndirection[1] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    TxLoInfoIndStartIdx        Referable Keys */
  { /*     0 */                  0u }   /* [DummyPartition] */
};
#define IPDUM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "IpduM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  IpduM_Segment
**********************************************************************************************************************/
/** 
  \var    IpduM_Segment
  \brief  all IpduMSegments
  \details
  Element               Description
  FullBytesPresent      True if full bytes exist in this segment.
  EndByteMaskClear      Mask for the partial end byte: clearing.
  FirstFullBytePos      Byte position of the first full byte.
  LastFullBytePos       Byte position of the last full byte.
  Length                the DefinitionRef: /MICROSAR/IpduM/IpduMConfig/IpduMRxPathway/IpduMRxIndication/IpduMRxDynamicPart/IpduMSegment/IpduMSegmentLength.
  StartByteMaskWrite    Mask for the partial start byte: writing.
*/ 
#define IPDUM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "IpduM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(IpduM_SegmentType, IPDUM_CONST) IpduM_Segment[3] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    FullBytesPresent  EndByteMaskClear  FirstFullBytePos  LastFullBytePos  Length  StartByteMaskWrite        Referable Keys */
  { /*     0 */             TRUE,            0x00u,               4u,              5u,    16u,              0xFFu },  /* [/ActiveEcuC/IpduM/IpduMConfig/msg_MyECU_Lamp_oCAN00_818e1651_Tx/IpduMTxRequest_30b6d8a0/msg_MyECU_Lamp_oCAN00_6ae678ab] */
  { /*     1 */             TRUE,            0x00u,               6u,             31u,   208u,              0xFFu },  /* [/ActiveEcuC/IpduM/IpduMConfig/msg_MyECU_Lamp_oCAN00_818e1651_Tx/IpduMTxRequest_30b6d8a0/msg_MyECU_Lamp_oCAN00_67614e93, /ActiveEcuC/IpduM/IpduMConfig/msg_MyECU_Lamp_oCAN00_818e1651_Tx/IpduMTxRequest_30b6d8a0/msg_MyECU_Lamp_oCAN00_abcb4e0d, /ActiveEcuC/IpduM/IpduMConfig/msg_MyECU_Lamp_oCAN00_818e1651_Tx/IpduMTxRequest_30b6d8a0/msg_MyECU_Lamp_oCAN00_e9ee4970] */
  { /*     2 */             TRUE,            0x00u,               0u,              3u,    32u,              0xFFu }   /* [/ActiveEcuC/IpduM/IpduMConfig/msg_MyECU_Lamp_oCAN00_818e1651_Tx/IpduMTxRequest_30b6d8a0/msg_MyECU_Lamp_oCAN00_67614e93, /ActiveEcuC/IpduM/IpduMConfig/msg_MyECU_Lamp_oCAN00_818e1651_Tx/IpduMTxRequest_30b6d8a0/msg_MyECU_Lamp_oCAN00_abcb4e0d, /ActiveEcuC/IpduM/IpduMConfig/msg_MyECU_Lamp_oCAN00_818e1651_Tx/IpduMTxRequest_30b6d8a0/msg_MyECU_Lamp_oCAN00_e9ee4970] */
};
#define IPDUM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "IpduM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  IpduM_TxInitValues
**********************************************************************************************************************/
/** 
  \var    IpduM_TxInitValues
  \brief  Initial values for tx buffer.
*/ 
#define IPDUM_START_SEC_CONST_8
/*lint -save -esym(961, 19.1) */
#include "IpduM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(IpduM_TxInitValuesType, IPDUM_CONST) IpduM_TxInitValues[32] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index     TxInitValues  */
  /*     0 */         0xA0u,
  /*     1 */         0x00u,
  /*     2 */         0x00u,
  /*     3 */         0x00u,
  /*     4 */         0x00u,
  /*     5 */         0x00u,
  /*     6 */         0x00u,
  /*     7 */         0x00u,
  /*     8 */         0x00u,
  /*     9 */         0x00u,
  /*    10 */         0x00u,
  /*    11 */         0x00u,
  /*    12 */         0x00u,
  /*    13 */         0x00u,
  /*    14 */         0x00u,
  /*    15 */         0x00u,
  /*    16 */         0x00u,
  /*    17 */         0x00u,
  /*    18 */         0x00u,
  /*    19 */         0x00u,
  /*    20 */         0x00u,
  /*    21 */         0x00u,
  /*    22 */         0x00u,
  /*    23 */         0x00u,
  /*    24 */         0x00u,
  /*    25 */         0x00u,
  /*    26 */         0x00u,
  /*    27 */         0x00u,
  /*    28 */         0x00u,
  /*    29 */         0x00u,
  /*    30 */         0x00u,
  /*    31 */         0x00u
};
#define IPDUM_STOP_SEC_CONST_8
/*lint -save -esym(961, 19.1) */
#include "IpduM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  IpduM_TxPart
**********************************************************************************************************************/
/** 
  \var    IpduM_TxPart
  \brief  DefinitionRef: /MICROSAR/IpduM/IpduMConfig/IpduMTxPathway/IpduMTxRequest/IpduMTxStaticPart and DefinitionRef: /MICROSAR/IpduM/IpduMConfig/IpduMTxPathway/IpduMTxRequest/IpduMTxDynamicPart
  \details
  Element            Description
  SegmentEndIdx      the end index of the 1:n relation pointing to IpduM_Segment
  SegmentStartIdx    the start index of the 1:n relation pointing to IpduM_Segment
  TxPathwayIdx       the index of the 1:1 relation pointing to IpduM_CTxPathway
  UlPduRef           the DefinitionRef: /MICROSAR/IpduM/IpduMConfig/IpduMTxPathway/IpduMTxRequest/IpduMTxStaticPart/IpduMTxStaticPduRef or DefinitionRef: /MICROSAR/IpduM/IpduMConfig/IpduMTxPathway/IpduMTxRequest/IpduMTxDynamicPart/IpduMTxDynamicPduRef
*/ 
#define IPDUM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "IpduM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(IpduM_TxPartType, IPDUM_CONST) IpduM_TxPart[4] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    SegmentEndIdx  SegmentStartIdx  TxPathwayIdx  UlPduRef                                                           Referable Keys */
  { /*     0 */            1u,              0u,           0u,   PduRConf_PduRDestPdu_msg_MyECU_Lamp_Mx_oCAN00_e57ca999_Tx },  /* [/ActiveEcuC/IpduM/IpduMConfig/msg_MyECU_Lamp_oCAN00_818e1651_Tx/IpduMTxRequest_30b6d8a0/msg_MyECU_Lamp_oCAN00_6ae678ab] */
  { /*     1 */            3u,              1u,           0u, PduRConf_PduRDestPdu_msg_MyECU_Lamp_MxA1_oCAN00_7bc5773a_Tx },  /* [/ActiveEcuC/IpduM/IpduMConfig/msg_MyECU_Lamp_oCAN00_818e1651_Tx/IpduMTxRequest_30b6d8a0, /ActiveEcuC/IpduM/IpduMConfig/msg_MyECU_Lamp_oCAN00_818e1651_Tx/IpduMTxRequest_30b6d8a0/msg_MyECU_Lamp_oCAN00_67614e93] */
  { /*     2 */            3u,              1u,           0u, PduRConf_PduRDestPdu_msg_MyECU_Lamp_MxA0_oCAN00_b76f77a4_Tx },  /* [/ActiveEcuC/IpduM/IpduMConfig/msg_MyECU_Lamp_oCAN00_818e1651_Tx/IpduMTxRequest_30b6d8a0, /ActiveEcuC/IpduM/IpduMConfig/msg_MyECU_Lamp_oCAN00_818e1651_Tx/IpduMTxRequest_30b6d8a0/msg_MyECU_Lamp_oCAN00_abcb4e0d] */
  { /*     3 */            3u,              1u,           0u, PduRConf_PduRDestPdu_msg_MyECU_Lamp_MxA2_oCAN00_f54a70d9_Tx }   /* [/ActiveEcuC/IpduM/IpduMConfig/msg_MyECU_Lamp_oCAN00_818e1651_Tx/IpduMTxRequest_30b6d8a0, /ActiveEcuC/IpduM/IpduMConfig/msg_MyECU_Lamp_oCAN00_818e1651_Tx/IpduMTxRequest_30b6d8a0/msg_MyECU_Lamp_oCAN00_e9ee4970] */
};
#define IPDUM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "IpduM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  IpduM_TxUpInfo
**********************************************************************************************************************/
/** 
  \var    IpduM_TxUpInfo
  \brief  All DefinitionRef: /MICROSAR/IpduM/IpduMConfig/IpduMTxPathway/IpduMTxRequest/IpduMTxDynamicPart, DefinitionRef: /MICROSAR/IpduM/IpduMConfig/IpduMTxPathway/IpduMTxRequest/IpduMTxStaticPart, DefinitionRef: /MICROSAR/IpduM/IpduMConfig/IpduMContainedTxPdu for transmission.
  \details
  Element    Description
  TxUpInd    the enum value of the according target of the 1:1 relation pointing to one of IpduM_TxPart,IpduM_TxContainedPdu
*/ 
#define IPDUM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "IpduM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(IpduM_TxUpInfoType, IPDUM_CONST) IpduM_TxUpInfo[4] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    TxUpInd                        */
  { /*     0 */ IPDUM_TXPART_TXUPINDOFTXUPINFO },
  { /*     1 */ IPDUM_TXPART_TXUPINDOFTXUPINFO },
  { /*     2 */ IPDUM_TXPART_TXUPINDOFTXUPINFO },
  { /*     3 */ IPDUM_TXPART_TXUPINDOFTXUPINFO }
};
#define IPDUM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "IpduM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  IpduM_Initialized
**********************************************************************************************************************/
/** 
  \var    IpduM_Initialized
  \brief  Initialization state of the IpduM. TRUE, if IpduM_Init() has been called, else FALSE.
*/ 
#define IPDUM_START_SEC_VAR_CLEARED_8
/*lint -save -esym(961, 19.1) */
#include "IpduM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(IpduM_InitializedType, IPDUM_VAR_CLEARED) IpduM_Initialized = FALSE;  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
#define IPDUM_STOP_SEC_VAR_CLEARED_8
/*lint -save -esym(961, 19.1) */
#include "IpduM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  IpduM_JitUpdateBuffer
**********************************************************************************************************************/
/** 
  \var    IpduM_JitUpdateBuffer
  \brief  buffer for updating a PDU by just-in-time update initiated by upper layer transmission.
*/ 
#define IPDUM_START_SEC_VAR_NO_INIT_8
/*lint -save -esym(961, 19.1) */
#include "IpduM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(IpduM_JitUpdateBufferUType, IPDUM_VAR_NO_INIT) IpduM_JitUpdateBuffer;  /* PRQA S 0759, 1514, 1533 */  /* MD_CSL_Union, MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys */
  /*     0 */  /* [/ActiveEcuC/IpduM/IpduMConfig/msg_MyECU_Lamp_oCAN00_818e1651_Tx/IpduMTxRequest_30b6d8a0] */
  /*   ... */  /* [/ActiveEcuC/IpduM/IpduMConfig/msg_MyECU_Lamp_oCAN00_818e1651_Tx/IpduMTxRequest_30b6d8a0] */
  /*    31 */  /* [/ActiveEcuC/IpduM/IpduMConfig/msg_MyECU_Lamp_oCAN00_818e1651_Tx/IpduMTxRequest_30b6d8a0] */

#define IPDUM_STOP_SEC_VAR_NO_INIT_8
/*lint -save -esym(961, 19.1) */
#include "IpduM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  IpduM_TriggerTransmitBuffer
**********************************************************************************************************************/
/** 
  \var    IpduM_TriggerTransmitBuffer
  \brief  buffer for updating a PDU by just-in-time update initiated by lower layer triggered transmission.
*/ 
#define IPDUM_START_SEC_VAR_NO_INIT_8
/*lint -save -esym(961, 19.1) */
#include "IpduM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(IpduM_TriggerTransmitBufferUType, IPDUM_VAR_NO_INIT) IpduM_TriggerTransmitBuffer;  /* PRQA S 0759, 1514, 1533 */  /* MD_CSL_Union, MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys */
  /*     0 */  /* [/ActiveEcuC/IpduM/IpduMConfig/msg_MyECU_Lamp_oCAN00_818e1651_Tx/IpduMTxRequest_30b6d8a0] */
  /*   ... */  /* [/ActiveEcuC/IpduM/IpduMConfig/msg_MyECU_Lamp_oCAN00_818e1651_Tx/IpduMTxRequest_30b6d8a0] */
  /*    31 */  /* [/ActiveEcuC/IpduM/IpduMConfig/msg_MyECU_Lamp_oCAN00_818e1651_Tx/IpduMTxRequest_30b6d8a0] */

#define IPDUM_STOP_SEC_VAR_NO_INIT_8
/*lint -save -esym(961, 19.1) */
#include "IpduM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  IpduM_TxBuffer
**********************************************************************************************************************/
/** 
  \var    IpduM_TxBuffer
  \brief  buffer to multiplex and forward static and dynamic TX parts whose transmission is requested.
*/ 
#define IPDUM_START_SEC_VAR_NO_INIT_8
/*lint -save -esym(961, 19.1) */
#include "IpduM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(IpduM_TxBufferUType, IPDUM_VAR_NO_INIT) IpduM_TxBuffer;  /* PRQA S 0759, 1514, 1533 */  /* MD_CSL_Union, MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys */
  /*     0 */  /* [/ActiveEcuC/IpduM/IpduMConfig/msg_MyECU_Lamp_oCAN00_818e1651_Tx/IpduMTxRequest_30b6d8a0] */
  /*   ... */  /* [/ActiveEcuC/IpduM/IpduMConfig/msg_MyECU_Lamp_oCAN00_818e1651_Tx/IpduMTxRequest_30b6d8a0] */
  /*    31 */  /* [/ActiveEcuC/IpduM/IpduMConfig/msg_MyECU_Lamp_oCAN00_818e1651_Tx/IpduMTxRequest_30b6d8a0] */

#define IPDUM_STOP_SEC_VAR_NO_INIT_8
/*lint -save -esym(961, 19.1) */
#include "IpduM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  IpduM_VTxLoInfo
**********************************************************************************************************************/
/** 
  \var    IpduM_VTxLoInfo
  \brief  all DefinitionRef: /MICROSAR/IpduM/IpduMConfig/IpduMTxPathway/IpduMTxRequest and DefinitionRef: /MICROSAR/IpduM/IpduMConfig/IpduMContainerTxPdu with DefinitionRef: /MICROSAR/IpduM/IpduMConfig/IpduMTxPathway/IpduMTxRequest/IpduMTxConfirmationPduId
  \details
  Element             Description
  TxConfTimeoutCnt    I-PDU based TX confirmation timeout counters.
*/ 
#define IPDUM_START_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "IpduM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(IpduM_VTxLoInfoType, IPDUM_VAR_NO_INIT) IpduM_VTxLoInfo[1];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys */
  /*     0 */  /* [validElement0, /ActiveEcuC/IpduM/IpduMConfig/msg_MyECU_Lamp_oCAN00_818e1651_Tx/IpduMTxRequest_30b6d8a0, DummyPartition] */

#define IPDUM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "IpduM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  IpduM_VTxPathway
**********************************************************************************************************************/
/** 
  \var    IpduM_VTxPathway
  \brief  All DefinitionRef: /MICROSAR/IpduM/IpduMConfig/IpduMTxPathway
  \details
  Element                 Description
  TxPartDynamicPartIdx    the index of the 1:1 relation pointing to IpduM_TxPart
*/ 
#define IPDUM_START_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "IpduM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(IpduM_VTxPathwayUType, IPDUM_VAR_NO_INIT) IpduM_VTxPathway;  /* PRQA S 0759, 1514, 1533 */  /* MD_CSL_Union, MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys */
  /*     0 */  /* [/ActiveEcuC/IpduM/IpduMConfig/msg_MyECU_Lamp_oCAN00_818e1651_Tx/IpduMTxRequest_30b6d8a0] */

#define IPDUM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "IpduM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
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
#define IPDUM_START_SEC_CODE
#include "IpduM_MemMap.h"    /* PRQA S 5087 */        /* MD_MSR_MemMap */


/**********************************************************************************************************************
 * IpduM_MainFunctionRx
 *********************************************************************************************************************/
 /*!
 * \internal
 * - call IpduM_MainFunctionRx with the id which represents the corresponding MainFunction context.
 * \endinternal
 *********************************************************************************************************************/
FUNC(void, IPDUM_CODE) IpduM_MainFunctionRx(void)
{
#if(IPDUM_CCONTAINERRXQUEUEINFO == STD_ON)
  if(IpduM_IsInitialized())
  {
    IpduM_MainFunctionRxIndirectionIterType mainFunctionRxIndirectionIdx = 0;
    IpduM_MainFunctionRxInternal(mainFunctionRxIndirectionIdx);
  }
#endif
}

/**********************************************************************************************************************
 * IpduM_MainFunctionTx
 *********************************************************************************************************************/
 /*!
 * \internal
 * - call IpduM_MainFunctionTx with the id which represents the corresponding MainFunction context.
 * \endinternal
 *********************************************************************************************************************/
FUNC(void, IPDUM_CODE) IpduM_MainFunctionTx(void)
{
#if((IPDUM_TXCONFTIMEOUTCNTOFVTXLOINFO == STD_ON) || (IPDUM_TXCONTAINEDPDU == STD_ON))
  if(IpduM_IsInitialized())
  {
    IpduM_MainFunctionTxIndirectionIterType mainFunctionTxIndirectionIdx = 0;
    IpduM_MainFunctionTxInternal(mainFunctionTxIndirectionIdx);
  }
#endif
}

#define IPDUM_STOP_SEC_CODE
#include "IpduM_MemMap.h" /* PRQA S 5087 */   /* MD_MSR_MemMap */

/**********************************************************************************************************************
  END OF FILE: IpduM_Lcfg.c
**********************************************************************************************************************/

