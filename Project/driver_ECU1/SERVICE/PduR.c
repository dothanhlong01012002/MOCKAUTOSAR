#include "PduR.h"
#define PDUR_MAX_PDU_ID 30

FUNC(Std_ReturnType,AUTOMATIC) PduR_ComTransmit(VAR(PduIdType,AUTOMATIC) TxPduId,P2CONST(PduInfoType,AUTOMATIC,AUTOMATIC) PduInfoPtr) {
    if (PduInfoPtr == NULL) {
        return E_NOT_OK;
    }

    if (TxPduId >= PDUR_MAX_PDU_ID) {
        return E_NOT_OK;
    }
    return CanIf_Transmit(TxPduId, PduInfoPtr);
}

FUNC(void,AUTOMATIC) PduR_LoIfTxConfirmation(VAR(PduIdType,AUTOMATIC) TxPduId, VAR(Std_ReturnType,AUTOMATIC) result) {
    Com_TxConfirmation(TxPduId,result);
}