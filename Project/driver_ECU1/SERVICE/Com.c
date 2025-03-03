#include "Com.h"

#define PDU_ID      5

FUNC(Std_ReturnType,AUTOMATIC) Com_SendSignal(VAR(Com_SignalIdType,AUTOMATIC) SignalId, P2CONST(void,AUTOMATIC,AUTOMATIC) SignalDataPtr) {
    (void)SignalId;
		if (SignalDataPtr == NULL)
    {
        return E_NOT_OK;
    }

    VAR(PduIdType,AUTOMATIC) PduId = PDU_ID;

    // Tạo PDU chứa dữ liệu cần gửi
    VAR(PduInfoType,AUTOMATIC) PduInfo;
    PduInfo.SduDataPtr = (P2VAR(uint8,AUTOMATIC,AUTOMATIC))SignalDataPtr;
    PduInfo.SduLength = 2;

    // Gọi xuống PduR để truyền dữ liệu
    return PduR_ComTransmit(PduId, &PduInfo);
}