#include "IOHwAbFan.h"

FUNC(Std_ReturnType,AUTOMATIC) AdjustFanControl(VAR(uint16,AUTOMATIC) fanR){
    Pwm_SetDutyCycle(PWM_CHANNEL0,fanR);
    return E_OK;
}
