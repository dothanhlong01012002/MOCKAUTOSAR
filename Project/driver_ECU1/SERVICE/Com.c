/******************************************************************************/  
/* Copyright   : FPT Software Corporation                                     */  
/* System Name : AUTOSAR Application Layer                                    */  
/* File Name   : Com.c                                                        */  
/* Contents    : Ecu Configuration(Ecuc)                                      */  
/* Author      : DN24_FR_AUTOSAR_02_TRUNG_LONG_NINH                           */  
/* Note        :                                                              */  
/******************************************************************************/ 

/*----------------------------------------------------------------------------*/
/* include headers                                                            */
/*----------------------------------------------------------------------------*/

#include "Com.h"

#define PDU_ID      5
#define COM_MAX_SIGNAL_ID 30

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
FUNC(Std_ReturnType,AUTOMATIC) Com_SendSignal(VAR(Com_SignalIdType,AUTOMATIC) SignalId, P2CONST(void,AUTOMATIC,AUTOMATIC) SignalDataPtr) {
    if (SignalDataPtr == NULL) {
      return E_NOT_OK;
    }

    if (SignalId >= COM_MAX_SIGNAL_ID) {
      return E_NOT_OK;
    }

    VAR(PduInfoType,AUTOMATIC) PduInfo;
    PduInfo.SduDataPtr = (P2VAR(uint8,AUTOMATIC,AUTOMATIC))SignalDataPtr;
    PduInfo.SduLength = 3;

    return PduR_ComTransmit(SignalId, &PduInfo);
}

/******************************************************************************/  
/* ModuleID    :                                                              */  
/* ServiceID   :                                                              */  
/* Name        : Com_TxConfirmation                                           */  
/* Param       :                                                              */  
/* Return      :                                                              */  
/* Contents    :                                                              */  
/* Author      : DN24_FR_AUTOSAR_02_TRUNG_LONG_NINH                           */  
/* Note        :                                                              */  
/******************************************************************************/  
FUNC(void,AUTOMATIC) Com_TxConfirmation(VAR(PduIdType,AUTOMATIC) TxPduId, VAR(Std_ReturnType,AUTOMATIC) result) {
  
}

/* End of Com.c */