#ifndef IOHwMenIf_H
#define IOHwMenIf_H

#include "Std_Types.h"
#include "Fls.h"

#define FLASH_ERROR_STORAGE_ADDRESS  0x1000

Std_ReturnType MemIf_Write(uint16 DeviceIndex, uint16 BlockNumber, const uint8* DataBufferPtr);
Std_ReturnType MemIf_Read(uint16 DeviceIndex, uint16 BlockNumber, uint8* DataBufferPtr);

#endif