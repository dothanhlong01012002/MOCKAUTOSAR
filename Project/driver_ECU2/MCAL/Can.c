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
#include "IOHwAbCan.h"
#include "stdlib.h"

VAR(uint8,AUTOMATIC) frameData[3];
/*----------------------------------------------------------------------------*/
/* functions and function style macros                                        */
/*----------------------------------------------------------------------------*/

/******************************************************************************/  
/* ModuleID    :                                                              */  
/* ServiceID   :                                                              */  
/* Name        : Handle_Can_Interrupt                                         */  
/* Param       : void                                                         */  
/* Return      : void                                                         */  
/* Contents    : Handles the CAN interrupt by populating a frame with data    */  
/*               and forwarding it to the `CanIf_RxIndication` function.      */  
/* Author      : DN24_FR_AUTOSAR_02_TRUNG_LONG_NINH                           */  
/* Note        : Function processes the CAN interrupt and forwards the data   */  
/*               to the appropriate function for further handling.            */  
/******************************************************************************/ 

FUNC(void,AUTOMATIC) Handle_Can_Interrupt(VAR(void,AUTOMATIC)) {
    VAR(Can_HwType,AUTOMATIC) Mailbox;
    Mailbox.Hoh = 10;

    VAR(PduInfoType,AUTOMATIC) PduInfo;
    frameData[0] = rand()%100;
    frameData[1] = rand()%40;
    frameData[2] = rand()%255;
    PduInfo.SduDataPtr = (P2VAR(uint8,AUTOMATIC,AUTOMATIC))frameData;
    PduInfo.SduLength = 3;

    CanIf_RxIndication(&Mailbox,&PduInfo);
}

/* End of Can.c */