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
 *              File: IpduM_Lcfg.h
 *   Generation Time: 2024-08-03 19:52:22
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


#if !defined (IPDUM_LCFG_H)
# define IPDUM_LCFG_H

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
/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL CONSTANT MACROS
**********************************************************************************************************************/
/** 
  \defgroup  IpduMPCDataSwitches  IpduM Data Switches  (PRE_COMPILE)
  \brief  These defines are used to deactivate data and their processing.
  \{
*/ 
#define IPDUM_CCONTAINERRXQUEUEINFO                                                                 STD_OFF  /**< Deactivateable: 'IpduM_CContainerRxQueueInfo' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define IPDUM_CONTAINERRXQUEUEINSTANCEENDIDXOFCONTAINERRXQUEUEINFO                                  STD_OFF  /**< Deactivateable: 'IpduM_CContainerRxQueueInfo.ContainerRxQueueInstanceEndIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define IPDUM_CONTAINERRXQUEUEINSTANCELENGTHOFCONTAINERRXQUEUEINFO                                  STD_OFF  /**< Deactivateable: 'IpduM_CContainerRxQueueInfo.ContainerRxQueueInstanceLength' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define IPDUM_CONTAINERRXQUEUEINSTANCESTARTIDXOFCONTAINERRXQUEUEINFO                                STD_OFF  /**< Deactivateable: 'IpduM_CContainerRxQueueInfo.ContainerRxQueueInstanceStartIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define IPDUM_RXCONTAINERMAINFUNCTIONBUFFERENDIDXOFCONTAINERRXQUEUEINFO                             STD_OFF  /**< Deactivateable: 'IpduM_CContainerRxQueueInfo.RxContainerMainFunctionBufferEndIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define IPDUM_RXCONTAINERMAINFUNCTIONBUFFERLENGTHOFCONTAINERRXQUEUEINFO                             STD_OFF  /**< Deactivateable: 'IpduM_CContainerRxQueueInfo.RxContainerMainFunctionBufferLength' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define IPDUM_RXCONTAINERMAINFUNCTIONBUFFERSTARTIDXOFCONTAINERRXQUEUEINFO                           STD_OFF  /**< Deactivateable: 'IpduM_CContainerRxQueueInfo.RxContainerMainFunctionBufferStartIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define IPDUM_CCONTAINERRXQUEUEINSTANCE                                                             STD_OFF  /**< Deactivateable: 'IpduM_CContainerRxQueueInstance' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define IPDUM_CONTAINERRXQUEUEBUFFERENDIDXOFCONTAINERRXQUEUEINSTANCE                                STD_OFF  /**< Deactivateable: 'IpduM_CContainerRxQueueInstance.ContainerRxQueueBufferEndIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define IPDUM_CONTAINERRXQUEUEBUFFERLENGTHOFCONTAINERRXQUEUEINSTANCE                                STD_OFF  /**< Deactivateable: 'IpduM_CContainerRxQueueInstance.ContainerRxQueueBufferLength' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define IPDUM_CONTAINERRXQUEUEBUFFERSTARTIDXOFCONTAINERRXQUEUEINSTANCE                              STD_OFF  /**< Deactivateable: 'IpduM_CContainerRxQueueInstance.ContainerRxQueueBufferStartIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define IPDUM_CCONTAINERTXCONFIRMATIONBUFFERINFO                                                    STD_OFF  /**< Deactivateable: 'IpduM_CContainerTxConfirmationBufferInfo' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define IPDUM_CONTAINERTXCONFIRMATIONBUFFERENDIDXOFCONTAINERTXCONFIRMATIONBUFFERINFO                STD_OFF  /**< Deactivateable: 'IpduM_CContainerTxConfirmationBufferInfo.ContainerTxConfirmationBufferEndIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define IPDUM_CONTAINERTXCONFIRMATIONBUFFERLENGTHOFCONTAINERTXCONFIRMATIONBUFFERINFO                STD_OFF  /**< Deactivateable: 'IpduM_CContainerTxConfirmationBufferInfo.ContainerTxConfirmationBufferLength' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define IPDUM_CONTAINERTXCONFIRMATIONBUFFERSTARTIDXOFCONTAINERTXCONFIRMATIONBUFFERINFO              STD_OFF  /**< Deactivateable: 'IpduM_CContainerTxConfirmationBufferInfo.ContainerTxConfirmationBufferStartIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define IPDUM_CDATAQUEUEINFO                                                                        STD_OFF  /**< Deactivateable: 'IpduM_CDataQueueInfo' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define IPDUM_DATAQUEUEINSTANCEENDIDXOFDATAQUEUEINFO                                                STD_OFF  /**< Deactivateable: 'IpduM_CDataQueueInfo.DataQueueInstanceEndIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define IPDUM_DATAQUEUEINSTANCELENGTHOFDATAQUEUEINFO                                                STD_OFF  /**< Deactivateable: 'IpduM_CDataQueueInfo.DataQueueInstanceLength' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define IPDUM_DATAQUEUEINSTANCESTARTIDXOFDATAQUEUEINFO                                              STD_OFF  /**< Deactivateable: 'IpduM_CDataQueueInfo.DataQueueInstanceStartIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define IPDUM_CDATAQUEUEINSTANCE                                                                    STD_OFF  /**< Deactivateable: 'IpduM_CDataQueueInstance' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define IPDUM_DATAQUEUEBUFFERENDIDXOFDATAQUEUEINSTANCE                                              STD_OFF  /**< Deactivateable: 'IpduM_CDataQueueInstance.DataQueueBufferEndIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define IPDUM_DATAQUEUEBUFFERLENGTHOFDATAQUEUEINSTANCE                                              STD_OFF  /**< Deactivateable: 'IpduM_CDataQueueInstance.DataQueueBufferLength' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define IPDUM_DATAQUEUEBUFFERSTARTIDXOFDATAQUEUEINSTANCE                                            STD_OFF  /**< Deactivateable: 'IpduM_CDataQueueInstance.DataQueueBufferStartIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define IPDUM_DATAQUEUEIDBUFFERENDIDXOFDATAQUEUEINSTANCE                                            STD_OFF  /**< Deactivateable: 'IpduM_CDataQueueInstance.DataQueueIdBufferEndIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define IPDUM_DATAQUEUEIDBUFFERLENGTHOFDATAQUEUEINSTANCE                                            STD_OFF  /**< Deactivateable: 'IpduM_CDataQueueInstance.DataQueueIdBufferLength' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define IPDUM_DATAQUEUEIDBUFFERSTARTIDXOFDATAQUEUEINSTANCE                                          STD_OFF  /**< Deactivateable: 'IpduM_CDataQueueInstance.DataQueueIdBufferStartIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define IPDUM_CREQUESTQUEUEINFO                                                                     STD_OFF  /**< Deactivateable: 'IpduM_CRequestQueueInfo' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define IPDUM_REQUESTQUEUEBUFFERENDIDXOFREQUESTQUEUEINFO                                            STD_OFF  /**< Deactivateable: 'IpduM_CRequestQueueInfo.RequestQueueBufferEndIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define IPDUM_REQUESTQUEUEBUFFERLENGTHOFREQUESTQUEUEINFO                                            STD_OFF  /**< Deactivateable: 'IpduM_CRequestQueueInfo.RequestQueueBufferLength' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define IPDUM_REQUESTQUEUEBUFFERSTARTIDXOFREQUESTQUEUEINFO                                          STD_OFF  /**< Deactivateable: 'IpduM_CRequestQueueInfo.RequestQueueBufferStartIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define IPDUM_CTXCONTAINERPDU                                                                       STD_OFF  /**< Deactivateable: 'IpduM_CTxContainerPdu' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define IPDUM_CONTAINERTXCONFIRMATIONBUFFERINFOIDXOFTXCONTAINERPDU                                  STD_OFF  /**< Deactivateable: 'IpduM_CTxContainerPdu.ContainerTxConfirmationBufferInfoIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define IPDUM_CONTAINERTXCONFIRMATIONBUFFERINFOUSEDOFTXCONTAINERPDU                                 STD_OFF  /**< Deactivateable: 'IpduM_CTxContainerPdu.ContainerTxConfirmationBufferInfoUsed' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define IPDUM_CONTAINERTYPEOFTXCONTAINERPDU                                                         STD_OFF  /**< Deactivateable: 'IpduM_CTxContainerPdu.ContainerType' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define IPDUM_DATAQUEUEINFOIDXOFTXCONTAINERPDU                                                      STD_OFF  /**< Deactivateable: 'IpduM_CTxContainerPdu.DataQueueInfoIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define IPDUM_DATAQUEUEINFOUSEDOFTXCONTAINERPDU                                                     STD_OFF  /**< Deactivateable: 'IpduM_CTxContainerPdu.DataQueueInfoUsed' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define IPDUM_DIRECTDATAPROVISIONOFTXCONTAINERPDU                                                   STD_OFF  /**< Deactivateable: 'IpduM_CTxContainerPdu.DirectDataProvision' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define IPDUM_FIRSTCONTAINEDPDUTRIGGEROFTXCONTAINERPDU                                              STD_OFF  /**< Deactivateable: 'IpduM_CTxContainerPdu.FirstContainedPduTrigger' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define IPDUM_HEADERSIZEOFTXCONTAINERPDU                                                            STD_OFF  /**< Deactivateable: 'IpduM_CTxContainerPdu.HeaderSize' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define IPDUM_METADATASIZEOFTXCONTAINERPDU                                                          STD_OFF  /**< Deactivateable: 'IpduM_CTxContainerPdu.MetaDataSize' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define IPDUM_PDULENGTHOFTXCONTAINERPDU                                                             STD_OFF  /**< Deactivateable: 'IpduM_CTxContainerPdu.PduLength' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define IPDUM_REQUESTQUEUEPRIOINDIRECTIONIDXOFTXCONTAINERPDU                                        STD_OFF  /**< Deactivateable: 'IpduM_CTxContainerPdu.RequestQueuePrioIndirectionIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define IPDUM_REQUESTQUEUEPRIOINDIRECTIONUSEDOFTXCONTAINERPDU                                       STD_OFF  /**< Deactivateable: 'IpduM_CTxContainerPdu.RequestQueuePrioIndirectionUsed' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define IPDUM_SENDTIMEOUTOFTXCONTAINERPDU                                                           STD_OFF  /**< Deactivateable: 'IpduM_CTxContainerPdu.SendTimeout' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define IPDUM_SENDTODEFOFTXCONTAINERPDU                                                             STD_OFF  /**< Deactivateable: 'IpduM_CTxContainerPdu.SendToDef' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define IPDUM_TRIGGERTRANSMITOFTXCONTAINERPDU                                                       STD_OFF  /**< Deactivateable: 'IpduM_CTxContainerPdu.TriggerTransmit' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define IPDUM_TXCONFIRMATIONTIMEOUTOFTXCONTAINERPDU                                                 STD_OFF  /**< Deactivateable: 'IpduM_CTxContainerPdu.TxConfirmationTimeout' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define IPDUM_TXCONTAINEDPDUENDIDXOFTXCONTAINERPDU                                                  STD_OFF  /**< Deactivateable: 'IpduM_CTxContainerPdu.TxContainedPduEndIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define IPDUM_TXCONTAINEDPDUSTARTIDXOFTXCONTAINERPDU                                                STD_OFF  /**< Deactivateable: 'IpduM_CTxContainerPdu.TxContainedPduStartIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define IPDUM_TXCONTAINEDPDUUSEDOFTXCONTAINERPDU                                                    STD_OFF  /**< Deactivateable: 'IpduM_CTxContainerPdu.TxContainedPduUsed' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define IPDUM_TXCONTAINERPDUREFOFTXCONTAINERPDU                                                     STD_OFF  /**< Deactivateable: 'IpduM_CTxContainerPdu.TxContainerPduRef' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define IPDUM_TXLOINFOIDXOFTXCONTAINERPDU                                                           STD_OFF  /**< Deactivateable: 'IpduM_CTxContainerPdu.TxLoInfoIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define IPDUM_TXLOINFOUSEDOFTXCONTAINERPDU                                                          STD_OFF  /**< Deactivateable: 'IpduM_CTxContainerPdu.TxLoInfoUsed' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define IPDUM_TXSIZETHRESHOLDOFTXCONTAINERPDU                                                       STD_OFF  /**< Deactivateable: 'IpduM_CTxContainerPdu.TxSizeThreshold' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define IPDUM_UNUSEDBITPATTERNOFTXCONTAINERPDU                                                      STD_OFF  /**< Deactivateable: 'IpduM_CTxContainerPdu.UnusedBitPattern' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define IPDUM_CTXLOINFO                                                                             STD_ON
#define IPDUM_PATHWAYTYPEOFCTXLOINFO                                                                STD_ON
#define IPDUM_TXCONTAINERPDUIDXOFCTXLOINFO                                                          STD_OFF  /**< Deactivateable: 'IpduM_CTxLoInfo.TxContainerPduIdx' Reason: 'the optional indirection is deactivated because TxContainerPduUsedOfCTxLoInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define IPDUM_TXCONTAINERPDUUSEDOFCTXLOINFO                                                         STD_OFF  /**< Deactivateable: 'IpduM_CTxLoInfo.TxContainerPduUsed' Reason: 'the optional indirection is deactivated because TxContainerPduUsedOfCTxLoInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define IPDUM_TXPATHWAYIDXOFCTXLOINFO                                                               STD_ON
#define IPDUM_TXPATHWAYUSEDOFCTXLOINFO                                                              STD_ON
#define IPDUM_CTXPATHWAY                                                                            STD_ON
#define IPDUM_JITUPDATEBUFFERENDIDXOFTXPATHWAY                                                      STD_ON
#define IPDUM_JITUPDATEBUFFERLENGTHOFTXPATHWAY                                                      STD_ON
#define IPDUM_JITUPDATEBUFFERSTARTIDXOFTXPATHWAY                                                    STD_ON
#define IPDUM_LLPDUREFOFTXPATHWAY                                                                   STD_ON
#define IPDUM_TRIGGERTRANSMITBUFFERENDIDXOFTXPATHWAY                                                STD_ON
#define IPDUM_TRIGGERTRANSMITBUFFERLENGTHOFTXPATHWAY                                                STD_ON
#define IPDUM_TRIGGERTRANSMITBUFFERSTARTIDXOFTXPATHWAY                                              STD_ON
#define IPDUM_TXBUFFERENDIDXOFTXPATHWAY                                                             STD_ON
#define IPDUM_TXBUFFERLENGTHOFTXPATHWAY                                                             STD_ON
#define IPDUM_TXBUFFERSTARTIDXOFTXPATHWAY                                                           STD_ON
#define IPDUM_TXCONFIRMATIONTIMEOUTOFTXPATHWAY                                                      STD_OFF  /**< Deactivateable: 'IpduM_CTxPathway.TxConfirmationTimeout' Reason: 'the value of IpduM_TxConfirmationTimeoutOfTxPathway is always '0' due to this, the array is deactivated.' */
#define IPDUM_TXLOINFOIDXOFTXPATHWAY                                                                STD_ON
#define IPDUM_TXLOINFOUSEDOFTXPATHWAY                                                               STD_ON
#define IPDUM_TXPARTINDENDIDXOFTXPATHWAY                                                            STD_ON
#define IPDUM_TXPARTINDSTARTIDXOFTXPATHWAY                                                          STD_ON
#define IPDUM_TXPARTINITIALDYNPARTIDXOFTXPATHWAY                                                    STD_ON
#define IPDUM_TXPARTSTATICPARTIDXOFTXPATHWAY                                                        STD_ON
#define IPDUM_TXPARTSTATICPARTUSEDOFTXPATHWAY                                                       STD_ON
#define IPDUM_TXSTATICPDUREFOFTXPATHWAY                                                             STD_ON
#define IPDUM_TXSTATICPDUREFUSEDOFTXPATHWAY                                                         STD_ON
#define IPDUM_UNUSEDAREASDEFAULTOFTXPATHWAY                                                         STD_ON
#define IPDUM_CONTAINERRXQUEUEBUFFER                                                                STD_OFF  /**< Deactivateable: 'IpduM_ContainerRxQueueBuffer' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define IPDUM_CONTAINERTXCONFIRMATIONBUFFER                                                         STD_OFF  /**< Deactivateable: 'IpduM_ContainerTxConfirmationBuffer' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define IPDUM_CONTAINERTXLIBBUFFER                                                                  STD_OFF  /**< Deactivateable: 'IpduM_ContainerTxLIBBuffer' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define IPDUM_DATAQUEUEBUFFER                                                                       STD_OFF  /**< Deactivateable: 'IpduM_DataQueueBuffer' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define IPDUM_DATAQUEUEIDBUFFER                                                                     STD_OFF  /**< Deactivateable: 'IpduM_DataQueueIdBuffer' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define IPDUM_FINALMAGICNUMBER                                                                      STD_OFF  /**< Deactivateable: 'IpduM_FinalMagicNumber' Reason: 'the module configuration does not support flashing of data.' */
#define IPDUM_INITDATAHASHCODE                                                                      STD_OFF  /**< Deactivateable: 'IpduM_InitDataHashCode' Reason: 'the module configuration does not support flashing of data.' */
#define IPDUM_INITIALIZED                                                                           STD_ON
#define IPDUM_JITUPDATEBUFFER                                                                       STD_ON
#define IPDUM_MAINFUNCTIONRXINDIRECTION                                                             STD_OFF  /**< Deactivateable: 'IpduM_MainFunctionRxIndirection' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define IPDUM_RXCONTAINERPDUINDENDIDXOFMAINFUNCTIONRXINDIRECTION                                    STD_OFF  /**< Deactivateable: 'IpduM_MainFunctionRxIndirection.RxContainerPduIndEndIdx' Reason: 'the optional indirection is deactivated because RxContainerPduIndUsedOfMainFunctionRxIndirection is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define IPDUM_RXCONTAINERPDUINDSTARTIDXOFMAINFUNCTIONRXINDIRECTION                                  STD_OFF  /**< Deactivateable: 'IpduM_MainFunctionRxIndirection.RxContainerPduIndStartIdx' Reason: 'the optional indirection is deactivated because RxContainerPduIndUsedOfMainFunctionRxIndirection is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define IPDUM_RXCONTAINERPDUINDUSEDOFMAINFUNCTIONRXINDIRECTION                                      STD_OFF  /**< Deactivateable: 'IpduM_MainFunctionRxIndirection.RxContainerPduIndUsed' Reason: 'the optional indirection is deactivated because RxContainerPduIndUsedOfMainFunctionRxIndirection is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define IPDUM_MAINFUNCTIONTXINDIRECTION                                                             STD_ON
#define IPDUM_TXCONTAINERPDUINDENDIDXOFMAINFUNCTIONTXINDIRECTION                                    STD_OFF  /**< Deactivateable: 'IpduM_MainFunctionTxIndirection.TxContainerPduIndEndIdx' Reason: 'the optional indirection is deactivated because TxContainerPduIndUsedOfMainFunctionTxIndirection is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define IPDUM_TXCONTAINERPDUINDSTARTIDXOFMAINFUNCTIONTXINDIRECTION                                  STD_OFF  /**< Deactivateable: 'IpduM_MainFunctionTxIndirection.TxContainerPduIndStartIdx' Reason: 'the optional indirection is deactivated because TxContainerPduIndUsedOfMainFunctionTxIndirection is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define IPDUM_TXCONTAINERPDUINDUSEDOFMAINFUNCTIONTXINDIRECTION                                      STD_OFF  /**< Deactivateable: 'IpduM_MainFunctionTxIndirection.TxContainerPduIndUsed' Reason: 'the optional indirection is deactivated because TxContainerPduIndUsedOfMainFunctionTxIndirection is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define IPDUM_TXLOINFOINDENDIDXOFMAINFUNCTIONTXINDIRECTION                                          STD_ON
#define IPDUM_TXLOINFOINDSTARTIDXOFMAINFUNCTIONTXINDIRECTION                                        STD_ON
#define IPDUM_TXLOINFOINDUSEDOFMAINFUNCTIONTXINDIRECTION                                            STD_ON
#define IPDUM_REQUESTQUEUEBUFFER                                                                    STD_OFF  /**< Deactivateable: 'IpduM_RequestQueueBuffer' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' */
#define IPDUM_DLCOFREQUESTQUEUEBUFFER                                                               STD_OFF  /**< Deactivateable: 'IpduM_RequestQueueBuffer.Dlc' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' */
#define IPDUM_TXCONTAINEDPDUIDXOFREQUESTQUEUEBUFFER                                                 STD_OFF  /**< Deactivateable: 'IpduM_RequestQueueBuffer.TxContainedPduIdx' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' */
#define IPDUM_REQUESTQUEUEPRIOINDIRECTION                                                           STD_OFF  /**< Deactivateable: 'IpduM_RequestQueuePrioIndirection' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define IPDUM_CONTAINERTXLIBBUFFERENDIDXOFREQUESTQUEUEPRIOINDIRECTION                               STD_OFF  /**< Deactivateable: 'IpduM_RequestQueuePrioIndirection.ContainerTxLIBBufferEndIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define IPDUM_CONTAINERTXLIBBUFFERLENGTHOFREQUESTQUEUEPRIOINDIRECTION                               STD_OFF  /**< Deactivateable: 'IpduM_RequestQueuePrioIndirection.ContainerTxLIBBufferLength' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define IPDUM_CONTAINERTXLIBBUFFERSTARTIDXOFREQUESTQUEUEPRIOINDIRECTION                             STD_OFF  /**< Deactivateable: 'IpduM_RequestQueuePrioIndirection.ContainerTxLIBBufferStartIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define IPDUM_REQUESTQUEUEINFOENDIDXOFREQUESTQUEUEPRIOINDIRECTION                                   STD_OFF  /**< Deactivateable: 'IpduM_RequestQueuePrioIndirection.RequestQueueInfoEndIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define IPDUM_REQUESTQUEUEINFOLENGTHOFREQUESTQUEUEPRIOINDIRECTION                                   STD_OFF  /**< Deactivateable: 'IpduM_RequestQueuePrioIndirection.RequestQueueInfoLength' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define IPDUM_REQUESTQUEUEINFOSTARTIDXOFREQUESTQUEUEPRIOINDIRECTION                                 STD_OFF  /**< Deactivateable: 'IpduM_RequestQueuePrioIndirection.RequestQueueInfoStartIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define IPDUM_RESTSEGMENT                                                                           STD_OFF  /**< Deactivateable: 'IpduM_RestSegment' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define IPDUM_BITINBYTEPOSOFRESTSEGMENT                                                             STD_OFF  /**< Deactivateable: 'IpduM_RestSegment.BitInBytePos' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define IPDUM_ENDBYTEMASKCLEAROFRESTSEGMENT                                                         STD_OFF  /**< Deactivateable: 'IpduM_RestSegment.EndByteMaskClear' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define IPDUM_ENDBYTEMASKWRITEOFRESTSEGMENT                                                         STD_OFF  /**< Deactivateable: 'IpduM_RestSegment.EndByteMaskWrite' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define IPDUM_FIRSTBYTEPOSOFRESTSEGMENT                                                             STD_OFF  /**< Deactivateable: 'IpduM_RestSegment.FirstBytePos' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define IPDUM_FIRSTFULLBYTEPOSOFRESTSEGMENT                                                         STD_OFF  /**< Deactivateable: 'IpduM_RestSegment.FirstFullBytePos' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define IPDUM_FULLBYTESPRESENTOFRESTSEGMENT                                                         STD_OFF  /**< Deactivateable: 'IpduM_RestSegment.FullBytesPresent' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define IPDUM_LASTBYTEPOSOFRESTSEGMENT                                                              STD_OFF  /**< Deactivateable: 'IpduM_RestSegment.LastBytePos' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define IPDUM_LASTFULLBYTEPOSOFRESTSEGMENT                                                          STD_OFF  /**< Deactivateable: 'IpduM_RestSegment.LastFullBytePos' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define IPDUM_LENGTHOFRESTSEGMENT                                                                   STD_OFF  /**< Deactivateable: 'IpduM_RestSegment.Length' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define IPDUM_PARTIALENDBYTEOFRESTSEGMENT                                                           STD_OFF  /**< Deactivateable: 'IpduM_RestSegment.PartialEndByte' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define IPDUM_PARTIALSTARTBYTEOFRESTSEGMENT                                                         STD_OFF  /**< Deactivateable: 'IpduM_RestSegment.PartialStartByte' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define IPDUM_PDUBYTEPOSOFRESTSEGMENT                                                               STD_OFF  /**< Deactivateable: 'IpduM_RestSegment.PduBytePos' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define IPDUM_STARTBYTEMASKCLEAROFRESTSEGMENT                                                       STD_OFF  /**< Deactivateable: 'IpduM_RestSegment.StartByteMaskClear' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define IPDUM_STARTBYTEMASKWRITEOFRESTSEGMENT                                                       STD_OFF  /**< Deactivateable: 'IpduM_RestSegment.StartByteMaskWrite' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define IPDUM_RXBUFFER                                                                              STD_OFF  /**< Deactivateable: 'IpduM_RxBuffer' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define IPDUM_RXCONTAINEDPDU                                                                        STD_OFF  /**< Deactivateable: 'IpduM_RxContainedPdu' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define IPDUM_CONTAINEDPDUREFOFRXCONTAINEDPDU                                                       STD_OFF  /**< Deactivateable: 'IpduM_RxContainedPdu.ContainedPduRef' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define IPDUM_ENDBYTEPOSITIONOFRXCONTAINEDPDU                                                       STD_OFF  /**< Deactivateable: 'IpduM_RxContainedPdu.EndBytePosition' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define IPDUM_HEADERIDOFRXCONTAINEDPDU                                                              STD_OFF  /**< Deactivateable: 'IpduM_RxContainedPdu.HeaderId' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define IPDUM_LENGTHOFRXCONTAINEDPDU                                                                STD_OFF  /**< Deactivateable: 'IpduM_RxContainedPdu.Length' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define IPDUM_OFFSETOFRXCONTAINEDPDU                                                                STD_OFF  /**< Deactivateable: 'IpduM_RxContainedPdu.Offset' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define IPDUM_RXCONTAINERPDUIDXOFRXCONTAINEDPDU                                                     STD_OFF  /**< Deactivateable: 'IpduM_RxContainedPdu.RxContainerPduIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define IPDUM_RXCONTAINERPDUUSEDOFRXCONTAINEDPDU                                                    STD_OFF  /**< Deactivateable: 'IpduM_RxContainedPdu.RxContainerPduUsed' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define IPDUM_UPDATEBITUSEDOFRXCONTAINEDPDU                                                         STD_OFF  /**< Deactivateable: 'IpduM_RxContainedPdu.UpdateBitUsed' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define IPDUM_UPDATEINDICATIONBITPOSITIONOFRXCONTAINEDPDU                                           STD_OFF  /**< Deactivateable: 'IpduM_RxContainedPdu.UpdateIndicationBitPosition' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define IPDUM_RXCONTAINEDPDUIND                                                                     STD_OFF  /**< Deactivateable: 'IpduM_RxContainedPduInd' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define IPDUM_RXCONTAINERMAINFUNCTIONBUFFER                                                         STD_OFF  /**< Deactivateable: 'IpduM_RxContainerMainFunctionBuffer' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define IPDUM_RXCONTAINERPDU                                                                        STD_OFF  /**< Deactivateable: 'IpduM_RxContainerPdu' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define IPDUM_ACCEPTALLPDUSOFRXCONTAINERPDU                                                         STD_OFF  /**< Deactivateable: 'IpduM_RxContainerPdu.AcceptAllPdus' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define IPDUM_CONTAINERRXQUEUEINFOIDXOFRXCONTAINERPDU                                               STD_OFF  /**< Deactivateable: 'IpduM_RxContainerPdu.ContainerRxQueueInfoIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define IPDUM_CONTAINERRXQUEUEINFOUSEDOFRXCONTAINERPDU                                              STD_OFF  /**< Deactivateable: 'IpduM_RxContainerPdu.ContainerRxQueueInfoUsed' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define IPDUM_HEADERSIZEOFRXCONTAINERPDU                                                            STD_OFF  /**< Deactivateable: 'IpduM_RxContainerPdu.HeaderSize' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define IPDUM_METADATASIZEOFRXCONTAINERPDU                                                          STD_OFF  /**< Deactivateable: 'IpduM_RxContainerPdu.MetaDataSize' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define IPDUM_RXCONTAINEDPDUINDENDIDXOFRXCONTAINERPDU                                               STD_OFF  /**< Deactivateable: 'IpduM_RxContainerPdu.RxContainedPduIndEndIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define IPDUM_RXCONTAINEDPDUINDSTARTIDXOFRXCONTAINERPDU                                             STD_OFF  /**< Deactivateable: 'IpduM_RxContainerPdu.RxContainedPduIndStartIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define IPDUM_RXCONTAINEDPDUINDUSEDOFRXCONTAINERPDU                                                 STD_OFF  /**< Deactivateable: 'IpduM_RxContainerPdu.RxContainedPduIndUsed' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define IPDUM_RXCONTAINERPDUIND                                                                     STD_OFF  /**< Deactivateable: 'IpduM_RxContainerPduInd' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define IPDUM_RXDYNPDU                                                                              STD_OFF  /**< Deactivateable: 'IpduM_RxDynPdu' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define IPDUM_MINDLCOFRXDYNPDU                                                                      STD_OFF  /**< Deactivateable: 'IpduM_RxDynPdu.MinDLC' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define IPDUM_RXSELECTORPATTERNENDIDXOFRXDYNPDU                                                     STD_OFF  /**< Deactivateable: 'IpduM_RxDynPdu.RxSelectorPatternEndIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define IPDUM_RXSELECTORPATTERNSTARTIDXOFRXDYNPDU                                                   STD_OFF  /**< Deactivateable: 'IpduM_RxDynPdu.RxSelectorPatternStartIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define IPDUM_SEGMENTENDIDXOFRXDYNPDU                                                               STD_OFF  /**< Deactivateable: 'IpduM_RxDynPdu.SegmentEndIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define IPDUM_SEGMENTSTARTIDXOFRXDYNPDU                                                             STD_OFF  /**< Deactivateable: 'IpduM_RxDynPdu.SegmentStartIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define IPDUM_ULPDUREFOFRXDYNPDU                                                                    STD_OFF  /**< Deactivateable: 'IpduM_RxDynPdu.UlPduRef' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define IPDUM_RXINFO                                                                                STD_OFF  /**< Deactivateable: 'IpduM_RxInfo' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define IPDUM_INVALIDHNDOFRXINFO                                                                    STD_OFF  /**< Deactivateable: 'IpduM_RxInfo.InvalidHnd' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define IPDUM_PATHWAYTYPEOFRXINFO                                                                   STD_OFF  /**< Deactivateable: 'IpduM_RxInfo.PathwayType' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define IPDUM_RXPATHWAYINDIDXOFRXINFO                                                               STD_OFF  /**< Deactivateable: 'IpduM_RxInfo.RxPathwayIndIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define IPDUM_RXPATHWAYINDOFRXINFO                                                                  STD_OFF  /**< Deactivateable: 'IpduM_RxInfo.RxPathwayInd' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define IPDUM_RXMUXPDU                                                                              STD_OFF  /**< Deactivateable: 'IpduM_RxMuxPdu' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define IPDUM_RXBUFFERENDIDXOFRXMUXPDU                                                              STD_OFF  /**< Deactivateable: 'IpduM_RxMuxPdu.RxBufferEndIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define IPDUM_RXBUFFERSTARTIDXOFRXMUXPDU                                                            STD_OFF  /**< Deactivateable: 'IpduM_RxMuxPdu.RxBufferStartIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define IPDUM_RXDYNPDUENDIDXOFRXMUXPDU                                                              STD_OFF  /**< Deactivateable: 'IpduM_RxMuxPdu.RxDynPduEndIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define IPDUM_RXDYNPDUSTARTIDXOFRXMUXPDU                                                            STD_OFF  /**< Deactivateable: 'IpduM_RxMuxPdu.RxDynPduStartIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define IPDUM_RXSTATICPDUIDXOFRXMUXPDU                                                              STD_OFF  /**< Deactivateable: 'IpduM_RxMuxPdu.RxStaticPduIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define IPDUM_RXSTATICPDUUSEDOFRXMUXPDU                                                             STD_OFF  /**< Deactivateable: 'IpduM_RxMuxPdu.RxStaticPduUsed' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define IPDUM_SELECTORFIELDBYTEPOSITIONOFRXMUXPDU                                                   STD_OFF  /**< Deactivateable: 'IpduM_RxMuxPdu.SelectorFieldBytePosition' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define IPDUM_SELECTORFIELDSTARTBITOFRXMUXPDU                                                       STD_OFF  /**< Deactivateable: 'IpduM_RxMuxPdu.SelectorFieldStartBit' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define IPDUM_RXSELECTORPATTERN                                                                     STD_OFF  /**< Deactivateable: 'IpduM_RxSelectorPattern' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define IPDUM_SELECTORFIELDSUBMASKOFRXSELECTORPATTERN                                               STD_OFF  /**< Deactivateable: 'IpduM_RxSelectorPattern.SelectorFieldSubMask' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define IPDUM_SELECTORFIELDSUBPATTERNOFRXSELECTORPATTERN                                            STD_OFF  /**< Deactivateable: 'IpduM_RxSelectorPattern.SelectorFieldSubPattern' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define IPDUM_RXSTATICPDU                                                                           STD_OFF  /**< Deactivateable: 'IpduM_RxStaticPdu' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define IPDUM_MINDLCOFRXSTATICPDU                                                                   STD_OFF  /**< Deactivateable: 'IpduM_RxStaticPdu.MinDLC' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define IPDUM_SEGMENTENDIDXOFRXSTATICPDU                                                            STD_OFF  /**< Deactivateable: 'IpduM_RxStaticPdu.SegmentEndIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define IPDUM_SEGMENTSTARTIDXOFRXSTATICPDU                                                          STD_OFF  /**< Deactivateable: 'IpduM_RxStaticPdu.SegmentStartIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define IPDUM_ULPDUREFOFRXSTATICPDU                                                                 STD_OFF  /**< Deactivateable: 'IpduM_RxStaticPdu.UlPduRef' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define IPDUM_SEGMENT                                                                               STD_ON
#define IPDUM_BITINBYTEPOSOFSEGMENT                                                                 STD_ON
#define IPDUM_ENDBYTEMASKCLEAROFSEGMENT                                                             STD_ON
#define IPDUM_ENDBYTEMASKWRITEOFSEGMENT                                                             STD_ON
#define IPDUM_FIRSTBYTEPOSOFSEGMENT                                                                 STD_ON
#define IPDUM_FIRSTFULLBYTEPOSOFSEGMENT                                                             STD_ON
#define IPDUM_FULLBYTESPRESENTOFSEGMENT                                                             STD_ON
#define IPDUM_LASTBYTEPOSOFSEGMENT                                                                  STD_ON
#define IPDUM_LASTFULLBYTEPOSOFSEGMENT                                                              STD_ON
#define IPDUM_LENGTHOFSEGMENT                                                                       STD_ON
#define IPDUM_PARTIALENDBYTEOFSEGMENT                                                               STD_OFF  /**< Deactivateable: 'IpduM_Segment.PartialEndByte' Reason: 'the value of IpduM_PartialEndByteOfSegment is always 'false' due to this, the array is deactivated.' */
#define IPDUM_PARTIALSTARTBYTEOFSEGMENT                                                             STD_OFF  /**< Deactivateable: 'IpduM_Segment.PartialStartByte' Reason: 'the value of IpduM_PartialStartByteOfSegment is always 'false' due to this, the array is deactivated.' */
#define IPDUM_PDUBYTEPOSOFSEGMENT                                                                   STD_ON
#define IPDUM_STARTBYTEMASKCLEAROFSEGMENT                                                           STD_ON
#define IPDUM_STARTBYTEMASKWRITEOFSEGMENT                                                           STD_ON
#define IPDUM_SIZEOFCTXLOINFO                                                                       STD_ON
#define IPDUM_SIZEOFCTXPATHWAY                                                                      STD_ON
#define IPDUM_SIZEOFJITUPDATEBUFFER                                                                 STD_ON
#define IPDUM_SIZEOFMAINFUNCTIONTXINDIRECTION                                                       STD_ON
#define IPDUM_SIZEOFSEGMENT                                                                         STD_ON
#define IPDUM_SIZEOFTRIGGERTRANSMITBUFFER                                                           STD_ON
#define IPDUM_SIZEOFTXBUFFER                                                                        STD_ON
#define IPDUM_SIZEOFTXINITVALUES                                                                    STD_ON
#define IPDUM_SIZEOFTXLOINFOIND                                                                     STD_ON
#define IPDUM_SIZEOFTXLOINFOWITHINVALIDINDEXES                                                      STD_ON
#define IPDUM_SIZEOFTXPART                                                                          STD_ON
#define IPDUM_SIZEOFTXPARTIND                                                                       STD_ON
#define IPDUM_SIZEOFTXUPINFO                                                                        STD_ON
#define IPDUM_SIZEOFVTXLOINFO                                                                       STD_ON
#define IPDUM_SIZEOFVTXPATHWAY                                                                      STD_ON
#define IPDUM_TRIGGERTRANSMITBUFFER                                                                 STD_ON
#define IPDUM_TXBUFFER                                                                              STD_ON
#define IPDUM_TXCONTAINEDPDU                                                                        STD_OFF  /**< Deactivateable: 'IpduM_TxContainedPdu' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define IPDUM_HEADERIDOFTXCONTAINEDPDU                                                              STD_OFF  /**< Deactivateable: 'IpduM_TxContainedPdu.HeaderId' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define IPDUM_LASTISBESTOFTXCONTAINEDPDU                                                            STD_OFF  /**< Deactivateable: 'IpduM_TxContainedPdu.LastIsBest' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define IPDUM_OFFSETOFTXCONTAINEDPDU                                                                STD_OFF  /**< Deactivateable: 'IpduM_TxContainedPdu.Offset' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define IPDUM_REQUESTQUEUEINFOIDXOFTXCONTAINEDPDU                                                   STD_OFF  /**< Deactivateable: 'IpduM_TxContainedPdu.RequestQueueInfoIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define IPDUM_REQUESTQUEUEINFOUSEDOFTXCONTAINEDPDU                                                  STD_OFF  /**< Deactivateable: 'IpduM_TxContainedPdu.RequestQueueInfoUsed' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define IPDUM_SENDTIMEOUTOFTXCONTAINEDPDU                                                           STD_OFF  /**< Deactivateable: 'IpduM_TxContainedPdu.SendTimeout' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define IPDUM_SENDTODEFOFTXCONTAINEDPDU                                                             STD_OFF  /**< Deactivateable: 'IpduM_TxContainedPdu.SendToDef' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define IPDUM_TXCONFIRMATIONOFTXCONTAINEDPDU                                                        STD_OFF  /**< Deactivateable: 'IpduM_TxContainedPdu.TxConfirmation' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define IPDUM_TXCONTAINEDPDUREFOFTXCONTAINEDPDU                                                     STD_OFF  /**< Deactivateable: 'IpduM_TxContainedPdu.TxContainedPduRef' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define IPDUM_TXCONTAINERPDUIDXOFTXCONTAINEDPDU                                                     STD_OFF  /**< Deactivateable: 'IpduM_TxContainedPdu.TxContainerPduIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define IPDUM_TXPDUTRIGGEROFTXCONTAINEDPDU                                                          STD_OFF  /**< Deactivateable: 'IpduM_TxContainedPdu.TxPduTrigger' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define IPDUM_UPDATEBITUSEDOFTXCONTAINEDPDU                                                         STD_OFF  /**< Deactivateable: 'IpduM_TxContainedPdu.UpdateBitUsed' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define IPDUM_UPDATEINDICATIONBITPOSITIONOFTXCONTAINEDPDU                                           STD_OFF  /**< Deactivateable: 'IpduM_TxContainedPdu.UpdateIndicationBitPosition' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define IPDUM_TXCONTAINERPDUIND                                                                     STD_OFF  /**< Deactivateable: 'IpduM_TxContainerPduInd' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define IPDUM_TXINITVALUES                                                                          STD_ON
#define IPDUM_TXLOINFOIND                                                                           STD_ON
#define IPDUM_TXLOINFOWITHINVALIDINDEXES                                                            STD_ON
#define IPDUM_CTXLOINFOIDXOFTXLOINFOWITHINVALIDINDEXES                                              STD_ON
#define IPDUM_INVALIDHNDOFTXLOINFOWITHINVALIDINDEXES                                                STD_OFF  /**< Deactivateable: 'IpduM_TxLoInfoWithInvalidIndexes.InvalidHnd' Reason: 'the value of IpduM_InvalidHndOfTxLoInfoWithInvalidIndexes is always 'false' due to this, the array is deactivated.' */
#define IPDUM_TXPART                                                                                STD_ON
#define IPDUM_JITUPDATEOFTXPART                                                                     STD_OFF  /**< Deactivateable: 'IpduM_TxPart.JitUpdate' Reason: 'the value of IpduM_JitUpdateOfTxPart is always 'false' due to this, the array is deactivated.' */
#define IPDUM_RESTSEGMENTENDIDXOFTXPART                                                             STD_OFF  /**< Deactivateable: 'IpduM_TxPart.RestSegmentEndIdx' Reason: 'the optional indirection is deactivated because RestSegmentUsedOfTxPart is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define IPDUM_RESTSEGMENTSTARTIDXOFTXPART                                                           STD_OFF  /**< Deactivateable: 'IpduM_TxPart.RestSegmentStartIdx' Reason: 'the optional indirection is deactivated because RestSegmentUsedOfTxPart is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define IPDUM_RESTSEGMENTUSEDOFTXPART                                                               STD_OFF  /**< Deactivateable: 'IpduM_TxPart.RestSegmentUsed' Reason: 'the optional indirection is deactivated because RestSegmentUsedOfTxPart is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define IPDUM_SEGMENTENDIDXOFTXPART                                                                 STD_ON
#define IPDUM_SEGMENTSTARTIDXOFTXPART                                                               STD_ON
#define IPDUM_TRIGGEREVENTOFTXPART                                                                  STD_ON
#define IPDUM_TXCONFIRMATIONOFTXPART                                                                STD_OFF  /**< Deactivateable: 'IpduM_TxPart.TxConfirmation' Reason: 'the value of IpduM_TxConfirmationOfTxPart is always 'false' due to this, the array is deactivated.' */
#define IPDUM_TXPATHWAYIDXOFTXPART                                                                  STD_ON
#define IPDUM_ULPDUREFOFTXPART                                                                      STD_ON
#define IPDUM_TXPARTIND                                                                             STD_ON
#define IPDUM_TXUPINFO                                                                              STD_ON
#define IPDUM_INVALIDHNDOFTXUPINFO                                                                  STD_OFF  /**< Deactivateable: 'IpduM_TxUpInfo.InvalidHnd' Reason: 'the value of IpduM_InvalidHndOfTxUpInfo is always 'false' due to this, the array is deactivated.' */
#define IPDUM_PATHWAYTYPEOFTXUPINFO                                                                 STD_ON
#define IPDUM_TXUPINDIDXOFTXUPINFO                                                                  STD_ON
#define IPDUM_TXUPINDOFTXUPINFO                                                                     STD_ON
#define IPDUM_VCONTAINERRXQUEUEINFO                                                                 STD_OFF  /**< Deactivateable: 'IpduM_VContainerRxQueueInfo' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' */
#define IPDUM_CONTAINERRXQUEUEINSTANCEREADIDXOFCONTAINERRXQUEUEINFO                                 STD_OFF  /**< Deactivateable: 'IpduM_VContainerRxQueueInfo.ContainerRxQueueInstanceReadIdx' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' */
#define IPDUM_CONTAINERRXQUEUEINSTANCEWRITEIDXOFCONTAINERRXQUEUEINFO                                STD_OFF  /**< Deactivateable: 'IpduM_VContainerRxQueueInfo.ContainerRxQueueInstanceWriteIdx' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' */
#define IPDUM_READCOUNTOFCONTAINERRXQUEUEINFO                                                       STD_OFF  /**< Deactivateable: 'IpduM_VContainerRxQueueInfo.ReadCount' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' */
#define IPDUM_WRITECOUNTOFCONTAINERRXQUEUEINFO                                                      STD_OFF  /**< Deactivateable: 'IpduM_VContainerRxQueueInfo.WriteCount' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' */
#define IPDUM_VCONTAINERRXQUEUEINSTANCE                                                             STD_OFF  /**< Deactivateable: 'IpduM_VContainerRxQueueInstance' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' */
#define IPDUM_RECEIVEDSIZEOFCONTAINERRXQUEUEINSTANCE                                                STD_OFF  /**< Deactivateable: 'IpduM_VContainerRxQueueInstance.ReceivedSize' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' */
#define IPDUM_VCONTAINERTXCONFIRMATIONBUFFERINFO                                                    STD_OFF  /**< Deactivateable: 'IpduM_VContainerTxConfirmationBufferInfo' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' */
#define IPDUM_CONTAINERTXCONFIRMATIONBUFFERREADIDXOFCONTAINERTXCONFIRMATIONBUFFERINFO               STD_OFF  /**< Deactivateable: 'IpduM_VContainerTxConfirmationBufferInfo.ContainerTxConfirmationBufferReadIdx' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' */
#define IPDUM_CONTAINERTXCONFIRMATIONBUFFERWRITEIDXOFCONTAINERTXCONFIRMATIONBUFFERINFO              STD_OFF  /**< Deactivateable: 'IpduM_VContainerTxConfirmationBufferInfo.ContainerTxConfirmationBufferWriteIdx' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' */
#define IPDUM_VDATAQUEUEINFO                                                                        STD_OFF  /**< Deactivateable: 'IpduM_VDataQueueInfo' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' */
#define IPDUM_DATAQUEUEINSTANCEREADIDXOFDATAQUEUEINFO                                               STD_OFF  /**< Deactivateable: 'IpduM_VDataQueueInfo.DataQueueInstanceReadIdx' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' */
#define IPDUM_DATAQUEUEINSTANCEWRITEIDXOFDATAQUEUEINFO                                              STD_OFF  /**< Deactivateable: 'IpduM_VDataQueueInfo.DataQueueInstanceWriteIdx' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' */
#define IPDUM_READCOUNTOFDATAQUEUEINFO                                                              STD_OFF  /**< Deactivateable: 'IpduM_VDataQueueInfo.ReadCount' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' */
#define IPDUM_WRITECOUNTOFDATAQUEUEINFO                                                             STD_OFF  /**< Deactivateable: 'IpduM_VDataQueueInfo.WriteCount' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' */
#define IPDUM_VDATAQUEUEINSTANCE                                                                    STD_OFF  /**< Deactivateable: 'IpduM_VDataQueueInstance' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' */
#define IPDUM_DATAQUEUEIDBUFFERWRITEIDXOFDATAQUEUEINSTANCE                                          STD_OFF  /**< Deactivateable: 'IpduM_VDataQueueInstance.DataQueueIdBufferWriteIdx' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' */
#define IPDUM_FILLCOUNTOFDATAQUEUEINSTANCE                                                          STD_OFF  /**< Deactivateable: 'IpduM_VDataQueueInstance.FillCount' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' */
#define IPDUM_VREQUESTQUEUEINFO                                                                     STD_OFF  /**< Deactivateable: 'IpduM_VRequestQueueInfo' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' */
#define IPDUM_READIDXOFREQUESTQUEUEINFO                                                             STD_OFF  /**< Deactivateable: 'IpduM_VRequestQueueInfo.ReadIdx' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' */
#define IPDUM_READTMPIDXOFREQUESTQUEUEINFO                                                          STD_OFF  /**< Deactivateable: 'IpduM_VRequestQueueInfo.ReadTmpIdx' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' */
#define IPDUM_WRITEIDXOFREQUESTQUEUEINFO                                                            STD_OFF  /**< Deactivateable: 'IpduM_VRequestQueueInfo.WriteIdx' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' */
#define IPDUM_VTXCONTAINERPDU                                                                       STD_OFF  /**< Deactivateable: 'IpduM_VTxContainerPdu' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' */
#define IPDUM_CONTAINERPDUSENDTIMEOUTOFTXCONTAINERPDU                                               STD_OFF  /**< Deactivateable: 'IpduM_VTxContainerPdu.ContainerPduSendTimeout' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' */
#define IPDUM_FIRSTCONTAINEDPDUOFTXCONTAINERPDU                                                     STD_OFF  /**< Deactivateable: 'IpduM_VTxContainerPdu.FirstContainedPdu' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' */
#define IPDUM_VTXLOINFO                                                                             STD_ON
#define IPDUM_TXCONFTIMEOUTCNTOFVTXLOINFO                                                           STD_ON
#define IPDUM_VTXPATHWAY                                                                            STD_ON
#define IPDUM_TXPARTDYNAMICPARTIDXOFTXPATHWAY                                                       STD_ON
#define IPDUM_PCCONFIG                                                                              STD_ON
#define IPDUM_CTXLOINFOOFPCCONFIG                                                                   STD_ON
#define IPDUM_CTXPATHWAYOFPCCONFIG                                                                  STD_ON
#define IPDUM_FINALMAGICNUMBEROFPCCONFIG                                                            STD_OFF  /**< Deactivateable: 'IpduM_PCConfig.FinalMagicNumber' Reason: 'the module configuration does not support flashing of data.' */
#define IPDUM_INITDATAHASHCODEOFPCCONFIG                                                            STD_OFF  /**< Deactivateable: 'IpduM_PCConfig.InitDataHashCode' Reason: 'the module configuration does not support flashing of data.' */
#define IPDUM_INITIALIZEDOFPCCONFIG                                                                 STD_ON
#define IPDUM_JITUPDATEBUFFEROFPCCONFIG                                                             STD_ON
#define IPDUM_MAINFUNCTIONTXINDIRECTIONOFPCCONFIG                                                   STD_ON
#define IPDUM_SEGMENTOFPCCONFIG                                                                     STD_ON
#define IPDUM_SIZEOFCTXLOINFOOFPCCONFIG                                                             STD_ON
#define IPDUM_SIZEOFCTXPATHWAYOFPCCONFIG                                                            STD_ON
#define IPDUM_SIZEOFJITUPDATEBUFFEROFPCCONFIG                                                       STD_ON
#define IPDUM_SIZEOFMAINFUNCTIONTXINDIRECTIONOFPCCONFIG                                             STD_ON
#define IPDUM_SIZEOFSEGMENTOFPCCONFIG                                                               STD_ON
#define IPDUM_SIZEOFTRIGGERTRANSMITBUFFEROFPCCONFIG                                                 STD_ON
#define IPDUM_SIZEOFTXBUFFEROFPCCONFIG                                                              STD_ON
#define IPDUM_SIZEOFTXINITVALUESOFPCCONFIG                                                          STD_ON
#define IPDUM_SIZEOFTXLOINFOINDOFPCCONFIG                                                           STD_ON
#define IPDUM_SIZEOFTXLOINFOWITHINVALIDINDEXESOFPCCONFIG                                            STD_ON
#define IPDUM_SIZEOFTXPARTINDOFPCCONFIG                                                             STD_ON
#define IPDUM_SIZEOFTXPARTOFPCCONFIG                                                                STD_ON
#define IPDUM_SIZEOFTXUPINFOOFPCCONFIG                                                              STD_ON
#define IPDUM_SIZEOFVTXLOINFOOFPCCONFIG                                                             STD_ON
#define IPDUM_SIZEOFVTXPATHWAYOFPCCONFIG                                                            STD_ON
#define IPDUM_TRIGGERTRANSMITBUFFEROFPCCONFIG                                                       STD_ON
#define IPDUM_TXBUFFEROFPCCONFIG                                                                    STD_ON
#define IPDUM_TXINITVALUESOFPCCONFIG                                                                STD_ON
#define IPDUM_TXLOINFOINDOFPCCONFIG                                                                 STD_ON
#define IPDUM_TXLOINFOWITHINVALIDINDEXESOFPCCONFIG                                                  STD_ON
#define IPDUM_TXPARTINDOFPCCONFIG                                                                   STD_ON
#define IPDUM_TXPARTOFPCCONFIG                                                                      STD_ON
#define IPDUM_TXUPINFOOFPCCONFIG                                                                    STD_ON
#define IPDUM_VTXLOINFOOFPCCONFIG                                                                   STD_ON
#define IPDUM_VTXPATHWAYOFPCCONFIG                                                                  STD_ON
/** 
  \}
*/ 

