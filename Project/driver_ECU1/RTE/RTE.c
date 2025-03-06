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