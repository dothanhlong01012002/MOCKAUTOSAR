#include "NVBlockSWC.h"

FUNC(void,AUTOMATIC) SaveNVM_Runnable(VAR(void,AUTOMATIC)){
    VAR(uint32,AUTOMATIC) errorCode;
    Rte_Call_RP_SaveNVData_NVM(errorCode);
}

FUNC(void,AUTOMATIC) GetNVM_Runnable(VAR(void,AUTOMATIC)){
    VAR(uint32,AUTOMATIC) errorCode;
    Rte_Call_RP_GetNVData_NVM(&errorCode);
}

