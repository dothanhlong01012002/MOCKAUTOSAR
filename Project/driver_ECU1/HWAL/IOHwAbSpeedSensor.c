#include "IOHwAbSpeedSensor.h"

FUNC(void,AUTOMATIC) ReadPulse_Runable(VAR(void,AUTOMATIC)) {
    VAR(uint16,AUTOMATIC) adcValue = Adc_ReadChannel(0);  // Read from ADC channel 0
    Rte_Write_PP_Pulse_EngineSpeedValue(adcValue);  // Send to RTE
}