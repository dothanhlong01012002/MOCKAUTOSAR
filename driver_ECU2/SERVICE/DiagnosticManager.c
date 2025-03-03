#include "DiagnosticManager.h"

DiagnosticEvent diagnosticEvents[10] = {{0, EVENT_STATUS_RESOLVED}};  // Khởi tạo mảng sự kiện lỗi

void ReportDiagnosticEvent(uint32 eventID, uint8 status)
{
		int i=0;
    for (; i < 10; i++) {
        if (diagnosticEvents[i].eventID == 0) { 
            diagnosticEvents[i].eventID = eventID;
            diagnosticEvents[i].status = status;
            return;
        }
    }
}


uint8 GetDiagnosticEventStatus(uint32 eventID)
{
		int i = 0;
    for (; i < 10; i++) {
        if (diagnosticEvents[i].eventID == eventID) {
            return diagnosticEvents[i].status;
        }
    }
    return 0xFF;  
}


void SetEventStatus(uint32 eventID, uint8 status)
{
		int i = 0;
    for (; i < 10; i++) {
        if (diagnosticEvents[i].eventID == eventID) {
            diagnosticEvents[i].status = status;
            return;
        }
    }
}
