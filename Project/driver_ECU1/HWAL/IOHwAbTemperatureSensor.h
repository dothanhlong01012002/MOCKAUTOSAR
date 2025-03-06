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

FUNC(void,AUTOMATIC) ReadVoltage_Runable(VAR(void,AUTOMATIC));

#endif /* IOHWABTEMPERATURESENSOR_H */
/* End of IOHwAbTemperatureSensor.h */