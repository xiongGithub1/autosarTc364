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
 *            Module: ComM
 *           Program: MSR_Vector_SLP4
 *          Customer: China Lithium Battery Technology Co., Ltd.
 *       Expiry Date: 2025-08-26
 *  Ordered Derivat.: SAK-TC387QP-160F300S AE
 *    License Scope : The usage is restricted to CBD2200508_D00
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: ComM_Cfg.h
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


#if !defined(COMM_CFG_H)
#define COMM_CFG_H

/* -----------------------------------------------------------------------------
    &&&~ INCLUDES
 ----------------------------------------------------------------------------- */

#include "ComM_Types.h"
#include "Com_Types.h"
#include "Os.h"
/* -----------------------------------------------------------------------------
    &&&~ CONFIGURATION DEFINES
 ----------------------------------------------------------------------------- */

#ifndef COMM_USE_DUMMY_STATEMENT
#define COMM_USE_DUMMY_STATEMENT STD_OFF /* /MICROSAR/vSet/vSetGeneral/vSetDummyStatementKind */
#endif
#ifndef COMM_DUMMY_STATEMENT
#define COMM_DUMMY_STATEMENT(v)  /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */  /* /MICROSAR/vSet/vSetGeneral/vSetDummyStatementKind */
#endif
#ifndef COMM_DUMMY_STATEMENT_CONST
#define COMM_DUMMY_STATEMENT_CONST(v)  /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */  /* /MICROSAR/vSet/vSetGeneral/vSetDummyStatementKind */
#endif
#ifndef COMM_ATOMIC_BIT_ACCESS_IN_BITFIELD
#define COMM_ATOMIC_BIT_ACCESS_IN_BITFIELD STD_OFF /* /MICROSAR/EcuC/EcucGeneral/AtomicBitAccessInBitfield */
#endif
#ifndef COMM_ATOMIC_VARIABLE_ACCESS
#define COMM_ATOMIC_VARIABLE_ACCESS 32u /* /MICROSAR/EcuC/EcucGeneral/AtomicVariableAccess */
#endif
#ifndef COMM_PROCESSOR_TC387Q
#define COMM_PROCESSOR_TC387Q
#endif
#ifndef COMM_COMP_TASKING
#define COMM_COMP_TASKING
#endif
#ifndef COMM_GEN_GENERATOR_MSR
#define COMM_GEN_GENERATOR_MSR
#endif
#ifndef COMM_CPUTYPE_BITORDER_LSB2MSB
#define COMM_CPUTYPE_BITORDER_LSB2MSB /* /MICROSAR/vSet/vSetPlatform/vSetBitOrder */
#endif
#ifndef COMM_CONFIGURATION_VARIANT_PRECOMPILE
#define COMM_CONFIGURATION_VARIANT_PRECOMPILE 1
#endif
#ifndef COMM_CONFIGURATION_VARIANT_LINKTIME
#define COMM_CONFIGURATION_VARIANT_LINKTIME 2
#endif
#ifndef COMM_CONFIGURATION_VARIANT_POSTBUILD_LOADABLE
#define COMM_CONFIGURATION_VARIANT_POSTBUILD_LOADABLE 3
#endif
#ifndef COMM_CONFIGURATION_VARIANT
#define COMM_CONFIGURATION_VARIANT COMM_CONFIGURATION_VARIANT_PRECOMPILE
#endif
#ifndef COMM_POSTBUILD_VARIANT_SUPPORT
#define COMM_POSTBUILD_VARIANT_SUPPORT STD_OFF
#endif

#ifndef COMM_DEV_ERROR_DETECT
#define COMM_DEV_ERROR_DETECT STD_ON
#endif
#ifndef COMM_DEV_ERROR_REPORT
#define COMM_DEV_ERROR_REPORT STD_ON
#endif

#define COMM_VERSION_INFO_API                                             STD_OFF

#define COMM_MODE_LIMITATION                                              STD_OFF
#define COMM_WAKEUP_INHIBITION                                            STD_OFF

#define COMM_PNC_SUPPORT                                                  STD_OFF
#define COMM_PNC_ACTIVE_COORD                                             STD_OFF
#define COMM_PNC_PS_TIMER                                                 0u
#define COMM_ACTIVE_PNC                                                   0u
#define COMM_PNC_EXTENDED_FUNCTIONALITY_ENABLED                           STD_OFF

#define COMM_SYNCHRONIZED_PNC_SHUTDOWN_ENABLED                            STD_OFF

#define COMM_PNC_TO_CHANNEL_ROUTING_LIMITATION_ENABLED                    STD_OFF
#define COMM_PNC_PASSIVE_GW_SUPPORT                                       STD_OFF
#define COMM_PNC_EXISTS_COORD_PNC_WITH_GW_PASSIVE_AND_MANAGED_CHANNELS    STD_OFF
#define COMM_PNC_EXISTS_GATEWAY_TYPE_ACTIVE                               STD_OFF
#define COMM_PNC_EXISTS_GATEWAY_TYPE_NONE                                 STD_OFF
#define COMM_PNC_SIGNAL_LENGTH                                            0u
#define COMM_PNC_MAX_NUMBER_OF_EIRA_RX                                    0u
#define COMM_PNC_CHECK_ENABLED_AT_RUNTIME                                 STD_OFF
#define COMM_PNC_0_VECTOR_AVOIDANCE                                       STD_OFF

#define COMM_NM_GW_EXT_ENABLED                                            STD_OFF
#define COMM_KEEP_AWAKE_CHANNELS_SUPPORT                                  STD_ON
#define COMM_BUS_TYPE_INTERNAL_PRESENT                                    STD_OFF
#define COMM_BUS_TYPE_FR_PRESENT                                          STD_OFF
#define COMM_BUS_TYPE_LIN_PRESENT                                         STD_OFF
#define COMM_EXISTS_ONLY_NONE_NMTYPEOFCHANNEL                             STD_ON

#define COMM_FULL_COMM_REQUEST_NOTIF                                      STD_OFF
#define COMM_MAX_NUMBER_OF_USERS                                          1u
#define COMM_DCM_INDICATION                                               STD_OFF
#define COMM_USERMODENOTIFUNC_PNC_USER_ONLY                               STD_ON
#define COMM_EXISTS_USER_WITH_SINGLE_PNC                                  STD_OFF

#define COMM_SYNCHRONOUS_WAKE_UP                                          STD_ON
#define COMM_EXTENDED_RAM_CHECK                                           STD_OFF

#define COMM_NVM_SUPPORT                                                  STD_OFF

#define COMM_MULTIPARTITION                                               STD_OFF
#define COMM_EXISTS_CHANNEL_ON_MASTER_PARTITION                           STD_ON



#define COMM_MASTER_PARTITION_IDX                       0u
#define COMM_SINGLEPARTITION                            0u

#define COMM_NO_SYMBOLICNAMEVALUE                       65535u
/* -----------------------------------------------------------------------------
    &&&~ USER HANDLES
 ----------------------------------------------------------------------------- */

#define ComMConf_ComMUser_CN_CAN00_06ecbb07 0u 


/* -----------------------------------------------------------------------------
    &&&~ CHANNEL HANDLES
 ----------------------------------------------------------------------------- */

#define ComMConf_ComMChannel_CN_CAN00_5e566ad9 0u 


/* -----------------------------------------------------------------------------
    &&&~ PNC HANDLES
 ----------------------------------------------------------------------------- */



