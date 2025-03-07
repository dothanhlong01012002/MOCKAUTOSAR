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

void ReportDiagnosticEvent(uint32 eventID, uint8 status)
{
    if (eventCount < MAX_DIAGNOSTIC_EVENTS) { 
        diagnosticEvents[eventCount].eventID = eventID;
        diagnosticEvents[eventCount].status = status;
        eventCount++;  
    }
    else {
        
    }
}

uint8 GetDiagnosticEventStatus(uint32 eventID)
{
		int i = 0;
    for ( ;i < eventCount; i++) {
        if (diagnosticEvents[i].eventID == eventID) {
            return diagnosticEvents[i].status;
        }
    }
    return 0xFF; 
}


void SetEventStatus(uint32 eventID, uint8 status)
{
		int i = 0;
    for (; i < eventCount; i++) {
        if (diagnosticEvents[i].eventID == eventID) {
            diagnosticEvents[i].status = status;
            return;
        }
    }
}

Std_ReturnType Dem_SetEventStatus(Dem_EventIdType EventId,Dem_EventStatus TypeEventStatus){
    int i = 0;
    for (i; i < eventCount; i++) {
        if (diagnosticEvents[i].eventID == EventId) {
            diagnosticEvents[i].status = TypeEventStatus;
            return E_OK;
        }
    }
}
