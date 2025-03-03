
#ifndef MEMORY_MANAGER_H
#define MEMORY_MANAGER_H

#include "Std_Types.h"

#define NVM_ERROR_CODE_ADDRESS  0x2000
#define ERROR_CODE_SIZE         sizeof(uint32)

Std_ReturnType MemoryManager_WriteErrorCode(uint32 errorCode);
Std_ReturnType MemoryManager_ReadErrorCode(uint32* errorCode);

#endif 
