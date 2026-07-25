/**********************************************************************************************************************
 *  Tle9180_Driver.c - TLE9180 init sequence (ported from legacy TLE9180.c, AUTOSAR MCAL)
 **********************************************************************************************************************/
#include "Tle9180_Driver.h"
#include "Tle9180_AutosarPort.h"
#include <string.h>
#include <tle9180CRC.h>

#define STUP_COMMANDS_SIZE              20U
#define CONTROL_COMMANDS_SIZE         5U
#define ERR_STATUS_SIZE                 14U
#define READ_MODE_AND_CLEAR_ERR_SIZE    3U
#define ERR_COUNT                       10U
#define TLE9180_REG_OPERATION_MODE      0x40U
#define TLE9180_OM_IDLE_MASK            0x01U
#define TLE9180_OM_CONFIG_MASK          0x02U
#define TLE9180_OM_CONFIG_LOCK_MASK     0x04U
#define TLE9180_OM_SELF_TEST_MASK       0x08U
#define TLE9180_OM_SAFE_OFF_MASK        0x10U
#define TLE9180_OM_ERROR_MASK           0x20U
#define TLE9180_OM_REDUCED_MASK         0x40U
#define TLE9180_OM_NORMAL_MASK          0x80U
#define TLE9180_SPI_NOP_FLUSH_COUNT     3U
static IfxTLE9180 Tle9180_Handle;
static Tle9180_DriverStateType Tle9180_DriverState = TLE9180_DRV_STATE_UNINIT;
static uint8 Tle9180_LastInitError = 0U;
static uint8 Tle9180_OperationModeRaw = 0U;
static Tle9180_OperationModeType Tle9180_OperationMode = TLE9180_OP_MODE_UNKNOWN;

typedef enum
{
  TLE9180_INIT_STEP_PORT = 0U,
  TLE9180_INIT_STEP_SPI_TEST,
  TLE9180_INIT_STEP_ERR_STARTUP,
  TLE9180_INIT_STEP_ERR_AGAIN,
  TLE9180_INIT_STEP_LOAD_CONTROL,
  TLE9180_INIT_STEP_LOAD_STARTUP,
  TLE9180_INIT_STEP_DONE
} Tle9180_InitStepType;

static Tle9180_InitStepType Tle9180_InitStep = TLE9180_INIT_STEP_PORT;
static uint8 Tle9180_InitStepAttempt = 0U;
uint32 Tle9180_Driver_MainCounter = 0U;
uint32 Tle9180_Driver_InitStepCounter = 0U;
Std_ReturnType Tle9180_Driver_LastSpiExchangeResult = E_NOT_OK;
uint32 Tle9180_Driver_LastTxFrame = 0U;
uint32 Tle9180_Driver_LastRxFrame = 0U;
uint8 Tle9180_Driver_LastRxAddress = 0U;
uint8 Tle9180_Driver_LastRxData = 0U;

