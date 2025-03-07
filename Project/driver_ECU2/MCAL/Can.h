/******************************************************************************/  
/* Copyright   : FPT Software Corporation                                     */  
/* System Name : AUTOSAR Application Layer                                    */  
/* File Name   : Can.h                                                        */  
/* Contents    : Ecu Configuration(Ecuc)                                      */  
/* Author      : DN24_FR_AUTOSAR_02_TRUNG_LONG_NINH                           */  
/* Note        :                                                              */  
/******************************************************************************/  

#ifndef CAN_H
#define CAN_H

/*----------------------------------------------------------------------------*/
/* include headers                                                            */
/*----------------------------------------------------------------------------*/

#include "Std_Types.h"
#include "Compiler.h"

typedef uint8 Can_HwHandleType;
typedef uint32 Can_IdType;
typedef uint32 PduIdType;

/*----------------------------------------------------------------------------*/
/* struct prototype declarations                                              */
/*----------------------------------------------------------------------------*/

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

FUNC(void,AUTOMATIC) Handle_Can_Interrupt(VAR(void,AUTOMATIC));

#endif /* CAN_H */
/* End of Can.h */
