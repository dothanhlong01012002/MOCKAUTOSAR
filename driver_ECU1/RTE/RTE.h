#ifndef RTE_H
#define RTE_H
#include "Std_Types.h"
#include "IOHwAbSpeedSensor.h"
#include "IOHwAbTemperatureSensor.h"
#include "ComM.h"
#include "Com.h"
#include "EngineSpeedSWC.h"
#include "TemperatureSensorSWC.h"

static VAR(uint16,AUTOMATIC) TemperatureValue = 0;
static VAR(uint16,AUTOMATIC) EngineSpeedValue = 0;

static VAR(uint16,AUTOMATIC) SpeedValue = 0;
static VAR(uint16,AUTOMATIC) TempValue = 0;

FUNC(void,AUTOMATIC) Rte_EV_ReadSensor(VAR(void,AUTOMATIC));
FUNC(void,AUTOMATIC) Rte_EV_DataHandle(VAR(void,AUTOMATIC));

FUNC(Std_ReturnType,AUTOMATIC) Rte_Write_PP_Voltage_TemperatureValue(VAR(uint16,AUTOMATIC) temp);
FUNC(Std_ReturnType,AUTOMATIC) Rte_Read_RP_Voltage_TemperatureValue(P2VAR(uint16,AUTOMATIC,AUTOMATIC) temp);
FUNC(Std_ReturnType,AUTOMATIC) Rte_Write_PP_Temperature_TempValue(VAR(uint16,AUTOMATIC) temp);
FUNC(Std_ReturnType,AUTOMATIC) Rte_Read_RP_Temperature_TempValue(P2VAR(uint16,AUTOMATIC,AUTOMATIC) temp);

FUNC(Std_ReturnType,AUTOMATIC) Rte_Read_RP_Speed_SpeedValue(P2VAR(uint16,AUTOMATIC,AUTOMATIC) temp);
FUNC(Std_ReturnType,AUTOMATIC) Rte_Write_PP_Speed_SpeedValue(VAR(uint16,AUTOMATIC) temp);
FUNC(Std_ReturnType,AUTOMATIC) Rte_Write_PP_Pulse_EngineSpeedValue(VAR(uint16,AUTOMATIC) temp);
FUNC(Std_ReturnType,AUTOMATIC) Rte_Read_RP_Pulse_EngineSpeedValue(P2VAR(uint16,AUTOMATIC,AUTOMATIC) temp);

#endif