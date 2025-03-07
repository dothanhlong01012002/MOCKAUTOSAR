/******************************************************************************/  
/* Copyright   : FPT Software Corporation                                     */  
/* System Name : AUTOSAR Application Layer                                    */  
/* File Name   : HwAbMem.c                                                    */  
/* Contents    : Ecu Configuration(Ecuc)                                      */  
/* Author      : DN24_FR_AUTOSAR_02_TRUNG_LONG_NINH                           */  
/* Note        :                                                              */  
/******************************************************************************/  

/*----------------------------------------------------------------------------*/
/* include headers                                                            */
/*----------------------------------------------------------------------------*/

#include "HwAbMem.h"

/*----------------------------------------------------------------------------*/
/* functions and function style macros                                        */
/*----------------------------------------------------------------------------*/

/******************************************************************************/  
/* ModuleID    :                                                              */  
/* ServiceID   :                                                              */  
/* Name        : MemIf_Write                                                  */  
/* Param       : DeviceIndex - Index of the device to be written              */  
/*               BlockNumber - Block number to be written                    */  
/*               DataBufferPtr - Pointer to the data buffer to be written     */  
/* Return      : Std_ReturnType                                               */  
/*               - E_OK     : Write operation successful                      */  
/*               - E_NOT_OK : Write operation failed                          */  
/* Contents    : Writes the provided data buffer to flash memory at a fixed   */  
/*               address.                                                     */  
/* Author      : DN24_FR_AUTOSAR_02_TRUNG_LONG_NINH                           */  
/* Note        : Function uses `Fls_Write` to write data to flash memory.     */  
/******************************************************************************/  
Std_ReturnType MemIf_Write(uint16 DeviceIndex, uint16 BlockNumber, const uint8* DataBufferPtr) {
    Fls_Write(FLASH_ERROR_STORAGE_ADDRESS, DataBufferPtr, 8);
    return E_OK;
}

/******************************************************************************/  
/* ModuleID    :                                                              */  
/* ServiceID   :                                                              */  
/* Name        : MemIf_Read                                                   */  
/* Param       : DeviceIndex - Index of the device to be read                */  
/*               BlockNumber - Block number to be read                        */  
/*               DataBufferPtr - Pointer to the buffer where the data will   */  
/*                               be stored                                    */  
/* Return      : Std_ReturnType                                               */  
/*               - E_OK     : Read operation successful                       */  
/*               - E_NOT_OK : Invalid pointer or read operation failed        */  
/* Contents    : Reads data from flash memory at the specified block number   */  
/*               and stores it in the provided buffer.                        */  
/* Author      : DN24_FR_AUTOSAR_02_TRUNG_LONG_NINH                           */  
/* Note        : Function checks for a NULL pointer and reads data from the  */  
/*               flash storage address.                                       */  
/******************************************************************************/  
Std_ReturnType MemIf_Read(uint16 DeviceIndex, uint16 BlockNumber, uint8* DataBufferPtr) {

    if (DataBufferPtr == NULL) {
        return E_NOT_OK;
    }

    Fls_Read(FLASH_ERROR_STORAGE_ADDRESS + (BlockNumber * sizeof(uint32)), DataBufferPtr, sizeof(uint32));
    return E_OK;
}

/* End of HwAbMem.c */