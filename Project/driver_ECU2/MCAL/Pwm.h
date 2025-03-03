// MCAL_PWM.h - Header file cho MCAL PWM
#ifndef MCAL_PWM_H
#define MCAL_PWM_H
#include"Std_Types.h"
#include "Compiler.h"

typedef uint8 Pwm_ChannelType;

FUNC(void,AUTOMATIC) Pwm_SetDutyCycle(VAR(Pwm_ChannelType,AUTOMATIC) ChannelNumber,VAR(uint16,AUTOMATIC) DutyCycle);  

#endif // MCAL_PWM_H
