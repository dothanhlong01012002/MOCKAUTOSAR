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
    return E_OK;
}

FUNC(Std_ReturnType,AUTOMATIC) Rte_Call_RP_NVHandle_SeverHandle(VAR(uint8,AUTOMATIC) requestID, P2VAR(uint8,AUTOMATIC,AUTOMATIC) ErrorCodes){
    return HandleNVM_Runable(requestID, ErrorCodes);
}

FUNC(Std_ReturnType,AUTOMATIC) Rte_Call_RP_NVHandle_SeverHandleWriteData(VAR(uint8,AUTOMATIC) requestID){
    return NvM_WriteBlock(DATA_BLOCK,Data.parameterData);
}

FUNC(Std_ReturnType,AUTOMATIC) Rte_Call_RP_NVHandle_SeverHandleWriteError(VAR(uint8,AUTOMATIC) requestID,P2VAR(uint8,AUTOMATIC,AUTOMATIC) ErrorCodes){
    memcpy(Data.errorCodes, ErrorCodes, sizeof(uint8) * 8);
    return NvM_WriteBlock(ERROR_BLOCK,Data.errorCodes);
}

FUNC(Std_ReturnType,AUTOMATIC) Rte_Call_RP_NVHandle_SeverHandleReadData(VAR(uint8,AUTOMATIC) requestID)
{   
    return NvM_ReadBlock(DATA_BLOCK,Data.errorCodes);
}

FUNC(Std_ReturnType,AUTOMATIC) Rte_Call_RP_NVHandle_SeverHandleReadError(VAR(uint8,AUTOMATIC) requestID)
{   
    return NvM_ReadBlock(ERROR_BLOCK,Data.errorCodes);
}