#include "ComM.h"

#define DATA_PDU_ID 0x100

FUNC(Std_ReturnType,AUTOMATIC) ComM_RequestComMode(VAR(ComM_UserHandleType,AUTOMATIC) User,VAR(ComM_ModeType,AUTOMATIC) ComMode) {
    (void)User; (void)ComMode;
		return E_OK;
}