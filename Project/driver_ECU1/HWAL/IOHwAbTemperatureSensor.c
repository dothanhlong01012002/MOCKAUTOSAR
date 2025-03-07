/******************************************************************************/  
/* Copyright   : FPT Software Corporation                                     */  
/* System Name : AUTOSAR Application Layer                                    */  
/* File Name   : IOHwAbTemperatureSensor.c                                    */  
/* Contents    : Ecu Configuration(Ecuc)                                      */  
/* Author      : DN24_FR_AUTOSAR_02_TRUNG_LONG_NINH                           */  
/* Note        :                                                              */  
/******************************************************************************/ 

/*----------------------------------------------------------------------------*/
/* include headers                                                            */
/*----------------------------------------------------------------------------*/

#include "IOHwAbTemperatureSensor.h"

/*----------------------------------------------------------------------------*/
/* functions and function style macros                                        */
/*----------------------------------------------------------------------------*/

/******************************************************************************/  
/* ModuleID    :                                                              */  
/* ServiceID   :                                                              */  
/* Name        : ReadVoltage_Runable                                          */  
/* Param       : void                                                         */  
/* Return      : void                                                         */  
/* Contents    : Reads ADC value from channel 0 and writes it to RTE          */  
/* Author      : DN24_FR_AUTOSAR_02_TRUNG_LONG_NINH                           */  
/* Note        : Function interacts with the ADC driver and RTE               */  
/******************************************************************************/  
FUNC(void,AUTOMATIC) ReadVoltage_Runable(VAR(void,AUTOMATIC)) {
    VAR(uint16,AUTOMATIC) adcValue = Adc_ReadChannel(0);  // Đọc từ ADC channel 0
    Rte_Write_PP_Voltage_TemperatureValue(adcValue);  // Gửi lên RTE
}

/* End of IOHwAbTemperatureSensor.c */