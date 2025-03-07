/******************************************************************************/  
/* Copyright   : FPT Software Corporation                                     */  
/* System Name : AUTOSAR Application Layer                                    */  
/* File Name   : TemperatureSensorSWC.c                                       */  
/* Contents    : Ecu Configuration(Ecuc)                                      */  
/* Author      : DN24_FR_AUTOSAR_02_TRUNG_LONG_NINH                           */  
/* Note        :                                                              */  
/******************************************************************************/ 

/*----------------------------------------------------------------------------*/
/* include headers                                                            */
/*----------------------------------------------------------------------------*/

#include "TemperatureSensorSWC.h"

/*----------------------------------------------------------------------------*/
/* functions and function style macros                                        */
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
FUNC(void,AUTOMATIC) ReadTemperature_Runable(VAR(void,AUTOMATIC)){
    VAR(uint16,AUTOMATIC) ActualTempValue;
    Rte_Read_RP_Voltage_TemperatureValue(&ActualTempValue);
    ActualTempValue +=32;
    Rte_Write_PP_Temperature_TempValue(ActualTempValue);
}

/* End of TemperatureSensorSWC.c */