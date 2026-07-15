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
 *            Module: Sbc
 *           Program: MSR_Vector_SLP4
 *          Customer: China Lithium Battery Technology Co., Ltd.
 *       Expiry Date: 2025-08-26
 *  Ordered Derivat.: SAK-TC387QP-160F300S AE
 *    License Scope : The usage is restricted to CBD2200508_D00
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: Sbc_30_Tlf35584_Cfg.h
 *   Generation Time: 2024-07-13 10:04:48
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



#if !defined (SBC_30_TLF35584_CFG_H)
# define SBC_30_TLF35584_CFG_H

#include "Sbc_30_Tlf35584_Types.h"

/**********************************************************************************************************************
  GLOBAL CONSTANT MACROS
**********************************************************************************************************************/
#ifndef SBC_30_TLF35584_USE_DUMMY_STATEMENT
#define SBC_30_TLF35584_USE_DUMMY_STATEMENT STD_OFF /* /MICROSAR/vSet/vSetGeneral/vSetDummyStatementKind */
#endif
#ifndef SBC_30_TLF35584_DUMMY_STATEMENT
#define SBC_30_TLF35584_DUMMY_STATEMENT(v)  /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */  /* /MICROSAR/vSet/vSetGeneral/vSetDummyStatementKind */
#endif
#ifndef SBC_30_TLF35584_DUMMY_STATEMENT_CONST
#define SBC_30_TLF35584_DUMMY_STATEMENT_CONST(v)  /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */  /* /MICROSAR/vSet/vSetGeneral/vSetDummyStatementKind */
#endif
#ifndef SBC_30_TLF35584_ATOMIC_BIT_ACCESS_IN_BITFIELD
#define SBC_30_TLF35584_ATOMIC_BIT_ACCESS_IN_BITFIELD STD_OFF /* /MICROSAR/EcuC/EcucGeneral/AtomicBitAccessInBitfield */
#endif
#ifndef SBC_30_TLF35584_ATOMIC_VARIABLE_ACCESS
#define SBC_30_TLF35584_ATOMIC_VARIABLE_ACCESS 32u /* /MICROSAR/EcuC/EcucGeneral/AtomicVariableAccess */
#endif
#ifndef SBC_30_TLF35584_PROCESSOR_TC387Q
#define SBC_30_TLF35584_PROCESSOR_TC387Q
#endif
#ifndef SBC_30_TLF35584_COMP_TASKING
#define SBC_30_TLF35584_COMP_TASKING
#endif
#ifndef SBC_30_TLF35584_GEN_GENERATOR_MSR
#define SBC_30_TLF35584_GEN_GENERATOR_MSR
#endif
#ifndef SBC_30_TLF35584_CPUTYPE_BITORDER_LSB2MSB
#define SBC_30_TLF35584_CPUTYPE_BITORDER_LSB2MSB /* /MICROSAR/vSet/vSetPlatform/vSetBitOrder */
#endif
#ifndef SBC_30_TLF35584_CONFIGURATION_VARIANT_PRECOMPILE
#define SBC_30_TLF35584_CONFIGURATION_VARIANT_PRECOMPILE 1
#endif
#ifndef SBC_30_TLF35584_CONFIGURATION_VARIANT_LINKTIME
#define SBC_30_TLF35584_CONFIGURATION_VARIANT_LINKTIME 2
#endif
#ifndef SBC_30_TLF35584_CONFIGURATION_VARIANT_POSTBUILD_LOADABLE
#define SBC_30_TLF35584_CONFIGURATION_VARIANT_POSTBUILD_LOADABLE 3
#endif
#ifndef SBC_30_TLF35584_CONFIGURATION_VARIANT
#define SBC_30_TLF35584_CONFIGURATION_VARIANT SBC_30_TLF35584_CONFIGURATION_VARIANT_PRECOMPILE
#endif
#ifndef SBC_30_TLF35584_POSTBUILD_VARIANT_SUPPORT
#define SBC_30_TLF35584_POSTBUILD_VARIANT_SUPPORT STD_OFF
#endif


/*! \brief Version defines that are used to check the compatibility of the generated data */
#define SBC_30_TLF35584_CFG_BASE_COMPAT_VERSION   0x0101u
#define SBC_30_TLF35584_CFG_HW_COMPAT_VERSION     0x0100u



/*! \brief Enables / disables development error detection */
#define SBC_30_TLF35584_DEV_ERROR_DETECT          STD_ON

/*! \brief Enables / disables development error reporting: enabled whenever error detection is configured */
#define SBC_30_TLF35584_DEV_ERROR_REPORT          STD_ON

/* ! \brief Enables / disables get version info API */
#define SBC_30_TLF35584_VERSION_INFO_API          STD_OFF

/*! \brief Specifies whether to use the single instance API */
#define SBC_30_TLF35584_SINGLE_INSTANCE_API       STD_ON

/*! \brief Specifies the number of SBC instances */
#define SBC_30_TLF35584_NUMBER_OF_DEVICES         1u

/*! \brief Specifies the maximum number of used CanTrcv devices */
#define SBC_30_TLF35584_MAX_NUMBER_OF_CANTRCV     0u

/*! \brief Specifies the maximum number of used LinTrcv devices */
#define SBC_30_TLF35584_MAX_NUMBER_OF_LINTRCV     0u

/*! \brief Specifies the maximum number of used Wdg devices */
#define SBC_30_TLF35584_MAX_NUMBER_OF_WDG         0u

/*! \brief Specifies whether the POR Wakeup Src is configured */
#define SBC_30_TLF35584_POR_NOTIFICATION          STD_OFF

/*! \brief Specifies whether the watchdog supports Off Mode */
#define SBC_30_TLF35584_WDG_OFF_MODE_ALLOWED      STD_ON

/*! \brief Specifies whether the watchdog supports Slow Mode */
#define SBC_30_TLF35584_WDG_SLOW_MODE_ALLOWED     STD_ON

/*! \brief Specifies whether the watchdog sets mode after trigger */
#define SBC_30_TLF35584_WDG_MODE_CHANGE_ASYNC     STD_OFF