/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL CONSTANT MACROS
**********************************************************************************************************************/
/** 
  \defgroup  ComMPCDataSwitches  ComM Data Switches  (PRE_COMPILE)
  \brief  These defines are used to deactivate data and their processing.
  \{
*/ 
#define COMM_ACTIVECOMMODE                                                                          STD_ON
#define COMM_ACTIVEPNCCOMMODE                                                                       STD_OFF  /**< Deactivateable: 'ComM_ActivePncComMode' Reason: 'PNC Support is disabled' */
#define COMM_BUSCOMMODEREQ                                                                          STD_ON
#define COMM_BUSCOMMODEREQFRSHUTDOWN                                                                STD_OFF  /**< Deactivateable: 'ComM_BusComModeReqFrShutdown' Reason: 'Fr support is not present' */
#define COMM_BUSPNCCOMMODEREQ                                                                       STD_OFF  /**< Deactivateable: 'ComM_BusPncComModeReq' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COMM_BUSSLEEPMODEINDICATED                                                                  STD_OFF  /**< Deactivateable: 'ComM_BusSleepModeIndicated' Reason: 'NM variant LINSLAVE is not present' */
#define COMM_BUSSMSTATE                                                                             STD_ON
#define COMM_CHANNEL                                                                                STD_ON
#define COMM_BUSTYPEOFCHANNEL                                                                       STD_ON
#define COMM_ENABLEDOFCHANNEL                                                                       STD_OFF  /**< Deactivateable: 'ComM_Channel.Enabled' Reason: 'the value of ComM_EnabledOfChannel is always 'true' due to this, the array is deactivated.' */
#define COMM_GETCURRENTBUSSMMODEAPIOFCHANNEL                                                        STD_ON
#define COMM_GWTYPEOFCHANNEL                                                                        STD_ON
#define COMM_INHIBITIONINITVALUEOFCHANNEL                                                           STD_ON
#define COMM_J1939SUPPORTOFCHANNEL                                                                  STD_OFF  /**< Deactivateable: 'ComM_Channel.J1939Support' Reason: 'the value of ComM_J1939SupportOfChannel is always 'false' due to this, the array is deactivated.' */
#define COMM_MAINFUNCTIONNEEDSSYNCOFCHANNEL                                                         STD_OFF  /**< Deactivateable: 'ComM_Channel.MainFunctionNeedsSync' Reason: 'Configuration is single partition.' */
#define COMM_MANAGINGCHANNELIDOFCHANNEL                                                             STD_OFF  /**< Deactivateable: 'ComM_Channel.ManagingChannelId' Reason: 'the value of ComM_ManagingChannelIdOfChannel is always 'COMM_NO_MANAGINGCHANNELIDOFCHANNEL' due to this, the array is deactivated.' */
#define COMM_MANAGINGCHANNELOFCHANNEL                                                               STD_OFF  /**< Deactivateable: 'ComM_Channel.ManagingChannel' Reason: 'the value of ComM_ManagingChannelOfChannel is always 'false' due to this, the array is deactivated.' */
#define COMM_MANAGINGUSEROFCHANNEL                                                                  STD_OFF  /**< Deactivateable: 'ComM_Channel.ManagingUser' Reason: 'the value of ComM_ManagingUserOfChannel is always 'COMM_NO_MANAGINGUSEROFCHANNEL' due to this, the array is deactivated.' */
#define COMM_MINFULLCOMTIMEOFCHANNEL                                                                STD_OFF  /**< Deactivateable: 'ComM_Channel.MinFullComTime' Reason: 'the value of ComM_MinFullComTimeOfChannel is always '0' due to this, the array is deactivated.' */
#define COMM_NMLIGHTDURATIONOFCHANNEL                                                               STD_OFF  /**< Deactivateable: 'ComM_Channel.NmLightDuration' Reason: 'the value of ComM_NmLightDurationOfChannel is always '0' due to this, the array is deactivated.' */
#define COMM_NMLIGHTSILENTDURATIONOFCHANNEL                                                         STD_OFF  /**< Deactivateable: 'ComM_Channel.NmLightSilentDuration' Reason: 'the value of ComM_NmLightSilentDurationOfChannel is always '0' due to this, the array is deactivated.' */
#define COMM_NMSUPPORTOFCHANNEL                                                                     STD_OFF  /**< Deactivateable: 'ComM_Channel.NmSupport' Reason: 'the value of ComM_NmSupportOfChannel is always 'false' due to this, the array is deactivated.' */
#define COMM_NMTYPEOFCHANNEL                                                                        STD_ON
#define COMM_PARTITIONCONFIGIDXOFCHANNEL                                                            STD_ON
#define COMM_PASSIVEORLINSLAVEOFCHANNEL                                                             STD_OFF  /**< Deactivateable: 'ComM_Channel.PassiveOrLinSlave' Reason: 'the value of ComM_PassiveOrLinSlaveOfChannel is always 'false' due to this, the array is deactivated.' */
#define COMM_PNCNMREQUESTOFCHANNEL                                                                  STD_OFF  /**< Deactivateable: 'ComM_Channel.PncNmRequest' Reason: 'PNC Support is disabled' */
#define COMM_REQUESTBUSSMMODEAPIOFCHANNEL                                                           STD_ON
#define COMM_RESETAFTERFORCINGNOCOMMOFCHANNEL                                                       STD_OFF  /**< Deactivateable: 'ComM_Channel.ResetAfterForcingNoComm' Reason: 'the value of ComM_ResetAfterForcingNoCommOfChannel is always 'false' due to this, the array is deactivated.' */
#define COMM_SILENTSUPPORTOFCHANNEL                                                                 STD_OFF  /**< Deactivateable: 'ComM_Channel.SilentSupport' Reason: 'the value of ComM_SilentSupportOfChannel is always 'false' due to this, the array is deactivated.' */
#define COMM_WAKEUPSTATEOFCHANNEL                                                                   STD_ON
#define COMM_CHANNELPB                                                                              STD_ON
#define COMM_PNCPBINDENDIDXOFCHANNELPB                                                              STD_OFF  /**< Deactivateable: 'ComM_ChannelPb.PncPbIndEndIdx' Reason: 'the optional indirection is deactivated because PncPbIndUsedOfChannelPb is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COMM_PNCPBINDSTARTIDXOFCHANNELPB                                                            STD_OFF  /**< Deactivateable: 'ComM_ChannelPb.PncPbIndStartIdx' Reason: 'the optional indirection is deactivated because PncPbIndUsedOfChannelPb is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COMM_PNCPBINDUSEDOFCHANNELPB                                                                STD_OFF  /**< Deactivateable: 'ComM_ChannelPb.PncPbIndUsed' Reason: 'the optional indirection is deactivated because PncPbIndUsedOfChannelPb is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COMM_USERREQFULLCOMENDIDXOFCHANNELPB                                                        STD_ON
#define COMM_USERREQFULLCOMSTARTIDXOFCHANNELPB                                                      STD_ON
#define COMM_USERREQFULLCOMUSEDOFCHANNELPB                                                          STD_ON
#define COMM_COMALLOWED                                                                             STD_ON
#define COMM_DCMREQUESTACTIVE                                                                       STD_OFF  /**< Deactivateable: 'ComM_DcmRequestActive' Reason: 'Keep Awake Channel support or Dcm support is disabled' */
#define COMM_ECUMWAKEUPINDICATED                                                                    STD_OFF  /**< Deactivateable: 'ComM_EcuMWakeUpIndicated' Reason: 'Synchronous WakeUp is disabled or no Nm Support is present or no channel is assigned to the master partition.' */
#define COMM_EIRATXSIGNALINDIRECTION                                                                STD_OFF  /**< Deactivateable: 'ComM_EiraTxSignalIndirection' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define COMM_SYMBOLICNAMEVALUEOFEIRATXSIGNALINDIRECTION                                             STD_OFF  /**< Deactivateable: 'ComM_EiraTxSignalIndirection.SymbolicNameValue' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COMM_FINALMAGICNUMBER                                                                       STD_OFF  /**< Deactivateable: 'ComM_FinalMagicNumber' Reason: 'the module configuration does not support flashing of data.' */
#define COMM_FORWARDSYNCHRONIZEDPNCSHUTDOWNINDICATED                                                STD_OFF  /**< Deactivateable: 'ComM_ForwardSynchronizedPncShutdownIndicated' Reason: 'Synchronized PNC Shutdown is disabled or no Intermediate PNC Coordinator exists.' */
#define COMM_FRSHUTDOWN                                                                             STD_OFF  /**< Deactivateable: 'ComM_FrShutdown' Reason: 'Fr support is not present' */
#define COMM_FULLCOMREQUESTERS                                                                      STD_OFF  /**< Deactivateable: 'ComM_FullComRequesters' Reason: 'Deactivated because no channel had ComMFullCommRequestNoficiation enabled' */
#define COMM_INHIBITION                                                                             STD_ON
#define COMM_INITDATAHASHCODE                                                                       STD_OFF  /**< Deactivateable: 'ComM_InitDataHashCode' Reason: 'the module configuration does not support flashing of data.' */
#define COMM_INITSTATUS                                                                             STD_ON
#define COMM_LASTSTATECHANGE                                                                        STD_OFF  /**< Deactivateable: 'ComM_LastStateChange' Reason: 'No user mode Notification configured.' */
#define COMM_MINFULLCOMMODETIMER                                                                    STD_OFF  /**< Deactivateable: 'ComM_MinFullComModeTimer' Reason: 'Min Full Com Timer is disabled' */
#define COMM_NMLIGHTTIMER                                                                           STD_OFF  /**< Deactivateable: 'ComM_NmLightTimer' Reason: 'Nm Light and Nm Light Silent Timers are disabled' */
#define COMM_NMSTARTUPINDICATED                                                                     STD_OFF  /**< Deactivateable: 'ComM_NmStartUpIndicated' Reason: 'Synchronous WakeUp is disabled or no Nm Support is present or no channel is assigned to the master partition.' */
#define COMM_NOTIFYPNCSTATECHANGE                                                                   STD_OFF  /**< Deactivateable: 'ComM_NotifyPncStateChange' Reason: 'No user mode Notification configured.' */
#define COMM_NVMSTOREREQ                                                                            STD_OFF  /**< Deactivateable: 'ComM_NvMStoreReq' Reason: 'NvM support is disabled' */
#define COMM_PARTITIONIDENTIFIERS                                                                   STD_ON
#define COMM_PCPARTITIONCONFIGIDXOFPARTITIONIDENTIFIERS                                             STD_ON
#define COMM_PARTITIONSNVOFPARTITIONIDENTIFIERS                                                     STD_ON
#define COMM_PNC                                                                                    STD_OFF  /**< Deactivateable: 'ComM_Pnc' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define COMM_CLEARMASKOFPNC                                                                         STD_OFF  /**< Deactivateable: 'ComM_Pnc.ClearMask' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COMM_COORDINATEDOFPNC                                                                       STD_OFF  /**< Deactivateable: 'ComM_Pnc.Coordinated' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COMM_INTERMEDIATEPNCCOORDINATOROFPNC                                                        STD_OFF  /**< Deactivateable: 'ComM_Pnc.IntermediatePncCoordinator' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COMM_PNCIDOFPNC                                                                             STD_OFF  /**< Deactivateable: 'ComM_Pnc.PncId' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COMM_SETMASKOFPNC                                                                           STD_OFF  /**< Deactivateable: 'ComM_Pnc.SetMask' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COMM_SYSTEMUSEROFPNC                                                                        STD_OFF  /**< Deactivateable: 'ComM_Pnc.SystemUser' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COMM_TOPLEVELPNCCOORDINATOROFPNC                                                            STD_OFF  /**< Deactivateable: 'ComM_Pnc.TopLevelPncCoordinator' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COMM_WAKEUPENABLEDOFPNC                                                                     STD_OFF  /**< Deactivateable: 'ComM_Pnc.WakeupEnabled' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COMM_PNCCHANNELMAPPING                                                                      STD_OFF  /**< Deactivateable: 'ComM_PncChannelMapping' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COMM_PNCPSLEEPTIMER                                                                         STD_OFF  /**< Deactivateable: 'ComM_PncPSleepTimer' Reason: 'PNC Support is disabled' */
#define COMM_PNCPB                                                                                  STD_OFF  /**< Deactivateable: 'ComM_PncPb' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define COMM_PNCCHANNELMAPPINGENDIDXOFPNCPB                                                         STD_OFF  /**< Deactivateable: 'ComM_PncPb.PncChannelMappingEndIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COMM_PNCCHANNELMAPPINGSTARTIDXOFPNCPB                                                       STD_OFF  /**< Deactivateable: 'ComM_PncPb.PncChannelMappingStartIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COMM_PNCCHANNELMAPPINGUSEDOFPNCPB                                                           STD_OFF  /**< Deactivateable: 'ComM_PncPb.PncChannelMappingUsed' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COMM_PNCSIGNALINDENDIDXOFPNCPB                                                              STD_OFF  /**< Deactivateable: 'ComM_PncPb.PncSignalIndEndIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COMM_PNCSIGNALINDSTARTIDXOFPNCPB                                                            STD_OFF  /**< Deactivateable: 'ComM_PncPb.PncSignalIndStartIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COMM_PNCSIGNALINDUSEDOFPNCPB                                                                STD_OFF  /**< Deactivateable: 'ComM_PncPb.PncSignalIndUsed' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COMM_SIGNALBYTEINDEXOFPNCPB                                                                 STD_OFF  /**< Deactivateable: 'ComM_PncPb.SignalByteIndex' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COMM_USERREQPNCFULLCOMENDIDXOFPNCPB                                                         STD_OFF  /**< Deactivateable: 'ComM_PncPb.UserReqPncFullComEndIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COMM_USERREQPNCFULLCOMSTARTIDXOFPNCPB                                                       STD_OFF  /**< Deactivateable: 'ComM_PncPb.UserReqPncFullComStartIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COMM_PNCPBIND                                                                               STD_OFF  /**< Deactivateable: 'ComM_PncPbInd' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COMM_PNCSIGNAL                                                                              STD_OFF  /**< Deactivateable: 'ComM_PncSignal' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define COMM_BUSTYPEIDOFPNCSIGNAL                                                                   STD_OFF  /**< Deactivateable: 'ComM_PncSignal.BusTypeId' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COMM_CHANNELIDXOFPNCSIGNAL                                                                  STD_OFF  /**< Deactivateable: 'ComM_PncSignal.ChannelIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COMM_CHANNELUSEDOFPNCSIGNAL                                                                 STD_OFF  /**< Deactivateable: 'ComM_PncSignal.ChannelUsed' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COMM_PNCSIGNALVALUESENDIDXOFPNCSIGNAL                                                       STD_OFF  /**< Deactivateable: 'ComM_PncSignal.PncSignalValuesEndIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COMM_PNCSIGNALVALUESSTARTIDXOFPNCSIGNAL                                                     STD_OFF  /**< Deactivateable: 'ComM_PncSignal.PncSignalValuesStartIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COMM_PNCSIGNALVALUESUSEDOFPNCSIGNAL                                                         STD_OFF  /**< Deactivateable: 'ComM_PncSignal.PncSignalValuesUsed' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COMM_TYPEOFPNCSIGNAL                                                                        STD_OFF  /**< Deactivateable: 'ComM_PncSignal.Type' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COMM_PNCSIGNALIND                                                                           STD_OFF  /**< Deactivateable: 'ComM_PncSignalInd' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COMM_PNCSIGNALVALUES                                                                        STD_OFF  /**< Deactivateable: 'ComM_PncSignalValues' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COMM_PNCTOCHANNELROUTINGSTATE                                                               STD_OFF  /**< Deactivateable: 'ComM_PncToChannelRoutingState' Reason: 'PNC Support is disabled' */
#define COMM_POSTINITIALIZED                                                                        STD_ON
#define COMM_RESETREQUIRED                                                                          STD_OFF  /**< Deactivateable: 'ComM_ResetRequired' Reason: 'NoResetAfterForcingNoCom is not present' */
#define COMM_SIMULATEDSMMODE                                                                        STD_OFF  /**< Deactivateable: 'ComM_SimulatedSmMode' Reason: 'No channel of type 'internal' is present' */
#define COMM_SIZEOFACTIVECOMMODE                                                                    STD_ON
#define COMM_SIZEOFBUSCOMMODEREQ                                                                    STD_ON
#define COMM_SIZEOFBUSSMSTATE                                                                       STD_ON
#define COMM_SIZEOFCHANNEL                                                                          STD_ON
#define COMM_SIZEOFCHANNELPB                                                                        STD_ON
#define COMM_SIZEOFCOMALLOWED                                                                       STD_ON
#define COMM_SIZEOFPARTITIONIDENTIFIERS                                                             STD_ON
#define COMM_SIZEOFPOSTINITIALIZED                                                                  STD_ON
#define COMM_SIZEOFUSER                                                                             STD_ON
#define COMM_SIZEOFUSERBYTEMASK                                                                     STD_ON
#define COMM_SIZEOFUSERREQFULLCOM                                                                   STD_ON
#define COMM_STATECHANGE                                                                            STD_OFF  /**< Deactivateable: 'ComM_StateChange' Reason: 'No user mode Notification configured.' */
#define COMM_USER                                                                                   STD_ON
#define COMM_PNCUSEROFUSER                                                                          STD_ON
#define COMM_USERBYTEMASKENDIDXOFUSER                                                               STD_ON
#define COMM_USERBYTEMASKSTARTIDXOFUSER                                                             STD_ON
#define COMM_USERBYTEMASKUSEDOFUSER                                                                 STD_ON
#define COMM_USERPNCBYTEMASKENDIDXOFUSER                                                            STD_OFF  /**< Deactivateable: 'ComM_User.UserPncByteMaskEndIdx' Reason: 'the optional indirection is deactivated because UserPncByteMaskUsedOfUser is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COMM_USERPNCBYTEMASKLENGTHOFUSER                                                            STD_OFF  /**< Deactivateable: 'ComM_User.UserPncByteMaskLength' Reason: 'the optional indirection is deactivated because UserPncByteMaskUsedOfUser is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COMM_USERPNCBYTEMASKSTARTIDXOFUSER                                                          STD_OFF  /**< Deactivateable: 'ComM_User.UserPncByteMaskStartIdx' Reason: 'the optional indirection is deactivated because UserPncByteMaskUsedOfUser is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COMM_USERPNCBYTEMASKUSEDOFUSER                                                              STD_OFF  /**< Deactivateable: 'ComM_User.UserPncByteMaskUsed' Reason: 'the optional indirection is deactivated because UserPncByteMaskUsedOfUser is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COMM_USERBYTEMASK                                                                           STD_ON
#define COMM_CHANNELOFUSERBYTEMASK                                                                  STD_ON
#define COMM_CLEARMASKOFUSERBYTEMASK                                                                STD_ON
#define COMM_SETMASKOFUSERBYTEMASK                                                                  STD_ON
#define COMM_USERREQFULLCOMIDXOFUSERBYTEMASK                                                        STD_ON
#define COMM_USERMODENOTIFUNC                                                                       STD_OFF  /**< Deactivateable: 'ComM_UserModeNotiFunc' Reason: 'No user mode Notification configured.' */
#define COMM_USERPNCBYTEMASK                                                                        STD_OFF  /**< Deactivateable: 'ComM_UserPncByteMask' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define COMM_CLEARMASKOFUSERPNCBYTEMASK                                                             STD_OFF  /**< Deactivateable: 'ComM_UserPncByteMask.ClearMask' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COMM_PNCIDOFUSERPNCBYTEMASK                                                                 STD_OFF  /**< Deactivateable: 'ComM_UserPncByteMask.PncID' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COMM_PNCIDXOFUSERPNCBYTEMASK                                                                STD_OFF  /**< Deactivateable: 'ComM_UserPncByteMask.PncIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COMM_SETMASKOFUSERPNCBYTEMASK                                                               STD_OFF  /**< Deactivateable: 'ComM_UserPncByteMask.SetMask' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COMM_USERREQPNCFULLCOMIDXOFUSERPNCBYTEMASK                                                  STD_OFF  /**< Deactivateable: 'ComM_UserPncByteMask.UserReqPncFullComIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COMM_USERREQFULLCOM                                                                         STD_ON
#define COMM_USERREQPNCFULLCOM                                                                      STD_OFF  /**< Deactivateable: 'ComM_UserReqPncFullCom' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COMM_PCCONFIG                                                                               STD_ON
#define COMM_FINALMAGICNUMBEROFPCCONFIG                                                             STD_OFF  /**< Deactivateable: 'ComM_PCConfig.FinalMagicNumber' Reason: 'the module configuration does not support flashing of data.' */
#define COMM_INITDATAHASHCODEOFPCCONFIG                                                             STD_OFF  /**< Deactivateable: 'ComM_PCConfig.InitDataHashCode' Reason: 'the module configuration does not support flashing of data.' */
#define COMM_PCPARTITIONCONFIGOFPCCONFIG                                                            STD_ON
#define COMM_PARTITIONIDENTIFIERSOFPCCONFIG                                                         STD_ON
#define COMM_SIZEOFPARTITIONIDENTIFIERSOFPCCONFIG                                                   STD_ON
#define COMM_PCPARTITIONCONFIG                                                                      STD_ON
#define COMM_ACTIVECOMMODEOFPCPARTITIONCONFIG                                                       STD_ON
#define COMM_BUSCOMMODEREQOFPCPARTITIONCONFIG                                                       STD_ON
#define COMM_BUSSMSTATEOFPCPARTITIONCONFIG                                                          STD_ON
#define COMM_CHANNELOFPCPARTITIONCONFIG                                                             STD_ON
#define COMM_CHANNELPBOFPCPARTITIONCONFIG                                                           STD_ON
#define COMM_COMALLOWEDOFPCPARTITIONCONFIG                                                          STD_ON
#define COMM_INHIBITIONOFPCPARTITIONCONFIG                                                          STD_ON
#define COMM_INITSTATUSOFPCPARTITIONCONFIG                                                          STD_ON
#define COMM_POSTINITIALIZEDOFPCPARTITIONCONFIG                                                     STD_ON
#define COMM_SIZEOFACTIVECOMMODEOFPCPARTITIONCONFIG                                                 STD_ON
#define COMM_SIZEOFBUSCOMMODEREQOFPCPARTITIONCONFIG                                                 STD_ON
#define COMM_SIZEOFBUSSMSTATEOFPCPARTITIONCONFIG                                                    STD_ON
#define COMM_SIZEOFCHANNELOFPCPARTITIONCONFIG                                                       STD_ON
#define COMM_SIZEOFCHANNELPBOFPCPARTITIONCONFIG                                                     STD_ON
#define COMM_SIZEOFCOMALLOWEDOFPCPARTITIONCONFIG                                                    STD_ON
#define COMM_SIZEOFPOSTINITIALIZEDOFPCPARTITIONCONFIG                                               STD_ON
#define COMM_SIZEOFUSERBYTEMASKOFPCPARTITIONCONFIG                                                  STD_ON
#define COMM_SIZEOFUSEROFPCPARTITIONCONFIG                                                          STD_ON
#define COMM_SIZEOFUSERREQFULLCOMOFPCPARTITIONCONFIG                                                STD_ON
#define COMM_USERBYTEMASKOFPCPARTITIONCONFIG                                                        STD_ON
#define COMM_USEROFPCPARTITIONCONFIG                                                                STD_ON
#define COMM_USERREQFULLCOMOFPCPARTITIONCONFIG                                                      STD_ON
/** 
  \}
*/ 

