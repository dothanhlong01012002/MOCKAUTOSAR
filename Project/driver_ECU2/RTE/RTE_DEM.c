/******************************************************************************/  
/* Copyright   : FPT Software Corporation                                     */  
/* System Name : AUTOSAR Application Layer                                    */  
/* File Name   : RTE_DEM.c                                                    */  
/* Contents    : Ecu Configuration(Ecuc)                                      */  
/* Author      : DN24_FR_AUTOSAR_02_TRUNG_LONG_NINH                           */  
/* Note        :                                                              */  
/******************************************************************************/ 
 
/*----------------------------------------------------------------------------*/
/* include headers                                                            */
/*----------------------------------------------------------------------------*/
 
#include "RTE_DEM.h"

/*----------------------------------------------------------------------------*/
/* functions and function style macros                                        */
/*----------------------------------------------------------------------------*/

/******************************************************************************/  
/* ModuleID    :                                                              */  
/* ServiceID   :                                                              */  
/* Name        : Rte_Call_RP_ERROR_ReportDiagnosticResult                     */  
/* Param       : eventID - The event ID to report diagnostic result for       */  
/*               status - The status of the event to report                   */  
/* Return      : Std_ReturnType                                               */  
/*               - E_OK     : Operation successful                            */  
/*               - E_NOT_OK : Operation failed (e.g., invalid parameters)     */  
/* Contents    : Calls the `Dem_SetEventStatus` function to report the event  */  
/*               status for a given event ID.                                 */  
/* Author      : DN24_FR_AUTOSAR_02_TRUNG_LONG_NINH                           */  
/* Note        : Function delegates the reporting of diagnostic result to     */  
/*               the `Dem_SetEventStatus` function.                           */  
/******************************************************************************/ 
#define RTE_START_SEC_CODE_EcucPartition_0
#include "Rte_MemMap.h"
FUNC(Std_ReturnType, RTE_CODE_EcucPartition_0) Rte_Call_RP_ERROR_ReportDiagnosticResult(VAR(uint16, AUTOMATIC) eventID, VAR(uint8, AUTOMATIC) status){
    Dem_SetEventStatus(eventID, status);
    return E_OK;
}
#define RTE_STOP_SEC_CODE_EcucPartition_0
#include "Rte_MemMap.h"

/* End of RTE_DEM.c */
