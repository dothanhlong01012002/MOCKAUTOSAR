#include "HwAbMem.h"

Std_ReturnType MemIf_Write(uint16 DeviceIndex, uint16 BlockNumber, const uint8* DataBufferPtr) {
    Fls_Write(FLASH_ERROR_STORAGE_ADDRESS, DataBufferPtr, 8);
    return E_OK;
}

Std_ReturnType MemIf_Read(uint16 DeviceIndex, uint16 BlockNumber, uint8* DataBufferPtr) {

    if (DataBufferPtr == NULL) {
        return E_NOT_OK;
    }

    Fls_Read(FLASH_ERROR_STORAGE_ADDRESS + (BlockNumber * sizeof(uint32)), DataBufferPtr, sizeof(uint32));
    return E_OK;
}