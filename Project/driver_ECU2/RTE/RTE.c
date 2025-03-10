/******************************************************************************/  
/* Copyright   : FPT Software Corporation                                     */  
/* System Name : AUTOSAR Application Layer                                    */  
/* File Name   : RTE.c                                                    */  
/* Contents    : Ecu Configuration(Ecuc)                                      */  
/* Author      : DN24_FR_AUTOSAR_02_TRUNG_LONG_NINH                           */  
/* Note        :                                                              */  
/******************************************************************************/ 
 
/*----------------------------------------------------------------------------*/
/* include headers                                                            */
/*----------------------------------------------------------------------------*/

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
#define RTE_STOP_SEC_CODE_EcucPartition_0
#include "Rte_MemMap.h"

/******************************************************************************/  
/* ModuleID    :                                                              */  
/* ServiceID   :                                                              */  
/* Name        : Rte_EV_Main                                                  */  
/* Param       : void                                                         */  
/* Return      : Std_ReturnType                                               */  
/*               - E_OK     : Operation successful                            */  
/*               - E_NOT_OK : Operation failed                                */  
/* Contents    : Calls the `CoolingControl_Runable` function to execute the   */  
/*               main cooling control logic.                                  */  
/* Author      : DN24_FR_AUTOSAR_02_TRUNG_LONG_NINH                           */  
/* Note        :                                                              */  
/******************************************************************************/
#define RTE_START_SEC_CODE_EcucPartition_0
#include "Rte_MemMap.h"
FUNC(Std_ReturnType, RTE_CODE_EcucPartition_0) Rte_EV_Main(VAR(void, AUTOMATIC)){
    return CoolingControl_Runable();
}
#define RTE_STOP_SEC_CODE_EcucPartition_0
#include "Rte_MemMap.h"

/******************************************************************************/  
/* ModuleID    :                                                              */  
/* ServiceID   :                                                              */  
/* Name        : Rte_EV_Component                                             */  
/* Param       : void                                                         */  
/* Return      : void                                                         */  
/* Contents    : Calls `FanControl_Runable` and `CompressorControl_Runable`   */  
/*               to execute fan and compressor control logic.                 */  
/* Author      : DN24_FR_AUTOSAR_02_TRUNG_LONG_NINH                           */  
/* Note        :                                                              */  
/******************************************************************************/  
#define RTE_START_SEC_CODE_EcucPartition_0
#include "Rte_MemMap.h"
FUNC(void, RTE_CODE_EcucPartition_0) Rte_EV_Component(VAR(void, AUTOMATIC)){
    FanControl_Runable();
    CompressorControl_Runable();
}
FUNC(void,AUTOMATIC) Rte_EV_GetError(VAR(void,AUTOMATIC)){}