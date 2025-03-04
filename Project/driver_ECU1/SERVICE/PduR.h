/******************************************************************************/  
/* Copyright   : FPT Software Corporation                                     */  
/* System Name : AUTOSAR Application Layer                                    */  
/* File Name   : ComM.h                                                       */  
/* Contents    : Ecu Configuration(Ecuc)                                      */  
/* Author      : DN24_FR_AUTOSAR_02_TRUNG_LONG_NINH                           */  
/* Note        :                                                              */  
/******************************************************************************/ 

#ifndef  PDUR_H
#define PDUR_H

/*----------------------------------------------------------------------------*/
/* include headers                                                            */
/*----------------------------------------------------------------------------*/

#include "Std_Types.h"
#include "IOHwAbCan.h"
#include "Compiler.h"

/*----------------------------------------------------------------------------*/
/* function prototype declarations                                            */
/*----------------------------------------------------------------------------*/

/******************************************************************************/  
/* ModuleID    :                                                              */  
/* ServiceID   :                                                              */  
/* Name        : PduR_ComTransmit                                             */  
/* Param       : TxPduId - Identifier for the PDU to be transmitted           */  
/*               PduInfoPtr - Pointer to the PDU data and length information  */  
/* Return      : Std_ReturnType                                               */  
/*               - E_OK     : Transmission request successful                 */  
/*               - E_NOT_OK : Transmission request failed                     */  
/* Contents    : Forwards the transmission request to CanIf_Transmit function */  
/*               for CAN transmission.                                        */  
/* Author      : DN24_FR_AUTOSAR_02_TRUNG_LONG_NINH                           */  
/* Note        : This function delegates the transmission to the CAN driver.  */  
/******************************************************************************/  
FUNC(Std_ReturnType,AUTOMATIC) PduR_ComTransmit(VAR(PduIdType,AUTOMATIC) TxPduId,P2CONST(PduInfoType,AUTOMATIC,AUTOMATIC) PduInfoPtr);

#endif /* PDUR_H */
/* End of PduR.h */