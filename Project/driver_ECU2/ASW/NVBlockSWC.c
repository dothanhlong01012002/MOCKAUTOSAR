#include "NVBlockSWC.h"

FUNC(Std_ReturnType,AUTOMATIC) HandleNVM_Runable(VAR(uint8,AUTOMATIC) requestID){
    if(requestID == 0){
        return Rte_Call_RP_NVHandle_SeverHandleWriteData(NV_WRITE_DATA);
    }else if(requestID == 1){
        return Rte_Call_RP_NVHandle_SeverHandleReadData(NV_READ_DATA);
    }else if(requestID == 2){
        return Rte_Call_RP_NVHandle_SeverHandleWriteError(NV_WRITE_ERROR);
    }else if(requestID == 3){
        return Rte_Call_RP_NVHandle_SeverHandleReadError(NV_READ_ERROR);
    }
    return E_NOT_OK;
}

