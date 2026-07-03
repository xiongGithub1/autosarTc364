#include "can_test.h"

#include "ComM_EcuMBswM.h"
#include "Dio.h"
#include "Dio_Cfg.h"

uint8 CanTest_CanTxLampCnt = 0U;
boolean CanTest_CanTxRearInteriorLight = FALSE;
uint8 CanTest_CanTxLampCntResult = E_NOT_OK;
uint8 CanTest_CanTxRearInteriorLightResult = E_NOT_OK;
uint32 CanTest_CanTxUpdateCounter = 0U;
uint32 CanTest_CanTxSkipCounter = 0U;
Com_StatusType CanTest_ComStatus = COM_UNINIT;
EcuM_StateType CanTest_EcuMState = ECUM_STATE_STARTUP;
Std_ReturnType CanTest_EcuMGetStateResult = E_NOT_OK;
ComM_InitStatusType CanTest_ComMStatus = COMM_UNINIT;
Std_ReturnType CanTest_ComMGetStatusResult = E_NOT_OK;
Std_ReturnType CanTest_ComMRequestResult = E_NOT_OK;
boolean CanTest_ComMCommunicationAllowed = FALSE;
ComM_ModeType CanTest_ComMCurrentMode = COMM_NO_COMMUNICATION;
Std_ReturnType CanTest_ComMCurrentModeResult = E_NOT_OK;
ComM_ModeType CanTest_CanSMCurrentMode = COMM_NO_COMMUNICATION;
Std_ReturnType CanTest_CanSMCurrentModeResult = E_NOT_OK;
CanIf_ControllerModeType CanTest_CanIfControllerMode = CANIF_CS_UNINIT;
Std_ReturnType CanTest_CanIfControllerModeResult = E_NOT_OK;
CanIf_PduGetModeType CanTest_CanIfPduMode = CANIF_GET_OFFLINE;
Std_ReturnType CanTest_CanIfPduModeResult = E_NOT_OK;
uint8 CanTest_Can1En = 0U;
uint8 CanTest_Can1Nerr = 0U;
uint8 CanTest_Can1Nstb = 0U;

void CanTest_Init(void)
{
  (void)EcuM_RequestRUN(EcuMConf_EcuMFixedUserConfig_EcuMFixedUserConfig);
  ComM_CommunicationAllowed(ComMConf_ComMChannel_CN_CAN00_5e566ad9, TRUE);
  CanTest_ComMCommunicationAllowed = TRUE;
  CanTest_ComMRequestResult =
      ComM_RequestComMode(ComMConf_ComMUser_CN_CAN00_06ecbb07,
          COMM_FULL_COMMUNICATION);
}

void CanTest_RunOnce(void)
{
  CanTest_Can1En = Dio_ReadChannel(DioConf_DioChannel_DioChannel_Can1En);
  CanTest_Can1Nerr = Dio_ReadChannel(DioConf_DioChannel_DioChannel_Can1Nerr);
  CanTest_Can1Nstb = Dio_ReadChannel(DioConf_DioChannel_DioChannel_Can1Nstb);
  CanTest_CanTxLampCnt++;
  CanTest_CanTxRearInteriorLight =
      (CanTest_CanTxRearInteriorLight == FALSE) ? TRUE : FALSE;

  CanTest_ComStatus = Com_GetStatus();
  CanTest_EcuMGetStateResult = EcuM_GetState(&CanTest_EcuMState);
  CanTest_ComMGetStatusResult = ComM_GetStatus(&CanTest_ComMStatus);
  CanTest_ComMCurrentModeResult =
      ComM_GetCurrentComMode(ComMConf_ComMUser_CN_CAN00_06ecbb07,
          &CanTest_ComMCurrentMode);
  CanTest_CanSMCurrentModeResult =
      CanSM_GetCurrentComMode(ComMConf_ComMChannel_CN_CAN00_5e566ad9,
          &CanTest_CanSMCurrentMode);
  CanTest_CanIfControllerModeResult =
      CanIf_GetControllerMode(0u, &CanTest_CanIfControllerMode);
  CanTest_CanIfPduModeResult = CanIf_GetPduMode(0u, &CanTest_CanIfPduMode);

  if (CanTest_ComStatus == COM_INIT)
  {
    CanTest_CanTxLampCntResult =
        Com_SendSignal(
            ComConf_ComSignal_sig_LampCnt_omsg_MyECU_Lamp_oCAN00_f37e68ea_Tx,
            &CanTest_CanTxLampCnt);
    CanTest_CanTxRearInteriorLightResult =
        Com_SendSignal(
            ComConf_ComSignal_sig_RearInteriorLight_omsg_Transmit_oCAN00_49a633c1_Tx,
            &CanTest_CanTxRearInteriorLight);
    CanTest_CanTxUpdateCounter++;
  }
  else
  {
    CanTest_CanTxSkipCounter++;
  }
}