/** 
  \defgroup  IpduMPCMinNumericValueDefines  IpduM Min Numeric Value Defines (PRE_COMPILE)
  \brief  These defines are used to implement against the minimum value in numerical based data.
  \{
*/ 
#define IPDUM_MIN_JITUPDATEBUFFER                                                                   0u
#define IPDUM_MIN_TRIGGERTRANSMITBUFFER                                                             0u
#define IPDUM_MIN_TXBUFFER                                                                          0u
#define IPDUM_MIN_TXCONFTIMEOUTCNTOFVTXLOINFO                                                       0u
#define IPDUM_MIN_TXPARTDYNAMICPARTIDXOFTXPATHWAY                                                   0u
/** 
  \}
*/ 

/** 
  \defgroup  IpduMPCMaxNumericValueDefines  IpduM Max Numeric Value Defines (PRE_COMPILE)
  \brief  These defines are used to implement against the maximum value in numerical based data.
  \{
*/ 
#define IPDUM_MAX_JITUPDATEBUFFER                                                                   255u
#define IPDUM_MAX_TRIGGERTRANSMITBUFFER                                                             255u
#define IPDUM_MAX_TXBUFFER                                                                          255u
#define IPDUM_MAX_TXCONFTIMEOUTCNTOFVTXLOINFO                                                       255u
#define IPDUM_MAX_TXPARTDYNAMICPARTIDXOFTXPATHWAY                                                   255u
/** 
  \}
*/ 

