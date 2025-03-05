#include "NVBlockSWC.h"

FUNC(Std_ReturnType,AUTOMATIC) HandleNVM_Runable(VAR(uint8,AUTOMATIC) requestID){
    if(requestID == 0){
        return NvM_WriteBlock(1,Data.parameterData);
    }else if(requestID == 1){
        return NvM_ReadBlock(1,Data.parameterData);
    }else if(requestID == 2){
        return NvM_WriteBlock(2,Data.errorCodes);
    }else if(requestID == 3){
        return NvM_ReadBlock(2,Data.errorCodes);
    }

    return E_NOT_OK;
}

