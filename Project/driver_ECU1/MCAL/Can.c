/******************************************************************************/  
/* Copyright   : FPT Software Corporation                                     */  
/* System Name : AUTOSAR Application Layer                                    */  
/* File Name   : Can.c                                                        */  
/* Contents    : Ecu Configuration(Ecuc)                                      */  
/* Author      : DN24_FR_AUTOSAR_02_TRUNG_LONG_NINH                           */  
/* Note        :                                                              */  
/******************************************************************************/ 

/*----------------------------------------------------------------------------*/
/* include headers                                                            */
/*----------------------------------------------------------------------------*/
#include "Can.h"
VAR(uint8,AUTOMATIC) dataFrame[3];
/*----------------------------------------------------------------------------*/
/* functions and function style macros                                        */
/*----------------------------------------------------------------------------*/

/******************************************************************************/  
/* ModuleID    :                                                              */  
/* ServiceID   :                                                              */  
/* Name        : Can_Write                                                    */  
/* Param       : Hth     - Hardware transmit handle                           */  
/*               PduInfo - Pointer to the CAN PDU containing ID, length, and  */  
/*                         data for transmission                              */  
/* Return      : Std_ReturnType                                               */  
/*               - E_OK     : Transmission request successful                 */  
/*               - E_NOT_OK : Transmission request failed                     */  
/* Contents    : Sends a CAN message using the provided hardware transmit     */  
/*               handle and PDU information.                                  */  
/* Author      : DN24_FR_AUTOSAR_02_TRUNG_LONG_NINH                           */  
/* Note        : This is a stub function, actual transmission is not handled. */  
/******************************************************************************/  
FUNC(Std_ReturnType,AUTOMATIC) Can_Write(VAR(Can_HwHandleType,AUTOMATIC) Hth,P2CONST(Can_PduType,AUTOMATIC,AUTOMATIC) PduInfo) {
  dataFrame[0] = *(PduInfo->sdu);
  dataFrame[1] = *(PduInfo->sdu + 1);
  dataFrame[2] = *(PduInfo->sdu + 2);
      if (PduInfo == NULL || PduInfo->sdu == NULL) {
        return E_NOT_OK;
    }

    if (PduInfo->length == 0) {
        return E_NOT_OK;
    }

    if (!Hth) {
      return E_NOT_OK;
    }
    
		return E_OK;
}

/* End of Can.c */