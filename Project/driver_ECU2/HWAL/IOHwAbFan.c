#include "IOHwAbFan.h"

FUNC(void,AUTOMATIC) AdjustFanControl(VAR(void,AUTOMATIC)){
    VAR(uint16,AUTOMATIC) fanRatio;
    Rte_RP_AdjustFan_ControlFan(fanRatio);
    Pwm_SetDutyCycle(PWM_CHANNEL0,fanRatio);
}
