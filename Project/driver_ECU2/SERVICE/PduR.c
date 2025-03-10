/******************************************************************************/  
/* Copyright   : FPT Software Corporation                                     */  
/* System Name : AUTOSAR Application Layer                                    */  
/* File Name   : PduR.c                                                       */  
/* Contents    : Ecu Configuration(Ecuc)                                      */  
/* Author      : DN24_FR_AUTOSAR_02_TRUNG_LONG_NINH                           */  
/* Note        :                                                              */  
/******************************************************************************/  

/*----------------------------------------------------------------------------*/
/* include headers                                                            */
/*----------------------------------------------------------------------------*/

#include "PduR.h"

#define PDUR_MAX_PDU_ID 30

/*----------------------------------------------------------------------------*/
/* functions and function style macros                                        */
/*----------------------------------------------------------------------------*/

/******************************************************************************/  
/* ModuleID    :                                                              */  
/* ServiceID   :                                                              */  
/* Name        : PduR_LoIfRxIndication                                        */  
/* Param       : RxPduId - ID of the received PDU                             */  
/*               PduInfoPtr - Pointer to the PDU information                  */  
/* Return      : void                                                         */  
/* Contents    : Validates the PDU ID and calls `Com_RxIndication` if valid.  */  
/* Author      : DN24_FR_AUTOSAR_02_TRUNG_LONG_NINH                           */  
/* Note        :                                                              */  
/******************************************************************************/ 
FUNC(void,AUTOMATIC) PduR_LoIfRxIndication(VAR(PduIdType,AUTOMATIC) RxPduId, P2CONST(PduInfoType,AUTOMATIC,AUTOMATIC) PduInfoPtr) {
    if (PduInfoPtr == NULL) {
        return; // Bảo vệ chống lỗi NULL Pointer
    }

    // Kiểm tra PDU ID hợp lệ
    if (RxPduId >= PDUR_MAX_PDU_ID) {
        return;
    }
    Com_RxIndication(RxPduId, PduInfoPtr);
}

/* End of PduR.c */