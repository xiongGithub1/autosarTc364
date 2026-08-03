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
 *            Module: Os
 *           Program: MSR_Vector_SLP4
 *          Customer: China Lithium Battery Technology Co., Ltd.
 *       Expiry Date: 2025-08-26
 *  Ordered Derivat.: SAK-TC387QP-160F300S AE
 *    License Scope : The usage is restricted to CBD2200508_D00
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: Os_Hal_Entry_Lcfg.c
 *   Generation Time: 2024-08-03 19:52:21
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

/* PRQA S 0777, 0779, 0828 EOF */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2, MD_MSR_Dir1.1 */

#define OS_HAL_ENTRY_LCFG_SOURCE

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

/* AUTOSAR includes */
#include "Std_Types.h"

/* Os module declarations */
#include "Os_Hal_Entry_Cfg.h"
#include "Os_Hal_Entry_Lcfg.h"
#include "Os_Hal_Entry.h"

/* Os kernel module dependencies */
#include "Os_Isr_Lcfg.h"
#include "Os.h"

/* Os hal dependencies */
#include "Os_Hal_Cfg.h"
#include "Os_Hal_Core_Lcfg.h"
#include "Os_Hal_Interrupt_Cfg.h"
#include "Os_Hal_Trap.h"


/**********************************************************************************************************************
 *  LOCAL CONSTANT MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTION MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL DATA PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL CONSTANT DATA
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  EXCEPTION VECTOR TABLE CORE 0
 *********************************************************************************************************************/


#define OS_START_SEC_EXCVEC_CORE0_CODE
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

Os_Hal_ExceptionSectionDeclaration(0)
Os_Hal_UnhandledTrapEntry(0, 0)
Os_Hal_UnhandledTrapEntry(0, 1)
Os_Hal_UnhandledTrapEntry(0, 2)
Os_Hal_UnhandledTrapEntry(0, 3)
Os_Hal_UnhandledTrapEntry(0, 4)
Os_Hal_UnhandledTrapEntry(0, 5)
Os_Hal_UnhandledTrapEntry(0, 6)
Os_Hal_UnhandledTrapEntry(0, 7)

#define OS_STOP_SEC_EXCVEC_CORE0_CODE
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */



/**********************************************************************************************************************
 *  INTERRUPT VECTOR TABLE CORE 0
 *********************************************************************************************************************/


#define OS_START_SEC_INTVEC_CORE0_CODE
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

