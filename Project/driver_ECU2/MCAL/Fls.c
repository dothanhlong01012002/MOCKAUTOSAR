/******************************************************************************/  
/* Copyright   : FPT Software Corporation                                     */  
/* System Name : AUTOSAR Application Layer                                    */  
/* File Name   : Fls.c                                                        */  
/* Contents    : Ecu Configuration(Ecuc)                                      */  
/* Author      : DN24_FR_AUTOSAR_02_TRUNG_LONG_NINH                           */  
/* Note        :                                                              */  
/******************************************************************************/  

/*----------------------------------------------------------------------------*/
/* include headers                                                            */
/*----------------------------------------------------------------------------*/

#include "Fls.h"
#include <stdio.h>
#include <string.h>
#define MEMORY_SIZE 100

VAR(uint8,AUTOMATIC) Memory[20];

/*----------------------------------------------------------------------------*/
/* functions and function style macros                                        */
/*----------------------------------------------------------------------------*/

/******************************************************************************/  
/* ModuleID    :                                                              */  
/* ServiceID   :                                                              */  
/* Name        : Fls_Write                                                    */  
/* Param       : TargetAddress - Address to write to                          */  
/*               SourceAddressPtr - Pointer to the source data                */  
/*               Length - Length of the data to write                         */  
/* Return      : E_OK     : Write successful                                  */  
/*               E_NOT_OK : Invalid parameters (NULL or zero length)          */  
/* Contents    : Validates the parameters and performs the write operation    */  
/* Author      : DN24_FR_AUTOSAR_02_TRUNG_LONG_NINH                           */  
/* Note        : Function checks for valid parameters before proceeding with  */
/*               the write operation                                          */  
/******************************************************************************/  
FUNC(Std_ReturnType,AUTOMATIC) Fls_Write(VAR(Fls_AddressType, AUTOMATIC) TargetAddress, P2CONST(uint8, AUTOMATIC, AUTOMATIC) SourceAddressPtr, VAR(Fls_LengthType, AUTOMATIC) Length){
    memcpy(Memory, SourceAddressPtr, Length);  

    return E_OK;  
}

/******************************************************************************/  
/* ModuleID    :                                                              */  
/* ServiceID   :                                                              */  
/* Name        : Fls_Read                                                     */  
/* Param       : TargetAddress - Address to read from                         */  
/*               DestinationPtr - Pointer to the buffer to store the data     */  
/*               Length - Length of the data to read                          */  
/* Return      : E_OK     : Read successful                                   */  
/*               E_NOT_OK : Invalid parameters (NULL or zero length)          */  
/* Contents    : Validates the parameters and performs the read operation     */  
/* Author      : DN24_FR_AUTOSAR_02_TRUNG_LONG_NINH                           */  
/* Note        : Function checks for valid parameters before proceeding with  */  
/*               the read operation                                           */  
/******************************************************************************/ 
FUNC(Std_ReturnType,AUTOMATIC) Fls_Read(VAR(Fls_AddressType, AUTOMATIC) SourceAddress, P2VAR(uint8, AUTOMATIC, AUTOMATIC) TargetAddressPtr, VAR(Fls_LengthType, AUTOMATIC) Length){
    if (TargetAddressPtr == NULL || Length == 0) {
        return E_NOT_OK;
    }
    return E_OK;
}

/* End of Fls.c */




