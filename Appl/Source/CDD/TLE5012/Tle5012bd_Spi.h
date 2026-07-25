/**********************************************************************************************************************
 *  Tle5012bd_Spi.h - TLE5012BD SPI: Async+DMA, blocking wait API
 **********************************************************************************************************************/
#ifndef TLE5012BD_SPI_H
#define TLE5012BD_SPI_H

#include "Std_Types.h"

typedef enum
{
  TLE5012BD_SPI_XFER_IDLE = 0U,
  TLE5012BD_SPI_XFER_PENDING = 1U,
  TLE5012BD_SPI_XFER_OK = 2U,
  TLE5012BD_SPI_XFER_FAIL = 3U
} Tle5012bd_SpiXferStateType;

extern uint32 Tle5012bd_SpiLastTxWord;
extern uint32 Tle5012bd_SpiLastRxWord;
extern Std_ReturnType Tle5012bd_SpiLastResult;
extern Std_ReturnType Tle5012bd_SpiLastSetupResult;
extern Std_ReturnType Tle5012bd_SpiLastTransmitResult;
extern volatile Tle5012bd_SpiXferStateType Tle5012bd_SpiXferState;

/* Blocking: Task / calibration. Non-blocking: 1 ms angle pipeline (INTERRUPT mode). */
Std_ReturnType Tle5012bd_SpiExchangeU32(uint32 txWord, uint32 *rxWord);

Std_ReturnType Tle5012bd_SpiStartExchangeU32(uint32 txWord);
Tle5012bd_SpiXferStateType Tle5012bd_SpiPollExchange(void);
Std_ReturnType Tle5012bd_SpiTakeRxWord(uint32 *rxWord);

#endif /* TLE5012BD_SPI_H */
