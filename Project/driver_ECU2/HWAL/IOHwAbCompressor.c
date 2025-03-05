#include "IOHwAbCompressor.h"

FUNC(Std_ReturnType,AUTOMATIC) AdjustCompressorControl(VAR(uint16,AUTOMATIC) compressorR){
    Pwm_SetDutyCycle(PWM_CHANNEL1,compressorR);
    return E_OK;
}
