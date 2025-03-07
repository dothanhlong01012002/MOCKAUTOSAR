/******************************************************************************/  
/* Copyright   : FPT Software Corporation                                     */  
/* System Name : AUTOSAR Application Layer                                    */  
/* File Name   : IOHwAbFan.h                                                  */  
/* Contents    : Ecu Configuration(Ecuc)                                      */  
/* Author      : DN24_FR_AUTOSAR_02_TRUNG_LONG_NINH                           */  
/* Note        :                                                              */  
/******************************************************************************/  

#ifndef  IOHWABFAN_H
#define  IOHWABFAN_H

/*----------------------------------------------------------------------------*/
/* include headers                                                            */
/*----------------------------------------------------------------------------*/

#include "Pwm.h"
#include "RTE_COM.h"
#include "Compiler.h"

#define PWM_CHANNEL0 0

/*----------------------------------------------------------------------------*/
/* function prototype declarations                                            */
/*----------------------------------------------------------------------------*/

FUNC(Std_ReturnType,AUTOMATIC) AdjustFanControl(VAR(uint16,AUTOMATIC) fanR);

#endif /* IOHWABFAN_H */
/* End of IOHwAbFan.h */