/*! \brief Specifies whether the SBC driver needs an initial trigger from watchdog driver: e.g. when SBC needs a watchdog trigger to leave init mode or to set watchdog default mode. */
#define SBC_30_TLF35584_WDG_INITIAL_TRIGGER       STD_OFF


#define SbcConf_SbcDevice_SbcDevice (0u)

/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL CONSTANT MACROS
**********************************************************************************************************************/
/** 
  \defgroup  Sbc_30_Tlf35584PCDataSwitches  Sbc_30_Tlf35584 Data Switches  (PRE_COMPILE)
  \brief  These defines are used to deactivate data and their processing.
  \{
*/ 
#define SBC_30_TLF35584_CANTRCVCONFIG                                 STD_OFF  /**< Deactivateable: 'Sbc_30_Tlf35584_CanTrcvConfig' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define SBC_30_TLF35584_CANTRCVACTIVEMODEVALOFCANTRCVCONFIG           STD_OFF  /**< Deactivateable: 'Sbc_30_Tlf35584_CanTrcvConfig.CanTrcvActiveModeVal' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define SBC_30_TLF35584_CANTRCVPNCONFIGIDXOFCANTRCVCONFIG             STD_OFF  /**< Deactivateable: 'Sbc_30_Tlf35584_CanTrcvConfig.CanTrcvPnConfigIdx' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define SBC_30_TLF35584_CANTRCVPNCONFIGUSEDOFCANTRCVCONFIG            STD_OFF  /**< Deactivateable: 'Sbc_30_Tlf35584_CanTrcvConfig.CanTrcvPnConfigUsed' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define SBC_30_TLF35584_DEVICECONFIGURATIONKEYOFCANTRCVCONFIG         STD_OFF  /**< Deactivateable: 'Sbc_30_Tlf35584_CanTrcvConfig.DeviceConfigurationKey' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define SBC_30_TLF35584_CANTRCVPNCONFIG                               STD_OFF  /**< Deactivateable: 'Sbc_30_Tlf35584_CanTrcvPnConfig' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define SBC_30_TLF35584_BAUDRATEOFCANTRCVPNCONFIG                     STD_OFF  /**< Deactivateable: 'Sbc_30_Tlf35584_CanTrcvPnConfig.BaudRate' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define SBC_30_TLF35584_CANTRCVPNCONFIGDATAENDIDXOFCANTRCVPNCONFIG    STD_OFF  /**< Deactivateable: 'Sbc_30_Tlf35584_CanTrcvPnConfig.CanTrcvPnConfigDataEndIdx' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define SBC_30_TLF35584_CANTRCVPNCONFIGDATALENGTHOFCANTRCVPNCONFIG    STD_OFF  /**< Deactivateable: 'Sbc_30_Tlf35584_CanTrcvPnConfig.CanTrcvPnConfigDataLength' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define SBC_30_TLF35584_CANTRCVPNCONFIGDATASTARTIDXOFCANTRCVPNCONFIG  STD_OFF  /**< Deactivateable: 'Sbc_30_Tlf35584_CanTrcvPnConfig.CanTrcvPnConfigDataStartIdx' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define SBC_30_TLF35584_ISEXTIDOFCANTRCVPNCONFIG                      STD_OFF  /**< Deactivateable: 'Sbc_30_Tlf35584_CanTrcvPnConfig.IsExtId' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define SBC_30_TLF35584_PNENABLEDOFCANTRCVPNCONFIG                    STD_OFF  /**< Deactivateable: 'Sbc_30_Tlf35584_CanTrcvPnConfig.PnEnabled' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define SBC_30_TLF35584_PNFRAMECANDLCOFCANTRCVPNCONFIG                STD_OFF  /**< Deactivateable: 'Sbc_30_Tlf35584_CanTrcvPnConfig.PnFrameCanDlc' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define SBC_30_TLF35584_PNFRAMECANIDMASKOFCANTRCVPNCONFIG             STD_OFF  /**< Deactivateable: 'Sbc_30_Tlf35584_CanTrcvPnConfig.PnFrameCanIdMask' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define SBC_30_TLF35584_PNFRAMECANIDOFCANTRCVPNCONFIG                 STD_OFF  /**< Deactivateable: 'Sbc_30_Tlf35584_CanTrcvPnConfig.PnFrameCanId' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define SBC_30_TLF35584_CANTRCVPNCONFIGDATA                           STD_OFF  /**< Deactivateable: 'Sbc_30_Tlf35584_CanTrcvPnConfigData' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define SBC_30_TLF35584_DATAOFCANTRCVPNCONFIGDATA                     STD_OFF  /**< Deactivateable: 'Sbc_30_Tlf35584_CanTrcvPnConfigData.Data' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define SBC_30_TLF35584_CANTRCVPNLLCONFIG                             STD_OFF  /**< Deactivateable: 'Sbc_30_Tlf35584_CanTrcvPnLlConfig' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define SBC_30_TLF35584_DATARATEREGOFCANTRCVPNLLCONFIG                STD_OFF  /**< Deactivateable: 'Sbc_30_Tlf35584_CanTrcvPnLlConfig.DataRateReg' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define SBC_30_TLF35584_DEVICECONFIGURATION                           STD_ON
#define SBC_30_TLF35584_CANTRCVCONFIGSTARTIDXOFDEVICECONFIGURATION    STD_OFF  /**< Deactivateable: 'Sbc_30_Tlf35584_DeviceConfiguration.CanTrcvConfigStartIdx' Reason: 'the optional indirection is deactivated because CanTrcvConfigUsedOfDeviceConfiguration is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define SBC_30_TLF35584_CANTRCVCONFIGUSEDOFDEVICECONFIGURATION        STD_OFF  /**< Deactivateable: 'Sbc_30_Tlf35584_DeviceConfiguration.CanTrcvConfigUsed' Reason: 'the optional indirection is deactivated because CanTrcvConfigUsedOfDeviceConfiguration is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define SBC_30_TLF35584_NUMBEROFCANTRCVOFDEVICECONFIGURATION          STD_ON
#define SBC_30_TLF35584_NUMBEROFLINTRCVOFDEVICECONFIGURATION          STD_ON
#define SBC_30_TLF35584_NUMBEROFWDGOFDEVICECONFIGURATION              STD_ON
#define SBC_30_TLF35584_WDGCONFIGSTARTIDXOFDEVICECONFIGURATION        STD_OFF  /**< Deactivateable: 'Sbc_30_Tlf35584_DeviceConfiguration.WdgConfigStartIdx' Reason: 'the optional indirection is deactivated because WdgConfigUsedOfDeviceConfiguration is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define SBC_30_TLF35584_WDGCONFIGUSEDOFDEVICECONFIGURATION            STD_OFF  /**< Deactivateable: 'Sbc_30_Tlf35584_DeviceConfiguration.WdgConfigUsed' Reason: 'the optional indirection is deactivated because WdgConfigUsedOfDeviceConfiguration is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define SBC_30_TLF35584_WUSRCPOROFDEVICECONFIGURATION                 STD_ON
#define SBC_30_TLF35584_DIOCHANNEL                                    STD_OFF  /**< Deactivateable: 'Sbc_30_Tlf35584_DioChannel' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define SBC_30_TLF35584_FINALMAGICNUMBER                              STD_OFF  /**< Deactivateable: 'Sbc_30_Tlf35584_FinalMagicNumber' Reason: 'the module configuration does not support flashing of data.' */
#define SBC_30_TLF35584_FWDCONFIG                                     STD_OFF  /**< Deactivateable: 'Sbc_30_Tlf35584_FwdConfig' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define SBC_30_TLF35584_INITCONFIG                                    STD_ON
#define SBC_30_TLF35584_SYSPCFG1OFINITCONFIG                          STD_ON
#define SBC_30_TLF35584_INITDATAHASHCODE                              STD_OFF  /**< Deactivateable: 'Sbc_30_Tlf35584_InitDataHashCode' Reason: 'the module configuration does not support flashing of data.' */
#define SBC_30_TLF35584_SPICHANNEL                                    STD_ON
#define SBC_30_TLF35584_SBCSPICHL_SBCSPICHANNELOFSPICHANNEL           STD_ON
#define SBC_30_TLF35584_SPISEQUENCE                                   STD_ON
#define SBC_30_TLF35584_SBCSPISEQ_SBCSPISEQUENCEOFSPISEQUENCE         STD_ON
#define SBC_30_TLF35584_SUPPLYCONFIG                                  STD_ON
#define SBC_30_TLF35584_DEVCTRLNORMALOFSUPPLYCONFIG                   STD_ON
#define SBC_30_TLF35584_DEVCTRLSTANDBYOFSUPPLYCONFIG                  STD_ON
#define SBC_30_TLF35584_SYSPCFG0NORMALOFSUPPLYCONFIG                  STD_ON
#define SBC_30_TLF35584_SYSPCFG0SLEEPOFSUPPLYCONFIG                   STD_ON
#define SBC_30_TLF35584_SYSPCFG0STANDBYOFSUPPLYCONFIG                 STD_ON
#define SBC_30_TLF35584_WDGCONFIG                                     STD_OFF  /**< Deactivateable: 'Sbc_30_Tlf35584_WdgConfig' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define SBC_30_TLF35584_DEVICECONFIGURATIONKEYOFWDGCONFIG             STD_OFF  /**< Deactivateable: 'Sbc_30_Tlf35584_WdgConfig.DeviceConfigurationKey' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define SBC_30_TLF35584_FWDCFGFASTOFWDGCONFIG                         STD_OFF  /**< Deactivateable: 'Sbc_30_Tlf35584_WdgConfig.FWDCFGfast' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define SBC_30_TLF35584_FWDCFGSLOWOFWDGCONFIG                         STD_OFF  /**< Deactivateable: 'Sbc_30_Tlf35584_WdgConfig.FWDCFGslow' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define SBC_30_TLF35584_FWDCONFIGIDXOFWDGCONFIG                       STD_OFF  /**< Deactivateable: 'Sbc_30_Tlf35584_WdgConfig.FwdConfigIdx' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define SBC_30_TLF35584_FWDCONFIGUSEDOFWDGCONFIG                      STD_OFF  /**< Deactivateable: 'Sbc_30_Tlf35584_WdgConfig.FwdConfigUsed' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define SBC_30_TLF35584_WDCFG0OFWDGCONFIG                             STD_OFF  /**< Deactivateable: 'Sbc_30_Tlf35584_WdgConfig.WDCFG0' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define SBC_30_TLF35584_WDCFG1OFWDGCONFIG                             STD_OFF  /**< Deactivateable: 'Sbc_30_Tlf35584_WdgConfig.WDCFG1' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define SBC_30_TLF35584_WDGINITMODEOFWDGCONFIG                        STD_OFF  /**< Deactivateable: 'Sbc_30_Tlf35584_WdgConfig.WdgInitMode' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define SBC_30_TLF35584_WWDCFG0FASTOFWDGCONFIG                        STD_OFF  /**< Deactivateable: 'Sbc_30_Tlf35584_WdgConfig.WwdCfg0Fast' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define SBC_30_TLF35584_WWDCFG0SLOWOFWDGCONFIG                        STD_OFF  /**< Deactivateable: 'Sbc_30_Tlf35584_WdgConfig.WwdCfg0Slow' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define SBC_30_TLF35584_WWDCFG1FASTOFWDGCONFIG                        STD_OFF  /**< Deactivateable: 'Sbc_30_Tlf35584_WdgConfig.WwdCfg1Fast' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define SBC_30_TLF35584_WWDCFG1SLOWOFWDGCONFIG                        STD_OFF  /**< Deactivateable: 'Sbc_30_Tlf35584_WdgConfig.WwdCfg1Slow' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define SBC_30_TLF35584_PCCONFIG                                      STD_ON
#define SBC_30_TLF35584_DEVICECONFIGURATIONOFPCCONFIG                 STD_ON
#define SBC_30_TLF35584_FINALMAGICNUMBEROFPCCONFIG                    STD_OFF  /**< Deactivateable: 'Sbc_30_Tlf35584_PCConfig.FinalMagicNumber' Reason: 'the module configuration does not support flashing of data.' */
#define SBC_30_TLF35584_INITCONFIGOFPCCONFIG                          STD_ON
#define SBC_30_TLF35584_INITDATAHASHCODEOFPCCONFIG                    STD_OFF  /**< Deactivateable: 'Sbc_30_Tlf35584_PCConfig.InitDataHashCode' Reason: 'the module configuration does not support flashing of data.' */
#define SBC_30_TLF35584_SPICHANNELOFPCCONFIG                          STD_ON
#define SBC_30_TLF35584_SPISEQUENCEOFPCCONFIG                         STD_ON
#define SBC_30_TLF35584_SUPPLYCONFIGOFPCCONFIG                        STD_ON
/** 
  \}
*/ 

