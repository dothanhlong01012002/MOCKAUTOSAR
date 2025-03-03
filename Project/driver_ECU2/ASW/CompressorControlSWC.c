#include "CompressorControlSWC.h"

FUNC(void,AUTOMATIC) CompressorControl_Runable(VAR(void,AUTOMATIC)){
    VAR(uint16,AUTOMATIC) CompressoerR;
    Rte_Read_RP_CompressorData_CompressorValue(&CompressoerR);
    Rte_Call_PP_AdjustCompressor_ControlCompressor(&CompressoerR);
}


