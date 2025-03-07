#include "Can.h"
#include "IOHwAbCan.h"

VAR(uint8,AUTOMATIC) frameData[3];
VAR(uint8,AUTOMATIC) TempData[] = {0x25,0xFF,0x50,0x35,0x20,0xFF};
VAR(uint8,AUTOMATIC) SpeedDataH[] = {0x10,0xFF,0x20,0x35,0x20,0xFF};
VAR(uint8,AUTOMATIC) SpeedDataL[] = {0x25,0xFF,0x50,0x35,0x20,0xFF};
VAR(uint8,AUTOMATIC) count = 0;
FUNC(void,AUTOMATIC) Handle_Can_Interrupt(VAR(void,AUTOMATIC)) {
    VAR(Can_HwType,AUTOMATIC) Mailbox; 

    VAR(PduInfoType,AUTOMATIC) PduInfo;
    frameData[0] = TempData[count];
    frameData[1] = SpeedDataH[count];
    frameData[2] = SpeedDataL[count];
    count++;
    if (count >= 6) count = 0;
    PduInfo.SduDataPtr = (P2VAR(uint8,AUTOMATIC,AUTOMATIC))frameData;
    PduInfo.SduLength = 3;

    CanIf_RxIndication(&Mailbox,&PduInfo);
}