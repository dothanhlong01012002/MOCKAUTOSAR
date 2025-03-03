#include "DiagnosticManager.h"

DiagnosticEvent diagnosticEvents[MAX_DIAGNOSTIC_EVENTS] = {{0, EVENT_STATUS_RESOLVED}};  // Khởi tạo mảng sự kiện lỗi

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
    for (int i = 0; i < eventCount; i++) {
        if (diagnosticEvents[i].eventID == eventID) {
            return diagnosticEvents[i].status;
        }
    }
    return 0xFF; 
}


void SetEventStatus(uint32 eventID, uint8 status)
{
    for (int i = 0; i < eventCount; i++) {
        if (diagnosticEvents[i].eventID == eventID) {
            diagnosticEvents[i].status = status;
            return;
        }
    }
}
