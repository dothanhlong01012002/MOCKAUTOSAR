/******************************************************************************/  
/* Copyright   : FPT Software Corporation                                     */  
/* System Name : AUTOSAR Application Layer                                    */  
/* File Name   : WdgIf.h                                                      */  
/* Contents    : Ecu Configuration(Ecuc)                                      */  
/* Author      : DN24_FR_AUTOSAR_02_TRUNG_LONG_NINH                           */  
/* Note        :                                                              */  
/******************************************************************************/  

#ifndef WDGIF_H
#define WDGIF_H

/*----------------------------------------------------------------------------*/
/* include headers                                                            */
/*----------------------------------------------------------------------------*/

#include "Std_Types.h"
#include "Wdg.h"
#include "Compiler.h"

/*----------------------------------------------------------------------------*/
/* function prototype declarations                                            */
/*----------------------------------------------------------------------------*/

FUNC(Std_ReturnType, AUTOMATIC) WdgIf_SetMode(VAR(uint8, AUTOMATIC) DeviceIndex, VAR(WdgIf_ModeType, AUTOMATIC) WdgMode);
FUNC(void, AUTOMATIC) WdgIf_SetTriggerCondition(VAR(uint8, AUTOMATIC) DeviceIndex, VAR(uint16, AUTOMATIC) Timeout);
FUNC(void, AUTOMATIC) WdgIf_Init(void);

#endif /* WDGIF_H */
/* End of WdgIf.h */
