#include "Com.h"

#define PDU_ID      5
#define COM_MAX_SIGNAL_ID 30


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

FUNC(void,AUTOMATIC) Com_TxConfirmation(VAR(PduIdType,AUTOMATIC) TxPduId, VAR(Std_ReturnType,AUTOMATIC) result) {
  
}