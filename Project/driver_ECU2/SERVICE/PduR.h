#ifndef PDUR_H
#define PDUR_H

#include "Std_Types.h"
#include "IOHwAbCan.h"
#include "Com.h"
#include "Compiler.h"

FUNC(void,AUTOMATIC) PduR_LoIfRxIndication(VAR(PduIdType,AUTOMATIC) RxPduId, P2CONST(PduInfoType,AUTOMATIC,AUTOMATIC) PduInfoPtr);

#endif