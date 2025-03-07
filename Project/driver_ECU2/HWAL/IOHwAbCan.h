/******************************************************************************/  
/* Copyright   : FPT Software Corporation                                     */  
/* System Name : AUTOSAR Application Layer                                    */  
/* File Name   : IOHwAbCan.c                                                  */  
/* Contents    : Ecu Configuration(Ecuc)                                      */  
/* Author      : DN24_FR_AUTOSAR_02_TRUNG_LONG_NINH                           */  
/* Note        :                                                              */  
/******************************************************************************/  

#ifndef IOHWABCAN_H
#define IOHWABCAN_H

/*----------------------------------------------------------------------------*/
/* include headers                                                            */
/*----------------------------------------------------------------------------*/

#include "Can.h"
#include "Std_Types.h"
#include "Compiler.h"

#define CAN_ID 0x100

extern P2VAR(uint8,AUTOMATIC,AUTOMATIC) CanRxBuffer;
extern VAR(uint8,AUTOMATIC) CanRxLength;
extern VAR(uint8,AUTOMATIC) status;

typedef enum {
    CANIF_NO_NOTIFICATION,
    CANIF_TX_RX_NOTIFICATION
}CanIf_NotifStatusType;

/*----------------------------------------------------------------------------*/
/* struct prototype declarations                                              */
/*----------------------------------------------------------------------------*/

typedef struct {
    Can_IdType CanId;
    Can_HwHandleType Hoh;
    VAR(uint8,AUTOMATIC) ControllerId;
} Can_HwType;

typedef struct
{
    VAR(uint8,AUTOMATIC) SduLength;
    P2VAR(uint8,AUTOMATIC,AUTOMATIC) SduDataPtr;
} PduInfoType;

/*----------------------------------------------------------------------------*/
/* function prototype declarations                                            */
/*----------------------------------------------------------------------------*/

FUNC(Std_ReturnType,AUTOMATIC) CanIf_ReadRxPduData(VAR(PduIdType,AUTOMATIC) CanIfRxSduId,P2VAR(PduInfoType,AUTOMATIC,AUTOMATIC) CanIfRxInfoPtr);
FUNC(void,AUTOMATIC) CanIf_RxIndication(P2CONST(Can_HwType,AUTOMATIC,AUTOMATIC) Mailbox,P2CONST(PduInfoType,AUTOMATIC,AUTOMATIC) PduInfoPtr);
FUNC(CanIf_NotifStatusType,AUTOMATIC) CanIf_ReadRxNotifStatus(VAR(PduIdType,AUTOMATIC) CanIfRxSduId);

#endif /* IOHWABCAN_H */
/* End of IOHwAbCan.h */