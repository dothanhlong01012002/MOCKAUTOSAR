#include "PduR.h"

#define PDUR_MAX_PDU_ID 30

FUNC(void,AUTOMATIC) PduR_LoIfRxIndication(VAR(PduIdType,AUTOMATIC) RxPduId, P2CONST(PduInfoType,AUTOMATIC,AUTOMATIC) PduInfoPtr) {
    if (PduInfoPtr == NULL) {
        return; // Bảo vệ chống lỗi NULL Pointer
    }

    // Kiểm tra PDU ID hợp lệ
    if (RxPduId >= PDUR_MAX_PDU_ID) {
        return;
    }
    Com_RxIndication(RxPduId, PduInfoPtr);
}