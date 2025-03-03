#include "FanControlSWC.h"

FUNC(void,AUTOMATIC) FanControl_Runable(VAR(void,AUTOMATIC)) {
    VAR(uint16,AUTOMATIC) FanR;
    Rte_Read_RP_FanData_FanValue(&FanR);
    Rte_Call_PP_AdjustFan_ControlFan(&FanR);
}