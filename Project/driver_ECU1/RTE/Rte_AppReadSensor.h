/******************************************************************************/  
/* Copyright   : FPT Software Corporation                                     */  
/* System Name : AUTOSAR Application Layer                                    */  
/* File Name   : Rte_AppReadSensor.h                                                      */  
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

/******************************************************************************/  
/* ModuleID    :                                                              */  
/* ServiceID   :                                                              */  
/* Name        : Rte_Write_PP_Voltage_TemperatureValue                        */  
/* Param       : temp - Temperature value to be stored                        */  
/* Return      : Std_ReturnType                                               */  
/*               - E_OK     : Write operation successful                      */  
/*               - E_NOT_OK : Write operation failed                          */  
/* Contents    : Stores the received temperature value in TemperatureValue.   */  
/* Author      : DN24_FR_AUTOSAR_02_TRUNG_LONG_NINH                           */  
/* Note        : Function writes temperature data for further processing.     */  
/******************************************************************************/ 
FUNC(Std_ReturnType,AUTOMATIC) Rte_Write_PP_Voltage_TemperatureValue(VAR(uint16,AUTOMATIC) temp);

/******************************************************************************/  
/* ModuleID    :                                                              */  
/* ServiceID   :                                                              */  
/* Name        : Rte_Read_RP_Voltage_TemperatureValue                         */  
/* Param       : temp - Pointer to store the retrieved temperature value      */  
/* Return      : Std_ReturnType                                               */  
/*               - E_OK     : Read operation successful                       */  
/*               - E_NOT_OK : Read operation failed (NULL pointer)            */  
/* Contents    : Reads the stored temperature value and writes it to temp.    */  
/* Author      : DN24_FR_AUTOSAR_02_TRUNG_LONG_NINH                           */  
/* Note        : Function ensures NULL pointer check before accessing data.   */  
/******************************************************************************/  
FUNC(Std_ReturnType,AUTOMATIC) Rte_Read_RP_Voltage_TemperatureValue(P2VAR(uint16,AUTOMATIC,AUTOMATIC) temp);

/******************************************************************************/  
/* ModuleID    :                                                              */  
/* ServiceID   :                                                              */  
/* Name        : Rte_Write_PP_Pulse_EngineSpeedValue                          */  
/* Param       : temp - Engine speed value to be stored                       */  
/* Return      : Std_ReturnType                                               */  
/*               - E_OK     : Write operation successful                      */  
/*               - E_NOT_OK : Write operation failed                          */  
/* Contents    : Stores the received engine speed value in EngineSpeedValue.  */  
/* Author      : DN24_FR_AUTOSAR_02_TRUNG_LONG_NINH                           */  
/* Note        : Function writes engine speed data for further processing.    */  
/******************************************************************************/  
FUNC(Std_ReturnType,AUTOMATIC) Rte_Write_PP_Pulse_EngineSpeedValue(VAR(uint16,AUTOMATIC) temp);

/******************************************************************************/  
/* ModuleID    :                                                              */  
/* ServiceID   :                                                              */  
/* Name        : Rte_Read_RP_Pulse_EngineSpeedValue                           */  
/* Param       : temp - Pointer to store the retrieved engine speed value     */  
/* Return      : Std_ReturnType                                               */  
/*               - E_OK     : Read operation successful                       */  
/*               - E_NOT_OK : Read operation failed (NULL pointer)            */  
/* Contents    : Reads the stored engine speed value and writes it to temp.   */  
/* Author      : DN24_FR_AUTOSAR_02_TRUNG_LONG_NINH                           */  
/* Note        : Function ensures NULL pointer check before accessing data.   */  
/******************************************************************************/  
FUNC(Std_ReturnType,AUTOMATIC) Rte_Read_RP_Pulse_EngineSpeedValue(P2VAR(uint16,AUTOMATIC,AUTOMATIC) temp);

#endif /* RTE_H */
/* End of RTE.h */