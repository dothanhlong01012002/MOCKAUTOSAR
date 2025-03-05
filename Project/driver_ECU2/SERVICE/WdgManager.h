#ifndef WDG_MANAGER_H
#define WDG_MANAGER_H
#include "WdgIf.h"

typedef struct {
    WdgIf_ModeType WdgMode;  // Chế độ Watchdog (OFF, SLOW, FAST)
    uint16 Timeout;          // Thời gian timeout cho Watchdog (trong mili giây)
} WdgM_ConfigType;

extern WdgM_ConfigType wdgConfig ;

typedef uint8 WdgM_SupervisedEntityIdType; 
typedef uint16 WdgM_CheckpointIdType;
static WdgM_ConfigType* currentConfig = NULL;
void WdgM_Init(const WdgM_ConfigType* ConfigPtr);
void WdgM_DeInit(void);
Std_ReturnType WdgM_SetMode(WdgIf_ModeType Mode);
Std_ReturnType WdgM_GetMode(WdgIf_ModeType* Mode);
void WdgM_PerformReset(void);
Std_ReturnType WdgM_CheckpointReached(WdgM_SupervisedEntityIdType SEID, WdgM_CheckpointIdType CheckpointID);
#endif