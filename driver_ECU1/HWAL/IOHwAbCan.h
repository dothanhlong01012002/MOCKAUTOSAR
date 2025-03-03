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

FUNC(Std_ReturnType,AUTOMATIC) CanIf_Transmit(VAR(PduIdType,AUTOMATIC) TxPduId,P2CONST(PduInfoType,AUTOMATIC,AUTOMATIC) PduInfoPtr);

#endif