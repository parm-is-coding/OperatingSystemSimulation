
#include "../HeaderFiles/baseFunctions.h"
#include "../HeaderFiles/ipc.h"
#include "../HeaderFiles/list.h"
#include "../HeaderFiles/operatingSystem.h"
#include "../HeaderFiles/pcb.h"
#include "../HeaderFiles/scheduler.h"
#include "../HeaderFiles/semaphore.h"
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
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
    char* priority;
    switch (pPCB->priority)
    {
    case High:
        priority = "High";
        break;
    case Medium:
        priority = "Medium";
        break;
    case Low:
        priority = "Low";
        break;
    case initPri:
        priority = "Lowest";
        break;
    default:
        printf("ERROR THIS IN pcb_printInfo");
        exit(1);
        break;
    }
    printf("\nProcessID: %d\nState: %s\nPriority: %s\nMessages: %s\n\n",pPCB->PID,state,priority,pPCB->messages);    
}

void pcb_Constructor(ProcessControlBlock* pPCB,int priority){
    pPCB->PID = nextPID++;
    pPCB->priority = priority;
    pPCB->state = Ready;
    pPCB->displayProc = NothingToShow;
    pPCB->sourcePID = 0;
    pPCB->waitingSender = NULL;
}
void pcb_Destructor(ProcessControlBlock* pPCB){
    free(pPCB);
}