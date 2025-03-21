
/******************************************************************************/  
/* Copyright   : FPT Software Corporation                                     */  
/* System Name : AUTOSAR Application Layer                                    */  
/* File Name   : DiagnosticManager.c                                          */  
/* Contents    : Ecu Configuration(Ecuc)                                      */  
/* Author      : DN24_FR_AUTOSAR_02_TRUNG_LONG_NINH                           */  
/* Note        :                                                              */  
/******************************************************************************/  

#include "DiagnosticManager.h"
int eventCount = 10;
DiagnosticEvent diagnosticEvents[MAX_DIAGNOSTIC_EVENTS] = {
    {0, EVENT_STATUS_RESOLVED},
    {1, EVENT_STATUS_RESOLVED},
    {2, EVENT_STATUS_RESOLVED},
    {3, EVENT_STATUS_RESOLVED},
    {4, EVENT_STATUS_RESOLVED},
    {5, EVENT_STATUS_RESOLVED},
    {6, EVENT_STATUS_RESOLVED},
    {7, EVENT_STATUS_RESOLVED},
    {8, EVENT_STATUS_RESOLVED},
    {9, EVENT_STATUS_RESOLVED}
};


/*----------------------------------------------------------------------------*/
/* include headers                                                            */
/*----------------------------------------------------------------------------*/

#include "DiagnosticManager.h"

/*----------------------------------------------------------------------------*/
/* variables                                                                  */
/*----------------------------------------------------------------------------*/


/*----------------------------------------------------------------------------*/
/* functions and function style macros                                        */
/*----------------------------------------------------------------------------*/

/******************************************************************************/  
/* ModuleID    :                                                              */  
/* ServiceID   :                                                              */  
/* Name        : ReportDiagnosticEvent                                        */  
/* Param       : eventID - ID of the diagnostic event                         */  
/*               status - Status of the diagnostic event                      */  
/* Return      : Std_ReturnType                                               */  
/*               - E_OK     : Event recorded successfully                     */  
/*               - E_NOT_OK : Event buffer is full                            */  
/* Contents    : Stores diagnostic event information if the buffer is not full*/  
/* Author      : DN24_FR_AUTOSAR_02_TRUNG_LONG_NINH                           */  
/* Note        :                                                              */  
/******************************************************************************/  
FUNC(Std_ReturnType, AUTOMATIC) ReportDiagnosticEvent(VAR(uint32, AUTOMATIC) eventID, VAR(uint8, AUTOMATIC) status)
{
    if (eventCount < MAX_DIAGNOSTIC_EVENTS) { 
        diagnosticEvents[eventCount].eventID = eventID;
        diagnosticEvents[eventCount].status = status;
        eventCount++;  
    }
    return E_OK;
}

/******************************************************************************/  
/* ModuleID    :                                                              */  
/* ServiceID   :                                                              */  
/* Name        : GetDiagnosticEventStatus                                     */  
/* Param       : eventID - ID of the diagnostic event                         */  
/* Return      : Std_ReturnType                                               */  
/*               - status  : Status of the diagnostic event if found          */  
/*               - 0xFF    : Event not found                                  */  
/* Contents    : Searches for the diagnostic event by ID and returns its      */  
/*               status if found, otherwise returns 0xFF.                     */  
/* Author      : DN24_FR_AUTOSAR_02_TRUNG_LONG_NINH                           */  
/* Note        :                                                              */  
/******************************************************************************/  
FUNC(Std_ReturnType, AUTOMATIC) GetDiagnosticEventStatus(VAR(uint32, AUTOMATIC) eventID)
{
    uint8 i = 0;
    for ( ;i < eventCount; i++) {
        if (diagnosticEvents[i].eventID == eventID) {
            return diagnosticEvents[i].status;
        }
    }
    return 0xFF; 
}

/******************************************************************************/  
/* ModuleID    :                                                              */  
/* ServiceID   :                                                              */  
/* Name        : SetEventStatus                                               */  
/* Param       : eventID - ID of the diagnostic event                         */  
/*               status - New status to be set for the event                  */  
/* Return      : void                                                         */  
/* Contents    : Searches for the diagnostic event by ID and updates its      */  
/*               status if found.                                             */  
/* Author      : DN24_FR_AUTOSAR_02_TRUNG_LONG_NINH                           */  
/* Note        :                                                              */  
/******************************************************************************/
FUNC(void, AUTOMATIC) SetEventStatus(VAR(uint32, AUTOMATIC) eventID, VAR(uint8, AUTOMATIC) status)
{
	uint8 i = 0;
    for (; i < eventCount; i++) {
        if (diagnosticEvents[i].eventID == eventID) {
            diagnosticEvents[i].status = status;
            return;
        }
    }
}

/******************************************************************************/  
/* ModuleID    :                                                              */  
/* ServiceID   :                                                              */  
/* Name        : Dem_SetEventStatus                                           */  
/* Param       : EventId - ID of the diagnostic event                         */  
/*               TypeEventStatus - New status to be set for the event         */  
/* Return      : Std_ReturnType                                               */  
/*               - E_OK     : Status update successful                        */  
/*               - E_NOT_OK : Event ID not found                              */  
/* Contents    : Searches for the diagnostic event by ID and updates its      */  
/*               status if found.                                             */  
/* Author      : DN24_FR_AUTOSAR_02_TRUNG_LONG_NINH                           */  
/* Note        :                                                              */  
/******************************************************************************/  
FUNC(Std_ReturnType, AUTOMATIC) Dem_SetEventStatus(VAR(Dem_EventIdType,AUTOMATIC) EventId, VAR(Dem_EventStatus,AUTOMATIC) TypeEventStatus)
{
    VAR(uint8, AUTOMATIC) i;
    for (i = 0; i < eventCount; i++) {
        if (diagnosticEvents[i].eventID == EventId) {
            diagnosticEvents[i].status = TypeEventStatus;
            return E_OK;
        }
    }
    return E_NOT_OK;
}

