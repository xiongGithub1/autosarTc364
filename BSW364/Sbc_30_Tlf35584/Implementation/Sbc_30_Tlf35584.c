/* Kernbauer Version: 1.16 Konfiguration: DrvSbc_Tlf35584Asr Erzeugungsgangnummer: 86 */

/*!********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *  Copyright (c) 2016 by Vector Informatik GmbH.                                              All rights reserved.
 *
 *                This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vector Informatik GmbH.
 *  \endverbatim
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         \file  Sbc_30_Tlf35584.c
 *        \brief  System Basis Chip Implementation
 *
 *      \details  This file contains the implementation of a hardware specific SBC module.
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Refer to the module's header file.
 * 
 *  FILE VERSION
 *  -------------------------------------------------------------------------------------------------------------------
 *  Refer to the VERSION CHECK below.
 *********************************************************************************************************************/

/* Defined only in Sbc.c */
#define SBC_SOURCE
#define SBC_INTERNAL
#define SBC_30_TLF35584_INTERNAL

/*********************************************************************************************************************
 *  INCLUDES
 ********************************************************************************************************************/

/* PRQA S 0779 Sbc_Include_Tag */ /* MD_Sbc_0779 */
#include "Sbc_30_Tlf35584.h"
/* PRQA L:Sbc_Include_Tag */

#include "EcuM.h"
#include "SchM_Sbc_30_Tlf35584.h"

#if (SBC_30_TLF35584_DEV_ERROR_REPORT == STD_ON)
# include "Det.h"
#endif

/*********************************************************************************************************************
 *  VERSION CHECK
 ********************************************************************************************************************/

/* Check the version of Sbc header file */
#if (  (SBC_30_CORE_SW_MAJOR_VERSION != (2u)) \
    || (SBC_30_CORE_SW_MINOR_VERSION != (1u)) \
    || (SBC_30_CORE_SW_PATCH_VERSION != (2u)) )
 #error "Vendor specific version numbers of Sbc.c and Sbc.h are inconsistent."
#endif

/* Check the version of the configuration header file */
#if ( SBC_30_TLF35584_CFG_BASE_COMPAT_VERSION != 0x0101u )
 #error "The configuration data contained in Sbc_30_Tlf35584_Cfg.h is not compatible to this implementation."
#endif


/*********************************************************************************************************************
 *  LOCAL CONSTANT MACROS
 *********************************************************************************************************************/
/* Controls the scope of local variables. By default, internal variables are static. */
#if !defined(SBC_30_TLF35584_LOCAL) /* COV_SBC_LOCAL_SCOPE */
# define SBC_LOCAL static
#else
# define SBC_LOCAL SBC_30_TLF35584_LOCAL
#endif

#if defined(SBC_30_TLF35584_LOCAL_INLINE) /* COV_SBC_LOCAL_SCOPE */
# define SBC_LOCAL_INLINE SBC_30_TLF35584_LOCAL_INLINE
#else
# define SBC_LOCAL_INLINE LOCAL_INLINE
#endif

/*********************************************************************************************************************
 *  LOCAL FUNCTION MACROS
 *********************************************************************************************************************/

/* PRQA S 3453 Sbc_LocalFunctionMacros_Tag */ /* MD_Sbc_3453 */

/* Macros to access the configuration data */
/* Retrieves the number of configured SBC devices */
#define Sbc_Cfg_GetNumberOfDevices()              (SBC_30_TLF35584_NUMBER_OF_DEVICES)

/* Retrieves the number of CanTrcv for a given SBC device */
#define Sbc_Cfg_GetNumberOfCanTrcv(dId)           (Sbc_30_Tlf35584_GetNumberOfCanTrcvOfDeviceConfiguration(dId))

/* Retrieves the number of LinTrcv for a given SBC device */
#define Sbc_Cfg_GetNumberOfLinTrcv(dId)           (Sbc_30_Tlf35584_GetNumberOfLinTrcvOfDeviceConfiguration(dId))

/* Retrieves the number of Wdg for a given SBC device */
#define Sbc_Cfg_GetNumberOfWdg(dId)               (Sbc_30_Tlf35584_GetNumberOfWdgOfDeviceConfiguration(dId))

/* Retrieves the wake-up source of POR for a given SBC device */
#define Sbc_Cfg_GetWuSrcPor(dId)                  (Sbc_30_Tlf35584_GetWuSrcPorOfDeviceConfiguration(dId))

/* Retrieves a index to the watchdog config */
#define Sbc_Cfg_GetWdgConfigIdx(dId, pId)         (Sbc_30_Tlf35584_GetWdgConfigStartIdxOfDeviceConfiguration(dId) + (pId))

/* Retrieves a index to the CanTrcv config */
#define Sbc_Cfg_GetCanTrcvConfigIdx(dId, pId)     (Sbc_30_Tlf35584_GetCanTrcvConfigStartIdxOfDeviceConfiguration(dId) + (pId))

/* Retrieves a index to the LinTrcv config */
#define Sbc_Cfg_GetLinTrcvConfigIdx(dId, pId)     (Sbc_30_Tlf35584_GetLinTrcvConfigStartIdxOfDeviceConfiguration(dId) + (pId))

/* Retrieves a index to the CanTrcv PN config */
#define Sbc_Cfg_GetCanTrcvPnConfigIdx(dId, pId)   (Sbc_30_Tlf35584_GetCanTrcvPnConfigIdxOfCanTrcvConfig( Sbc_Cfg_GetCanTrcvConfigIdx(dId, pId) ))

/* Retrieves the initial watchdog mode */
#define Sbc_Cfg_GetWdgInitialMode(dId, pId)       (Sbc_30_Tlf35584_GetWdgInitModeOfWdgConfig(Sbc_Cfg_GetWdgConfigIdx(dId, pId)))


/* Macros to access runtime data */
/* Access to the system status of the given device */
#define Sbc_Rt_GetSystemStatus(dId)           (Sbc_SystemStatus[dId])

/* Access to the CanTrcv status of the given device */
#define Sbc_Rt_GetCanTrcvStatus(dId, pId)     (Sbc_CanTrcvStatus[dId][pId])

/* Access to the LinTrcv status of the given device */
#define Sbc_Rt_GetLinTrcvStatus(dId, pId)     (Sbc_LinTrcvStatus[dId][pId])

/* Get the Wdg mode of the given device */
#define Sbc_Rt_GetWdgMode(dId, pId)           (Sbc_WdgMode[dId][pId])

/* Set the Wdg mode of the given device */
#define Sbc_Rt_SetWdgMode(dId, pId, newval)   (Sbc_WdgMode[dId][pId] = (newval))


/* Status handling */
/* Updates the status val by clearing the mask and writing the new value */
/* PRQA S 3412 3 */ /* MD_Sbc_3412 */
#define Sbc_UpdateStatusFlags(val, newval)            (val)->Events |= (newval).Events; \
                                                      (val)->States  = (newval).States; \
                                                      (val)->Mode    = (newval).Mode

/* Resets a bit in flags if the corresponding flag in wflags is set to 1 */
#define Sbc_ClearEventFlags(flags, wflags)            ( (flags)->Events &= (Sbc_CanTrcvEventType)(~(wflags)) )

/* Macros for ID handling */
/* Create an SbcId using the given dId and pId */
#define Sbc_MakeId(dId, pId)            ( ( ((dId) & 0xFFF)<<4 ) | ( (pId) & 0xF ) )

/* Retrieve the Device Id from a given Id */
#define Sbc_GetDeviceIndex(id)          ( ( (id) >> 4 ) & 0xFFF )

/* Retrieve the Peripheral Id from a given Id */
#define Sbc_GetPeriphalIndex(id)        ( ( (id) >> 0 ) & 0xF )

/* Used for DET checks */

/* Checks if the Module is initialized */
#define Sbc_IsModuleInitialized()         ( Sbc_ModuleInitialized == SBC_INIT )

/* Checks if the SBC ID is valid */
#define Sbc_IsIdValid(id)             ( (Sbc_GetDeviceIndex(id) < Sbc_Cfg_GetNumberOfDevices()) && \
                                        (Sbc_GetPeriphalIndex(id) == 0u) )

/* Checks if the CanTrcv ID is valid */
#define Sbc_IsCanTrcvIdValid(id)   ( (Sbc_GetDeviceIndex(id) < Sbc_Cfg_GetNumberOfDevices()) && \
                                     (Sbc_GetPeriphalIndex(id) < Sbc_Cfg_GetNumberOfCanTrcv(Sbc_GetDeviceIndex(id))) && \
                                     (Sbc_GetPeriphalIndex(id) < SBC_30_TLF35584_MAX_NUMBER_OF_CANTRCV) )
                                     
/* Checks if the LinTrcv ID is valid */
#define Sbc_IsLinTrcvIdValid(id)   ( (Sbc_GetDeviceIndex(id) < Sbc_Cfg_GetNumberOfDevices()) && \
                                     (Sbc_GetPeriphalIndex(id) < Sbc_Cfg_GetNumberOfLinTrcv(Sbc_GetDeviceIndex(id))) && \
                                     (Sbc_GetPeriphalIndex(id) < SBC_30_TLF35584_MAX_NUMBER_OF_LINTRCV) )

/* Checks if the Wdg ID is valid */
#define Sbc_IsWdgIdValid(id)   ( (Sbc_GetDeviceIndex(id) < Sbc_Cfg_GetNumberOfDevices()) && \
                                 (Sbc_GetPeriphalIndex(id) < Sbc_Cfg_GetNumberOfWdg(Sbc_GetDeviceIndex(id))) && \
                                 (Sbc_GetPeriphalIndex(id) < SBC_30_TLF35584_MAX_NUMBER_OF_WDG) )

/* Checks if the System Mode is in range */
#define Sbc_IsSysModeValid(mode)      ( ((mode) >= SBC_SYS_MODE_NORMAL) && ((mode) <= SBC_SYS_MODE_SLEEP) )

/* Checks if the CanTrcv Mode is in range */
#define Sbc_IsCanTrcvModeValid(mode)  ( ((mode) >= SBC_CANTRCV_MODE_NORMAL) && ((mode) <= SBC_CANTRCV_MODE_STANDBY) )

/* Checks if the LinTrcv Mode is in range */
#define Sbc_IsLinTrcvModeValid(mode)  ( ((mode) >= SBC_LINTRCV_MODE_NORMAL) && ((mode) <= SBC_LINTRCV_MODE_STANDBY) )

/* Checks if the Wdg Mode is in range */
#define Sbc_IsWdgModeValid(mode)      ( ((mode) >= SBC_WDG_MODE_OFF) && ((mode) <= SBC_WDG_MODE_FAST) )

/* Checks if the pointer is valid */
#define Sbc_IsPtrValid(ptr)           ( (ptr) != NULL_PTR )

/* Enter a critical area */
/* PRQA S 0342 1 */ /* MD_Sbc_0342 */
#define Sbc_EnterCritical(s) SchM_Enter_Sbc_30_Tlf35584_##s()

/* Leave a critical area */
/* PRQA S 0342 1 */ /* MD_Sbc_0342 */
#define Sbc_LeaveCritical(s) SchM_Exit_Sbc_30_Tlf35584_##s()

/* PRQA L:Sbc_LocalFunctionMacros_Tag */


/*********************************************************************************************************************
 *  LOCAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/


/*********************************************************************************************************************
 *  LOCAL DATA PROTOTYPES
 *********************************************************************************************************************/

#define SBC_30_TLF35584_START_SEC_VAR_INIT_8BIT
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#if (SBC_30_TLF35584_DEV_ERROR_DETECT == STD_ON)
/* Initialization state of the module */
SBC_LOCAL VAR(uint8, SBC_30_TLF35584_VAR_INIT) Sbc_ModuleInitialized = SBC_UNINIT;
#endif

#define SBC_30_TLF35584_STOP_SEC_VAR_INIT_8BIT
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#define SBC_30_TLF35584_START_SEC_VAR_NOINIT_SAFE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
/* for SafeBSW the variables must be linked to a memory section that is protected from QM software access */

/* Stores the current System Status of the SBC. The values are updated each time they are read. */
SBC_LOCAL VAR(Sbc_SystemStatusType, SBC_30_TLF35584_VAR_NOINIT) Sbc_SystemStatus[SBC_30_TLF35584_NUMBER_OF_DEVICES];

#if defined(SBC_30_TLF35584_ENABLE_WDG)
/* Stores the current Mode of the Wdg. */
SBC_LOCAL VAR(Sbc_WdgModeType, SBC_30_TLF35584_VAR_NOINIT) Sbc_WdgMode[SBC_30_TLF35584_NUMBER_OF_DEVICES][SBC_30_TLF35584_MAX_NUMBER_OF_WDG];

# if (SBC_30_TLF35584_DEV_ERROR_DETECT == STD_ON)
/* This variable must be written in Sbc_Wdg_Trigger function to protect against Wrong Caller */
SBC_LOCAL VAR(uint32, SBC_30_TLF35584_VAR_NOINIT) Sbc_WdgTriggerFlag[SBC_30_TLF35584_NUMBER_OF_DEVICES][SBC_30_TLF35584_MAX_NUMBER_OF_WDG]; /* PRQA S 3218 */ /* MD_Sbc_3218 */
# endif
#endif

#define SBC_30_TLF35584_STOP_SEC_VAR_NOINIT_SAFE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#define SBC_30_TLF35584_START_SEC_VAR_NOINIT_32BIT
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */



#define SBC_30_TLF35584_STOP_SEC_VAR_NOINIT_32BIT
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/*********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/

/*********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/


/*********************************************************************************************************************
 *  LOW LEVEL FUNCTION
 *********************************************************************************************************************/
#define SBC_30_TLF35584_START_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 *  Sbc_Ll_InitDevice()
 *********************************************************************************************************************/
/*! \brief       Initialize the SBC hardware identified by deviceID dId.
 *  \details     Switches the SBC Mode to NORMAL and the peripherals to an initialized mode that does not affect bus
 *               communication. The watchdog could be enabled after this API returns.
 *               The following events shall be held pending even if they occurred prior to the initialization: 
 *               - POR 
 *               - Peripheral Wakeups (WUP/WUF)
 *  \param[in]   dId  Identifies the device id, dId must be a valid value.
 *  \return      E_OK on success. 
 *               E_NOT_OK otherwise.
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *  \pre         -
 *********************************************************************************************************************/
SBC_LOCAL_INLINE FUNC(Std_ReturnType, SBC_30_TLF35584_CODE) Sbc_Ll_InitDevice(Sbc_IdType dId);

/**********************************************************************************************************************
 *  Sbc_Ll_Sys_CanSetMode()
 *********************************************************************************************************************/
/*! \brief       Returns whether the System Mode can be changed.
 *  \details     Checks if the system mode of the SBC that is identified by the given dId can be changed to the given
 *               mode. 
 *               The API checks if the mode transition is supported by the hardware and whether the peripherals
 *               are in the expected state.
 *  \param[in]   dId   Identifies the device id, dId must be a valid value.
 *  \param[in]   mode  The mode that shall be reached.
 *  \return      E_OK if it is possible to change the mode. \n
 *               E_NOT_OK otherwise.
 *  \context     ANY
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *  \pre         -
 *  \note        If this API returns E_OK the module expects that the call to Sbc_Ll_Sys_SetMode() fails only if the
 *               module is not possible to communicate with the hardware.
 *********************************************************************************************************************/
SBC_LOCAL_INLINE FUNC(Std_ReturnType, SBC_30_TLF35584_CODE) Sbc_Ll_Sys_CanSetMode(Sbc_IdType dId, Sbc_SystemModeType mode);

/**********************************************************************************************************************
 *  Sbc_Ll_Sys_SetMode()
 *********************************************************************************************************************/
