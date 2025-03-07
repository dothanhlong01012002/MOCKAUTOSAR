/******************************************************************************/  
/* Copyright   : FPT Software Corporation                                     */  
/* System Name : AUTOSAR Application Layer                                    */  
/* File Name   : NVBlockSWC.c                                                 */  
/* Contents    : Ecu Configuration(Ecuc)                                      */  
/* Author      : DN24_FR_AUTOSAR_02_TRUNG_LONG_NINH                           */  
/* Note        :                                                              */  
/******************************************************************************/  

/*----------------------------------------------------------------------------*/
/* include headers                                                            */
/*----------------------------------------------------------------------------*/

#include "NVBlockSWC.h"

/*----------------------------------------------------------------------------*/
/* functions and function style macros                                        */
/*----------------------------------------------------------------------------*/

/******************************************************************************/  
/* ModuleID    :                                                              */  
/* ServiceID   :                                                              */  
/* Name        : HandleNVM_Runnable                                           */  
/* Param       : requestID - Identifier for the NVM operation request         */  
/* Return      : Std_ReturnType                                               */  
/*               - E_OK     : NVM operation successful                        */  
/*               - E_NOT_OK : Invalid request ID or operation failure         */  
/* Contents    : Handles NVM read and write operations based on the requestID */  
/*               for different data blocks.                                   */  
/* Author      : DN24_FR_AUTOSAR_02_TRUNG_LONG_NINH                           */  
/* Note        :                                                              */  
/******************************************************************************/ 
FUNC(Std_ReturnType,AUTOMATIC) HandleNVM_Runable(VAR(uint8,AUTOMATIC) requestID){
    if(requestID == 0){
        return NvM_WriteBlock(1,Data.parameterData);
    }else if(requestID == 1){
        return NvM_ReadBlock(1,Data.parameterData);
    }else if(requestID == 2){
        return NvM_WriteBlock(2,Data.errorCodes);
    }else if(requestID == 3){
        return NvM_ReadBlock(2,Data.errorCodes);
    }

    return E_NOT_OK;
}

/* End of NVBlockSWC.c */
