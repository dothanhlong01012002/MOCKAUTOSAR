/******************************************************************************/  
/* Copyright   : FPT Software Corporation                                     */  
/* System Name : AUTOSAR Application Layer                                    */  
/* File Name   : IOHwAbCan.c                                                  */  
/* Contents    : Ecu Configuration(Ecuc)                                      */  
/* Author      : DN24_FR_AUTOSAR_02_TRUNG_LONG_NINH                           */  
/* Note        :                                                              */  
/******************************************************************************/  

/*----------------------------------------------------------------------------*/
/* include headers                                                            */
/*----------------------------------------------------------------------------*/

#include "IOHwAbCan.h"
#include "PduR.h"

P2VAR(uint8,AUTOMATIC,AUTOMATIC) CanRxBuffer;
VAR(uint8,AUTOMATIC) CanRxLength;
VAR(uint8,AUTOMATIC) status = FALSE;

/*----------------------------------------------------------------------------*/
/* functions and function style macros                                        */
/*----------------------------------------------------------------------------*/

/******************************************************************************/  
/* ModuleID    :                                                              */  
/* ServiceID   :                                                              */  
/* Name        : CanIf_ReadRxPduData                                          */  
/* Param       : CanIfRxSduId - Identifier of the received PDU                */  
/*               CanIfRxInfoPtr - Pointer to the PDU info structure to store  */  
/*                               received data                                */  
/* Return      : Std_ReturnType                                               */  
/*               - E_OK     : Read operation successful                       */  
/*               - E_NOT_OK : Invalid PDU ID or NULL pointer                  */  
/* Contents    : Validates the PDU ID, checks for NULL pointers, and copies   */  
/*               the received data into the provided PduInfo structure.       */  
/* Author      : DN24_FR_AUTOSAR_02_TRUNG_LONG_NINH                           */  
/* Note        : Function reads received data and stores it in the provided   */  
/*               PduInfo structure if valid.                                  */  
/******************************************************************************/ 
FUNC(Std_ReturnType,AUTOMATIC) CanIf_ReadRxPduData(VAR(PduIdType,AUTOMATIC) CanIfRxSduId,P2VAR(PduInfoType,AUTOMATIC,AUTOMATIC) CanIfRxInfoPtr) {
    if (CanIfRxInfoPtr == NULL) {
        return E_NOT_OK;
    }

    if (CanIfRxSduId > 10) {
        return E_NOT_OK;
    }

    CanIfRxInfoPtr->SduDataPtr = CanRxBuffer;
    CanIfRxInfoPtr->SduLength = CanRxLength;

    return E_OK;
}

/******************************************************************************/  
/* ModuleID    :                                                              */  
/* ServiceID   :                                                              */  
/* Name        : CanIf_RxIndication                                           */  
/* Param       : Mailbox - Pointer to the CAN hardware mailbox                */  
/*               PduInfoPtr - Pointer to the received PDU data information    */  
/* Return      : void                                                         */  
/* Contents    : Validates input pointers, extracts PDU data, and forwards    */  
/*               the indication to the next layer.                            */  
/* Author      : DN24_FR_AUTOSAR_02_TRUNG_LONG_NINH                           */  
/* Note        : Function processes incoming CAN messages and triggers the    */  
/*               appropriate indication for the next layer.                   */  
/******************************************************************************/ 
FUNC(void,AUTOMATIC) CanIf_RxIndication(P2CONST(Can_HwType,AUTOMATIC,AUTOMATIC) Mailbox,P2CONST(PduInfoType,AUTOMATIC,AUTOMATIC) PduInfoPtr) {
    if (Mailbox == NULL || PduInfoPtr == NULL || PduInfoPtr->SduDataPtr == NULL) {
        return;
    }

    PduIdType RxPduId = (uint32)Mailbox->Hoh;

    CanRxBuffer =  PduInfoPtr->SduDataPtr;
    CanRxLength = PduInfoPtr->SduLength;

    status = TRUE;
    
    PduR_LoIfRxIndication(RxPduId, PduInfoPtr);
}

/******************************************************************************/  
/* ModuleID    :                                                              */  
/* ServiceID   :                                                              */  
/* Name        : CanIf_ReadRxNotifStatus                                      */  
/* Param       : CanIfRxSduId - Identifier of the received PDU                */  
/* Return      : CanIf_NotifStatusType                                        */  
/*               - CANIF_TX_RX_NOTIFICATION : Notification status for received*/  
/*                 PDU                                                        */  
/*               - E_NOT_OK : Invalid PDU ID                                  */  
/* Contents    : Checks the PDU ID and returns the notification status for    */  
/*               the received PDU.                                            */  
/* Author      : DN24_FR_AUTOSAR_02_TRUNG_LONG_NINH                           */  
/* Note        : Function validates the PDU ID and returns a status.          */  
/******************************************************************************/  
FUNC(CanIf_NotifStatusType,AUTOMATIC) CanIf_ReadRxNotifStatus(VAR(PduIdType,AUTOMATIC) CanIfRxSduId) {
    if (CanIfRxSduId > 10) {
        return E_NOT_OK;
    }
    return CANIF_TX_RX_NOTIFICATION;
}

/* End of IOHwAbCan.c */