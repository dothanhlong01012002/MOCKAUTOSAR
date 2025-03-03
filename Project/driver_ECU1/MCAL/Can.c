#include "Can.h"

FUNC(Std_ReturnType,AUTOMATIC) Can_Write(VAR(Can_HwHandleType,AUTOMATIC) Hth,P2CONST(Can_PduType,AUTOMATIC,AUTOMATIC) PduInfo) {
    (void)Hth; (void)PduInfo;
		return E_OK;
}