/******************************************************************************/  
/* Copyright   : FPT Software Corporation                                     */  
/* System Name : AUTOSAR Application Layer                                    */  
/* File Name   : TemperatureSensorSWC.h                                       */  
/* Contents    : Ecu Configuration(Ecuc)                                      */  
/* Author      : DN24_FR_AUTOSAR_02_TRUNG_LONG_NINH                           */  
/* Note        :                                                              */  
/******************************************************************************/ 

#ifndef  TEMPERATURESENSOR_H
#define TEMPERATURESENSOR_H

/*----------------------------------------------------------------------------*/
/* include headers                                                            */
/*----------------------------------------------------------------------------*/

#include "RTE.h"
#include "Std_Types.h"

/*----------------------------------------------------------------------------*/
/* function prototype declarations                                            */
/*----------------------------------------------------------------------------*/

/******************************************************************************/  
/* ModuleID    :                                                              */  
/* ServiceID   :                                                              */  
/* Name        : ReadTemperature_Runable                                      */  
/* Param       : void                                                         */  
/* Return      : void                                                         */  
/* Contents    : Reads temperature voltage, adjusts value, and writes output  */  
/* Author      : DN24_FR_AUTOSAR_02_TRUNG_LONG_NINH                           */  
/* Note        :                                                              */  
/******************************************************************************/  
FUNC(void,AUTOMATIC) ReadTemperature_Runable(VAR(void,AUTOMATIC));

#endif /* TEMPERATURESENSOR_H */
/* End of TemperatureSensorSWC.h */