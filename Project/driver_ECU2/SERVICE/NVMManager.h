
#ifndef MEMORY_MANAGER_H
#define MEMORY_MANAGER_H

#include "Std_Types.h"
#include "HwAbMem.h"

#define NVM_DTC_ERROR_BLOCK_ID  0x2000
#define ERROR_CODE_SIZE         sizeof(uint32)
#define MEMIF_FLASH_DEVICE_INDEX  0

#define MAX_DATA_PARAMETER  10
#define MAX_ERROR_CODES     5
#define NV_WRITE_DATA       0
#define NV_READ_DATA        1
#define NV_WRITE_ERROR      2
#define NV_READ_ERROR       3

typedef struct {
    uint8 parameterData[MAX_DATA_PARAMETER];    
    uint8 errorCodes[MAX_ERROR_CODES];  
    uint8 numErrorCodes;         
} NvM_DataBuffer;
extern NvM_DataBuffer Data;

Std_ReturnType NvM_WriteBlock(uint16 BlockId, const uint8* DataBufferPtr);
Std_ReturnType NvM_ReadBlock(uint16 BlockId, uint8 *DataBufferPtr);
#endif 