/*! \brief       Changes the system mode of the SBC identified by dId to the given mode.
 *  \details     The API changes the system mode of the SBC with the given dId to the requested mode.
 *               When NORMAL mode is requested, a possibly pending POR is cleared from hardware.
 *  \param[in]   dId   Identifies the device id, dId must be a valid value.
 *  \param[in]   mode  The mode that shall be reached.
 *  \return      E_OK on success. 
 *               E_NOT_OK otherwise.
 *  \context     ANY
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *  \pre         This API is only called if Sbc_Ll_Sys_CanSetMode returned E_OK.     
 *********************************************************************************************************************/
SBC_LOCAL_INLINE FUNC(Std_ReturnType, SBC_30_TLF35584_CODE) Sbc_Ll_Sys_SetMode(Sbc_IdType dId, Sbc_SystemModeType mode);

/**********************************************************************************************************************
 *  Sbc_Ll_Sys_ClearEvents()
 *********************************************************************************************************************/
/*! \brief       Clears the specified events from the SBC hardware.
 *  \details     This API clears the events that have a "1" at the corresponding position of the given clearFlags from
 *               the SBC device that is identified by dId. 
 *               If necessary the API stores the state and events after the clearing in the objects that is referred
 *               by parameter status.
 *  \param[in]   dId         Identifies the device id, dId must be a valid value.
 *  \param[out]  status      Reference to the object to store the status.
 *  \param[in]   clearFlags  The flags that shall be cleared.
 *  \return      E_OK on success. 
 *               E_NOT_OK otherwise.
 *  \context     ANY
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *  \pre         -
 *********************************************************************************************************************/
SBC_LOCAL_INLINE FUNC(Std_ReturnType, SBC_30_TLF35584_CODE) Sbc_Ll_Sys_ClearEvents(Sbc_IdType dId, P2VAR(Sbc_SystemStatusType, AUTOMATIC, SBC_30_TLF35584_APPL_DATA) status, Sbc_SystemEventType clearFlags);

/**********************************************************************************************************************
 *  Sbc_Ll_Sys_ReadStatus()
 *********************************************************************************************************************/
/*! \brief       Reads the current system status from the SBC hardware.
 *  \details     This API reads the current hardware status from the SBC that is identified by parameter dId and stores
 *               the flags in the object that is referred by parameter status.
 *  \param[in]   dId         Identifies the device id, dId must be a valid value.
 *  \param[out]  status      Reference to the object to store the status.
 *  \return      E_OK on success. 
 *               E_NOT_OK otherwise.
 *  \context     ANY
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *  \pre         -
 *********************************************************************************************************************/
SBC_LOCAL_INLINE FUNC(Std_ReturnType, SBC_30_TLF35584_CODE) Sbc_Ll_Sys_ReadStatus(Sbc_IdType dId, P2VAR(Sbc_SystemStatusType, AUTOMATIC, SBC_30_TLF35584_APPL_DATA) status);

/**********************************************************************************************************************
 *  Sbc_Ll_Sys_AccessRegister()
 *********************************************************************************************************************/
/*! \brief       Accesses specific SBC register.
 *  \details     This API accesses specific SBC registers identified by the register address that is coded in the spiCommand.
 *               The value that is read back on MISO pin is copied to spiAnswer variable.
 *  \param[in]   dId         Identifies the device id, dId must be a valid value.
 *  \param[in]   spiCommand  The complete SPI value that can be directly written to MOSI register.
 *  \param[out]  spiAnswer   The complete SPI value that is received on MISO register. SpiAnswer must be a valid pointer.
 *  \return      E_OK on success. 
 *               E_NOT_OK otherwise.
 *  \context     ANY
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *  \pre         -
 *********************************************************************************************************************/
SBC_LOCAL_INLINE FUNC(Std_ReturnType, SBC_30_TLF35584_CODE) Sbc_Ll_Sys_AccessRegister(Sbc_IdType dId, Sbc_SpiDataWidth spiCommand, P2VAR(Sbc_SpiDataWidth, AUTOMATIC, SBC_30_TLF35584_APPL_DATA) spiAnswer);



#if defined(SBC_30_TLF35584_ENABLE_WDG)
/**********************************************************************************************************************
 *  Sbc_Ll_Wdg_Trigger()
 *********************************************************************************************************************/
/*! \brief       Triggers the watchdog.
 *  \details     This API triggers the hardware watchdog by sending a proper command via SPI to the underlying hardware.
 *  \param[in]   dId         Identifies the device id, dId must be a valid value.
 *  \param[in]   pId         Identifies the peripheral id, pId must be a valid value.
 *  \return      E_OK on success. 
 *               E_NOT_OK otherwise.
 *  \context     ANY
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *  \config      SBC_30_TLF35584_ENABLE_WDG
 *  \pre         -
 *  \note        This API should use a separate high-priority sequence in order to ensure that the sequence is processed
 *               in time.
 *********************************************************************************************************************/
SBC_LOCAL_INLINE FUNC(Std_ReturnType, SBC_30_TLF35584_CODE) Sbc_Ll_Wdg_Trigger(Sbc_IdType dId, Sbc_IdType pId);

/**********************************************************************************************************************
 *  Sbc_Ll_Wdg_CanSetMode()
 *********************************************************************************************************************/
/*! \brief       Checks if the mode of the watchdog can be changed.
 * \details      This functions checks if it is possible to change the current watchdog mode to the given new mode. 
 *               Reasons for not allowed mode changes may be: 
 *                 - Unsupported mode 
 *                 - Invalid mode transition 
 *                 - Incorrect timing
 *  \param[in]   dId         Identifies the device id, dId must be a valid value.
 *  \param[in]   pId         Identifies the peripheral id, pId must be a valid value.
 *  \param[in]   mode        The mode that shall be reached.
 *  \return      E_OK if it is possible to change the mode. 
 *               E_NOT_OK otherwise.
 *  \context     ANY
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *  \config      SBC_30_TLF35584_ENABLE_WDG
 *  \pre         -
 *  \note        If this API returns E_OK it is expected that Sbc_Ll_Wdg_SetMode() may only fail due to incorrect
 *               communication towards the hardware.
 *********************************************************************************************************************/
SBC_LOCAL_INLINE FUNC(Std_ReturnType, SBC_30_TLF35584_CODE) Sbc_Ll_Wdg_CanSetMode(Sbc_IdType dId, Sbc_IdType pId, Sbc_WdgModeType mode);

/**********************************************************************************************************************
 *  Sbc_Ll_Wdg_SetMode()
 *********************************************************************************************************************/
/*! \brief       Changes the mode of the watchdog.
 *  \details     This API changes the mode of the watchdog that is identified by parameter dId and pId to the given mode.
 *  \param[in]   dId         Identifies the device id, dId must be a valid value.
 *  \param[in]   pId         Identifies the peripheral id, pId must be a valid value.
 *  \param[in]   mode        The mode that shall be reached.
 *  \return      E_OK on success. 
 *               E_NOT_OK otherwise.
 *  \context     ANY
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *  \config      SBC_30_TLF35584_ENABLE_WDG
 *  \pre         -
 *  \note        This API is only called if Sbc_Ll_Wdg_CanSetMode() returned E_OK.
 *********************************************************************************************************************/
SBC_LOCAL_INLINE FUNC(Std_ReturnType, SBC_30_TLF35584_CODE) Sbc_Ll_Wdg_SetMode(Sbc_IdType dId, Sbc_IdType pId, Sbc_WdgModeType mode);
#endif /* SBC_30_TLF35584_ENABLE_WD */

#define SBC_30_TLF35584_STOP_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#if !defined(SBC_SOURCE)
# error "This file must be included in Sbc.c"
#endif

/* Check the version of Sbc header file */

/* Check the version of Sbc header file */
#if (  (SBC_30_TLF35584_SW_MAJOR_VERSION != (0x01u)) \
    || (SBC_30_TLF35584_SW_MINOR_VERSION != (0x00u)) \
    || (SBC_30_TLF35584_SW_PATCH_VERSION != (0x01u)) )
 #error "Vendor specific version numbers of Sbc.c and Sbc.h are inconsistent"
#endif

/**********************************************************************************************************************
 *  HARDWARE SOFTWARE INTERFACE
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 */

/*! Read / Write masks */
#define SBC_30_TLF35584_MASK_SPIADDR                    (0x3Fu)     /*!< Masks address from address byte (1 Byte) */
#define SBC_30_TLF35584_MASK_SPIADDR_RAW                (0x7E00u)   /*!< Masks address from complete SPI sequence (2 Bytes) */
#define SBC_30_TLF35584_MASK_SPIDATA_RAW                (0x01FEu)   /*!< Masks data from complete SPI sequence (2 Bytes) */
#define SBC_30_TLF35584_MASK_CMD_WRITE_RAW              (0x8000u)   /*!< Masks CMD bit from complete SPI sequence (2 Bytes) */
#define SBC_30_TLF35584_MASK_ALL_FLAGS                  (0xFFu)     /*!< Mask that selects all flags (i.e. to clear all pending event flags) */
#define SBC_30_TLF35584_OFFSET_SPIADDR                  (9u)        /*!< Offset of address bits in SPI command */
#define SBC_30_TLF35584_OFFSET_SPIDATA                  (1u)        /*!< Offset of data bits in SPI command */

/*! Protected registers addresses */
#define SBC_30_TLF35584_REG_ADDR_SYSPCFG0               (0x04u)     /*!< Protected System configuration request 0 */
#define SBC_30_TLF35584_REG_ADDR_SYSPCFG1               (0x05u)     /*!< Protected System configuration request 1 */
#define SBC_30_TLF35584_REG_ADDR_WDCFG0                 (0x06u)     /*!< Protected Watchdog configuration request 0 */
#define SBC_30_TLF35584_REG_ADDR_WDCFG1                 (0x07u)     /*!< Protected Watchdog configuration request 1 */
#define SBC_30_TLF35584_REG_ADDR_FWDCFG                 (0x08u)     /*!< Protected Functional watchdog configuration request */
#define SBC_30_TLF35584_REG_ADDR_WWDCFG0                (0x09u)     /*!< Protected Window watchdog configuration request 0 */
#define SBC_30_TLF35584_REG_ADDR_WWDCFG1                (0x0Au)     /*!< Protected Window watchdog configuration request 1 */

/*! Main registers addresses */
#define SBC_30_TLF35584_REG_ADDR_PROTCFG                (0x03u)     /*!< Protected register */
#define SBC_30_TLF35584_REG_ADDR_RSYSPCFG0              (0x0Bu)     /*!< System configuration 0 status */
#define SBC_30_TLF35584_REG_ADDR_RSYSPCFG1              (0x0Cu)     /*!< System configuration 1 status */
#define SBC_30_TLF35584_REG_ADDR_RWDCFG0                (0x0Du)     /*!< Watchdog configuration 0 status */
#define SBC_30_TLF35584_REG_ADDR_RWDCFG1                (0x0Eu)     /*!< Watchdog configuration 1 status */
#define SBC_30_TLF35584_REG_ADDR_RFWDCFG                (0x0Fu)     /*!< Functional watchdog configuration status */
#define SBC_30_TLF35584_REG_ADDR_RWWDCFG0               (0x10u)     /*!< Window watchdog configuration status 0 */
#define SBC_30_TLF35584_REG_ADDR_RWWDCFG1               (0x11u)     /*!< Window watchdog configuration status 1 */

/*! Device control register addresses */
#define SBC_30_TLF35584_REG_ADDR_DEVCTRL                (0x15u)     /*!< Device control request */
#define SBC_30_TLF35584_REG_ADDR_DEVCTRLN               (0x16u)     /*!< Device control inverted request */
#define SBC_30_TLF35584_REG_ADDR_DEVSTAT                (0x27u)     /*!< Device status register */

/*! Device control register bitmasks */
#define SBC_30_TLF35584_DEVCTRL_NORMAL                  (0x02u)     /*!< Go to device state NORMAL */
#define SBC_30_TLF35584_DEVCTRL_STANDBY                 (0x04u)     /*!< Go to device state STANDBY */

#define SBC_30_TLF35584_REG_ADDR_WWDSCMD                (0x17u)     /*!< Window watchdog service command */
#define SBC_30_TLF35584_REG_ADDR_WWDSTAT                (0x29u)     /*!< Window watchdog status */

/*! Status flag registers */
#define SBC_30_TLF35584_REG_ADDR_SYSFAIL                (0x1Au)     /*!< Failure status flags */
#define SBC_30_TLF35584_REG_ADDR_IF                     (0x1Cu)     /*!< Interrupt flags */
#define SBC_30_TLF35584_REG_ADDR_MONSF1                 (0x21u)     /*!< Monitor status flags 1 */
#define SBC_30_TLF35584_REG_ADDR_MONSF2                 (0x22u)     /*!< Monitor status flags 2 */
#define SBC_30_TLF35584_REG_ADDR_MONSF3                 (0x23u)     /*!< Monitor status flags 3 */
#define SBC_30_TLF35584_REG_ADDR_OTFAIL                 (0x24u)     /*!< Over temperature failure status flags */

#define SBC_30_TLF35584_REG_ADDR_INITERR                (0x1Bu)     /*!< Init error status flags */
#define SBC_30_TLF35584_REG_ADDR_SYSSF                  (0x1Du)     /*!< System status flags */
#define SBC_30_TLF35584_REG_ADDR_SPISF                  (0x1Fu)     /*!< SPI status flags */
#define SBC_30_TLF35584_REG_ADDR_PROTSTAT               (0x28u)     /*!< Protection status */

/*! Status flag register bit masks */
#define SBC_30_TLF35584_REG_MASK_SYSFAIL_VMONF          (0x04u)      /*!< SYSFAIL:2:2 Voltage monitor failure flag */
#define SBC_30_TLF35584_REG_MASK_SYSFAIL_OTF            (0x02u)      /*!< SYSFAIL:1:1 Over temperature failure flag */

#define SBC_30_TLF35584_REG_MASK_IF_OTF                 (0x20u)      /*!< IF:5:5 Over temperature failure interrupt flag */
#define SBC_30_TLF35584_REG_MASK_IF_SPI                 (0x04u)      /*!< IF:2:2 SPI interrupt flag */
#define SBC_30_TLF35584_REG_MASK_IF_SYSSF               (0x01u)      /*!< IF:0:0 System interrupt flag */

#define SBC_30_TLF35584_REG_MASK_MONSF1_ALL             (0xFFu)      /*!< MONSF1:0:7 Selects all flags of MONSF1 */

#define SBC_30_TLF35584_REG_MASK_MONSF2_ALL             (0xFFu)      /*!< MONSF2:0:7 Selects all flags of MONSF2 */

#define SBC_30_TLF35584_REG_MASK_MONSF3_BG12OV          (0x20u)      /*!< IF:5:5 Bandgap comparator over voltage condition flag */
#define SBC_30_TLF35584_REG_MASK_MONSF3_BG12UV          (0x10u)      /*!< IF:5:5 Bandgap comparator under voltage condition flag */
#define SBC_30_TLF35584_REG_MASK_MONSF3_VBATOV          (0x01u)      /*!< IF:5:5 Supply voltage VSx over voltage flag */
#define SBC_30_TLF35584_REG_MASK_MONSF3_OVFLAGS         (SBC_30_TLF35584_REG_MASK_MONSF3_BG12OV \
                                                          | SBC_30_TLF35584_REG_MASK_MONSF3_VBATOV)

#define SBC_30_TLF35584_REG_MASK_OTFAIL_MON             (0x80u)      /*! OTFAIL:7:7 Monitoring over temperature flag */
#define SBC_30_TLF35584_REG_MASK_OTFAIL_COM             (0x10u)      /*! OTFAIL:4:4 Communication LDO over temperature flag */
#define SBC_30_TLF35584_REG_MASK_OTFAIL_UC              (0x02u)      /*! OTFAIL:1:1 uC LDO over temperature flag */
#define SBC_30_TLF35584_REG_MASK_OTFAIL_PREG            (0x01u)      /*! OTFAIL:0:0 Pre-regulator over temperature flag */
#define SBC_30_TLF35584_REG_MASK_OTFAIL_ALL             (SBC_30_TLF35584_REG_MASK_OTFAIL_MON \
                                                          | SBC_30_TLF35584_REG_MASK_OTFAIL_COM \
                                                          | SBC_30_TLF35584_REG_MASK_OTFAIL_UC \
                                                          | SBC_30_TLF35584_REG_MASK_OTFAIL_PREG)

