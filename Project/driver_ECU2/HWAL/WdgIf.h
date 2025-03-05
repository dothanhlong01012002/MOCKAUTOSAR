#ifndef WDGIF_H
#define WDGIF_H

#include "Std_Types.h"
#include "Wdg.h"

/* Function to set the watchdog mode */
Std_ReturnType WdgIf_SetMode(uint8 DeviceIndex, WdgIf_ModeType WdgMode);

/* Function to set the trigger condition (timeout for watchdog) */
void WdgIf_SetTriggerCondition(uint8 DeviceIndex, uint16 Timeout);


#endif /* WDGIF_H */
