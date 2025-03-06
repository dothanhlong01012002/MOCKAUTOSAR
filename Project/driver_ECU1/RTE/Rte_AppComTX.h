/******************************************************************************/  
/* Copyright   : FPT Software Corporation                                     */  
/* System Name : AUTOSAR Application Layer                                    */  
/* File Name   : RTE.h                                                        */  
/* Contents    : Ecu Configuration(Ecuc)                                      */  
/* Author      : DN24_FR_AUTOSAR_02_TRUNG_LONG_NINH                           */  
/* Note        :                                                              */  
/******************************************************************************/ 

#ifndef RTE_APPCOMTX_H
#define RTE_APPCOMTX_H

/*----------------------------------------------------------------------------*/
/* include headers                                                            */
/*----------------------------------------------------------------------------*/

#include "Std_Types.h"
#include "Compiler.h"

/*----------------------------------------------------------------------------*/
/* variables                                                                  */
/*----------------------------------------------------------------------------*/

static VAR(uint16,AUTOMATIC) SpeedValue = 0;
static VAR(uint16,AUTOMATIC) TempValue = 0;

/*----------------------------------------------------------------------------*/
/* function prototype declarations                                            */
/*----------------------------------------------------------------------------*/

/******************************************************************************/  
/* ModuleID    :                                                              */  
/* ServiceID   :                                                              */  
/* Name        : Rte_Write_PP_Temperature_TempValue                           */  
/* Param       : temp - Temperature value to be stored                        */  
/* Return      : Std_ReturnType                                               */  
/*               - E_OK     : Write operation successful                      */  
/*               - E_NOT_OK : Write operation failed                          */  
/* Contents    : Stores the received temperature value in TempValue.          */  
/* Author      : DN24_FR_AUTOSAR_02_TRUNG_LONG_NINH                           */  
/* Note        : Function writes processed temperature data for further use.  */  
/******************************************************************************/ 
FUNC(Std_ReturnType,AUTOMATIC) Rte_Write_PP_Temperature_TempValue(VAR(uint16,AUTOMATIC) temp);

/******************************************************************************/  
/* ModuleID    :                                                              */  
/* ServiceID   :                                                              */  
/* Name        : Rte_Read_RP_Temperature_TempValue                            */  
/* Param       : temp - Pointer to store the retrieved temperature value      */  
/* Return      : Std_ReturnType                                               */  
/*               - E_OK     : Read operation successful                       */  
/*               - E_NOT_OK : Read operation failed (NULL pointer)            */  
/* Contents    : Reads the stored temperature value and writes it to temp.    */  
/* Author      : DN24_FR_AUTOSAR_02_TRUNG_LONG_NINH                           */  
/* Note        : Function ensures NULL pointer check before accessing data.   */  
/******************************************************************************/  
FUNC(Std_ReturnType,AUTOMATIC) Rte_Read_RP_Temperature_TempValue(P2VAR(uint16,AUTOMATIC,AUTOMATIC) temp);

/******************************************************************************/  
/* ModuleID    :                                                              */  
/* ServiceID   :                                                              */  
/* Name        : Rte_Read_RP_Speed_SpeedValue                                 */  
/* Param       : temp - Pointer to store the retrieved speed value            */  
/* Return      : Std_ReturnType                                               */  
/*               - E_OK     : Read operation successful                       */  
/*               - E_NOT_OK : Read operation failed (NULL pointer)            */  
/* Contents    : Reads the stored speed value and writes it to temp.          */  
/* Author      : DN24_FR_AUTOSAR_02_TRUNG_LONG_NINH                           */  
/* Note        : Function ensures NULL pointer check before accessing data.   */  
/******************************************************************************/  
FUNC(Std_ReturnType,AUTOMATIC) Rte_Read_RP_Speed_SpeedValue(P2VAR(uint16,AUTOMATIC,AUTOMATIC) temp);

/******************************************************************************/  
/* ModuleID    :                                                              */  
/* ServiceID   :                                                              */  
/* Name        : Rte_Write_PP_Speed_SpeedValue                                */  
/* Param       : temp - Speed value to be stored                              */  
/* Return      : Std_ReturnType                                               */  
/*               - E_OK     : Write operation successful                      */  
/*               - E_NOT_OK : Write operation failed                          */  
/* Contents    : Stores the received speed value in SpeedValue.               */  
/* Author      : DN24_FR_AUTOSAR_02_TRUNG_LONG_NINH                           */  
/* Note        : Function writes speed data for further processing.           */  
/******************************************************************************/  
FUNC(Std_ReturnType,AUTOMATIC) Rte_Write_PP_Speed_SpeedValue(VAR(uint16,AUTOMATIC) temp);

#endif /* RTE_H */
/* End of RTE.h */