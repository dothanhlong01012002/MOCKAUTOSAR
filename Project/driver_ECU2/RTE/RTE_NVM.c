#include "RTE_NVM.h"

FUNC(Std_ReturnType,AUTOMATIC) Rte_Call_RP_NVData_CallServerFunction(VAR(uint8,AUTOMATIC) requestID){
    Rte_Call_RP_NVHandle_SeverHandle(requestID);
    return E_OK;
}

FUNC(Std_ReturnType,AUTOMATIC) Rte_Call_RP_NVHandle_SeverHandle(VAR(uint8,AUTOMATIC) requestID){
    return HandleNVM_Runable(requestID);
}