/** 
  \defgroup  ComMPCMinNumericValueDefines  ComM Min Numeric Value Defines (PRE_COMPILE)
  \brief  These defines are used to implement against the minimum value in numerical based data.
  \{
*/ 
#define COMM_MIN_USERREQFULLCOM                                                                     0u
/** 
  \}
*/ 

/** 
  \defgroup  ComMPCMaxNumericValueDefines  ComM Max Numeric Value Defines (PRE_COMPILE)
  \brief  These defines are used to implement against the maximum value in numerical based data.
  \{
*/ 
#define COMM_MAX_USERREQFULLCOM                                                                     255u
/** 
  \}
*/ 

/** 
  \defgroup  ComMPCNoReferenceDefines  ComM No Reference Defines (PRE_COMPILE)
  \brief  These defines are used to indicate unused indexes in data relations.
  \{
*/ 
#define COMM_NO_USERREQFULLCOMENDIDXOFCHANNELPB                                                     255u
#define COMM_NO_USERREQFULLCOMSTARTIDXOFCHANNELPB                                                   255u
#define COMM_NO_USERBYTEMASKENDIDXOFUSER                                                            255u
#define COMM_NO_USERBYTEMASKSTARTIDXOFUSER                                                          255u
/** 
  \}
*/ 

/** 
  \defgroup  ComMPCEnumExistsDefines  ComM Enum Exists Defines (PRE_COMPILE)
  \brief  These defines can be used to deactivate enumeration based code sequences if the enumeration value does not exist in the configuration data.
  \{
*/ 
#define COMM_EXISTS_NOT_USED_IN_THIS_VARIANT_NMTYPEOFCHANNEL                                        STD_OFF
#define COMM_EXISTS_FULL_NMTYPEOFCHANNEL                                                            STD_OFF
#define COMM_EXISTS_PASSIVE_NMTYPEOFCHANNEL                                                         STD_OFF
#define COMM_EXISTS_LIGHT_NMTYPEOFCHANNEL                                                           STD_OFF
#define COMM_EXISTS_NONE_NMTYPEOFCHANNEL                                                            STD_ON
#define COMM_EXISTS_LINSLAVE_NMTYPEOFCHANNEL                                                        STD_OFF
#define COMM_EXISTS_EIRA_RX_TYPEOFPNCSIGNAL                                                         STD_OFF  /**< Deactivateable: 'ComM_PncSignal.Type' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COMM_EXISTS_EIRA_TX_TYPEOFPNCSIGNAL                                                         STD_OFF  /**< Deactivateable: 'ComM_PncSignal.Type' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COMM_EXISTS_ERA_RX_TYPEOFPNCSIGNAL                                                          STD_OFF  /**< Deactivateable: 'ComM_PncSignal.Type' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COMM_EXISTS_NOT_USED_IN_THIS_VARIANT_TYPEOFPNCSIGNAL                                        STD_OFF  /**< Deactivateable: 'ComM_PncSignal.Type' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
/** 
  \}
*/ 

