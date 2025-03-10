/******************************************************************************/  
/* Copyright   : FPT Software Corporation                                     */  
/* System Name : AUTOSAR Application Layer                                    */  
/* File Name   : Rte_AppComTx.h                                               */  
/* Contents    : Ecu Configuration(Ecuc)                                      */  
/* Author      : DN24_FR_AUTOSAR_02_TRUNG_LONG_NINH                           */  
/* Note        :                                                              */  
/******************************************************************************/ 

#ifndef RTE_APPCOMTX_H
#define RTE_APPCOMTX_H

/*----------------------------------------------------------------------------*/
/* include headers                                                            */
/*----------------------------------------------------------------------------*/

#include "Std_Types.h"
#include "Compiler.h"

/*----------------------------------------------------------------------------*/
/* variables                                                                  */
/*----------------------------------------------------------------------------*/

static VAR(uint16,AUTOMATIC) SpeedValue = 0;
static VAR(uint16,AUTOMATIC) TempValue = 0;

/*----------------------------------------------------------------------------*/
/* function prototype declarations                                            */
/*----------------------------------------------------------------------------*/

extern FUNC(Std_ReturnType, RTE_CODE_EcucPartition_0) Rte_Write_PP_Temperature_TempValue(VAR(uint16,AUTOMATIC) temp);
#define Rte_Write_PP_Temperature_TempValue Rte_Write_PP_Temperature_TempValue
 
extern FUNC(Std_ReturnType, RTE_CODE_EcucPartition_0) Rte_Read_RP_Temperature_TempValue(P2VAR(uint16,AUTOMATIC,AUTOMATIC) temp);
#define Rte_Read_RP_Temperature_TempValue Rte_Read_RP_Temperature_TempValue

extern FUNC(Std_ReturnType, RTE_CODE_EcucPartition_0) Rte_Read_RP_Speed_SpeedValue(P2VAR(uint16,AUTOMATIC,AUTOMATIC) temp);
#define Rte_Read_RP_Speed_SpeedValue Rte_Read_RP_Speed_SpeedValue

extern FUNC(Std_ReturnType, RTE_CODE_EcucPartition_0) Rte_Write_PP_Speed_SpeedValue(VAR(uint16,AUTOMATIC) temp);
#define Rte_Write_PP_Speed_SpeedValue Rte_Write_PP_Speed_SpeedValue

#endif /* RTE_APPCOMTX_H */
/* End of Rte_AppComTx.h */
