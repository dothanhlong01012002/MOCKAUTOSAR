#ifndef CAN_H
#define CAN_H

#include "Std_Types.h"
#include "Compiler.h"

typedef uint8 Can_HwHandleType;
typedef uint32 Can_IdType;
typedef uint32 PduIdType;

typedef struct
{
    VAR(PduIdType,AUTOMATIC) swPduHandle;
    VAR(uint8,AUTOMATIC) length;
    VAR(Can_IdType,AUTOMATIC) id;
    P2VAR(uint8,AUTOMATIC,AUTOMATIC) sdu;
} Can_PduType;


FUNC(Std_ReturnType,AUTOMATIC) Can_Write(VAR(Can_HwHandleType,AUTOMATIC) Hth,P2CONST(Can_PduType,AUTOMATIC,AUTOMATIC) PduInfo);

#endif /* CAN_H */
