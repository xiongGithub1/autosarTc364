/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *
 *                This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vector Informatik GmbH.
 *  \endverbatim
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *             File:  E2EXf_LCfg.h
 *           Config:  last364.dpa
 *      ECU-Project:  last364
 *
 *        Generator:  MICROSAR E2EXf Generator Version 1.16.0
 *                    RTE Core Version 1.29.0
 *          License:  CBD2200508
 *
 *      Description:  MICROSAR E2EXf header file for link-time variant
 *********************************************************************************************************************/

/* double include prevention */
#ifndef E2EXF_LCFG_H
# define E2EXF_LCFG_H

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

# include "SchM_E2EXf_Type.h"
# define E2EXF_LEGACY_STATEMACHINE (STD_OFF)

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

/* Version identification */
# define E2EXF_CFG_MAJOR_VERSION   (0x01U)
# define E2EXF_CFG_MINOR_VERSION   (0x0fU)

# define E2EXF_VERSION_INFO_API    (STD_OFF)

# define E2EXF_DEV_ERROR_DETECT    (STD_ON)
# define E2EXF_DEV_ERROR_REPORT    (STD_ON)

# define E2EXF_P01_ENABLED         (STD_OFF)
# define E2EXF_P02_ENABLED         (STD_OFF)
# define E2EXF_P04_ENABLED         (STD_OFF)
# define E2EXF_P05_ENABLED         (STD_OFF)
# define E2EXF_P06_ENABLED         (STD_OFF)
# define E2EXF_P07_ENABLED         (STD_OFF)
# define E2EXF_P08_ENABLED         (STD_OFF)
# define E2EXF_P11_ENABLED         (STD_OFF)
# define E2EXF_P22_ENABLED         (STD_OFF)
# define E2EXF_P44_ENABLED         (STD_OFF)

# define E2EXF_OUTOFPLACE_ENABLED  (STD_OFF)

/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/

#ifndef E2EXF_DUMMY_STATEMENT
# define E2EXF_DUMMY_STATEMENT(v)
#endif
#ifndef E2EXF_DUMMY_STATEMENT_CONST
# define E2EXF_DUMMY_STATEMENT_CONST(v)
#endif


/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

typedef struct {
    boolean inPlace;
    boolean executeDespiteDataUnavailability;
    boolean profileBehavior;
    boolean disableEndToEndCheck;
    uint32 headerLength;
    uint32 upperHeaderBitsToShift;
} E2EXf_OptionsType;

typedef struct
{
    /* postbuild not yet supported */
    uint8 E2EXf_dummy;
} E2EXf_ConfigType;

/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

# define E2EXF_START_SEC_CODE
# include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  E2EXf_Init_Calls
 *********************************************************************************************************************/
/*! \brief       State structures initialization function
 *  \details     This function initializes all state structures managed by E2EXf.
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(void, E2EXF_CODE) E2EXf_Init_Calls(void);

# define E2EXF_STOP_SEC_CODE
# include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#endif /* E2EXF_LCFG_H */
