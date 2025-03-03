#include "IOHwAbCan.h"

#define CAN_ID 0x100

FUNC(Std_ReturnType,AUTOMATIC) CanIf_Transmit(VAR(PduIdType,AUTOMATIC) TxPduId,P2CONST(PduInfoType,AUTOMATIC,AUTOMATIC) PduInfoPtr)
{
		(void)TxPduId;
    VAR(Can_PduType,AUTOMATIC) CanPdu;
    CanPdu.id = CAN_ID;
    CanPdu.length = PduInfoPtr->SduLength;
    CanPdu.sdu = PduInfoPtr->SduDataPtr;
    return Can_Write(0,&CanPdu);
}