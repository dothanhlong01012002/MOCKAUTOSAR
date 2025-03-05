#ifndef RTE_H
#define RTE_H

#include "CoolingControlSWC.h"
#include "FanControlSWC.h"
#include "NVBlockSWC.h"
#include "CompressorControlSWC.h"
#include "IOHwAbCompressor.h"
#include "IOHwAbFan.h"
#include "Com.h"
#include "DiagnosticManager.h"
#include "NVMManager.h"

extern VAR(uint8,AUTOMATIC) ExpectedTemp;
extern VAR(uint8,AUTOMATIC) TemperatureValue;
extern VAR(uint16,AUTOMATIC) EngineSpeedValue;
extern VAR(uint16,AUTOMATIC) FanRatio;
extern VAR(uint16,AUTOMATIC) CompressorRatio;
extern VAR(uint16,AUTOMATIC) ErrorCode;

FUNC(Std_ReturnType,AUTOMATIC) Rte_Write_PP_ComData_TempSpeedValue(VAR(uint16,AUTOMATIC) Tempvalue, VAR(uint16,AUTOMATIC) SpeedValue);
FUNC(Std_ReturnType,AUTOMATIC) Rte_Read_RP_ComData_TempSpeedValue(P2VAR(uint16,AUTOMATIC,AUTOMATIC) Tempvalue, P2VAR(uint16,AUTOMATIC,AUTOMATIC) SpeedValue);

FUNC(Std_ReturnType,AUTOMATIC) Rte_Write_PP_FanData_FanValue(VAR(uint16,AUTOMATIC) FanV);
FUNC(Std_ReturnType,AUTOMATIC) Rte_Read_RP_FanData_FanValue(P2VAR(uint16,AUTOMATIC,AUTOMATIC) FanV);

FUNC(Std_ReturnType,AUTOMATIC) Rte_Write_PP_CompressorData_CompressorValue(VAR(uint16,AUTOMATIC) CompressorV);
FUNC(Std_ReturnType,AUTOMATIC) Rte_Read_RP_CompressorData_CompressorValue(P2VAR(uint16,AUTOMATIC,AUTOMATIC) CompressorV);

FUNC(Std_ReturnType,AUTOMATIC) Rte_Call_PP_AdjustFan_ControlFan(P2VAR(uint16,AUTOMATIC,AUTOMATIC) FanR);
FUNC(Std_ReturnType,AUTOMATIC) Rte_RP_AdjustFan_ControlFan(VAR(uint16,AUTOMATIC) FanR);

FUNC(Std_ReturnType,AUTOMATIC) Rte_Call_PP_AdjustCompressor_ControlCompressor(P2VAR(uint16,AUTOMATIC,AUTOMATIC) CompressorR);
FUNC(Std_ReturnType,AUTOMATIC) Rte_RP_AdjustCompressor_ControlCompressor(VAR(uint16,AUTOMATIC) CompressorR);

FUNC(Std_ReturnType,AUTOMATIC) Rte_PP_ERROR_ReportDiagnosticResult(VAR(uint32,AUTOMATIC) eventID, VAR(uint8,AUTOMATIC) status);
FUNC(Std_ReturnType,AUTOMATIC) Rte_Call_RP_ERROR_ReportDiagnosticResult(VAR(uint32,AUTOMATIC) eventID, VAR(uint8,AUTOMATIC) status);

FUNC(Std_ReturnType,AUTOMATIC) Rte_Call_PP_NVData_WriteError(VAR(uint32,AUTOMATIC) ErrorCodeV);
FUNC(Std_ReturnType,AUTOMATIC) Rte_Call_RP_NVData_GetError(P2VAR(uint32,AUTOMATIC,AUTOMATIC) ErrorCodeV);

FUNC(Std_ReturnType,AUTOMATIC) Rte_PP_SaveNVData_NVM(VAR(uint32,AUTOMATIC) ErrorCodeV);
FUNC(Std_ReturnType,AUTOMATIC) Rte_Call_RP_SaveNVData_NVM(VAR(uint32,AUTOMATIC) ErrorCodeV);

FUNC(Std_ReturnType,AUTOMATIC) Rte_PP_GetNVData_NVM(P2VAR(uint32,AUTOMATIC,AUTOMATIC) ErrorCodeV);
FUNC(Std_ReturnType,AUTOMATIC) Rte_Call_RP_GetNVData_NVM(P2VAR(uint32,AUTOMATIC,AUTOMATIC) ErrorCodeV);

FUNC(Std_ReturnType,AUTOMATIC) Rte_Read_RP_PARAM_ExpectedTemperature(P2VAR(uint16,AUTOMATIC,AUTOMATIC) ExTemp);
FUNC(Std_ReturnType,AUTOMATIC) Rte_Write_PP_PARAM_ExpectedTemperature(VAR(uint16,AUTOMATIC) ExTemp);


FUNC(void,AUTOMATIC) Rte_EV_ComReceive(VAR(void,AUTOMATIC));
FUNC(void,AUTOMATIC) Rte_EV_Main(VAR(void,AUTOMATIC));
FUNC(void,AUTOMATIC) Rte_EV_Component(VAR(void,AUTOMATIC));
FUNC(void,AUTOMATIC) Rte_EV_Actuator(VAR(void,AUTOMATIC));
FUNC(void,AUTOMATIC) Rte_EV_GetError(VAR(void,AUTOMATIC));
FUNC(void,AUTOMATIC) Rte_EV_WriteError(VAR(void,AUTOMATIC));

#endif