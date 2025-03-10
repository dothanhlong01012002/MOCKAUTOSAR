/******************************************************************************/  
/* Copyright   : FPT Software Corporation                                     */  
/* System Name : AUTOSAR Application Layer                                    */  
/* File Name   : IOHwAbFan.c                                                  */  
/* Contents    : Ecu Configuration(Ecuc)                                      */  
/* Author      : DN24_FR_AUTOSAR_02_TRUNG_LONG_NINH                           */  
/* Note        :                                                              */  
/******************************************************************************/  

/*----------------------------------------------------------------------------*/
/* include headers                                                            */
/*----------------------------------------------------------------------------*/

#include "IOHwAbFan.h"

/*----------------------------------------------------------------------------*/
/* functions and function style macros                                        */
/*----------------------------------------------------------------------------*/

/******************************************************************************/  
/* ModuleID    :                                                              */  
/* ServiceID   :                                                              */  
/* Name        : AdjustFanControl                                             */  
/* Param       : fanR - Duty cycle value for the fan control                  */  
/* Return      : Std_ReturnType                                               */  
/*               - E_OK     : Adjustment successful                           */  
/*               - E_NOT_OK : Adjustment failed                               */  
/* Contents    : Sets the PWM duty cycle for the fan control based on the     */  
/*               provided value.                                              */  
/* Author      : DN24_FR_AUTOSAR_02_TRUNG_LONG_NINH                           */  
/* Note        : Function interacts with PWM module to control the fan.       */  
/******************************************************************************/  
FUNC(Std_ReturnType,AUTOMATIC) AdjustFanControl(VAR(uint16,AUTOMATIC) fanR){
    Pwm_SetDutyCycle(PWM_CHANNEL0,fanR);
    return E_OK;
}

/* End of IOHwAbFan.c */