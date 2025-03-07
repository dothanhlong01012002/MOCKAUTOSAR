/******************************************************************************/  
/* Copyright   : FPT Software Corporation                                     */  
/* System Name : AUTOSAR Application Layer                                    */  
/* File Name   : CoolingControlSWC.c                                          */  
/* Contents    : Ecu Configuration(Ecuc)                                      */  
/* Author      : DN24_FR_AUTOSAR_02_TRUNG_LONG_NINH                           */  
/* Note        :                                                              */  
/******************************************************************************/  

/*----------------------------------------------------------------------------*/
/* include headers                                                            */
/*----------------------------------------------------------------------------*/

#include "CoolingControlSWC.h"

/*----------------------------------------------------------------------------*/
/* functions and function style macros                                        */
/*----------------------------------------------------------------------------*/

/******************************************************************************/  
/* ModuleID    :                                                              */  
/* ServiceID   :                                                              */  
/* Name        : CoolingControl_Runnable                                      */  
/* Param       : void                                                         */  
/* Return      : Std_ReturnType                                               */  
/*               - E_OK     : Cooling control executed successfully           */  
/*               - E_NOT_OK : Error occurred in sensor data or control logic  */  
/* Contents    : Reads temperature and engine speed values, checks for errors,*/  
/*               and adjusts compressor and fan ratios based on temperature.  */  
/* Author      : DN24_FR_AUTOSAR_02_TRUNG_LONG_NINH                           */  
/* Note        :                                                              */  
/******************************************************************************/  
FUNC(Std_ReturnType,AUTOMATIC) CoolingControl_Runable(VAR(void,AUTOMATIC)){
    VAR(uint16,AUTOMATIC) Temp, Speed, ExTemperature;
    VAR(uint16,AUTOMATIC) compressorRatio,fanRatio;
    VAR(uint16,AUTOMATIC) tempDiff;

    Rte_Read_RP_ComData_TempSpeedValue(&Temp,&Speed);
    Rte_Read_RP_PARAM_ExpectedTemperature(&ExTemperature);

    VAR(uint8,AUTOMATIC) errorOccurred = FALSE;

    if (Temp > 100 || Temp < 0) {
        Rte_Call_RP_ERROR_ReportDiagnosticResult(EVENT_ID_TEMPERATURE_SENSOR_ERROR, EVENT_STATUS_FAIL);
        errorOccurred = TRUE;
    }

    if (Speed < 0 || Speed > 10000) {
        Rte_Call_RP_ERROR_ReportDiagnosticResult(EVENT_ID_ENGINESPEED_SENSOR_FAILURE, EVENT_STATUS_FAIL);
        errorOccurred = TRUE;
    }

    if (errorOccurred) {
        Rte_Call_RP_NVData_CallServerFunction(NV_WRITE_ERROR);
        return E_NOT_OK;
    }

    Rte_Call_RP_ERROR_ReportDiagnosticResult(EVENT_ID_TEMPERATURE_SENSOR_ERROR, EVENT_STATUS_PASS);
    Rte_Call_RP_ERROR_ReportDiagnosticResult(EVENT_ID_ENGINESPEED_SENSOR_FAILURE, EVENT_STATUS_PASS);

    tempDiff= ExTemperature - Temp;
    if(tempDiff >= 5){
        compressorRatio = 100;
        fanRatio = 100;
    }
    else if(tempDiff>0&&tempDiff<5){
        compressorRatio = 50;
        fanRatio = 50;
    }
    else if(tempDiff ==0 || Speed == 0){
        compressorRatio = 0;
        fanRatio = 0;
    }

    Rte_Write_PP_CompressorData_CompressorValue(compressorRatio);
    Rte_Write_PP_FanData_FanValue(fanRatio);
    return E_OK;
}

/* End of CoolingControlSWC.c */