/** 
  \defgroup  Sbc_30_Tlf35584PCIsReducedToDefineDefines  Sbc_30_Tlf35584 Is Reduced To Define Defines (PRE_COMPILE)
  \brief  If all values in a CONST array or an element in a CONST array of structs are equal, the define is STD_ON else STD_OFF.
  \{
*/ 
#define SBC_30_TLF35584_ISDEF_NUMBEROFCANTRCVOFDEVICECONFIGURATION    STD_OFF
#define SBC_30_TLF35584_ISDEF_NUMBEROFLINTRCVOFDEVICECONFIGURATION    STD_OFF
#define SBC_30_TLF35584_ISDEF_NUMBEROFWDGOFDEVICECONFIGURATION        STD_OFF
#define SBC_30_TLF35584_ISDEF_WUSRCPOROFDEVICECONFIGURATION           STD_OFF
#define SBC_30_TLF35584_ISDEF_SYSPCFG1OFINITCONFIG                    STD_OFF
#define SBC_30_TLF35584_ISDEF_SBCSPICHL_SBCSPICHANNELOFSPICHANNEL     STD_OFF
#define SBC_30_TLF35584_ISDEF_SBCSPISEQ_SBCSPISEQUENCEOFSPISEQUENCE   STD_OFF
#define SBC_30_TLF35584_ISDEF_DEVCTRLNORMALOFSUPPLYCONFIG             STD_OFF
#define SBC_30_TLF35584_ISDEF_DEVCTRLSTANDBYOFSUPPLYCONFIG            STD_OFF
#define SBC_30_TLF35584_ISDEF_SYSPCFG0NORMALOFSUPPLYCONFIG            STD_OFF
#define SBC_30_TLF35584_ISDEF_SYSPCFG0SLEEPOFSUPPLYCONFIG             STD_OFF
#define SBC_30_TLF35584_ISDEF_SYSPCFG0STANDBYOFSUPPLYCONFIG           STD_OFF
#define SBC_30_TLF35584_ISDEF_DEVICECONFIGURATIONOFPCCONFIG           STD_ON
#define SBC_30_TLF35584_ISDEF_INITCONFIGOFPCCONFIG                    STD_ON
#define SBC_30_TLF35584_ISDEF_SPICHANNELOFPCCONFIG                    STD_ON
#define SBC_30_TLF35584_ISDEF_SPISEQUENCEOFPCCONFIG                   STD_ON
#define SBC_30_TLF35584_ISDEF_SUPPLYCONFIGOFPCCONFIG                  STD_ON
/** 
  \}
*/ 

