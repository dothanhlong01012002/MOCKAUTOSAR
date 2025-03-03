#include "os.h"
#include "RTE.h"
#include "Compiler.h"
DeclareTask(DataHandle_Task);
DeclareTask(ReadSensor_Task);

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
			Rte_EV_DataHandle();
      ClearEvent(BE_ReadSensor); 
   }
}

TASK(ReadSensor_Task)
{
		Rte_EV_ReadSensor();
    SetEvent(DataHandle_Task, BE_ReadSensor); 
    TerminateTask(); 
}