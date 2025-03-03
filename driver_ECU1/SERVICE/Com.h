#ifndef  COM_H
#define COM_H

#include <stdint.h>
#include "PduR.h"
#include "Std_Types.h"
#include "RTE.h"
#include "Compiler.h"

typedef uint16 Com_SignalIdType;

FUNC(uint8,AUTOMATIC) Com_SendSignal(VAR(Com_SignalIdType,AUTOMATIC) SignalId, P2CONST(void,AUTOMATIC,AUTOMATIC) SignalDataPtr);

#endif