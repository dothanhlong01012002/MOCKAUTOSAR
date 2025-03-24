/******************************************************************************/  
/* Copyright   : FPT Software Corporation                                     */  
/* System Name : AUTOSAR Application Layer                                    */  
/* File Name   : RTE_DEM.c                                                    */  
/* Contents    : Ecu Configuration(Ecuc)                                      */  
/* Author      : DN24_FR_AUTOSAR_02_TRUNG_LONG_NINH                           */  
/* Note        :                                                              */  
/******************************************************************************/ 
 
#ifndef RTE_H
#define RTE_H

/*----------------------------------------------------------------------------*/
/* include headers                                                            */
/*----------------------------------------------------------------------------*/

#include "CoolingControlSWC.h"
#include "FanControlSWC.h"
#include "NVBlockSWC.h"
#include "CompressorControlSWC.h"
#include "RTE_COM.h"
#include "RTE_DEM.h"
#include "RTE_WDG.h"

/*----------------------------------------------------------------------------*/
/* function prototype declarations                                            */
/*----------------------------------------------------------------------------*/

extern FUNC(void, RTE_CODE_EcucPartition_0) Rte_EV_ComReceive(VAR(void, AUTOMATIC));
#define Rte_EV_ComReceive Rte_EV_ComReceive

extern FUNC(Std_ReturnType, RTE_CODE_EcucPartition_0) Rte_EV_Main(VAR(void, AUTOMATIC));
#define Rte_EV_Main Rte_EV_Main

extern FUNC(void, RTE_CODE_EcucPartition_0) Rte_EV_Component(VAR(void, AUTOMATIC));
#define Rte_EV_Component Rte_EV_Component

extern FUNC(void, RTE_CODE_EcucPartition_0) Rte_EV_GetError(VAR(void, AUTOMATIC));
#define Rte_EV_GetError Rte_EV_GetError

#endif /* RTE_H */
/* End of RTE.h */