/** 
  \defgroup  Sbc_30_Tlf35584PCEqualsAlwaysToDefines  Sbc_30_Tlf35584 Equals Always To Defines (PRE_COMPILE)
  \brief  If all values in a CONST array or an element in a CONST array of structs are equal, the define contains the always equals value.
  \{
*/ 
#define SBC_30_TLF35584_EQ2_NUMBEROFCANTRCVOFDEVICECONFIGURATION      
#define SBC_30_TLF35584_EQ2_NUMBEROFLINTRCVOFDEVICECONFIGURATION      
#define SBC_30_TLF35584_EQ2_NUMBEROFWDGOFDEVICECONFIGURATION          
#define SBC_30_TLF35584_EQ2_WUSRCPOROFDEVICECONFIGURATION             
#define SBC_30_TLF35584_EQ2_SYSPCFG1OFINITCONFIG                      
#define SBC_30_TLF35584_EQ2_SBCSPICHL_SBCSPICHANNELOFSPICHANNEL       
#define SBC_30_TLF35584_EQ2_SBCSPISEQ_SBCSPISEQUENCEOFSPISEQUENCE     
#define SBC_30_TLF35584_EQ2_DEVCTRLNORMALOFSUPPLYCONFIG               
#define SBC_30_TLF35584_EQ2_DEVCTRLSTANDBYOFSUPPLYCONFIG              
#define SBC_30_TLF35584_EQ2_SYSPCFG0NORMALOFSUPPLYCONFIG              
#define SBC_30_TLF35584_EQ2_SYSPCFG0SLEEPOFSUPPLYCONFIG               
#define SBC_30_TLF35584_EQ2_SYSPCFG0STANDBYOFSUPPLYCONFIG             
#define SBC_30_TLF35584_EQ2_DEVICECONFIGURATIONOFPCCONFIG             Sbc_30_Tlf35584_DeviceConfiguration
#define SBC_30_TLF35584_EQ2_INITCONFIGOFPCCONFIG                      Sbc_30_Tlf35584_InitConfig
#define SBC_30_TLF35584_EQ2_SPICHANNELOFPCCONFIG                      Sbc_30_Tlf35584_SpiChannel
#define SBC_30_TLF35584_EQ2_SPISEQUENCEOFPCCONFIG                     Sbc_30_Tlf35584_SpiSequence
#define SBC_30_TLF35584_EQ2_SUPPLYCONFIGOFPCCONFIG                    Sbc_30_Tlf35584_SupplyConfig
/** 
  \}
*/ 

/** 
  \defgroup  Sbc_30_Tlf35584PCSymbolicInitializationPointers  Sbc_30_Tlf35584 Symbolic Initialization Pointers (PRE_COMPILE)
  \brief  Symbolic initialization pointers to be used in the call of a preinit or init function.
  \{
*/ 
#define Sbc_30_Tlf35584_Config_Ptr                                    NULL_PTR  /**< symbolic identifier which shall be used to initialize 'Sbc_30_Tlf35584' */
/** 
  \}
*/ 

