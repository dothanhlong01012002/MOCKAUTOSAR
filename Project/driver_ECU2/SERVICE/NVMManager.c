
#include "NVMManager.h"
#include <string.h>

Std_ReturnType MemoryManager_WriteErrorCode(uint32 errorCode)
{
    NvM_WriteBlock(NVM_DTC_ERROR_BLOCK_ID, &errorCode);
    return E_OK;
}

Std_ReturnType MemoryManager_ReadErrorCode(uint32 errorCode)
{
    if (errorCode == NULL)
    {
        return E_NOT_OK;
    }
    NvM_ReadBlock(NVM_DTC_ERROR_BLOCK_ID, &errorCode);
    return E_OK;
}

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
