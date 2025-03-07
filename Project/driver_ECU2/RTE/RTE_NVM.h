#ifndef RTE_NVM_H
#define RTE_NVM_H

#include "Compiler.h"
#include "Std_Types.h"
#include "NVMManager.h"
#include "NVBlockSWC.h"
#include "RTE.h"
FUNC(Std_ReturnType,AUTOMATIC) Rte_Call_RP_NVData_CallServerFunction(VAR(uint8,AUTOMATIC) requestID);
FUNC(Std_ReturnType,AUTOMATIC) Rte_Call_RP_NVHandle_SeverHandle(VAR(uint8,AUTOMATIC) requestID);

FUNC(Std_ReturnType,AUTOMATIC) Rte_Call_RP_NVHandle_SeverHandleWriteData(VAR(uint8,AUTOMATIC) requestID);
FUNC(Std_ReturnType,AUTOMATIC) Rte_Call_RP_NVHandle_SeverHandleWriteError(VAR(uint8,AUTOMATIC) requestID);
FUNC(Std_ReturnType,AUTOMATIC) Rte_Call_RP_NVHandle_SeverHandleReadData(VAR(uint8,AUTOMATIC) requestID);
FUNC(Std_ReturnType,AUTOMATIC) Rte_Call_RP_NVHandle_SeverHandleReadError(VAR(uint8,AUTOMATIC) requestID);




#endif