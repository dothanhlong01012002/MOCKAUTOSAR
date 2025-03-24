#include "os.h"
#include "RTE.h"
#include "counter.h"

DeclareTask(ComReceive_Task);
DeclareTask(Main_Task);
DeclareTask(Component_Task);
bool ErrorFlag = TRUE;
int GetError_Runable = 0;
int toggle_ComReceive_Task = 0;
int toggle_Component_Task= 0;
int toggle_Main_Task=0;

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
			toggle_Component_Task = 1;
			Rte_EV_Component();
			toggle_Component_Task = 0;
      ClearEvent(BE_Signal); 
   }
}

TASK(Main_Task)
{ 
   while(true)
   {
      WaitEvent(BE_Receive);
			toggle_Main_Task = 1;
			if(Rte_EV_Main()!= E_NOT_OK){
				SetEvent(Component_Task, BE_Signal);
				SystickCounter = 0;
			}else {
				ErrorFlag = FALSE;
				Rte_Call_RP_WdgM_CheckpointReached(SEID_SENSOR_ERROR,CHECKPOINT_SENSOR_READ);
				if(SystickCounter > 99){
					Rte_Call_RP_WdgM_PerformReset();
					ErrorFlag = TRUE;
				}
			}
			toggle_Main_Task = 0;
      ClearEvent(BE_Receive); 
   }
}

TASK(ComReceive_Task)
{		
		toggle_ComReceive_Task=1;
		SetEvent(Main_Task, BE_Receive);
		if(ErrorFlag == TRUE)
		{
			Rte_EV_ComReceive(); 
		}
		toggle_ComReceive_Task=0;
    TerminateTask(); 
}

