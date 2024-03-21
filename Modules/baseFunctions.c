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
void Create(OperatingSystem* pKernal){
    printf("Create command executed\n");
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
    printf("Enter Valid Process ID:\n");
    int PID = 0;
    ProcessControlBlock* pPCB;
    if(PID == 0){
        pPCB = &(pKernal->initProcess);
    }else{
        pPCB = operatingSystem_findPID(pKernal,PID);
    }
    if(pPCB == NULL){
        printf("Failure: InvalidPID\n");
    }else{
        pcb_printInfo(pPCB);
    } 
    
}
void Total_Info(OperatingSystem* pKernal){
    printf("TotalInfo command executed\n");
}