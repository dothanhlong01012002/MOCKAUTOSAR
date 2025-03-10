/******************************************************************************/  
/* Copyright   : FPT Software Corporation                                     */  
/* System Name : AUTOSAR Application Layer                                    */  
/* File Name   : IOHwAbCompressor.h                                                  */  
/* Contents    : Ecu Configuration(Ecuc)                                      */  
/* Author      : DN24_FR_AUTOSAR_02_TRUNG_LONG_NINH                           */  
/* Note        :                                                              */  
/******************************************************************************/  

#ifndef  IOHWABCOMPRESSOR_H
#define  IOHWABCOMPRESSOR_H

/*----------------------------------------------------------------------------*/
/* include headers                                                            */
/*----------------------------------------------------------------------------*/

#include "Pwm.h"
#include "RTE_COM.h"
#include "Compiler.h"

#define PWM_CHANNEL1 1

/*----------------------------------------------------------------------------*/
/* function prototype declarations                                            */
/*----------------------------------------------------------------------------*/

FUNC(Std_ReturnType,AUTOMATIC) AdjustCompressorControl(VAR(uint16,AUTOMATIC) compressorR);

#endif /* IOHWABCOMPRESSOR_H */
/* End of IOHwAbCompressor.h */