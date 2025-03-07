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

P2VAR(uint8,AUTOMATIC,AUTOMATIC) Com_SignalBuffer;
VAR(uint8,AUTOMATIC) Com_SignalLength;

/*----------------------------------------------------------------------------*/
/* functions and function style macros                                        */
/*----------------------------------------------------------------------------*/

/******************************************************************************/  
/* ModuleID    :                                                              */  
/* ServiceID   :                                                              */  
/* Name        : Com_ReceiveSignal                                            */  
/* Param       : SignalId - The ID of the signal to be received               */  
/*               SignalDataPtr - Pointer to store the received signal data    */  
/* Return      : uint8                                                        */  
/*               - E_OK     : Signal received successfully                    */  
/*               - E_NOT_OK : Invalid parameters or reception failure         */  
/* Contents    : Retrieves the signal data from the communication buffer and  */  
/*               copies it to the provided pointer.                           */  
/* Author      : DN24_FR_AUTOSAR_02_TRUNG_LONG_NINH                           */  
/* Note        :                                                              */  
/******************************************************************************/
FUNC(uint8,AUTOMATIC) Com_ReceiveSignal(VAR(Com_SignalIdType,AUTOMATIC) SignalId, P2VAR(void,AUTOMATIC,AUTOMATIC) SignalDataPtr) {
    if (SignalDataPtr == NULL) {
        return E_NOT_OK;
    }

    if (SignalId >= COM_MAX_SIGNAL_ID) {
        return E_NOT_OK;
    }

    uint8* signalBuffer = Com_SignalBuffer;
    if (signalBuffer == NULL) {
        return E_NOT_OK;
    }
    memcpy(SignalDataPtr, signalBuffer, Com_SignalLength);
    
    return E_OK;    
}

/******************************************************************************/  
/* ModuleID    :                                                              */  
/* ServiceID   :                                                              */  
/* Name        : Com_RxIndication                                             */  
/* Param       : RxPduId - ID of the received PDU                             */  
/*               PduInfoPtr - Pointer to PDU information                      */  
/* Return      : void                                                         */  
/* Contents    : Updates the signal buffer with the received PDU data.        */  
/* Author      : DN24_FR_AUTOSAR_02_TRUNG_LONG_NINH                           */  
/* Note        :                                                              */  
/******************************************************************************/
FUNC(void,AUTOMATIC) Com_RxIndication(VAR(PduIdType,AUTOMATIC) RxPduId, P2CONST(PduInfoType,AUTOMATIC,AUTOMATIC) PduInfoPtr) {
    if (PduInfoPtr == NULL || PduInfoPtr->SduDataPtr == NULL) {
        return;
    }

    if (RxPduId >= COM_MAX_PDU_ID) {
        return;
    }
    Com_SignalBuffer = PduInfoPtr->SduDataPtr;
    Com_SignalLength = PduInfoPtr->SduLength;
}

/* End of Com.c */