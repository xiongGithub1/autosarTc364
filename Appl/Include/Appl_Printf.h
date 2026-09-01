/**********************************************************************************************************************
 * Appl_Printf.h
 *
 * printf() retarget for ASCLIN0 (Uart channel 0, P15.2 TX).
 * - io_putchar() feeds a TX ring (Tasking C library hook).
 * - Appl_Printf_MainFunction() drains the ring via async Uart_Write (Core0 only).
 *
 * Baud rate: configure in DaVinci Uart module, then regenerate GenData.
 **********************************************************************************************************************/
#ifndef APPL_PRINTF_H
#define APPL_PRINTF_H

#include "Std_Types.h"

#ifndef APPL_PRINTF_ENABLE
#define APPL_PRINTF_ENABLE  STD_ON
#endif

#if (APPL_PRINTF_ENABLE == STD_ON)

void Appl_Printf_Init(void);
void Appl_Printf_MainFunction(void);

extern volatile uint32 Appl_Printf_TxOkCount;
extern volatile uint32 Appl_Printf_TxDropCount;
extern volatile uint32 Appl_Printf_TxBusyCount;

#else

#define Appl_Printf_Init()              ((void)0)
#define Appl_Printf_MainFunction()      ((void)0)

#endif /* APPL_PRINTF_ENABLE */

#endif /* APPL_PRINTF_H */
