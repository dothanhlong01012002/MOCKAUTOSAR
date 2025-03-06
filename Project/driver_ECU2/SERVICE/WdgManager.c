#include "WdgManager.h"

// Cấu hình Watchdog với chế độ chậm (Slow Mode) và timeout là 1 giây (1000ms)
WdgM_ConfigType wdgConfig = {
    .WdgMode = WDGIF_SLOW_MODE,  // Chế độ Watchdog: Slow Mode
    .Timeout = 200              // Timeout 1 giây
};

// Hàm khởi tạo Watchdog Manager
void WdgM_Init(const WdgM_ConfigType* ConfigPtr) {
    // Kiểm tra nếu cấu hình là NULL
    if (ConfigPtr == NULL) {
        return;  // Không thực hiện gì nếu cấu hình không hợp lệ
    }
    WdgIf_Init();
    // Lưu cấu hình hiện tại
    currentConfig = (WdgM_ConfigType*)ConfigPtr;

    // Cấu hình chế độ của Watchdog thông qua WdgIf_SetMode
    Std_ReturnType result = WdgIf_SetMode(0, currentConfig->WdgMode);  // DeviceIndex là 0 nếu chỉ có 1 thiết bị Watchdog
    if (result != E_OK) {
        // Nếu không thể thiết lập chế độ, thực hiện reset MCU nếu cần thiết
        WdgM_PerformReset();
    }

    // Cấu hình thời gian timeout cho Watchdog
    WdgIf_SetTriggerCondition(0, currentConfig->Timeout);  // DeviceIndex là 0
}

// Hàm dừng Watchdog Manager
void WdgM_DeInit(void) {
    // Đặt lại tất cả Watchdog về trạng thái khởi tạo ban đầu
    WdgIf_SetMode(0, WDGIF_OFF_MODE);  // Tắt Watchdog
    WdgIf_SetTriggerCondition(0, 0);   // Thiết lập timeout bằng 0 để ngừng Watchdog
}

// Hàm thay đổi chế độ của Watchdog
Std_ReturnType WdgM_SetMode(WdgIf_ModeType Mode) {
    // Kiểm tra xem chế độ có hợp lệ không
    if (Mode < WDGIF_OFF_MODE || Mode > WDGIF_FAST_MODE) {
        return E_NOT_OK;  // Trả về lỗi nếu chế độ không hợp lệ
    }

    // Gọi WdgIf_SetMode để thay đổi chế độ
    return WdgIf_SetMode(0, Mode);  // DeviceIndex là 0 nếu chỉ có 1 thiết bị Watchdog
}

// Hàm lấy chế độ hiện tại của Watchdog Manager
Std_ReturnType WdgM_GetMode(WdgIf_ModeType* Mode) {
    // Kiểm tra nếu con trỏ là NULL
    if (Mode == NULL) {
        return E_NOT_OK;  // Trả về lỗi nếu con trỏ là NULL
    }

    // Lấy chế độ từ cấu hình hiện tại và trả về
    *Mode = currentConfig->WdgMode;
    return E_OK;
}

// Hàm thực hiện reset hệ thống khi hết thời gian
void WdgM_PerformReset(void) {
    // Thiết lập trigger condition của tất cả các thiết bị Watchdog về 0
    WdgIf_SetTriggerCondition(0, 0);  // DeviceIndex là 0
    
    // Tại đây có thể thêm lệnh reset hệ thống, ví dụ:
    // NVIC_SystemReset();  // Lệnh reset hệ thống cho STM32 (hoặc MCU của bạn)
}

// Hàm báo khi một checkpoint được đạt tới
Std_ReturnType WdgM_CheckpointReached(WdgM_SupervisedEntityIdType SEID, WdgM_CheckpointIdType CheckpointID) {
    // Kiểm tra nếu Checkpoint hợp lệ, và thực hiện cập nhật Alive Counter
    // Cập nhật Alive Counter của Checkpoint, ví dụ:
    // AliveCounters[SEID][CheckpointID]++;

    // Trả về E_OK nếu thành công
    return E_OK;
}
