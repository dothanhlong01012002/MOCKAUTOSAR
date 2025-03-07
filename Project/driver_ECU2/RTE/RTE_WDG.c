#include "RTE_WDG.h"

FUNC(Std_ReturnType, AUTOMATIC) Rte_Call_RP_WdgM_Init(VAR(const WdgM_ConfigType*, AUTOMATIC) ConfigPtr){
    if (ConfigPtr != NULL) {
        WdgM_Init(ConfigPtr);
    }
    return E_OK;
}

FUNC(void, AUTOMATIC) Rte_Call_RP_WdgM_DeInit(void){
    WdgM_DeInit();
}

FUNC(Std_ReturnType, AUTOMATIC) Rte_Call_RP_WdgM_SetMode(VAR(WdgIf_ModeType, AUTOMATIC) Mode){
    return WdgM_SetMode(Mode);
}

FUNC(Std_ReturnType, AUTOMATIC) Rte_Call_RP_WdgM_GetMode(VAR(WdgIf_ModeType, AUTOMATIC) Mode){
    return WdgM_GetMode(&Mode);
}

FUNC(void, AUTOMATIC) Rte_Call_RP_WdgM_PerformReset(void){
    //WdgM_PerformReset(); 
    SystickCounter =0;
}

FUNC(Std_ReturnType, AUTOMATIC) Rte_Call_RP_WdgM_CheckpointReached(VAR(WdgM_SupervisedEntityIdType, AUTOMATIC) SEID,VAR(WdgM_CheckpointIdType, AUTOMATIC) CheckpointID){
    return WdgM_CheckpointReached(SEID, CheckpointID);
}