static IfxTLE9180_SpiTx Tle9180_startupConfig[STUP_COMMANDS_SIZE] =
{
  { .B.C = 1U, .B.ADDRESS = 0x01U, .B.DATA = 0x80U, .B.CRC = 0U },
  { .B.C = 1U, .B.ADDRESS = 0x02U, .B.DATA = 0x7FU, .B.CRC = 0U },
  { .B.C = 1U, .B.ADDRESS = 0x03U, .B.DATA = 0x18U, .B.CRC = 0U },
  { .B.C = 1U, .B.ADDRESS = 0x04U, .B.DATA = 0x56U, .B.CRC = 0U },
  { .B.C = 1U, .B.ADDRESS = 0x05U, .B.DATA = 0x37U, .B.CRC = 0U },
  { .B.C = 1U, .B.ADDRESS = 0x06U, .B.DATA = 0xC0U, .B.CRC = 0U },
  { .B.C = 1U, .B.ADDRESS = 0x07U, .B.DATA = 0x9AU, .B.CRC = 0U },
  { .B.C = 1U, .B.ADDRESS = 0x08U, .B.DATA = 0x30U, .B.CRC = 0U },
  { .B.C = 1U, .B.ADDRESS = 0x09U, .B.DATA = 0x70U, .B.CRC = 0U },
  { .B.C = 1U, .B.ADDRESS = 0x0AU, .B.DATA = 0x10U, .B.CRC = 0U },
  { .B.C = 1U, .B.ADDRESS = 0x0BU, .B.DATA = 0x20U, .B.CRC = 0U },
  { .B.C = 1U, .B.ADDRESS = 0x0CU, .B.DATA = 0x60U, .B.CRC = 0U },
  { .B.C = 1U, .B.ADDRESS = 0x0DU, .B.DATA = 0x0EU, .B.CRC = 0U },
  { .B.C = 1U, .B.ADDRESS = 0x0EU, .B.DATA = 0x0EU, .B.CRC = 0U },
  { .B.C = 1U, .B.ADDRESS = 0x0FU, .B.DATA = 0x85U, .B.CRC = 0U },
  { .B.C = 1U, .B.ADDRESS = 0x10U, .B.DATA = 0x50U, .B.CRC = 0U },
  { .B.C = 1U, .B.ADDRESS = 0x11U, .B.DATA = 0x0EU, .B.CRC = 0U },
  { .B.C = 1U, .B.ADDRESS = 0x12U, .B.DATA = 0x02U, .B.CRC = 0U },
  { .B.C = 1U, .B.ADDRESS = 0x13U, .B.DATA = 0x00U, .B.CRC = 0U },
  { .B.C = 1U, .B.ADDRESS = 0x00U, .B.DATA = 0x00U, .B.CRC = 0U }
};

static IfxTLE9180_SpiTx Tle9180_controlConfig[CONTROL_COMMANDS_SIZE] =
{
  { .B.C = 1U, .B.ADDRESS = 0x20U, .B.DATA = 0x00U, .B.CRC = 0U },
  { .B.C = 1U, .B.ADDRESS = 0x21U, .B.DATA = 0x00U, .B.CRC = 0U },
  { .B.C = 1U, .B.ADDRESS = 0x22U, .B.DATA = 0x00U, .B.CRC = 0U },
  { .B.C = 1U, .B.ADDRESS = 0x23U, .B.DATA = 0x9FU, .B.CRC = 0U },
  { .B.C = 0U, .B.ADDRESS = 0x32U, .B.DATA = 0x00U, .B.CRC = 0U }
};

static IfxTLE9180_SpiTx Tle9180_errStatusBuffer[ERR_STATUS_SIZE] =
{
  { .B.C = 0U, .B.ADDRESS = 0x40U, .B.DATA = 0x00U, .B.CRC = 0U },
  { .B.C = 0U, .B.ADDRESS = 0x42U, .B.DATA = 0x00U, .B.CRC = 0U },
  { .B.C = 0U, .B.ADDRESS = 0x43U, .B.DATA = 0x00U, .B.CRC = 0U },
  { .B.C = 0U, .B.ADDRESS = 0x44U, .B.DATA = 0x00U, .B.CRC = 0U },
  { .B.C = 0U, .B.ADDRESS = 0x45U, .B.DATA = 0x00U, .B.CRC = 0U },
  { .B.C = 0U, .B.ADDRESS = 0x46U, .B.DATA = 0x00U, .B.CRC = 0U },
  { .B.C = 0U, .B.ADDRESS = 0x47U, .B.DATA = 0x00U, .B.CRC = 0U },
  { .B.C = 0U, .B.ADDRESS = 0x48U, .B.DATA = 0x00U, .B.CRC = 0U },
  { .B.C = 0U, .B.ADDRESS = 0x49U, .B.DATA = 0x00U, .B.CRC = 0U },
  { .B.C = 0U, .B.ADDRESS = 0x4AU, .B.DATA = 0x00U, .B.CRC = 0U },
  { .B.C = 0U, .B.ADDRESS = 0x4BU, .B.DATA = 0x00U, .B.CRC = 0U },
  { .B.C = 0U, .B.ADDRESS = 0x4CU, .B.DATA = 0x00U, .B.CRC = 0U },
  { .B.C = 0U, .B.ADDRESS = 0x4DU, .B.DATA = 0x00U, .B.CRC = 0U },
  { .B.C = 0U, .B.ADDRESS = 0x32U, .B.DATA = 0x00U, .B.CRC = 0U }
};