/** 
  \defgroup  Sbc_30_Tlf35584PCInitializationSymbols  Sbc_30_Tlf35584 Initialization Symbols (PRE_COMPILE)
  \brief  Symbolic initialization pointers which may be used in the call of a preinit or init function. Please note, that the defined value can be a 'NULL_PTR' and the address operator is not usable.
  \{
*/ 
#define Sbc_30_Tlf35584_Config                                        NULL_PTR  /**< symbolic identifier which could be used to initialize 'Sbc_30_Tlf35584 */
/** 
  \}
*/ 

/** 
  \defgroup  Sbc_30_Tlf35584PCGeneral  Sbc_30_Tlf35584 General (PRE_COMPILE)
  \brief  General constant defines not associated with a group of defines.
  \{
*/ 
#define SBC_30_TLF35584_CHECK_INIT_POINTER                            STD_OFF  /**< STD_ON if the init pointer shall not be used as NULL_PTR and a check shall validate this. */
#define SBC_30_TLF35584_FINAL_MAGIC_NUMBER                            0xFF1Eu  /**< the precompile constant to validate the size of the initialization structure at initialization time of Sbc_30_Tlf35584 */
#define SBC_30_TLF35584_INDIVIDUAL_POSTBUILD                          STD_OFF  /**< the precompile constant to check, that the module is individual postbuildable. The module 'Sbc_30_Tlf35584' is not configured to be postbuild capable. */
#define SBC_30_TLF35584_INIT_DATA                                     SBC_30_TLF35584_CONST  /**< CompilerMemClassDefine for the initialization data. */
#define SBC_30_TLF35584_INIT_DATA_HASH_CODE                           -1443657596  /**< the precompile constant to validate the initialization structure at initialization time of Sbc_30_Tlf35584 with a hashcode. The seed value is '0xFF1Eu' */
#define SBC_30_TLF35584_USE_ECUM_BSW_ERROR_HOOK                       STD_OFF  /**< STD_ON if the EcuM_BswErrorHook shall be called in the ConfigPtr check. */
#define SBC_30_TLF35584_USE_INIT_POINTER                              STD_OFF  /**< STD_ON if the init pointer Sbc_30_Tlf35584 shall be used. */
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
  /* PRQA S 3453 MACROS_3453 */  /* MD_CSL_3453 */
/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL FUNCTION MACROS
**********************************************************************************************************************/
/** 
  \defgroup  Sbc_30_Tlf35584PCGetConstantDuplicatedRootDataMacros  Sbc_30_Tlf35584 Get Constant Duplicated Root Data Macros (PRE_COMPILE)
  \brief  These macros can be used to read deduplicated by constance root data elements.
  \{
*/ 
#define Sbc_30_Tlf35584_GetDeviceConfigurationOfPCConfig()            Sbc_30_Tlf35584_DeviceConfiguration  /**< the pointer to Sbc_30_Tlf35584_DeviceConfiguration */
#define Sbc_30_Tlf35584_GetInitConfigOfPCConfig()                     Sbc_30_Tlf35584_InitConfig  /**< the pointer to Sbc_30_Tlf35584_InitConfig */
#define Sbc_30_Tlf35584_GetSpiChannelOfPCConfig()                     Sbc_30_Tlf35584_SpiChannel  /**< the pointer to Sbc_30_Tlf35584_SpiChannel */
#define Sbc_30_Tlf35584_GetSpiSequenceOfPCConfig()                    Sbc_30_Tlf35584_SpiSequence  /**< the pointer to Sbc_30_Tlf35584_SpiSequence */
#define Sbc_30_Tlf35584_GetSupplyConfigOfPCConfig()                   Sbc_30_Tlf35584_SupplyConfig  /**< the pointer to Sbc_30_Tlf35584_SupplyConfig */
/** 
  \}
*/ 

/** 
  \defgroup  Sbc_30_Tlf35584PCGetDataMacros  Sbc_30_Tlf35584 Get Data Macros (PRE_COMPILE)
  \brief  These macros can be used to read CONST and VAR data.
  \{
*/ 
#define Sbc_30_Tlf35584_GetNumberOfCanTrcvOfDeviceConfiguration(Index) (Sbc_30_Tlf35584_GetDeviceConfigurationOfPCConfig()[(Index)].NumberOfCanTrcvOfDeviceConfiguration)
#define Sbc_30_Tlf35584_GetNumberOfLinTrcvOfDeviceConfiguration(Index) (Sbc_30_Tlf35584_GetDeviceConfigurationOfPCConfig()[(Index)].NumberOfLinTrcvOfDeviceConfiguration)
#define Sbc_30_Tlf35584_GetNumberOfWdgOfDeviceConfiguration(Index)    (Sbc_30_Tlf35584_GetDeviceConfigurationOfPCConfig()[(Index)].NumberOfWdgOfDeviceConfiguration)
#define Sbc_30_Tlf35584_GetWuSrcPorOfDeviceConfiguration(Index)       (Sbc_30_Tlf35584_GetDeviceConfigurationOfPCConfig()[(Index)].WuSrcPorOfDeviceConfiguration)
#define Sbc_30_Tlf35584_GetSYSPCFG1OfInitConfig(Index)                (Sbc_30_Tlf35584_GetInitConfigOfPCConfig()[(Index)].SYSPCFG1OfInitConfig)
#define Sbc_30_Tlf35584_GetSbcSpiChl_SbcSpiChannelOfSpiChannel(Index) ((Spi_ChannelType)Sbc_30_Tlf35584_GetSpiChannelOfPCConfig()[(Index)].SbcSpiChl_SbcSpiChannelOfSpiChannel)
#define Sbc_30_Tlf35584_GetSbcSpiSeq_SbcSpiSequenceOfSpiSequence(Index) ((Spi_SequenceType)Sbc_30_Tlf35584_GetSpiSequenceOfPCConfig()[(Index)].SbcSpiSeq_SbcSpiSequenceOfSpiSequence)
#define Sbc_30_Tlf35584_GetDEVCTRLnormalOfSupplyConfig(Index)         (Sbc_30_Tlf35584_GetSupplyConfigOfPCConfig()[(Index)].DEVCTRLnormalOfSupplyConfig)
#define Sbc_30_Tlf35584_GetDEVCTRLstandbyOfSupplyConfig(Index)        (Sbc_30_Tlf35584_GetSupplyConfigOfPCConfig()[(Index)].DEVCTRLstandbyOfSupplyConfig)
#define Sbc_30_Tlf35584_GetSYSPCFG0normalOfSupplyConfig(Index)        (Sbc_30_Tlf35584_GetSupplyConfigOfPCConfig()[(Index)].SYSPCFG0normalOfSupplyConfig)
#define Sbc_30_Tlf35584_GetSYSPCFG0sleepOfSupplyConfig(Index)         (Sbc_30_Tlf35584_GetSupplyConfigOfPCConfig()[(Index)].SYSPCFG0sleepOfSupplyConfig)
#define Sbc_30_Tlf35584_GetSYSPCFG0standbyOfSupplyConfig(Index)       (Sbc_30_Tlf35584_GetSupplyConfigOfPCConfig()[(Index)].SYSPCFG0standbyOfSupplyConfig)
/** 
  \}
*/ 

