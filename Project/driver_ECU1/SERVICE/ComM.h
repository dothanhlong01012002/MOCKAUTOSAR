#ifndef  COMM_H
#define COMM_H

#include <stdint.h>
#include "PduR.h"
#include "Std_Types.h"
#include "RTE.h"
#include "Compiler.h"

typedef uint16_t ComM_UserHandleType;
typedef uint8_t ComM_ModeType;

#define COMM_NO_COMMUNICATION                           0x00    /*Configured channel shall have no transmission or reception capability */
#define COMM_SILENT_COMMUNICATION                       0x01    /*Configured channel shall have only reception capability, no transmission capability.*/
#define COMM_FULL_COMMUNICATION                         0x02    /*Configured channel shall have both transmission and reception capability. */
#define COMM_FULL_COMMUNICATION_WITH_WAKEUP_REQUEST     0x03    /*Configured channel shall have both transmission and reception towards the lower layer (e.g. Ethernet hardware compliant to OA TC10). This is only for internal use within the ComM channel statemachine.*/

FUNC(Std_ReturnType,AUTOMATIC) ComM_RequestComMode(VAR(ComM_UserHandleType,AUTOMATIC) User,VAR(ComM_ModeType,AUTOMATIC) ComMode);

#endif