#define SBC_30_TLF35584_REG_MASK_INITERR_FWDF           (0x10u)      /*!< INITERR:4:4 FWD error counter overflow flag */
#define SBC_30_TLF35584_REG_MASK_INITERR_WWDF           (0x08u)      /*!< INITERR:3:3 WWD error counter overflow flag */
#define SBC_30_TLF35584_REG_MASK_INITERR_VMONF          (0x04u)      /*!< INITERR:2:2 Voltage monitor failure flag */
#define SBC_30_TLF35584_REG_MASK_INITERR_WDFLAGS        (SBC_30_TLF35584_REG_MASK_INITERR_FWDF \
                                                          | SBC_30_TLF35584_REG_MASK_INITERR_WWDF)

#define SBC_30_TLF35584_REG_MASK_SPISF_LOCK             (0x10u)      /*!< SPISF:4:4 LOCK or UNLOCK procedure error flag */
#define SBC_30_TLF35584_REG_MASK_SPISF_DURE             (0x08u)      /*!< SPISF:3:3 SPI frame duration error flag */
#define SBC_30_TLF35584_REG_MASK_SPISF_ADDRE            (0x04u)      /*!< SPISF:2:2 SPI address invalid flag */
#define SBC_30_TLF35584_REG_MASK_SPISF_LENE             (0x02u)      /*!< SPISF:1:1 SPI frame length invalid flag */
#define SBC_30_TLF35584_REG_MASK_SPISF_PARE             (0x01u)      /*!< SPISF:0:0 SPI frame length invalid flag */
#define SBC_30_TLF35584_REG_MASK_SPISF_ALL              (SBC_30_TLF35584_REG_MASK_SPISF_LOCK \
                                                          | SBC_30_TLF35584_REG_MASK_SPISF_DURE \
                                                          | SBC_30_TLF35584_REG_MASK_SPISF_ADDRE \
                                                          | SBC_30_TLF35584_REG_MASK_SPISF_LENE \
                                                          | SBC_30_TLF35584_REG_MASK_SPISF_PARE)

#define SBC_30_TLF35584_REG_MASK_PROTSTAT_LOCK          (0x01u)      /*!< PROTSTAT:1:1 Protected register lock status */

/*! FWD registers */
#define SBC_30_TLF35584_REG_ADDR_FWDRSP                 (0x18u)      /*!< Functional watchdog response command */
#define SBC_30_TLF35584_REG_ADDR_FWDRSPSYNC             (0x19u)      /*!< Functional watchdog response command with synchronization */
#define SBC_30_TLF35584_REG_ADDR_FWDSTAT                (0x2Au)      /*!< Functional watchdog status */

/*! FWDSTAT register bit masks */
#define SBC_30_TLF35584_REG_MASK_FWDSTAT_FWDQUEST       (0x0Fu)      /*!< FWDSTAT:0:3 Functional watchdog question */

/*! PROTCFG register bit masks */
#define SBC_30_TLF35584_REG_MASK_PROTCFG_KEY            (0xFFu)      /*!< PROTCFG:0:7 Key to lock/unlock protected registers */

/*! SYSPCFG1 register bit masks */
#define SBC_30_TLF35584_REG_MASK_SYSPCFG1_ERREN         (0x08u)      /*!< SYSPCFG1:3:3 Enable ERR pin monitor */

/*! WDCFG0 register bit masks */
#define SBC_30_TLF35584_REG_MASK_WDCFG0_WDCYC           (0x01u)      /*!< WDCFG0:0:0 Watchdog cycle time */
#define SBC_30_TLF35584_REG_MASK_WDCFG0_WWDTSEL         (0x02u)      /*!< WDCFG0:1:1 Window watchdog trigger selection */
#define SBC_30_TLF35584_REG_MASK_WDCFG0_FWDEN           (0x04u)      /*!< WDCFG0:3:3 Functional watchdog enable */
#define SBC_30_TLF35584_REG_MASK_WDCFG0_WWDEN           (0x08u)      /*!< WDCFG0:3:3 Window watchdog enable */
#define SBC_30_TLF35584_REG_MASK_WDCFG0_ERRTRH          (0xF0u)      /*!< WDCFG0:4:7 Window watchdog error threshold */

#define SBC_30_TLF35584_WDCFG0_DEFAULT_VAL              (0x9Bu)      /*!< Default value of WDCFG0 */

/*! WWDSCMD register bit masks */
#define SBC_30_TLF35584_REG_MASK_WWDSCMD_TRIG           (0x01u)      /*!< WWDSCMD:0:0 WWD trigger command to trigger WWD */
#define SBC_30_TLF35584_REG_MASK_WWDSCMD_TRIG_STATUS    (0x80u)      /*!< WWDSCMD:7:7 Last internal trigger value received via SPI */

/*! Protection register values */
#define SBC_30_TLF35584_REG_CMD_PROTCFG_UNLOCK_SEQ1     (0xABu)      /*!< First byte of consecutive unlock sequence */
#define SBC_30_TLF35584_REG_CMD_PROTCFG_UNLOCK_SEQ2     (0xEFu)      /*!< Second byte of consecutive unlock sequence */
#define SBC_30_TLF35584_REG_CMD_PROTCFG_UNLOCK_SEQ3     (0x56u)      /*!< Third byte of consecutive unlock sequence */
#define SBC_30_TLF35584_REG_CMD_PROTCFG_UNLOCK_SEQ4     (0x12u)      /*!< Fourth byte of consecutive unlock sequence */

#define SBC_30_TLF35584_REG_CMD_PROTCFG_LOCK_SEQ1       (0xDFu)      /*!< First byte of consecutive lock sequence */
#define SBC_30_TLF35584_REG_CMD_PROTCFG_LOCK_SEQ2       (0x34u)      /*!< Second byte of consecutive lock sequence */
#define SBC_30_TLF35584_REG_CMD_PROTCFG_LOCK_SEQ3       (0xBEu)      /*!< Third byte of consecutive lock sequence */
#define SBC_30_TLF35584_REG_CMD_PROTCFG_LOCK_SEQ4       (0xCAu)      /*!< Fourth byte of consecutive lock sequence */

/*! Compatibility defines for SPI API mapping */
#if !defined(Sbc_SpiSetupEB) /* COV_SBC_SPI_COMPATIBILITY */
# define Sbc_SpiSetupEB Spi_SetupEB
#endif

#if !defined(Sbc_SpiSyncTransmit) /* COV_SBC_SPI_COMPATIBILITY */
# define Sbc_SpiSyncTransmit Spi_SyncTransmit
#endif

#if !defined(SBC_LL_SPI_TRANSFER_LENGTH) /* COV_SBC_SPI_COMPATIBILITY */
# define SBC_LL_SPI_TRANSFER_LENGTH 1
#endif

#if !defined(Sbc_SpiDataType) /* COV_SBC_SPI_COMPATIBILITY */
# define Sbc_SpiDataType Spi_DataBufferType
#endif

/**********************************************************************************************************************
 *  LOCAL CONSTANT MACROS
 *********************************************************************************************************************/
#define SBC_30_TLF35584_RESPONSE_TABLE_SIZE             (16u) /*!< Size of Functional watchdog response table. */
#define SBC_30_TLF35584_SHIFT_WWD_STAT_TO_CMD            (7u) /*!< Operand for shifting the WWD status bit to cmd bit. */
#define SBC_30_TLF35584_NUMBER_OF_PROTECTED_REGISTERS    (7u) /*!< Defines the number of protected registers. */

/**********************************************************************************************************************
 *  LOCAL FUNCTION-LIKE MACROS
 **********************************************************************************************************************/

/* PRQA S 3453 Sbc_LocalFunctionMacros_Tag */ /* MD_Sbc_3453 */

#define Sbc_Ll_Cfg_GetSpiSequence(dId)                           ((Spi_SequenceType)(Sbc_30_Tlf35584_GetSbcSpiSeq_SbcSpiSequenceOfSpiSequence(dId)))
#define Sbc_Ll_Cfg_GetSpiChannel(dId)                            ((Spi_ChannelType)(Sbc_30_Tlf35584_GetSbcSpiChl_SbcSpiChannelOfSpiChannel(dId)))

#define Sbc_Ll_Cfg_GetWdgInit_Mode(dId, pId)                      ((uint8)(Sbc_30_Tlf35584_GetWdgInitModeOfWdgConfig(Sbc_Cfg_GetWdgConfigIdx(dId, pId))))

#if SBC_30_TLF35584_FWDCFGFASTOFWDGCONFIG == STD_ON
# define Sbc_Ll_Cfg_GetWdgFWCFGfast(dId, pId)                    ((uint8)Sbc_30_Tlf35584_GetFWDCFGfastOfWdgConfig(Sbc_Cfg_GetWdgConfigIdx(dId, pId)))
# define Sbc_Ll_Cfg_GetWdgFWCFGslow(dId, pId)                    ((uint8)Sbc_30_Tlf35584_GetFWDCFGslowOfWdgConfig(Sbc_Cfg_GetWdgConfigIdx(dId, pId)))
#endif

#if SBC_30_TLF35584_WWDCFG0FASTOFWDGCONFIG == STD_ON
# define Sbc_Ll_Cfg_GetWdgWWDCFG0fast(dId, pId)                  ((uint8)Sbc_30_Tlf35584_GetWwdCfg0FastOfWdgConfig(Sbc_Cfg_GetWdgConfigIdx(dId, pId)))
# define Sbc_Ll_Cfg_GetWdgWWDCFG0slow(dId, pId)                  ((uint8)Sbc_30_Tlf35584_GetWwdCfg0SlowOfWdgConfig(Sbc_Cfg_GetWdgConfigIdx(dId, pId)))
# define Sbc_Ll_Cfg_GetWdgWWDCFG1fast(dId, pId)                  ((uint8)Sbc_30_Tlf35584_GetWwdCfg1FastOfWdgConfig(Sbc_Cfg_GetWdgConfigIdx(dId, pId)))
# define Sbc_Ll_Cfg_GetWdgWWDCFG1slow(dId, pId)                  ((uint8)Sbc_30_Tlf35584_GetWwdCfg1SlowOfWdgConfig(Sbc_Cfg_GetWdgConfigIdx(dId, pId)))
#endif

#if SBC_30_TLF35584_DIOCHANNEL == STD_ON
# define Sbc_Ll_Cfg_GetDioChannel(dId)                           ((Dio_ChannelType)(Sbc_30_Tlf35584_GetSbcDioChl_SbcDioChannelOfDioChannel(dId)))
#endif

#define Sbc_Ll_Cfg_GetSyspcfg1(dId)                              ((uint8)Sbc_30_Tlf35584_GetSYSPCFG1OfInitConfig(dId))
#define Sbc_Ll_Cfg_GetWdgWDCFG0(dId, pId)                        ((uint8)Sbc_30_Tlf35584_GetWDCFG0OfWdgConfig(Sbc_Cfg_GetWdgConfigIdx(dId, pId)))
#define Sbc_Ll_Cfg_GetWdgWDCFG1(dId, pId)                        ((uint8)Sbc_30_Tlf35584_GetWDCFG1OfWdgConfig(Sbc_Cfg_GetWdgConfigIdx(dId, pId)))

#define Sbc_Ll_Cfg_GetDevCtrlRegNormal(dId)                      Sbc_30_Tlf35584_GetDEVCTRLnormalOfSupplyConfig(dId)
#define Sbc_Ll_Cfg_GetDevCtrlRegStandby(dId)                     Sbc_30_Tlf35584_GetDEVCTRLstandbyOfSupplyConfig(dId)
#define Sbc_Ll_Cfg_GetSyspCfg0RegNormal(dId)                     Sbc_30_Tlf35584_GetSYSPCFG0normalOfSupplyConfig(dId)
#define Sbc_Ll_Cfg_GetSyspCfg0RegStandby(dId)                    Sbc_30_Tlf35584_GetSYSPCFG0standbyOfSupplyConfig(dId)
#define Sbc_Ll_Cfg_GetSyspCfg0RegSleep(dId)                      Sbc_30_Tlf35584_GetSYSPCFG0sleepOfSupplyConfig(dId)


#define Sbc_Ll_MkWrCommand(addr, data)                           (uint16) ( ( ( ( ( (addr) & 0xFFu) << 8) | ((uint16)(data) & 0xFFu) ) << SBC_30_TLF35584_OFFSET_SPIDATA) | SBC_30_TLF35584_MASK_CMD_WRITE_RAW)
#define Sbc_Ll_MkRdCommand(addr)                                 (uint16)( ( (addr) & SBC_30_TLF35584_MASK_SPIADDR) << SBC_30_TLF35584_OFFSET_SPIADDR)

/* PRQA S 3412 2 */ /* MD_MSR_19.4 */
#define Sbc_Ll_ReadRegister(dId, addr, target)                   Sbc_Ll_RwRegister(dId, Sbc_Ll_CalcSpiParity(Sbc_Ll_MkRdCommand((addr))), (target));*(target)>>=SBC_30_TLF35584_OFFSET_SPIDATA
#define Sbc_Ll_WriteRegister(dId, addr, data)                    Sbc_Ll_RwRegister(dId, Sbc_Ll_CalcSpiParity(Sbc_Ll_MkWrCommand((addr), (data))), NULL_PTR)

/*! Calculate the address from protected register by index. */
#define Sbc_Ll_GetAddrOfProtRegFromIdx(idx)                      (uint16)((idx) + SBC_30_TLF35584_REG_ADDR_SYSPCFG0)
#define Sbc_Ll_GetAddrOfReadProtRegFromIdx(idx)                  (uint16)((idx) + SBC_30_TLF35584_REG_ADDR_RSYSPCFG0)
/* PRQA L:Sbc_LocalFunctionMacros_Tag */

/**********************************************************************************************************************
 *  LOCAL DATA TYPES AND STRUCTURES
 **********************************************************************************************************************/
/*! Type for indexing buffered values of protected registers. */
typedef enum
{
  SYSPCFG0 = 0, /*!< Index for buffered value of register SYSPCFG0. */
  SYSPCFG1 = 1, /*!< Index for buffered value of register SYSPCFG1. */
  WDCFG0 = 2,   /*!< Index for buffered value of register WDCFG0. */
  WDCFG1 = 3,   /*!< Index for buffered value of register WDCFG1. */
  FWDCFG = 4,   /*!< Index for buffered value of register FWDCFG. */
  WWDCFG0 = 5,  /*!< Index for buffered value of register WWDCFG0. */
  WWDCFG1 = 6   /*!< Index for buffered value of register WWDCFG1. */
} Sbc_Ll_ProtectedRegisterValueIndex_Type;

#if SBC_30_TLF35584_FWDCFGFASTOFWDGCONFIG == STD_ON
/*! Data type to store related responses to a FWD question. */
typedef struct
{
  uint8 RESP3; /*!< Response byte 3 */
  uint8 RESP2; /*!< Response byte 2 */
  uint8 RESP1; /*!< Response byte 1 */
  uint8 RESP0; /*!< Response byte 0 */
} Sbc_30_Tlf35584_FwdResponse_Type;
#endif

/**********************************************************************************************************************
 *  LOCAL DATA PROTOTYPES
 **********************************************************************************************************************/
#define SBC_30_TLF35584_START_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/*! Spi input/output buffers */
SBC_LOCAL VAR(Sbc_SpiDataWidth, SBC_30_TLF35584_VAR_NOINIT) Sbc_Ll_SpiOutBuffer[SBC_30_TLF35584_NUMBER_OF_DEVICES];
SBC_LOCAL VAR(Sbc_SpiDataWidth, SBC_30_TLF35584_VAR_NOINIT) Sbc_Ll_SpiInBuffer[SBC_30_TLF35584_NUMBER_OF_DEVICES];

