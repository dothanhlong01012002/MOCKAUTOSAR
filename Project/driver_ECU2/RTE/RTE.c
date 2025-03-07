#include "RTE.h"
#include "Can.h"

 #define TEMP_SPEED_SIGNAL_ID    10


FUNC(void,AUTOMATIC) Rte_EV_ComReceive(VAR(void,AUTOMATIC)){
    P2VAR(uint8,AUTOMATIC,AUTOMATIC) DataPtr;
    uint8 DataBuffer[3];  // Cấp phát bộ nhớ cho 3 byte dữ liệu
    DataPtr = DataBuffer; // Gán con trỏ đến vùng bộ nhớ đã cấp phát
    Handle_Can_Interrupt();
    Com_ReceiveSignal(TEMP_SPEED_SIGNAL_ID,DataPtr);
    TemperatureValue = DataPtr[0];
    EngineSpeedValue = ((uint16)DataPtr[1] << 8) + DataPtr[2];
}
FUNC(Std_ReturnType,AUTOMATIC) Rte_EV_Main(VAR(void,AUTOMATIC)){
    return CoolingControl_Runable();
}
FUNC(void,AUTOMATIC) Rte_EV_Component(VAR(void,AUTOMATIC)){
    FanControl_Runable();
    CompressorControl_Runable();
}
FUNC(void,AUTOMATIC) Rte_EV_GetError(VAR(void,AUTOMATIC)){}
