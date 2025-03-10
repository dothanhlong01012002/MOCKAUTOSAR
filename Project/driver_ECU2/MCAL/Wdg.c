/******************************************************************************/  
/* Copyright   : FPT Software Corporation                                     */  
/* System Name : AUTOSAR Application Layer                                    */  
/* File Name   : Wdg.c                                                        */  
/* Contents    : Ecu Configuration(Ecuc)                                      */  
/* Author      : DN24_FR_AUTOSAR_02_TRUNG_LONG_NINH                           */  
/* Note        :                                                              */  
/******************************************************************************/  

/*----------------------------------------------------------------------------*/
/* include headers                                                            */
/*----------------------------------------------------------------------------*/

#include "Wdg.h" 

/*----------------------------------------------------------------------------*/
/* functions and function style macros                                        */
/*----------------------------------------------------------------------------*/

/******************************************************************************/  
/* ModuleID    :                                                              */  
/* ServiceID   :                                                              */  
/* Name        : Wdg_SetMode                                                  */  
/* Param       : DeviceIndex - Index of the watchdog device                   */  
/*               WdgMode - Mode to be set for the watchdog                    */  
/* Return      : void                                                         */  
/* Contents    : Sets the mode of the watchdog device based on the provided   */  
/*               mode.                                                        */  
/* Author      : DN24_FR_AUTOSAR_02_TRUNG_LONG_NINH                           */  
/* Note        : Function configures the watchdog mode                        */  
/******************************************************************************/  
FUNC(void, AUTOMATIC) Wdg_SetMode(VAR(WdgIf_ModeType, AUTOMATIC) WdgMode){
    // Kiểm tra chế độ và cấu hình Watchdog tương ứng
    // switch (WdgMode) {
    //     case WDGIF_OFF_MODE:
    //         WDG_CTL = 0x00;  // Tắt Watchdog
    //         break;
    //     case WDGIF_SLOW_MODE:
    //         WDG_CTL = 0x01;  // Thiết lập chế độ chậm (Slow)
    //         break;
    //     case WDGIF_FAST_MODE:
    //         WDG_CTL = 0x02;  // Thiết lập chế độ nhanh (Fast)
    //         break;
    //     default:
    //         WDG_CTL = 0x00;  // Mặc định là tắt Watchdog
    //         break;
    // }
}

/******************************************************************************/  
/* ModuleID    :                                                              */  
/* ServiceID   :                                                              */  
/* Name        : Wdg_SetTriggerCondition                                      */  
/* Param       : DeviceIndex - Index of the watchdog device                   */  
/*               Timeout - Timeout value to be set for the watchdog timer     */  
/* Return      : void                                                         */  
/* Contents    : Validates the timeout value and sets the trigger condition   */  
/*               for the watchdog timer.                                      */  
/* Author      : DN24_FR_AUTOSAR_02_TRUNG_LONG_NINH                           */  
/* Note        : Function ensures the timeout does not exceed the maximum     */  
/*               allowed value and configures the watchdog timer accordingly. */  
/******************************************************************************/  
FUNC(void, AUTOMATIC) Wdg_SetTriggerCondition(VAR(uint16, AUTOMATIC) Timeout) {
    // // Kiểm tra timeout có hợp lệ không, giới hạn tối đa là MAX_TIMEOUT
    // if (Timeout > MAX_TIMEOUT) {
    //     Timeout = MAX_TIMEOUT;  // Giới hạn timeout
    // }

    // // Cấu hình thời gian timeout cho Watchdog Timer
    // WDG_LOAD = Timeout;  // Thiết lập giá trị timeout
    // WDG_VALUE = Timeout; // Khởi động lại giá trị đếm
    // WDG_ICR = 0x01;      // Xóa cờ ngắt của Watchdog (nếu có)
}

/******************************************************************************/  
/* ModuleID    :                                                              */  
/* ServiceID   :                                                              */  
/* Name        : Wdg_Init                                                     */  
/* Param       : void                                                         */  
/* Return      : void                                                         */  
/* Contents    :                                                              */  
/* Author      : DN24_FR_AUTOSAR_02_TRUNG_LONG_NINH                           */  
/* Note        :                                                              */  
/******************************************************************************/ 
FUNC(void, AUTOMATIC) Wdg_Init(void){
    
}

/* End of Wdg.c */