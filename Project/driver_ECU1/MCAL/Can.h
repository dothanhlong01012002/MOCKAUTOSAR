/******************************************************************************/  
/* Copyright   : FPT Software Corporation                                     */  
/* System Name : AUTOSAR Application Layer                                    */  
/* File Name   : Can.h                                                        */  
/* Contents    : Ecu Configuration(Ecuc)                                      */  
/* Author      : DN24_FR_AUTOSAR_02_TRUNG_LONG_NINH                           */  
/* Note        :                                                              */  
/******************************************************************************/ 

#ifndef CANTX_H
#define CANTX_H

/*----------------------------------------------------------------------------*/
/* include headers                                                            */
/*----------------------------------------------------------------------------*/

#include "Std_Types.h"
#include "Compiler.h"

/*----------------------------------------------------------------------------*/
/* struct prototype declarations                                              */
/*----------------------------------------------------------------------------*/

typedef uint8 Can_HwHandleType;
typedef uint32 Can_IdType;
typedef uint32 PduIdType;

typedef struct
{
    VAR(PduIdType,AUTOMATIC) swPduHandle;
    VAR(uint8,AUTOMATIC) length;
    VAR(Can_IdType,AUTOMATIC) id;
    P2VAR(uint8,AUTOMATIC,AUTOMATIC) sdu;
} Can_PduType;

/*----------------------------------------------------------------------------*/
/* function prototype declarations                                            */
/*----------------------------------------------------------------------------*/

FUNC(Std_ReturnType,AUTOMATIC) Can_Write(VAR(Can_HwHandleType,AUTOMATIC) Hth,P2CONST(Can_PduType,AUTOMATIC,AUTOMATIC) PduInfo);

#endif /* CAN_H */
/* End of Can.h */