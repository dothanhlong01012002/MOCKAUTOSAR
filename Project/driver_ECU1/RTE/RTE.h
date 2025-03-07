/******************************************************************************/  
/* Copyright   : FPT Software Corporation                                     */  
/* System Name : AUTOSAR Application Layer                                    */  
/* File Name   : RTE.h                                                        */  
/* Contents    : Ecu Configuration(Ecuc)                                      */  
/* Author      : DN24_FR_AUTOSAR_02_TRUNG_LONG_NINH                           */  
/* Note        :                                                              */  
/******************************************************************************/ 

#ifndef RTE_H
#define RTE_H

/*----------------------------------------------------------------------------*/
/* include headers                                                            */
/*----------------------------------------------------------------------------*/

#include "Std_Types.h"
#include "IOHwAbSpeedSensor.h"
#include "IOHwAbTemperatureSensor.h"
#include "ComM.h"
#include "Com.h"
#include "EngineSpeedSWC.h"
#include "TemperatureSensorSWC.h"
#include "Rte_AppComTX.h"
#include "Rte_AppReadSensor.h"

/*----------------------------------------------------------------------------*/
/* function prototype declarations                                            */
/*----------------------------------------------------------------------------*/

extern FUNC(void, RTE_CODE_EcucPartition_0) Rte_EV_ReadSensor(VAR(void,AUTOMATIC));
#define Rte_EV_ReadSensor Rte_EV_ReadSensor

extern FUNC(void, RTE_CODE_EcucPartition_0) Rte_EV_DataHandle(VAR(void,AUTOMATIC));
#define Rte_EV_DataHandle Rte_EV_DataHandle

#endif /* RTE_H */
/* End of RTE.h */