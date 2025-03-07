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
    return E_OK;
}
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
#define RTE_STOP_SEC_CODE_EcucPartition_0
#include "Rte_MemMap.h"

/* End of RTE_NVM.c */