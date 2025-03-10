#include "RTE_NVM.h"

FUNC(Std_ReturnType,AUTOMATIC) Rte_Call_RP_NVData_CallServerFunction(VAR(uint8,AUTOMATIC) requestID, P2VAR(uint8,AUTOMATIC,AUTOMATIC) ErrorCodes)
{
    Rte_Call_RP_NVHandle_SeverHandle(requestID, ErrorCodes);
    return E_OK;
}

FUNC(Std_ReturnType,AUTOMATIC) Rte_Call_RP_NVHandle_SeverHandle(VAR(uint8,AUTOMATIC) requestID, P2VAR(uint8,AUTOMATIC,AUTOMATIC) ErrorCodes){
    return HandleNVM_Runable(requestID, ErrorCodes);
}

FUNC(Std_ReturnType,AUTOMATIC) Rte_Call_RP_NVHandle_SeverHandleWriteData(VAR(uint8,AUTOMATIC) requestID){
    return NvM_WriteBlock(1,Data.parameterData);
}

FUNC(Std_ReturnType,AUTOMATIC) Rte_Call_RP_NVHandle_SeverHandleWriteError(VAR(uint8,AUTOMATIC) requestID,P2VAR(uint8,AUTOMATIC,AUTOMATIC) ErrorCodes){
    memcpy(Data.errorCodes, ErrorCodes, sizeof(uint8) * 8);
    return NvM_WriteBlock(1,Data.errorCodes);
}

FUNC(Std_ReturnType,AUTOMATIC) Rte_Call_RP_NVHandle_SeverHandleReadData(VAR(uint8,AUTOMATIC) requestID)
{   
    return NvM_ReadBlock(2,Data.errorCodes);
}

FUNC(Std_ReturnType,AUTOMATIC) Rte_Call_RP_NVHandle_SeverHandleReadError(VAR(uint8,AUTOMATIC) requestID)
{   
    return NvM_ReadBlock(2,Data.errorCodes);
}