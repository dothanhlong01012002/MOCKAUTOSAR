/******************************************************************************/  
/* Copyright   : FPT Software Corporation                                     */  
/* System Name : AUTOSAR Application Layer                                    */  
/* File Name   : CoolingControlSWC.h                                          */  
/* Contents    : Ecu Configuration(Ecuc)                                      */  
/* Author      : DN24_FR_AUTOSAR_02_TRUNG_LONG_NINH                           */  
/* Note        :                                                              */  
/******************************************************************************/  

#ifndef COOLINGCONTROLSWC_H
#define COOLINGCONTROLSWC_H

/*----------------------------------------------------------------------------*/
/* include headers                                                            */
/*----------------------------------------------------------------------------*/

#include "RTE_COM.h"
#include "RTE_DEM.h"
#include "RTE_NVM.h"
#include "RTE_WDG.h"
#include "Compiler.h"

/*----------------------------------------------------------------------------*/
/* function prototype declarations                                            */
/*----------------------------------------------------------------------------*/

FUNC(Std_ReturnType,AUTOMATIC) CoolingControl_Runable(VAR(void,AUTOMATIC));

#endif /* COOLINGCONTROLSWC_H */
/* End of CoolingControlSWC.h */