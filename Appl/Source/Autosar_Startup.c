#include "EcuM.h"
#include "Os.h"
#include "Appl_HwStartup.h"
#include "Os_Trap.h"


int main(void)
{
  Appl_HwStartup_Init();
  Os_InitMemory();
  Os_Init();
  EcuM_Init();

  for(;;)
  {
  }
}

#define OS_START_SEC_Default_Init_Task_CODE
#include "Os_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

TASK(Default_Init_Task)
{
  EcuM_StartupTwo();
  (void)Os_InitialEnableInterruptSources(TRUE);
  (void)TerminateTask();
}

#define OS_STOP_SEC_Default_Init_Task_CODE
#include "Os_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#define OS_START_SEC_Default_Init_Task_Trusted_CODE
#include "Os_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

TASK(Default_Init_Task_Trusted)
{
  (void)TerminateTask();
}

#define OS_STOP_SEC_Default_Init_Task_Trusted_CODE
#include "Os_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
