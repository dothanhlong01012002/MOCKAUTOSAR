#include "IOHwAbCan.h"
#include "PduR.h"

P2VAR(uint8,AUTOMATIC,AUTOMATIC) CanRxBuffer;
VAR(uint8,AUTOMATIC) CanRxLength;

VAR(uint8,AUTOMATIC) status = FALSE;

FUNC(Std_ReturnType,AUTOMATIC) CanIf_ReadRxPduData(VAR(PduIdType,AUTOMATIC) CanIfRxSduId,P2VAR(PduInfoType,AUTOMATIC,AUTOMATIC) CanIfRxInfoPtr) {
    // Kiểm tra tham số đầu vào có hợp lệ không
    if (CanIfRxInfoPtr == NULL) {
        return E_NOT_OK;
    }

    // Kiểm tra ID hợp lệ (giả lập chỉ hỗ trợ ID từ 0 đến 10)
    if (CanIfRxSduId > 10) {
        return E_NOT_OK;
    }

    // Gán dữ liệu vào PduInfoType
    CanIfRxInfoPtr->SduDataPtr = CanRxBuffer;
    CanIfRxInfoPtr->SduLength = CanRxLength;

    return E_OK;
}

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

FUNC(CanIf_NotifStatusType,AUTOMATIC) CanIf_ReadRxNotifStatus(VAR(PduIdType,AUTOMATIC) CanIfRxSduId) {
    if (CanIfRxSduId > 10) {
        return E_NOT_OK;
    }
    return CANIF_TX_RX_NOTIFICATION;
}