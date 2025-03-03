
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
