/******************************************************************************/  
/* Copyright   : FPT Software Corporation                                     */  
/* System Name : AUTOSAR Application Layer                                    */  
/* File Name   : RTE_WDG.h                                                    */  
/* Contents    : Ecu Configuration(Ecuc)                                      */  
/* Author      : DN24_FR_AUTOSAR_02_TRUNG_LONG_NINH                           */  
/* Note        :                                                              */  
/******************************************************************************/ 

/*----------------------------------------------------------------------------*/
/* include headers                                                            */
/*----------------------------------------------------------------------------*/

#ifndef RTE_WDG_H
#define RTE_WDG_H

#include "Compiler.h"
#include "Std_Types.h"
#include "WdgManager.h"
#include "counter.h"

extern FUNC(Std_ReturnType, RTE_CODE_EcucPartition_0) Rte_Call_RP_WdgM_Init(VAR(const WdgM_ConfigType*, AUTOMATIC) ConfigPtr);
#define Rte_Call_RP_WdgM_Init Rte_Call_RP_WdgM_Init

extern FUNC(void, RTE_CODE_EcucPartition_0) Rte_Call_RP_WdgM_DeInit(void);
#define Rte_Call_RP_WdgM_DeInit Rte_Call_RP_WdgM_DeInit

extern FUNC(Std_ReturnType, RTE_CODE_EcucPartition_0) Rte_Call_RP_WdgM_SetMode(VAR(WdgIf_ModeType, AUTOMATIC) Mode);
#define Rte_Call_RP_WdgM_SetMode Rte_Call_RP_WdgM_SetMode

extern FUNC(Std_ReturnType, RTE_CODE_EcucPartition_0) Rte_Call_RP_WdgM_GetMode(VAR(WdgIf_ModeType, AUTOMATIC) Mode);
#define Rte_Call_RP_WdgM_GetMode Rte_Call_RP_WdgM_GetMode

extern FUNC(void, RTE_CODE_EcucPartition_0) Rte_Call_RP_WdgM_PerformReset(void);
#define Rte_Call_RP_WdgM_PerformReset Rte_Call_RP_WdgM_PerformReset

extern FUNC(Std_ReturnType, RTE_CODE_EcucPartition_0) Rte_Call_RP_WdgM_CheckpointReached(VAR(WdgM_SupervisedEntityIdType, AUTOMATIC) SEID, VAR(WdgM_CheckpointIdType, AUTOMATIC) CheckpointID);
#define Rte_Call_RP_WdgM_CheckpointReached Rte_Call_RP_WdgM_CheckpointReached

#endif /* RTE_WDG_H */
/* End of RTE_WDG.h */