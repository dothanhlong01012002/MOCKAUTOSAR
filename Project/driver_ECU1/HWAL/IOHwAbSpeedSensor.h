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

FUNC(void,AUTOMATIC) ReadPulse_Runable(VAR(void,AUTOMATIC));

#endif /* IOHWABSPEEDSENSOR_H */
/* End of IOHwAbSpeedSensor.h */