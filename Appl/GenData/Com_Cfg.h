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
 *              File: Com_Cfg.h
 *   Generation Time: 2024-08-03 19:52:20
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


#if !defined (COM_CFG_H)
# define COM_CFG_H

/**********************************************************************************************************************
 * MISRA JUSTIFICATION
 *********************************************************************************************************************/

/**********************************************************************************************************************
  INCLUDES
**********************************************************************************************************************/
# include "Com_Types.h"

/**********************************************************************************************************************
  GLOBAL CONSTANT MACROS
**********************************************************************************************************************/

#ifndef COM_USE_DUMMY_STATEMENT
#define COM_USE_DUMMY_STATEMENT STD_OFF /* /MICROSAR/vSet/vSetGeneral/vSetDummyStatementKind */
#endif
#ifndef COM_DUMMY_STATEMENT
#define COM_DUMMY_STATEMENT(v)  /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */  /* /MICROSAR/vSet/vSetGeneral/vSetDummyStatementKind */
#endif
#ifndef COM_DUMMY_STATEMENT_CONST
#define COM_DUMMY_STATEMENT_CONST(v)  /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */  /* /MICROSAR/vSet/vSetGeneral/vSetDummyStatementKind */
#endif
#ifndef COM_ATOMIC_BIT_ACCESS_IN_BITFIELD
#define COM_ATOMIC_BIT_ACCESS_IN_BITFIELD STD_OFF /* /MICROSAR/EcuC/EcucGeneral/AtomicBitAccessInBitfield */
#endif
#ifndef COM_ATOMIC_VARIABLE_ACCESS
#define COM_ATOMIC_VARIABLE_ACCESS 32u /* /MICROSAR/EcuC/EcucGeneral/AtomicVariableAccess */
#endif
#ifndef COM_PROCESSOR_TC387Q
#define COM_PROCESSOR_TC387Q
#endif
#ifndef COM_COMP_TASKING
#define COM_COMP_TASKING
#endif
#ifndef COM_GEN_GENERATOR_MSR
#define COM_GEN_GENERATOR_MSR
#endif
#ifndef COM_CPUTYPE_BITORDER_LSB2MSB
#define COM_CPUTYPE_BITORDER_LSB2MSB /* /MICROSAR/vSet/vSetPlatform/vSetBitOrder */
#endif
#ifndef COM_CONFIGURATION_VARIANT_PRECOMPILE
#define COM_CONFIGURATION_VARIANT_PRECOMPILE 1
#endif
#ifndef COM_CONFIGURATION_VARIANT_LINKTIME
#define COM_CONFIGURATION_VARIANT_LINKTIME 2
#endif
#ifndef COM_CONFIGURATION_VARIANT_POSTBUILD_LOADABLE
#define COM_CONFIGURATION_VARIANT_POSTBUILD_LOADABLE 3
#endif
#ifndef COM_CONFIGURATION_VARIANT
#define COM_CONFIGURATION_VARIANT COM_CONFIGURATION_VARIANT_PRECOMPILE
#endif
#ifndef COM_POSTBUILD_VARIANT_SUPPORT
#define COM_POSTBUILD_VARIANT_SUPPORT STD_OFF
#endif


/* General */
#define COM_DEV_ERROR_DETECT                 STD_ON  /**< /ActiveEcuC/Com/ComGeneral[0:ComSafeBswChecks] || /ActiveEcuC/Com/ComGeneral[0:ComConfigurationUseDet] */
#define COM_DEV_ERROR_REPORT                 STD_ON  /**< /ActiveEcuC/Com/ComGeneral[0:ComConfigurationUseDet] */
#define COM_RETRY_FAILED_TRANSMIT_REQUESTS   STD_ON  /**< /ActiveEcuC/Com/ComGeneral[0:ComRetryFailedTransmitRequests] */

/* API */
#define COM_COMMUNICATION_INTERFACE          STD_ON  /**< /ActiveEcuC/PduR/Com[0:PduRCommunicationInterface] */
#define COM_TRANSPORT_PROTOCOL               STD_OFF  /**< /ActiveEcuC/PduR/Com[0:PduRTransportProtocol] */

