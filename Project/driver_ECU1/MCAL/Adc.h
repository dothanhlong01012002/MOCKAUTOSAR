/******************************************************************************/  
/* Copyright   : FPT Software Corporation                                     */  
/* System Name : AUTOSAR Application Layer                                    */  
/* File Name   : Adc.h                                                        */  
/* Contents    : Ecu Configuration(Ecuc)                                      */  
/* Author      : DN24_FR_AUTOSAR_02_TRUNG_LONG_NINH                           */  
/* Note        :                                                              */  
/******************************************************************************/ 

#ifndef ADC_H
#define ADC_H

/*----------------------------------------------------------------------------*/
/* include headers                                                            */
/*----------------------------------------------------------------------------*/

#include "Std_Types.h"
#include "Compiler.h"

/*----------------------------------------------------------------------------*/
/* function prototype declarations                                            */
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
FUNC(uint16,AUTOMATIC) Adc_ReadChannel(VAR(char,AUTOMATIC) channel);  // Đọc giá trị ADC từ cảm biến nhiệt độ

#endif /* ADC_H */
/* End of Adc.h */