#ifndef RTE_COM_H
#define RTE_COM_H
#include "Compiler.h"
#include "Std_Types.h"

extern  VAR(uint16,AUTOMATIC) TemperatureValue;
extern  VAR(uint16,AUTOMATIC) EngineSpeedValue;
extern  VAR(uint16,AUTOMATIC) FanRatio;
extern  VAR(uint16,AUTOMATIC) CompressorRatio;
extern  VAR(uint8,AUTOMATIC) ExpectedTemp;

FUNC(Std_ReturnType,AUTOMATIC) Rte_Read_RP_ComData_TempSpeedValue(P2VAR(uint16,AUTOMATIC,AUTOMATIC) Tempvalue, P2VAR(uint16,AUTOMATIC,AUTOMATIC) SpeedValue);
FUNC(Std_ReturnType,AUTOMATIC) Rte_Write_PP_ComData_TempSpeedValue(VAR(uint16,AUTOMATIC) Tempvalue, VAR(uint16,AUTOMATIC) SpeedValue);

FUNC(Std_ReturnType,AUTOMATIC) Rte_Write_PP_FanData_FanValue(VAR(uint16,AUTOMATIC) FanV);
FUNC(Std_ReturnType,AUTOMATIC) Rte_Read_RP_FanData_FanValue(P2VAR(uint16,AUTOMATIC,AUTOMATIC) FanV);

FUNC(Std_ReturnType,AUTOMATIC) Rte_Write_PP_CompressorData_CompressorValue(VAR(uint16,AUTOMATIC) CompressorV);
FUNC(Std_ReturnType,AUTOMATIC) Rte_Read_RP_CompressorData_CompressorValue(P2VAR(uint16,AUTOMATIC,AUTOMATIC) CompressorV);

FUNC(Std_ReturnType,AUTOMATIC) Rte_Call_RP_AdjustFan_ControlFan(VAR(uint16,AUTOMATIC) FanR);
FUNC(Std_ReturnType,AUTOMATIC) Rte_Call_RP_AdjustCompressor_ControlCompressor(VAR(uint16,AUTOMATIC) CompressorR);

FUNC(Std_ReturnType,AUTOMATIC) Rte_Read_RP_PARAM_ExpectedTemperature(P2VAR(uint16,AUTOMATIC,AUTOMATIC) ExTemp);
FUNC(Std_ReturnType,AUTOMATIC) Rte_Write_PP_PARAM_ExpectedTemperature(VAR(uint16,AUTOMATIC) ExTemp);

FUNC(Std_ReturnType,AUTOMATIC) Rte_Read_RP_PARAM_ExpectedTemperature(P2VAR(uint16,AUTOMATIC,AUTOMATIC) ExTemp);
FUNC(Std_ReturnType,AUTOMATIC) Rte_Write_PP_PARAM_ExpectedTemperature(VAR(uint16,AUTOMATIC) ExTemp);

#endif