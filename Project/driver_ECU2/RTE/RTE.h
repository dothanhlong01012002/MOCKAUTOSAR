#ifndef RTE_H
#define RTE_H

#include "CoolingControlSWC.h"
#include "FanControlSWC.h"
#include "NVBlockSWC.h"
#include "CompressorControlSWC.h"
#include "RTE_COM.h"
#include "RTE_DEM.h"

FUNC(void,AUTOMATIC) Rte_EV_ComReceive(VAR(void,AUTOMATIC));
FUNC(Std_ReturnType,AUTOMATIC) Rte_EV_Main(VAR(void,AUTOMATIC));
FUNC(void,AUTOMATIC) Rte_EV_Component(VAR(void,AUTOMATIC));
FUNC(void,AUTOMATIC) Rte_EV_GetError(VAR(void,AUTOMATIC));

#endif