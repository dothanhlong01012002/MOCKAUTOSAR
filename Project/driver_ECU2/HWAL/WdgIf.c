/******************************************************************************/  
/* Copyright   : FPT Software Corporation                                     */  
/* System Name : AUTOSAR Application Layer                                    */  
/* File Name   : WdgIf.c                                                      */  
/* Contents    : Ecu Configuration(Ecuc)                                      */  
/* Author      : DN24_FR_AUTOSAR_02_TRUNG_LONG_NINH                           */  
/* Note        :                                                              */  
/******************************************************************************/  

/*----------------------------------------------------------------------------*/
/* include headers                                                            */
/*----------------------------------------------------------------------------*/

#include "WdgIf.h" 

#define MAX_TIMEOUT 1000

/*----------------------------------------------------------------------------*/
/* functions and function style macros                                        */
/*----------------------------------------------------------------------------*/

/******************************************************************************/  
/* ModuleID    :                                                              */  
/* ServiceID   :                                                              */  
/* Name        : WdgIf_SetMode                                                */  
/* Param       : DeviceIndex - Index of the watchdog device to be configured  */  
/*               WdgMode - Mode to be set for the watchdog device             */  
/* Return      : Std_ReturnType                                               */  
/*               - E_OK     : Mode set successfully                           */  
/*               - E_NOT_OK : Invalid mode provided                           */  
/* Contents    : Validates the requested watchdog mode and sets the mode      */  
/*               for the specified device.                                    */  
/* Author      : DN24_FR_AUTOSAR_02_TRUNG_LONG_NINH                           */  
/* Note        : Function ensures that the provided mode is valid before      */  
/*               calling the `Wdg_SetMode` function to configure the device.  */  
/******************************************************************************/ 
FUNC(Std_ReturnType, AUTOMATIC) WdgIf_SetMode(VAR(uint8, AUTOMATIC) DeviceIndex, VAR(WdgIf_ModeType, AUTOMATIC) WdgMode)
{
    if (WdgMode < WDGIF_OFF_MODE || WdgMode > WDGIF_FAST_MODE) {
        return E_NOT_OK;  
    }

    Wdg_SetMode(WdgMode);
    return E_OK;
}

/******************************************************************************/  
/* ModuleID    :                                                              */  
/* ServiceID   :                                                              */  
/* Name        : WdgIf_SetTriggerCondition                                    */  
/* Param       : DeviceIndex - Index of the watchdog device to be configured  */  
/*               Timeout - Timeout value to be set for the watchdog trigger   */  
/* Return      : void                                                         */  
/* Contents    : Limits the timeout value to a maximum value and sets the     */  
/*               watchdog trigger condition for the specified device.         */  
/* Author      : DN24_FR_AUTOSAR_02_TRUNG_LONG_NINH                           */  
/* Note        : Function ensures that the timeout value does not exceed the  */  
/*               maximum allowed timeout.                                     */  
/******************************************************************************/  
FUNC(void, AUTOMATIC) WdgIf_SetTriggerCondition(VAR(uint8, AUTOMATIC) DeviceIndex, VAR(uint16, AUTOMATIC) Timeout)
{
    if (Timeout > MAX_TIMEOUT) {
        Timeout = MAX_TIMEOUT;  // Giới hạn timeout
    }
    Wdg_SetTriggerCondition(Timeout);
}

/******************************************************************************/  
/* ModuleID    :                                                              */  
/* ServiceID   :                                                              */  
/* Name        : WdgIf_Init                                                   */  
/* Param       : void                                                         */  
/* Return      : void                                                         */  
/* Contents    :                                                              */  
/* Author      : DN24_FR_AUTOSAR_02_TRUNG_LONG_NINH                           */  
/* Note        :                                                              */  
/******************************************************************************/ 
FUNC(void, AUTOMATIC) WdgIf_Init(void){
    Wdg_Init();
}

/* End of WdgIf.c */