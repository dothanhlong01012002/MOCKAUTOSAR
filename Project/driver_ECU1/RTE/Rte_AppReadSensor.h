/******************************************************************************/  
/* Copyright   : FPT Software Corporation                                     */  
/* System Name : AUTOSAR Application Layer                                    */  
/* File Name   : Rte_AppReadSensor.h                                          */  
/* Contents    : Ecu Configuration(Ecuc)                                      */  
/* Author      : DN24_FR_AUTOSAR_02_TRUNG_LONG_NINH                           */  
/* Note        :                                                              */  
/******************************************************************************/ 

#ifndef RTE_APP_READSENSOR_H
#define RTE_APP_READSENSOR_H

/*----------------------------------------------------------------------------*/
/* include headers                                                            */
/*----------------------------------------------------------------------------*/

#include "Std_Types.h"
#include "Compiler.h"

/*----------------------------------------------------------------------------*/
/* variables                                                                  */
/*----------------------------------------------------------------------------*/

static VAR(uint16,AUTOMATIC) TemperatureValue = 0;
static VAR(uint16,AUTOMATIC) EngineSpeedValue = 0;


extern FUNC(Std_ReturnType, RTE_CODE_EcucPartition_0) Rte_Write_PP_Voltage_TemperatureValue(VAR(uint16,AUTOMATIC) temp);
#define Rte_Write_PP_Voltage_TemperatureValue Rte_Write_PP_Voltage_TemperatureValue

extern FUNC(Std_ReturnType, RTE_CODE_EcucPartition_0) Rte_Read_RP_Voltage_TemperatureValue(P2VAR(uint16,AUTOMATIC,AUTOMATIC) temp);
#define Rte_Read_RP_Voltage_TemperatureValue Rte_Read_RP_Voltage_TemperatureValue

extern FUNC(Std_ReturnType, RTE_CODE_EcucPartition_0) Rte_Write_PP_Pulse_EngineSpeedValue(VAR(uint16,AUTOMATIC) temp);
#define Rte_Write_PP_Pulse_EngineSpeedValue Rte_Write_PP_Pulse_EngineSpeedValue

extern FUNC(Std_ReturnType, RTE_CODE_EcucPartition_0) Rte_Read_RP_Pulse_EngineSpeedValue(P2VAR(uint16,AUTOMATIC,AUTOMATIC) temp);
#define Rte_Read_RP_Pulse_EngineSpeedValue Rte_Read_RP_Pulse_EngineSpeedValue

#endif /* RTE_APP_READSENSOR_H */
/* End of Rte_AppReadSensor.h */