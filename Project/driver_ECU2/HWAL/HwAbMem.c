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
FUNC(Std_ReturnType, AUTOMATIC) MemIf_Write(VAR(uint16, AUTOMATIC) DeviceIndex, VAR(uint16, AUTOMATIC) BlockNumber, P2CONST(uint8, AUTOMATIC, AUTOMATIC) DataBufferPtr) {
    Fls_Write(FLASH_ERROR_STORAGE_ADDRESS, DataBufferPtr, 8);
    return E_OK;
}

/******************************************************************************/  
/* ModuleID    :                                                              */  
/* ServiceID   :                                                              */  
/* Name        : MemIf_Read                                                   */  
/* Param       : DeviceIndex - Index of the device to be read                 */  
/*               BlockNumber - Block number to be read                        */  
/*               DataBufferPtr - Pointer to the buffer where the data will    */  
/*                               be stored                                    */  
/* Return      : Std_ReturnType                                               */  
/*               - E_OK     : Read operation successful                       */  
/*               - E_NOT_OK : Invalid pointer or read operation failed        */  
/* Contents    : Reads data from flash memory at the specified block number   */  
/*               and stores it in the provided buffer.                        */  
/* Author      : DN24_FR_AUTOSAR_02_TRUNG_LONG_NINH                           */  
/* Note        : Function checks for a NULL pointer and reads data from the   */  
/*               flash storage address.                                       */  
/******************************************************************************/ 
 FUNC(Std_ReturnType, AUTOMATIC) MemIf_Read(VAR(uint16, AUTOMATIC) DeviceIndex, VAR(uint16, AUTOMATIC) BlockNumber, P2VAR(uint8, AUTOMATIC, AUTOMATIC) DataBufferPtr, VAR(uint16, AUTOMATIC) BlockOffset, VAR(uint16, AUTOMATIC) Length )
 {
    if (DataBufferPtr == NULL) {
        return E_NOT_OK;
    }

    VAR(Fls_AddressType, AUTOMATIC) ReadAddress = 
        FLASH_ERROR_STORAGE_ADDRESS + (BlockNumber * sizeof(uint32)) + BlockOffset;

    /* Gọi hàm Fls_Read để đọc dữ liệu từ bộ nhớ Flash */
    if (Fls_Read(ReadAddress, DataBufferPtr, Length) != E_OK) {
        return E_NOT_OK;
    }
    return E_OK;
}

/* End of HwAbMem.c */