/** 
  \defgroup  IpduMPCNoReferenceDefines  IpduM No Reference Defines (PRE_COMPILE)
  \brief  These defines are used to indicate unused indexes in data relations.
  \{
*/ 
#define IPDUM_NO_TXPATHWAYIDXOFCTXLOINFO                                                            255u
#define IPDUM_NO_TXLOINFOIDXOFTXPATHWAY                                                             255u
#define IPDUM_NO_TXPARTSTATICPARTIDXOFTXPATHWAY                                                     255u
#define IPDUM_NO_TXSTATICPDUREFOFTXPATHWAY                                                          255u
#define IPDUM_NO_TXLOINFOINDENDIDXOFMAINFUNCTIONTXINDIRECTION                                       255u
#define IPDUM_NO_TXLOINFOINDSTARTIDXOFMAINFUNCTIONTXINDIRECTION                                     255u
/** 
  \}
*/ 

/** 
  \defgroup  IpduMPCEnumExistsDefines  IpduM Enum Exists Defines (PRE_COMPILE)
  \brief  These defines can be used to deactivate enumeration based code sequences if the enumeration value does not exist in the configuration data.
  \{
*/ 
#define IPDUM_EXISTS_QUEUED_CONTAINERTYPEOFTXCONTAINERPDU                                           STD_OFF  /**< Deactivateable: 'IpduM_CTxContainerPdu.ContainerType' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define IPDUM_EXISTS_LAST_IS_BEST_CONTAINERTYPEOFTXCONTAINERPDU                                     STD_OFF  /**< Deactivateable: 'IpduM_CTxContainerPdu.ContainerType' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define IPDUM_EXISTS_LONG_HEADERSIZEOFTXCONTAINERPDU                                                STD_OFF  /**< Deactivateable: 'IpduM_CTxContainerPdu.HeaderSize' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define IPDUM_EXISTS_SHORT_HEADERSIZEOFTXCONTAINERPDU                                               STD_OFF  /**< Deactivateable: 'IpduM_CTxContainerPdu.HeaderSize' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define IPDUM_EXISTS_NONE_HEADERSIZEOFTXCONTAINERPDU                                                STD_OFF  /**< Deactivateable: 'IpduM_CTxContainerPdu.HeaderSize' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define IPDUM_EXISTS_MUX_PATHWAYTYPEOFCTXLOINFO                                                     STD_ON
#define IPDUM_EXISTS_CONTAINER_PATHWAYTYPEOFCTXLOINFO                                               STD_OFF
#define IPDUM_EXISTS_LONG_HEADERSIZEOFRXCONTAINERPDU                                                STD_OFF  /**< Deactivateable: 'IpduM_RxContainerPdu.HeaderSize' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define IPDUM_EXISTS_SHORT_HEADERSIZEOFRXCONTAINERPDU                                               STD_OFF  /**< Deactivateable: 'IpduM_RxContainerPdu.HeaderSize' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define IPDUM_EXISTS_NONE_HEADERSIZEOFRXCONTAINERPDU                                                STD_OFF  /**< Deactivateable: 'IpduM_RxContainerPdu.HeaderSize' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define IPDUM_EXISTS_MUX_PATHWAYTYPEOFRXINFO                                                        STD_OFF  /**< Deactivateable: 'IpduM_RxInfo.PathwayType' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define IPDUM_EXISTS_CONTAINER_PATHWAYTYPEOFRXINFO                                                  STD_OFF  /**< Deactivateable: 'IpduM_RxInfo.PathwayType' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define IPDUM_EXISTS_RXMUXPDU_RXPATHWAYINDOFRXINFO                                                  STD_OFF  /**< Deactivateable: 'IpduM_RxInfo.RxPathwayInd' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define IPDUM_EXISTS_RXCONTAINERPDU_RXPATHWAYINDOFRXINFO                                            STD_OFF  /**< Deactivateable: 'IpduM_RxInfo.RxPathwayInd' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define IPDUM_EXISTS_MUX_PATHWAYTYPEOFTXUPINFO                                                      STD_ON
#define IPDUM_EXISTS_CONTAINER_PATHWAYTYPEOFTXUPINFO                                                STD_OFF
#define IPDUM_EXISTS_TXPART_TXUPINDOFTXUPINFO                                                       STD_ON
#define IPDUM_EXISTS_TXCONTAINEDPDU_TXUPINDOFTXUPINFO                                               STD_OFF
/** 
  \}
*/ 