/** 
  \defgroup  Sbc_30_Tlf35584PCHasMacros  Sbc_30_Tlf35584 Has Macros (PRE_COMPILE)
  \brief  These macros can be used to detect at runtime a deactivated piece of information. TRUE in the CONFIGURATION_VARIANT PRE-COMPILE, TRUE or FALSE in the CONFIGURATION_VARIANT POST-BUILD.
  \{
*/ 
#define Sbc_30_Tlf35584_HasDeviceConfiguration()                      (TRUE != FALSE)
#define Sbc_30_Tlf35584_HasNumberOfCanTrcvOfDeviceConfiguration()     (TRUE != FALSE)
#define Sbc_30_Tlf35584_HasNumberOfLinTrcvOfDeviceConfiguration()     (TRUE != FALSE)
#define Sbc_30_Tlf35584_HasNumberOfWdgOfDeviceConfiguration()         (TRUE != FALSE)
#define Sbc_30_Tlf35584_HasWuSrcPorOfDeviceConfiguration()            (TRUE != FALSE)
#define Sbc_30_Tlf35584_HasInitConfig()                               (TRUE != FALSE)
#define Sbc_30_Tlf35584_HasSYSPCFG1OfInitConfig()                     (TRUE != FALSE)
#define Sbc_30_Tlf35584_HasSpiChannel()                               (TRUE != FALSE)
#define Sbc_30_Tlf35584_HasSbcSpiChl_SbcSpiChannelOfSpiChannel()      (TRUE != FALSE)
#define Sbc_30_Tlf35584_HasSpiSequence()                              (TRUE != FALSE)
#define Sbc_30_Tlf35584_HasSbcSpiSeq_SbcSpiSequenceOfSpiSequence()    (TRUE != FALSE)
#define Sbc_30_Tlf35584_HasSupplyConfig()                             (TRUE != FALSE)
#define Sbc_30_Tlf35584_HasDEVCTRLnormalOfSupplyConfig()              (TRUE != FALSE)
#define Sbc_30_Tlf35584_HasDEVCTRLstandbyOfSupplyConfig()             (TRUE != FALSE)
#define Sbc_30_Tlf35584_HasSYSPCFG0normalOfSupplyConfig()             (TRUE != FALSE)
#define Sbc_30_Tlf35584_HasSYSPCFG0sleepOfSupplyConfig()              (TRUE != FALSE)
#define Sbc_30_Tlf35584_HasSYSPCFG0standbyOfSupplyConfig()            (TRUE != FALSE)
#define Sbc_30_Tlf35584_HasPCConfig()                                 (TRUE != FALSE)
#define Sbc_30_Tlf35584_HasDeviceConfigurationOfPCConfig()            (TRUE != FALSE)
#define Sbc_30_Tlf35584_HasInitConfigOfPCConfig()                     (TRUE != FALSE)
#define Sbc_30_Tlf35584_HasSpiChannelOfPCConfig()                     (TRUE != FALSE)
#define Sbc_30_Tlf35584_HasSpiSequenceOfPCConfig()                    (TRUE != FALSE)
#define Sbc_30_Tlf35584_HasSupplyConfigOfPCConfig()                   (TRUE != FALSE)
/** 
  \}
*/ 

  /* PRQA L:MACROS_3453 */
/** 
  \}
*/ 

/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL ACCESS FUNCTION MACROS
**********************************************************************************************************************/


/**********************************************************************************************************************
  GLOBAL DATA TYPES AND STRUCTURES
**********************************************************************************************************************/
/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL DATA TYPES AND STRUCTURES
**********************************************************************************************************************/
/** 
  \defgroup  Sbc_30_Tlf35584PCIterableTypes  Sbc_30_Tlf35584 Iterable Types (PRE_COMPILE)
  \brief  These type definitions are used to iterate over an array with least processor cycles for variable access as possible.
  \{
*/ 
/**   \brief  type used to iterate Sbc_30_Tlf35584_DeviceConfiguration */
typedef uint8_least Sbc_30_Tlf35584_DeviceConfigurationIterType;

/**   \brief  type used to iterate Sbc_30_Tlf35584_InitConfig */
typedef uint8_least Sbc_30_Tlf35584_InitConfigIterType;

/**   \brief  type used to iterate Sbc_30_Tlf35584_SpiChannel */
typedef uint8_least Sbc_30_Tlf35584_SpiChannelIterType;

/**   \brief  type used to iterate Sbc_30_Tlf35584_SpiSequence */
typedef uint8_least Sbc_30_Tlf35584_SpiSequenceIterType;

/**   \brief  type used to iterate Sbc_30_Tlf35584_SupplyConfig */
typedef uint8_least Sbc_30_Tlf35584_SupplyConfigIterType;

/** 
  \}
*/ 

/** 
  \defgroup  Sbc_30_Tlf35584PCValueTypes  Sbc_30_Tlf35584 Value Types (PRE_COMPILE)
  \brief  These type definitions are used for value based data representations.
  \{
*/ 
/**   \brief  value based type definition for Sbc_30_Tlf35584_NumberOfCanTrcvOfDeviceConfiguration */
typedef uint8 Sbc_30_Tlf35584_NumberOfCanTrcvOfDeviceConfigurationType;

