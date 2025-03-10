/******************************************************************************/  
/* Copyright   : FPT Software Corporation                                     */  
/* System Name : AUTOSAR Application Layer                                    */  
/* File Name   : HwAbMem.h                                                 */  
/* Contents    : Ecu Configuration(Ecuc)                                      */  
/* Author      : DN24_FR_AUTOSAR_02_TRUNG_LONG_NINH                           */  
/* Note        :                                                              */  
/******************************************************************************/  

#ifndef IOHwMenIf_H
#define IOHwMenIf_H

/*----------------------------------------------------------------------------*/
/* include headers                                                            */
/*----------------------------------------------------------------------------*/

#include "Std_Types.h"
#include "Fls.h"

#define FLASH_ERROR_STORAGE_ADDRESS  0x1000

/*----------------------------------------------------------------------------*/
/* function prototype declarations                                            */
/*----------------------------------------------------------------------------*/

FUNC(Std_ReturnType, AUTOMATIC) MemIf_Write(VAR(uint16, AUTOMATIC) DeviceIndex, VAR(uint16, AUTOMATIC) BlockNumber, P2CONST(uint8, AUTOMATIC, AUTOMATIC) DataBufferPtr);
FUNC(Std_ReturnType, AUTOMATIC) MemIf_Read(VAR(uint16, AUTOMATIC) DeviceIndex, VAR(uint16, AUTOMATIC) BlockNumber, P2VAR(uint8, AUTOMATIC, AUTOMATIC) DataBufferPtr, VAR(uint16, AUTOMATIC) BlockOffset, VAR(uint16, AUTOMATIC) Length );

#endif /* IOHwMenIf_H */
/* End of HwAbMem.h */