#define SBC_30_TLF35584_STOP_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#define SBC_30_TLF35584_START_SEC_VAR_NOINIT_8BIT
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/*! Buffer to read/write protected register values  */
SBC_LOCAL VAR(uint8, SBC_30_TLF35584_VAR_NOINIT)
  Sbc_30_Tlf35584_ProtectedRegisterValues[SBC_30_TLF35584_NUMBER_OF_DEVICES][SBC_30_TLF35584_NUMBER_OF_PROTECTED_REGISTERS];

#define SBC_30_TLF35584_STOP_SEC_VAR_NOINIT_8BIT
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#if SBC_30_TLF35584_FWDCFGFASTOFWDGCONFIG == STD_ON

#define SBC_30_TLF35584_START_SEC_VAR_NOINIT_8BIT
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/*! Stores recent FWD question. */
SBC_LOCAL VAR(uint8, SBC_30_TLF35584_VAR_NOINIT) Wdg_30_Tlf35584_FwdQuestion[SBC_30_TLF35584_NUMBER_OF_DEVICES];

#define SBC_30_TLF35584_STOP_SEC_VAR_NOINIT_8BIT
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#define SBC_30_TLF35584_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/*! Functional watchdog response table */
SBC_LOCAL CONST(Sbc_30_Tlf35584_FwdResponse_Type, SBC_30_TLF35584_CONST)
  Wdg_30_TLF35584_FwdResponseTbl[SBC_30_TLF35584_RESPONSE_TABLE_SIZE] =  /* PRQA S 3218 */ /* MD_Sbc_3218 */
{
/* QUESTION */ /* RESP3, RESP2, RESP1, RESP0 */
/*     0    */  { 0xFFu, 0x0Fu, 0xF0u, 0x00u },
/*     1    */  { 0xB0u, 0x40u, 0xBFu, 0x4Fu },
/*     2    */  { 0xE9u, 0x19u, 0xE6u, 0x16u },
/*     3    */  { 0xA6u, 0x56u, 0xA9u, 0x59u },
/*     4    */  { 0x75u, 0x85u, 0x7Au, 0x8Au },
/*     5    */  { 0x3Au, 0xCAu, 0x35u, 0xC5u },
/*     6    */  { 0x63u, 0x93u, 0x6Cu, 0x9Cu },
/*     7    */  { 0x2Cu, 0xDCu, 0x23u, 0xD3u },
/*     8    */  { 0xD2u, 0x22u, 0xDDu, 0x2Du },
/*     9    */  { 0x9Du, 0x6Du, 0x92u, 0x62u },
/*     A    */  { 0xC4u, 0x34u, 0xCBu, 0x3Bu },
/*     B    */  { 0x8Bu, 0x7Bu, 0x84u, 0x74u },
/*     C    */  { 0x58u, 0xA8u, 0x57u, 0xA7u },
/*     D    */  { 0x17u, 0xE7u, 0x18u, 0xE8u },
/*     E    */  { 0x4Eu, 0xBEu, 0x41u, 0xB1u },
/*     F    */  { 0x01u, 0xF1u, 0x0Eu, 0xFEu }
 };

#define SBC_30_TLF35584_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#endif /* SBC_30_TLF35584_FWDCFGFASTOFWDGCONFIG */

#define SBC_30_TLF35584_START_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 **********************************************************************************************************************/
/**********************************************************************************************************************
 * Sbc_Ll_CalcSpiParity
 *********************************************************************************************************************/
/*! \brief       Calculate parity bit for an SPI command.
 *  \details     This function calculates the parity bit for the passed SPI command and returns the SPI command which
 *               includes.
 *  \param[in]   in   Data intended to be written to TLF35584 via SPI.
 *  \return      Data intended to be written to TLF35584 via SPI including the parity bit.
 *  \pre         -
 *  \context     ANY
 *  \reentrant   TRUE
 *  \synchronous TRUE
 *********************************************************************************************************************/
SBC_LOCAL_INLINE FUNC(uint16, SBC_30_TLF35584_CODE) Sbc_Ll_CalcSpiParity(uint16 in);

/**********************************************************************************************************************
 *  Sbc_Ll_RwRegister()
 *********************************************************************************************************************/
/*! \brief       Initiates SPI transfer to SBC module.
 *  \details     This function computes the parity bit for write commands and trigger synchronous SPI transfer.
 *  \param[in]   dId  Identifies the device id, dId must be a valid value.
 *  \param[in]   out  SPI output value for MOSI pin.
 *  \param[out]  in   SPI input value from MISO pin.
 *  \return      E_OK on success.
 *               E_NOT_OK otherwise.
 *  \context     ANY
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *  \pre         -
 *********************************************************************************************************************/
SBC_LOCAL FUNC(Std_ReturnType, SBC_30_TLF35584_CODE) Sbc_Ll_RwRegister(
    Sbc_IdType dId, uint16 out, P2VAR(uint16, AUTOMATIC, SBC_30_TLF35584_APPL_DATA) in);

/**********************************************************************************************************************
 * Sbc_Ll_ReadAndUnlockProtectedRegisters
 *********************************************************************************************************************/
/*! \brief       Unlock and read protected registers of TLF35584.
 *  \details     This function sends the UNLOCK sequence to unlock the protected registers and buffers the values of
 *               the protected register.
 *  \param[in]   dId  Identifies the device id, dId must be a valid value.
 *  \return      E_OK on success.
 *               E_NOT_OK otherwise.
 *  \pre         -
 *  \context     ANY
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
SBC_LOCAL_INLINE FUNC(Std_ReturnType, SBC_30_TLF35584_CODE) Sbc_Ll_ReadAndUnlockProtectedRegisters(Sbc_IdType dId);

/**********************************************************************************************************************
 * Sbc_Ll_WriteAndLockProtectedRegisters
 *********************************************************************************************************************/
/*! \brief       Write and lock protected registers of TLF35584.
 *  \details     This function writes buffered data to protected registers and sends the LOCK sequence to lock the
 *               protected registers.
 *  \param[in]   dId  Identifies the device id, dId must be a valid value.
 *  \return      E_OK on success.
 *               E_NOT_OK otherwise.
 *  \pre         -
 *  \context     ANY
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
SBC_LOCAL_INLINE FUNC(Std_ReturnType, SBC_30_TLF35584_CODE) Sbc_Ll_WriteAndLockProtectedRegisters(Sbc_IdType dId);


/**********************************************************************************************************************
 *  Sbc_Ll_Sys_EvaluateMonsfRegs()
 *********************************************************************************************************************/
/*! \brief       Evaluates the events in MONSF register events.
 *  \details     This function reads and stores the events of the corresponding registers.
 *  \param[in]   dId         Identifies the device id, dId must be a valid value.
 *  \param[out]  status      Reference to the object to store the status.
 *  \return      E_OK on success.
 *               E_NOT_OK otherwise.
 *  \context     ANY
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *  \pre         -
 *********************************************************************************************************************/
SBC_LOCAL_INLINE FUNC(Std_ReturnType, SBC_30_TLF35584_CODE) Sbc_Ll_Sys_EvaluateMonsfRegs(Sbc_IdType dId, P2VAR(Sbc_SystemStatusType, AUTOMATIC, SBC_30_TLF35584_APPL_DATA) status);


/* ********************************************************************************************************************
 *  LOCAL LOW LEVEL FUNCTIONS
 * ********************************************************************************************************************/

/* ********************************************************************************************************************
 * Sbc_Ll_InitDevice
 * ********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 *
 */
SBC_LOCAL_INLINE FUNC(Std_ReturnType, SBC_30_TLF35584_CODE) Sbc_Ll_InitDevice(Sbc_IdType dId)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType result = E_OK;
  uint16 tmp;

  /* ----- Implementation ----------------------------------------------- */

  /* #10 Setup SPI buffers */
  result = Sbc_SpiSetupEB(
    Sbc_Ll_Cfg_GetSpiChannel(dId), /* SBSW_SBC_CALL_SPI_SETUPEB */
    (Sbc_SpiDataType*) &Sbc_Ll_SpiOutBuffer[dId],
    (Sbc_SpiDataType*) &Sbc_Ll_SpiInBuffer[dId],
    SBC_LL_SPI_TRANSFER_LENGTH);

  /* #20 Unlock protected registers */
  result |= Sbc_Ll_ReadAndUnlockProtectedRegisters(dId);

  /* #30 Configure SYSPCFG0 (LDO_Stby) */
  Sbc_30_Tlf35584_ProtectedRegisterValues[dId][SYSPCFG0] = Sbc_Ll_Cfg_GetSyspCfg0RegNormal(dId); /* SBSW_SBC_VALID_DID */ /* SBSW_SBC_VALID_REG_IDX */

  /* #35 Configure SYSPCFG1 (ErrPin Monitoring, SS2 delay) */
  Sbc_30_Tlf35584_ProtectedRegisterValues[dId][SYSPCFG1] = Sbc_Ll_Cfg_GetSyspcfg1(dId); /* SBSW_SBC_VALID_DID */ /* SBSW_SBC_VALID_REG_IDX */

  /* #40 Disable both watchdog peripherals */
  Sbc_30_Tlf35584_ProtectedRegisterValues[dId][WDCFG0] = (SBC_30_TLF35584_WDCFG0_DEFAULT_VAL /* SBSW_SBC_VALID_DID */ /* SBSW_SBC_VALID_REG_IDX */
    & ~(SBC_30_TLF35584_REG_MASK_WDCFG0_FWDEN | SBC_30_TLF35584_REG_MASK_WDCFG0_WWDEN));

  /* #50 Lock protected registers */
  result |= Sbc_Ll_WriteAndLockProtectedRegisters(dId);

  /* #60 Set DEVCTRL (power supplies) and request device NORMAL state */
  tmp = (Sbc_Ll_Cfg_GetDevCtrlRegNormal(dId) | SBC_30_TLF35584_DEVCTRL_NORMAL);
  result |= Sbc_Ll_WriteRegister(dId, SBC_30_TLF35584_REG_ADDR_DEVCTRL, tmp); /* SBSW_SBC_NULLPTR_PARAM */
  result |= Sbc_Ll_WriteRegister(dId, SBC_30_TLF35584_REG_ADDR_DEVCTRLN, ~(tmp)); /* SBSW_SBC_NULLPTR_PARAM */

  return result;
}

/* ********************************************************************************************************************
 * Sbc_Ll_Sys_CanSetMode
 * ********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
SBC_LOCAL_INLINE FUNC(Std_ReturnType, SBC_30_TLF35584_CODE) Sbc_Ll_Sys_CanSetMode(
    Sbc_IdType dId, Sbc_SystemModeType mode)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType result = E_NOT_OK;
  Sbc_SystemModeType currentMode = (Sbc_SystemModeType)Sbc_Sys_St_GetMode(Sbc_Rt_GetSystemStatus(dId));

  /* ----- Implementation ----------------------------------------------- */
  if (mode == SBC_SYS_MODE_STANDBY)
  {
    result = E_OK;
  }
  else if (mode == SBC_SYS_MODE_SLEEP)
  {
    if (currentMode == SBC_SYS_MODE_STANDBY)
    {
      result = E_OK;
    }
  }
  else /* NORMAL Mode: only NORMAL, STANDBY and SLEEP Mode are valid: Invalid ones are blocked by core DET check */
  {
      result = E_OK;
  }

  return result;
}

/* ********************************************************************************************************************
 * Sbc_Ll_Sys_SetMode
 * ********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 *
 *
 */
SBC_LOCAL_INLINE FUNC(Std_ReturnType, SBC_30_TLF35584_CODE) Sbc_Ll_Sys_SetMode(
    Sbc_IdType dId, Sbc_SystemModeType mode)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType result = E_OK;
  uint16 tmp;

  /* ----- Implementation ----------------------------------------------- */
    /* #10 If requested mode is SLEEP */
  if (mode == SBC_SYS_MODE_SLEEP)
  {

    /* #15 Set supply settings according to SLEEP mode */
    result |= Sbc_Ll_ReadAndUnlockProtectedRegisters(dId);
    Sbc_30_Tlf35584_ProtectedRegisterValues[dId][SYSPCFG0] = Sbc_Ll_Cfg_GetSyspCfg0RegSleep(dId);  /* SBSW_SBC_VALID_DID */ /* SBSW_SBC_VALID_REG_IDX */
    result |= Sbc_Ll_WriteAndLockProtectedRegisters(dId);

    /* #20 Request device state STANDBY */
    /* Device state STANDBY is equivalent to Sbc mode SLEEP. */
    result |= Sbc_Ll_WriteRegister(dId, SBC_30_TLF35584_REG_ADDR_DEVCTRL, SBC_30_TLF35584_DEVCTRL_STANDBY); /* SBSW_SBC_NULLPTR_PARAM */
    result |= Sbc_Ll_WriteRegister(dId, SBC_30_TLF35584_REG_ADDR_DEVCTRLN, ~(SBC_30_TLF35584_DEVCTRL_STANDBY)); /* SBSW_SBC_NULLPTR_PARAM */

  }
  /* #30 If requested mode is STANDBY */
  else if(mode == SBC_SYS_MODE_STANDBY)
  {

    /* #35 Set supply settings according to STANDBY mode */
    result |= Sbc_Ll_ReadAndUnlockProtectedRegisters(dId);
    Sbc_30_Tlf35584_ProtectedRegisterValues[dId][SYSPCFG0] = Sbc_Ll_Cfg_GetSyspCfg0RegStandby(dId);  /* SBSW_SBC_VALID_DID */ /* SBSW_SBC_VALID_REG_IDX */
    result |= Sbc_Ll_WriteAndLockProtectedRegisters(dId);

    tmp = (Sbc_Ll_Cfg_GetDevCtrlRegStandby(dId) | SBC_30_TLF35584_DEVCTRL_NORMAL);

    /* #40 Request device state NORMAL */
    /* Sbc state STANDBY is equivalent to device state NORMAL with according supply settings. */
    result |= Sbc_Ll_WriteRegister(dId, SBC_30_TLF35584_REG_ADDR_DEVCTRL, tmp); /* SBSW_SBC_NULLPTR_PARAM */
    result |= Sbc_Ll_WriteRegister(dId, SBC_30_TLF35584_REG_ADDR_DEVCTRLN, ~(tmp)); /* SBSW_SBC_NULLPTR_PARAM */
  }
  /* #50 If requested mode is NORMAL */
  else
  {

    /* #55 Set supply settings according to NORMAL mode */
    result |= Sbc_Ll_ReadAndUnlockProtectedRegisters(dId);
    Sbc_30_Tlf35584_ProtectedRegisterValues[dId][SYSPCFG0] = Sbc_Ll_Cfg_GetSyspCfg0RegNormal(dId);  /* SBSW_SBC_VALID_DID */ /* SBSW_SBC_VALID_REG_IDX */
    result |= Sbc_Ll_WriteAndLockProtectedRegisters(dId);

    tmp = (Sbc_Ll_Cfg_GetDevCtrlRegNormal(dId) | SBC_30_TLF35584_DEVCTRL_NORMAL);

    /* Sbc state NORMAL is equivalent to device state NORMAL with according supply settings. */
    result |= Sbc_Ll_WriteRegister(dId, SBC_30_TLF35584_REG_ADDR_DEVCTRL, tmp); /* SBSW_SBC_NULLPTR_PARAM */
    result |= Sbc_Ll_WriteRegister(dId, SBC_30_TLF35584_REG_ADDR_DEVCTRLN, ~(tmp)); /* SBSW_SBC_NULLPTR_PARAM */

  }

  return result;
}


/* ********************************************************************************************************************
 * Sbc_Ll_Sys_ClearEvents
 * ********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 */
