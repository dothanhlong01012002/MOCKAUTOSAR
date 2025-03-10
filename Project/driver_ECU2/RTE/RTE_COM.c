/******************************************************************************/  
/* Copyright   : FPT Software Corporation                                     */  
/* System Name : AUTOSAR Application Layer                                    */  
/* File Name   : RTE_COM.c                                               */  
/* Contents    : Ecu Configuration(Ecuc)                                      */  
/* Author      : DN24_FR_AUTOSAR_02_TRUNG_LONG_NINH                           */  
/* Note        :                                                              */  
/******************************************************************************/ 

/*----------------------------------------------------------------------------*/
/* include headers                                                            */
/*----------------------------------------------------------------------------*/

#include "RTE_COM.h"

/*----------------------------------------------------------------------------*/
/* variables                                                                  */
/*----------------------------------------------------------------------------*/

VAR(uint16,AUTOMATIC) TemperatureValue;
VAR(uint16,AUTOMATIC) EngineSpeedValue;
VAR(uint16,AUTOMATIC) FanRatio;
VAR(uint16,AUTOMATIC) CompressorRatio;
VAR(uint8,AUTOMATIC) ExpectedTemp=32;

/*----------------------------------------------------------------------------*/
/* functions and function style macros                                        */
/*----------------------------------------------------------------------------*/

/******************************************************************************/  
/* ModuleID    :                                                              */  
/* ServiceID   :                                                              */  
/* Name        : Rte_Read_RP_ComData_TempSpeedValue                           */  
/* Param       : Tempvalue - Pointer to store the temperature value           */  
/*               SpeedValue - Pointer to store the engine speed value         */  
/* Return      : Std_ReturnType                                               */  
/*               - E_OK     : Operation successful                            */  
/*               - E_NOT_OK : Invalid input parameters (NULL pointer)         */  
/* Contents    : Reads the temperature and engine speed values and stores     */  
/*               them in the provided pointers.                               */  
/* Author      : DN24_FR_AUTOSAR_02_TRUNG_LONG_NINH                           */  
/* Note        : Function checks if the input pointers are valid before       */  
/*               assigning values.                                            */  
/******************************************************************************/ 
#define RTE_START_SEC_CODE_EcucPartition_0
#include "Rte_MemMap.h"
FUNC(Std_ReturnType, RTE_CODE_EcucPartition_0) Rte_Read_RP_ComData_TempSpeedValue(P2VAR(uint16, AUTOMATIC, AUTOMATIC) Tempvalue, P2VAR(uint16, AUTOMATIC, AUTOMATIC) SpeedValue){
    if(Tempvalue!= NULL&&SpeedValue!= NULL){
        *Tempvalue = TemperatureValue;
        *SpeedValue = EngineSpeedValue;
        return E_OK;
    }
    return E_NOT_OK;
}
#define RTE_STOP_SEC_CODE_EcucPartition_0
#include "Rte_MemMap.h"

/******************************************************************************/  
/* ModuleID    :                                                              */  
/* ServiceID   :                                                              */  
/* Name        : Rte_Write_PP_ComData_TempSpeedValue                          */  
/* Param       : Tempvalue - The temperature value to be written              */  
/*               SpeedValue - The engine speed value to be written            */  
/* Return      : Std_ReturnType                                               */  
/*               - E_OK     : Operation successful                            */  
/*               - E_NOT_OK : Operation failed (e.g., invalid parameters)     */  
/* Contents    : Writes the provided temperature and engine speed values      */  
/*               to the respective global variables.                          */  
/* Author      : DN24_FR_AUTOSAR_02_TRUNG_LONG_NINH                           */  
/* Note        : Function assigns the input values to the global variables    */  
/******************************************************************************/  
#define RTE_START_SEC_CODE_EcucPartition_0
#include "Rte_MemMap.h"
FUNC(Std_ReturnType, RTE_CODE_EcucPartition_0) Rte_Write_PP_ComData_TempSpeedValue(VAR(uint16, AUTOMATIC) Tempvalue, VAR(uint16, AUTOMATIC) SpeedValue){
    TemperatureValue = Tempvalue;
    EngineSpeedValue = SpeedValue;
    return E_OK;
}
#define RTE_STOP_SEC_CODE_EcucPartition_0
#include "Rte_MemMap.h"

