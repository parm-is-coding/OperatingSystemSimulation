#include "../HeaderFiles/baseFunctions.h"
#include "../HeaderFiles/ipc.h"
#include "../HeaderFiles/list.h"
#include "../HeaderFiles/operatingSystem.h"
#include "../HeaderFiles/pcb.h"
#include "../HeaderFiles/scheduler.h"
#include "../HeaderFiles/semaphore.h"
#include <stdio.h>
#include <stdbool.h>

void scheduler_runRunningProcess(OperatingSystem* pKernal){
    ProcessControlBlock* pPCB = pKernal->runningProcess;
    if(pPCB->PID == pKernal->initProcess.PID){
        printf("\nPID: %d Running InitProcess\n\n",pPCB->PID);
    }else{
        pPCB->time -= 50;
        printf("PID: %d Running %d Time Remaining\n",pPCB->PID,pPCB->time);
    }
}
void scheduler_returnRunningToReady(OperatingSystem* pKernal){

}
void scheduler_pickNextRunningProcess(OperatingSystem* pKernal){

}