/**   \brief  value based type definition for Sbc_30_Tlf35584_NumberOfLinTrcvOfDeviceConfiguration */
typedef uint8 Sbc_30_Tlf35584_NumberOfLinTrcvOfDeviceConfigurationType;

/**   \brief  value based type definition for Sbc_30_Tlf35584_NumberOfWdgOfDeviceConfiguration */
typedef uint8 Sbc_30_Tlf35584_NumberOfWdgOfDeviceConfigurationType;

/**   \brief  value based type definition for Sbc_30_Tlf35584_WuSrcPorOfDeviceConfiguration */
typedef uint8 Sbc_30_Tlf35584_WuSrcPorOfDeviceConfigurationType;

/**   \brief  value based type definition for Sbc_30_Tlf35584_SYSPCFG1OfInitConfig */
typedef uint8 Sbc_30_Tlf35584_SYSPCFG1OfInitConfigType;

/**   \brief  value based type definition for Sbc_30_Tlf35584_SbcSpiChl_SbcSpiChannelOfSpiChannel */
typedef uint8 Sbc_30_Tlf35584_SbcSpiChl_SbcSpiChannelOfSpiChannelType;

/**   \brief  value based type definition for Sbc_30_Tlf35584_SbcSpiSeq_SbcSpiSequenceOfSpiSequence */
typedef uint8 Sbc_30_Tlf35584_SbcSpiSeq_SbcSpiSequenceOfSpiSequenceType;

/**   \brief  value based type definition for Sbc_30_Tlf35584_DEVCTRLnormalOfSupplyConfig */
typedef uint8 Sbc_30_Tlf35584_DEVCTRLnormalOfSupplyConfigType;

/**   \brief  value based type definition for Sbc_30_Tlf35584_DEVCTRLstandbyOfSupplyConfig */
typedef uint8 Sbc_30_Tlf35584_DEVCTRLstandbyOfSupplyConfigType;

/**   \brief  value based type definition for Sbc_30_Tlf35584_SYSPCFG0normalOfSupplyConfig */
typedef uint8 Sbc_30_Tlf35584_SYSPCFG0normalOfSupplyConfigType;

/**   \brief  value based type definition for Sbc_30_Tlf35584_SYSPCFG0sleepOfSupplyConfig */
typedef uint8 Sbc_30_Tlf35584_SYSPCFG0sleepOfSupplyConfigType;

/**   \brief  value based type definition for Sbc_30_Tlf35584_SYSPCFG0standbyOfSupplyConfig */
typedef uint8 Sbc_30_Tlf35584_SYSPCFG0standbyOfSupplyConfigType;

/** 
  \}
*/ 

/** 
  \defgroup  Sbc_30_Tlf35584PCStructTypes  Sbc_30_Tlf35584 Struct Types (PRE_COMPILE)
  \brief  These type definitions are used for structured data representations.
  \{
*/ 
/**   \brief  type used in Sbc_30_Tlf35584_DeviceConfiguration */
typedef struct sSbc_30_Tlf35584_DeviceConfigurationType
{
  Sbc_30_Tlf35584_NumberOfCanTrcvOfDeviceConfigurationType NumberOfCanTrcvOfDeviceConfiguration;  /**< Specifies the number of CAN Transceivers that are used on this device */
  Sbc_30_Tlf35584_NumberOfLinTrcvOfDeviceConfigurationType NumberOfLinTrcvOfDeviceConfiguration;  /**< Specifies the number of LIN Transceivers that are used on this device */
  Sbc_30_Tlf35584_NumberOfWdgOfDeviceConfigurationType NumberOfWdgOfDeviceConfiguration;  /**< Specifies the number of Watchdogs that are used on this device */
  Sbc_30_Tlf35584_WuSrcPorOfDeviceConfigurationType WuSrcPorOfDeviceConfiguration;  /**< The wakeup source that is used to notify power-on wakeup events */
} Sbc_30_Tlf35584_DeviceConfigurationType;

/**   \brief  type used in Sbc_30_Tlf35584_InitConfig */
typedef struct sSbc_30_Tlf35584_InitConfigType
{
  Sbc_30_Tlf35584_SYSPCFG1OfInitConfigType SYSPCFG1OfInitConfig;  /**< A byte value that is used by the driver to configure the SYSPCFG1 register in Sbc initialization sequence. */
} Sbc_30_Tlf35584_InitConfigType;

/**   \brief  type used in Sbc_30_Tlf35584_SpiChannel */
typedef struct sSbc_30_Tlf35584_SpiChannelType
{
  Sbc_30_Tlf35584_SbcSpiChl_SbcSpiChannelOfSpiChannelType SbcSpiChl_SbcSpiChannelOfSpiChannel;  /**< Spi Channel to access SbcDevice 0 */
} Sbc_30_Tlf35584_SpiChannelType;

/**   \brief  type used in Sbc_30_Tlf35584_SpiSequence */
typedef struct sSbc_30_Tlf35584_SpiSequenceType
{
  Sbc_30_Tlf35584_SbcSpiSeq_SbcSpiSequenceOfSpiSequenceType SbcSpiSeq_SbcSpiSequenceOfSpiSequence;  /**< Spi Sequence to access SbcDevice 0 */
} Sbc_30_Tlf35584_SpiSequenceType;

