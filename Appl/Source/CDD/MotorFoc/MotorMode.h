#ifndef MOTORMODE_H
#define MOTORMODE_H

#include "Std_Types.h"

/**
 * @brief Motor control mode, aligned with RTE Pp_MotorCtrlCmd/MotorMode (uint8).
 *        UDE can change MotorControll_MotorModeCmd directly with symbolic enum names.
 */
typedef enum
{
  MOTOR_MODE_IDLE = 0U,
  MOTOR_MODE_STOP = 1U,
  MOTOR_MODE_FOC_SPEED = 2U,
  MOTOR_MODE_FOC_CURRENT = 3U,
  MOTOR_MODE_OPEN_LOOP = 4U,
  MOTOR_MODE_CALIBRATION = 5U,
  MOTOR_MODE_CALIBRATION_ERASE = 6U
} MotorMode_Type;

#define MOTOR_MODE_DEFAULT   MOTOR_MODE_IDLE

#endif /* MOTORMODE_H */