static IfxTLE9180_SpiTx Tle9180_viewModeClearErr[READ_MODE_AND_CLEAR_ERR_SIZE] =
{
  { .B.C = 0U, .B.ADDRESS = 0x40U, .B.DATA = 0x00U, .B.CRC = 0U },
  { .B.C = 0U, .B.ADDRESS = 0x41U, .B.DATA = 0x00U, .B.CRC = 0U },
  { .B.C = 0U, .B.ADDRESS = 0x42U, .B.DATA = 0x00U, .B.CRC = 0U }
};

static Tle9180_OperationModeType Tle9180_DecodeOperationMode(uint8 modeRaw)
{
  Tle9180_OperationModeType mode = TLE9180_OP_MODE_UNKNOWN;

  if ((modeRaw & TLE9180_OM_NORMAL_MASK) != 0U)
  {
    mode = TLE9180_OP_MODE_NORMAL;
  }
  else if ((modeRaw & TLE9180_OM_REDUCED_MASK) != 0U)
  {
    mode = TLE9180_OP_MODE_REDUCED;
  }
  else if ((modeRaw & TLE9180_OM_ERROR_MASK) != 0U)
  {
    mode = TLE9180_OP_MODE_ERROR;
  }
  else if ((modeRaw & TLE9180_OM_SAFE_OFF_MASK) != 0U)
  {
    mode = TLE9180_OP_MODE_SAFE_OFF;
  }
  else if ((modeRaw & TLE9180_OM_SELF_TEST_MASK) != 0U)
  {
    mode = TLE9180_OP_MODE_SELF_TEST;
  }
  else if ((modeRaw & TLE9180_OM_CONFIG_LOCK_MASK) != 0U)
  {
    mode = TLE9180_OP_MODE_CONFIG_LOCK;
  }
  else if ((modeRaw & TLE9180_OM_CONFIG_MASK) != 0U)
  {
    mode = TLE9180_OP_MODE_CONFIG;
  }
  else if ((modeRaw & TLE9180_OM_IDLE_MASK) != 0U)
  {
    mode = TLE9180_OP_MODE_IDLE;
  }

  return mode;
}

static Std_ReturnType Tle9180_Exchange(uint32 txFrame)
{
  Std_ReturnType result;

  result = Tle9180_Port_SpiExchange(&Tle9180_Handle, txFrame);
  Tle9180_Driver_LastSpiExchangeResult = result;
  Tle9180_Driver_LastTxFrame = txFrame;
  Tle9180_Driver_LastRxFrame = Tle9180_Handle.receive.U;
  Tle9180_Driver_LastRxAddress = (uint8)Tle9180_Handle.receive.B.ADDRESS;
  Tle9180_Driver_LastRxData = (uint8)Tle9180_Handle.receive.B.DATA;

  return result;
}
static void Tle9180_UpdateOperationModeSnapshot(void)
{
  Tle9180_OperationModeRaw = (uint8)Tle9180_Handle.receiveBuffer[TLE9180_REG_OPERATION_MODE].B.DATA;
  Tle9180_OperationMode = Tle9180_DecodeOperationMode(Tle9180_OperationModeRaw);
}
static Std_ReturnType Tle9180_SpiNop(void)
{
  const uint32 tx = calcCRC_3(0x320000U);
  return Tle9180_Exchange(tx);
}

static void Tle9180_EnaReset(void)
{
  Tle9180_Port_ActivateEnable();
  Tle9180_Port_DelayUs(10U);
  Tle9180_Port_DeactivateEnable();
  Tle9180_Port_DelayUs(10U);
}

static boolean Tle9180_PortInit(void)
{
  boolean errHigh = FALSE;
  uint32 timeoutUs = 0U;

  (void)memset((void *)&Tle9180_Handle, 0, sizeof(Tle9180_Handle));
  Tle9180_OperationModeRaw = 0U;
  Tle9180_OperationMode = TLE9180_OP_MODE_SLEEP;

  Tle9180_Port_ActivateInhibit();
  Tle9180_Port_DelayMs(5U);
  Tle9180_Port_ActivateSafeOff();
  Tle9180_Port_DeactivateEnable();
  Tle9180_Port_DeactivateInhibit();
  Tle9180_Port_DelayMs(5U);

  while ((errHigh == FALSE) && (timeoutUs < 20000U))
  {
    errHigh = Tle9180_Port_GetErrorState();
    Tle9180_Port_DelayUs(10U);
    timeoutUs += 10U;
  }

  return errHigh;
}