SBC_LOCAL_INLINE FUNC(Std_ReturnType, SBC_30_TLF35584_CODE) Sbc_Ll_Sys_ClearEvents(
    Sbc_IdType dId, P2VAR(Sbc_SystemStatusType, AUTOMATIC, SBC_30_TLF35584_APPL_DATA) status, Sbc_SystemEventType clearFlags)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType result = E_OK;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Clear over-voltage flags */
  if ( (clearFlags & SBC_SYS_EV_OVERR) != 0 )
  {
    result |= Sbc_Ll_WriteRegister(dId, SBC_30_TLF35584_REG_ADDR_MONSF1, SBC_30_TLF35584_REG_MASK_MONSF1_ALL); /* SBSW_SBC_VALID_STATUSPTR */
    result |= Sbc_Ll_WriteRegister(dId, SBC_30_TLF35584_REG_ADDR_MONSF3, SBC_30_TLF35584_REG_MASK_MONSF3_OVFLAGS); /* SBSW_SBC_VALID_STATUSPTR */
  }

  /* #20 Clear under-voltage flags */
  if ( (clearFlags & SBC_SYS_EV_UVERR) != 0 )
  {
    result |= Sbc_Ll_WriteRegister(dId, SBC_30_TLF35584_REG_ADDR_INITERR, SBC_30_TLF35584_REG_MASK_INITERR_VMONF); /* SBSW_SBC_VALID_STATUSPTR */
    result |= Sbc_Ll_WriteRegister(dId, SBC_30_TLF35584_REG_ADDR_MONSF2, SBC_30_TLF35584_REG_MASK_MONSF2_ALL); /* SBSW_SBC_VALID_STATUSPTR */
    result |= Sbc_Ll_WriteRegister(dId, SBC_30_TLF35584_REG_ADDR_MONSF3, SBC_30_TLF35584_REG_MASK_MONSF3_BG12UV); /* SBSW_SBC_VALID_STATUSPTR */
  }

  /* #30 Clear over-temperature flags */
  if ( (clearFlags & SBC_SYS_EV_TEMPFAIL) != 0 )
  {
    result |= Sbc_Ll_WriteRegister(dId, SBC_30_TLF35584_REG_ADDR_OTFAIL, SBC_30_TLF35584_REG_MASK_OTFAIL_ALL); /* SBSW_SBC_VALID_STATUSPTR */
  }

  /* #40 Clear watchdog failure flags */
  if ( (clearFlags & SBC_SYS_EV_WDFAIL) != 0 )
  {
    result |= Sbc_Ll_WriteRegister(dId, SBC_30_TLF35584_REG_ADDR_INITERR, SBC_30_TLF35584_REG_MASK_INITERR_WDFLAGS); /* SBSW_SBC_VALID_STATUSPTR */
  }

  /* #50 Clear SPI failure flags */
  if ( (clearFlags & SBC_SYS_EV_SPIFAIL) != 0 )
  {
    result |= Sbc_Ll_WriteRegister(dId, SBC_30_TLF35584_REG_ADDR_SPISF, SBC_30_TLF35584_REG_MASK_SPISF_ALL); /* SBSW_SBC_VALID_STATUSPTR */
  }

  return result;
}


/* ********************************************************************************************************************
 * Sbc_Ll_Sys_ReadStatus
 * ********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 *
 */
SBC_LOCAL_INLINE FUNC(Std_ReturnType, SBC_30_TLF35584_CODE) Sbc_Ll_Sys_ReadStatus(
    Sbc_IdType dId, P2VAR(Sbc_SystemStatusType, AUTOMATIC, SBC_30_TLF35584_APPL_DATA) status)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType result = E_OK;
  uint16 tmp;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Read system-failure register */
  result = Sbc_Ll_ReadRegister(dId, SBC_30_TLF35584_REG_ADDR_SYSFAIL, &tmp); /* SBSW_SBC_LOCALPTR_PARAM */ /* SBSW_SBC_ACCESS_LOCAL */

  /* #20 Evaluate over-temperature failure flag */
  if( (((uint8)tmp) & SBC_30_TLF35584_REG_MASK_SYSFAIL_OTF) != 0) /* COV_SBC_LL_EVENTS */
  {
    Sbc_Ev_Set(status, SBC_SYS_EV_TEMPFAIL); /* SBSW_SBC_VALID_STATUSPTR */
  }

  /* #30 Evaluate voltage-monitoring failure flag */
  if( (((uint8)tmp) & SBC_30_TLF35584_REG_MASK_SYSFAIL_VMONF) != 0) /* COV_SBC_LL_EVENTS */
  {
    result |= Sbc_Ll_Sys_EvaluateMonsfRegs(dId, status); /* SBSW_SBC_VALID_STATUSPTR */
  }

  /* #40 Read init-error register */
  result |= Sbc_Ll_ReadRegister(dId, SBC_30_TLF35584_REG_ADDR_INITERR, &tmp); /* SBSW_SBC_LOCALPTR_PARAM */ /* SBSW_SBC_ACCESS_LOCAL */

  /* #50 Evaluate watchdog error flags */
  if( (((uint8)tmp) & SBC_30_TLF35584_REG_MASK_INITERR_WDFLAGS) != 0) /* COV_SBC_LL_EVENTS */
  {
    Sbc_Ev_Set(status, SBC_SYS_EV_WDFAIL); /* SBSW_SBC_VALID_STATUSPTR */
  }

  /* #60 Read SPI status flag register */
  result |= Sbc_Ll_ReadRegister(dId, SBC_30_TLF35584_REG_ADDR_SPISF, &tmp); /* SBSW_SBC_LOCALPTR_PARAM */ /* SBSW_SBC_ACCESS_LOCAL */

  /* #70 Evaluate SPI error flags */
  if( ((uint8)tmp) != 0) /* COV_SBC_LL_EVENTS */
  {
    Sbc_Ev_Set(status, SBC_SYS_EV_SPIFAIL); /* SBSW_SBC_VALID_STATUSPTR */
  }

  return result;
}

/* ********************************************************************************************************************
 * Sbc_Ll_Sys_AccessRegister
 * ********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
SBC_LOCAL_INLINE FUNC(Std_ReturnType, SBC_30_TLF35584_CODE) Sbc_Ll_Sys_AccessRegister(
  Sbc_IdType dId, Sbc_SpiDataWidth spiCommand, P2VAR(Sbc_SpiDataWidth, AUTOMATIC, SBC_30_TLF35584_APPL_DATA) spiAnswer)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType result = E_NOT_OK;

  /* ----- Implementation ----------------------------------------------- */
#if (SBC_30_TLF35584_DEV_ERROR_DETECT == STD_ON)
  /* #10 Ensure that the spiCommand does not influence the Watchdog behaviour */
  if (
        ((spiCommand & (SBC_30_TLF35584_MASK_CMD_WRITE_RAW | SBC_30_TLF35584_MASK_SPIADDR_RAW)) != (Sbc_Ll_MkWrCommand(SBC_30_TLF35584_REG_ADDR_WDCFG0, 0))) &&
        ((spiCommand & (SBC_30_TLF35584_MASK_CMD_WRITE_RAW | SBC_30_TLF35584_MASK_SPIADDR_RAW)) != (Sbc_Ll_MkWrCommand(SBC_30_TLF35584_REG_ADDR_WDCFG1, 0))) &&
        ((spiCommand & (SBC_30_TLF35584_MASK_CMD_WRITE_RAW | SBC_30_TLF35584_MASK_SPIADDR_RAW)) != (Sbc_Ll_MkWrCommand(SBC_30_TLF35584_REG_ADDR_FWDCFG, 0))) &&
        ((spiCommand & (SBC_30_TLF35584_MASK_CMD_WRITE_RAW | SBC_30_TLF35584_MASK_SPIADDR_RAW)) != (Sbc_Ll_MkWrCommand(SBC_30_TLF35584_REG_ADDR_WWDCFG0, 0))) &&
       ( (spiCommand & (SBC_30_TLF35584_MASK_CMD_WRITE_RAW | SBC_30_TLF35584_MASK_SPIADDR_RAW)) != (Sbc_Ll_MkWrCommand(SBC_30_TLF35584_REG_ADDR_WWDCFG1, 0)))
      )
#endif
  {
    /* #20 Call Sbc_Ll_RwRegister to initiate SPI transfer */
    result = Sbc_Ll_RwRegister(dId, spiCommand, spiAnswer); /* SBSW_SBC_VALID_SPIANSWERPTR */
  }

  return result;
}

#if defined(SBC_30_TLF35584_ENABLE_WDG)
/* ********************************************************************************************************************
 * Sbc_Ll_Wdg_Trigger
 * ********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 */
SBC_LOCAL_INLINE FUNC(Std_ReturnType, SBC_30_TLF35584_CODE) Sbc_Ll_Wdg_Trigger(
    Sbc_IdType dId, Sbc_IdType pId)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType result = E_OK;
# if SBC_30_TLF35584_DIOCHANNEL == STD_OFF
  uint16 tmp;
# endif
# if SBC_30_TLF35584_FWDCFGFASTOFWDGCONFIG == STD_ON
  uint16 quest;
# endif
  SBC_30_TLF35584_DUMMY_STATEMENT(pId); /* PRQA S 3112 */ /* MD_MSR_14.2 */

  /* ----- Implementation ----------------------------------------------- */
  /* #10 If FWD is used */
# if SBC_30_TLF35584_FWDCFGFASTOFWDGCONFIG == STD_ON

  /* #20 Write response keys to FWD */
  quest = Wdg_30_Tlf35584_FwdQuestion[dId];
  result |= Sbc_Ll_WriteRegister(dId, SBC_30_TLF35584_REG_ADDR_FWDRSP, Wdg_30_TLF35584_FwdResponseTbl[quest].RESP3); /* SBSW_SBC_NULLPTR_PARAM */
  result |= Sbc_Ll_WriteRegister(dId, SBC_30_TLF35584_REG_ADDR_FWDRSP, Wdg_30_TLF35584_FwdResponseTbl[quest].RESP2); /* SBSW_SBC_NULLPTR_PARAM */
  result |= Sbc_Ll_WriteRegister(dId, SBC_30_TLF35584_REG_ADDR_FWDRSP, Wdg_30_TLF35584_FwdResponseTbl[quest].RESP1); /* SBSW_SBC_NULLPTR_PARAM */
  result |= Sbc_Ll_WriteRegister(dId, SBC_30_TLF35584_REG_ADDR_FWDRSPSYNC, Wdg_30_TLF35584_FwdResponseTbl[quest].RESP0); /* SBSW_SBC_NULLPTR_PARAM */

  /* #30 Obtain new question of FWD for next trigger cycle */
  result |= Sbc_Ll_ReadRegister(dId, SBC_30_TLF35584_REG_ADDR_FWDSTAT, &tmp); /* SBSW_SBC_LOCALPTR_PARAM */ /* SBSW_SBC_ACCESS_LOCAL */
  Wdg_30_Tlf35584_FwdQuestion[dId] = ((uint8)tmp & SBC_30_TLF35584_REG_MASK_FWDSTAT_FWDQUEST); /* SBSW_SBC_VALID_DID */

# endif /* SBC_30_TLF35584_FWDCFGFASTOFWDGCONFIG */

  /* #50 If WWD is used */
# if SBC_30_TLF35584_WWDCFG0FASTOFWDGCONFIG == STD_ON
  /* #60 If WWD is triggered via Dio */
#  if SBC_30_TLF35584_DIOCHANNEL == STD_ON
  /* #70 Trigger WWD by flipping the level of DioChannel connected to WDI */
  (void)Dio_FlipChannel(Sbc_Ll_Cfg_GetDioChannel(dId));
  /* #80 If WWD is triggered via Spi */
#  else
  /* #90 Read trigger status bit */
  result |= Sbc_Ll_ReadRegister(dId, SBC_30_TLF35584_REG_ADDR_WWDSCMD, &tmp); /* SBSW_SBC_LOCALPTR_PARAM */ /* SBSW_SBC_ACCESS_LOCAL */

  /* #100 Calculate trigger command */
  tmp = ((uint8)(~((uint8)((uint8)tmp) >> SBC_30_TLF35584_SHIFT_WWD_STAT_TO_CMD)) & SBC_30_TLF35584_REG_MASK_WWDSCMD_TRIG);

  /* #120 Trigger WWD by writing the calculated trigger command */
  result |= Sbc_Ll_WriteRegister(dId, SBC_30_TLF35584_REG_ADDR_WWDSCMD, tmp); /* SBSW_SBC_NULLPTR_PARAM */

#  endif /* SBC_30_TLF35584_DIOCHANNEL */

# endif /* SBC_30_TLF35584_WWDCFG0FASTOFWDGCONFIG */

  return result;
}

/* ********************************************************************************************************************
 * Sbc_Ll_Wdg_CanSetMode
 * ********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
SBC_LOCAL_INLINE FUNC(Std_ReturnType, SBC_30_TLF35584_CODE) Sbc_Ll_Wdg_CanSetMode(
    Sbc_IdType dId, Sbc_IdType pId, Sbc_WdgModeType mode)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType result = E_OK;

  SBC_30_TLF35584_DUMMY_STATEMENT(dId);  /* PRQA S 3112 */ /* MD_MSR_14.2 */
  SBC_30_TLF35584_DUMMY_STATEMENT(pId);  /* PRQA S 3112 */ /* MD_MSR_14.2 */
  SBC_30_TLF35584_DUMMY_STATEMENT(mode); /* PRQA S 3112 */ /* MD_MSR_14.2 */

  /* ----- Implementation ----------------------------------------------- */
  return result;
}


/* ********************************************************************************************************************
 * Sbc_Ll_Wdg_SetMode
 * ********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 */
SBC_LOCAL_INLINE FUNC(Std_ReturnType, SBC_30_TLF35584_CODE) Sbc_Ll_Wdg_SetMode(
    Sbc_IdType dId, Sbc_IdType pId, Sbc_WdgModeType mode)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType result = E_OK;
# if SBC_30_TLF35584_FWDCFGFASTOFWDGCONFIG == STD_ON
  uint16 tmp;
