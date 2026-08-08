/**********************************************************************************************************************
 *  FILE: UartTest.c
 *  DESC: Periodic UART test frame on ASCLIN0 (Uart channel 0).
 *        Call UartTest_Init() once after BswM Uart_Init(), then UartTest_MainFunction() cyclically.
 *********************************************************************************************************************/
#include "UartTest.h"
#include "Uart.h"

#define UARTTEST_CHANNEL              (0U)
#define UARTTEST_TX_BUF_SIZE          (48U)

#define UARTTEST_MSG_PREFIX           "TC364 UART test #"
#define UARTTEST_MSG_SUFFIX           "\r\n"

volatile uint32 UartTest_TxOkCount = 0U;
volatile uint32 UartTest_TxBusyCount = 0U;
volatile uint32 UartTest_TxFailCount = 0U;
volatile uint32 UartTest_AbortRecoverCount = 0U;
volatile uint32 UartTest_LastStatus = 0U;

static Uart_MemType UartTest_TxBuf[UARTTEST_TX_BUF_SIZE];
static uint32 UartTest_Sequence = 0U;
static uint32 UartTest_BusyStreak = 0U;

#define UARTTEST_BUSY_ABORT_THRESHOLD   (2U)

static uint8 UartTest_AppendU32Dec(Uart_MemType *const buf, uint8 pos, uint32 value)
{
  Uart_MemType tmp[10];
  uint8 len = 0U;
  uint8 i;

  if (value == 0U)
  {
    buf[pos] = (Uart_MemType)'0';
    return (uint8)(pos + 1U);
  }

  while (value > 0U)
  {
    tmp[len] = (Uart_MemType)((value % 10U) + (uint32)'0');
    value /= 10U;
    len++;
  }

  for (i = 0U; i < len; i++)
  {
    buf[pos + i] = tmp[(len - 1U) - i];
  }

  return (uint8)(pos + len);
}

static void UartTest_AppendString(Uart_MemType *const buf, uint8 *pos, const char *str)
{
  while ((*str != '\0') && (*pos < UARTTEST_TX_BUF_SIZE))
  {
    buf[*pos] = (Uart_MemType)(*str);
    (*pos)++;
    str++;
  }
}

static Uart_SizeType UartTest_BuildTxMessage(uint32 seq)
{
  const char *prefix = UARTTEST_MSG_PREFIX;
  const char *suffix = UARTTEST_MSG_SUFFIX;
  uint8 pos = 0U;

  UartTest_AppendString(UartTest_TxBuf, &pos, prefix);
  pos = UartTest_AppendU32Dec(UartTest_TxBuf, pos, seq);
  UartTest_AppendString(UartTest_TxBuf, &pos, suffix);

  return (Uart_SizeType)pos;
}

void UartTest_Init(void)
{
  UartTest_Sequence = 0U;
  UartTest_BusyStreak = 0U;
}

void UartTest_MainFunction(void)
{
  Uart_ReturnType retVal;
  Uart_SizeType txLen;
  Uart_StatusType status;

  status = Uart_GetStatus(UARTTEST_CHANNEL);
  UartTest_LastStatus = (uint32)status;

  if (status != UART_IDLE)
  {
    UartTest_TxBusyCount++;
    UartTest_BusyStreak++;

    /* Workaround: TX complete is handled in ASCLIN0ERR_ISR; if ERR IRQ is disabled
       the driver stays BUSY_TRANSMIT forever. Abort to allow next frame. */
    if (UartTest_BusyStreak >= UARTTEST_BUSY_ABORT_THRESHOLD)
    {
      (void)Uart_AbortWrite(UARTTEST_CHANNEL);
      UartTest_AbortRecoverCount++;
      UartTest_BusyStreak = 0U;
    }
    return;
  }

  UartTest_BusyStreak = 0U;

  txLen = UartTest_BuildTxMessage(UartTest_Sequence);
  UartTest_Sequence++;

  retVal = Uart_Write(UARTTEST_CHANNEL, UartTest_TxBuf, txLen);
  if (retVal == UART_E_OK)
  {
    UartTest_TxOkCount++;
  }
  else if (retVal == UART_E_BUSY)
  {
    UartTest_TxBusyCount++;
  }
  else
  {
    UartTest_TxFailCount++;
  }
}
