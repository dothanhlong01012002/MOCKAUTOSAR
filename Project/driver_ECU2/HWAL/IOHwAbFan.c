#include "IOHwAbFan.h"

FUNC(void,AUTOMATIC) AdjustFan_Runable(VAR(void,AUTOMATIC)){
    VAR(uint16,AUTOMATIC) fanRatio;
    Rte_RP_AdjustFan_ControlFan(fanRatio);
    Pwm_SetDutyCycle(PWM_CHANNEL0,fanRatio);
}
