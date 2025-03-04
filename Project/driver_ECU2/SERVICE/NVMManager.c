
#include "NVMManager.h"
#include <string.h>  

Std_ReturnType MemoryManager_WriteErrorCode(uint32 errorCode)
{
    memcpy((void*)NVM_ERROR_CODE_ADDRESS, &errorCode, ERROR_CODE_SIZE);
    return E_OK; 
}

Std_ReturnType MemoryManager_ReadErrorCode(uint32* errorCode)
{
    memcpy(errorCode, (void*)NVM_ERROR_CODE_ADDRESS, ERROR_CODE_SIZE);
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