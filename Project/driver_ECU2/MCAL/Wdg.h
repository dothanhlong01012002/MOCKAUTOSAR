#ifndef WDG_H
#define WDG_H

#include "Std_Types.h"
#include <stdint.h>

#define MAX_TIMEOUT 60000  // Giới hạn timeout (có thể thay đổi tùy theo yêu cầu)

#define WDG_BASE_ADDR 0x40000000  // Địa chỉ base của Watchdog Timer

// Các thanh ghi điều khiển Watchdog Timer
#define WDG_CTL    (*(volatile uint32_t*)(WDG_BASE_ADDR + 0x00))  // Control register
#define WDG_LOAD   (*(volatile uint32_t*)(WDG_BASE_ADDR + 0x04))  // Load register
#define WDG_VALUE  (*(volatile uint32_t*)(WDG_BASE_ADDR + 0x08))  // Value register
#define WDG_ICR    (*(volatile uint32_t*)(WDG_BASE_ADDR + 0x0C))  // Interrupt clear register

// Chế độ của Watchdog Timer
typedef enum {
    WDGIF_OFF_MODE = 0,  // Watchdog off
    WDGIF_SLOW_MODE,     // Watchdog slow mode
    WDGIF_FAST_MODE      // Watchdog fast mode
} WdgIf_ModeType;
void Wdg_SetMode(uint8_t DeviceIndex, WdgIf_ModeType WdgMode);
void Wdg_SetTriggerCondition(uint8_t DeviceIndex, uint16_t Timeout);
void Wdg_Init(void);
#endif /* WDGIF_H */
