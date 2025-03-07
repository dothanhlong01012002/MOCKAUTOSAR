/******************************************************************************/  
/* Copyright   : FPT Software Corporation                                     */  
/* System Name : AUTOSAR Application Layer                                    */  
/* File Name   : WdgManager.c                                                 */  
/* Contents    : Ecu Configuration(Ecuc)                                      */  
/* Author      : DN24_FR_AUTOSAR_02_TRUNG_LONG_NINH                           */  
/* Note        :                                                              */  
/******************************************************************************/  

/*----------------------------------------------------------------------------*/
/* include headers                                                            */
/*----------------------------------------------------------------------------*/

#include "WdgManager.h"

/*----------------------------------------------------------------------------*/
/* variables                                                                  */
/*----------------------------------------------------------------------------*/

WdgM_ConfigType wdgConfig = {
    .WdgMode = WDGIF_SLOW_MODE,  
    .Timeout = 200              
};

/*----------------------------------------------------------------------------*/
/* functions and function style macros                                        */
/*----------------------------------------------------------------------------*/

/******************************************************************************/  
/* ModuleID    :                                                              */  
/* ServiceID   :                                                              */  
/* Name        : WdgM_Init                                                    */  
/* Param       : ConfigPtr - Pointer to the watchdog manager configuration    */  
/* Return      : void                                                         */  
/* Contents    : Initializes the watchdog manager with the provided config.   */  
/* Author      : DN24_FR_AUTOSAR_02_TRUNG_LONG_NINH                           */  
/* Note        :                                                              */  
/******************************************************************************/  
void WdgM_Init(const WdgM_ConfigType* ConfigPtr) {
    if (ConfigPtr == NULL) {
        return;  
    }
    WdgIf_Init();
    currentConfig = (WdgM_ConfigType*)ConfigPtr;

    Std_ReturnType result = WdgIf_SetMode(0, currentConfig->WdgMode);  
    if (result != E_OK) {
        WdgM_PerformReset();
    }

    WdgIf_SetTriggerCondition(0, currentConfig->Timeout); 
}

/******************************************************************************/  
/* ModuleID    :                                                              */  
/* ServiceID   :                                                              */  
/* Name        : WdgM_DeInit                                                  */  
/* Param       : void                                                         */  
/* Return      : void                                                         */  
/* Contents    : Deinitializes the watchdog manager by setting the mode to    */  
/*               OFF and clearing the trigger condition.                      */  
/* Author      : DN24_FR_AUTOSAR_02_TRUNG_LONG_NINH                           */  
/* Note        :                                                              */  
/******************************************************************************/  
void WdgM_DeInit(void) {
    WdgIf_SetMode(0, WDGIF_OFF_MODE);  
    WdgIf_SetTriggerCondition(0, 0);   
}

/******************************************************************************/  
/* ModuleID    :                                                              */  
/* ServiceID   :                                                              */  
/* Name        : WdgM_SetMode                                                 */  
/* Param       : Mode - The mode to set for the watchdog                      */  
/* Return      : Std_ReturnType                                               */  
/*               - E_OK     : Mode set successfully                           */  
/*               - E_NOT_OK : Invalid mode passed                             */  
/* Contents    : Validates the provided mode and sets it for the watchdog.    */  
/* Author      : DN24_FR_AUTOSAR_02_TRUNG_LONG_NINH                           */  
/* Note        :                                                              */  
/******************************************************************************/ 
Std_ReturnType WdgM_SetMode(WdgIf_ModeType Mode) {
    if (Mode < WDGIF_OFF_MODE || Mode > WDGIF_FAST_MODE) {
        return E_NOT_OK;  
    }
    return WdgIf_SetMode(0, Mode);  
}

/******************************************************************************/  
/* ModuleID    :                                                              */  
/* ServiceID   :                                                              */  
/* Name        : WdgM_GetMode                                                 */  
/* Param       : Mode - Pointer to store the current mode of the watchdog     */  
/* Return      : Std_ReturnType                                               */  
/*               - E_OK     : Mode retrieved successfully                     */  
/*               - E_NOT_OK : Invalid pointer passed                          */  
/* Contents    : Retrieves the current mode of the watchdog and stores it in  */  
/*               the provided pointer.                                        */  
/* Author      : DN24_FR_AUTOSAR_02_TRUNG_LONG_NINH                           */  
/* Note        :                                                              */  
/******************************************************************************/ 
Std_ReturnType WdgM_GetMode(WdgIf_ModeType* Mode) {
    if (Mode == NULL) {
        return E_NOT_OK;  
    }
    *Mode = currentConfig->WdgMode;
    return E_OK;
}

/******************************************************************************/  
/* ModuleID    :                                                              */  
/* ServiceID   :                                                              */  
/* Name        : WdgM_PerformReset                                            */  
/* Param       : void                                                         */  
/* Return      : void                                                         */  
/* Contents    : Performs the reset for the watchdog manager. Clears the      */  
/*               trigger condition for the watchdog.                          */  
/* Author      : DN24_FR_AUTOSAR_02_TRUNG_LONG_NINH                           */  
/* Note        :                                                              */  
/******************************************************************************/ 
void WdgM_PerformReset(void) {
    WdgIf_SetTriggerCondition(0, 0);  
    
    // Tại đây có thể thêm lệnh reset hệ thống, ví dụ:
    // NVIC_SystemReset();  // Lệnh reset hệ thống cho STM32 (hoặc MCU của bạn)
}

/******************************************************************************/  
/* ModuleID    :                                                              */  
/* ServiceID   :                                                              */  
/* Name        : WdgM_CheckpointReached                                       */  
/* Param       : SEID - ID of the supervised entity                           */  
/*               CheckpointID - ID of the checkpoint that was reached         */  
/* Return      : Std_ReturnType                                               */  
/*               - E_OK     : Checkpoint reached successfully                 */  
/*               - E_NOT_OK : Checkpoint ID is invalid or update failed       */  
/* Contents    : Validates the checkpoint and updates the Alive Counter.      */  
/* Author      : DN24_FR_AUTOSAR_02_TRUNG_LONG_NINH                           */  
/* Note        :                                                              */  
/******************************************************************************/  
Std_ReturnType WdgM_CheckpointReached(WdgM_SupervisedEntityIdType SEID, WdgM_CheckpointIdType CheckpointID) {
    // Kiểm tra nếu Checkpoint hợp lệ, và thực hiện cập nhật Alive Counter
    // Cập nhật Alive Counter của Checkpoint, ví dụ:
    // AliveCounters[SEID][CheckpointID]++;

    // Trả về E_OK nếu thành công
    return E_OK;
}

/* End of WdgManager.c */