/** 
  \defgroup  ComMPCEnumDefines  ComM Enum Defines (PRE_COMPILE)
  \brief  These defines are the enumeration values of enumeration based CONST and VAR data.
  \{
*/ 
#define COMM_NONE_NMTYPEOFCHANNEL                                                                   0x04u
/** 
  \}
*/ 

/** 
  \defgroup  ComMPCIsReducedToDefineDefines  ComM Is Reduced To Define Defines (PRE_COMPILE)
  \brief  If all values in a CONST array or an element in a CONST array of structs are equal, the define is STD_ON else STD_OFF.
  \{
*/ 
#define COMM_ISDEF_BUSTYPEOFCHANNEL                                                                 STD_ON
#define COMM_ISDEF_GETCURRENTBUSSMMODEAPIOFCHANNEL                                                  STD_OFF
#define COMM_ISDEF_GWTYPEOFCHANNEL                                                                  STD_ON
#define COMM_ISDEF_INHIBITIONINITVALUEOFCHANNEL                                                     STD_ON
#define COMM_ISDEF_NMTYPEOFCHANNEL                                                                  STD_ON
#define COMM_ISDEF_PARTITIONCONFIGIDXOFCHANNEL                                                      STD_ON
#define COMM_ISDEF_REQUESTBUSSMMODEAPIOFCHANNEL                                                     STD_OFF
#define COMM_ISDEF_WAKEUPSTATEOFCHANNEL                                                             STD_ON
#define COMM_ISDEF_USERREQFULLCOMENDIDXOFCHANNELPB                                                  STD_ON
#define COMM_ISDEF_USERREQFULLCOMSTARTIDXOFCHANNELPB                                                STD_ON
#define COMM_ISDEF_USERREQFULLCOMUSEDOFCHANNELPB                                                    STD_ON
#define COMM_ISDEF_PCPARTITIONCONFIGIDXOFPARTITIONIDENTIFIERS                                       STD_OFF
#define COMM_ISDEF_PARTITIONSNVOFPARTITIONIDENTIFIERS                                               STD_OFF
#define COMM_ISDEF_PNCUSEROFUSER                                                                    STD_OFF
#define COMM_ISDEF_USERBYTEMASKENDIDXOFUSER                                                         STD_ON
#define COMM_ISDEF_USERBYTEMASKSTARTIDXOFUSER                                                       STD_ON
#define COMM_ISDEF_USERBYTEMASKUSEDOFUSER                                                           STD_ON
#define COMM_ISDEF_CHANNELOFUSERBYTEMASK                                                            STD_ON
#define COMM_ISDEF_CLEARMASKOFUSERBYTEMASK                                                          STD_ON
#define COMM_ISDEF_SETMASKOFUSERBYTEMASK                                                            STD_ON
#define COMM_ISDEF_USERREQFULLCOMIDXOFUSERBYTEMASK                                                  STD_ON
#define COMM_ISDEF_PCPARTITIONCONFIGOFPCCONFIG                                                      STD_ON
#define COMM_ISDEF_PARTITIONIDENTIFIERSOFPCCONFIG                                                   STD_ON
#define COMM_ISDEF_ACTIVECOMMODEOFPCPARTITIONCONFIG                                                 STD_ON
#define COMM_ISDEF_BUSCOMMODEREQOFPCPARTITIONCONFIG                                                 STD_ON
#define COMM_ISDEF_BUSSMSTATEOFPCPARTITIONCONFIG                                                    STD_ON
#define COMM_ISDEF_CHANNELOFPCPARTITIONCONFIG                                                       STD_ON
#define COMM_ISDEF_CHANNELPBOFPCPARTITIONCONFIG                                                     STD_ON
#define COMM_ISDEF_COMALLOWEDOFPCPARTITIONCONFIG                                                    STD_ON
#define COMM_ISDEF_INHIBITIONOFPCPARTITIONCONFIG                                                    STD_ON
#define COMM_ISDEF_INITSTATUSOFPCPARTITIONCONFIG                                                    STD_ON
#define COMM_ISDEF_POSTINITIALIZEDOFPCPARTITIONCONFIG                                               STD_ON
#define COMM_ISDEF_USERBYTEMASKOFPCPARTITIONCONFIG                                                  STD_ON
#define COMM_ISDEF_USEROFPCPARTITIONCONFIG                                                          STD_ON
#define COMM_ISDEF_USERREQFULLCOMOFPCPARTITIONCONFIG                                                STD_ON
/** 
  \}
*/ 

