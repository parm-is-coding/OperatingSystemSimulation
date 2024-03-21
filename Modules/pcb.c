
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
    char* state;
    switch (pPCB->state)
    {
    case Ready:
        state = "Ready";
        break;
    case Running:
        state = "Running";
        break;
    case Blocked:
        state = "Blocked";
        break;
    case WaitingReceiver:
        state = "WaitingReceiver";
        break;
    case WaitingSender:
        state = "WaitingSender";
        break;
    default:
        printf("ERROR THIS IN pcb_printInfo");
        exit(1);
        break;
    }
    printf("\nProcessID: %d\nTime to execute: %d\nState: %s\nPriority: %d\nMessages: %s\n\n",pPCB->PID,pPCB->time,state,pPCB->priority,pPCB->messages);    
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