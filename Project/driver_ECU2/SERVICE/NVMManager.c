/******************************************************************************/  
/* Copyright   : FPT Software Corporation                                     */  
/* System Name : AUTOSAR Application Layer                                    */  
/* File Name   : NVMManager.c                                                 */  
/* Contents    : Ecu Configuration(Ecuc)                                      */  
/* Author      : DN24_FR_AUTOSAR_02_TRUNG_LONG_NINH                           */  
/* Note        :                                                              */  
/******************************************************************************/  

/*----------------------------------------------------------------------------*/
/* include headers                                                            */
/*----------------------------------------------------------------------------*/

#include "NVMManager.h"
#include <string.h>

NvM_DataBuffer Data;

/*----------------------------------------------------------------------------*/
/* functions and function style macros                                        */
/*----------------------------------------------------------------------------*/

/******************************************************************************/  
/* ModuleID    :                                                              */  
/* ServiceID   :                                                              */  
/* Name        : NvM_WriteBlock                                               */  
/* Param       : BlockId - The ID of the block to write                       */  
/*               DataBufferPtr - Pointer to the data to be written            */  
/* Return      : Std_ReturnType                                               */  
/*               - E_OK     : Write operation successful                      */  
/*               - E_NOT_OK : Write operation failed                          */  
/* Contents    : Calls the `MemIf_Write` function to write the data to the    */  
/*               specified block.                                             */  
/* Author      : DN24_FR_AUTOSAR_02_TRUNG_LONG_NINH                           */  
/* Note        :                                                              */  
/******************************************************************************/ 
Std_ReturnType NvM_WriteBlock(uint16 BlockId, const uint8 *DataBufferPtr)
{
    MemIf_Write(MEMIF_FLASH_DEVICE_INDEX, BlockId, DataBufferPtr);
    return E_OK;
}

/******************************************************************************/  
/* ModuleID    :                                                              */  
/* ServiceID   :                                                              */  
/* Name        : NvM_ReadBlock                                                */  
/* Param       : BlockId - The ID of the block to read                        */  
/*               DataBufferPtr - Pointer to store the read data               */  
/* Return      : Std_ReturnType                                               */  
/*               - E_OK     : Read operation successful                       */  
/*               - E_NOT_OK : Read operation failed                           */  
/* Contents    : Calls the `MemIf_Read` function to read the data from the    */  
/*               specified block.                                             */  
/* Author      : DN24_FR_AUTOSAR_02_TRUNG_LONG_NINH                           */  
/* Note        :                                                              */  
/******************************************************************************/  
Std_ReturnType NvM_ReadBlock(uint16 BlockId, uint8 *DataBufferPtr)
{
    MemIf_Read(MEMIF_FLASH_DEVICE_INDEX, BlockId, DataBufferPtr);
    return E_OK;
}

/* End of NVMManager.c */