/** 
  \defgroup  ComMPCEqualsAlwaysToDefines  ComM Equals Always To Defines (PRE_COMPILE)
  \brief  If all values in a CONST array or an element in a CONST array of structs are equal, the define contains the always equals value.
  \{
*/ 
#define COMM_EQ2_BUSTYPEOFCHANNEL                                                                   COMM_BUS_TYPE_CAN
#define COMM_EQ2_GETCURRENTBUSSMMODEAPIOFCHANNEL                                                    
#define COMM_EQ2_GWTYPEOFCHANNEL                                                                    COMM_GATEWAY_TYPE_NONE
#define COMM_EQ2_INHIBITIONINITVALUEOFCHANNEL                                                       0x00u
#define COMM_EQ2_NMTYPEOFCHANNEL                                                                    COMM_NONE_NMTYPEOFCHANNEL
#define COMM_EQ2_PARTITIONCONFIGIDXOFCHANNEL                                                        0u
#define COMM_EQ2_REQUESTBUSSMMODEAPIOFCHANNEL                                                       
#define COMM_EQ2_WAKEUPSTATEOFCHANNEL                                                               COMM_FULL_COM_NETWORK_REQUESTED
#define COMM_EQ2_USERREQFULLCOMENDIDXOFCHANNELPB                                                    1u
#define COMM_EQ2_USERREQFULLCOMSTARTIDXOFCHANNELPB                                                  0u
#define COMM_EQ2_USERREQFULLCOMUSEDOFCHANNELPB                                                      TRUE
#define COMM_EQ2_PCPARTITIONCONFIGIDXOFPARTITIONIDENTIFIERS                                         
#define COMM_EQ2_PARTITIONSNVOFPARTITIONIDENTIFIERS                                                 
#define COMM_EQ2_PNCUSEROFUSER                                                                      
#define COMM_EQ2_USERBYTEMASKENDIDXOFUSER                                                           1u
#define COMM_EQ2_USERBYTEMASKSTARTIDXOFUSER                                                         0u
#define COMM_EQ2_USERBYTEMASKUSEDOFUSER                                                             TRUE
#define COMM_EQ2_CHANNELOFUSERBYTEMASK                                                              0u
#define COMM_EQ2_CLEARMASKOFUSERBYTEMASK                                                            0xFEu
#define COMM_EQ2_SETMASKOFUSERBYTEMASK                                                              0x01u
#define COMM_EQ2_USERREQFULLCOMIDXOFUSERBYTEMASK                                                    0u
#define COMM_EQ2_PCPARTITIONCONFIGOFPCCONFIG                                                        ComM_PCPartitionConfig
#define COMM_EQ2_PARTITIONIDENTIFIERSOFPCCONFIG                                                     ComM_PartitionIdentifiers
#define COMM_EQ2_ACTIVECOMMODEOFPCPARTITIONCONFIG                                                   ComM_ActiveComMode.raw
#define COMM_EQ2_BUSCOMMODEREQOFPCPARTITIONCONFIG                                                   ComM_BusComModeReq.raw
#define COMM_EQ2_BUSSMSTATEOFPCPARTITIONCONFIG                                                      ComM_BusSmState.raw
#define COMM_EQ2_CHANNELOFPCPARTITIONCONFIG                                                         ComM_Channel
#define COMM_EQ2_CHANNELPBOFPCPARTITIONCONFIG                                                       ComM_ChannelPb
#define COMM_EQ2_COMALLOWEDOFPCPARTITIONCONFIG                                                      ComM_ComAllowed.raw
#define COMM_EQ2_INHIBITIONOFPCPARTITIONCONFIG                                                      (&(ComM_Inhibition))
#define COMM_EQ2_INITSTATUSOFPCPARTITIONCONFIG                                                      (&(ComM_InitStatus))
#define COMM_EQ2_POSTINITIALIZEDOFPCPARTITIONCONFIG                                                 ComM_PostInitialized
#define COMM_EQ2_USERBYTEMASKOFPCPARTITIONCONFIG                                                    ComM_UserByteMask
#define COMM_EQ2_USEROFPCPARTITIONCONFIG                                                            ComM_User
#define COMM_EQ2_USERREQFULLCOMOFPCPARTITIONCONFIG                                                  ComM_UserReqFullCom
/** 
  \}
*/ 

/** 
  \defgroup  ComMPCSymbolicInitializationPointers  ComM Symbolic Initialization Pointers (PRE_COMPILE)
  \brief  Symbolic initialization pointers to be used in the call of a preinit or init function.
  \{
*/ 
#define ComM_Config_Ptr                                                                             NULL_PTR  /**< symbolic identifier which shall be used to initialize 'ComM' */
/** 
  \}
*/ 

/** 
  \defgroup  ComMPCInitializationSymbols  ComM Initialization Symbols (PRE_COMPILE)
  \brief  Symbolic initialization pointers which may be used in the call of a preinit or init function. Please note, that the defined value can be a 'NULL_PTR' and the address operator is not usable.
  \{
*/ 
#define ComM_Config                                                                                 NULL_PTR  /**< symbolic identifier which could be used to initialize 'ComM */
/** 
  \}
*/ 

