#include "RTE_COM.h"
VAR(uint16,AUTOMATIC) TemperatureValue;
VAR(uint16,AUTOMATIC) EngineSpeedValue;
VAR(uint16,AUTOMATIC) FanRatio;
VAR(uint16,AUTOMATIC) CompressorRatio;
VAR(uint8,AUTOMATIC) ExpectedTemp;

FUNC(Std_ReturnType,AUTOMATIC) Rte_Read_RP_ComData_TempSpeedValue(P2VAR(uint16,AUTOMATIC,AUTOMATIC) Tempvalue, P2VAR(uint16,AUTOMATIC,AUTOMATIC) SpeedValue){
    if(Tempvalue!= NULL&&SpeedValue!= NULL){
        *Tempvalue = TemperatureValue;
        *SpeedValue = EngineSpeedValue;
        return E_OK;
    }
    return E_NOT_OK;
}

FUNC(Std_ReturnType,AUTOMATIC) Rte_Write_PP_ComData_TempSpeedValue(VAR(uint16,AUTOMATIC) Tempvalue, VAR(uint16,AUTOMATIC) SpeedValue){
    TemperatureValue = Tempvalue;
    EngineSpeedValue = SpeedValue;
    return E_OK;
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

FUNC(Std_ReturnType,AUTOMATIC) Rte_Call_RP_AdjustFan_ControlFan(VAR(uint16,AUTOMATIC) FanR){
    return AdjustFanControl(FanR);
}

FUNC(Std_ReturnType,AUTOMATIC) Rte_Call_RP_AdjustCompressor_ControlCompressor(VAR(uint16,AUTOMATIC) CompressorR){
    return AdjustCompressorControl(CompressorR);
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

