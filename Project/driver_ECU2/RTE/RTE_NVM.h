/******************************************************************************/  
/* Copyright   : FPT Software Corporation                                     */  
/* System Name : AUTOSAR Application Layer                                    */  
/* File Name   : RTE_NVM.h                                               */  
/* Contents    : Ecu Configuration(Ecuc)                                      */  
/* Author      : DN24_FR_AUTOSAR_02_TRUNG_LONG_NINH                           */  
/* Note        :                                                              */  
/******************************************************************************/ 

#ifndef RTE_NVM_H
#define RTE_NVM_H

/*----------------------------------------------------------------------------*/
/* include headers                                                            */
/*----------------------------------------------------------------------------*/

#include "Compiler.h"
#include "Std_Types.h"
#include "NVMManager.h"

/*----------------------------------------------------------------------------*/
/* function prototype declarations                                            */
/*----------------------------------------------------------------------------*/

extern FUNC(Std_ReturnType, RTE_CODE_EcucPartition_0) Rte_Call_RP_NVData_CallServerFunction(VAR(uint8, AUTOMATIC) requestID);
#define Rte_Call_RP_NVData_CallServerFunction Rte_Call_RP_NVData_CallServerFunction

extern FUNC(Std_ReturnType, RTE_CODE_EcucPartition_0) Rte_Call_RP_NVHandle_SeverHandle(VAR(uint8, AUTOMATIC) requestID);
#define Rte_Call_RP_NVHandle_SeverHandle Rte_Call_RP_NVHandle_SeverHandle

#endif /* RTE_NVM_H */
/* End of RTE_NVM.h */