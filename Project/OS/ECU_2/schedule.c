#include "os.h"
#include "RTE.h"
#include "counter.h"

DeclareTask(ComReceive_Task);
DeclareTask(Main_Task);
DeclareTask(Component_Task);
DeclareTask(Actuator_Task);
DeclareTask(GetError_Task);
bool ErrorFlag = TRUE;
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

TASK(Main_Task)
{ 
   while(true)
   {
      WaitEvent(BE_Receive);
			if(Rte_EV_Main()!= E_NOT_OK){
				SetEvent(Component_Task, BE_Signal);
				SystickCounter = 0;
			}else {
				ErrorFlag = FALSE;
				if(SystickCounter > 99){
					WdgM_CheckpointReached(1,1);
					Rte_Call_RP_WdgM_PerformReset();
					ErrorFlag = TRUE;
				}
			}
      ClearEvent(BE_Receive); 
   }
}

TASK(ComReceive_Task)
{		
		SetEvent(Main_Task, BE_Receive);
		if(ErrorFlag == TRUE)
		{
			Rte_EV_ComReceive(); 
		}
    TerminateTask(); 
}

