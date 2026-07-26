/**********************************************************************************************************************
 *  Tle5012bd_Spi.h - TLE5012BD SPI: Async+DMA Kick/Poll pipeline
 **********************************************************************************************************************/
#ifndef TLE5012BD_SPI_H
#define TLE5012BD_SPI_H

#include "Std_Types.h"
#include "Spi.h"

extern uint32 Tle5012bd_SpiLastTxWord;
extern uint32 Tle5012bd_SpiLastRxWord;
extern Std_ReturnType Tle5012bd_SpiLastResult;
extern Std_ReturnType Tle5012bd_SpiLastSetupResult;
extern Std_ReturnType Tle5012bd_SpiLastTransmitResult;

/* Non-blocking: Kick starts transfer; Poll returns PENDING/OK/FAILED once. */
Std_ReturnType Tle5012bd_SpiKickU32(uint32 txWord);
Spi_SeqResultType Tle5012bd_SpiPollU32(uint32 *rxWord);

/* Blocking spin-wait — config/SSC only; NEVER call from ADC/FOC fast loop. */
Std_ReturnType Tle5012bd_SpiExchangeU32(uint32 txWord, uint32 *rxWord);

#endif /* TLE5012BD_SPI_H */


