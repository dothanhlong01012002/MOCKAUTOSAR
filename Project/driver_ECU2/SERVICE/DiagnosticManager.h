
#ifndef DIAGNOSTIC_EVENT_H
#define DIAGNOSTIC_EVENT_H

#include "Std_Types.h"
#include "RTE.h"
#define EVENT_ID_TEMPERATURE_SENSOR_ERROR 0x01
#define EVENT_ID_ENGINESPEED_SENSOR_FAILURE 0x02
#define MAX_DIAGNOSTIC_EVENTS 50
// Các trạng thái lỗi
#define EVENT_STATUS_RESOLVED 0x00
#define EVENT_STATUS_PASS 0x01
#define EVENT_STATUS_FAIL 0x02
typedef uint16 Dem_EventIdType;
typedef uint8 Dem_EventStatus;
// Cấu trúc cho một sự kiện lỗi
typedef struct {
    uint16 eventID;      // Mã Event ID
    uint8 status;        // Trạng thái lỗi (PASS, FAIL, RESOLVED, PREFAIL)
} DiagnosticEvent;
extern int eventCount;

void ReportDiagnosticEvent(uint32 eventID, uint8 status);
uint8 GetDiagnosticEventStatus(uint32 eventID);
void SetEventStatus(uint32 eventID, uint8 status);
extern DiagnosticEvent diagnosticEvents[MAX_DIAGNOSTIC_EVENTS];

Std_ReturnType Dem_SetEventStatus(Dem_EventIdType EventId,Dem_EventStatus TypeEventStatus);
#endif // DIAGNOSTIC_EVENT_H
