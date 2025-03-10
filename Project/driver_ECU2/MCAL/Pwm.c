/******************************************************************************/  
/* Copyright   : FPT Software Corporation                                     */  
/* System Name : AUTOSAR Application Layer                                    */  
/* File Name   : Pwm.c                                                        */  
/* Contents    : Ecu Configuration(Ecuc)                                      */  
/* Author      : DN24_FR_AUTOSAR_02_TRUNG_LONG_NINH                           */  
/* Note        :                                                              */  
/******************************************************************************/  

/*----------------------------------------------------------------------------*/
/* include headers                                                            */
/*----------------------------------------------------------------------------*/

#include "Pwm.h"

/*----------------------------------------------------------------------------*/
/* functions and function style macros                                        */
/*----------------------------------------------------------------------------*/

/******************************************************************************/  
/* ModuleID    :                                                              */  
/* ServiceID   :                                                              */  
/* Name        : Pwm_SetDutyCycle                                             */  
/* Param       : ChannelNumber - PWM channel number to be set                 */  
/*               DutyCycle - Duty cycle value to be set                       */  
/* Return      : void                                                         */  
/* Contents    : Sets the duty cycle for the specified PWM channel            */  
/* Author      : DN24_FR_AUTOSAR_02_TRUNG_LONG_NINH                           */  
/* Note        : Function currently has no implemented behavior for the PWM   */  
/*               channels.                                                    */  
/******************************************************************************/     
FUNC(void,AUTOMATIC) Pwm_SetDutyCycle(VAR(Pwm_ChannelType,AUTOMATIC) ChannelNumber,VAR(uint16,AUTOMATIC) DutyCycle)
{
    if (ChannelNumber == 0) {

    } else if (ChannelNumber == 1) {
        
    }
}

/* End of Pwm.c */