/** 
  \defgroup  ComMPCGeneral  ComM General (PRE_COMPILE)
  \brief  General constant defines not associated with a group of defines.
  \{
*/ 
#define COMM_CHECK_INIT_POINTER                                                                     STD_OFF  /**< STD_ON if the init pointer shall not be used as NULL_PTR and a check shall validate this. */
#define COMM_FINAL_MAGIC_NUMBER                                                                     0x0C1Eu  /**< the precompile constant to validate the size of the initialization structure at initialization time of ComM */
#define COMM_INDIVIDUAL_POSTBUILD                                                                   STD_OFF  /**< the precompile constant to check, that the module is individual postbuildable. The module 'ComM' is not configured to be postbuild capable. */
#define COMM_INIT_DATA                                                                              COMM_CONST  /**< CompilerMemClassDefine for the initialization data. */
#define COMM_INIT_DATA_HASH_CODE                                                                    -215872543  /**< the precompile constant to validate the initialization structure at initialization time of ComM with a hashcode. The seed value is '0x0C1Eu' */
#define COMM_USE_ECUM_BSW_ERROR_HOOK                                                                STD_OFF  /**< STD_ON if the EcuM_BswErrorHook shall be called in the ConfigPtr check. */
#define COMM_USE_INIT_POINTER                                                                       STD_OFF  /**< STD_ON if the init pointer ComM shall be used. */
/** 
  \}
*/ 


/**********************************************************************************************************************
  CONFIGURATION CLASS: POST_BUILD
  SECTION: GLOBAL CONSTANT MACROS
**********************************************************************************************************************/
/** 
  \defgroup  ComMPBDataSwitches  ComM Data Switches  (POST_BUILD)
  \brief  These defines are used to deactivate data and their processing.
  \{
*/ 
#define COMM_PBCONFIG                                                                               STD_OFF  /**< Deactivateable: 'ComM_PBConfig' Reason: 'the module configuration is VARIANT_PRE_COMPILE.' */
#define COMM_LTCONFIGIDXOFPBCONFIG                                                                  STD_OFF  /**< Deactivateable: 'ComM_PBConfig.LTConfigIdx' Reason: 'the module configuration is VARIANT_PRE_COMPILE.' */
#define COMM_PBPARTITIONCONFIGOFPBCONFIG                                                            STD_OFF  /**< Deactivateable: 'ComM_PBConfig.PBPartitionConfig' Reason: 'the module configuration is VARIANT_PRE_COMPILE.' */
#define COMM_PCCONFIGIDXOFPBCONFIG                                                                  STD_OFF  /**< Deactivateable: 'ComM_PBConfig.PCConfigIdx' Reason: 'the module configuration is VARIANT_PRE_COMPILE.' */
#define COMM_PBPARTITIONCONFIG                                                                      STD_OFF  /**< Deactivateable: 'ComM_PBPartitionConfig' Reason: 'the module configuration is VARIANT_PRE_COMPILE.' */
/** 
  \}
*/ 



/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
**********************************************************************************************************************/
typedef P2FUNC(Std_ReturnType, COMM_CODE, RequestBusSMModeApiType) (NetworkHandleType Channel, ComM_ModeType ComMode);
typedef P2FUNC(Std_ReturnType, COMM_CODE, GetCurrentBusSMModeApiType) (NetworkHandleType Channel, P2VAR(ComM_ModeType, AUTOMATIC, AUTOMATIC) ComMode);
typedef P2FUNC(Std_ReturnType, COMM_CODE, ComM_ForwardingFunctionPtrType) (CONST(NetworkHandleType, AUTOMATIC)); /* PRQA S 1336 */ /* MD_ComM_1336 */

/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: SIZEOF DATA TYPES
**********************************************************************************************************************/
/** 
  \defgroup  ComMPCSizeOfTypes  ComM SizeOf Types (PRE_COMPILE)
  \brief  These type definitions are used for the SizeOf information.
  \{
*/ 
/**   \brief  value based type definition for ComM_SizeOfActiveComMode */
typedef uint8 ComM_SizeOfActiveComModeType;

/**   \brief  value based type definition for ComM_SizeOfBusComModeReq */
typedef uint8 ComM_SizeOfBusComModeReqType;

/**   \brief  value based type definition for ComM_SizeOfBusSmState */
typedef uint8 ComM_SizeOfBusSmStateType;

/**   \brief  value based type definition for ComM_SizeOfChannel */
typedef uint8 ComM_SizeOfChannelType;

/**   \brief  value based type definition for ComM_SizeOfChannelPb */
typedef uint8 ComM_SizeOfChannelPbType;

/**   \brief  value based type definition for ComM_SizeOfComAllowed */
typedef uint8 ComM_SizeOfComAllowedType;

/**   \brief  value based type definition for ComM_SizeOfPartitionIdentifiers */
typedef uint8 ComM_SizeOfPartitionIdentifiersType;

/**   \brief  value based type definition for ComM_SizeOfPostInitialized */
typedef uint8 ComM_SizeOfPostInitializedType;

/**   \brief  value based type definition for ComM_SizeOfUser */
typedef uint8 ComM_SizeOfUserType;

/**   \brief  value based type definition for ComM_SizeOfUserByteMask */
typedef uint8 ComM_SizeOfUserByteMaskType;

/**   \brief  value based type definition for ComM_SizeOfUserReqFullCom */
typedef uint8 ComM_SizeOfUserReqFullComType;

/** 
  \}
*/ 

/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL SIMPLE DATA TYPES AND STRUCTURES
**********************************************************************************************************************/
/** 
  \defgroup  ComMPCIterableTypes  ComM Iterable Types (PRE_COMPILE)
  \brief  These type definitions are used to iterate over an array with least processor cycles for variable access as possible.
  \{
*/ 
/**   \brief  type used to iterate ComM_Channel */
typedef uint8_least ComM_ChannelIterType;

/**   \brief  type used to iterate ComM_ChannelPb */
typedef uint8_least ComM_ChannelPbIterType;

/**   \brief  type used to iterate ComM_PartitionIdentifiers */
typedef uint8_least ComM_PartitionIdentifiersIterType;

/**   \brief  type used to iterate ComM_PostInitialized */
typedef uint8_least ComM_PostInitializedIterType;

/**   \brief  type used to iterate ComM_User */
typedef uint8_least ComM_UserIterType;

/**   \brief  type used to iterate ComM_UserByteMask */
typedef uint8_least ComM_UserByteMaskIterType;

/**   \brief  type used to iterate ComM_UserReqFullCom */
typedef uint8_least ComM_UserReqFullComIterType;

/**   \brief  type used to iterate ComM_PCPartitionConfig */
typedef uint8_least ComM_PCPartitionConfigIterType;

/** 
  \}
*/ 

/** 
  \defgroup  ComMPCIterableTypesWithSizeRelations  ComM Iterable Types With Size Relations (PRE_COMPILE)
  \brief  These type definitions are used to iterate over a VAR based array with the same iterator as the related CONST array.
  \{
*/ 
/**   \brief  type used to iterate ComM_ActiveComMode */
typedef ComM_ChannelIterType ComM_ActiveComModeIterType;

/**   \brief  type used to iterate ComM_BusComModeReq */
typedef ComM_ChannelIterType ComM_BusComModeReqIterType;

/**   \brief  type used to iterate ComM_BusSmState */
typedef ComM_ChannelIterType ComM_BusSmStateIterType;

/**   \brief  type used to iterate ComM_ComAllowed */
typedef ComM_ChannelIterType ComM_ComAllowedIterType;

/** 
  \}
*/ 

/** 
  \defgroup  ComMPCValueTypes  ComM Value Types (PRE_COMPILE)
  \brief  These type definitions are used for value based data representations.
  \{
*/ 
/**   \brief  value based type definition for ComM_GwTypeOfChannel */
typedef uint8 ComM_GwTypeOfChannelType;

/**   \brief  value based type definition for ComM_InhibitionInitValueOfChannel */
typedef uint8 ComM_InhibitionInitValueOfChannelType;

/**   \brief  value based type definition for ComM_NmTypeOfChannel */
typedef uint8 ComM_NmTypeOfChannelType;

/**   \brief  value based type definition for ComM_PartitionConfigIdxOfChannel */
typedef uint8 ComM_PartitionConfigIdxOfChannelType;

/**   \brief  value based type definition for ComM_WakeupStateOfChannel */
typedef uint8 ComM_WakeupStateOfChannelType;

/**   \brief  value based type definition for ComM_UserReqFullComEndIdxOfChannelPb */
typedef uint8 ComM_UserReqFullComEndIdxOfChannelPbType;

/**   \brief  value based type definition for ComM_UserReqFullComStartIdxOfChannelPb */
typedef uint8 ComM_UserReqFullComStartIdxOfChannelPbType;

/**   \brief  value based type definition for ComM_UserReqFullComUsedOfChannelPb */
typedef boolean ComM_UserReqFullComUsedOfChannelPbType;

/**   \brief  value based type definition for ComM_ComAllowed */
typedef boolean ComM_ComAllowedType;

/**   \brief  value based type definition for ComM_PCPartitionConfigIdxOfPartitionIdentifiers */
typedef uint8 ComM_PCPartitionConfigIdxOfPartitionIdentifiersType;

