/******************************************************************************/  
/* Copyright   : FPT Software Corporation                                     */  
/* System Name : AUTOSAR Application Layer                                    */  
/* File Name   : IOHwAbCan.h                                                  */  
/* Contents    : Ecu Configuration(Ecuc)                                      */  
/* Author      : DN24_FR_AUTOSAR_02_TRUNG_LONG_NINH                           */  
/* Note        :                                                              */  
/******************************************************************************/ 

/*----------------------------------------------------------------------------*/
/* include headers                                                            */
/*----------------------------------------------------------------------------*/

#ifndef IOHWABCANTX_H
#define IOHWABCANTX_H
#include "Can.h"
#include "Std_Types.h"
#include "Compiler.h"

#define CAN_ID 0x100
#define CANIF_MAX_PDU_ID 30
#define HW_TYPE          0
/*----------------------------------------------------------------------------*/
/* struct prototype declarations                                              */
/*----------------------------------------------------------------------------*/

typedef struct
{
    VAR(uint8,AUTOMATIC) SduLength;
    P2VAR(uint8,AUTOMATIC,AUTOMATIC) SduDataPtr;
} PduInfoType;

/*----------------------------------------------------------------------------*/
/* function prototype declarations                                            */
/*----------------------------------------------------------------------------*/

/******************************************************************************/  
/* ModuleID    :                                                              */  
/* ServiceID   :                                                              */  
/* Name        : CanIf_Transmit                                               */  
/* Param       : TxPduId - Identifier of the PDU to be transmitted            */  
/*               PduInfoPtr - Pointer to PDU data and length information      */  
/* Return      : Std_ReturnType                                               */  
/*               - E_OK     : Transmission request successful                 */  
/*               - E_NOT_OK : Transmission request failed                     */  
/* Contents    : Transmits a CAN message via the CAN Interface (CanIf).       */  
/*               Maps PDU data to Can_PduType and calls Can_Write().          */  
/* Author      : DN24_FR_AUTOSAR_02_TRUNG_LONG_NINH                           */  
/* Note        : Function interacts with the CAN driver layer.                */  
/******************************************************************************/ 
FUNC(Std_ReturnType,AUTOMATIC) CanIf_Transmit(VAR(PduIdType,AUTOMATIC) TxPduId,P2CONST(PduInfoType,AUTOMATIC,AUTOMATIC) PduInfoPtr);

#endif /* IOHWABCAN_H */
/* End of IOHwAbCan.h */