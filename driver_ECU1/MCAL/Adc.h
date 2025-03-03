#ifndef ADC_H
#define ADC_H

#include "Std_Types.h"
#include "Compiler.h"

FUNC(uint16,AUTOMATIC) Adc_ReadChannel(VAR(char,AUTOMATIC) channel);  // Đọc giá trị ADC từ cảm biến nhiệt độ

#endif /* ADC_H */
