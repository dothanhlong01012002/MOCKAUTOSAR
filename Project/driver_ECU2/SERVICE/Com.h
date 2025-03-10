/******************************************************************************/  
/* Copyright   : FPT Software Corporation                                     */  
/* System Name : AUTOSAR Application Layer                                    */  
/* File Name   : Com.h                                                        */  
/* Contents    : Ecu Configuration(Ecuc)                                      */  
/* Author      : DN24_FR_AUTOSAR_02_TRUNG_LONG_NINH                           */  
/* Note        :                                                              */  
/******************************************************************************/ 

#ifndef  COM_H
#define COM_H

/*----------------------------------------------------------------------------*/
/* include headers                                                            */
/*----------------------------------------------------------------------------*/

#include "RTE_COM.h"
#include "string.h"
#include "PduR.h"
#include "Compiler.h"
#include "IOHwAbCan.h"

typedef uint8 Com_SignalIdType;

#define COM_MAX_PDU_ID          30
#define COM_MAX_SIGNAL_ID       30

extern P2VAR(uint8,AUTOMATIC,AUTOMATIC) Com_SignalBuffer;
extern VAR(uint8,AUTOMATIC) Com_SignalLength;

/*----------------------------------------------------------------------------*/
/* function prototype declarations                                            */
/*----------------------------------------------------------------------------*/

FUNC(uint8,AUTOMATIC) Com_ReceiveSignal(VAR(Com_SignalIdType,AUTOMATIC) SignalId, P2VAR(void,AUTOMATIC,AUTOMATIC) SignalDataPtr);
FUNC(void,AUTOMATIC) Com_RxIndication(VAR(PduIdType,AUTOMATIC) RxPduId,P2CONST(PduInfoType,AUTOMATIC,AUTOMATIC) PduInfoPtr);

#endif /* COM_H */
/* End of Com.h */