#include "TemperatureSensorSWC.h"

FUNC(void,AUTOMATIC) ReadTemperature_Runable(VAR(void,AUTOMATIC)){
    VAR(uint16,AUTOMATIC) ActualTempValue;
    Rte_Read_RP_Voltage_TemperatureValue(&ActualTempValue);
    ActualTempValue +=32;
    Rte_Write_PP_Temperature_TempValue(ActualTempValue);
}

