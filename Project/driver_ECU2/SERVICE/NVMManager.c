
#include "NVMManager.h"
#include <string.h>

NvM_DataBuffer Data;

Std_ReturnType NvM_WriteBlock(uint16 BlockId, const uint8 *DataBufferPtr)
{
    MemIf_Write(MEMIF_FLASH_DEVICE_INDEX, BlockId, DataBufferPtr);
    return E_OK;
}

Std_ReturnType NvM_ReadBlock(uint16 BlockId, uint8 *DataBufferPtr)
{
    MemIf_Read(MEMIF_FLASH_DEVICE_INDEX, BlockId, DataBufferPtr);
    return E_OK;
}