/** 
  \defgroup  IpduMPCEnumDefines  IpduM Enum Defines (PRE_COMPILE)
  \brief  These defines are the enumeration values of enumeration based CONST and VAR data.
  \{
*/ 
#define IPDUM_MUX_PATHWAYTYPEOFCTXLOINFO                                                            0x00u
#define IPDUM_MUX_PATHWAYTYPEOFTXUPINFO                                                             0x00u
#define IPDUM_TXPART_TXUPINDOFTXUPINFO                                                              0x00u
/** 
  \}
*/ 

/** 
  \defgroup  IpduMPCIsReducedToDefineDefines  IpduM Is Reduced To Define Defines (PRE_COMPILE)
  \brief  If all values in a CONST array or an element in a CONST array of structs are equal, the define is STD_ON else STD_OFF.
  \{
*/ 
#define IPDUM_ISDEF_PATHWAYTYPEOFCTXLOINFO                                                          STD_OFF
#define IPDUM_ISDEF_TXPATHWAYIDXOFCTXLOINFO                                                         STD_OFF
#define IPDUM_ISDEF_TXPATHWAYUSEDOFCTXLOINFO                                                        STD_OFF
#define IPDUM_ISDEF_JITUPDATEBUFFERENDIDXOFTXPATHWAY                                                STD_OFF
#define IPDUM_ISDEF_JITUPDATEBUFFERLENGTHOFTXPATHWAY                                                STD_OFF
#define IPDUM_ISDEF_JITUPDATEBUFFERSTARTIDXOFTXPATHWAY                                              STD_OFF
#define IPDUM_ISDEF_LLPDUREFOFTXPATHWAY                                                             STD_OFF
#define IPDUM_ISDEF_TRIGGERTRANSMITBUFFERENDIDXOFTXPATHWAY                                          STD_OFF
#define IPDUM_ISDEF_TRIGGERTRANSMITBUFFERLENGTHOFTXPATHWAY                                          STD_OFF
#define IPDUM_ISDEF_TRIGGERTRANSMITBUFFERSTARTIDXOFTXPATHWAY                                        STD_OFF
#define IPDUM_ISDEF_TXBUFFERENDIDXOFTXPATHWAY                                                       STD_OFF
#define IPDUM_ISDEF_TXBUFFERLENGTHOFTXPATHWAY                                                       STD_OFF
#define IPDUM_ISDEF_TXBUFFERSTARTIDXOFTXPATHWAY                                                     STD_OFF
#define IPDUM_ISDEF_TXLOINFOIDXOFTXPATHWAY                                                          STD_OFF
#define IPDUM_ISDEF_TXLOINFOUSEDOFTXPATHWAY                                                         STD_OFF
#define IPDUM_ISDEF_TXPARTINDENDIDXOFTXPATHWAY                                                      STD_OFF
#define IPDUM_ISDEF_TXPARTINDSTARTIDXOFTXPATHWAY                                                    STD_OFF
#define IPDUM_ISDEF_TXPARTINITIALDYNPARTIDXOFTXPATHWAY                                              STD_OFF
#define IPDUM_ISDEF_TXPARTSTATICPARTIDXOFTXPATHWAY                                                  STD_OFF
#define IPDUM_ISDEF_TXPARTSTATICPARTUSEDOFTXPATHWAY                                                 STD_OFF
#define IPDUM_ISDEF_TXSTATICPDUREFOFTXPATHWAY                                                       STD_OFF
#define IPDUM_ISDEF_TXSTATICPDUREFUSEDOFTXPATHWAY                                                   STD_OFF
#define IPDUM_ISDEF_UNUSEDAREASDEFAULTOFTXPATHWAY                                                   STD_OFF
#define IPDUM_ISDEF_TXLOINFOINDENDIDXOFMAINFUNCTIONTXINDIRECTION                                    STD_OFF
#define IPDUM_ISDEF_TXLOINFOINDSTARTIDXOFMAINFUNCTIONTXINDIRECTION                                  STD_OFF
#define IPDUM_ISDEF_TXLOINFOINDUSEDOFMAINFUNCTIONTXINDIRECTION                                      STD_OFF
#define IPDUM_ISDEF_BITINBYTEPOSOFSEGMENT                                                           STD_OFF
#define IPDUM_ISDEF_ENDBYTEMASKCLEAROFSEGMENT                                                       STD_OFF
#define IPDUM_ISDEF_ENDBYTEMASKWRITEOFSEGMENT                                                       STD_OFF
#define IPDUM_ISDEF_FIRSTBYTEPOSOFSEGMENT                                                           STD_OFF
#define IPDUM_ISDEF_FIRSTFULLBYTEPOSOFSEGMENT                                                       STD_OFF
#define IPDUM_ISDEF_FULLBYTESPRESENTOFSEGMENT                                                       STD_OFF
#define IPDUM_ISDEF_LASTBYTEPOSOFSEGMENT                                                            STD_OFF
#define IPDUM_ISDEF_LASTFULLBYTEPOSOFSEGMENT                                                        STD_OFF
#define IPDUM_ISDEF_LENGTHOFSEGMENT                                                                 STD_OFF
#define IPDUM_ISDEF_PDUBYTEPOSOFSEGMENT                                                             STD_OFF
#define IPDUM_ISDEF_STARTBYTEMASKCLEAROFSEGMENT                                                     STD_OFF
#define IPDUM_ISDEF_STARTBYTEMASKWRITEOFSEGMENT                                                     STD_OFF
#define IPDUM_ISDEF_TXINITVALUES                                                                    STD_OFF
#define IPDUM_ISDEF_TXLOINFOIND                                                                     STD_OFF
#define IPDUM_ISDEF_CTXLOINFOIDXOFTXLOINFOWITHINVALIDINDEXES                                        STD_OFF
#define IPDUM_ISDEF_SEGMENTENDIDXOFTXPART                                                           STD_OFF
#define IPDUM_ISDEF_SEGMENTSTARTIDXOFTXPART                                                         STD_OFF
#define IPDUM_ISDEF_TRIGGEREVENTOFTXPART                                                            STD_OFF
#define IPDUM_ISDEF_TXPATHWAYIDXOFTXPART                                                            STD_OFF
#define IPDUM_ISDEF_ULPDUREFOFTXPART                                                                STD_OFF
#define IPDUM_ISDEF_TXPARTIND                                                                       STD_OFF
#define IPDUM_ISDEF_PATHWAYTYPEOFTXUPINFO                                                           STD_OFF
#define IPDUM_ISDEF_TXUPINDIDXOFTXUPINFO                                                            STD_OFF
#define IPDUM_ISDEF_TXUPINDOFTXUPINFO                                                               STD_OFF
#define IPDUM_ISDEF_CTXLOINFOOFPCCONFIG                                                             STD_ON
#define IPDUM_ISDEF_CTXPATHWAYOFPCCONFIG                                                            STD_ON
#define IPDUM_ISDEF_INITIALIZEDOFPCCONFIG                                                           STD_ON
#define IPDUM_ISDEF_JITUPDATEBUFFEROFPCCONFIG                                                       STD_ON
#define IPDUM_ISDEF_MAINFUNCTIONTXINDIRECTIONOFPCCONFIG                                             STD_ON
#define IPDUM_ISDEF_SEGMENTOFPCCONFIG                                                               STD_ON
#define IPDUM_ISDEF_TRIGGERTRANSMITBUFFEROFPCCONFIG                                                 STD_ON
#define IPDUM_ISDEF_TXBUFFEROFPCCONFIG                                                              STD_ON
#define IPDUM_ISDEF_TXINITVALUESOFPCCONFIG                                                          STD_ON
#define IPDUM_ISDEF_TXLOINFOINDOFPCCONFIG                                                           STD_ON
#define IPDUM_ISDEF_TXLOINFOWITHINVALIDINDEXESOFPCCONFIG                                            STD_ON
#define IPDUM_ISDEF_TXPARTINDOFPCCONFIG                                                             STD_ON
#define IPDUM_ISDEF_TXPARTOFPCCONFIG                                                                STD_ON
#define IPDUM_ISDEF_TXUPINFOOFPCCONFIG                                                              STD_ON
#define IPDUM_ISDEF_VTXLOINFOOFPCCONFIG                                                             STD_ON
#define IPDUM_ISDEF_VTXPATHWAYOFPCCONFIG                                                            STD_ON
/** 
  \}
*/ 

/** 
  \defgroup  IpduMPCEqualsAlwaysToDefines  IpduM Equals Always To Defines (PRE_COMPILE)
  \brief  If all values in a CONST array or an element in a CONST array of structs are equal, the define contains the always equals value.
  \{
*/ 
#define IPDUM_EQ2_PATHWAYTYPEOFCTXLOINFO                                                            
#define IPDUM_EQ2_TXPATHWAYIDXOFCTXLOINFO                                                           
#define IPDUM_EQ2_TXPATHWAYUSEDOFCTXLOINFO                                                          
#define IPDUM_EQ2_JITUPDATEBUFFERENDIDXOFTXPATHWAY                                                  
#define IPDUM_EQ2_JITUPDATEBUFFERLENGTHOFTXPATHWAY                                                  
#define IPDUM_EQ2_JITUPDATEBUFFERSTARTIDXOFTXPATHWAY                                                
#define IPDUM_EQ2_LLPDUREFOFTXPATHWAY                                                               
#define IPDUM_EQ2_TRIGGERTRANSMITBUFFERENDIDXOFTXPATHWAY                                            
#define IPDUM_EQ2_TRIGGERTRANSMITBUFFERLENGTHOFTXPATHWAY                                            
#define IPDUM_EQ2_TRIGGERTRANSMITBUFFERSTARTIDXOFTXPATHWAY                                          
#define IPDUM_EQ2_TXBUFFERENDIDXOFTXPATHWAY                                                         
#define IPDUM_EQ2_TXBUFFERLENGTHOFTXPATHWAY                                                         
#define IPDUM_EQ2_TXBUFFERSTARTIDXOFTXPATHWAY                                                       
#define IPDUM_EQ2_TXLOINFOIDXOFTXPATHWAY                                                            
#define IPDUM_EQ2_TXLOINFOUSEDOFTXPATHWAY                                                           
#define IPDUM_EQ2_TXPARTINDENDIDXOFTXPATHWAY                                                        
#define IPDUM_EQ2_TXPARTINDSTARTIDXOFTXPATHWAY                                                      
#define IPDUM_EQ2_TXPARTINITIALDYNPARTIDXOFTXPATHWAY                                                
#define IPDUM_EQ2_TXPARTSTATICPARTIDXOFTXPATHWAY                                                    
#define IPDUM_EQ2_TXPARTSTATICPARTUSEDOFTXPATHWAY                                                   
#define IPDUM_EQ2_TXSTATICPDUREFOFTXPATHWAY                                                         
#define IPDUM_EQ2_TXSTATICPDUREFUSEDOFTXPATHWAY                                                     
#define IPDUM_EQ2_UNUSEDAREASDEFAULTOFTXPATHWAY                                                     
#define IPDUM_EQ2_TXLOINFOINDENDIDXOFMAINFUNCTIONTXINDIRECTION                                      
#define IPDUM_EQ2_TXLOINFOINDSTARTIDXOFMAINFUNCTIONTXINDIRECTION                                    
#define IPDUM_EQ2_TXLOINFOINDUSEDOFMAINFUNCTIONTXINDIRECTION                                        
#define IPDUM_EQ2_BITINBYTEPOSOFSEGMENT                                                             
#define IPDUM_EQ2_ENDBYTEMASKCLEAROFSEGMENT                                                         
#define IPDUM_EQ2_ENDBYTEMASKWRITEOFSEGMENT                                                         
#define IPDUM_EQ2_FIRSTBYTEPOSOFSEGMENT                                                             
#define IPDUM_EQ2_FIRSTFULLBYTEPOSOFSEGMENT                                                         
#define IPDUM_EQ2_FULLBYTESPRESENTOFSEGMENT                                                         
#define IPDUM_EQ2_LASTBYTEPOSOFSEGMENT                                                              
#define IPDUM_EQ2_LASTFULLBYTEPOSOFSEGMENT                                                          
#define IPDUM_EQ2_LENGTHOFSEGMENT                                                                   
#define IPDUM_EQ2_PDUBYTEPOSOFSEGMENT                                                               
#define IPDUM_EQ2_STARTBYTEMASKCLEAROFSEGMENT                                                       
#define IPDUM_EQ2_STARTBYTEMASKWRITEOFSEGMENT                                                       
#define IPDUM_EQ2_TXINITVALUES                                                                      
#define IPDUM_EQ2_TXLOINFOIND                                                                       
#define IPDUM_EQ2_CTXLOINFOIDXOFTXLOINFOWITHINVALIDINDEXES                                          
#define IPDUM_EQ2_SEGMENTENDIDXOFTXPART                                                             
#define IPDUM_EQ2_SEGMENTSTARTIDXOFTXPART                                                           
#define IPDUM_EQ2_TRIGGEREVENTOFTXPART                                                              
#define IPDUM_EQ2_TXPATHWAYIDXOFTXPART                                                              
#define IPDUM_EQ2_ULPDUREFOFTXPART                                                                  
#define IPDUM_EQ2_TXPARTIND                                                                         
#define IPDUM_EQ2_PATHWAYTYPEOFTXUPINFO                                                             
#define IPDUM_EQ2_TXUPINDIDXOFTXUPINFO                                                              
#define IPDUM_EQ2_TXUPINDOFTXUPINFO                                                                 
#define IPDUM_EQ2_CTXLOINFOOFPCCONFIG                                                               IpduM_CTxLoInfo
#define IPDUM_EQ2_CTXPATHWAYOFPCCONFIG                                                              IpduM_CTxPathway
#define IPDUM_EQ2_INITIALIZEDOFPCCONFIG                                                             (&(IpduM_Initialized))
#define IPDUM_EQ2_JITUPDATEBUFFEROFPCCONFIG                                                         IpduM_JitUpdateBuffer.raw
#define IPDUM_EQ2_MAINFUNCTIONTXINDIRECTIONOFPCCONFIG                                               IpduM_MainFunctionTxIndirection
#define IPDUM_EQ2_SEGMENTOFPCCONFIG                                                                 IpduM_Segment
#define IPDUM_EQ2_TRIGGERTRANSMITBUFFEROFPCCONFIG                                                   IpduM_TriggerTransmitBuffer.raw
#define IPDUM_EQ2_TXBUFFEROFPCCONFIG                                                                IpduM_TxBuffer.raw
#define IPDUM_EQ2_TXINITVALUESOFPCCONFIG                                                            IpduM_TxInitValues
#define IPDUM_EQ2_TXLOINFOINDOFPCCONFIG                                                             IpduM_TxLoInfoInd
#define IPDUM_EQ2_TXLOINFOWITHINVALIDINDEXESOFPCCONFIG                                              IpduM_TxLoInfoWithInvalidIndexes
#define IPDUM_EQ2_TXPARTINDOFPCCONFIG                                                               IpduM_TxPartInd
#define IPDUM_EQ2_TXPARTOFPCCONFIG                                                                  IpduM_TxPart
#define IPDUM_EQ2_TXUPINFOOFPCCONFIG                                                                IpduM_TxUpInfo
#define IPDUM_EQ2_VTXLOINFOOFPCCONFIG                                                               IpduM_VTxLoInfo
#define IPDUM_EQ2_VTXPATHWAYOFPCCONFIG                                                              IpduM_VTxPathway.raw
/** 
  \}
*/ 

/** 
  \defgroup  IpduMPCSymbolicInitializationPointers  IpduM Symbolic Initialization Pointers (PRE_COMPILE)
  \brief  Symbolic initialization pointers to be used in the call of a preinit or init function.
  \{
*/ 
#define IpduM_Config_Ptr                                                                            NULL_PTR  /**< symbolic identifier which shall be used to initialize 'IpduM' */
/** 
  \}
*/ 

/** 
  \defgroup  IpduMPCInitializationSymbols  IpduM Initialization Symbols (PRE_COMPILE)
  \brief  Symbolic initialization pointers which may be used in the call of a preinit or init function. Please note, that the defined value can be a 'NULL_PTR' and the address operator is not usable.
  \{
*/ 
#define IpduM_Config                                                                                NULL_PTR  /**< symbolic identifier which could be used to initialize 'IpduM */
/** 
  \}
*/ 

/** 
  \defgroup  IpduMPCGeneral  IpduM General (PRE_COMPILE)
  \brief  General constant defines not associated with a group of defines.
  \{
*/ 
#define IPDUM_CHECK_INIT_POINTER                                                                    STD_OFF  /**< STD_ON if the init pointer shall not be used as NULL_PTR and a check shall validate this. */
#define IPDUM_FINAL_MAGIC_NUMBER                                                                    0x341Eu  /**< the precompile constant to validate the size of the initialization structure at initialization time of IpduM */
#define IPDUM_INDIVIDUAL_POSTBUILD                                                                  STD_OFF  /**< the precompile constant to check, that the module is individual postbuildable. The module 'IpduM' is not configured to be postbuild capable. */
#define IPDUM_INIT_DATA                                                                             IPDUM_CONST  /**< CompilerMemClassDefine for the initialization data. */
#define IPDUM_INIT_DATA_HASH_CODE                                                                   966437021  /**< the precompile constant to validate the initialization structure at initialization time of IpduM with a hashcode. The seed value is '0x341Eu' */
#define IPDUM_USE_ECUM_BSW_ERROR_HOOK                                                               STD_OFF  /**< STD_ON if the EcuM_BswErrorHook shall be called in the ConfigPtr check. */
#define IPDUM_USE_INIT_POINTER                                                                      STD_OFF  /**< STD_ON if the init pointer IpduM shall be used. */
/** 
  \}
*/ 


