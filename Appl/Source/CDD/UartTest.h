/**********************************************************************************************************************
 *  FILE: UartTest.h
 *  DESC: VOFA+ JustFloat telemetry on ASCLIN0 (P15.2 TX). Send from Core0 only.
 *********************************************************************************************************************/
#ifndef UARTTEST_H
#define UARTTEST_H

#include "Std_Types.h"

extern void UartTest_Init(void);
extern void UartTest_CaptureFromFoc(void);
extern void UartTest_MainFunction(void);

extern volatile uint32 UartTest_TxOkCount;
extern volatile uint32 UartTest_TxBusyCount;
extern volatile uint32 UartTest_TxFailCount;
extern volatile uint32 UartTest_AbortRecoverCount;
extern volatile uint32 UartTest_LastStatus;
extern volatile uint32 UartTest_CaptureCount;
extern volatile uint32 UartTest_DropCount;

#endif /* UARTTEST_H */
