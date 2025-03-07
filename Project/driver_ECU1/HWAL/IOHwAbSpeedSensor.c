/******************************************************************************/  
/* Copyright   : FPT Software Corporation                                     */  
/* System Name : AUTOSAR Application Layer                                    */  
/* File Name   : IOHwAbCan.c                                                  */  
/* Contents    : Ecu Configuration(Ecuc)                                      */  
/* Author      : DN24_FR_AUTOSAR_02_TRUNG_LONG_NINH                           */  
/* Note        :                                                              */  
/******************************************************************************/ 

/*----------------------------------------------------------------------------*/
/* include headers                                                            */
/*----------------------------------------------------------------------------*/

#include "IOHwAbSpeedSensor.h"

/*----------------------------------------------------------------------------*/
/* functions and function style macros                                        */
/*----------------------------------------------------------------------------*/

/******************************************************************************/  
/* ModuleID    :                                                              */  
/* ServiceID   :                                                              */  
/* Name        : ReadPulse_Runable                                            */  
/* Param       : void                                                         */  
/* Return      : void                                                         */  
/* Contents    : Reads ADC value from channel 0 and writes it to RTE          */  
/* Author      : DN24_FR_AUTOSAR_02_TRUNG_LONG_NINH                           */  
/* Note        : Function interacts with the ADC driver and RTE               */  
/******************************************************************************/  
FUNC(void,AUTOMATIC) ReadPulse_Runable(VAR(void,AUTOMATIC)) {
    VAR(uint16,AUTOMATIC) adcValue = Adc_ReadChannel(1);  // Read from ADC channel 0
    Rte_Write_PP_Pulse_EngineSpeedValue(adcValue);  // Send to RTE
}

/* End of IOHwAbSpeedSensor.c */