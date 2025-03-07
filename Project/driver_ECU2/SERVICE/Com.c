#include "Com.h"

P2VAR(uint8,AUTOMATIC,AUTOMATIC) Com_SignalBuffer;
VAR(uint8,AUTOMATIC) Com_SignalLength;

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