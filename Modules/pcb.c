
#include "../HeaderFiles/baseFunctions.h"
#include "../HeaderFiles/ipc.h"
#include "../HeaderFiles/list.h"
#include "../HeaderFiles/operatingSystem.h"
#include "../HeaderFiles/pcb.h"
#include "../HeaderFiles/scheduler.h"
#include "../HeaderFiles/semaphore.h"
#include <stdio.h>
#include <stdbool.h>
void pcb_Constructor();

void pcb_printInfo(ProcessControlBlock* pPCB){
    printf("ProcessID: %d\nTime to execute: %d\nState: %d\nPriority: %d\nMessages: %s\n",pPCB->PID,pPCB->time,pPCB->state,pPCB->priority,pPCB->messages);    
}