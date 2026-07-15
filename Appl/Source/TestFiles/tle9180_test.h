/**********************************************************************************************************************
 * tle9180_test.h - TLE9180 SPI bring-up (TestFiles)
 *
 * Debugger: add watch -> Tle9180Test_Obs
 **********************************************************************************************************************/
#ifndef TLE9180_TEST_H
#define TLE9180_TEST_H

#include "Std_Types.h"
#include "Spi.h"
#include "Tle9180_Driver.h"

/*
 * Watch this one struct in debugger (QSPI3 / SpiSequence_9183).
 *
 * Pass criteria (typical):
 *   HwInited=1, State=READY(1), SpiExch=E_OK(0),
 *   SeqAfter=SPI_SEQ_OK(0), HwUnitAfter=SPI_IDLE(0),
 *   OkCounter rising, FailCounter stable
 */
typedef struct
{
  boolean Enabled;
  boolean HwInited;
  Tle9180_DriverStateType State;          /* 0=UNINIT 1=READY 2=FAULT */
  uint8 LastInitError;
  uint8 OpModeRaw;
  Tle9180_OperationModeType OpMode;       /* expect NORMAL when ready */
  boolean IsNormalMode;
  boolean IsConfigMode;
  boolean IsIdleMode;
  boolean IsSleepMode;
  boolean IsConfigLockMode;
  uint32 MainCounter;
  uint32 InitStepCounter;
  Std_ReturnType SpiExch;                 /* last Driver SPI exchange: 0=E_OK */
  uint32 TxFrame;
  uint32 RxFrame;
  uint8 RxAddr;
  uint8 RxData;
  Spi_StatusType SpiGlobalBefore;         /* Spi_GetStatus */
  Spi_StatusType SpiGlobalAfter;
  Spi_StatusType HwUnitBefore;            /* Spi_GetHWUnitStatus(QSPI3) */
  Spi_StatusType HwUnitAfter;             /* 0=IDLE 1=BUSY */
  Spi_JobResultType JobBefore;
  Spi_JobResultType JobAfter;             /* 0=SPI_JOB_OK */
  Spi_SeqResultType SeqBefore;
  Spi_SeqResultType SeqAfter;             /* 0=SPI_SEQ_OK */
  uint32 TestCounter;
  uint32 OkCounter;
  uint32 FailCounter;
} Tle9180Test_ObsType;

extern Tle9180Test_ObsType Tle9180Test_Obs;

void Tle9180Test_Init(void);
void Tle9180Test_RunOnce(void);

#endif /* TLE9180_TEST_H */
