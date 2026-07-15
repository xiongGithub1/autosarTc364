#ifndef MOTORFOC_OPENLOOPCAN_H
#define MOTORFOC_OPENLOOPCAN_H

#include "Std_Types.h"
#include "MotorMode.h"

/* Temporary CAN-FD diagnostic output for open-loop tuning. */
#define MOTORFOC_OPENLOOPCAN_PAYLOAD_LENGTH  (32U)
#define MOTORFOC_OPENLOOPCAN_PAGE_CONTROL    (0xA0U)
#define MOTORFOC_OPENLOOPCAN_PAGE_PWM        (0xA1U)
#define MOTORFOC_OPENLOOPCAN_PAGE_ADC        (0xA2U)

extern volatile uint8 MotorFoc_OpenLoopCan_Enable;
extern volatile uint8 MotorFoc_OpenLoopCan_LastTxResult;
extern volatile uint32 MotorFoc_OpenLoopCan_TxCounter;
extern volatile uint32 MotorFoc_OpenLoopCan_TxErrorCounter;

void MotorFoc_OpenLoopCan_Init(void);
void MotorFoc_OpenLoopCan_MainFunction(MotorMode_Type motorMode);

#endif /* MOTORFOC_OPENLOOPCAN_H */