Os_Hal_InterruptSectionDeclaration(0)
Os_Hal_UnhandledInterruptEntry(0, 0) 
Os_Hal_UnhandledInterruptEntry(0, 1) 
Os_Hal_UnhandledInterruptEntry(0, 2) 
Os_Hal_UnhandledInterruptEntry(0, 3) 
Os_Hal_UnhandledInterruptEntry(0, 4) 
Os_Hal_UnhandledInterruptEntry(0, 5) 
Os_Hal_UnhandledInterruptEntry(0, 6) 
Os_Hal_UnhandledInterruptEntry(0, 7) 
Os_Hal_UnhandledInterruptEntry(0, 8) 
Os_Hal_UnhandledInterruptEntry(0, 9) 
Os_Hal_UnhandledInterruptEntry(0, 10) 
Os_Hal_UnhandledInterruptEntry(0, 11) 
Os_Hal_UnhandledInterruptEntry(0, 12) 
Os_Hal_UnhandledInterruptEntry(0, 13) 
Os_Hal_UnhandledInterruptEntry(0, 14) 
Os_Hal_UnhandledInterruptEntry(0, 15) 
Os_Hal_UnhandledInterruptEntry(0, 16) 
Os_Hal_UnhandledInterruptEntry(0, 17) 
Os_Hal_UnhandledInterruptEntry(0, 18) 
Os_Hal_UnhandledInterruptEntry(0, 19) 
Os_Hal_UnhandledInterruptEntry(0, 20) 
Os_Hal_UnhandledInterruptEntry(0, 21) 
Os_Hal_UnhandledInterruptEntry(0, 22) 
Os_Hal_UnhandledInterruptEntry(0, 23) 
Os_Hal_UnhandledInterruptEntry(0, 24) 
Os_Hal_UnhandledInterruptEntry(0, 25) 
Os_Hal_UnhandledInterruptEntry(0, 26) 
Os_Hal_UnhandledInterruptEntry(0, 27) 
Os_Hal_UnhandledInterruptEntry(0, 28) 
Os_Hal_UnhandledInterruptEntry(0, 29) 
Os_Hal_UnhandledInterruptEntry(0, 30) 
Os_Hal_UnhandledInterruptEntry(0, 31) 
Os_Hal_UnhandledInterruptEntry(0, 32) 
Os_Hal_UnhandledInterruptEntry(0, 33) 
Os_Hal_UnhandledInterruptEntry(0, 34) 
Os_Hal_UnhandledInterruptEntry(0, 35) 
Os_Hal_UnhandledInterruptEntry(0, 36) 
Os_Hal_UnhandledInterruptEntry(0, 37) 
Os_Hal_UnhandledInterruptEntry(0, 38) 
Os_Hal_UnhandledInterruptEntry(0, 39) 
Os_Hal_UnhandledInterruptEntry(0, 40) 
Os_Hal_UnhandledInterruptEntry(0, 41) 
Os_Hal_UnhandledInterruptEntry(0, 42) 
Os_Hal_UnhandledInterruptEntry(0, 43) 
Os_Hal_UnhandledInterruptEntry(0, 44) 
Os_Hal_UnhandledInterruptEntry(0, 45) 
Os_Hal_UnhandledInterruptEntry(0, 46) 
Os_Hal_UnhandledInterruptEntry(0, 47) 
Os_Hal_UnhandledInterruptEntry(0, 48) 
Os_Hal_UnhandledInterruptEntry(0, 49) 
Os_Hal_UnhandledInterruptEntry(0, 50) 
Os_Hal_UnhandledInterruptEntry(0, 51) 
Os_Hal_UnhandledInterruptEntry(0, 52) 
Os_Hal_UnhandledInterruptEntry(0, 53) 
Os_Hal_UnhandledInterruptEntry(0, 54) 
Os_Hal_UnhandledInterruptEntry(0, 55) 
Os_Hal_UnhandledInterruptEntry(0, 56) 
Os_Hal_UnhandledInterruptEntry(0, 57) 
Os_Hal_UnhandledInterruptEntry(0, 58) 
Os_Hal_UnhandledInterruptEntry(0, 59) 
Os_Hal_Cat2InterruptEntry(0, 60, OS_CFG_HAL_ISR2_DISABLE_LEVEL, OsCfg_Isr_CanIsr_0)
Os_Hal_UnhandledInterruptEntry(0, 61) 
Os_Hal_UnhandledInterruptEntry(0, 62) 
Os_Hal_UnhandledInterruptEntry(0, 63) 
Os_Hal_UnhandledInterruptEntry(0, 64) 
Os_Hal_UnhandledInterruptEntry(0, 65) 
Os_Hal_UnhandledInterruptEntry(0, 66) 
Os_Hal_UnhandledInterruptEntry(0, 67) 
Os_Hal_UnhandledInterruptEntry(0, 68) 
Os_Hal_UnhandledInterruptEntry(0, 69) 
Os_Hal_Cat2InterruptEntry(0, 70, OS_CFG_HAL_ISR2_DISABLE_LEVEL, OsCfg_Isr_XSignalIsr_OsCore0)
Os_Hal_UnhandledInterruptEntry(0, 71) 
Os_Hal_UnhandledInterruptEntry(0, 72) 
Os_Hal_UnhandledInterruptEntry(0, 73) 
Os_Hal_UnhandledInterruptEntry(0, 74) 
Os_Hal_UnhandledInterruptEntry(0, 75) 
Os_Hal_UnhandledInterruptEntry(0, 76) 
Os_Hal_UnhandledInterruptEntry(0, 77) 
Os_Hal_Cat2InterruptEntry(0, 78, OS_CFG_HAL_ISR2_DISABLE_LEVEL, OsCfg_Isr_AdcIsr_G8)
Os_Hal_UnhandledInterruptEntry(0, 79) 
Os_Hal_Cat2InterruptEntry(0, 80, OS_CFG_HAL_ISR2_DISABLE_LEVEL, OsCfg_Isr_CounterIsr_SystemTimer)
Os_Hal_UnhandledInterruptEntry(0, 81) 
Os_Hal_UnhandledInterruptEntry(0, 82) 
Os_Hal_UnhandledInterruptEntry(0, 83) 
Os_Hal_UnhandledInterruptEntry(0, 84) 
Os_Hal_UnhandledInterruptEntry(0, 85) 
Os_Hal_UnhandledInterruptEntry(0, 86) 
Os_Hal_UnhandledInterruptEntry(0, 87) 
Os_Hal_UnhandledInterruptEntry(0, 88) 
Os_Hal_UnhandledInterruptEntry(0, 89) 
Os_Hal_UnhandledInterruptEntry(0, 90) 
Os_Hal_UnhandledInterruptEntry(0, 91) 
Os_Hal_UnhandledInterruptEntry(0, 92) 
Os_Hal_UnhandledInterruptEntry(0, 93) 
Os_Hal_UnhandledInterruptEntry(0, 94) 
Os_Hal_UnhandledInterruptEntry(0, 95) 
Os_Hal_UnhandledInterruptEntry(0, 96) 
Os_Hal_UnhandledInterruptEntry(0, 97) 
Os_Hal_UnhandledInterruptEntry(0, 98) 
Os_Hal_UnhandledInterruptEntry(0, 99) 
Os_Hal_UnhandledInterruptEntry(0, 100) 
Os_Hal_UnhandledInterruptEntry(0, 101) 
Os_Hal_UnhandledInterruptEntry(0, 102) 
Os_Hal_UnhandledInterruptEntry(0, 103) 
Os_Hal_UnhandledInterruptEntry(0, 104) 
Os_Hal_UnhandledInterruptEntry(0, 105) 
Os_Hal_UnhandledInterruptEntry(0, 106) 
Os_Hal_UnhandledInterruptEntry(0, 107) 
Os_Hal_UnhandledInterruptEntry(0, 108) 
Os_Hal_UnhandledInterruptEntry(0, 109) 
Os_Hal_UnhandledInterruptEntry(0, 110) 
Os_Hal_UnhandledInterruptEntry(0, 111) 
Os_Hal_UnhandledInterruptEntry(0, 112) 
Os_Hal_UnhandledInterruptEntry(0, 113) 
Os_Hal_UnhandledInterruptEntry(0, 114) 
Os_Hal_UnhandledInterruptEntry(0, 115) 
Os_Hal_UnhandledInterruptEntry(0, 116) 
Os_Hal_UnhandledInterruptEntry(0, 117) 
Os_Hal_UnhandledInterruptEntry(0, 118) 
Os_Hal_UnhandledInterruptEntry(0, 119) 
Os_Hal_UnhandledInterruptEntry(0, 120) 
Os_Hal_UnhandledInterruptEntry(0, 121) 
Os_Hal_UnhandledInterruptEntry(0, 122) 
Os_Hal_UnhandledInterruptEntry(0, 123) 
Os_Hal_UnhandledInterruptEntry(0, 124) 
Os_Hal_UnhandledInterruptEntry(0, 125) 
Os_Hal_UnhandledInterruptEntry(0, 126) 
Os_Hal_UnhandledInterruptEntry(0, 127) 
Os_Hal_UnhandledInterruptEntry(0, 128) 
Os_Hal_UnhandledInterruptEntry(0, 129) 
Os_Hal_UnhandledInterruptEntry(0, 130) 
Os_Hal_UnhandledInterruptEntry(0, 131) 
Os_Hal_UnhandledInterruptEntry(0, 132) 
Os_Hal_UnhandledInterruptEntry(0, 133) 
Os_Hal_UnhandledInterruptEntry(0, 134) 
Os_Hal_UnhandledInterruptEntry(0, 135) 
Os_Hal_UnhandledInterruptEntry(0, 136) 
Os_Hal_UnhandledInterruptEntry(0, 137) 
Os_Hal_UnhandledInterruptEntry(0, 138) 
Os_Hal_UnhandledInterruptEntry(0, 139) 
Os_Hal_UnhandledInterruptEntry(0, 140) 
Os_Hal_UnhandledInterruptEntry(0, 141) 
Os_Hal_UnhandledInterruptEntry(0, 142) 
Os_Hal_UnhandledInterruptEntry(0, 143) 
Os_Hal_UnhandledInterruptEntry(0, 144) 
Os_Hal_UnhandledInterruptEntry(0, 145) 
Os_Hal_UnhandledInterruptEntry(0, 146) 
Os_Hal_UnhandledInterruptEntry(0, 147) 
Os_Hal_UnhandledInterruptEntry(0, 148) 
Os_Hal_UnhandledInterruptEntry(0, 149) 
Os_Hal_UnhandledInterruptEntry(0, 150) 
Os_Hal_UnhandledInterruptEntry(0, 151) 
Os_Hal_UnhandledInterruptEntry(0, 152) 
Os_Hal_UnhandledInterruptEntry(0, 153) 
Os_Hal_UnhandledInterruptEntry(0, 154) 
Os_Hal_UnhandledInterruptEntry(0, 155) 
Os_Hal_UnhandledInterruptEntry(0, 156) 
Os_Hal_UnhandledInterruptEntry(0, 157) 
Os_Hal_UnhandledInterruptEntry(0, 158) 
Os_Hal_UnhandledInterruptEntry(0, 159) 
Os_Hal_UnhandledInterruptEntry(0, 160) 
Os_Hal_UnhandledInterruptEntry(0, 161) 
Os_Hal_UnhandledInterruptEntry(0, 162) 
Os_Hal_UnhandledInterruptEntry(0, 163) 
Os_Hal_UnhandledInterruptEntry(0, 164) 
Os_Hal_UnhandledInterruptEntry(0, 165) 
Os_Hal_UnhandledInterruptEntry(0, 166) 
Os_Hal_UnhandledInterruptEntry(0, 167) 
Os_Hal_UnhandledInterruptEntry(0, 168) 
Os_Hal_UnhandledInterruptEntry(0, 169) 
Os_Hal_UnhandledInterruptEntry(0, 170) 
Os_Hal_UnhandledInterruptEntry(0, 171) 
Os_Hal_UnhandledInterruptEntry(0, 172) 
Os_Hal_UnhandledInterruptEntry(0, 173) 
Os_Hal_UnhandledInterruptEntry(0, 174) 
Os_Hal_UnhandledInterruptEntry(0, 175) 
Os_Hal_UnhandledInterruptEntry(0, 176) 
Os_Hal_UnhandledInterruptEntry(0, 177) 
Os_Hal_UnhandledInterruptEntry(0, 178) 
Os_Hal_UnhandledInterruptEntry(0, 179) 
Os_Hal_UnhandledInterruptEntry(0, 180) 
Os_Hal_UnhandledInterruptEntry(0, 181) 
Os_Hal_UnhandledInterruptEntry(0, 182) 
Os_Hal_UnhandledInterruptEntry(0, 183) 
Os_Hal_UnhandledInterruptEntry(0, 184) 
Os_Hal_UnhandledInterruptEntry(0, 185) 
Os_Hal_UnhandledInterruptEntry(0, 186) 
Os_Hal_UnhandledInterruptEntry(0, 187) 
Os_Hal_UnhandledInterruptEntry(0, 188) 
Os_Hal_UnhandledInterruptEntry(0, 189) 
Os_Hal_UnhandledInterruptEntry(0, 190) 
Os_Hal_UnhandledInterruptEntry(0, 191) 
Os_Hal_UnhandledInterruptEntry(0, 192) 
Os_Hal_UnhandledInterruptEntry(0, 193) 
Os_Hal_UnhandledInterruptEntry(0, 194) 
Os_Hal_UnhandledInterruptEntry(0, 195) 
Os_Hal_UnhandledInterruptEntry(0, 196) 
Os_Hal_UnhandledInterruptEntry(0, 197) 
Os_Hal_UnhandledInterruptEntry(0, 198) 
Os_Hal_UnhandledInterruptEntry(0, 199) 
Os_Hal_UnhandledInterruptEntry(0, 200) 
Os_Hal_UnhandledInterruptEntry(0, 201) 
Os_Hal_UnhandledInterruptEntry(0, 202) 
Os_Hal_UnhandledInterruptEntry(0, 203) 
Os_Hal_UnhandledInterruptEntry(0, 204) 
Os_Hal_UnhandledInterruptEntry(0, 205) 
Os_Hal_UnhandledInterruptEntry(0, 206) 
Os_Hal_UnhandledInterruptEntry(0, 207) 
Os_Hal_UnhandledInterruptEntry(0, 208) 
Os_Hal_UnhandledInterruptEntry(0, 209) 
Os_Hal_UnhandledInterruptEntry(0, 210) 
Os_Hal_UnhandledInterruptEntry(0, 211) 
Os_Hal_UnhandledInterruptEntry(0, 212) 
Os_Hal_UnhandledInterruptEntry(0, 213) 
Os_Hal_UnhandledInterruptEntry(0, 214) 
Os_Hal_UnhandledInterruptEntry(0, 215) 
Os_Hal_UnhandledInterruptEntry(0, 216) 
Os_Hal_UnhandledInterruptEntry(0, 217) 
Os_Hal_UnhandledInterruptEntry(0, 218) 
Os_Hal_UnhandledInterruptEntry(0, 219) 
Os_Hal_UnhandledInterruptEntry(0, 220) 
Os_Hal_UnhandledInterruptEntry(0, 221) 
Os_Hal_UnhandledInterruptEntry(0, 222) 
Os_Hal_UnhandledInterruptEntry(0, 223) 
Os_Hal_UnhandledInterruptEntry(0, 224) 
Os_Hal_UnhandledInterruptEntry(0, 225) 
Os_Hal_UnhandledInterruptEntry(0, 226) 
Os_Hal_UnhandledInterruptEntry(0, 227) 
Os_Hal_UnhandledInterruptEntry(0, 228) 
Os_Hal_UnhandledInterruptEntry(0, 229) 
Os_Hal_UnhandledInterruptEntry(0, 230) 
Os_Hal_UnhandledInterruptEntry(0, 231) 
Os_Hal_UnhandledInterruptEntry(0, 232) 
Os_Hal_UnhandledInterruptEntry(0, 233) 
Os_Hal_UnhandledInterruptEntry(0, 234) 
Os_Hal_UnhandledInterruptEntry(0, 235) 
Os_Hal_UnhandledInterruptEntry(0, 236) 
Os_Hal_UnhandledInterruptEntry(0, 237) 
Os_Hal_UnhandledInterruptEntry(0, 238) 
Os_Hal_UnhandledInterruptEntry(0, 239) 
Os_Hal_UnhandledInterruptEntry(0, 240) 
Os_Hal_UnhandledInterruptEntry(0, 241) 
Os_Hal_UnhandledInterruptEntry(0, 242) 
Os_Hal_UnhandledInterruptEntry(0, 243) 
Os_Hal_UnhandledInterruptEntry(0, 244) 
Os_Hal_UnhandledInterruptEntry(0, 245) 
Os_Hal_UnhandledInterruptEntry(0, 246) 
Os_Hal_UnhandledInterruptEntry(0, 247) 
Os_Hal_UnhandledInterruptEntry(0, 248) 
Os_Hal_UnhandledInterruptEntry(0, 249) 
Os_Hal_UnhandledInterruptEntry(0, 250) 
Os_Hal_UnhandledInterruptEntry(0, 251) 
Os_Hal_UnhandledInterruptEntry(0, 252) 
Os_Hal_UnhandledInterruptEntry(0, 253) 
Os_Hal_UnhandledInterruptEntry(0, 254) 
Os_Hal_UnhandledInterruptEntry(0, 255) 

