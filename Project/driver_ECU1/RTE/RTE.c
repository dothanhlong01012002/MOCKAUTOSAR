/******************************************************************************/  
/* Copyright   : FPT Software Corporation                                     */  
/* System Name : AUTOSAR Application Layer                                    */  
/* File Name   : RTE.c                                                        */  
/* Contents    : Ecu Configuration(Ecuc)                                      */  
/* Author      : DN24_FR_AUTOSAR_02_TRUNG_LONG_NINH                           */  
/* Note        :                                                              */  
/******************************************************************************/ 

/*----------------------------------------------------------------------------*/
/* include headers                                                            */
/*----------------------------------------------------------------------------*/

#include "RTE.h"

#define TEMP_SPEED_SIGNAL_ID    10

/*----------------------------------------------------------------------------*/
/* functions and function style macros                                        */
/*----------------------------------------------------------------------------*/

/******************************************************************************/  
/* ModuleID    :                                                              */  
/* ServiceID   :                                                              */  
/* Name        : Rte_EV_ReadSensor                                            */  
/* Param       : void                                                         */  
/* Return      : void                                                         */  
/* Contents    : Reads pulse and voltage sensor values by calling             */  
/*               corresponding runnable functions.                            */  
/* Author      : DN24_FR_AUTOSAR_02_TRUNG_LONG_NINH                           */  
/* Note        : Function triggers sensor reading runnables.                  */  
/******************************************************************************/ 
#define RTE_START_SEC_CODE_EcucPartition_0
#include "Rte_MemMap.h"
FUNC(void, RTE_CODE_EcucPartition_0) Rte_EV_ReadSensor(VAR(void,AUTOMATIC)){
    ReadPulse_Runable();
    ReadVoltage_Runable();
}
#define RTE_STOP_SEC_CODE_EcucPartition_0
#include "Rte_MemMap.h"

/******************************************************************************/  
/* ModuleID    :                                                              */  
/* ServiceID   :                                                              */  
/* Name        : Rte_EV_DataHandle                                            */  
/* Param       : void                                                         */  
/* Return      : void                                                         */  
/* Contents    : Reads temperature and speed values, processes the data,      */  
/*               and sends it via COM.                                        */  
/* Author      : DN24_FR_AUTOSAR_02_TRUNG_LONG_NINH                           */  
/* Note        : Combines temperature and speed data into a frame and sends.  */  
/******************************************************************************/  
#define RTE_START_SEC_CODE_EcucPartition_0
#include "Rte_MemMap.h"
VAR(uint8,AUTOMATIC) frameData[3];
FUNC(void, RTE_CODE_EcucPartition_0) Rte_EV_DataHandle(VAR(void,AUTOMATIC)){
    ReadTemperature_Runable();
    ReadSpeed_Runable();
    frameData[0] =(uint8)TempValue;
    frameData[1] =(uint8)(SpeedValue >> 8);
    frameData[2] =(uint8)(SpeedValue & 0xFF);
    Com_SendSignal(TEMP_SPEED_SIGNAL_ID,&frameData);
}
#define RTE_STOP_SEC_CODE_EcucPartition_0
#include "Rte_MemMap.h"