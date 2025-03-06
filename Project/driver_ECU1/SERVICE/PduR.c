/******************************************************************************/  
/* Copyright   : FPT Software Corporation                                     */  
/* System Name : AUTOSAR Application Layer                                    */  
/* File Name   : PduR.c                                                       */  
/* Contents    : Ecu Configuration(Ecuc)                                      */  
/* Author      : DN24_FR_AUTOSAR_02_TRUNG_LONG_NINH                           */  
/* Note        :                                                              */  
/******************************************************************************/ 

/*----------------------------------------------------------------------------*/
/* include headers                                                            */
/*----------------------------------------------------------------------------*/

#include "PduR.h"
#define PDUR_MAX_PDU_ID 30

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
FUNC(Std_ReturnType,AUTOMATIC) PduR_ComTransmit(VAR(PduIdType,AUTOMATIC) TxPduId,P2CONST(PduInfoType,AUTOMATIC,AUTOMATIC) PduInfoPtr) {
    if (PduInfoPtr == NULL) {
        return E_NOT_OK;
    }

    if (TxPduId >= PDUR_MAX_PDU_ID) {
        return E_NOT_OK;
    }
    return CanIf_Transmit(TxPduId, PduInfoPtr);
}

/******************************************************************************/  
/* ModuleID    :                                                              */  
/* ServiceID   :                                                              */  
/* Name        : PduR_LoIfTxConfirmation                                      */  
/* Param       : TxPduId - Identifier for the transmitted PDU                 */  
/*               result - Result of the transmission (success/failure)        */  
/* Return      : void                                                         */  
/* Contents    : Calls Com_TxConfirmation to indicate the transmission result */  
/* Author      : DN24_FR_AUTOSAR_02_TRUNG_LONG_NINH                           */  
/* Note        : Function forwards the transmission confirmation to Com.      */  
/******************************************************************************/  
FUNC(void,AUTOMATIC) PduR_LoIfTxConfirmation(VAR(PduIdType,AUTOMATIC) TxPduId, VAR(Std_ReturnType,AUTOMATIC) result) {
    Com_TxConfirmation(TxPduId,result);
}

/* End of PduR.c */