/**   \brief  value based type definition for ComM_PartitionSNVOfPartitionIdentifiers */
typedef uint32 ComM_PartitionSNVOfPartitionIdentifiersType;

/**   \brief  value based type definition for ComM_PostInitialized */
typedef boolean ComM_PostInitializedType;

/**   \brief  value based type definition for ComM_PncUserOfUser */
typedef boolean ComM_PncUserOfUserType;

/**   \brief  value based type definition for ComM_UserByteMaskEndIdxOfUser */
typedef uint8 ComM_UserByteMaskEndIdxOfUserType;

/**   \brief  value based type definition for ComM_UserByteMaskStartIdxOfUser */
typedef uint8 ComM_UserByteMaskStartIdxOfUserType;

/**   \brief  value based type definition for ComM_UserByteMaskUsedOfUser */
typedef boolean ComM_UserByteMaskUsedOfUserType;

/**   \brief  value based type definition for ComM_ChannelOfUserByteMask */
typedef uint8 ComM_ChannelOfUserByteMaskType;

/**   \brief  value based type definition for ComM_ClearMaskOfUserByteMask */
typedef uint8 ComM_ClearMaskOfUserByteMaskType;

/**   \brief  value based type definition for ComM_SetMaskOfUserByteMask */
typedef uint8 ComM_SetMaskOfUserByteMaskType;

/**   \brief  value based type definition for ComM_UserReqFullComIdxOfUserByteMask */
typedef uint8 ComM_UserReqFullComIdxOfUserByteMaskType;

/**   \brief  value based type definition for ComM_UserReqFullCom */
typedef uint8 ComM_UserReqFullComType;

/** 
  \}
*/ 


/* PRQA S 0639, 0779 POSTBUILDGLOBALDATATYPES */ /* MD_MSR_1.1_639, MD_MSR_Rule5.2_0779 */
/**********************************************************************************************************************
  CONFIGURATION CLASS: POST_BUILD
  SECTION: SIZEOF DATA TYPES
**********************************************************************************************************************/
/**********************************************************************************************************************
  CONFIGURATION CLASS: POST_BUILD
  SECTION: GLOBAL SIMPLE DATA TYPES AND STRUCTURES
**********************************************************************************************************************/

/* PRQA L:POSTBUILDGLOBALDATATYPES */

/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL COMPLEX DATA TYPES AND STRUCTURES
**********************************************************************************************************************/
/** 
  \defgroup  ComMPCStructTypes  ComM Struct Types (PRE_COMPILE)
  \brief  These type definitions are used for structured data representations.
  \{
*/ 
/**   \brief  type used in ComM_Channel */
typedef struct sComM_ChannelType
{
  GetCurrentBusSMModeApiType GetCurrentBusSMModeApiOfChannel;  /**< Query the current communication mode from the corresponding BusSM */
  RequestBusSMModeApiType RequestBusSMModeApiOfChannel;  /**< Request the communication mode from the corresponding BusSM */
} ComM_ChannelType;

/**   \brief  type used in ComM_ChannelPb */
typedef struct sComM_ChannelPbType
{
  uint8 ComM_ChannelPbNeverUsed;  /**< dummy entry for the structure in the configuration variant precompile which is not used by the code. */
} ComM_ChannelPbType;

/**   \brief  type used in ComM_PartitionIdentifiers */
typedef struct sComM_PartitionIdentifiersType
{
  ComM_PartitionSNVOfPartitionIdentifiersType PartitionSNVOfPartitionIdentifiers;
  ComM_PCPartitionConfigIdxOfPartitionIdentifiersType PCPartitionConfigIdxOfPartitionIdentifiers;  /**< the index of the 1:1 relation pointing to ComM_PCPartitionConfig */
} ComM_PartitionIdentifiersType;

/**   \brief  type used in ComM_User */
typedef struct sComM_UserType
{
  ComM_PncUserOfUserType PncUserOfUser;  /**< decides if a user is a partial network user or a direct channel user */
} ComM_UserType;

/**   \brief  type used in ComM_UserByteMask */
typedef struct sComM_UserByteMaskType
{
  uint8 ComM_UserByteMaskNeverUsed;  /**< dummy entry for the structure in the configuration variant precompile which is not used by the code. */
} ComM_UserByteMaskType;

/** 
  \}
*/ 

/** 
  \defgroup  ComMPCSymbolicStructTypes  ComM Symbolic Struct Types (PRE_COMPILE)
  \brief  These structs are used in unions to have a symbol based data representation style.
  \{
*/ 
/**   \brief  type to be used as symbolic data element access to ComM_ActiveComMode in the partition context  */
typedef struct ComM_ActiveComModeStructSTag
{
  ComM_StateType ComMChannel_0;
} ComM_ActiveComModeStructSType;

/**   \brief  type to be used as symbolic data element access to ComM_BusComModeReq in the partition context  */
typedef struct ComM_BusComModeReqStructSTag
{
  ComM_StateType ComMChannel_0;
} ComM_BusComModeReqStructSType;

/**   \brief  type to be used as symbolic data element access to ComM_BusSmState in the partition context  */
typedef struct ComM_BusSmStateStructSTag
{
  ComM_ModeType ComMChannel_0;
} ComM_BusSmStateStructSType;

/**   \brief  type to be used as symbolic data element access to ComM_ComAllowed in the partition context  */
typedef struct ComM_ComAllowedStructSTag
{
  ComM_ComAllowedType ComMChannel_0;
} ComM_ComAllowedStructSType;

/** 
  \}
*/ 

/** 
  \defgroup  ComMPCUnionIndexAndSymbolTypes  ComM Union Index And Symbol Types (PRE_COMPILE)
  \brief  These unions are used to access arrays in an index and symbol based style.
  \{
*/ 
/**   \brief  type to access ComM_ActiveComMode in an index and symbol based style. */
typedef union ComM_ActiveComModeUTag
{  /* PRQA S 0750 */  /* MD_CSL_Union */
  ComM_StateType raw[1];
  ComM_ActiveComModeStructSType str;
} ComM_ActiveComModeUType;

/**   \brief  type to access ComM_BusComModeReq in an index and symbol based style. */
typedef union ComM_BusComModeReqUTag
{  /* PRQA S 0750 */  /* MD_CSL_Union */
  ComM_StateType raw[1];
  ComM_BusComModeReqStructSType str;
} ComM_BusComModeReqUType;

/**   \brief  type to access ComM_BusSmState in an index and symbol based style. */
typedef union ComM_BusSmStateUTag
{  /* PRQA S 0750 */  /* MD_CSL_Union */
  ComM_ModeType raw[1];
  ComM_BusSmStateStructSType str;
} ComM_BusSmStateUType;

/**   \brief  type to access ComM_ComAllowed in an index and symbol based style. */
typedef union ComM_ComAllowedUTag
{  /* PRQA S 0750 */  /* MD_CSL_Union */
  ComM_ComAllowedType raw[1];
  ComM_ComAllowedStructSType str;
} ComM_ComAllowedUType;

/** 
  \}
*/ 

/** 
  \defgroup  ComMPCRootPointerTypes  ComM Root Pointer Types (PRE_COMPILE)
  \brief  These type definitions are used to point from the config root to symbol instances.
  \{
*/ 
/**   \brief  type used to point to ComM_ActiveComMode */
typedef P2VAR(ComM_StateType, TYPEDEF, COMM_VAR_NO_INIT) ComM_ActiveComModePtrType;

/**   \brief  type used to point to ComM_BusComModeReq */
typedef P2VAR(ComM_StateType, TYPEDEF, COMM_VAR_NO_INIT) ComM_BusComModeReqPtrType;

/**   \brief  type used to point to ComM_BusSmState */
typedef P2VAR(ComM_ModeType, TYPEDEF, COMM_VAR_NO_INIT) ComM_BusSmStatePtrType;

/**   \brief  type used to point to ComM_Channel */
typedef P2CONST(ComM_ChannelType, TYPEDEF, COMM_CONST) ComM_ChannelPtrType;

/**   \brief  type used to point to ComM_ChannelPb */
typedef P2CONST(ComM_ChannelPbType, TYPEDEF, COMM_CONST) ComM_ChannelPbPtrType;

/**   \brief  type used to point to ComM_ComAllowed */
typedef P2VAR(ComM_ComAllowedType, TYPEDEF, COMM_VAR_NO_INIT) ComM_ComAllowedPtrType;

/**   \brief  type used to point to ComM_Inhibition */
typedef P2VAR(ComM_InhibitionType, TYPEDEF, COMM_NVM_DATA_NO_INIT) ComM_InhibitionPtrType;

/**   \brief  type used to point to ComM_InitStatus */
typedef P2VAR(ComM_InitStatusType, TYPEDEF, COMM_VAR_NO_INIT) ComM_InitStatusPtrType;

