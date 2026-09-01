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
 *              File: Com_Lcfg.h
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

#if !defined (COM_LCFG_H)
# define COM_LCFG_H

/**********************************************************************************************************************
 * MISRA JUSTIFICATION
 *********************************************************************************************************************/

/**********************************************************************************************************************
  INCLUDES
**********************************************************************************************************************/
# include "Com_Cfg.h"
# include "Com_Cbk.h"
# include "PduR_Cfg.h"
# include "Com_PBcfg.h"


/**********************************************************************************************************************
  GLOBAL CONSTANT MACROS
**********************************************************************************************************************/
/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL CONSTANT MACROS
**********************************************************************************************************************/
/** 
  \defgroup  ComPCDataSwitches  Com Data Switches  (PRE_COMPILE)
  \brief  These defines are used to deactivate data and their processing.
  \{
*/ 
#define COM_ALWAYSACTIVERXCOMIPDUS                                                                  STD_OFF  /**< Deactivateable: 'Com_AlwaysActiveRxComIPdus' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define COM_PARTITIONSALWAYSACTIVERXCOMIPDUSSTRUCTIDXOFALWAYSACTIVERXCOMIPDUS                       STD_OFF  /**< Deactivateable: 'Com_AlwaysActiveRxComIPdus.PartitionsAlwaysActiveRxComIPdusStructIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_RXPDUINFOIDXOFALWAYSACTIVERXCOMIPDUS                                                    STD_OFF  /**< Deactivateable: 'Com_AlwaysActiveRxComIPdus.RxPduInfoIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_ALWAYSACTIVETXCOMIPDUS                                                                  STD_ON
#define COM_PARTITIONSALWAYSACTIVETXCOMIPDUSSTRUCTIDXOFALWAYSACTIVETXCOMIPDUS                       STD_ON
#define COM_TXPDUINFOIDXOFALWAYSACTIVETXCOMIPDUS                                                    STD_ON
#define COM_CCPRQUEUE                                                                               STD_OFF  /**< Deactivateable: 'Com_CCprQueue' Reason: 'No CrossPartitionRoutingQueues configured.' */
#define COM_CPRQUEUEBUFFERENDIDXOFCPRQUEUE                                                          STD_OFF  /**< Deactivateable: 'Com_CCprQueue.CprQueueBufferEndIdx' Reason: 'No CrossPartitionRoutingQueues configured.' */
#define COM_CPRQUEUEBUFFERLENGTHOFCPRQUEUE                                                          STD_OFF  /**< Deactivateable: 'Com_CCprQueue.CprQueueBufferLength' Reason: 'No CrossPartitionRoutingQueues configured.' */
#define COM_CPRQUEUEBUFFERSTARTIDXOFCPRQUEUE                                                        STD_OFF  /**< Deactivateable: 'Com_CCprQueue.CprQueueBufferStartIdx' Reason: 'No CrossPartitionRoutingQueues configured.' */
#define COM_CBKRXTOUTFUNCPTR                                                                        STD_OFF  /**< Deactivateable: 'Com_CbkRxTOutFuncPtr' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_CBKRXTOUTFUNCPTRIND                                                                     STD_OFF  /**< Deactivateable: 'Com_CbkRxTOutFuncPtrInd' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_CBKTXACKDEFFUNCPTR                                                                      STD_OFF  /**< Deactivateable: 'Com_CbkTxAckDefFuncPtr' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_CBKTXACKDEFFUNCPTRIND                                                                   STD_OFF  /**< Deactivateable: 'Com_CbkTxAckDefFuncPtrInd' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_CBKTXACKIMFUNCPTR                                                                       STD_OFF  /**< Deactivateable: 'Com_CbkTxAckImFuncPtr' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_CBKTXACKIMFUNCPTRIND                                                                    STD_OFF  /**< Deactivateable: 'Com_CbkTxAckImFuncPtrInd' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_CBKTXERRFUNCPTR                                                                         STD_OFF  /**< Deactivateable: 'Com_CbkTxErrFuncPtr' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_CBKTXERRFUNCPTRIND                                                                      STD_OFF  /**< Deactivateable: 'Com_CbkTxErrFuncPtrInd' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_CBKTXTOUTFUNCPTR                                                                        STD_OFF  /**< Deactivateable: 'Com_CbkTxTOutFuncPtr' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_CBKTXTOUTFUNCPTRIND                                                                     STD_OFF  /**< Deactivateable: 'Com_CbkTxTOutFuncPtrInd' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_CONFIGID                                                                                STD_ON
#define COM_CONSTVALUEARRAYBASED                                                                    STD_OFF  /**< Deactivateable: 'Com_ConstValueArrayBased' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_CONSTVALUEFLOAT32                                                                       STD_OFF  /**< Deactivateable: 'Com_ConstValueFloat32' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_CONSTVALUEFLOAT64                                                                       STD_OFF  /**< Deactivateable: 'Com_ConstValueFloat64' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_CONSTVALUESINT16                                                                        STD_OFF  /**< Deactivateable: 'Com_ConstValueSInt16' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_CONSTVALUESINT32                                                                        STD_OFF  /**< Deactivateable: 'Com_ConstValueSInt32' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_CONSTVALUESINT64                                                                        STD_OFF  /**< Deactivateable: 'Com_ConstValueSInt64' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_CONSTVALUESINT8                                                                         STD_OFF  /**< Deactivateable: 'Com_ConstValueSInt8' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_CONSTVALUESIGGRPARRAYACCESS                                                             STD_OFF  /**< Deactivateable: 'Com_ConstValueSigGrpArrayAccess' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_CONSTVALUEUINT16                                                                        STD_OFF  /**< Deactivateable: 'Com_ConstValueUInt16' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_CONSTVALUEUINT32                                                                        STD_OFF  /**< Deactivateable: 'Com_ConstValueUInt32' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_CONSTVALUEUINT64                                                                        STD_OFF  /**< Deactivateable: 'Com_ConstValueUInt64' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_CONSTVALUEUINT8                                                                         STD_ON
#define COM_CPRQUEUEBUFFER                                                                          STD_OFF  /**< Deactivateable: 'Com_CprQueueBuffer' Reason: 'No CrossPartitionRoutingQueues configured.' */
#define COM_CPRQUEUEDESCRIPTIONROUTINGIND                                                           STD_OFF  /**< Deactivateable: 'Com_CprQueueDescriptionRoutingInd' Reason: 'No CrossPartitionRoutingQueues configured.' */
#define COM_CPRQUEUESIGNALROUTINGIND                                                                STD_OFF  /**< Deactivateable: 'Com_CprQueueSignalRoutingInd' Reason: 'No CrossPartitionRoutingQueues configured.' */
#define COM_CPRSIGNALROUTINGTMPBUFFER                                                               STD_OFF  /**< Deactivateable: 'Com_CprSignalRoutingTmpBuffer' Reason: 'No CrossPartitionRoutingQueues configured.' */
#define COM_CURRENTTXMODE                                                                           STD_ON
#define COM_CYCLETIMECNT                                                                            STD_ON
#define COM_CYCLICSENDREQUEST                                                                       STD_ON
#define COM_DELAYTIMECNT                                                                            STD_OFF  /**< Deactivateable: 'Com_DelayTimeCnt' Reason: 'MinimumDelayTime is not configured or always zero in all variants.' */
#define COM_DIRECTTRIGGER                                                                           STD_OFF  /**< Deactivateable: 'Com_DirectTrigger' Reason: 'the parameter is only needed if ComEnableMDTForCyclicTransmission is equals FALSE.' */
#define COM_FILTERINFO_FLOAT32                                                                      STD_OFF  /**< Deactivateable: 'Com_FilterInfo_Float32' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define COM_FILTERALGOOFFILTERINFO_FLOAT32                                                          STD_OFF  /**< Deactivateable: 'Com_FilterInfo_Float32.FilterAlgo' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_FILTERMASKOFFILTERINFO_FLOAT32                                                          STD_OFF  /**< Deactivateable: 'Com_FilterInfo_Float32.FilterMask' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_FILTERMAXOFFILTERINFO_FLOAT32                                                           STD_OFF  /**< Deactivateable: 'Com_FilterInfo_Float32.FilterMax' Reason: 'FilterMin, FilterMax, FilterX are deactivated for Float32 and Float64 Filter Info, because they aren't configurable.' */
#define COM_FILTERMINOFFILTERINFO_FLOAT32                                                           STD_OFF  /**< Deactivateable: 'Com_FilterInfo_Float32.FilterMin' Reason: 'FilterMin, FilterMax, FilterX are deactivated for Float32 and Float64 Filter Info, because they aren't configurable.' */
#define COM_FILTERXOFFILTERINFO_FLOAT32                                                             STD_OFF  /**< Deactivateable: 'Com_FilterInfo_Float32.FilterX' Reason: 'FilterMin, FilterMax, FilterX are deactivated for Float32 and Float64 Filter Info, because they aren't configurable.' */
#define COM_FILTERINFO_FLOAT64                                                                      STD_OFF  /**< Deactivateable: 'Com_FilterInfo_Float64' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define COM_FILTERALGOOFFILTERINFO_FLOAT64                                                          STD_OFF  /**< Deactivateable: 'Com_FilterInfo_Float64.FilterAlgo' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_FILTERMASKOFFILTERINFO_FLOAT64                                                          STD_OFF  /**< Deactivateable: 'Com_FilterInfo_Float64.FilterMask' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_FILTERMAXOFFILTERINFO_FLOAT64                                                           STD_OFF  /**< Deactivateable: 'Com_FilterInfo_Float64.FilterMax' Reason: 'FilterMin, FilterMax, FilterX are deactivated for Float32 and Float64 Filter Info, because they aren't configurable.' */
#define COM_FILTERMINOFFILTERINFO_FLOAT64                                                           STD_OFF  /**< Deactivateable: 'Com_FilterInfo_Float64.FilterMin' Reason: 'FilterMin, FilterMax, FilterX are deactivated for Float32 and Float64 Filter Info, because they aren't configurable.' */
#define COM_FILTERXOFFILTERINFO_FLOAT64                                                             STD_OFF  /**< Deactivateable: 'Com_FilterInfo_Float64.FilterX' Reason: 'FilterMin, FilterMax, FilterX are deactivated for Float32 and Float64 Filter Info, because they aren't configurable.' */
#define COM_FILTERINFO_SINT16                                                                       STD_OFF  /**< Deactivateable: 'Com_FilterInfo_SInt16' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define COM_FILTERALGOOFFILTERINFO_SINT16                                                           STD_OFF  /**< Deactivateable: 'Com_FilterInfo_SInt16.FilterAlgo' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_FILTERMASKOFFILTERINFO_SINT16                                                           STD_OFF  /**< Deactivateable: 'Com_FilterInfo_SInt16.FilterMask' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_FILTERMAXOFFILTERINFO_SINT16                                                            STD_OFF  /**< Deactivateable: 'Com_FilterInfo_SInt16.FilterMax' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_FILTERMINOFFILTERINFO_SINT16                                                            STD_OFF  /**< Deactivateable: 'Com_FilterInfo_SInt16.FilterMin' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_FILTERXOFFILTERINFO_SINT16                                                              STD_OFF  /**< Deactivateable: 'Com_FilterInfo_SInt16.FilterX' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_FILTERINFO_SINT32                                                                       STD_OFF  /**< Deactivateable: 'Com_FilterInfo_SInt32' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define COM_FILTERALGOOFFILTERINFO_SINT32                                                           STD_OFF  /**< Deactivateable: 'Com_FilterInfo_SInt32.FilterAlgo' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_FILTERMASKOFFILTERINFO_SINT32                                                           STD_OFF  /**< Deactivateable: 'Com_FilterInfo_SInt32.FilterMask' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_FILTERMAXOFFILTERINFO_SINT32                                                            STD_OFF  /**< Deactivateable: 'Com_FilterInfo_SInt32.FilterMax' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_FILTERMINOFFILTERINFO_SINT32                                                            STD_OFF  /**< Deactivateable: 'Com_FilterInfo_SInt32.FilterMin' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_FILTERXOFFILTERINFO_SINT32                                                              STD_OFF  /**< Deactivateable: 'Com_FilterInfo_SInt32.FilterX' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_FILTERINFO_SINT64                                                                       STD_OFF  /**< Deactivateable: 'Com_FilterInfo_SInt64' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define COM_FILTERALGOOFFILTERINFO_SINT64                                                           STD_OFF  /**< Deactivateable: 'Com_FilterInfo_SInt64.FilterAlgo' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_FILTERMASKOFFILTERINFO_SINT64                                                           STD_OFF  /**< Deactivateable: 'Com_FilterInfo_SInt64.FilterMask' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_FILTERMAXOFFILTERINFO_SINT64                                                            STD_OFF  /**< Deactivateable: 'Com_FilterInfo_SInt64.FilterMax' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_FILTERMINOFFILTERINFO_SINT64                                                            STD_OFF  /**< Deactivateable: 'Com_FilterInfo_SInt64.FilterMin' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_FILTERXOFFILTERINFO_SINT64                                                              STD_OFF  /**< Deactivateable: 'Com_FilterInfo_SInt64.FilterX' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_FILTERINFO_SINT8                                                                        STD_OFF  /**< Deactivateable: 'Com_FilterInfo_SInt8' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define COM_FILTERALGOOFFILTERINFO_SINT8                                                            STD_OFF  /**< Deactivateable: 'Com_FilterInfo_SInt8.FilterAlgo' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_FILTERMASKOFFILTERINFO_SINT8                                                            STD_OFF  /**< Deactivateable: 'Com_FilterInfo_SInt8.FilterMask' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_FILTERMAXOFFILTERINFO_SINT8                                                             STD_OFF  /**< Deactivateable: 'Com_FilterInfo_SInt8.FilterMax' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_FILTERMINOFFILTERINFO_SINT8                                                             STD_OFF  /**< Deactivateable: 'Com_FilterInfo_SInt8.FilterMin' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_FILTERXOFFILTERINFO_SINT8                                                               STD_OFF  /**< Deactivateable: 'Com_FilterInfo_SInt8.FilterX' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_FILTERINFO_UINT16                                                                       STD_OFF  /**< Deactivateable: 'Com_FilterInfo_UInt16' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define COM_FILTERALGOOFFILTERINFO_UINT16                                                           STD_OFF  /**< Deactivateable: 'Com_FilterInfo_UInt16.FilterAlgo' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_FILTERMASKOFFILTERINFO_UINT16                                                           STD_OFF  /**< Deactivateable: 'Com_FilterInfo_UInt16.FilterMask' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_FILTERMAXOFFILTERINFO_UINT16                                                            STD_OFF  /**< Deactivateable: 'Com_FilterInfo_UInt16.FilterMax' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_FILTERMINOFFILTERINFO_UINT16                                                            STD_OFF  /**< Deactivateable: 'Com_FilterInfo_UInt16.FilterMin' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_FILTERXOFFILTERINFO_UINT16                                                              STD_OFF  /**< Deactivateable: 'Com_FilterInfo_UInt16.FilterX' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_FILTERINFO_UINT32                                                                       STD_OFF  /**< Deactivateable: 'Com_FilterInfo_UInt32' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define COM_FILTERALGOOFFILTERINFO_UINT32                                                           STD_OFF  /**< Deactivateable: 'Com_FilterInfo_UInt32.FilterAlgo' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_FILTERMASKOFFILTERINFO_UINT32                                                           STD_OFF  /**< Deactivateable: 'Com_FilterInfo_UInt32.FilterMask' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_FILTERMAXOFFILTERINFO_UINT32                                                            STD_OFF  /**< Deactivateable: 'Com_FilterInfo_UInt32.FilterMax' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_FILTERMINOFFILTERINFO_UINT32                                                            STD_OFF  /**< Deactivateable: 'Com_FilterInfo_UInt32.FilterMin' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_FILTERXOFFILTERINFO_UINT32                                                              STD_OFF  /**< Deactivateable: 'Com_FilterInfo_UInt32.FilterX' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_FILTERINFO_UINT64                                                                       STD_OFF  /**< Deactivateable: 'Com_FilterInfo_UInt64' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define COM_FILTERALGOOFFILTERINFO_UINT64                                                           STD_OFF  /**< Deactivateable: 'Com_FilterInfo_UInt64.FilterAlgo' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_FILTERMASKOFFILTERINFO_UINT64                                                           STD_OFF  /**< Deactivateable: 'Com_FilterInfo_UInt64.FilterMask' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_FILTERMAXOFFILTERINFO_UINT64                                                            STD_OFF  /**< Deactivateable: 'Com_FilterInfo_UInt64.FilterMax' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_FILTERMINOFFILTERINFO_UINT64                                                            STD_OFF  /**< Deactivateable: 'Com_FilterInfo_UInt64.FilterMin' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_FILTERXOFFILTERINFO_UINT64                                                              STD_OFF  /**< Deactivateable: 'Com_FilterInfo_UInt64.FilterX' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_FILTERINFO_UINT8                                                                        STD_OFF  /**< Deactivateable: 'Com_FilterInfo_UInt8' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define COM_FILTERALGOOFFILTERINFO_UINT8                                                            STD_OFF  /**< Deactivateable: 'Com_FilterInfo_UInt8.FilterAlgo' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_FILTERMASKOFFILTERINFO_UINT8                                                            STD_OFF  /**< Deactivateable: 'Com_FilterInfo_UInt8.FilterMask' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_FILTERMAXOFFILTERINFO_UINT8                                                             STD_OFF  /**< Deactivateable: 'Com_FilterInfo_UInt8.FilterMax' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_FILTERMINOFFILTERINFO_UINT8                                                             STD_OFF  /**< Deactivateable: 'Com_FilterInfo_UInt8.FilterMin' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_FILTERXOFFILTERINFO_UINT8                                                               STD_OFF  /**< Deactivateable: 'Com_FilterInfo_UInt8.FilterX' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_FILTERINFO_UINT8_N                                                                      STD_OFF  /**< Deactivateable: 'Com_FilterInfo_UInt8_N' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define COM_FILTERALGOOFFILTERINFO_UINT8_N                                                          STD_OFF  /**< Deactivateable: 'Com_FilterInfo_UInt8_N.FilterAlgo' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_FILTERMASKOFFILTERINFO_UINT8_N                                                          STD_OFF  /**< Deactivateable: 'Com_FilterInfo_UInt8_N.FilterMask' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_FILTERMAXOFFILTERINFO_UINT8_N                                                           STD_OFF  /**< Deactivateable: 'Com_FilterInfo_UInt8_N.FilterMax' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_FILTERMINOFFILTERINFO_UINT8_N                                                           STD_OFF  /**< Deactivateable: 'Com_FilterInfo_UInt8_N.FilterMin' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_FILTERXOFFILTERINFO_UINT8_N                                                             STD_OFF  /**< Deactivateable: 'Com_FilterInfo_UInt8_N.FilterX' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_FINALMAGICNUMBER                                                                        STD_OFF  /**< Deactivateable: 'Com_FinalMagicNumber' Reason: 'the module configuration does not support flashing of data.' */
#define COM_GATEWAYDESCRIPTIONPROCESSINGISRLOCKCOUNTER                                              STD_OFF  /**< Deactivateable: 'Com_GatewayDescriptionProcessingISRLockCounter' Reason: 'No Deferred Description Routings exist in all variants.' */
#define COM_GATEWAYDESCRIPTIONPROCESSINGISRLOCKTHRESHOLD                                            STD_OFF  /**< Deactivateable: 'Com_GatewayDescriptionProcessingISRLockThreshold' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComDescriptionGateway] is configured to 'false'' */
#define COM_GATEWAYPROCESSINGISRLOCKCOUNTER                                                         STD_OFF  /**< Deactivateable: 'Com_GatewayProcessingISRLockCounter' Reason: 'Signal Gateway is not configured in all variants.' */
#define COM_GATEWAYPROCESSINGISRLOCKTHRESHOLD                                                       STD_OFF  /**< Deactivateable: 'Com_GatewayProcessingISRLockThreshold' Reason: 'Signal Gateway is not configured in all variants.' */
#define COM_GWDESCRIPTIONACCESSINFO                                                                 STD_OFF  /**< Deactivateable: 'Com_GwDescriptionAccessInfo' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComDescriptionGateway] is configured to 'false'' */
#define COM_BITOFFSETOFGWDESCRIPTIONACCESSINFO                                                      STD_OFF  /**< Deactivateable: 'Com_GwDescriptionAccessInfo.BitOffset' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComDescriptionGateway] is configured to 'false'' */
#define COM_BITSIZEOFGWDESCRIPTIONACCESSINFO                                                        STD_OFF  /**< Deactivateable: 'Com_GwDescriptionAccessInfo.BitSize' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComDescriptionGateway] is configured to 'false'' */
#define COM_COPYTYPEOFGWDESCRIPTIONACCESSINFO                                                       STD_OFF  /**< Deactivateable: 'Com_GwDescriptionAccessInfo.CopyType' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComDescriptionGateway] is configured to 'false'' */
#define COM_ENDIANNESSOFGWDESCRIPTIONACCESSINFO                                                     STD_OFF  /**< Deactivateable: 'Com_GwDescriptionAccessInfo.Endianness' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComDescriptionGateway] is configured to 'false'' */
#define COM_GWSOURCESTARTBITINDEXOFGWDESCRIPTIONACCESSINFO                                          STD_OFF  /**< Deactivateable: 'Com_GwDescriptionAccessInfo.GwSourceStartBitIndex' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComDescriptionGateway] is configured to 'false'' */
#define COM_RXUBIDXOFGWDESCRIPTIONACCESSINFO                                                        STD_OFF  /**< Deactivateable: 'Com_GwDescriptionAccessInfo.RxUbIdx' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComDescriptionGateway] is configured to 'false'' */
#define COM_RXUBIDXUSEDOFGWDESCRIPTIONACCESSINFO                                                    STD_OFF  /**< Deactivateable: 'Com_GwDescriptionAccessInfo.RxUbIdxUsed' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComDescriptionGateway] is configured to 'false'' */
#define COM_RXUBMASKIDXOFGWDESCRIPTIONACCESSINFO                                                    STD_OFF  /**< Deactivateable: 'Com_GwDescriptionAccessInfo.RxUbMaskIdx' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComDescriptionGateway] is configured to 'false'' */
#define COM_RXUBMASKOFGWDESCRIPTIONACCESSINFO                                                       STD_OFF  /**< Deactivateable: 'Com_GwDescriptionAccessInfo.RxUbMask' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComDescriptionGateway] is configured to 'false'' */
#define COM_RXUBMASKUSEDOFGWDESCRIPTIONACCESSINFO                                                   STD_OFF  /**< Deactivateable: 'Com_GwDescriptionAccessInfo.RxUbMaskUsed' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComDescriptionGateway] is configured to 'false'' */
#define COM_SOURCEDESCRIPTIONMASKENDMASKIDXOFGWDESCRIPTIONACCESSINFO                                STD_OFF  /**< Deactivateable: 'Com_GwDescriptionAccessInfo.SourceDescriptionMaskEndMaskIdx' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComDescriptionGateway] is configured to 'false'' */
#define COM_SOURCEDESCRIPTIONMASKENDMASKUSEDOFGWDESCRIPTIONACCESSINFO                               STD_OFF  /**< Deactivateable: 'Com_GwDescriptionAccessInfo.SourceDescriptionMaskEndMaskUsed' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComDescriptionGateway] is configured to 'false'' */
#define COM_SOURCEDESCRIPTIONMASKIDXOFGWDESCRIPTIONACCESSINFO                                       STD_OFF  /**< Deactivateable: 'Com_GwDescriptionAccessInfo.SourceDescriptionMaskIdx' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComDescriptionGateway] is configured to 'false'' */
#define COM_SOURCESTARTBYTEOFFSETOFGWDESCRIPTIONACCESSINFO                                          STD_OFF  /**< Deactivateable: 'Com_GwDescriptionAccessInfo.SourceStartByteOffset' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComDescriptionGateway] is configured to 'false'' */
#define COM_TXBUFFERENDIDXOFGWDESCRIPTIONACCESSINFO                                                 STD_OFF  /**< Deactivateable: 'Com_GwDescriptionAccessInfo.TxBufferEndIdx' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComDescriptionGateway] is configured to 'false'' */
#define COM_TXBUFFERLENGTHOFGWDESCRIPTIONACCESSINFO                                                 STD_OFF  /**< Deactivateable: 'Com_GwDescriptionAccessInfo.TxBufferLength' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComDescriptionGateway] is configured to 'false'' */
#define COM_TXBUFFERSTARTIDXOFGWDESCRIPTIONACCESSINFO                                               STD_OFF  /**< Deactivateable: 'Com_GwDescriptionAccessInfo.TxBufferStartIdx' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComDescriptionGateway] is configured to 'false'' */
#define COM_TXBUFFERUBIDXOFGWDESCRIPTIONACCESSINFO                                                  STD_OFF  /**< Deactivateable: 'Com_GwDescriptionAccessInfo.TxBufferUbIdx' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComDescriptionGateway] is configured to 'false'' */
#define COM_TXBUFFERUBUSEDOFGWDESCRIPTIONACCESSINFO                                                 STD_OFF  /**< Deactivateable: 'Com_GwDescriptionAccessInfo.TxBufferUbUsed' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComDescriptionGateway] is configured to 'false'' */
#define COM_TXPDUINFOIDXOFGWDESCRIPTIONACCESSINFO                                                   STD_OFF  /**< Deactivateable: 'Com_GwDescriptionAccessInfo.TxPduInfoIdx' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComDescriptionGateway] is configured to 'false'' */
#define COM_TXUBMASKIDXOFGWDESCRIPTIONACCESSINFO                                                    STD_OFF  /**< Deactivateable: 'Com_GwDescriptionAccessInfo.TxUbMaskIdx' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComDescriptionGateway] is configured to 'false'' */
#define COM_TXUBMASKOFGWDESCRIPTIONACCESSINFO                                                       STD_OFF  /**< Deactivateable: 'Com_GwDescriptionAccessInfo.TxUbMask' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComDescriptionGateway] is configured to 'false'' */
#define COM_TXUBMASKUSEDOFGWDESCRIPTIONACCESSINFO                                                   STD_OFF  /**< Deactivateable: 'Com_GwDescriptionAccessInfo.TxUbMaskUsed' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComDescriptionGateway] is configured to 'false'' */
#define COM_TYPEOFGWDESCRIPTIONACCESSINFO                                                           STD_OFF  /**< Deactivateable: 'Com_GwDescriptionAccessInfo.Type' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComDescriptionGateway] is configured to 'false'' */
#define COM_VALIDDLCOFGWDESCRIPTIONACCESSINFO                                                       STD_OFF  /**< Deactivateable: 'Com_GwDescriptionAccessInfo.ValidDlc' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComDescriptionGateway] is configured to 'false'' */
#define COM_GWEVENT                                                                                 STD_OFF  /**< Deactivateable: 'Com_GwEvent' Reason: 'The gateway is deactivated!' */
#define COM_GWEVENTCACHE                                                                            STD_OFF  /**< Deactivateable: 'Com_GwEventCache' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComDescriptionGateway] is configured to 'false'' */
#define COM_RXPDUINFOIDXOFGWEVENTCACHE                                                              STD_OFF  /**< Deactivateable: 'Com_GwEventCache.RxPduInfoIdx' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComDescriptionGateway] is configured to 'false'' */
#define COM_GWEVENTCACHEINDEX                                                                       STD_OFF  /**< Deactivateable: 'Com_GwEventCacheIndex' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComDescriptionGateway] is configured to 'false'' */
#define COM_GWEVENTCACHEIDXOFGWEVENTCACHEINDEX                                                      STD_OFF  /**< Deactivateable: 'Com_GwEventCacheIndex.GwEventCacheIdx' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComDescriptionGateway] is configured to 'false'' */
#define COM_GWGRPSIGMAPPING                                                                         STD_OFF  /**< Deactivateable: 'Com_GwGrpSigMapping' Reason: 'The gateway is deactivated!' */
#define COM_RXACCESSINFOIDXOFGWGRPSIGMAPPING                                                        STD_OFF  /**< Deactivateable: 'Com_GwGrpSigMapping.RxAccessInfoIdx' Reason: 'The gateway is deactivated!' */
#define COM_TXGRPSIGINFOIDXOFGWGRPSIGMAPPING                                                        STD_OFF  /**< Deactivateable: 'Com_GwGrpSigMapping.TxGrpSigInfoIdx' Reason: 'The gateway is deactivated!' */
#define COM_GWINFO                                                                                  STD_OFF  /**< Deactivateable: 'Com_GwInfo' Reason: 'The gateway is deactivated!' */
#define COM_GWSIGGRPMAPPINGENDIDXOFGWINFO                                                           STD_OFF  /**< Deactivateable: 'Com_GwInfo.GwSigGrpMappingEndIdx' Reason: 'The gateway is deactivated!' */
#define COM_GWSIGGRPMAPPINGSTARTIDXOFGWINFO                                                         STD_OFF  /**< Deactivateable: 'Com_GwInfo.GwSigGrpMappingStartIdx' Reason: 'The gateway is deactivated!' */
#define COM_GWSIGGRPMAPPINGUSEDOFGWINFO                                                             STD_OFF  /**< Deactivateable: 'Com_GwInfo.GwSigGrpMappingUsed' Reason: 'The gateway is deactivated!' */
#define COM_GWSIGMAPPINGENDIDXOFGWINFO                                                              STD_OFF  /**< Deactivateable: 'Com_GwInfo.GwSigMappingEndIdx' Reason: 'The gateway is deactivated!' */
#define COM_GWSIGMAPPINGSTARTIDXOFGWINFO                                                            STD_OFF  /**< Deactivateable: 'Com_GwInfo.GwSigMappingStartIdx' Reason: 'The gateway is deactivated!' */
#define COM_GWSIGMAPPINGUSEDOFGWINFO                                                                STD_OFF  /**< Deactivateable: 'Com_GwInfo.GwSigMappingUsed' Reason: 'The gateway is deactivated!' */
#define COM_GWINFOIND                                                                               STD_OFF  /**< Deactivateable: 'Com_GwInfoInd' Reason: 'The gateway is deactivated!' */
#define COM_GWROUTINGTIMEOUTCOUNTER                                                                 STD_OFF  /**< Deactivateable: 'Com_GwRoutingTimeoutCounter' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_GWSIGGRPMAPPING                                                                         STD_OFF  /**< Deactivateable: 'Com_GwSigGrpMapping' Reason: 'The gateway is deactivated!' */
#define COM_CPRQUEUEIDXOFGWSIGGRPMAPPING                                                            STD_OFF  /**< Deactivateable: 'Com_GwSigGrpMapping.CprQueueIdx' Reason: 'The gateway is deactivated!' */
#define COM_CPRQUEUEUSEDOFGWSIGGRPMAPPING                                                           STD_OFF  /**< Deactivateable: 'Com_GwSigGrpMapping.CprQueueUsed' Reason: 'The gateway is deactivated!' */
#define COM_GWGRPSIGMAPPINGENDIDXOFGWSIGGRPMAPPING                                                  STD_OFF  /**< Deactivateable: 'Com_GwSigGrpMapping.GwGrpSigMappingEndIdx' Reason: 'The gateway is deactivated!' */
#define COM_GWGRPSIGMAPPINGSTARTIDXOFGWSIGGRPMAPPING                                                STD_OFF  /**< Deactivateable: 'Com_GwSigGrpMapping.GwGrpSigMappingStartIdx' Reason: 'The gateway is deactivated!' */
#define COM_TXSIGGRPINFOIDXOFGWSIGGRPMAPPING                                                        STD_OFF  /**< Deactivateable: 'Com_GwSigGrpMapping.TxSigGrpInfoIdx' Reason: 'The gateway is deactivated!' */
#define COM_GWSIGMAPPING                                                                            STD_OFF  /**< Deactivateable: 'Com_GwSigMapping' Reason: 'The gateway is deactivated!' */
#define COM_CPRQUEUEIDXOFGWSIGMAPPING                                                               STD_OFF  /**< Deactivateable: 'Com_GwSigMapping.CprQueueIdx' Reason: 'The gateway is deactivated!' */
#define COM_CPRQUEUEUSEDOFGWSIGMAPPING                                                              STD_OFF  /**< Deactivateable: 'Com_GwSigMapping.CprQueueUsed' Reason: 'The gateway is deactivated!' */
#define COM_RXACCESSINFOIDXOFGWSIGMAPPING                                                           STD_OFF  /**< Deactivateable: 'Com_GwSigMapping.RxAccessInfoIdx' Reason: 'The gateway is deactivated!' */
#define COM_TXSIGINFOIDXOFGWSIGMAPPING                                                              STD_OFF  /**< Deactivateable: 'Com_GwSigMapping.TxSigInfoIdx' Reason: 'The gateway is deactivated!' */
#define COM_GWTIMEOUTINFO                                                                           STD_OFF  /**< Deactivateable: 'Com_GwTimeoutInfo' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define COM_GWROUTINGTIMEOUTFACTOROFGWTIMEOUTINFO                                                   STD_OFF  /**< Deactivateable: 'Com_GwTimeoutInfo.GwRoutingTimeoutFactor' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_TXPDUINFOIDXOFGWTIMEOUTINFO                                                             STD_OFF  /**< Deactivateable: 'Com_GwTimeoutInfo.TxPduInfoIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_GWTIMEOUTINFOOFMAINFUNCTIONTXIND                                                        STD_OFF  /**< Deactivateable: 'Com_GwTimeoutInfoOfMainFunctionTxInd' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_GWTXPDUDESCRIPTIONINFO                                                                  STD_OFF  /**< Deactivateable: 'Com_GwTxPduDescriptionInfo' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComDescriptionGateway] is configured to 'false'' */
#define COM_CPRQUEUEIDXOFGWTXPDUDESCRIPTIONINFO                                                     STD_OFF  /**< Deactivateable: 'Com_GwTxPduDescriptionInfo.CprQueueIdx' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComDescriptionGateway] is configured to 'false'' */
#define COM_CPRQUEUEUSEDOFGWTXPDUDESCRIPTIONINFO                                                    STD_OFF  /**< Deactivateable: 'Com_GwTxPduDescriptionInfo.CprQueueUsed' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComDescriptionGateway] is configured to 'false'' */
#define COM_GWDESCRIPTIONACCESSINFOENDIDXOFGWTXPDUDESCRIPTIONINFO                                   STD_OFF  /**< Deactivateable: 'Com_GwTxPduDescriptionInfo.GwDescriptionAccessInfoEndIdx' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComDescriptionGateway] is configured to 'false'' */
#define COM_GWDESCRIPTIONACCESSINFOSTARTIDXOFGWTXPDUDESCRIPTIONINFO                                 STD_OFF  /**< Deactivateable: 'Com_GwTxPduDescriptionInfo.GwDescriptionAccessInfoStartIdx' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComDescriptionGateway] is configured to 'false'' */
#define COM_SOURCEMAXLENGTHOFGWTXPDUDESCRIPTIONINFO                                                 STD_OFF  /**< Deactivateable: 'Com_GwTxPduDescriptionInfo.SourceMaxLength' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComDescriptionGateway] is configured to 'false'' */
#define COM_SOURCEMINSTARTBYTEPOSITIONOFGWTXPDUDESCRIPTIONINFO                                      STD_OFF  /**< Deactivateable: 'Com_GwTxPduDescriptionInfo.SourceMinStartBytePosition' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComDescriptionGateway] is configured to 'false'' */
#define COM_HANDLERXDEFERREDGWDESCRIPTION                                                           STD_OFF  /**< Deactivateable: 'Com_HandleRxDeferredGwDescription' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComDescriptionGateway] is configured to 'false'' */
#define COM_HANDLERXPDUDEFERRED                                                                     STD_ON
#define COM_HANDLETXPDUDEFERRED                                                                     STD_OFF  /**< Deactivateable: 'Com_HandleTxPduDeferred' Reason: 'This array is deactivated, because no Tx notification functions for deferred signal processing are configured in all variants.' */
#define COM_IPDUGROUPINFO                                                                           STD_ON
#define COM_IPDUGROUPINFOTOSUBIPDUGROUPSINDENDIDXOFIPDUGROUPINFO                                    STD_ON
#define COM_IPDUGROUPINFOTOSUBIPDUGROUPSINDSTARTIDXOFIPDUGROUPINFO                                  STD_ON
#define COM_IPDUGROUPINFOTOSUBIPDUGROUPSINDUSEDOFIPDUGROUPINFO                                      STD_ON
#define COM_INVALIDHNDOFIPDUGROUPINFO                                                               STD_OFF  /**< Deactivateable: 'Com_IPduGroupInfo.InvalidHnd' Reason: 'the value of Com_InvalidHndOfIPduGroupInfo is always 'false' due to this, the array is deactivated.' */
#define COM_PARTITIONSRXSTRUCTIDXOFIPDUGROUPINFO                                                    STD_ON
#define COM_PARTITIONSRXSTRUCTUSEDOFIPDUGROUPINFO                                                   STD_ON
#define COM_PARTITIONSTXSTRUCTIDXOFIPDUGROUPINFO                                                    STD_ON
#define COM_PARTITIONSTXSTRUCTUSEDOFIPDUGROUPINFO                                                   STD_ON
#define COM_RXPDUINFOINDENDIDXOFIPDUGROUPINFO                                                       STD_ON
#define COM_RXPDUINFOINDSTARTIDXOFIPDUGROUPINFO                                                     STD_ON
#define COM_RXPDUINFOINDUSEDOFIPDUGROUPINFO                                                         STD_ON
#define COM_TXPDUINFOINDENDIDXOFIPDUGROUPINFO                                                       STD_ON
#define COM_TXPDUINFOINDSTARTIDXOFIPDUGROUPINFO                                                     STD_ON
#define COM_TXPDUINFOINDUSEDOFIPDUGROUPINFO                                                         STD_ON
#define COM_IPDUGROUPINFOOFRXPDUINFOIND                                                             STD_ON
#define COM_IPDUGROUPINFOOFTXPDUINFOIND                                                             STD_ON
#define COM_IPDUGROUPINFOTOSUBIPDUGROUPSIND                                                         STD_ON
#define COM_IPDUGROUPSTATE                                                                          STD_ON
#define COM_INITDATAHASHCODE                                                                        STD_OFF  /**< Deactivateable: 'Com_InitDataHashCode' Reason: 'the module configuration does not support flashing of data.' */
#define COM_INITIALTRANSMIT                                                                         STD_OFF  /**< Deactivateable: 'Com_InitialTransmit' Reason: 'This parameter is only needed if ComMixedModePeriodicSuppression is set to TRUE.' */
#define COM_INITIALIZED                                                                             STD_ON
#define COM_MAINFUNCTIONROUTESIGNALSSTRUCT                                                          STD_OFF  /**< Deactivateable: 'Com_MainFunctionRouteSignalsStruct' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define COM_GATEWAYDESCRIPTIONPROCESSINGISRLOCKCOUNTERIDXOFMAINFUNCTIONROUTESIGNALSSTRUCT           STD_OFF  /**< Deactivateable: 'Com_MainFunctionRouteSignalsStruct.GatewayDescriptionProcessingISRLockCounterIdx' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComDescriptionGateway] is configured to 'false'' */
#define COM_GATEWAYPROCESSINGISRLOCKCOUNTERIDXOFMAINFUNCTIONROUTESIGNALSSTRUCT                      STD_OFF  /**< Deactivateable: 'Com_MainFunctionRouteSignalsStruct.GatewayProcessingISRLockCounterIdx' Reason: 'All indirection targets are deactivated in all variants.' */
#define COM_GWEVENTCACHEENDIDXOFMAINFUNCTIONROUTESIGNALSSTRUCT                                      STD_OFF  /**< Deactivateable: 'Com_MainFunctionRouteSignalsStruct.GwEventCacheEndIdx' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComDescriptionGateway] is configured to 'false'' */
#define COM_GWEVENTCACHEINDEXIDXOFMAINFUNCTIONROUTESIGNALSSTRUCT                                    STD_OFF  /**< Deactivateable: 'Com_MainFunctionRouteSignalsStruct.GwEventCacheIndexIdx' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComDescriptionGateway] is configured to 'false'' */
#define COM_GWEVENTCACHEINDEXUSEDOFMAINFUNCTIONROUTESIGNALSSTRUCT                                   STD_OFF  /**< Deactivateable: 'Com_MainFunctionRouteSignalsStruct.GwEventCacheIndexUsed' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComDescriptionGateway] is configured to 'false'' */
#define COM_GWEVENTCACHESTARTIDXOFMAINFUNCTIONROUTESIGNALSSTRUCT                                    STD_OFF  /**< Deactivateable: 'Com_MainFunctionRouteSignalsStruct.GwEventCacheStartIdx' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComDescriptionGateway] is configured to 'false'' */
#define COM_GWEVENTCACHEUSEDOFMAINFUNCTIONROUTESIGNALSSTRUCT                                        STD_OFF  /**< Deactivateable: 'Com_MainFunctionRouteSignalsStruct.GwEventCacheUsed' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComDescriptionGateway] is configured to 'false'' */
#define COM_GWINFOINDENDIDXOFMAINFUNCTIONROUTESIGNALSSTRUCT                                         STD_OFF  /**< Deactivateable: 'Com_MainFunctionRouteSignalsStruct.GwInfoIndEndIdx' Reason: 'All indirection targets are deactivated in all variants.' */
#define COM_GWINFOINDSTARTIDXOFMAINFUNCTIONROUTESIGNALSSTRUCT                                       STD_OFF  /**< Deactivateable: 'Com_MainFunctionRouteSignalsStruct.GwInfoIndStartIdx' Reason: 'All indirection targets are deactivated in all variants.' */
#define COM_GWINFOINDUSEDOFMAINFUNCTIONROUTESIGNALSSTRUCT                                           STD_OFF  /**< Deactivateable: 'Com_MainFunctionRouteSignalsStruct.GwInfoIndUsed' Reason: 'All indirection targets are deactivated in all variants.' */
#define COM_PARTITIONSTXSTRUCTIDXOFMAINFUNCTIONROUTESIGNALSSTRUCT                                   STD_OFF  /**< Deactivateable: 'Com_MainFunctionRouteSignalsStruct.PartitionsTxStructIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_PARTITIONSTXSTRUCTUSEDOFMAINFUNCTIONROUTESIGNALSSTRUCT                                  STD_OFF  /**< Deactivateable: 'Com_MainFunctionRouteSignalsStruct.PartitionsTxStructUsed' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_MAINFUNCTIONRXSTRUCT                                                                    STD_ON
#define COM_RXDEFERREDEVENTCACHEENDIDXOFMAINFUNCTIONRXSTRUCT                                        STD_OFF  /**< Deactivateable: 'Com_MainFunctionRxStruct.RxDeferredEventCacheEndIdx' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComDeferredEventCacheSupport] is configured to 'false'' */
#define COM_RXDEFERREDEVENTCACHESTARTIDXOFMAINFUNCTIONRXSTRUCT                                      STD_OFF  /**< Deactivateable: 'Com_MainFunctionRxStruct.RxDeferredEventCacheStartIdx' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComDeferredEventCacheSupport] is configured to 'false'' */
#define COM_RXDEFERREDFCTPTRCACHEENDIDXOFMAINFUNCTIONRXSTRUCT                                       STD_OFF  /**< Deactivateable: 'Com_MainFunctionRxStruct.RxDeferredFctPtrCacheEndIdx' Reason: 'NotificationCache size is zero in all variants' */
#define COM_RXDEFERREDFCTPTRCACHELENGTHOFMAINFUNCTIONRXSTRUCT                                       STD_OFF  /**< Deactivateable: 'Com_MainFunctionRxStruct.RxDeferredFctPtrCacheLength' Reason: 'NotificationCache size is zero in all variants' */
#define COM_RXDEFERREDFCTPTRCACHESTARTIDXOFMAINFUNCTIONRXSTRUCT                                     STD_OFF  /**< Deactivateable: 'Com_MainFunctionRxStruct.RxDeferredFctPtrCacheStartIdx' Reason: 'NotificationCache size is zero in all variants' */
#define COM_RXMAINFUNCTIONPROCESSINGISRLOCKCOUNTERIDXOFMAINFUNCTIONRXSTRUCT                         STD_ON
#define COM_RXNEXTEVENTCACHEENTRYIDXOFMAINFUNCTIONRXSTRUCT                                          STD_OFF  /**< Deactivateable: 'Com_MainFunctionRxStruct.RxNextEventCacheEntryIdx' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComDeferredEventCacheSupport] is configured to 'false'' */
#define COM_RXPDUINFOOFMAINFUNCTIONRXINDENDIDXOFMAINFUNCTIONRXSTRUCT                                STD_ON
#define COM_RXPDUINFOOFMAINFUNCTIONRXINDSTARTIDXOFMAINFUNCTIONRXSTRUCT                              STD_ON
#define COM_RXPDUINFOOFMAINFUNCTIONRXINDUSEDOFMAINFUNCTIONRXSTRUCT                                  STD_ON
#define COM_RXTOUTINFOOFMAINFUNCTIONRXINDENDIDXOFMAINFUNCTIONRXSTRUCT                               STD_OFF  /**< Deactivateable: 'Com_MainFunctionRxStruct.RxTOutInfoOfMainFunctionRxIndEndIdx' Reason: 'the optional indirection is deactivated because RxTOutInfoOfMainFunctionRxIndUsedOfMainFunctionRxStruct is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_RXTOUTINFOOFMAINFUNCTIONRXINDSTARTIDXOFMAINFUNCTIONRXSTRUCT                             STD_OFF  /**< Deactivateable: 'Com_MainFunctionRxStruct.RxTOutInfoOfMainFunctionRxIndStartIdx' Reason: 'the optional indirection is deactivated because RxTOutInfoOfMainFunctionRxIndUsedOfMainFunctionRxStruct is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_RXTOUTINFOOFMAINFUNCTIONRXINDUSEDOFMAINFUNCTIONRXSTRUCT                                 STD_OFF  /**< Deactivateable: 'Com_MainFunctionRxStruct.RxTOutInfoOfMainFunctionRxIndUsed' Reason: 'the optional indirection is deactivated because RxTOutInfoOfMainFunctionRxIndUsedOfMainFunctionRxStruct is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_MAINFUNCTIONTXSTRUCT                                                                    STD_ON
#define COM_GWTIMEOUTINFOOFMAINFUNCTIONTXINDENDIDXOFMAINFUNCTIONTXSTRUCT                            STD_OFF  /**< Deactivateable: 'Com_MainFunctionTxStruct.GwTimeoutInfoOfMainFunctionTxIndEndIdx' Reason: 'the optional indirection is deactivated because GwTimeoutInfoOfMainFunctionTxIndUsedOfMainFunctionTxStruct is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_GWTIMEOUTINFOOFMAINFUNCTIONTXINDSTARTIDXOFMAINFUNCTIONTXSTRUCT                          STD_OFF  /**< Deactivateable: 'Com_MainFunctionTxStruct.GwTimeoutInfoOfMainFunctionTxIndStartIdx' Reason: 'the optional indirection is deactivated because GwTimeoutInfoOfMainFunctionTxIndUsedOfMainFunctionTxStruct is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_GWTIMEOUTINFOOFMAINFUNCTIONTXINDUSEDOFMAINFUNCTIONTXSTRUCT                              STD_OFF  /**< Deactivateable: 'Com_MainFunctionTxStruct.GwTimeoutInfoOfMainFunctionTxIndUsed' Reason: 'the optional indirection is deactivated because GwTimeoutInfoOfMainFunctionTxIndUsedOfMainFunctionTxStruct is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_TXCYCLICPDUOFMAINFUNCTIONTXINDENDIDXOFMAINFUNCTIONTXSTRUCT                              STD_ON
#define COM_TXCYCLICPDUOFMAINFUNCTIONTXINDSTARTIDXOFMAINFUNCTIONTXSTRUCT                            STD_ON
#define COM_TXCYCLICPDUOFMAINFUNCTIONTXINDUSEDOFMAINFUNCTIONTXSTRUCT                                STD_ON
#define COM_TXPDUINFOOFMAINFUNCTIONTXINDENDIDXOFMAINFUNCTIONTXSTRUCT                                STD_ON
#define COM_TXPDUINFOOFMAINFUNCTIONTXINDSTARTIDXOFMAINFUNCTIONTXSTRUCT                              STD_ON
#define COM_TXPDUINFOOFMAINFUNCTIONTXINDUSEDOFMAINFUNCTIONTXSTRUCT                                  STD_ON
#define COM_TXPROCESSINGISRLOCKCOUNTERIDXOFMAINFUNCTIONTXSTRUCT                                     STD_ON
#define COM_TXTOUTINFOOFMAINFUNCTIONTXINDENDIDXOFMAINFUNCTIONTXSTRUCT                               STD_OFF  /**< Deactivateable: 'Com_MainFunctionTxStruct.TxTOutInfoOfMainFunctionTxIndEndIdx' Reason: 'the optional indirection is deactivated because TxTOutInfoOfMainFunctionTxIndUsedOfMainFunctionTxStruct is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_TXTOUTINFOOFMAINFUNCTIONTXINDSTARTIDXOFMAINFUNCTIONTXSTRUCT                             STD_OFF  /**< Deactivateable: 'Com_MainFunctionTxStruct.TxTOutInfoOfMainFunctionTxIndStartIdx' Reason: 'the optional indirection is deactivated because TxTOutInfoOfMainFunctionTxIndUsedOfMainFunctionTxStruct is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_TXTOUTINFOOFMAINFUNCTIONTXINDUSEDOFMAINFUNCTIONTXSTRUCT                                 STD_OFF  /**< Deactivateable: 'Com_MainFunctionTxStruct.TxTOutInfoOfMainFunctionTxIndUsed' Reason: 'the optional indirection is deactivated because TxTOutInfoOfMainFunctionTxIndUsedOfMainFunctionTxStruct is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_MINPROCGWARRAYACCESSSIGGRPBUFFER                                                        STD_OFF  /**< Deactivateable: 'Com_MinProcGwArrayAccessSigGrpBuffer' Reason: 'The gateway is not set to MinimalSignalProcessing!' */
#define COM_MINPROCGWBUFFERARRAYBASED                                                               STD_OFF  /**< Deactivateable: 'Com_MinProcGwBufferArrayBased' Reason: 'The gateway is not set to MinimalSignalProcessing!' */
#define COM_MINPROCGWBUFFERFLOAT32                                                                  STD_OFF  /**< Deactivateable: 'Com_MinProcGwBufferFloat32' Reason: 'The gateway is not set to MinimalSignalProcessing!' */
#define COM_MINPROCGWBUFFERFLOAT64                                                                  STD_OFF  /**< Deactivateable: 'Com_MinProcGwBufferFloat64' Reason: 'The gateway is not set to MinimalSignalProcessing!' */
#define COM_MINPROCGWBUFFERSINT16                                                                   STD_OFF  /**< Deactivateable: 'Com_MinProcGwBufferSInt16' Reason: 'The gateway is not set to MinimalSignalProcessing!' */
#define COM_MINPROCGWBUFFERSINT32                                                                   STD_OFF  /**< Deactivateable: 'Com_MinProcGwBufferSInt32' Reason: 'The gateway is not set to MinimalSignalProcessing!' */
#define COM_MINPROCGWBUFFERSINT64                                                                   STD_OFF  /**< Deactivateable: 'Com_MinProcGwBufferSInt64' Reason: 'The gateway is not set to MinimalSignalProcessing!' */
#define COM_MINPROCGWBUFFERSINT8                                                                    STD_OFF  /**< Deactivateable: 'Com_MinProcGwBufferSInt8' Reason: 'The gateway is not set to MinimalSignalProcessing!' */
#define COM_MINPROCGWBUFFERUINT16                                                                   STD_OFF  /**< Deactivateable: 'Com_MinProcGwBufferUInt16' Reason: 'The gateway is not set to MinimalSignalProcessing!' */
#define COM_MINPROCGWBUFFERUINT32                                                                   STD_OFF  /**< Deactivateable: 'Com_MinProcGwBufferUInt32' Reason: 'The gateway is not set to MinimalSignalProcessing!' */
#define COM_MINPROCGWBUFFERUINT64                                                                   STD_OFF  /**< Deactivateable: 'Com_MinProcGwBufferUInt64' Reason: 'The gateway is not set to MinimalSignalProcessing!' */
#define COM_MINPROCGWBUFFERUINT8                                                                    STD_OFF  /**< Deactivateable: 'Com_MinProcGwBufferUInt8' Reason: 'The gateway is not set to MinimalSignalProcessing!' */
#define COM_MINPROCGWBUFFERZEROBIT                                                                  STD_OFF  /**< Deactivateable: 'Com_MinProcGwBufferZeroBit' Reason: 'The gateway is not set to MinimalSignalProcessing!' */
#define COM_PARTITIONSALWAYSACTIVERXCOMIPDUSSTRUCT                                                  STD_OFF  /**< Deactivateable: 'Com_PartitionsAlwaysActiveRxComIPdusStruct' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define COM_RXIPDUGROUPISRLOCKCOUNTERIDXOFPARTITIONSALWAYSACTIVERXCOMIPDUSSTRUCT                    STD_OFF  /**< Deactivateable: 'Com_PartitionsAlwaysActiveRxComIPdusStruct.RxIPduGroupISRLockCounterIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_PARTITIONSALWAYSACTIVETXCOMIPDUSSTRUCT                                                  STD_ON
#define COM_TXIPDUGROUPISRLOCKCOUNTERIDXOFPARTITIONSALWAYSACTIVETXCOMIPDUSSTRUCT                    STD_ON
#define COM_PARTITIONSRXSTRUCT                                                                      STD_ON
#define COM_RXIPDUGROUPISRLOCKCOUNTERIDXOFPARTITIONSRXSTRUCT                                        STD_ON
#define COM_PARTITIONSTXSTRUCT                                                                      STD_ON
#define COM_CPRQUEUEDESCRIPTIONROUTINGINDENDIDXOFPARTITIONSTXSTRUCT                                 STD_OFF  /**< Deactivateable: 'Com_PartitionsTxStruct.CprQueueDescriptionRoutingIndEndIdx' Reason: 'the optional indirection is deactivated because CprQueueDescriptionRoutingIndUsedOfPartitionsTxStruct is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_CPRQUEUEDESCRIPTIONROUTINGINDSTARTIDXOFPARTITIONSTXSTRUCT                               STD_OFF  /**< Deactivateable: 'Com_PartitionsTxStruct.CprQueueDescriptionRoutingIndStartIdx' Reason: 'the optional indirection is deactivated because CprQueueDescriptionRoutingIndUsedOfPartitionsTxStruct is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_CPRQUEUEDESCRIPTIONROUTINGINDUSEDOFPARTITIONSTXSTRUCT                                   STD_OFF  /**< Deactivateable: 'Com_PartitionsTxStruct.CprQueueDescriptionRoutingIndUsed' Reason: 'the optional indirection is deactivated because CprQueueDescriptionRoutingIndUsedOfPartitionsTxStruct is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_CPRQUEUESIGNALROUTINGINDENDIDXOFPARTITIONSTXSTRUCT                                      STD_OFF  /**< Deactivateable: 'Com_PartitionsTxStruct.CprQueueSignalRoutingIndEndIdx' Reason: 'the optional indirection is deactivated because CprQueueSignalRoutingIndUsedOfPartitionsTxStruct is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_CPRQUEUESIGNALROUTINGINDSTARTIDXOFPARTITIONSTXSTRUCT                                    STD_OFF  /**< Deactivateable: 'Com_PartitionsTxStruct.CprQueueSignalRoutingIndStartIdx' Reason: 'the optional indirection is deactivated because CprQueueSignalRoutingIndUsedOfPartitionsTxStruct is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_CPRQUEUESIGNALROUTINGINDUSEDOFPARTITIONSTXSTRUCT                                        STD_OFF  /**< Deactivateable: 'Com_PartitionsTxStruct.CprQueueSignalRoutingIndUsed' Reason: 'the optional indirection is deactivated because CprQueueSignalRoutingIndUsedOfPartitionsTxStruct is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_TXIPDUGROUPISRLOCKCOUNTERIDXOFPARTITIONSTXSTRUCT                                        STD_ON
#define COM_PDUGRPCNT                                                                               STD_ON
#define COM_REPCNT                                                                                  STD_OFF  /**< Deactivateable: 'Com_RepCnt' Reason: 'This array is deactivated, because no transmission mode with repetitions is configured.' */
#define COM_REPCYCLECNT                                                                             STD_OFF  /**< Deactivateable: 'Com_RepCycleCnt' Reason: 'This array is deactivated, because no transmission mode with repetitions is configured.' */
#define COM_RXACCESSINFO                                                                            STD_ON
#define COM_APPLTYPEOFRXACCESSINFO                                                                  STD_ON
#define COM_BITLENGTHOFRXACCESSINFO                                                                 STD_ON
#define COM_BITPOSITIONOFRXACCESSINFO                                                               STD_ON
#define COM_BUFFERIDXOFRXACCESSINFO                                                                 STD_ON
#define COM_BUFFEROFRXACCESSINFO                                                                    STD_ON
#define COM_BUFFERUSEDOFRXACCESSINFO                                                                STD_ON
#define COM_BUSACCOFRXACCESSINFO                                                                    STD_ON
#define COM_BYTELENGTHOFRXACCESSINFO                                                                STD_ON
#define COM_BYTEPOSITIONOFRXACCESSINFO                                                              STD_ON
#define COM_CONSTVALUEARRAYBASEDINITVALUEENDIDXOFRXACCESSINFO                                       STD_OFF  /**< Deactivateable: 'Com_RxAccessInfo.ConstValueArrayBasedInitValueEndIdx' Reason: 'the optional indirection is deactivated because ConstValueArrayBasedInitValueUsedOfRxAccessInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_CONSTVALUEARRAYBASEDINITVALUELENGTHOFRXACCESSINFO                                       STD_OFF  /**< Deactivateable: 'Com_RxAccessInfo.ConstValueArrayBasedInitValueLength' Reason: 'the optional indirection is deactivated because ConstValueArrayBasedInitValueUsedOfRxAccessInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_CONSTVALUEARRAYBASEDINITVALUESTARTIDXOFRXACCESSINFO                                     STD_OFF  /**< Deactivateable: 'Com_RxAccessInfo.ConstValueArrayBasedInitValueStartIdx' Reason: 'the optional indirection is deactivated because ConstValueArrayBasedInitValueUsedOfRxAccessInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_CONSTVALUEARRAYBASEDINITVALUEUSEDOFRXACCESSINFO                                         STD_OFF  /**< Deactivateable: 'Com_RxAccessInfo.ConstValueArrayBasedInitValueUsed' Reason: 'the optional indirection is deactivated because ConstValueArrayBasedInitValueUsedOfRxAccessInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_CONSTVALUEARRAYBASEDINVVALUEENDIDXOFRXACCESSINFO                                        STD_OFF  /**< Deactivateable: 'Com_RxAccessInfo.ConstValueArrayBasedInvValueEndIdx' Reason: 'the optional indirection is deactivated because ConstValueArrayBasedInvValueUsedOfRxAccessInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_CONSTVALUEARRAYBASEDINVVALUELENGTHOFRXACCESSINFO                                        STD_OFF  /**< Deactivateable: 'Com_RxAccessInfo.ConstValueArrayBasedInvValueLength' Reason: 'the optional indirection is deactivated because ConstValueArrayBasedInvValueUsedOfRxAccessInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_CONSTVALUEARRAYBASEDINVVALUESTARTIDXOFRXACCESSINFO                                      STD_OFF  /**< Deactivateable: 'Com_RxAccessInfo.ConstValueArrayBasedInvValueStartIdx' Reason: 'the optional indirection is deactivated because ConstValueArrayBasedInvValueUsedOfRxAccessInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_CONSTVALUEARRAYBASEDINVVALUEUSEDOFRXACCESSINFO                                          STD_OFF  /**< Deactivateable: 'Com_RxAccessInfo.ConstValueArrayBasedInvValueUsed' Reason: 'the optional indirection is deactivated because ConstValueArrayBasedInvValueUsedOfRxAccessInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_CONSTVALUEARRAYBASEDRXDATATIMEOUTSUBSTITUTIONVALUEENDIDXOFRXACCESSINFO                  STD_OFF  /**< Deactivateable: 'Com_RxAccessInfo.ConstValueArrayBasedRxDataTimeoutSubstitutionValueEndIdx' Reason: 'the optional indirection is deactivated because ConstValueArrayBasedRxDataTimeoutSubstitutionValueUsedOfRxAccessInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_CONSTVALUEARRAYBASEDRXDATATIMEOUTSUBSTITUTIONVALUELENGTHOFRXACCESSINFO                  STD_OFF  /**< Deactivateable: 'Com_RxAccessInfo.ConstValueArrayBasedRxDataTimeoutSubstitutionValueLength' Reason: 'the optional indirection is deactivated because ConstValueArrayBasedRxDataTimeoutSubstitutionValueUsedOfRxAccessInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_CONSTVALUEARRAYBASEDRXDATATIMEOUTSUBSTITUTIONVALUESTARTIDXOFRXACCESSINFO                STD_OFF  /**< Deactivateable: 'Com_RxAccessInfo.ConstValueArrayBasedRxDataTimeoutSubstitutionValueStartIdx' Reason: 'the optional indirection is deactivated because ConstValueArrayBasedRxDataTimeoutSubstitutionValueUsedOfRxAccessInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_CONSTVALUEARRAYBASEDRXDATATIMEOUTSUBSTITUTIONVALUEUSEDOFRXACCESSINFO                    STD_OFF  /**< Deactivateable: 'Com_RxAccessInfo.ConstValueArrayBasedRxDataTimeoutSubstitutionValueUsed' Reason: 'the optional indirection is deactivated because ConstValueArrayBasedRxDataTimeoutSubstitutionValueUsedOfRxAccessInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_DYNSIGNALOFRXACCESSINFO                                                                 STD_ON
#define COM_FILTERINFOIDXOFRXACCESSINFO                                                             STD_OFF  /**< Deactivateable: 'Com_RxAccessInfo.FilterInfoIdx' Reason: 'the optional indirection is deactivated because FilterInfoUsedOfRxAccessInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_FILTERINFOOFRXACCESSINFO                                                                STD_OFF  /**< Deactivateable: 'Com_RxAccessInfo.FilterInfo' Reason: 'the optional indirection is deactivated because FilterInfoUsedOfRxAccessInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_FILTERINFOUSEDOFRXACCESSINFO                                                            STD_OFF  /**< Deactivateable: 'Com_RxAccessInfo.FilterInfoUsed' Reason: 'the optional indirection is deactivated because FilterInfoUsedOfRxAccessInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_GWINFOIDXOFRXACCESSINFO                                                                 STD_OFF  /**< Deactivateable: 'Com_RxAccessInfo.GwInfoIdx' Reason: 'The gateway is deactivated!' */
#define COM_GWINFOUSEDOFRXACCESSINFO                                                                STD_OFF  /**< Deactivateable: 'Com_RxAccessInfo.GwInfoUsed' Reason: 'The gateway is deactivated!' */
#define COM_INITVALUEIDXOFRXACCESSINFO                                                              STD_ON
#define COM_INITVALUEOFRXACCESSINFO                                                                 STD_ON
#define COM_INITVALUEUSEDOFRXACCESSINFO                                                             STD_ON
#define COM_INVVALUEIDXOFRXACCESSINFO                                                               STD_OFF  /**< Deactivateable: 'Com_RxAccessInfo.InvValueIdx' Reason: 'the optional indirection is deactivated because InvValueUsedOfRxAccessInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_INVVALUEOFRXACCESSINFO                                                                  STD_OFF  /**< Deactivateable: 'Com_RxAccessInfo.InvValue' Reason: 'the optional indirection is deactivated because InvValueUsedOfRxAccessInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_INVVALUEUSEDOFRXACCESSINFO                                                              STD_OFF  /**< Deactivateable: 'Com_RxAccessInfo.InvValueUsed' Reason: 'the optional indirection is deactivated because InvValueUsedOfRxAccessInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_INVALIDHNDOFRXACCESSINFO                                                                STD_OFF  /**< Deactivateable: 'Com_RxAccessInfo.InvalidHnd' Reason: 'the value of Com_InvalidHndOfRxAccessInfo is always 'false' due to this, the array is deactivated.' */
#define COM_ISGROUPSIGNALOFRXACCESSINFO                                                             STD_OFF  /**< Deactivateable: 'Com_RxAccessInfo.IsGroupSignal' Reason: 'the value of Com_IsGroupSignalOfRxAccessInfo is always 'false' due to this, the array is deactivated.' */
#define COM_MINPROCGWBUFFERARRAYBASEDBUFFERENDIDXOFRXACCESSINFO                                     STD_OFF  /**< Deactivateable: 'Com_RxAccessInfo.MinProcGwBufferArrayBasedBufferEndIdx' Reason: 'The gateway is not set to MinimalSignalProcessing!' */
#define COM_MINPROCGWBUFFERARRAYBASEDBUFFERLENGTHOFRXACCESSINFO                                     STD_OFF  /**< Deactivateable: 'Com_RxAccessInfo.MinProcGwBufferArrayBasedBufferLength' Reason: 'The gateway is not set to MinimalSignalProcessing!' */
#define COM_MINPROCGWBUFFERARRAYBASEDBUFFERSTARTIDXOFRXACCESSINFO                                   STD_OFF  /**< Deactivateable: 'Com_RxAccessInfo.MinProcGwBufferArrayBasedBufferStartIdx' Reason: 'The gateway is not set to MinimalSignalProcessing!' */
#define COM_MINPROCGWBUFFERARRAYBASEDBUFFERUSEDOFRXACCESSINFO                                       STD_OFF  /**< Deactivateable: 'Com_RxAccessInfo.MinProcGwBufferArrayBasedBufferUsed' Reason: 'The gateway is not set to MinimalSignalProcessing!' */
#define COM_MINPROCGWBUFFERIDXOFRXACCESSINFO                                                        STD_OFF  /**< Deactivateable: 'Com_RxAccessInfo.MinProcGwBufferIdx' Reason: 'the optional indirection is deactivated because MinProcGwBufferUsedOfRxAccessInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_MINPROCGWBUFFEROFRXACCESSINFO                                                           STD_OFF  /**< Deactivateable: 'Com_RxAccessInfo.MinProcGwBuffer' Reason: 'the optional indirection is deactivated because MinProcGwBufferUsedOfRxAccessInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_MINPROCGWBUFFERUSEDOFRXACCESSINFO                                                       STD_OFF  /**< Deactivateable: 'Com_RxAccessInfo.MinProcGwBufferUsed' Reason: 'the optional indirection is deactivated because MinProcGwBufferUsedOfRxAccessInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_ROUTINGBUFFERIDXOFRXACCESSINFO                                                          STD_OFF  /**< Deactivateable: 'Com_RxAccessInfo.RoutingBufferIdx' Reason: 'The gateway is deactivated!' */
#define COM_ROUTINGBUFFEROFRXACCESSINFO                                                             STD_OFF  /**< Deactivateable: 'Com_RxAccessInfo.RoutingBuffer' Reason: 'The gateway is deactivated!' */
#define COM_ROUTINGBUFFERUSEDOFRXACCESSINFO                                                         STD_OFF  /**< Deactivateable: 'Com_RxAccessInfo.RoutingBufferUsed' Reason: 'The gateway is deactivated!' */
#define COM_RXDATATIMEOUTSUBSTITUTIONVALUEIDXOFRXACCESSINFO                                         STD_OFF  /**< Deactivateable: 'Com_RxAccessInfo.RxDataTimeoutSubstitutionValueIdx' Reason: 'the optional indirection is deactivated because RxDataTimeoutSubstitutionValueUsedOfRxAccessInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_RXDATATIMEOUTSUBSTITUTIONVALUEOFRXACCESSINFO                                            STD_OFF  /**< Deactivateable: 'Com_RxAccessInfo.RxDataTimeoutSubstitutionValue' Reason: 'the optional indirection is deactivated because RxDataTimeoutSubstitutionValueUsedOfRxAccessInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_RXDATATIMEOUTSUBSTITUTIONVALUEUSEDOFRXACCESSINFO                                        STD_OFF  /**< Deactivateable: 'Com_RxAccessInfo.RxDataTimeoutSubstitutionValueUsed' Reason: 'the optional indirection is deactivated because RxDataTimeoutSubstitutionValueUsedOfRxAccessInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_RXPDUINFOIDXOFRXACCESSINFO                                                              STD_ON
#define COM_RXSIGBUFFERARRAYBASEDBUFFERENDIDXOFRXACCESSINFO                                         STD_OFF  /**< Deactivateable: 'Com_RxAccessInfo.RxSigBufferArrayBasedBufferEndIdx' Reason: 'the optional indirection is deactivated because RxSigBufferArrayBasedBufferUsedOfRxAccessInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_RXSIGBUFFERARRAYBASEDBUFFERLENGTHOFRXACCESSINFO                                         STD_OFF  /**< Deactivateable: 'Com_RxAccessInfo.RxSigBufferArrayBasedBufferLength' Reason: 'the optional indirection is deactivated because RxSigBufferArrayBasedBufferUsedOfRxAccessInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_RXSIGBUFFERARRAYBASEDBUFFERSTARTIDXOFRXACCESSINFO                                       STD_OFF  /**< Deactivateable: 'Com_RxAccessInfo.RxSigBufferArrayBasedBufferStartIdx' Reason: 'the optional indirection is deactivated because RxSigBufferArrayBasedBufferUsedOfRxAccessInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_RXSIGBUFFERARRAYBASEDBUFFERUSEDOFRXACCESSINFO                                           STD_OFF  /**< Deactivateable: 'Com_RxAccessInfo.RxSigBufferArrayBasedBufferUsed' Reason: 'the optional indirection is deactivated because RxSigBufferArrayBasedBufferUsedOfRxAccessInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_RXSIGBUFFERARRAYBASEDROUTINGBUFFERENDIDXOFRXACCESSINFO                                  STD_OFF  /**< Deactivateable: 'Com_RxAccessInfo.RxSigBufferArrayBasedRoutingBufferEndIdx' Reason: 'The gateway is deactivated!' */
#define COM_RXSIGBUFFERARRAYBASEDROUTINGBUFFERLENGTHOFRXACCESSINFO                                  STD_OFF  /**< Deactivateable: 'Com_RxAccessInfo.RxSigBufferArrayBasedRoutingBufferLength' Reason: 'The gateway is deactivated!' */
#define COM_RXSIGBUFFERARRAYBASEDROUTINGBUFFERSTARTIDXOFRXACCESSINFO                                STD_OFF  /**< Deactivateable: 'Com_RxAccessInfo.RxSigBufferArrayBasedRoutingBufferStartIdx' Reason: 'The gateway is deactivated!' */
#define COM_RXSIGBUFFERARRAYBASEDROUTINGBUFFERUSEDOFRXACCESSINFO                                    STD_OFF  /**< Deactivateable: 'Com_RxAccessInfo.RxSigBufferArrayBasedRoutingBufferUsed' Reason: 'The gateway is deactivated!' */
#define COM_RXSIGBUFFERARRAYBASEDSHDBUFFERENDIDXOFRXACCESSINFO                                      STD_OFF  /**< Deactivateable: 'Com_RxAccessInfo.RxSigBufferArrayBasedShdBufferEndIdx' Reason: 'the optional indirection is deactivated because RxSigBufferArrayBasedShdBufferUsedOfRxAccessInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_RXSIGBUFFERARRAYBASEDSHDBUFFERLENGTHOFRXACCESSINFO                                      STD_OFF  /**< Deactivateable: 'Com_RxAccessInfo.RxSigBufferArrayBasedShdBufferLength' Reason: 'the optional indirection is deactivated because RxSigBufferArrayBasedShdBufferUsedOfRxAccessInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_RXSIGBUFFERARRAYBASEDSHDBUFFERSTARTIDXOFRXACCESSINFO                                    STD_OFF  /**< Deactivateable: 'Com_RxAccessInfo.RxSigBufferArrayBasedShdBufferStartIdx' Reason: 'the optional indirection is deactivated because RxSigBufferArrayBasedShdBufferUsedOfRxAccessInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_RXSIGBUFFERARRAYBASEDSHDBUFFERUSEDOFRXACCESSINFO                                        STD_OFF  /**< Deactivateable: 'Com_RxAccessInfo.RxSigBufferArrayBasedShdBufferUsed' Reason: 'the optional indirection is deactivated because RxSigBufferArrayBasedShdBufferUsedOfRxAccessInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_RXTOUTINFOIDXOFRXACCESSINFO                                                             STD_OFF  /**< Deactivateable: 'Com_RxAccessInfo.RxTOutInfoIdx' Reason: 'the optional indirection is deactivated because RxTOutInfoUsedOfRxAccessInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_RXTOUTINFOUSEDOFRXACCESSINFO                                                            STD_OFF  /**< Deactivateable: 'Com_RxAccessInfo.RxTOutInfoUsed' Reason: 'the optional indirection is deactivated because RxTOutInfoUsedOfRxAccessInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_SHDBUFFERIDXOFRXACCESSINFO                                                              STD_OFF  /**< Deactivateable: 'Com_RxAccessInfo.ShdBufferIdx' Reason: 'the optional indirection is deactivated because ShdBufferUsedOfRxAccessInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_SHDBUFFEROFRXACCESSINFO                                                                 STD_OFF  /**< Deactivateable: 'Com_RxAccessInfo.ShdBuffer' Reason: 'the optional indirection is deactivated because ShdBufferUsedOfRxAccessInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_SHDBUFFERUSEDOFRXACCESSINFO                                                             STD_OFF  /**< Deactivateable: 'Com_RxAccessInfo.ShdBufferUsed' Reason: 'the optional indirection is deactivated because ShdBufferUsedOfRxAccessInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_SIGNEXTREQUIREDOFRXACCESSINFO                                                           STD_OFF  /**< Deactivateable: 'Com_RxAccessInfo.SignExtRequired' Reason: 'the value of Com_SignExtRequiredOfRxAccessInfo is always 'false' due to this, the array is deactivated.' */
#define COM_SIGNALLENGTHINBYTEOFRXACCESSINFO                                                        STD_ON
#define COM_STARTBYTEINPDUPOSITIONOFRXACCESSINFO                                                    STD_ON
#define COM_TMPBUFFERIDXOFRXACCESSINFO                                                              STD_OFF  /**< Deactivateable: 'Com_RxAccessInfo.TmpBufferIdx' Reason: 'the optional indirection is deactivated because TmpBufferUsedOfRxAccessInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_TMPBUFFEROFRXACCESSINFO                                                                 STD_OFF  /**< Deactivateable: 'Com_RxAccessInfo.TmpBuffer' Reason: 'the optional indirection is deactivated because TmpBufferUsedOfRxAccessInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_TMPBUFFERUSEDOFRXACCESSINFO                                                             STD_OFF  /**< Deactivateable: 'Com_RxAccessInfo.TmpBufferUsed' Reason: 'the optional indirection is deactivated because TmpBufferUsedOfRxAccessInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_TMPRXSHDBUFFERARRAYBASEDTMPBUFFERENDIDXOFRXACCESSINFO                                   STD_OFF  /**< Deactivateable: 'Com_RxAccessInfo.TmpRxShdBufferArrayBasedTmpBufferEndIdx' Reason: 'the optional indirection is deactivated because TmpRxShdBufferArrayBasedTmpBufferUsedOfRxAccessInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_TMPRXSHDBUFFERARRAYBASEDTMPBUFFERLENGTHOFRXACCESSINFO                                   STD_OFF  /**< Deactivateable: 'Com_RxAccessInfo.TmpRxShdBufferArrayBasedTmpBufferLength' Reason: 'the optional indirection is deactivated because TmpRxShdBufferArrayBasedTmpBufferUsedOfRxAccessInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_TMPRXSHDBUFFERARRAYBASEDTMPBUFFERSTARTIDXOFRXACCESSINFO                                 STD_OFF  /**< Deactivateable: 'Com_RxAccessInfo.TmpRxShdBufferArrayBasedTmpBufferStartIdx' Reason: 'the optional indirection is deactivated because TmpRxShdBufferArrayBasedTmpBufferUsedOfRxAccessInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_TMPRXSHDBUFFERARRAYBASEDTMPBUFFERUSEDOFRXACCESSINFO                                     STD_OFF  /**< Deactivateable: 'Com_RxAccessInfo.TmpRxShdBufferArrayBasedTmpBufferUsed' Reason: 'the optional indirection is deactivated because TmpRxShdBufferArrayBasedTmpBufferUsedOfRxAccessInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_RXACCESSINFOGRPSIGIND                                                                   STD_OFF  /**< Deactivateable: 'Com_RxAccessInfoGrpSigInd' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_RXACCESSINFOIND                                                                         STD_ON
#define COM_RXACCESSINFOREPLACEGRPSIGIND                                                            STD_OFF  /**< Deactivateable: 'Com_RxAccessInfoReplaceGrpSigInd' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_RXACCESSINFOREPLACESIGIND                                                               STD_OFF  /**< Deactivateable: 'Com_RxAccessInfoReplaceSigInd' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_RXCBKFUNCPTR                                                                            STD_OFF  /**< Deactivateable: 'Com_RxCbkFuncPtr' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_RXDEFPDUBUFFER                                                                          STD_ON
#define COM_RXDEFERREDEVENTCACHE                                                                    STD_OFF  /**< Deactivateable: 'Com_RxDeferredEventCache' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComDeferredEventCacheSupport] is configured to 'false'' */
#define COM_RXPDUINFOIDXOFRXDEFERREDEVENTCACHE                                                      STD_OFF  /**< Deactivateable: 'Com_RxDeferredEventCache.RxPduInfoIdx' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComDeferredEventCacheSupport] is configured to 'false'' */
#define COM_RXDEFERREDFCTPTRCACHE                                                                   STD_OFF  /**< Deactivateable: 'Com_RxDeferredFctPtrCache' Reason: 'NotificationCache size is zero in all variants' */
#define COM_RXDYNSIGNALLENGTH                                                                       STD_OFF  /**< Deactivateable: 'Com_RxDynSignalLength' Reason: '/ActiveEcuC/PduR/Com[0:PduRTransportProtocol] is configured to 'false'' */
#define COM_RXDYNSIGNALTMPLENGTHFORSIGNALGROUPS                                                     STD_OFF  /**< Deactivateable: 'Com_RxDynSignalTmpLengthForSignalGroups' Reason: 'No dynamic length group signals are present in all variants.' */
#define COM_RXIPDUGROUPISRLOCKCOUNTER                                                               STD_ON
#define COM_RXIPDUGROUPISRLOCKTHRESHOLD                                                             STD_ON
#define COM_RXMAINFUNCTIONPROCESSINGISRLOCKCOUNTER                                                  STD_ON
#define COM_RXMAINFUNCTIONPROCESSINGISRLOCKTHRESHOLD                                                STD_ON
#define COM_RXNEXTEVENTCACHEENTRY                                                                   STD_OFF  /**< Deactivateable: 'Com_RxNextEventCacheEntry' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComDeferredEventCacheSupport] is configured to 'false'' */
#define COM_RXDEFERREDEVENTCACHEIDXOFRXNEXTEVENTCACHEENTRY                                          STD_OFF  /**< Deactivateable: 'Com_RxNextEventCacheEntry.RxDeferredEventCacheIdx' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComDeferredEventCacheSupport] is configured to 'false'' */
#define COM_RXPDUCALLOUTFUNCPTR                                                                     STD_OFF  /**< Deactivateable: 'Com_RxPduCalloutFuncPtr' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_RXPDUDMSTATE                                                                            STD_OFF  /**< Deactivateable: 'Com_RxPduDmState' Reason: 'This array is deactivated, because no Rx timeout is configured in all variants.' */
#define COM_RXPDUGRPACTIVE                                                                          STD_ON
#define COM_RXPDUINFO                                                                               STD_ON
#define COM_GWINFOENDIDXOFRXPDUINFO                                                                 STD_OFF  /**< Deactivateable: 'Com_RxPduInfo.GwInfoEndIdx' Reason: 'The gateway is deactivated!' */
#define COM_GWINFOSTARTIDXOFRXPDUINFO                                                               STD_OFF  /**< Deactivateable: 'Com_RxPduInfo.GwInfoStartIdx' Reason: 'The gateway is deactivated!' */
#define COM_GWINFOUSEDOFRXPDUINFO                                                                   STD_OFF  /**< Deactivateable: 'Com_RxPduInfo.GwInfoUsed' Reason: 'The gateway is deactivated!' */
#define COM_GWTXPDUDESCRIPTIONINFOENDIDXOFRXPDUINFO                                                 STD_OFF  /**< Deactivateable: 'Com_RxPduInfo.GwTxPduDescriptionInfoEndIdx' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComDescriptionGateway] is configured to 'false'' */
#define COM_GWTXPDUDESCRIPTIONINFOSTARTIDXOFRXPDUINFO                                               STD_OFF  /**< Deactivateable: 'Com_RxPduInfo.GwTxPduDescriptionInfoStartIdx' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComDescriptionGateway] is configured to 'false'' */
#define COM_GWTXPDUDESCRIPTIONINFOUSEDOFRXPDUINFO                                                   STD_OFF  /**< Deactivateable: 'Com_RxPduInfo.GwTxPduDescriptionInfoUsed' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComDescriptionGateway] is configured to 'false'' */
#define COM_HANDLERXDEFERREDGWDESCRIPTIONIDXOFRXPDUINFO                                             STD_OFF  /**< Deactivateable: 'Com_RxPduInfo.HandleRxDeferredGwDescriptionIdx' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComDescriptionGateway] is configured to 'false'' */
#define COM_HANDLERXDEFERREDGWDESCRIPTIONUSEDOFRXPDUINFO                                            STD_OFF  /**< Deactivateable: 'Com_RxPduInfo.HandleRxDeferredGwDescriptionUsed' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComDescriptionGateway] is configured to 'false'' */
#define COM_HANDLERXPDUDEFERREDIDXOFRXPDUINFO                                                       STD_ON
#define COM_HANDLERXPDUDEFERREDUSEDOFRXPDUINFO                                                      STD_ON
#define COM_IPDUGROUPINFOOFRXPDUINFOINDENDIDXOFRXPDUINFO                                            STD_ON
#define COM_IPDUGROUPINFOOFRXPDUINFOINDSTARTIDXOFRXPDUINFO                                          STD_ON
#define COM_IPDUGROUPINFOOFRXPDUINFOINDUSEDOFRXPDUINFO                                              STD_ON
#define COM_INVALIDHNDOFRXPDUINFO                                                                   STD_OFF  /**< Deactivateable: 'Com_RxPduInfo.InvalidHnd' Reason: 'the value of Com_InvalidHndOfRxPduInfo is always 'false' due to this, the array is deactivated.' */
#define COM_MAINFUNCTIONROUTESIGNALSSTRUCTIDXOFRXPDUINFO                                            STD_OFF  /**< Deactivateable: 'Com_RxPduInfo.MainFunctionRouteSignalsStructIdx' Reason: 'the optional indirection is deactivated because MainFunctionRouteSignalsStructUsedOfRxPduInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_MAINFUNCTIONROUTESIGNALSSTRUCTUSEDOFRXPDUINFO                                           STD_OFF  /**< Deactivateable: 'Com_RxPduInfo.MainFunctionRouteSignalsStructUsed' Reason: 'the optional indirection is deactivated because MainFunctionRouteSignalsStructUsedOfRxPduInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_MAINFUNCTIONRXSTRUCTIDXOFRXPDUINFO                                                      STD_ON
#define COM_MAINFUNCTIONRXSTRUCTUSEDOFRXPDUINFO                                                     STD_ON
#define COM_METADATALENGTHOFRXPDUINFO                                                               STD_OFF  /**< Deactivateable: 'Com_RxPduInfo.MetaDataLength' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComMetaDataSupport] is configured to 'false'' */
#define COM_PARTITIONSRXSTRUCTIDXOFRXPDUINFO                                                        STD_ON
#define COM_RXACCESSINFOINDENDIDXOFRXPDUINFO                                                        STD_ON
#define COM_RXACCESSINFOINDSTARTIDXOFRXPDUINFO                                                      STD_ON
#define COM_RXACCESSINFOINDUSEDOFRXPDUINFO                                                          STD_ON
#define COM_RXDEFPDUBUFFERENDIDXOFRXPDUINFO                                                         STD_ON
#define COM_RXDEFPDUBUFFERLENGTHOFRXPDUINFO                                                         STD_ON
#define COM_RXDEFPDUBUFFERSTARTIDXOFRXPDUINFO                                                       STD_ON
#define COM_RXDEFPDUBUFFERUSEDOFRXPDUINFO                                                           STD_ON
#define COM_RXPDUCALLOUTFUNCPTRIDXOFRXPDUINFO                                                       STD_OFF  /**< Deactivateable: 'Com_RxPduInfo.RxPduCalloutFuncPtrIdx' Reason: 'the optional indirection is deactivated because RxPduCalloutFuncPtrUsedOfRxPduInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_RXPDUCALLOUTFUNCPTRUSEDOFRXPDUINFO                                                      STD_OFF  /**< Deactivateable: 'Com_RxPduInfo.RxPduCalloutFuncPtrUsed' Reason: 'the optional indirection is deactivated because RxPduCalloutFuncPtrUsedOfRxPduInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_RXSIGGRPINFOINDENDIDXOFRXPDUINFO                                                        STD_OFF  /**< Deactivateable: 'Com_RxPduInfo.RxSigGrpInfoIndEndIdx' Reason: 'the optional indirection is deactivated because RxSigGrpInfoIndUsedOfRxPduInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_RXSIGGRPINFOINDSTARTIDXOFRXPDUINFO                                                      STD_OFF  /**< Deactivateable: 'Com_RxPduInfo.RxSigGrpInfoIndStartIdx' Reason: 'the optional indirection is deactivated because RxSigGrpInfoIndUsedOfRxPduInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_RXSIGGRPINFOINDUSEDOFRXPDUINFO                                                          STD_OFF  /**< Deactivateable: 'Com_RxPduInfo.RxSigGrpInfoIndUsed' Reason: 'the optional indirection is deactivated because RxSigGrpInfoIndUsedOfRxPduInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_RXSIGINFOENDIDXOFRXPDUINFO                                                              STD_ON
#define COM_RXSIGINFOSTARTIDXOFRXPDUINFO                                                            STD_ON
#define COM_RXSIGINFOUSEDOFRXPDUINFO                                                                STD_ON
#define COM_RXTOUTINFOIDXOFRXPDUINFO                                                                STD_OFF  /**< Deactivateable: 'Com_RxPduInfo.RxTOutInfoIdx' Reason: 'the optional indirection is deactivated because RxTOutInfoUsedOfRxPduInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_RXTOUTINFOINDENDIDXOFRXPDUINFO                                                          STD_OFF  /**< Deactivateable: 'Com_RxPduInfo.RxTOutInfoIndEndIdx' Reason: 'the optional indirection is deactivated because RxTOutInfoIndUsedOfRxPduInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_RXTOUTINFOINDSTARTIDXOFRXPDUINFO                                                        STD_OFF  /**< Deactivateable: 'Com_RxPduInfo.RxTOutInfoIndStartIdx' Reason: 'the optional indirection is deactivated because RxTOutInfoIndUsedOfRxPduInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_RXTOUTINFOINDUSEDOFRXPDUINFO                                                            STD_OFF  /**< Deactivateable: 'Com_RxPduInfo.RxTOutInfoIndUsed' Reason: 'the optional indirection is deactivated because RxTOutInfoIndUsedOfRxPduInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_RXTOUTINFOUSEDOFRXPDUINFO                                                               STD_OFF  /**< Deactivateable: 'Com_RxPduInfo.RxTOutInfoUsed' Reason: 'the optional indirection is deactivated because RxTOutInfoUsedOfRxPduInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_RXTPINFOIDXOFRXPDUINFO                                                                  STD_OFF  /**< Deactivateable: 'Com_RxPduInfo.RxTpInfoIdx' Reason: '/ActiveEcuC/PduR/Com[0:PduRTransportProtocol] is configured to 'false'' */
#define COM_RXTPINFOUSEDOFRXPDUINFO                                                                 STD_OFF  /**< Deactivateable: 'Com_RxPduInfo.RxTpInfoUsed' Reason: '/ActiveEcuC/PduR/Com[0:PduRTransportProtocol] is configured to 'false'' */
#define COM_SIGNALPROCESSINGOFRXPDUINFO                                                             STD_ON
#define COM_TYPEOFRXPDUINFO                                                                         STD_ON
#define COM_RXPDUINFOIND                                                                            STD_ON
#define COM_RXPDUINFOOFMAINFUNCTIONRXIND                                                            STD_ON
#define COM_RXSIGARRAYACCESSSIGGRPBUFFER                                                            STD_OFF  /**< Deactivateable: 'Com_RxSigArrayAccessSigGrpBuffer' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_RXSIGBUFFERARRAYBASED                                                                   STD_OFF  /**< Deactivateable: 'Com_RxSigBufferArrayBased' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_RXSIGBUFFERFLOAT32                                                                      STD_OFF  /**< Deactivateable: 'Com_RxSigBufferFloat32' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_RXSIGBUFFERFLOAT64                                                                      STD_OFF  /**< Deactivateable: 'Com_RxSigBufferFloat64' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_RXSIGBUFFERSINT16                                                                       STD_OFF  /**< Deactivateable: 'Com_RxSigBufferSInt16' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_RXSIGBUFFERSINT32                                                                       STD_OFF  /**< Deactivateable: 'Com_RxSigBufferSInt32' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_RXSIGBUFFERSINT64                                                                       STD_OFF  /**< Deactivateable: 'Com_RxSigBufferSInt64' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_RXSIGBUFFERSINT8                                                                        STD_OFF  /**< Deactivateable: 'Com_RxSigBufferSInt8' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_RXSIGBUFFERUINT16                                                                       STD_OFF  /**< Deactivateable: 'Com_RxSigBufferUInt16' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_RXSIGBUFFERUINT32                                                                       STD_OFF  /**< Deactivateable: 'Com_RxSigBufferUInt32' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_RXSIGBUFFERUINT64                                                                       STD_OFF  /**< Deactivateable: 'Com_RxSigBufferUInt64' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_RXSIGBUFFERUINT8                                                                        STD_ON
#define COM_RXSIGBUFFERZEROBIT                                                                      STD_OFF  /**< Deactivateable: 'Com_RxSigBufferZeroBit' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_RXSIGGRPINFO                                                                            STD_OFF  /**< Deactivateable: 'Com_RxSigGrpInfo' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define COM_ARRAYACCESSUSEDOFRXSIGGRPINFO                                                           STD_OFF  /**< Deactivateable: 'Com_RxSigGrpInfo.ArrayAccessUsed' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComEnableSignalGroupArrayApi] is configured to 'false'' */
#define COM_CONSTVALUESIGGRPARRAYACCESSENDIDXOFRXSIGGRPINFO                                         STD_OFF  /**< Deactivateable: 'Com_RxSigGrpInfo.ConstValueSigGrpArrayAccessEndIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_CONSTVALUESIGGRPARRAYACCESSLENGTHOFRXSIGGRPINFO                                         STD_OFF  /**< Deactivateable: 'Com_RxSigGrpInfo.ConstValueSigGrpArrayAccessLength' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_CONSTVALUESIGGRPARRAYACCESSSTARTIDXOFRXSIGGRPINFO                                       STD_OFF  /**< Deactivateable: 'Com_RxSigGrpInfo.ConstValueSigGrpArrayAccessStartIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_CONSTVALUESIGGRPARRAYACCESSUSEDOFRXSIGGRPINFO                                           STD_OFF  /**< Deactivateable: 'Com_RxSigGrpInfo.ConstValueSigGrpArrayAccessUsed' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_CONSTVALUEUINT8ENDIDXOFRXSIGGRPINFO                                                     STD_OFF  /**< Deactivateable: 'Com_RxSigGrpInfo.ConstValueUInt8EndIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_CONSTVALUEUINT8LENGTHOFRXSIGGRPINFO                                                     STD_OFF  /**< Deactivateable: 'Com_RxSigGrpInfo.ConstValueUInt8Length' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_CONSTVALUEUINT8STARTIDXOFRXSIGGRPINFO                                                   STD_OFF  /**< Deactivateable: 'Com_RxSigGrpInfo.ConstValueUInt8StartIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_CONSTVALUEUINT8USEDOFRXSIGGRPINFO                                                       STD_OFF  /**< Deactivateable: 'Com_RxSigGrpInfo.ConstValueUInt8Used' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_FILTEREVENTOFRXSIGGRPINFO                                                               STD_OFF  /**< Deactivateable: 'Com_RxSigGrpInfo.FilterEvent' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_GWINFOIDXOFRXSIGGRPINFO                                                                 STD_OFF  /**< Deactivateable: 'Com_RxSigGrpInfo.GwInfoIdx' Reason: 'The gateway is deactivated!' */
#define COM_GWINFOUSEDOFRXSIGGRPINFO                                                                STD_OFF  /**< Deactivateable: 'Com_RxSigGrpInfo.GwInfoUsed' Reason: 'The gateway is deactivated!' */
#define COM_INVEVENTOFRXSIGGRPINFO                                                                  STD_OFF  /**< Deactivateable: 'Com_RxSigGrpInfo.InvEvent' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_INVALIDHNDOFRXSIGGRPINFO                                                                STD_OFF  /**< Deactivateable: 'Com_RxSigGrpInfo.InvalidHnd' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_RXACCESSINFOGRPSIGINDENDIDXOFRXSIGGRPINFO                                               STD_OFF  /**< Deactivateable: 'Com_RxSigGrpInfo.RxAccessInfoGrpSigIndEndIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_RXACCESSINFOGRPSIGINDSTARTIDXOFRXSIGGRPINFO                                             STD_OFF  /**< Deactivateable: 'Com_RxSigGrpInfo.RxAccessInfoGrpSigIndStartIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_RXACCESSINFOGRPSIGINDUSEDOFRXSIGGRPINFO                                                 STD_OFF  /**< Deactivateable: 'Com_RxSigGrpInfo.RxAccessInfoGrpSigIndUsed' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_RXCBKFUNCPTRACKIDXOFRXSIGGRPINFO                                                        STD_OFF  /**< Deactivateable: 'Com_RxSigGrpInfo.RxCbkFuncPtrAckIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_RXCBKFUNCPTRACKUSEDOFRXSIGGRPINFO                                                       STD_OFF  /**< Deactivateable: 'Com_RxSigGrpInfo.RxCbkFuncPtrAckUsed' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_RXCBKFUNCPTRINVACKIDXOFRXSIGGRPINFO                                                     STD_OFF  /**< Deactivateable: 'Com_RxSigGrpInfo.RxCbkFuncPtrInvAckIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_RXCBKFUNCPTRINVACKUSEDOFRXSIGGRPINFO                                                    STD_OFF  /**< Deactivateable: 'Com_RxSigGrpInfo.RxCbkFuncPtrInvAckUsed' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_RXPDUINFOIDXOFRXSIGGRPINFO                                                              STD_OFF  /**< Deactivateable: 'Com_RxSigGrpInfo.RxPduInfoIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_RXSIGARRAYACCESSSIGGRPBUFFERENDIDXOFRXSIGGRPINFO                                        STD_OFF  /**< Deactivateable: 'Com_RxSigGrpInfo.RxSigArrayAccessSigGrpBufferEndIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_RXSIGARRAYACCESSSIGGRPBUFFERLENGTHOFRXSIGGRPINFO                                        STD_OFF  /**< Deactivateable: 'Com_RxSigGrpInfo.RxSigArrayAccessSigGrpBufferLength' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_RXSIGARRAYACCESSSIGGRPBUFFERSTARTIDXOFRXSIGGRPINFO                                      STD_OFF  /**< Deactivateable: 'Com_RxSigGrpInfo.RxSigArrayAccessSigGrpBufferStartIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_RXSIGARRAYACCESSSIGGRPBUFFERUSEDOFRXSIGGRPINFO                                          STD_OFF  /**< Deactivateable: 'Com_RxSigGrpInfo.RxSigArrayAccessSigGrpBufferUsed' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_RXSIGBUFFERUINT8ENDIDXOFRXSIGGRPINFO                                                    STD_OFF  /**< Deactivateable: 'Com_RxSigGrpInfo.RxSigBufferUInt8EndIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_RXSIGBUFFERUINT8LENGTHOFRXSIGGRPINFO                                                    STD_OFF  /**< Deactivateable: 'Com_RxSigGrpInfo.RxSigBufferUInt8Length' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_RXSIGBUFFERUINT8STARTIDXOFRXSIGGRPINFO                                                  STD_OFF  /**< Deactivateable: 'Com_RxSigGrpInfo.RxSigBufferUInt8StartIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_RXSIGBUFFERUINT8USEDOFRXSIGGRPINFO                                                      STD_OFF  /**< Deactivateable: 'Com_RxSigGrpInfo.RxSigBufferUInt8Used' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_RXTOUTINFOIDXOFRXSIGGRPINFO                                                             STD_OFF  /**< Deactivateable: 'Com_RxSigGrpInfo.RxTOutInfoIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_RXTOUTINFOUSEDOFRXSIGGRPINFO                                                            STD_OFF  /**< Deactivateable: 'Com_RxSigGrpInfo.RxTOutInfoUsed' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_SHDBUFFERREQUIREDOFRXSIGGRPINFO                                                         STD_OFF  /**< Deactivateable: 'Com_RxSigGrpInfo.ShdBufferRequired' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_SIGNALPROCESSINGOFRXSIGGRPINFO                                                          STD_OFF  /**< Deactivateable: 'Com_RxSigGrpInfo.SignalProcessing' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_STARTBYTEPOSITIONOFRXSIGGRPINFO                                                         STD_OFF  /**< Deactivateable: 'Com_RxSigGrpInfo.StartBytePosition' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_UBIDXOFRXSIGGRPINFO                                                                     STD_OFF  /**< Deactivateable: 'Com_RxSigGrpInfo.UbIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_UBIDXUSEDOFRXSIGGRPINFO                                                                 STD_OFF  /**< Deactivateable: 'Com_RxSigGrpInfo.UbIdxUsed' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_UBMASKIDXOFRXSIGGRPINFO                                                                 STD_OFF  /**< Deactivateable: 'Com_RxSigGrpInfo.UbMaskIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_UBMASKOFRXSIGGRPINFO                                                                    STD_OFF  /**< Deactivateable: 'Com_RxSigGrpInfo.UbMask' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_UBMASKUSEDOFRXSIGGRPINFO                                                                STD_OFF  /**< Deactivateable: 'Com_RxSigGrpInfo.UbMaskUsed' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_VALIDDLCOFRXSIGGRPINFO                                                                  STD_OFF  /**< Deactivateable: 'Com_RxSigGrpInfo.ValidDlc' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_RXSIGGRPINFOIND                                                                         STD_OFF  /**< Deactivateable: 'Com_RxSigGrpInfoInd' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_RXSIGINFO                                                                               STD_ON
#define COM_GWINFOIDXOFRXSIGINFO                                                                    STD_OFF  /**< Deactivateable: 'Com_RxSigInfo.GwInfoIdx' Reason: 'The gateway is deactivated!' */
#define COM_GWINFOUSEDOFRXSIGINFO                                                                   STD_OFF  /**< Deactivateable: 'Com_RxSigInfo.GwInfoUsed' Reason: 'The gateway is deactivated!' */
#define COM_RXACCESSINFOIDXOFRXSIGINFO                                                              STD_ON
#define COM_RXCBKFUNCPTRACKIDXOFRXSIGINFO                                                           STD_OFF  /**< Deactivateable: 'Com_RxSigInfo.RxCbkFuncPtrAckIdx' Reason: 'the optional indirection is deactivated because RxCbkFuncPtrAckUsedOfRxSigInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_RXCBKFUNCPTRACKUSEDOFRXSIGINFO                                                          STD_OFF  /**< Deactivateable: 'Com_RxSigInfo.RxCbkFuncPtrAckUsed' Reason: 'the optional indirection is deactivated because RxCbkFuncPtrAckUsedOfRxSigInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_RXCBKFUNCPTRINVACKIDXOFRXSIGINFO                                                        STD_OFF  /**< Deactivateable: 'Com_RxSigInfo.RxCbkFuncPtrInvAckIdx' Reason: 'the optional indirection is deactivated because RxCbkFuncPtrInvAckUsedOfRxSigInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_RXCBKFUNCPTRINVACKUSEDOFRXSIGINFO                                                       STD_OFF  /**< Deactivateable: 'Com_RxSigInfo.RxCbkFuncPtrInvAckUsed' Reason: 'the optional indirection is deactivated because RxCbkFuncPtrInvAckUsedOfRxSigInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_RXTOUTINFOIDXOFRXSIGINFO                                                                STD_OFF  /**< Deactivateable: 'Com_RxSigInfo.RxTOutInfoIdx' Reason: 'the optional indirection is deactivated because RxTOutInfoUsedOfRxSigInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_RXTOUTINFOUSEDOFRXSIGINFO                                                               STD_OFF  /**< Deactivateable: 'Com_RxSigInfo.RxTOutInfoUsed' Reason: 'the optional indirection is deactivated because RxTOutInfoUsedOfRxSigInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_SIGNALPROCESSINGOFRXSIGINFO                                                             STD_ON
#define COM_UBIDXOFRXSIGINFO                                                                        STD_OFF  /**< Deactivateable: 'Com_RxSigInfo.UbIdx' Reason: 'the value of Com_UbIdxOfRxSigInfo is always 'COM_NO_UBIDXOFRXSIGINFO' due to this, the array is deactivated.' */
#define COM_UBIDXUSEDOFRXSIGINFO                                                                    STD_OFF  /**< Deactivateable: 'Com_RxSigInfo.UbIdxUsed' Reason: 'the value of Com_UbIdxUsedOfRxSigInfo is always 'false' due to this, the array is deactivated.' */
#define COM_UBMASKIDXOFRXSIGINFO                                                                    STD_OFF  /**< Deactivateable: 'Com_RxSigInfo.UbMaskIdx' Reason: 'the optional indirection is deactivated because UbMaskUsedOfRxSigInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_UBMASKOFRXSIGINFO                                                                       STD_OFF  /**< Deactivateable: 'Com_RxSigInfo.UbMask' Reason: 'the optional indirection is deactivated because UbMaskUsedOfRxSigInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_UBMASKUSEDOFRXSIGINFO                                                                   STD_OFF  /**< Deactivateable: 'Com_RxSigInfo.UbMaskUsed' Reason: 'the optional indirection is deactivated because UbMaskUsedOfRxSigInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_VALIDDLCOFRXSIGINFO                                                                     STD_ON
#define COM_RXTOUTCNT                                                                               STD_OFF  /**< Deactivateable: 'Com_RxTOutCnt' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_RXTOUTINFO                                                                              STD_OFF  /**< Deactivateable: 'Com_RxTOutInfo' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define COM_CBKRXTOUTFUNCPTRINDENDIDXOFRXTOUTINFO                                                   STD_OFF  /**< Deactivateable: 'Com_RxTOutInfo.CbkRxTOutFuncPtrIndEndIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_CBKRXTOUTFUNCPTRINDSTARTIDXOFRXTOUTINFO                                                 STD_OFF  /**< Deactivateable: 'Com_RxTOutInfo.CbkRxTOutFuncPtrIndStartIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_CBKRXTOUTFUNCPTRINDUSEDOFRXTOUTINFO                                                     STD_OFF  /**< Deactivateable: 'Com_RxTOutInfo.CbkRxTOutFuncPtrIndUsed' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_FACTOROFRXTOUTINFO                                                                      STD_OFF  /**< Deactivateable: 'Com_RxTOutInfo.Factor' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_FIRSTFACTOROFRXTOUTINFO                                                                 STD_OFF  /**< Deactivateable: 'Com_RxTOutInfo.FirstFactor' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_RXACCESSINFOREPLACEGRPSIGINDENDIDXOFRXTOUTINFO                                          STD_OFF  /**< Deactivateable: 'Com_RxTOutInfo.RxAccessInfoReplaceGrpSigIndEndIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_RXACCESSINFOREPLACEGRPSIGINDSTARTIDXOFRXTOUTINFO                                        STD_OFF  /**< Deactivateable: 'Com_RxTOutInfo.RxAccessInfoReplaceGrpSigIndStartIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_RXACCESSINFOREPLACEGRPSIGINDUSEDOFRXTOUTINFO                                            STD_OFF  /**< Deactivateable: 'Com_RxTOutInfo.RxAccessInfoReplaceGrpSigIndUsed' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_RXACCESSINFOREPLACESIGINDENDIDXOFRXTOUTINFO                                             STD_OFF  /**< Deactivateable: 'Com_RxTOutInfo.RxAccessInfoReplaceSigIndEndIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_RXACCESSINFOREPLACESIGINDSTARTIDXOFRXTOUTINFO                                           STD_OFF  /**< Deactivateable: 'Com_RxTOutInfo.RxAccessInfoReplaceSigIndStartIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_RXACCESSINFOREPLACESIGINDUSEDOFRXTOUTINFO                                               STD_OFF  /**< Deactivateable: 'Com_RxTOutInfo.RxAccessInfoReplaceSigIndUsed' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_RXPDUINFOIDXOFRXTOUTINFO                                                                STD_OFF  /**< Deactivateable: 'Com_RxTOutInfo.RxPduInfoIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_RXTOUTINFOIND                                                                           STD_OFF  /**< Deactivateable: 'Com_RxTOutInfoInd' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_RXTOUTINFOOFMAINFUNCTIONRXIND                                                           STD_OFF  /**< Deactivateable: 'Com_RxTOutInfoOfMainFunctionRxInd' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_RXTPBUFFER                                                                              STD_OFF  /**< Deactivateable: 'Com_RxTpBuffer' Reason: '/ActiveEcuC/PduR/Com[0:PduRTransportProtocol] is configured to 'false'' */
#define COM_RXTPCONNECTIONSTATE                                                                     STD_OFF  /**< Deactivateable: 'Com_RxTpConnectionState' Reason: '/ActiveEcuC/PduR/Com[0:PduRTransportProtocol] is configured to 'false'' */
#define COM_RXTPINFO                                                                                STD_OFF  /**< Deactivateable: 'Com_RxTpInfo' Reason: '/ActiveEcuC/PduR/Com[0:PduRTransportProtocol] is configured to 'false'' */
#define COM_BUFFERSIZEOFRXTPINFO                                                                    STD_OFF  /**< Deactivateable: 'Com_RxTpInfo.BufferSize' Reason: '/ActiveEcuC/PduR/Com[0:PduRTransportProtocol] is configured to 'false'' */
#define COM_DYNAMICINITIALLENGTHOFRXTPINFO                                                          STD_OFF  /**< Deactivateable: 'Com_RxTpInfo.DynamicInitialLength' Reason: '/ActiveEcuC/PduR/Com[0:PduRTransportProtocol] is configured to 'false'' */
#define COM_RXACCESSINFODYNSIGIDXOFRXTPINFO                                                         STD_OFF  /**< Deactivateable: 'Com_RxTpInfo.RxAccessInfoDynSigIdx' Reason: '/ActiveEcuC/PduR/Com[0:PduRTransportProtocol] is configured to 'false'' */
#define COM_RXACCESSINFODYNSIGUSEDOFRXTPINFO                                                        STD_OFF  /**< Deactivateable: 'Com_RxTpInfo.RxAccessInfoDynSigUsed' Reason: '/ActiveEcuC/PduR/Com[0:PduRTransportProtocol] is configured to 'false'' */
#define COM_RXTPBUFFERENDIDXOFRXTPINFO                                                              STD_OFF  /**< Deactivateable: 'Com_RxTpInfo.RxTpBufferEndIdx' Reason: '/ActiveEcuC/PduR/Com[0:PduRTransportProtocol] is configured to 'false'' */
#define COM_RXTPBUFFERMETADATAENDIDXOFRXTPINFO                                                      STD_OFF  /**< Deactivateable: 'Com_RxTpInfo.RxTpBufferMetaDataEndIdx' Reason: '/ActiveEcuC/PduR/Com[0:PduRTransportProtocol] is configured to 'false'' */
#define COM_RXTPBUFFERMETADATALENGTHOFRXTPINFO                                                      STD_OFF  /**< Deactivateable: 'Com_RxTpInfo.RxTpBufferMetaDataLength' Reason: '/ActiveEcuC/PduR/Com[0:PduRTransportProtocol] is configured to 'false'' */
#define COM_RXTPBUFFERMETADATASTARTIDXOFRXTPINFO                                                    STD_OFF  /**< Deactivateable: 'Com_RxTpInfo.RxTpBufferMetaDataStartIdx' Reason: '/ActiveEcuC/PduR/Com[0:PduRTransportProtocol] is configured to 'false'' */
#define COM_RXTPBUFFERMETADATAUSEDOFRXTPINFO                                                        STD_OFF  /**< Deactivateable: 'Com_RxTpInfo.RxTpBufferMetaDataUsed' Reason: '/ActiveEcuC/PduR/Com[0:PduRTransportProtocol] is configured to 'false'' */
#define COM_RXTPBUFFERSTARTIDXOFRXTPINFO                                                            STD_OFF  /**< Deactivateable: 'Com_RxTpInfo.RxTpBufferStartIdx' Reason: '/ActiveEcuC/PduR/Com[0:PduRTransportProtocol] is configured to 'false'' */
#define COM_RXTPBUFFERUSEDOFRXTPINFO                                                                STD_OFF  /**< Deactivateable: 'Com_RxTpInfo.RxTpBufferUsed' Reason: '/ActiveEcuC/PduR/Com[0:PduRTransportProtocol] is configured to 'false'' */
#define COM_RXTPSDULENGTH                                                                           STD_OFF  /**< Deactivateable: 'Com_RxTpSduLength' Reason: '/ActiveEcuC/PduR/Com[0:PduRTransportProtocol] is configured to 'false'' */
#define COM_RXTPWRITTENBYTESCOUNTER                                                                 STD_OFF  /**< Deactivateable: 'Com_RxTpWrittenBytesCounter' Reason: '/ActiveEcuC/PduR/Com[0:PduRTransportProtocol] is configured to 'false'' */
#define COM_SIGGRPARRAYFILTERINFO                                                                   STD_OFF  /**< Deactivateable: 'Com_SigGrpArrayFilterInfo' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComEnableSignalGroupArrayApi] is configured to 'false'' */
#define COM_CONSTVALUEUINT8FILTERMASKENDIDXOFSIGGRPARRAYFILTERINFO                                  STD_OFF  /**< Deactivateable: 'Com_SigGrpArrayFilterInfo.ConstValueUInt8FilterMaskEndIdx' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComEnableSignalGroupArrayApi] is configured to 'false'' */
#define COM_CONSTVALUEUINT8FILTERMASKLENGTHOFSIGGRPARRAYFILTERINFO                                  STD_OFF  /**< Deactivateable: 'Com_SigGrpArrayFilterInfo.ConstValueUInt8FilterMaskLength' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComEnableSignalGroupArrayApi] is configured to 'false'' */
#define COM_CONSTVALUEUINT8FILTERMASKSTARTIDXOFSIGGRPARRAYFILTERINFO                                STD_OFF  /**< Deactivateable: 'Com_SigGrpArrayFilterInfo.ConstValueUInt8FilterMaskStartIdx' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComEnableSignalGroupArrayApi] is configured to 'false'' */
#define COM_CONSTVALUEUINT8FILTERMASKUSEDOFSIGGRPARRAYFILTERINFO                                    STD_OFF  /**< Deactivateable: 'Com_SigGrpArrayFilterInfo.ConstValueUInt8FilterMaskUsed' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComEnableSignalGroupArrayApi] is configured to 'false'' */
#define COM_CONSTVALUEUINT8FILTERVALUEXENDIDXOFSIGGRPARRAYFILTERINFO                                STD_OFF  /**< Deactivateable: 'Com_SigGrpArrayFilterInfo.ConstValueUInt8FilterValueXEndIdx' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComEnableSignalGroupArrayApi] is configured to 'false'' */
#define COM_CONSTVALUEUINT8FILTERVALUEXLENGTHOFSIGGRPARRAYFILTERINFO                                STD_OFF  /**< Deactivateable: 'Com_SigGrpArrayFilterInfo.ConstValueUInt8FilterValueXLength' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComEnableSignalGroupArrayApi] is configured to 'false'' */
#define COM_CONSTVALUEUINT8FILTERVALUEXSTARTIDXOFSIGGRPARRAYFILTERINFO                              STD_OFF  /**< Deactivateable: 'Com_SigGrpArrayFilterInfo.ConstValueUInt8FilterValueXStartIdx' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComEnableSignalGroupArrayApi] is configured to 'false'' */
#define COM_CONSTVALUEUINT8FILTERVALUEXUSEDOFSIGGRPARRAYFILTERINFO                                  STD_OFF  /**< Deactivateable: 'Com_SigGrpArrayFilterInfo.ConstValueUInt8FilterValueXUsed' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComEnableSignalGroupArrayApi] is configured to 'false'' */
#define COM_FILTERALGOOFSIGGRPARRAYFILTERINFO                                                       STD_OFF  /**< Deactivateable: 'Com_SigGrpArrayFilterInfo.FilterAlgo' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComEnableSignalGroupArrayApi] is configured to 'false'' */
#define COM_OFFSETINSIGNALGROUPOFSIGGRPARRAYFILTERINFO                                              STD_OFF  /**< Deactivateable: 'Com_SigGrpArrayFilterInfo.OffsetInSignalGroup' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComEnableSignalGroupArrayApi] is configured to 'false'' */
#define COM_SIGGRPEVENTFLAG                                                                         STD_OFF  /**< Deactivateable: 'Com_SigGrpEventFlag' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_SIZEOFALWAYSACTIVETXCOMIPDUS                                                            STD_ON
#define COM_SIZEOFCONSTVALUEUINT8                                                                   STD_ON
#define COM_SIZEOFCURRENTTXMODE                                                                     STD_ON
#define COM_SIZEOFCYCLETIMECNT                                                                      STD_ON
#define COM_SIZEOFCYCLICSENDREQUEST                                                                 STD_ON
#define COM_SIZEOFHANDLERXPDUDEFERRED                                                               STD_ON
#define COM_SIZEOFIPDUGROUPINFO                                                                     STD_ON
#define COM_SIZEOFIPDUGROUPINFOOFRXPDUINFOIND                                                       STD_ON
#define COM_SIZEOFIPDUGROUPINFOOFTXPDUINFOIND                                                       STD_ON
#define COM_SIZEOFIPDUGROUPINFOTOSUBIPDUGROUPSIND                                                   STD_ON
#define COM_SIZEOFIPDUGROUPSTATE                                                                    STD_ON
#define COM_SIZEOFMAINFUNCTIONRXSTRUCT                                                              STD_ON
#define COM_SIZEOFMAINFUNCTIONTXSTRUCT                                                              STD_ON
#define COM_SIZEOFPARTITIONSALWAYSACTIVETXCOMIPDUSSTRUCT                                            STD_ON
#define COM_SIZEOFPARTITIONSRXSTRUCT                                                                STD_ON
#define COM_SIZEOFPARTITIONSTXSTRUCT                                                                STD_ON
#define COM_SIZEOFRXACCESSINFO                                                                      STD_ON
#define COM_SIZEOFRXACCESSINFOIND                                                                   STD_ON
#define COM_SIZEOFRXDEFPDUBUFFER                                                                    STD_ON
#define COM_SIZEOFRXIPDUGROUPISRLOCKCOUNTER                                                         STD_ON
#define COM_SIZEOFRXMAINFUNCTIONPROCESSINGISRLOCKCOUNTER                                            STD_ON
#define COM_SIZEOFRXPDUGRPACTIVE                                                                    STD_ON
#define COM_SIZEOFRXPDUINFO                                                                         STD_ON
#define COM_SIZEOFRXPDUINFOIND                                                                      STD_ON
#define COM_SIZEOFRXPDUINFOOFMAINFUNCTIONRXIND                                                      STD_ON
#define COM_SIZEOFRXSIGBUFFERUINT8                                                                  STD_ON
#define COM_SIZEOFRXSIGINFO                                                                         STD_ON
#define COM_SIZEOFTRANSMITREQUEST                                                                   STD_ON
#define COM_SIZEOFTXACCESSINFO                                                                      STD_ON
#define COM_SIZEOFTXBUFFER                                                                          STD_ON
#define COM_SIZEOFTXCYCLICPDU                                                                       STD_ON
#define COM_SIZEOFTXCYCLICPDUOFMAINFUNCTIONTXIND                                                    STD_ON
#define COM_SIZEOFTXIPDUGROUPISRLOCKCOUNTER                                                         STD_ON
#define COM_SIZEOFTXMODEFALSE                                                                       STD_ON
#define COM_SIZEOFTXMODEINFO                                                                        STD_ON
#define COM_SIZEOFTXMODETRUE                                                                        STD_ON
#define COM_SIZEOFTXPDUGRPACTIVE                                                                    STD_ON
#define COM_SIZEOFTXPDUINFO                                                                         STD_ON
#define COM_SIZEOFTXPDUINFOIND                                                                      STD_ON
#define COM_SIZEOFTXPDUINFOOFMAINFUNCTIONTXIND                                                      STD_ON
#define COM_SIZEOFTXPDUINITVALUE                                                                    STD_ON
#define COM_SIZEOFTXPROCESSINGISRLOCKCOUNTER                                                        STD_ON
#define COM_SIZEOFTXSDULENGTH                                                                       STD_ON
#define COM_SIZEOFTXSIGINFO                                                                         STD_ON
#define COM_SOURCEDESCRIPTIONMASK                                                                   STD_OFF  /**< Deactivateable: 'Com_SourceDescriptionMask' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComDescriptionGateway] is configured to 'false'' */
#define COM_TMPRXBUFFER                                                                             STD_OFF  /**< Deactivateable: 'Com_TmpRxBuffer' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_TMPRXSHDBUFFERARRAYBASED                                                                STD_OFF  /**< Deactivateable: 'Com_TmpRxShdBufferArrayBased' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_TMPRXSHDBUFFERFLOAT32                                                                   STD_OFF  /**< Deactivateable: 'Com_TmpRxShdBufferFloat32' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_TMPRXSHDBUFFERFLOAT64                                                                   STD_OFF  /**< Deactivateable: 'Com_TmpRxShdBufferFloat64' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_TMPRXSHDBUFFERSINT16                                                                    STD_OFF  /**< Deactivateable: 'Com_TmpRxShdBufferSInt16' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_TMPRXSHDBUFFERSINT32                                                                    STD_OFF  /**< Deactivateable: 'Com_TmpRxShdBufferSInt32' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_TMPRXSHDBUFFERSINT64                                                                    STD_OFF  /**< Deactivateable: 'Com_TmpRxShdBufferSInt64' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_TMPRXSHDBUFFERSINT8                                                                     STD_OFF  /**< Deactivateable: 'Com_TmpRxShdBufferSInt8' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_TMPRXSHDBUFFERUINT16                                                                    STD_OFF  /**< Deactivateable: 'Com_TmpRxShdBufferUInt16' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_TMPRXSHDBUFFERUINT32                                                                    STD_OFF  /**< Deactivateable: 'Com_TmpRxShdBufferUInt32' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_TMPRXSHDBUFFERUINT64                                                                    STD_OFF  /**< Deactivateable: 'Com_TmpRxShdBufferUInt64' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_TMPRXSHDBUFFERUINT8                                                                     STD_OFF  /**< Deactivateable: 'Com_TmpRxShdBufferUInt8' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_TRANSMITREQUEST                                                                         STD_ON
#define COM_TXACCESSINFO                                                                            STD_ON
#define COM_INVALIDHNDOFTXACCESSINFO                                                                STD_OFF  /**< Deactivateable: 'Com_TxAccessInfo.InvalidHnd' Reason: 'the value of Com_InvalidHndOfTxAccessInfo is always 'false' due to this, the array is deactivated.' */
#define COM_TXGRPSIGINFOIDXOFTXACCESSINFO                                                           STD_OFF  /**< Deactivateable: 'Com_TxAccessInfo.TxGrpSigInfoIdx' Reason: 'the optional indirection is deactivated because TxGrpSigInfoUsedOfTxAccessInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_TXGRPSIGINFOUSEDOFTXACCESSINFO                                                          STD_OFF  /**< Deactivateable: 'Com_TxAccessInfo.TxGrpSigInfoUsed' Reason: 'the optional indirection is deactivated because TxGrpSigInfoUsedOfTxAccessInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_TXSIGINFOIDXOFTXACCESSINFO                                                              STD_ON
#define COM_TXSIGINFOUSEDOFTXACCESSINFO                                                             STD_ON
#define COM_TXBUFFER                                                                                STD_ON
#define COM_TXCYCLICPDU                                                                             STD_ON
#define COM_TXPDUINFOIDXOFTXCYCLICPDU                                                               STD_ON
#define COM_TXCYCLICPDUOFMAINFUNCTIONTXIND                                                          STD_ON
#define COM_TXDYNSIGNALLENGTH                                                                       STD_OFF  /**< Deactivateable: 'Com_TxDynSignalLength' Reason: '/ActiveEcuC/PduR/Com[0:PduRTransportProtocol] is configured to 'false'' */
#define COM_TXFILTERINITSTATE                                                                       STD_OFF  /**< Deactivateable: 'Com_TxFilterInitState' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_TXFILTERINITVALUEARRAYBASED                                                             STD_OFF  /**< Deactivateable: 'Com_TxFilterInitValueArrayBased' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_TXFILTERINITVALUEFLOAT32                                                                STD_OFF  /**< Deactivateable: 'Com_TxFilterInitValueFloat32' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_TXFILTERINITVALUEFLOAT64                                                                STD_OFF  /**< Deactivateable: 'Com_TxFilterInitValueFloat64' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_TXFILTERINITVALUESINT16                                                                 STD_OFF  /**< Deactivateable: 'Com_TxFilterInitValueSInt16' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_TXFILTERINITVALUESINT32                                                                 STD_OFF  /**< Deactivateable: 'Com_TxFilterInitValueSInt32' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_TXFILTERINITVALUESINT64                                                                 STD_OFF  /**< Deactivateable: 'Com_TxFilterInitValueSInt64' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_TXFILTERINITVALUESINT8                                                                  STD_OFF  /**< Deactivateable: 'Com_TxFilterInitValueSInt8' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_TXFILTERINITVALUESIGGRPARRAYACCESS                                                      STD_OFF  /**< Deactivateable: 'Com_TxFilterInitValueSigGrpArrayAccess' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_TXFILTERINITVALUEUINT16                                                                 STD_OFF  /**< Deactivateable: 'Com_TxFilterInitValueUInt16' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_TXFILTERINITVALUEUINT32                                                                 STD_OFF  /**< Deactivateable: 'Com_TxFilterInitValueUInt32' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_TXFILTERINITVALUEUINT64                                                                 STD_OFF  /**< Deactivateable: 'Com_TxFilterInitValueUInt64' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_TXFILTERINITVALUEUINT8                                                                  STD_OFF  /**< Deactivateable: 'Com_TxFilterInitValueUInt8' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_TXFILTEROLDVALUEARRAYBASED                                                              STD_OFF  /**< Deactivateable: 'Com_TxFilterOldValueArrayBased' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_TXFILTEROLDVALUEFLOAT32                                                                 STD_OFF  /**< Deactivateable: 'Com_TxFilterOldValueFloat32' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_TXFILTEROLDVALUEFLOAT64                                                                 STD_OFF  /**< Deactivateable: 'Com_TxFilterOldValueFloat64' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_TXFILTEROLDVALUESINT16                                                                  STD_OFF  /**< Deactivateable: 'Com_TxFilterOldValueSInt16' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_TXFILTEROLDVALUESINT32                                                                  STD_OFF  /**< Deactivateable: 'Com_TxFilterOldValueSInt32' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_TXFILTEROLDVALUESINT64                                                                  STD_OFF  /**< Deactivateable: 'Com_TxFilterOldValueSInt64' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_TXFILTEROLDVALUESINT8                                                                   STD_OFF  /**< Deactivateable: 'Com_TxFilterOldValueSInt8' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_TXFILTEROLDVALUEUINT16                                                                  STD_OFF  /**< Deactivateable: 'Com_TxFilterOldValueUInt16' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_TXFILTEROLDVALUEUINT32                                                                  STD_OFF  /**< Deactivateable: 'Com_TxFilterOldValueUInt32' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_TXFILTEROLDVALUEUINT64                                                                  STD_OFF  /**< Deactivateable: 'Com_TxFilterOldValueUInt64' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_TXFILTEROLDVALUEUINT8                                                                   STD_OFF  /**< Deactivateable: 'Com_TxFilterOldValueUInt8' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_TXFILTERSTATE                                                                           STD_OFF  /**< Deactivateable: 'Com_TxFilterState' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_TXGRPSIGINFO                                                                            STD_OFF  /**< Deactivateable: 'Com_TxGrpSigInfo' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define COM_APPLTYPEOFTXGRPSIGINFO                                                                  STD_OFF  /**< Deactivateable: 'Com_TxGrpSigInfo.ApplType' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_BITLENGTHOFTXGRPSIGINFO                                                                 STD_OFF  /**< Deactivateable: 'Com_TxGrpSigInfo.BitLength' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_BITPOSITIONOFTXGRPSIGINFO                                                               STD_OFF  /**< Deactivateable: 'Com_TxGrpSigInfo.BitPosition' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_BUSACCOFTXGRPSIGINFO                                                                    STD_OFF  /**< Deactivateable: 'Com_TxGrpSigInfo.BusAcc' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_BYTELENGTHOFTXGRPSIGINFO                                                                STD_OFF  /**< Deactivateable: 'Com_TxGrpSigInfo.ByteLength' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_BYTEPOSITIONOFTXGRPSIGINFO                                                              STD_OFF  /**< Deactivateable: 'Com_TxGrpSigInfo.BytePosition' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_CONSTVALUEARRAYBASEDINVVALUEENDIDXOFTXGRPSIGINFO                                        STD_OFF  /**< Deactivateable: 'Com_TxGrpSigInfo.ConstValueArrayBasedInvValueEndIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_CONSTVALUEARRAYBASEDINVVALUELENGTHOFTXGRPSIGINFO                                        STD_OFF  /**< Deactivateable: 'Com_TxGrpSigInfo.ConstValueArrayBasedInvValueLength' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_CONSTVALUEARRAYBASEDINVVALUESTARTIDXOFTXGRPSIGINFO                                      STD_OFF  /**< Deactivateable: 'Com_TxGrpSigInfo.ConstValueArrayBasedInvValueStartIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_CONSTVALUEARRAYBASEDINVVALUEUSEDOFTXGRPSIGINFO                                          STD_OFF  /**< Deactivateable: 'Com_TxGrpSigInfo.ConstValueArrayBasedInvValueUsed' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_DYNSIGNALOFTXGRPSIGINFO                                                                 STD_OFF  /**< Deactivateable: 'Com_TxGrpSigInfo.DynSignal' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_FILTERINFOIDXOFTXGRPSIGINFO                                                             STD_OFF  /**< Deactivateable: 'Com_TxGrpSigInfo.FilterInfoIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_FILTERINFOOFTXGRPSIGINFO                                                                STD_OFF  /**< Deactivateable: 'Com_TxGrpSigInfo.FilterInfo' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_FILTERINFOUSEDOFTXGRPSIGINFO                                                            STD_OFF  /**< Deactivateable: 'Com_TxGrpSigInfo.FilterInfoUsed' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_FILTERINITVALUEIDXOFTXGRPSIGINFO                                                        STD_OFF  /**< Deactivateable: 'Com_TxGrpSigInfo.FilterInitValueIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_FILTERINITVALUEOFTXGRPSIGINFO                                                           STD_OFF  /**< Deactivateable: 'Com_TxGrpSigInfo.FilterInitValue' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_FILTERINITVALUEUSEDOFTXGRPSIGINFO                                                       STD_OFF  /**< Deactivateable: 'Com_TxGrpSigInfo.FilterInitValueUsed' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_INVVALUEIDXOFTXGRPSIGINFO                                                               STD_OFF  /**< Deactivateable: 'Com_TxGrpSigInfo.InvValueIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_INVVALUEOFTXGRPSIGINFO                                                                  STD_OFF  /**< Deactivateable: 'Com_TxGrpSigInfo.InvValue' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_INVVALUEUSEDOFTXGRPSIGINFO                                                              STD_OFF  /**< Deactivateable: 'Com_TxGrpSigInfo.InvValueUsed' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_ONCHANGEIDXOFTXGRPSIGINFO                                                               STD_OFF  /**< Deactivateable: 'Com_TxGrpSigInfo.OnChangeIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_ONCHANGEOFTXGRPSIGINFO                                                                  STD_OFF  /**< Deactivateable: 'Com_TxGrpSigInfo.OnChange' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_ONCHANGEUSEDOFTXGRPSIGINFO                                                              STD_OFF  /**< Deactivateable: 'Com_TxGrpSigInfo.OnChangeUsed' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_STARTBYTEINPDUPOSITIONOFTXGRPSIGINFO                                                    STD_OFF  /**< Deactivateable: 'Com_TxGrpSigInfo.StartByteInPduPosition' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_TRIGGEREDOFTXGRPSIGINFO                                                                 STD_OFF  /**< Deactivateable: 'Com_TxGrpSigInfo.Triggered' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_TXACCESSINFOIDXOFTXGRPSIGINFO                                                           STD_OFF  /**< Deactivateable: 'Com_TxGrpSigInfo.TxAccessInfoIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_TXBUFFERENDIDXOFTXGRPSIGINFO                                                            STD_OFF  /**< Deactivateable: 'Com_TxGrpSigInfo.TxBufferEndIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_TXBUFFERLENGTHOFTXGRPSIGINFO                                                            STD_OFF  /**< Deactivateable: 'Com_TxGrpSigInfo.TxBufferLength' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_TXBUFFERSTARTIDXOFTXGRPSIGINFO                                                          STD_OFF  /**< Deactivateable: 'Com_TxGrpSigInfo.TxBufferStartIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_TXBUFFERUSEDOFTXGRPSIGINFO                                                              STD_OFF  /**< Deactivateable: 'Com_TxGrpSigInfo.TxBufferUsed' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_TXFILTERINITSTATEIDXOFTXGRPSIGINFO                                                      STD_OFF  /**< Deactivateable: 'Com_TxGrpSigInfo.TxFilterInitStateIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_TXFILTERINITSTATEUSEDOFTXGRPSIGINFO                                                     STD_OFF  /**< Deactivateable: 'Com_TxGrpSigInfo.TxFilterInitStateUsed' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_TXFILTERINITVALUEARRAYBASEDFILTERINITVALUEENDIDXOFTXGRPSIGINFO                          STD_OFF  /**< Deactivateable: 'Com_TxGrpSigInfo.TxFilterInitValueArrayBasedFilterInitValueEndIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_TXFILTERINITVALUEARRAYBASEDFILTERINITVALUELENGTHOFTXGRPSIGINFO                          STD_OFF  /**< Deactivateable: 'Com_TxGrpSigInfo.TxFilterInitValueArrayBasedFilterInitValueLength' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_TXFILTERINITVALUEARRAYBASEDFILTERINITVALUESTARTIDXOFTXGRPSIGINFO                        STD_OFF  /**< Deactivateable: 'Com_TxGrpSigInfo.TxFilterInitValueArrayBasedFilterInitValueStartIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_TXFILTERINITVALUEARRAYBASEDFILTERINITVALUEUSEDOFTXGRPSIGINFO                            STD_OFF  /**< Deactivateable: 'Com_TxGrpSigInfo.TxFilterInitValueArrayBasedFilterInitValueUsed' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_TXPDUINFOIDXOFTXGRPSIGINFO                                                              STD_OFF  /**< Deactivateable: 'Com_TxGrpSigInfo.TxPduInfoIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_TXSIGGRPINFOIDXOFTXGRPSIGINFO                                                           STD_OFF  /**< Deactivateable: 'Com_TxGrpSigInfo.TxSigGrpInfoIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_WITHOUTREPOFTXGRPSIGINFO                                                                STD_OFF  /**< Deactivateable: 'Com_TxGrpSigInfo.WithoutRep' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_TXGRPSIGINFOFILTERINITVALUEIND                                                          STD_OFF  /**< Deactivateable: 'Com_TxGrpSigInfoFilterInitValueInd' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_TXGRPSIGINFOINVVALUEIND                                                                 STD_OFF  /**< Deactivateable: 'Com_TxGrpSigInfoInvValueInd' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_TXIPDUGROUPISRLOCKCOUNTER                                                               STD_ON
#define COM_TXIPDUGROUPISRLOCKTHRESHOLD                                                             STD_ON
#define COM_TXMODEFALSE                                                                             STD_ON
#define COM_DIRECTOFTXMODEFALSE                                                                     STD_OFF  /**< Deactivateable: 'Com_TxModeFalse.Direct' Reason: 'the value of Com_DirectOfTxModeFalse is always 'false' due to this, the array is deactivated.' */
#define COM_PERIODICOFTXMODEFALSE                                                                   STD_ON
#define COM_REPCNTOFTXMODEFALSE                                                                     STD_OFF  /**< Deactivateable: 'Com_TxModeFalse.RepCnt' Reason: 'the value of Com_RepCntOfTxModeFalse is always '0' due to this, the array is deactivated.' */
#define COM_REPPERIODOFTXMODEFALSE                                                                  STD_OFF  /**< Deactivateable: 'Com_TxModeFalse.RepPeriod' Reason: 'the value of Com_RepPeriodOfTxModeFalse is always '0' due to this, the array is deactivated.' */
#define COM_TIMEOFFSETOFTXMODEFALSE                                                                 STD_OFF  /**< Deactivateable: 'Com_TxModeFalse.TimeOffset' Reason: 'the value of Com_TimeOffsetOfTxModeFalse is always '1' due to this, the array is deactivated.' */
#define COM_TIMEPERIODOFTXMODEFALSE                                                                 STD_ON
#define COM_TXMODEINFO                                                                              STD_ON
#define COM_INITMODEOFTXMODEINFO                                                                    STD_ON
#define COM_INVALIDHNDOFTXMODEINFO                                                                  STD_OFF  /**< Deactivateable: 'Com_TxModeInfo.InvalidHnd' Reason: 'the value of Com_InvalidHndOfTxModeInfo is always 'false' due to this, the array is deactivated.' */
#define COM_MINIMUMDELAYOFTXMODEINFO                                                                STD_OFF  /**< Deactivateable: 'Com_TxModeInfo.MinimumDelay' Reason: 'the value of Com_MinimumDelayOfTxModeInfo is always '0' due to this, the array is deactivated.' */
#define COM_TXFILTERINITSTATEENDIDXOFTXMODEINFO                                                     STD_OFF  /**< Deactivateable: 'Com_TxModeInfo.TxFilterInitStateEndIdx' Reason: 'the optional indirection is deactivated because TxFilterInitStateUsedOfTxModeInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_TXFILTERINITSTATESTARTIDXOFTXMODEINFO                                                   STD_OFF  /**< Deactivateable: 'Com_TxModeInfo.TxFilterInitStateStartIdx' Reason: 'the optional indirection is deactivated because TxFilterInitStateUsedOfTxModeInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_TXFILTERINITSTATEUSEDOFTXMODEINFO                                                       STD_OFF  /**< Deactivateable: 'Com_TxModeInfo.TxFilterInitStateUsed' Reason: 'the optional indirection is deactivated because TxFilterInitStateUsedOfTxModeInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_TXGRPSIGINFOFILTERINITVALUEINDENDIDXOFTXMODEINFO                                        STD_OFF  /**< Deactivateable: 'Com_TxModeInfo.TxGrpSigInfoFilterInitValueIndEndIdx' Reason: 'the optional indirection is deactivated because TxGrpSigInfoFilterInitValueIndUsedOfTxModeInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_TXGRPSIGINFOFILTERINITVALUEINDSTARTIDXOFTXMODEINFO                                      STD_OFF  /**< Deactivateable: 'Com_TxModeInfo.TxGrpSigInfoFilterInitValueIndStartIdx' Reason: 'the optional indirection is deactivated because TxGrpSigInfoFilterInitValueIndUsedOfTxModeInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_TXGRPSIGINFOFILTERINITVALUEINDUSEDOFTXMODEINFO                                          STD_OFF  /**< Deactivateable: 'Com_TxModeInfo.TxGrpSigInfoFilterInitValueIndUsed' Reason: 'the optional indirection is deactivated because TxGrpSigInfoFilterInitValueIndUsedOfTxModeInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_TXMODEFALSEIDXOFTXMODEINFO                                                              STD_ON
#define COM_TXMODETRUEIDXOFTXMODEINFO                                                               STD_ON
#define COM_TXSIGINFOFILTERINITVALUEINDENDIDXOFTXMODEINFO                                           STD_OFF  /**< Deactivateable: 'Com_TxModeInfo.TxSigInfoFilterInitValueIndEndIdx' Reason: 'the optional indirection is deactivated because TxSigInfoFilterInitValueIndUsedOfTxModeInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_TXSIGINFOFILTERINITVALUEINDSTARTIDXOFTXMODEINFO                                         STD_OFF  /**< Deactivateable: 'Com_TxModeInfo.TxSigInfoFilterInitValueIndStartIdx' Reason: 'the optional indirection is deactivated because TxSigInfoFilterInitValueIndUsedOfTxModeInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_TXSIGINFOFILTERINITVALUEINDUSEDOFTXMODEINFO                                             STD_OFF  /**< Deactivateable: 'Com_TxModeInfo.TxSigInfoFilterInitValueIndUsed' Reason: 'the optional indirection is deactivated because TxSigInfoFilterInitValueIndUsedOfTxModeInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_TXMODETRUE                                                                              STD_ON
#define COM_DIRECTOFTXMODETRUE                                                                      STD_OFF  /**< Deactivateable: 'Com_TxModeTrue.Direct' Reason: 'the value of Com_DirectOfTxModeTrue is always 'false' due to this, the array is deactivated.' */
#define COM_PERIODICOFTXMODETRUE                                                                    STD_ON
#define COM_REPCNTOFTXMODETRUE                                                                      STD_OFF  /**< Deactivateable: 'Com_TxModeTrue.RepCnt' Reason: 'the value of Com_RepCntOfTxModeTrue is always '0' due to this, the array is deactivated.' */
#define COM_REPPERIODOFTXMODETRUE                                                                   STD_OFF  /**< Deactivateable: 'Com_TxModeTrue.RepPeriod' Reason: 'the value of Com_RepPeriodOfTxModeTrue is always '0' due to this, the array is deactivated.' */
#define COM_TIMEOFFSETOFTXMODETRUE                                                                  STD_OFF  /**< Deactivateable: 'Com_TxModeTrue.TimeOffset' Reason: 'the value of Com_TimeOffsetOfTxModeTrue is always '1' due to this, the array is deactivated.' */
#define COM_TIMEPERIODOFTXMODETRUE                                                                  STD_ON
#define COM_TXPDUCALLOUTFUNCPTR                                                                     STD_OFF  /**< Deactivateable: 'Com_TxPduCalloutFuncPtr' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_TXPDUGRPACTIVE                                                                          STD_ON
#define COM_TXPDUINFO                                                                               STD_ON
#define COM_CANCELLATIONSUPPORTOFTXPDUINFO                                                          STD_OFF  /**< Deactivateable: 'Com_TxPduInfo.CancellationSupport' Reason: '/ActiveEcuC/PduR/Com[0:PduRCancelTransmit] is configured to 'false'' */
#define COM_CBKTXACKDEFFUNCPTRINDENDIDXOFTXPDUINFO                                                  STD_OFF  /**< Deactivateable: 'Com_TxPduInfo.CbkTxAckDefFuncPtrIndEndIdx' Reason: 'the optional indirection is deactivated because CbkTxAckDefFuncPtrIndUsedOfTxPduInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_CBKTXACKDEFFUNCPTRINDSTARTIDXOFTXPDUINFO                                                STD_OFF  /**< Deactivateable: 'Com_TxPduInfo.CbkTxAckDefFuncPtrIndStartIdx' Reason: 'the optional indirection is deactivated because CbkTxAckDefFuncPtrIndUsedOfTxPduInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_CBKTXACKDEFFUNCPTRINDUSEDOFTXPDUINFO                                                    STD_OFF  /**< Deactivateable: 'Com_TxPduInfo.CbkTxAckDefFuncPtrIndUsed' Reason: 'the optional indirection is deactivated because CbkTxAckDefFuncPtrIndUsedOfTxPduInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_CBKTXACKIMFUNCPTRINDENDIDXOFTXPDUINFO                                                   STD_OFF  /**< Deactivateable: 'Com_TxPduInfo.CbkTxAckImFuncPtrIndEndIdx' Reason: 'the optional indirection is deactivated because CbkTxAckImFuncPtrIndUsedOfTxPduInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_CBKTXACKIMFUNCPTRINDSTARTIDXOFTXPDUINFO                                                 STD_OFF  /**< Deactivateable: 'Com_TxPduInfo.CbkTxAckImFuncPtrIndStartIdx' Reason: 'the optional indirection is deactivated because CbkTxAckImFuncPtrIndUsedOfTxPduInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_CBKTXACKIMFUNCPTRINDUSEDOFTXPDUINFO                                                     STD_OFF  /**< Deactivateable: 'Com_TxPduInfo.CbkTxAckImFuncPtrIndUsed' Reason: 'the optional indirection is deactivated because CbkTxAckImFuncPtrIndUsedOfTxPduInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_CBKTXERRFUNCPTRINDENDIDXOFTXPDUINFO                                                     STD_OFF  /**< Deactivateable: 'Com_TxPduInfo.CbkTxErrFuncPtrIndEndIdx' Reason: 'the optional indirection is deactivated because CbkTxErrFuncPtrIndUsedOfTxPduInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_CBKTXERRFUNCPTRINDSTARTIDXOFTXPDUINFO                                                   STD_OFF  /**< Deactivateable: 'Com_TxPduInfo.CbkTxErrFuncPtrIndStartIdx' Reason: 'the optional indirection is deactivated because CbkTxErrFuncPtrIndUsedOfTxPduInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_CBKTXERRFUNCPTRINDUSEDOFTXPDUINFO                                                       STD_OFF  /**< Deactivateable: 'Com_TxPduInfo.CbkTxErrFuncPtrIndUsed' Reason: 'the optional indirection is deactivated because CbkTxErrFuncPtrIndUsedOfTxPduInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_CLRUBOFTXPDUINFO                                                                        STD_OFF  /**< Deactivateable: 'Com_TxPduInfo.ClrUb' Reason: 'This array is deactivated, because no Tx I-PDUs with update-bits are configured in all variants.' */
#define COM_CONSTVALUEUINT8UBCLEARMASKENDIDXOFTXPDUINFO                                             STD_OFF  /**< Deactivateable: 'Com_TxPduInfo.ConstValueUInt8UbClearMaskEndIdx' Reason: 'the optional indirection is deactivated because ConstValueUInt8UbClearMaskUsedOfTxPduInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_CONSTVALUEUINT8UBCLEARMASKSTARTIDXOFTXPDUINFO                                           STD_OFF  /**< Deactivateable: 'Com_TxPduInfo.ConstValueUInt8UbClearMaskStartIdx' Reason: 'the optional indirection is deactivated because ConstValueUInt8UbClearMaskUsedOfTxPduInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_CONSTVALUEUINT8UBCLEARMASKUSEDOFTXPDUINFO                                               STD_OFF  /**< Deactivateable: 'Com_TxPduInfo.ConstValueUInt8UbClearMaskUsed' Reason: 'the optional indirection is deactivated because ConstValueUInt8UbClearMaskUsedOfTxPduInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_EXTERNALIDOFTXPDUINFO                                                                   STD_ON
#define COM_GWTIMEOUTINFOIDXOFTXPDUINFO                                                             STD_OFF  /**< Deactivateable: 'Com_TxPduInfo.GwTimeoutInfoIdx' Reason: 'the optional indirection is deactivated because GwTimeoutInfoUsedOfTxPduInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_GWTIMEOUTINFOUSEDOFTXPDUINFO                                                            STD_OFF  /**< Deactivateable: 'Com_TxPduInfo.GwTimeoutInfoUsed' Reason: 'the optional indirection is deactivated because GwTimeoutInfoUsedOfTxPduInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_IPDUGROUPINFOOFTXPDUINFOINDENDIDXOFTXPDUINFO                                            STD_ON
#define COM_IPDUGROUPINFOOFTXPDUINFOINDSTARTIDXOFTXPDUINFO                                          STD_ON
#define COM_IPDUGROUPINFOOFTXPDUINFOINDUSEDOFTXPDUINFO                                              STD_ON
#define COM_INVALIDHNDOFTXPDUINFO                                                                   STD_OFF  /**< Deactivateable: 'Com_TxPduInfo.InvalidHnd' Reason: 'the value of Com_InvalidHndOfTxPduInfo is always 'false' due to this, the array is deactivated.' */
#define COM_METADATALENGTHOFTXPDUINFO                                                               STD_ON
#define COM_PARTITIONSTXSTRUCTIDXOFTXPDUINFO                                                        STD_ON
#define COM_PDUWITHMETADATALENGTHOFTXPDUINFO                                                        STD_ON
#define COM_TXBUFFERENDIDXOFTXPDUINFO                                                               STD_ON
#define COM_TXBUFFERLENGTHOFTXPDUINFO                                                               STD_ON
#define COM_TXBUFFERMETADATAENDIDXOFTXPDUINFO                                                       STD_OFF  /**< Deactivateable: 'Com_TxPduInfo.TxBufferMetaDataEndIdx' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComMetaDataSupport] is configured to 'false'' */
#define COM_TXBUFFERMETADATALENGTHOFTXPDUINFO                                                       STD_OFF  /**< Deactivateable: 'Com_TxPduInfo.TxBufferMetaDataLength' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComMetaDataSupport] is configured to 'false'' */
#define COM_TXBUFFERMETADATASTARTIDXOFTXPDUINFO                                                     STD_OFF  /**< Deactivateable: 'Com_TxPduInfo.TxBufferMetaDataStartIdx' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComMetaDataSupport] is configured to 'false'' */
#define COM_TXBUFFERMETADATAUSEDOFTXPDUINFO                                                         STD_OFF  /**< Deactivateable: 'Com_TxPduInfo.TxBufferMetaDataUsed' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComMetaDataSupport] is configured to 'false'' */
#define COM_TXBUFFERSTARTIDXOFTXPDUINFO                                                             STD_ON
#define COM_TXBUFFERUSEDOFTXPDUINFO                                                                 STD_ON
#define COM_TXMODEINFOIDXOFTXPDUINFO                                                                STD_ON
#define COM_TXPDUCALLOUTFUNCPTRIDXOFTXPDUINFO                                                       STD_OFF  /**< Deactivateable: 'Com_TxPduInfo.TxPduCalloutFuncPtrIdx' Reason: 'the optional indirection is deactivated because TxPduCalloutFuncPtrUsedOfTxPduInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_TXPDUCALLOUTFUNCPTRUSEDOFTXPDUINFO                                                      STD_OFF  /**< Deactivateable: 'Com_TxPduInfo.TxPduCalloutFuncPtrUsed' Reason: 'the optional indirection is deactivated because TxPduCalloutFuncPtrUsedOfTxPduInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_TXPDUINITVALUEENDIDXOFTXPDUINFO                                                         STD_ON
#define COM_TXPDUINITVALUEMETADATAENDIDXOFTXPDUINFO                                                 STD_OFF  /**< Deactivateable: 'Com_TxPduInfo.TxPduInitValueMetaDataEndIdx' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComMetaDataSupport] is configured to 'false'' */
#define COM_TXPDUINITVALUEMETADATASTARTIDXOFTXPDUINFO                                               STD_OFF  /**< Deactivateable: 'Com_TxPduInfo.TxPduInitValueMetaDataStartIdx' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComMetaDataSupport] is configured to 'false'' */
#define COM_TXPDUINITVALUEMETADATAUSEDOFTXPDUINFO                                                   STD_OFF  /**< Deactivateable: 'Com_TxPduInfo.TxPduInitValueMetaDataUsed' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComMetaDataSupport] is configured to 'false'' */
#define COM_TXPDUINITVALUESTARTIDXOFTXPDUINFO                                                       STD_ON
#define COM_TXPDUINITVALUEUSEDOFTXPDUINFO                                                           STD_ON
#define COM_TXPDUTTCALLOUTFUNCPTRIDXOFTXPDUINFO                                                     STD_OFF  /**< Deactivateable: 'Com_TxPduInfo.TxPduTTCalloutFuncPtrIdx' Reason: 'the optional indirection is deactivated because TxPduTTCalloutFuncPtrUsedOfTxPduInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_TXPDUTTCALLOUTFUNCPTRUSEDOFTXPDUINFO                                                    STD_OFF  /**< Deactivateable: 'Com_TxPduInfo.TxPduTTCalloutFuncPtrUsed' Reason: 'the optional indirection is deactivated because TxPduTTCalloutFuncPtrUsedOfTxPduInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_TXSIGGRPINFOINDENDIDXOFTXPDUINFO                                                        STD_OFF  /**< Deactivateable: 'Com_TxPduInfo.TxSigGrpInfoIndEndIdx' Reason: 'the optional indirection is deactivated because TxSigGrpInfoIndUsedOfTxPduInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_TXSIGGRPINFOINDSTARTIDXOFTXPDUINFO                                                      STD_OFF  /**< Deactivateable: 'Com_TxPduInfo.TxSigGrpInfoIndStartIdx' Reason: 'the optional indirection is deactivated because TxSigGrpInfoIndUsedOfTxPduInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_TXSIGGRPINFOINDUSEDOFTXPDUINFO                                                          STD_OFF  /**< Deactivateable: 'Com_TxPduInfo.TxSigGrpInfoIndUsed' Reason: 'the optional indirection is deactivated because TxSigGrpInfoIndUsedOfTxPduInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_TXTOUTINFOIDXOFTXPDUINFO                                                                STD_OFF  /**< Deactivateable: 'Com_TxPduInfo.TxTOutInfoIdx' Reason: 'the optional indirection is deactivated because TxTOutInfoUsedOfTxPduInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_TXTOUTINFOUSEDOFTXPDUINFO                                                               STD_OFF  /**< Deactivateable: 'Com_TxPduInfo.TxTOutInfoUsed' Reason: 'the optional indirection is deactivated because TxTOutInfoUsedOfTxPduInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_TXTPINFOIDXOFTXPDUINFO                                                                  STD_OFF  /**< Deactivateable: 'Com_TxPduInfo.TxTpInfoIdx' Reason: '/ActiveEcuC/PduR/Com[0:PduRTransportProtocol] is configured to 'false'' */
#define COM_TXTPINFOUSEDOFTXPDUINFO                                                                 STD_OFF  /**< Deactivateable: 'Com_TxPduInfo.TxTpInfoUsed' Reason: '/ActiveEcuC/PduR/Com[0:PduRTransportProtocol] is configured to 'false'' */
#define COM_TYPEOFTXPDUINFO                                                                         STD_ON
#define COM_TXPDUINFOIND                                                                            STD_ON
#define COM_TXPDUINFOOFMAINFUNCTIONTXIND                                                            STD_ON
#define COM_TXPDUINITVALUE                                                                          STD_ON
#define COM_TXPDUTTCALLOUTFUNCPTR                                                                   STD_OFF  /**< Deactivateable: 'Com_TxPduTTCalloutFuncPtr' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_TXPROCESSINGISRLOCKCOUNTER                                                              STD_ON
#define COM_TXPROCESSINGISRLOCKTHRESHOLD                                                            STD_ON
#define COM_TXSDULENGTH                                                                             STD_ON
#define COM_TXSIGGRPINFO                                                                            STD_OFF  /**< Deactivateable: 'Com_TxSigGrpInfo' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define COM_ARRAYACCESSUSEDOFTXSIGGRPINFO                                                           STD_OFF  /**< Deactivateable: 'Com_TxSigGrpInfo.ArrayAccessUsed' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComEnableSignalGroupArrayApi] is configured to 'false'' */
#define COM_INVALIDHNDOFTXSIGGRPINFO                                                                STD_OFF  /**< Deactivateable: 'Com_TxSigGrpInfo.InvalidHnd' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_PDUOFFSETOFTXSIGGRPINFO                                                                 STD_OFF  /**< Deactivateable: 'Com_TxSigGrpInfo.PduOffset' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_SIGGROUPONCHANGEOFFSETOFTXSIGGRPINFO                                                    STD_OFF  /**< Deactivateable: 'Com_TxSigGrpInfo.SigGroupOnChangeOffset' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComEnableSignalGroupArrayApi] is configured to 'false'' */
#define COM_SIGGROUPONCHANGESTARTPOSITIONOFTXSIGGRPINFO                                             STD_OFF  /**< Deactivateable: 'Com_TxSigGrpInfo.SigGroupOnChangeStartPosition' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComEnableSignalGroupArrayApi] is configured to 'false'' */
#define COM_SIGGROUPONCHANGEWITHOUTREPOFFSETOFTXSIGGRPINFO                                          STD_OFF  /**< Deactivateable: 'Com_TxSigGrpInfo.SigGroupOnChangeWithoutRepOffset' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComEnableSignalGroupArrayApi] is configured to 'false'' */
#define COM_SIGGROUPONCHANGEWITHOUTREPSTARTPOSITIONOFTXSIGGRPINFO                                   STD_OFF  /**< Deactivateable: 'Com_TxSigGrpInfo.SigGroupOnChangeWithoutRepStartPosition' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComEnableSignalGroupArrayApi] is configured to 'false'' */
#define COM_SIGGRPARRAYFILTERINFOENDIDXOFTXSIGGRPINFO                                               STD_OFF  /**< Deactivateable: 'Com_TxSigGrpInfo.SigGrpArrayFilterInfoEndIdx' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComEnableSignalGroupArrayApi] is configured to 'false'' */
#define COM_SIGGRPARRAYFILTERINFOSTARTIDXOFTXSIGGRPINFO                                             STD_OFF  /**< Deactivateable: 'Com_TxSigGrpInfo.SigGrpArrayFilterInfoStartIdx' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComEnableSignalGroupArrayApi] is configured to 'false'' */
#define COM_SIGGRPARRAYFILTERINFOUSEDOFTXSIGGRPINFO                                                 STD_OFF  /**< Deactivateable: 'Com_TxSigGrpInfo.SigGrpArrayFilterInfoUsed' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComEnableSignalGroupArrayApi] is configured to 'false'' */
#define COM_TRANSFERPROPERTYOFTXSIGGRPINFO                                                          STD_OFF  /**< Deactivateable: 'Com_TxSigGrpInfo.TransferProperty' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_TXBUFFERENDIDXOFTXSIGGRPINFO                                                            STD_OFF  /**< Deactivateable: 'Com_TxSigGrpInfo.TxBufferEndIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_TXBUFFERLENGTHOFTXSIGGRPINFO                                                            STD_OFF  /**< Deactivateable: 'Com_TxSigGrpInfo.TxBufferLength' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_TXBUFFERSIGGRPINTXIPDUENDIDXOFTXSIGGRPINFO                                              STD_OFF  /**< Deactivateable: 'Com_TxSigGrpInfo.TxBufferSigGrpInTxIPDUEndIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_TXBUFFERSIGGRPINTXIPDULENGTHOFTXSIGGRPINFO                                              STD_OFF  /**< Deactivateable: 'Com_TxSigGrpInfo.TxBufferSigGrpInTxIPDULength' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_TXBUFFERSIGGRPINTXIPDUSTARTIDXOFTXSIGGRPINFO                                            STD_OFF  /**< Deactivateable: 'Com_TxSigGrpInfo.TxBufferSigGrpInTxIPDUStartIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_TXBUFFERSIGGRPINTXIPDUUSEDOFTXSIGGRPINFO                                                STD_OFF  /**< Deactivateable: 'Com_TxSigGrpInfo.TxBufferSigGrpInTxIPDUUsed' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_TXBUFFERSTARTIDXOFTXSIGGRPINFO                                                          STD_OFF  /**< Deactivateable: 'Com_TxSigGrpInfo.TxBufferStartIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_TXBUFFERUBIDXINTXBUFFERIDXOFTXSIGGRPINFO                                                STD_OFF  /**< Deactivateable: 'Com_TxSigGrpInfo.TxBufferUbIdxInTxBufferIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_TXBUFFERUBIDXINTXBUFFERUSEDOFTXSIGGRPINFO                                               STD_OFF  /**< Deactivateable: 'Com_TxSigGrpInfo.TxBufferUbIdxInTxBufferUsed' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_TXBUFFERUSEDOFTXSIGGRPINFO                                                              STD_OFF  /**< Deactivateable: 'Com_TxSigGrpInfo.TxBufferUsed' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_TXFILTERINITSTATEENDIDXOFTXSIGGRPINFO                                                   STD_OFF  /**< Deactivateable: 'Com_TxSigGrpInfo.TxFilterInitStateEndIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_TXFILTERINITSTATESTARTIDXOFTXSIGGRPINFO                                                 STD_OFF  /**< Deactivateable: 'Com_TxSigGrpInfo.TxFilterInitStateStartIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_TXFILTERINITSTATEUSEDOFTXSIGGRPINFO                                                     STD_OFF  /**< Deactivateable: 'Com_TxSigGrpInfo.TxFilterInitStateUsed' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_TXGRPSIGINFOINVVALUEINDENDIDXOFTXSIGGRPINFO                                             STD_OFF  /**< Deactivateable: 'Com_TxSigGrpInfo.TxGrpSigInfoInvValueIndEndIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_TXGRPSIGINFOINVVALUEINDSTARTIDXOFTXSIGGRPINFO                                           STD_OFF  /**< Deactivateable: 'Com_TxSigGrpInfo.TxGrpSigInfoInvValueIndStartIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_TXGRPSIGINFOINVVALUEINDUSEDOFTXSIGGRPINFO                                               STD_OFF  /**< Deactivateable: 'Com_TxSigGrpInfo.TxGrpSigInfoInvValueIndUsed' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_TXPDUINFOIDXOFTXSIGGRPINFO                                                              STD_OFF  /**< Deactivateable: 'Com_TxSigGrpInfo.TxPduInfoIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_TXSIGGRPMASKENDIDXOFTXSIGGRPINFO                                                        STD_OFF  /**< Deactivateable: 'Com_TxSigGrpInfo.TxSigGrpMaskEndIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_TXSIGGRPMASKLENGTHOFTXSIGGRPINFO                                                        STD_OFF  /**< Deactivateable: 'Com_TxSigGrpInfo.TxSigGrpMaskLength' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_TXSIGGRPMASKSTARTIDXOFTXSIGGRPINFO                                                      STD_OFF  /**< Deactivateable: 'Com_TxSigGrpInfo.TxSigGrpMaskStartIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_TXSIGGRPMASKUSEDOFTXSIGGRPINFO                                                          STD_OFF  /**< Deactivateable: 'Com_TxSigGrpInfo.TxSigGrpMaskUsed' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_TXSIGGRPONCHANGEMASKONCHANGEENDIDXOFTXSIGGRPINFO                                        STD_OFF  /**< Deactivateable: 'Com_TxSigGrpInfo.TxSigGrpOnChangeMaskOnChangeEndIdx' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComEnableSignalGroupArrayApi] is configured to 'false'' */
#define COM_TXSIGGRPONCHANGEMASKONCHANGELENGTHOFTXSIGGRPINFO                                        STD_OFF  /**< Deactivateable: 'Com_TxSigGrpInfo.TxSigGrpOnChangeMaskOnChangeLength' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComEnableSignalGroupArrayApi] is configured to 'false'' */
#define COM_TXSIGGRPONCHANGEMASKONCHANGESTARTIDXOFTXSIGGRPINFO                                      STD_OFF  /**< Deactivateable: 'Com_TxSigGrpInfo.TxSigGrpOnChangeMaskOnChangeStartIdx' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComEnableSignalGroupArrayApi] is configured to 'false'' */
#define COM_TXSIGGRPONCHANGEMASKONCHANGEUSEDOFTXSIGGRPINFO                                          STD_OFF  /**< Deactivateable: 'Com_TxSigGrpInfo.TxSigGrpOnChangeMaskOnChangeUsed' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComEnableSignalGroupArrayApi] is configured to 'false'' */
#define COM_TXSIGGRPONCHANGEMASKONCHANGEWITHOUTREPENDIDXOFTXSIGGRPINFO                              STD_OFF  /**< Deactivateable: 'Com_TxSigGrpInfo.TxSigGrpOnChangeMaskOnChangeWithoutRepEndIdx' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComEnableSignalGroupArrayApi] is configured to 'false'' */
#define COM_TXSIGGRPONCHANGEMASKONCHANGEWITHOUTREPLENGTHOFTXSIGGRPINFO                              STD_OFF  /**< Deactivateable: 'Com_TxSigGrpInfo.TxSigGrpOnChangeMaskOnChangeWithoutRepLength' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComEnableSignalGroupArrayApi] is configured to 'false'' */
#define COM_TXSIGGRPONCHANGEMASKONCHANGEWITHOUTREPSTARTIDXOFTXSIGGRPINFO                            STD_OFF  /**< Deactivateable: 'Com_TxSigGrpInfo.TxSigGrpOnChangeMaskOnChangeWithoutRepStartIdx' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComEnableSignalGroupArrayApi] is configured to 'false'' */
#define COM_TXSIGGRPONCHANGEMASKONCHANGEWITHOUTREPUSEDOFTXSIGGRPINFO                                STD_OFF  /**< Deactivateable: 'Com_TxSigGrpInfo.TxSigGrpOnChangeMaskOnChangeWithoutRepUsed' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComEnableSignalGroupArrayApi] is configured to 'false'' */
#define COM_UBMASKIDXOFTXSIGGRPINFO                                                                 STD_OFF  /**< Deactivateable: 'Com_TxSigGrpInfo.UbMaskIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_UBMASKOFTXSIGGRPINFO                                                                    STD_OFF  /**< Deactivateable: 'Com_TxSigGrpInfo.UbMask' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_UBMASKUSEDOFTXSIGGRPINFO                                                                STD_OFF  /**< Deactivateable: 'Com_TxSigGrpInfo.UbMaskUsed' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_TXSIGGRPINFOIND                                                                         STD_OFF  /**< Deactivateable: 'Com_TxSigGrpInfoInd' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_TXSIGGRPMASK                                                                            STD_OFF  /**< Deactivateable: 'Com_TxSigGrpMask' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_TXSIGGRPONCHANGEMASK                                                                    STD_OFF  /**< Deactivateable: 'Com_TxSigGrpOnChangeMask' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComEnableSignalGroupArrayApi] is configured to 'false'' */
#define COM_TXSIGINFO                                                                               STD_ON
#define COM_APPLTYPEOFTXSIGINFO                                                                     STD_ON
#define COM_BITLENGTHOFTXSIGINFO                                                                    STD_ON
#define COM_BITPOSITIONOFTXSIGINFO                                                                  STD_ON
#define COM_BUSACCOFTXSIGINFO                                                                       STD_ON
#define COM_BYTELENGTHOFTXSIGINFO                                                                   STD_ON
#define COM_BYTEPOSITIONOFTXSIGINFO                                                                 STD_ON
#define COM_CONSTVALUEARRAYBASEDINVVALUEENDIDXOFTXSIGINFO                                           STD_OFF  /**< Deactivateable: 'Com_TxSigInfo.ConstValueArrayBasedInvValueEndIdx' Reason: 'the optional indirection is deactivated because ConstValueArrayBasedInvValueUsedOfTxSigInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_CONSTVALUEARRAYBASEDINVVALUELENGTHOFTXSIGINFO                                           STD_OFF  /**< Deactivateable: 'Com_TxSigInfo.ConstValueArrayBasedInvValueLength' Reason: 'the optional indirection is deactivated because ConstValueArrayBasedInvValueUsedOfTxSigInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_CONSTVALUEARRAYBASEDINVVALUESTARTIDXOFTXSIGINFO                                         STD_OFF  /**< Deactivateable: 'Com_TxSigInfo.ConstValueArrayBasedInvValueStartIdx' Reason: 'the optional indirection is deactivated because ConstValueArrayBasedInvValueUsedOfTxSigInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_CONSTVALUEARRAYBASEDINVVALUEUSEDOFTXSIGINFO                                             STD_OFF  /**< Deactivateable: 'Com_TxSigInfo.ConstValueArrayBasedInvValueUsed' Reason: 'the optional indirection is deactivated because ConstValueArrayBasedInvValueUsedOfTxSigInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_DYNSIGNALOFTXSIGINFO                                                                    STD_ON
#define COM_FILTERINFOIDXOFTXSIGINFO                                                                STD_OFF  /**< Deactivateable: 'Com_TxSigInfo.FilterInfoIdx' Reason: 'the optional indirection is deactivated because FilterInfoUsedOfTxSigInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_FILTERINFOOFTXSIGINFO                                                                   STD_OFF  /**< Deactivateable: 'Com_TxSigInfo.FilterInfo' Reason: 'the optional indirection is deactivated because FilterInfoUsedOfTxSigInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_FILTERINFOUSEDOFTXSIGINFO                                                               STD_OFF  /**< Deactivateable: 'Com_TxSigInfo.FilterInfoUsed' Reason: 'the optional indirection is deactivated because FilterInfoUsedOfTxSigInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_FILTERINITVALUEIDXOFTXSIGINFO                                                           STD_OFF  /**< Deactivateable: 'Com_TxSigInfo.FilterInitValueIdx' Reason: 'the optional indirection is deactivated because FilterInitValueUsedOfTxSigInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_FILTERINITVALUEOFTXSIGINFO                                                              STD_OFF  /**< Deactivateable: 'Com_TxSigInfo.FilterInitValue' Reason: 'the optional indirection is deactivated because FilterInitValueUsedOfTxSigInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_FILTERINITVALUEUSEDOFTXSIGINFO                                                          STD_OFF  /**< Deactivateable: 'Com_TxSigInfo.FilterInitValueUsed' Reason: 'the optional indirection is deactivated because FilterInitValueUsedOfTxSigInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_INVVALUEIDXOFTXSIGINFO                                                                  STD_OFF  /**< Deactivateable: 'Com_TxSigInfo.InvValueIdx' Reason: 'the optional indirection is deactivated because InvValueUsedOfTxSigInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_INVVALUEOFTXSIGINFO                                                                     STD_OFF  /**< Deactivateable: 'Com_TxSigInfo.InvValue' Reason: 'the optional indirection is deactivated because InvValueUsedOfTxSigInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_INVVALUEUSEDOFTXSIGINFO                                                                 STD_OFF  /**< Deactivateable: 'Com_TxSigInfo.InvValueUsed' Reason: 'the optional indirection is deactivated because InvValueUsedOfTxSigInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_ONCHANGEIDXOFTXSIGINFO                                                                  STD_OFF  /**< Deactivateable: 'Com_TxSigInfo.OnChangeIdx' Reason: 'the optional indirection is deactivated because OnChangeUsedOfTxSigInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_ONCHANGEOFTXSIGINFO                                                                     STD_OFF  /**< Deactivateable: 'Com_TxSigInfo.OnChange' Reason: 'the optional indirection is deactivated because OnChangeUsedOfTxSigInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_ONCHANGEUSEDOFTXSIGINFO                                                                 STD_OFF  /**< Deactivateable: 'Com_TxSigInfo.OnChangeUsed' Reason: 'the optional indirection is deactivated because OnChangeUsedOfTxSigInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_STARTBYTEINPDUPOSITIONOFTXSIGINFO                                                       STD_ON
#define COM_TRIGGEREDOFTXSIGINFO                                                                    STD_OFF  /**< Deactivateable: 'Com_TxSigInfo.Triggered' Reason: 'the value of Com_TriggeredOfTxSigInfo is always 'false' due to this, the array is deactivated.' */
#define COM_TXACCESSINFOIDXOFTXSIGINFO                                                              STD_ON
#define COM_TXBUFFERENDIDXOFTXSIGINFO                                                               STD_ON
#define COM_TXBUFFERLENGTHOFTXSIGINFO                                                               STD_ON
#define COM_TXBUFFERSTARTIDXOFTXSIGINFO                                                             STD_ON
#define COM_TXBUFFERUBIDXINTXBUFFERIDXOFTXSIGINFO                                                   STD_OFF  /**< Deactivateable: 'Com_TxSigInfo.TxBufferUbIdxInTxBufferIdx' Reason: 'the optional indirection is deactivated because TxBufferUbIdxInTxBufferUsedOfTxSigInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_TXBUFFERUBIDXINTXBUFFERUSEDOFTXSIGINFO                                                  STD_OFF  /**< Deactivateable: 'Com_TxSigInfo.TxBufferUbIdxInTxBufferUsed' Reason: 'the optional indirection is deactivated because TxBufferUbIdxInTxBufferUsedOfTxSigInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_TXBUFFERUSEDOFTXSIGINFO                                                                 STD_ON
#define COM_TXFILTERINITSTATEIDXOFTXSIGINFO                                                         STD_OFF  /**< Deactivateable: 'Com_TxSigInfo.TxFilterInitStateIdx' Reason: 'the optional indirection is deactivated because TxFilterInitStateUsedOfTxSigInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_TXFILTERINITSTATEUSEDOFTXSIGINFO                                                        STD_OFF  /**< Deactivateable: 'Com_TxSigInfo.TxFilterInitStateUsed' Reason: 'the optional indirection is deactivated because TxFilterInitStateUsedOfTxSigInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_TXFILTERINITVALUEARRAYBASEDFILTERINITVALUEENDIDXOFTXSIGINFO                             STD_OFF  /**< Deactivateable: 'Com_TxSigInfo.TxFilterInitValueArrayBasedFilterInitValueEndIdx' Reason: 'the optional indirection is deactivated because TxFilterInitValueArrayBasedFilterInitValueUsedOfTxSigInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_TXFILTERINITVALUEARRAYBASEDFILTERINITVALUELENGTHOFTXSIGINFO                             STD_OFF  /**< Deactivateable: 'Com_TxSigInfo.TxFilterInitValueArrayBasedFilterInitValueLength' Reason: 'the optional indirection is deactivated because TxFilterInitValueArrayBasedFilterInitValueUsedOfTxSigInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_TXFILTERINITVALUEARRAYBASEDFILTERINITVALUESTARTIDXOFTXSIGINFO                           STD_OFF  /**< Deactivateable: 'Com_TxSigInfo.TxFilterInitValueArrayBasedFilterInitValueStartIdx' Reason: 'the optional indirection is deactivated because TxFilterInitValueArrayBasedFilterInitValueUsedOfTxSigInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_TXFILTERINITVALUEARRAYBASEDFILTERINITVALUEUSEDOFTXSIGINFO                               STD_OFF  /**< Deactivateable: 'Com_TxSigInfo.TxFilterInitValueArrayBasedFilterInitValueUsed' Reason: 'the optional indirection is deactivated because TxFilterInitValueArrayBasedFilterInitValueUsedOfTxSigInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_TXPDUINFOIDXOFTXSIGINFO                                                                 STD_ON
#define COM_UBMASKIDXOFTXSIGINFO                                                                    STD_OFF  /**< Deactivateable: 'Com_TxSigInfo.UbMaskIdx' Reason: 'the optional indirection is deactivated because UbMaskUsedOfTxSigInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_UBMASKOFTXSIGINFO                                                                       STD_OFF  /**< Deactivateable: 'Com_TxSigInfo.UbMask' Reason: 'the optional indirection is deactivated because UbMaskUsedOfTxSigInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_UBMASKUSEDOFTXSIGINFO                                                                   STD_OFF  /**< Deactivateable: 'Com_TxSigInfo.UbMaskUsed' Reason: 'the optional indirection is deactivated because UbMaskUsedOfTxSigInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_WITHOUTREPOFTXSIGINFO                                                                   STD_OFF  /**< Deactivateable: 'Com_TxSigInfo.WithoutRep' Reason: 'the value of Com_WithoutRepOfTxSigInfo is always 'false' due to this, the array is deactivated.' */
#define COM_TXSIGINFOFILTERINITVALUEIND                                                             STD_OFF  /**< Deactivateable: 'Com_TxSigInfoFilterInitValueInd' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_TXTOUTCNT                                                                               STD_OFF  /**< Deactivateable: 'Com_TxTOutCnt' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_TXTOUTINFO                                                                              STD_OFF  /**< Deactivateable: 'Com_TxTOutInfo' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define COM_CBKTXTOUTFUNCPTRINDENDIDXOFTXTOUTINFO                                                   STD_OFF  /**< Deactivateable: 'Com_TxTOutInfo.CbkTxTOutFuncPtrIndEndIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_CBKTXTOUTFUNCPTRINDSTARTIDXOFTXTOUTINFO                                                 STD_OFF  /**< Deactivateable: 'Com_TxTOutInfo.CbkTxTOutFuncPtrIndStartIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_CBKTXTOUTFUNCPTRINDUSEDOFTXTOUTINFO                                                     STD_OFF  /**< Deactivateable: 'Com_TxTOutInfo.CbkTxTOutFuncPtrIndUsed' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_FACTOROFTXTOUTINFO                                                                      STD_OFF  /**< Deactivateable: 'Com_TxTOutInfo.Factor' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_MODEOFTXTOUTINFO                                                                        STD_OFF  /**< Deactivateable: 'Com_TxTOutInfo.Mode' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_TXPDUINFOIDXOFTXTOUTINFO                                                                STD_OFF  /**< Deactivateable: 'Com_TxTOutInfo.TxPduInfoIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_TXTOUTINFOOFMAINFUNCTIONTXIND                                                           STD_OFF  /**< Deactivateable: 'Com_TxTOutInfoOfMainFunctionTxInd' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_TXTMPTPPDULENGTH                                                                        STD_OFF  /**< Deactivateable: 'Com_TxTmpTpPduLength' Reason: '/ActiveEcuC/PduR/Com[0:PduRTransportProtocol] is configured to 'false'' */
#define COM_TXTPCONNECTIONSTATE                                                                     STD_OFF  /**< Deactivateable: 'Com_TxTpConnectionState' Reason: '/ActiveEcuC/PduR/Com[0:PduRTransportProtocol] is configured to 'false'' */
#define COM_TXTPINFO                                                                                STD_OFF  /**< Deactivateable: 'Com_TxTpInfo' Reason: '/ActiveEcuC/PduR/Com[0:PduRTransportProtocol] is configured to 'false'' */
#define COM_BUFFERSIZEOFTXTPINFO                                                                    STD_OFF  /**< Deactivateable: 'Com_TxTpInfo.BufferSize' Reason: '/ActiveEcuC/PduR/Com[0:PduRTransportProtocol] is configured to 'false'' */
#define COM_DYNAMICINITIALLENGTHOFTXTPINFO                                                          STD_OFF  /**< Deactivateable: 'Com_TxTpInfo.DynamicInitialLength' Reason: '/ActiveEcuC/PduR/Com[0:PduRTransportProtocol] is configured to 'false'' */
#define COM_TXACCESSINFODYNSIGIDXOFTXTPINFO                                                         STD_OFF  /**< Deactivateable: 'Com_TxTpInfo.TxAccessInfoDynSigIdx' Reason: '/ActiveEcuC/PduR/Com[0:PduRTransportProtocol] is configured to 'false'' */
#define COM_TXACCESSINFODYNSIGUSEDOFTXTPINFO                                                        STD_OFF  /**< Deactivateable: 'Com_TxTpInfo.TxAccessInfoDynSigUsed' Reason: '/ActiveEcuC/PduR/Com[0:PduRTransportProtocol] is configured to 'false'' */
#define COM_TXBUFFERENDIDXOFTXTPINFO                                                                STD_OFF  /**< Deactivateable: 'Com_TxTpInfo.TxBufferEndIdx' Reason: '/ActiveEcuC/PduR/Com[0:PduRTransportProtocol] is configured to 'false'' */
#define COM_TXBUFFERLENGTHOFTXTPINFO                                                                STD_OFF  /**< Deactivateable: 'Com_TxTpInfo.TxBufferLength' Reason: '/ActiveEcuC/PduR/Com[0:PduRTransportProtocol] is configured to 'false'' */
#define COM_TXBUFFERSTARTIDXOFTXTPINFO                                                              STD_OFF  /**< Deactivateable: 'Com_TxTpInfo.TxBufferStartIdx' Reason: '/ActiveEcuC/PduR/Com[0:PduRTransportProtocol] is configured to 'false'' */
#define COM_TXBUFFERUSEDOFTXTPINFO                                                                  STD_OFF  /**< Deactivateable: 'Com_TxTpInfo.TxBufferUsed' Reason: '/ActiveEcuC/PduR/Com[0:PduRTransportProtocol] is configured to 'false'' */
#define COM_TXTPSDULENGTH                                                                           STD_OFF  /**< Deactivateable: 'Com_TxTpSduLength' Reason: '/ActiveEcuC/PduR/Com[0:PduRTransportProtocol] is configured to 'false'' */
#define COM_TXTPWRITTENBYTESCOUNTER                                                                 STD_OFF  /**< Deactivateable: 'Com_TxTpWrittenBytesCounter' Reason: '/ActiveEcuC/PduR/Com[0:PduRTransportProtocol] is configured to 'false'' */
#define COM_VCPRQUEUE                                                                               STD_OFF  /**< Deactivateable: 'Com_VCprQueue' Reason: 'No CrossPartitionRoutingQueues configured.' */
#define COM_CPRQUEUEBUFFERNUMBEROFBYTESREADIDXOFCPRQUEUE                                            STD_OFF  /**< Deactivateable: 'Com_VCprQueue.CprQueueBufferNumberOfBytesReadIdx' Reason: 'No CrossPartitionRoutingQueues configured.' */
#define COM_CPRQUEUEBUFFERPENDINGREADIDXOFCPRQUEUE                                                  STD_OFF  /**< Deactivateable: 'Com_VCprQueue.CprQueueBufferPendingReadIdx' Reason: 'No CrossPartitionRoutingQueues configured.' */
#define COM_CPRQUEUEBUFFERPENDINGWRITEIDXOFCPRQUEUE                                                 STD_OFF  /**< Deactivateable: 'Com_VCprQueue.CprQueueBufferPendingWriteIdx' Reason: 'No CrossPartitionRoutingQueues configured.' */
#define COM_CPRQUEUEBUFFERREADIDXOFCPRQUEUE                                                         STD_OFF  /**< Deactivateable: 'Com_VCprQueue.CprQueueBufferReadIdx' Reason: 'No CrossPartitionRoutingQueues configured.' */
#define COM_CPRQUEUEBUFFERWRITEIDXOFCPRQUEUE                                                        STD_OFF  /**< Deactivateable: 'Com_VCprQueue.CprQueueBufferWriteIdx' Reason: 'No CrossPartitionRoutingQueues configured.' */
#define COM_WAITINGFORCONFIRMATION                                                                  STD_OFF  /**< Deactivateable: 'Com_WaitingForConfirmation' Reason: 'This array is deactivated, because no Tx error notification functions are configured in all variants.' */
#define COM_PCCONFIG                                                                                STD_ON
#define COM_ALWAYSACTIVETXCOMIPDUSOFPCCONFIG                                                        STD_ON
#define COM_CONFIGIDOFPCCONFIG                                                                      STD_ON
#define COM_CONSTVALUEUINT8OFPCCONFIG                                                               STD_ON
#define COM_CURRENTTXMODEOFPCCONFIG                                                                 STD_ON
#define COM_CYCLETIMECNTOFPCCONFIG                                                                  STD_ON
#define COM_CYCLICSENDREQUESTOFPCCONFIG                                                             STD_ON
#define COM_FINALMAGICNUMBEROFPCCONFIG                                                              STD_OFF  /**< Deactivateable: 'Com_PCConfig.FinalMagicNumber' Reason: 'the module configuration does not support flashing of data.' */
#define COM_GATEWAYDESCRIPTIONPROCESSINGISRLOCKTHRESHOLDOFPCCONFIG                                  STD_OFF  /**< Deactivateable: 'Com_PCConfig.GatewayDescriptionProcessingISRLockThreshold' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComDescriptionGateway] is configured to 'false'' */
#define COM_GATEWAYPROCESSINGISRLOCKTHRESHOLDOFPCCONFIG                                             STD_OFF  /**< Deactivateable: 'Com_PCConfig.GatewayProcessingISRLockThreshold' Reason: 'Signal Gateway is not configured in all variants.' */
#define COM_HANDLERXPDUDEFERREDOFPCCONFIG                                                           STD_ON
#define COM_IPDUGROUPINFOOFPCCONFIG                                                                 STD_ON
#define COM_IPDUGROUPINFOOFRXPDUINFOINDOFPCCONFIG                                                   STD_ON
#define COM_IPDUGROUPINFOOFTXPDUINFOINDOFPCCONFIG                                                   STD_ON
#define COM_IPDUGROUPINFOTOSUBIPDUGROUPSINDOFPCCONFIG                                               STD_ON
#define COM_IPDUGROUPSTATEOFPCCONFIG                                                                STD_ON
#define COM_INITDATAHASHCODEOFPCCONFIG                                                              STD_OFF  /**< Deactivateable: 'Com_PCConfig.InitDataHashCode' Reason: 'the module configuration does not support flashing of data.' */
#define COM_INITIALIZEDOFPCCONFIG                                                                   STD_ON
#define COM_MAINFUNCTIONRXSTRUCTOFPCCONFIG                                                          STD_ON
#define COM_MAINFUNCTIONTXSTRUCTOFPCCONFIG                                                          STD_ON
#define COM_PARTITIONSALWAYSACTIVETXCOMIPDUSSTRUCTOFPCCONFIG                                        STD_ON
#define COM_PARTITIONSRXSTRUCTOFPCCONFIG                                                            STD_ON
#define COM_PARTITIONSTXSTRUCTOFPCCONFIG                                                            STD_ON
#define COM_PDUGRPCNTOFPCCONFIG                                                                     STD_ON
#define COM_RXACCESSINFOINDOFPCCONFIG                                                               STD_ON
#define COM_RXACCESSINFOOFPCCONFIG                                                                  STD_ON
#define COM_RXDEFPDUBUFFEROFPCCONFIG                                                                STD_ON
#define COM_RXIPDUGROUPISRLOCKCOUNTEROFPCCONFIG                                                     STD_ON
#define COM_RXIPDUGROUPISRLOCKTHRESHOLDOFPCCONFIG                                                   STD_ON
#define COM_RXMAINFUNCTIONPROCESSINGISRLOCKCOUNTEROFPCCONFIG                                        STD_ON
#define COM_RXMAINFUNCTIONPROCESSINGISRLOCKTHRESHOLDOFPCCONFIG                                      STD_ON
#define COM_RXPDUGRPACTIVEOFPCCONFIG                                                                STD_ON
#define COM_RXPDUINFOINDOFPCCONFIG                                                                  STD_ON
#define COM_RXPDUINFOOFMAINFUNCTIONRXINDOFPCCONFIG                                                  STD_ON
#define COM_RXPDUINFOOFPCCONFIG                                                                     STD_ON
#define COM_RXSIGBUFFERUINT8OFPCCONFIG                                                              STD_ON
#define COM_RXSIGINFOOFPCCONFIG                                                                     STD_ON
#define COM_SIZEOFALWAYSACTIVETXCOMIPDUSOFPCCONFIG                                                  STD_ON
#define COM_SIZEOFCONSTVALUEUINT8OFPCCONFIG                                                         STD_ON
#define COM_SIZEOFCURRENTTXMODEOFPCCONFIG                                                           STD_ON
#define COM_SIZEOFCYCLETIMECNTOFPCCONFIG                                                            STD_ON
#define COM_SIZEOFCYCLICSENDREQUESTOFPCCONFIG                                                       STD_ON
#define COM_SIZEOFHANDLERXPDUDEFERREDOFPCCONFIG                                                     STD_ON
#define COM_SIZEOFIPDUGROUPINFOOFPCCONFIG                                                           STD_ON
#define COM_SIZEOFIPDUGROUPINFOOFRXPDUINFOINDOFPCCONFIG                                             STD_ON
#define COM_SIZEOFIPDUGROUPINFOOFTXPDUINFOINDOFPCCONFIG                                             STD_ON
#define COM_SIZEOFIPDUGROUPINFOTOSUBIPDUGROUPSINDOFPCCONFIG                                         STD_ON
#define COM_SIZEOFIPDUGROUPSTATEOFPCCONFIG                                                          STD_ON
#define COM_SIZEOFMAINFUNCTIONRXSTRUCTOFPCCONFIG                                                    STD_ON
#define COM_SIZEOFMAINFUNCTIONTXSTRUCTOFPCCONFIG                                                    STD_ON
#define COM_SIZEOFPARTITIONSALWAYSACTIVETXCOMIPDUSSTRUCTOFPCCONFIG                                  STD_ON
#define COM_SIZEOFPARTITIONSRXSTRUCTOFPCCONFIG                                                      STD_ON
#define COM_SIZEOFPARTITIONSTXSTRUCTOFPCCONFIG                                                      STD_ON
#define COM_SIZEOFRXACCESSINFOINDOFPCCONFIG                                                         STD_ON
#define COM_SIZEOFRXACCESSINFOOFPCCONFIG                                                            STD_ON
#define COM_SIZEOFRXDEFPDUBUFFEROFPCCONFIG                                                          STD_ON
#define COM_SIZEOFRXIPDUGROUPISRLOCKCOUNTEROFPCCONFIG                                               STD_ON
#define COM_SIZEOFRXMAINFUNCTIONPROCESSINGISRLOCKCOUNTEROFPCCONFIG                                  STD_ON
#define COM_SIZEOFRXPDUGRPACTIVEOFPCCONFIG                                                          STD_ON
#define COM_SIZEOFRXPDUINFOINDOFPCCONFIG                                                            STD_ON
#define COM_SIZEOFRXPDUINFOOFMAINFUNCTIONRXINDOFPCCONFIG                                            STD_ON
#define COM_SIZEOFRXPDUINFOOFPCCONFIG                                                               STD_ON
#define COM_SIZEOFRXSIGBUFFERUINT8OFPCCONFIG                                                        STD_ON
#define COM_SIZEOFRXSIGINFOOFPCCONFIG                                                               STD_ON
#define COM_SIZEOFTRANSMITREQUESTOFPCCONFIG                                                         STD_ON
#define COM_SIZEOFTXACCESSINFOOFPCCONFIG                                                            STD_ON
#define COM_SIZEOFTXBUFFEROFPCCONFIG                                                                STD_ON
#define COM_SIZEOFTXCYCLICPDUOFMAINFUNCTIONTXINDOFPCCONFIG                                          STD_ON
#define COM_SIZEOFTXCYCLICPDUOFPCCONFIG                                                             STD_ON
#define COM_SIZEOFTXIPDUGROUPISRLOCKCOUNTEROFPCCONFIG                                               STD_ON
#define COM_SIZEOFTXMODEFALSEOFPCCONFIG                                                             STD_ON
#define COM_SIZEOFTXMODEINFOOFPCCONFIG                                                              STD_ON
#define COM_SIZEOFTXMODETRUEOFPCCONFIG                                                              STD_ON
#define COM_SIZEOFTXPDUGRPACTIVEOFPCCONFIG                                                          STD_ON
#define COM_SIZEOFTXPDUINFOINDOFPCCONFIG                                                            STD_ON
#define COM_SIZEOFTXPDUINFOOFMAINFUNCTIONTXINDOFPCCONFIG                                            STD_ON
#define COM_SIZEOFTXPDUINFOOFPCCONFIG                                                               STD_ON
#define COM_SIZEOFTXPDUINITVALUEOFPCCONFIG                                                          STD_ON
#define COM_SIZEOFTXPROCESSINGISRLOCKCOUNTEROFPCCONFIG                                              STD_ON
#define COM_SIZEOFTXSDULENGTHOFPCCONFIG                                                             STD_ON
#define COM_SIZEOFTXSIGINFOOFPCCONFIG                                                               STD_ON
#define COM_TRANSMITREQUESTOFPCCONFIG                                                               STD_ON
#define COM_TXACCESSINFOOFPCCONFIG                                                                  STD_ON
#define COM_TXBUFFEROFPCCONFIG                                                                      STD_ON
#define COM_TXCYCLICPDUOFMAINFUNCTIONTXINDOFPCCONFIG                                                STD_ON
#define COM_TXCYCLICPDUOFPCCONFIG                                                                   STD_ON
#define COM_TXIPDUGROUPISRLOCKCOUNTEROFPCCONFIG                                                     STD_ON
#define COM_TXIPDUGROUPISRLOCKTHRESHOLDOFPCCONFIG                                                   STD_ON
#define COM_TXMODEFALSEOFPCCONFIG                                                                   STD_ON
#define COM_TXMODEINFOOFPCCONFIG                                                                    STD_ON
#define COM_TXMODETRUEOFPCCONFIG                                                                    STD_ON
#define COM_TXPDUGRPACTIVEOFPCCONFIG                                                                STD_ON
#define COM_TXPDUINFOINDOFPCCONFIG                                                                  STD_ON
#define COM_TXPDUINFOOFMAINFUNCTIONTXINDOFPCCONFIG                                                  STD_ON
#define COM_TXPDUINFOOFPCCONFIG                                                                     STD_ON
#define COM_TXPDUINITVALUEOFPCCONFIG                                                                STD_ON
#define COM_TXPROCESSINGISRLOCKCOUNTEROFPCCONFIG                                                    STD_ON
#define COM_TXPROCESSINGISRLOCKTHRESHOLDOFPCCONFIG                                                  STD_ON
#define COM_TXSDULENGTHOFPCCONFIG                                                                   STD_ON
#define COM_TXSIGINFOOFPCCONFIG                                                                     STD_ON
/** 
  \}
*/ 

/** 
  \defgroup  ComPCMinNumericValueDefines  Com Min Numeric Value Defines (PRE_COMPILE)
  \brief  These defines are used to implement against the minimum value in numerical based data.
  \{
*/ 
#define COM_MIN_CYCLETIMECNT                                                                        0u
#define COM_MIN_HANDLERXPDUDEFERRED                                                                 0u
#define COM_MIN_RXDEFPDUBUFFER                                                                      0u
#define COM_MIN_RXIPDUGROUPISRLOCKCOUNTER                                                           0u
#define COM_MIN_RXMAINFUNCTIONPROCESSINGISRLOCKCOUNTER                                              0u
#define COM_MIN_RXSIGBUFFERUINT8                                                                    0u
#define COM_MIN_TXBUFFER                                                                            0u
#define COM_MIN_TXIPDUGROUPISRLOCKCOUNTER                                                           0u
#define COM_MIN_TXPROCESSINGISRLOCKCOUNTER                                                          0u
#define COM_MIN_TXSDULENGTH                                                                         0u
/** 
  \}
*/ 

/** 
  \defgroup  ComPCMaxNumericValueDefines  Com Max Numeric Value Defines (PRE_COMPILE)
  \brief  These defines are used to implement against the maximum value in numerical based data.
  \{
*/ 
#define COM_MAX_CYCLETIMECNT                                                                        255u
#define COM_MAX_HANDLERXPDUDEFERRED                                                                 65535u
#define COM_MAX_RXDEFPDUBUFFER                                                                      255u
#define COM_MAX_RXIPDUGROUPISRLOCKCOUNTER                                                           65535u
#define COM_MAX_RXMAINFUNCTIONPROCESSINGISRLOCKCOUNTER                                              65535u
#define COM_MAX_RXSIGBUFFERUINT8                                                                    255u
#define COM_MAX_TXBUFFER                                                                            255u
#define COM_MAX_TXIPDUGROUPISRLOCKCOUNTER                                                           65535u
#define COM_MAX_TXPROCESSINGISRLOCKCOUNTER                                                          65535u
#define COM_MAX_TXSDULENGTH                                                                         65535u
/** 
  \}
*/ 

/** 
  \defgroup  ComPCNoReferenceDefines  Com No Reference Defines (PRE_COMPILE)
  \brief  These defines are used to indicate unused indexes in data relations.
  \{
*/ 
#define COM_NO_IPDUGROUPINFOTOSUBIPDUGROUPSINDENDIDXOFIPDUGROUPINFO                                 255u
#define COM_NO_IPDUGROUPINFOTOSUBIPDUGROUPSINDSTARTIDXOFIPDUGROUPINFO                               255u
#define COM_NO_PARTITIONSRXSTRUCTIDXOFIPDUGROUPINFO                                                 255u
#define COM_NO_PARTITIONSTXSTRUCTIDXOFIPDUGROUPINFO                                                 255u
#define COM_NO_RXPDUINFOINDENDIDXOFIPDUGROUPINFO                                                    255u
#define COM_NO_RXPDUINFOINDSTARTIDXOFIPDUGROUPINFO                                                  255u
#define COM_NO_TXPDUINFOINDENDIDXOFIPDUGROUPINFO                                                    255u
#define COM_NO_TXPDUINFOINDSTARTIDXOFIPDUGROUPINFO                                                  255u
#define COM_NO_RXPDUINFOOFMAINFUNCTIONRXINDENDIDXOFMAINFUNCTIONRXSTRUCT                             255u
#define COM_NO_RXPDUINFOOFMAINFUNCTIONRXINDSTARTIDXOFMAINFUNCTIONRXSTRUCT                           255u
#define COM_NO_TXCYCLICPDUOFMAINFUNCTIONTXINDENDIDXOFMAINFUNCTIONTXSTRUCT                           255u
#define COM_NO_TXCYCLICPDUOFMAINFUNCTIONTXINDSTARTIDXOFMAINFUNCTIONTXSTRUCT                         255u
#define COM_NO_TXPDUINFOOFMAINFUNCTIONTXINDENDIDXOFMAINFUNCTIONTXSTRUCT                             255u
#define COM_NO_TXPDUINFOOFMAINFUNCTIONTXINDSTARTIDXOFMAINFUNCTIONTXSTRUCT                           255u
#define COM_NO_BUFFERIDXOFRXACCESSINFO                                                              255u
#define COM_NO_INITVALUEIDXOFRXACCESSINFO                                                           255u
#define COM_NO_HANDLERXPDUDEFERREDIDXOFRXPDUINFO                                                    255u
#define COM_NO_IPDUGROUPINFOOFRXPDUINFOINDENDIDXOFRXPDUINFO                                         255u
#define COM_NO_IPDUGROUPINFOOFRXPDUINFOINDSTARTIDXOFRXPDUINFO                                       255u
#define COM_NO_MAINFUNCTIONRXSTRUCTIDXOFRXPDUINFO                                                   255u
#define COM_NO_RXACCESSINFOINDENDIDXOFRXPDUINFO                                                     255u
#define COM_NO_RXACCESSINFOINDSTARTIDXOFRXPDUINFO                                                   255u
#define COM_NO_RXDEFPDUBUFFERENDIDXOFRXPDUINFO                                                      255u
#define COM_NO_RXDEFPDUBUFFERSTARTIDXOFRXPDUINFO                                                    255u
#define COM_NO_RXSIGINFOENDIDXOFRXPDUINFO                                                           255u
#define COM_NO_RXSIGINFOSTARTIDXOFRXPDUINFO                                                         255u
#define COM_NO_TXSIGINFOIDXOFTXACCESSINFO                                                           255u
#define COM_NO_IPDUGROUPINFOOFTXPDUINFOINDENDIDXOFTXPDUINFO                                         255u
#define COM_NO_IPDUGROUPINFOOFTXPDUINFOINDSTARTIDXOFTXPDUINFO                                       255u
#define COM_NO_TXBUFFERENDIDXOFTXPDUINFO                                                            255u
#define COM_NO_TXBUFFERSTARTIDXOFTXPDUINFO                                                          255u
#define COM_NO_TXPDUINITVALUEENDIDXOFTXPDUINFO                                                      255u
#define COM_NO_TXPDUINITVALUESTARTIDXOFTXPDUINFO                                                    255u
#define COM_NO_TXBUFFERENDIDXOFTXSIGINFO                                                            255u
#define COM_NO_TXBUFFERSTARTIDXOFTXSIGINFO                                                          255u
/** 
  \}
*/ 

/** 
  \defgroup  ComPCEnumExistsDefines  Com Enum Exists Defines (PRE_COMPILE)
  \brief  These defines can be used to deactivate enumeration based code sequences if the enumeration value does not exist in the configuration data.
  \{
*/ 
#define COM_EXISTS_ALWAYS_FILTERALGOOFFILTERINFO_FLOAT32                                            STD_OFF  /**< Deactivateable: 'Com_FilterInfo_Float32.FilterAlgo' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_NEVER_FILTERALGOOFFILTERINFO_FLOAT32                                             STD_OFF  /**< Deactivateable: 'Com_FilterInfo_Float32.FilterAlgo' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_MASKED_NEW_DIFFERS_MASKED_OLD_FILTERALGOOFFILTERINFO_FLOAT32                     STD_OFF  /**< Deactivateable: 'Com_FilterInfo_Float32.FilterAlgo' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_MASKED_NEW_DIFFERS_X_FILTERALGOOFFILTERINFO_FLOAT32                              STD_OFF  /**< Deactivateable: 'Com_FilterInfo_Float32.FilterAlgo' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_MASKED_NEW_EQUALS_X_FILTERALGOOFFILTERINFO_FLOAT32                               STD_OFF  /**< Deactivateable: 'Com_FilterInfo_Float32.FilterAlgo' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_NEW_IS_OUTSIDE_FILTERALGOOFFILTERINFO_FLOAT32                                    STD_OFF  /**< Deactivateable: 'Com_FilterInfo_Float32.FilterAlgo' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_NEW_IS_WITHIN_FILTERALGOOFFILTERINFO_FLOAT32                                     STD_OFF  /**< Deactivateable: 'Com_FilterInfo_Float32.FilterAlgo' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_NONE_FILTERALGOOFFILTERINFO_FLOAT32                                              STD_OFF  /**< Deactivateable: 'Com_FilterInfo_Float32.FilterAlgo' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_ALWAYS_FILTERALGOOFFILTERINFO_FLOAT64                                            STD_OFF  /**< Deactivateable: 'Com_FilterInfo_Float64.FilterAlgo' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_NEVER_FILTERALGOOFFILTERINFO_FLOAT64                                             STD_OFF  /**< Deactivateable: 'Com_FilterInfo_Float64.FilterAlgo' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_MASKED_NEW_DIFFERS_MASKED_OLD_FILTERALGOOFFILTERINFO_FLOAT64                     STD_OFF  /**< Deactivateable: 'Com_FilterInfo_Float64.FilterAlgo' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_MASKED_NEW_DIFFERS_X_FILTERALGOOFFILTERINFO_FLOAT64                              STD_OFF  /**< Deactivateable: 'Com_FilterInfo_Float64.FilterAlgo' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_MASKED_NEW_EQUALS_X_FILTERALGOOFFILTERINFO_FLOAT64                               STD_OFF  /**< Deactivateable: 'Com_FilterInfo_Float64.FilterAlgo' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_NEW_IS_OUTSIDE_FILTERALGOOFFILTERINFO_FLOAT64                                    STD_OFF  /**< Deactivateable: 'Com_FilterInfo_Float64.FilterAlgo' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_NEW_IS_WITHIN_FILTERALGOOFFILTERINFO_FLOAT64                                     STD_OFF  /**< Deactivateable: 'Com_FilterInfo_Float64.FilterAlgo' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_NONE_FILTERALGOOFFILTERINFO_FLOAT64                                              STD_OFF  /**< Deactivateable: 'Com_FilterInfo_Float64.FilterAlgo' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_ALWAYS_FILTERALGOOFFILTERINFO_SINT16                                             STD_OFF  /**< Deactivateable: 'Com_FilterInfo_SInt16.FilterAlgo' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_NEVER_FILTERALGOOFFILTERINFO_SINT16                                              STD_OFF  /**< Deactivateable: 'Com_FilterInfo_SInt16.FilterAlgo' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_MASKED_NEW_DIFFERS_MASKED_OLD_FILTERALGOOFFILTERINFO_SINT16                      STD_OFF  /**< Deactivateable: 'Com_FilterInfo_SInt16.FilterAlgo' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_MASKED_NEW_DIFFERS_X_FILTERALGOOFFILTERINFO_SINT16                               STD_OFF  /**< Deactivateable: 'Com_FilterInfo_SInt16.FilterAlgo' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_MASKED_NEW_EQUALS_X_FILTERALGOOFFILTERINFO_SINT16                                STD_OFF  /**< Deactivateable: 'Com_FilterInfo_SInt16.FilterAlgo' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_NEW_IS_OUTSIDE_FILTERALGOOFFILTERINFO_SINT16                                     STD_OFF  /**< Deactivateable: 'Com_FilterInfo_SInt16.FilterAlgo' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_NEW_IS_WITHIN_FILTERALGOOFFILTERINFO_SINT16                                      STD_OFF  /**< Deactivateable: 'Com_FilterInfo_SInt16.FilterAlgo' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_NONE_FILTERALGOOFFILTERINFO_SINT16                                               STD_OFF  /**< Deactivateable: 'Com_FilterInfo_SInt16.FilterAlgo' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_ALWAYS_FILTERALGOOFFILTERINFO_SINT32                                             STD_OFF  /**< Deactivateable: 'Com_FilterInfo_SInt32.FilterAlgo' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_NEVER_FILTERALGOOFFILTERINFO_SINT32                                              STD_OFF  /**< Deactivateable: 'Com_FilterInfo_SInt32.FilterAlgo' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_MASKED_NEW_DIFFERS_MASKED_OLD_FILTERALGOOFFILTERINFO_SINT32                      STD_OFF  /**< Deactivateable: 'Com_FilterInfo_SInt32.FilterAlgo' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_MASKED_NEW_DIFFERS_X_FILTERALGOOFFILTERINFO_SINT32                               STD_OFF  /**< Deactivateable: 'Com_FilterInfo_SInt32.FilterAlgo' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_MASKED_NEW_EQUALS_X_FILTERALGOOFFILTERINFO_SINT32                                STD_OFF  /**< Deactivateable: 'Com_FilterInfo_SInt32.FilterAlgo' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_NEW_IS_OUTSIDE_FILTERALGOOFFILTERINFO_SINT32                                     STD_OFF  /**< Deactivateable: 'Com_FilterInfo_SInt32.FilterAlgo' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_NEW_IS_WITHIN_FILTERALGOOFFILTERINFO_SINT32                                      STD_OFF  /**< Deactivateable: 'Com_FilterInfo_SInt32.FilterAlgo' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_NONE_FILTERALGOOFFILTERINFO_SINT32                                               STD_OFF  /**< Deactivateable: 'Com_FilterInfo_SInt32.FilterAlgo' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_ALWAYS_FILTERALGOOFFILTERINFO_SINT64                                             STD_OFF  /**< Deactivateable: 'Com_FilterInfo_SInt64.FilterAlgo' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_NEVER_FILTERALGOOFFILTERINFO_SINT64                                              STD_OFF  /**< Deactivateable: 'Com_FilterInfo_SInt64.FilterAlgo' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_MASKED_NEW_DIFFERS_MASKED_OLD_FILTERALGOOFFILTERINFO_SINT64                      STD_OFF  /**< Deactivateable: 'Com_FilterInfo_SInt64.FilterAlgo' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_MASKED_NEW_DIFFERS_X_FILTERALGOOFFILTERINFO_SINT64                               STD_OFF  /**< Deactivateable: 'Com_FilterInfo_SInt64.FilterAlgo' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_MASKED_NEW_EQUALS_X_FILTERALGOOFFILTERINFO_SINT64                                STD_OFF  /**< Deactivateable: 'Com_FilterInfo_SInt64.FilterAlgo' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_NEW_IS_OUTSIDE_FILTERALGOOFFILTERINFO_SINT64                                     STD_OFF  /**< Deactivateable: 'Com_FilterInfo_SInt64.FilterAlgo' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_NEW_IS_WITHIN_FILTERALGOOFFILTERINFO_SINT64                                      STD_OFF  /**< Deactivateable: 'Com_FilterInfo_SInt64.FilterAlgo' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_NONE_FILTERALGOOFFILTERINFO_SINT64                                               STD_OFF  /**< Deactivateable: 'Com_FilterInfo_SInt64.FilterAlgo' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_ALWAYS_FILTERALGOOFFILTERINFO_SINT8                                              STD_OFF  /**< Deactivateable: 'Com_FilterInfo_SInt8.FilterAlgo' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_NEVER_FILTERALGOOFFILTERINFO_SINT8                                               STD_OFF  /**< Deactivateable: 'Com_FilterInfo_SInt8.FilterAlgo' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_MASKED_NEW_DIFFERS_MASKED_OLD_FILTERALGOOFFILTERINFO_SINT8                       STD_OFF  /**< Deactivateable: 'Com_FilterInfo_SInt8.FilterAlgo' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_MASKED_NEW_DIFFERS_X_FILTERALGOOFFILTERINFO_SINT8                                STD_OFF  /**< Deactivateable: 'Com_FilterInfo_SInt8.FilterAlgo' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_MASKED_NEW_EQUALS_X_FILTERALGOOFFILTERINFO_SINT8                                 STD_OFF  /**< Deactivateable: 'Com_FilterInfo_SInt8.FilterAlgo' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_NEW_IS_OUTSIDE_FILTERALGOOFFILTERINFO_SINT8                                      STD_OFF  /**< Deactivateable: 'Com_FilterInfo_SInt8.FilterAlgo' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_NEW_IS_WITHIN_FILTERALGOOFFILTERINFO_SINT8                                       STD_OFF  /**< Deactivateable: 'Com_FilterInfo_SInt8.FilterAlgo' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_NONE_FILTERALGOOFFILTERINFO_SINT8                                                STD_OFF  /**< Deactivateable: 'Com_FilterInfo_SInt8.FilterAlgo' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_ALWAYS_FILTERALGOOFFILTERINFO_UINT16                                             STD_OFF  /**< Deactivateable: 'Com_FilterInfo_UInt16.FilterAlgo' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_NEVER_FILTERALGOOFFILTERINFO_UINT16                                              STD_OFF  /**< Deactivateable: 'Com_FilterInfo_UInt16.FilterAlgo' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_MASKED_NEW_DIFFERS_MASKED_OLD_FILTERALGOOFFILTERINFO_UINT16                      STD_OFF  /**< Deactivateable: 'Com_FilterInfo_UInt16.FilterAlgo' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_MASKED_NEW_DIFFERS_X_FILTERALGOOFFILTERINFO_UINT16                               STD_OFF  /**< Deactivateable: 'Com_FilterInfo_UInt16.FilterAlgo' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_MASKED_NEW_EQUALS_X_FILTERALGOOFFILTERINFO_UINT16                                STD_OFF  /**< Deactivateable: 'Com_FilterInfo_UInt16.FilterAlgo' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_NEW_IS_OUTSIDE_FILTERALGOOFFILTERINFO_UINT16                                     STD_OFF  /**< Deactivateable: 'Com_FilterInfo_UInt16.FilterAlgo' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_NEW_IS_WITHIN_FILTERALGOOFFILTERINFO_UINT16                                      STD_OFF  /**< Deactivateable: 'Com_FilterInfo_UInt16.FilterAlgo' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_NONE_FILTERALGOOFFILTERINFO_UINT16                                               STD_OFF  /**< Deactivateable: 'Com_FilterInfo_UInt16.FilterAlgo' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_ALWAYS_FILTERALGOOFFILTERINFO_UINT32                                             STD_OFF  /**< Deactivateable: 'Com_FilterInfo_UInt32.FilterAlgo' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_NEVER_FILTERALGOOFFILTERINFO_UINT32                                              STD_OFF  /**< Deactivateable: 'Com_FilterInfo_UInt32.FilterAlgo' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_MASKED_NEW_DIFFERS_MASKED_OLD_FILTERALGOOFFILTERINFO_UINT32                      STD_OFF  /**< Deactivateable: 'Com_FilterInfo_UInt32.FilterAlgo' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_MASKED_NEW_DIFFERS_X_FILTERALGOOFFILTERINFO_UINT32                               STD_OFF  /**< Deactivateable: 'Com_FilterInfo_UInt32.FilterAlgo' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_MASKED_NEW_EQUALS_X_FILTERALGOOFFILTERINFO_UINT32                                STD_OFF  /**< Deactivateable: 'Com_FilterInfo_UInt32.FilterAlgo' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_NEW_IS_OUTSIDE_FILTERALGOOFFILTERINFO_UINT32                                     STD_OFF  /**< Deactivateable: 'Com_FilterInfo_UInt32.FilterAlgo' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_NEW_IS_WITHIN_FILTERALGOOFFILTERINFO_UINT32                                      STD_OFF  /**< Deactivateable: 'Com_FilterInfo_UInt32.FilterAlgo' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_NONE_FILTERALGOOFFILTERINFO_UINT32                                               STD_OFF  /**< Deactivateable: 'Com_FilterInfo_UInt32.FilterAlgo' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_ALWAYS_FILTERALGOOFFILTERINFO_UINT64                                             STD_OFF  /**< Deactivateable: 'Com_FilterInfo_UInt64.FilterAlgo' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_NEVER_FILTERALGOOFFILTERINFO_UINT64                                              STD_OFF  /**< Deactivateable: 'Com_FilterInfo_UInt64.FilterAlgo' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_MASKED_NEW_DIFFERS_MASKED_OLD_FILTERALGOOFFILTERINFO_UINT64                      STD_OFF  /**< Deactivateable: 'Com_FilterInfo_UInt64.FilterAlgo' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_MASKED_NEW_DIFFERS_X_FILTERALGOOFFILTERINFO_UINT64                               STD_OFF  /**< Deactivateable: 'Com_FilterInfo_UInt64.FilterAlgo' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_MASKED_NEW_EQUALS_X_FILTERALGOOFFILTERINFO_UINT64                                STD_OFF  /**< Deactivateable: 'Com_FilterInfo_UInt64.FilterAlgo' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_NEW_IS_OUTSIDE_FILTERALGOOFFILTERINFO_UINT64                                     STD_OFF  /**< Deactivateable: 'Com_FilterInfo_UInt64.FilterAlgo' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_NEW_IS_WITHIN_FILTERALGOOFFILTERINFO_UINT64                                      STD_OFF  /**< Deactivateable: 'Com_FilterInfo_UInt64.FilterAlgo' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_NONE_FILTERALGOOFFILTERINFO_UINT64                                               STD_OFF  /**< Deactivateable: 'Com_FilterInfo_UInt64.FilterAlgo' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_ALWAYS_FILTERALGOOFFILTERINFO_UINT8                                              STD_OFF  /**< Deactivateable: 'Com_FilterInfo_UInt8.FilterAlgo' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_NEVER_FILTERALGOOFFILTERINFO_UINT8                                               STD_OFF  /**< Deactivateable: 'Com_FilterInfo_UInt8.FilterAlgo' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_MASKED_NEW_DIFFERS_MASKED_OLD_FILTERALGOOFFILTERINFO_UINT8                       STD_OFF  /**< Deactivateable: 'Com_FilterInfo_UInt8.FilterAlgo' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_MASKED_NEW_DIFFERS_X_FILTERALGOOFFILTERINFO_UINT8                                STD_OFF  /**< Deactivateable: 'Com_FilterInfo_UInt8.FilterAlgo' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_MASKED_NEW_EQUALS_X_FILTERALGOOFFILTERINFO_UINT8                                 STD_OFF  /**< Deactivateable: 'Com_FilterInfo_UInt8.FilterAlgo' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_NEW_IS_OUTSIDE_FILTERALGOOFFILTERINFO_UINT8                                      STD_OFF  /**< Deactivateable: 'Com_FilterInfo_UInt8.FilterAlgo' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_NEW_IS_WITHIN_FILTERALGOOFFILTERINFO_UINT8                                       STD_OFF  /**< Deactivateable: 'Com_FilterInfo_UInt8.FilterAlgo' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_NONE_FILTERALGOOFFILTERINFO_UINT8                                                STD_OFF  /**< Deactivateable: 'Com_FilterInfo_UInt8.FilterAlgo' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_ALWAYS_FILTERALGOOFFILTERINFO_UINT8_N                                            STD_OFF  /**< Deactivateable: 'Com_FilterInfo_UInt8_N.FilterAlgo' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_NEVER_FILTERALGOOFFILTERINFO_UINT8_N                                             STD_OFF  /**< Deactivateable: 'Com_FilterInfo_UInt8_N.FilterAlgo' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_MASKED_NEW_DIFFERS_MASKED_OLD_FILTERALGOOFFILTERINFO_UINT8_N                     STD_OFF  /**< Deactivateable: 'Com_FilterInfo_UInt8_N.FilterAlgo' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_MASKED_NEW_DIFFERS_X_FILTERALGOOFFILTERINFO_UINT8_N                              STD_OFF  /**< Deactivateable: 'Com_FilterInfo_UInt8_N.FilterAlgo' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_MASKED_NEW_EQUALS_X_FILTERALGOOFFILTERINFO_UINT8_N                               STD_OFF  /**< Deactivateable: 'Com_FilterInfo_UInt8_N.FilterAlgo' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_NEW_IS_OUTSIDE_FILTERALGOOFFILTERINFO_UINT8_N                                    STD_OFF  /**< Deactivateable: 'Com_FilterInfo_UInt8_N.FilterAlgo' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_NEW_IS_WITHIN_FILTERALGOOFFILTERINFO_UINT8_N                                     STD_OFF  /**< Deactivateable: 'Com_FilterInfo_UInt8_N.FilterAlgo' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_NONE_FILTERALGOOFFILTERINFO_UINT8_N                                              STD_OFF  /**< Deactivateable: 'Com_FilterInfo_UInt8_N.FilterAlgo' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_DIRECT_COPYTYPEOFGWDESCRIPTIONACCESSINFO                                         STD_OFF  /**< Deactivateable: 'Com_GwDescriptionAccessInfo.CopyType' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComDescriptionGateway] is configured to 'false'' */
#define COM_EXISTS_RIGHTSHIFT_COPYTYPEOFGWDESCRIPTIONACCESSINFO                                     STD_OFF  /**< Deactivateable: 'Com_GwDescriptionAccessInfo.CopyType' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComDescriptionGateway] is configured to 'false'' */
#define COM_EXISTS_LEFTSHIFT_COPYTYPEOFGWDESCRIPTIONACCESSINFO                                      STD_OFF  /**< Deactivateable: 'Com_GwDescriptionAccessInfo.CopyType' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComDescriptionGateway] is configured to 'false'' */
#define COM_EXISTS_BIG_ENDIAN_ENDIANNESSOFGWDESCRIPTIONACCESSINFO                                   STD_OFF  /**< Deactivateable: 'Com_GwDescriptionAccessInfo.Endianness' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComDescriptionGateway] is configured to 'false'' */
#define COM_EXISTS_LITTLE_ENDIAN_ENDIANNESSOFGWDESCRIPTIONACCESSINFO                                STD_OFF  /**< Deactivateable: 'Com_GwDescriptionAccessInfo.Endianness' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComDescriptionGateway] is configured to 'false'' */
#define COM_EXISTS_CONSTVALUEUINT8_RXUBMASKOFGWDESCRIPTIONACCESSINFO                                STD_OFF  /**< Deactivateable: 'Com_GwDescriptionAccessInfo.RxUbMask' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComDescriptionGateway] is configured to 'false'' */
#define COM_EXISTS_CONSTVALUEUINT16_RXUBMASKOFGWDESCRIPTIONACCESSINFO                               STD_OFF  /**< Deactivateable: 'Com_GwDescriptionAccessInfo.RxUbMask' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComDescriptionGateway] is configured to 'false'' */
#define COM_EXISTS_CONSTVALUEUINT32_RXUBMASKOFGWDESCRIPTIONACCESSINFO                               STD_OFF  /**< Deactivateable: 'Com_GwDescriptionAccessInfo.RxUbMask' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComDescriptionGateway] is configured to 'false'' */
#define COM_EXISTS_CONSTVALUEUINT64_RXUBMASKOFGWDESCRIPTIONACCESSINFO                               STD_OFF  /**< Deactivateable: 'Com_GwDescriptionAccessInfo.RxUbMask' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComDescriptionGateway] is configured to 'false'' */
#define COM_EXISTS_CONSTVALUESINT8_RXUBMASKOFGWDESCRIPTIONACCESSINFO                                STD_OFF  /**< Deactivateable: 'Com_GwDescriptionAccessInfo.RxUbMask' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComDescriptionGateway] is configured to 'false'' */
#define COM_EXISTS_CONSTVALUESINT16_RXUBMASKOFGWDESCRIPTIONACCESSINFO                               STD_OFF  /**< Deactivateable: 'Com_GwDescriptionAccessInfo.RxUbMask' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComDescriptionGateway] is configured to 'false'' */
#define COM_EXISTS_CONSTVALUESINT32_RXUBMASKOFGWDESCRIPTIONACCESSINFO                               STD_OFF  /**< Deactivateable: 'Com_GwDescriptionAccessInfo.RxUbMask' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComDescriptionGateway] is configured to 'false'' */
#define COM_EXISTS_CONSTVALUESINT64_RXUBMASKOFGWDESCRIPTIONACCESSINFO                               STD_OFF  /**< Deactivateable: 'Com_GwDescriptionAccessInfo.RxUbMask' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComDescriptionGateway] is configured to 'false'' */
#define COM_EXISTS_CONSTVALUEFLOAT32_RXUBMASKOFGWDESCRIPTIONACCESSINFO                              STD_OFF  /**< Deactivateable: 'Com_GwDescriptionAccessInfo.RxUbMask' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComDescriptionGateway] is configured to 'false'' */
#define COM_EXISTS_CONSTVALUEFLOAT64_RXUBMASKOFGWDESCRIPTIONACCESSINFO                              STD_OFF  /**< Deactivateable: 'Com_GwDescriptionAccessInfo.RxUbMask' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComDescriptionGateway] is configured to 'false'' */
#define COM_EXISTS_NO_RXUBMASKOFGWDESCRIPTIONACCESSINFO                                             STD_OFF  /**< Deactivateable: 'Com_GwDescriptionAccessInfo.RxUbMask' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComDescriptionGateway] is configured to 'false'' */
#define COM_EXISTS_CONSTVALUEUINT8_TXUBMASKOFGWDESCRIPTIONACCESSINFO                                STD_OFF  /**< Deactivateable: 'Com_GwDescriptionAccessInfo.TxUbMask' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComDescriptionGateway] is configured to 'false'' */
#define COM_EXISTS_CONSTVALUEUINT16_TXUBMASKOFGWDESCRIPTIONACCESSINFO                               STD_OFF  /**< Deactivateable: 'Com_GwDescriptionAccessInfo.TxUbMask' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComDescriptionGateway] is configured to 'false'' */
#define COM_EXISTS_CONSTVALUEUINT32_TXUBMASKOFGWDESCRIPTIONACCESSINFO                               STD_OFF  /**< Deactivateable: 'Com_GwDescriptionAccessInfo.TxUbMask' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComDescriptionGateway] is configured to 'false'' */
#define COM_EXISTS_CONSTVALUEUINT64_TXUBMASKOFGWDESCRIPTIONACCESSINFO                               STD_OFF  /**< Deactivateable: 'Com_GwDescriptionAccessInfo.TxUbMask' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComDescriptionGateway] is configured to 'false'' */
#define COM_EXISTS_CONSTVALUESINT8_TXUBMASKOFGWDESCRIPTIONACCESSINFO                                STD_OFF  /**< Deactivateable: 'Com_GwDescriptionAccessInfo.TxUbMask' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComDescriptionGateway] is configured to 'false'' */
#define COM_EXISTS_CONSTVALUESINT16_TXUBMASKOFGWDESCRIPTIONACCESSINFO                               STD_OFF  /**< Deactivateable: 'Com_GwDescriptionAccessInfo.TxUbMask' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComDescriptionGateway] is configured to 'false'' */
#define COM_EXISTS_CONSTVALUESINT32_TXUBMASKOFGWDESCRIPTIONACCESSINFO                               STD_OFF  /**< Deactivateable: 'Com_GwDescriptionAccessInfo.TxUbMask' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComDescriptionGateway] is configured to 'false'' */
#define COM_EXISTS_CONSTVALUESINT64_TXUBMASKOFGWDESCRIPTIONACCESSINFO                               STD_OFF  /**< Deactivateable: 'Com_GwDescriptionAccessInfo.TxUbMask' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComDescriptionGateway] is configured to 'false'' */
#define COM_EXISTS_CONSTVALUEFLOAT32_TXUBMASKOFGWDESCRIPTIONACCESSINFO                              STD_OFF  /**< Deactivateable: 'Com_GwDescriptionAccessInfo.TxUbMask' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComDescriptionGateway] is configured to 'false'' */
#define COM_EXISTS_CONSTVALUEFLOAT64_TXUBMASKOFGWDESCRIPTIONACCESSINFO                              STD_OFF  /**< Deactivateable: 'Com_GwDescriptionAccessInfo.TxUbMask' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComDescriptionGateway] is configured to 'false'' */
#define COM_EXISTS_NO_TXUBMASKOFGWDESCRIPTIONACCESSINFO                                             STD_OFF  /**< Deactivateable: 'Com_GwDescriptionAccessInfo.TxUbMask' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComDescriptionGateway] is configured to 'false'' */
#define COM_EXISTS_IMMEDIATE_PENDING_TYPEOFGWDESCRIPTIONACCESSINFO                                  STD_OFF  /**< Deactivateable: 'Com_GwDescriptionAccessInfo.Type' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComDescriptionGateway] is configured to 'false'' */
#define COM_EXISTS_IMMEDIATE_TRIGGERED_TYPEOFGWDESCRIPTIONACCESSINFO                                STD_OFF  /**< Deactivateable: 'Com_GwDescriptionAccessInfo.Type' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComDescriptionGateway] is configured to 'false'' */
#define COM_EXISTS_IMMEDIATE_TRIGGERED_ONCHANGE_TYPEOFGWDESCRIPTIONACCESSINFO                       STD_OFF  /**< Deactivateable: 'Com_GwDescriptionAccessInfo.Type' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComDescriptionGateway] is configured to 'false'' */
#define COM_EXISTS_IMMEDIATE_TRIGGERED_ONCHANGE_WITHOUTREP_TYPEOFGWDESCRIPTIONACCESSINFO            STD_OFF  /**< Deactivateable: 'Com_GwDescriptionAccessInfo.Type' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComDescriptionGateway] is configured to 'false'' */
#define COM_EXISTS_IMMEDIATE_TRIGGERED_WITHOUTREP_TYPEOFGWDESCRIPTIONACCESSINFO                     STD_OFF  /**< Deactivateable: 'Com_GwDescriptionAccessInfo.Type' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComDescriptionGateway] is configured to 'false'' */
#define COM_EXISTS_DEFERRED_PENDING_TYPEOFGWDESCRIPTIONACCESSINFO                                   STD_OFF  /**< Deactivateable: 'Com_GwDescriptionAccessInfo.Type' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComDescriptionGateway] is configured to 'false'' */
#define COM_EXISTS_DEFERRED_TRIGGERED_TYPEOFGWDESCRIPTIONACCESSINFO                                 STD_OFF  /**< Deactivateable: 'Com_GwDescriptionAccessInfo.Type' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComDescriptionGateway] is configured to 'false'' */
#define COM_EXISTS_DEFERRED_TRIGGERED_ONCHANGE_TYPEOFGWDESCRIPTIONACCESSINFO                        STD_OFF  /**< Deactivateable: 'Com_GwDescriptionAccessInfo.Type' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComDescriptionGateway] is configured to 'false'' */
#define COM_EXISTS_DEFERRED_TRIGGERED_ONCHANGE_WITHOUTREP_TYPEOFGWDESCRIPTIONACCESSINFO             STD_OFF  /**< Deactivateable: 'Com_GwDescriptionAccessInfo.Type' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComDescriptionGateway] is configured to 'false'' */
#define COM_EXISTS_DEFERRED_TRIGGERED_WITHOUTREP_TYPEOFGWDESCRIPTIONACCESSINFO                      STD_OFF  /**< Deactivateable: 'Com_GwDescriptionAccessInfo.Type' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComDescriptionGateway] is configured to 'false'' */
#define COM_EXISTS_UINT8_APPLTYPEOFRXACCESSINFO                                                     STD_ON
#define COM_EXISTS_SINT8_APPLTYPEOFRXACCESSINFO                                                     STD_OFF
#define COM_EXISTS_UINT16_APPLTYPEOFRXACCESSINFO                                                    STD_OFF
#define COM_EXISTS_SINT16_APPLTYPEOFRXACCESSINFO                                                    STD_OFF
#define COM_EXISTS_UINT32_APPLTYPEOFRXACCESSINFO                                                    STD_OFF
#define COM_EXISTS_SINT32_APPLTYPEOFRXACCESSINFO                                                    STD_OFF
#define COM_EXISTS_UINT64_APPLTYPEOFRXACCESSINFO                                                    STD_OFF
#define COM_EXISTS_SINT64_APPLTYPEOFRXACCESSINFO                                                    STD_OFF
#define COM_EXISTS_UINT8_N_APPLTYPEOFRXACCESSINFO                                                   STD_OFF
#define COM_EXISTS_UINT8_DYN_APPLTYPEOFRXACCESSINFO                                                 STD_OFF
#define COM_EXISTS_ZEROBIT_APPLTYPEOFRXACCESSINFO                                                   STD_OFF
#define COM_EXISTS_FLOAT32_APPLTYPEOFRXACCESSINFO                                                   STD_OFF
#define COM_EXISTS_FLOAT64_APPLTYPEOFRXACCESSINFO                                                   STD_OFF
#define COM_EXISTS_RXSIGBUFFERUINT8_BUFFEROFRXACCESSINFO                                            STD_ON
#define COM_EXISTS_RXSIGBUFFERUINT16_BUFFEROFRXACCESSINFO                                           STD_OFF
#define COM_EXISTS_RXSIGBUFFERUINT32_BUFFEROFRXACCESSINFO                                           STD_OFF
#define COM_EXISTS_RXSIGBUFFERUINT64_BUFFEROFRXACCESSINFO                                           STD_OFF
#define COM_EXISTS_RXSIGBUFFERZEROBIT_BUFFEROFRXACCESSINFO                                          STD_OFF
#define COM_EXISTS_RXSIGBUFFERSINT8_BUFFEROFRXACCESSINFO                                            STD_OFF
#define COM_EXISTS_RXSIGBUFFERSINT16_BUFFEROFRXACCESSINFO                                           STD_OFF
#define COM_EXISTS_RXSIGBUFFERSINT32_BUFFEROFRXACCESSINFO                                           STD_OFF
#define COM_EXISTS_RXSIGBUFFERSINT64_BUFFEROFRXACCESSINFO                                           STD_OFF
#define COM_EXISTS_RXSIGBUFFERFLOAT32_BUFFEROFRXACCESSINFO                                          STD_OFF
#define COM_EXISTS_RXSIGBUFFERFLOAT64_BUFFEROFRXACCESSINFO                                          STD_OFF
#define COM_EXISTS_NO_BUFFEROFRXACCESSINFO                                                          STD_OFF
#define COM_EXISTS_NBIT_BUSACCOFRXACCESSINFO                                                        STD_ON
#define COM_EXISTS_BYTE_BUSACCOFRXACCESSINFO                                                        STD_OFF
#define COM_EXISTS_NBYTE_BUSACCOFRXACCESSINFO                                                       STD_OFF
#define COM_EXISTS_NBYTE_SW_BUSACCOFRXACCESSINFO                                                    STD_OFF
#define COM_EXISTS_NBITNBYTE_BUSACCOFRXACCESSINFO                                                   STD_OFF
#define COM_EXISTS_NBITNBYTE_SW_BUSACCOFRXACCESSINFO                                                STD_OFF
#define COM_EXISTS_ARRAY_BASED_BUSACCOFRXACCESSINFO                                                 STD_OFF
#define COM_EXISTS_FILTERINFO_UINT8_FILTERINFOOFRXACCESSINFO                                        STD_OFF  /**< Deactivateable: 'Com_RxAccessInfo.FilterInfo' Reason: 'the optional indirection is deactivated because FilterInfoUsedOfRxAccessInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_EXISTS_FILTERINFO_SINT8_FILTERINFOOFRXACCESSINFO                                        STD_OFF  /**< Deactivateable: 'Com_RxAccessInfo.FilterInfo' Reason: 'the optional indirection is deactivated because FilterInfoUsedOfRxAccessInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_EXISTS_FILTERINFO_UINT16_FILTERINFOOFRXACCESSINFO                                       STD_OFF  /**< Deactivateable: 'Com_RxAccessInfo.FilterInfo' Reason: 'the optional indirection is deactivated because FilterInfoUsedOfRxAccessInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_EXISTS_FILTERINFO_SINT16_FILTERINFOOFRXACCESSINFO                                       STD_OFF  /**< Deactivateable: 'Com_RxAccessInfo.FilterInfo' Reason: 'the optional indirection is deactivated because FilterInfoUsedOfRxAccessInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_EXISTS_FILTERINFO_UINT32_FILTERINFOOFRXACCESSINFO                                       STD_OFF  /**< Deactivateable: 'Com_RxAccessInfo.FilterInfo' Reason: 'the optional indirection is deactivated because FilterInfoUsedOfRxAccessInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_EXISTS_FILTERINFO_SINT32_FILTERINFOOFRXACCESSINFO                                       STD_OFF  /**< Deactivateable: 'Com_RxAccessInfo.FilterInfo' Reason: 'the optional indirection is deactivated because FilterInfoUsedOfRxAccessInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_EXISTS_FILTERINFO_UINT64_FILTERINFOOFRXACCESSINFO                                       STD_OFF  /**< Deactivateable: 'Com_RxAccessInfo.FilterInfo' Reason: 'the optional indirection is deactivated because FilterInfoUsedOfRxAccessInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_EXISTS_FILTERINFO_SINT64_FILTERINFOOFRXACCESSINFO                                       STD_OFF  /**< Deactivateable: 'Com_RxAccessInfo.FilterInfo' Reason: 'the optional indirection is deactivated because FilterInfoUsedOfRxAccessInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_EXISTS_FILTERINFO_FLOAT32_FILTERINFOOFRXACCESSINFO                                      STD_OFF  /**< Deactivateable: 'Com_RxAccessInfo.FilterInfo' Reason: 'the optional indirection is deactivated because FilterInfoUsedOfRxAccessInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_EXISTS_FILTERINFO_FLOAT64_FILTERINFOOFRXACCESSINFO                                      STD_OFF  /**< Deactivateable: 'Com_RxAccessInfo.FilterInfo' Reason: 'the optional indirection is deactivated because FilterInfoUsedOfRxAccessInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_EXISTS_FILTERINFO_UINT8_N_FILTERINFOOFRXACCESSINFO                                      STD_OFF  /**< Deactivateable: 'Com_RxAccessInfo.FilterInfo' Reason: 'the optional indirection is deactivated because FilterInfoUsedOfRxAccessInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_EXISTS_NO_FILTERINFOOFRXACCESSINFO                                                      STD_OFF  /**< Deactivateable: 'Com_RxAccessInfo.FilterInfo' Reason: 'the optional indirection is deactivated because FilterInfoUsedOfRxAccessInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_EXISTS_CONSTVALUEUINT8_INITVALUEOFRXACCESSINFO                                          STD_ON
#define COM_EXISTS_CONSTVALUEUINT16_INITVALUEOFRXACCESSINFO                                         STD_OFF
#define COM_EXISTS_CONSTVALUEUINT32_INITVALUEOFRXACCESSINFO                                         STD_OFF
#define COM_EXISTS_CONSTVALUEUINT64_INITVALUEOFRXACCESSINFO                                         STD_OFF
#define COM_EXISTS_CONSTVALUESINT8_INITVALUEOFRXACCESSINFO                                          STD_OFF
#define COM_EXISTS_CONSTVALUESINT16_INITVALUEOFRXACCESSINFO                                         STD_OFF
#define COM_EXISTS_CONSTVALUESINT32_INITVALUEOFRXACCESSINFO                                         STD_OFF
#define COM_EXISTS_CONSTVALUESINT64_INITVALUEOFRXACCESSINFO                                         STD_OFF
#define COM_EXISTS_CONSTVALUEFLOAT32_INITVALUEOFRXACCESSINFO                                        STD_OFF
#define COM_EXISTS_CONSTVALUEFLOAT64_INITVALUEOFRXACCESSINFO                                        STD_OFF
#define COM_EXISTS_NO_INITVALUEOFRXACCESSINFO                                                       STD_OFF
#define COM_EXISTS_CONSTVALUEUINT8_INVVALUEOFRXACCESSINFO                                           STD_OFF  /**< Deactivateable: 'Com_RxAccessInfo.InvValue' Reason: 'the optional indirection is deactivated because InvValueUsedOfRxAccessInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_EXISTS_CONSTVALUEUINT16_INVVALUEOFRXACCESSINFO                                          STD_OFF  /**< Deactivateable: 'Com_RxAccessInfo.InvValue' Reason: 'the optional indirection is deactivated because InvValueUsedOfRxAccessInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_EXISTS_CONSTVALUEUINT32_INVVALUEOFRXACCESSINFO                                          STD_OFF  /**< Deactivateable: 'Com_RxAccessInfo.InvValue' Reason: 'the optional indirection is deactivated because InvValueUsedOfRxAccessInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_EXISTS_CONSTVALUEUINT64_INVVALUEOFRXACCESSINFO                                          STD_OFF  /**< Deactivateable: 'Com_RxAccessInfo.InvValue' Reason: 'the optional indirection is deactivated because InvValueUsedOfRxAccessInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_EXISTS_CONSTVALUESINT8_INVVALUEOFRXACCESSINFO                                           STD_OFF  /**< Deactivateable: 'Com_RxAccessInfo.InvValue' Reason: 'the optional indirection is deactivated because InvValueUsedOfRxAccessInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_EXISTS_CONSTVALUESINT16_INVVALUEOFRXACCESSINFO                                          STD_OFF  /**< Deactivateable: 'Com_RxAccessInfo.InvValue' Reason: 'the optional indirection is deactivated because InvValueUsedOfRxAccessInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_EXISTS_CONSTVALUESINT32_INVVALUEOFRXACCESSINFO                                          STD_OFF  /**< Deactivateable: 'Com_RxAccessInfo.InvValue' Reason: 'the optional indirection is deactivated because InvValueUsedOfRxAccessInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_EXISTS_CONSTVALUESINT64_INVVALUEOFRXACCESSINFO                                          STD_OFF  /**< Deactivateable: 'Com_RxAccessInfo.InvValue' Reason: 'the optional indirection is deactivated because InvValueUsedOfRxAccessInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_EXISTS_CONSTVALUEFLOAT32_INVVALUEOFRXACCESSINFO                                         STD_OFF  /**< Deactivateable: 'Com_RxAccessInfo.InvValue' Reason: 'the optional indirection is deactivated because InvValueUsedOfRxAccessInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_EXISTS_CONSTVALUEFLOAT64_INVVALUEOFRXACCESSINFO                                         STD_OFF  /**< Deactivateable: 'Com_RxAccessInfo.InvValue' Reason: 'the optional indirection is deactivated because InvValueUsedOfRxAccessInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_EXISTS_NO_INVVALUEOFRXACCESSINFO                                                        STD_OFF  /**< Deactivateable: 'Com_RxAccessInfo.InvValue' Reason: 'the optional indirection is deactivated because InvValueUsedOfRxAccessInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_EXISTS_MINPROCGWBUFFERUINT8_MINPROCGWBUFFEROFRXACCESSINFO                               STD_OFF  /**< Deactivateable: 'Com_RxAccessInfo.MinProcGwBuffer' Reason: 'the optional indirection is deactivated because MinProcGwBufferUsedOfRxAccessInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_EXISTS_MINPROCGWBUFFERUINT16_MINPROCGWBUFFEROFRXACCESSINFO                              STD_OFF  /**< Deactivateable: 'Com_RxAccessInfo.MinProcGwBuffer' Reason: 'the optional indirection is deactivated because MinProcGwBufferUsedOfRxAccessInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_EXISTS_MINPROCGWBUFFERUINT32_MINPROCGWBUFFEROFRXACCESSINFO                              STD_OFF  /**< Deactivateable: 'Com_RxAccessInfo.MinProcGwBuffer' Reason: 'the optional indirection is deactivated because MinProcGwBufferUsedOfRxAccessInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_EXISTS_MINPROCGWBUFFERUINT64_MINPROCGWBUFFEROFRXACCESSINFO                              STD_OFF  /**< Deactivateable: 'Com_RxAccessInfo.MinProcGwBuffer' Reason: 'the optional indirection is deactivated because MinProcGwBufferUsedOfRxAccessInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_EXISTS_MINPROCGWBUFFERZEROBIT_MINPROCGWBUFFEROFRXACCESSINFO                             STD_OFF  /**< Deactivateable: 'Com_RxAccessInfo.MinProcGwBuffer' Reason: 'the optional indirection is deactivated because MinProcGwBufferUsedOfRxAccessInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_EXISTS_MINPROCGWBUFFERSINT8_MINPROCGWBUFFEROFRXACCESSINFO                               STD_OFF  /**< Deactivateable: 'Com_RxAccessInfo.MinProcGwBuffer' Reason: 'the optional indirection is deactivated because MinProcGwBufferUsedOfRxAccessInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_EXISTS_MINPROCGWBUFFERSINT16_MINPROCGWBUFFEROFRXACCESSINFO                              STD_OFF  /**< Deactivateable: 'Com_RxAccessInfo.MinProcGwBuffer' Reason: 'the optional indirection is deactivated because MinProcGwBufferUsedOfRxAccessInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_EXISTS_MINPROCGWBUFFERSINT32_MINPROCGWBUFFEROFRXACCESSINFO                              STD_OFF  /**< Deactivateable: 'Com_RxAccessInfo.MinProcGwBuffer' Reason: 'the optional indirection is deactivated because MinProcGwBufferUsedOfRxAccessInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_EXISTS_MINPROCGWBUFFERSINT64_MINPROCGWBUFFEROFRXACCESSINFO                              STD_OFF  /**< Deactivateable: 'Com_RxAccessInfo.MinProcGwBuffer' Reason: 'the optional indirection is deactivated because MinProcGwBufferUsedOfRxAccessInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_EXISTS_MINPROCGWBUFFERFLOAT32_MINPROCGWBUFFEROFRXACCESSINFO                             STD_OFF  /**< Deactivateable: 'Com_RxAccessInfo.MinProcGwBuffer' Reason: 'the optional indirection is deactivated because MinProcGwBufferUsedOfRxAccessInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_EXISTS_MINPROCGWBUFFERFLOAT64_MINPROCGWBUFFEROFRXACCESSINFO                             STD_OFF  /**< Deactivateable: 'Com_RxAccessInfo.MinProcGwBuffer' Reason: 'the optional indirection is deactivated because MinProcGwBufferUsedOfRxAccessInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_EXISTS_NO_MINPROCGWBUFFEROFRXACCESSINFO                                                 STD_OFF  /**< Deactivateable: 'Com_RxAccessInfo.MinProcGwBuffer' Reason: 'the optional indirection is deactivated because MinProcGwBufferUsedOfRxAccessInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_EXISTS_RXSIGBUFFERUINT8_ROUTINGBUFFEROFRXACCESSINFO                                     STD_OFF  /**< Deactivateable: 'Com_RxAccessInfo.RoutingBuffer' Reason: 'The gateway is deactivated!' */
#define COM_EXISTS_RXSIGBUFFERUINT16_ROUTINGBUFFEROFRXACCESSINFO                                    STD_OFF  /**< Deactivateable: 'Com_RxAccessInfo.RoutingBuffer' Reason: 'The gateway is deactivated!' */
#define COM_EXISTS_RXSIGBUFFERUINT32_ROUTINGBUFFEROFRXACCESSINFO                                    STD_OFF  /**< Deactivateable: 'Com_RxAccessInfo.RoutingBuffer' Reason: 'The gateway is deactivated!' */
#define COM_EXISTS_RXSIGBUFFERUINT64_ROUTINGBUFFEROFRXACCESSINFO                                    STD_OFF  /**< Deactivateable: 'Com_RxAccessInfo.RoutingBuffer' Reason: 'The gateway is deactivated!' */
#define COM_EXISTS_RXSIGBUFFERZEROBIT_ROUTINGBUFFEROFRXACCESSINFO                                   STD_OFF  /**< Deactivateable: 'Com_RxAccessInfo.RoutingBuffer' Reason: 'The gateway is deactivated!' */
#define COM_EXISTS_RXSIGBUFFERSINT8_ROUTINGBUFFEROFRXACCESSINFO                                     STD_OFF  /**< Deactivateable: 'Com_RxAccessInfo.RoutingBuffer' Reason: 'The gateway is deactivated!' */
#define COM_EXISTS_RXSIGBUFFERSINT16_ROUTINGBUFFEROFRXACCESSINFO                                    STD_OFF  /**< Deactivateable: 'Com_RxAccessInfo.RoutingBuffer' Reason: 'The gateway is deactivated!' */
#define COM_EXISTS_RXSIGBUFFERSINT32_ROUTINGBUFFEROFRXACCESSINFO                                    STD_OFF  /**< Deactivateable: 'Com_RxAccessInfo.RoutingBuffer' Reason: 'The gateway is deactivated!' */
#define COM_EXISTS_RXSIGBUFFERSINT64_ROUTINGBUFFEROFRXACCESSINFO                                    STD_OFF  /**< Deactivateable: 'Com_RxAccessInfo.RoutingBuffer' Reason: 'The gateway is deactivated!' */
#define COM_EXISTS_RXSIGBUFFERFLOAT32_ROUTINGBUFFEROFRXACCESSINFO                                   STD_OFF  /**< Deactivateable: 'Com_RxAccessInfo.RoutingBuffer' Reason: 'The gateway is deactivated!' */
#define COM_EXISTS_RXSIGBUFFERFLOAT64_ROUTINGBUFFEROFRXACCESSINFO                                   STD_OFF  /**< Deactivateable: 'Com_RxAccessInfo.RoutingBuffer' Reason: 'The gateway is deactivated!' */
#define COM_EXISTS_NO_ROUTINGBUFFEROFRXACCESSINFO                                                   STD_OFF  /**< Deactivateable: 'Com_RxAccessInfo.RoutingBuffer' Reason: 'The gateway is deactivated!' */
#define COM_EXISTS_CONSTVALUEUINT8_RXDATATIMEOUTSUBSTITUTIONVALUEOFRXACCESSINFO                     STD_OFF  /**< Deactivateable: 'Com_RxAccessInfo.RxDataTimeoutSubstitutionValue' Reason: 'the optional indirection is deactivated because RxDataTimeoutSubstitutionValueUsedOfRxAccessInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_EXISTS_CONSTVALUEUINT16_RXDATATIMEOUTSUBSTITUTIONVALUEOFRXACCESSINFO                    STD_OFF  /**< Deactivateable: 'Com_RxAccessInfo.RxDataTimeoutSubstitutionValue' Reason: 'the optional indirection is deactivated because RxDataTimeoutSubstitutionValueUsedOfRxAccessInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_EXISTS_CONSTVALUEUINT32_RXDATATIMEOUTSUBSTITUTIONVALUEOFRXACCESSINFO                    STD_OFF  /**< Deactivateable: 'Com_RxAccessInfo.RxDataTimeoutSubstitutionValue' Reason: 'the optional indirection is deactivated because RxDataTimeoutSubstitutionValueUsedOfRxAccessInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_EXISTS_CONSTVALUEUINT64_RXDATATIMEOUTSUBSTITUTIONVALUEOFRXACCESSINFO                    STD_OFF  /**< Deactivateable: 'Com_RxAccessInfo.RxDataTimeoutSubstitutionValue' Reason: 'the optional indirection is deactivated because RxDataTimeoutSubstitutionValueUsedOfRxAccessInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_EXISTS_CONSTVALUESINT8_RXDATATIMEOUTSUBSTITUTIONVALUEOFRXACCESSINFO                     STD_OFF  /**< Deactivateable: 'Com_RxAccessInfo.RxDataTimeoutSubstitutionValue' Reason: 'the optional indirection is deactivated because RxDataTimeoutSubstitutionValueUsedOfRxAccessInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_EXISTS_CONSTVALUESINT16_RXDATATIMEOUTSUBSTITUTIONVALUEOFRXACCESSINFO                    STD_OFF  /**< Deactivateable: 'Com_RxAccessInfo.RxDataTimeoutSubstitutionValue' Reason: 'the optional indirection is deactivated because RxDataTimeoutSubstitutionValueUsedOfRxAccessInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_EXISTS_CONSTVALUESINT32_RXDATATIMEOUTSUBSTITUTIONVALUEOFRXACCESSINFO                    STD_OFF  /**< Deactivateable: 'Com_RxAccessInfo.RxDataTimeoutSubstitutionValue' Reason: 'the optional indirection is deactivated because RxDataTimeoutSubstitutionValueUsedOfRxAccessInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_EXISTS_CONSTVALUESINT64_RXDATATIMEOUTSUBSTITUTIONVALUEOFRXACCESSINFO                    STD_OFF  /**< Deactivateable: 'Com_RxAccessInfo.RxDataTimeoutSubstitutionValue' Reason: 'the optional indirection is deactivated because RxDataTimeoutSubstitutionValueUsedOfRxAccessInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_EXISTS_CONSTVALUEFLOAT32_RXDATATIMEOUTSUBSTITUTIONVALUEOFRXACCESSINFO                   STD_OFF  /**< Deactivateable: 'Com_RxAccessInfo.RxDataTimeoutSubstitutionValue' Reason: 'the optional indirection is deactivated because RxDataTimeoutSubstitutionValueUsedOfRxAccessInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_EXISTS_CONSTVALUEFLOAT64_RXDATATIMEOUTSUBSTITUTIONVALUEOFRXACCESSINFO                   STD_OFF  /**< Deactivateable: 'Com_RxAccessInfo.RxDataTimeoutSubstitutionValue' Reason: 'the optional indirection is deactivated because RxDataTimeoutSubstitutionValueUsedOfRxAccessInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_EXISTS_NO_RXDATATIMEOUTSUBSTITUTIONVALUEOFRXACCESSINFO                                  STD_OFF  /**< Deactivateable: 'Com_RxAccessInfo.RxDataTimeoutSubstitutionValue' Reason: 'the optional indirection is deactivated because RxDataTimeoutSubstitutionValueUsedOfRxAccessInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_EXISTS_RXSIGBUFFERUINT8_SHDBUFFEROFRXACCESSINFO                                         STD_OFF  /**< Deactivateable: 'Com_RxAccessInfo.ShdBuffer' Reason: 'the optional indirection is deactivated because ShdBufferUsedOfRxAccessInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_EXISTS_RXSIGBUFFERUINT16_SHDBUFFEROFRXACCESSINFO                                        STD_OFF  /**< Deactivateable: 'Com_RxAccessInfo.ShdBuffer' Reason: 'the optional indirection is deactivated because ShdBufferUsedOfRxAccessInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_EXISTS_RXSIGBUFFERUINT32_SHDBUFFEROFRXACCESSINFO                                        STD_OFF  /**< Deactivateable: 'Com_RxAccessInfo.ShdBuffer' Reason: 'the optional indirection is deactivated because ShdBufferUsedOfRxAccessInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_EXISTS_RXSIGBUFFERUINT64_SHDBUFFEROFRXACCESSINFO                                        STD_OFF  /**< Deactivateable: 'Com_RxAccessInfo.ShdBuffer' Reason: 'the optional indirection is deactivated because ShdBufferUsedOfRxAccessInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_EXISTS_RXSIGBUFFERZEROBIT_SHDBUFFEROFRXACCESSINFO                                       STD_OFF  /**< Deactivateable: 'Com_RxAccessInfo.ShdBuffer' Reason: 'the optional indirection is deactivated because ShdBufferUsedOfRxAccessInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_EXISTS_RXSIGBUFFERSINT8_SHDBUFFEROFRXACCESSINFO                                         STD_OFF  /**< Deactivateable: 'Com_RxAccessInfo.ShdBuffer' Reason: 'the optional indirection is deactivated because ShdBufferUsedOfRxAccessInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_EXISTS_RXSIGBUFFERSINT16_SHDBUFFEROFRXACCESSINFO                                        STD_OFF  /**< Deactivateable: 'Com_RxAccessInfo.ShdBuffer' Reason: 'the optional indirection is deactivated because ShdBufferUsedOfRxAccessInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_EXISTS_RXSIGBUFFERSINT32_SHDBUFFEROFRXACCESSINFO                                        STD_OFF  /**< Deactivateable: 'Com_RxAccessInfo.ShdBuffer' Reason: 'the optional indirection is deactivated because ShdBufferUsedOfRxAccessInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_EXISTS_RXSIGBUFFERSINT64_SHDBUFFEROFRXACCESSINFO                                        STD_OFF  /**< Deactivateable: 'Com_RxAccessInfo.ShdBuffer' Reason: 'the optional indirection is deactivated because ShdBufferUsedOfRxAccessInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_EXISTS_RXSIGBUFFERFLOAT32_SHDBUFFEROFRXACCESSINFO                                       STD_OFF  /**< Deactivateable: 'Com_RxAccessInfo.ShdBuffer' Reason: 'the optional indirection is deactivated because ShdBufferUsedOfRxAccessInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_EXISTS_RXSIGBUFFERFLOAT64_SHDBUFFEROFRXACCESSINFO                                       STD_OFF  /**< Deactivateable: 'Com_RxAccessInfo.ShdBuffer' Reason: 'the optional indirection is deactivated because ShdBufferUsedOfRxAccessInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_EXISTS_NO_SHDBUFFEROFRXACCESSINFO                                                       STD_OFF  /**< Deactivateable: 'Com_RxAccessInfo.ShdBuffer' Reason: 'the optional indirection is deactivated because ShdBufferUsedOfRxAccessInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_EXISTS_TMPRXSHDBUFFERUINT8_TMPBUFFEROFRXACCESSINFO                                      STD_OFF  /**< Deactivateable: 'Com_RxAccessInfo.TmpBuffer' Reason: 'the optional indirection is deactivated because TmpBufferUsedOfRxAccessInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_EXISTS_TMPRXSHDBUFFERUINT16_TMPBUFFEROFRXACCESSINFO                                     STD_OFF  /**< Deactivateable: 'Com_RxAccessInfo.TmpBuffer' Reason: 'the optional indirection is deactivated because TmpBufferUsedOfRxAccessInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_EXISTS_TMPRXSHDBUFFERUINT32_TMPBUFFEROFRXACCESSINFO                                     STD_OFF  /**< Deactivateable: 'Com_RxAccessInfo.TmpBuffer' Reason: 'the optional indirection is deactivated because TmpBufferUsedOfRxAccessInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_EXISTS_TMPRXSHDBUFFERUINT64_TMPBUFFEROFRXACCESSINFO                                     STD_OFF  /**< Deactivateable: 'Com_RxAccessInfo.TmpBuffer' Reason: 'the optional indirection is deactivated because TmpBufferUsedOfRxAccessInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_EXISTS_TMPRXSHDBUFFERSINT8_TMPBUFFEROFRXACCESSINFO                                      STD_OFF  /**< Deactivateable: 'Com_RxAccessInfo.TmpBuffer' Reason: 'the optional indirection is deactivated because TmpBufferUsedOfRxAccessInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_EXISTS_TMPRXSHDBUFFERSINT16_TMPBUFFEROFRXACCESSINFO                                     STD_OFF  /**< Deactivateable: 'Com_RxAccessInfo.TmpBuffer' Reason: 'the optional indirection is deactivated because TmpBufferUsedOfRxAccessInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_EXISTS_TMPRXSHDBUFFERSINT32_TMPBUFFEROFRXACCESSINFO                                     STD_OFF  /**< Deactivateable: 'Com_RxAccessInfo.TmpBuffer' Reason: 'the optional indirection is deactivated because TmpBufferUsedOfRxAccessInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_EXISTS_TMPRXSHDBUFFERSINT64_TMPBUFFEROFRXACCESSINFO                                     STD_OFF  /**< Deactivateable: 'Com_RxAccessInfo.TmpBuffer' Reason: 'the optional indirection is deactivated because TmpBufferUsedOfRxAccessInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_EXISTS_TMPRXSHDBUFFERFLOAT32_TMPBUFFEROFRXACCESSINFO                                    STD_OFF  /**< Deactivateable: 'Com_RxAccessInfo.TmpBuffer' Reason: 'the optional indirection is deactivated because TmpBufferUsedOfRxAccessInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_EXISTS_TMPRXSHDBUFFERFLOAT64_TMPBUFFEROFRXACCESSINFO                                    STD_OFF  /**< Deactivateable: 'Com_RxAccessInfo.TmpBuffer' Reason: 'the optional indirection is deactivated because TmpBufferUsedOfRxAccessInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_EXISTS_NO_TMPBUFFEROFRXACCESSINFO                                                       STD_OFF  /**< Deactivateable: 'Com_RxAccessInfo.TmpBuffer' Reason: 'the optional indirection is deactivated because TmpBufferUsedOfRxAccessInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_EXISTS_DEFERRED_SIGNALPROCESSINGOFRXPDUINFO                                             STD_ON
#define COM_EXISTS_IMMEDIATE_SIGNALPROCESSINGOFRXPDUINFO                                            STD_OFF
#define COM_EXISTS_NORMAL_TYPEOFRXPDUINFO                                                           STD_ON
#define COM_EXISTS_TP_TYPEOFRXPDUINFO                                                               STD_OFF
#define COM_EXISTS_DEFERRED_SIGNALPROCESSINGOFRXSIGGRPINFO                                          STD_OFF  /**< Deactivateable: 'Com_RxSigGrpInfo.SignalProcessing' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_IMMEDIATE_SIGNALPROCESSINGOFRXSIGGRPINFO                                         STD_OFF  /**< Deactivateable: 'Com_RxSigGrpInfo.SignalProcessing' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_CONSTVALUEUINT8_UBMASKOFRXSIGGRPINFO                                             STD_OFF  /**< Deactivateable: 'Com_RxSigGrpInfo.UbMask' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_CONSTVALUEUINT16_UBMASKOFRXSIGGRPINFO                                            STD_OFF  /**< Deactivateable: 'Com_RxSigGrpInfo.UbMask' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_CONSTVALUEUINT32_UBMASKOFRXSIGGRPINFO                                            STD_OFF  /**< Deactivateable: 'Com_RxSigGrpInfo.UbMask' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_CONSTVALUEUINT64_UBMASKOFRXSIGGRPINFO                                            STD_OFF  /**< Deactivateable: 'Com_RxSigGrpInfo.UbMask' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_CONSTVALUESINT8_UBMASKOFRXSIGGRPINFO                                             STD_OFF  /**< Deactivateable: 'Com_RxSigGrpInfo.UbMask' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_CONSTVALUESINT16_UBMASKOFRXSIGGRPINFO                                            STD_OFF  /**< Deactivateable: 'Com_RxSigGrpInfo.UbMask' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_CONSTVALUESINT32_UBMASKOFRXSIGGRPINFO                                            STD_OFF  /**< Deactivateable: 'Com_RxSigGrpInfo.UbMask' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_CONSTVALUESINT64_UBMASKOFRXSIGGRPINFO                                            STD_OFF  /**< Deactivateable: 'Com_RxSigGrpInfo.UbMask' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_CONSTVALUEFLOAT32_UBMASKOFRXSIGGRPINFO                                           STD_OFF  /**< Deactivateable: 'Com_RxSigGrpInfo.UbMask' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_CONSTVALUEFLOAT64_UBMASKOFRXSIGGRPINFO                                           STD_OFF  /**< Deactivateable: 'Com_RxSigGrpInfo.UbMask' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_NO_UBMASKOFRXSIGGRPINFO                                                          STD_OFF  /**< Deactivateable: 'Com_RxSigGrpInfo.UbMask' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO                                             STD_ON
#define COM_EXISTS_IMMEDIATE_SIGNALPROCESSINGOFRXSIGINFO                                            STD_OFF
#define COM_EXISTS_CONSTVALUEUINT8_UBMASKOFRXSIGINFO                                                STD_OFF  /**< Deactivateable: 'Com_RxSigInfo.UbMask' Reason: 'the optional indirection is deactivated because UbMaskUsedOfRxSigInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_EXISTS_CONSTVALUEUINT16_UBMASKOFRXSIGINFO                                               STD_OFF  /**< Deactivateable: 'Com_RxSigInfo.UbMask' Reason: 'the optional indirection is deactivated because UbMaskUsedOfRxSigInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_EXISTS_CONSTVALUEUINT32_UBMASKOFRXSIGINFO                                               STD_OFF  /**< Deactivateable: 'Com_RxSigInfo.UbMask' Reason: 'the optional indirection is deactivated because UbMaskUsedOfRxSigInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_EXISTS_CONSTVALUEUINT64_UBMASKOFRXSIGINFO                                               STD_OFF  /**< Deactivateable: 'Com_RxSigInfo.UbMask' Reason: 'the optional indirection is deactivated because UbMaskUsedOfRxSigInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_EXISTS_CONSTVALUESINT8_UBMASKOFRXSIGINFO                                                STD_OFF  /**< Deactivateable: 'Com_RxSigInfo.UbMask' Reason: 'the optional indirection is deactivated because UbMaskUsedOfRxSigInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_EXISTS_CONSTVALUESINT16_UBMASKOFRXSIGINFO                                               STD_OFF  /**< Deactivateable: 'Com_RxSigInfo.UbMask' Reason: 'the optional indirection is deactivated because UbMaskUsedOfRxSigInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_EXISTS_CONSTVALUESINT32_UBMASKOFRXSIGINFO                                               STD_OFF  /**< Deactivateable: 'Com_RxSigInfo.UbMask' Reason: 'the optional indirection is deactivated because UbMaskUsedOfRxSigInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_EXISTS_CONSTVALUESINT64_UBMASKOFRXSIGINFO                                               STD_OFF  /**< Deactivateable: 'Com_RxSigInfo.UbMask' Reason: 'the optional indirection is deactivated because UbMaskUsedOfRxSigInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_EXISTS_CONSTVALUEFLOAT32_UBMASKOFRXSIGINFO                                              STD_OFF  /**< Deactivateable: 'Com_RxSigInfo.UbMask' Reason: 'the optional indirection is deactivated because UbMaskUsedOfRxSigInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_EXISTS_CONSTVALUEFLOAT64_UBMASKOFRXSIGINFO                                              STD_OFF  /**< Deactivateable: 'Com_RxSigInfo.UbMask' Reason: 'the optional indirection is deactivated because UbMaskUsedOfRxSigInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_EXISTS_NO_UBMASKOFRXSIGINFO                                                             STD_OFF  /**< Deactivateable: 'Com_RxSigInfo.UbMask' Reason: 'the optional indirection is deactivated because UbMaskUsedOfRxSigInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_EXISTS_ALWAYS_FILTERALGOOFSIGGRPARRAYFILTERINFO                                         STD_OFF  /**< Deactivateable: 'Com_SigGrpArrayFilterInfo.FilterAlgo' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComEnableSignalGroupArrayApi] is configured to 'false'' */
#define COM_EXISTS_NEVER_FILTERALGOOFSIGGRPARRAYFILTERINFO                                          STD_OFF  /**< Deactivateable: 'Com_SigGrpArrayFilterInfo.FilterAlgo' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComEnableSignalGroupArrayApi] is configured to 'false'' */
#define COM_EXISTS_MASKED_NEW_DIFFERS_MASKED_OLD_FILTERALGOOFSIGGRPARRAYFILTERINFO                  STD_OFF  /**< Deactivateable: 'Com_SigGrpArrayFilterInfo.FilterAlgo' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComEnableSignalGroupArrayApi] is configured to 'false'' */
#define COM_EXISTS_MASKED_NEW_DIFFERS_X_FILTERALGOOFSIGGRPARRAYFILTERINFO                           STD_OFF  /**< Deactivateable: 'Com_SigGrpArrayFilterInfo.FilterAlgo' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComEnableSignalGroupArrayApi] is configured to 'false'' */
#define COM_EXISTS_MASKED_NEW_EQUALS_X_FILTERALGOOFSIGGRPARRAYFILTERINFO                            STD_OFF  /**< Deactivateable: 'Com_SigGrpArrayFilterInfo.FilterAlgo' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComEnableSignalGroupArrayApi] is configured to 'false'' */
#define COM_EXISTS_NEW_IS_OUTSIDE_FILTERALGOOFSIGGRPARRAYFILTERINFO                                 STD_OFF  /**< Deactivateable: 'Com_SigGrpArrayFilterInfo.FilterAlgo' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComEnableSignalGroupArrayApi] is configured to 'false'' */
#define COM_EXISTS_NEW_IS_WITHIN_FILTERALGOOFSIGGRPARRAYFILTERINFO                                  STD_OFF  /**< Deactivateable: 'Com_SigGrpArrayFilterInfo.FilterAlgo' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComEnableSignalGroupArrayApi] is configured to 'false'' */
#define COM_EXISTS_NONE_FILTERALGOOFSIGGRPARRAYFILTERINFO                                           STD_OFF  /**< Deactivateable: 'Com_SigGrpArrayFilterInfo.FilterAlgo' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComEnableSignalGroupArrayApi] is configured to 'false'' */
#define COM_EXISTS_UINT8_APPLTYPEOFTXGRPSIGINFO                                                     STD_OFF  /**< Deactivateable: 'Com_TxGrpSigInfo.ApplType' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_SINT8_APPLTYPEOFTXGRPSIGINFO                                                     STD_OFF  /**< Deactivateable: 'Com_TxGrpSigInfo.ApplType' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_UINT16_APPLTYPEOFTXGRPSIGINFO                                                    STD_OFF  /**< Deactivateable: 'Com_TxGrpSigInfo.ApplType' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_SINT16_APPLTYPEOFTXGRPSIGINFO                                                    STD_OFF  /**< Deactivateable: 'Com_TxGrpSigInfo.ApplType' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_UINT32_APPLTYPEOFTXGRPSIGINFO                                                    STD_OFF  /**< Deactivateable: 'Com_TxGrpSigInfo.ApplType' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_SINT32_APPLTYPEOFTXGRPSIGINFO                                                    STD_OFF  /**< Deactivateable: 'Com_TxGrpSigInfo.ApplType' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_UINT64_APPLTYPEOFTXGRPSIGINFO                                                    STD_OFF  /**< Deactivateable: 'Com_TxGrpSigInfo.ApplType' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_SINT64_APPLTYPEOFTXGRPSIGINFO                                                    STD_OFF  /**< Deactivateable: 'Com_TxGrpSigInfo.ApplType' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_UINT8_N_APPLTYPEOFTXGRPSIGINFO                                                   STD_OFF  /**< Deactivateable: 'Com_TxGrpSigInfo.ApplType' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_UINT8_DYN_APPLTYPEOFTXGRPSIGINFO                                                 STD_OFF  /**< Deactivateable: 'Com_TxGrpSigInfo.ApplType' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_ZEROBIT_APPLTYPEOFTXGRPSIGINFO                                                   STD_OFF  /**< Deactivateable: 'Com_TxGrpSigInfo.ApplType' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_FLOAT32_APPLTYPEOFTXGRPSIGINFO                                                   STD_OFF  /**< Deactivateable: 'Com_TxGrpSigInfo.ApplType' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_FLOAT64_APPLTYPEOFTXGRPSIGINFO                                                   STD_OFF  /**< Deactivateable: 'Com_TxGrpSigInfo.ApplType' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_NBIT_BUSACCOFTXGRPSIGINFO                                                        STD_OFF  /**< Deactivateable: 'Com_TxGrpSigInfo.BusAcc' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_BYTE_BUSACCOFTXGRPSIGINFO                                                        STD_OFF  /**< Deactivateable: 'Com_TxGrpSigInfo.BusAcc' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_NBYTE_BUSACCOFTXGRPSIGINFO                                                       STD_OFF  /**< Deactivateable: 'Com_TxGrpSigInfo.BusAcc' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_NBYTE_SW_BUSACCOFTXGRPSIGINFO                                                    STD_OFF  /**< Deactivateable: 'Com_TxGrpSigInfo.BusAcc' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_NBITNBYTE_BUSACCOFTXGRPSIGINFO                                                   STD_OFF  /**< Deactivateable: 'Com_TxGrpSigInfo.BusAcc' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_NBITNBYTE_SW_BUSACCOFTXGRPSIGINFO                                                STD_OFF  /**< Deactivateable: 'Com_TxGrpSigInfo.BusAcc' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_ARRAY_BASED_BUSACCOFTXGRPSIGINFO                                                 STD_OFF  /**< Deactivateable: 'Com_TxGrpSigInfo.BusAcc' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_FILTERINFO_UINT8_FILTERINFOOFTXGRPSIGINFO                                        STD_OFF  /**< Deactivateable: 'Com_TxGrpSigInfo.FilterInfo' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_FILTERINFO_SINT8_FILTERINFOOFTXGRPSIGINFO                                        STD_OFF  /**< Deactivateable: 'Com_TxGrpSigInfo.FilterInfo' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_FILTERINFO_UINT16_FILTERINFOOFTXGRPSIGINFO                                       STD_OFF  /**< Deactivateable: 'Com_TxGrpSigInfo.FilterInfo' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_FILTERINFO_SINT16_FILTERINFOOFTXGRPSIGINFO                                       STD_OFF  /**< Deactivateable: 'Com_TxGrpSigInfo.FilterInfo' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_FILTERINFO_UINT32_FILTERINFOOFTXGRPSIGINFO                                       STD_OFF  /**< Deactivateable: 'Com_TxGrpSigInfo.FilterInfo' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_FILTERINFO_SINT32_FILTERINFOOFTXGRPSIGINFO                                       STD_OFF  /**< Deactivateable: 'Com_TxGrpSigInfo.FilterInfo' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_FILTERINFO_UINT64_FILTERINFOOFTXGRPSIGINFO                                       STD_OFF  /**< Deactivateable: 'Com_TxGrpSigInfo.FilterInfo' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_FILTERINFO_SINT64_FILTERINFOOFTXGRPSIGINFO                                       STD_OFF  /**< Deactivateable: 'Com_TxGrpSigInfo.FilterInfo' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_FILTERINFO_FLOAT32_FILTERINFOOFTXGRPSIGINFO                                      STD_OFF  /**< Deactivateable: 'Com_TxGrpSigInfo.FilterInfo' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_FILTERINFO_FLOAT64_FILTERINFOOFTXGRPSIGINFO                                      STD_OFF  /**< Deactivateable: 'Com_TxGrpSigInfo.FilterInfo' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_FILTERINFO_UINT8_N_FILTERINFOOFTXGRPSIGINFO                                      STD_OFF  /**< Deactivateable: 'Com_TxGrpSigInfo.FilterInfo' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_NO_FILTERINFOOFTXGRPSIGINFO                                                      STD_OFF  /**< Deactivateable: 'Com_TxGrpSigInfo.FilterInfo' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_TXFILTERINITVALUEUINT8_FILTERINITVALUEOFTXGRPSIGINFO                             STD_OFF  /**< Deactivateable: 'Com_TxGrpSigInfo.FilterInitValue' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_TXFILTERINITVALUEUINT16_FILTERINITVALUEOFTXGRPSIGINFO                            STD_OFF  /**< Deactivateable: 'Com_TxGrpSigInfo.FilterInitValue' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_TXFILTERINITVALUEUINT32_FILTERINITVALUEOFTXGRPSIGINFO                            STD_OFF  /**< Deactivateable: 'Com_TxGrpSigInfo.FilterInitValue' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_TXFILTERINITVALUEUINT64_FILTERINITVALUEOFTXGRPSIGINFO                            STD_OFF  /**< Deactivateable: 'Com_TxGrpSigInfo.FilterInitValue' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_TXFILTERINITVALUESINT8_FILTERINITVALUEOFTXGRPSIGINFO                             STD_OFF  /**< Deactivateable: 'Com_TxGrpSigInfo.FilterInitValue' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_TXFILTERINITVALUESINT16_FILTERINITVALUEOFTXGRPSIGINFO                            STD_OFF  /**< Deactivateable: 'Com_TxGrpSigInfo.FilterInitValue' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_TXFILTERINITVALUESINT32_FILTERINITVALUEOFTXGRPSIGINFO                            STD_OFF  /**< Deactivateable: 'Com_TxGrpSigInfo.FilterInitValue' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_TXFILTERINITVALUESINT64_FILTERINITVALUEOFTXGRPSIGINFO                            STD_OFF  /**< Deactivateable: 'Com_TxGrpSigInfo.FilterInitValue' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_TXFILTERINITVALUEFLOAT32_FILTERINITVALUEOFTXGRPSIGINFO                           STD_OFF  /**< Deactivateable: 'Com_TxGrpSigInfo.FilterInitValue' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_TXFILTERINITVALUEFLOAT64_FILTERINITVALUEOFTXGRPSIGINFO                           STD_OFF  /**< Deactivateable: 'Com_TxGrpSigInfo.FilterInitValue' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_NO_FILTERINITVALUEOFTXGRPSIGINFO                                                 STD_OFF  /**< Deactivateable: 'Com_TxGrpSigInfo.FilterInitValue' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_CONSTVALUEUINT8_INVVALUEOFTXGRPSIGINFO                                           STD_OFF  /**< Deactivateable: 'Com_TxGrpSigInfo.InvValue' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_CONSTVALUEUINT16_INVVALUEOFTXGRPSIGINFO                                          STD_OFF  /**< Deactivateable: 'Com_TxGrpSigInfo.InvValue' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_CONSTVALUEUINT32_INVVALUEOFTXGRPSIGINFO                                          STD_OFF  /**< Deactivateable: 'Com_TxGrpSigInfo.InvValue' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_CONSTVALUEUINT64_INVVALUEOFTXGRPSIGINFO                                          STD_OFF  /**< Deactivateable: 'Com_TxGrpSigInfo.InvValue' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_CONSTVALUESINT8_INVVALUEOFTXGRPSIGINFO                                           STD_OFF  /**< Deactivateable: 'Com_TxGrpSigInfo.InvValue' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_CONSTVALUESINT16_INVVALUEOFTXGRPSIGINFO                                          STD_OFF  /**< Deactivateable: 'Com_TxGrpSigInfo.InvValue' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_CONSTVALUESINT32_INVVALUEOFTXGRPSIGINFO                                          STD_OFF  /**< Deactivateable: 'Com_TxGrpSigInfo.InvValue' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_CONSTVALUESINT64_INVVALUEOFTXGRPSIGINFO                                          STD_OFF  /**< Deactivateable: 'Com_TxGrpSigInfo.InvValue' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_CONSTVALUEFLOAT32_INVVALUEOFTXGRPSIGINFO                                         STD_OFF  /**< Deactivateable: 'Com_TxGrpSigInfo.InvValue' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_CONSTVALUEFLOAT64_INVVALUEOFTXGRPSIGINFO                                         STD_OFF  /**< Deactivateable: 'Com_TxGrpSigInfo.InvValue' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_NO_INVVALUEOFTXGRPSIGINFO                                                        STD_OFF  /**< Deactivateable: 'Com_TxGrpSigInfo.InvValue' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_FILTERINFO_UINT8_ONCHANGEOFTXGRPSIGINFO                                          STD_OFF  /**< Deactivateable: 'Com_TxGrpSigInfo.OnChange' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_FILTERINFO_SINT8_ONCHANGEOFTXGRPSIGINFO                                          STD_OFF  /**< Deactivateable: 'Com_TxGrpSigInfo.OnChange' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_FILTERINFO_UINT16_ONCHANGEOFTXGRPSIGINFO                                         STD_OFF  /**< Deactivateable: 'Com_TxGrpSigInfo.OnChange' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_FILTERINFO_SINT16_ONCHANGEOFTXGRPSIGINFO                                         STD_OFF  /**< Deactivateable: 'Com_TxGrpSigInfo.OnChange' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_FILTERINFO_UINT32_ONCHANGEOFTXGRPSIGINFO                                         STD_OFF  /**< Deactivateable: 'Com_TxGrpSigInfo.OnChange' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_FILTERINFO_SINT32_ONCHANGEOFTXGRPSIGINFO                                         STD_OFF  /**< Deactivateable: 'Com_TxGrpSigInfo.OnChange' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_FILTERINFO_UINT64_ONCHANGEOFTXGRPSIGINFO                                         STD_OFF  /**< Deactivateable: 'Com_TxGrpSigInfo.OnChange' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_FILTERINFO_SINT64_ONCHANGEOFTXGRPSIGINFO                                         STD_OFF  /**< Deactivateable: 'Com_TxGrpSigInfo.OnChange' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_FILTERINFO_FLOAT32_ONCHANGEOFTXGRPSIGINFO                                        STD_OFF  /**< Deactivateable: 'Com_TxGrpSigInfo.OnChange' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_FILTERINFO_FLOAT64_ONCHANGEOFTXGRPSIGINFO                                        STD_OFF  /**< Deactivateable: 'Com_TxGrpSigInfo.OnChange' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_FILTERINFO_UINT8_N_ONCHANGEOFTXGRPSIGINFO                                        STD_OFF  /**< Deactivateable: 'Com_TxGrpSigInfo.OnChange' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_NO_ONCHANGEOFTXGRPSIGINFO                                                        STD_OFF  /**< Deactivateable: 'Com_TxGrpSigInfo.OnChange' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_TRANSMIT_CLRUBOFTXPDUINFO                                                        STD_OFF  /**< Deactivateable: 'Com_TxPduInfo.ClrUb' Reason: 'This array is deactivated, because no Tx I-PDUs with update-bits are configured in all variants.' */
#define COM_EXISTS_TRIGGER_TRANSMIT_CLRUBOFTXPDUINFO                                                STD_OFF  /**< Deactivateable: 'Com_TxPduInfo.ClrUb' Reason: 'This array is deactivated, because no Tx I-PDUs with update-bits are configured in all variants.' */
#define COM_EXISTS_NOT_USED_CLRUBOFTXPDUINFO                                                        STD_OFF  /**< Deactivateable: 'Com_TxPduInfo.ClrUb' Reason: 'This array is deactivated, because no Tx I-PDUs with update-bits are configured in all variants.' */
#define COM_EXISTS_CONFIRMATION_CLRUBOFTXPDUINFO                                                    STD_OFF  /**< Deactivateable: 'Com_TxPduInfo.ClrUb' Reason: 'This array is deactivated, because no Tx I-PDUs with update-bits are configured in all variants.' */
#define COM_EXISTS_NORMAL_TYPEOFTXPDUINFO                                                           STD_ON
#define COM_EXISTS_TP_TYPEOFTXPDUINFO                                                               STD_OFF
#define COM_EXISTS_PENDING_TRANSFERPROPERTYOFTXSIGGRPINFO                                           STD_OFF  /**< Deactivateable: 'Com_TxSigGrpInfo.TransferProperty' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_TRIGGERED_TRANSFERPROPERTYOFTXSIGGRPINFO                                         STD_OFF  /**< Deactivateable: 'Com_TxSigGrpInfo.TransferProperty' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_TRIGGERED_WITHOUT_REPETITION_TRANSFERPROPERTYOFTXSIGGRPINFO                      STD_OFF  /**< Deactivateable: 'Com_TxSigGrpInfo.TransferProperty' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_TRIGGERED_ON_CHANGE_TRANSFERPROPERTYOFTXSIGGRPINFO                               STD_OFF  /**< Deactivateable: 'Com_TxSigGrpInfo.TransferProperty' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_TRIGGERED_ON_CHANGE_WITHOUT_REPETITION_TRANSFERPROPERTYOFTXSIGGRPINFO            STD_OFF  /**< Deactivateable: 'Com_TxSigGrpInfo.TransferProperty' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_CONSTVALUEUINT8_UBMASKOFTXSIGGRPINFO                                             STD_OFF  /**< Deactivateable: 'Com_TxSigGrpInfo.UbMask' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_CONSTVALUEUINT16_UBMASKOFTXSIGGRPINFO                                            STD_OFF  /**< Deactivateable: 'Com_TxSigGrpInfo.UbMask' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_CONSTVALUEUINT32_UBMASKOFTXSIGGRPINFO                                            STD_OFF  /**< Deactivateable: 'Com_TxSigGrpInfo.UbMask' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_CONSTVALUEUINT64_UBMASKOFTXSIGGRPINFO                                            STD_OFF  /**< Deactivateable: 'Com_TxSigGrpInfo.UbMask' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_CONSTVALUESINT8_UBMASKOFTXSIGGRPINFO                                             STD_OFF  /**< Deactivateable: 'Com_TxSigGrpInfo.UbMask' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_CONSTVALUESINT16_UBMASKOFTXSIGGRPINFO                                            STD_OFF  /**< Deactivateable: 'Com_TxSigGrpInfo.UbMask' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_CONSTVALUESINT32_UBMASKOFTXSIGGRPINFO                                            STD_OFF  /**< Deactivateable: 'Com_TxSigGrpInfo.UbMask' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_CONSTVALUESINT64_UBMASKOFTXSIGGRPINFO                                            STD_OFF  /**< Deactivateable: 'Com_TxSigGrpInfo.UbMask' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_CONSTVALUEFLOAT32_UBMASKOFTXSIGGRPINFO                                           STD_OFF  /**< Deactivateable: 'Com_TxSigGrpInfo.UbMask' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_CONSTVALUEFLOAT64_UBMASKOFTXSIGGRPINFO                                           STD_OFF  /**< Deactivateable: 'Com_TxSigGrpInfo.UbMask' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_NO_UBMASKOFTXSIGGRPINFO                                                          STD_OFF  /**< Deactivateable: 'Com_TxSigGrpInfo.UbMask' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_UINT8_APPLTYPEOFTXSIGINFO                                                        STD_ON
#define COM_EXISTS_SINT8_APPLTYPEOFTXSIGINFO                                                        STD_OFF
#define COM_EXISTS_UINT16_APPLTYPEOFTXSIGINFO                                                       STD_OFF
#define COM_EXISTS_SINT16_APPLTYPEOFTXSIGINFO                                                       STD_ON
#define COM_EXISTS_UINT32_APPLTYPEOFTXSIGINFO                                                       STD_OFF
#define COM_EXISTS_SINT32_APPLTYPEOFTXSIGINFO                                                       STD_OFF
#define COM_EXISTS_UINT64_APPLTYPEOFTXSIGINFO                                                       STD_OFF
#define COM_EXISTS_SINT64_APPLTYPEOFTXSIGINFO                                                       STD_OFF
#define COM_EXISTS_UINT8_N_APPLTYPEOFTXSIGINFO                                                      STD_OFF
#define COM_EXISTS_UINT8_DYN_APPLTYPEOFTXSIGINFO                                                    STD_OFF
#define COM_EXISTS_ZEROBIT_APPLTYPEOFTXSIGINFO                                                      STD_OFF
#define COM_EXISTS_FLOAT32_APPLTYPEOFTXSIGINFO                                                      STD_OFF
#define COM_EXISTS_FLOAT64_APPLTYPEOFTXSIGINFO                                                      STD_OFF
#define COM_EXISTS_NBIT_BUSACCOFTXSIGINFO                                                           STD_ON
#define COM_EXISTS_BYTE_BUSACCOFTXSIGINFO                                                           STD_ON
#define COM_EXISTS_NBYTE_BUSACCOFTXSIGINFO                                                          STD_ON
#define COM_EXISTS_NBYTE_SW_BUSACCOFTXSIGINFO                                                       STD_OFF
#define COM_EXISTS_NBITNBYTE_BUSACCOFTXSIGINFO                                                      STD_OFF
#define COM_EXISTS_NBITNBYTE_SW_BUSACCOFTXSIGINFO                                                   STD_OFF
#define COM_EXISTS_ARRAY_BASED_BUSACCOFTXSIGINFO                                                    STD_OFF
#define COM_EXISTS_FILTERINFO_UINT8_FILTERINFOOFTXSIGINFO                                           STD_OFF  /**< Deactivateable: 'Com_TxSigInfo.FilterInfo' Reason: 'the optional indirection is deactivated because FilterInfoUsedOfTxSigInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_EXISTS_FILTERINFO_SINT8_FILTERINFOOFTXSIGINFO                                           STD_OFF  /**< Deactivateable: 'Com_TxSigInfo.FilterInfo' Reason: 'the optional indirection is deactivated because FilterInfoUsedOfTxSigInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_EXISTS_FILTERINFO_UINT16_FILTERINFOOFTXSIGINFO                                          STD_OFF  /**< Deactivateable: 'Com_TxSigInfo.FilterInfo' Reason: 'the optional indirection is deactivated because FilterInfoUsedOfTxSigInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_EXISTS_FILTERINFO_SINT16_FILTERINFOOFTXSIGINFO                                          STD_OFF  /**< Deactivateable: 'Com_TxSigInfo.FilterInfo' Reason: 'the optional indirection is deactivated because FilterInfoUsedOfTxSigInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_EXISTS_FILTERINFO_UINT32_FILTERINFOOFTXSIGINFO                                          STD_OFF  /**< Deactivateable: 'Com_TxSigInfo.FilterInfo' Reason: 'the optional indirection is deactivated because FilterInfoUsedOfTxSigInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_EXISTS_FILTERINFO_SINT32_FILTERINFOOFTXSIGINFO                                          STD_OFF  /**< Deactivateable: 'Com_TxSigInfo.FilterInfo' Reason: 'the optional indirection is deactivated because FilterInfoUsedOfTxSigInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_EXISTS_FILTERINFO_UINT64_FILTERINFOOFTXSIGINFO                                          STD_OFF  /**< Deactivateable: 'Com_TxSigInfo.FilterInfo' Reason: 'the optional indirection is deactivated because FilterInfoUsedOfTxSigInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_EXISTS_FILTERINFO_SINT64_FILTERINFOOFTXSIGINFO                                          STD_OFF  /**< Deactivateable: 'Com_TxSigInfo.FilterInfo' Reason: 'the optional indirection is deactivated because FilterInfoUsedOfTxSigInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_EXISTS_FILTERINFO_FLOAT32_FILTERINFOOFTXSIGINFO                                         STD_OFF  /**< Deactivateable: 'Com_TxSigInfo.FilterInfo' Reason: 'the optional indirection is deactivated because FilterInfoUsedOfTxSigInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_EXISTS_FILTERINFO_FLOAT64_FILTERINFOOFTXSIGINFO                                         STD_OFF  /**< Deactivateable: 'Com_TxSigInfo.FilterInfo' Reason: 'the optional indirection is deactivated because FilterInfoUsedOfTxSigInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_EXISTS_FILTERINFO_UINT8_N_FILTERINFOOFTXSIGINFO                                         STD_OFF  /**< Deactivateable: 'Com_TxSigInfo.FilterInfo' Reason: 'the optional indirection is deactivated because FilterInfoUsedOfTxSigInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_EXISTS_NO_FILTERINFOOFTXSIGINFO                                                         STD_OFF  /**< Deactivateable: 'Com_TxSigInfo.FilterInfo' Reason: 'the optional indirection is deactivated because FilterInfoUsedOfTxSigInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_EXISTS_TXFILTERINITVALUEUINT8_FILTERINITVALUEOFTXSIGINFO                                STD_OFF  /**< Deactivateable: 'Com_TxSigInfo.FilterInitValue' Reason: 'the optional indirection is deactivated because FilterInitValueUsedOfTxSigInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_EXISTS_TXFILTERINITVALUEUINT16_FILTERINITVALUEOFTXSIGINFO                               STD_OFF  /**< Deactivateable: 'Com_TxSigInfo.FilterInitValue' Reason: 'the optional indirection is deactivated because FilterInitValueUsedOfTxSigInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_EXISTS_TXFILTERINITVALUEUINT32_FILTERINITVALUEOFTXSIGINFO                               STD_OFF  /**< Deactivateable: 'Com_TxSigInfo.FilterInitValue' Reason: 'the optional indirection is deactivated because FilterInitValueUsedOfTxSigInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_EXISTS_TXFILTERINITVALUEUINT64_FILTERINITVALUEOFTXSIGINFO                               STD_OFF  /**< Deactivateable: 'Com_TxSigInfo.FilterInitValue' Reason: 'the optional indirection is deactivated because FilterInitValueUsedOfTxSigInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_EXISTS_TXFILTERINITVALUESINT8_FILTERINITVALUEOFTXSIGINFO                                STD_OFF  /**< Deactivateable: 'Com_TxSigInfo.FilterInitValue' Reason: 'the optional indirection is deactivated because FilterInitValueUsedOfTxSigInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_EXISTS_TXFILTERINITVALUESINT16_FILTERINITVALUEOFTXSIGINFO                               STD_OFF  /**< Deactivateable: 'Com_TxSigInfo.FilterInitValue' Reason: 'the optional indirection is deactivated because FilterInitValueUsedOfTxSigInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_EXISTS_TXFILTERINITVALUESINT32_FILTERINITVALUEOFTXSIGINFO                               STD_OFF  /**< Deactivateable: 'Com_TxSigInfo.FilterInitValue' Reason: 'the optional indirection is deactivated because FilterInitValueUsedOfTxSigInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_EXISTS_TXFILTERINITVALUESINT64_FILTERINITVALUEOFTXSIGINFO                               STD_OFF  /**< Deactivateable: 'Com_TxSigInfo.FilterInitValue' Reason: 'the optional indirection is deactivated because FilterInitValueUsedOfTxSigInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_EXISTS_TXFILTERINITVALUEFLOAT32_FILTERINITVALUEOFTXSIGINFO                              STD_OFF  /**< Deactivateable: 'Com_TxSigInfo.FilterInitValue' Reason: 'the optional indirection is deactivated because FilterInitValueUsedOfTxSigInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_EXISTS_TXFILTERINITVALUEFLOAT64_FILTERINITVALUEOFTXSIGINFO                              STD_OFF  /**< Deactivateable: 'Com_TxSigInfo.FilterInitValue' Reason: 'the optional indirection is deactivated because FilterInitValueUsedOfTxSigInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_EXISTS_NO_FILTERINITVALUEOFTXSIGINFO                                                    STD_OFF  /**< Deactivateable: 'Com_TxSigInfo.FilterInitValue' Reason: 'the optional indirection is deactivated because FilterInitValueUsedOfTxSigInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_EXISTS_CONSTVALUEUINT8_INVVALUEOFTXSIGINFO                                              STD_OFF  /**< Deactivateable: 'Com_TxSigInfo.InvValue' Reason: 'the optional indirection is deactivated because InvValueUsedOfTxSigInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_EXISTS_CONSTVALUEUINT16_INVVALUEOFTXSIGINFO                                             STD_OFF  /**< Deactivateable: 'Com_TxSigInfo.InvValue' Reason: 'the optional indirection is deactivated because InvValueUsedOfTxSigInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_EXISTS_CONSTVALUEUINT32_INVVALUEOFTXSIGINFO                                             STD_OFF  /**< Deactivateable: 'Com_TxSigInfo.InvValue' Reason: 'the optional indirection is deactivated because InvValueUsedOfTxSigInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_EXISTS_CONSTVALUEUINT64_INVVALUEOFTXSIGINFO                                             STD_OFF  /**< Deactivateable: 'Com_TxSigInfo.InvValue' Reason: 'the optional indirection is deactivated because InvValueUsedOfTxSigInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_EXISTS_CONSTVALUESINT8_INVVALUEOFTXSIGINFO                                              STD_OFF  /**< Deactivateable: 'Com_TxSigInfo.InvValue' Reason: 'the optional indirection is deactivated because InvValueUsedOfTxSigInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_EXISTS_CONSTVALUESINT16_INVVALUEOFTXSIGINFO                                             STD_OFF  /**< Deactivateable: 'Com_TxSigInfo.InvValue' Reason: 'the optional indirection is deactivated because InvValueUsedOfTxSigInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_EXISTS_CONSTVALUESINT32_INVVALUEOFTXSIGINFO                                             STD_OFF  /**< Deactivateable: 'Com_TxSigInfo.InvValue' Reason: 'the optional indirection is deactivated because InvValueUsedOfTxSigInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_EXISTS_CONSTVALUESINT64_INVVALUEOFTXSIGINFO                                             STD_OFF  /**< Deactivateable: 'Com_TxSigInfo.InvValue' Reason: 'the optional indirection is deactivated because InvValueUsedOfTxSigInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_EXISTS_CONSTVALUEFLOAT32_INVVALUEOFTXSIGINFO                                            STD_OFF  /**< Deactivateable: 'Com_TxSigInfo.InvValue' Reason: 'the optional indirection is deactivated because InvValueUsedOfTxSigInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_EXISTS_CONSTVALUEFLOAT64_INVVALUEOFTXSIGINFO                                            STD_OFF  /**< Deactivateable: 'Com_TxSigInfo.InvValue' Reason: 'the optional indirection is deactivated because InvValueUsedOfTxSigInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_EXISTS_NO_INVVALUEOFTXSIGINFO                                                           STD_OFF  /**< Deactivateable: 'Com_TxSigInfo.InvValue' Reason: 'the optional indirection is deactivated because InvValueUsedOfTxSigInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_EXISTS_FILTERINFO_UINT8_ONCHANGEOFTXSIGINFO                                             STD_OFF  /**< Deactivateable: 'Com_TxSigInfo.OnChange' Reason: 'the optional indirection is deactivated because OnChangeUsedOfTxSigInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_EXISTS_FILTERINFO_SINT8_ONCHANGEOFTXSIGINFO                                             STD_OFF  /**< Deactivateable: 'Com_TxSigInfo.OnChange' Reason: 'the optional indirection is deactivated because OnChangeUsedOfTxSigInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_EXISTS_FILTERINFO_UINT16_ONCHANGEOFTXSIGINFO                                            STD_OFF  /**< Deactivateable: 'Com_TxSigInfo.OnChange' Reason: 'the optional indirection is deactivated because OnChangeUsedOfTxSigInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_EXISTS_FILTERINFO_SINT16_ONCHANGEOFTXSIGINFO                                            STD_OFF  /**< Deactivateable: 'Com_TxSigInfo.OnChange' Reason: 'the optional indirection is deactivated because OnChangeUsedOfTxSigInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_EXISTS_FILTERINFO_UINT32_ONCHANGEOFTXSIGINFO                                            STD_OFF  /**< Deactivateable: 'Com_TxSigInfo.OnChange' Reason: 'the optional indirection is deactivated because OnChangeUsedOfTxSigInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_EXISTS_FILTERINFO_SINT32_ONCHANGEOFTXSIGINFO                                            STD_OFF  /**< Deactivateable: 'Com_TxSigInfo.OnChange' Reason: 'the optional indirection is deactivated because OnChangeUsedOfTxSigInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_EXISTS_FILTERINFO_UINT64_ONCHANGEOFTXSIGINFO                                            STD_OFF  /**< Deactivateable: 'Com_TxSigInfo.OnChange' Reason: 'the optional indirection is deactivated because OnChangeUsedOfTxSigInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_EXISTS_FILTERINFO_SINT64_ONCHANGEOFTXSIGINFO                                            STD_OFF  /**< Deactivateable: 'Com_TxSigInfo.OnChange' Reason: 'the optional indirection is deactivated because OnChangeUsedOfTxSigInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_EXISTS_FILTERINFO_FLOAT32_ONCHANGEOFTXSIGINFO                                           STD_OFF  /**< Deactivateable: 'Com_TxSigInfo.OnChange' Reason: 'the optional indirection is deactivated because OnChangeUsedOfTxSigInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_EXISTS_FILTERINFO_FLOAT64_ONCHANGEOFTXSIGINFO                                           STD_OFF  /**< Deactivateable: 'Com_TxSigInfo.OnChange' Reason: 'the optional indirection is deactivated because OnChangeUsedOfTxSigInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_EXISTS_FILTERINFO_UINT8_N_ONCHANGEOFTXSIGINFO                                           STD_OFF  /**< Deactivateable: 'Com_TxSigInfo.OnChange' Reason: 'the optional indirection is deactivated because OnChangeUsedOfTxSigInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_EXISTS_NO_ONCHANGEOFTXSIGINFO                                                           STD_OFF  /**< Deactivateable: 'Com_TxSigInfo.OnChange' Reason: 'the optional indirection is deactivated because OnChangeUsedOfTxSigInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_EXISTS_CONSTVALUEUINT8_UBMASKOFTXSIGINFO                                                STD_OFF  /**< Deactivateable: 'Com_TxSigInfo.UbMask' Reason: 'the optional indirection is deactivated because UbMaskUsedOfTxSigInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_EXISTS_CONSTVALUEUINT16_UBMASKOFTXSIGINFO                                               STD_OFF  /**< Deactivateable: 'Com_TxSigInfo.UbMask' Reason: 'the optional indirection is deactivated because UbMaskUsedOfTxSigInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_EXISTS_CONSTVALUEUINT32_UBMASKOFTXSIGINFO                                               STD_OFF  /**< Deactivateable: 'Com_TxSigInfo.UbMask' Reason: 'the optional indirection is deactivated because UbMaskUsedOfTxSigInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_EXISTS_CONSTVALUEUINT64_UBMASKOFTXSIGINFO                                               STD_OFF  /**< Deactivateable: 'Com_TxSigInfo.UbMask' Reason: 'the optional indirection is deactivated because UbMaskUsedOfTxSigInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_EXISTS_CONSTVALUESINT8_UBMASKOFTXSIGINFO                                                STD_OFF  /**< Deactivateable: 'Com_TxSigInfo.UbMask' Reason: 'the optional indirection is deactivated because UbMaskUsedOfTxSigInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_EXISTS_CONSTVALUESINT16_UBMASKOFTXSIGINFO                                               STD_OFF  /**< Deactivateable: 'Com_TxSigInfo.UbMask' Reason: 'the optional indirection is deactivated because UbMaskUsedOfTxSigInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_EXISTS_CONSTVALUESINT32_UBMASKOFTXSIGINFO                                               STD_OFF  /**< Deactivateable: 'Com_TxSigInfo.UbMask' Reason: 'the optional indirection is deactivated because UbMaskUsedOfTxSigInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_EXISTS_CONSTVALUESINT64_UBMASKOFTXSIGINFO                                               STD_OFF  /**< Deactivateable: 'Com_TxSigInfo.UbMask' Reason: 'the optional indirection is deactivated because UbMaskUsedOfTxSigInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_EXISTS_CONSTVALUEFLOAT32_UBMASKOFTXSIGINFO                                              STD_OFF  /**< Deactivateable: 'Com_TxSigInfo.UbMask' Reason: 'the optional indirection is deactivated because UbMaskUsedOfTxSigInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_EXISTS_CONSTVALUEFLOAT64_UBMASKOFTXSIGINFO                                              STD_OFF  /**< Deactivateable: 'Com_TxSigInfo.UbMask' Reason: 'the optional indirection is deactivated because UbMaskUsedOfTxSigInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_EXISTS_NO_UBMASKOFTXSIGINFO                                                             STD_OFF  /**< Deactivateable: 'Com_TxSigInfo.UbMask' Reason: 'the optional indirection is deactivated because UbMaskUsedOfTxSigInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_EXISTS_NORMAL_MODEOFTXTOUTINFO                                                          STD_OFF  /**< Deactivateable: 'Com_TxTOutInfo.Mode' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_NONE_MODEOFTXTOUTINFO                                                            STD_OFF  /**< Deactivateable: 'Com_TxTOutInfo.Mode' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
/** 
  \}
*/ 

/** 
  \defgroup  ComPCEnumDefines  Com Enum Defines (PRE_COMPILE)
  \brief  These defines are the enumeration values of enumeration based CONST and VAR data.
  \{
*/ 
#define COM_INACTIVE_IPDUGROUPSTATE                                                                 0x00u
#define COM_ACTIVE_DMINACTIVE_IPDUGROUPSTATE                                                        0x01u
#define COM_ACTIVE_DMACTIVE_IPDUGROUPSTATE                                                          0x02u
#define COM_UINT8_APPLTYPEOFRXACCESSINFO                                                            0x00u
#define COM_RXSIGBUFFERUINT8_BUFFEROFRXACCESSINFO                                                   0x00u
#define COM_NBIT_BUSACCOFRXACCESSINFO                                                               0x00u
#define COM_CONSTVALUEUINT8_INITVALUEOFRXACCESSINFO                                                 0x00u
#define COM_DEFERRED_SIGNALPROCESSINGOFRXPDUINFO                                                    0x00u
#define COM_NORMAL_TYPEOFRXPDUINFO                                                                  0x00u
#define COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO                                                    0x00u
#define COM_NORMAL_TYPEOFTXPDUINFO                                                                  0x00u
#define COM_UINT8_APPLTYPEOFTXSIGINFO                                                               0x00u
#define COM_SINT16_APPLTYPEOFTXSIGINFO                                                              0x03u
#define COM_NBIT_BUSACCOFTXSIGINFO                                                                  0x00u
#define COM_BYTE_BUSACCOFTXSIGINFO                                                                  0x01u
#define COM_NBYTE_BUSACCOFTXSIGINFO                                                                 0x02u
/** 
  \}
*/ 

/** 
  \defgroup  ComPCIsReducedToDefineDefines  Com Is Reduced To Define Defines (PRE_COMPILE)
  \brief  If all values in a CONST array or an element in a CONST array of structs are equal, the define is STD_ON else STD_OFF.
  \{
*/ 
#define COM_ISDEF_PARTITIONSALWAYSACTIVETXCOMIPDUSSTRUCTIDXOFALWAYSACTIVETXCOMIPDUS                 STD_OFF
#define COM_ISDEF_TXPDUINFOIDXOFALWAYSACTIVETXCOMIPDUS                                              STD_OFF
#define COM_ISDEF_CONSTVALUEUINT8                                                                   STD_OFF
#define COM_ISDEF_IPDUGROUPINFOTOSUBIPDUGROUPSINDENDIDXOFIPDUGROUPINFO                              STD_OFF
#define COM_ISDEF_IPDUGROUPINFOTOSUBIPDUGROUPSINDSTARTIDXOFIPDUGROUPINFO                            STD_OFF
#define COM_ISDEF_IPDUGROUPINFOTOSUBIPDUGROUPSINDUSEDOFIPDUGROUPINFO                                STD_OFF
#define COM_ISDEF_PARTITIONSRXSTRUCTIDXOFIPDUGROUPINFO                                              STD_OFF
#define COM_ISDEF_PARTITIONSRXSTRUCTUSEDOFIPDUGROUPINFO                                             STD_OFF
#define COM_ISDEF_PARTITIONSTXSTRUCTIDXOFIPDUGROUPINFO                                              STD_OFF
#define COM_ISDEF_PARTITIONSTXSTRUCTUSEDOFIPDUGROUPINFO                                             STD_OFF
#define COM_ISDEF_RXPDUINFOINDENDIDXOFIPDUGROUPINFO                                                 STD_OFF
#define COM_ISDEF_RXPDUINFOINDSTARTIDXOFIPDUGROUPINFO                                               STD_OFF
#define COM_ISDEF_RXPDUINFOINDUSEDOFIPDUGROUPINFO                                                   STD_OFF
#define COM_ISDEF_TXPDUINFOINDENDIDXOFIPDUGROUPINFO                                                 STD_OFF
#define COM_ISDEF_TXPDUINFOINDSTARTIDXOFIPDUGROUPINFO                                               STD_OFF
#define COM_ISDEF_TXPDUINFOINDUSEDOFIPDUGROUPINFO                                                   STD_OFF
#define COM_ISDEF_IPDUGROUPINFOOFRXPDUINFOIND                                                       STD_OFF
#define COM_ISDEF_IPDUGROUPINFOOFTXPDUINFOIND                                                       STD_OFF
#define COM_ISDEF_IPDUGROUPINFOTOSUBIPDUGROUPSIND                                                   STD_OFF
#define COM_ISDEF_RXMAINFUNCTIONPROCESSINGISRLOCKCOUNTERIDXOFMAINFUNCTIONRXSTRUCT                   STD_OFF
#define COM_ISDEF_RXPDUINFOOFMAINFUNCTIONRXINDENDIDXOFMAINFUNCTIONRXSTRUCT                          STD_OFF
#define COM_ISDEF_RXPDUINFOOFMAINFUNCTIONRXINDSTARTIDXOFMAINFUNCTIONRXSTRUCT                        STD_OFF
#define COM_ISDEF_RXPDUINFOOFMAINFUNCTIONRXINDUSEDOFMAINFUNCTIONRXSTRUCT                            STD_OFF
#define COM_ISDEF_TXCYCLICPDUOFMAINFUNCTIONTXINDENDIDXOFMAINFUNCTIONTXSTRUCT                        STD_OFF
#define COM_ISDEF_TXCYCLICPDUOFMAINFUNCTIONTXINDSTARTIDXOFMAINFUNCTIONTXSTRUCT                      STD_OFF
#define COM_ISDEF_TXCYCLICPDUOFMAINFUNCTIONTXINDUSEDOFMAINFUNCTIONTXSTRUCT                          STD_OFF
#define COM_ISDEF_TXPDUINFOOFMAINFUNCTIONTXINDENDIDXOFMAINFUNCTIONTXSTRUCT                          STD_OFF
#define COM_ISDEF_TXPDUINFOOFMAINFUNCTIONTXINDSTARTIDXOFMAINFUNCTIONTXSTRUCT                        STD_OFF
#define COM_ISDEF_TXPDUINFOOFMAINFUNCTIONTXINDUSEDOFMAINFUNCTIONTXSTRUCT                            STD_OFF
#define COM_ISDEF_TXPROCESSINGISRLOCKCOUNTERIDXOFMAINFUNCTIONTXSTRUCT                               STD_OFF
#define COM_ISDEF_TXIPDUGROUPISRLOCKCOUNTERIDXOFPARTITIONSALWAYSACTIVETXCOMIPDUSSTRUCT              STD_OFF
#define COM_ISDEF_RXIPDUGROUPISRLOCKCOUNTERIDXOFPARTITIONSRXSTRUCT                                  STD_OFF
#define COM_ISDEF_TXIPDUGROUPISRLOCKCOUNTERIDXOFPARTITIONSTXSTRUCT                                  STD_OFF
#define COM_ISDEF_APPLTYPEOFRXACCESSINFO                                                            STD_OFF
#define COM_ISDEF_BITLENGTHOFRXACCESSINFO                                                           STD_OFF
#define COM_ISDEF_BITPOSITIONOFRXACCESSINFO                                                         STD_OFF
#define COM_ISDEF_BUFFERIDXOFRXACCESSINFO                                                           STD_OFF
#define COM_ISDEF_BUFFEROFRXACCESSINFO                                                              STD_OFF
#define COM_ISDEF_BUFFERUSEDOFRXACCESSINFO                                                          STD_OFF
#define COM_ISDEF_BUSACCOFRXACCESSINFO                                                              STD_OFF
#define COM_ISDEF_BYTELENGTHOFRXACCESSINFO                                                          STD_OFF
#define COM_ISDEF_BYTEPOSITIONOFRXACCESSINFO                                                        STD_OFF
#define COM_ISDEF_DYNSIGNALOFRXACCESSINFO                                                           STD_OFF
#define COM_ISDEF_INITVALUEIDXOFRXACCESSINFO                                                        STD_OFF
#define COM_ISDEF_INITVALUEOFRXACCESSINFO                                                           STD_OFF
#define COM_ISDEF_INITVALUEUSEDOFRXACCESSINFO                                                       STD_OFF
#define COM_ISDEF_RXPDUINFOIDXOFRXACCESSINFO                                                        STD_OFF
#define COM_ISDEF_SIGNALLENGTHINBYTEOFRXACCESSINFO                                                  STD_OFF
#define COM_ISDEF_STARTBYTEINPDUPOSITIONOFRXACCESSINFO                                              STD_OFF
#define COM_ISDEF_RXACCESSINFOIND                                                                   STD_OFF
#define COM_ISDEF_HANDLERXPDUDEFERREDIDXOFRXPDUINFO                                                 STD_OFF
#define COM_ISDEF_HANDLERXPDUDEFERREDUSEDOFRXPDUINFO                                                STD_OFF
#define COM_ISDEF_IPDUGROUPINFOOFRXPDUINFOINDENDIDXOFRXPDUINFO                                      STD_OFF
#define COM_ISDEF_IPDUGROUPINFOOFRXPDUINFOINDSTARTIDXOFRXPDUINFO                                    STD_OFF
#define COM_ISDEF_IPDUGROUPINFOOFRXPDUINFOINDUSEDOFRXPDUINFO                                        STD_OFF
#define COM_ISDEF_MAINFUNCTIONRXSTRUCTIDXOFRXPDUINFO                                                STD_OFF
#define COM_ISDEF_MAINFUNCTIONRXSTRUCTUSEDOFRXPDUINFO                                               STD_OFF
#define COM_ISDEF_PARTITIONSRXSTRUCTIDXOFRXPDUINFO                                                  STD_OFF
#define COM_ISDEF_RXACCESSINFOINDENDIDXOFRXPDUINFO                                                  STD_OFF
#define COM_ISDEF_RXACCESSINFOINDSTARTIDXOFRXPDUINFO                                                STD_OFF
#define COM_ISDEF_RXACCESSINFOINDUSEDOFRXPDUINFO                                                    STD_OFF
#define COM_ISDEF_RXDEFPDUBUFFERENDIDXOFRXPDUINFO                                                   STD_OFF
#define COM_ISDEF_RXDEFPDUBUFFERLENGTHOFRXPDUINFO                                                   STD_OFF
#define COM_ISDEF_RXDEFPDUBUFFERSTARTIDXOFRXPDUINFO                                                 STD_OFF
#define COM_ISDEF_RXDEFPDUBUFFERUSEDOFRXPDUINFO                                                     STD_OFF
#define COM_ISDEF_RXSIGINFOENDIDXOFRXPDUINFO                                                        STD_OFF
#define COM_ISDEF_RXSIGINFOSTARTIDXOFRXPDUINFO                                                      STD_OFF
#define COM_ISDEF_RXSIGINFOUSEDOFRXPDUINFO                                                          STD_OFF
#define COM_ISDEF_SIGNALPROCESSINGOFRXPDUINFO                                                       STD_OFF
#define COM_ISDEF_TYPEOFRXPDUINFO                                                                   STD_OFF
#define COM_ISDEF_RXPDUINFOIND                                                                      STD_OFF
#define COM_ISDEF_RXPDUINFOOFMAINFUNCTIONRXIND                                                      STD_OFF
#define COM_ISDEF_RXACCESSINFOIDXOFRXSIGINFO                                                        STD_OFF
#define COM_ISDEF_SIGNALPROCESSINGOFRXSIGINFO                                                       STD_OFF
#define COM_ISDEF_VALIDDLCOFRXSIGINFO                                                               STD_OFF
#define COM_ISDEF_TXSIGINFOIDXOFTXACCESSINFO                                                        STD_OFF
#define COM_ISDEF_TXSIGINFOUSEDOFTXACCESSINFO                                                       STD_OFF
#define COM_ISDEF_TXPDUINFOIDXOFTXCYCLICPDU                                                         STD_OFF
#define COM_ISDEF_TXCYCLICPDUOFMAINFUNCTIONTXIND                                                    STD_OFF
#define COM_ISDEF_PERIODICOFTXMODEFALSE                                                             STD_OFF
#define COM_ISDEF_TIMEPERIODOFTXMODEFALSE                                                           STD_OFF
#define COM_ISDEF_INITMODEOFTXMODEINFO                                                              STD_OFF
#define COM_ISDEF_TXMODEFALSEIDXOFTXMODEINFO                                                        STD_OFF
#define COM_ISDEF_TXMODETRUEIDXOFTXMODEINFO                                                         STD_OFF
#define COM_ISDEF_PERIODICOFTXMODETRUE                                                              STD_OFF
#define COM_ISDEF_TIMEPERIODOFTXMODETRUE                                                            STD_OFF
#define COM_ISDEF_EXTERNALIDOFTXPDUINFO                                                             STD_OFF
#define COM_ISDEF_IPDUGROUPINFOOFTXPDUINFOINDENDIDXOFTXPDUINFO                                      STD_OFF
#define COM_ISDEF_IPDUGROUPINFOOFTXPDUINFOINDSTARTIDXOFTXPDUINFO                                    STD_OFF
#define COM_ISDEF_IPDUGROUPINFOOFTXPDUINFOINDUSEDOFTXPDUINFO                                        STD_OFF
#define COM_ISDEF_METADATALENGTHOFTXPDUINFO                                                         STD_OFF
#define COM_ISDEF_PARTITIONSTXSTRUCTIDXOFTXPDUINFO                                                  STD_OFF
#define COM_ISDEF_PDUWITHMETADATALENGTHOFTXPDUINFO                                                  STD_OFF
#define COM_ISDEF_TXBUFFERENDIDXOFTXPDUINFO                                                         STD_OFF
#define COM_ISDEF_TXBUFFERLENGTHOFTXPDUINFO                                                         STD_OFF
#define COM_ISDEF_TXBUFFERSTARTIDXOFTXPDUINFO                                                       STD_OFF
#define COM_ISDEF_TXBUFFERUSEDOFTXPDUINFO                                                           STD_OFF
#define COM_ISDEF_TXMODEINFOIDXOFTXPDUINFO                                                          STD_OFF
#define COM_ISDEF_TXPDUINITVALUEENDIDXOFTXPDUINFO                                                   STD_OFF
#define COM_ISDEF_TXPDUINITVALUESTARTIDXOFTXPDUINFO                                                 STD_OFF
#define COM_ISDEF_TXPDUINITVALUEUSEDOFTXPDUINFO                                                     STD_OFF
#define COM_ISDEF_TYPEOFTXPDUINFO                                                                   STD_OFF
#define COM_ISDEF_TXPDUINFOIND                                                                      STD_OFF
#define COM_ISDEF_TXPDUINFOOFMAINFUNCTIONTXIND                                                      STD_OFF
#define COM_ISDEF_TXPDUINITVALUE                                                                    STD_OFF
#define COM_ISDEF_APPLTYPEOFTXSIGINFO                                                               STD_OFF
#define COM_ISDEF_BITLENGTHOFTXSIGINFO                                                              STD_OFF
#define COM_ISDEF_BITPOSITIONOFTXSIGINFO                                                            STD_OFF
#define COM_ISDEF_BUSACCOFTXSIGINFO                                                                 STD_OFF
#define COM_ISDEF_BYTELENGTHOFTXSIGINFO                                                             STD_OFF
#define COM_ISDEF_BYTEPOSITIONOFTXSIGINFO                                                           STD_OFF
#define COM_ISDEF_DYNSIGNALOFTXSIGINFO                                                              STD_OFF
#define COM_ISDEF_STARTBYTEINPDUPOSITIONOFTXSIGINFO                                                 STD_OFF
#define COM_ISDEF_TXACCESSINFOIDXOFTXSIGINFO                                                        STD_OFF
#define COM_ISDEF_TXBUFFERENDIDXOFTXSIGINFO                                                         STD_OFF
#define COM_ISDEF_TXBUFFERLENGTHOFTXSIGINFO                                                         STD_OFF
#define COM_ISDEF_TXBUFFERSTARTIDXOFTXSIGINFO                                                       STD_OFF
#define COM_ISDEF_TXBUFFERUSEDOFTXSIGINFO                                                           STD_OFF
#define COM_ISDEF_TXPDUINFOIDXOFTXSIGINFO                                                           STD_OFF
#define COM_ISDEF_ALWAYSACTIVETXCOMIPDUSOFPCCONFIG                                                  STD_ON
#define COM_ISDEF_CONSTVALUEUINT8OFPCCONFIG                                                         STD_ON
#define COM_ISDEF_CURRENTTXMODEOFPCCONFIG                                                           STD_ON
#define COM_ISDEF_CYCLETIMECNTOFPCCONFIG                                                            STD_ON
#define COM_ISDEF_CYCLICSENDREQUESTOFPCCONFIG                                                       STD_ON
#define COM_ISDEF_HANDLERXPDUDEFERREDOFPCCONFIG                                                     STD_ON
#define COM_ISDEF_IPDUGROUPINFOOFPCCONFIG                                                           STD_ON
#define COM_ISDEF_IPDUGROUPINFOOFRXPDUINFOINDOFPCCONFIG                                             STD_ON
#define COM_ISDEF_IPDUGROUPINFOOFTXPDUINFOINDOFPCCONFIG                                             STD_ON
#define COM_ISDEF_IPDUGROUPINFOTOSUBIPDUGROUPSINDOFPCCONFIG                                         STD_ON
#define COM_ISDEF_IPDUGROUPSTATEOFPCCONFIG                                                          STD_ON
#define COM_ISDEF_INITIALIZEDOFPCCONFIG                                                             STD_ON
#define COM_ISDEF_MAINFUNCTIONRXSTRUCTOFPCCONFIG                                                    STD_ON
#define COM_ISDEF_MAINFUNCTIONTXSTRUCTOFPCCONFIG                                                    STD_ON
#define COM_ISDEF_PARTITIONSALWAYSACTIVETXCOMIPDUSSTRUCTOFPCCONFIG                                  STD_ON
#define COM_ISDEF_PARTITIONSRXSTRUCTOFPCCONFIG                                                      STD_ON
#define COM_ISDEF_PARTITIONSTXSTRUCTOFPCCONFIG                                                      STD_ON
#define COM_ISDEF_RXACCESSINFOINDOFPCCONFIG                                                         STD_ON
#define COM_ISDEF_RXACCESSINFOOFPCCONFIG                                                            STD_ON
#define COM_ISDEF_RXDEFPDUBUFFEROFPCCONFIG                                                          STD_ON
#define COM_ISDEF_RXIPDUGROUPISRLOCKCOUNTEROFPCCONFIG                                               STD_ON
#define COM_ISDEF_RXMAINFUNCTIONPROCESSINGISRLOCKCOUNTEROFPCCONFIG                                  STD_ON
#define COM_ISDEF_RXPDUGRPACTIVEOFPCCONFIG                                                          STD_ON
#define COM_ISDEF_RXPDUINFOINDOFPCCONFIG                                                            STD_ON
#define COM_ISDEF_RXPDUINFOOFMAINFUNCTIONRXINDOFPCCONFIG                                            STD_ON
#define COM_ISDEF_RXPDUINFOOFPCCONFIG                                                               STD_ON
#define COM_ISDEF_RXSIGBUFFERUINT8OFPCCONFIG                                                        STD_ON
#define COM_ISDEF_RXSIGINFOOFPCCONFIG                                                               STD_ON
#define COM_ISDEF_TRANSMITREQUESTOFPCCONFIG                                                         STD_ON
#define COM_ISDEF_TXACCESSINFOOFPCCONFIG                                                            STD_ON
#define COM_ISDEF_TXBUFFEROFPCCONFIG                                                                STD_ON
#define COM_ISDEF_TXCYCLICPDUOFMAINFUNCTIONTXINDOFPCCONFIG                                          STD_ON
#define COM_ISDEF_TXCYCLICPDUOFPCCONFIG                                                             STD_ON
#define COM_ISDEF_TXIPDUGROUPISRLOCKCOUNTEROFPCCONFIG                                               STD_ON
#define COM_ISDEF_TXMODEFALSEOFPCCONFIG                                                             STD_ON
#define COM_ISDEF_TXMODEINFOOFPCCONFIG                                                              STD_ON
#define COM_ISDEF_TXMODETRUEOFPCCONFIG                                                              STD_ON
#define COM_ISDEF_TXPDUGRPACTIVEOFPCCONFIG                                                          STD_ON
#define COM_ISDEF_TXPDUINFOINDOFPCCONFIG                                                            STD_ON
#define COM_ISDEF_TXPDUINFOOFMAINFUNCTIONTXINDOFPCCONFIG                                            STD_ON
#define COM_ISDEF_TXPDUINFOOFPCCONFIG                                                               STD_ON
#define COM_ISDEF_TXPDUINITVALUEOFPCCONFIG                                                          STD_ON
#define COM_ISDEF_TXPROCESSINGISRLOCKCOUNTEROFPCCONFIG                                              STD_ON
#define COM_ISDEF_TXSDULENGTHOFPCCONFIG                                                             STD_ON
#define COM_ISDEF_TXSIGINFOOFPCCONFIG                                                               STD_ON
/** 
  \}
*/ 

/** 
  \defgroup  ComPCEqualsAlwaysToDefines  Com Equals Always To Defines (PRE_COMPILE)
  \brief  If all values in a CONST array or an element in a CONST array of structs are equal, the define contains the always equals value.
  \{
*/ 
#define COM_EQ2_PARTITIONSALWAYSACTIVETXCOMIPDUSSTRUCTIDXOFALWAYSACTIVETXCOMIPDUS                   
#define COM_EQ2_TXPDUINFOIDXOFALWAYSACTIVETXCOMIPDUS                                                
#define COM_EQ2_CONSTVALUEUINT8                                                                     
#define COM_EQ2_IPDUGROUPINFOTOSUBIPDUGROUPSINDENDIDXOFIPDUGROUPINFO                                
#define COM_EQ2_IPDUGROUPINFOTOSUBIPDUGROUPSINDSTARTIDXOFIPDUGROUPINFO                              
#define COM_EQ2_IPDUGROUPINFOTOSUBIPDUGROUPSINDUSEDOFIPDUGROUPINFO                                  
#define COM_EQ2_PARTITIONSRXSTRUCTIDXOFIPDUGROUPINFO                                                
#define COM_EQ2_PARTITIONSRXSTRUCTUSEDOFIPDUGROUPINFO                                               
#define COM_EQ2_PARTITIONSTXSTRUCTIDXOFIPDUGROUPINFO                                                
#define COM_EQ2_PARTITIONSTXSTRUCTUSEDOFIPDUGROUPINFO                                               
#define COM_EQ2_RXPDUINFOINDENDIDXOFIPDUGROUPINFO                                                   
#define COM_EQ2_RXPDUINFOINDSTARTIDXOFIPDUGROUPINFO                                                 
#define COM_EQ2_RXPDUINFOINDUSEDOFIPDUGROUPINFO                                                     
#define COM_EQ2_TXPDUINFOINDENDIDXOFIPDUGROUPINFO                                                   
#define COM_EQ2_TXPDUINFOINDSTARTIDXOFIPDUGROUPINFO                                                 
#define COM_EQ2_TXPDUINFOINDUSEDOFIPDUGROUPINFO                                                     
#define COM_EQ2_IPDUGROUPINFOOFRXPDUINFOIND                                                         
#define COM_EQ2_IPDUGROUPINFOOFTXPDUINFOIND                                                         
#define COM_EQ2_IPDUGROUPINFOTOSUBIPDUGROUPSIND                                                     
#define COM_EQ2_RXMAINFUNCTIONPROCESSINGISRLOCKCOUNTERIDXOFMAINFUNCTIONRXSTRUCT                     
#define COM_EQ2_RXPDUINFOOFMAINFUNCTIONRXINDENDIDXOFMAINFUNCTIONRXSTRUCT                            
#define COM_EQ2_RXPDUINFOOFMAINFUNCTIONRXINDSTARTIDXOFMAINFUNCTIONRXSTRUCT                          
#define COM_EQ2_RXPDUINFOOFMAINFUNCTIONRXINDUSEDOFMAINFUNCTIONRXSTRUCT                              
#define COM_EQ2_TXCYCLICPDUOFMAINFUNCTIONTXINDENDIDXOFMAINFUNCTIONTXSTRUCT                          
#define COM_EQ2_TXCYCLICPDUOFMAINFUNCTIONTXINDSTARTIDXOFMAINFUNCTIONTXSTRUCT                        
#define COM_EQ2_TXCYCLICPDUOFMAINFUNCTIONTXINDUSEDOFMAINFUNCTIONTXSTRUCT                            
#define COM_EQ2_TXPDUINFOOFMAINFUNCTIONTXINDENDIDXOFMAINFUNCTIONTXSTRUCT                            
#define COM_EQ2_TXPDUINFOOFMAINFUNCTIONTXINDSTARTIDXOFMAINFUNCTIONTXSTRUCT                          
#define COM_EQ2_TXPDUINFOOFMAINFUNCTIONTXINDUSEDOFMAINFUNCTIONTXSTRUCT                              
#define COM_EQ2_TXPROCESSINGISRLOCKCOUNTERIDXOFMAINFUNCTIONTXSTRUCT                                 
#define COM_EQ2_TXIPDUGROUPISRLOCKCOUNTERIDXOFPARTITIONSALWAYSACTIVETXCOMIPDUSSTRUCT                
#define COM_EQ2_RXIPDUGROUPISRLOCKCOUNTERIDXOFPARTITIONSRXSTRUCT                                    
#define COM_EQ2_TXIPDUGROUPISRLOCKCOUNTERIDXOFPARTITIONSTXSTRUCT                                    
#define COM_EQ2_APPLTYPEOFRXACCESSINFO                                                              
#define COM_EQ2_BITLENGTHOFRXACCESSINFO                                                             
#define COM_EQ2_BITPOSITIONOFRXACCESSINFO                                                           
#define COM_EQ2_BUFFERIDXOFRXACCESSINFO                                                             
#define COM_EQ2_BUFFEROFRXACCESSINFO                                                                
#define COM_EQ2_BUFFERUSEDOFRXACCESSINFO                                                            
#define COM_EQ2_BUSACCOFRXACCESSINFO                                                                
#define COM_EQ2_BYTELENGTHOFRXACCESSINFO                                                            
#define COM_EQ2_BYTEPOSITIONOFRXACCESSINFO                                                          
#define COM_EQ2_DYNSIGNALOFRXACCESSINFO                                                             
#define COM_EQ2_INITVALUEIDXOFRXACCESSINFO                                                          
#define COM_EQ2_INITVALUEOFRXACCESSINFO                                                             
#define COM_EQ2_INITVALUEUSEDOFRXACCESSINFO                                                         
#define COM_EQ2_RXPDUINFOIDXOFRXACCESSINFO                                                          
#define COM_EQ2_SIGNALLENGTHINBYTEOFRXACCESSINFO                                                    
#define COM_EQ2_STARTBYTEINPDUPOSITIONOFRXACCESSINFO                                                
#define COM_EQ2_RXACCESSINFOIND                                                                     
#define COM_EQ2_HANDLERXPDUDEFERREDIDXOFRXPDUINFO                                                   
#define COM_EQ2_HANDLERXPDUDEFERREDUSEDOFRXPDUINFO                                                  
#define COM_EQ2_IPDUGROUPINFOOFRXPDUINFOINDENDIDXOFRXPDUINFO                                        
#define COM_EQ2_IPDUGROUPINFOOFRXPDUINFOINDSTARTIDXOFRXPDUINFO                                      
#define COM_EQ2_IPDUGROUPINFOOFRXPDUINFOINDUSEDOFRXPDUINFO                                          
#define COM_EQ2_MAINFUNCTIONRXSTRUCTIDXOFRXPDUINFO                                                  
#define COM_EQ2_MAINFUNCTIONRXSTRUCTUSEDOFRXPDUINFO                                                 
#define COM_EQ2_PARTITIONSRXSTRUCTIDXOFRXPDUINFO                                                    
#define COM_EQ2_RXACCESSINFOINDENDIDXOFRXPDUINFO                                                    
#define COM_EQ2_RXACCESSINFOINDSTARTIDXOFRXPDUINFO                                                  
#define COM_EQ2_RXACCESSINFOINDUSEDOFRXPDUINFO                                                      
#define COM_EQ2_RXDEFPDUBUFFERENDIDXOFRXPDUINFO                                                     
#define COM_EQ2_RXDEFPDUBUFFERLENGTHOFRXPDUINFO                                                     
#define COM_EQ2_RXDEFPDUBUFFERSTARTIDXOFRXPDUINFO                                                   
#define COM_EQ2_RXDEFPDUBUFFERUSEDOFRXPDUINFO                                                       
#define COM_EQ2_RXSIGINFOENDIDXOFRXPDUINFO                                                          
#define COM_EQ2_RXSIGINFOSTARTIDXOFRXPDUINFO                                                        
#define COM_EQ2_RXSIGINFOUSEDOFRXPDUINFO                                                            
#define COM_EQ2_SIGNALPROCESSINGOFRXPDUINFO                                                         
#define COM_EQ2_TYPEOFRXPDUINFO                                                                     
#define COM_EQ2_RXPDUINFOIND                                                                        
#define COM_EQ2_RXPDUINFOOFMAINFUNCTIONRXIND                                                        
#define COM_EQ2_RXACCESSINFOIDXOFRXSIGINFO                                                          
#define COM_EQ2_SIGNALPROCESSINGOFRXSIGINFO                                                         
#define COM_EQ2_VALIDDLCOFRXSIGINFO                                                                 
#define COM_EQ2_TXSIGINFOIDXOFTXACCESSINFO                                                          
#define COM_EQ2_TXSIGINFOUSEDOFTXACCESSINFO                                                         
#define COM_EQ2_TXPDUINFOIDXOFTXCYCLICPDU                                                           
#define COM_EQ2_TXCYCLICPDUOFMAINFUNCTIONTXIND                                                      
#define COM_EQ2_PERIODICOFTXMODEFALSE                                                               
#define COM_EQ2_TIMEPERIODOFTXMODEFALSE                                                             
#define COM_EQ2_INITMODEOFTXMODEINFO                                                                
#define COM_EQ2_TXMODEFALSEIDXOFTXMODEINFO                                                          
#define COM_EQ2_TXMODETRUEIDXOFTXMODEINFO                                                           
#define COM_EQ2_PERIODICOFTXMODETRUE                                                                
#define COM_EQ2_TIMEPERIODOFTXMODETRUE                                                              
#define COM_EQ2_EXTERNALIDOFTXPDUINFO                                                               
#define COM_EQ2_IPDUGROUPINFOOFTXPDUINFOINDENDIDXOFTXPDUINFO                                        
#define COM_EQ2_IPDUGROUPINFOOFTXPDUINFOINDSTARTIDXOFTXPDUINFO                                      
#define COM_EQ2_IPDUGROUPINFOOFTXPDUINFOINDUSEDOFTXPDUINFO                                          
#define COM_EQ2_METADATALENGTHOFTXPDUINFO                                                           
#define COM_EQ2_PARTITIONSTXSTRUCTIDXOFTXPDUINFO                                                    
#define COM_EQ2_PDUWITHMETADATALENGTHOFTXPDUINFO                                                    
#define COM_EQ2_TXBUFFERENDIDXOFTXPDUINFO                                                           
#define COM_EQ2_TXBUFFERLENGTHOFTXPDUINFO                                                           
#define COM_EQ2_TXBUFFERSTARTIDXOFTXPDUINFO                                                         
#define COM_EQ2_TXBUFFERUSEDOFTXPDUINFO                                                             
#define COM_EQ2_TXMODEINFOIDXOFTXPDUINFO                                                            
#define COM_EQ2_TXPDUINITVALUEENDIDXOFTXPDUINFO                                                     
#define COM_EQ2_TXPDUINITVALUESTARTIDXOFTXPDUINFO                                                   
#define COM_EQ2_TXPDUINITVALUEUSEDOFTXPDUINFO                                                       
#define COM_EQ2_TYPEOFTXPDUINFO                                                                     
#define COM_EQ2_TXPDUINFOIND                                                                        
#define COM_EQ2_TXPDUINFOOFMAINFUNCTIONTXIND                                                        
#define COM_EQ2_TXPDUINITVALUE                                                                      
#define COM_EQ2_APPLTYPEOFTXSIGINFO                                                                 
#define COM_EQ2_BITLENGTHOFTXSIGINFO                                                                
#define COM_EQ2_BITPOSITIONOFTXSIGINFO                                                              
#define COM_EQ2_BUSACCOFTXSIGINFO                                                                   
#define COM_EQ2_BYTELENGTHOFTXSIGINFO                                                               
#define COM_EQ2_BYTEPOSITIONOFTXSIGINFO                                                             
#define COM_EQ2_DYNSIGNALOFTXSIGINFO                                                                
#define COM_EQ2_STARTBYTEINPDUPOSITIONOFTXSIGINFO                                                   
#define COM_EQ2_TXACCESSINFOIDXOFTXSIGINFO                                                          
#define COM_EQ2_TXBUFFERENDIDXOFTXSIGINFO                                                           
#define COM_EQ2_TXBUFFERLENGTHOFTXSIGINFO                                                           
#define COM_EQ2_TXBUFFERSTARTIDXOFTXSIGINFO                                                         
#define COM_EQ2_TXBUFFERUSEDOFTXSIGINFO                                                             
#define COM_EQ2_TXPDUINFOIDXOFTXSIGINFO                                                             
#define COM_EQ2_ALWAYSACTIVETXCOMIPDUSOFPCCONFIG                                                    Com_AlwaysActiveTxComIPdus
#define COM_EQ2_CONSTVALUEUINT8OFPCCONFIG                                                           Com_ConstValueUInt8
#define COM_EQ2_CURRENTTXMODEOFPCCONFIG                                                             Com_CurrentTxMode.raw
#define COM_EQ2_CYCLETIMECNTOFPCCONFIG                                                              Com_CycleTimeCnt.raw
#define COM_EQ2_CYCLICSENDREQUESTOFPCCONFIG                                                         Com_CyclicSendRequest.raw
#define COM_EQ2_HANDLERXPDUDEFERREDOFPCCONFIG                                                       Com_HandleRxPduDeferred.raw
#define COM_EQ2_IPDUGROUPINFOOFPCCONFIG                                                             Com_IPduGroupInfo
#define COM_EQ2_IPDUGROUPINFOOFRXPDUINFOINDOFPCCONFIG                                               Com_IPduGroupInfoOfRxPduInfoInd
#define COM_EQ2_IPDUGROUPINFOOFTXPDUINFOINDOFPCCONFIG                                               Com_IPduGroupInfoOfTxPduInfoInd
#define COM_EQ2_IPDUGROUPINFOTOSUBIPDUGROUPSINDOFPCCONFIG                                           Com_IPduGroupInfoToSubIPduGroupsInd
#define COM_EQ2_IPDUGROUPSTATEOFPCCONFIG                                                            Com_IPduGroupState
#define COM_EQ2_INITIALIZEDOFPCCONFIG                                                               (&(Com_Initialized))
#define COM_EQ2_MAINFUNCTIONRXSTRUCTOFPCCONFIG                                                      Com_MainFunctionRxStruct
#define COM_EQ2_MAINFUNCTIONTXSTRUCTOFPCCONFIG                                                      Com_MainFunctionTxStruct
#define COM_EQ2_PARTITIONSALWAYSACTIVETXCOMIPDUSSTRUCTOFPCCONFIG                                    Com_PartitionsAlwaysActiveTxComIPdusStruct
#define COM_EQ2_PARTITIONSRXSTRUCTOFPCCONFIG                                                        Com_PartitionsRxStruct
#define COM_EQ2_PARTITIONSTXSTRUCTOFPCCONFIG                                                        Com_PartitionsTxStruct
#define COM_EQ2_RXACCESSINFOINDOFPCCONFIG                                                           Com_RxAccessInfoInd
#define COM_EQ2_RXACCESSINFOOFPCCONFIG                                                              Com_RxAccessInfo
#define COM_EQ2_RXDEFPDUBUFFEROFPCCONFIG                                                            Com_RxDefPduBuffer.raw
#define COM_EQ2_RXIPDUGROUPISRLOCKCOUNTEROFPCCONFIG                                                 Com_RxIPduGroupISRLockCounter.raw
#define COM_EQ2_RXMAINFUNCTIONPROCESSINGISRLOCKCOUNTEROFPCCONFIG                                    Com_RxMainFunctionProcessingISRLockCounter.raw
#define COM_EQ2_RXPDUGRPACTIVEOFPCCONFIG                                                            Com_RxPduGrpActive
#define COM_EQ2_RXPDUINFOINDOFPCCONFIG                                                              Com_RxPduInfoInd
#define COM_EQ2_RXPDUINFOOFMAINFUNCTIONRXINDOFPCCONFIG                                              Com_RxPduInfoOfMainFunctionRxInd
#define COM_EQ2_RXPDUINFOOFPCCONFIG                                                                 Com_RxPduInfo
#define COM_EQ2_RXSIGBUFFERUINT8OFPCCONFIG                                                          Com_RxSigBufferUInt8
#define COM_EQ2_RXSIGINFOOFPCCONFIG                                                                 Com_RxSigInfo
#define COM_EQ2_TRANSMITREQUESTOFPCCONFIG                                                           Com_TransmitRequest.raw
#define COM_EQ2_TXACCESSINFOOFPCCONFIG                                                              Com_TxAccessInfo
#define COM_EQ2_TXBUFFEROFPCCONFIG                                                                  Com_TxBuffer
#define COM_EQ2_TXCYCLICPDUOFMAINFUNCTIONTXINDOFPCCONFIG                                            Com_TxCyclicPduOfMainFunctionTxInd
#define COM_EQ2_TXCYCLICPDUOFPCCONFIG                                                               Com_TxCyclicPdu
#define COM_EQ2_TXIPDUGROUPISRLOCKCOUNTEROFPCCONFIG                                                 Com_TxIPduGroupISRLockCounter.raw
#define COM_EQ2_TXMODEFALSEOFPCCONFIG                                                               Com_TxModeFalse
#define COM_EQ2_TXMODEINFOOFPCCONFIG                                                                Com_TxModeInfo
#define COM_EQ2_TXMODETRUEOFPCCONFIG                                                                Com_TxModeTrue
#define COM_EQ2_TXPDUGRPACTIVEOFPCCONFIG                                                            Com_TxPduGrpActive
#define COM_EQ2_TXPDUINFOINDOFPCCONFIG                                                              Com_TxPduInfoInd
#define COM_EQ2_TXPDUINFOOFMAINFUNCTIONTXINDOFPCCONFIG                                              Com_TxPduInfoOfMainFunctionTxInd
#define COM_EQ2_TXPDUINFOOFPCCONFIG                                                                 Com_TxPduInfo
#define COM_EQ2_TXPDUINITVALUEOFPCCONFIG                                                            Com_TxPduInitValue
#define COM_EQ2_TXPROCESSINGISRLOCKCOUNTEROFPCCONFIG                                                Com_TxProcessingISRLockCounter.raw
#define COM_EQ2_TXSDULENGTHOFPCCONFIG                                                               Com_TxSduLength
#define COM_EQ2_TXSIGINFOOFPCCONFIG                                                                 Com_TxSigInfo
/** 
  \}
*/ 

/** 
  \defgroup  ComPCSymbolicInitializationPointers  Com Symbolic Initialization Pointers (PRE_COMPILE)
  \brief  Symbolic initialization pointers to be used in the call of a preinit or init function.
  \{
*/ 
#define Com_Config_Ptr                                                                              NULL_PTR  /**< symbolic identifier which shall be used to initialize 'Com' */
/** 
  \}
*/ 

/** 
  \defgroup  ComPCInitializationSymbols  Com Initialization Symbols (PRE_COMPILE)
  \brief  Symbolic initialization pointers which may be used in the call of a preinit or init function. Please note, that the defined value can be a 'NULL_PTR' and the address operator is not usable.
  \{
*/ 
#define Com_Config                                                                                  NULL_PTR  /**< symbolic identifier which could be used to initialize 'Com */
/** 
  \}
*/ 

/** 
  \defgroup  ComPCGeneral  Com General (PRE_COMPILE)
  \brief  General constant defines not associated with a group of defines.
  \{
*/ 
#define COM_CHECK_INIT_POINTER                                                                      STD_OFF  /**< STD_ON if the init pointer shall not be used as NULL_PTR and a check shall validate this. */
#define COM_FINAL_MAGIC_NUMBER                                                                      0x321Eu  /**< the precompile constant to validate the size of the initialization structure at initialization time of Com */
#define COM_INDIVIDUAL_POSTBUILD                                                                    STD_OFF  /**< the precompile constant to check, that the module is individual postbuildable. The module 'Com' is not configured to be postbuild capable. */
#define COM_INIT_DATA                                                                               COM_CONST  /**< CompilerMemClassDefine for the initialization data. */
#define COM_INIT_DATA_HASH_CODE                                                                     -917688657  /**< the precompile constant to validate the initialization structure at initialization time of Com with a hashcode. The seed value is '0x321Eu' */
#define COM_USE_ECUM_BSW_ERROR_HOOK                                                                 STD_OFF  /**< STD_ON if the EcuM_BswErrorHook shall be called in the ConfigPtr check. */
#define COM_USE_INIT_POINTER                                                                        STD_OFF  /**< STD_ON if the init pointer Com shall be used. */
/** 
  \}
*/ 


/**********************************************************************************************************************
  CONFIGURATION CLASS: LINK
  SECTION: GLOBAL CONSTANT MACROS
**********************************************************************************************************************/
/** 
  \defgroup  ComLTDataSwitches  Com Data Switches  (LINK)
  \brief  These defines are used to deactivate data and their processing.
  \{
*/ 
#define COM_LTCONFIG                                                                                STD_OFF  /**< Deactivateable: 'Com_LTConfig' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' */
/** 
  \}
*/ 



/**********************************************************************************************************************
  GLOBAL FUNCTION MACROS
**********************************************************************************************************************/
/** 
  \defgroup  DataAccessMacros  Data Access Macros
  \brief  generated data access macros to abstract the generated data from the code to read and write CONST or VAR data.
  \{
*/ 
  /* PRQA S 3453 Macros_3453 */  /* MD_MSR_FctLikeMacro */
/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL FUNCTION MACROS
**********************************************************************************************************************/
/** 
  \defgroup  ComPCGetConstantDuplicatedRootDataMacros  Com Get Constant Duplicated Root Data Macros (PRE_COMPILE)
  \brief  These macros can be used to read deduplicated by constance root data elements.
  \{
*/ 
#define Com_GetAlwaysActiveTxComIPdusOfPCConfig()                                                   Com_AlwaysActiveTxComIPdus  /**< the pointer to Com_AlwaysActiveTxComIPdus */
#define Com_GetConfigIdOfPCConfig()                                                                 0u  /**< DefinitionRef: /MICROSAR/Com/ComConfig/ComConfigurationId */
#define Com_GetConstValueUInt8OfPCConfig()                                                          Com_ConstValueUInt8  /**< the pointer to Com_ConstValueUInt8 */
#define Com_GetCurrentTxModeOfPCConfig()                                                            Com_CurrentTxMode.raw  /**< the pointer to Com_CurrentTxMode */
#define Com_GetCycleTimeCntOfPCConfig()                                                             Com_CycleTimeCnt.raw  /**< the pointer to Com_CycleTimeCnt */
#define Com_GetCyclicSendRequestOfPCConfig()                                                        Com_CyclicSendRequest.raw  /**< the pointer to Com_CyclicSendRequest */
#define Com_GetHandleRxPduDeferredOfPCConfig()                                                      Com_HandleRxPduDeferred.raw  /**< the pointer to Com_HandleRxPduDeferred */
#define Com_GetIPduGroupInfoOfPCConfig()                                                            Com_IPduGroupInfo  /**< the pointer to Com_IPduGroupInfo */
#define Com_GetIPduGroupInfoOfRxPduInfoIndOfPCConfig()                                              Com_IPduGroupInfoOfRxPduInfoInd  /**< the pointer to Com_IPduGroupInfoOfRxPduInfoInd */
#define Com_GetIPduGroupInfoOfTxPduInfoIndOfPCConfig()                                              Com_IPduGroupInfoOfTxPduInfoInd  /**< the pointer to Com_IPduGroupInfoOfTxPduInfoInd */
#define Com_GetIPduGroupInfoToSubIPduGroupsIndOfPCConfig()                                          Com_IPduGroupInfoToSubIPduGroupsInd  /**< the pointer to Com_IPduGroupInfoToSubIPduGroupsInd */
#define Com_GetIPduGroupStateOfPCConfig()                                                           Com_IPduGroupState  /**< the pointer to Com_IPduGroupState */
#define Com_GetInitializedOfPCConfig()                                                              (&(Com_Initialized))  /**< the pointer to Com_Initialized */
#define Com_GetMainFunctionRxStructOfPCConfig()                                                     Com_MainFunctionRxStruct  /**< the pointer to Com_MainFunctionRxStruct */
#define Com_GetMainFunctionTxStructOfPCConfig()                                                     Com_MainFunctionTxStruct  /**< the pointer to Com_MainFunctionTxStruct */
#define Com_GetPartitionsAlwaysActiveTxComIPdusStructOfPCConfig()                                   Com_PartitionsAlwaysActiveTxComIPdusStruct  /**< the pointer to Com_PartitionsAlwaysActiveTxComIPdusStruct */
#define Com_GetPartitionsRxStructOfPCConfig()                                                       Com_PartitionsRxStruct  /**< the pointer to Com_PartitionsRxStruct */
#define Com_GetPartitionsTxStructOfPCConfig()                                                       Com_PartitionsTxStruct  /**< the pointer to Com_PartitionsTxStruct */
#define Com_GetPduGrpCntOfPCConfig()                                                                0u
#define Com_GetRxAccessInfoIndOfPCConfig()                                                          Com_RxAccessInfoInd  /**< the pointer to Com_RxAccessInfoInd */
#define Com_GetRxAccessInfoOfPCConfig()                                                             Com_RxAccessInfo  /**< the pointer to Com_RxAccessInfo */
#define Com_GetRxDefPduBufferOfPCConfig()                                                           Com_RxDefPduBuffer.raw  /**< the pointer to Com_RxDefPduBuffer */
#define Com_GetRxIPduGroupISRLockCounterOfPCConfig()                                                Com_RxIPduGroupISRLockCounter.raw  /**< the pointer to Com_RxIPduGroupISRLockCounter */
#define Com_GetRxIPduGroupISRLockThresholdOfPCConfig()                                              1u
#define Com_GetRxMainFunctionProcessingISRLockCounterOfPCConfig()                                   Com_RxMainFunctionProcessingISRLockCounter.raw  /**< the pointer to Com_RxMainFunctionProcessingISRLockCounter */
#define Com_GetRxMainFunctionProcessingISRLockThresholdOfPCConfig()                                 1u
#define Com_GetRxPduGrpActiveOfPCConfig()                                                           Com_RxPduGrpActive  /**< the pointer to Com_RxPduGrpActive */
#define Com_GetRxPduInfoIndOfPCConfig()                                                             Com_RxPduInfoInd  /**< the pointer to Com_RxPduInfoInd */
#define Com_GetRxPduInfoOfMainFunctionRxIndOfPCConfig()                                             Com_RxPduInfoOfMainFunctionRxInd  /**< the pointer to Com_RxPduInfoOfMainFunctionRxInd */
#define Com_GetRxPduInfoOfPCConfig()                                                                Com_RxPduInfo  /**< the pointer to Com_RxPduInfo */
#define Com_GetRxSigBufferUInt8OfPCConfig()                                                         Com_RxSigBufferUInt8  /**< the pointer to Com_RxSigBufferUInt8 */
#define Com_GetRxSigInfoOfPCConfig()                                                                Com_RxSigInfo  /**< the pointer to Com_RxSigInfo */
#define Com_GetSizeOfAlwaysActiveTxComIPdusOfPCConfig()                                             1u  /**< the number of accomplishable value elements in Com_AlwaysActiveTxComIPdus */
#define Com_GetSizeOfConstValueUInt8OfPCConfig()                                                    1u  /**< the number of accomplishable value elements in Com_ConstValueUInt8 */
#define Com_GetSizeOfHandleRxPduDeferredOfPCConfig()                                                1u  /**< the number of accomplishable value elements in Com_HandleRxPduDeferred */
#define Com_GetSizeOfIPduGroupInfoOfPCConfig()                                                      2u  /**< the number of accomplishable value elements in Com_IPduGroupInfo */
#define Com_GetSizeOfIPduGroupInfoOfRxPduInfoIndOfPCConfig()                                        1u  /**< the number of accomplishable value elements in Com_IPduGroupInfoOfRxPduInfoInd */
#define Com_GetSizeOfIPduGroupInfoOfTxPduInfoIndOfPCConfig()                                        2u  /**< the number of accomplishable value elements in Com_IPduGroupInfoOfTxPduInfoInd */
#define Com_GetSizeOfIPduGroupInfoToSubIPduGroupsIndOfPCConfig()                                    2u  /**< the number of accomplishable value elements in Com_IPduGroupInfoToSubIPduGroupsInd */
#define Com_GetSizeOfMainFunctionRxStructOfPCConfig()                                               1u  /**< the number of accomplishable value elements in Com_MainFunctionRxStruct */
#define Com_GetSizeOfMainFunctionTxStructOfPCConfig()                                               1u  /**< the number of accomplishable value elements in Com_MainFunctionTxStruct */
#define Com_GetSizeOfPartitionsAlwaysActiveTxComIPdusStructOfPCConfig()                             1u  /**< the number of accomplishable value elements in Com_PartitionsAlwaysActiveTxComIPdusStruct */
#define Com_GetSizeOfPartitionsRxStructOfPCConfig()                                                 1u  /**< the number of accomplishable value elements in Com_PartitionsRxStruct */
#define Com_GetSizeOfPartitionsTxStructOfPCConfig()                                                 1u  /**< the number of accomplishable value elements in Com_PartitionsTxStruct */
#define Com_GetSizeOfRxAccessInfoIndOfPCConfig()                                                    2u  /**< the number of accomplishable value elements in Com_RxAccessInfoInd */
#define Com_GetSizeOfRxAccessInfoOfPCConfig()                                                       2u  /**< the number of accomplishable value elements in Com_RxAccessInfo */
#define Com_GetSizeOfRxDefPduBufferOfPCConfig()                                                     1u  /**< the number of accomplishable value elements in Com_RxDefPduBuffer */
#define Com_GetSizeOfRxIPduGroupISRLockCounterOfPCConfig()                                          1u  /**< the number of accomplishable value elements in Com_RxIPduGroupISRLockCounter */
#define Com_GetSizeOfRxMainFunctionProcessingISRLockCounterOfPCConfig()                             1u  /**< the number of accomplishable value elements in Com_RxMainFunctionProcessingISRLockCounter */
#define Com_GetSizeOfRxPduInfoIndOfPCConfig()                                                       1u  /**< the number of accomplishable value elements in Com_RxPduInfoInd */
#define Com_GetSizeOfRxPduInfoOfMainFunctionRxIndOfPCConfig()                                       1u  /**< the number of accomplishable value elements in Com_RxPduInfoOfMainFunctionRxInd */
#define Com_GetSizeOfRxPduInfoOfPCConfig()                                                          1u  /**< the number of accomplishable value elements in Com_RxPduInfo */
#define Com_GetSizeOfRxSigBufferUInt8OfPCConfig()                                                   2u  /**< the number of accomplishable value elements in Com_RxSigBufferUInt8 */
#define Com_GetSizeOfRxSigInfoOfPCConfig()                                                          2u  /**< the number of accomplishable value elements in Com_RxSigInfo */
#define Com_GetSizeOfTxAccessInfoOfPCConfig()                                                       13u  /**< the number of accomplishable value elements in Com_TxAccessInfo */
#define Com_GetSizeOfTxBufferOfPCConfig()                                                           20u  /**< the number of accomplishable value elements in Com_TxBuffer */
#define Com_GetSizeOfTxCyclicPduOfMainFunctionTxIndOfPCConfig()                                     2u  /**< the number of accomplishable value elements in Com_TxCyclicPduOfMainFunctionTxInd */
#define Com_GetSizeOfTxCyclicPduOfPCConfig()                                                        2u  /**< the number of accomplishable value elements in Com_TxCyclicPdu */
#define Com_GetSizeOfTxIPduGroupISRLockCounterOfPCConfig()                                          1u  /**< the number of accomplishable value elements in Com_TxIPduGroupISRLockCounter */
#define Com_GetSizeOfTxModeFalseOfPCConfig()                                                        3u  /**< the number of accomplishable value elements in Com_TxModeFalse */
#define Com_GetSizeOfTxModeInfoOfPCConfig()                                                         3u  /**< the number of accomplishable value elements in Com_TxModeInfo */
#define Com_GetSizeOfTxModeTrueOfPCConfig()                                                         3u  /**< the number of accomplishable value elements in Com_TxModeTrue */
#define Com_GetSizeOfTxPduInfoIndOfPCConfig()                                                       2u  /**< the number of accomplishable value elements in Com_TxPduInfoInd */
#define Com_GetSizeOfTxPduInfoOfMainFunctionTxIndOfPCConfig()                                       3u  /**< the number of accomplishable value elements in Com_TxPduInfoOfMainFunctionTxInd */
#define Com_GetSizeOfTxPduInfoOfPCConfig()                                                          3u  /**< the number of accomplishable value elements in Com_TxPduInfo */
#define Com_GetSizeOfTxPduInitValueOfPCConfig()                                                     19u  /**< the number of accomplishable value elements in Com_TxPduInitValue */
#define Com_GetSizeOfTxProcessingISRLockCounterOfPCConfig()                                         1u  /**< the number of accomplishable value elements in Com_TxProcessingISRLockCounter */
#define Com_GetSizeOfTxSigInfoOfPCConfig()                                                          13u  /**< the number of accomplishable value elements in Com_TxSigInfo */
#define Com_GetTransmitRequestOfPCConfig()                                                          Com_TransmitRequest.raw  /**< the pointer to Com_TransmitRequest */
#define Com_GetTxAccessInfoOfPCConfig()                                                             Com_TxAccessInfo  /**< the pointer to Com_TxAccessInfo */
#define Com_GetTxBufferOfPCConfig()                                                                 Com_TxBuffer  /**< the pointer to Com_TxBuffer */
#define Com_GetTxCyclicPduOfMainFunctionTxIndOfPCConfig()                                           Com_TxCyclicPduOfMainFunctionTxInd  /**< the pointer to Com_TxCyclicPduOfMainFunctionTxInd */
#define Com_GetTxCyclicPduOfPCConfig()                                                              Com_TxCyclicPdu  /**< the pointer to Com_TxCyclicPdu */
#define Com_GetTxIPduGroupISRLockCounterOfPCConfig()                                                Com_TxIPduGroupISRLockCounter.raw  /**< the pointer to Com_TxIPduGroupISRLockCounter */
#define Com_GetTxIPduGroupISRLockThresholdOfPCConfig()                                              1u
#define Com_GetTxModeFalseOfPCConfig()                                                              Com_TxModeFalse  /**< the pointer to Com_TxModeFalse */
#define Com_GetTxModeInfoOfPCConfig()                                                               Com_TxModeInfo  /**< the pointer to Com_TxModeInfo */
#define Com_GetTxModeTrueOfPCConfig()                                                               Com_TxModeTrue  /**< the pointer to Com_TxModeTrue */
#define Com_GetTxPduGrpActiveOfPCConfig()                                                           Com_TxPduGrpActive  /**< the pointer to Com_TxPduGrpActive */
#define Com_GetTxPduInfoIndOfPCConfig()                                                             Com_TxPduInfoInd  /**< the pointer to Com_TxPduInfoInd */
#define Com_GetTxPduInfoOfMainFunctionTxIndOfPCConfig()                                             Com_TxPduInfoOfMainFunctionTxInd  /**< the pointer to Com_TxPduInfoOfMainFunctionTxInd */
#define Com_GetTxPduInfoOfPCConfig()                                                                Com_TxPduInfo  /**< the pointer to Com_TxPduInfo */
#define Com_GetTxPduInitValueOfPCConfig()                                                           Com_TxPduInitValue  /**< the pointer to Com_TxPduInitValue */
#define Com_GetTxProcessingISRLockCounterOfPCConfig()                                               Com_TxProcessingISRLockCounter.raw  /**< the pointer to Com_TxProcessingISRLockCounter */
#define Com_GetTxProcessingISRLockThresholdOfPCConfig()                                             1u
#define Com_GetTxSduLengthOfPCConfig()                                                              Com_TxSduLength  /**< the pointer to Com_TxSduLength */
#define Com_GetTxSigInfoOfPCConfig()                                                                Com_TxSigInfo  /**< the pointer to Com_TxSigInfo */
/** 
  \}
*/ 

/** 
  \defgroup  ComPCGetDuplicatedRootDataMacros  Com Get Duplicated Root Data Macros (PRE_COMPILE)
  \brief  These macros can be used to read deduplicated root data elements.
  \{
*/ 
#define Com_GetSizeOfCurrentTxModeOfPCConfig()                                                      Com_GetSizeOfTxModeInfoOfPCConfig()  /**< the number of accomplishable value elements in Com_CurrentTxMode */
#define Com_GetSizeOfCycleTimeCntOfPCConfig()                                                       Com_GetSizeOfTxModeInfoOfPCConfig()  /**< the number of accomplishable value elements in Com_CycleTimeCnt */
#define Com_GetSizeOfCyclicSendRequestOfPCConfig()                                                  Com_GetSizeOfTxModeInfoOfPCConfig()  /**< the number of accomplishable value elements in Com_CyclicSendRequest */
#define Com_GetSizeOfIPduGroupStateOfPCConfig()                                                     Com_GetSizeOfIPduGroupInfoOfPCConfig()  /**< the number of accomplishable value elements in Com_IPduGroupState */
#define Com_GetSizeOfRxPduGrpActiveOfPCConfig()                                                     Com_GetSizeOfRxPduInfoOfPCConfig()  /**< the number of accomplishable value elements in Com_RxPduGrpActive */
#define Com_GetSizeOfTransmitRequestOfPCConfig()                                                    Com_GetSizeOfTxModeInfoOfPCConfig()  /**< the number of accomplishable value elements in Com_TransmitRequest */
#define Com_GetSizeOfTxPduGrpActiveOfPCConfig()                                                     Com_GetSizeOfTxPduInfoOfPCConfig()  /**< the number of accomplishable value elements in Com_TxPduGrpActive */
#define Com_GetSizeOfTxSduLengthOfPCConfig()                                                        Com_GetSizeOfTxPduInfoOfPCConfig()  /**< the number of accomplishable value elements in Com_TxSduLength */
/** 
  \}
*/ 

/** 
  \defgroup  ComPCGetDataMacros  Com Get Data Macros (PRE_COMPILE)
  \brief  These macros can be used to read CONST and VAR data.
  \{
*/ 
#define Com_GetConstValueUInt8(Index)                                                               (Com_GetConstValueUInt8OfPCConfig()[(Index)])
#define Com_IsCurrentTxMode(Index)                                                                  ((Com_GetCurrentTxModeOfPCConfig()[(Index)]) != FALSE)
#define Com_GetCycleTimeCnt(Index)                                                                  (Com_GetCycleTimeCntOfPCConfig()[(Index)])
#define Com_IsCyclicSendRequest(Index)                                                              ((Com_GetCyclicSendRequestOfPCConfig()[(Index)]) != FALSE)
#define Com_GetHandleRxPduDeferred(Index)                                                           (Com_GetHandleRxPduDeferredOfPCConfig()[(Index)])
#define Com_GetIPduGroupInfoToSubIPduGroupsIndStartIdxOfIPduGroupInfo(Index)                        (Com_GetIPduGroupInfoOfPCConfig()[(Index)].IPduGroupInfoToSubIPduGroupsIndStartIdxOfIPduGroupInfo)
#define Com_GetPartitionsRxStructIdxOfIPduGroupInfo(Index)                                          (Com_GetIPduGroupInfoOfPCConfig()[(Index)].PartitionsRxStructIdxOfIPduGroupInfo)
#define Com_GetPartitionsTxStructIdxOfIPduGroupInfo(Index)                                          (Com_GetIPduGroupInfoOfPCConfig()[(Index)].PartitionsTxStructIdxOfIPduGroupInfo)
#define Com_GetRxPduInfoIndEndIdxOfIPduGroupInfo(Index)                                             (Com_GetIPduGroupInfoOfPCConfig()[(Index)].RxPduInfoIndEndIdxOfIPduGroupInfo)
#define Com_GetRxPduInfoIndStartIdxOfIPduGroupInfo(Index)                                           (Com_GetIPduGroupInfoOfPCConfig()[(Index)].RxPduInfoIndStartIdxOfIPduGroupInfo)
#define Com_GetTxPduInfoIndEndIdxOfIPduGroupInfo(Index)                                             (Com_GetIPduGroupInfoOfPCConfig()[(Index)].TxPduInfoIndEndIdxOfIPduGroupInfo)
#define Com_GetTxPduInfoIndStartIdxOfIPduGroupInfo(Index)                                           (Com_GetIPduGroupInfoOfPCConfig()[(Index)].TxPduInfoIndStartIdxOfIPduGroupInfo)
#define Com_GetIPduGroupInfoOfTxPduInfoInd(Index)                                                   (Com_GetIPduGroupInfoOfTxPduInfoIndOfPCConfig()[(Index)])
#define Com_GetIPduGroupState(Index)                                                                (Com_GetIPduGroupStateOfPCConfig()[(Index)])
#define Com_IsInitialized()                                                                         (((*(Com_GetInitializedOfPCConfig()))) != FALSE)
#define Com_GetRxPduInfoOfMainFunctionRxIndStartIdxOfMainFunctionRxStruct(Index)                    (Com_GetMainFunctionRxStructOfPCConfig()[(Index)].RxPduInfoOfMainFunctionRxIndStartIdxOfMainFunctionRxStruct)
#define Com_GetTxCyclicPduOfMainFunctionTxIndStartIdxOfMainFunctionTxStruct(Index)                  (Com_GetMainFunctionTxStructOfPCConfig()[(Index)].TxCyclicPduOfMainFunctionTxIndStartIdxOfMainFunctionTxStruct)
#define Com_GetTxPduInfoOfMainFunctionTxIndStartIdxOfMainFunctionTxStruct(Index)                    (Com_GetMainFunctionTxStructOfPCConfig()[(Index)].TxPduInfoOfMainFunctionTxIndStartIdxOfMainFunctionTxStruct)
#define Com_GetBufferIdxOfRxAccessInfo(Index)                                                       (Com_GetRxAccessInfoOfPCConfig()[(Index)].BufferIdxOfRxAccessInfo)
#define Com_GetBufferOfRxAccessInfo(Index)                                                          (Com_GetRxAccessInfoOfPCConfig()[(Index)].BufferOfRxAccessInfo)
#define Com_IsDynSignalOfRxAccessInfo(Index)                                                        ((Com_GetRxAccessInfoOfPCConfig()[(Index)].DynSignalOfRxAccessInfo) != FALSE)
#define Com_GetInitValueIdxOfRxAccessInfo(Index)                                                    (Com_GetRxAccessInfoOfPCConfig()[(Index)].InitValueIdxOfRxAccessInfo)
#define Com_GetSignalLengthInByteOfRxAccessInfo(Index)                                              (Com_GetRxAccessInfoOfPCConfig()[(Index)].SignalLengthInByteOfRxAccessInfo)
#define Com_GetRxDefPduBuffer(Index)                                                                (Com_GetRxDefPduBufferOfPCConfig()[(Index)])
#define Com_GetRxIPduGroupISRLockCounter(Index)                                                     (Com_GetRxIPduGroupISRLockCounterOfPCConfig()[(Index)])
#define Com_GetRxMainFunctionProcessingISRLockCounter(Index)                                        (Com_GetRxMainFunctionProcessingISRLockCounterOfPCConfig()[(Index)])
#define Com_IsRxPduGrpActive(Index)                                                                 ((Com_GetRxPduGrpActiveOfPCConfig()[(Index)]) != FALSE)
#define Com_GetHandleRxPduDeferredIdxOfRxPduInfo(Index)                                             (Com_GetRxPduInfoOfPCConfig()[(Index)].HandleRxPduDeferredIdxOfRxPduInfo)
#define Com_GetIPduGroupInfoOfRxPduInfoIndStartIdxOfRxPduInfo(Index)                                (Com_GetRxPduInfoOfPCConfig()[(Index)].IPduGroupInfoOfRxPduInfoIndStartIdxOfRxPduInfo)
#define Com_GetMainFunctionRxStructIdxOfRxPduInfo(Index)                                            (Com_GetRxPduInfoOfPCConfig()[(Index)].MainFunctionRxStructIdxOfRxPduInfo)
#define Com_GetRxAccessInfoIndStartIdxOfRxPduInfo(Index)                                            (Com_GetRxPduInfoOfPCConfig()[(Index)].RxAccessInfoIndStartIdxOfRxPduInfo)
#define Com_GetRxDefPduBufferLengthOfRxPduInfo(Index)                                               (Com_GetRxPduInfoOfPCConfig()[(Index)].RxDefPduBufferLengthOfRxPduInfo)
#define Com_GetRxSigInfoStartIdxOfRxPduInfo(Index)                                                  (Com_GetRxPduInfoOfPCConfig()[(Index)].RxSigInfoStartIdxOfRxPduInfo)
#define Com_GetRxSigBufferUInt8(Index)                                                              (Com_GetRxSigBufferUInt8OfPCConfig()[(Index)])
#define Com_GetValidDlcOfRxSigInfo(Index)                                                           (Com_GetRxSigInfoOfPCConfig()[(Index)].ValidDlcOfRxSigInfo)
#define Com_IsTransmitRequest(Index)                                                                ((Com_GetTransmitRequestOfPCConfig()[(Index)]) != FALSE)
#define Com_GetTxSigInfoIdxOfTxAccessInfo(Index)                                                    (Com_GetTxAccessInfoOfPCConfig()[(Index)].TxSigInfoIdxOfTxAccessInfo)
#define Com_GetTxBuffer(Index)                                                                      (Com_GetTxBufferOfPCConfig()[(Index)])
#define Com_GetTxIPduGroupISRLockCounter(Index)                                                     (Com_GetTxIPduGroupISRLockCounterOfPCConfig()[(Index)])
#define Com_GetTimePeriodOfTxModeFalse(Index)                                                       (Com_GetTxModeFalseOfPCConfig()[(Index)].TimePeriodOfTxModeFalse)
#define Com_IsInitModeOfTxModeInfo(Index)                                                           ((Com_GetTxModeInfoOfPCConfig()[(Index)].InitModeOfTxModeInfo) != FALSE)
#define Com_GetTimePeriodOfTxModeTrue(Index)                                                        (Com_GetTxModeTrueOfPCConfig()[(Index)].TimePeriodOfTxModeTrue)
#define Com_IsTxPduGrpActive(Index)                                                                 ((Com_GetTxPduGrpActiveOfPCConfig()[(Index)]) != FALSE)
#define Com_GetExternalIdOfTxPduInfo(Index)                                                         (Com_GetTxPduInfoOfPCConfig()[(Index)].ExternalIdOfTxPduInfo)
#define Com_GetIPduGroupInfoOfTxPduInfoIndEndIdxOfTxPduInfo(Index)                                  (Com_GetTxPduInfoOfPCConfig()[(Index)].IPduGroupInfoOfTxPduInfoIndEndIdxOfTxPduInfo)
#define Com_GetIPduGroupInfoOfTxPduInfoIndStartIdxOfTxPduInfo(Index)                                (Com_GetTxPduInfoOfPCConfig()[(Index)].IPduGroupInfoOfTxPduInfoIndStartIdxOfTxPduInfo)
#define Com_GetPartitionsTxStructIdxOfTxPduInfo(Index)                                              (Com_GetTxPduInfoOfPCConfig()[(Index)].PartitionsTxStructIdxOfTxPduInfo)
#define Com_GetTxBufferLengthOfTxPduInfo(Index)                                                     (Com_GetTxPduInfoOfPCConfig()[(Index)].TxBufferLengthOfTxPduInfo)
#define Com_GetTxPduInitValueEndIdxOfTxPduInfo(Index)                                               (Com_GetTxPduInfoOfPCConfig()[(Index)].TxPduInitValueEndIdxOfTxPduInfo)
#define Com_GetTxPduInitValueStartIdxOfTxPduInfo(Index)                                             (Com_GetTxPduInfoOfPCConfig()[(Index)].TxPduInitValueStartIdxOfTxPduInfo)
#define Com_GetTxPduInitValue(Index)                                                                (Com_GetTxPduInitValueOfPCConfig()[(Index)])
#define Com_GetTxProcessingISRLockCounter(Index)                                                    (Com_GetTxProcessingISRLockCounterOfPCConfig()[(Index)])
#define Com_GetTxSduLength(Index)                                                                   (Com_GetTxSduLengthOfPCConfig()[(Index)])
#define Com_GetApplTypeOfTxSigInfo(Index)                                                           (Com_GetTxSigInfoOfPCConfig()[(Index)].ApplTypeOfTxSigInfo)
#define Com_GetBitLengthOfTxSigInfo(Index)                                                          (Com_GetTxSigInfoOfPCConfig()[(Index)].BitLengthOfTxSigInfo)
#define Com_GetBitPositionOfTxSigInfo(Index)                                                        (Com_GetTxSigInfoOfPCConfig()[(Index)].BitPositionOfTxSigInfo)
#define Com_GetByteLengthOfTxSigInfo(Index)                                                         (Com_GetTxSigInfoOfPCConfig()[(Index)].ByteLengthOfTxSigInfo)
#define Com_IsDynSignalOfTxSigInfo(Index)                                                           ((Com_GetTxSigInfoOfPCConfig()[(Index)].DynSignalOfTxSigInfo) != FALSE)
#define Com_GetStartByteInPduPositionOfTxSigInfo(Index)                                             (Com_GetTxSigInfoOfPCConfig()[(Index)].StartByteInPduPositionOfTxSigInfo)
#define Com_GetTxBufferEndIdxOfTxSigInfo(Index)                                                     (Com_GetTxSigInfoOfPCConfig()[(Index)].TxBufferEndIdxOfTxSigInfo)
#define Com_GetTxBufferStartIdxOfTxSigInfo(Index)                                                   (Com_GetTxSigInfoOfPCConfig()[(Index)].TxBufferStartIdxOfTxSigInfo)
#define Com_GetTxPduInfoIdxOfTxSigInfo(Index)                                                       (Com_GetTxSigInfoOfPCConfig()[(Index)].TxPduInfoIdxOfTxSigInfo)
/** 
  \}
*/ 

/** 
  \defgroup  ComPCGetDeduplicatedDataMacros  Com Get Deduplicated Data Macros (PRE_COMPILE)
  \brief  These macros can be used to read deduplicated data elements.
  \{
*/ 
#define Com_GetPartitionsAlwaysActiveTxComIPdusStructIdxOfAlwaysActiveTxComIPdus(Index)             ((Com_PartitionsAlwaysActiveTxComIPdusStructIdxOfAlwaysActiveTxComIPdusType)((Index)))  /**< the index of the 1:1 relation pointing to Com_PartitionsAlwaysActiveTxComIPdusStruct */
#define Com_GetTxPduInfoIdxOfAlwaysActiveTxComIPdus(Index)                                          ((Com_TxPduInfoIdxOfAlwaysActiveTxComIPdusType)((((Com_TxPduInfoIdxOfAlwaysActiveTxComIPdusType)(Index)) + 2u)))  /**< the index of the 1:1 relation pointing to Com_TxPduInfo */
#define Com_GetConfigId()                                                                           Com_GetConfigIdOfPCConfig()
#define Com_GetIPduGroupInfoToSubIPduGroupsIndEndIdxOfIPduGroupInfo(Index)                          ((Com_IPduGroupInfoToSubIPduGroupsIndEndIdxOfIPduGroupInfoType)((((Com_IPduGroupInfoToSubIPduGroupsIndEndIdxOfIPduGroupInfoType)(Index)) + 1u)))  /**< the end index of the 0:n relation pointing to Com_IPduGroupInfoToSubIPduGroupsInd */
#define Com_IsIPduGroupInfoToSubIPduGroupsIndUsedOfIPduGroupInfo(Index)                             (((boolean)(Com_GetIPduGroupInfoToSubIPduGroupsIndStartIdxOfIPduGroupInfo(Index) != COM_NO_IPDUGROUPINFOTOSUBIPDUGROUPSINDSTARTIDXOFIPDUGROUPINFO)) != FALSE)  /**< TRUE, if the 0:n relation has 1 relation pointing to Com_IPduGroupInfoToSubIPduGroupsInd */
#define Com_IsPartitionsRxStructUsedOfIPduGroupInfo(Index)                                          (((boolean)(Com_GetPartitionsRxStructIdxOfIPduGroupInfo(Index) != COM_NO_PARTITIONSRXSTRUCTIDXOFIPDUGROUPINFO)) != FALSE)  /**< TRUE, if the 0:1 relation has minimum 1 relation pointing to Com_PartitionsRxStruct */
#define Com_IsPartitionsTxStructUsedOfIPduGroupInfo(Index)                                          (((boolean)(Com_GetPartitionsTxStructIdxOfIPduGroupInfo(Index) != COM_NO_PARTITIONSTXSTRUCTIDXOFIPDUGROUPINFO)) != FALSE)  /**< TRUE, if the 0:1 relation has minimum 1 relation pointing to Com_PartitionsTxStruct */
#define Com_IsRxPduInfoIndUsedOfIPduGroupInfo(Index)                                                (((boolean)(Com_GetRxPduInfoIndStartIdxOfIPduGroupInfo(Index) != COM_NO_RXPDUINFOINDSTARTIDXOFIPDUGROUPINFO)) != FALSE)  /**< TRUE, if the 0:n relation has 1 relation pointing to Com_RxPduInfoInd */
#define Com_IsTxPduInfoIndUsedOfIPduGroupInfo(Index)                                                (((boolean)(Com_GetTxPduInfoIndStartIdxOfIPduGroupInfo(Index) != COM_NO_TXPDUINFOINDSTARTIDXOFIPDUGROUPINFO)) != FALSE)  /**< TRUE, if the 0:n relation has 1 relation pointing to Com_TxPduInfoInd */
#define Com_GetIPduGroupInfoOfRxPduInfoInd(Index)                                                   ((Com_IPduGroupInfoOfRxPduInfoIndType)((Index)))  /**< the indexes of the 1:1 sorted relation pointing to Com_IPduGroupInfo */
#define Com_GetIPduGroupInfoToSubIPduGroupsInd(Index)                                               ((Com_IPduGroupInfoToSubIPduGroupsIndType)((Index)))  /**< the indexes of the 1:1 sorted relation pointing to Com_IPduGroupInfo */
#define Com_GetRxMainFunctionProcessingISRLockCounterIdxOfMainFunctionRxStruct(Index)               ((Com_RxMainFunctionProcessingISRLockCounterIdxOfMainFunctionRxStructType)((Index)))  /**< the index of the 1:1 relation pointing to Com_RxMainFunctionProcessingISRLockCounter */
#define Com_GetRxPduInfoOfMainFunctionRxIndEndIdxOfMainFunctionRxStruct(Index)                      ((Com_RxPduInfoOfMainFunctionRxIndEndIdxOfMainFunctionRxStructType)((((Com_RxPduInfoOfMainFunctionRxIndEndIdxOfMainFunctionRxStructType)(Index)) + 1u)))  /**< the end index of the 0:n relation pointing to Com_RxPduInfoOfMainFunctionRxInd */
#define Com_IsRxPduInfoOfMainFunctionRxIndUsedOfMainFunctionRxStruct(Index)                         (((boolean)(Com_GetRxPduInfoOfMainFunctionRxIndStartIdxOfMainFunctionRxStruct(Index) != COM_NO_RXPDUINFOOFMAINFUNCTIONRXINDSTARTIDXOFMAINFUNCTIONRXSTRUCT)) != FALSE)  /**< TRUE, if the 0:n relation has 1 relation pointing to Com_RxPduInfoOfMainFunctionRxInd */
#define Com_GetTxCyclicPduOfMainFunctionTxIndEndIdxOfMainFunctionTxStruct(Index)                    ((Com_TxCyclicPduOfMainFunctionTxIndEndIdxOfMainFunctionTxStructType)((((Com_TxCyclicPduOfMainFunctionTxIndEndIdxOfMainFunctionTxStructType)(Index)) + 2u)))  /**< the end index of the 0:n relation pointing to Com_TxCyclicPduOfMainFunctionTxInd */
#define Com_IsTxCyclicPduOfMainFunctionTxIndUsedOfMainFunctionTxStruct(Index)                       (((boolean)(Com_GetTxCyclicPduOfMainFunctionTxIndStartIdxOfMainFunctionTxStruct(Index) != COM_NO_TXCYCLICPDUOFMAINFUNCTIONTXINDSTARTIDXOFMAINFUNCTIONTXSTRUCT)) != FALSE)  /**< TRUE, if the 0:n relation has 1 relation pointing to Com_TxCyclicPduOfMainFunctionTxInd */
#define Com_GetTxPduInfoOfMainFunctionTxIndEndIdxOfMainFunctionTxStruct(Index)                      ((Com_TxPduInfoOfMainFunctionTxIndEndIdxOfMainFunctionTxStructType)((((Com_TxPduInfoOfMainFunctionTxIndEndIdxOfMainFunctionTxStructType)(Index)) + 3u)))  /**< the end index of the 0:n relation pointing to Com_TxPduInfoOfMainFunctionTxInd */
#define Com_IsTxPduInfoOfMainFunctionTxIndUsedOfMainFunctionTxStruct(Index)                         (((boolean)(Com_GetTxPduInfoOfMainFunctionTxIndStartIdxOfMainFunctionTxStruct(Index) != COM_NO_TXPDUINFOOFMAINFUNCTIONTXINDSTARTIDXOFMAINFUNCTIONTXSTRUCT)) != FALSE)  /**< TRUE, if the 0:n relation has 1 relation pointing to Com_TxPduInfoOfMainFunctionTxInd */
#define Com_GetTxProcessingISRLockCounterIdxOfMainFunctionTxStruct(Index)                           ((Com_TxProcessingISRLockCounterIdxOfMainFunctionTxStructType)((Index)))  /**< the index of the 1:1 relation pointing to Com_TxProcessingISRLockCounter */
#define Com_GetTxIPduGroupISRLockCounterIdxOfPartitionsAlwaysActiveTxComIPdusStruct(Index)          ((Com_TxIPduGroupISRLockCounterIdxOfPartitionsAlwaysActiveTxComIPdusStructType)((Index)))  /**< the index of the 1:1 relation pointing to Com_TxIPduGroupISRLockCounter */
#define Com_GetRxIPduGroupISRLockCounterIdxOfPartitionsRxStruct(Index)                              ((Com_RxIPduGroupISRLockCounterIdxOfPartitionsRxStructType)((Index)))  /**< the index of the 1:1 relation pointing to Com_RxIPduGroupISRLockCounter */
#define Com_GetTxIPduGroupISRLockCounterIdxOfPartitionsTxStruct(Index)                              ((Com_TxIPduGroupISRLockCounterIdxOfPartitionsTxStructType)((Index)))  /**< the index of the 1:1 relation pointing to Com_TxIPduGroupISRLockCounter */
#define Com_GetPduGrpCnt()                                                                          Com_GetPduGrpCntOfPCConfig()
#define Com_GetApplTypeOfRxAccessInfo(Index)                                                        Com_GetBufferOfRxAccessInfo(Index)  /**< Application data type. */
#define Com_GetBitLengthOfRxAccessInfo(Index)                                                       Com_GetSignalLengthInByteOfRxAccessInfo(Index)  /**< Bit length of the signal or group signal. */
#define Com_GetBitPositionOfRxAccessInfo(Index)                                                     ((Com_BitPositionOfRxAccessInfoType)((Index)))  /**< Little endian bit position of the signal or group signal within the I-PDU. */
#define Com_IsBufferUsedOfRxAccessInfo(Index)                                                       (((boolean)(Com_GetBufferIdxOfRxAccessInfo(Index) != COM_NO_BUFFERIDXOFRXACCESSINFO)) != FALSE)  /**< TRUE, if the 0:1 relation has minimum 1 relation pointing to Com_RxSigBufferUInt8,Com_RxSigBufferUInt16,Com_RxSigBufferUInt32,Com_RxSigBufferUInt64,Com_RxSigBufferZeroBit,Com_RxSigBufferSInt8,Com_RxSigBufferSInt16,Com_RxSigBufferSInt32,Com_RxSigBufferSInt64,Com_RxSigBufferFloat32,Com_RxSigBufferFloat64 */
#define Com_GetBusAccOfRxAccessInfo(Index)                                                          Com_GetBufferOfRxAccessInfo(Index)  /**< BUS access algorithm for signal or group signal packing / un-packing. */
#define Com_GetByteLengthOfRxAccessInfo(Index)                                                      Com_GetBufferOfRxAccessInfo(Index)  /**< Byte length of the signal or group signal. */
#define Com_GetBytePositionOfRxAccessInfo(Index)                                                    Com_GetBufferOfRxAccessInfo(Index)  /**< Little endian byte position of the signal or group signal within the I-PDU. */
#define Com_GetInitValueOfRxAccessInfo(Index)                                                       Com_GetBufferOfRxAccessInfo(Index)  /**< the enum value of the according target of the 0:1 relation pointing to Com_ConstValueUInt8,Com_ConstValueUInt16,Com_ConstValueUInt32,Com_ConstValueUInt64,Com_ConstValueSInt8,Com_ConstValueSInt16,Com_ConstValueSInt32,Com_ConstValueSInt64,Com_ConstValueFloat32,Com_ConstValueFloat64 */
#define Com_IsInitValueUsedOfRxAccessInfo(Index)                                                    (((boolean)(Com_GetInitValueIdxOfRxAccessInfo(Index) != COM_NO_INITVALUEIDXOFRXACCESSINFO)) != FALSE)  /**< TRUE, if the 0:1 relation has minimum 1 relation pointing to Com_ConstValueUInt8,Com_ConstValueUInt16,Com_ConstValueUInt32,Com_ConstValueUInt64,Com_ConstValueSInt8,Com_ConstValueSInt16,Com_ConstValueSInt32,Com_ConstValueSInt64,Com_ConstValueFloat32,Com_ConstValueFloat64 */
#define Com_GetRxPduInfoIdxOfRxAccessInfo(Index)                                                    Com_GetBufferOfRxAccessInfo(Index)  /**< the index of the 1:1 relation pointing to Com_RxPduInfo */
#define Com_GetStartByteInPduPositionOfRxAccessInfo(Index)                                          Com_GetBufferOfRxAccessInfo(Index)  /**< Start Byte position of the signal or group signal within the I-PDU. */
#define Com_GetRxAccessInfoInd(Index)                                                               ((Com_RxAccessInfoIndType)((Index)))  /**< the indexes of the 1:1 sorted relation pointing to Com_RxAccessInfo */
#define Com_GetRxIPduGroupISRLockThreshold()                                                        Com_GetRxIPduGroupISRLockThresholdOfPCConfig()
#define Com_GetRxMainFunctionProcessingISRLockThreshold()                                           Com_GetRxMainFunctionProcessingISRLockThresholdOfPCConfig()
#define Com_IsHandleRxPduDeferredUsedOfRxPduInfo(Index)                                             (((boolean)(Com_GetHandleRxPduDeferredIdxOfRxPduInfo(Index) != COM_NO_HANDLERXPDUDEFERREDIDXOFRXPDUINFO)) != FALSE)  /**< TRUE, if the 0:1 relation has minimum 1 relation pointing to Com_HandleRxPduDeferred */
#define Com_GetIPduGroupInfoOfRxPduInfoIndEndIdxOfRxPduInfo(Index)                                  ((Com_IPduGroupInfoOfRxPduInfoIndEndIdxOfRxPduInfoType)((((Com_IPduGroupInfoOfRxPduInfoIndEndIdxOfRxPduInfoType)(Index)) + 1u)))  /**< the end index of the 0:n relation pointing to Com_IPduGroupInfoOfRxPduInfoInd */
#define Com_IsIPduGroupInfoOfRxPduInfoIndUsedOfRxPduInfo(Index)                                     (((boolean)(Com_GetIPduGroupInfoOfRxPduInfoIndStartIdxOfRxPduInfo(Index) != COM_NO_IPDUGROUPINFOOFRXPDUINFOINDSTARTIDXOFRXPDUINFO)) != FALSE)  /**< TRUE, if the 0:n relation has 1 relation pointing to Com_IPduGroupInfoOfRxPduInfoInd */
#define Com_IsMainFunctionRxStructUsedOfRxPduInfo(Index)                                            (((boolean)(Com_GetMainFunctionRxStructIdxOfRxPduInfo(Index) != COM_NO_MAINFUNCTIONRXSTRUCTIDXOFRXPDUINFO)) != FALSE)  /**< TRUE, if the 0:1 relation has minimum 1 relation pointing to Com_MainFunctionRxStruct */
#define Com_GetPartitionsRxStructIdxOfRxPduInfo(Index)                                              ((Com_PartitionsRxStructIdxOfRxPduInfoType)((Index)))  /**< the index of the 1:1 relation pointing to Com_PartitionsRxStruct */
#define Com_GetRxAccessInfoIndEndIdxOfRxPduInfo(Index)                                              ((Com_RxAccessInfoIndEndIdxOfRxPduInfoType)((((Com_RxAccessInfoIndEndIdxOfRxPduInfoType)(Index)) + 2u)))  /**< the end index of the 0:n relation pointing to Com_RxAccessInfoInd */
#define Com_IsRxAccessInfoIndUsedOfRxPduInfo(Index)                                                 (((boolean)(Com_GetRxAccessInfoIndStartIdxOfRxPduInfo(Index) != COM_NO_RXACCESSINFOINDSTARTIDXOFRXPDUINFO)) != FALSE)  /**< TRUE, if the 0:n relation has 1 relation pointing to Com_RxAccessInfoInd */
#define Com_GetRxDefPduBufferEndIdxOfRxPduInfo(Index)                                               ((Com_RxDefPduBufferEndIdxOfRxPduInfoType)((((Com_RxDefPduBufferEndIdxOfRxPduInfoType)(Index)) + 1u)))  /**< the end index of the 0:n relation pointing to Com_RxDefPduBuffer */
#define Com_GetRxDefPduBufferStartIdxOfRxPduInfo(Index)                                             ((Com_RxDefPduBufferStartIdxOfRxPduInfoType)((Index)))  /**< the start index of the 0:n relation pointing to Com_RxDefPduBuffer */
#define Com_IsRxDefPduBufferUsedOfRxPduInfo(Index)                                                  (((boolean)(Com_GetRxDefPduBufferLengthOfRxPduInfo(Index) != 0u)) != FALSE)  /**< TRUE, if the 0:n relation has 1 relation pointing to Com_RxDefPduBuffer */
#define Com_GetRxSigInfoEndIdxOfRxPduInfo(Index)                                                    ((Com_RxSigInfoEndIdxOfRxPduInfoType)((((Com_RxSigInfoEndIdxOfRxPduInfoType)(Index)) + 2u)))  /**< the end index of the 0:n relation pointing to Com_RxSigInfo */
#define Com_IsRxSigInfoUsedOfRxPduInfo(Index)                                                       (((boolean)(Com_GetRxSigInfoStartIdxOfRxPduInfo(Index) != COM_NO_RXSIGINFOSTARTIDXOFRXPDUINFO)) != FALSE)  /**< TRUE, if the 0:n relation has 1 relation pointing to Com_RxSigInfo */
#define Com_GetSignalProcessingOfRxPduInfo(Index)                                                   ((Com_SignalProcessingOfRxPduInfoType)((Index)))  /**< Defines whether rx Pdu is processed in DEFERRED or IMMEDIATE fashion. */
#define Com_GetTypeOfRxPduInfo(Index)                                                               ((Com_TypeOfRxPduInfoType)((Index)))  /**< Defines whether rx Pdu is a NORMAL or TP IPdu. */
#define Com_GetRxPduInfoInd(Index)                                                                  ((Com_RxPduInfoIndType)((Index)))  /**< the indexes of the 1:1 sorted relation pointing to Com_RxPduInfo */
#define Com_GetRxPduInfoOfMainFunctionRxInd(Index)                                                  ((Com_RxPduInfoOfMainFunctionRxIndType)((Index)))  /**< the indexes of the 1:1 sorted relation pointing to Com_RxPduInfo */
#define Com_GetRxAccessInfoIdxOfRxSigInfo(Index)                                                    ((Com_RxAccessInfoIdxOfRxSigInfoType)((Index)))  /**< the index of the 1:1 relation pointing to Com_RxAccessInfo */
#define Com_GetSignalProcessingOfRxSigInfo(Index)                                                   ((Com_SignalProcessingOfRxSigInfoType)((Com_GetValidDlcOfRxSigInfo(Index) - 1u)))
#define Com_GetSizeOfAlwaysActiveTxComIPdus()                                                       Com_GetSizeOfAlwaysActiveTxComIPdusOfPCConfig()
#define Com_GetSizeOfConstValueUInt8()                                                              Com_GetSizeOfConstValueUInt8OfPCConfig()
#define Com_GetSizeOfCurrentTxMode()                                                                Com_GetSizeOfCurrentTxModeOfPCConfig()
#define Com_GetSizeOfCycleTimeCnt()                                                                 Com_GetSizeOfCycleTimeCntOfPCConfig()
#define Com_GetSizeOfCyclicSendRequest()                                                            Com_GetSizeOfCyclicSendRequestOfPCConfig()
#define Com_GetSizeOfHandleRxPduDeferred()                                                          Com_GetSizeOfHandleRxPduDeferredOfPCConfig()
#define Com_GetSizeOfIPduGroupInfo()                                                                Com_GetSizeOfIPduGroupInfoOfPCConfig()
#define Com_GetSizeOfIPduGroupInfoOfRxPduInfoInd()                                                  Com_GetSizeOfIPduGroupInfoOfRxPduInfoIndOfPCConfig()
#define Com_GetSizeOfIPduGroupInfoOfTxPduInfoInd()                                                  Com_GetSizeOfIPduGroupInfoOfTxPduInfoIndOfPCConfig()
#define Com_GetSizeOfIPduGroupInfoToSubIPduGroupsInd()                                              Com_GetSizeOfIPduGroupInfoToSubIPduGroupsIndOfPCConfig()
#define Com_GetSizeOfIPduGroupState()                                                               Com_GetSizeOfIPduGroupStateOfPCConfig()
#define Com_GetSizeOfMainFunctionRxStruct()                                                         Com_GetSizeOfMainFunctionRxStructOfPCConfig()
#define Com_GetSizeOfMainFunctionTxStruct()                                                         Com_GetSizeOfMainFunctionTxStructOfPCConfig()
#define Com_GetSizeOfPartitionsAlwaysActiveTxComIPdusStruct()                                       Com_GetSizeOfPartitionsAlwaysActiveTxComIPdusStructOfPCConfig()
#define Com_GetSizeOfPartitionsRxStruct()                                                           Com_GetSizeOfPartitionsRxStructOfPCConfig()
#define Com_GetSizeOfPartitionsTxStruct()                                                           Com_GetSizeOfPartitionsTxStructOfPCConfig()
#define Com_GetSizeOfRxAccessInfo()                                                                 Com_GetSizeOfRxAccessInfoOfPCConfig()
#define Com_GetSizeOfRxAccessInfoInd()                                                              Com_GetSizeOfRxAccessInfoIndOfPCConfig()
#define Com_GetSizeOfRxDefPduBuffer()                                                               Com_GetSizeOfRxDefPduBufferOfPCConfig()
#define Com_GetSizeOfRxIPduGroupISRLockCounter()                                                    Com_GetSizeOfRxIPduGroupISRLockCounterOfPCConfig()
#define Com_GetSizeOfRxMainFunctionProcessingISRLockCounter()                                       Com_GetSizeOfRxMainFunctionProcessingISRLockCounterOfPCConfig()
#define Com_GetSizeOfRxPduGrpActive()                                                               Com_GetSizeOfRxPduGrpActiveOfPCConfig()
#define Com_GetSizeOfRxPduInfo()                                                                    Com_GetSizeOfRxPduInfoOfPCConfig()
#define Com_GetSizeOfRxPduInfoInd()                                                                 Com_GetSizeOfRxPduInfoIndOfPCConfig()
#define Com_GetSizeOfRxPduInfoOfMainFunctionRxInd()                                                 Com_GetSizeOfRxPduInfoOfMainFunctionRxIndOfPCConfig()
#define Com_GetSizeOfRxSigBufferUInt8()                                                             Com_GetSizeOfRxSigBufferUInt8OfPCConfig()
#define Com_GetSizeOfRxSigInfo()                                                                    Com_GetSizeOfRxSigInfoOfPCConfig()
#define Com_GetSizeOfTransmitRequest()                                                              Com_GetSizeOfTransmitRequestOfPCConfig()
#define Com_GetSizeOfTxAccessInfo()                                                                 Com_GetSizeOfTxAccessInfoOfPCConfig()
#define Com_GetSizeOfTxBuffer()                                                                     Com_GetSizeOfTxBufferOfPCConfig()
#define Com_GetSizeOfTxCyclicPdu()                                                                  Com_GetSizeOfTxCyclicPduOfPCConfig()
#define Com_GetSizeOfTxCyclicPduOfMainFunctionTxInd()                                               Com_GetSizeOfTxCyclicPduOfMainFunctionTxIndOfPCConfig()
#define Com_GetSizeOfTxIPduGroupISRLockCounter()                                                    Com_GetSizeOfTxIPduGroupISRLockCounterOfPCConfig()
#define Com_GetSizeOfTxModeFalse()                                                                  Com_GetSizeOfTxModeFalseOfPCConfig()
#define Com_GetSizeOfTxModeInfo()                                                                   Com_GetSizeOfTxModeInfoOfPCConfig()
#define Com_GetSizeOfTxModeTrue()                                                                   Com_GetSizeOfTxModeTrueOfPCConfig()
#define Com_GetSizeOfTxPduGrpActive()                                                               Com_GetSizeOfTxPduGrpActiveOfPCConfig()
#define Com_GetSizeOfTxPduInfo()                                                                    Com_GetSizeOfTxPduInfoOfPCConfig()
#define Com_GetSizeOfTxPduInfoInd()                                                                 Com_GetSizeOfTxPduInfoIndOfPCConfig()
#define Com_GetSizeOfTxPduInfoOfMainFunctionTxInd()                                                 Com_GetSizeOfTxPduInfoOfMainFunctionTxIndOfPCConfig()
#define Com_GetSizeOfTxPduInitValue()                                                               Com_GetSizeOfTxPduInitValueOfPCConfig()
#define Com_GetSizeOfTxProcessingISRLockCounter()                                                   Com_GetSizeOfTxProcessingISRLockCounterOfPCConfig()
#define Com_GetSizeOfTxSduLength()                                                                  Com_GetSizeOfTxSduLengthOfPCConfig()
#define Com_GetSizeOfTxSigInfo()                                                                    Com_GetSizeOfTxSigInfoOfPCConfig()
#define Com_IsTxSigInfoUsedOfTxAccessInfo(Index)                                                    (((boolean)(Com_GetTxSigInfoIdxOfTxAccessInfo(Index) != COM_NO_TXSIGINFOIDXOFTXACCESSINFO)) != FALSE)  /**< TRUE, if the 0:1 relation has minimum 1 relation pointing to Com_TxSigInfo */
#define Com_GetTxPduInfoIdxOfTxCyclicPdu(Index)                                                     ((Com_TxPduInfoIdxOfTxCyclicPduType)((Index)))  /**< the index of the 1:1 relation pointing to Com_TxPduInfo */
#define Com_GetTxCyclicPduOfMainFunctionTxInd(Index)                                                ((Com_TxCyclicPduOfMainFunctionTxIndType)((Index)))  /**< the indexes of the 1:1 sorted relation pointing to Com_TxCyclicPdu */
#define Com_GetTxIPduGroupISRLockThreshold()                                                        Com_GetTxIPduGroupISRLockThresholdOfPCConfig()
#define Com_IsPeriodicOfTxModeFalse(Index)                                                          (((boolean)(Com_GetTimePeriodOfTxModeFalse(Index) != 0u)) != FALSE)  /**< TRUE if transmission mode contains a cyclic part. */
#define Com_GetTxModeFalseIdxOfTxModeInfo(Index)                                                    ((Com_TxModeFalseIdxOfTxModeInfoType)((Index)))  /**< the index of the 1:1 relation pointing to Com_TxModeFalse */
#define Com_GetTxModeTrueIdxOfTxModeInfo(Index)                                                     ((Com_TxModeTrueIdxOfTxModeInfoType)((Index)))  /**< the index of the 1:1 relation pointing to Com_TxModeTrue */
#define Com_IsPeriodicOfTxModeTrue(Index)                                                           (((boolean)(Com_GetTimePeriodOfTxModeTrue(Index) != 0u)) != FALSE)  /**< TRUE if transmission mode contains a cyclic part. */
#define Com_IsIPduGroupInfoOfTxPduInfoIndUsedOfTxPduInfo(Index)                                     (((boolean)(Com_GetIPduGroupInfoOfTxPduInfoIndStartIdxOfTxPduInfo(Index) != COM_NO_IPDUGROUPINFOOFTXPDUINFOINDSTARTIDXOFTXPDUINFO)) != FALSE)  /**< TRUE, if the 0:n relation has 1 relation pointing to Com_IPduGroupInfoOfTxPduInfoInd */
#define Com_GetMetaDataLengthOfTxPduInfo(Index)                                                     Com_GetPartitionsTxStructIdxOfTxPduInfo(Index)  /**< Length of MetaData. */
#define Com_GetPduWithMetaDataLengthOfTxPduInfo(Index)                                              Com_GetTxBufferLengthOfTxPduInfo(Index)  /**< Length of Pdu with MetaData. */
#define Com_GetTxBufferEndIdxOfTxPduInfo(Index)                                                     Com_GetTxPduInitValueEndIdxOfTxPduInfo(Index)  /**< the end index of the 0:n relation pointing to Com_TxBuffer */
#define Com_GetTxBufferStartIdxOfTxPduInfo(Index)                                                   Com_GetTxPduInitValueStartIdxOfTxPduInfo(Index)  /**< the start index of the 0:n relation pointing to Com_TxBuffer */
#define Com_IsTxBufferUsedOfTxPduInfo(Index)                                                        (((boolean)(Com_GetTxBufferLengthOfTxPduInfo(Index) != 0u)) != FALSE)  /**< TRUE, if the 0:n relation has 1 relation pointing to Com_TxBuffer */
#define Com_GetTxModeInfoIdxOfTxPduInfo(Index)                                                      ((Com_TxModeInfoIdxOfTxPduInfoType)((Index)))  /**< the index of the 1:1 relation pointing to Com_TxModeInfo */
#define Com_IsTxPduInitValueUsedOfTxPduInfo(Index)                                                  (((boolean)(Com_GetTxPduInitValueStartIdxOfTxPduInfo(Index) != COM_NO_TXPDUINITVALUESTARTIDXOFTXPDUINFO)) != FALSE)  /**< TRUE, if the 0:n relation has 1 relation pointing to Com_TxPduInitValue */
#define Com_GetTypeOfTxPduInfo(Index)                                                               Com_GetPartitionsTxStructIdxOfTxPduInfo(Index)  /**< Defines whether rx Pdu is a NORMAL or TP IPdu. */
#define Com_GetTxPduInfoInd(Index)                                                                  ((Com_TxPduInfoIndType)((Index)))  /**< the indexes of the 1:1 sorted relation pointing to Com_TxPduInfo */
#define Com_GetTxPduInfoOfMainFunctionTxInd(Index)                                                  ((Com_TxPduInfoOfMainFunctionTxIndType)((Index)))  /**< the indexes of the 1:1 sorted relation pointing to Com_TxPduInfo */
#define Com_GetTxProcessingISRLockThreshold()                                                       Com_GetTxProcessingISRLockThresholdOfPCConfig()
#define Com_GetBusAccOfTxSigInfo(Index)                                                             Com_GetByteLengthOfTxSigInfo(Index)  /**< BUS access algorithm for signal or group signal packing / un-packing. */
#define Com_GetBytePositionOfTxSigInfo(Index)                                                       Com_GetStartByteInPduPositionOfTxSigInfo(Index)  /**< Little endian byte position of the signal or group signal within the I-PDU. */
#define Com_GetTxAccessInfoIdxOfTxSigInfo(Index)                                                    ((Com_TxAccessInfoIdxOfTxSigInfoType)((Index)))  /**< the index of the 1:1 relation pointing to Com_TxAccessInfo */
#define Com_GetTxBufferLengthOfTxSigInfo(Index)                                                     ((Com_TxBufferLengthOfTxSigInfoType)((Com_GetTxBufferEndIdxOfTxSigInfo(Index) - Com_GetTxBufferStartIdxOfTxSigInfo(Index))))  /**< the number of relations pointing to Com_TxBuffer */
#define Com_IsTxBufferUsedOfTxSigInfo(Index)                                                        (((boolean)(Com_GetTxBufferLengthOfTxSigInfo(Index) != 0u)) != FALSE)  /**< TRUE, if the 0:n relation has 1 relation pointing to Com_TxBuffer */
/** 
  \}
*/ 

/** 
  \defgroup  ComPCSetDataMacros  Com Set Data Macros (PRE_COMPILE)
  \brief  These macros can be used to write data.
  \{
*/ 
#define Com_SetCurrentTxMode(Index, Value)                                                          Com_GetCurrentTxModeOfPCConfig()[(Index)] = (Value)
#define Com_SetCycleTimeCnt(Index, Value)                                                           Com_GetCycleTimeCntOfPCConfig()[(Index)] = (Value)
#define Com_SetCyclicSendRequest(Index, Value)                                                      Com_GetCyclicSendRequestOfPCConfig()[(Index)] = (Value)
#define Com_SetHandleRxPduDeferred(Index, Value)                                                    Com_GetHandleRxPduDeferredOfPCConfig()[(Index)] = (Value)
#define Com_SetIPduGroupState(Index, Value)                                                         Com_GetIPduGroupStateOfPCConfig()[(Index)] = (Value)
#define Com_SetInitialized(Value)                                                                   (*(Com_GetInitializedOfPCConfig())) = (Value)
#define Com_SetRxDefPduBuffer(Index, Value)                                                         Com_GetRxDefPduBufferOfPCConfig()[(Index)] = (Value)
#define Com_SetRxIPduGroupISRLockCounter(Index, Value)                                              Com_GetRxIPduGroupISRLockCounterOfPCConfig()[(Index)] = (Value)
#define Com_SetRxMainFunctionProcessingISRLockCounter(Index, Value)                                 Com_GetRxMainFunctionProcessingISRLockCounterOfPCConfig()[(Index)] = (Value)
#define Com_SetRxPduGrpActive(Index, Value)                                                         Com_GetRxPduGrpActiveOfPCConfig()[(Index)] = (Value)
#define Com_SetRxSigBufferUInt8(Index, Value)                                                       Com_GetRxSigBufferUInt8OfPCConfig()[(Index)] = (Value)
#define Com_SetTransmitRequest(Index, Value)                                                        Com_GetTransmitRequestOfPCConfig()[(Index)] = (Value)
#define Com_SetTxBuffer(Index, Value)                                                               Com_GetTxBufferOfPCConfig()[(Index)] = (Value)
#define Com_SetTxIPduGroupISRLockCounter(Index, Value)                                              Com_GetTxIPduGroupISRLockCounterOfPCConfig()[(Index)] = (Value)
#define Com_SetTxPduGrpActive(Index, Value)                                                         Com_GetTxPduGrpActiveOfPCConfig()[(Index)] = (Value)
#define Com_SetTxProcessingISRLockCounter(Index, Value)                                             Com_GetTxProcessingISRLockCounterOfPCConfig()[(Index)] = (Value)
#define Com_SetTxSduLength(Index, Value)                                                            Com_GetTxSduLengthOfPCConfig()[(Index)] = (Value)
/** 
  \}
*/ 

/** 
  \defgroup  ComPCGetAddressOfDataMacros  Com Get Address Of Data Macros (PRE_COMPILE)
  \brief  These macros can be used to get the data by the address operator.
  \{
*/ 
#define Com_GetAddrConstValueUInt8(Index)                                                           (&Com_GetConstValueUInt8(Index))
#define Com_GetAddrRxDefPduBuffer(Index)                                                            (&Com_GetRxDefPduBuffer(Index))
#define Com_GetAddrRxSigBufferUInt8(Index)                                                          (&Com_GetRxSigBufferUInt8(Index))
#define Com_GetAddrTxBuffer(Index)                                                                  (&Com_GetTxBuffer(Index))
#define Com_GetAddrTxPduInitValue(Index)                                                            (&Com_GetTxPduInitValue(Index))
/** 
  \}
*/ 

/** 
  \defgroup  ComPCHasMacros  Com Has Macros (PRE_COMPILE)
  \brief  These macros can be used to detect at runtime a deactivated piece of information. TRUE in the CONFIGURATION_VARIANT PRE-COMPILE, TRUE or FALSE in the CONFIGURATION_VARIANT POST-BUILD.
  \{
*/ 
#define Com_HasAlwaysActiveTxComIPdus()                                                             (TRUE != FALSE)
#define Com_HasPartitionsAlwaysActiveTxComIPdusStructIdxOfAlwaysActiveTxComIPdus()                  (TRUE != FALSE)
#define Com_HasTxPduInfoIdxOfAlwaysActiveTxComIPdus()                                               (TRUE != FALSE)
#define Com_HasConfigId()                                                                           (TRUE != FALSE)
#define Com_HasConstValueUInt8()                                                                    (TRUE != FALSE)
#define Com_HasCurrentTxMode()                                                                      (TRUE != FALSE)
#define Com_HasCycleTimeCnt()                                                                       (TRUE != FALSE)
#define Com_HasCyclicSendRequest()                                                                  (TRUE != FALSE)
#define Com_HasHandleRxPduDeferred()                                                                (TRUE != FALSE)
#define Com_HasIPduGroupInfo()                                                                      (TRUE != FALSE)
#define Com_HasIPduGroupInfoToSubIPduGroupsIndEndIdxOfIPduGroupInfo()                               (TRUE != FALSE)
#define Com_HasIPduGroupInfoToSubIPduGroupsIndStartIdxOfIPduGroupInfo()                             (TRUE != FALSE)
#define Com_HasIPduGroupInfoToSubIPduGroupsIndUsedOfIPduGroupInfo()                                 (TRUE != FALSE)
#define Com_HasPartitionsRxStructIdxOfIPduGroupInfo()                                               (TRUE != FALSE)
#define Com_HasPartitionsRxStructUsedOfIPduGroupInfo()                                              (TRUE != FALSE)
#define Com_HasPartitionsTxStructIdxOfIPduGroupInfo()                                               (TRUE != FALSE)
#define Com_HasPartitionsTxStructUsedOfIPduGroupInfo()                                              (TRUE != FALSE)
#define Com_HasRxPduInfoIndEndIdxOfIPduGroupInfo()                                                  (TRUE != FALSE)
#define Com_HasRxPduInfoIndStartIdxOfIPduGroupInfo()                                                (TRUE != FALSE)
#define Com_HasRxPduInfoIndUsedOfIPduGroupInfo()                                                    (TRUE != FALSE)
#define Com_HasTxPduInfoIndEndIdxOfIPduGroupInfo()                                                  (TRUE != FALSE)
#define Com_HasTxPduInfoIndStartIdxOfIPduGroupInfo()                                                (TRUE != FALSE)
#define Com_HasTxPduInfoIndUsedOfIPduGroupInfo()                                                    (TRUE != FALSE)
#define Com_HasIPduGroupInfoOfRxPduInfoInd()                                                        (TRUE != FALSE)
#define Com_HasIPduGroupInfoOfTxPduInfoInd()                                                        (TRUE != FALSE)
#define Com_HasIPduGroupInfoToSubIPduGroupsInd()                                                    (TRUE != FALSE)
#define Com_HasIPduGroupState()                                                                     (TRUE != FALSE)
#define Com_HasInitialized()                                                                        (TRUE != FALSE)
#define Com_HasMainFunctionRxStruct()                                                               (TRUE != FALSE)
#define Com_HasRxMainFunctionProcessingISRLockCounterIdxOfMainFunctionRxStruct()                    (TRUE != FALSE)
#define Com_HasRxPduInfoOfMainFunctionRxIndEndIdxOfMainFunctionRxStruct()                           (TRUE != FALSE)
#define Com_HasRxPduInfoOfMainFunctionRxIndStartIdxOfMainFunctionRxStruct()                         (TRUE != FALSE)
#define Com_HasRxPduInfoOfMainFunctionRxIndUsedOfMainFunctionRxStruct()                             (TRUE != FALSE)
#define Com_HasMainFunctionTxStruct()                                                               (TRUE != FALSE)
#define Com_HasTxCyclicPduOfMainFunctionTxIndEndIdxOfMainFunctionTxStruct()                         (TRUE != FALSE)
#define Com_HasTxCyclicPduOfMainFunctionTxIndStartIdxOfMainFunctionTxStruct()                       (TRUE != FALSE)
#define Com_HasTxCyclicPduOfMainFunctionTxIndUsedOfMainFunctionTxStruct()                           (TRUE != FALSE)
#define Com_HasTxPduInfoOfMainFunctionTxIndEndIdxOfMainFunctionTxStruct()                           (TRUE != FALSE)
#define Com_HasTxPduInfoOfMainFunctionTxIndStartIdxOfMainFunctionTxStruct()                         (TRUE != FALSE)
#define Com_HasTxPduInfoOfMainFunctionTxIndUsedOfMainFunctionTxStruct()                             (TRUE != FALSE)
#define Com_HasTxProcessingISRLockCounterIdxOfMainFunctionTxStruct()                                (TRUE != FALSE)
#define Com_HasPartitionsAlwaysActiveTxComIPdusStruct()                                             (TRUE != FALSE)
#define Com_HasTxIPduGroupISRLockCounterIdxOfPartitionsAlwaysActiveTxComIPdusStruct()               (TRUE != FALSE)
#define Com_HasPartitionsRxStruct()                                                                 (TRUE != FALSE)
#define Com_HasRxIPduGroupISRLockCounterIdxOfPartitionsRxStruct()                                   (TRUE != FALSE)
#define Com_HasPartitionsTxStruct()                                                                 (TRUE != FALSE)
#define Com_HasTxIPduGroupISRLockCounterIdxOfPartitionsTxStruct()                                   (TRUE != FALSE)
#define Com_HasPduGrpCnt()                                                                          (TRUE != FALSE)
#define Com_HasRxAccessInfo()                                                                       (TRUE != FALSE)
#define Com_HasApplTypeOfRxAccessInfo()                                                             (TRUE != FALSE)
#define Com_HasBitLengthOfRxAccessInfo()                                                            (TRUE != FALSE)
#define Com_HasBitPositionOfRxAccessInfo()                                                          (TRUE != FALSE)
#define Com_HasBufferIdxOfRxAccessInfo()                                                            (TRUE != FALSE)
#define Com_HasBufferOfRxAccessInfo()                                                               (TRUE != FALSE)
#define Com_HasBufferUsedOfRxAccessInfo()                                                           (TRUE != FALSE)
#define Com_HasBusAccOfRxAccessInfo()                                                               (TRUE != FALSE)
#define Com_HasByteLengthOfRxAccessInfo()                                                           (TRUE != FALSE)
#define Com_HasBytePositionOfRxAccessInfo()                                                         (TRUE != FALSE)
#define Com_HasDynSignalOfRxAccessInfo()                                                            (TRUE != FALSE)
#define Com_HasInitValueIdxOfRxAccessInfo()                                                         (TRUE != FALSE)
#define Com_HasInitValueOfRxAccessInfo()                                                            (TRUE != FALSE)
#define Com_HasInitValueUsedOfRxAccessInfo()                                                        (TRUE != FALSE)
#define Com_HasRxPduInfoIdxOfRxAccessInfo()                                                         (TRUE != FALSE)
#define Com_HasSignalLengthInByteOfRxAccessInfo()                                                   (TRUE != FALSE)
#define Com_HasStartByteInPduPositionOfRxAccessInfo()                                               (TRUE != FALSE)
#define Com_HasRxAccessInfoInd()                                                                    (TRUE != FALSE)
#define Com_HasRxDefPduBuffer()                                                                     (TRUE != FALSE)
#define Com_HasRxIPduGroupISRLockCounter()                                                          (TRUE != FALSE)
#define Com_HasRxIPduGroupISRLockThreshold()                                                        (TRUE != FALSE)
#define Com_HasRxMainFunctionProcessingISRLockCounter()                                             (TRUE != FALSE)
#define Com_HasRxMainFunctionProcessingISRLockThreshold()                                           (TRUE != FALSE)
#define Com_HasRxPduGrpActive()                                                                     (TRUE != FALSE)
#define Com_HasRxPduInfo()                                                                          (TRUE != FALSE)
#define Com_HasHandleRxPduDeferredIdxOfRxPduInfo()                                                  (TRUE != FALSE)
#define Com_HasHandleRxPduDeferredUsedOfRxPduInfo()                                                 (TRUE != FALSE)
#define Com_HasIPduGroupInfoOfRxPduInfoIndEndIdxOfRxPduInfo()                                       (TRUE != FALSE)
#define Com_HasIPduGroupInfoOfRxPduInfoIndStartIdxOfRxPduInfo()                                     (TRUE != FALSE)
#define Com_HasIPduGroupInfoOfRxPduInfoIndUsedOfRxPduInfo()                                         (TRUE != FALSE)
#define Com_HasMainFunctionRxStructIdxOfRxPduInfo()                                                 (TRUE != FALSE)
#define Com_HasMainFunctionRxStructUsedOfRxPduInfo()                                                (TRUE != FALSE)
#define Com_HasPartitionsRxStructIdxOfRxPduInfo()                                                   (TRUE != FALSE)
#define Com_HasRxAccessInfoIndEndIdxOfRxPduInfo()                                                   (TRUE != FALSE)
#define Com_HasRxAccessInfoIndStartIdxOfRxPduInfo()                                                 (TRUE != FALSE)
#define Com_HasRxAccessInfoIndUsedOfRxPduInfo()                                                     (TRUE != FALSE)
#define Com_HasRxDefPduBufferEndIdxOfRxPduInfo()                                                    (TRUE != FALSE)
#define Com_HasRxDefPduBufferLengthOfRxPduInfo()                                                    (TRUE != FALSE)
#define Com_HasRxDefPduBufferStartIdxOfRxPduInfo()                                                  (TRUE != FALSE)
#define Com_HasRxDefPduBufferUsedOfRxPduInfo()                                                      (TRUE != FALSE)
#define Com_HasRxSigInfoEndIdxOfRxPduInfo()                                                         (TRUE != FALSE)
#define Com_HasRxSigInfoStartIdxOfRxPduInfo()                                                       (TRUE != FALSE)
#define Com_HasRxSigInfoUsedOfRxPduInfo()                                                           (TRUE != FALSE)
#define Com_HasSignalProcessingOfRxPduInfo()                                                        (TRUE != FALSE)
#define Com_HasTypeOfRxPduInfo()                                                                    (TRUE != FALSE)
#define Com_HasRxPduInfoInd()                                                                       (TRUE != FALSE)
#define Com_HasRxPduInfoOfMainFunctionRxInd()                                                       (TRUE != FALSE)
#define Com_HasRxSigBufferUInt8()                                                                   (TRUE != FALSE)
#define Com_HasRxSigInfo()                                                                          (TRUE != FALSE)
#define Com_HasRxAccessInfoIdxOfRxSigInfo()                                                         (TRUE != FALSE)
#define Com_HasSignalProcessingOfRxSigInfo()                                                        (TRUE != FALSE)
#define Com_HasValidDlcOfRxSigInfo()                                                                (TRUE != FALSE)
#define Com_HasSizeOfAlwaysActiveTxComIPdus()                                                       (TRUE != FALSE)
#define Com_HasSizeOfConstValueUInt8()                                                              (TRUE != FALSE)
#define Com_HasSizeOfCurrentTxMode()                                                                (TRUE != FALSE)
#define Com_HasSizeOfCycleTimeCnt()                                                                 (TRUE != FALSE)
#define Com_HasSizeOfCyclicSendRequest()                                                            (TRUE != FALSE)
#define Com_HasSizeOfHandleRxPduDeferred()                                                          (TRUE != FALSE)
#define Com_HasSizeOfIPduGroupInfo()                                                                (TRUE != FALSE)
#define Com_HasSizeOfIPduGroupInfoOfRxPduInfoInd()                                                  (TRUE != FALSE)
#define Com_HasSizeOfIPduGroupInfoOfTxPduInfoInd()                                                  (TRUE != FALSE)
#define Com_HasSizeOfIPduGroupInfoToSubIPduGroupsInd()                                              (TRUE != FALSE)
#define Com_HasSizeOfIPduGroupState()                                                               (TRUE != FALSE)
#define Com_HasSizeOfMainFunctionRxStruct()                                                         (TRUE != FALSE)
#define Com_HasSizeOfMainFunctionTxStruct()                                                         (TRUE != FALSE)
#define Com_HasSizeOfPartitionsAlwaysActiveTxComIPdusStruct()                                       (TRUE != FALSE)
#define Com_HasSizeOfPartitionsRxStruct()                                                           (TRUE != FALSE)
#define Com_HasSizeOfPartitionsTxStruct()                                                           (TRUE != FALSE)
#define Com_HasSizeOfRxAccessInfo()                                                                 (TRUE != FALSE)
#define Com_HasSizeOfRxAccessInfoInd()                                                              (TRUE != FALSE)
#define Com_HasSizeOfRxDefPduBuffer()                                                               (TRUE != FALSE)
#define Com_HasSizeOfRxIPduGroupISRLockCounter()                                                    (TRUE != FALSE)
#define Com_HasSizeOfRxMainFunctionProcessingISRLockCounter()                                       (TRUE != FALSE)
#define Com_HasSizeOfRxPduGrpActive()                                                               (TRUE != FALSE)
#define Com_HasSizeOfRxPduInfo()                                                                    (TRUE != FALSE)
#define Com_HasSizeOfRxPduInfoInd()                                                                 (TRUE != FALSE)
#define Com_HasSizeOfRxPduInfoOfMainFunctionRxInd()                                                 (TRUE != FALSE)
#define Com_HasSizeOfRxSigBufferUInt8()                                                             (TRUE != FALSE)
#define Com_HasSizeOfRxSigInfo()                                                                    (TRUE != FALSE)
#define Com_HasSizeOfTransmitRequest()                                                              (TRUE != FALSE)
#define Com_HasSizeOfTxAccessInfo()                                                                 (TRUE != FALSE)
#define Com_HasSizeOfTxBuffer()                                                                     (TRUE != FALSE)
#define Com_HasSizeOfTxCyclicPdu()                                                                  (TRUE != FALSE)
#define Com_HasSizeOfTxCyclicPduOfMainFunctionTxInd()                                               (TRUE != FALSE)
#define Com_HasSizeOfTxIPduGroupISRLockCounter()                                                    (TRUE != FALSE)
#define Com_HasSizeOfTxModeFalse()                                                                  (TRUE != FALSE)
#define Com_HasSizeOfTxModeInfo()                                                                   (TRUE != FALSE)
#define Com_HasSizeOfTxModeTrue()                                                                   (TRUE != FALSE)
#define Com_HasSizeOfTxPduGrpActive()                                                               (TRUE != FALSE)
#define Com_HasSizeOfTxPduInfo()                                                                    (TRUE != FALSE)
#define Com_HasSizeOfTxPduInfoInd()                                                                 (TRUE != FALSE)
#define Com_HasSizeOfTxPduInfoOfMainFunctionTxInd()                                                 (TRUE != FALSE)
#define Com_HasSizeOfTxPduInitValue()                                                               (TRUE != FALSE)
#define Com_HasSizeOfTxProcessingISRLockCounter()                                                   (TRUE != FALSE)
#define Com_HasSizeOfTxSduLength()                                                                  (TRUE != FALSE)
#define Com_HasSizeOfTxSigInfo()                                                                    (TRUE != FALSE)
#define Com_HasTransmitRequest()                                                                    (TRUE != FALSE)
#define Com_HasTxAccessInfo()                                                                       (TRUE != FALSE)
#define Com_HasTxSigInfoIdxOfTxAccessInfo()                                                         (TRUE != FALSE)
#define Com_HasTxSigInfoUsedOfTxAccessInfo()                                                        (TRUE != FALSE)
#define Com_HasTxBuffer()                                                                           (TRUE != FALSE)
#define Com_HasTxCyclicPdu()                                                                        (TRUE != FALSE)
#define Com_HasTxPduInfoIdxOfTxCyclicPdu()                                                          (TRUE != FALSE)
#define Com_HasTxCyclicPduOfMainFunctionTxInd()                                                     (TRUE != FALSE)
#define Com_HasTxIPduGroupISRLockCounter()                                                          (TRUE != FALSE)
#define Com_HasTxIPduGroupISRLockThreshold()                                                        (TRUE != FALSE)
#define Com_HasTxModeFalse()                                                                        (TRUE != FALSE)
#define Com_HasPeriodicOfTxModeFalse()                                                              (TRUE != FALSE)
#define Com_HasTimePeriodOfTxModeFalse()                                                            (TRUE != FALSE)
#define Com_HasTxModeInfo()                                                                         (TRUE != FALSE)
#define Com_HasInitModeOfTxModeInfo()                                                               (TRUE != FALSE)
#define Com_HasTxModeFalseIdxOfTxModeInfo()                                                         (TRUE != FALSE)
#define Com_HasTxModeTrueIdxOfTxModeInfo()                                                          (TRUE != FALSE)
#define Com_HasTxModeTrue()                                                                         (TRUE != FALSE)
#define Com_HasPeriodicOfTxModeTrue()                                                               (TRUE != FALSE)
#define Com_HasTimePeriodOfTxModeTrue()                                                             (TRUE != FALSE)
#define Com_HasTxPduGrpActive()                                                                     (TRUE != FALSE)
#define Com_HasTxPduInfo()                                                                          (TRUE != FALSE)
#define Com_HasExternalIdOfTxPduInfo()                                                              (TRUE != FALSE)
#define Com_HasIPduGroupInfoOfTxPduInfoIndEndIdxOfTxPduInfo()                                       (TRUE != FALSE)
#define Com_HasIPduGroupInfoOfTxPduInfoIndStartIdxOfTxPduInfo()                                     (TRUE != FALSE)
#define Com_HasIPduGroupInfoOfTxPduInfoIndUsedOfTxPduInfo()                                         (TRUE != FALSE)
#define Com_HasMetaDataLengthOfTxPduInfo()                                                          (TRUE != FALSE)
#define Com_HasPartitionsTxStructIdxOfTxPduInfo()                                                   (TRUE != FALSE)
#define Com_HasPduWithMetaDataLengthOfTxPduInfo()                                                   (TRUE != FALSE)
#define Com_HasTxBufferEndIdxOfTxPduInfo()                                                          (TRUE != FALSE)
#define Com_HasTxBufferLengthOfTxPduInfo()                                                          (TRUE != FALSE)
#define Com_HasTxBufferStartIdxOfTxPduInfo()                                                        (TRUE != FALSE)
#define Com_HasTxBufferUsedOfTxPduInfo()                                                            (TRUE != FALSE)
#define Com_HasTxModeInfoIdxOfTxPduInfo()                                                           (TRUE != FALSE)
#define Com_HasTxPduInitValueEndIdxOfTxPduInfo()                                                    (TRUE != FALSE)
#define Com_HasTxPduInitValueStartIdxOfTxPduInfo()                                                  (TRUE != FALSE)
#define Com_HasTxPduInitValueUsedOfTxPduInfo()                                                      (TRUE != FALSE)
#define Com_HasTypeOfTxPduInfo()                                                                    (TRUE != FALSE)
#define Com_HasTxPduInfoInd()                                                                       (TRUE != FALSE)
#define Com_HasTxPduInfoOfMainFunctionTxInd()                                                       (TRUE != FALSE)
#define Com_HasTxPduInitValue()                                                                     (TRUE != FALSE)
#define Com_HasTxProcessingISRLockCounter()                                                         (TRUE != FALSE)
#define Com_HasTxProcessingISRLockThreshold()                                                       (TRUE != FALSE)
#define Com_HasTxSduLength()                                                                        (TRUE != FALSE)
#define Com_HasTxSigInfo()                                                                          (TRUE != FALSE)
#define Com_HasApplTypeOfTxSigInfo()                                                                (TRUE != FALSE)
#define Com_HasBitLengthOfTxSigInfo()                                                               (TRUE != FALSE)
#define Com_HasBitPositionOfTxSigInfo()                                                             (TRUE != FALSE)
#define Com_HasBusAccOfTxSigInfo()                                                                  (TRUE != FALSE)
#define Com_HasByteLengthOfTxSigInfo()                                                              (TRUE != FALSE)
#define Com_HasBytePositionOfTxSigInfo()                                                            (TRUE != FALSE)
#define Com_HasDynSignalOfTxSigInfo()                                                               (TRUE != FALSE)
#define Com_HasStartByteInPduPositionOfTxSigInfo()                                                  (TRUE != FALSE)
#define Com_HasTxAccessInfoIdxOfTxSigInfo()                                                         (TRUE != FALSE)
#define Com_HasTxBufferEndIdxOfTxSigInfo()                                                          (TRUE != FALSE)
#define Com_HasTxBufferLengthOfTxSigInfo()                                                          (TRUE != FALSE)
#define Com_HasTxBufferStartIdxOfTxSigInfo()                                                        (TRUE != FALSE)
#define Com_HasTxBufferUsedOfTxSigInfo()                                                            (TRUE != FALSE)
#define Com_HasTxPduInfoIdxOfTxSigInfo()                                                            (TRUE != FALSE)
#define Com_HasPCConfig()                                                                           (TRUE != FALSE)
#define Com_HasAlwaysActiveTxComIPdusOfPCConfig()                                                   (TRUE != FALSE)
#define Com_HasConfigIdOfPCConfig()                                                                 (TRUE != FALSE)
#define Com_HasConstValueUInt8OfPCConfig()                                                          (TRUE != FALSE)
#define Com_HasCurrentTxModeOfPCConfig()                                                            (TRUE != FALSE)
#define Com_HasCycleTimeCntOfPCConfig()                                                             (TRUE != FALSE)
#define Com_HasCyclicSendRequestOfPCConfig()                                                        (TRUE != FALSE)
#define Com_HasHandleRxPduDeferredOfPCConfig()                                                      (TRUE != FALSE)
#define Com_HasIPduGroupInfoOfPCConfig()                                                            (TRUE != FALSE)
#define Com_HasIPduGroupInfoOfRxPduInfoIndOfPCConfig()                                              (TRUE != FALSE)
#define Com_HasIPduGroupInfoOfTxPduInfoIndOfPCConfig()                                              (TRUE != FALSE)
#define Com_HasIPduGroupInfoToSubIPduGroupsIndOfPCConfig()                                          (TRUE != FALSE)
#define Com_HasIPduGroupStateOfPCConfig()                                                           (TRUE != FALSE)
#define Com_HasInitializedOfPCConfig()                                                              (TRUE != FALSE)
#define Com_HasMainFunctionRxStructOfPCConfig()                                                     (TRUE != FALSE)
#define Com_HasMainFunctionTxStructOfPCConfig()                                                     (TRUE != FALSE)
#define Com_HasPartitionsAlwaysActiveTxComIPdusStructOfPCConfig()                                   (TRUE != FALSE)
#define Com_HasPartitionsRxStructOfPCConfig()                                                       (TRUE != FALSE)
#define Com_HasPartitionsTxStructOfPCConfig()                                                       (TRUE != FALSE)
#define Com_HasPduGrpCntOfPCConfig()                                                                (TRUE != FALSE)
#define Com_HasRxAccessInfoIndOfPCConfig()                                                          (TRUE != FALSE)
#define Com_HasRxAccessInfoOfPCConfig()                                                             (TRUE != FALSE)
#define Com_HasRxDefPduBufferOfPCConfig()                                                           (TRUE != FALSE)
#define Com_HasRxIPduGroupISRLockCounterOfPCConfig()                                                (TRUE != FALSE)
#define Com_HasRxIPduGroupISRLockThresholdOfPCConfig()                                              (TRUE != FALSE)
#define Com_HasRxMainFunctionProcessingISRLockCounterOfPCConfig()                                   (TRUE != FALSE)
#define Com_HasRxMainFunctionProcessingISRLockThresholdOfPCConfig()                                 (TRUE != FALSE)
#define Com_HasRxPduGrpActiveOfPCConfig()                                                           (TRUE != FALSE)
#define Com_HasRxPduInfoIndOfPCConfig()                                                             (TRUE != FALSE)
#define Com_HasRxPduInfoOfMainFunctionRxIndOfPCConfig()                                             (TRUE != FALSE)
#define Com_HasRxPduInfoOfPCConfig()                                                                (TRUE != FALSE)
#define Com_HasRxSigBufferUInt8OfPCConfig()                                                         (TRUE != FALSE)
#define Com_HasRxSigInfoOfPCConfig()                                                                (TRUE != FALSE)
#define Com_HasSizeOfAlwaysActiveTxComIPdusOfPCConfig()                                             (TRUE != FALSE)
#define Com_HasSizeOfConstValueUInt8OfPCConfig()                                                    (TRUE != FALSE)
#define Com_HasSizeOfCurrentTxModeOfPCConfig()                                                      (TRUE != FALSE)
#define Com_HasSizeOfCycleTimeCntOfPCConfig()                                                       (TRUE != FALSE)
#define Com_HasSizeOfCyclicSendRequestOfPCConfig()                                                  (TRUE != FALSE)
#define Com_HasSizeOfHandleRxPduDeferredOfPCConfig()                                                (TRUE != FALSE)
#define Com_HasSizeOfIPduGroupInfoOfPCConfig()                                                      (TRUE != FALSE)
#define Com_HasSizeOfIPduGroupInfoOfRxPduInfoIndOfPCConfig()                                        (TRUE != FALSE)
#define Com_HasSizeOfIPduGroupInfoOfTxPduInfoIndOfPCConfig()                                        (TRUE != FALSE)
#define Com_HasSizeOfIPduGroupInfoToSubIPduGroupsIndOfPCConfig()                                    (TRUE != FALSE)
#define Com_HasSizeOfIPduGroupStateOfPCConfig()                                                     (TRUE != FALSE)
#define Com_HasSizeOfMainFunctionRxStructOfPCConfig()                                               (TRUE != FALSE)
#define Com_HasSizeOfMainFunctionTxStructOfPCConfig()                                               (TRUE != FALSE)
#define Com_HasSizeOfPartitionsAlwaysActiveTxComIPdusStructOfPCConfig()                             (TRUE != FALSE)
#define Com_HasSizeOfPartitionsRxStructOfPCConfig()                                                 (TRUE != FALSE)
#define Com_HasSizeOfPartitionsTxStructOfPCConfig()                                                 (TRUE != FALSE)
#define Com_HasSizeOfRxAccessInfoIndOfPCConfig()                                                    (TRUE != FALSE)
#define Com_HasSizeOfRxAccessInfoOfPCConfig()                                                       (TRUE != FALSE)
#define Com_HasSizeOfRxDefPduBufferOfPCConfig()                                                     (TRUE != FALSE)
#define Com_HasSizeOfRxIPduGroupISRLockCounterOfPCConfig()                                          (TRUE != FALSE)
#define Com_HasSizeOfRxMainFunctionProcessingISRLockCounterOfPCConfig()                             (TRUE != FALSE)
#define Com_HasSizeOfRxPduGrpActiveOfPCConfig()                                                     (TRUE != FALSE)
#define Com_HasSizeOfRxPduInfoIndOfPCConfig()                                                       (TRUE != FALSE)
#define Com_HasSizeOfRxPduInfoOfMainFunctionRxIndOfPCConfig()                                       (TRUE != FALSE)
#define Com_HasSizeOfRxPduInfoOfPCConfig()                                                          (TRUE != FALSE)
#define Com_HasSizeOfRxSigBufferUInt8OfPCConfig()                                                   (TRUE != FALSE)
#define Com_HasSizeOfRxSigInfoOfPCConfig()                                                          (TRUE != FALSE)
#define Com_HasSizeOfTransmitRequestOfPCConfig()                                                    (TRUE != FALSE)
#define Com_HasSizeOfTxAccessInfoOfPCConfig()                                                       (TRUE != FALSE)
#define Com_HasSizeOfTxBufferOfPCConfig()                                                           (TRUE != FALSE)
#define Com_HasSizeOfTxCyclicPduOfMainFunctionTxIndOfPCConfig()                                     (TRUE != FALSE)
#define Com_HasSizeOfTxCyclicPduOfPCConfig()                                                        (TRUE != FALSE)
#define Com_HasSizeOfTxIPduGroupISRLockCounterOfPCConfig()                                          (TRUE != FALSE)
#define Com_HasSizeOfTxModeFalseOfPCConfig()                                                        (TRUE != FALSE)
#define Com_HasSizeOfTxModeInfoOfPCConfig()                                                         (TRUE != FALSE)
#define Com_HasSizeOfTxModeTrueOfPCConfig()                                                         (TRUE != FALSE)
#define Com_HasSizeOfTxPduGrpActiveOfPCConfig()                                                     (TRUE != FALSE)
#define Com_HasSizeOfTxPduInfoIndOfPCConfig()                                                       (TRUE != FALSE)
#define Com_HasSizeOfTxPduInfoOfMainFunctionTxIndOfPCConfig()                                       (TRUE != FALSE)
#define Com_HasSizeOfTxPduInfoOfPCConfig()                                                          (TRUE != FALSE)
#define Com_HasSizeOfTxPduInitValueOfPCConfig()                                                     (TRUE != FALSE)
#define Com_HasSizeOfTxProcessingISRLockCounterOfPCConfig()                                         (TRUE != FALSE)
#define Com_HasSizeOfTxSduLengthOfPCConfig()                                                        (TRUE != FALSE)
#define Com_HasSizeOfTxSigInfoOfPCConfig()                                                          (TRUE != FALSE)
#define Com_HasTransmitRequestOfPCConfig()                                                          (TRUE != FALSE)
#define Com_HasTxAccessInfoOfPCConfig()                                                             (TRUE != FALSE)
#define Com_HasTxBufferOfPCConfig()                                                                 (TRUE != FALSE)
#define Com_HasTxCyclicPduOfMainFunctionTxIndOfPCConfig()                                           (TRUE != FALSE)
#define Com_HasTxCyclicPduOfPCConfig()                                                              (TRUE != FALSE)
#define Com_HasTxIPduGroupISRLockCounterOfPCConfig()                                                (TRUE != FALSE)
#define Com_HasTxIPduGroupISRLockThresholdOfPCConfig()                                              (TRUE != FALSE)
#define Com_HasTxModeFalseOfPCConfig()                                                              (TRUE != FALSE)
#define Com_HasTxModeInfoOfPCConfig()                                                               (TRUE != FALSE)
#define Com_HasTxModeTrueOfPCConfig()                                                               (TRUE != FALSE)
#define Com_HasTxPduGrpActiveOfPCConfig()                                                           (TRUE != FALSE)
#define Com_HasTxPduInfoIndOfPCConfig()                                                             (TRUE != FALSE)
#define Com_HasTxPduInfoOfMainFunctionTxIndOfPCConfig()                                             (TRUE != FALSE)
#define Com_HasTxPduInfoOfPCConfig()                                                                (TRUE != FALSE)
#define Com_HasTxPduInitValueOfPCConfig()                                                           (TRUE != FALSE)
#define Com_HasTxProcessingISRLockCounterOfPCConfig()                                               (TRUE != FALSE)
#define Com_HasTxProcessingISRLockThresholdOfPCConfig()                                             (TRUE != FALSE)
#define Com_HasTxSduLengthOfPCConfig()                                                              (TRUE != FALSE)
#define Com_HasTxSigInfoOfPCConfig()                                                                (TRUE != FALSE)
/** 
  \}
*/ 

/** 
  \defgroup  ComPCIncrementDataMacros  Com Increment Data Macros (PRE_COMPILE)
  \brief  These macros can be used to increment VAR data with numerical nature.
  \{
*/ 
#define Com_IncCycleTimeCnt(Index)                                                                  Com_GetCycleTimeCnt(Index)++
#define Com_IncHandleRxPduDeferred(Index)                                                           Com_GetHandleRxPduDeferred(Index)++
#define Com_IncRxDefPduBuffer(Index)                                                                Com_GetRxDefPduBuffer(Index)++
#define Com_IncRxIPduGroupISRLockCounter(Index)                                                     Com_GetRxIPduGroupISRLockCounter(Index)++
#define Com_IncRxMainFunctionProcessingISRLockCounter(Index)                                        Com_GetRxMainFunctionProcessingISRLockCounter(Index)++
#define Com_IncRxSigBufferUInt8(Index)                                                              Com_GetRxSigBufferUInt8(Index)++
#define Com_IncTxBuffer(Index)                                                                      Com_GetTxBuffer(Index)++
#define Com_IncTxIPduGroupISRLockCounter(Index)                                                     Com_GetTxIPduGroupISRLockCounter(Index)++
#define Com_IncTxProcessingISRLockCounter(Index)                                                    Com_GetTxProcessingISRLockCounter(Index)++
#define Com_IncTxSduLength(Index)                                                                   Com_GetTxSduLength(Index)++
/** 
  \}
*/ 

/** 
  \defgroup  ComPCDecrementDataMacros  Com Decrement Data Macros (PRE_COMPILE)
  \brief  These macros can be used to decrement VAR data with numerical nature.
  \{
*/ 
#define Com_DecCycleTimeCnt(Index)                                                                  Com_GetCycleTimeCnt(Index)--
#define Com_DecHandleRxPduDeferred(Index)                                                           Com_GetHandleRxPduDeferred(Index)--
#define Com_DecRxDefPduBuffer(Index)                                                                Com_GetRxDefPduBuffer(Index)--
#define Com_DecRxIPduGroupISRLockCounter(Index)                                                     Com_GetRxIPduGroupISRLockCounter(Index)--
#define Com_DecRxMainFunctionProcessingISRLockCounter(Index)                                        Com_GetRxMainFunctionProcessingISRLockCounter(Index)--
#define Com_DecRxSigBufferUInt8(Index)                                                              Com_GetRxSigBufferUInt8(Index)--
#define Com_DecTxBuffer(Index)                                                                      Com_GetTxBuffer(Index)--
#define Com_DecTxIPduGroupISRLockCounter(Index)                                                     Com_GetTxIPduGroupISRLockCounter(Index)--
#define Com_DecTxProcessingISRLockCounter(Index)                                                    Com_GetTxProcessingISRLockCounter(Index)--
#define Com_DecTxSduLength(Index)                                                                   Com_GetTxSduLength(Index)--
/** 
  \}
*/ 

/** 
  \defgroup  ComPCAddDataMacros  Com Add Data Macros (PRE_COMPILE)
  \brief  These macros can be used to add VAR data with numerical nature.
  \{
*/ 
#define Com_AddCycleTimeCnt(Index, Value)                                                           Com_SetCycleTimeCnt(Index, (Com_GetCycleTimeCnt(Index) + Value))
#define Com_AddHandleRxPduDeferred(Index, Value)                                                    Com_SetHandleRxPduDeferred(Index, (Com_GetHandleRxPduDeferred(Index) + Value))
#define Com_AddRxDefPduBuffer(Index, Value)                                                         Com_SetRxDefPduBuffer(Index, (Com_GetRxDefPduBuffer(Index) + Value))
#define Com_AddRxIPduGroupISRLockCounter(Index, Value)                                              Com_SetRxIPduGroupISRLockCounter(Index, (Com_GetRxIPduGroupISRLockCounter(Index) + Value))
#define Com_AddRxMainFunctionProcessingISRLockCounter(Index, Value)                                 Com_SetRxMainFunctionProcessingISRLockCounter(Index, (Com_GetRxMainFunctionProcessingISRLockCounter(Index) + Value))
#define Com_AddRxSigBufferUInt8(Index, Value)                                                       Com_SetRxSigBufferUInt8(Index, (Com_GetRxSigBufferUInt8(Index) + Value))
#define Com_AddTxBuffer(Index, Value)                                                               Com_SetTxBuffer(Index, (Com_GetTxBuffer(Index) + Value))
#define Com_AddTxIPduGroupISRLockCounter(Index, Value)                                              Com_SetTxIPduGroupISRLockCounter(Index, (Com_GetTxIPduGroupISRLockCounter(Index) + Value))
#define Com_AddTxProcessingISRLockCounter(Index, Value)                                             Com_SetTxProcessingISRLockCounter(Index, (Com_GetTxProcessingISRLockCounter(Index) + Value))
#define Com_AddTxSduLength(Index, Value)                                                            Com_SetTxSduLength(Index, (Com_GetTxSduLength(Index) + Value))
/** 
  \}
*/ 

/** 
  \defgroup  ComPCSubstractDataMacros  Com Substract Data Macros (PRE_COMPILE)
  \brief  These macros can be used to substract VAR data with numerical nature.
  \{
*/ 
#define Com_SubCycleTimeCnt(Index, Value)                                                           Com_SetCycleTimeCnt(Index, (Com_GetCycleTimeCnt(Index) - Value))
#define Com_SubHandleRxPduDeferred(Index, Value)                                                    Com_SetHandleRxPduDeferred(Index, (Com_GetHandleRxPduDeferred(Index) - Value))
#define Com_SubRxDefPduBuffer(Index, Value)                                                         Com_SetRxDefPduBuffer(Index, (Com_GetRxDefPduBuffer(Index) - Value))
#define Com_SubRxIPduGroupISRLockCounter(Index, Value)                                              Com_SetRxIPduGroupISRLockCounter(Index, (Com_GetRxIPduGroupISRLockCounter(Index) - Value))
#define Com_SubRxMainFunctionProcessingISRLockCounter(Index, Value)                                 Com_SetRxMainFunctionProcessingISRLockCounter(Index, (Com_GetRxMainFunctionProcessingISRLockCounter(Index) - Value))
#define Com_SubRxSigBufferUInt8(Index, Value)                                                       Com_SetRxSigBufferUInt8(Index, (Com_GetRxSigBufferUInt8(Index) - Value))
#define Com_SubTxBuffer(Index, Value)                                                               Com_SetTxBuffer(Index, (Com_GetTxBuffer(Index) - Value))
#define Com_SubTxIPduGroupISRLockCounter(Index, Value)                                              Com_SetTxIPduGroupISRLockCounter(Index, (Com_GetTxIPduGroupISRLockCounter(Index) - Value))
#define Com_SubTxProcessingISRLockCounter(Index, Value)                                             Com_SetTxProcessingISRLockCounter(Index, (Com_GetTxProcessingISRLockCounter(Index) - Value))
#define Com_SubTxSduLength(Index, Value)                                                            Com_SetTxSduLength(Index, (Com_GetTxSduLength(Index) - Value))
/** 
  \}
*/ 

  /* PRQA L:Macros_3453 */
/** 
  \}
*/ 

/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL ACCESS FUNCTION MACROS
**********************************************************************************************************************/

/** 
  \defgroup  DataAccessMacros  Data Access Macros
  \brief  generated data access macros to abstract the generated data from the code to read and write CONST or VAR data.
  \{
*/ 
  /* PRQA S 3453 Macros_3453 */  /* MD_MSR_FctLikeMacro */
/**********************************************************************************************************************
  CONFIGURATION CLASS: LINK
  SECTION: GLOBAL FUNCTION MACROS
**********************************************************************************************************************/
  /* PRQA L:Macros_3453 */
/** 
  \}
*/ 

/**********************************************************************************************************************
  CONFIGURATION CLASS: LINK
  SECTION: GLOBAL ACCESS FUNCTION MACROS
**********************************************************************************************************************/


/**********************************************************************************************************************
  GLOBAL DATA TYPES AND STRUCTURES
**********************************************************************************************************************/
/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: SIZEOF DATA TYPES
**********************************************************************************************************************/
/** 
  \defgroup  ComPCSizeOfTypes  Com SizeOf Types (PRE_COMPILE)
  \brief  These type definitions are used for the SizeOf information.
  \{
*/ 
/**   \brief  value based type definition for Com_SizeOfAlwaysActiveTxComIPdus */
typedef uint8 Com_SizeOfAlwaysActiveTxComIPdusType;

/**   \brief  value based type definition for Com_SizeOfConstValueUInt8 */
typedef uint8 Com_SizeOfConstValueUInt8Type;

/**   \brief  value based type definition for Com_SizeOfCurrentTxMode */
typedef uint8 Com_SizeOfCurrentTxModeType;

/**   \brief  value based type definition for Com_SizeOfCycleTimeCnt */
typedef uint8 Com_SizeOfCycleTimeCntType;

/**   \brief  value based type definition for Com_SizeOfCyclicSendRequest */
typedef uint8 Com_SizeOfCyclicSendRequestType;

/**   \brief  value based type definition for Com_SizeOfHandleRxPduDeferred */
typedef uint8 Com_SizeOfHandleRxPduDeferredType;

/**   \brief  value based type definition for Com_SizeOfIPduGroupInfo */
typedef uint8 Com_SizeOfIPduGroupInfoType;

/**   \brief  value based type definition for Com_SizeOfIPduGroupInfoOfRxPduInfoInd */
typedef uint8 Com_SizeOfIPduGroupInfoOfRxPduInfoIndType;

/**   \brief  value based type definition for Com_SizeOfIPduGroupInfoOfTxPduInfoInd */
typedef uint8 Com_SizeOfIPduGroupInfoOfTxPduInfoIndType;

/**   \brief  value based type definition for Com_SizeOfIPduGroupInfoToSubIPduGroupsInd */
typedef uint8 Com_SizeOfIPduGroupInfoToSubIPduGroupsIndType;

/**   \brief  value based type definition for Com_SizeOfIPduGroupState */
typedef uint8 Com_SizeOfIPduGroupStateType;

/**   \brief  value based type definition for Com_SizeOfMainFunctionRxStruct */
typedef uint8 Com_SizeOfMainFunctionRxStructType;

/**   \brief  value based type definition for Com_SizeOfMainFunctionTxStruct */
typedef uint8 Com_SizeOfMainFunctionTxStructType;

/**   \brief  value based type definition for Com_SizeOfPartitionsAlwaysActiveTxComIPdusStruct */
typedef uint8 Com_SizeOfPartitionsAlwaysActiveTxComIPdusStructType;

/**   \brief  value based type definition for Com_SizeOfPartitionsRxStruct */
typedef uint8 Com_SizeOfPartitionsRxStructType;

/**   \brief  value based type definition for Com_SizeOfPartitionsTxStruct */
typedef uint8 Com_SizeOfPartitionsTxStructType;

/**   \brief  value based type definition for Com_SizeOfRxAccessInfo */
typedef uint8 Com_SizeOfRxAccessInfoType;

/**   \brief  value based type definition for Com_SizeOfRxAccessInfoInd */
typedef uint8 Com_SizeOfRxAccessInfoIndType;

/**   \brief  value based type definition for Com_SizeOfRxDefPduBuffer */
typedef uint8 Com_SizeOfRxDefPduBufferType;

/**   \brief  value based type definition for Com_SizeOfRxIPduGroupISRLockCounter */
typedef uint8 Com_SizeOfRxIPduGroupISRLockCounterType;

/**   \brief  value based type definition for Com_SizeOfRxMainFunctionProcessingISRLockCounter */
typedef uint8 Com_SizeOfRxMainFunctionProcessingISRLockCounterType;

/**   \brief  value based type definition for Com_SizeOfRxPduGrpActive */
typedef uint8 Com_SizeOfRxPduGrpActiveType;

/**   \brief  value based type definition for Com_SizeOfRxPduInfo */
typedef uint8 Com_SizeOfRxPduInfoType;

/**   \brief  value based type definition for Com_SizeOfRxPduInfoInd */
typedef uint8 Com_SizeOfRxPduInfoIndType;

/**   \brief  value based type definition for Com_SizeOfRxPduInfoOfMainFunctionRxInd */
typedef uint8 Com_SizeOfRxPduInfoOfMainFunctionRxIndType;

/**   \brief  value based type definition for Com_SizeOfRxSigBufferUInt8 */
typedef uint8 Com_SizeOfRxSigBufferUInt8Type;

/**   \brief  value based type definition for Com_SizeOfRxSigInfo */
typedef uint8 Com_SizeOfRxSigInfoType;

/**   \brief  value based type definition for Com_SizeOfTransmitRequest */
typedef uint8 Com_SizeOfTransmitRequestType;

/**   \brief  value based type definition for Com_SizeOfTxAccessInfo */
typedef uint8 Com_SizeOfTxAccessInfoType;

/**   \brief  value based type definition for Com_SizeOfTxBuffer */
typedef uint8 Com_SizeOfTxBufferType;

/**   \brief  value based type definition for Com_SizeOfTxCyclicPdu */
typedef uint8 Com_SizeOfTxCyclicPduType;

/**   \brief  value based type definition for Com_SizeOfTxCyclicPduOfMainFunctionTxInd */
typedef uint8 Com_SizeOfTxCyclicPduOfMainFunctionTxIndType;

/**   \brief  value based type definition for Com_SizeOfTxIPduGroupISRLockCounter */
typedef uint8 Com_SizeOfTxIPduGroupISRLockCounterType;

/**   \brief  value based type definition for Com_SizeOfTxModeFalse */
typedef uint8 Com_SizeOfTxModeFalseType;

/**   \brief  value based type definition for Com_SizeOfTxModeInfo */
typedef uint8 Com_SizeOfTxModeInfoType;

/**   \brief  value based type definition for Com_SizeOfTxModeTrue */
typedef uint8 Com_SizeOfTxModeTrueType;

/**   \brief  value based type definition for Com_SizeOfTxPduGrpActive */
typedef uint8 Com_SizeOfTxPduGrpActiveType;

/**   \brief  value based type definition for Com_SizeOfTxPduInfo */
typedef uint8 Com_SizeOfTxPduInfoType;

/**   \brief  value based type definition for Com_SizeOfTxPduInfoInd */
typedef uint8 Com_SizeOfTxPduInfoIndType;

/**   \brief  value based type definition for Com_SizeOfTxPduInfoOfMainFunctionTxInd */
typedef uint8 Com_SizeOfTxPduInfoOfMainFunctionTxIndType;

/**   \brief  value based type definition for Com_SizeOfTxPduInitValue */
typedef uint8 Com_SizeOfTxPduInitValueType;

/**   \brief  value based type definition for Com_SizeOfTxProcessingISRLockCounter */
typedef uint8 Com_SizeOfTxProcessingISRLockCounterType;

/**   \brief  value based type definition for Com_SizeOfTxSduLength */
typedef uint8 Com_SizeOfTxSduLengthType;

/**   \brief  value based type definition for Com_SizeOfTxSigInfo */
typedef uint8 Com_SizeOfTxSigInfoType;

/** 
  \}
*/ 

/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL SIMPLE DATA TYPES AND STRUCTURES
**********************************************************************************************************************/
/** 
  \defgroup  ComPCIterableTypes  Com Iterable Types (PRE_COMPILE)
  \brief  These type definitions are used to iterate over an array with least processor cycles for variable access as possible.
  \{
*/ 
/**   \brief  type used to iterate Com_AlwaysActiveTxComIPdus */
typedef uint8_least Com_AlwaysActiveTxComIPdusIterType;

/**   \brief  type used to iterate Com_ConstValueUInt8 */
typedef uint8_least Com_ConstValueUInt8IterType;

/**   \brief  type used to iterate Com_HandleRxPduDeferred */
typedef uint8_least Com_HandleRxPduDeferredIterType;

/**   \brief  type used to iterate Com_IPduGroupInfo */
typedef uint8_least Com_IPduGroupInfoIterType;

/**   \brief  type used to iterate Com_IPduGroupInfoOfRxPduInfoInd */
typedef uint8_least Com_IPduGroupInfoOfRxPduInfoIndIterType;

/**   \brief  type used to iterate Com_IPduGroupInfoOfTxPduInfoInd */
typedef uint8_least Com_IPduGroupInfoOfTxPduInfoIndIterType;

/**   \brief  type used to iterate Com_IPduGroupInfoToSubIPduGroupsInd */
typedef uint8_least Com_IPduGroupInfoToSubIPduGroupsIndIterType;

/**   \brief  type used to iterate Com_MainFunctionRxStruct */
typedef uint8_least Com_MainFunctionRxStructIterType;

/**   \brief  type used to iterate Com_MainFunctionTxStruct */
typedef uint8_least Com_MainFunctionTxStructIterType;

/**   \brief  type used to iterate Com_PartitionsAlwaysActiveTxComIPdusStruct */
typedef uint8_least Com_PartitionsAlwaysActiveTxComIPdusStructIterType;

/**   \brief  type used to iterate Com_PartitionsRxStruct */
typedef uint8_least Com_PartitionsRxStructIterType;

/**   \brief  type used to iterate Com_PartitionsTxStruct */
typedef uint8_least Com_PartitionsTxStructIterType;

/**   \brief  type used to iterate Com_RxAccessInfo */
typedef uint8_least Com_RxAccessInfoIterType;

/**   \brief  type used to iterate Com_RxAccessInfoInd */
typedef uint8_least Com_RxAccessInfoIndIterType;

/**   \brief  type used to iterate Com_RxDefPduBuffer */
typedef uint8_least Com_RxDefPduBufferIterType;

/**   \brief  type used to iterate Com_RxIPduGroupISRLockCounter */
typedef uint8_least Com_RxIPduGroupISRLockCounterIterType;

/**   \brief  type used to iterate Com_RxMainFunctionProcessingISRLockCounter */
typedef uint8_least Com_RxMainFunctionProcessingISRLockCounterIterType;

/**   \brief  type used to iterate Com_RxPduInfo */
typedef uint8_least Com_RxPduInfoIterType;

/**   \brief  type used to iterate Com_RxPduInfoInd */
typedef uint8_least Com_RxPduInfoIndIterType;

/**   \brief  type used to iterate Com_RxPduInfoOfMainFunctionRxInd */
typedef uint8_least Com_RxPduInfoOfMainFunctionRxIndIterType;

/**   \brief  type used to iterate Com_RxSigBufferUInt8 */
typedef uint8_least Com_RxSigBufferUInt8IterType;

/**   \brief  type used to iterate Com_RxSigInfo */
typedef uint8_least Com_RxSigInfoIterType;

/**   \brief  type used to iterate Com_TxAccessInfo */
typedef uint16_least Com_TxAccessInfoIterType;

/**   \brief  type used to iterate Com_TxBuffer */
typedef uint8_least Com_TxBufferIterType;

/**   \brief  type used to iterate Com_TxCyclicPdu */
typedef uint8_least Com_TxCyclicPduIterType;

/**   \brief  type used to iterate Com_TxCyclicPduOfMainFunctionTxInd */
typedef uint8_least Com_TxCyclicPduOfMainFunctionTxIndIterType;

/**   \brief  type used to iterate Com_TxIPduGroupISRLockCounter */
typedef uint8_least Com_TxIPduGroupISRLockCounterIterType;

/**   \brief  type used to iterate Com_TxModeFalse */
typedef uint8_least Com_TxModeFalseIterType;

/**   \brief  type used to iterate Com_TxModeInfo */
typedef uint8_least Com_TxModeInfoIterType;

/**   \brief  type used to iterate Com_TxModeTrue */
typedef uint8_least Com_TxModeTrueIterType;

/**   \brief  type used to iterate Com_TxPduInfo */
typedef uint16_least Com_TxPduInfoIterType;

/**   \brief  type used to iterate Com_TxPduInfoInd */
typedef uint8_least Com_TxPduInfoIndIterType;

/**   \brief  type used to iterate Com_TxPduInfoOfMainFunctionTxInd */
typedef uint8_least Com_TxPduInfoOfMainFunctionTxIndIterType;

/**   \brief  type used to iterate Com_TxPduInitValue */
typedef uint8_least Com_TxPduInitValueIterType;

/**   \brief  type used to iterate Com_TxProcessingISRLockCounter */
typedef uint8_least Com_TxProcessingISRLockCounterIterType;

/**   \brief  type used to iterate Com_TxSigInfo */
typedef uint16_least Com_TxSigInfoIterType;

/** 
  \}
*/ 

/** 
  \defgroup  ComPCIterableTypesWithSizeRelations  Com Iterable Types With Size Relations (PRE_COMPILE)
  \brief  These type definitions are used to iterate over a VAR based array with the same iterator as the related CONST array.
  \{
*/ 
/**   \brief  type used to iterate Com_CurrentTxMode */
typedef Com_TxModeInfoIterType Com_CurrentTxModeIterType;

/**   \brief  type used to iterate Com_CycleTimeCnt */
typedef Com_TxModeInfoIterType Com_CycleTimeCntIterType;

/**   \brief  type used to iterate Com_CyclicSendRequest */
typedef Com_TxModeInfoIterType Com_CyclicSendRequestIterType;

/**   \brief  type used to iterate Com_IPduGroupState */
typedef Com_IPduGroupInfoIterType Com_IPduGroupStateIterType;

/**   \brief  type used to iterate Com_RxPduGrpActive */
typedef Com_RxPduInfoIterType Com_RxPduGrpActiveIterType;

/**   \brief  type used to iterate Com_TransmitRequest */
typedef Com_TxModeInfoIterType Com_TransmitRequestIterType;

/**   \brief  type used to iterate Com_TxPduGrpActive */
typedef Com_TxPduInfoIterType Com_TxPduGrpActiveIterType;

/**   \brief  type used to iterate Com_TxSduLength */
typedef Com_TxPduInfoIterType Com_TxSduLengthIterType;

/** 
  \}
*/ 

/** 
  \defgroup  ComPCValueTypes  Com Value Types (PRE_COMPILE)
  \brief  These type definitions are used for value based data representations.
  \{
*/ 
/**   \brief  value based type definition for Com_PartitionsAlwaysActiveTxComIPdusStructIdxOfAlwaysActiveTxComIPdus */
typedef uint8 Com_PartitionsAlwaysActiveTxComIPdusStructIdxOfAlwaysActiveTxComIPdusType;

/**   \brief  value based type definition for Com_TxPduInfoIdxOfAlwaysActiveTxComIPdus */
typedef uint8 Com_TxPduInfoIdxOfAlwaysActiveTxComIPdusType;

/**   \brief  value based type definition for Com_ConfigId */
typedef uint8 Com_ConfigIdType;

/**   \brief  value based type definition for Com_ConstValueUInt8 */
typedef uint8 Com_ConstValueUInt8Type;

/**   \brief  value based type definition for Com_CurrentTxMode */
typedef boolean Com_CurrentTxModeType;

/**   \brief  value based type definition for Com_CycleTimeCnt */
typedef uint8 Com_CycleTimeCntType;

/**   \brief  value based type definition for Com_CyclicSendRequest */
typedef boolean Com_CyclicSendRequestType;

/**   \brief  value based type definition for Com_HandleRxPduDeferred */
typedef PduLengthType Com_HandleRxPduDeferredType;

/**   \brief  value based type definition for Com_IPduGroupInfoToSubIPduGroupsIndEndIdxOfIPduGroupInfo */
typedef uint8 Com_IPduGroupInfoToSubIPduGroupsIndEndIdxOfIPduGroupInfoType;

/**   \brief  value based type definition for Com_IPduGroupInfoToSubIPduGroupsIndStartIdxOfIPduGroupInfo */
typedef uint8 Com_IPduGroupInfoToSubIPduGroupsIndStartIdxOfIPduGroupInfoType;

/**   \brief  value based type definition for Com_IPduGroupInfoToSubIPduGroupsIndUsedOfIPduGroupInfo */
typedef boolean Com_IPduGroupInfoToSubIPduGroupsIndUsedOfIPduGroupInfoType;

/**   \brief  value based type definition for Com_PartitionsRxStructIdxOfIPduGroupInfo */
typedef uint8 Com_PartitionsRxStructIdxOfIPduGroupInfoType;

/**   \brief  value based type definition for Com_PartitionsRxStructUsedOfIPduGroupInfo */
typedef boolean Com_PartitionsRxStructUsedOfIPduGroupInfoType;

/**   \brief  value based type definition for Com_PartitionsTxStructIdxOfIPduGroupInfo */
typedef uint8 Com_PartitionsTxStructIdxOfIPduGroupInfoType;

/**   \brief  value based type definition for Com_PartitionsTxStructUsedOfIPduGroupInfo */
typedef boolean Com_PartitionsTxStructUsedOfIPduGroupInfoType;

/**   \brief  value based type definition for Com_RxPduInfoIndEndIdxOfIPduGroupInfo */
typedef uint8 Com_RxPduInfoIndEndIdxOfIPduGroupInfoType;

/**   \brief  value based type definition for Com_RxPduInfoIndStartIdxOfIPduGroupInfo */
typedef uint8 Com_RxPduInfoIndStartIdxOfIPduGroupInfoType;

/**   \brief  value based type definition for Com_RxPduInfoIndUsedOfIPduGroupInfo */
typedef boolean Com_RxPduInfoIndUsedOfIPduGroupInfoType;

/**   \brief  value based type definition for Com_TxPduInfoIndEndIdxOfIPduGroupInfo */
typedef uint8 Com_TxPduInfoIndEndIdxOfIPduGroupInfoType;

/**   \brief  value based type definition for Com_TxPduInfoIndStartIdxOfIPduGroupInfo */
typedef uint8 Com_TxPduInfoIndStartIdxOfIPduGroupInfoType;

/**   \brief  value based type definition for Com_TxPduInfoIndUsedOfIPduGroupInfo */
typedef boolean Com_TxPduInfoIndUsedOfIPduGroupInfoType;

/**   \brief  value based type definition for Com_IPduGroupInfoOfRxPduInfoInd */
typedef uint8 Com_IPduGroupInfoOfRxPduInfoIndType;

/**   \brief  value based type definition for Com_IPduGroupInfoOfTxPduInfoInd */
typedef uint8 Com_IPduGroupInfoOfTxPduInfoIndType;

/**   \brief  value based type definition for Com_IPduGroupInfoToSubIPduGroupsInd */
typedef uint8 Com_IPduGroupInfoToSubIPduGroupsIndType;

/**   \brief  value based type definition for Com_IPduGroupState */
typedef uint8 Com_IPduGroupStateType;

/**   \brief  value based type definition for Com_Initialized */
typedef boolean Com_InitializedType;

/**   \brief  value based type definition for Com_RxMainFunctionProcessingISRLockCounterIdxOfMainFunctionRxStruct */
typedef uint8 Com_RxMainFunctionProcessingISRLockCounterIdxOfMainFunctionRxStructType;

/**   \brief  value based type definition for Com_RxPduInfoOfMainFunctionRxIndEndIdxOfMainFunctionRxStruct */
typedef uint8 Com_RxPduInfoOfMainFunctionRxIndEndIdxOfMainFunctionRxStructType;

/**   \brief  value based type definition for Com_RxPduInfoOfMainFunctionRxIndStartIdxOfMainFunctionRxStruct */
typedef uint8 Com_RxPduInfoOfMainFunctionRxIndStartIdxOfMainFunctionRxStructType;

/**   \brief  value based type definition for Com_RxPduInfoOfMainFunctionRxIndUsedOfMainFunctionRxStruct */
typedef boolean Com_RxPduInfoOfMainFunctionRxIndUsedOfMainFunctionRxStructType;

/**   \brief  value based type definition for Com_TxCyclicPduOfMainFunctionTxIndEndIdxOfMainFunctionTxStruct */
typedef uint8 Com_TxCyclicPduOfMainFunctionTxIndEndIdxOfMainFunctionTxStructType;

/**   \brief  value based type definition for Com_TxCyclicPduOfMainFunctionTxIndStartIdxOfMainFunctionTxStruct */
typedef uint8 Com_TxCyclicPduOfMainFunctionTxIndStartIdxOfMainFunctionTxStructType;

/**   \brief  value based type definition for Com_TxCyclicPduOfMainFunctionTxIndUsedOfMainFunctionTxStruct */
typedef boolean Com_TxCyclicPduOfMainFunctionTxIndUsedOfMainFunctionTxStructType;

/**   \brief  value based type definition for Com_TxPduInfoOfMainFunctionTxIndEndIdxOfMainFunctionTxStruct */
typedef uint8 Com_TxPduInfoOfMainFunctionTxIndEndIdxOfMainFunctionTxStructType;

/**   \brief  value based type definition for Com_TxPduInfoOfMainFunctionTxIndStartIdxOfMainFunctionTxStruct */
typedef uint8 Com_TxPduInfoOfMainFunctionTxIndStartIdxOfMainFunctionTxStructType;

/**   \brief  value based type definition for Com_TxPduInfoOfMainFunctionTxIndUsedOfMainFunctionTxStruct */
typedef boolean Com_TxPduInfoOfMainFunctionTxIndUsedOfMainFunctionTxStructType;

/**   \brief  value based type definition for Com_TxProcessingISRLockCounterIdxOfMainFunctionTxStruct */
typedef uint8 Com_TxProcessingISRLockCounterIdxOfMainFunctionTxStructType;

/**   \brief  value based type definition for Com_TxIPduGroupISRLockCounterIdxOfPartitionsAlwaysActiveTxComIPdusStruct */
typedef uint8 Com_TxIPduGroupISRLockCounterIdxOfPartitionsAlwaysActiveTxComIPdusStructType;

/**   \brief  value based type definition for Com_RxIPduGroupISRLockCounterIdxOfPartitionsRxStruct */
typedef uint8 Com_RxIPduGroupISRLockCounterIdxOfPartitionsRxStructType;

/**   \brief  value based type definition for Com_TxIPduGroupISRLockCounterIdxOfPartitionsTxStruct */
typedef uint8 Com_TxIPduGroupISRLockCounterIdxOfPartitionsTxStructType;

/**   \brief  value based type definition for Com_PduGrpCnt */
typedef uint8 Com_PduGrpCntType;

/**   \brief  value based type definition for Com_ApplTypeOfRxAccessInfo */
typedef uint8 Com_ApplTypeOfRxAccessInfoType;

/**   \brief  value based type definition for Com_BitLengthOfRxAccessInfo */
typedef uint8 Com_BitLengthOfRxAccessInfoType;

/**   \brief  value based type definition for Com_BitPositionOfRxAccessInfo */
typedef uint8 Com_BitPositionOfRxAccessInfoType;

/**   \brief  value based type definition for Com_BufferIdxOfRxAccessInfo */
typedef uint8 Com_BufferIdxOfRxAccessInfoType;

/**   \brief  value based type definition for Com_BufferOfRxAccessInfo */
typedef uint8 Com_BufferOfRxAccessInfoType;

/**   \brief  value based type definition for Com_BufferUsedOfRxAccessInfo */
typedef boolean Com_BufferUsedOfRxAccessInfoType;

/**   \brief  value based type definition for Com_BusAccOfRxAccessInfo */
typedef uint8 Com_BusAccOfRxAccessInfoType;

/**   \brief  value based type definition for Com_ByteLengthOfRxAccessInfo */
typedef uint8 Com_ByteLengthOfRxAccessInfoType;

/**   \brief  value based type definition for Com_BytePositionOfRxAccessInfo */
typedef uint8 Com_BytePositionOfRxAccessInfoType;

/**   \brief  value based type definition for Com_DynSignalOfRxAccessInfo */
typedef boolean Com_DynSignalOfRxAccessInfoType;

/**   \brief  value based type definition for Com_InitValueIdxOfRxAccessInfo */
typedef uint8 Com_InitValueIdxOfRxAccessInfoType;

/**   \brief  value based type definition for Com_InitValueOfRxAccessInfo */
typedef uint8 Com_InitValueOfRxAccessInfoType;

/**   \brief  value based type definition for Com_InitValueUsedOfRxAccessInfo */
typedef boolean Com_InitValueUsedOfRxAccessInfoType;

/**   \brief  value based type definition for Com_RxPduInfoIdxOfRxAccessInfo */
typedef uint8 Com_RxPduInfoIdxOfRxAccessInfoType;

/**   \brief  value based type definition for Com_SignalLengthInByteOfRxAccessInfo */
typedef uint8 Com_SignalLengthInByteOfRxAccessInfoType;

/**   \brief  value based type definition for Com_StartByteInPduPositionOfRxAccessInfo */
typedef uint8 Com_StartByteInPduPositionOfRxAccessInfoType;

/**   \brief  value based type definition for Com_RxAccessInfoInd */
typedef uint8 Com_RxAccessInfoIndType;

/**   \brief  value based type definition for Com_RxDefPduBuffer */
typedef uint8 Com_RxDefPduBufferType;

/**   \brief  value based type definition for Com_RxIPduGroupISRLockCounter */
typedef uint16 Com_RxIPduGroupISRLockCounterType;

/**   \brief  value based type definition for Com_RxIPduGroupISRLockThreshold */
typedef uint8 Com_RxIPduGroupISRLockThresholdType;

/**   \brief  value based type definition for Com_RxMainFunctionProcessingISRLockCounter */
typedef uint16 Com_RxMainFunctionProcessingISRLockCounterType;

/**   \brief  value based type definition for Com_RxMainFunctionProcessingISRLockThreshold */
typedef uint8 Com_RxMainFunctionProcessingISRLockThresholdType;

/**   \brief  value based type definition for Com_RxPduGrpActive */
typedef boolean Com_RxPduGrpActiveType;

/**   \brief  value based type definition for Com_HandleRxPduDeferredIdxOfRxPduInfo */
typedef uint8 Com_HandleRxPduDeferredIdxOfRxPduInfoType;

/**   \brief  value based type definition for Com_HandleRxPduDeferredUsedOfRxPduInfo */
typedef boolean Com_HandleRxPduDeferredUsedOfRxPduInfoType;

/**   \brief  value based type definition for Com_IPduGroupInfoOfRxPduInfoIndEndIdxOfRxPduInfo */
typedef uint8 Com_IPduGroupInfoOfRxPduInfoIndEndIdxOfRxPduInfoType;

/**   \brief  value based type definition for Com_IPduGroupInfoOfRxPduInfoIndStartIdxOfRxPduInfo */
typedef uint8 Com_IPduGroupInfoOfRxPduInfoIndStartIdxOfRxPduInfoType;

/**   \brief  value based type definition for Com_IPduGroupInfoOfRxPduInfoIndUsedOfRxPduInfo */
typedef boolean Com_IPduGroupInfoOfRxPduInfoIndUsedOfRxPduInfoType;

/**   \brief  value based type definition for Com_MainFunctionRxStructIdxOfRxPduInfo */
typedef uint8 Com_MainFunctionRxStructIdxOfRxPduInfoType;

/**   \brief  value based type definition for Com_MainFunctionRxStructUsedOfRxPduInfo */
typedef boolean Com_MainFunctionRxStructUsedOfRxPduInfoType;

/**   \brief  value based type definition for Com_PartitionsRxStructIdxOfRxPduInfo */
typedef uint8 Com_PartitionsRxStructIdxOfRxPduInfoType;

/**   \brief  value based type definition for Com_RxAccessInfoIndEndIdxOfRxPduInfo */
typedef uint8 Com_RxAccessInfoIndEndIdxOfRxPduInfoType;

/**   \brief  value based type definition for Com_RxAccessInfoIndStartIdxOfRxPduInfo */
typedef uint8 Com_RxAccessInfoIndStartIdxOfRxPduInfoType;

/**   \brief  value based type definition for Com_RxAccessInfoIndUsedOfRxPduInfo */
typedef boolean Com_RxAccessInfoIndUsedOfRxPduInfoType;

/**   \brief  value based type definition for Com_RxDefPduBufferEndIdxOfRxPduInfo */
typedef uint8 Com_RxDefPduBufferEndIdxOfRxPduInfoType;

/**   \brief  value based type definition for Com_RxDefPduBufferLengthOfRxPduInfo */
typedef uint8 Com_RxDefPduBufferLengthOfRxPduInfoType;

/**   \brief  value based type definition for Com_RxDefPduBufferStartIdxOfRxPduInfo */
typedef uint8 Com_RxDefPduBufferStartIdxOfRxPduInfoType;

/**   \brief  value based type definition for Com_RxDefPduBufferUsedOfRxPduInfo */
typedef boolean Com_RxDefPduBufferUsedOfRxPduInfoType;

/**   \brief  value based type definition for Com_RxSigInfoEndIdxOfRxPduInfo */
typedef uint8 Com_RxSigInfoEndIdxOfRxPduInfoType;

/**   \brief  value based type definition for Com_RxSigInfoStartIdxOfRxPduInfo */
typedef uint8 Com_RxSigInfoStartIdxOfRxPduInfoType;

/**   \brief  value based type definition for Com_RxSigInfoUsedOfRxPduInfo */
typedef boolean Com_RxSigInfoUsedOfRxPduInfoType;

/**   \brief  value based type definition for Com_SignalProcessingOfRxPduInfo */
typedef uint8 Com_SignalProcessingOfRxPduInfoType;

/**   \brief  value based type definition for Com_TypeOfRxPduInfo */
typedef uint8 Com_TypeOfRxPduInfoType;

/**   \brief  value based type definition for Com_RxPduInfoInd */
typedef uint8 Com_RxPduInfoIndType;

/**   \brief  value based type definition for Com_RxPduInfoOfMainFunctionRxInd */
typedef uint8 Com_RxPduInfoOfMainFunctionRxIndType;

/**   \brief  value based type definition for Com_RxSigBufferUInt8 */
typedef uint8 Com_RxSigBufferUInt8Type;

/**   \brief  value based type definition for Com_RxAccessInfoIdxOfRxSigInfo */
typedef uint8 Com_RxAccessInfoIdxOfRxSigInfoType;

/**   \brief  value based type definition for Com_SignalProcessingOfRxSigInfo */
typedef uint8 Com_SignalProcessingOfRxSigInfoType;

/**   \brief  value based type definition for Com_ValidDlcOfRxSigInfo */
typedef uint8 Com_ValidDlcOfRxSigInfoType;

/**   \brief  value based type definition for Com_TransmitRequest */
typedef boolean Com_TransmitRequestType;

/**   \brief  value based type definition for Com_TxSigInfoIdxOfTxAccessInfo */
typedef uint8 Com_TxSigInfoIdxOfTxAccessInfoType;

/**   \brief  value based type definition for Com_TxSigInfoUsedOfTxAccessInfo */
typedef boolean Com_TxSigInfoUsedOfTxAccessInfoType;

/**   \brief  value based type definition for Com_TxBuffer */
typedef uint8 Com_TxBufferType;

/**   \brief  value based type definition for Com_TxPduInfoIdxOfTxCyclicPdu */
typedef uint8 Com_TxPduInfoIdxOfTxCyclicPduType;

/**   \brief  value based type definition for Com_TxCyclicPduOfMainFunctionTxInd */
typedef uint8 Com_TxCyclicPduOfMainFunctionTxIndType;

/**   \brief  value based type definition for Com_TxIPduGroupISRLockCounter */
typedef uint16 Com_TxIPduGroupISRLockCounterType;

/**   \brief  value based type definition for Com_TxIPduGroupISRLockThreshold */
typedef uint8 Com_TxIPduGroupISRLockThresholdType;

/**   \brief  value based type definition for Com_PeriodicOfTxModeFalse */
typedef boolean Com_PeriodicOfTxModeFalseType;

/**   \brief  value based type definition for Com_TimePeriodOfTxModeFalse */
typedef uint8 Com_TimePeriodOfTxModeFalseType;

/**   \brief  value based type definition for Com_InitModeOfTxModeInfo */
typedef boolean Com_InitModeOfTxModeInfoType;

/**   \brief  value based type definition for Com_TxModeFalseIdxOfTxModeInfo */
typedef uint8 Com_TxModeFalseIdxOfTxModeInfoType;

/**   \brief  value based type definition for Com_TxModeTrueIdxOfTxModeInfo */
typedef uint8 Com_TxModeTrueIdxOfTxModeInfoType;

/**   \brief  value based type definition for Com_PeriodicOfTxModeTrue */
typedef boolean Com_PeriodicOfTxModeTrueType;

/**   \brief  value based type definition for Com_TimePeriodOfTxModeTrue */
typedef uint8 Com_TimePeriodOfTxModeTrueType;

/**   \brief  value based type definition for Com_TxPduGrpActive */
typedef boolean Com_TxPduGrpActiveType;

/**   \brief  value based type definition for Com_ExternalIdOfTxPduInfo */
typedef uint8 Com_ExternalIdOfTxPduInfoType;

/**   \brief  value based type definition for Com_IPduGroupInfoOfTxPduInfoIndEndIdxOfTxPduInfo */
typedef uint8 Com_IPduGroupInfoOfTxPduInfoIndEndIdxOfTxPduInfoType;

/**   \brief  value based type definition for Com_IPduGroupInfoOfTxPduInfoIndStartIdxOfTxPduInfo */
typedef uint8 Com_IPduGroupInfoOfTxPduInfoIndStartIdxOfTxPduInfoType;

/**   \brief  value based type definition for Com_IPduGroupInfoOfTxPduInfoIndUsedOfTxPduInfo */
typedef boolean Com_IPduGroupInfoOfTxPduInfoIndUsedOfTxPduInfoType;

/**   \brief  value based type definition for Com_MetaDataLengthOfTxPduInfo */
typedef uint8 Com_MetaDataLengthOfTxPduInfoType;

/**   \brief  value based type definition for Com_PartitionsTxStructIdxOfTxPduInfo */
typedef uint8 Com_PartitionsTxStructIdxOfTxPduInfoType;

/**   \brief  value based type definition for Com_PduWithMetaDataLengthOfTxPduInfo */
typedef uint8 Com_PduWithMetaDataLengthOfTxPduInfoType;

/**   \brief  value based type definition for Com_TxBufferEndIdxOfTxPduInfo */
typedef uint8 Com_TxBufferEndIdxOfTxPduInfoType;

/**   \brief  value based type definition for Com_TxBufferLengthOfTxPduInfo */
typedef uint8 Com_TxBufferLengthOfTxPduInfoType;

/**   \brief  value based type definition for Com_TxBufferStartIdxOfTxPduInfo */
typedef uint8 Com_TxBufferStartIdxOfTxPduInfoType;

/**   \brief  value based type definition for Com_TxBufferUsedOfTxPduInfo */
typedef boolean Com_TxBufferUsedOfTxPduInfoType;

/**   \brief  value based type definition for Com_TxModeInfoIdxOfTxPduInfo */
typedef uint8 Com_TxModeInfoIdxOfTxPduInfoType;

/**   \brief  value based type definition for Com_TxPduInitValueEndIdxOfTxPduInfo */
typedef uint8 Com_TxPduInitValueEndIdxOfTxPduInfoType;

/**   \brief  value based type definition for Com_TxPduInitValueStartIdxOfTxPduInfo */
typedef uint8 Com_TxPduInitValueStartIdxOfTxPduInfoType;

/**   \brief  value based type definition for Com_TxPduInitValueUsedOfTxPduInfo */
typedef boolean Com_TxPduInitValueUsedOfTxPduInfoType;

/**   \brief  value based type definition for Com_TypeOfTxPduInfo */
typedef uint8 Com_TypeOfTxPduInfoType;

/**   \brief  value based type definition for Com_TxPduInfoInd */
typedef uint8 Com_TxPduInfoIndType;

/**   \brief  value based type definition for Com_TxPduInfoOfMainFunctionTxInd */
typedef uint8 Com_TxPduInfoOfMainFunctionTxIndType;

/**   \brief  value based type definition for Com_TxPduInitValue */
typedef uint8 Com_TxPduInitValueType;

/**   \brief  value based type definition for Com_TxProcessingISRLockCounter */
typedef uint16 Com_TxProcessingISRLockCounterType;

/**   \brief  value based type definition for Com_TxProcessingISRLockThreshold */
typedef uint8 Com_TxProcessingISRLockThresholdType;

/**   \brief  value based type definition for Com_TxSduLength */
typedef PduLengthType Com_TxSduLengthType;

/**   \brief  value based type definition for Com_ApplTypeOfTxSigInfo */
typedef uint8 Com_ApplTypeOfTxSigInfoType;

/**   \brief  value based type definition for Com_BitLengthOfTxSigInfo */
typedef uint8 Com_BitLengthOfTxSigInfoType;

/**   \brief  value based type definition for Com_BitPositionOfTxSigInfo */
typedef uint8 Com_BitPositionOfTxSigInfoType;

/**   \brief  value based type definition for Com_BusAccOfTxSigInfo */
typedef uint8 Com_BusAccOfTxSigInfoType;

/**   \brief  value based type definition for Com_ByteLengthOfTxSigInfo */
typedef uint8 Com_ByteLengthOfTxSigInfoType;

/**   \brief  value based type definition for Com_BytePositionOfTxSigInfo */
typedef uint8 Com_BytePositionOfTxSigInfoType;

/**   \brief  value based type definition for Com_DynSignalOfTxSigInfo */
typedef boolean Com_DynSignalOfTxSigInfoType;

/**   \brief  value based type definition for Com_StartByteInPduPositionOfTxSigInfo */
typedef uint8 Com_StartByteInPduPositionOfTxSigInfoType;

/**   \brief  value based type definition for Com_TxAccessInfoIdxOfTxSigInfo */
typedef uint8 Com_TxAccessInfoIdxOfTxSigInfoType;

/**   \brief  value based type definition for Com_TxBufferEndIdxOfTxSigInfo */
typedef uint8 Com_TxBufferEndIdxOfTxSigInfoType;

/**   \brief  value based type definition for Com_TxBufferLengthOfTxSigInfo */
typedef uint8 Com_TxBufferLengthOfTxSigInfoType;

/**   \brief  value based type definition for Com_TxBufferStartIdxOfTxSigInfo */
typedef uint8 Com_TxBufferStartIdxOfTxSigInfoType;

/**   \brief  value based type definition for Com_TxBufferUsedOfTxSigInfo */
typedef boolean Com_TxBufferUsedOfTxSigInfoType;

/**   \brief  value based type definition for Com_TxPduInfoIdxOfTxSigInfo */
typedef uint8 Com_TxPduInfoIdxOfTxSigInfoType;

/** 
  \}
*/ 

/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL COMPLEX DATA TYPES AND STRUCTURES
**********************************************************************************************************************/
/** 
  \defgroup  ComPCStructTypes  Com Struct Types (PRE_COMPILE)
  \brief  These type definitions are used for structured data representations.
  \{
*/ 
/**   \brief  type used in Com_AlwaysActiveTxComIPdus */
typedef struct sCom_AlwaysActiveTxComIPdusType
{
  uint8 Com_AlwaysActiveTxComIPdusNeverUsed;  /**< dummy entry for the structure in the configuration variant precompile which is not used by the code. */
} Com_AlwaysActiveTxComIPdusType;

/**   \brief  type used in Com_IPduGroupInfo */
typedef struct sCom_IPduGroupInfoType
{
  Com_IPduGroupInfoToSubIPduGroupsIndStartIdxOfIPduGroupInfoType IPduGroupInfoToSubIPduGroupsIndStartIdxOfIPduGroupInfo;  /**< the start index of the 0:n relation pointing to Com_IPduGroupInfoToSubIPduGroupsInd */
  Com_PartitionsRxStructIdxOfIPduGroupInfoType PartitionsRxStructIdxOfIPduGroupInfo;  /**< the index of the 0:1 relation pointing to Com_PartitionsRxStruct */
  Com_PartitionsTxStructIdxOfIPduGroupInfoType PartitionsTxStructIdxOfIPduGroupInfo;  /**< the index of the 0:1 relation pointing to Com_PartitionsTxStruct */
  Com_RxPduInfoIndEndIdxOfIPduGroupInfoType RxPduInfoIndEndIdxOfIPduGroupInfo;  /**< the end index of the 0:n relation pointing to Com_RxPduInfoInd */
  Com_RxPduInfoIndStartIdxOfIPduGroupInfoType RxPduInfoIndStartIdxOfIPduGroupInfo;  /**< the start index of the 0:n relation pointing to Com_RxPduInfoInd */
  Com_TxPduInfoIndEndIdxOfIPduGroupInfoType TxPduInfoIndEndIdxOfIPduGroupInfo;  /**< the end index of the 0:n relation pointing to Com_TxPduInfoInd */
  Com_TxPduInfoIndStartIdxOfIPduGroupInfoType TxPduInfoIndStartIdxOfIPduGroupInfo;  /**< the start index of the 0:n relation pointing to Com_TxPduInfoInd */
} Com_IPduGroupInfoType;

/**   \brief  type used in Com_MainFunctionRxStruct */
typedef struct sCom_MainFunctionRxStructType
{
  Com_RxPduInfoOfMainFunctionRxIndStartIdxOfMainFunctionRxStructType RxPduInfoOfMainFunctionRxIndStartIdxOfMainFunctionRxStruct;  /**< the start index of the 0:n relation pointing to Com_RxPduInfoOfMainFunctionRxInd */
} Com_MainFunctionRxStructType;

/**   \brief  type used in Com_MainFunctionTxStruct */
typedef struct sCom_MainFunctionTxStructType
{
  Com_TxCyclicPduOfMainFunctionTxIndStartIdxOfMainFunctionTxStructType TxCyclicPduOfMainFunctionTxIndStartIdxOfMainFunctionTxStruct;  /**< the start index of the 0:n relation pointing to Com_TxCyclicPduOfMainFunctionTxInd */
  Com_TxPduInfoOfMainFunctionTxIndStartIdxOfMainFunctionTxStructType TxPduInfoOfMainFunctionTxIndStartIdxOfMainFunctionTxStruct;  /**< the start index of the 0:n relation pointing to Com_TxPduInfoOfMainFunctionTxInd */
} Com_MainFunctionTxStructType;

/**   \brief  type used in Com_PartitionsAlwaysActiveTxComIPdusStruct */
typedef struct sCom_PartitionsAlwaysActiveTxComIPdusStructType
{
  uint8 Com_PartitionsAlwaysActiveTxComIPdusStructNeverUsed;  /**< dummy entry for the structure in the configuration variant precompile which is not used by the code. */
} Com_PartitionsAlwaysActiveTxComIPdusStructType;

/**   \brief  type used in Com_PartitionsRxStruct */
typedef struct sCom_PartitionsRxStructType
{
  uint8 Com_PartitionsRxStructNeverUsed;  /**< dummy entry for the structure in the configuration variant precompile which is not used by the code. */
} Com_PartitionsRxStructType;

/**   \brief  type used in Com_PartitionsTxStruct */
typedef struct sCom_PartitionsTxStructType
{
  uint8 Com_PartitionsTxStructNeverUsed;  /**< dummy entry for the structure in the configuration variant precompile which is not used by the code. */
} Com_PartitionsTxStructType;

/**   \brief  type used in Com_RxAccessInfo */
typedef struct sCom_RxAccessInfoType
{
  Com_DynSignalOfRxAccessInfoType DynSignalOfRxAccessInfo;  /**< TRUE if the Signal is a dynamic length signal (UINT8_DYN), FALSE otherwise. */
  Com_BufferOfRxAccessInfoType BufferOfRxAccessInfo;  /**< the enum value of the according target of the 0:1 relation pointing to Com_RxSigBufferUInt8,Com_RxSigBufferUInt16,Com_RxSigBufferUInt32,Com_RxSigBufferUInt64,Com_RxSigBufferZeroBit,Com_RxSigBufferSInt8,Com_RxSigBufferSInt16,Com_RxSigBufferSInt32,Com_RxSigBufferSInt64,Com_RxSigBufferFloat32,Com_RxSigBufferFloat64 */
  Com_BufferIdxOfRxAccessInfoType BufferIdxOfRxAccessInfo;  /**< the index of the 0:1 relation pointing to Com_RxSigBufferUInt8,Com_RxSigBufferUInt16,Com_RxSigBufferUInt32,Com_RxSigBufferUInt64,Com_RxSigBufferZeroBit,Com_RxSigBufferSInt8,Com_RxSigBufferSInt16,Com_RxSigBufferSInt32,Com_RxSigBufferSInt64,Com_RxSigBufferFloat32,Com_RxSigBufferFloat64 */
  Com_InitValueIdxOfRxAccessInfoType InitValueIdxOfRxAccessInfo;  /**< the index of the 0:1 relation pointing to Com_ConstValueUInt8,Com_ConstValueUInt16,Com_ConstValueUInt32,Com_ConstValueUInt64,Com_ConstValueSInt8,Com_ConstValueSInt16,Com_ConstValueSInt32,Com_ConstValueSInt64,Com_ConstValueFloat32,Com_ConstValueFloat64 */
  Com_SignalLengthInByteOfRxAccessInfoType SignalLengthInByteOfRxAccessInfo;  /**< The length of the Signal/GroupSignal in Byte */
} Com_RxAccessInfoType;

/**   \brief  type used in Com_RxPduInfo */
typedef struct sCom_RxPduInfoType
{
  Com_HandleRxPduDeferredIdxOfRxPduInfoType HandleRxPduDeferredIdxOfRxPduInfo;  /**< the index of the 0:1 relation pointing to Com_HandleRxPduDeferred */
  Com_IPduGroupInfoOfRxPduInfoIndStartIdxOfRxPduInfoType IPduGroupInfoOfRxPduInfoIndStartIdxOfRxPduInfo;  /**< the start index of the 0:n relation pointing to Com_IPduGroupInfoOfRxPduInfoInd */
  Com_MainFunctionRxStructIdxOfRxPduInfoType MainFunctionRxStructIdxOfRxPduInfo;  /**< the index of the 0:1 relation pointing to Com_MainFunctionRxStruct */
  Com_RxAccessInfoIndStartIdxOfRxPduInfoType RxAccessInfoIndStartIdxOfRxPduInfo;  /**< the start index of the 0:n relation pointing to Com_RxAccessInfoInd */
  Com_RxDefPduBufferLengthOfRxPduInfoType RxDefPduBufferLengthOfRxPduInfo;  /**< the number of relations pointing to Com_RxDefPduBuffer */
  Com_RxSigInfoStartIdxOfRxPduInfoType RxSigInfoStartIdxOfRxPduInfo;  /**< the start index of the 0:n relation pointing to Com_RxSigInfo */
} Com_RxPduInfoType;

/**   \brief  type used in Com_RxSigInfo */
typedef struct sCom_RxSigInfoType
{
  Com_ValidDlcOfRxSigInfoType ValidDlcOfRxSigInfo;  /**< Minimum length of PDU required to completely receive the signal or signal group. */
} Com_RxSigInfoType;

/**   \brief  type used in Com_TxAccessInfo */
typedef struct sCom_TxAccessInfoType
{
  Com_TxSigInfoIdxOfTxAccessInfoType TxSigInfoIdxOfTxAccessInfo;  /**< the index of the 0:1 relation pointing to Com_TxSigInfo */
} Com_TxAccessInfoType;

/**   \brief  type used in Com_TxCyclicPdu */
typedef struct sCom_TxCyclicPduType
{
  uint8 Com_TxCyclicPduNeverUsed;  /**< dummy entry for the structure in the configuration variant precompile which is not used by the code. */
} Com_TxCyclicPduType;

/**   \brief  type used in Com_TxModeFalse */
typedef struct sCom_TxModeFalseType
{
  Com_TimePeriodOfTxModeFalseType TimePeriodOfTxModeFalse;  /**< Cycle time factor. */
} Com_TxModeFalseType;

/**   \brief  type used in Com_TxModeInfo */
typedef struct sCom_TxModeInfoType
{
  Com_InitModeOfTxModeInfoType InitModeOfTxModeInfo;  /**< Initial transmission mode selector of the Tx I-PDU. */
} Com_TxModeInfoType;

/**   \brief  type used in Com_TxModeTrue */
typedef struct sCom_TxModeTrueType
{
  Com_TimePeriodOfTxModeTrueType TimePeriodOfTxModeTrue;  /**< Cycle time factor. */
} Com_TxModeTrueType;

/**   \brief  type used in Com_TxPduInfo */
typedef struct sCom_TxPduInfoType
{
  Com_ExternalIdOfTxPduInfoType ExternalIdOfTxPduInfo;  /**< External ID used to call PduR_ComTransmit(). */
  Com_IPduGroupInfoOfTxPduInfoIndEndIdxOfTxPduInfoType IPduGroupInfoOfTxPduInfoIndEndIdxOfTxPduInfo;  /**< the end index of the 0:n relation pointing to Com_IPduGroupInfoOfTxPduInfoInd */
  Com_IPduGroupInfoOfTxPduInfoIndStartIdxOfTxPduInfoType IPduGroupInfoOfTxPduInfoIndStartIdxOfTxPduInfo;  /**< the start index of the 0:n relation pointing to Com_IPduGroupInfoOfTxPduInfoInd */
  Com_PartitionsTxStructIdxOfTxPduInfoType PartitionsTxStructIdxOfTxPduInfo;  /**< the index of the 1:1 relation pointing to Com_PartitionsTxStruct */
  Com_TxBufferLengthOfTxPduInfoType TxBufferLengthOfTxPduInfo;  /**< the number of relations pointing to Com_TxBuffer */
  Com_TxPduInitValueEndIdxOfTxPduInfoType TxPduInitValueEndIdxOfTxPduInfo;  /**< the end index of the 0:n relation pointing to Com_TxPduInitValue */
  Com_TxPduInitValueStartIdxOfTxPduInfoType TxPduInitValueStartIdxOfTxPduInfo;  /**< the start index of the 0:n relation pointing to Com_TxPduInitValue */
} Com_TxPduInfoType;

/**   \brief  type used in Com_TxSigInfo */
typedef struct sCom_TxSigInfoType
{
  Com_DynSignalOfTxSigInfoType DynSignalOfTxSigInfo;  /**< TRUE if the Signal is a dynamic length signal (UINT8_DYN), FALSE otherwise. */
  Com_ApplTypeOfTxSigInfoType ApplTypeOfTxSigInfo;  /**< Application data type. */
  Com_BitLengthOfTxSigInfoType BitLengthOfTxSigInfo;  /**< Bit length of the signal or group signal. */
  Com_BitPositionOfTxSigInfoType BitPositionOfTxSigInfo;  /**< Little endian bit position of the signal or group signal within the I-PDU. */
  Com_ByteLengthOfTxSigInfoType ByteLengthOfTxSigInfo;  /**< Byte length of the signal or group signal. */
  Com_StartByteInPduPositionOfTxSigInfoType StartByteInPduPositionOfTxSigInfo;  /**< Start Byte position of the signal or group signal within the I-PDU. */
  Com_TxBufferEndIdxOfTxSigInfoType TxBufferEndIdxOfTxSigInfo;  /**< the end index of the 0:n relation pointing to Com_TxBuffer */
  Com_TxBufferStartIdxOfTxSigInfoType TxBufferStartIdxOfTxSigInfo;  /**< the start index of the 0:n relation pointing to Com_TxBuffer */
  Com_TxPduInfoIdxOfTxSigInfoType TxPduInfoIdxOfTxSigInfo;  /**< the index of the 1:1 relation pointing to Com_TxPduInfo */
} Com_TxSigInfoType;

/** 
  \}
*/ 

/** 
  \defgroup  ComPCSymbolicStructTypes  Com Symbolic Struct Types (PRE_COMPILE)
  \brief  These structs are used in unions to have a symbol based data representation style.
  \{
*/ 
/**   \brief  type to be used as symbolic data element access to Com_CurrentTxMode */
typedef struct Com_CurrentTxModeStructSTag
{
  Com_CurrentTxModeType msg_MotorStatus_oCAN00_71118836_Tx;
  Com_CurrentTxModeType msg_Transmit_oCAN00_0723e95e_Tx;
  Com_CurrentTxModeType msg_nm_MyECU_oCAN00_92bb24c1_Tx;
} Com_CurrentTxModeStructSType;

/**   \brief  type to be used as symbolic data element access to Com_CycleTimeCnt */
typedef struct Com_CycleTimeCntStructSTag
{
  Com_CycleTimeCntType msg_MotorStatus_oCAN00_71118836_Tx;
  Com_CycleTimeCntType msg_Transmit_oCAN00_0723e95e_Tx;
  Com_CycleTimeCntType msg_nm_MyECU_oCAN00_92bb24c1_Tx;
} Com_CycleTimeCntStructSType;

/**   \brief  type to be used as symbolic data element access to Com_CyclicSendRequest */
typedef struct Com_CyclicSendRequestStructSTag
{
  Com_CyclicSendRequestType msg_MotorStatus_oCAN00_71118836_Tx;
  Com_CyclicSendRequestType msg_Transmit_oCAN00_0723e95e_Tx;
  Com_CyclicSendRequestType msg_nm_MyECU_oCAN00_92bb24c1_Tx;
} Com_CyclicSendRequestStructSType;

/**   \brief  type to be used as symbolic data element access to Com_HandleRxPduDeferred */
typedef struct Com_HandleRxPduDeferredStructSTag
{
  Com_HandleRxPduDeferredType msg_Receive_oCAN00_2b456e3f_Rx;
} Com_HandleRxPduDeferredStructSType;

/**   \brief  type to be used as symbolic data element access to Com_RxDefPduBuffer */
typedef struct Com_RxDefPduBufferStructSTag
{
  Com_RxDefPduBufferType msg_Receive_oCAN00_2b456e3f_Rx;
} Com_RxDefPduBufferStructSType;

/**   \brief  type to be used as symbolic data element access to Com_RxIPduGroupISRLockCounter */
typedef struct Com_RxIPduGroupISRLockCounterStructSTag
{
  Com_RxIPduGroupISRLockCounterType noPartition;
} Com_RxIPduGroupISRLockCounterStructSType;

/**   \brief  type to be used as symbolic data element access to Com_RxMainFunctionProcessingISRLockCounter */
typedef struct Com_RxMainFunctionProcessingISRLockCounterStructSTag
{
  Com_RxMainFunctionProcessingISRLockCounterType ComMainFunctionRx;
} Com_RxMainFunctionProcessingISRLockCounterStructSType;

/**   \brief  type to be used as symbolic data element access to Com_TransmitRequest */
typedef struct Com_TransmitRequestStructSTag
{
  Com_TransmitRequestType msg_MotorStatus_oCAN00_71118836_Tx;
  Com_TransmitRequestType msg_Transmit_oCAN00_0723e95e_Tx;
  Com_TransmitRequestType msg_nm_MyECU_oCAN00_92bb24c1_Tx;
} Com_TransmitRequestStructSType;

/**   \brief  type to be used as symbolic data element access to Com_TxIPduGroupISRLockCounter */
typedef struct Com_TxIPduGroupISRLockCounterStructSTag
{
  Com_TxIPduGroupISRLockCounterType noPartition;
} Com_TxIPduGroupISRLockCounterStructSType;

/**   \brief  type to be used as symbolic data element access to Com_TxProcessingISRLockCounter */
typedef struct Com_TxProcessingISRLockCounterStructSTag
{
  Com_TxProcessingISRLockCounterType ComMainFunctionTx;
} Com_TxProcessingISRLockCounterStructSType;

/** 
  \}
*/ 

/** 
  \defgroup  ComPCUnionIndexAndSymbolTypes  Com Union Index And Symbol Types (PRE_COMPILE)
  \brief  These unions are used to access arrays in an index and symbol based style.
  \{
*/ 
/**   \brief  type to access Com_CurrentTxMode in an index and symbol based style. */
typedef union Com_CurrentTxModeUTag
{  /* PRQA S 0750 */  /* MD_CSL_Union */
  Com_CurrentTxModeType raw[3];
  Com_CurrentTxModeStructSType str;
} Com_CurrentTxModeUType;

/**   \brief  type to access Com_CycleTimeCnt in an index and symbol based style. */
typedef union Com_CycleTimeCntUTag
{  /* PRQA S 0750 */  /* MD_CSL_Union */
  Com_CycleTimeCntType raw[3];
  Com_CycleTimeCntStructSType str;
} Com_CycleTimeCntUType;

/**   \brief  type to access Com_CyclicSendRequest in an index and symbol based style. */
typedef union Com_CyclicSendRequestUTag
{  /* PRQA S 0750 */  /* MD_CSL_Union */
  Com_CyclicSendRequestType raw[3];
  Com_CyclicSendRequestStructSType str;
} Com_CyclicSendRequestUType;

/**   \brief  type to access Com_HandleRxPduDeferred in an index and symbol based style. */
typedef union Com_HandleRxPduDeferredUTag
{  /* PRQA S 0750 */  /* MD_CSL_Union */
  Com_HandleRxPduDeferredType raw[1];
  Com_HandleRxPduDeferredStructSType str;
} Com_HandleRxPduDeferredUType;

/**   \brief  type to access Com_RxDefPduBuffer in an index and symbol based style. */
typedef union Com_RxDefPduBufferUTag
{  /* PRQA S 0750 */  /* MD_CSL_Union */
  Com_RxDefPduBufferType raw[1];
  Com_RxDefPduBufferStructSType str;
} Com_RxDefPduBufferUType;

/**   \brief  type to access Com_RxIPduGroupISRLockCounter in an index and symbol based style. */
typedef union Com_RxIPduGroupISRLockCounterUTag
{  /* PRQA S 0750 */  /* MD_CSL_Union */
  Com_RxIPduGroupISRLockCounterType raw[1];
  Com_RxIPduGroupISRLockCounterStructSType str;
} Com_RxIPduGroupISRLockCounterUType;

/**   \brief  type to access Com_RxMainFunctionProcessingISRLockCounter in an index and symbol based style. */
typedef union Com_RxMainFunctionProcessingISRLockCounterUTag
{  /* PRQA S 0750 */  /* MD_CSL_Union */
  Com_RxMainFunctionProcessingISRLockCounterType raw[1];
  Com_RxMainFunctionProcessingISRLockCounterStructSType str;
} Com_RxMainFunctionProcessingISRLockCounterUType;

/**   \brief  type to access Com_TransmitRequest in an index and symbol based style. */
typedef union Com_TransmitRequestUTag
{  /* PRQA S 0750 */  /* MD_CSL_Union */
  Com_TransmitRequestType raw[3];
  Com_TransmitRequestStructSType str;
} Com_TransmitRequestUType;

/**   \brief  type to access Com_TxIPduGroupISRLockCounter in an index and symbol based style. */
typedef union Com_TxIPduGroupISRLockCounterUTag
{  /* PRQA S 0750 */  /* MD_CSL_Union */
  Com_TxIPduGroupISRLockCounterType raw[1];
  Com_TxIPduGroupISRLockCounterStructSType str;
} Com_TxIPduGroupISRLockCounterUType;

/**   \brief  type to access Com_TxProcessingISRLockCounter in an index and symbol based style. */
typedef union Com_TxProcessingISRLockCounterUTag
{  /* PRQA S 0750 */  /* MD_CSL_Union */
  Com_TxProcessingISRLockCounterType raw[1];
  Com_TxProcessingISRLockCounterStructSType str;
} Com_TxProcessingISRLockCounterUType;

/** 
  \}
*/ 

/** 
  \defgroup  ComPCRootPointerTypes  Com Root Pointer Types (PRE_COMPILE)
  \brief  These type definitions are used to point from the config root to symbol instances.
  \{
*/ 
/**   \brief  type used to point to Com_AlwaysActiveTxComIPdus */
typedef P2CONST(Com_AlwaysActiveTxComIPdusType, TYPEDEF, COM_CONST) Com_AlwaysActiveTxComIPdusPtrType;

/**   \brief  type used to point to Com_ConstValueUInt8 */
typedef P2CONST(Com_ConstValueUInt8Type, TYPEDEF, COM_CONST) Com_ConstValueUInt8PtrType;

/**   \brief  type used to point to Com_CurrentTxMode */
typedef P2VAR(Com_CurrentTxModeType, TYPEDEF, COM_VAR_NO_INIT) Com_CurrentTxModePtrType;

/**   \brief  type used to point to Com_CycleTimeCnt */
typedef P2VAR(Com_CycleTimeCntType, TYPEDEF, COM_VAR_NO_INIT) Com_CycleTimeCntPtrType;

/**   \brief  type used to point to Com_CyclicSendRequest */
typedef P2VAR(Com_CyclicSendRequestType, TYPEDEF, COM_VAR_NO_INIT) Com_CyclicSendRequestPtrType;

/**   \brief  type used to point to Com_HandleRxPduDeferred */
typedef P2VAR(Com_HandleRxPduDeferredType, TYPEDEF, COM_VAR_NO_INIT) Com_HandleRxPduDeferredPtrType;

/**   \brief  type used to point to Com_IPduGroupInfo */
typedef P2CONST(Com_IPduGroupInfoType, TYPEDEF, COM_CONST) Com_IPduGroupInfoPtrType;

/**   \brief  type used to point to Com_IPduGroupInfoOfRxPduInfoInd */
typedef P2CONST(Com_IPduGroupInfoOfRxPduInfoIndType, TYPEDEF, COM_CONST) Com_IPduGroupInfoOfRxPduInfoIndPtrType;

/**   \brief  type used to point to Com_IPduGroupInfoOfTxPduInfoInd */
typedef P2CONST(Com_IPduGroupInfoOfTxPduInfoIndType, TYPEDEF, COM_CONST) Com_IPduGroupInfoOfTxPduInfoIndPtrType;

/**   \brief  type used to point to Com_IPduGroupInfoToSubIPduGroupsInd */
typedef P2CONST(Com_IPduGroupInfoToSubIPduGroupsIndType, TYPEDEF, COM_CONST) Com_IPduGroupInfoToSubIPduGroupsIndPtrType;

/**   \brief  type used to point to Com_IPduGroupState */
typedef P2VAR(Com_IPduGroupStateType, TYPEDEF, COM_VAR_NO_INIT) Com_IPduGroupStatePtrType;

/**   \brief  type used to point to Com_Initialized */
typedef P2VAR(Com_InitializedType, TYPEDEF, COM_VAR_CLEARED) Com_InitializedPtrType;

/**   \brief  type used to point to Com_MainFunctionRxStruct */
typedef P2CONST(Com_MainFunctionRxStructType, TYPEDEF, COM_CONST) Com_MainFunctionRxStructPtrType;

/**   \brief  type used to point to Com_MainFunctionTxStruct */
typedef P2CONST(Com_MainFunctionTxStructType, TYPEDEF, COM_CONST) Com_MainFunctionTxStructPtrType;

/**   \brief  type used to point to Com_PartitionsAlwaysActiveTxComIPdusStruct */
typedef P2CONST(Com_PartitionsAlwaysActiveTxComIPdusStructType, TYPEDEF, COM_CONST) Com_PartitionsAlwaysActiveTxComIPdusStructPtrType;

/**   \brief  type used to point to Com_PartitionsRxStruct */
typedef P2CONST(Com_PartitionsRxStructType, TYPEDEF, COM_CONST) Com_PartitionsRxStructPtrType;

/**   \brief  type used to point to Com_PartitionsTxStruct */
typedef P2CONST(Com_PartitionsTxStructType, TYPEDEF, COM_CONST) Com_PartitionsTxStructPtrType;

/**   \brief  type used to point to Com_RxAccessInfo */
typedef P2CONST(Com_RxAccessInfoType, TYPEDEF, COM_CONST) Com_RxAccessInfoPtrType;

/**   \brief  type used to point to Com_RxAccessInfoInd */
typedef P2CONST(Com_RxAccessInfoIndType, TYPEDEF, COM_CONST) Com_RxAccessInfoIndPtrType;

/**   \brief  type used to point to Com_RxDefPduBuffer */
typedef P2VAR(Com_RxDefPduBufferType, TYPEDEF, COM_VAR_NO_INIT) Com_RxDefPduBufferPtrType;

/**   \brief  type used to point to Com_RxIPduGroupISRLockCounter */
typedef P2VAR(Com_RxIPduGroupISRLockCounterType, TYPEDEF, COM_VAR_NO_INIT) Com_RxIPduGroupISRLockCounterPtrType;

/**   \brief  type used to point to Com_RxMainFunctionProcessingISRLockCounter */
typedef P2VAR(Com_RxMainFunctionProcessingISRLockCounterType, TYPEDEF, COM_VAR_NO_INIT) Com_RxMainFunctionProcessingISRLockCounterPtrType;

/**   \brief  type used to point to Com_RxPduGrpActive */
typedef P2VAR(Com_RxPduGrpActiveType, TYPEDEF, COM_VAR_NO_INIT) Com_RxPduGrpActivePtrType;

/**   \brief  type used to point to Com_RxPduInfo */
typedef P2CONST(Com_RxPduInfoType, TYPEDEF, COM_CONST) Com_RxPduInfoPtrType;

/**   \brief  type used to point to Com_RxPduInfoInd */
typedef P2CONST(Com_RxPduInfoIndType, TYPEDEF, COM_CONST) Com_RxPduInfoIndPtrType;

/**   \brief  type used to point to Com_RxPduInfoOfMainFunctionRxInd */
typedef P2CONST(Com_RxPduInfoOfMainFunctionRxIndType, TYPEDEF, COM_CONST) Com_RxPduInfoOfMainFunctionRxIndPtrType;

/**   \brief  type used to point to Com_RxSigBufferUInt8 */
typedef P2VAR(Com_RxSigBufferUInt8Type, TYPEDEF, COM_VAR_NO_INIT) Com_RxSigBufferUInt8PtrType;

/**   \brief  type used to point to Com_RxSigInfo */
typedef P2CONST(Com_RxSigInfoType, TYPEDEF, COM_CONST) Com_RxSigInfoPtrType;

/**   \brief  type used to point to Com_TransmitRequest */
typedef P2VAR(Com_TransmitRequestType, TYPEDEF, COM_VAR_NO_INIT) Com_TransmitRequestPtrType;

/**   \brief  type used to point to Com_TxAccessInfo */
typedef P2CONST(Com_TxAccessInfoType, TYPEDEF, COM_CONST) Com_TxAccessInfoPtrType;

/**   \brief  type used to point to Com_TxBuffer */
typedef P2VAR(Com_TxBufferType, TYPEDEF, COM_VAR_NO_INIT) Com_TxBufferPtrType;

/**   \brief  type used to point to Com_TxCyclicPdu */
typedef P2CONST(Com_TxCyclicPduType, TYPEDEF, COM_CONST) Com_TxCyclicPduPtrType;

/**   \brief  type used to point to Com_TxCyclicPduOfMainFunctionTxInd */
typedef P2CONST(Com_TxCyclicPduOfMainFunctionTxIndType, TYPEDEF, COM_CONST) Com_TxCyclicPduOfMainFunctionTxIndPtrType;

/**   \brief  type used to point to Com_TxIPduGroupISRLockCounter */
typedef P2VAR(Com_TxIPduGroupISRLockCounterType, TYPEDEF, COM_VAR_NO_INIT) Com_TxIPduGroupISRLockCounterPtrType;

/**   \brief  type used to point to Com_TxModeFalse */
typedef P2CONST(Com_TxModeFalseType, TYPEDEF, COM_CONST) Com_TxModeFalsePtrType;

/**   \brief  type used to point to Com_TxModeInfo */
typedef P2CONST(Com_TxModeInfoType, TYPEDEF, COM_CONST) Com_TxModeInfoPtrType;

/**   \brief  type used to point to Com_TxModeTrue */
typedef P2CONST(Com_TxModeTrueType, TYPEDEF, COM_CONST) Com_TxModeTruePtrType;

/**   \brief  type used to point to Com_TxPduGrpActive */
typedef P2VAR(Com_TxPduGrpActiveType, TYPEDEF, COM_VAR_NO_INIT) Com_TxPduGrpActivePtrType;

/**   \brief  type used to point to Com_TxPduInfo */
typedef P2CONST(Com_TxPduInfoType, TYPEDEF, COM_CONST) Com_TxPduInfoPtrType;

/**   \brief  type used to point to Com_TxPduInfoInd */
typedef P2CONST(Com_TxPduInfoIndType, TYPEDEF, COM_CONST) Com_TxPduInfoIndPtrType;

/**   \brief  type used to point to Com_TxPduInfoOfMainFunctionTxInd */
typedef P2CONST(Com_TxPduInfoOfMainFunctionTxIndType, TYPEDEF, COM_CONST) Com_TxPduInfoOfMainFunctionTxIndPtrType;

/**   \brief  type used to point to Com_TxPduInitValue */
typedef P2CONST(Com_TxPduInitValueType, TYPEDEF, COM_CONST) Com_TxPduInitValuePtrType;

/**   \brief  type used to point to Com_TxProcessingISRLockCounter */
typedef P2VAR(Com_TxProcessingISRLockCounterType, TYPEDEF, COM_VAR_NO_INIT) Com_TxProcessingISRLockCounterPtrType;

/**   \brief  type used to point to Com_TxSduLength */
typedef P2VAR(Com_TxSduLengthType, TYPEDEF, COM_VAR_NO_INIT) Com_TxSduLengthPtrType;

/**   \brief  type used to point to Com_TxSigInfo */
typedef P2CONST(Com_TxSigInfoType, TYPEDEF, COM_CONST) Com_TxSigInfoPtrType;

/** 
  \}
*/ 

/** 
  \defgroup  ComPCRootValueTypes  Com Root Value Types (PRE_COMPILE)
  \brief  These type definitions are used for value representations in root arrays.
  \{
*/ 
/**   \brief  type used in Com_PCConfig */
typedef struct sCom_PCConfigType
{
  uint8 Com_PCConfigNeverUsed;  /**< dummy entry for the structure in the configuration variant precompile which is not used by the code. */
} Com_PCConfigType;

typedef Com_PCConfigType Com_ConfigType;  /**< A structure type is present for data in each configuration class. This typedef redefines the probably different name to the specified one. */

/** 
  \}
*/ 


/**********************************************************************************************************************
  CONFIGURATION CLASS: LINK
  SECTION: SIZEOF DATA TYPES
**********************************************************************************************************************/
/**********************************************************************************************************************
  CONFIGURATION CLASS: LINK
  SECTION: GLOBAL SIMPLE DATA TYPES AND STRUCTURES
**********************************************************************************************************************/
/**********************************************************************************************************************
  CONFIGURATION CLASS: LINK
  SECTION: GLOBAL COMPLEX DATA TYPES AND STRUCTURES
**********************************************************************************************************************/


/**********************************************************************************************************************
  GLOBAL DATA PROTOTYPES
**********************************************************************************************************************/
/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL DATA PROTOTYPES
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
extern CONST(Com_ConstValueUInt8Type, COM_CONST) Com_ConstValueUInt8[1];
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
extern CONST(Com_IPduGroupInfoType, COM_CONST) Com_IPduGroupInfo[2];
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
extern CONST(Com_IPduGroupInfoOfTxPduInfoIndType, COM_CONST) Com_IPduGroupInfoOfTxPduInfoInd[2];
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
extern CONST(Com_MainFunctionRxStructType, COM_CONST) Com_MainFunctionRxStruct[1];
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
extern CONST(Com_MainFunctionTxStructType, COM_CONST) Com_MainFunctionTxStruct[1];
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
extern CONST(Com_RxAccessInfoType, COM_CONST) Com_RxAccessInfo[2];
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
extern CONST(Com_RxPduInfoType, COM_CONST) Com_RxPduInfo[1];
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
extern CONST(Com_RxSigInfoType, COM_CONST) Com_RxSigInfo[2];
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
extern CONST(Com_TxAccessInfoType, COM_CONST) Com_TxAccessInfo[13];
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
extern CONST(Com_TxModeFalseType, COM_CONST) Com_TxModeFalse[3];
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
extern CONST(Com_TxModeInfoType, COM_CONST) Com_TxModeInfo[3];
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
extern CONST(Com_TxModeTrueType, COM_CONST) Com_TxModeTrue[3];
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
extern CONST(Com_TxPduInfoType, COM_CONST) Com_TxPduInfo[3];
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
extern CONST(Com_TxPduInitValueType, COM_CONST) Com_TxPduInitValue[19];
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
extern CONST(Com_TxSigInfoType, COM_CONST) Com_TxSigInfo[13];
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
extern VAR(Com_CurrentTxModeUType, COM_VAR_NO_INIT) Com_CurrentTxMode;  /* PRQA S 0759 */  /* MD_CSL_Union */
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
extern VAR(Com_CycleTimeCntUType, COM_VAR_NO_INIT) Com_CycleTimeCnt;  /* PRQA S 0759 */  /* MD_CSL_Union */
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
extern VAR(Com_CyclicSendRequestUType, COM_VAR_NO_INIT) Com_CyclicSendRequest;  /* PRQA S 0759 */  /* MD_CSL_Union */
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
extern VAR(Com_HandleRxPduDeferredUType, COM_VAR_NO_INIT) Com_HandleRxPduDeferred;  /* PRQA S 0759 */  /* MD_CSL_Union */
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
extern VAR(Com_IPduGroupStateType, COM_VAR_NO_INIT) Com_IPduGroupState[2];
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
extern VAR(Com_InitializedType, COM_VAR_CLEARED) Com_Initialized;
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
extern VAR(Com_RxDefPduBufferUType, COM_VAR_NO_INIT) Com_RxDefPduBuffer;  /* PRQA S 0759 */  /* MD_CSL_Union */
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
extern VAR(Com_RxIPduGroupISRLockCounterUType, COM_VAR_NO_INIT) Com_RxIPduGroupISRLockCounter;  /* PRQA S 0759 */  /* MD_CSL_Union */
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
extern VAR(Com_RxMainFunctionProcessingISRLockCounterUType, COM_VAR_NO_INIT) Com_RxMainFunctionProcessingISRLockCounter;  /* PRQA S 0777, 0759 */  /* MD_MSR_Rule5.1, MD_CSL_Union */
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
extern VAR(Com_RxPduGrpActiveType, COM_VAR_NO_INIT) Com_RxPduGrpActive[1];
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
extern VAR(Com_RxSigBufferUInt8Type, COM_VAR_NO_INIT) Com_RxSigBufferUInt8[2];
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
extern VAR(Com_TransmitRequestUType, COM_VAR_NO_INIT) Com_TransmitRequest;  /* PRQA S 0759 */  /* MD_CSL_Union */
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
extern VAR(Com_TxBufferType, COM_VAR_NO_INIT) Com_TxBuffer[20];
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
extern VAR(Com_TxIPduGroupISRLockCounterUType, COM_VAR_NO_INIT) Com_TxIPduGroupISRLockCounter;  /* PRQA S 0759 */  /* MD_CSL_Union */
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
extern VAR(Com_TxPduGrpActiveType, COM_VAR_NO_INIT) Com_TxPduGrpActive[3];
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
extern VAR(Com_TxProcessingISRLockCounterUType, COM_VAR_NO_INIT) Com_TxProcessingISRLockCounter;  /* PRQA S 0759 */  /* MD_CSL_Union */
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
extern VAR(Com_TxSduLengthType, COM_VAR_NO_INIT) Com_TxSduLength[3];
#define COM_STOP_SEC_VAR_NO_INIT_16
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */


/**********************************************************************************************************************
  CONFIGURATION CLASS: LINK
  SECTION: GLOBAL DATA PROTOTYPES
**********************************************************************************************************************/



/**********************************************************************************************************************
  GLOBAL FUNCTION PROTOTYPES
**********************************************************************************************************************/
/* User Config File Start */

/* User Config File End */


/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL FUNCTION PROTOTYPES
**********************************************************************************************************************/

/**********************************************************************************************************************
  CONFIGURATION CLASS: LINK
  SECTION: GLOBAL FUNCTION PROTOTYPES
**********************************************************************************************************************/



#endif  /* COM_LCFG_H */
/**********************************************************************************************************************
  END OF FILE: Com_Lcfg.h
**********************************************************************************************************************/

