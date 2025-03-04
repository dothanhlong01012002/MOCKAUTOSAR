
#ifndef MEMORY_MANAGER_H
#define MEMORY_MANAGER_H

#include "Std_Types.h"
#include "IOHwMemIf.h"

#define NVM_DTC_ERROR_BLOCK_ID  0x2000
#define ERROR_CODE_SIZE         sizeof(uint32)
#define MEMIF_FLASH_DEVICE_INDEX  0

Std_ReturnType MemoryManager_WriteErrorCode(uint32 errorCode);
Std_ReturnType MemoryManager_ReadErrorCode(uint32 errorCode);
Std_ReturnType NvM_WriteBlock(uint16 BlockId, const uint8* DataBufferPtr);
Std_ReturnType NvM_ReadBlock(uint16 BlockId, uint8 *DataBufferPtr);
#endif 
