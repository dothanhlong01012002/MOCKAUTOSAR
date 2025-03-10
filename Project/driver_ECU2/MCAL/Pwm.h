/******************************************************************************/  
/* Copyright   : FPT Software Corporation                                     */  
/* System Name : AUTOSAR Application Layer                                    */  
/* File Name   : Pwm.h                                                        */  
/* Contents    : Ecu Configuration(Ecuc)                                      */  
/* Author      : DN24_FR_AUTOSAR_02_TRUNG_LONG_NINH                           */  
/* Note        :                                                              */  
/******************************************************************************/  

#ifndef MCAL_PWM_H
#define MCAL_PWM_H

/*----------------------------------------------------------------------------*/
/* include headers                                                            */
/*----------------------------------------------------------------------------*/

#include"Std_Types.h"
#include "Compiler.h"

typedef uint8 Pwm_ChannelType;

/*----------------------------------------------------------------------------*/
/* function prototype declarations                                            */
/*----------------------------------------------------------------------------*/

FUNC(void,AUTOMATIC) Pwm_SetDutyCycle(VAR(Pwm_ChannelType,AUTOMATIC) ChannelNumber,VAR(uint16,AUTOMATIC) DutyCycle);  

#endif /* MCAL_PWM_H */
/* End of Pwm.h */
