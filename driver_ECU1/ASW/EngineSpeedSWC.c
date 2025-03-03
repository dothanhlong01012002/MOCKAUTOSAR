#include "EngineSpeedSWC.h"

FUNC(void,AUTOMATIC) ReadSpeed_Runable(VAR(void,AUTOMATIC)){
    VAR(uint16,AUTOMATIC) EngineSpeedTemp;
    Rte_Read_RP_Pulse_EngineSpeedValue(&EngineSpeedTemp);
    EngineSpeedTemp *= 1000;
    Rte_Write_PP_Speed_SpeedValue(EngineSpeedTemp);
}