static boolean Tle9180_SpiTest(void)
{
  boolean ok = FALSE;
  uint8 i;

  for (i = 0U; i < TLE9180_SPI_NOP_FLUSH_COUNT; i++)
  {
    if (Tle9180_SpiNop() == E_OK)
    {
      if ((Tle9180_Driver_LastRxAddress == 0x32U) ||
          (Tle9180_Handle.receiveBuffer[0x32U].B.ADDRESS == 0x32U))
      {
        ok = TRUE;
        break;
      }
    }
    Tle9180_Port_DelayUs(1U);
  }

  if (ok != TRUE)
  {
    Tle9180_Port_DelayUs(10U);
    Tle9180_EnaReset();
  }

  return ok;
}

static boolean Tle9180_LoadStartupConfiguration(void)
{
  boolean result = FALSE;
  uint8 i;

  for (i = 0U; i < (STUP_COMMANDS_SIZE - 1U); i++)
  {
    Tle9180_startupConfig[i].B.CRC = 0U;
    Tle9180_startupConfig[i].U = calcCRC_3(Tle9180_startupConfig[i].U);
  }

  Tle9180_startupConfig[STUP_COMMANDS_SIZE - 1U].U =
      calcCRC_8(&Tle9180_startupConfig[0].U, (uint8)(STUP_COMMANDS_SIZE - 1U));
  Tle9180_startupConfig[STUP_COMMANDS_SIZE - 1U].U =
      (Tle9180_startupConfig[STUP_COMMANDS_SIZE - 1U].U << 8) | 0x800000U;
  Tle9180_startupConfig[STUP_COMMANDS_SIZE - 1U].U =
      calcCRC_3(Tle9180_startupConfig[STUP_COMMANDS_SIZE - 1U].U);

  for (i = 0U; i < STUP_COMMANDS_SIZE; i++)
  {
    (void)Tle9180_Exchange(Tle9180_startupConfig[i].U);
  }

  Tle9180_Port_DelayUs(1U);
  Tle9180_SpiNop();

  if (Tle9180_Handle.receiveBuffer[0U].B.CONFVALID == TRUE)
  {
    Tle9180_Port_DeactivateSafeOff();

    for (i = 0U; i < READ_MODE_AND_CLEAR_ERR_SIZE; i++)
    {
      Tle9180_viewModeClearErr[i].B.CRC = 0U;
      Tle9180_viewModeClearErr[i].U = calcCRC_3(Tle9180_viewModeClearErr[i].U);
      (void)Tle9180_Exchange(Tle9180_viewModeClearErr[i].U);
    }

    Tle9180_UpdateOperationModeSnapshot();

    if ((Tle9180_OperationModeRaw & TLE9180_OM_NORMAL_MASK) != 0U)
    {
      result = TRUE;
    }
  }

  return result;
}

static boolean Tle9180_ReadErrorStatusStartup(void)
{
  boolean result = FALSE;
  uint8 i;
  uint8 errCp;
  uint8 errSd;
  uint32 tx;

  for (i = 0U; i < ERR_STATUS_SIZE; i++)
  {
    Tle9180_errStatusBuffer[i].B.CRC = 0U;
    Tle9180_errStatusBuffer[i].U = calcCRC_3(Tle9180_errStatusBuffer[i].U);
    (void)Tle9180_Exchange(Tle9180_errStatusBuffer[i].U);
  }

  Tle9180_UpdateOperationModeSnapshot();

  errCp = (uint8)Tle9180_Handle.receiveBuffer[0x44U].B.DATA;
  errSd = (uint8)Tle9180_Handle.receiveBuffer[0x46U].B.DATA;

  if (((errCp & 0x18U) != 0U) || ((errSd & 0x82U) != 0U))
  {
    Tle9180_Port_DelayMs(5U);
    Tle9180_EnaReset();
    Tle9180_Port_DelayUs(500U);
  }
  else if ((errSd & 0x4U) == 0x4U)
  {
    Tle9180_EnaReset();
    Tle9180_Port_DelayUs(500U);
  }

  tx = calcCRC_3(0x460000U);
  (void)Tle9180_Exchange(tx);
  Tle9180_SpiNop();

  if ((Tle9180_Handle.receiveBuffer[0x46U].B.DATA & 0x10U) == 0U)
  {
    result = TRUE;
  }
  else
  {
    tx = calcCRC_3(0x650000U);
    (void)Tle9180_Exchange(tx);
    Tle9180_SpiNop();
  }

  return result;
}

