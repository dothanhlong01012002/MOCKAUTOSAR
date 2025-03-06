/******************************************************************************/  
/* Copyright   : FPT Software Corporation                                     */  
/* System Name : AUTOSAR Application Layer                                    */  
/* File Name   : ComM.c                                                       */  
/* Contents    : Ecu Configuration(Ecuc)                                      */  
/* Author      : DN24_FR_AUTOSAR_02_TRUNG_LONG_NINH                           */  
/* Note        :                                                              */  
/******************************************************************************/ 

/*----------------------------------------------------------------------------*/
/* include headers                                                            */
/*----------------------------------------------------------------------------*/

#include "ComM.h"

#define DATA_PDU_ID 0x100

/*----------------------------------------------------------------------------*/
/* function prototype declarations                                            */
/*----------------------------------------------------------------------------*/

/******************************************************************************/  
/* ModuleID    :                                                              */  
/* ServiceID   :                                                              */  
/* Name        : ComM_RequestComMode                                          */  
/* Param       : User - Handle for the user requesting the communication mode */  
/*               ComMode - Desired communication mode                         */  
/* Return      : Std_ReturnType                                               */  
/*               - E_OK     : Request for communication mode successful       */  
/*               - E_NOT_OK : Request for communication mode failed           */  
/* Contents    : Handles the request to set the communication mode for the    */  
/*               specified user.                                              */  
/* Author      : DN24_FR_AUTOSAR_02_TRUNG_LONG_NINH                           */  
/* Note        : Function currently returns a successful status without       */  
/*               implementing actual mode change logic.                       */  
/******************************************************************************/  
FUNC(Std_ReturnType,AUTOMATIC) ComM_RequestComMode(VAR(ComM_UserHandleType,AUTOMATIC) User,VAR(ComM_ModeType,AUTOMATIC) ComMode) {
    (void)User; (void)ComMode;
		return E_OK;
}

/* End of ComM.c */