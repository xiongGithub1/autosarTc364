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
 *             File:  SchM_Sbc_30_Tlf35584.h
 *           Config:  last364.dpa
 *      ECU-Project:  last364
 *
 *        Generator:  MICROSAR RTE Generator Version 4.29.0
 *                    RTE Core Version 1.29.0
 *          License:  CBD2200508
 *
 *      Description:  Header of BSW Scheduler for BSW Module <Sbc_30_Tlf35584>
 *********************************************************************************************************************/
#ifndef SCHM_SBC_30_TLF35584_H
# define SCHM_SBC_30_TLF35584_H

# ifdef __cplusplus
extern "C" {
# endif  /* __cplusplus */

# include "SchM_Sbc_30_Tlf35584_Type.h"

# include "Os.h" /* PRQA S 0828, 0883 */ /* MD_MSR_Dir1.1, MD_Rte_Os */

# define SchM_Enter_Sbc_30_Tlf35584_SBC_EXCLUSIVE_AREA_0() SuspendOSInterrupts()  /* RteAnalyzer(ExclusiveArea, OS_INTERRUPT_BLOCKING) */

# define SchM_Exit_Sbc_30_Tlf35584_SBC_EXCLUSIVE_AREA_0() ResumeOSInterrupts()  /* RteAnalyzer(ExclusiveArea, OS_INTERRUPT_BLOCKING) */

# define SchM_Enter_Sbc_30_Tlf35584_SBC_EXCLUSIVE_AREA_1() SuspendOSInterrupts()  /* RteAnalyzer(ExclusiveArea, OS_INTERRUPT_BLOCKING) */

# define SchM_Exit_Sbc_30_Tlf35584_SBC_EXCLUSIVE_AREA_1() ResumeOSInterrupts()  /* RteAnalyzer(ExclusiveArea, OS_INTERRUPT_BLOCKING) */

# define SchM_Enter_Sbc_30_Tlf35584_SBC_EXCLUSIVE_AREA_2() SuspendOSInterrupts()  /* RteAnalyzer(ExclusiveArea, OS_INTERRUPT_BLOCKING) */

# define SchM_Exit_Sbc_30_Tlf35584_SBC_EXCLUSIVE_AREA_2() ResumeOSInterrupts()  /* RteAnalyzer(ExclusiveArea, OS_INTERRUPT_BLOCKING) */

# define SchM_Enter_Sbc_30_Tlf35584_SBC_EXCLUSIVE_AREA_3() SuspendOSInterrupts()  /* RteAnalyzer(ExclusiveArea, OS_INTERRUPT_BLOCKING) */

# define SchM_Exit_Sbc_30_Tlf35584_SBC_EXCLUSIVE_AREA_3() ResumeOSInterrupts()  /* RteAnalyzer(ExclusiveArea, OS_INTERRUPT_BLOCKING) */

# define SchM_Enter_Sbc_30_Tlf35584_SBC_EXCLUSIVE_AREA_4() SuspendOSInterrupts()  /* RteAnalyzer(ExclusiveArea, OS_INTERRUPT_BLOCKING) */

# define SchM_Exit_Sbc_30_Tlf35584_SBC_EXCLUSIVE_AREA_4() ResumeOSInterrupts()  /* RteAnalyzer(ExclusiveArea, OS_INTERRUPT_BLOCKING) */


# ifdef __cplusplus
} /* extern "C" */
# endif  /* __cplusplus */

#endif /* SCHM_SBC_30_TLF35584_H */

/**********************************************************************************************************************
 MISRA 2012 violations and justifications
 *********************************************************************************************************************/

/* module specific MISRA deviations:
   MD_Rte_Os:
     Reason:     This justification is used as summary justification for all deviations caused by the MICROSAR OS
                 which is for testing of the RTE. Those deviations are no issues in the RTE code.
     Risk:       No functional risk.
     Prevention: Not required.

*/
