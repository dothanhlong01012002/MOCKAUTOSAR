#include "WdgIf.h" 

#define MAX_TIMEOUT 1000

Std_ReturnType WdgIf_SetMode(uint8 DeviceIndex, WdgIf_ModeType WdgMode) {

    if (WdgMode < WDGIF_OFF_MODE || WdgMode > WDGIF_FAST_MODE) {
        return E_NOT_OK;  
    }

    Wdg_SetMode(DeviceIndex, WdgMode);
    return E_OK;
}

/* Hàm này dùng để thiết lập thời gian timeout cho watchdog */
void WdgIf_SetTriggerCondition(uint8 DeviceIndex, uint16 Timeout) {
    // Kiểm tra timeout có hợp lệ không (timeout phải nhỏ hơn giá trị tối đa)
    if (Timeout > MAX_TIMEOUT) {
        Timeout = MAX_TIMEOUT;  // Giới hạn timeout
    }

    // Gọi hàm của driver thực tế để thiết lập trigger condition
    Wdg_SetTriggerCondition(DeviceIndex, Timeout);
}
