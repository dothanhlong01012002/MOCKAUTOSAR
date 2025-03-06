#include "Rte_AppComTX.h"

FUNC(Std_ReturnType,AUTOMATIC) Rte_Write_PP_Speed_SpeedValue(VAR(uint16,AUTOMATIC) temp){
    SpeedValue = temp;
    return E_OK;
}

FUNC(Std_ReturnType,AUTOMATIC) Rte_Read_RP_Speed_SpeedValue(P2VAR(uint16,AUTOMATIC,AUTOMATIC) temp){
    if (temp != NULL) {
        *temp = SpeedValue;
        return E_OK;
    }
    return E_NOT_OK;
}

FUNC(Std_ReturnType,AUTOMATIC) Rte_Write_PP_Temperature_TempValue(VAR(uint16,AUTOMATIC) temp){
    TempValue = temp;
    return E_OK;
}

FUNC(Std_ReturnType,AUTOMATIC) Rte_Read_RP_Temperature_TempValue(P2VAR(uint16,AUTOMATIC,AUTOMATIC) temp){
    if (temp != NULL) {
        *temp = TempValue;
        return E_OK;
    }
    return E_NOT_OK;
}
