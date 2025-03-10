/******************************************************************************/  
/* Copyright   : FPT Software Corporation                                     */  
/* System Name : AUTOSAR Application Layer                                    */  
/* File Name   : RTE_COM.h                                               */  
/* Contents    : Ecu Configuration(Ecuc)                                      */  
/* Author      : DN24_FR_AUTOSAR_02_TRUNG_LONG_NINH                           */  
/* Note        :                                                              */  
/******************************************************************************/ 

#ifndef RTE_COM_H
#define RTE_COM_H

/*----------------------------------------------------------------------------*/
/* include headers                                                            */
/*----------------------------------------------------------------------------*/

#include "Compiler.h"
#include "Std_Types.h"
  
/*----------------------------------------------------------------------------*/
/* variables                                                                  */
/*----------------------------------------------------------------------------*/

extern  VAR(uint16,AUTOMATIC) TemperatureValue;
extern  VAR(uint16,AUTOMATIC) EngineSpeedValue;
extern  VAR(uint16,AUTOMATIC) FanRatio;
extern  VAR(uint16,AUTOMATIC) CompressorRatio;
extern  VAR(uint8,AUTOMATIC) ExpectedTemp;

/*----------------------------------------------------------------------------*/
/* function prototype declarations                                            */
/*----------------------------------------------------------------------------*/

extern FUNC(Std_ReturnType, RTE_CODE_EcucPartition_0) Rte_Read_RP_ComData_TempSpeedValue(P2VAR(uint16, AUTOMATIC, AUTOMATIC) Tempvalue, P2VAR(uint16, AUTOMATIC, AUTOMATIC) SpeedValue);
#define Rte_Read_RP_ComData_TempSpeedValue Rte_Read_RP_ComData_TempSpeedValue

extern FUNC(Std_ReturnType, RTE_CODE_EcucPartition_0) Rte_Write_PP_ComData_TempSpeedValue(VAR(uint16, AUTOMATIC) Tempvalue, VAR(uint16, AUTOMATIC) SpeedValue);
#define Rte_Write_PP_ComData_TempSpeedValue Rte_Write_PP_ComData_TempSpeedValue

extern FUNC(Std_ReturnType, RTE_CODE_EcucPartition_0) Rte_Write_PP_FanData_FanValue(VAR(uint16, AUTOMATIC) FanV);
#define Rte_Write_PP_FanData_FanValue Rte_Write_PP_FanData_FanValue

extern FUNC(Std_ReturnType, RTE_CODE_EcucPartition_0) Rte_Read_RP_FanData_FanValue(P2VAR(uint16, AUTOMATIC, AUTOMATIC) FanV);
#define Rte_Read_RP_FanData_FanValue Rte_Read_RP_FanData_FanValue

extern FUNC(Std_ReturnType, RTE_CODE_EcucPartition_0) Rte_Write_PP_CompressorData_CompressorValue(VAR(uint16, AUTOMATIC) CompressorV);
#define Rte_Write_PP_CompressorData_CompressorValue Rte_Write_PP_CompressorData_CompressorValue

extern FUNC(Std_ReturnType, RTE_CODE_EcucPartition_0) Rte_Read_RP_CompressorData_CompressorValue(P2VAR(uint16, AUTOMATIC, AUTOMATIC) CompressorV);
#define Rte_Read_RP_CompressorData_CompressorValue Rte_Read_RP_CompressorData_CompressorValue

extern FUNC(Std_ReturnType, RTE_CODE_EcucPartition_0) Rte_Call_RP_AdjustFan_ControlFan(VAR(uint16, AUTOMATIC) FanR);
#define Rte_Call_RP_AdjustFan_ControlFan Rte_Call_RP_AdjustFan_ControlFan

extern FUNC(Std_ReturnType, RTE_CODE_EcucPartition_0) Rte_Call_RP_AdjustCompressor_ControlCompressor(VAR(uint16, AUTOMATIC) CompressorR);
#define Rte_Call_RP_AdjustCompressor_ControlCompressor Rte_Call_RP_AdjustCompressor_ControlCompressor

extern FUNC(Std_ReturnType, RTE_CODE_EcucPartition_0) Rte_Read_RP_PARAM_ExpectedTemperature(P2VAR(uint16, AUTOMATIC, AUTOMATIC) ExTemp);
#define Rte_Read_RP_PARAM_ExpectedTemperature Rte_Read_RP_PARAM_ExpectedTemperature

extern FUNC(Std_ReturnType, RTE_CODE_EcucPartition_0) Rte_Write_PP_PARAM_ExpectedTemperature(VAR(uint16, AUTOMATIC) ExTemp);
#define Rte_Write_PP_PARAM_ExpectedTemperature Rte_Write_PP_PARAM_ExpectedTemperature

#endif /* RTE_COM_H */
/* End of RTE_COM.h */