#include "IOHwAbCompressor.h"

FUNC(void,AUTOMATIC) AdjustCompressorControl(VAR(void,AUTOMATIC)){
    VAR(uint16,AUTOMATIC) compressorRatio;
    Rte_RP_AdjustCompressor_ControlCompressor(compressorRatio);
    Pwm_SetDutyCycle(PWM_CHANNEL1,compressorRatio);
}
