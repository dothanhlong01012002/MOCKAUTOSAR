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

/*----------------------------------------------------------------------------*/
/* functions and function style macros                                        */
/*----------------------------------------------------------------------------*/

/******************************************************************************/  
/* ModuleID    :                                                              */  
/* ServiceID   :                                                              */  
/* Name        : CanIf_Transmit                                               */  
/* Param       : TxPduId - Identifier of the PDU to be transmitted            */  
/*               PduInfoPtr - Pointer to PDU data and length information      */  
/* Return      : Std_ReturnType                                               */  
/*               - E_OK     : Transmission request successful                 */  
/*               - E_NOT_OK : Transmission request failed                     */  
/* Contents    : Transmits a CAN message via the CAN Interface (CanIf).       */  
/*               Maps PDU data to Can_PduType and calls Can_Write().          */  
/* Author      : DN24_FR_AUTOSAR_02_TRUNG_LONG_NINH                           */  
/* Note        : Function interacts with the CAN driver layer.                */  
/******************************************************************************/ 
FUNC(Std_ReturnType,AUTOMATIC) CanIf_Transmit(VAR(PduIdType,AUTOMATIC) TxPduId,P2CONST(PduInfoType,AUTOMATIC,AUTOMATIC) PduInfoPtr)
{
    if (PduInfoPtr == NULL || PduInfoPtr->SduDataPtr == NULL) {
      return E_NOT_OK;
    }

    if (TxPduId >= CANIF_MAX_PDU_ID) {
        return E_NOT_OK;
    }

    VAR(Can_PduType,AUTOMATIC) CanPdu;
    CanPdu.swPduHandle = TxPduId;
    CanPdu.id = CAN_ID;
    CanPdu.length = PduInfoPtr->SduLength;
    CanPdu.sdu = PduInfoPtr->SduDataPtr;

    VAR(Std_ReturnType,AUTOMATIC) status = Can_Write(HW_TYPE,&CanPdu);
    PduR_LoIfTxConfirmation(TxPduId,status);
    return status;
}

/* End of IOHwAbCan.c */