/**   \brief  type used in Sbc_30_Tlf35584_SupplyConfig */
typedef struct sSbc_30_Tlf35584_SupplyConfigType
{
  Sbc_30_Tlf35584_DEVCTRLnormalOfSupplyConfigType DEVCTRLnormalOfSupplyConfig;  /**< A byte value that is used by the driver to configure the DEVCTRL register for SBC_SYS_NORMAL. */
  Sbc_30_Tlf35584_DEVCTRLstandbyOfSupplyConfigType DEVCTRLstandbyOfSupplyConfig;  /**< A byte value that is used by the driver to configure the DEVCTRL register for SBC_SYS_STANDBY. */
  Sbc_30_Tlf35584_SYSPCFG0normalOfSupplyConfigType SYSPCFG0normalOfSupplyConfig;  /**< A byte value that is used by the driver to configure the SYSPCFG0 register for SBC_SYS_NORMAL. */
  Sbc_30_Tlf35584_SYSPCFG0sleepOfSupplyConfigType SYSPCFG0sleepOfSupplyConfig;  /**< A byte value that is used by the driver to configure the SYSPCFG0 register for SBC_SYS_SLEEP. */
  Sbc_30_Tlf35584_SYSPCFG0standbyOfSupplyConfigType SYSPCFG0standbyOfSupplyConfig;  /**< A byte value that is used by the driver to configure the SYSPCFG0 register for SBC_SYS_STANDBY. */
} Sbc_30_Tlf35584_SupplyConfigType;

/** 
  \}
*/ 

/** 
  \defgroup  Sbc_30_Tlf35584PCRootValueTypes  Sbc_30_Tlf35584 Root Value Types (PRE_COMPILE)
  \brief  These type definitions are used for value representations in root arrays.
  \{
*/ 
/**   \brief  type used in Sbc_30_Tlf35584_PCConfig */
typedef struct sSbc_30_Tlf35584_PCConfigType
{
  uint8 Sbc_30_Tlf35584_PCConfigNeverUsed;  /**< dummy entry for the structure in the configuration variant precompile which is not used by the code. */
} Sbc_30_Tlf35584_PCConfigType;

typedef Sbc_30_Tlf35584_PCConfigType Sbc_30_Tlf35584_ConfigType;  /**< A structure type is present for data in each configuration class. This typedef redefines the probably different name to the specified one. */

/** 
  \}
*/ 



/**********************************************************************************************************************
  GLOBAL DATA PROTOTYPES
**********************************************************************************************************************/
/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL DATA PROTOTYPES
**********************************************************************************************************************/
/**********************************************************************************************************************
  Sbc_30_Tlf35584_DeviceConfiguration
**********************************************************************************************************************/
/** 
  \var    Sbc_30_Tlf35584_DeviceConfiguration
  \brief  Stores general information about one device.
  \details
  Element            Description
  NumberOfCanTrcv    Specifies the number of CAN Transceivers that are used on this device
  NumberOfLinTrcv    Specifies the number of LIN Transceivers that are used on this device
  NumberOfWdg        Specifies the number of Watchdogs that are used on this device
  WuSrcPor           The wakeup source that is used to notify power-on wakeup events
*/ 
#define SBC_30_TLF35584_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
extern CONST(Sbc_30_Tlf35584_DeviceConfigurationType, SBC_30_TLF35584_CONST) Sbc_30_Tlf35584_DeviceConfiguration[1];  /* PRQA S 0777 */  /* MD_MSR_5.1_777 */
#define SBC_30_TLF35584_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Sbc_30_Tlf35584_InitConfig
**********************************************************************************************************************/
/** 
  \var    Sbc_30_Tlf35584_InitConfig
  \details
  Element     Description
  SYSPCFG1    A byte value that is used by the driver to configure the SYSPCFG1 register in Sbc initialization sequence.
*/ 
#define SBC_30_TLF35584_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
extern CONST(Sbc_30_Tlf35584_InitConfigType, SBC_30_TLF35584_CONST) Sbc_30_Tlf35584_InitConfig[1];
#define SBC_30_TLF35584_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Sbc_30_Tlf35584_SpiChannel
**********************************************************************************************************************/
/** 
  \var    Sbc_30_Tlf35584_SpiChannel
  \details
  Element                    Description
  SbcSpiChl_SbcSpiChannel    Spi Channel to access SbcDevice 0
*/ 
#define SBC_30_TLF35584_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
extern CONST(Sbc_30_Tlf35584_SpiChannelType, SBC_30_TLF35584_CONST) Sbc_30_Tlf35584_SpiChannel[1];
#define SBC_30_TLF35584_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Sbc_30_Tlf35584_SpiSequence
**********************************************************************************************************************/
/** 
  \var    Sbc_30_Tlf35584_SpiSequence
  \details
  Element                     Description
  SbcSpiSeq_SbcSpiSequence    Spi Sequence to access SbcDevice 0
*/ 
#define SBC_30_TLF35584_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
extern CONST(Sbc_30_Tlf35584_SpiSequenceType, SBC_30_TLF35584_CONST) Sbc_30_Tlf35584_SpiSequence[1];
#define SBC_30_TLF35584_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Sbc_30_Tlf35584_SupplyConfig
**********************************************************************************************************************/
/** 
  \var    Sbc_30_Tlf35584_SupplyConfig
  \details
  Element            Description
  DEVCTRLnormal      A byte value that is used by the driver to configure the DEVCTRL register for SBC_SYS_NORMAL.
  DEVCTRLstandby     A byte value that is used by the driver to configure the DEVCTRL register for SBC_SYS_STANDBY.
  SYSPCFG0normal     A byte value that is used by the driver to configure the SYSPCFG0 register for SBC_SYS_NORMAL.
  SYSPCFG0sleep      A byte value that is used by the driver to configure the SYSPCFG0 register for SBC_SYS_SLEEP.
  SYSPCFG0standby    A byte value that is used by the driver to configure the SYSPCFG0 register for SBC_SYS_STANDBY.
*/ 
#define SBC_30_TLF35584_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
extern CONST(Sbc_30_Tlf35584_SupplyConfigType, SBC_30_TLF35584_CONST) Sbc_30_Tlf35584_SupplyConfig[1];
#define SBC_30_TLF35584_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */



/**********************************************************************************************************************
  GLOBAL FUNCTION PROTOTYPES
**********************************************************************************************************************/
/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL FUNCTION PROTOTYPES
**********************************************************************************************************************/


/**********************************************************************************************************************
  SWITCHES (HW SPECIFIC)
**********************************************************************************************************************/




#endif  /* SBC_30_TLF35584_CFG_H */
/**********************************************************************************************************************
  END OF FILE: Sbc_30_Tlf35584_Cfg.h ; Generated with Version 1.00.01
**********************************************************************************************************************/
