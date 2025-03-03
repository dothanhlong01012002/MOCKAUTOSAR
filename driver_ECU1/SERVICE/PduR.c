#include "PduR.h"

FUNC(Std_ReturnType,AUTOMATIC) PduR_ComTransmit(VAR(PduIdType,AUTOMATIC) TxPduId,P2CONST(PduInfoType,AUTOMATIC,AUTOMATIC) PduInfoPtr) {
    return CanIf_Transmit(TxPduId, PduInfoPtr);
}