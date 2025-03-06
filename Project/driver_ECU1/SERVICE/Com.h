/******************************************************************************/  
/* Copyright   : FPT Software Corporation                                     */  
/* System Name : AUTOSAR Application Layer                                    */  
/* File Name   : Com.h                                                        */  
/* Contents    : Ecu Configuration(Ecuc)                                      */  
/* Author      : DN24_FR_AUTOSAR_02_TRUNG_LONG_NINH                           */  
/* Note        :                                                              */  
/******************************************************************************/ 

#ifndef  COMTX_H
#define COMTX_H

/*----------------------------------------------------------------------------*/
/* include headers                                                            */
/*----------------------------------------------------------------------------*/

#include <stdint.h>
#include "PduR.h"
#include "Std_Types.h"
#include "RTE.h"
#include "Compiler.h"

typedef uint16 Com_SignalIdType;

/*----------------------------------------------------------------------------*/
/* function prototype declarations                                            */
/*----------------------------------------------------------------------------*/

FUNC(uint8,AUTOMATIC) Com_SendSignal(VAR(Com_SignalIdType,AUTOMATIC) SignalId, P2CONST(void,AUTOMATIC,AUTOMATIC) SignalDataPtr);

FUNC(void,AUTOMATIC) Com_TxConfirmation(VAR(PduIdType,AUTOMATIC) TxPduId, VAR(Std_ReturnType,AUTOMATIC) result);
    
#endif /* COM_H */
/* End of Com.h */