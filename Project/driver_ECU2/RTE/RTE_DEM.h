/******************************************************************************/  
/* Copyright   : FPT Software Corporation                                     */  
/* System Name : AUTOSAR Application Layer                                    */  
/* File Name   : RTE_DEM.h                                                    */  
/* Contents    : Ecu Configuration(Ecuc)                                      */  
/* Author      : DN24_FR_AUTOSAR_02_TRUNG_LONG_NINH                           */  
/* Note        :                                                              */  
/******************************************************************************/ 

#ifndef RTE_DEM_H
#define RTE_DEM_H

/*----------------------------------------------------------------------------*/
/* include headers                                                            */
/*----------------------------------------------------------------------------*/

#include "Compiler.h"
#include "Std_Types.h"
#include "DiagnosticManager.h"

/*----------------------------------------------------------------------------*/
/* function prototype declarations                                            */
/*----------------------------------------------------------------------------*/

extern FUNC(Std_ReturnType, RTE_CODE_EcucPartition_0) Rte_Call_RP_ERROR_ReportDiagnosticResult(VAR(uint16, AUTOMATIC) eventID, VAR(uint8, AUTOMATIC) status);
#define Rte_Call_RP_ERROR_ReportDiagnosticResult Rte_Call_RP_ERROR_ReportDiagnosticResult

#endif /* RTE_DEM_H */
/* End of RTE_DEM.h */