static boolean Tle9180_ReadErrorStatusAgain(void)
{
  boolean result = FALSE;
  uint8 i;
  uint8 errCp;
  uint8 errSd;

  for (i = 0U; i < ERR_STATUS_SIZE; i++)
  {
    Tle9180_errStatusBuffer[i].B.CRC = 0U;
    Tle9180_errStatusBuffer[i].U = calcCRC_3(Tle9180_errStatusBuffer[i].U);
    (void)Tle9180_Exchange(Tle9180_errStatusBuffer[i].U);
  }

  Tle9180_UpdateOperationModeSnapshot();

  errCp = (uint8)Tle9180_Handle.receiveBuffer[0x44U].B.DATA;
  errSd = (uint8)Tle9180_Handle.receiveBuffer[0x46U].B.DATA;

  if (((errCp & 0x18U) != 0U) || (errSd != 0U))
  {
    Tle9180_Port_DelayMs(5U);
    Tle9180_Port_ActivateInhibit();
  }
  else
  {
    result = TRUE;
  }

  return result;
}

static boolean Tle9180_LoadControlConfiguration(void)
{
  uint8 i;

  for (i = 0U; i < CONTROL_COMMANDS_SIZE; i++)
  {
    Tle9180_controlConfig[i].B.CRC = 0U;
    Tle9180_controlConfig[i].U = calcCRC_3(Tle9180_controlConfig[i].U);
    (void)Tle9180_Exchange(Tle9180_controlConfig[i].U);
  }

  Tle9180_SpiNop();
  return (boolean)(Tle9180_Handle.receiveBuffer[0x23U].B.DATA
      == Tle9180_Handle.transmitBuffer[0x23U].B.DATA);
}

static boolean Tle9180_RunStep(boolean (*stepFn)(void), uint8 errorCode)
{
  uint8 i;

  for (i = 0U; i < ERR_COUNT; i++)
  {
    if (stepFn() == TRUE)
    {
      return TRUE;
    }
  }

  Tle9180_LastInitError = errorCode;
  return FALSE;
}

void Tle9180_Driver_Init(void)
{
  if (Tle9180_DriverState == TLE9180_DRV_STATE_READY)
  {
    return;
  }

  Tle9180_LastInitError = 0U;

  if (Tle9180_PortInit() != TRUE)
  {
    Tle9180_LastInitError = 1U;
    Tle9180_DriverState = TLE9180_DRV_STATE_FAULT;
    return;
  }

  if (Tle9180_RunStep(Tle9180_SpiTest, 2U) != TRUE) { Tle9180_DriverState = TLE9180_DRV_STATE_FAULT; return; }
  if (Tle9180_RunStep(Tle9180_ReadErrorStatusStartup, 3U) != TRUE) { Tle9180_DriverState = TLE9180_DRV_STATE_FAULT; return; }
  if (Tle9180_RunStep(Tle9180_ReadErrorStatusAgain, 4U) != TRUE) { Tle9180_DriverState = TLE9180_DRV_STATE_FAULT; return; }
  if (Tle9180_RunStep(Tle9180_LoadControlConfiguration, 5U) != TRUE) { Tle9180_DriverState = TLE9180_DRV_STATE_FAULT; return; }
  if (Tle9180_RunStep(Tle9180_LoadStartupConfiguration, 6U) != TRUE) { Tle9180_DriverState = TLE9180_DRV_STATE_FAULT; return; }

  Tle9180_Port_DeactivateEnable();
  Tle9180_DriverState = TLE9180_DRV_STATE_READY;
}