#endif

  /* ----- Implementation ----------------------------------------------- */

  /* #10 If requested watchdog mode is OFF mode */
  if(mode == SBC_WDG_MODE_OFF)
  {

    /* #20 Unlock protected registers */
    result |= Sbc_Ll_ReadAndUnlockProtectedRegisters(dId);

    /* #30 Disable watchdog peripherals */
    Sbc_30_Tlf35584_ProtectedRegisterValues[dId][WDCFG0] = (SBC_30_TLF35584_WDCFG0_DEFAULT_VAL /* SBSW_SBC_VALID_DID */ /* SBSW_SBC_VALID_REG_IDX */
    & ~(SBC_30_TLF35584_REG_MASK_WDCFG0_FWDEN | SBC_30_TLF35584_REG_MASK_WDCFG0_WWDEN));

    /* #40 Lock protected registers */
    result |= Sbc_Ll_WriteAndLockProtectedRegisters(dId);
  }
  /* #50 Otherwise */
  else
  {
    /* #60 Unlock protected registers */
    result |= Sbc_Ll_ReadAndUnlockProtectedRegisters(dId);

    /* #70 Write generic watchdog settings */
    Sbc_30_Tlf35584_ProtectedRegisterValues[dId][WDCFG0] = Sbc_Ll_Cfg_GetWdgWDCFG0(dId, pId);  /* SBSW_SBC_VALID_DID */ /* SBSW_SBC_VALID_REG_IDX */
    Sbc_30_Tlf35584_ProtectedRegisterValues[dId][WDCFG1] = Sbc_Ll_Cfg_GetWdgWDCFG1(dId, pId);  /* SBSW_SBC_VALID_DID */ /* SBSW_SBC_VALID_REG_IDX */

    /* #80 If requested watchdog mode is FAST mode configure peripheral correspondingly */
    if(mode == SBC_WDG_MODE_FAST)
    {
# if SBC_30_TLF35584_FWDCFGFASTOFWDGCONFIG == STD_ON
      Sbc_30_Tlf35584_ProtectedRegisterValues[dId][FWDCFG] = Sbc_Ll_Cfg_GetWdgFWCFGfast(dId, pId);  /* SBSW_SBC_VALID_DID */ /* SBSW_SBC_VALID_REG_IDX */
# endif
# if SBC_30_TLF35584_WWDCFG0FASTOFWDGCONFIG == STD_ON
    Sbc_30_Tlf35584_ProtectedRegisterValues[dId][WWDCFG0] = Sbc_Ll_Cfg_GetWdgWWDCFG0fast(dId, pId);  /* SBSW_SBC_VALID_DID */ /* SBSW_SBC_VALID_REG_IDX */
    Sbc_30_Tlf35584_ProtectedRegisterValues[dId][WWDCFG1] = Sbc_Ll_Cfg_GetWdgWWDCFG1fast(dId, pId);  /* SBSW_SBC_VALID_DID */ /* SBSW_SBC_VALID_REG_IDX */
# endif
    }
    /* #90 Otherwise (if requested mode is SLOW mode) configure peripheral correspondingly */
    else /* SBC_WDG_MODE_SLOW */
    {
# if SBC_30_TLF35584_FWDCFGFASTOFWDGCONFIG == STD_ON
      Sbc_30_Tlf35584_ProtectedRegisterValues[dId][FWDCFG] = Sbc_Ll_Cfg_GetWdgFWCFGslow(dId, pId);  /* SBSW_SBC_VALID_DID */ /* SBSW_SBC_VALID_REG_IDX */
# endif
# if SBC_30_TLF35584_WWDCFG0FASTOFWDGCONFIG == STD_ON
      Sbc_30_Tlf35584_ProtectedRegisterValues[dId][WWDCFG0] = Sbc_Ll_Cfg_GetWdgWWDCFG0slow(dId, pId); /* SBSW_SBC_VALID_DID */ /* SBSW_SBC_VALID_REG_IDX */
      Sbc_30_Tlf35584_ProtectedRegisterValues[dId][WWDCFG1] = Sbc_Ll_Cfg_GetWdgWWDCFG1slow(dId, pId); /* SBSW_SBC_VALID_DID */ /* SBSW_SBC_VALID_REG_IDX */
# endif
    }

    /* #100 Lock protected registers */
    result |= Sbc_Ll_WriteAndLockProtectedRegisters(dId);

    /* #110 If FWD peripheral is used read initial FWD question */
# if SBC_30_TLF35584_FWDCFGFASTOFWDGCONFIG == STD_ON
    result |= Sbc_Ll_ReadRegister(dId, SBC_30_TLF35584_REG_ADDR_FWDSTAT, &tmp); /* SBSW_SBC_LOCALPTR_PARAM */ /* SBSW_SBC_ACCESS_LOCAL */
    Wdg_30_Tlf35584_FwdQuestion[dId] = ((uint8)tmp & SBC_30_TLF35584_REG_MASK_FWDSTAT_FWDQUEST); /* SBSW_SBC_VALID_DID */
# endif

    /* #120 If WWD peripheral with DIO triggering is used, set initial level */
#if ((SBC_30_TLF35584_WWDCFG0FASTOFWDGCONFIG == STD_ON) && (SBC_30_TLF35584_DIOCHANNEL == STD_ON))
    Dio_WriteChannel(Sbc_Ll_Cfg_GetDioChannel(dId), STD_HIGH);
#endif

  }

  return result;
}
#endif /* SBC_30_TLF35584_ENABLE_WDG */


/**********************************************************************************************************************
 * Sbc_Ll_CalcSpiParity
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
SBC_LOCAL_INLINE FUNC(uint16, SBC_30_TLF35584_CODE) Sbc_Ll_CalcSpiParity(uint16 in)
{
  /* ----- Local Variables ---------------------------------------------- */
  uint8 i;
  uint16 res = 0;

  /* ----- Implementation ----------------------------------------------- */
  for(i = 0; i < 16; i++)
  {
      res = res ^ ((in >> i) & 0x01);
  }
  return (((in & (~(0x01u))) | res));
}


/**********************************************************************************************************************
 * Sbc_Ll_RwRegister
 *********************************************************************************************************************/
/*!
 * - #10 Write command to SPI out buffer
 * - #20 Transmit command synchronously via SPI
 * - #30 If parameter target is not a NULL_PTR, write read back value to pointer
 */
SBC_LOCAL FUNC(Std_ReturnType, SBC_30_TLF35584_CODE) Sbc_Ll_RwRegister(
    Sbc_IdType dId, uint16 out, P2VAR(uint16, AUTOMATIC, SBC_30_TLF35584_APPL_DATA) in)
{

  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType result = E_NOT_OK;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Write command to SPI out buffer */
  Sbc_Ll_SpiOutBuffer[dId] = out; /* SBSW_SBC_VALID_DID */

  Sbc_EnterCritical(SBC_EXCLUSIVE_AREA_3);
  /* >>> CRITICAL SECTION START >>> */

  /* #20 Transmit command synchronously via SPI */
  result = Sbc_SpiSyncTransmit(Sbc_Ll_Cfg_GetSpiSequence(dId));

  /* #30 If parameter target is not a NULL_PTR, write read back value to pointer */
  if(in != NULL_PTR)
  {
    *in = Sbc_Ll_SpiInBuffer[dId]; /* SBSW_SBC_VALID_INPTR */
  }

  /* <<< CRITICAL SECTION END <<< */
  Sbc_LeaveCritical(SBC_EXCLUSIVE_AREA_3);

  return result;
}

/* ********************************************************************************************************************
 * Sbc_Ll_ReadAndUnlockProtectedRegisters
 * ********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
SBC_LOCAL_INLINE FUNC(Std_ReturnType, SBC_30_TLF35584_CODE) Sbc_Ll_ReadAndUnlockProtectedRegisters(Sbc_IdType dId)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType result = E_OK;
  uint16 tmp;
  uint8 regIdx;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Unlock protected registers */
  result |= Sbc_Ll_WriteRegister(dId, SBC_30_TLF35584_REG_ADDR_PROTCFG, SBC_30_TLF35584_REG_CMD_PROTCFG_UNLOCK_SEQ1);  /* SBSW_SBC_NULLPTR_PARAM */
  result |= Sbc_Ll_WriteRegister(dId, SBC_30_TLF35584_REG_ADDR_PROTCFG, SBC_30_TLF35584_REG_CMD_PROTCFG_UNLOCK_SEQ2);  /* SBSW_SBC_NULLPTR_PARAM */
  result |= Sbc_Ll_WriteRegister(dId, SBC_30_TLF35584_REG_ADDR_PROTCFG, SBC_30_TLF35584_REG_CMD_PROTCFG_UNLOCK_SEQ3);  /* SBSW_SBC_NULLPTR_PARAM */
  result |= Sbc_Ll_WriteRegister(dId, SBC_30_TLF35584_REG_ADDR_PROTCFG, SBC_30_TLF35584_REG_CMD_PROTCFG_UNLOCK_SEQ4);  /* SBSW_SBC_NULLPTR_PARAM */

  /* #20 Check if unlock procedure was successful */
  result |= Sbc_Ll_ReadRegister(dId, SBC_30_TLF35584_REG_ADDR_PROTSTAT, &tmp);  /* SBSW_SBC_LOCALPTR_PARAM */ /* SBSW_SBC_ACCESS_LOCAL */
  if (((uint8)tmp & SBC_30_TLF35584_REG_MASK_PROTSTAT_LOCK) != 0) /* COV_SBC_LL_EVENTS */
  {
    result |= E_NOT_OK;
  }
  else
  {
    /* #30 Read values of protected register to buffer */
    for (regIdx = 0; regIdx < SBC_30_TLF35584_NUMBER_OF_PROTECTED_REGISTERS; regIdx++)
    {
      result |= Sbc_Ll_ReadRegister(dId, Sbc_Ll_GetAddrOfReadProtRegFromIdx(regIdx), &tmp);  /* SBSW_SBC_LOCALPTR_PARAM */ /* SBSW_SBC_ACCESS_LOCAL */
      Sbc_30_Tlf35584_ProtectedRegisterValues[dId][regIdx] = (uint8)tmp; /* SBSW_SBC_VALID_DID */ /* SBSW_SBC_VALID_REG_IDX_LOOP */
    }
  }

  return result;
}


/* ********************************************************************************************************************
 * Sbc_Ll_WriteAndLockProtectedRegisters
 * ********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
SBC_LOCAL_INLINE FUNC(Std_ReturnType, SBC_30_TLF35584_CODE) Sbc_Ll_WriteAndLockProtectedRegisters(Sbc_IdType dId)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType result = E_OK;
  uint16 tmp;
  uint8 checkSum = 0xFF;
  uint8 regIdx;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Write buffered values of protected registers */
  for (regIdx = 0; regIdx < SBC_30_TLF35584_NUMBER_OF_PROTECTED_REGISTERS; regIdx++)
  {
    result |= Sbc_Ll_WriteRegister(dId, Sbc_Ll_GetAddrOfProtRegFromIdx(regIdx), Sbc_30_Tlf35584_ProtectedRegisterValues[dId][regIdx]);  /* SBSW_SBC_NULLPTR_PARAM */
  }

  /* #20 Check if data was written successfully written to protected registers */
  for (regIdx = 0; regIdx < SBC_30_TLF35584_NUMBER_OF_PROTECTED_REGISTERS; regIdx++)
  {
    result |= Sbc_Ll_ReadRegister(dId, Sbc_Ll_GetAddrOfProtRegFromIdx(regIdx), &tmp); /* SBSW_SBC_LOCALPTR_PARAM */ /* SBSW_SBC_ACCESS_LOCAL */
    checkSum &= (Sbc_30_Tlf35584_ProtectedRegisterValues[dId][regIdx] ^ (uint8)tmp);
  }

  if(checkSum != 0xFF)
  {
    result |= E_NOT_OK;
  }

  /* #30 Lock protected registers */
  result |= Sbc_Ll_WriteRegister(dId, SBC_30_TLF35584_REG_ADDR_PROTCFG, SBC_30_TLF35584_REG_CMD_PROTCFG_LOCK_SEQ1);  /* SBSW_SBC_NULLPTR_PARAM */
  result |= Sbc_Ll_WriteRegister(dId, SBC_30_TLF35584_REG_ADDR_PROTCFG, SBC_30_TLF35584_REG_CMD_PROTCFG_LOCK_SEQ2);  /* SBSW_SBC_NULLPTR_PARAM */
  result |= Sbc_Ll_WriteRegister(dId, SBC_30_TLF35584_REG_ADDR_PROTCFG, SBC_30_TLF35584_REG_CMD_PROTCFG_LOCK_SEQ3);  /* SBSW_SBC_NULLPTR_PARAM */
  result |= Sbc_Ll_WriteRegister(dId, SBC_30_TLF35584_REG_ADDR_PROTCFG, SBC_30_TLF35584_REG_CMD_PROTCFG_LOCK_SEQ4);  /* SBSW_SBC_NULLPTR_PARAM */

  /* #40 Check if unlock procedure was successful */
  result |= Sbc_Ll_ReadRegister(dId, SBC_30_TLF35584_REG_ADDR_PROTSTAT, &tmp);  /* SBSW_SBC_LOCALPTR_PARAM */ /* SBSW_SBC_ACCESS_LOCAL */
  if (((uint8)tmp & SBC_30_TLF35584_REG_MASK_PROTSTAT_LOCK) != SBC_30_TLF35584_REG_MASK_PROTSTAT_LOCK) /* COV_SBC_LL_EVENTS */
  {
    result |= E_NOT_OK;
  }

  return result;
}

/* ********************************************************************************************************************
 * Sbc_Ll_Sys_EvaluateMonsfRegs
 * ********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
SBC_LOCAL_INLINE FUNC(Std_ReturnType, SBC_30_TLF35584_CODE) Sbc_Ll_Sys_EvaluateMonsfRegs(
    Sbc_IdType dId, P2VAR(Sbc_SystemStatusType, AUTOMATIC, SBC_30_TLF35584_APPL_DATA) status)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType result = E_OK;
  uint16 tmp;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Evaluate register MONSF1 */
  result = Sbc_Ll_ReadRegister(dId, SBC_30_TLF35584_REG_ADDR_MONSF1, &tmp); /* SBSW_SBC_LOCALPTR_PARAM */ /* SBSW_SBC_ACCESS_LOCAL */
  if( ((uint8)tmp) != 0) /* COV_SBC_LL_EVENTS */
  {
    Sbc_Ev_Set(status, SBC_SYS_EV_OVERR); /* SBSW_SBC_VALID_STATUSPTR */
  }

  /* #20 Evaluate register MONSF2 */
  result = Sbc_Ll_ReadRegister(dId, SBC_30_TLF35584_REG_ADDR_MONSF2, &tmp); /* SBSW_SBC_LOCALPTR_PARAM */ /* SBSW_SBC_ACCESS_LOCAL */
  if( ((uint8)tmp) != 0) /* COV_SBC_LL_EVENTS */
  {
    Sbc_Ev_Set(status, SBC_SYS_EV_UVERR); /* SBSW_SBC_VALID_STATUSPTR */
  }

  /* #30 Evaluate register MONSF3 */
  result = Sbc_Ll_ReadRegister(dId, SBC_30_TLF35584_REG_ADDR_MONSF3, &tmp); /* SBSW_SBC_LOCALPTR_PARAM */ /* SBSW_SBC_ACCESS_LOCAL */
  if( (((uint8)tmp) & SBC_30_TLF35584_REG_MASK_MONSF3_OVFLAGS) != 0) /* COV_SBC_LL_EVENTS */
  {
    Sbc_Ev_Set(status, SBC_SYS_EV_OVERR); /* SBSW_SBC_VALID_STATUSPTR */
  }

  if( (((uint8)tmp) & SBC_30_TLF35584_REG_MASK_MONSF3_BG12UV) != 0) /* COV_SBC_LL_EVENTS */
  {
    Sbc_Ev_Set(status, SBC_SYS_EV_UVERR); /* SBSW_SBC_VALID_STATUSPTR */
  }

  return result;

}
#define SBC_30_TLF35584_STOP_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


#define SBC_30_TLF35584_START_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
/*********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/

/*********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  Sbc_InitMemory()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(void, SBC_30_TLF35584_CODE) Sbc_30_Tlf35584_InitMemory(void)
{

  /* ----- Implementation ----------------------------------------------- */
#if (SBC_30_TLF35584_DEV_ERROR_DETECT == STD_ON)
  Sbc_ModuleInitialized = SBC_UNINIT;
#endif

} /* Sbc_InitMemory() */


/*********************************************************************************************************************
 * Sbc_Init()
 *********************************************************************************************************************/
 /*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 */
