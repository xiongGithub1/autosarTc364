#ifndef MOTORFOC_CURRENTLOOP_H
#define MOTORFOC_CURRENTLOOP_H

#include "MotorFoc_Types.h"

extern volatile float32 MotorFoc_CurrentLoopMaxCurrentA;
extern volatile float32 MotorFoc_CurrentLoopMinVdcRunV;
extern volatile uint16 MotorFoc_CurrentLoopStartupBlankingCount;
extern volatile uint16 MotorFoc_CurrentLoopStartupBlankingLeft;
extern volatile uint16 MotorFoc_CurrentLoopUndervoltConfirmCount;
extern volatile uint16 MotorFoc_CurrentLoopUndervoltCounter;
extern volatile uint16 MotorFoc_CurrentLoopOverCurrentConfirmCount;
extern volatile uint16 MotorFoc_CurrentLoopOverCurrentCounter;
extern volatile uint8 MotorFoc_CurrentLoopFault;
extern volatile uint8 MotorFoc_CurrentLoopFaultReason;
extern volatile uint8 MotorFoc_CurrentLoopFaultClearRequest;
extern volatile float32 MotorFoc_CurrentLoopFaultIuA;
extern volatile float32 MotorFoc_CurrentLoopFaultIvA;
extern volatile float32 MotorFoc_CurrentLoopFaultIwA;
extern volatile float32 MotorFoc_CurrentLoopFaultVdcV;

#define MOTORFOC_CURRENT_FAULT_NONE         (0U)
#define MOTORFOC_CURRENT_FAULT_UNDERVOLT    (1U)
#define MOTORFOC_CURRENT_FAULT_OVERCURRENT  (2U)

void MotorFoc_CurrentLoopInit(MotorFoc_ContextType* ctx);
void MotorFoc_SetIdRef(MotorFoc_ContextType* ctx, float32 idRef);
void MotorFoc_SetIqRef(MotorFoc_ContextType* ctx, float32 iqRef);
void MotorFoc_SetAngleFromTle5012(MotorFoc_ContextType* ctx,
                                  float32 angleRaw,
                                  float32 electricalAngleRad);
void MotorFoc_UpdateCurrentFromAdc(MotorFoc_ContextType* ctx,
                                   float32 iu,
                                   float32 iv,
                                   float32 iw,
                                   float32 vdc);
void MotorFoc_UpdateRawCurrentForProtection(float32 iu,
                                             float32 iv,
                                             float32 iw);
void MotorFoc_RunCurrentLoop(MotorFoc_ContextType* ctx);
void MotorFoc_RunVoltageOpenLoop(MotorFoc_ContextType* ctx,
                                 float32 vdRef,
                                 float32 vqRef);
void MotorFoc_CurrentLoopStop(MotorFoc_ContextType* ctx);
void MotorFoc_CurrentLoopPreparePwmNeutral(MotorFoc_ContextType* ctx);
void MotorFoc_CurrentLoopClearFault(void);
void MotorFoc_CurrentLoopArmStartupBlanking(void);

#endif /* MOTORFOC_CURRENTLOOP_H */
