#ifndef  PDUR_H
#define PDUR_H

#include "Std_Types.h"
#include "IOHwAbCan.h"
#include "Compiler.h"

FUNC(Std_ReturnType,AUTOMATIC) PduR_ComTransmit(VAR(PduIdType,AUTOMATIC) TxPduId,P2CONST(PduInfoType,AUTOMATIC,AUTOMATIC) PduInfoPtr);

#endif