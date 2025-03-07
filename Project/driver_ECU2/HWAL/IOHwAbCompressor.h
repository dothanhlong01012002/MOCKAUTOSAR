#ifndef  IOHWABCOMPRESSOR_H
#define  IOHWABCOMPRESSOR_H
#include "Pwm.h"
#include "RTE_COM.h"
#include "Compiler.h"

#define PWM_CHANNEL1 1

FUNC(Std_ReturnType,AUTOMATIC) AdjustCompressorControl(VAR(uint16,AUTOMATIC) compressorR);

#endif