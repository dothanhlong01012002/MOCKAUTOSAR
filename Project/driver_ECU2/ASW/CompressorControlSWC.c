/******************************************************************************/  
/* Copyright   : FPT Software Corporation                                     */  
/* System Name : AUTOSAR Application Layer                                    */  
/* File Name   : CompressorControlSWC.c                                       */  
/* Contents    : Ecu Configuration(Ecuc)                                      */  
/* Author      : DN24_FR_AUTOSAR_02_TRUNG_LONG_NINH                           */  
/* Note        :                                                              */  
/******************************************************************************/  

/*----------------------------------------------------------------------------*/
/* include headers                                                            */
/*----------------------------------------------------------------------------*/

#include "CompressorControlSWC.h"

/*----------------------------------------------------------------------------*/
/* functions and function style macros                                        */
/*----------------------------------------------------------------------------*/

/******************************************************************************/  
/* ModuleID    :                                                              */  
/* ServiceID   :                                                              */  
/* Name        : CompressorControl_Runnable                                   */  
/* Param       : void                                                         */  
/* Return      : void                                                         */  
/* Contents    : Reads compressor data and calls function to adjust compressor*/  
/* Author      : DN24_FR_AUTOSAR_02_TRUNG_LONG_NINH                           */  
/* Note        : Function interacts with RTE to read and adjust compressor.   */  
/******************************************************************************/  
FUNC(void,AUTOMATIC) CompressorControl_Runable(VAR(void,AUTOMATIC)){
    VAR(uint16,AUTOMATIC) CompressoerR;
    Rte_Read_RP_CompressorData_CompressorValue(&CompressoerR);
    Rte_Call_RP_AdjustCompressor_ControlCompressor(CompressoerR);
}

/* End of CompressorControlSWC.c */
