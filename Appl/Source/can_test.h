#ifndef CAN_TEST_H
#define CAN_TEST_H

#include "CanIf.h"
#include "CanSM_ComM.h"
#include "Com.h"
#include "ComM.h"
#include "EcuM.h"
#include "Rte_EcuM_Type.h"
#include "Std_Types.h"

extern uint8 CanTest_CanTxLampCnt;
extern boolean CanTest_CanTxRearInteriorLight;
extern uint8 CanTest_CanTxLampCntResult;
extern uint8 CanTest_CanTxRearInteriorLightResult;
extern uint32 CanTest_CanTxUpdateCounter;
extern uint32 CanTest_CanTxSkipCounter;
extern Com_StatusType CanTest_ComStatus;
extern EcuM_StateType CanTest_EcuMState;
extern Std_ReturnType CanTest_EcuMGetStateResult;
extern ComM_InitStatusType CanTest_ComMStatus;
extern Std_ReturnType CanTest_ComMGetStatusResult;
extern Std_ReturnType CanTest_ComMRequestResult;
extern boolean CanTest_ComMCommunicationAllowed;
extern ComM_ModeType CanTest_ComMCurrentMode;
extern Std_ReturnType CanTest_ComMCurrentModeResult;
extern ComM_ModeType CanTest_CanSMCurrentMode;
extern Std_ReturnType CanTest_CanSMCurrentModeResult;
extern CanIf_ControllerModeType CanTest_CanIfControllerMode;
extern Std_ReturnType CanTest_CanIfControllerModeResult;
extern CanIf_PduGetModeType CanTest_CanIfPduMode;
extern Std_ReturnType CanTest_CanIfPduModeResult;
extern uint8 CanTest_Can1En;
extern uint8 CanTest_Can1Nerr;
extern uint8 CanTest_Can1Nstb;

void CanTest_Init(void);
void CanTest_RunOnce(void);

#endif
