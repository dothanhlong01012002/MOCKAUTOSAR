#include "Can.h"
#include "IOHwAbCan.h"

VAR(uint8,AUTOMATIC) frameData[3];

FUNC(void,AUTOMATIC) Handle_Can_Interrupt(VAR(void,AUTOMATIC)) {
    VAR(Can_HwType,AUTOMATIC) Mailbox; 

    VAR(PduInfoType,AUTOMATIC) PduInfo;
    frameData[0] = 0x25;
    frameData[1] = 0x10;
    frameData[2] = 0x20;
    PduInfo.SduDataPtr = (P2VAR(uint8,AUTOMATIC,AUTOMATIC))frameData;
    PduInfo.SduLength = 3;

    CanIf_RxIndication(&Mailbox,&PduInfo);
}