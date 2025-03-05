#ifndef  IOHWABFAN_H
#define  IOHWABFAN_H
#include "Pwm.h"
#include "RTE.h"
#include "Compiler.h"

#define PWM_CHANNEL0 0

FUNC(Std_ReturnType,AUTOMATIC) AdjustFanControl(VAR(uint16,AUTOMATIC) fanR);

#endif