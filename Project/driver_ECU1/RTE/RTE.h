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
FUNC(void,AUTOMATIC) Rte_EV_ReadSensor(VAR(void,AUTOMATIC));

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
FUNC(void,AUTOMATIC) Rte_EV_DataHandle(VAR(void,AUTOMATIC));

#endif /* RTE_H */
/* End of RTE.h */