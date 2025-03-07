/******************************************************************************/  
/* Copyright   : FPT Software Corporation                                     */  
/* System Name : AUTOSAR Application Layer                                    */  
/* File Name   : RTE_WDG.c                                                    */  
/* Contents    : Ecu Configuration(Ecuc)                                      */  
/* Author      : DN24_FR_AUTOSAR_02_TRUNG_LONG_NINH                           */  
/* Note        :                                                              */  
/******************************************************************************/ 

/*----------------------------------------------------------------------------*/
/* include headers                                                            */
/*----------------------------------------------------------------------------*/

#include "RTE_WDG.h"

/*----------------------------------------------------------------------------*/
/* functions and function style macros                                        */
/*----------------------------------------------------------------------------*/

/******************************************************************************/  
/* ModuleID    :                                                              */  
/* ServiceID   :                                                              */  
/* Name        : Rte_Call_RP_WdgM_Init                                        */  
/* Param       : ConfigPtr - Pointer to the watchdog manager configuration    */  
/* Return      : Std_ReturnType                                               */  
/*               - E_OK     : Operation successful                            */  
/*               - E_NOT_OK : Invalid input (NULL pointer)                    */  
/* Contents    : Calls the `WdgM_Init` function to initialize the watchdog    */  
/*               manager with the provided configuration.                     */  
/* Author      : DN24_FR_AUTOSAR_02_TRUNG_LONG_NINH                           */  
/* Note        : Function checks if the input pointer is valid before         */  
/*               calling `WdgM_Init`.                                         */  
/******************************************************************************/  
#define RTE_START_SEC_CODE_EcucPartition_0
#include "Rte_MemMap.h"
FUNC(Std_ReturnType, RTE_CODE_EcucPartition_0) Rte_Call_RP_WdgM_Init(VAR(const WdgM_ConfigType*, AUTOMATIC) ConfigPtr){
    if (ConfigPtr != NULL) {
        WdgM_Init(ConfigPtr);
    }
    return E_OK;
}
#define RTE_STOP_SEC_CODE_EcucPartition_0
#include "Rte_MemMap.h"

/******************************************************************************/  
/* ModuleID    :                                                              */  
/* ServiceID   :                                                              */  
/* Name        : Rte_Call_RP_WdgM_DeInit                                      */  
/* Param       : void                                                         */  
/* Return      : void                                                         */  
/* Contents    : Calls the `WdgM_DeInit` function to deinitialize the watchdog*/  
/*               manager.                                                     */  
/* Author      : DN24_FR_AUTOSAR_02_TRUNG_LONG_NINH                           */  
/* Note        : Function delegates the deinitialization to `WdgM_DeInit`.    */  
/******************************************************************************/  
#define RTE_START_SEC_CODE_EcucPartition_0
#include "Rte_MemMap.h"
FUNC(void, RTE_CODE_EcucPartition_0) Rte_Call_RP_WdgM_DeInit(void){
    WdgM_DeInit();
}
#define RTE_STOP_SEC_CODE_EcucPartition_0
#include "Rte_MemMap.h"

/******************************************************************************/  
/* ModuleID    :                                                              */  
/* ServiceID   :                                                              */  
/* Name        : Rte_Call_RP_WdgM_SetMode                                     */  
/* Param       : Mode - The mode to be set for the watchdog manager           */  
/* Return      : Std_ReturnType                                               */  
/*               - E_OK     : Operation successful                            */  
/*               - E_NOT_OK : Operation failed (e.g., invalid parameters)     */  
/* Contents    : Calls the `WdgM_SetMode` function to set the mode for the    */  
/*               watchdog manager.                                            */  
/* Author      : DN24_FR_AUTOSAR_02_TRUNG_LONG_NINH                           */  
/* Note        : Function delegates the mode setting to `WdgM_SetMode`.       */  
/******************************************************************************/  
#define RTE_START_SEC_CODE_EcucPartition_0
#include "Rte_MemMap.h"
FUNC(Std_ReturnType, RTE_CODE_EcucPartition_0) Rte_Call_RP_WdgM_SetMode(VAR(WdgIf_ModeType, AUTOMATIC) Mode){
    return WdgM_SetMode(Mode);
}
#define RTE_STOP_SEC_CODE_EcucPartition_0
#include "Rte_MemMap.h"

