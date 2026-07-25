/**********************************************************************************************************************
 *  Tle5012bd_Spi.h - TLE5012BD SPI: Async+DMA, IPB-style blocking wait
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

/* Non-blocking exchange owned by the TLE5012 angle service. */
Std_ReturnType Tle5012bd_SpiKickU32(uint32 txWord);
Spi_SeqResultType Tle5012bd_SpiPollU32(uint32 *rxWord);

/* Legacy blocking API: do not use in the motor angle path. */
Std_ReturnType Tle5012bd_SpiExchangeU32(uint32 txWord, uint32 *rxWord);

#endif /* TLE5012BD_SPI_H */


