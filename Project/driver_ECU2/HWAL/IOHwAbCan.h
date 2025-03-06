#ifndef IOHWABCAN_H
#define IOHWABCAN_H
#include "Can.h"
#include "Std_Types.h"
#include "Compiler.h"


typedef struct
{
    VAR(uint8,AUTOMATIC) SduLength;
    P2VAR(uint8,AUTOMATIC,AUTOMATIC) SduDataPtr;
} PduInfoType;

#define CAN_ID 0x100

extern P2VAR(uint8,AUTOMATIC,AUTOMATIC) CanRxBuffer;
extern VAR(uint8,AUTOMATIC) CanRxLength;

extern VAR(uint8,AUTOMATIC) status;

typedef struct {
    Can_IdType CanId;
    Can_HwHandleType Hoh;
    VAR(uint8,AUTOMATIC) ControllerId;
} Can_HwType;

typedef enum {
    CANIF_NO_NOTIFICATION,
    CANIF_TX_RX_NOTIFICATION
}CanIf_NotifStatusType;

FUNC(Std_ReturnType,AUTOMATIC) CanIf_ReadRxPduData(VAR(PduIdType,AUTOMATIC) CanIfRxSduId,P2VAR(PduInfoType,AUTOMATIC,AUTOMATIC) CanIfRxInfoPtr);
FUNC(void,AUTOMATIC) CanIf_RxIndication(P2CONST(Can_HwType,AUTOMATIC,AUTOMATIC) Mailbox,P2CONST(PduInfoType,AUTOMATIC,AUTOMATIC) PduInfoPtr);
FUNC(CanIf_NotifStatusType,AUTOMATIC) CanIf_ReadRxNotifStatus(VAR(PduIdType,AUTOMATIC) CanIfRxSduId);
#endif