/******************************************************************************/  
/* ModuleID    :                                                              */  
/* ServiceID   :                                                              */  
/* Name        : Rte_Call_RP_WdgM_GetMode                                     */  
/* Param       : Mode - Pointer to store the current mode of the watchdog     */  
/* Return      : Std_ReturnType                                               */  
/*               - E_OK     : Operation successful                            */  
/*               - E_NOT_OK : Operation failed (e.g., invalid parameters)     */  
/* Contents    : Calls the `WdgM_GetMode` function to get the current mode    */  
/*               of the watchdog manager and stores it in the provided pointer*/  
/* Author      : DN24_FR_AUTOSAR_02_TRUNG_LONG_NINH                           */  
/* Note        : Function delegates the mode retrieval to `WdgM_GetMode`.     */  
/******************************************************************************/
#define RTE_START_SEC_CODE_EcucPartition_0
#include "Rte_MemMap.h"
FUNC(Std_ReturnType, RTE_CODE_EcucPartition_0) Rte_Call_RP_WdgM_GetMode(VAR(WdgIf_ModeType, AUTOMATIC) Mode){
    return WdgM_GetMode(&Mode);
}
#define RTE_STOP_SEC_CODE_EcucPartition_0
#include "Rte_MemMap.h"

/******************************************************************************/  
/* ModuleID    :                                                              */  
/* ServiceID   :                                                              */  
/* Name        : Rte_Call_RP_WdgM_PerformReset                                */  
/* Param       : void                                                         */  
/* Return      : void                                                         */  
/* Contents    : Calls the watchdog manager reset function.                   */  
/* Author      : DN24_FR_AUTOSAR_02_TRUNG_LONG_NINH                           */  
/* Note        :                                                              */  
/******************************************************************************/  
#define RTE_START_SEC_CODE_EcucPartition_0
#include "Rte_MemMap.h"
FUNC(void, RTE_CODE_EcucPartition_0) Rte_Call_RP_WdgM_PerformReset(void){
    //WdgM_PerformReset(); 
    //SystickCounter =0;
}
#define RTE_STOP_SEC_CODE_EcucPartition_0
#include "Rte_MemMap.h"

/******************************************************************************/  
/* ModuleID    :                                                              */  
/* ServiceID   :                                                              */  
/* Name        : Rte_Call_RP_WdgM_CheckpointReached                           */  
/* Param       : SEID - The ID of the supervised entity                       */  
/*               CheckpointID - The ID of the checkpoint reached              */  
/* Return      : Std_ReturnType                                               */  
/*               - E_OK     : Operation successful                            */  
/*               - E_NOT_OK : Operation failed (e.g., invalid parameters)     */  
/* Contents    : Calls the `WdgM_CheckpointReached` function to report the    */  
/*               checkpoint reached for a given supervised entity.            */  
/* Author      : DN24_FR_AUTOSAR_02_TRUNG_LONG_NINH                           */  
/* Note        :                                                              */  
/******************************************************************************/  
#define RTE_START_SEC_CODE_EcucPartition_0
#include "Rte_MemMap.h"
FUNC(Std_ReturnType, RTE_CODE_EcucPartition_0) Rte_Call_RP_WdgM_CheckpointReached(VAR(WdgM_SupervisedEntityIdType, AUTOMATIC) SEID, VAR(WdgM_CheckpointIdType, AUTOMATIC) CheckpointID){
    return WdgM_CheckpointReached(SEID, CheckpointID);
}
#define RTE_STOP_SEC_CODE_EcucPartition_0
#include "Rte_MemMap.h"

/* End of RTE_WDG.c */