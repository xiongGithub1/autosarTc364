/**********************************************************************************************************************
 *  TLE9180_Types.h - SPI frame and driver handle (no iLLD)
 **********************************************************************************************************************/
#ifndef TLE9180_TYPES_H
#define TLE9180_TYPES_H

#include "Std_Types.h"

typedef struct
{
  unsigned CRC     : 3;
  unsigned         : 5;
  unsigned DATA    : 8;
  unsigned ADDRESS : 7;
  unsigned C       : 1;
  unsigned         : 8;
} Tle9180_SpiTx_bits;

typedef struct
{
  unsigned CRC       : 3;
  unsigned           : 1;
  unsigned DATA      : 8;
  unsigned ADDRESS   : 7;
  unsigned SPLEVENT  : 1;
  unsigned SPIERR    : 1;
  unsigned CONFVALID : 1;
  unsigned WARNING   : 1;
  unsigned ERROR     : 1;
  unsigned           : 8;
} Tle9180_SpiRx_bits;

typedef union
{
  uint32 U;
  Tle9180_SpiTx_bits B;
} IfxTLE9180_SpiTx;

typedef union
{
  uint32 U;
  Tle9180_SpiRx_bits B;
} IfxTLE9180_SpiRx;

typedef struct
{
  IfxTLE9180_SpiRx receiveBuffer[0x68];
  IfxTLE9180_SpiTx transmitBuffer[0x68];
  IfxTLE9180_SpiRx receive;
  IfxTLE9180_SpiTx transmit;
} IfxTLE9180;

#endif /* TLE9180_TYPES_H */
