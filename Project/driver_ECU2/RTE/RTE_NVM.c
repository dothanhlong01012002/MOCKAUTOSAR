#include "RTE_NVM.h"

FUNC(Std_ReturnType,AUTOMATIC) Rte_Call_RP_NVData_CallServerFunction(VAR(uint8,AUTOMATIC) requestID){
    Rte_Call_RP_NVHandle_SeverHandle(requestID);
    int i = 0;
    Data.parameterData[0] = EngineSpeedValue;
    Data.parameterData[1] = TemperatureValue;
    Data.parameterData[2] = FanRatio;
    Data.parameterData[3] = CompressorRatio;
    return E_OK;
}

FUNC(Std_ReturnType,AUTOMATIC) Rte_Call_RP_NVHandle_SeverHandle(VAR(uint8,AUTOMATIC) requestID){
    return HandleNVM_Runable(requestID);
}

FUNC(Std_ReturnType,AUTOMATIC) Rte_Call_RP_NVHandle_SeverHandleWriteData(VAR(uint8,AUTOMATIC) requestID){
    return NvM_WriteBlock(1,Data.parameterData);
}

FUNC(Std_ReturnType,AUTOMATIC) Rte_Call_RP_NVHandle_SeverHandleWriteError(VAR(uint8,AUTOMATIC) requestID){
    return NvM_WriteBlock(1,Data.parameterData);
}

FUNC(Std_ReturnType,AUTOMATIC) Rte_Call_RP_NVHandle_SeverHandleReadData(VAR(uint8,AUTOMATIC) requestID)
{   
    return NvM_ReadBlock(2,Data.errorCodes);
}

FUNC(Std_ReturnType,AUTOMATIC) Rte_Call_RP_NVHandle_SeverHandleReadError(VAR(uint8,AUTOMATIC) requestID)
{   
    return NvM_ReadBlock(2,Data.errorCodes);
}