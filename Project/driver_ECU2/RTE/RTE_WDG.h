#ifndef RTE_WDG_H
#define RTE_WDG_H

#include "Compiler.h"
#include "Std_Types.h"
#include "WdgManager.h"
#include "counter.h"

FUNC(Std_ReturnType, AUTOMATIC) Rte_Call_RP_WdgM_Init(VAR(const WdgM_ConfigType*, AUTOMATIC) ConfigPtr);
FUNC(void, AUTOMATIC) Rte_Call_RP_WdgM_DeInit(void);
FUNC(Std_ReturnType, AUTOMATIC) Rte_Call_RP_WdgM_SetMode(VAR(WdgIf_ModeType, AUTOMATIC) Mode);
FUNC(Std_ReturnType, AUTOMATIC) Rte_Call_RP_WdgM_GetMode(VAR(WdgIf_ModeType, AUTOMATIC) Mode);
FUNC(void, AUTOMATIC) Rte_Call_RP_WdgM_PerformReset(void);
FUNC(Std_ReturnType, AUTOMATIC) Rte_Call_RP_WdgM_CheckpointReached(VAR(WdgM_SupervisedEntityIdType, AUTOMATIC) SEID,VAR(WdgM_CheckpointIdType, AUTOMATIC) CheckpointID);

#endif