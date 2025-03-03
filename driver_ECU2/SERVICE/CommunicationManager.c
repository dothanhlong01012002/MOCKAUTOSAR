#include "CommunicationManager.h"

void ReceiveData_Runable(){
    Rte_Write_PP_ComData_TempSpeedValue(TEMPERATURE_SIMULATE,ENGINESPEED_SIMULATE);
}