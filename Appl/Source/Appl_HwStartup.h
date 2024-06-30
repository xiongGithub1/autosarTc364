/**********************************************************************************************************************
 *  Appl_HwStartup.h
 *
 *  Low-level hardware initialization for TC364 (AURIX2G), modeled after Infineon Mcal.c startup on TC234.
 *  Called from main() before Os_InitMemory / Os_Init / EcuM_Init.
 **********************************************************************************************************************/

#ifndef APPL_HWSTARTUP_H
#define APPL_HWSTARTUP_H

#include "Std_Types.h"

extern void Appl_HwStartup_Init(void);

#endif /* APPL_HWSTARTUP_H */
