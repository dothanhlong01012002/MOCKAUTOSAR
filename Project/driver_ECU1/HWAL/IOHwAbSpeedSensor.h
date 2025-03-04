/******************************************************************************/  
/* Copyright   : FPT Software Corporation                                     */  
/* System Name : AUTOSAR Application Layer                                    */  
/* File Name   : IOHwAbSpeedSensor.h                                          */  
/* Contents    : Ecu Configuration(Ecuc)                                      */  
/* Author      : DN24_FR_AUTOSAR_02_TRUNG_LONG_NINH                           */  
/* Note        :                                                              */  
/******************************************************************************/ 

/*----------------------------------------------------------------------------*/
/* include headers                                                            */
/*----------------------------------------------------------------------------*/

#ifndef  IOHWABSPEEDSENSOR_H
#define IOHWABSPEEDSENSOR_H
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
/* Name        : ReadPulse_Runable                                            */  
/* Param       : void                                                         */  
/* Return      : void                                                         */  
/* Contents    : Reads ADC value from channel 0 and writes it to RTE          */  
/* Author      : DN24_FR_AUTOSAR_02_TRUNG_LONG_NINH                           */  
/* Note        : Function interacts with the ADC driver and RTE               */  
/******************************************************************************/  
FUNC(void,AUTOMATIC) ReadPulse_Runable(VAR(void,AUTOMATIC));

#endif /* IOHWABSPEEDSENSOR_H */
/* End of IOHwAbSpeedSensor.h */