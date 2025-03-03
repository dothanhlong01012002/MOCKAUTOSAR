#include "IOHwAbTemperatureSensor.h"

FUNC(void,AUTOMATIC) ReadVoltage_Runable(VAR(void,AUTOMATIC)) {
    VAR(uint16,AUTOMATIC) adcValue = Adc_ReadChannel(0);  // Đọc từ ADC channel 0
    Rte_Write_PP_Voltage_TemperatureValue(adcValue);  // Gửi lên RTE
}