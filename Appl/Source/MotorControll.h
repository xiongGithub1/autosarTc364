#ifndef MOTORCONTROLL_H
#define MOTORCONTROLL_H

#include "Std_Types.h"
#include "MotorMode.h"

extern volatile uint8 MotorControll_OpenLoopEnable;
extern volatile uint32 MotorControll_MainCounter;
extern volatile uint32 MotorControll_OpenLoopBlockedCounter;
extern volatile float32 MotorControll_SensorElectricalAngleRad;
extern volatile float32 MotorControll_SensorMechanicalRpm;
extern volatile float32 MotorControll_ForcedElectricalAngleDeg;
extern volatile float32 MotorControll_RefSpeedRpm;
extern volatile float32 MotorControll_IdRefCmd;
extern volatile float32 MotorControll_IqRefCmd;
extern volatile float32 MotorControll_IdRefOut;
extern volatile float32 MotorControll_IqRefOut;
extern volatile float32 MotorControll_OpenLoopCurrentLimitA;
extern volatile float32 MotorControll_OpenLoopCurrentRampStepA;
extern volatile MotorMode_Type MotorControll_MotorModeCmd;
extern volatile uint8 MotorControll_GateDriverState;
extern volatile uint8 MotorControll_GateDriverLastInitError;
extern volatile uint8 MotorControll_GateDriverOpModeRaw;
extern volatile uint8 MotorControll_GateDriverOutputEnabled;

void MotorControll_MainFunction(void);
void MotorControll_StopPwm(void);
uint8 MotorControll_IsCurrentOffsetReady(void);
uint8 MotorControll_IsOutputEnabled(void);

#endif /* MOTORCONTROLL_H */
