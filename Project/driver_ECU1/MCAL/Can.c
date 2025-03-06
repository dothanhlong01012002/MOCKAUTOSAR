#include "Can.h"

FUNC(Std_ReturnType,AUTOMATIC) Can_Write(VAR(Can_HwHandleType,AUTOMATIC) Hth,P2CONST(Can_PduType,AUTOMATIC,AUTOMATIC) PduInfo) {
      if (PduInfo == NULL || PduInfo->sdu == NULL) {
        return E_NOT_OK;
    }

    if (PduInfo->length == 0) {
        return E_NOT_OK;
    }

    if (!Hth) {
      return E_NOT_OK;
    }
    
		return E_OK;
}