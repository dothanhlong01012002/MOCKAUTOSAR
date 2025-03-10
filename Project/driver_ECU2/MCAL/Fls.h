/******************************************************************************/  
/* Copyright   : FPT Software Corporation                                     */  
/* System Name : AUTOSAR Application Layer                                    */  
/* File Name   : Fls.h                                                        */  
/* Contents    : Ecu Configuration(Ecuc)                                      */  
/* Author      : DN24_FR_AUTOSAR_02_TRUNG_LONG_NINH                           */  
/* Note        :                                                              */  
/******************************************************************************/  

#ifndef Fsh_H
#define Fsh_H

/*----------------------------------------------------------------------------*/
/* include headers                                                            */
/*----------------------------------------------------------------------------*/

#include "Std_Types.h"
#include "Compiler.h"

typedef uint32 Fls_AddressType;
typedef uint32 Fls_LengthType; 

/*----------------------------------------------------------------------------*/
/* function prototype declarations                                            */
/*----------------------------------------------------------------------------*/

FUNC(Std_ReturnType,AUTOMATIC) Fls_Write(VAR(Fls_AddressType, AUTOMATIC) TargetAddress, P2CONST(uint8, AUTOMATIC, AUTOMATIC) SourceAddressPtr, VAR(Fls_LengthType, AUTOMATIC) Length);
FUNC(Std_ReturnType,AUTOMATIC) Fls_Read(VAR(Fls_AddressType, AUTOMATIC) SourceAddress, P2VAR(uint8, AUTOMATIC, AUTOMATIC) TargetAddressPtr, VAR(Fls_LengthType, AUTOMATIC) Length);

extern VAR(uint8,AUTOMATIC) Memory[20];

// void writeErrorCodeToLog(int errorCode, const char *errorDescription);
// int readErrorCodesFromLog();


#endif