#define COM_TRIGGER_TRANSMIT_API             STD_OFF  /**< /ActiveEcuC/PduR/Com[0:PduRTriggertransmit] */
#define COM_TX_CONFIRMATION_API              STD_ON  /**< /ActiveEcuC/PduR/Com[0:PduRTxConfirmation] */
#define COM_TRIGGER_IPDU_SEND_WITH_META_DATA_API    STD_OFF  /**< /ActiveEcuC/Com/ComGeneral[0:ComMetaDataSupport] */
#define COM_MAIN_FUNCTION_ROUTE_SIGNALS_API  STD_OFF  /**< /ActiveEcuC/Com/ComGeneral[0:ComSignalGateway] || /ActiveEcuC/Com/ComGeneral[0:ComDescriptionGateway] */
#define COM_ENABLE_SIGNAL_GROUP_ARRAY_API    STD_OFF  /**< /ActiveEcuC/Com/ComGeneral[0:ComEnableSignalGroupArrayApi] */

#define COM_VERSION_INFO_API                 STD_OFF  /**< /ActiveEcuC/Com/ComGeneral[0:ComVersionInfoApi] */

#define COM_SUPPORTED_IPDU_GROUPS            2u  /**< /ActiveEcuC/Com/ComGeneral[0:ComSupportedIPduGroups] */

#define COM_RXIMMEDIATEFCTPTRCACHE           STD_OFF
#define COM_RXIMMEDIATEFCTPTRCACHESIZE       0U

#define COM_STRICT_REPETITION_PERIOD         STD_OFF  /**< /ActiveEcuC/Com/ComGeneral[0:ComStrictRepetitionPeriod] */
#define COM_MIXEDMODEPERIODICSUPPRESSION     STD_OFF  /**< /ActiveEcuC/Com/ComGeneral[0:ComMixedModePeriodicSuppression] */

/**
  \brief  Constants to compare floating-point values according to ISO C-99 standard.
  \details  -
    \{
*/
#define COM_FLT_EPSILON                      1E-5
#define COM_DBL_EPSILON                      1E-9
/**
  \}
*/




/**
 * \defgroup ComHandleIdsComRxSig Handle IDs of handle space ComRxSig.
 * \brief Rx Signals
 * \{
 */

/* Handle IDs active in all predefined variants (the application has not to take the active variant into account) */
/*      Symbolic Name                                                 Value   Active in predefined variant(s) */
#define ComConf_ComSignal_sig_State_RearLeftDoor_omsg_Receive_oCAN00_84ad4140_Rx 0u
#define ComConf_ComSignal_sig_State_RearRightDoor_omsg_Receive_oCAN00_a8945098_Rx 1u
/**\} */

/**
 * \defgroup ComHandleIdsComTxSig Handle IDs of handle space ComTxSig.
 * \brief Tx Signals
 * \{
 */