/**********************************************************************************************************************
  CONFIGURATION CLASS: LINK
  SECTION: GLOBAL CONSTANT MACROS
**********************************************************************************************************************/
/** 
  \defgroup  IpduMLTDataSwitches  IpduM Data Switches  (LINK)
  \brief  These defines are used to deactivate data and their processing.
  \{
*/ 
#define IPDUM_LTCONFIG                                                                              STD_OFF  /**< Deactivateable: 'IpduM_LTConfig' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' */
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
  \defgroup  IpduMPCGetConstantDuplicatedRootDataMacros  IpduM Get Constant Duplicated Root Data Macros (PRE_COMPILE)
  \brief  These macros can be used to read deduplicated by constance root data elements.
  \{
*/ 
#define IpduM_GetCTxLoInfoOfPCConfig()                                                              IpduM_CTxLoInfo  /**< the pointer to IpduM_CTxLoInfo */
#define IpduM_GetCTxPathwayOfPCConfig()                                                             IpduM_CTxPathway  /**< the pointer to IpduM_CTxPathway */
#define IpduM_GetInitializedOfPCConfig()                                                            (&(IpduM_Initialized))  /**< the pointer to IpduM_Initialized */
#define IpduM_GetJitUpdateBufferOfPCConfig()                                                        IpduM_JitUpdateBuffer.raw  /**< the pointer to IpduM_JitUpdateBuffer */
#define IpduM_GetMainFunctionTxIndirectionOfPCConfig()                                              IpduM_MainFunctionTxIndirection  /**< the pointer to IpduM_MainFunctionTxIndirection */
#define IpduM_GetSegmentOfPCConfig()                                                                IpduM_Segment  /**< the pointer to IpduM_Segment */
#define IpduM_GetSizeOfCTxLoInfoOfPCConfig()                                                        1u  /**< the number of accomplishable value elements in IpduM_CTxLoInfo */
#define IpduM_GetSizeOfCTxPathwayOfPCConfig()                                                       1u  /**< the number of accomplishable value elements in IpduM_CTxPathway */
#define IpduM_GetSizeOfJitUpdateBufferOfPCConfig()                                                  32u  /**< the number of accomplishable value elements in IpduM_JitUpdateBuffer */
#define IpduM_GetSizeOfMainFunctionTxIndirectionOfPCConfig()                                        1u  /**< the number of accomplishable value elements in IpduM_MainFunctionTxIndirection */
#define IpduM_GetSizeOfSegmentOfPCConfig()                                                          3u  /**< the number of accomplishable value elements in IpduM_Segment */
#define IpduM_GetSizeOfTriggerTransmitBufferOfPCConfig()                                            32u  /**< the number of accomplishable value elements in IpduM_TriggerTransmitBuffer */
#define IpduM_GetSizeOfTxBufferOfPCConfig()                                                         32u  /**< the number of accomplishable value elements in IpduM_TxBuffer */
#define IpduM_GetSizeOfTxInitValuesOfPCConfig()                                                     32u  /**< the number of accomplishable value elements in IpduM_TxInitValues */
#define IpduM_GetSizeOfTxLoInfoIndOfPCConfig()                                                      1u  /**< the number of accomplishable value elements in IpduM_TxLoInfoInd */
#define IpduM_GetSizeOfTxLoInfoWithInvalidIndexesOfPCConfig()                                       1u  /**< the number of accomplishable value elements in IpduM_TxLoInfoWithInvalidIndexes */
#define IpduM_GetSizeOfTxPartIndOfPCConfig()                                                        3u  /**< the number of accomplishable value elements in IpduM_TxPartInd */
#define IpduM_GetSizeOfTxPartOfPCConfig()                                                           4u  /**< the number of accomplishable value elements in IpduM_TxPart */
#define IpduM_GetSizeOfTxUpInfoOfPCConfig()                                                         4u  /**< the number of accomplishable value elements in IpduM_TxUpInfo */
#define IpduM_GetTriggerTransmitBufferOfPCConfig()                                                  IpduM_TriggerTransmitBuffer.raw  /**< the pointer to IpduM_TriggerTransmitBuffer */
#define IpduM_GetTxBufferOfPCConfig()                                                               IpduM_TxBuffer.raw  /**< the pointer to IpduM_TxBuffer */
#define IpduM_GetTxInitValuesOfPCConfig()                                                           IpduM_TxInitValues  /**< the pointer to IpduM_TxInitValues */
#define IpduM_GetTxLoInfoIndOfPCConfig()                                                            IpduM_TxLoInfoInd  /**< the pointer to IpduM_TxLoInfoInd */
#define IpduM_GetTxLoInfoWithInvalidIndexesOfPCConfig()                                             IpduM_TxLoInfoWithInvalidIndexes  /**< the pointer to IpduM_TxLoInfoWithInvalidIndexes */
#define IpduM_GetTxPartIndOfPCConfig()                                                              IpduM_TxPartInd  /**< the pointer to IpduM_TxPartInd */
#define IpduM_GetTxPartOfPCConfig()                                                                 IpduM_TxPart  /**< the pointer to IpduM_TxPart */
#define IpduM_GetTxUpInfoOfPCConfig()                                                               IpduM_TxUpInfo  /**< the pointer to IpduM_TxUpInfo */
#define IpduM_GetVTxLoInfoOfPCConfig()                                                              IpduM_VTxLoInfo  /**< the pointer to IpduM_VTxLoInfo */
#define IpduM_GetVTxPathwayOfPCConfig()                                                             IpduM_VTxPathway.raw  /**< the pointer to IpduM_VTxPathway */
/** 
  \}
*/ 

/** 
  \defgroup  IpduMPCGetDuplicatedRootDataMacros  IpduM Get Duplicated Root Data Macros (PRE_COMPILE)
  \brief  These macros can be used to read deduplicated root data elements.
  \{
*/ 
#define IpduM_GetSizeOfVTxLoInfoOfPCConfig()                                                        IpduM_GetSizeOfCTxLoInfoOfPCConfig()  /**< the number of accomplishable value elements in IpduM_VTxLoInfo */
#define IpduM_GetSizeOfVTxPathwayOfPCConfig()                                                       IpduM_GetSizeOfCTxPathwayOfPCConfig()  /**< the number of accomplishable value elements in IpduM_VTxPathway */
/** 
  \}
*/ 

/** 
  \defgroup  IpduMPCGetDataMacros  IpduM Get Data Macros (PRE_COMPILE)
  \brief  These macros can be used to read CONST and VAR data.
  \{
*/ 
#define IpduM_GetTxPathwayIdxOfCTxLoInfo(Index)                                                     (IpduM_GetCTxLoInfoOfPCConfig()[(Index)].TxPathwayIdxOfCTxLoInfo)
#define IpduM_GetTxLoInfoIdxOfTxPathway(Index)                                                      (IpduM_GetCTxPathwayOfPCConfig()[(Index)].TxLoInfoIdxOfTxPathway)
#define IpduM_GetTxPartStaticPartIdxOfTxPathway(Index)                                              (IpduM_GetCTxPathwayOfPCConfig()[(Index)].TxPartStaticPartIdxOfTxPathway)
#define IpduM_IsTxStaticPduRefUsedOfTxPathway(Index)                                                ((IpduM_GetCTxPathwayOfPCConfig()[(Index)].TxStaticPduRefUsedOfTxPathway) != FALSE)
#define IpduM_IsInitialized()                                                                       (((*(IpduM_GetInitializedOfPCConfig()))) != FALSE)
#define IpduM_GetJitUpdateBuffer(Index)                                                             (IpduM_GetJitUpdateBufferOfPCConfig()[(Index)])
#define IpduM_GetTxLoInfoIndStartIdxOfMainFunctionTxIndirection(Index)                              (IpduM_GetMainFunctionTxIndirectionOfPCConfig()[(Index)].TxLoInfoIndStartIdxOfMainFunctionTxIndirection)
#define IpduM_GetEndByteMaskClearOfSegment(Index)                                                   (IpduM_GetSegmentOfPCConfig()[(Index)].EndByteMaskClearOfSegment)
#define IpduM_GetFirstFullBytePosOfSegment(Index)                                                   (IpduM_GetSegmentOfPCConfig()[(Index)].FirstFullBytePosOfSegment)
#define IpduM_IsFullBytesPresentOfSegment(Index)                                                    ((IpduM_GetSegmentOfPCConfig()[(Index)].FullBytesPresentOfSegment) != FALSE)
#define IpduM_GetLastFullBytePosOfSegment(Index)                                                    (IpduM_GetSegmentOfPCConfig()[(Index)].LastFullBytePosOfSegment)
#define IpduM_GetLengthOfSegment(Index)                                                             (IpduM_GetSegmentOfPCConfig()[(Index)].LengthOfSegment)
#define IpduM_GetStartByteMaskWriteOfSegment(Index)                                                 (IpduM_GetSegmentOfPCConfig()[(Index)].StartByteMaskWriteOfSegment)
#define IpduM_GetTriggerTransmitBuffer(Index)                                                       (IpduM_GetTriggerTransmitBufferOfPCConfig()[(Index)])
#define IpduM_GetTxBuffer(Index)                                                                    (IpduM_GetTxBufferOfPCConfig()[(Index)])
#define IpduM_GetTxInitValues(Index)                                                                (IpduM_GetTxInitValuesOfPCConfig()[(Index)])
#define IpduM_GetSegmentEndIdxOfTxPart(Index)                                                       (IpduM_GetTxPartOfPCConfig()[(Index)].SegmentEndIdxOfTxPart)
#define IpduM_GetSegmentStartIdxOfTxPart(Index)                                                     (IpduM_GetTxPartOfPCConfig()[(Index)].SegmentStartIdxOfTxPart)
#define IpduM_GetTxPathwayIdxOfTxPart(Index)                                                        (IpduM_GetTxPartOfPCConfig()[(Index)].TxPathwayIdxOfTxPart)
#define IpduM_GetUlPduRefOfTxPart(Index)                                                            (IpduM_GetTxPartOfPCConfig()[(Index)].UlPduRefOfTxPart)
#define IpduM_GetTxUpIndOfTxUpInfo(Index)                                                           (IpduM_GetTxUpInfoOfPCConfig()[(Index)].TxUpIndOfTxUpInfo)
#define IpduM_GetTxConfTimeoutCntOfVTxLoInfo(Index)                                                 (IpduM_GetVTxLoInfoOfPCConfig()[(Index)].TxConfTimeoutCntOfVTxLoInfo)
#define IpduM_GetTxPartDynamicPartIdxOfTxPathway(Index)                                             (IpduM_GetVTxPathwayOfPCConfig()[(Index)].TxPartDynamicPartIdxOfTxPathway)
/** 
  \}
*/ 

/** 
  \defgroup  IpduMPCGetDeduplicatedDataMacros  IpduM Get Deduplicated Data Macros (PRE_COMPILE)
  \brief  These macros can be used to read deduplicated data elements.
  \{
*/ 
#define IpduM_GetPathwayTypeOfCTxLoInfo(Index)                                                      ((IpduM_PathwayTypeOfCTxLoInfoType)((Index)))  /**< The type of the pathway. */
#define IpduM_IsTxPathwayUsedOfCTxLoInfo(Index)                                                     (((boolean)(IpduM_GetTxPathwayIdxOfCTxLoInfo(Index) != IPDUM_NO_TXPATHWAYIDXOFCTXLOINFO)) != FALSE)  /**< TRUE, if the 0:1 relation has minimum 1 relation pointing to IpduM_CTxPathway */
#define IpduM_GetJitUpdateBufferEndIdxOfTxPathway(Index)                                            ((IpduM_JitUpdateBufferEndIdxOfTxPathwayType)((((IpduM_JitUpdateBufferEndIdxOfTxPathwayType)(Index)) + 32u)))  /**< the end index of the 1:n relation pointing to IpduM_JitUpdateBuffer */
#define IpduM_GetJitUpdateBufferLengthOfTxPathway(Index)                                            ((IpduM_JitUpdateBufferLengthOfTxPathwayType)((((IpduM_JitUpdateBufferLengthOfTxPathwayType)(Index)) + 32u)))  /**< the number of relations pointing to IpduM_JitUpdateBuffer */
#define IpduM_GetJitUpdateBufferStartIdxOfTxPathway(Index)                                          ((IpduM_JitUpdateBufferStartIdxOfTxPathwayType)((Index)))  /**< the start index of the 1:n relation pointing to IpduM_JitUpdateBuffer */
#define IpduM_GetLlPduRefOfTxPathway(Index)                                                         ((IpduM_LlPduRefOfTxPathwayType)((((IpduM_LlPduRefOfTxPathwayType)(Index)) + 4u)))  /**< the DefinitionRef: /MICROSAR/IpduM/IpduMConfig/IpduMTxPathway/IpduMTxRequest/IpduMOutgoingPduRef */
#define IpduM_GetTriggerTransmitBufferEndIdxOfTxPathway(Index)                                      ((IpduM_TriggerTransmitBufferEndIdxOfTxPathwayType)((((IpduM_TriggerTransmitBufferEndIdxOfTxPathwayType)(Index)) + 32u)))  /**< the end index of the 1:n relation pointing to IpduM_TriggerTransmitBuffer */
#define IpduM_GetTriggerTransmitBufferLengthOfTxPathway(Index)                                      ((IpduM_TriggerTransmitBufferLengthOfTxPathwayType)((((IpduM_TriggerTransmitBufferLengthOfTxPathwayType)(Index)) + 32u)))  /**< the number of relations pointing to IpduM_TriggerTransmitBuffer */
#define IpduM_GetTriggerTransmitBufferStartIdxOfTxPathway(Index)                                    ((IpduM_TriggerTransmitBufferStartIdxOfTxPathwayType)((Index)))  /**< the start index of the 1:n relation pointing to IpduM_TriggerTransmitBuffer */
#define IpduM_GetTxBufferEndIdxOfTxPathway(Index)                                                   ((IpduM_TxBufferEndIdxOfTxPathwayType)((((IpduM_TxBufferEndIdxOfTxPathwayType)(Index)) + 32u)))  /**< the end index of the 1:n relation pointing to IpduM_TxBuffer */
#define IpduM_GetTxBufferLengthOfTxPathway(Index)                                                   ((IpduM_TxBufferLengthOfTxPathwayType)((((IpduM_TxBufferLengthOfTxPathwayType)(Index)) + 32u)))  /**< the number of relations pointing to IpduM_TxBuffer */
#define IpduM_GetTxBufferStartIdxOfTxPathway(Index)                                                 ((IpduM_TxBufferStartIdxOfTxPathwayType)((Index)))  /**< the start index of the 1:n relation pointing to IpduM_TxBuffer */
#define IpduM_IsTxLoInfoUsedOfTxPathway(Index)                                                      (((boolean)(IpduM_GetTxLoInfoIdxOfTxPathway(Index) != IPDUM_NO_TXLOINFOIDXOFTXPATHWAY)) != FALSE)  /**< TRUE, if the 0:1 relation has minimum 1 relation pointing to IpduM_TxLoInfoWithInvalidIndexes */
#define IpduM_GetTxPartIndEndIdxOfTxPathway(Index)                                                  ((IpduM_TxPartIndEndIdxOfTxPathwayType)((((IpduM_TxPartIndEndIdxOfTxPathwayType)(Index)) + 3u)))  /**< the end index of the 1:n relation pointing to IpduM_TxPartInd */
#define IpduM_GetTxPartIndStartIdxOfTxPathway(Index)                                                ((IpduM_TxPartIndStartIdxOfTxPathwayType)((Index)))  /**< the start index of the 1:n relation pointing to IpduM_TxPartInd */
#define IpduM_GetTxPartInitialDynPartIdxOfTxPathway(Index)                                          ((IpduM_TxPartInitialDynPartIdxOfTxPathwayType)((((IpduM_TxPartInitialDynPartIdxOfTxPathwayType)(Index)) + 1u)))  /**< the index of the 1:1 relation pointing to IpduM_TxPart */
#define IpduM_IsTxPartStaticPartUsedOfTxPathway(Index)                                              (((boolean)(IpduM_GetTxPartStaticPartIdxOfTxPathway(Index) != IPDUM_NO_TXPARTSTATICPARTIDXOFTXPATHWAY)) != FALSE)  /**< TRUE, if the 0:1 relation has minimum 1 relation pointing to IpduM_TxPart */
#define IpduM_GetTxStaticPduRefOfTxPathway(Index)                                                   ((IpduM_TxStaticPduRefOfTxPathwayType)((((IpduM_TxStaticPduRefOfTxPathwayType)(Index)) + 3u)))  /**< the DefinitionRef: /MICROSAR/IpduM/IpduMConfig/IpduMTxPathway/IpduMTxRequest/IpduMTxStaticPart/IpduMTxStaticPduRef */
#define IpduM_GetUnusedAreasDefaultOfTxPathway(Index)                                               ((IpduM_UnusedAreasDefaultOfTxPathwayType)((Index)))  /**< the DefinitionRef: /MICROSAR/IpduM/IpduMConfig/IpduMTxPathway/IpduMTxRequest/IpduMIPduUnusedAreasDefault */
#define IpduM_GetTxLoInfoIndEndIdxOfMainFunctionTxIndirection(Index)                                ((IpduM_TxLoInfoIndEndIdxOfMainFunctionTxIndirectionType)((((IpduM_TxLoInfoIndEndIdxOfMainFunctionTxIndirectionType)(Index)) + 1u)))  /**< the end index of the 0:n relation pointing to IpduM_TxLoInfoInd */
#define IpduM_IsTxLoInfoIndUsedOfMainFunctionTxIndirection(Index)                                   (((boolean)(IpduM_GetTxLoInfoIndStartIdxOfMainFunctionTxIndirection(Index) != IPDUM_NO_TXLOINFOINDSTARTIDXOFMAINFUNCTIONTXINDIRECTION)) != FALSE)  /**< TRUE, if the 0:n relation has 1 relation pointing to IpduM_TxLoInfoInd */
#define IpduM_GetBitInBytePosOfSegment(Index)                                                       IpduM_GetEndByteMaskClearOfSegment(Index)  /**< the bit position of the segment in the byte position. */
#define IpduM_GetEndByteMaskWriteOfSegment(Index)                                                   IpduM_GetStartByteMaskWriteOfSegment(Index)  /**< Mask for the partial end byte: writing. */
#define IpduM_GetFirstBytePosOfSegment(Index)                                                       IpduM_GetFirstFullBytePosOfSegment(Index)  /**< Byte position of the first byte of this segment. */
#define IpduM_GetLastBytePosOfSegment(Index)                                                        IpduM_GetLastFullBytePosOfSegment(Index)  /**< Byte position of the last byte of this segment. */
#define IpduM_GetPduBytePosOfSegment(Index)                                                         IpduM_GetFirstFullBytePosOfSegment(Index)  /**< the byte position of the segment in the PDU. */
#define IpduM_GetStartByteMaskClearOfSegment(Index)                                                 IpduM_GetEndByteMaskClearOfSegment(Index)  /**< Mask for the partial start byte: clearing. */
#define IpduM_GetSizeOfCTxLoInfo()                                                                  IpduM_GetSizeOfCTxLoInfoOfPCConfig()
#define IpduM_GetSizeOfCTxPathway()                                                                 IpduM_GetSizeOfCTxPathwayOfPCConfig()
#define IpduM_GetSizeOfJitUpdateBuffer()                                                            IpduM_GetSizeOfJitUpdateBufferOfPCConfig()
#define IpduM_GetSizeOfMainFunctionTxIndirection()                                                  IpduM_GetSizeOfMainFunctionTxIndirectionOfPCConfig()
#define IpduM_GetSizeOfSegment()                                                                    IpduM_GetSizeOfSegmentOfPCConfig()
#define IpduM_GetSizeOfTriggerTransmitBuffer()                                                      IpduM_GetSizeOfTriggerTransmitBufferOfPCConfig()
#define IpduM_GetSizeOfTxBuffer()                                                                   IpduM_GetSizeOfTxBufferOfPCConfig()
#define IpduM_GetSizeOfTxInitValues()                                                               IpduM_GetSizeOfTxInitValuesOfPCConfig()
#define IpduM_GetSizeOfTxLoInfoInd()                                                                IpduM_GetSizeOfTxLoInfoIndOfPCConfig()
#define IpduM_GetSizeOfTxLoInfoWithInvalidIndexes()                                                 IpduM_GetSizeOfTxLoInfoWithInvalidIndexesOfPCConfig()
#define IpduM_GetSizeOfTxPart()                                                                     IpduM_GetSizeOfTxPartOfPCConfig()
#define IpduM_GetSizeOfTxPartInd()                                                                  IpduM_GetSizeOfTxPartIndOfPCConfig()
#define IpduM_GetSizeOfTxUpInfo()                                                                   IpduM_GetSizeOfTxUpInfoOfPCConfig()
#define IpduM_GetSizeOfVTxLoInfo()                                                                  IpduM_GetSizeOfVTxLoInfoOfPCConfig()
#define IpduM_GetSizeOfVTxPathway()                                                                 IpduM_GetSizeOfVTxPathwayOfPCConfig()
#define IpduM_GetTxLoInfoInd(Index)                                                                 ((IpduM_TxLoInfoIndType)((Index)))  /**< the index of the 1:1 relation pointing to IpduM_TxLoInfoWithInvalidIndexes */
#define IpduM_GetCTxLoInfoIdxOfTxLoInfoWithInvalidIndexes(Index)                                    ((IpduM_CTxLoInfoIdxOfTxLoInfoWithInvalidIndexesType)((Index)))  /**< the index of the 1:1 relation pointing to IpduM_CTxLoInfo */
#define IpduM_IsTriggerEventOfTxPart(Index)                                                         (((boolean)(IpduM_GetSegmentEndIdxOfTxPart(Index) == 3u)) != FALSE)  /**< the DefinitionRef: /MICROSAR/IpduM/IpduMConfig/IpduMTxPathway/IpduMTxRequest/IpduMTxTriggerMode */
#define IpduM_GetTxPartInd(Index)                                                                   ((IpduM_TxPartIndType)((((IpduM_TxPartIndType)(Index)) + 1u)))  /**< the indexes of the 1:1 sorted relation pointing to IpduM_TxPart */
#define IpduM_GetPathwayTypeOfTxUpInfo(Index)                                                       IpduM_GetTxUpIndOfTxUpInfo(Index)  /**< The type of the pathway. */
#define IpduM_GetTxUpIndIdxOfTxUpInfo(Index)                                                        ((IpduM_TxUpIndIdxOfTxUpInfoType)((Index)))  /**< the index of the 1:1 relation pointing to one of IpduM_TxPart,IpduM_TxContainedPdu */
/** 
  \}
*/ 

/** 
  \defgroup  IpduMPCSetDataMacros  IpduM Set Data Macros (PRE_COMPILE)
  \brief  These macros can be used to write data.
  \{
*/ 
#define IpduM_SetInitialized(Value)                                                                 (*(IpduM_GetInitializedOfPCConfig())) = (Value)
#define IpduM_SetJitUpdateBuffer(Index, Value)                                                      IpduM_GetJitUpdateBufferOfPCConfig()[(Index)] = (Value)
#define IpduM_SetTriggerTransmitBuffer(Index, Value)                                                IpduM_GetTriggerTransmitBufferOfPCConfig()[(Index)] = (Value)
#define IpduM_SetTxBuffer(Index, Value)                                                             IpduM_GetTxBufferOfPCConfig()[(Index)] = (Value)
#define IpduM_SetTxConfTimeoutCntOfVTxLoInfo(Index, Value)                                          IpduM_GetVTxLoInfoOfPCConfig()[(Index)].TxConfTimeoutCntOfVTxLoInfo = (Value)
#define IpduM_SetTxPartDynamicPartIdxOfTxPathway(Index, Value)                                      IpduM_GetVTxPathwayOfPCConfig()[(Index)].TxPartDynamicPartIdxOfTxPathway = (Value)
/** 
  \}
*/ 

/** 
  \defgroup  IpduMPCGetAddressOfDataMacros  IpduM Get Address Of Data Macros (PRE_COMPILE)
  \brief  These macros can be used to get the data by the address operator.
  \{
*/ 
#define IpduM_GetAddrJitUpdateBuffer(Index)                                                         (&IpduM_GetJitUpdateBuffer(Index))
#define IpduM_GetAddrTriggerTransmitBuffer(Index)                                                   (&IpduM_GetTriggerTransmitBuffer(Index))
#define IpduM_GetAddrTxBuffer(Index)                                                                (&IpduM_GetTxBuffer(Index))
#define IpduM_GetAddrTxInitValues(Index)                                                            (&IpduM_GetTxInitValues(Index))
/** 
  \}
*/ 

/** 
  \defgroup  IpduMPCHasMacros  IpduM Has Macros (PRE_COMPILE)
  \brief  These macros can be used to detect at runtime a deactivated piece of information. TRUE in the CONFIGURATION_VARIANT PRE-COMPILE, TRUE or FALSE in the CONFIGURATION_VARIANT POST-BUILD.
  \{
*/ 
#define IpduM_HasCTxLoInfo()                                                                        (TRUE != FALSE)
#define IpduM_HasPathwayTypeOfCTxLoInfo()                                                           (TRUE != FALSE)
#define IpduM_HasTxPathwayIdxOfCTxLoInfo()                                                          (TRUE != FALSE)
#define IpduM_HasTxPathwayUsedOfCTxLoInfo()                                                         (TRUE != FALSE)
#define IpduM_HasCTxPathway()                                                                       (TRUE != FALSE)
#define IpduM_HasJitUpdateBufferEndIdxOfTxPathway()                                                 (TRUE != FALSE)
#define IpduM_HasJitUpdateBufferLengthOfTxPathway()                                                 (TRUE != FALSE)
#define IpduM_HasJitUpdateBufferStartIdxOfTxPathway()                                               (TRUE != FALSE)
#define IpduM_HasLlPduRefOfTxPathway()                                                              (TRUE != FALSE)
#define IpduM_HasTriggerTransmitBufferEndIdxOfTxPathway()                                           (TRUE != FALSE)
#define IpduM_HasTriggerTransmitBufferLengthOfTxPathway()                                           (TRUE != FALSE)
#define IpduM_HasTriggerTransmitBufferStartIdxOfTxPathway()                                         (TRUE != FALSE)
#define IpduM_HasTxBufferEndIdxOfTxPathway()                                                        (TRUE != FALSE)
#define IpduM_HasTxBufferLengthOfTxPathway()                                                        (TRUE != FALSE)
#define IpduM_HasTxBufferStartIdxOfTxPathway()                                                      (TRUE != FALSE)
#define IpduM_HasTxLoInfoIdxOfTxPathway()                                                           (TRUE != FALSE)
#define IpduM_HasTxLoInfoUsedOfTxPathway()                                                          (TRUE != FALSE)
#define IpduM_HasTxPartIndEndIdxOfTxPathway()                                                       (TRUE != FALSE)
#define IpduM_HasTxPartIndStartIdxOfTxPathway()                                                     (TRUE != FALSE)
#define IpduM_HasTxPartInitialDynPartIdxOfTxPathway()                                               (TRUE != FALSE)
#define IpduM_HasTxPartStaticPartIdxOfTxPathway()                                                   (TRUE != FALSE)
#define IpduM_HasTxPartStaticPartUsedOfTxPathway()                                                  (TRUE != FALSE)
#define IpduM_HasTxStaticPduRefOfTxPathway()                                                        (TRUE != FALSE)
#define IpduM_HasTxStaticPduRefUsedOfTxPathway()                                                    (TRUE != FALSE)
#define IpduM_HasUnusedAreasDefaultOfTxPathway()                                                    (TRUE != FALSE)
#define IpduM_HasInitialized()                                                                      (TRUE != FALSE)
#define IpduM_HasJitUpdateBuffer()                                                                  (TRUE != FALSE)
#define IpduM_HasMainFunctionTxIndirection()                                                        (TRUE != FALSE)
#define IpduM_HasTxLoInfoIndEndIdxOfMainFunctionTxIndirection()                                     (TRUE != FALSE)
#define IpduM_HasTxLoInfoIndStartIdxOfMainFunctionTxIndirection()                                   (TRUE != FALSE)
#define IpduM_HasTxLoInfoIndUsedOfMainFunctionTxIndirection()                                       (TRUE != FALSE)
#define IpduM_HasSegment()                                                                          (TRUE != FALSE)
#define IpduM_HasBitInBytePosOfSegment()                                                            (TRUE != FALSE)
#define IpduM_HasEndByteMaskClearOfSegment()                                                        (TRUE != FALSE)
#define IpduM_HasEndByteMaskWriteOfSegment()                                                        (TRUE != FALSE)
#define IpduM_HasFirstBytePosOfSegment()                                                            (TRUE != FALSE)
#define IpduM_HasFirstFullBytePosOfSegment()                                                        (TRUE != FALSE)
#define IpduM_HasFullBytesPresentOfSegment()                                                        (TRUE != FALSE)
#define IpduM_HasLastBytePosOfSegment()                                                             (TRUE != FALSE)
#define IpduM_HasLastFullBytePosOfSegment()                                                         (TRUE != FALSE)
#define IpduM_HasLengthOfSegment()                                                                  (TRUE != FALSE)
#define IpduM_HasPduBytePosOfSegment()                                                              (TRUE != FALSE)
#define IpduM_HasStartByteMaskClearOfSegment()                                                      (TRUE != FALSE)
#define IpduM_HasStartByteMaskWriteOfSegment()                                                      (TRUE != FALSE)
#define IpduM_HasSizeOfCTxLoInfo()                                                                  (TRUE != FALSE)
#define IpduM_HasSizeOfCTxPathway()                                                                 (TRUE != FALSE)
#define IpduM_HasSizeOfJitUpdateBuffer()                                                            (TRUE != FALSE)
#define IpduM_HasSizeOfMainFunctionTxIndirection()                                                  (TRUE != FALSE)
#define IpduM_HasSizeOfSegment()                                                                    (TRUE != FALSE)
#define IpduM_HasSizeOfTriggerTransmitBuffer()                                                      (TRUE != FALSE)
#define IpduM_HasSizeOfTxBuffer()                                                                   (TRUE != FALSE)
#define IpduM_HasSizeOfTxInitValues()                                                               (TRUE != FALSE)
#define IpduM_HasSizeOfTxLoInfoInd()                                                                (TRUE != FALSE)
#define IpduM_HasSizeOfTxLoInfoWithInvalidIndexes()                                                 (TRUE != FALSE)
#define IpduM_HasSizeOfTxPart()                                                                     (TRUE != FALSE)
#define IpduM_HasSizeOfTxPartInd()                                                                  (TRUE != FALSE)
#define IpduM_HasSizeOfTxUpInfo()                                                                   (TRUE != FALSE)
#define IpduM_HasSizeOfVTxLoInfo()                                                                  (TRUE != FALSE)
#define IpduM_HasSizeOfVTxPathway()                                                                 (TRUE != FALSE)
#define IpduM_HasTriggerTransmitBuffer()                                                            (TRUE != FALSE)
#define IpduM_HasTxBuffer()                                                                         (TRUE != FALSE)
#define IpduM_HasTxInitValues()                                                                     (TRUE != FALSE)
#define IpduM_HasTxLoInfoInd()                                                                      (TRUE != FALSE)
#define IpduM_HasTxLoInfoWithInvalidIndexes()                                                       (TRUE != FALSE)
#define IpduM_HasCTxLoInfoIdxOfTxLoInfoWithInvalidIndexes()                                         (TRUE != FALSE)
#define IpduM_HasTxPart()                                                                           (TRUE != FALSE)
#define IpduM_HasSegmentEndIdxOfTxPart()                                                            (TRUE != FALSE)
#define IpduM_HasSegmentStartIdxOfTxPart()                                                          (TRUE != FALSE)
#define IpduM_HasTriggerEventOfTxPart()                                                             (TRUE != FALSE)
#define IpduM_HasTxPathwayIdxOfTxPart()                                                             (TRUE != FALSE)
#define IpduM_HasUlPduRefOfTxPart()                                                                 (TRUE != FALSE)
#define IpduM_HasTxPartInd()                                                                        (TRUE != FALSE)
#define IpduM_HasTxUpInfo()                                                                         (TRUE != FALSE)
#define IpduM_HasPathwayTypeOfTxUpInfo()                                                            (TRUE != FALSE)
#define IpduM_HasTxUpIndIdxOfTxUpInfo()                                                             (TRUE != FALSE)
#define IpduM_HasTxUpIndOfTxUpInfo()                                                                (TRUE != FALSE)
#define IpduM_HasVTxLoInfo()                                                                        (TRUE != FALSE)
#define IpduM_HasTxConfTimeoutCntOfVTxLoInfo()                                                      (TRUE != FALSE)
#define IpduM_HasVTxPathway()                                                                       (TRUE != FALSE)
#define IpduM_HasTxPartDynamicPartIdxOfTxPathway()                                                  (TRUE != FALSE)
#define IpduM_HasPCConfig()                                                                         (TRUE != FALSE)
#define IpduM_HasCTxLoInfoOfPCConfig()                                                              (TRUE != FALSE)
#define IpduM_HasCTxPathwayOfPCConfig()                                                             (TRUE != FALSE)
#define IpduM_HasInitializedOfPCConfig()                                                            (TRUE != FALSE)
#define IpduM_HasJitUpdateBufferOfPCConfig()                                                        (TRUE != FALSE)
#define IpduM_HasMainFunctionTxIndirectionOfPCConfig()                                              (TRUE != FALSE)
#define IpduM_HasSegmentOfPCConfig()                                                                (TRUE != FALSE)
#define IpduM_HasSizeOfCTxLoInfoOfPCConfig()                                                        (TRUE != FALSE)
#define IpduM_HasSizeOfCTxPathwayOfPCConfig()                                                       (TRUE != FALSE)
#define IpduM_HasSizeOfJitUpdateBufferOfPCConfig()                                                  (TRUE != FALSE)
#define IpduM_HasSizeOfMainFunctionTxIndirectionOfPCConfig()                                        (TRUE != FALSE)
#define IpduM_HasSizeOfSegmentOfPCConfig()                                                          (TRUE != FALSE)
#define IpduM_HasSizeOfTriggerTransmitBufferOfPCConfig()                                            (TRUE != FALSE)
#define IpduM_HasSizeOfTxBufferOfPCConfig()                                                         (TRUE != FALSE)
#define IpduM_HasSizeOfTxInitValuesOfPCConfig()                                                     (TRUE != FALSE)
#define IpduM_HasSizeOfTxLoInfoIndOfPCConfig()                                                      (TRUE != FALSE)
#define IpduM_HasSizeOfTxLoInfoWithInvalidIndexesOfPCConfig()                                       (TRUE != FALSE)
#define IpduM_HasSizeOfTxPartIndOfPCConfig()                                                        (TRUE != FALSE)
#define IpduM_HasSizeOfTxPartOfPCConfig()                                                           (TRUE != FALSE)
#define IpduM_HasSizeOfTxUpInfoOfPCConfig()                                                         (TRUE != FALSE)
#define IpduM_HasSizeOfVTxLoInfoOfPCConfig()                                                        (TRUE != FALSE)
#define IpduM_HasSizeOfVTxPathwayOfPCConfig()                                                       (TRUE != FALSE)
#define IpduM_HasTriggerTransmitBufferOfPCConfig()                                                  (TRUE != FALSE)
#define IpduM_HasTxBufferOfPCConfig()                                                               (TRUE != FALSE)
#define IpduM_HasTxInitValuesOfPCConfig()                                                           (TRUE != FALSE)
#define IpduM_HasTxLoInfoIndOfPCConfig()                                                            (TRUE != FALSE)
#define IpduM_HasTxLoInfoWithInvalidIndexesOfPCConfig()                                             (TRUE != FALSE)
#define IpduM_HasTxPartIndOfPCConfig()                                                              (TRUE != FALSE)
#define IpduM_HasTxPartOfPCConfig()                                                                 (TRUE != FALSE)
#define IpduM_HasTxUpInfoOfPCConfig()                                                               (TRUE != FALSE)
#define IpduM_HasVTxLoInfoOfPCConfig()                                                              (TRUE != FALSE)
#define IpduM_HasVTxPathwayOfPCConfig()                                                             (TRUE != FALSE)
/** 
  \}
*/ 

/** 
  \defgroup  IpduMPCIncrementDataMacros  IpduM Increment Data Macros (PRE_COMPILE)
  \brief  These macros can be used to increment VAR data with numerical nature.
  \{
*/ 
#define IpduM_IncJitUpdateBuffer(Index)                                                             IpduM_GetJitUpdateBuffer(Index)++
#define IpduM_IncTriggerTransmitBuffer(Index)                                                       IpduM_GetTriggerTransmitBuffer(Index)++
#define IpduM_IncTxBuffer(Index)                                                                    IpduM_GetTxBuffer(Index)++
#define IpduM_IncTxConfTimeoutCntOfVTxLoInfo(Index)                                                 IpduM_GetTxConfTimeoutCntOfVTxLoInfo(Index)++
#define IpduM_IncTxPartDynamicPartIdxOfTxPathway(Index)                                             IpduM_GetTxPartDynamicPartIdxOfTxPathway(Index)++
/** 
  \}
*/ 

/** 
  \defgroup  IpduMPCDecrementDataMacros  IpduM Decrement Data Macros (PRE_COMPILE)
  \brief  These macros can be used to decrement VAR data with numerical nature.
  \{
*/ 
#define IpduM_DecJitUpdateBuffer(Index)                                                             IpduM_GetJitUpdateBuffer(Index)--
#define IpduM_DecTriggerTransmitBuffer(Index)                                                       IpduM_GetTriggerTransmitBuffer(Index)--
#define IpduM_DecTxBuffer(Index)                                                                    IpduM_GetTxBuffer(Index)--
#define IpduM_DecTxConfTimeoutCntOfVTxLoInfo(Index)                                                 IpduM_GetTxConfTimeoutCntOfVTxLoInfo(Index)--
#define IpduM_DecTxPartDynamicPartIdxOfTxPathway(Index)                                             IpduM_GetTxPartDynamicPartIdxOfTxPathway(Index)--
/** 
  \}
*/ 

/** 
  \defgroup  IpduMPCAddDataMacros  IpduM Add Data Macros (PRE_COMPILE)
  \brief  These macros can be used to add VAR data with numerical nature.
  \{
*/ 
#define IpduM_AddJitUpdateBuffer(Index, Value)                                                      IpduM_SetJitUpdateBuffer(Index, (IpduM_GetJitUpdateBuffer(Index) + Value))
#define IpduM_AddTriggerTransmitBuffer(Index, Value)                                                IpduM_SetTriggerTransmitBuffer(Index, (IpduM_GetTriggerTransmitBuffer(Index) + Value))
#define IpduM_AddTxBuffer(Index, Value)                                                             IpduM_SetTxBuffer(Index, (IpduM_GetTxBuffer(Index) + Value))
#define IpduM_AddTxConfTimeoutCntOfVTxLoInfo(Index, Value)                                          IpduM_SetTxConfTimeoutCntOfVTxLoInfo(Index, (IpduM_GetTxConfTimeoutCntOfVTxLoInfo(Index) + Value))
#define IpduM_AddTxPartDynamicPartIdxOfTxPathway(Index, Value)                                      IpduM_SetTxPartDynamicPartIdxOfTxPathway(Index, (IpduM_GetTxPartDynamicPartIdxOfTxPathway(Index) + Value))
/** 
  \}
*/ 

/** 
  \defgroup  IpduMPCSubstractDataMacros  IpduM Substract Data Macros (PRE_COMPILE)
  \brief  These macros can be used to substract VAR data with numerical nature.
  \{
*/ 
#define IpduM_SubJitUpdateBuffer(Index, Value)                                                      IpduM_SetJitUpdateBuffer(Index, (IpduM_GetJitUpdateBuffer(Index) - Value))
#define IpduM_SubTriggerTransmitBuffer(Index, Value)                                                IpduM_SetTriggerTransmitBuffer(Index, (IpduM_GetTriggerTransmitBuffer(Index) - Value))
#define IpduM_SubTxBuffer(Index, Value)                                                             IpduM_SetTxBuffer(Index, (IpduM_GetTxBuffer(Index) - Value))
#define IpduM_SubTxConfTimeoutCntOfVTxLoInfo(Index, Value)                                          IpduM_SetTxConfTimeoutCntOfVTxLoInfo(Index, (IpduM_GetTxConfTimeoutCntOfVTxLoInfo(Index) - Value))
#define IpduM_SubTxPartDynamicPartIdxOfTxPathway(Index, Value)                                      IpduM_SetTxPartDynamicPartIdxOfTxPathway(Index, (IpduM_GetTxPartDynamicPartIdxOfTxPathway(Index) - Value))
/** 
  \}
*/ 

/** 
  \defgroup  IpduMPCOptimizedMacros  IpduM Optimized Macros (PRE_COMPILE)
  \brief  These macros can be used to access struct elements that are optimized.
  \{
*/ 
#define IpduM_GetPathwayTypeOfCTxLoInfoOfTxLoInfoWithInvalidIndexes(Index)                          IpduM_GetPathwayTypeOfCTxLoInfo(IpduM_GetCTxLoInfoIdxOfTxLoInfoWithInvalidIndexes(Index))
#define IpduM_GetTxPathwayIdxOfCTxLoInfoOfTxLoInfoWithInvalidIndexes(Index)                         IpduM_GetTxPathwayIdxOfCTxLoInfo(IpduM_GetCTxLoInfoIdxOfTxLoInfoWithInvalidIndexes(Index))
#define IpduM_IsTxPathwayUsedOfCTxLoInfoOfTxLoInfoWithInvalidIndexes(Index)                         IpduM_IsTxPathwayUsedOfCTxLoInfo(IpduM_GetCTxLoInfoIdxOfTxLoInfoWithInvalidIndexes(Index))
#define IpduM_GetTxConfTimeoutCntOfVTxLoInfoOfTxLoInfoWithInvalidIndexes(Index)                     IpduM_GetTxConfTimeoutCntOfVTxLoInfo(IpduM_GetCTxLoInfoIdxOfTxLoInfoWithInvalidIndexes(Index))
#define IpduM_SetTxConfTimeoutCntOfVTxLoInfoOfTxLoInfoWithInvalidIndexes(Index, Value)              IpduM_SetTxConfTimeoutCntOfVTxLoInfo(((IpduM_GetCTxLoInfoIdxOfTxLoInfoWithInvalidIndexes(Index))), (Value))
#define IpduM_IncTxConfTimeoutCntOfVTxLoInfoOfTxLoInfoWithInvalidIndexes(Index)                     IpduM_IncTxConfTimeoutCntOfVTxLoInfo(IpduM_GetCTxLoInfoIdxOfTxLoInfoWithInvalidIndexes(Index))
#define IpduM_DecTxConfTimeoutCntOfVTxLoInfoOfTxLoInfoWithInvalidIndexes(Index)                     IpduM_DecTxConfTimeoutCntOfVTxLoInfo(IpduM_GetCTxLoInfoIdxOfTxLoInfoWithInvalidIndexes(Index))
#define IpduM_AddTxConfTimeoutCntOfVTxLoInfoOfTxLoInfoWithInvalidIndexes(Index, Value)              IpduM_AddTxConfTimeoutCntOfVTxLoInfo(((IpduM_GetCTxLoInfoIdxOfTxLoInfoWithInvalidIndexes(Index))), (Value))
#define IpduM_SubTxConfTimeoutCntOfVTxLoInfoOfTxLoInfoWithInvalidIndexes(Index, Value)              IpduM_SubTxConfTimeoutCntOfVTxLoInfo(((IpduM_GetCTxLoInfoIdxOfTxLoInfoWithInvalidIndexes(Index))), (Value))
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
  SECTION: GLOBAL SIMPLE DATA TYPES AND STRUCTURES
**********************************************************************************************************************/
/** 
  \defgroup  IpduMPCIterableTypes  IpduM Iterable Types (PRE_COMPILE)
  \brief  These type definitions are used to iterate over an array with least processor cycles for variable access as possible.
  \{
*/ 
/**   \brief  type used to iterate IpduM_CTxLoInfo */
/*! \spec strong type invariant () { self < IpduM_GetSizeOfCTxLoInfo() } \endspec */ 
typedef uint8_least IpduM_CTxLoInfoIterType;

/**   \brief  type used to iterate IpduM_CTxPathway */
/*! \spec strong type invariant () { self < IpduM_GetSizeOfCTxPathway() } \endspec */ 
typedef uint8_least IpduM_CTxPathwayIterType;

/**   \brief  type used to iterate IpduM_JitUpdateBuffer */
/*! \spec strong type invariant () { self < IpduM_GetSizeOfJitUpdateBuffer() } \endspec */ 
typedef uint8_least IpduM_JitUpdateBufferIterType;

/**   \brief  type used to iterate IpduM_MainFunctionTxIndirection */
/*! \spec strong type invariant () { self < IpduM_GetSizeOfMainFunctionTxIndirection() } \endspec */ 
typedef uint8_least IpduM_MainFunctionTxIndirectionIterType;

/**   \brief  type used to iterate IpduM_Segment */
/*! \spec strong type invariant () { self < IpduM_GetSizeOfSegment() } \endspec */ 
typedef uint8_least IpduM_SegmentIterType;

/**   \brief  type used to iterate IpduM_TriggerTransmitBuffer */
/*! \spec strong type invariant () { self < IpduM_GetSizeOfTriggerTransmitBuffer() } \endspec */ 
typedef uint8_least IpduM_TriggerTransmitBufferIterType;

/**   \brief  type used to iterate IpduM_TxBuffer */
/*! \spec strong type invariant () { self < IpduM_GetSizeOfTxBuffer() } \endspec */ 
typedef uint8_least IpduM_TxBufferIterType;

/**   \brief  type used to iterate IpduM_TxInitValues */
/*! \spec strong type invariant () { self < IpduM_GetSizeOfTxInitValues() } \endspec */ 
typedef uint8_least IpduM_TxInitValuesIterType;

/**   \brief  type used to iterate IpduM_TxLoInfoInd */
/*! \spec strong type invariant () { self < IpduM_GetSizeOfTxLoInfoInd() } \endspec */ 
typedef uint8_least IpduM_TxLoInfoIndIterType;

/**   \brief  type used to iterate IpduM_TxLoInfoWithInvalidIndexes */
/*! \spec strong type invariant () { self < IpduM_GetSizeOfTxLoInfoWithInvalidIndexes() } \endspec */ 
typedef uint8_least IpduM_TxLoInfoWithInvalidIndexesIterType;

/**   \brief  type used to iterate IpduM_TxPart */
/*! \spec strong type invariant () { self < IpduM_GetSizeOfTxPart() } \endspec */ 
typedef uint8_least IpduM_TxPartIterType;

/**   \brief  type used to iterate IpduM_TxPartInd */
/*! \spec strong type invariant () { self < IpduM_GetSizeOfTxPartInd() } \endspec */ 
typedef uint8_least IpduM_TxPartIndIterType;

/**   \brief  type used to iterate IpduM_TxUpInfo */
/*! \spec strong type invariant () { self < IpduM_GetSizeOfTxUpInfo() } \endspec */ 
typedef uint8_least IpduM_TxUpInfoIterType;

/** 
  \}
*/ 

/** 
  \defgroup  IpduMPCIterableTypesWithSizeRelations  IpduM Iterable Types With Size Relations (PRE_COMPILE)
  \brief  These type definitions are used to iterate over a VAR based array with the same iterator as the related CONST array.
  \{
*/ 
/**   \brief  type used to iterate IpduM_VTxLoInfo */
/*! \spec strong type invariant () { self < IpduM_GetSizeOfVTxLoInfo() } \endspec */ 
typedef IpduM_CTxLoInfoIterType IpduM_VTxLoInfoIterType;

/**   \brief  type used to iterate IpduM_VTxPathway */
/*! \spec strong type invariant () { self < IpduM_GetSizeOfVTxPathway() } \endspec */ 
typedef IpduM_CTxPathwayIterType IpduM_VTxPathwayIterType;

/** 
  \}
*/ 

/** 
  \defgroup  IpduMPCValueTypes  IpduM Value Types (PRE_COMPILE)
  \brief  These type definitions are used for value based data representations.
  \{
*/ 
/**   \brief  value based type definition for IpduM_PathwayTypeOfCTxLoInfo */
typedef uint8 IpduM_PathwayTypeOfCTxLoInfoType;

/**   \brief  value based type definition for IpduM_TxPathwayIdxOfCTxLoInfo */
/*! \spec strong type invariant () { self < IpduM_GetSizeOfCTxPathway() } \endspec */ 
typedef uint8 IpduM_TxPathwayIdxOfCTxLoInfoType;

/**   \brief  value based type definition for IpduM_TxPathwayUsedOfCTxLoInfo */
typedef boolean IpduM_TxPathwayUsedOfCTxLoInfoType;

/**   \brief  value based type definition for IpduM_JitUpdateBufferEndIdxOfTxPathway */
/*! \spec strong type invariant () { self < IpduM_GetSizeOfJitUpdateBuffer() } \endspec */ 
typedef uint8 IpduM_JitUpdateBufferEndIdxOfTxPathwayType;

/**   \brief  value based type definition for IpduM_JitUpdateBufferLengthOfTxPathway */
typedef uint8 IpduM_JitUpdateBufferLengthOfTxPathwayType;

/**   \brief  value based type definition for IpduM_JitUpdateBufferStartIdxOfTxPathway */
/*! \spec strong type invariant () { self < IpduM_GetSizeOfJitUpdateBuffer() } \endspec */ 
typedef uint8 IpduM_JitUpdateBufferStartIdxOfTxPathwayType;

/**   \brief  value based type definition for IpduM_LlPduRefOfTxPathway */
typedef uint8 IpduM_LlPduRefOfTxPathwayType;

/**   \brief  value based type definition for IpduM_TriggerTransmitBufferEndIdxOfTxPathway */
/*! \spec strong type invariant () { self < IpduM_GetSizeOfTriggerTransmitBuffer() } \endspec */ 
typedef uint8 IpduM_TriggerTransmitBufferEndIdxOfTxPathwayType;

/**   \brief  value based type definition for IpduM_TriggerTransmitBufferLengthOfTxPathway */
typedef uint8 IpduM_TriggerTransmitBufferLengthOfTxPathwayType;

/**   \brief  value based type definition for IpduM_TriggerTransmitBufferStartIdxOfTxPathway */
/*! \spec strong type invariant () { self < IpduM_GetSizeOfTriggerTransmitBuffer() } \endspec */ 
typedef uint8 IpduM_TriggerTransmitBufferStartIdxOfTxPathwayType;

/**   \brief  value based type definition for IpduM_TxBufferEndIdxOfTxPathway */
/*! \spec strong type invariant () { self < IpduM_GetSizeOfTxBuffer() } \endspec */ 
typedef uint8 IpduM_TxBufferEndIdxOfTxPathwayType;

/**   \brief  value based type definition for IpduM_TxBufferLengthOfTxPathway */
typedef uint8 IpduM_TxBufferLengthOfTxPathwayType;

/**   \brief  value based type definition for IpduM_TxBufferStartIdxOfTxPathway */
/*! \spec strong type invariant () { self < IpduM_GetSizeOfTxBuffer() } \endspec */ 
typedef uint8 IpduM_TxBufferStartIdxOfTxPathwayType;

/**   \brief  value based type definition for IpduM_TxLoInfoIdxOfTxPathway */
/*! \spec strong type invariant () { self < IpduM_GetSizeOfTxLoInfoWithInvalidIndexes() } \endspec */ 
typedef uint8 IpduM_TxLoInfoIdxOfTxPathwayType;

/**   \brief  value based type definition for IpduM_TxLoInfoUsedOfTxPathway */
typedef boolean IpduM_TxLoInfoUsedOfTxPathwayType;

/**   \brief  value based type definition for IpduM_TxPartIndEndIdxOfTxPathway */
/*! \spec strong type invariant () { self < IpduM_GetSizeOfTxPartInd() } \endspec */ 
typedef uint8 IpduM_TxPartIndEndIdxOfTxPathwayType;

/**   \brief  value based type definition for IpduM_TxPartIndStartIdxOfTxPathway */
/*! \spec strong type invariant () { self < IpduM_GetSizeOfTxPartInd() } \endspec */ 
typedef uint8 IpduM_TxPartIndStartIdxOfTxPathwayType;

/**   \brief  value based type definition for IpduM_TxPartInitialDynPartIdxOfTxPathway */
/*! \spec strong type invariant () { self < IpduM_GetSizeOfTxPart() } \endspec */ 
typedef uint8 IpduM_TxPartInitialDynPartIdxOfTxPathwayType;

/**   \brief  value based type definition for IpduM_TxPartStaticPartIdxOfTxPathway */
/*! \spec strong type invariant () { self < IpduM_GetSizeOfTxPart() } \endspec */ 
typedef uint8 IpduM_TxPartStaticPartIdxOfTxPathwayType;

/**   \brief  value based type definition for IpduM_TxPartStaticPartUsedOfTxPathway */
typedef boolean IpduM_TxPartStaticPartUsedOfTxPathwayType;

/**   \brief  value based type definition for IpduM_TxStaticPduRefOfTxPathway */
typedef uint8 IpduM_TxStaticPduRefOfTxPathwayType;

/**   \brief  value based type definition for IpduM_TxStaticPduRefUsedOfTxPathway */
typedef boolean IpduM_TxStaticPduRefUsedOfTxPathwayType;

/**   \brief  value based type definition for IpduM_UnusedAreasDefaultOfTxPathway */
typedef uint8 IpduM_UnusedAreasDefaultOfTxPathwayType;

/**   \brief  value based type definition for IpduM_Initialized */
typedef boolean IpduM_InitializedType;

/**   \brief  value based type definition for IpduM_JitUpdateBuffer */
typedef uint8 IpduM_JitUpdateBufferType;

/**   \brief  value based type definition for IpduM_TxLoInfoIndEndIdxOfMainFunctionTxIndirection */
/*! \spec strong type invariant () { self < IpduM_GetSizeOfTxLoInfoInd() } \endspec */ 
typedef uint8 IpduM_TxLoInfoIndEndIdxOfMainFunctionTxIndirectionType;

/**   \brief  value based type definition for IpduM_TxLoInfoIndStartIdxOfMainFunctionTxIndirection */
/*! \spec strong type invariant () { self < IpduM_GetSizeOfTxLoInfoInd() } \endspec */ 
typedef uint8 IpduM_TxLoInfoIndStartIdxOfMainFunctionTxIndirectionType;

/**   \brief  value based type definition for IpduM_TxLoInfoIndUsedOfMainFunctionTxIndirection */
typedef boolean IpduM_TxLoInfoIndUsedOfMainFunctionTxIndirectionType;

/**   \brief  value based type definition for IpduM_BitInBytePosOfSegment */
typedef uint8 IpduM_BitInBytePosOfSegmentType;

/**   \brief  value based type definition for IpduM_EndByteMaskClearOfSegment */
typedef uint8 IpduM_EndByteMaskClearOfSegmentType;

/**   \brief  value based type definition for IpduM_EndByteMaskWriteOfSegment */
typedef uint8 IpduM_EndByteMaskWriteOfSegmentType;

/**   \brief  value based type definition for IpduM_FirstBytePosOfSegment */
typedef uint8 IpduM_FirstBytePosOfSegmentType;

/**   \brief  value based type definition for IpduM_FirstFullBytePosOfSegment */
typedef uint8 IpduM_FirstFullBytePosOfSegmentType;

/**   \brief  value based type definition for IpduM_FullBytesPresentOfSegment */
typedef boolean IpduM_FullBytesPresentOfSegmentType;

/**   \brief  value based type definition for IpduM_LastBytePosOfSegment */
typedef uint8 IpduM_LastBytePosOfSegmentType;

/**   \brief  value based type definition for IpduM_LastFullBytePosOfSegment */
typedef uint8 IpduM_LastFullBytePosOfSegmentType;

/**   \brief  value based type definition for IpduM_LengthOfSegment */
typedef uint8 IpduM_LengthOfSegmentType;

/**   \brief  value based type definition for IpduM_PduBytePosOfSegment */
typedef uint8 IpduM_PduBytePosOfSegmentType;

/**   \brief  value based type definition for IpduM_StartByteMaskClearOfSegment */
typedef uint8 IpduM_StartByteMaskClearOfSegmentType;

/**   \brief  value based type definition for IpduM_StartByteMaskWriteOfSegment */
typedef uint8 IpduM_StartByteMaskWriteOfSegmentType;

/**   \brief  value based type definition for IpduM_SizeOfCTxLoInfo */
typedef uint8 IpduM_SizeOfCTxLoInfoType;

/**   \brief  value based type definition for IpduM_SizeOfCTxPathway */
typedef uint8 IpduM_SizeOfCTxPathwayType;

/**   \brief  value based type definition for IpduM_SizeOfJitUpdateBuffer */
typedef uint8 IpduM_SizeOfJitUpdateBufferType;

/**   \brief  value based type definition for IpduM_SizeOfMainFunctionTxIndirection */
typedef uint8 IpduM_SizeOfMainFunctionTxIndirectionType;

/**   \brief  value based type definition for IpduM_SizeOfSegment */
typedef uint8 IpduM_SizeOfSegmentType;

/**   \brief  value based type definition for IpduM_SizeOfTriggerTransmitBuffer */
typedef uint8 IpduM_SizeOfTriggerTransmitBufferType;

/**   \brief  value based type definition for IpduM_SizeOfTxBuffer */
typedef uint8 IpduM_SizeOfTxBufferType;

/**   \brief  value based type definition for IpduM_SizeOfTxInitValues */
typedef uint8 IpduM_SizeOfTxInitValuesType;

/**   \brief  value based type definition for IpduM_SizeOfTxLoInfoInd */
typedef uint8 IpduM_SizeOfTxLoInfoIndType;

/**   \brief  value based type definition for IpduM_SizeOfTxLoInfoWithInvalidIndexes */
typedef uint8 IpduM_SizeOfTxLoInfoWithInvalidIndexesType;

/**   \brief  value based type definition for IpduM_SizeOfTxPart */
typedef uint8 IpduM_SizeOfTxPartType;

/**   \brief  value based type definition for IpduM_SizeOfTxPartInd */
typedef uint8 IpduM_SizeOfTxPartIndType;

/**   \brief  value based type definition for IpduM_SizeOfTxUpInfo */
typedef uint8 IpduM_SizeOfTxUpInfoType;

/**   \brief  value based type definition for IpduM_SizeOfVTxLoInfo */
typedef uint8 IpduM_SizeOfVTxLoInfoType;

/**   \brief  value based type definition for IpduM_SizeOfVTxPathway */
typedef uint8 IpduM_SizeOfVTxPathwayType;

/**   \brief  value based type definition for IpduM_TriggerTransmitBuffer */
typedef uint8 IpduM_TriggerTransmitBufferType;

/**   \brief  value based type definition for IpduM_TxBuffer */
typedef uint8 IpduM_TxBufferType;

/**   \brief  value based type definition for IpduM_TxInitValues */
typedef uint8 IpduM_TxInitValuesType;

/**   \brief  value based type definition for IpduM_TxLoInfoInd */
/*! \spec strong type invariant () { self < IpduM_GetSizeOfTxLoInfoWithInvalidIndexes() } \endspec */ 
typedef uint8 IpduM_TxLoInfoIndType;

/**   \brief  value based type definition for IpduM_CTxLoInfoIdxOfTxLoInfoWithInvalidIndexes */
/*! \spec strong type invariant () { self < IpduM_GetSizeOfCTxLoInfo() } \endspec */ 
typedef uint8 IpduM_CTxLoInfoIdxOfTxLoInfoWithInvalidIndexesType;

/**   \brief  value based type definition for IpduM_SegmentEndIdxOfTxPart */
/*! \spec strong type invariant () { self < IpduM_GetSizeOfSegment() } \endspec */ 
typedef uint8 IpduM_SegmentEndIdxOfTxPartType;

/**   \brief  value based type definition for IpduM_SegmentStartIdxOfTxPart */
/*! \spec strong type invariant () { self < IpduM_GetSizeOfSegment() } \endspec */ 
typedef uint8 IpduM_SegmentStartIdxOfTxPartType;

/**   \brief  value based type definition for IpduM_TriggerEventOfTxPart */
typedef boolean IpduM_TriggerEventOfTxPartType;

/**   \brief  value based type definition for IpduM_TxPathwayIdxOfTxPart */
/*! \spec strong type invariant () { self < IpduM_GetSizeOfCTxPathway() } \endspec */ 
typedef uint8 IpduM_TxPathwayIdxOfTxPartType;

/**   \brief  value based type definition for IpduM_UlPduRefOfTxPart */
typedef uint8 IpduM_UlPduRefOfTxPartType;

/**   \brief  value based type definition for IpduM_TxPartInd */
/*! \spec strong type invariant () { self < IpduM_GetSizeOfTxPart() } \endspec */ 
typedef uint8 IpduM_TxPartIndType;

/**   \brief  value based type definition for IpduM_PathwayTypeOfTxUpInfo */
typedef uint8 IpduM_PathwayTypeOfTxUpInfoType;

/**   \brief  value based type definition for IpduM_TxUpIndIdxOfTxUpInfo */
/*! \spec strong type invariant () { (self < IpduM_GetSizeOfTxPart()) } \endspec */ 
typedef uint8 IpduM_TxUpIndIdxOfTxUpInfoType;

/**   \brief  value based type definition for IpduM_TxUpIndOfTxUpInfo */
typedef uint8 IpduM_TxUpIndOfTxUpInfoType;

/**   \brief  value based type definition for IpduM_TxConfTimeoutCntOfVTxLoInfo */
typedef uint8 IpduM_TxConfTimeoutCntOfVTxLoInfoType;

/**   \brief  value based type definition for IpduM_TxPartDynamicPartIdxOfTxPathway */
typedef uint8 IpduM_TxPartDynamicPartIdxOfTxPathwayType;

/** 
  \}
*/ 

/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL COMPLEX DATA TYPES AND STRUCTURES
**********************************************************************************************************************/
/** 
  \defgroup  IpduMPCStructTypes  IpduM Struct Types (PRE_COMPILE)
  \brief  These type definitions are used for structured data representations.
  \{
*/ 
/**   \brief  type used in IpduM_CTxLoInfo */
/*! 
 * \spec strong type invariant () { 
 *   (!(self.TxPathwayIdxOfCTxLoInfo != IPDUM_NO_TXPATHWAYIDXOFCTXLOINFO) || (self.TxPathwayIdxOfCTxLoInfo < IpduM_GetSizeOfCTxPathway()))
 * }
 * \endspec 
 */ 
typedef struct sIpduM_CTxLoInfoType
{
  IpduM_TxPathwayIdxOfCTxLoInfoType TxPathwayIdxOfCTxLoInfo;  /**< the index of the 0:1 relation pointing to IpduM_CTxPathway */
} IpduM_CTxLoInfoType;

/**   \brief  type used in IpduM_CTxPathway */
/*! 
 * \spec strong type invariant () { 
 *   (!(self.TxLoInfoIdxOfTxPathway != IPDUM_NO_TXLOINFOIDXOFTXPATHWAY) || (self.TxLoInfoIdxOfTxPathway < IpduM_GetSizeOfTxLoInfoWithInvalidIndexes())) &&
 *   (!(self.TxPartStaticPartIdxOfTxPathway != IPDUM_NO_TXPARTSTATICPARTIDXOFTXPATHWAY) || (self.TxPartStaticPartIdxOfTxPathway < IpduM_GetSizeOfTxPart()))
 * }
 * \endspec 
 */ 
typedef struct sIpduM_CTxPathwayType
{
  IpduM_TxStaticPduRefUsedOfTxPathwayType TxStaticPduRefUsedOfTxPathway;  /**< TRUE, if the index value in TxStaticPduRef is valid. */
  IpduM_TxLoInfoIdxOfTxPathwayType TxLoInfoIdxOfTxPathway;  /**< the index of the 0:1 relation pointing to IpduM_TxLoInfoWithInvalidIndexes */
  IpduM_TxPartStaticPartIdxOfTxPathwayType TxPartStaticPartIdxOfTxPathway;  /**< the index of the 0:1 relation pointing to IpduM_TxPart */
} IpduM_CTxPathwayType;

/**   \brief  type used in IpduM_MainFunctionTxIndirection */
/*! 
 * \spec strong type invariant () { 
 *   (!(self.TxLoInfoIndStartIdxOfMainFunctionTxIndirection != IPDUM_NO_TXLOINFOINDSTARTIDXOFMAINFUNCTIONTXINDIRECTION) || (self.TxLoInfoIndStartIdxOfMainFunctionTxIndirection < IpduM_GetSizeOfTxLoInfoInd()))
 * }
 * \endspec 
 */ 
typedef struct sIpduM_MainFunctionTxIndirectionType
{
  IpduM_TxLoInfoIndStartIdxOfMainFunctionTxIndirectionType TxLoInfoIndStartIdxOfMainFunctionTxIndirection;  /**< the start index of the 0:n relation pointing to IpduM_TxLoInfoInd */
} IpduM_MainFunctionTxIndirectionType;

/**   \brief  type used in IpduM_Segment */
typedef struct sIpduM_SegmentType
{
  IpduM_FullBytesPresentOfSegmentType FullBytesPresentOfSegment;  /**< True if full bytes exist in this segment. */
  IpduM_EndByteMaskClearOfSegmentType EndByteMaskClearOfSegment;  /**< Mask for the partial end byte: clearing. */
  IpduM_FirstFullBytePosOfSegmentType FirstFullBytePosOfSegment;  /**< Byte position of the first full byte. */
  IpduM_LastFullBytePosOfSegmentType LastFullBytePosOfSegment;  /**< Byte position of the last full byte. */
  IpduM_LengthOfSegmentType LengthOfSegment;  /**< the DefinitionRef: /MICROSAR/IpduM/IpduMConfig/IpduMRxPathway/IpduMRxIndication/IpduMRxDynamicPart/IpduMSegment/IpduMSegmentLength. */
  IpduM_StartByteMaskWriteOfSegmentType StartByteMaskWriteOfSegment;  /**< Mask for the partial start byte: writing. */
} IpduM_SegmentType;

/**   \brief  type used in IpduM_TxLoInfoWithInvalidIndexes */
typedef struct sIpduM_TxLoInfoWithInvalidIndexesType
{
  uint8 IpduM_TxLoInfoWithInvalidIndexesNeverUsed;  /**< dummy entry for the structure in the configuration variant precompile which is not used by the code. */
} IpduM_TxLoInfoWithInvalidIndexesType;

/**   \brief  type used in IpduM_TxPart */
/*! 
 * \spec strong type invariant () { 
 *   (self.SegmentEndIdxOfTxPart < IpduM_GetSizeOfSegment()) &&
 *   (self.SegmentStartIdxOfTxPart < IpduM_GetSizeOfSegment()) &&
 *   (self.TxPathwayIdxOfTxPart < IpduM_GetSizeOfCTxPathway())
 * }
 * \endspec 
 */ 
typedef struct sIpduM_TxPartType
{
  IpduM_SegmentEndIdxOfTxPartType SegmentEndIdxOfTxPart;  /**< the end index of the 1:n relation pointing to IpduM_Segment */
  IpduM_SegmentStartIdxOfTxPartType SegmentStartIdxOfTxPart;  /**< the start index of the 1:n relation pointing to IpduM_Segment */
  IpduM_TxPathwayIdxOfTxPartType TxPathwayIdxOfTxPart;  /**< the index of the 1:1 relation pointing to IpduM_CTxPathway */
  IpduM_UlPduRefOfTxPartType UlPduRefOfTxPart;  /**< the DefinitionRef: /MICROSAR/IpduM/IpduMConfig/IpduMTxPathway/IpduMTxRequest/IpduMTxStaticPart/IpduMTxStaticPduRef or DefinitionRef: /MICROSAR/IpduM/IpduMConfig/IpduMTxPathway/IpduMTxRequest/IpduMTxDynamicPart/IpduMTxDynamicPduRef */
} IpduM_TxPartType;

/**   \brief  type used in IpduM_TxUpInfo */
typedef struct sIpduM_TxUpInfoType
{
  IpduM_TxUpIndOfTxUpInfoType TxUpIndOfTxUpInfo;  /**< the enum value of the according target of the 1:1 relation pointing to one of IpduM_TxPart,IpduM_TxContainedPdu */
} IpduM_TxUpInfoType;

/**   \brief  type used in IpduM_VTxLoInfo */
typedef struct sIpduM_VTxLoInfoType
{
  IpduM_TxConfTimeoutCntOfVTxLoInfoType TxConfTimeoutCntOfVTxLoInfo;  /**< I-PDU based TX confirmation timeout counters. */
} IpduM_VTxLoInfoType;

/**   \brief  type used in IpduM_VTxPathway */
typedef struct sIpduM_VTxPathwayType
{
  IpduM_TxPartDynamicPartIdxOfTxPathwayType TxPartDynamicPartIdxOfTxPathway;  /**< the index of the 1:1 relation pointing to IpduM_TxPart */
} IpduM_VTxPathwayType;

/** 
  \}
*/ 

/** 
  \defgroup  IpduMPCSymbolicStructTypes  IpduM Symbolic Struct Types (PRE_COMPILE)
  \brief  These structs are used in unions to have a symbol based data representation style.
  \{
*/ 
/**   \brief  type to be used as symbolic data element access to IpduM_JitUpdateBuffer */
typedef struct IpduM_JitUpdateBufferStructSTag
{
  IpduM_JitUpdateBufferType IpduMTxRequest_30b6d8a0[32];
} IpduM_JitUpdateBufferStructSType;

/**   \brief  type to be used as symbolic data element access to IpduM_TriggerTransmitBuffer */
typedef struct IpduM_TriggerTransmitBufferStructSTag
{
  IpduM_TriggerTransmitBufferType IpduMTxRequest_30b6d8a0[32];
} IpduM_TriggerTransmitBufferStructSType;

/**   \brief  type to be used as symbolic data element access to IpduM_TxBuffer */
typedef struct IpduM_TxBufferStructSTag
{
  IpduM_TxBufferType IpduMTxRequest_30b6d8a0[32];
} IpduM_TxBufferStructSType;

/**   \brief  type to be used as symbolic data element access to IpduM_VTxPathway */
typedef struct IpduM_VTxPathwayStructSTag
{
  IpduM_VTxPathwayType IpduMTxRequest_30b6d8a0;
} IpduM_VTxPathwayStructSType;

/** 
  \}
*/ 

/** 
  \defgroup  IpduMPCUnionIndexAndSymbolTypes  IpduM Union Index And Symbol Types (PRE_COMPILE)
  \brief  These unions are used to access arrays in an index and symbol based style.
  \{
*/ 
/**   \brief  type to access IpduM_JitUpdateBuffer in an index and symbol based style. */
typedef union IpduM_JitUpdateBufferUTag
{  /* PRQA S 0750 */  /* MD_CSL_Union */
  IpduM_JitUpdateBufferType raw[32];
  IpduM_JitUpdateBufferStructSType str;
} IpduM_JitUpdateBufferUType;

/**   \brief  type to access IpduM_TriggerTransmitBuffer in an index and symbol based style. */
typedef union IpduM_TriggerTransmitBufferUTag
{  /* PRQA S 0750 */  /* MD_CSL_Union */
  IpduM_TriggerTransmitBufferType raw[32];
  IpduM_TriggerTransmitBufferStructSType str;
} IpduM_TriggerTransmitBufferUType;

/**   \brief  type to access IpduM_TxBuffer in an index and symbol based style. */
typedef union IpduM_TxBufferUTag
{  /* PRQA S 0750 */  /* MD_CSL_Union */
  IpduM_TxBufferType raw[32];
  IpduM_TxBufferStructSType str;
} IpduM_TxBufferUType;

/**   \brief  type to access IpduM_VTxPathway in an index and symbol based style. */
typedef union IpduM_VTxPathwayUTag
{  /* PRQA S 0750 */  /* MD_CSL_Union */
  IpduM_VTxPathwayType raw[1];
  IpduM_VTxPathwayStructSType str;
} IpduM_VTxPathwayUType;

/** 
  \}
*/ 

/** 
  \defgroup  IpduMPCRootPointerTypes  IpduM Root Pointer Types (PRE_COMPILE)
  \brief  These type definitions are used to point from the config root to symbol instances.
  \{
*/ 
/**   \brief  type used to point to IpduM_CTxLoInfo */
typedef P2CONST(IpduM_CTxLoInfoType, TYPEDEF, IPDUM_CONST) IpduM_CTxLoInfoPtrType;

/**   \brief  type used to point to IpduM_CTxPathway */
typedef P2CONST(IpduM_CTxPathwayType, TYPEDEF, IPDUM_CONST) IpduM_CTxPathwayPtrType;

/**   \brief  type used to point to IpduM_Initialized */
typedef P2VAR(IpduM_InitializedType, TYPEDEF, IPDUM_VAR_CLEARED) IpduM_InitializedPtrType;

/**   \brief  type used to point to IpduM_JitUpdateBuffer */
typedef P2VAR(IpduM_JitUpdateBufferType, TYPEDEF, IPDUM_VAR_NO_INIT) IpduM_JitUpdateBufferPtrType;

/**   \brief  type used to point to IpduM_MainFunctionTxIndirection */
typedef P2CONST(IpduM_MainFunctionTxIndirectionType, TYPEDEF, IPDUM_CONST) IpduM_MainFunctionTxIndirectionPtrType;

/**   \brief  type used to point to IpduM_Segment */
typedef P2CONST(IpduM_SegmentType, TYPEDEF, IPDUM_CONST) IpduM_SegmentPtrType;

/**   \brief  type used to point to IpduM_TriggerTransmitBuffer */
typedef P2VAR(IpduM_TriggerTransmitBufferType, TYPEDEF, IPDUM_VAR_NO_INIT) IpduM_TriggerTransmitBufferPtrType;

/**   \brief  type used to point to IpduM_TxBuffer */
typedef P2VAR(IpduM_TxBufferType, TYPEDEF, IPDUM_VAR_NO_INIT) IpduM_TxBufferPtrType;

/**   \brief  type used to point to IpduM_TxInitValues */
typedef P2CONST(IpduM_TxInitValuesType, TYPEDEF, IPDUM_CONST) IpduM_TxInitValuesPtrType;

/**   \brief  type used to point to IpduM_TxLoInfoInd */
typedef P2CONST(IpduM_TxLoInfoIndType, TYPEDEF, IPDUM_CONST) IpduM_TxLoInfoIndPtrType;

/**   \brief  type used to point to IpduM_TxLoInfoWithInvalidIndexes */
typedef P2CONST(IpduM_TxLoInfoWithInvalidIndexesType, TYPEDEF, IPDUM_CONST) IpduM_TxLoInfoWithInvalidIndexesPtrType;

/**   \brief  type used to point to IpduM_TxPart */
typedef P2CONST(IpduM_TxPartType, TYPEDEF, IPDUM_CONST) IpduM_TxPartPtrType;

/**   \brief  type used to point to IpduM_TxPartInd */
typedef P2CONST(IpduM_TxPartIndType, TYPEDEF, IPDUM_CONST) IpduM_TxPartIndPtrType;

/**   \brief  type used to point to IpduM_TxUpInfo */
typedef P2CONST(IpduM_TxUpInfoType, TYPEDEF, IPDUM_CONST) IpduM_TxUpInfoPtrType;

/**   \brief  type used to point to IpduM_VTxLoInfo */
typedef P2VAR(IpduM_VTxLoInfoType, TYPEDEF, IPDUM_VAR_NO_INIT) IpduM_VTxLoInfoPtrType;

/**   \brief  type used to point to IpduM_VTxPathway */
typedef P2VAR(IpduM_VTxPathwayType, TYPEDEF, IPDUM_VAR_NO_INIT) IpduM_VTxPathwayPtrType;

/** 
  \}
*/ 

/** 
  \defgroup  IpduMPCRootValueTypes  IpduM Root Value Types (PRE_COMPILE)
  \brief  These type definitions are used for value representations in root arrays.
  \{
*/ 
/**   \brief  type used in IpduM_PCConfig */
typedef struct sIpduM_PCConfigType
{
  uint8 IpduM_PCConfigNeverUsed;  /**< dummy entry for the structure in the configuration variant precompile which is not used by the code. */
} IpduM_PCConfigType;

typedef IpduM_PCConfigType IpduM_ConfigType;  /**< A structure type is present for data in each configuration class. This typedef redefines the probably different name to the specified one. */

/** 
  \}
*/ 


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
extern CONST(IpduM_CTxLoInfoType, IPDUM_CONST) IpduM_CTxLoInfo[1];
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
extern CONST(IpduM_CTxPathwayType, IPDUM_CONST) IpduM_CTxPathway[1];
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
extern CONST(IpduM_MainFunctionTxIndirectionType, IPDUM_CONST) IpduM_MainFunctionTxIndirection[1];
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
extern CONST(IpduM_SegmentType, IPDUM_CONST) IpduM_Segment[3];
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
extern CONST(IpduM_TxInitValuesType, IPDUM_CONST) IpduM_TxInitValues[32];
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
extern CONST(IpduM_TxPartType, IPDUM_CONST) IpduM_TxPart[4];
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
extern CONST(IpduM_TxUpInfoType, IPDUM_CONST) IpduM_TxUpInfo[4];
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
extern VAR(IpduM_InitializedType, IPDUM_VAR_CLEARED) IpduM_Initialized;
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
extern VAR(IpduM_JitUpdateBufferUType, IPDUM_VAR_NO_INIT) IpduM_JitUpdateBuffer;  /* PRQA S 0759 */  /* MD_CSL_Union */
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
extern VAR(IpduM_TriggerTransmitBufferUType, IPDUM_VAR_NO_INIT) IpduM_TriggerTransmitBuffer;  /* PRQA S 0759 */  /* MD_CSL_Union */
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
extern VAR(IpduM_TxBufferUType, IPDUM_VAR_NO_INIT) IpduM_TxBuffer;  /* PRQA S 0759 */  /* MD_CSL_Union */
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
extern VAR(IpduM_VTxLoInfoType, IPDUM_VAR_NO_INIT) IpduM_VTxLoInfo[1];
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
extern VAR(IpduM_VTxPathwayUType, IPDUM_VAR_NO_INIT) IpduM_VTxPathway;  /* PRQA S 0759 */  /* MD_CSL_Union */
#define IPDUM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "IpduM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */


/**********************************************************************************************************************
  CONFIGURATION CLASS: LINK
  SECTION: GLOBAL DATA PROTOTYPES
**********************************************************************************************************************/


/**********************************************************************************************************************
  GLOBAL FUNCTION PROTOTYPES
**********************************************************************************************************************/
/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL FUNCTION PROTOTYPES
**********************************************************************************************************************/

/**********************************************************************************************************************
  CONFIGURATION CLASS: LINK
  SECTION: GLOBAL FUNCTION PROTOTYPES
**********************************************************************************************************************/


#endif  /* IPDUM_LCFG_H */
/**********************************************************************************************************************
  END OF FILE: IpduM_Lcfg.h
**********************************************************************************************************************/

