/******************************************************************************/  
/* Copyright   : FPT Software Corporation                                     */  
/* System Name : AUTOSAR Application Layer                                    */  
/* File Name   : PduR.h                                                       */  
/* Contents    : Ecu Configuration(Ecuc)                                      */  
/* Author      : DN24_FR_AUTOSAR_02_TRUNG_LONG_NINH                           */  
/* Note        :                                                              */  
/******************************************************************************/ 

#ifndef  PDURTX_H
#define PDURTX_H

/*----------------------------------------------------------------------------*/
/* include headers                                                            */
/*----------------------------------------------------------------------------*/

#include "Std_Types.h"
#include "IOHwAbCan.h"
#include "Compiler.h"
#include "Com.h"

/*----------------------------------------------------------------------------*/
/* function prototype declarations                                            */
/*----------------------------------------------------------------------------*/

FUNC(Std_ReturnType,AUTOMATIC) PduR_ComTransmit(VAR(PduIdType,AUTOMATIC) TxPduId,P2CONST(PduInfoType,AUTOMATIC,AUTOMATIC) PduInfoPtr);

FUNC(void,AUTOMATIC) PduR_LoIfTxConfirmation(VAR(PduIdType,AUTOMATIC) TxPduId, VAR(Std_ReturnType,AUTOMATIC) result);
    
#endif /* PDUR_H */
/* End of PduR.h */