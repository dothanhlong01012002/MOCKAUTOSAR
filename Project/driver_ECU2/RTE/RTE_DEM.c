#include "RTE_DEM.h"

FUNC(Std_ReturnType,AUTOMATIC) Rte_Call_RP_ERROR_ReportDiagnosticResult(VAR(Dem_EventIdType,AUTOMATIC) eventID, VAR(Dem_EventStatus,AUTOMATIC) status){
    Dem_SetEventStatus(eventID, status);
    return E_OK;
}
