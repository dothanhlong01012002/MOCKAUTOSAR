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
#include "WdgManager.h"

#define MAX_DATA_PARAMETER  10
#define MAX_ERROR_CODES     5
#define NV_WRITE_DATA       0
#define NV_READ_DATA        1
#define NV_WRITE_ERROR      2
#define NV_READ_ERROR       3

typedef struct {
    uint8 parameterData[MAX_DATA_PARAMETER];    
    uint8 errorCodes[MAX_ERROR_CODES];  
    uint8 numErrorCodes;         
} NvM_DataBuffer;

extern VAR(NvM_DataBuffer,AUTOMATIC) Data;
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

FUNC(Std_ReturnType,AUTOMATIC) Rte_Call_RP_AdjustFan_ControlFan(VAR(uint16,AUTOMATIC) FanR);
FUNC(Std_ReturnType,AUTOMATIC) Rte_Call_RP_AdjustCompressor_ControlCompressor(VAR(uint16,AUTOMATIC) CompressorR);

FUNC(Std_ReturnType,AUTOMATIC) Rte_Call_RP_ERROR_ReportDiagnosticResult(VAR(uint32,AUTOMATIC) eventID, VAR(uint8,AUTOMATIC) status);
FUNC(Std_ReturnType,AUTOMATIC) Rte_Call_RP_ERROR_SetEvent(VAR(uint32,AUTOMATIC) eventID, VAR(uint8,AUTOMATIC) status);

FUNC(Std_ReturnType,AUTOMATIC) Rte_Read_RP_PARAM_ExpectedTemperature(P2VAR(uint16,AUTOMATIC,AUTOMATIC) ExTemp);
FUNC(Std_ReturnType,AUTOMATIC) Rte_Write_PP_PARAM_ExpectedTemperature(VAR(uint16,AUTOMATIC) ExTemp);

FUNC(Std_ReturnType,AUTOMATIC) Rte_Call_RP_NVData_CallServerFunction(VAR(uint8,AUTOMATIC) requestID);
FUNC(Std_ReturnType,AUTOMATIC) Rte_Call_RP_NVHandle_SeverHandle(VAR(uint8,AUTOMATIC) requestID);

FUNC(void,AUTOMATIC) Rte_EV_ComReceive(VAR(void,AUTOMATIC));
FUNC(Std_ReturnType,AUTOMATIC) Rte_EV_Main(VAR(void,AUTOMATIC));
FUNC(void,AUTOMATIC) Rte_EV_Component(VAR(void,AUTOMATIC));
FUNC(void,AUTOMATIC) Rte_EV_GetError(VAR(void,AUTOMATIC));

FUNC(Std_ReturnType, AUTOMATIC) Rte_Call_RP_WdgM_Init(VAR(const WdgM_ConfigType*, AUTOMATIC) ConfigPtr);
FUNC(void, AUTOMATIC) Rte_Call_RP_WdgM_DeInit(void);
FUNC(Std_ReturnType, AUTOMATIC) Rte_Call_RP_WdgM_SetMode(VAR(WdgIf_ModeType, AUTOMATIC) Mode);
FUNC(Std_ReturnType, AUTOMATIC) Rte_Call_RP_WdgM_GetMode(VAR(WdgIf_ModeType, AUTOMATIC) Mode);
FUNC(void, AUTOMATIC) Rte_Call_RP_WdgM_PerformReset(void);
FUNC(Std_ReturnType, AUTOMATIC) Rte_Call_RP_WdgM_CheckpointReached(VAR(WdgM_SupervisedEntityIdType, AUTOMATIC) SEID,VAR(WdgM_CheckpointIdType, AUTOMATIC) CheckpointID);

#endif