/******************************************************************************/  
/* ModuleID    :                                                              */  
/* ServiceID   :                                                              */  
/* Name        : Rte_Write_PP_FanData_FanValue                                */  
/* Param       : FanV - The fan value to be written                           */  
/* Return      : Std_ReturnType                                               */  
/*               - E_OK     : Operation successful                            */  
/*               - E_NOT_OK : Operation failed (e.g., invalid parameters)     */  
/* Contents    : Writes the provided fan value to the global variable.        */  
/* Author      : DN24_FR_AUTOSAR_02_TRUNG_LONG_NINH                           */  
/* Note        : Function assigns the input fan value to the global variable. */  
/******************************************************************************/
#define RTE_START_SEC_CODE_EcucPartition_0
#include "Rte_MemMap.h"
FUNC(Std_ReturnType, RTE_CODE_EcucPartition_0) Rte_Write_PP_FanData_FanValue(VAR(uint16, AUTOMATIC) FanV){
    FanRatio = FanV;
    return E_OK;
}
#define RTE_STOP_SEC_CODE_EcucPartition_0
#include "Rte_MemMap.h"

/******************************************************************************/  
/* ModuleID    :                                                              */  
/* ServiceID   :                                                              */  
/* Name        : Rte_Read_RP_FanData_FanValue                                 */  
/* Param       : FanV - Pointer to store the fan value                        */  
/* Return      : Std_ReturnType                                               */  
/*               - E_OK     : Operation successful                            */  
/*               - E_NOT_OK : Invalid input (NULL pointer)                    */  
/* Contents    : Reads the fan value and stores it in the provided pointer.   */  
/* Author      : DN24_FR_AUTOSAR_02_TRUNG_LONG_NINH                           */  
/* Note        : Function checks if the input pointer is valid before         */  
/*               assigning the fan value.                                     */  
/******************************************************************************/  
#define RTE_START_SEC_CODE_EcucPartition_0
#include "Rte_MemMap.h"
FUNC(Std_ReturnType, RTE_CODE_EcucPartition_0) Rte_Read_RP_FanData_FanValue(P2VAR(uint16, AUTOMATIC, AUTOMATIC) FanV){
    if(FanV!= NULL){
        *FanV = FanRatio;
        return E_OK;
    }
    return E_NOT_OK;
}
#define RTE_STOP_SEC_CODE_EcucPartition_0
#include "Rte_MemMap.h"

/******************************************************************************/  
/* ModuleID    :                                                              */  
/* ServiceID   :                                                              */  
/* Name        : Rte_Write_PP_CompressorData_CompressorValue                  */  
/* Param       : CompressorV - The compressor value to be written             */  
/* Return      : Std_ReturnType                                               */  
/*               - E_OK     : Operation successful                            */  
/*               - E_NOT_OK : Operation failed (e.g., invalid parameters)     */  
/* Contents    : Writes the provided compressor value to the global variable. */  
/* Author      : DN24_FR_AUTOSAR_02_TRUNG_LONG_NINH                           */  
/* Note        : Function assigns the input compressor value to the global    */  
/*               variable.                                                    */  
/******************************************************************************/ 
#define RTE_START_SEC_CODE_EcucPartition_0
#include "Rte_MemMap.h"
FUNC(Std_ReturnType, RTE_CODE_EcucPartition_0) Rte_Write_PP_CompressorData_CompressorValue(VAR(uint16, AUTOMATIC) CompressorV){
    CompressorRatio = CompressorV;
    return E_OK;
}
#define RTE_STOP_SEC_CODE_EcucPartition_0
#include "Rte_MemMap.h"

/******************************************************************************/  
/* ModuleID    :                                                              */  
/* ServiceID   :                                                              */  
/* Name        : Rte_Read_RP_CompressorData_CompressorValue                   */  
/* Param       : CompressorV - Pointer to store the compressor value          */  
/* Return      : Std_ReturnType                                               */  
/*               - E_OK     : Operation successful                            */  
/*               - E_NOT_OK : Invalid input (NULL pointer)                    */  
/* Contents    : Reads the compressor value and stores it in the provided     */  
/*               pointer.                                                     */  
/* Author      : DN24_FR_AUTOSAR_02_TRUNG_LONG_NINH                           */  
/* Note        : Function checks if the input pointer is valid before         */  
/*               assigning the compressor value.                              */  
/******************************************************************************/ 
#define RTE_START_SEC_CODE_EcucPartition_0
#include "Rte_MemMap.h"
FUNC(Std_ReturnType, RTE_CODE_EcucPartition_0) Rte_Read_RP_CompressorData_CompressorValue(P2VAR(uint16, AUTOMATIC, AUTOMATIC) CompressorV){
    if(CompressorV!= NULL){
        *CompressorV = CompressorRatio;
        return E_OK;
    }
    return E_NOT_OK;
}
#define RTE_STOP_SEC_CODE_EcucPartition_0
#include "Rte_MemMap.h"

