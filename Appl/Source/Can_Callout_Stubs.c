/**********************************************************************************************************************
 *  Can_Callout_Stubs.c
 *
 *  Application callbacks for Vector Can driver hardware loop timeout monitoring.
 *  Uses STM via Mcal_DelayGetTick() so timing works inside Can SchM exclusive
 *  areas where SuspendAllInterrupts() forbids GetCounterValue().
 **********************************************************************************************************************/

#include "Can.h"
#include "McalLib.h"
#include "Os.h"

#if (CAN_DEV_ERROR_DETECT == STD_ON)
# include "Det.h"
#endif

void ApplCanInterruptDisable(uint8 Controller)
{
  (void)Controller;
  SuspendAllInterrupts();
}

void ApplCanInterruptRestore(uint8 Controller)
{
  (void)Controller;
  ResumeAllInterrupts();
}

static uint32 Can_Callout_GetTimeoutTicks(void)
{
  uint32 resolution;

  resolution = Mcal_DelayTickResolution();
  if (resolution == 0U)
  {
    resolution = Mcal_DelayResetTickCalibration();
  }

  if (resolution == 0U)
  {
    return 0U;
  }

  return (CAN_TIMEOUT_DURATION * 1000000UL) / resolution;
}

static Can_ExternalTickType Can_Callout_GetStartTick(uint8 source)
{
  return Can_GetLoopTimeoutOfControllerData(0U)[source];
}

static void Can_Callout_SetStartTick(uint8 source, Can_ExternalTickType startTick)
{
  Can_GetLoopTimeoutOfControllerData(0U)[source] = startTick;
}

void ApplCanTimerStart(uint8 source)
{
#if (CAN_DEV_ERROR_DETECT == STD_ON)
  if (source > CAN_LOOP_MAX)
  {
    (void)Det_ReportError(CAN_MODULE_ID, CAN_INSTANCE_ID, CAN_HW_ACCESS_ID, CAN_E_PARAM_HANDLE);
  }
  else
#endif
  {
    Can_Callout_SetStartTick(source, Mcal_DelayGetTick());
  }
}

Can_ReturnType ApplCanTimerLoop(uint8 source)
{
  Can_ReturnType retval;
  uint32 elapsedTicks;
  uint32 timeoutTicks;
  Can_ExternalTickType startTick;

  retval = CAN_NOT_OK;

#if (CAN_DEV_ERROR_DETECT == STD_ON)
  if (source > CAN_LOOP_MAX)
  {
    (void)Det_ReportError(CAN_MODULE_ID, CAN_INSTANCE_ID, CAN_HW_ACCESS_ID, CAN_E_PARAM_HANDLE);
  }
  else
#endif
  {
    startTick = Can_Callout_GetStartTick(source);
    elapsedTicks = Mcal_DelayGetTick() - startTick;
    timeoutTicks = Can_Callout_GetTimeoutTicks();

    if ((timeoutTicks == 0U) || (elapsedTicks < timeoutTicks))
    {
      retval = CAN_OK;
    }
#if (CAN_DEV_ERROR_DETECT == STD_ON)
    else if (source < CAN_LOOP_MAX)
    {
      (void)Det_ReportError(CAN_MODULE_ID, CAN_INSTANCE_ID, CAN_HW_ACCESS_ID, CAN_E_TIMEOUT_DET);
    }
#endif
  }

  return retval;
}

void ApplCanTimerEnd(uint8 source)
{
  ApplCanTimerStart(source);
}
