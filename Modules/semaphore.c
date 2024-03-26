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

void New_Sem(OperatingSystem* pKernal){
    printf("New_Sem command executed\n");
    int id, initVal;
    printf("Enter semaphore id value 0-4 and initial semaphore value\n");
    scanf("%d %d",&id,&initVal);
    helper_clearStdinBuffer();
    if(id < 0 || id > 4){
        printf("Failure: invalid semaphore id\n");
    }else{
        pKernal->semaphors[id] = (Semaphore*)malloc(sizeof(Semaphore));
        printf("Semaphore %d Initialized \n",id);
        pKernal->semaphors[id]->queue = List_create();
    }

    
}
void Sem_P(OperatingSystem* pKernal){
    printf("Sem_P command executed\n");
     printf("Enter Semaphore ID:");
    int id;
    scanf("%d",&id);
    helper_clearStdinBuffer();
    if(0<id || id > 4){
        printf("Failure: invalid Semaphore ID\n");
    }else if(pKernal->semaphors[id] == NULL){
        printf("Failure: uninitialized Semaphore ID\n");
    }else if(pKernal->runningProcess->PID == 0){
        printf("Failure: cannot Block initProcess\n");
    }else{
        pKernal->semaphors[id]->Value--;
        if(pKernal->semaphors[id]->Value < 0){
            printf("PID: %d has been blocked\n",pKernal->runningProcess->PID);
            pKernal->runningProcess->state = Blocked;
            //add running process to semaphore.blockedlist
            List_append(pKernal->semaphors[id]->queue,pKernal->runningProcess); 
            pKernal->runningProcess = NULL;
            scheduler_pickNextRunningProcess(pKernal);
        }else{
            printf("PID: %d proceeded without being blocked\n",pKernal->runningProcess->PID);
        }
    }
}
    static bool noProcessesAreBlocked(OperatingSystem* pKernal, int id){
        List* sem = pKernal->semaphors[id]->queue;
        if (List_count(sem) == 0) {
            return true;
        }
        return false;
    }

void Sem_V(OperatingSystem* pKernal){
    printf("Sem_V command executed\n");
    printf("Enter Semaphore ID:");
    int id;
    scanf("%d",&id);
    helper_clearStdinBuffer();
    if(0>id || id > 4){
        printf("Failure: invalid Semaphore ID\n");
    }else if(pKernal->semaphors[id] == NULL){
        printf("Failure: uninitialized Semaphore ID\n");
    }else if(noProcessesAreBlocked(pKernal, id)){
        printf("Failure: no processes are blocked\n");
    }
    else{
        pKernal->semaphors[id]->Value++;
        if(pKernal->semaphors[id]->Value <=0){
            ProcessControlBlock* pPCB = List_trim(pKernal->semaphors[id]->queue);
            printf("PID: %d Woken up\n",pPCB->PID);
            List_prepend(pKernal->readyQueues[pPCB->priority],pPCB);
        }

    }
}