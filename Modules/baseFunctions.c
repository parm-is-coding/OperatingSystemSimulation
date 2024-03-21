#include "../HeaderFiles/baseFunctions.h"
#include "../HeaderFiles/ipc.h"
#include "../HeaderFiles/list.h"
#include "../HeaderFiles/operatingSystem.h"
#include "../HeaderFiles/pcb.h"
#include "../HeaderFiles/scheduler.h"
#include "../HeaderFiles/semaphore.h"
#include "../HeaderFiles/helper.h"
#include <stdio.h>
#include <stdbool.h>

//created processes must be dynamically allocated PCBs
//Prompt User for Priority
//Validates input to be  0 1 or 2
//Fail on input
//Dynamically allocate space for a PCB
//Construct the PCB with values
//Append the PCB on all processes
//prepend the PCB on the appropriate readyqueue 
void Create(OperatingSystem* pKernal){
    printf("Create command executed\n");
    //get userinput

    int priority;
    printf("Enter priority level 0 1 2 for new Process:");
    scanf("%d",&priority);
    helper_clearStdinBuffer();
    if(priority == 0 ||priority == 1 ||priority == 2){
        ProcessControlBlock* pPCB = malloc(sizeof(ProcessControlBlock));
        pcb_Constructor(pPCB,priority);
        List_append(pKernal->allProcesses,pPCB);
        List_prepend(pKernal->readyQueues[pPCB->priority],pPCB);
        printf("Success: new ProcessID: %d\n",pPCB->PID);
    }else{
        printf("Failure: Invalid Priority\n");
    }
}
void Fork(OperatingSystem* pKernal){
    printf("Fork command executed\n");
}

void Kill(OperatingSystem* pKernal){
    printf(" command executed\n");
}
void Exit(OperatingSystem* pKernal){
    printf("Exit command executed\n");
}
void Quantum(OperatingSystem* pKernal){
    printf("Quantum command executed\n");
}

//Get PID from user NEED TO DO
//Maybe from PID error checking
//find the process with the same pid as the user requested
//print all the info
//NOT TESTED FOR CREATED PROCESS 
//WAITING FOR CREATE TO BE IMPLEMENTED
void Proc_Info(OperatingSystem* pKernal){
    printf("ProcessInfo command executed\n");
    printf("Enter Valid Process ID:");
    int PID;
    scanf("%d",&PID);
    helper_clearStdinBuffer();
    ProcessControlBlock* pPCB;
    if(PID == 0){
        pPCB = &(pKernal->initProcess);
    }else{
        pPCB = operatingSystem_findPID(pKernal, PID);
    }
    if(pPCB == NULL){
        printf("Failure: InvalidPID: %d\n",PID);
    }else{
        pcb_printInfo(pPCB);
    } 
    
}
//Iterate over all processes starting with init Process
//callprint info on each node
void Total_Info(OperatingSystem* pKernal){
    printf("TotalInfo command executed\n");
    pcb_printInfo(&pKernal->initProcess);
    List_first(pKernal->allProcesses);
    pKernal->allProcesses->lastOutOfBoundsReason = LIST_OOB_START;
    while(pKernal->allProcesses->pCurrentNode != NULL){
        pcb_printInfo((ProcessControlBlock*)pKernal->allProcesses->pCurrentNode->pItem);
        List_next(pKernal->allProcesses);
    }
    List_first(pKernal->allProcesses);
}