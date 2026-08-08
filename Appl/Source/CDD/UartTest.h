/**********************************************************************************************************************
 *  FILE: UartTest.h
 *  DESC: ASCLIN0 UART send test (115200 8N1, P15.2 TX / P15.3 RX)
 *********************************************************************************************************************/
#ifndef UARTTEST_H
#define UARTTEST_H

#include "Std_Types.h"

extern void UartTest_Init(void);
extern void UartTest_MainFunction(void);

/* Debug counters (visible in debugger / future XCP) */
extern volatile uint32 UartTest_TxOkCount;
extern volatile uint32 UartTest_TxBusyCount;
extern volatile uint32 UartTest_TxFailCount;
extern volatile uint32 UartTest_AbortRecoverCount;
extern volatile uint32 UartTest_LastStatus;

#endif /* UARTTEST_H */
