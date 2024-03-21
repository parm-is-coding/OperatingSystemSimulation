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
void Create(){
    printf("Create command executed\n");
}
void Fork(){
    printf("Fork command executed\n");
}

void Kill(OperatingSystem* pKernal){
    printf(" command executed\n");
}
void Exit(OperatingSystem* pKernal){
    printf("Exit command executed\n");
}
void Quantum(){
    printf("Quantum command executed\n");
}
//Get PID from user
//Maybe from PID error checking
//find the process with the same pid as the user requested
//print all the info
void Proc_Info(OperatingSystem* pKernal){
    printf("ProcessInfo command executed\n");
    //printf("Enter Valid Process ID:\n");
    //int PID;
    //ProcessControlBlock* pPCB = List_search(); 
    pcb_printInfo(&pKernal->initProcess);
    
}
void Total_Info(){
    printf("TotalInfo command executed\n");
}