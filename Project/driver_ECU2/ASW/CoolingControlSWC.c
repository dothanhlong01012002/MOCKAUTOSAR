#include "CoolingControlSWC.h"


FUNC(void,AUTOMATIC) CoolingControl_Runable(VAR(void,AUTOMATIC)){
    VAR(uint16,AUTOMATIC) Temp, Speed, ExTemperature;
    VAR(uint16,AUTOMATIC) compressorRatio,fanRatio;
    VAR(uint16,AUTOMATIC) tempDiff;
    Rte_Read_RP_ComData_TempSpeedValue(&Temp,&Speed);
    Rte_Read_RP_PARAM_ExpectedTemperature(&ExTemperature);

    if(Temp >100||Temp<0){
        Rte_Call_RP_ERROR_ReportDiagnosticResult(EVENT_ID_TEMPERATURE_SENSOR_ERROR,EVENT_STATUS_FAIL);
        Rte_Call_RP_NVData_CallServerFunction(NV_WRITE_ERROR);
    }else if(Speed<0||Speed>10000){
        Rte_Call_RP_ERROR_ReportDiagnosticResult(EVENT_ID_ENGINESPEED_SENSOR_FAILURE,EVENT_STATUS_FAIL);
        Rte_Call_RP_NVData_CallServerFunction(NV_WRITE_ERROR);
    }
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
}