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

Std_ReturnType MemIf_Write(uint16 DeviceIndex, uint16 BlockNumber, const uint8* DataBufferPtr);
Std_ReturnType MemIf_Read(uint16 DeviceIndex, uint16 BlockNumber, uint8* DataBufferPtr);

#endif /* IOHwMenIf_H */
/* End of HwAbMem.h */