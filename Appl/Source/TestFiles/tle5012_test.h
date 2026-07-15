#ifndef TLE5012_TEST_H
#define TLE5012_TEST_H

#include "Std_Types.h"
#include "Tle5012bd_Driver.h"
#include "Tle5012bd_Spi.h"

extern boolean Tle5012Test_Enabled;
extern boolean Tle5012Test_HwInited;
extern Tle5012bd_StateType Tle5012Test_State;
extern uint32 Tle5012Test_RunEntryCounter;
extern uint32 Tle5012Test_StateNotReadyCounter;
extern uint32 Tle5012Test_TestCounter;
extern uint32 Tle5012Test_OkCounter;
extern uint32 Tle5012Test_FailCounter;
extern float32 Tle5012Test_Angle;
extern float32 Tle5012Test_OriginalAngle;
extern float32 Tle5012Test_ElectricalAngleRad;
extern float32 Tle5012Test_AngleSpeed;
extern float32 Tle5012Test_AngleSpeedFilter;
extern float32 Tle5012Test_MechanicalRpm;
extern boolean Tle5012Test_Direction;
extern uint16 Tle5012Test_AngBase;
extern uint16 Tle5012Test_RawAval;
extern uint16 Tle5012Test_RawAspd;
extern uint16 Tle5012Test_RawStat;
extern boolean Tle5012Test_AvalValid;
extern boolean Tle5012Test_AspdValid;
extern uint16 Tle5012Test_AvalRawAngle;
extern uint16 Tle5012Test_AspdRawSpeed;
extern uint32 Tle5012Test_SpiLastTxWord;
extern uint32 Tle5012Test_SpiLastRxWord;
extern uint16 Tle5012Test_SpiLastTx0;
extern uint16 Tle5012Test_SpiLastTx1;
extern uint16 Tle5012Test_SpiLastRx0;
extern uint16 Tle5012Test_SpiLastRx1;
extern Std_ReturnType Tle5012Test_SpiLastResult;
extern Std_ReturnType Tle5012Test_SpiLastSetupResult;
extern Std_ReturnType Tle5012Test_SpiLastTransmitResult;
extern Spi_SeqResultType Tle5012Test_SpiLastSeqResult;
extern Spi_StatusType Tle5012Test_SpiStatusBefore;
extern Spi_StatusType Tle5012Test_SpiStatusAfter;

void Tle5012Test_Init(void);
void Tle5012Test_RunOnce(void);

#endif /* TLE5012_TEST_H */

