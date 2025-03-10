/******************************************************************************/  
/* Copyright   : FPT Software Corporation                                     */  
/* System Name : AUTOSAR Application Layer                                    */  
/* File Name   : DiagnosticManager.h                                          */  
/* Contents    : Ecu Configuration(Ecuc)                                      */  
/* Author      : DN24_FR_AUTOSAR_02_TRUNG_LONG_NINH                           */  
/* Note        :                                                              */  
/******************************************************************************/  

#ifndef DIAGNOSTIC_EVENT_H
#define DIAGNOSTIC_EVENT_H

/*----------------------------------------------------------------------------*/
/* include headers                                                            */
/*----------------------------------------------------------------------------*/

#include "Std_Types.h"
#include "RTE_DEM.h"

#define EVENT_ID_TEMPERATURE_SENSOR_ERROR 0x01
#define EVENT_ID_ENGINESPEED_SENSOR_FAILURE 0x02
#define MAX_DIAGNOSTIC_EVENTS 50

#define EVENT_STATUS_RESOLVED 0x00
#define EVENT_STATUS_PASS 0x01
#define EVENT_STATUS_FAIL 0x02
typedef uint16 Dem_EventIdType;
typedef uint8 Dem_EventStatus;

/*----------------------------------------------------------------------------*/
/* struct prototype declarations                                              */
/*----------------------------------------------------------------------------*/

typedef struct {
    uint16 eventID;      
    uint8 status;        
} DiagnosticEvent;
extern int eventCount;
extern DiagnosticEvent diagnosticEvents[MAX_DIAGNOSTIC_EVENTS];

/*----------------------------------------------------------------------------*/
/* functions and function style macros                                        */
/*----------------------------------------------------------------------------*/

FUNC(Std_ReturnType, AUTOMATIC) ReportDiagnosticEvent(VAR(uint32, AUTOMATIC) eventID, VAR(uint8, AUTOMATIC) status);
FUNC(Std_ReturnType, AUTOMATIC) GetDiagnosticEventStatus(VAR(uint32, AUTOMATIC) eventID);
FUNC(void, AUTOMATIC) SetEventStatus(VAR(uint32, AUTOMATIC) eventID, VAR(uint8, AUTOMATIC) status);
Std_ReturnType Dem_SetEventStatus(Dem_EventIdType EventId,Dem_EventStatus TypeEventStatus);

#endif /* DIAGNOSTIC_EVENT_H */
/* End of DiagnosticManager.h */
