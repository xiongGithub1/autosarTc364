/**********************************************************************************************************************
 * Appl_Printf.c
 *
 * Non-blocking printf over MCAL Uart (ASCLIN0 / channel 0).
 * Call Appl_Printf_MainFunction() periodically from Core0 (e.g. 1 ms task).
 **********************************************************************************************************************/
#include "Appl_Printf.h"

#if (APPL_PRINTF_ENABLE == STD_ON)

#include <stdio.h>
#include "Uart.h"

#ifndef APPL_PRINTF_UART_CHANNEL
#define APPL_PRINTF_UART_CHANNEL      (0U)
#endif

#ifndef APPL_PRINTF_TX_RING_SIZE
#define APPL_PRINTF_TX_RING_SIZE      (512U)
#endif

#ifndef APPL_PRINTF_TX_CHUNK_SIZE
#define APPL_PRINTF_TX_CHUNK_SIZE     (128U)
#endif

static uint8 Appl_Printf_TxRing[APPL_PRINTF_TX_RING_SIZE];
static volatile uint16 Appl_Printf_RingHead;
static volatile uint16 Appl_Printf_RingTail;
static uint8 Appl_Printf_TxChunk[APPL_PRINTF_TX_CHUNK_SIZE];

volatile uint32 Appl_Printf_TxOkCount;
volatile uint32 Appl_Printf_TxDropCount;
volatile uint32 Appl_Printf_TxBusyCount;

static uint16 Appl_Printf_RingUsed(void)
{
  uint16 head;
  uint16 tail;

  head = Appl_Printf_RingHead;
  tail = Appl_Printf_RingTail;

  if (head >= tail)
  {
    return (uint16)(head - tail);
  }

  return (uint16)(APPL_PRINTF_TX_RING_SIZE - tail + head);
}

static boolean Appl_Printf_RingPush(const uint8 byte)
{
  uint16 head;
  uint16 next;

  head = Appl_Printf_RingHead;
  next = (uint16)((head + 1U) % APPL_PRINTF_TX_RING_SIZE);

  if (next == Appl_Printf_RingTail)
  {
    return FALSE;
  }

  Appl_Printf_TxRing[head] = byte;
  Appl_Printf_RingHead = next;
  return TRUE;
}

void Appl_Printf_Init(void)
{
  Appl_Printf_RingHead = 0U;
  Appl_Printf_RingTail = 0U;
  Appl_Printf_TxOkCount = 0U;
  Appl_Printf_TxDropCount = 0U;
  Appl_Printf_TxBusyCount = 0U;
}

int io_putchar(int ch)
{
  uint8 c;

  c = (uint8)ch;
  if (Appl_Printf_RingPush(c) == FALSE)
  {
    Appl_Printf_TxDropCount++;
  }

  return ch;
}

void Appl_Printf_MainFunction(void)
{
  uint16 used;
  uint16 count;
  uint16 tail;
  uint16 idx;
  Uart_ReturnType retVal;

  if (Uart_GetStatus((Uart_ChannelIdType)APPL_PRINTF_UART_CHANNEL) != UART_IDLE)
  {
    Appl_Printf_TxBusyCount++;
    return;
  }

  used = Appl_Printf_RingUsed();
  if (used == 0U)
  {
    return;
  }

  count = used;
  if (count > APPL_PRINTF_TX_CHUNK_SIZE)
  {
    count = APPL_PRINTF_TX_CHUNK_SIZE;
  }

  tail = Appl_Printf_RingTail;
  for (idx = 0U; idx < count; idx++)
  {
    Appl_Printf_TxChunk[idx] = Appl_Printf_TxRing[tail];
    tail = (uint16)((tail + 1U) % APPL_PRINTF_TX_RING_SIZE);
  }

  retVal = Uart_Write((Uart_ChannelIdType)APPL_PRINTF_UART_CHANNEL,
                      Appl_Printf_TxChunk,
                      (Uart_SizeType)count);
  if (retVal == UART_E_OK)
  {
    Appl_Printf_RingTail = tail;
    Appl_Printf_TxOkCount += (uint32)count;
  }
  else if (retVal == UART_E_BUSY)
  {
    Appl_Printf_TxBusyCount++;
  }
}

#endif /* APPL_PRINTF_ENABLE */
