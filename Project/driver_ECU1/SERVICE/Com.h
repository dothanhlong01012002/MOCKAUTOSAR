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

#include <stdint.h>
#include "PduR.h"
#include "Std_Types.h"
#include "RTE.h"
#include "Compiler.h"

typedef uint16 Com_SignalIdType;

/*----------------------------------------------------------------------------*/
/* function prototype declarations                                            */
/*----------------------------------------------------------------------------*/

/******************************************************************************/  
/* ModuleID    :                                                              */  
/* ServiceID   :                                                              */  
/* Name        : Com_SendSignal                                               */  
/* Param       : SignalId - Identifier of the signal to be sent               */  
/*               SignalDataPtr - Pointer to the signal data to be transmitted */  
/* Return      : Std_ReturnType                                               */  
/*               - E_OK     : Transmission request successful                 */  
/*               - E_NOT_OK : Transmission request failed (NULL pointer)      */  
/* Contents    : Creates a PDU containing the signal data and calls PduR      */  
/*               to transmit the data.                                        */  
/* Author      : DN24_FR_AUTOSAR_02_TRUNG_LONG_NINH                           */  
/* Note        : Function checks for NULL pointer and transmits using PduR.   */  
/******************************************************************************/  
FUNC(uint8,AUTOMATIC) Com_SendSignal(VAR(Com_SignalIdType,AUTOMATIC) SignalId, P2CONST(void,AUTOMATIC,AUTOMATIC) SignalDataPtr);

#endif /* COM_H */
/* End of Com.h */