#include "Rte_AppReadSensor.h"

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
