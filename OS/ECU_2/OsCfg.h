/*******************************************************************************
	Module Name:		OsCfg.h
	Generation Date:	2025-March-Monday	15:35:38
	Tool Version: 		V.0
	Description: 		Os configuration header file


	All Rights Reserved - Sarea Alhariri
*******************************************************************************/

/******************************************************************************/
/*******************AUTO GENERATED FILE PLEASE DO NOT TOUCH********************/
/******************************************************************************/

#ifndef OS_CFG_H_
#define OS_CFG_H_
 
#include "OsTypes.h"

/*******************************************************************************
	Extern number of App Tasks
*******************************************************************************/
extern const uint8_t OsCfg_MAX_NUM_OF_TASKS;
/*******************************************************************************
	Define the number of alarms
*******************************************************************************/
extern const uint8_t OsCfg_MAX_NUM_OF_ALARMS;
/*******************************************************************************
	Define the number of resources
*******************************************************************************/
extern const uint8_t OsCfg_MAX_NUM_OF_RESOURCES; 
/*******************************************************************************
	OsCfg_ALL_STACK_SIZE
*******************************************************************************/
extern const uint16_t OsCfg_ALL_STACK_SIZE;
/*******************************************************************************
	Hook routines configurations
*******************************************************************************/
extern const uint8_t OsCfg_USE_ERROR_HOOK;
extern const uint8_t OsCfg_USE_PRETASK_HOOK;
extern const uint8_t OsCfg_USE_POSTTASK_HOOK;
extern const uint8_t OsCfg_USE_STARTUP_HOOK;
extern const uint8_t OsCfg_USE_STACK_OVER_FLOW_HOOK;


extern const uint8_t OsCfg_USE_PARAMETER_ACCESS;
extern const uint8_t OsCfg_USE_GET_SERVICE_ID;
extern const uint32_t OsCfg_SYSTEM_TICK_IN_MS;
extern const uint32_t OSTICKDURATION;
/*******************************************************************************
	System task functions prototypes
*******************************************************************************/
extern void OsTask_WriteError_Task(void); 
extern void OsTask_GetError_Task(void); 
extern void OsTask_Actuator_Task(void); 
extern void OsTask_Component_Task(void); 
extern void OsTask_Main_Task(void); 
extern void OsTask_ComReceive_Task(void); 
extern void OsTask_IdleMechanism(void); 
/*******************************************************************************
	Task Identifiers
*******************************************************************************/
enum OsCfg_TaskIDs
{
	WriteError_Task,
	GetError_Task,
	Actuator_Task,
	Component_Task,
	Main_Task,
	ComReceive_Task
};
/*******************************************************************************
	Symbolic names for wait events for each thread
*******************************************************************************/
/*WriteError_TaskEvents*/
#define BE_Error		1
/*GetError_TaskEvents*/
/*Actuator_TaskEvents*/
#define BE_ControlActuator		1
/*Component_TaskEvents*/
#define BE_Signal		1
/*Main_TaskEvents*/
#define BE_Receive		1
/*ComReceive_TaskEvents*/

/*******************************************************************************
	Task Control Blocks Table
*******************************************************************************/
extern tcb_t OsCfg_TCBs[6+1/*for Idle mechanism */]; 

/*******************************************************************************
	Alarm control blocks table
*******************************************************************************/
extern acb_t OsCfg_Alarms[2/*OsCfg_MAX_NUM_OF_ALARMS*/];

/*******************************************************************************
	Stack size for each thread
*******************************************************************************/
extern const uint32_t OsCfg_StackSize[6];

/*******************************************************************************
	Stack Buffer For All Threads
*******************************************************************************/
extern uint32_t OsCfg_Stack[300+16/* 16 for Idle mechanism */]; 

/*******************************************************************************
	Rosource task authorization
*******************************************************************************/
extern const uint8_t OsCfg_ResourceTaskAuthorized[1][1]; /*Not used*/
/*******************************************************************************
	Alarms base records to be referenced in alarm configs
*******************************************************************************/
extern AlarmBaseType MainCounter;

/*******************************************************************************
	Symbolic names for alarms
*******************************************************************************/
enum OsCfg_AlarmIDs {
	Alrm_Periodic,
	Alrm_Periodic2
};
/*******************************************************************************
	Alarms CB externs
*******************************************************************************/
/*******************************************************************************
	Ceiling priority for sysytem resources
*******************************************************************************/
extern const uint8_t OsCfg_ResourceCeilPri[1];/*Not used.*/
/*******************************************************************************
	Error code task buffer
*******************************************************************************/
extern StatusType SVCCnxt_ErrCodes[6/*OsCfg_MAX_NUM_OF_TASKS*/];
/*******************************************************************************
	SVC resource context
*******************************************************************************/
extern ResourceType SVCCnxt_ResMgrCnxt[1];/*Not used*/
/*******************************************************************************
	Resource control block table
*******************************************************************************/
extern RCB_t RCB[1];/*Not used*/
#endif
