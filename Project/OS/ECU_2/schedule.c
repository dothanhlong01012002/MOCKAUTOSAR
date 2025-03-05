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
	Rte_Call_RP_WdgM_Init(&wdgConfig);
  StartOS();
  while(1); /* Should not be executed */
  return 0;
}

TASK(Component_Task){
	while(true)
   {
      WaitEvent(BE_Signal); 
			Rte_EV_Component();
      ClearEvent(BE_Signal); 
   }
}

TASK(GetError_Task){
	Rte_EV_GetError();
	TerminateTask();
}

TASK(Main_Task)
{ 
   while(true)
   {
      WaitEvent(BE_Receive);
			if(Rte_EV_Main()!=E_NOT_OK){
				SetEvent(Component_Task, BE_Signal);
			}else {
				ErrorFlag = false;
				Rte_Call_RP_WdgM_PerformReset();
			}
      ClearEvent(BE_Receive); 
   }
}

TASK(ComReceive_Task)
{		
		if(ErrorFlag ==true)
		{
			Rte_EV_ComReceive();
			SetEvent(Main_Task, BE_Receive); 
		}
    TerminateTask(); 
}

