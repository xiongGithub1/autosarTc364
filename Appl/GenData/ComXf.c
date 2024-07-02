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
 *             File:  ComXf.c
 *           Config:  last364.dpa
 *      ECU-Project:  last364
 *
 *        Generator:  MICROSAR ComXf Generator Version 1.21.0
 *                    RTE Core Version 1.29.0
 *          License:  CBD2200508
 *
 *      Description:  MICROSAR ComXf implementation file
 *********************************************************************************************************************/

/* PRQA S 0777, 0779, 0715, 0857 EOF */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2, MD_MSR_Dir1.1, MD_MSR_Dir1.1 */

#include "ComXf.h" /* PRQA S 0828, 0810 */ /* MD_MSR_Dir1.1, MD_MSR_Dir1.1 */

/**********************************************************************************************************************
 *  LOCAL FUNCTION MACROS
 *********************************************************************************************************************/

#if !defined(COMXF_LOCAL_INLINE)
# define COMXF_LOCAL_INLINE LOCAL_INLINE
#endif

#ifndef COMXF_DUMMY_STATEMENT
# define COMXF_DUMMY_STATEMENT(v)
#endif
#ifndef COMXF_DUMMY_STATEMENT_CONST
# define COMXF_DUMMY_STATEMENT_CONST(v)
#endif

#define COMXF_START_SEC_CODE
#include "ComXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

COMXF_LOCAL_INLINE FUNC(void, COMXF_CODE) ComXf_Copy16Bit(P2VAR(uint8, AUTOMATIC, COMXF_APPL_VAR) dst, P2CONST(uint8, AUTOMATIC, COMXF_APPL_DATA) src);

COMXF_LOCAL_INLINE FUNC(void, COMXF_CODE) ComXf_Copy32Bit(P2VAR(uint8, AUTOMATIC, COMXF_APPL_VAR) dst, P2CONST(uint8, AUTOMATIC, COMXF_APPL_DATA) src);

COMXF_LOCAL_INLINE FUNC(void, COMXF_CODE) ComXf_Copy64Bit(P2VAR(uint8, AUTOMATIC, COMXF_APPL_VAR) dst, P2CONST(uint8, AUTOMATIC, COMXF_APPL_DATA) src);

COMXF_LOCAL_INLINE FUNC(void, COMXF_CODE) ComXf_Copy16BitEndConv(P2VAR(uint8, AUTOMATIC, COMXF_APPL_VAR) dst, P2CONST(uint8, AUTOMATIC, COMXF_APPL_DATA) src);

COMXF_LOCAL_INLINE FUNC(void, COMXF_CODE) ComXf_Copy32BitEndConv(P2VAR(uint8, AUTOMATIC, COMXF_APPL_VAR) dst, P2CONST(uint8, AUTOMATIC, COMXF_APPL_DATA) src);

COMXF_LOCAL_INLINE FUNC(void, COMXF_CODE) ComXf_Copy64BitEndConv(P2VAR(uint8, AUTOMATIC, COMXF_APPL_VAR) dst, P2CONST(uint8, AUTOMATIC, COMXF_APPL_DATA) src);

/**********************************************************************************************************************
 * ComXf Init/DeInit API
 *********************************************************************************************************************/

FUNC(void, COMXF_CODE) ComXf_Init(P2CONST(ComXf_ConfigType, AUTOMATIC, COMXF_APPL_DATA) config) /* PRQA S 3206 */ /* MD_ComXf_3206 */
{
  COMXF_DUMMY_STATEMENT(config); /* PRQA S 1338, 2983 */ /* MD_MSR_DummyStmt, MD_MSR_DummyStmt */
}

FUNC(void, COMXF_CODE) ComXf_DeInit(void)
{
}

#define COMXF_STOP_SEC_CODE
#include "ComXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 MISRA 2012 violations and justifications
 *********************************************************************************************************************/

/* module specific MISRA deviations:
   MD_ComXf_3206:  MISRA rule: Rule2.7
     Reason:       The parameters are not used by the code in all possible code variants.
     Risk:         No functional risk.
     Prevention:   Not required.

*/