static void Tle9180_AdvanceInitStep(void)
{
  Tle9180_InitStepAttempt = 0U;
  Tle9180_Driver_InitStepCounter++;
  Tle9180_InitStep = (Tle9180_InitStepType)((uint8)Tle9180_InitStep + 1U);
}

static void Tle9180_HandleInitStepResult(boolean stepOk, uint8 errorCode)
{
  if (stepOk == TRUE)
  {
    Tle9180_AdvanceInitStep();
    return;
  }

  Tle9180_InitStepAttempt++;
  if (Tle9180_InitStepAttempt >= ERR_COUNT)
  {
    Tle9180_LastInitError = errorCode;
    Tle9180_DriverState = TLE9180_DRV_STATE_FAULT;
  }
}

void Tle9180_Driver_MainFunction(void)
{
  Tle9180_Driver_MainCounter++;

  if (Tle9180_DriverState == TLE9180_DRV_STATE_READY)
  {
    return;
  }

  if (Tle9180_DriverState == TLE9180_DRV_STATE_FAULT)
  {
    return;
  }

  switch (Tle9180_InitStep)
  {
    case TLE9180_INIT_STEP_PORT:
      Tle9180_HandleInitStepResult(Tle9180_PortInit(), 1U);
      break;

    case TLE9180_INIT_STEP_SPI_TEST:
      Tle9180_HandleInitStepResult(Tle9180_SpiTest(), 2U);
      break;

    case TLE9180_INIT_STEP_ERR_STARTUP:
      Tle9180_HandleInitStepResult(Tle9180_ReadErrorStatusStartup(), 3U);
      break;

    case TLE9180_INIT_STEP_ERR_AGAIN:
      Tle9180_HandleInitStepResult(Tle9180_ReadErrorStatusAgain(), 4U);
      break;

    case TLE9180_INIT_STEP_LOAD_CONTROL:
      Tle9180_HandleInitStepResult(Tle9180_LoadControlConfiguration(), 5U);
      break;

    case TLE9180_INIT_STEP_LOAD_STARTUP:
      Tle9180_HandleInitStepResult(Tle9180_LoadStartupConfiguration(), 6U);
      break;

    default:
      Tle9180_Port_DeactivateEnable();
      Tle9180_DriverState = TLE9180_DRV_STATE_READY;
      Tle9180_InitStep = TLE9180_INIT_STEP_DONE;
      break;
  }
}

Tle9180_DriverStateType Tle9180_Driver_GetState(void)
{
  return Tle9180_DriverState;
}

uint8 Tle9180_Driver_GetLastInitError(void)
{
  return Tle9180_LastInitError;
}

Std_ReturnType Tle9180_Driver_ReadOperationMode(void)
{
  Std_ReturnType result;
  uint32 tx;

  tx = calcCRC_3(0x400000U);
  result = Tle9180_Exchange(tx);
  if (result == E_OK)
  {
    Tle9180_SpiNop();
    Tle9180_UpdateOperationModeSnapshot();
  }
  else if (Tle9180_DriverState == TLE9180_DRV_STATE_UNINIT)
  {
    Tle9180_OperationModeRaw = 0U;
    Tle9180_OperationMode = TLE9180_OP_MODE_SLEEP;
  }

  return result;
}

Tle9180_OperationModeType Tle9180_Driver_GetOperationMode(void)
{
  return Tle9180_OperationMode;
}

uint8 Tle9180_Driver_GetOperationModeRaw(void)
{
  return Tle9180_OperationModeRaw;
}
void Tle9180_Driver_EnableOutput(boolean enable)
{
  if (enable == TRUE)
  {
    Tle9180_Port_DeactivateSafeOff();
    Tle9180_Port_ActivateEnable();
  }
  else
  {
    Tle9180_Port_DeactivateEnable();
    Tle9180_Port_ActivateSafeOff();
  }
}

void Tle9180_Driver_ReadErrorStatus(void)
{
  uint8 i;

  for (i = 0U; i < ERR_STATUS_SIZE; i++)
  {
    Tle9180_errStatusBuffer[i].B.CRC = 0U;
    Tle9180_errStatusBuffer[i].U = calcCRC_3(Tle9180_errStatusBuffer[i].U);
    (void)Tle9180_Exchange(Tle9180_errStatusBuffer[i].U);
  }
}





