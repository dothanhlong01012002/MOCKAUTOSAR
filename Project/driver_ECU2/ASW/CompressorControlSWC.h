/******************************************************************************/  
/* Copyright   : FPT Software Corporation                                     */  
/* System Name : AUTOSAR Application Layer                                    */  
/* File Name   : CompressorControlSWC.h                                       */  
/* Contents    : Ecu Configuration(Ecuc)                                      */  
/* Author      : DN24_FR_AUTOSAR_02_TRUNG_LONG_NINH                           */  
/* Note        :                                                              */  
/******************************************************************************/  

#ifndef COMPRESSORCONTROLSWC_H
#define COMPRESSORCONTROLSWC_H

/*----------------------------------------------------------------------------*/
/* include headers                                                            */
/*----------------------------------------------------------------------------*/

#include "RTE_COM.h"
#include "Compiler.h"
#include "Std_Types.h"

/*----------------------------------------------------------------------------*/
/* function prototype declarations                                            */
/*----------------------------------------------------------------------------*/

FUNC(void,AUTOMATIC) CompressorControl_Runable(VAR(void,AUTOMATIC));

#endif /* COMPRESSORCONTROLSWC_H */
/* End of CompressorControlSWC.h */