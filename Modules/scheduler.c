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
#include <stdlib.h>

void scheduler_runRunningProcess(OperatingSystem* pKernal){
    ProcessControlBlock* pPCB = pKernal->runningProcess;
    if(pPCB->PID == pKernal->initProcess.PID){
        printf("\nPID: %d Running InitProcess Cycle: %d\n",pPCB->PID,pKernal->numCycles);
    }else{
        pPCB->time -= 50;
        printf("PID: %d Running %d Time Remaining Cycle: %d\n",pPCB->PID,pPCB->time,pKernal->numCycles);
    }
    pKernal->numCycles++;
}

     
//check to see if the running process is init or has time value of 0 or needs to be rescheduled on appropriate queue 
void scheduler_returnRunningToReady(OperatingSystem* pKernal){
    pKernal->runningProcess->state = Ready;
    if(pKernal->runningProcess->priority == initPri){
        //do nothing
    }else if(pKernal->runningProcess->time == 0){
        //we need to remove a completed process
        helper_removeFromAllProcesses(pKernal->allProcesses,pKernal->runningProcess->PID);
        pKernal->runningProcess = NULL;
    }else{
        //reschedule the running process on the appropriate ready queue
        
        List_prepend(pKernal->readyQueues[pKernal->runningProcess->priority],pKernal->runningProcess);    
    }
        // set running process to nullptr
        pKernal->runningProcess = NULL;
}

    static bool allReadyQueuesAreEmpty(OperatingSystem* pKernal){
        if(pKernal->readyQueues[0]->count == 0 & pKernal->readyQueues[1]->count == 0 & pKernal->readyQueues[2]->count == 0 ){
            return true;
        }else{
            return false;
        }
    }
     
    static void schedule(OperatingSystem*pKernal,int priority){
        if(allReadyQueuesAreEmpty(pKernal)){
            printf("Error in scheduler picking next processes but all readyqueues are empty!");
            exit(1);
        }
        //the ready queue has an item
        if(pKernal->readyQueues[priority]->count == 0){
            schedule(pKernal,(priority+1)%3);
        }else{
            pKernal->runningProcess = (ProcessControlBlock*)List_trim(pKernal->readyQueues[priority]);
            pKernal->runningProcess->state = Running; 
        }
    }
//pops a ready process from the appropriate ready queue 
// if non set the running process as init process
void scheduler_pickNextRunningProcess(OperatingSystem* pKernal){
    if(allReadyQueuesAreEmpty(pKernal)){
        pKernal->runningProcess = &pKernal->initProcess;
        pKernal->initProcess.state = Running;
    }else{
        if(pKernal->numCycles % 3 == 0){
            schedule(pKernal,Medium);
        }else if(pKernal->numCycles % 7 == 0){
            schedule(pKernal,Low);
        }else{
            schedule(pKernal,High);
        }
    }
    if(pKernal->initProcessIsAlive){
        printf("Next running Process will be PID:%d\n\n",pKernal->runningProcess->PID);
    }
}
