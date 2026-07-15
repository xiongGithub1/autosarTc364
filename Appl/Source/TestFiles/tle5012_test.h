/**********************************************************************************************************************
 * tle5012_test.h - TLE5012 SPI bring-up (TestFiles)
 *
 * Debugger: add watch -> Tle5012Test_Obs
 **********************************************************************************************************************/
#ifndef TLE5012_TEST_H
#define TLE5012_TEST_H

#include "Std_Types.h"
#include "Spi.h"
#include "Tle5012bd_Driver.h"
#include "Tle5012bd_Spi.h"

/*
 * Watch this one struct in debugger (QSPI2 / SpiSequence_5012BD).
 *
 * Pass criteria (typical):
 *   HwInited=1, State=READY, AvalValid=1,
 *   SpiResult=E_OK(0), SeqResult=SPI_SEQ_OK(0),
 *   HwUnitAfter=SPI_IDLE(0), OkCounter rising
 */
typedef struct
{
  boolean Enabled;
  boolean HwInited;
  Tle5012bd_StateType State;              /* expect READY after Init */
  uint32 RunEntryCounter;
  uint32 StateNotReadyCounter;
  uint32 TestCounter;
  uint32 OkCounter;
  uint32 FailCounter;
  /* angle / speed */
  float32 AngleDeg;
  float32 OriginalAngleDeg;
  float32 ElectricalAngleRad;
  float32 AngleSpeed;
  float32 AngleSpeedFilter;
  float32 MechanicalRpm;
  boolean Direction;
  uint16 AngBase;
  /* raw sensor SFR */
  uint16 RawAval;
  uint16 RawAspd;
  uint16 RawStat;
  boolean AvalValid;
  boolean AspdValid;
  uint16 AvalRawAngle;
  uint16 AspdRawSpeed;
  /* last SPI frame diagnostics */
  uint32 SpiTxWord;
  uint32 SpiRxWord;
  uint16 SpiTx0;
  uint16 SpiTx1;
  uint16 SpiRx0;
  uint16 SpiRx1;
  Std_ReturnType SpiResult;               /* overall exchange: 0=E_OK */
  Std_ReturnType SpiSetupResult;          /* SetupEB */
  Std_ReturnType SpiTransmitResult;       /* AsyncTransmit */
  Spi_SeqResultType SeqResult;            /* 0=OK 1=PENDING 2=FAILED 3=CANCELED */
  Spi_StatusType HwUnitBefore;            /* QSPI2 */
  Spi_StatusType HwUnitAfter;             /* 0=IDLE 1=BUSY */
} Tle5012Test_ObsType;

extern Tle5012Test_ObsType Tle5012Test_Obs;

void Tle5012Test_Init(void);
void Tle5012Test_RunOnce(void);

#endif /* TLE5012_TEST_H */
