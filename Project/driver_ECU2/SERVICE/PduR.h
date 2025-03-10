/******************************************************************************/  
/* Copyright   : FPT Software Corporation                                     */  
/* System Name : AUTOSAR Application Layer                                    */  
/* File Name   : PduR.h                                                       */  
/* Contents    : Ecu Configuration(Ecuc)                                      */  
/* Author      : DN24_FR_AUTOSAR_02_TRUNG_LONG_NINH                           */  
/* Note        :                                                              */  
/******************************************************************************/  

#ifndef PDUR_H
#define PDUR_H

/*----------------------------------------------------------------------------*/
/* include headers                                                            */
/*----------------------------------------------------------------------------*/

#include "Std_Types.h"
#include "IOHwAbCan.h"
#include "Com.h"
#include "Compiler.h"

/*----------------------------------------------------------------------------*/
/* functions and function style macros                                        */
/*----------------------------------------------------------------------------*/

FUNC(void,AUTOMATIC) PduR_LoIfRxIndication(VAR(PduIdType,AUTOMATIC) RxPduId, P2CONST(PduInfoType,AUTOMATIC,AUTOMATIC) PduInfoPtr);

#endif /* PDUR_H */
/* End of PduR.h */