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
/*               NvM_SrcPtr - Pointer to the data to be written               */  
/* Return      : Std_ReturnType                                               */  
/*               - E_OK     : Write operation successful                      */  
/*               - E_NOT_OK : Write operation failed                          */  
/* Contents    : Calls the `MemIf_Write` function to write the data to the    */  
/*               specified block.                                             */  
/* Author      : DN24_FR_AUTOSAR_02_TRUNG_LONG_NINH                           */  
/* Note        :                                                              */  
/******************************************************************************/ 
FUNC(Std_ReturnType, AUTOMATIC) NvM_WriteBlock(VAR(NvM_BlockIdType, AUTOMATIC) BlockId, P2CONST(uint8, AUTOMATIC, AUTOMATIC) NvM_SrcPtr)
{
    MemIf_Write(MEMIF_FLASH_DEVICE_INDEX, BlockId, NvM_SrcPtr);
    return E_OK;
}

/******************************************************************************/  
/* ModuleID    :                                                              */  
/* ServiceID   :                                                              */  
/* Name        : NvM_ReadBlock                                                */  
/* Param       : BlockId - The ID of the block to read                        */  
/*               NvM_DstPtr - Pointer to store the read data                  */  
/* Return      : Std_ReturnType                                               */  
/*               - E_OK     : Read operation successful                       */  
/*               - E_NOT_OK : Read operation failed                           */  
/* Contents    : Calls the `MemIf_Read` function to read the data from the    */  
/*               specified block.                                             */  
/* Author      : DN24_FR_AUTOSAR_02_TRUNG_LONG_NINH                           */  
/* Note        :                                                              */  
/******************************************************************************/  
FUNC(Std_ReturnType, AUTOMATIC) NvM_ReadBlock(VAR(NvM_BlockIdType, AUTOMATIC) BlockId, P2VAR(uint8, AUTOMATIC, AUTOMATIC) NvM_DstPtr)
{
    VAR(uint16, AUTOMATIC) BlockOffset =  0;
    VAR(uint16, AUTOMATIC) Length =  256;
    MemIf_Read(MEMIF_FLASH_DEVICE_INDEX, BlockId, NvM_DstPtr, BlockOffset, Length);
    return E_OK;
}

/* End of NVMManager.c */
