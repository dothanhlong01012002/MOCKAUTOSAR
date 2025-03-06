/******************************************************************************/  
/* Copyright   : FPT Software Corporation                                     */  
/* System Name : AUTOSAR Application Layer                                    */  
/* File Name   : EngineSpeedSWC.c                                             */  
/* Contents    : Ecu Configuration(Ecuc)                                      */  
/* Author      : DN24_FR_AUTOSAR_02_TRUNG_LONG_NINH                           */  
/* Note        :                                                              */  
/******************************************************************************/  

/*----------------------------------------------------------------------------*/
/* include headers                                                            */
/*----------------------------------------------------------------------------*/

#include "EngineSpeedSWC.h"

/*----------------------------------------------------------------------------*/
/* functions and function style macros                                        */
/*----------------------------------------------------------------------------*/

/******************************************************************************/  
/* ModuleID    :                                                              */  
/* ServiceID   :                                                              */  
/* Name        : ReadSpeed_Runable                                            */  
/* Param       : void                                                         */  
/* Return      : void                                                         */  
/* Contents    : Reads engine speed, scales it, and writes the speed value    */  
/* Author      : DN24_FR_AUTOSAR_02_TRUNG_LONG_NINH                           */  
/* Note        :                                                              */  
/******************************************************************************/  
FUNC(void,AUTOMATIC) ReadSpeed_Runable(VAR(void,AUTOMATIC)){
    VAR(uint16,AUTOMATIC) EngineSpeedTemp;
    Rte_Read_RP_Pulse_EngineSpeedValue(&EngineSpeedTemp);
    EngineSpeedTemp *= 1000;
    Rte_Write_PP_Speed_SpeedValue(EngineSpeedTemp);
}

/* End of EngineSpeedSWC.c */