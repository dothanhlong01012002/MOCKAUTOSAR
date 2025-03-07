/******************************************************************************/  
/* Copyright   : FPT Software Corporation                                     */  
/* System Name : AUTOSAR Application Layer                                    */  
/* File Name   : FanControlSWC.c                                              */  
/* Contents    : Ecu Configuration(Ecuc)                                      */  
/* Author      : DN24_FR_AUTOSAR_02_TRUNG_LONG_NINH                           */  
/* Note        :                                                              */  
/******************************************************************************/  

/*----------------------------------------------------------------------------*/
/* include headers                                                            */
/*----------------------------------------------------------------------------*/

#include "FanControlSWC.h"

/*----------------------------------------------------------------------------*/
/* functions and function style macros                                        */
/*----------------------------------------------------------------------------*/

/******************************************************************************/  
/* ModuleID    :                                                              */  
/* ServiceID   :                                                              */  
/* Name        : FanControl_Runnable                                          */  
/* Param       : void                                                         */  
/* Return      : void                                                         */  
/* Contents    : Reads the fan value and calls the function to adjust the fan */  
/* Author      : DN24_FR_AUTOSAR_02_TRUNG_LONG_NINH                           */  
/* Note        : Function interacts with RTE to adjust the fan based on the   */  
/*               value read.                                                  */  
/******************************************************************************/ 
FUNC(void,AUTOMATIC) FanControl_Runable(VAR(void,AUTOMATIC)) {
    VAR(uint16,AUTOMATIC) FanR;
    Rte_Read_RP_FanData_FanValue(&FanR);
    Rte_Call_RP_AdjustFan_ControlFan(FanR);
}

/* End of FanControlSWC.c */