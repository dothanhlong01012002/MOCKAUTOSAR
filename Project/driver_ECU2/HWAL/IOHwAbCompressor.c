/******************************************************************************/  
/* Copyright   : FPT Software Corporation                                     */  
/* System Name : AUTOSAR Application Layer                                    */  
/* File Name   : IOHwAbCompressor.c                                                  */  
/* Contents    : Ecu Configuration(Ecuc)                                      */  
/* Author      : DN24_FR_AUTOSAR_02_TRUNG_LONG_NINH                           */  
/* Note        :                                                              */  
/******************************************************************************/  

/*----------------------------------------------------------------------------*/
/* include headers                                                            */
/*----------------------------------------------------------------------------*/

#include "IOHwAbCompressor.h"

/*----------------------------------------------------------------------------*/
/* functions and function style macros                                        */
/*----------------------------------------------------------------------------*/

/******************************************************************************/  
/* ModuleID    :                                                              */  
/* ServiceID   :                                                              */  
/* Name        : AdjustCompressorControl                                      */  
/* Param       : compressorR - Duty cycle value for the compressor control    */  
/* Return      : Std_ReturnType                                               */  
/*               - E_OK     : Adjustment successful                           */  
/*               - E_NOT_OK : Adjustment failed                               */  
/* Contents    : Sets the PWM duty cycle for the compressor control based on  */  
/*               the provided value.                                          */  
/* Author      : DN24_FR_AUTOSAR_02_TRUNG_LONG_NINH                           */  
/* Note        : Function interacts with PWM module to control the compressor */  
/******************************************************************************/  
FUNC(Std_ReturnType,AUTOMATIC) AdjustCompressorControl(VAR(uint16,AUTOMATIC) compressorR){
    Pwm_SetDutyCycle(PWM_CHANNEL1,compressorR);
    return E_OK;
}

/* End of IOHwAbCompressor.c */