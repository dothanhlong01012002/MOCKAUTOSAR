/******************************************************************************/  
/* Copyright   : FPT Software Corporation                                     */  
/* System Name : AUTOSAR Application Layer                                    */  
/* File Name   : IOHwAbTemperatureSensor.h                                    */  
/* Contents    : Ecu Configuration(Ecuc)                                      */  
/* Author      : DN24_FR_AUTOSAR_02_TRUNG_LONG_NINH                           */  
/* Note        :                                                              */  
/******************************************************************************/ 

#ifndef  IOHWABTEMPERATURESENSOR_H
#define IOHWABTEMPERATURESENSOR_H

/*----------------------------------------------------------------------------*/
/* include headers                                                            */
/*----------------------------------------------------------------------------*/

#include "Adc.h"
#include "RTE.h"
#include "Std_Types.h"
#include "Compiler.h"

/*----------------------------------------------------------------------------*/
/* function prototype declarations                                            */
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
FUNC(void,AUTOMATIC) ReadVoltage_Runable(VAR(void,AUTOMATIC));

#endif /* IOHWABTEMPERATURESENSOR_H */
/* End of IOHwAbTemperatureSensor.h */