#define OS_STOP_SEC_INTVEC_CORE0_CODE
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


/**********************************************************************************************************************
 *  EXCEPTION VECTOR TABLE CORE 1
 *********************************************************************************************************************/


#define OS_START_SEC_EXCVEC_CORE1_CODE
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

Os_Hal_ExceptionSectionDeclaration(1)
Os_Hal_UnhandledTrapEntry(1, 0)
Os_Hal_UnhandledTrapEntry(1, 1)
Os_Hal_UnhandledTrapEntry(1, 2)
Os_Hal_UnhandledTrapEntry(1, 3)
Os_Hal_UnhandledTrapEntry(1, 4)
Os_Hal_UnhandledTrapEntry(1, 5)
Os_Hal_UnhandledTrapEntry(1, 6)
Os_Hal_UnhandledTrapEntry(1, 7)

#define OS_STOP_SEC_EXCVEC_CORE1_CODE
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */



/**********************************************************************************************************************
 *  INTERRUPT VECTOR TABLE CORE 1
 *********************************************************************************************************************/


#define OS_START_SEC_INTVEC_CORE1_CODE
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

Os_Hal_InterruptSectionDeclaration(1)
Os_Hal_UnhandledInterruptEntry(1, 0) 
Os_Hal_Cat2InterruptEntry(1, 1, OS_CFG_HAL_ISR2_DISABLE_LEVEL, OsCfg_Isr_CounterIsr_SystemTimer1)
Os_Hal_UnhandledInterruptEntry(1, 2) 
Os_Hal_UnhandledInterruptEntry(1, 3) 
Os_Hal_UnhandledInterruptEntry(1, 4) 
Os_Hal_UnhandledInterruptEntry(1, 5) 
Os_Hal_UnhandledInterruptEntry(1, 6) 
Os_Hal_UnhandledInterruptEntry(1, 7) 
Os_Hal_UnhandledInterruptEntry(1, 8) 
Os_Hal_UnhandledInterruptEntry(1, 9) 
Os_Hal_UnhandledInterruptEntry(1, 10) 
Os_Hal_UnhandledInterruptEntry(1, 11) 
Os_Hal_UnhandledInterruptEntry(1, 12) 
Os_Hal_UnhandledInterruptEntry(1, 13) 
Os_Hal_UnhandledInterruptEntry(1, 14) 
Os_Hal_UnhandledInterruptEntry(1, 15) 
Os_Hal_UnhandledInterruptEntry(1, 16) 
Os_Hal_UnhandledInterruptEntry(1, 17) 
Os_Hal_UnhandledInterruptEntry(1, 18) 
Os_Hal_UnhandledInterruptEntry(1, 19) 
Os_Hal_UnhandledInterruptEntry(1, 20) 
Os_Hal_UnhandledInterruptEntry(1, 21) 
Os_Hal_UnhandledInterruptEntry(1, 22) 
Os_Hal_UnhandledInterruptEntry(1, 23) 
Os_Hal_UnhandledInterruptEntry(1, 24) 
Os_Hal_UnhandledInterruptEntry(1, 25) 
Os_Hal_UnhandledInterruptEntry(1, 26) 
Os_Hal_UnhandledInterruptEntry(1, 27) 
Os_Hal_UnhandledInterruptEntry(1, 28) 
Os_Hal_UnhandledInterruptEntry(1, 29) 
Os_Hal_UnhandledInterruptEntry(1, 30) 
Os_Hal_UnhandledInterruptEntry(1, 31) 
Os_Hal_UnhandledInterruptEntry(1, 32) 
Os_Hal_UnhandledInterruptEntry(1, 33) 
Os_Hal_UnhandledInterruptEntry(1, 34) 
Os_Hal_UnhandledInterruptEntry(1, 35) 
Os_Hal_UnhandledInterruptEntry(1, 36) 
Os_Hal_UnhandledInterruptEntry(1, 37) 
Os_Hal_UnhandledInterruptEntry(1, 38) 
Os_Hal_UnhandledInterruptEntry(1, 39) 
Os_Hal_UnhandledInterruptEntry(1, 40) 
Os_Hal_UnhandledInterruptEntry(1, 41) 
Os_Hal_UnhandledInterruptEntry(1, 42) 
Os_Hal_UnhandledInterruptEntry(1, 43) 
Os_Hal_UnhandledInterruptEntry(1, 44) 
Os_Hal_UnhandledInterruptEntry(1, 45) 
Os_Hal_UnhandledInterruptEntry(1, 46) 
Os_Hal_UnhandledInterruptEntry(1, 47) 
Os_Hal_UnhandledInterruptEntry(1, 48) 
Os_Hal_UnhandledInterruptEntry(1, 49) 
Os_Hal_UnhandledInterruptEntry(1, 50) 
Os_Hal_UnhandledInterruptEntry(1, 51) 
Os_Hal_UnhandledInterruptEntry(1, 52) 
Os_Hal_UnhandledInterruptEntry(1, 53) 
Os_Hal_UnhandledInterruptEntry(1, 54) 
Os_Hal_UnhandledInterruptEntry(1, 55) 
Os_Hal_UnhandledInterruptEntry(1, 56) 
Os_Hal_UnhandledInterruptEntry(1, 57) 
Os_Hal_UnhandledInterruptEntry(1, 58) 
Os_Hal_UnhandledInterruptEntry(1, 59) 
Os_Hal_UnhandledInterruptEntry(1, 60) 
Os_Hal_UnhandledInterruptEntry(1, 61) 
Os_Hal_UnhandledInterruptEntry(1, 62) 
Os_Hal_UnhandledInterruptEntry(1, 63) 
Os_Hal_UnhandledInterruptEntry(1, 64) 
Os_Hal_UnhandledInterruptEntry(1, 65) 
Os_Hal_UnhandledInterruptEntry(1, 66) 
Os_Hal_UnhandledInterruptEntry(1, 67) 
Os_Hal_UnhandledInterruptEntry(1, 68) 
Os_Hal_UnhandledInterruptEntry(1, 69) 
Os_Hal_Cat2InterruptEntry(1, 70, OS_CFG_HAL_ISR2_DISABLE_LEVEL, OsCfg_Isr_XSignalIsr_OsCore1)
Os_Hal_UnhandledInterruptEntry(1, 71) 
Os_Hal_UnhandledInterruptEntry(1, 72) 
Os_Hal_UnhandledInterruptEntry(1, 73) 
Os_Hal_UnhandledInterruptEntry(1, 74) 
Os_Hal_UnhandledInterruptEntry(1, 75) 
Os_Hal_UnhandledInterruptEntry(1, 76) 
Os_Hal_UnhandledInterruptEntry(1, 77) 
Os_Hal_UnhandledInterruptEntry(1, 78) 
Os_Hal_UnhandledInterruptEntry(1, 79) 
Os_Hal_UnhandledInterruptEntry(1, 80) 
Os_Hal_UnhandledInterruptEntry(1, 81) 
Os_Hal_UnhandledInterruptEntry(1, 82) 
Os_Hal_Cat1InterruptEntry(1, 83, ADC0SR0_ISR)
Os_Hal_UnhandledInterruptEntry(1, 84) 
Os_Hal_UnhandledInterruptEntry(1, 85) 
Os_Hal_UnhandledInterruptEntry(1, 86) 
Os_Hal_UnhandledInterruptEntry(1, 87) 
Os_Hal_UnhandledInterruptEntry(1, 88) 
Os_Hal_UnhandledInterruptEntry(1, 89) 
Os_Hal_UnhandledInterruptEntry(1, 90) 
Os_Hal_UnhandledInterruptEntry(1, 91) 
Os_Hal_UnhandledInterruptEntry(1, 92) 
Os_Hal_UnhandledInterruptEntry(1, 93) 
Os_Hal_UnhandledInterruptEntry(1, 94) 
Os_Hal_UnhandledInterruptEntry(1, 95) 
Os_Hal_UnhandledInterruptEntry(1, 96) 
Os_Hal_UnhandledInterruptEntry(1, 97) 
Os_Hal_UnhandledInterruptEntry(1, 98) 
Os_Hal_UnhandledInterruptEntry(1, 99) 
Os_Hal_UnhandledInterruptEntry(1, 100) 
Os_Hal_UnhandledInterruptEntry(1, 101) 
Os_Hal_UnhandledInterruptEntry(1, 102) 
Os_Hal_UnhandledInterruptEntry(1, 103) 
Os_Hal_UnhandledInterruptEntry(1, 104) 
Os_Hal_UnhandledInterruptEntry(1, 105) 
Os_Hal_UnhandledInterruptEntry(1, 106) 
Os_Hal_UnhandledInterruptEntry(1, 107) 
Os_Hal_UnhandledInterruptEntry(1, 108) 
Os_Hal_UnhandledInterruptEntry(1, 109) 
Os_Hal_UnhandledInterruptEntry(1, 110) 
Os_Hal_UnhandledInterruptEntry(1, 111) 
Os_Hal_UnhandledInterruptEntry(1, 112) 
Os_Hal_UnhandledInterruptEntry(1, 113) 
Os_Hal_UnhandledInterruptEntry(1, 114) 
Os_Hal_UnhandledInterruptEntry(1, 115) 
Os_Hal_UnhandledInterruptEntry(1, 116) 
Os_Hal_UnhandledInterruptEntry(1, 117) 
Os_Hal_UnhandledInterruptEntry(1, 118) 
Os_Hal_UnhandledInterruptEntry(1, 119) 
Os_Hal_UnhandledInterruptEntry(1, 120) 
Os_Hal_UnhandledInterruptEntry(1, 121) 
Os_Hal_UnhandledInterruptEntry(1, 122) 
Os_Hal_UnhandledInterruptEntry(1, 123) 
Os_Hal_UnhandledInterruptEntry(1, 124) 
Os_Hal_UnhandledInterruptEntry(1, 125) 
Os_Hal_UnhandledInterruptEntry(1, 126) 
Os_Hal_UnhandledInterruptEntry(1, 127) 
Os_Hal_UnhandledInterruptEntry(1, 128) 
Os_Hal_UnhandledInterruptEntry(1, 129) 
Os_Hal_UnhandledInterruptEntry(1, 130) 
Os_Hal_UnhandledInterruptEntry(1, 131) 
Os_Hal_UnhandledInterruptEntry(1, 132) 
Os_Hal_UnhandledInterruptEntry(1, 133) 
Os_Hal_UnhandledInterruptEntry(1, 134) 
Os_Hal_UnhandledInterruptEntry(1, 135) 
Os_Hal_UnhandledInterruptEntry(1, 136) 
Os_Hal_UnhandledInterruptEntry(1, 137) 
Os_Hal_UnhandledInterruptEntry(1, 138) 
Os_Hal_UnhandledInterruptEntry(1, 139) 
Os_Hal_UnhandledInterruptEntry(1, 140) 
Os_Hal_UnhandledInterruptEntry(1, 141) 
Os_Hal_UnhandledInterruptEntry(1, 142) 
Os_Hal_UnhandledInterruptEntry(1, 143) 
Os_Hal_UnhandledInterruptEntry(1, 144) 
Os_Hal_UnhandledInterruptEntry(1, 145) 
Os_Hal_UnhandledInterruptEntry(1, 146) 
Os_Hal_UnhandledInterruptEntry(1, 147) 
Os_Hal_UnhandledInterruptEntry(1, 148) 
Os_Hal_UnhandledInterruptEntry(1, 149) 
Os_Hal_UnhandledInterruptEntry(1, 150) 
Os_Hal_UnhandledInterruptEntry(1, 151) 
Os_Hal_UnhandledInterruptEntry(1, 152) 
Os_Hal_UnhandledInterruptEntry(1, 153) 
Os_Hal_UnhandledInterruptEntry(1, 154) 
Os_Hal_UnhandledInterruptEntry(1, 155) 
Os_Hal_UnhandledInterruptEntry(1, 156) 
Os_Hal_UnhandledInterruptEntry(1, 157) 
Os_Hal_UnhandledInterruptEntry(1, 158) 
Os_Hal_UnhandledInterruptEntry(1, 159) 
Os_Hal_UnhandledInterruptEntry(1, 160) 
Os_Hal_UnhandledInterruptEntry(1, 161) 
Os_Hal_UnhandledInterruptEntry(1, 162) 
Os_Hal_UnhandledInterruptEntry(1, 163) 
Os_Hal_UnhandledInterruptEntry(1, 164) 
Os_Hal_UnhandledInterruptEntry(1, 165) 
Os_Hal_UnhandledInterruptEntry(1, 166) 
Os_Hal_UnhandledInterruptEntry(1, 167) 
Os_Hal_UnhandledInterruptEntry(1, 168) 
Os_Hal_UnhandledInterruptEntry(1, 169) 
Os_Hal_UnhandledInterruptEntry(1, 170) 
Os_Hal_UnhandledInterruptEntry(1, 171) 
Os_Hal_UnhandledInterruptEntry(1, 172) 
Os_Hal_UnhandledInterruptEntry(1, 173) 
Os_Hal_UnhandledInterruptEntry(1, 174) 
Os_Hal_UnhandledInterruptEntry(1, 175) 
Os_Hal_UnhandledInterruptEntry(1, 176) 
Os_Hal_UnhandledInterruptEntry(1, 177) 
Os_Hal_UnhandledInterruptEntry(1, 178) 
Os_Hal_UnhandledInterruptEntry(1, 179) 
Os_Hal_UnhandledInterruptEntry(1, 180) 
Os_Hal_UnhandledInterruptEntry(1, 181) 
Os_Hal_UnhandledInterruptEntry(1, 182) 
Os_Hal_UnhandledInterruptEntry(1, 183) 
Os_Hal_UnhandledInterruptEntry(1, 184) 
Os_Hal_UnhandledInterruptEntry(1, 185) 
Os_Hal_UnhandledInterruptEntry(1, 186) 
Os_Hal_UnhandledInterruptEntry(1, 187) 
Os_Hal_UnhandledInterruptEntry(1, 188) 
Os_Hal_UnhandledInterruptEntry(1, 189) 
Os_Hal_UnhandledInterruptEntry(1, 190) 
Os_Hal_UnhandledInterruptEntry(1, 191) 
Os_Hal_UnhandledInterruptEntry(1, 192) 
Os_Hal_UnhandledInterruptEntry(1, 193) 
Os_Hal_UnhandledInterruptEntry(1, 194) 
Os_Hal_UnhandledInterruptEntry(1, 195) 
Os_Hal_UnhandledInterruptEntry(1, 196) 
Os_Hal_UnhandledInterruptEntry(1, 197) 
Os_Hal_UnhandledInterruptEntry(1, 198) 
Os_Hal_UnhandledInterruptEntry(1, 199) 
Os_Hal_UnhandledInterruptEntry(1, 200) 
Os_Hal_UnhandledInterruptEntry(1, 201) 
Os_Hal_UnhandledInterruptEntry(1, 202) 
Os_Hal_UnhandledInterruptEntry(1, 203) 
Os_Hal_UnhandledInterruptEntry(1, 204) 
Os_Hal_UnhandledInterruptEntry(1, 205) 
Os_Hal_UnhandledInterruptEntry(1, 206) 
Os_Hal_UnhandledInterruptEntry(1, 207) 
Os_Hal_UnhandledInterruptEntry(1, 208) 
Os_Hal_UnhandledInterruptEntry(1, 209) 
Os_Hal_UnhandledInterruptEntry(1, 210) 
Os_Hal_UnhandledInterruptEntry(1, 211) 
Os_Hal_UnhandledInterruptEntry(1, 212) 
Os_Hal_UnhandledInterruptEntry(1, 213) 
Os_Hal_UnhandledInterruptEntry(1, 214) 
Os_Hal_UnhandledInterruptEntry(1, 215) 
Os_Hal_UnhandledInterruptEntry(1, 216) 
Os_Hal_UnhandledInterruptEntry(1, 217) 
Os_Hal_UnhandledInterruptEntry(1, 218) 
Os_Hal_UnhandledInterruptEntry(1, 219) 
Os_Hal_UnhandledInterruptEntry(1, 220) 
Os_Hal_UnhandledInterruptEntry(1, 221) 
Os_Hal_UnhandledInterruptEntry(1, 222) 
Os_Hal_UnhandledInterruptEntry(1, 223) 
Os_Hal_UnhandledInterruptEntry(1, 224) 
Os_Hal_UnhandledInterruptEntry(1, 225) 
Os_Hal_UnhandledInterruptEntry(1, 226) 
Os_Hal_UnhandledInterruptEntry(1, 227) 
Os_Hal_UnhandledInterruptEntry(1, 228) 
Os_Hal_UnhandledInterruptEntry(1, 229) 
Os_Hal_UnhandledInterruptEntry(1, 230) 
Os_Hal_UnhandledInterruptEntry(1, 231) 
Os_Hal_UnhandledInterruptEntry(1, 232) 
Os_Hal_UnhandledInterruptEntry(1, 233) 
Os_Hal_UnhandledInterruptEntry(1, 234) 
Os_Hal_UnhandledInterruptEntry(1, 235) 
Os_Hal_UnhandledInterruptEntry(1, 236) 
Os_Hal_UnhandledInterruptEntry(1, 237) 
Os_Hal_UnhandledInterruptEntry(1, 238) 
Os_Hal_UnhandledInterruptEntry(1, 239) 
Os_Hal_UnhandledInterruptEntry(1, 240) 
Os_Hal_UnhandledInterruptEntry(1, 241) 
Os_Hal_UnhandledInterruptEntry(1, 242) 
Os_Hal_UnhandledInterruptEntry(1, 243) 
Os_Hal_UnhandledInterruptEntry(1, 244) 
Os_Hal_UnhandledInterruptEntry(1, 245) 
Os_Hal_UnhandledInterruptEntry(1, 246) 
Os_Hal_UnhandledInterruptEntry(1, 247) 
Os_Hal_UnhandledInterruptEntry(1, 248) 
Os_Hal_UnhandledInterruptEntry(1, 249) 
Os_Hal_UnhandledInterruptEntry(1, 250) 
Os_Hal_UnhandledInterruptEntry(1, 251) 
Os_Hal_UnhandledInterruptEntry(1, 252) 
Os_Hal_UnhandledInterruptEntry(1, 253) 
Os_Hal_UnhandledInterruptEntry(1, 254) 
Os_Hal_UnhandledInterruptEntry(1, 255) 

#define OS_STOP_SEC_INTVEC_CORE1_CODE
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


/**********************************************************************************************************************
 *  END OF FILE: Os_Hal_Entry_Lcfg.c
 *********************************************************************************************************************/
