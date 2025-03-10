/******************************************************************************/  
/* Copyright   : FPT Software Corporation                                     */  
/* System Name : AUTOSAR Application Layer                                    */  
/* File Name   : WdgManager.h                                                 */  
/* Contents    : Ecu Configuration(Ecuc)                                      */  
/* Author      : DN24_FR_AUTOSAR_02_TRUNG_LONG_NINH                           */  
/* Note        :                                                              */  
/******************************************************************************/  

#ifndef WDG_MANAGER_H
#define WDG_MANAGER_H

/*----------------------------------------------------------------------------*/
/* include headers                                                            */
/*----------------------------------------------------------------------------*/

#include "WdgIf.h"

#define SEID_SENSOR 1
#define CHECKPOINT_SENSOR_READ 1

/*----------------------------------------------------------------------------*/
/* struct prototype declarations                                              */
/*----------------------------------------------------------------------------*/

typedef struct {
    WdgIf_ModeType WdgMode;  // Chế độ Watchdog (OFF, SLOW, FAST)
    uint16 Timeout;          // Thời gian timeout cho Watchdog (trong mili giây)
} WdgM_ConfigType;

extern WdgM_ConfigType wdgConfig ;
typedef uint8 WdgM_SupervisedEntityIdType; 
typedef uint16 WdgM_CheckpointIdType;
static WdgM_ConfigType* currentConfig = NULL;

/*----------------------------------------------------------------------------*/
/* functions and function style macros                                        */
/*----------------------------------------------------------------------------*/

FUNC(void, AUTOMATIC) WdgM_Init(P2CONST(WdgM_ConfigType, AUTOMATIC, AUTOMATIC) ConfigPtr);
FUNC(void, AUTOMATIC) WdgM_DeInit(void);
FUNC(Std_ReturnType, AUTOMATIC) WdgM_SetMode(VAR(WdgIf_ModeType, AUTOMATIC) Mode);
FUNC(Std_ReturnType, AUTOMATIC) WdgM_GetMode(P2VAR(WdgIf_ModeType, AUTOMATIC, AUTOMATIC) Mode);
FUNC(void, AUTOMATIC) WdgM_PerformReset(void);
FUNC(Std_ReturnType, AUTOMATIC) WdgM_CheckpointReached(VAR(WdgM_SupervisedEntityIdType, AUTOMATIC) SEID, VAR(WdgM_CheckpointIdType, AUTOMATIC) CheckpointID);

#endif /* WDG_MANAGER_H */
/* End of WdgIf.h */