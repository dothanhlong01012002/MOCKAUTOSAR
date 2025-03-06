/******************************************************************************/  
/* Copyright   : FPT Software Corporation                                     */  
/* System Name : AUTOSAR Application Layer                                    */  
/* File Name   : EngineSpeedSWC.h                                             */  
/* Contents    : Ecu Configuration(Ecuc)                                      */  
/* Author      : DN24_FR_AUTOSAR_02_TRUNG_LONG_NINH                           */  
/* Note        :                                                              */  
/******************************************************************************/  
#ifndef  ENGINESPEED_H
#define ENGINESPEED_H

/*----------------------------------------------------------------------------*/
/* include headers                                                            */
/*----------------------------------------------------------------------------*/

#include "RTE.h"
#include "Std_Types.h"
#include "Compiler.h"

/*----------------------------------------------------------------------------*/
/* function prototype declarations                                            */
/*----------------------------------------------------------------------------*/

FUNC(void,AUTOMATIC) ReadSpeed_Runable(VAR(void,AUTOMATIC));

#endif /* ENGINESPEED_H */
/* End of EngineSpeedSWC.h */