FUNC(void, SBC_30_TLF35584_CODE) Sbc_30_Tlf35584_Init( P2CONST(Sbc_30_Tlf35584_ConfigType, AUTOMATIC, SBC_30_TLF35584_PBCFG) ConfigPtr )
{
  /* ----- Local Variables ---------------------------------------------- */
  uint8 errorId = SBC_E_NO_ERROR;
  Std_ReturnType deviceResult;
  Sbc_IdType dId;
  
#if defined(SBC_30_TLF35584_ENABLE_WDG)
  Sbc_IdType pId;
#endif

  /* ----- Development Error Checks ------------------------------------- */
# if (SBC_30_TLF35584_DEV_ERROR_DETECT == STD_ON)
  /* #10 Check if SBC driver is in an uninitialized state */
  if ( Sbc_IsModuleInitialized() )
  {
    /* Module is already initialized. */
    errorId = SBC_E_ALREADY_INITIALIZED;
  }
  else
#endif
  {
    /* ----- Implementation ----------------------------------------------- */

    /* #20 Loop over all SBC instances */
    for (dId = 0; dId < Sbc_Cfg_GetNumberOfDevices(); dId++)
    {
      /* #30 Reset the software states of all SBC instances and all of their peripherals */
      
      /* Reset the system data. No need for a critical area here as module is not initialized. */
      Sbc_Rt_GetSystemStatus(dId).Events = 0; /* SBSW_SBC_DEVICE_INIT_LOOP */
      Sbc_Rt_GetSystemStatus(dId).States = 0; /* SBSW_SBC_DEVICE_INIT_LOOP */
      Sbc_Rt_GetSystemStatus(dId).Mode = SBC_SYS_MODE_NORMAL; /* SBSW_SBC_DEVICE_INIT_LOOP */



#if defined(SBC_30_TLF35584_ENABLE_WDG)
      /* Initialize mode of Wdg(s): Wdg modes are hw dependent and must be set in Sbc_Ll_InitDevice() or by watchdog driver */
      for (pId = 0; pId < Sbc_Cfg_GetNumberOfWdg(dId); pId++)
      {
# if (SBC_30_TLF35584_DEV_ERROR_DETECT == STD_ON)
        if (pId < SBC_30_TLF35584_MAX_NUMBER_OF_WDG) /* COV_SBC_INVALID_PID */
# endif
        {
          Sbc_Rt_SetWdgMode(dId, pId, SBC_WDG_MODE_INVALID); /* SBSW_SBC_PERIPHERAL_INIT_LOOP */
        }
# if (SBC_30_TLF35584_DEV_ERROR_DETECT == STD_ON)
        else
        {
          errorId = SBC_E_PARAM_ID;
        }
# endif
      }
#endif

      /* #40 Initialize hardware specific parts of SBC instance */
      deviceResult = Sbc_Ll_InitDevice(dId);

      /* #50 If hardware specific parts of SBC instance is not initialized successfully */
      if ( deviceResult == E_NOT_OK )
      {
        /* #60 Set the error flag and cancel initialization loop */
        errorId = SBC_E_INITIALIZATION_FAILED;
        
        /* leave the loop over Sbc devices */
        break;
      }
    }
  }

  /* ----- Development Error Report ------------------------------------- */
#if (SBC_30_TLF35584_DEV_ERROR_REPORT == STD_ON)
  if ( errorId == SBC_E_NO_ERROR )
  {
    /* Initialization was successful. */
    Sbc_ModuleInitialized = SBC_INIT;
  }
  else
  {
    (void) Det_ReportError(SBC_30_TLF35584_MODULE_ID, SBC_30_TLF35584_INSTANCE_ID_DET, SBC_SID_INIT, errorId);
  }
# else
  SBC_30_TLF35584_DUMMY_STATEMENT(errorId); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */
# endif

} /* Sbc_Init() */ /* PRQA S 2006,6010,6030 */ /* MD_MSR_14.7,MD_MSR_STPTH,MD_MSR_STCYC */



#if ( SBC_30_TLF35584_VERSION_INFO_API == STD_ON )
/**********************************************************************************************************************
 *  Sbc_GetVersionInfo()
 *********************************************************************************************************************/
 /*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(void, SBC_30_TLF35584_CODE) Sbc_30_Tlf35584_GetVersionInfo(P2VAR(Std_VersionInfoType, AUTOMATIC, SBC_30_TLF35584_APPL_DATA) versioninfo)
{
  uint8 errorId = SBC_E_NO_ERROR;

  /* ----- Development Error Checks ------------------------------------- */
# if (SBC_30_TLF35584_DEV_ERROR_DETECT == STD_ON)
  /* #10 Check parameter versioninfo */
  if ( !Sbc_IsPtrValid(versioninfo) )
  {
    errorId = SBC_E_PARAM_VERSIONINFO;
  }
  else
# endif
  {
    /* ----- Implementation ----------------------------------------------- */
    /* #20 Fill versions from defines into versioninfo structure  */
    versioninfo->vendorID         = ( SBC_30_TLF35584_VENDOR_ID );         /* SBSW_SBC_VERSIONINFO */
    versioninfo->moduleID         = ( SBC_30_TLF35584_MODULE_ID );         /* SBSW_SBC_VERSIONINFO */
    versioninfo->sw_major_version = ( SBC_30_TLF35584_SW_MAJOR_VERSION );  /* SBSW_SBC_VERSIONINFO */
    versioninfo->sw_minor_version = ( SBC_30_TLF35584_SW_MINOR_VERSION );  /* SBSW_SBC_VERSIONINFO */
    versioninfo->sw_patch_version = ( SBC_30_TLF35584_SW_PATCH_VERSION );  /* SBSW_SBC_VERSIONINFO */
  }

  /* ----- Development Error Report ------------------------------------- */
# if (SBC_30_TLF35584_DEV_ERROR_REPORT == STD_ON)
  if (errorId != SBC_E_NO_ERROR)
  {
    (void) Det_ReportError(SBC_30_TLF35584_MODULE_ID, SBC_30_TLF35584_INSTANCE_ID_DET, SBC_SID_GETVERSIONINFO, errorId);
  }
# else
  SBC_30_TLF35584_DUMMY_STATEMENT(errorId); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */
# endif

} /* Sbc_GetVersionInfo() */  /* PRQA S 2006 */ /* MD_MSR_14.7 */
#endif

/*********************************************************************************************************************
 * Sbc_SetMode
 **********************************************************************************************************************/
 /*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 */
FUNC(Std_ReturnType, SBC_30_TLF35584_CODE) Sbc_30_Tlf35584_SetMode(Sbc_IdType id, Sbc_SystemModeType mode)
{
  /* ----- Local Variables ---------------------------------------------- */
  uint8 errorId = SBC_E_NO_ERROR;
  Std_ReturnType result = E_NOT_OK;
  Sbc_IdType dId;

  /* ----- Development Error Checks ------------------------------------- */
#if (SBC_30_TLF35584_DEV_ERROR_DETECT == STD_ON)
  /* #10 Check if SBC driver is initialized and parameters 'id' and 'mode' are valid */
  if ( !Sbc_IsModuleInitialized() )
  {
    errorId = SBC_E_UNINIT;
  }
  else if ( !Sbc_IsIdValid(id) )
  {
    errorId = SBC_E_PARAM_ID;
  }
  else if ( !Sbc_IsSysModeValid(mode) ) /* PRQA S 3355 */ /* MD_Sbc_3355 */
  {
    errorId = SBC_E_PARAM_MODE;
  }
  else
#endif
  {
  /* ----- Implementation ----------------------------------------------- */
    /* Get the device id */
    dId = Sbc_GetDeviceIndex(id);

    /* #20 If mode change is possible */
    if ( Sbc_Ll_Sys_CanSetMode(dId, mode) == E_OK )
    {
      /* #30 Change the operation mode */
      result = Sbc_Ll_Sys_SetMode(dId, mode);

      /* #40 If mode was changed successfully */
      if ( result == E_OK )
      {
        Sbc_EnterCritical(SBC_EXCLUSIVE_AREA_0);
        /* >>> CRITICAL AREA START >>> */
        
        /* #50 Store the operation mode */
        Sbc_Sys_St_SetMode(&Sbc_Rt_GetSystemStatus(dId), mode); /* SBSW_SBC_VALID_DID_DET */
        
        /* #60 Clear POR event if mode is changed to NORMAL mode */
        if (SBC_SYS_MODE_NORMAL == mode)
        {
          Sbc_Ev_Clr(&Sbc_Rt_GetSystemStatus(dId), SBC_SYS_EV_POR); /* SBSW_SBC_VALID_DID_DET */
        }

        /* <<< CRITICAL AREA END <<< */
        Sbc_LeaveCritical(SBC_EXCLUSIVE_AREA_0);
      }
      else
      {
        /* Communication failed */
        errorId = SBC_E_COMMUNICATION;
      }

    }
    else
    {
      /* Mode change not possible */
      errorId = SBC_E_INVALID_STATE;
    }
  }

  /* ----- Development Error Report ------------------------------------- */
#if (SBC_30_TLF35584_DEV_ERROR_REPORT == STD_ON)
  if (errorId != SBC_E_NO_ERROR)
  {
    (void) Det_ReportError(SBC_30_TLF35584_MODULE_ID, SBC_30_TLF35584_INSTANCE_ID_DET, SBC_SID_SETMODE, errorId);
  }
#else
  SBC_30_TLF35584_DUMMY_STATEMENT(errorId); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */
#endif

  return result;
} /* Sbc_SetMode() */ /* PRQA S 6080 */ /* MD_MSR_STMIF */

/*********************************************************************************************************************
 * Sbc_GetStatus
 *********************************************************************************************************************/
 /*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 */
FUNC(Std_ReturnType, SBC_30_TLF35584_CODE) Sbc_30_Tlf35584_GetStatus(Sbc_IdType id, P2VAR(Sbc_SystemStatusType, AUTOMATIC, SBC_30_TLF35584_APPL_DATA) status)
{
  /* ----- Local Variables ---------------------------------------------- */
  uint8 errorId = SBC_E_NO_ERROR;
  Std_ReturnType result = E_NOT_OK;
  Sbc_IdType dId;
  Sbc_SystemStatusType tempStatus;

  /* ----- Development Error Checks ------------------------------------- */
#if (SBC_30_TLF35584_DEV_ERROR_DETECT == STD_ON)
  /* #10 Check if SBC driver is initialized and parameters 'id' and 'status' are valid */
  if ( !Sbc_IsModuleInitialized() )
  {
    errorId = SBC_E_UNINIT;
  }
  else if ( !Sbc_IsIdValid(id) )
  {
    errorId = SBC_E_PARAM_ID;
  }
  else if ( !Sbc_IsPtrValid(status) )
  {
    errorId = SBC_E_PARAM_STATUS;
  }
  else
#endif
  {
    /* ----- Implementation ----------------------------------------------- */

    /* Get the device id */
    dId = Sbc_GetDeviceIndex(id);

    tempStatus.Events = 0;
    tempStatus.States = 0;  
    /* Preserve the current mode. LL may overwrite it */
    tempStatus.Mode = Sbc_Rt_GetSystemStatus(dId).Mode;

    /* #20 Query the status from hardware */
    result = Sbc_Ll_Sys_ReadStatus(dId, &tempStatus); /* SBSW_SBC_LOCALPTR_PARAM */

    /* #30 If status was read from hardware successfully */
    if ( result == E_OK )
    {
      Sbc_EnterCritical(SBC_EXCLUSIVE_AREA_0);
      /* >>> CRITICAL AREA START >>> */

      /* #40 Update the global status */
      Sbc_UpdateStatusFlags(&Sbc_Rt_GetSystemStatus(dId), tempStatus); /* SBSW_SBC_VALID_DID_DET */ /* SBSW_SBC_VALID_DID_DET */ /* SBSW_SBC_VALID_DID_DET */

      /* #50 Copy it to the return value */
      *status = Sbc_Rt_GetSystemStatus(dId); /* SBSW_SBC_VALID_STATUSPTR */

      /* <<< CRITICAL AREA END <<< */
      Sbc_LeaveCritical(SBC_EXCLUSIVE_AREA_0);
    }
    else
    {
      /* Communication was not possible */
      errorId = SBC_E_COMMUNICATION;
    }
  }

  /* ----- Development Error Report ------------------------------------- */
#if (SBC_30_TLF35584_DEV_ERROR_REPORT == STD_ON)
  if (errorId != SBC_E_NO_ERROR)
  {
    (void) Det_ReportError(SBC_30_TLF35584_MODULE_ID, SBC_30_TLF35584_INSTANCE_ID_DET, SBC_SID_GETSTATUS, errorId);
  }
#else
  SBC_30_TLF35584_DUMMY_STATEMENT(errorId); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */
#endif

  return result;
} /* Sbc_GetStatus() */


/*********************************************************************************************************************
 * Sbc_ClearEvents
 *********************************************************************************************************************/
 /*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 */
Std_ReturnType Sbc_30_Tlf35584_ClearEvents(Sbc_IdType id, Sbc_SystemEventType events)
{
  /* ----- Local Variables ---------------------------------------------- */
  uint8 errorId = SBC_E_NO_ERROR;
  Std_ReturnType result = E_NOT_OK;
  Sbc_IdType dId;
  Sbc_SystemStatusType tempStatus;

  /* ----- Development Error Checks ------------------------------------- */
#if (SBC_30_TLF35584_DEV_ERROR_DETECT == STD_ON)
  /* #10 Check if SBC driver is initialized and parameter 'id' is valid */
  if ( !Sbc_IsModuleInitialized() )
  {
    errorId = SBC_E_UNINIT;
  }
  else if ( !Sbc_IsIdValid(id) )
  {
    errorId = SBC_E_PARAM_ID;
  }
  else
#endif
  {
    /* ----- Implementation ----------------------------------------------- */
    /* Get the device id */
    dId = Sbc_GetDeviceIndex(id);

    tempStatus.Events = 0;
    /* Preserve the current mode and state */
    tempStatus.States = Sbc_Rt_GetSystemStatus(dId).States;
    tempStatus.Mode = Sbc_Rt_GetSystemStatus(dId).Mode;

    /* #20 Clear the flags from hardware */
    result = Sbc_Ll_Sys_ClearEvents(dId, &tempStatus, events); /* SBSW_SBC_LOCALPTR_PARAM */

    /* #30 If events are cleared from hardware successfully */
    if ( result == E_OK )
    {
      Sbc_EnterCritical(SBC_EXCLUSIVE_AREA_0);
      /* >>> CRITICAL AREA START >>> */

      /* #40 Update the global status with the newly read flags */
      Sbc_UpdateStatusFlags(&Sbc_Rt_GetSystemStatus(dId), tempStatus); /* SBSW_SBC_VALID_DID_DET */ /* SBSW_SBC_VALID_DID_DET */ /* SBSW_SBC_VALID_DID_DET */

      /* #50 Clear the status flags */
      Sbc_ClearEventFlags(&Sbc_Rt_GetSystemStatus(dId), events); /* SBSW_SBC_VALID_DID_DET */

      /* <<< CRITICAL AREA END <<< */
      Sbc_LeaveCritical(SBC_EXCLUSIVE_AREA_0);
    }
    else
    {
      /* Communication not possible */
      errorId = SBC_E_COMMUNICATION;
    }
  }

  /* ----- Development Error Report ------------------------------------- */
#if (SBC_30_TLF35584_DEV_ERROR_REPORT == STD_ON)
  if (errorId != SBC_E_NO_ERROR)
  {
    (void) Det_ReportError(SBC_30_TLF35584_MODULE_ID, SBC_30_TLF35584_INSTANCE_ID_DET, SBC_SID_CLEAREVENTS, errorId);
  }
#else
  SBC_30_TLF35584_DUMMY_STATEMENT(errorId); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */
#endif

  return result;
} /* Sbc_ClearEvents() */

/*********************************************************************************************************************
 * Sbc_AccessRegister()
 *********************************************************************************************************************/
 /*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(Std_ReturnType, SBC_30_TLF35584_CODE) Sbc_30_Tlf35584_AccessRegister(Sbc_IdType id, Sbc_SpiDataWidth spiCommand, P2VAR(Sbc_SpiDataWidth, AUTOMATIC, SBC_30_TLF35584_APPL_DATA) spiAnswer)
{
  /* ----- Local Variables ---------------------------------------------- */
  uint8 errorId = SBC_E_NO_ERROR;
  Std_ReturnType result = E_NOT_OK;
  Sbc_IdType dId;

  /* ----- Development Error Checks ------------------------------------- */
#if (SBC_30_TLF35584_DEV_ERROR_DETECT == STD_ON)
  /* #10 Check if SBC driver is initialized and parameters 'id' and 'spiAnswer' are valid */
  if ( !Sbc_IsModuleInitialized() )
  {
    errorId = SBC_E_UNINIT;
  }
  else if ( !Sbc_IsIdValid(id) )
  {
    errorId = SBC_E_PARAM_ID;
  }
  else if ( !Sbc_IsPtrValid(spiAnswer) )
  {
    errorId = SBC_E_PARAM_SPIANSWER;
  }
  else
