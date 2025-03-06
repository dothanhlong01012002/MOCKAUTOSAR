#include "RTE.h"

#define TEMP_SPEED_SIGNAL_ID    10

FUNC(void,AUTOMATIC) Rte_EV_ReadSensor(VAR(void,AUTOMATIC)){
    ReadPulse_Runable();
    ReadVoltage_Runable();
}

FUNC(void,AUTOMATIC) Rte_EV_DataHandle(VAR(void,AUTOMATIC)){
    ReadTemperature_Runable();
    ReadSpeed_Runable();
    VAR(uint8,AUTOMATIC) frameData[3];
    frameData[0] = (uint8)TempValue;
    frameData[1] = (uint8)(SpeedValue >> 8);
    frameData[2] = (uint8)(SpeedValue & 0xFF);
    Com_SendSignal(TEMP_SPEED_SIGNAL_ID,&frameData);
}

FUNC(Std_ReturnType,AUTOMATIC) Rte_Read_RP_Pulse_EngineSpeedValue(P2VAR(uint16,AUTOMATIC,AUTOMATIC) temp){
    if (temp != NULL) {
        *temp = EngineSpeedValue;  
        return E_OK;
    }
    return E_NOT_OK;
}

FUNC(Std_ReturnType,AUTOMATIC) Rte_Write_PP_Pulse_EngineSpeedValue(VAR(uint16,AUTOMATIC) temp){
    EngineSpeedValue = temp; 
    return E_OK;
}

FUNC(Std_ReturnType,AUTOMATIC) Rte_Write_PP_Speed_SpeedValue(VAR(uint16,AUTOMATIC) temp){
    SpeedValue = temp;
    return E_OK;
}

FUNC(Std_ReturnType,AUTOMATIC) Rte_Read_RP_Speed_SpeedValue(P2VAR(uint16,AUTOMATIC,AUTOMATIC) temp){
    if (temp != NULL) {
        *temp = SpeedValue;
        return E_OK;
    }
    return E_NOT_OK;
}


FUNC(Std_ReturnType,AUTOMATIC) Rte_Write_PP_Voltage_TemperatureValue(VAR(uint16,AUTOMATIC) temp){
    TemperatureValue = temp;
    return E_OK;
}

FUNC(Std_ReturnType,AUTOMATIC) Rte_Read_RP_Voltage_TemperatureValue(P2VAR(uint16,AUTOMATIC,AUTOMATIC) temp){
    if (temp != NULL) {
        *temp = TemperatureValue;  
        return E_OK;
    }
    return E_NOT_OK;
}

FUNC(Std_ReturnType,AUTOMATIC) Rte_Write_PP_Temperature_TempValue(VAR(uint16,AUTOMATIC) temp){
    TempValue = temp;
    return E_OK;
}

FUNC(Std_ReturnType,AUTOMATIC) Rte_Read_RP_Temperature_TempValue(P2VAR(uint16,AUTOMATIC,AUTOMATIC) temp){
    if (temp != NULL) {
        *temp = TempValue;
        return E_OK;
    }
    return E_NOT_OK;
}
