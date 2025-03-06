#include "RTE.h"
#include "Can.h"

#define TEMP_SPEED_SIGNAL_ID    10

VAR(uint8,AUTOMATIC) ExpectedTemp;
VAR(uint8,AUTOMATIC) TemperatureValue;
VAR(uint16,AUTOMATIC) EngineSpeedValue;
VAR(uint16,AUTOMATIC) FanRatio;
VAR(uint16,AUTOMATIC) CompressorRatio;
VAR(uint16,AUTOMATIC) ErrorCode;
VAR(NvM_DataBuffer,AUTOMATIC) Data;


FUNC(void,AUTOMATIC) Rte_EV_ComReceive(VAR(void,AUTOMATIC)){
    P2VAR(uint8,AUTOMATIC,AUTOMATIC) DataPtr;
    uint8 DataBuffer[3];  // Cấp phát bộ nhớ cho 3 byte dữ liệu
    DataPtr = DataBuffer; // Gán con trỏ đến vùng bộ nhớ đã cấp phát
    Handle_Can_Interrupt();
    Com_ReceiveSignal(TEMP_SPEED_SIGNAL_ID,DataPtr);
    TemperatureValue = DataPtr[0];
    EngineSpeedValue = ((uint16)DataPtr[1] << 8) + DataPtr[2];
}
FUNC(Std_ReturnType,AUTOMATIC) Rte_EV_Main(VAR(void,AUTOMATIC)){
    return CoolingControl_Runable();
}
FUNC(void,AUTOMATIC) Rte_EV_Component(VAR(void,AUTOMATIC)){
    FanControl_Runable();
    CompressorControl_Runable();
}
FUNC(void,AUTOMATIC) Rte_EV_GetError(VAR(void,AUTOMATIC)){
    HandleNVM_Runable(NV_READ_ERROR);
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

FUNC(Std_ReturnType,AUTOMATIC) Rte_Call_RP_AdjustFan_ControlFan(VAR(uint16,AUTOMATIC) FanR){
    return AdjustFanControl(FanR);
}

FUNC(Std_ReturnType,AUTOMATIC) Rte_Call_RP_AdjustCompressor_ControlCompressor(VAR(uint16,AUTOMATIC) CompressorR){
    return AdjustCompressorControl(CompressorR);
}

FUNC(Std_ReturnType,AUTOMATIC) Rte_Call_RP_NVData_CallServerFunction(VAR(uint8,AUTOMATIC) requestID){
    Rte_Call_RP_NVHandle_SeverHandle(requestID);
    return E_OK;
}

FUNC(Std_ReturnType,AUTOMATIC) Rte_Call_RP_NVHandle_SeverHandle(VAR(uint8,AUTOMATIC) requestID){
    return HandleNVM_Runable(requestID);
}

FUNC(Std_ReturnType,AUTOMATIC) Rte_Call_RP_ERROR_ReportDiagnosticResult(VAR(Dem_EventIdType,AUTOMATIC) eventID, VAR(Dem_EventStatus,AUTOMATIC) status){
    Dem_SetEventStatus(eventID, status);
    return E_OK;
}

FUNC(Std_ReturnType,AUTOMATIC) Rte_Call_RP_ERROR_SetEvent(VAR(Dem_EventIdType,AUTOMATIC) eventID, VAR(Dem_EventStatus,AUTOMATIC) status){
    return E_OK;
}


//WDG////////////////////////
FUNC(Std_ReturnType, AUTOMATIC) Rte_Call_RP_WdgM_Init(VAR(const WdgM_ConfigType*, AUTOMATIC) ConfigPtr){
    if (ConfigPtr != NULL) {
        WdgM_Init(ConfigPtr);
    }
    return E_OK;
}

FUNC(void, AUTOMATIC) Rte_Call_RP_WdgM_DeInit(void){
    WdgM_DeInit();
}

FUNC(Std_ReturnType, AUTOMATIC) Rte_Call_RP_WdgM_SetMode(VAR(WdgIf_ModeType, AUTOMATIC) Mode){
    return WdgM_SetMode(Mode);
}

FUNC(Std_ReturnType, AUTOMATIC) Rte_Call_RP_WdgM_GetMode(VAR(WdgIf_ModeType, AUTOMATIC) Mode){
    return WdgM_GetMode(&Mode);
}

FUNC(void, AUTOMATIC) Rte_Call_RP_WdgM_PerformReset(void){
    //WdgM_PerformReset(); 
    SystickCounter = 0;
}

FUNC(Std_ReturnType, AUTOMATIC) Rte_Call_RP_WdgM_CheckpointReached(VAR(WdgM_SupervisedEntityIdType, AUTOMATIC) SEID,VAR(WdgM_CheckpointIdType, AUTOMATIC) CheckpointID){
    return WdgM_CheckpointReached(SEID, CheckpointID);
}
