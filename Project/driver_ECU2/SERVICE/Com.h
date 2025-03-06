#ifndef  COM_H
#define COM_H

#include "RTE.h"
#include "string.h"
#include "PduR.h"
#include "Compiler.h"
#include "IOHwAbCan.h"

typedef uint8 Com_SignalIdType;

#define COM_MAX_PDU_ID          30
#define COM_MAX_SIGNAL_ID       30

extern P2VAR(uint8,AUTOMATIC,AUTOMATIC) Com_SignalBuffer;
extern VAR(uint8,AUTOMATIC) Com_SignalLength;

FUNC(uint8,AUTOMATIC) Com_ReceiveSignal(VAR(Com_SignalIdType,AUTOMATIC) SignalId, P2VAR(void,AUTOMATIC,AUTOMATIC) SignalDataPtr);
FUNC(void,AUTOMATIC) Com_RxIndication(VAR(PduIdType,AUTOMATIC) RxPduId,P2CONST(PduInfoType,AUTOMATIC,AUTOMATIC) PduInfoPtr);
#endif