#include "os.h"
#include "RTE.h"


DeclareTask(ComReceive_Task);
DeclareTask(Main_Task);
DeclareTask(Component_Task);
DeclareTask(Actuator_Task);
DeclareTask(GetError_Task);
bool ErrorFlag = true;
int GetError_Runable = 0;

void SystemInit(void)
{
}
int main(void)
{
  StartOS();
  while(1); /* Should not be executed */
  return 0;
}
TASK(Component_Task){
	while(true)
   {
      WaitEvent(BE_Signal); 
			Rte_EV_Component();
			SetEvent(Actuator_Task, BE_ControlActuator);
      ClearEvent(BE_Signal); 
   }
}
TASK(Actuator_Task){
	while(true)
   {
      WaitEvent(BE_ControlActuator); 
			Rte_EV_Actuator();
			ClearEvent(BE_ControlActuator);
   }
}
TASK(WriteError_Task){
	while(true)
   {
      WaitEvent(BE_Error); 
			Rte_EV_WriteError();
			ClearEvent(BE_Error);
   }
}
TASK(GetError_Task){
	Rte_EV_GetError();
	SetEvent(WriteError_Task, BE_Error);
	TerminateTask();
}
TASK(Main_Task)
{ 
   while(true)
   {
      WaitEvent(BE_Receive); 
			Rte_EV_Main();
			SetEvent(Component_Task, BE_Signal);
      ClearEvent(BE_Receive); 
   }
}
TASK(ComReceive_Task)
{		
		Rte_EV_ComReceive();
		if(ErrorFlag ==true)
		{
			SetEvent(Main_Task, BE_Receive); 
		}
    TerminateTask(); 
}