#endif
  {
    /* ----- Implementation ----------------------------------------------- */
    /* Get the device id */
    dId = Sbc_GetDeviceIndex(id);
    
    /* #20 Initiates SPI transfer to SBC module */
    result = Sbc_Ll_Sys_AccessRegister(dId, spiCommand, spiAnswer); /* SBSW_SBC_PTR_PARAM */
    if (result == E_NOT_OK)
    {
      errorId = SBC_E_COMMUNICATION;
    }
  }

  /* ----- Development Error Report ------------------------------------- */
#if (SBC_30_TLF35584_DEV_ERROR_REPORT == STD_ON)
  if (errorId != SBC_E_NO_ERROR)
  {
    (void) Det_ReportError(SBC_30_TLF35584_MODULE_ID, SBC_30_TLF35584_INSTANCE_ID_DET, SBC_SID_ACCESS_REGISTER, errorId);
  }
#else
  SBC_30_TLF35584_DUMMY_STATEMENT(errorId); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */
#endif

  return result;
} /* Sbc_AccessRegister() */




#if defined(SBC_30_TLF35584_ENABLE_WDG)
/*********************************************************************************************************************
 * Sbc_Wdg_SetMode
 *********************************************************************************************************************/
 /*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 *
 */
FUNC(Std_ReturnType, SBC_30_TLF35584_CODE) Sbc_30_Tlf35584_Wdg_SetMode(Sbc_PeripheralIdType id, Sbc_WdgModeType mode)
{
  /* ----- Local Variables ---------------------------------------------- */
  uint8 errorId = SBC_E_NO_ERROR;
  Sbc_IdType dId, pId;
  Std_ReturnType result = E_NOT_OK;

  /* ----- Development Error Checks ------------------------------------- */
#if (SBC_30_TLF35584_DEV_ERROR_DETECT == STD_ON)
  /* #10 Check if SBC driver is initialized and parameters 'id' and 'mode' are valid */
  if ( !Sbc_IsModuleInitialized() )
  {
    errorId = SBC_E_UNINIT;
  }
  else if ( !Sbc_IsWdgIdValid(id) ) /* COV_SBC_INVALID_PID */
  {
    errorId = SBC_E_PARAM_ID;
  }
  else if ( !Sbc_IsWdgModeValid(mode) ) /* PRQA S 3355 */ /* MD_Sbc_3355 */
  {
    errorId = SBC_E_PARAM_MODE;
  }
  else
#endif
  {
    /* ----- Implementation ----------------------------------------------- */
    /* Get the device and peripheral id */
    dId = Sbc_GetDeviceIndex(id);
    pId = Sbc_GetPeriphalIndex(id);

    /* #20 If the requested mode is supported */
    if ( Sbc_Ll_Wdg_CanSetMode(dId, pId, mode) == E_OK ) /* COV_SBC_WDG_CANSETMODE */
    {

      /* #30 If requested mode == current mode */
      if (Sbc_Rt_GetWdgMode(dId, pId) == mode)
      {
        /* #40 Do not change the mode in hardware, just return E_OK */
        result = E_OK;     
      }
      /* #50 If requested mode != current mode */
      else
      {
        /* #60 Change the operation mode */
        result = Sbc_Ll_Wdg_SetMode(dId, pId, mode);

        /* #70 Store the operation mode if mode was changed successfully */
        if (result == E_OK) /* COV_SBC_LL_HW_SPI_ERR */
        {
          Sbc_Rt_SetWdgMode(dId, pId, mode); /* SBSW_SBC_VALID_DID_PID_DET */
        }
        else
        {
          /* mode change failed: set error id */
          errorId = SBC_E_COMMUNICATION;
        }
      }
    }
    else
    {
      /* The mode change is not allowed */
      errorId = SBC_E_MODE_FAILED;
    }
  }

  /* ----- Development Error Report ------------------------------------- */
#if (SBC_30_TLF35584_DEV_ERROR_REPORT == STD_ON)
  if (errorId != SBC_E_NO_ERROR)
  {
    (void) Det_ReportError(SBC_30_TLF35584_MODULE_ID, SBC_30_TLF35584_INSTANCE_ID_DET, SBC_SID_WDG_SETMODE, errorId);
  }
#else
  SBC_30_TLF35584_DUMMY_STATEMENT(errorId); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */
#endif

  return result;
} /* Sbc_Wdg_SetMode() */ /* PRQA S 6080 */ /* MD_MSR_STMIF */

/*********************************************************************************************************************
 * Sbc_Wdg_Trigger
 *********************************************************************************************************************/
 /*!
 * Internal comment removed.
 *
 *
 *
 *
 */
FUNC(Std_ReturnType, SBC_30_TLF35584_CODE) Sbc_30_Tlf35584_Wdg_Trigger(Sbc_PeripheralIdType id)
{
  /* ----- Local Variables ---------------------------------------------- */
  uint8 errorId = SBC_E_NO_ERROR;
  Std_ReturnType result = E_NOT_OK;
  Sbc_IdType dId, pId;

  /* ----- Development Error Checks ------------------------------------- */
#if (SBC_30_TLF35584_DEV_ERROR_DETECT == STD_ON)
  /* #10 Check if SBC driver is initialized and parameter 'id' is valid */
  if ( !Sbc_IsModuleInitialized() )
  {
    errorId = SBC_E_UNINIT;
  }
  else if ( !Sbc_IsWdgIdValid(id) ) /* COV_SBC_INVALID_PID */
  {
    errorId = SBC_E_PARAM_ID;
  }
  else
#endif
  {
    /* ----- Implementation ----------------------------------------------- */

    /* Get the device and peripheral id */
    dId = Sbc_GetDeviceIndex(id);
    pId = Sbc_GetPeriphalIndex(id);
    
#if (SBC_30_TLF35584_DEV_ERROR_DETECT == STD_ON)
    /* #20 Sbc_WdgTriggerFlag must be written to protect against Wrong Caller */
    Sbc_WdgTriggerFlag[dId][pId] = 1; /* SBSW_SBC_VALID_DID_PID_DET */
    
    /* self-assignment to prevent compiler warning */
    SBC_30_TLF35584_DUMMY_STATEMENT(Sbc_WdgTriggerFlag[dId][pId]); /* SBSW_SBC_VALID_DID_PID_DET */ /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */
#endif

    /* #30 Trigger the watchdog */
    result = Sbc_Ll_Wdg_Trigger(dId, pId);
    
    if (result == E_NOT_OK)
    {
      errorId = SBC_E_COMMUNICATION;
    }
  }

  /* ----- Development Error Report ------------------------------------- */
#if (SBC_30_TLF35584_DEV_ERROR_REPORT == STD_ON)
  if (errorId != SBC_E_NO_ERROR)
  {
    (void) Det_ReportError(SBC_30_TLF35584_MODULE_ID, SBC_30_TLF35584_INSTANCE_ID_DET, SBC_SID_WDG_TRIGGER, errorId);
  }
#else
  SBC_30_TLF35584_DUMMY_STATEMENT(errorId); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */
#endif
  
  return result;
} /* Sbc_Wdg_Trigger() */
#endif /* SBC_30_TLF35584_ENABLE_WDG */

#define SBC_30_TLF35584_STOP_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/* Justification for module-specific MISRA deviations:

MD_Sbc_0342: MISRA Rule 19.13
  Reason: Glue operator used to abstract AUTOSAR SchM access.
  Risk: Compiler does not support the glue operator.
  Prevention: Module supports only ANSI Compiler. Integration tests verify that the code compiles.
  
MD_Sbc_3453: MISRA Rule 19.7
  Reason: Complex Macros used to optimize code runtime.
  Risk: Readability reduced.
  Prevention: Code inspection.
  
MD_Sbc_3410: MISRA Rule 19.10
  Reason: Parameter used in structures that does not allow brackets
  Risk: None atomic parameter lead to compile errors
  Prevention: Used parameter is always atomic depend on usage
  
MD_Sbc_3412: MISRA Rule 19.4
  Reason: Complex Macros with unrecognised code-fragment used to optimize code runtime.
  Risk: Readability reduced.
  Prevention: Code inspection.
  
MD_Sbc_0779: MISRA Rule 5.1
  Reason: Long identifiers does not differ within the specified number of significant characters
  Risk: Readability reduced.
  Prevention: Code inspection.

MD_Sbc_3355: MISRA Rule 13.7
  Reason: Enum values are checked against greatest limit, so should be always true for valid parameters
  Risk: No risk. Makes the module more robust.
  Prevention: Code inspection.
  
MD_Sbc_3218: MISRA Rule 8.7
  Reason: File scope static, 'Sbc_WdgTriggerFlag', only accessed in one function.
  Risk: No risk. Must be in file scope static so could be linked to a safe section for SafeBSW requirements.
  Prevention: Code inspection.
  

MD_Sbc_3218: MISRA Rule 8.7
  Reason: File scope static, 'Wdg_30_TLF35584_FwdResponseTbl', only accessed in one function.
  Risk: No risk. Must be in file scope static so could be linked to a safe section for SafeBSW requirements.
  Prevention: Code inspection.


*/

/* SBSW_JUSTIFICATION_BEGIN

\ID SBSW_SBC_ACCESS_LOCAL
   \DESCRIPTION Access to a pointer referencing a stack variable.
   \COUNTERMEASURE \N Access to a pointer referencing a stack variable is always valid.


\ID SBSW_SBC_VALID_REG_IDX_LOOP
 \DESCRIPTION Access of array 'Sbc_30_Tlf35584_ProtectedRegisterValues' using an index.
 \COUNTERMEASURE \R The for loop ensures that 'regIdx' never exceeds the size of the array because the loop
                from 0 to dimension of the array.


\ID SBSW_SBC_VALID_REG_IDX
 \DESCRIPTION Access of array 'Sbc_30_Tlf35584_ProtectedRegisterValues' using an index.
 \COUNTERMEASURE \N A static index which does not exceed the array dimension is used to access the array.



SBSW_JUSTIFICATION_END */

/*
  
*/

/* SBSW_JUSTIFICATION_BEGIN

\ID SBSW_SBC_DEVICE_INIT_LOOP
 \DESCRIPTION Linear memory access using a for loop.
 \COUNTERMEASURE \R The for loop ensures that 'dId' never exceeds the size of the array because the loop
                from 0 to dimension of the array.
 
\ID SBSW_SBC_PERIPHERAL_INIT_LOOP
 \DESCRIPTION Linear memory access using a for loop.
 \COUNTERMEASURE \R The for loop ensures that 'dId' never exceeds the size of the first dimension of the array
                because the loop iterates from 0 to dimension of the array.
                'If-conditions' ensure that the 'pId' never exceeds the size of the second dimension of the array.
 
\ID SBSW_SBC_VALID_DID
 \DESCRIPTION Array access or function call using parameter 'dId'.
 \COUNTERMEASURE \N The caller ensures that the parameter 'dId' is valid.
 
\ID SBSW_SBC_VALID_DID_DET
 \DESCRIPTION Array access or function call using parameter 'dId'.
 \COUNTERMEASURE \R DET check (Sbc_IsIdValid) ensures that the parameter 'dId' is valid.
 
\ID SBSW_SBC_VALID_DID_PID
 \DESCRIPTION Array access or function call using parameter 'dId' and 'pId'.
 \COUNTERMEASURE \N The caller ensures that the parameter 'dId' and 'pId' is valid.
 
\ID SBSW_SBC_VALID_DID_PID_DET
 \DESCRIPTION Array access or function call using parameter 'dId' or 'pId'.
 \COUNTERMEASURE \R DET check (Sbc_IsCanTrcvIdValid, Sbc_IsLinTrcvIdValid or Sbc_IsWdgIdValid) ensures
                  that the parameter 'dId' and 'pId' is valid.
 
\ID SBSW_SBC_VALID_STATUSPTR
 \DESCRIPTION Array access or function call using pointer 'status'.
 \COUNTERMEASURE \N The caller ensures that the pointer 'status' that is used as parameter is valid.
 
\ID SBSW_SBC_VALID_SPIANSWERPTR
 \DESCRIPTION Array access or function call using pointer 'spiAnswer'.
 \COUNTERMEASURE \N The caller ensures that the pointer 'spiAnswer' that is used as parameter is valid. 

\ID SBSW_SBC_VALID_INPTR
 \DESCRIPTION Array access or function call using parameter 'in'.
 \COUNTERMEASURE \N The caller ensures that the pointer 'in' that is used as parameter is valid.
                    
\ID SBSW_SBC_VERSIONINFO
  \DESCRIPTION The function writes to the object referenced by parameter 'versioninfo'.
  \COUNTERMEASURE \N The caller ensures that the pointer passed to the parameter 'versioninfo' is valid and references
                    an object of type Std_VersionInfoType.
                    
\ID SBSW_SBC_LOCALPTR_PARAM
  \DESCRIPTION Static functions are called with a local pointer as a parameter.
  \COUNTERMEASURE \N The static function is only called with valid pointers to local parameters.

\ID SBSW_SBC_PTR_PARAM
  \DESCRIPTION API functions are called with a pointer as a parameter.
  \COUNTERMEASURE \N The caller mist ensure that the pointer is valid.
  
\ID SBSW_SBC_NULLPTR_PARAM
  \DESCRIPTION Static function Sbc_Ll_RwRegister is called with a null pointer as a parameter.
  \COUNTERMEASURE \R A 'if-condition' ensures that in case of a null pointer the parameter 'in' is not used.

\ID SBSW_SBC_CALL_SPI_SETUPEB
  \DESCRIPTION SPI API function Spi_SetupEB is called with parameter 'Channel', 'SrcDataBufferPtr',
        'DesDataBufferPtr' and 'Length'.
  \COUNTERMEASURE \N SrcDataBufferPtr is a pointer to const and its content cannot be modified by the callee.
        For DesDataBufferPtr a pointer to one element of the Sbc_Ll_SpiOutBuffer is passed.
        The element identified by dId.
        The caller of Sbc_Ll_InitDevice ensures that dId is smaller than the size of Sbc_Ll_SpiOutBuffer (SBC_NUMBER_OF_DEVICES).
        The length is always 1.
  
SBSW_JUSTIFICATION_END */

/* START_COVERAGE_JUSTIFICATION

\ID COV_SBC_SINGLE_INSTANCE_API
  \ACCEPT TX
  \REASON For that release only single instance API is supported.
  
\ID COV_SBC_SPI_COMPATIBILITY
  \ACCEPT TX
  \REASON This is a compatibility define to manipulate SPI usage by user configuration file, if needed by SPI driver.
    The code is verified by code inspection.
  
\ID COV_SBC_LOCAL_SCOPE
  \ACCEPT TX
  \ACCEPT XF
  \REASON This defines an easier control of the compiler behaviour for functions in local scope.
    The code is verified by code inspection.

\ID COV_SBC_INVALID_PID
  \ACCEPT TX
  \ACCEPT TF tf tf tx
  \REASON The condition checks for invalid configured PID cannot be simulated. The code is verified by code inspection.

\ID COV_SBC_WDG_CANSETMODE
  \ACCEPT TX
  \REASON Some watchdog support all Wdg Modes (OFF, SLOW and FAST). So all Mode switches are supported. Invalid Mode values are blocked with DET check.
    The code is verified by code inspection.

\ID COV_SBC_LL_EVENTS
  \ACCEPT XF
  \ACCEPT TX
  \ACCEPT X
  \REASON The condition checks for hardware failures that cannot be simulated. The code is verified by code inspection.


END_COVERAGE_JUSTIFICATION */ 

/* ********************************************************************************************************************
 *  END OF FILE: Sbc.c
 * *******************************************************************************************************************/
