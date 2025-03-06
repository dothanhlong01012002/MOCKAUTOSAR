#include "IOHwAbCan.h"
#include "PduR.h"

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

    Std_ReturnType status = Can_Write(HW_TYPE,&CanPdu);
    PduR_LoIfTxConfirmation(TxPduId,status);
    return status;
}