#include "Wdg.h" 
// Cấu hình chế độ cho Watchdog Timer
void Wdg_SetMode(uint8_t DeviceIndex, WdgIf_ModeType WdgMode) {
    // Kiểm tra chế độ và cấu hình Watchdog tương ứng
    switch (WdgMode) {
        case WDGIF_OFF_MODE:
            WDG_CTL = 0x00;  // Tắt Watchdog
            break;
        case WDGIF_SLOW_MODE:
            WDG_CTL = 0x01;  // Thiết lập chế độ chậm (Slow)
            break;
        case WDGIF_FAST_MODE:
            WDG_CTL = 0x02;  // Thiết lập chế độ nhanh (Fast)
            break;
        default:
            WDG_CTL = 0x00;  // Mặc định là tắt Watchdog
            break;
    }
}

// Cấu hình thời gian timeout cho Watchdog Timer
void Wdg_SetTriggerCondition(uint8_t DeviceIndex, uint16_t Timeout) {
    // Kiểm tra timeout có hợp lệ không, giới hạn tối đa là MAX_TIMEOUT
    if (Timeout > MAX_TIMEOUT) {
        Timeout = MAX_TIMEOUT;  // Giới hạn timeout
    }

    // Cấu hình thời gian timeout cho Watchdog Timer
    WDG_LOAD = Timeout;  // Thiết lập giá trị timeout
    WDG_VALUE = Timeout; // Khởi động lại giá trị đếm
    WDG_ICR = 0x01;      // Xóa cờ ngắt của Watchdog (nếu có)
}
