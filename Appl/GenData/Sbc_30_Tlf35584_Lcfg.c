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
 *              File: Sbc_30_Tlf35584_Lcfg.c
 *   Generation Time: 2026-07-29 10:31:07
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
  INCLUDES
**********************************************************************************************************************/
#define SBC_30_TLF35584_LCFG
#define SBC_INTERNAL
#define SBC_30_TLF35584_INTERNAL

/* PRQA S 0779 Sbc_Cfg_Include_Tag */ /* MD_Sbc_0779 */
/* PRQA S 3453 Sbc_Cfg_Include_Tag */ /* MD_Sbc_3453 */
#include "Sbc_30_Tlf35584_Cfg.h"
/* PRQA L:Sbc_Cfg_Include_Tag */

#include "Spi.h"

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
  SECTION: LOCAL DATA TYPES AND STRUCTURES
**********************************************************************************************************************/


/**********************************************************************************************************************
  LOCAL DATA
**********************************************************************************************************************/
/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
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
CONST(Sbc_30_Tlf35584_DeviceConfigurationType, SBC_30_TLF35584_CONST) Sbc_30_Tlf35584_DeviceConfiguration[1] = {
    /* Index    NumberOfCanTrcv  NumberOfLinTrcv  NumberOfWdg  WuSrcPor           Comment */
  { /*     0 */              0u,              0u,          0u, 0x00000000u }   /* [SbcDevice] */
};
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
CONST(Sbc_30_Tlf35584_InitConfigType, SBC_30_TLF35584_CONST) Sbc_30_Tlf35584_InitConfig[1] = {
    /* Index    SYSPCFG1 */
  { /*     0 */    0x08u }
};
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
CONST(Sbc_30_Tlf35584_SpiChannelType, SBC_30_TLF35584_CONST) Sbc_30_Tlf35584_SpiChannel[1] = {
    /* Index    SbcSpiChl_SbcSpiChannel             */
  { /*     0 */ SpiConf_SpiChannel_SpiChannel_35584 }
};
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
CONST(Sbc_30_Tlf35584_SpiSequenceType, SBC_30_TLF35584_CONST) Sbc_30_Tlf35584_SpiSequence[1] = {
    /* Index    SbcSpiSeq_SbcSpiSequence              */
  { /*     0 */ SpiConf_SpiSequence_SpiSequence_35584 }
};
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
CONST(Sbc_30_Tlf35584_SupplyConfigType, SBC_30_TLF35584_CONST) Sbc_30_Tlf35584_SupplyConfig[1] = {
    /* Index    DEVCTRLnormal  DEVCTRLstandby  SYSPCFG0normal  SYSPCFG0sleep  SYSPCFG0standby */
  { /*     0 */         0xE8u,          0xE8u,          0x01u,         0x01u,           0x01u }
};
#define SBC_30_TLF35584_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */



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
  END OF FILE: Sbc_30_Tlf35584_Lcfg.c ; Generated with Version 1.00.01
**********************************************************************************************************************/
