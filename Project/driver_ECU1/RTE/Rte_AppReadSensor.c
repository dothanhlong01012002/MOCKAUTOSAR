/******************************************************************************/  
/* Copyright   : FPT Software Corporation                                     */  
/* System Name : AUTOSAR Application Layer                                    */  
/* File Name   : Rte_AppReadSensor.c                                          */  
/* Contents    : Ecu Configuration(Ecuc)                                      */  
/* Author      : DN24_FR_AUTOSAR_02_TRUNG_LONG_NINH                           */  
/* Note        :                                                              */  
/******************************************************************************/ 

/*----------------------------------------------------------------------------*/
/* include headers                                                            */
/*----------------------------------------------------------------------------*/

#include "Rte_AppReadSensor.h"

/*----------------------------------------------------------------------------*/
/* functions and function style macros                                        */
/*----------------------------------------------------------------------------*/
VAR(uint16,AUTOMATIC) TemperatureValue;
VAR(uint16,AUTOMATIC) EngineSpeedValue;
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
#define RTE_START_SEC_CODE_EcucPartition_0
#include "Rte_MemMap.h"
FUNC(Std_ReturnType, RTE_CODE_EcucPartition_0) Rte_Read_RP_Pulse_EngineSpeedValue(P2VAR(uint16,AUTOMATIC,AUTOMATIC) temp){
    if (temp != NULL) {
        *temp = EngineSpeedValue;  
        return E_OK;
    }
    return E_NOT_OK;
}
#define RTE_STOP_SEC_CODE_EcucPartition_0
#include "Rte_MemMap.h"

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
#define RTE_START_SEC_CODE_EcucPartition_0
#include "Rte_MemMap.h"
FUNC(Std_ReturnType, RTE_CODE_EcucPartition_0) Rte_Write_PP_Pulse_EngineSpeedValue(VAR(uint16,AUTOMATIC) temp){
    EngineSpeedValue = temp; 
    return E_OK;
}
#define RTE_STOP_SEC_CODE_EcucPartition_0
#include "Rte_MemMap.h"


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
#define RTE_START_SEC_CODE_EcucPartition_0
#include "Rte_MemMap.h"
FUNC(Std_ReturnType, RTE_CODE_EcucPartition_0) Rte_Write_PP_Voltage_TemperatureValue(VAR(uint16,AUTOMATIC) temp){
    TemperatureValue = temp;
    return E_OK;
}
#define RTE_STOP_SEC_CODE_EcucPartition_0
#include "Rte_MemMap.h"

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
#define RTE_START_SEC_CODE_EcucPartition_0
#include "Rte_MemMap.h"
FUNC(Std_ReturnType, RTE_CODE_EcucPartition_0) Rte_Read_RP_Voltage_TemperatureValue(P2VAR(uint16,AUTOMATIC,AUTOMATIC) temp){
    if (temp != NULL) {
        *temp = TemperatureValue;  
        return E_OK;
    }
    return E_NOT_OK;
}
#define RTE_STOP_SEC_CODE_EcucPartition_0
#include "Rte_MemMap.h"

/* End of Rte_AppReadSensor.c */