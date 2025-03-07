/******************************************************************************/  
/* Copyright   : FPT Software Corporation                                     */  
/* System Name : AUTOSAR Application Layer                                    */  
/* File Name   : Adc.c                                                        */  
/* Contents    : Ecu Configuration(Ecuc)                                      */  
/* Author      : DN24_FR_AUTOSAR_02_TRUNG_LONG_NINH                           */  
/* Note        :                                                              */  
/******************************************************************************/ 

/*----------------------------------------------------------------------------*/
/* include headers                                                            */
/*----------------------------------------------------------------------------*/

#include "Adc.h"

/*----------------------------------------------------------------------------*/
/* functions and function style macros                                        */
/*----------------------------------------------------------------------------*/

/******************************************************************************/  
/* ModuleID    :                                                              */  
/* ServiceID   :                                                              */  
/* Name        : Adc_ReadChannel                                              */  
/* Param       : channel - ADC channel to be read                             */  
/* Return      : uint16 - ADC value corresponding to the selected channel     */  
/* Contents    : Reads the value from the specified ADC channel and returns   */  
/*               a simulated ADC reading based on the channel number.         */  
/* Author      : DN24_FR_AUTOSAR_02_TRUNG_LONG_NINH                           */  
/* Note        : This is a mock implementation for ADC reading.               */  
/******************************************************************************/ 
FUNC(uint16,AUTOMATIC) Adc_ReadChannel(VAR(char,AUTOMATIC) channel) {
    if(channel == 1){
        return 512;
    }
    else{
        return 32;
    }
}

/* End of Adc.h */