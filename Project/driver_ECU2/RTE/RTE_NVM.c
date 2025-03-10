/******************************************************************************/  
/* Copyright   : FPT Software Corporation                                     */  
/* System Name : AUTOSAR Application Layer                                    */  
/* File Name   : RTE_NVM.c                                               */  
/* Contents    : Ecu Configuration(Ecuc)                                      */  
/* Author      : DN24_FR_AUTOSAR_02_TRUNG_LONG_NINH                           */  
/* Note        :                                                              */  
/******************************************************************************/ 

/*----------------------------------------------------------------------------*/
/* include headers                                                            */
/*----------------------------------------------------------------------------*/

#include "RTE_NVM.h"

FUNC(Std_ReturnType,AUTOMATIC) Rte_Call_RP_NVData_CallServerFunction(VAR(uint8,AUTOMATIC) requestID, P2VAR(uint8,AUTOMATIC,AUTOMATIC) ErrorCodes)
{
    Rte_Call_RP_NVHandle_SeverHandle(requestID, ErrorCodes);
/*----------------------------------------------------------------------------*/
/* functions and function style macros                                        */
/*----------------------------------------------------------------------------*/

/******************************************************************************/  
/* ModuleID    :                                                              */  
/* ServiceID   :                                                              */  
/* Name        : Rte_Call_RP_NVData_CallServerFunction                        */  
/* Param       : requestID - The request ID to be passed to the function      */  
/* Return      : Std_ReturnType                                               */  
/*               - E_OK     : Operation successful                            */  
/*               - E_NOT_OK : Operation failed (e.g., invalid parameters)     */  
/* Contents    : Calls the `Rte_Call_RP_NVHandle_SeverHandle` function with   */  
/*               the provided request ID.                                     */  
/* Author      : DN24_FR_AUTOSAR_02_TRUNG_LONG_NINH                           */  
/* Note        : Function delegates the handling of the request to another    */  
/*               function (`Rte_Call_RP_NVHandle_SeverHandle`).               */  
/******************************************************************************/ 
#define RTE_START_SEC_CODE_EcucPartition_0
#include "Rte_MemMap.h"
FUNC(Std_ReturnType, RTE_CODE_EcucPartition_0) Rte_Call_RP_NVData_CallServerFunction(VAR(uint8, AUTOMATIC) requestID){
    Rte_Call_RP_NVHandle_SeverHandle(requestID);
    int i = 0;
    Data.parameterData[0] = EngineSpeedValue;
    Data.parameterData[1] = TemperatureValue;
    Data.parameterData[2] = FanRatio;
    Data.parameterData[3] = CompressorRatio;
    return E_OK;
}

FUNC(Std_ReturnType,AUTOMATIC) Rte_Call_RP_NVHandle_SeverHandle(VAR(uint8,AUTOMATIC) requestID, P2VAR(uint8,AUTOMATIC,AUTOMATIC) ErrorCodes){
    return HandleNVM_Runable(requestID, ErrorCodes);
#define RTE_STOP_SEC_CODE_EcucPartition_0
#include "Rte_MemMap.h"

/******************************************************************************/  
/* ModuleID    :                                                              */  
/* ServiceID   :                                                              */  
/* Name        : Rte_Call_RP_NVHandle_SeverHandle                             */  
/* Param       : requestID - The request ID to be passed to the NVM handler   */  
/* Return      : Std_ReturnType                                               */  
/*               - E_OK     : Operation successful                            */  
/*               - E_NOT_OK : Operation failed (e.g., invalid parameters)     */  
/* Contents    : Calls the `HandleNVM_Runable` function with the provided     */  
/*               request ID to handle the NVM operation.                      */  
/* Author      : DN24_FR_AUTOSAR_02_TRUNG_LONG_NINH                           */  
/* Note        : Function delegates the handling of the request to another    */  
/*               function (`HandleNVM_Runable`).                              */  
/******************************************************************************/
#define RTE_START_SEC_CODE_EcucPartition_0
#include "Rte_MemMap.h"
FUNC(Std_ReturnType, RTE_CODE_EcucPartition_0) Rte_Call_RP_NVHandle_SeverHandle(VAR(uint8, AUTOMATIC) requestID){
    return HandleNVM_Runable(requestID);
}

FUNC(Std_ReturnType,AUTOMATIC) Rte_Call_RP_NVHandle_SeverHandleWriteData(VAR(uint8,AUTOMATIC) requestID){
    return NvM_WriteBlock(1,Data.parameterData);
}

FUNC(Std_ReturnType,AUTOMATIC) Rte_Call_RP_NVHandle_SeverHandleWriteError(VAR(uint8,AUTOMATIC) requestID,P2VAR(uint8,AUTOMATIC,AUTOMATIC) ErrorCodes){
    memcpy(Data.errorCodes, ErrorCodes, sizeof(uint8) * 8);
    return NvM_WriteBlock(1,Data.errorCodes);
}

FUNC(Std_ReturnType,AUTOMATIC) Rte_Call_RP_NVHandle_SeverHandleReadData(VAR(uint8,AUTOMATIC) requestID)
{   
    return NvM_ReadBlock(2,Data.errorCodes);
}

FUNC(Std_ReturnType,AUTOMATIC) Rte_Call_RP_NVHandle_SeverHandleReadError(VAR(uint8,AUTOMATIC) requestID)
{   
    return NvM_ReadBlock(2,Data.errorCodes);
}