/*********************************************************************************/  
/* ModuleID    :                                                                 */  
/* ServiceID   :                                                                 */  
/* Name        : Rte_Call_RP_AdjustFan_ControlFan                                */  
/* Param       : FanR - The fan value to be passed to the fan control function   */  
/* Return      : Std_ReturnType                                                  */  
/*               - E_OK     : Operation successful                               */  
/*               - E_NOT_OK : Operation failed (e.g., invalid parameters)        */  
/* Contents    : Calls the fan control function to adjust the fan based on the   */  
/*               provided fan value.                                             */  
/* Author      : DN24_FR_AUTOSAR_02_TRUNG_LONG_NINH                              */  
/* Note        : Function delegates the fan adjustment to the AdjustFan function */  
/*********************************************************************************/  
#define RTE_START_SEC_CODE_EcucPartition_0
#include "Rte_MemMap.h"
FUNC(Std_ReturnType, RTE_CODE_EcucPartition_0) Rte_Call_RP_AdjustFan_ControlFan(VAR(uint16, AUTOMATIC) FanR){
    return AdjustFanControl(FanR);
}
#define RTE_STOP_SEC_CODE_EcucPartition_0
#include "Rte_MemMap.h"

/******************************************************************************/  
/* ModuleID    :                                                              */  
/* ServiceID   :                                                              */  
/* Name        : Rte_Call_RP_AdjustCompressor_ControlCompressor               */  
/* Param       : CompressorR - The compressor value to be passed to the       */  
/*               compressor control function.                                 */  
/* Return      : Std_ReturnType                                               */  
/*               - E_OK     : Operation successful                            */  
/*               - E_NOT_OK : Operation failed (e.g., invalid parameters)     */  
/* Contents    : Calls the compressor control function to adjust the          */  
/*               compressor based on the provided value.                      */  
/* Author      : DN24_FR_AUTOSAR_02_TRUNG_LONG_NINH                           */  
/* Note        : Function delegates the compressor adjustment to the          */  
/*               `AdjustCompressorControl` function.                          */  
/******************************************************************************/ 
#define RTE_START_SEC_CODE_EcucPartition_0
#include "Rte_MemMap.h"
FUNC(Std_ReturnType, RTE_CODE_EcucPartition_0) Rte_Call_RP_AdjustCompressor_ControlCompressor(VAR(uint16, AUTOMATIC) CompressorR){
    return AdjustCompressorControl(CompressorR);
}
#define RTE_STOP_SEC_CODE_EcucPartition_0
#include "Rte_MemMap.h"

/******************************************************************************/  
/* ModuleID    :                                                              */  
/* ServiceID   :                                                              */  
/* Name        : Rte_Read_RP_PARAM_ExpectedTemperature                        */  
/* Param       : ExTemp - Pointer to store the expected temperature value     */  
/* Return      : Std_ReturnType                                               */  
/*               - E_OK     : Operation successful                            */  
/*               - E_NOT_OK : Invalid input (NULL pointer)                    */  
/* Contents    : Reads the expected temperature value and stores it in the    */  
/*               provided pointer.                                            */  
/* Author      : DN24_FR_AUTOSAR_02_TRUNG_LONG_NINH                           */  
/* Note        : Function checks if the input pointer is valid before         */  
/*               assigning the expected temperature value.                    */  
/******************************************************************************/ 
#define RTE_START_SEC_CODE_EcucPartition_0
#include "Rte_MemMap.h"
FUNC(Std_ReturnType, RTE_CODE_EcucPartition_0) Rte_Read_RP_PARAM_ExpectedTemperature(P2VAR(uint16, AUTOMATIC, AUTOMATIC) ExTemp){
    if(ExTemp != NULL){
        *ExTemp = ExpectedTemp;
        return E_OK; 
    }
    return E_NOT_OK;
}
#define RTE_STOP_SEC_CODE_EcucPartition_0
#include "Rte_MemMap.h"

/******************************************************************************/  
/* ModuleID    :                                                              */  
/* ServiceID   :                                                              */  
/* Name        : Rte_Write_PP_PARAM_ExpectedTemperature                       */  
/* Param       : ExTemp - The expected temperature value to be written        */  
/* Return      : Std_ReturnType                                               */  
/*               - E_OK     : Operation successful                            */  
/*               - E_NOT_OK : Operation failed (e.g., invalid parameters)     */  
/* Contents    : Writes the provided expected temperature value to the global */  
/*               variable.                                                    */  
/* Author      : DN24_FR_AUTOSAR_02_TRUNG_LONG_NINH                           */  
/* Note        : Function assigns the input temperature value to the global   */  
/*               variable.                                                    */  
/******************************************************************************/
#define RTE_START_SEC_CODE_EcucPartition_0
#include "Rte_MemMap.h"
FUNC(Std_ReturnType, RTE_CODE_EcucPartition_0) Rte_Write_PP_PARAM_ExpectedTemperature(VAR(uint16, AUTOMATIC) ExTemp){
    ExpectedTemp = ExTemp;
    return E_OK;
}
#define RTE_STOP_SEC_CODE_EcucPartition_0
#include "Rte_MemMap.h"

/* End of RTE_COM.c */
