/******************************************************************************/  
/* Copyright   : FPT Software Corporation                                     */  
/* System Name : AUTOSAR Application Layer                                    */  
/* File Name   : Wdg.h                                                        */  
/* Contents    : Ecu Configuration(Ecuc)                                      */  
/* Author      : DN24_FR_AUTOSAR_02_TRUNG_LONG_NINH                           */  
/* Note        :                                                              */  
/******************************************************************************/  

#ifndef WDG_H
#define WDG_H

/*----------------------------------------------------------------------------*/
/* include headers                                                            */
/*----------------------------------------------------------------------------*/

#include "Std_Types.h"
#include <stdint.h>

#define MAX_TIMEOUT 60000  
#define WDG_BASE_ADDR 0x40000000  
#define WDG_CTL    (*(volatile uint32_t*)(WDG_BASE_ADDR + 0x00))  // Control register
#define WDG_LOAD   (*(volatile uint32_t*)(WDG_BASE_ADDR + 0x04))  // Load register
#define WDG_VALUE  (*(volatile uint32_t*)(WDG_BASE_ADDR + 0x08))  // Value register
#define WDG_ICR    (*(volatile uint32_t*)(WDG_BASE_ADDR + 0x0C))  // Interrupt clear register

typedef enum {
    WDGIF_OFF_MODE = 0,  // Watchdog off
    WDGIF_SLOW_MODE,     // Watchdog slow mode
    WDGIF_FAST_MODE      // Watchdog fast mode
} WdgIf_ModeType;

/*----------------------------------------------------------------------------*/
/* function prototype declarations                                            */
/*----------------------------------------------------------------------------*/

void Wdg_SetMode(uint8_t DeviceIndex, WdgIf_ModeType WdgMode);
void Wdg_SetTriggerCondition(uint8_t DeviceIndex, uint16_t Timeout);
void Wdg_Init(void);

#endif /* WDG_H */
/* End of Wdg.h */
