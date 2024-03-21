
#include "../HeaderFiles/baseFunctions.h"
#include "../HeaderFiles/ipc.h"
#include "../HeaderFiles/list.h"
#include "../HeaderFiles/operatingSystem.h"
#include "../HeaderFiles/pcb.h"
#include "../HeaderFiles/scheduler.h"
#include "../HeaderFiles/semaphore.h"
#include <stdio.h>
#include <stdbool.h>
static int nextPID = 1;
void pcb_Constructor();

void pcb_printInfo(ProcessControlBlock* pPCB){
    printf("ProcessID: %d\nTime to execute: %d\nState: %d\nPriority: %d\nMessages: %s\n",pPCB->PID,pPCB->time,pPCB->state,pPCB->priority,pPCB->messages);    
}

void pcb_Constructor(ProcessControlBlock* pPCB,int priority){
    pPCB->PID = nextPID++;
    pPCB->messages = "";
    pPCB->priority = priority;
    pPCB->time = 100;
    pPCB->state = Ready;
}
void pcb_Destructor(ProcessControlBlock* pPCB){
    free(pPCB);
}