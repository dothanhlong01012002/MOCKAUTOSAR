#include "RTE.h"

#define TEMP_SPEED_SIGNAL_ID    10

VAR(uint8,AUTOMATIC) ExpectedTemp;
VAR(uint8,AUTOMATIC) TemperatureValue;
VAR(uint16,AUTOMATIC) EngineSpeedValue;
VAR(uint16,AUTOMATIC) FanRatio;
VAR(uint16,AUTOMATIC) CompressorRatio;
VAR(uint16,AUTOMATIC) ErrorCode;

FUNC(void,AUTOMATIC) Rte_EV_ComReceive(VAR(void,AUTOMATIC)){
    P2VAR(uint8,AUTOMATIC,AUTOMATIC) DataPtr;
    Com_ReceiveSignal(TEMP_SPEED_SIGNAL_ID,DataPtr);
    TemperatureValue = DataPtr[0];
    EngineSpeedValue = ((uint16)DataPtr[1] << 8) + DataPtr[2];
}
FUNC(void,AUTOMATIC) Rte_EV_Main(VAR(void,AUTOMATIC)){
    CoolingControl_Runable();
}
FUNC(void,AUTOMATIC) Rte_EV_Component(VAR(void,AUTOMATIC)){
    FanControl_Runable();
    CompressorControl_Runable();
}
FUNC(void,AUTOMATIC) Rte_EV_Actuator(VAR(void,AUTOMATIC)){
    AdjustFanControl();
    AdjustCompressorControl();
}
FUNC(void,AUTOMATIC) Rte_EV_GetError(VAR(void,AUTOMATIC)){
    GetNVM_Runnable();
}
FUNC(void,AUTOMATIC) Rte_EV_WriteError(VAR(void,AUTOMATIC)){
    SaveNVM_Runnable();
}

FUNC(Std_ReturnType,AUTOMATIC) Rte_Write_PP_ComData_TempSpeedValue(VAR(uint16,AUTOMATIC) Tempvalue, VAR(uint16,AUTOMATIC) SpeedValue){
    TemperatureValue = Tempvalue;
    EngineSpeedValue = SpeedValue;
    return E_OK;
}

FUNC(Std_ReturnType,AUTOMATIC) Rte_Read_RP_ComData_TempSpeedValue(P2VAR(uint16,AUTOMATIC,AUTOMATIC) Tempvalue, P2VAR(uint16,AUTOMATIC,AUTOMATIC) SpeedValue){
    if(Tempvalue!= NULL&&SpeedValue!= NULL){
        *Tempvalue = TemperatureValue;
        *SpeedValue = EngineSpeedValue;
        return E_OK;
    }
    return E_NOT_OK;
}

FUNC(Std_ReturnType,AUTOMATIC) Rte_Write_PP_FanData_FanValue(VAR(uint16,AUTOMATIC) FanV){
    FanRatio = FanV;
    return E_OK;
}

FUNC(Std_ReturnType,AUTOMATIC) Rte_Read_RP_FanData_FanValue(P2VAR(uint16,AUTOMATIC,AUTOMATIC) FanV){
    if(FanV!= NULL){
        *FanV = FanRatio;
        return E_OK;
    }
    return E_NOT_OK;
}

FUNC(Std_ReturnType,AUTOMATIC) Rte_Write_PP_CompressorData_CompressorValue(VAR(uint16,AUTOMATIC) CompressorV){
    CompressorRatio = CompressorV;
    return E_OK;
}

FUNC(Std_ReturnType,AUTOMATIC) Rte_Read_RP_CompressorData_CompressorValue(P2VAR(uint16,AUTOMATIC,AUTOMATIC) CompressorV){
    if(CompressorV!= NULL){
        *CompressorV = CompressorRatio;
        return E_OK;
    }
    return E_NOT_OK;
}

FUNC(Std_ReturnType,AUTOMATIC) Rte_Read_RP_PARAM_ExpectedTemperature(P2VAR(uint16,AUTOMATIC,AUTOMATIC) ExTemp){
    if(ExTemp != NULL){
        *ExTemp = ExpectedTemp;
        return E_OK; 
    }
    return E_NOT_OK;
}

FUNC(Std_ReturnType,AUTOMATIC) Rte_Write_PP_PARAM_ExpectedTemperature(VAR(uint16,AUTOMATIC) ExTemp){
    ExpectedTemp = ExTemp;
    return E_OK;
}

FUNC(Std_ReturnType,AUTOMATIC) Rte_Call_PP_AdjustFan_ControlFan(P2VAR(uint16,AUTOMATIC,AUTOMATIC) FanR){
    return Rte_RP_AdjustFan_ControlFan(*FanR);
}

FUNC(Std_ReturnType,AUTOMATIC) Rte_RP_AdjustFan_ControlFan(VAR(uint16,AUTOMATIC) FanR){
    // SetFanPWM(FanR);
}

FUNC(Std_ReturnType,AUTOMATIC) Rte_Call_PP_AdjustCompressor_ControlCompressor(P2VAR(uint16,AUTOMATIC,AUTOMATIC) CompressorR){
    return Rte_RP_AdjustCompressor_ControlCompressor(*CompressorR);
}

FUNC(Std_ReturnType,AUTOMATIC) Rte_RP_AdjustCompressor_ControlCompressor(VAR(uint16,AUTOMATIC) CompressorR){
    // SetCompressorPWM(CompressorR);
}

FUNC(Std_ReturnType,AUTOMATIC) Rte_Call_PP_NVData_WriteError(VAR(uint32,AUTOMATIC) ErrorCodeV){
    return Rte_Call_RP_SaveNVData_NVM(ErrorCodeV);
}

FUNC(Std_ReturnType,AUTOMATIC) Rte_Call_RP_NVData_GetError(P2VAR(uint32,AUTOMATIC,AUTOMATIC) ErrorCodeV){
    return Rte_Call_RP_GetNVData_NVM(ErrorCodeV);
}

FUNC(Std_ReturnType,AUTOMATIC) Rte_PP_SaveNVData_NVM(VAR(uint32,AUTOMATIC) ErrorCodeV){
    return MemoryManager_WriteErrorCode(ErrorCodeV);
}

FUNC(Std_ReturnType,AUTOMATIC) Rte_Call_RP_SaveNVData_NVM(VAR(uint32,AUTOMATIC) ErrorCodeV){
    return Rte_PP_SaveNVData_NVM(ErrorCodeV);
}

FUNC(Std_ReturnType,AUTOMATIC) Rte_PP_GetNVData_NVM(P2VAR(uint32,AUTOMATIC,AUTOMATIC) ErrorCodeV){
    return MemoryManager_ReadErrorCode(ErrorCodeV);
}

FUNC(Std_ReturnType,AUTOMATIC) Rte_Call_RP_GetNVData_NVM(P2VAR(uint32,AUTOMATIC,AUTOMATIC) ErrorCodeV){
    return Rte_PP_GetNVData_NVM(ErrorCodeV);
}

FUNC(Std_ReturnType,AUTOMATIC) Rte_Call_RP_ERROR_ReportDiagnosticResult(VAR(uint32,AUTOMATIC) eventID, VAR(uint8,AUTOMATIC) status){
    return Rte_PP_ERROR_ReportDiagnosticResult(eventID,status);
}

FUNC(Std_ReturnType,AUTOMATIC) Rte_PP_ERROR_ReportDiagnosticResult(VAR(uint32,AUTOMATIC) eventID, VAR(uint8,AUTOMATIC) status){
    SetEventStatus(eventID, status);
}