/**   \brief  type used to point to ComM_PartitionIdentifiers */
typedef P2CONST(ComM_PartitionIdentifiersType, TYPEDEF, COMM_CONST) ComM_PartitionIdentifiersPtrType;

/**   \brief  type used to point to ComM_PostInitialized */
typedef P2VAR(ComM_PostInitializedType, TYPEDEF, COMM_VAR_NO_INIT) ComM_PostInitializedPtrType;

/**   \brief  type used to point to ComM_User */
typedef P2CONST(ComM_UserType, TYPEDEF, COMM_CONST) ComM_UserPtrType;

/**   \brief  type used to point to ComM_UserByteMask */
typedef P2CONST(ComM_UserByteMaskType, TYPEDEF, COMM_CONST) ComM_UserByteMaskPtrType;

/**   \brief  type used to point to ComM_UserReqFullCom */
typedef P2VAR(ComM_UserReqFullComType, TYPEDEF, COMM_VAR_NO_INIT) ComM_UserReqFullComPtrType;

/** 
  \}
*/ 

/** 
  \defgroup  ComMPCPartitionRootPointer  ComM Partition Root Pointer (PRE_COMPILE)
  \brief  This type definitions are used for partition specific instance.
  \{
*/ 
/**   \brief  type used in ComM_PCPartitionConfig */
typedef struct sComM_PCPartitionConfigType
{
  uint8 ComM_PCPartitionConfigNeverUsed;  /**< dummy entry for the structure in the configuration variant precompile which is not used by the code. */
} ComM_PCPartitionConfigType;

/**   \brief  type used to point to ComM_PCPartitionConfig */
typedef P2CONST(ComM_PCPartitionConfigType, TYPEDEF, COMM_CONST) ComM_PCPartitionConfigPtrType;

/** 
  \}
*/ 

/** 
  \defgroup  ComMPCRootValueTypes  ComM Root Value Types (PRE_COMPILE)
  \brief  These type definitions are used for value representations in root arrays.
  \{
*/ 
/**   \brief  type used in ComM_PCConfig */
typedef struct sComM_PCConfigType
{
  uint8 ComM_PCConfigNeverUsed;  /**< dummy entry for the structure in the configuration variant precompile which is not used by the code. */
} ComM_PCConfigType;

typedef ComM_PCConfigType ComM_ConfigType;  /**< A structure type is present for data in each configuration class. This typedef redefines the probably different name to the specified one. */

/** 
  \}
*/ 


/* PRQA S 0639, 0779 POSTBUILDGLOBALDATATYPES */ /* MD_MSR_1.1_639, MD_MSR_Rule5.2_0779 */
/**********************************************************************************************************************
  CONFIGURATION CLASS: POST_BUILD
  SECTION: GLOBAL COMPLEX DATA TYPES AND STRUCTURES
**********************************************************************************************************************/

/* PRQA L:POSTBUILDGLOBALDATATYPES */

/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
**********************************************************************************************************************/
/* PRQA S 3451 EXTERNDECLARATIONS */ /* MD_ComM_3451_3449 */
/* PRQA S 3449 EXTERNALDECLARATIONS_3449 */ /* MD_ComM_3451_3449 */
/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL DATA PROTOTYPES
**********************************************************************************************************************/
/**********************************************************************************************************************
  ComM_Channel
**********************************************************************************************************************/
/** 
  \var    ComM_Channel
  \brief  Contains PreCompile configuration parameters of channels
  \details
  Element                   Description
  GetCurrentBusSMModeApi    Query the current communication mode from the corresponding BusSM
  RequestBusSMModeApi       Request the communication mode from the corresponding BusSM
*/ 
#define COMM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "ComM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(ComM_ChannelType, COMM_CONST) ComM_Channel[1];
#define COMM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "ComM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  ComM_PartitionIdentifiers
**********************************************************************************************************************/
/** 
  \var    ComM_PartitionIdentifiers
  \brief  the partition context in Config
  \details
  Element                 Description
  PartitionSNV        
  PCPartitionConfigIdx    the index of the 1:1 relation pointing to ComM_PCPartitionConfig
*/ 
#define COMM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "ComM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(ComM_PartitionIdentifiersType, COMM_CONST) ComM_PartitionIdentifiers[1];
#define COMM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "ComM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  ComM_User
**********************************************************************************************************************/
/** 
  \var    ComM_User
  \brief  Information about ComM users
  \details
  Element    Description
  PncUser    decides if a user is a partial network user or a direct channel user
*/ 
#define COMM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "ComM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(ComM_UserType, COMM_CONST) ComM_User[1];
#define COMM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "ComM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  ComM_ActiveComMode
**********************************************************************************************************************/
/** 
  \var    ComM_ActiveComMode
  \brief  Current state of a channel
*/ 
#define COMM_START_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "ComM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(ComM_ActiveComModeUType, COMM_VAR_NO_INIT) ComM_ActiveComMode;  /* PRQA S 0759 */  /* MD_CSL_Union */
#define COMM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "ComM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  ComM_BusComModeReq
**********************************************************************************************************************/
/** 
  \var    ComM_BusComModeReq
  \brief  State requested externally (bus)
*/ 
#define COMM_START_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "ComM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(ComM_BusComModeReqUType, COMM_VAR_NO_INIT) ComM_BusComModeReq;  /* PRQA S 0759 */  /* MD_CSL_Union */
#define COMM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "ComM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  ComM_BusSmState
**********************************************************************************************************************/
/** 
  \var    ComM_BusSmState
  \brief  Communication state of a channel provided by BusSM
*/ 
#define COMM_START_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "ComM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(ComM_BusSmStateUType, COMM_VAR_NO_INIT) ComM_BusSmState;  /* PRQA S 0759 */  /* MD_CSL_Union */
#define COMM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "ComM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  ComM_ComAllowed
**********************************************************************************************************************/
/** 
  \var    ComM_ComAllowed
  \brief  Communication allowed status of a channel
*/ 
#define COMM_START_SEC_VAR_NO_INIT_8
/*lint -save -esym(961, 19.1) */
#include "ComM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(ComM_ComAllowedUType, COMM_VAR_NO_INIT) ComM_ComAllowed;  /* PRQA S 0759 */  /* MD_CSL_Union */
#define COMM_STOP_SEC_VAR_NO_INIT_8
/*lint -save -esym(961, 19.1) */
#include "ComM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  ComM_Inhibition
**********************************************************************************************************************/
/** 
  \var    ComM_Inhibition
  \brief  Status of mode limitation (inhibition)
*/ 
#define COMM_START_SEC_VAR_SAVED_ZONE0_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "ComM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(ComM_InhibitionType, COMM_NVM_DATA_NO_INIT) ComM_Inhibition;
#define COMM_STOP_SEC_VAR_SAVED_ZONE0_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "ComM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  ComM_InitStatus
**********************************************************************************************************************/
/** 
  \var    ComM_InitStatus
  \brief  Initialization state of ComM
*/ 
#define COMM_START_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "ComM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(ComM_InitStatusType, COMM_VAR_NO_INIT) ComM_InitStatus;
#define COMM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "ComM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  ComM_PostInitialized
**********************************************************************************************************************/
/** 
  \var    ComM_PostInitialized
  \brief  Post-Initialized state
*/ 
#define COMM_START_SEC_VAR_NO_INIT_8
/*lint -save -esym(961, 19.1) */
#include "ComM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(ComM_PostInitializedType, COMM_VAR_NO_INIT) ComM_PostInitialized[1];
#define COMM_STOP_SEC_VAR_NO_INIT_8
/*lint -save -esym(961, 19.1) */
#include "ComM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  ComM_UserReqFullCom
**********************************************************************************************************************/
/** 
  \var    ComM_UserReqFullCom
  \brief  RAM array used to store user requests for channels as bitmasks. Each channel 'owns' 1..n bytes in this array, depending on the number of users assigned to it.
*/ 
#define COMM_START_SEC_VAR_NO_INIT_8
/*lint -save -esym(961, 19.1) */
#include "ComM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(ComM_UserReqFullComType, COMM_VAR_NO_INIT) ComM_UserReqFullCom[1];
#define COMM_STOP_SEC_VAR_NO_INIT_8
/*lint -save -esym(961, 19.1) */
#include "ComM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */



/**********************************************************************************************************************
  CONFIGURATION CLASS: POST_BUILD
  SECTION: GLOBAL DATA PROTOTYPES
**********************************************************************************************************************/

/* PRQA L:EXTERNALDECLARATIONS_3449 */
/* PRQA L:EXTERNDECLARATIONS */

/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
**********************************************************************************************************************/
/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL FUNCTION PROTOTYPES
**********************************************************************************************************************/


/**********************************************************************************************************************
  CONFIGURATION CLASS: POST_BUILD
  SECTION: GLOBAL FUNCTION PROTOTYPES
**********************************************************************************************************************/






#endif /* COMM_CFG_H */

