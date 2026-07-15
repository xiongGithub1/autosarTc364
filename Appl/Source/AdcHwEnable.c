/*
 * @Author: qinXiong
 * @Date: 2026-07-07 16:19:41
 * @LastEditors: Qxiong&&2307975018@qq.com
 * @Description: ADC master-group notification bridge for motor sync sampling.
 */

#include "AdcHwEnable.h"
#include "MotorCdd_Adc.h"

void Adc_9183SenseVo1andVro_Notification(void)
{
  MotorCdd_AdcGroup0Notification();
}

void App_AdcHwTriggerInit(void)
{
  MotorCdd_AdcHwTriggerInit();
}
