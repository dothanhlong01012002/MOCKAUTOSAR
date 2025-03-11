#include "os.h"
#include "RTE.h"
#include "Compiler.h"
DeclareTask(DataHandle_Task);
DeclareTask(ReadSensor_Task);
int toggle_ReadSensor_Task = 0;
int toggle_DataHandle_Task = 0;
int a = 0;

void SystemInit(void)
{
}
int main(void)
{
  StartOS();
  while(1); /* Should not be executed */
  return 0;
}

TASK(DataHandle_Task)
{ 
   while(true)
   {
      WaitEvent(BE_ReadSensor);
		  toggle_DataHandle_Task = 1;
			Rte_EV_DataHandle();
      ClearEvent(BE_ReadSensor); 
			toggle_DataHandle_Task = 0;
   }
}

TASK(ReadSensor_Task)
{
		toggle_ReadSensor_Task= 1;
		Rte_EV_ReadSensor();
    SetEvent(DataHandle_Task, BE_ReadSensor); 
		toggle_ReadSensor_Task= 0;
    TerminateTask(); 
}