#ifndef Fsh_H
#define Fsh_H

#include "Std_Types.h"
#include "Compiler.h"

Std_ReturnType Fls_Write(uint32 TargetAddress, const uint8* SourceAddressPtr, uint32 Length);
Std_ReturnType Fls_Read(uint32 TargetAddress, uint8* DestinationPtr, uint32 Length);

// void writeErrorCodeToLog(int errorCode, const char *errorDescription);
// int readErrorCodesFromLog();


#endif