/* Handle IDs active in all predefined variants (the application has not to take the active variant into account) */
/*      Symbolic Name                                                 Value   Active in predefined variant(s) */
#define ComConf_ComSignal_MotorFoc_AdcFilterAlpha_MxA2_omsg_MyECU_Lamp_oCAN00_4c48c598_Tx 0u
#define ComConf_ComSignal_MotorFoc_AdcFilterEnabled_MxA2_omsg_MyECU_Lamp_oCAN00_bb1a16f8_Tx 1u
#define ComConf_ComSignal_MotorFoc_AdcFilterReady_MxA2_omsg_MyECU_Lamp_oCAN00_dd22f986_Tx 2u
#define ComConf_ComSignal_MotorFoc_AdcOffsetSampleCount_MxA2_omsg_MyECU_Lamp_oCAN00_98a9a073_Tx 3u
#define ComConf_ComSignal_MotorFoc_AdcOffsetVo1_MxA2_omsg_MyECU_Lamp_oCAN00_7e4e712f_Tx 4u
#define ComConf_ComSignal_MotorFoc_AdcOffsetVo2_MxA2_omsg_MyECU_Lamp_oCAN00_db461a43_Tx 5u
#define ComConf_ComSignal_MotorFoc_AdcOffsetVo3_MxA2_omsg_MyECU_Lamp_oCAN00_b841c367_Tx 6u
#define ComConf_ComSignal_MotorFoc_AdcSyncCounter_MxA2_omsg_MyECU_Lamp_oCAN00_8264daf6_Tx 7u
#define ComConf_ComSignal_MotorFoc_AngleRaw_MxA0_omsg_MyECU_Lamp_oCAN00_7aec7e78_Tx 8u
#define ComConf_ComSignal_MotorFoc_CurrentOffsetReady_MxA0_omsg_MyECU_Lamp_oCAN00_81ce1bc4_Tx 9u
#define ComConf_ComSignal_MotorFoc_CurrentOffsetSampleCount_MxA0_omsg_MyECU_Lamp_oCAN00_6c5c0a81_Tx 10u
#define ComConf_ComSignal_MotorFoc_ElectricalAngle_rad_MxA0_omsg_MyECU_Lamp_oCAN00_5447ad3f_Tx 11u
#define ComConf_ComSignal_MotorFoc_FaultIu_A_MxA1_omsg_MyECU_Lamp_oCAN00_99a1880c_Tx 12u
#define ComConf_ComSignal_MotorFoc_FaultIv_A_MxA1_omsg_MyECU_Lamp_oCAN00_8a89b17f_Tx 13u
#define ComConf_ComSignal_MotorFoc_FaultIw_A_MxA1_omsg_MyECU_Lamp_oCAN00_846e59ae_Tx 14u
#define ComConf_ComSignal_MotorFoc_FaultPwm_MxA1_omsg_MyECU_Lamp_oCAN00_e43e797b_Tx 15u
#define ComConf_ComSignal_MotorFoc_FaultReasonPwm_MxA1_omsg_MyECU_Lamp_oCAN00_32050898_Tx 16u
#define ComConf_ComSignal_MotorFoc_FaultReason_MxA0_omsg_MyECU_Lamp_oCAN00_0576dfc4_Tx 17u
#define ComConf_ComSignal_MotorFoc_FaultVdc_V_MxA1_omsg_MyECU_Lamp_oCAN00_65447c06_Tx 18u
#define ComConf_ComSignal_MotorFoc_Fault_MxA0_omsg_MyECU_Lamp_oCAN00_3dd6add5_Tx 19u
#define ComConf_ComSignal_MotorFoc_GateDriverOutputEnabled_MxA0_omsg_MyECU_Lamp_oCAN00_6012a7f7_Tx 20u
#define ComConf_ComSignal_MotorFoc_GateDriverState_MxA0_omsg_MyECU_Lamp_oCAN00_e2e4dde6_Tx 21u
#define ComConf_ComSignal_MotorFoc_IdRef_A_MxA0_omsg_MyECU_Lamp_oCAN00_832c12be_Tx 22u
#define ComConf_ComSignal_MotorFoc_Id_A_MxA0_omsg_MyECU_Lamp_oCAN00_888850f5_Tx 23u
#define ComConf_ComSignal_MotorFoc_IqRef_A_MxA0_omsg_MyECU_Lamp_oCAN00_10111ef3_Tx 24u
#define ComConf_ComSignal_MotorFoc_Iq_A_MxA0_omsg_MyECU_Lamp_oCAN00_538e9670_Tx 25u
#define ComConf_ComSignal_MotorFoc_IuFiltered_A_MxA2_omsg_MyECU_Lamp_oCAN00_edadce4b_Tx 26u
#define ComConf_ComSignal_MotorFoc_IuRaw_A_MxA2_omsg_MyECU_Lamp_oCAN00_ca30e9cf_Tx 27u
#define ComConf_ComSignal_MotorFoc_Iu_A_MxA0_omsg_MyECU_Lamp_oCAN00_68113534_Tx 28u
#define ComConf_ComSignal_MotorFoc_IvFiltered_A_MxA2_omsg_MyECU_Lamp_oCAN00_3e36d2b0_Tx 29u
#define ComConf_ComSignal_MotorFoc_IvRaw_A_MxA2_omsg_MyECU_Lamp_oCAN00_a7b61a95_Tx 30u
#define ComConf_ComSignal_MotorFoc_Iv_A_MxA0_omsg_MyECU_Lamp_oCAN00_7b390c47_Tx 31u
#define ComConf_ComSignal_MotorFoc_IwFiltered_A_MxA2_omsg_MyECU_Lamp_oCAN00_70bfd919_Tx 32u
#define ComConf_ComSignal_MotorFoc_IwRaw_A_MxA2_omsg_MyECU_Lamp_oCAN00_83344ba3_Tx 33u
#define ComConf_ComSignal_MotorFoc_Iw_A_MxA0_omsg_MyECU_Lamp_oCAN00_75dee496_Tx 34u
#define ComConf_ComSignal_MotorFoc_MechanicalSpeed_rpm_MxA0_omsg_MyECU_Lamp_oCAN00_04bd2026_Tx 35u
#define ComConf_ComSignal_MotorFoc_MotorModePwm_MxA1_omsg_MyECU_Lamp_oCAN00_d3afa653_Tx 36u
#define ComConf_ComSignal_MotorFoc_MotorMode_MxA0_omsg_MyECU_Lamp_oCAN00_aa7dbeca_Tx 37u
#define ComConf_ComSignal_MotorFoc_Page_MxA0_omsg_MyECU_Lamp_oCAN00_9aab60ea_Tx 38u
#define ComConf_ComSignal_MotorFoc_Page_MxA1_omsg_MyECU_Lamp_oCAN00_1b8e05cd_Tx 39u
#define ComConf_ComSignal_MotorFoc_Page_MxA2_omsg_MyECU_Lamp_oCAN00_4390ace5_Tx 40u
#define ComConf_ComSignal_MotorFoc_PwmPeriod_MxA1_omsg_MyECU_Lamp_oCAN00_d26baca6_Tx 41u
#define ComConf_ComSignal_MotorFoc_PwmU_MxA1_omsg_MyECU_Lamp_oCAN00_c33fb364_Tx 42u
#define ComConf_ComSignal_MotorFoc_PwmV_MxA1_omsg_MyECU_Lamp_oCAN00_6637d808_Tx 43u
#define ComConf_ComSignal_MotorFoc_PwmW_MxA1_omsg_MyECU_Lamp_oCAN00_0530012c_Tx 44u
#define ComConf_ComSignal_MotorFoc_Sequence_Mx_omsg_MyECU_Lamp_oCAN00_339a541d_Tx 45u
#define ComConf_ComSignal_MotorFoc_ValphaRef_V_MxA1_omsg_MyECU_Lamp_oCAN00_dafa2b94_Tx 46u
#define ComConf_ComSignal_MotorFoc_VbetaRef_V_MxA1_omsg_MyECU_Lamp_oCAN00_623c36a7_Tx 47u
#define ComConf_ComSignal_MotorFoc_VdRef_V_MxA1_omsg_MyECU_Lamp_oCAN00_f0517bd4_Tx 48u
#define ComConf_ComSignal_MotorFoc_VdcMax_V_MxA1_omsg_MyECU_Lamp_oCAN00_8d3d4389_Tx 49u
#define ComConf_ComSignal_MotorFoc_Vdc_V_MxA0_omsg_MyECU_Lamp_oCAN00_6919810c_Tx 50u
#define ComConf_ComSignal_MotorFoc_Vinv_V_MxA2_omsg_MyECU_Lamp_oCAN00_bd00cc55_Tx 51u
#define ComConf_ComSignal_MotorFoc_VqRef_V_MxA1_omsg_MyECU_Lamp_oCAN00_636c7799_Tx 52u
#define ComConf_ComSignal_MotorFoc_Vro_V_MxA2_omsg_MyECU_Lamp_oCAN00_a894d119_Tx 53u
#define ComConf_ComSignal_sig_RearInteriorLight_omsg_Transmit_oCAN00_49a633c1_Tx 54u
/**\} */







/**
 * \defgroup ComHandleIds Handle IDs.
 * \{
 */

/* Handle IDs active in all predefined variants (the application has not to take the active variant into account) */
/*      Symbolic Name                                                 Value   Active in predefined variant(s) */
#define ComConf_ComIPduGroup_MyECU_oCAN00_Rx_4cbf71f7                 0u
#define ComConf_ComIPduGroup_MyECU_oCAN00_Tx_1ae5d671                 1u
/**\} */

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

#endif  /* COM_CFG_H */
/**********************************************************************************************************************
  END OF FILE: Com_Cfg.h
**********************************************************************************************************************/

