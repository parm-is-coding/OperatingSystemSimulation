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


void operatingSystem_Constructor(OperatingSystem* pOperatingSystem){
    //initialize initProcess
    pOperatingSystem->initProcess.PID = 0;
    pOperatingSystem->initProcess.priority = initPri;
    pOperatingSystem->initProcess.state = Running;
    pOperatingSystem->initProcess.messages;
    pOperatingSystem->initProcess.time = 0; //not sure if we need this
    pOperatingSystem->initProcessIsAlive = true;
    //initialize the first running Process as initProcess
    pOperatingSystem->runningProcess = &pOperatingSystem->initProcess;
    pOperatingSystem->allProcesses = List_create();
    pOperatingSystem->waitingReply = List_create();
    pOperatingSystem->WaitingSend = List_create();
    pOperatingSystem->readyQueues[0] = List_create();
    pOperatingSystem->readyQueues[1] = List_create();
    pOperatingSystem->readyQueues[2] = List_create();
    pOperatingSystem->numCycles = 0;
    //Probably Change this when doing IPC
    
}
    static void freefn(void* pItem){
        ProcessControlBlock* pPCB = pItem;
        free(pPCB);
    }
//define Freefn, free all the Lists in Kernal
//test to see if that fixed ProcInfo
void operatingSystem_Destructor(OperatingSystem* pKernal){
    List_free(pKernal->waitingReply,freefn);
    List_free(pKernal->WaitingSend,freefn);
    List_free(pKernal->readyQueues[0],freefn);
    List_free(pKernal->readyQueues[1],freefn);
    List_free(pKernal->readyQueues[2],freefn);
    List_free(pKernal->waitingReply,freefn);
    free(pKernal);
}



    
ProcessControlBlock* operatingSystem_findPID(OperatingSystem* pKernal,int PID){
    List_first(pKernal->allProcesses);
    ProcessControlBlock* pPCB = List_search(pKernal->allProcesses,helper_cmpfunc,&PID);
    List_first(pKernal->allProcesses);
    return pPCB;
}
void operatingSystem_runCommand(char command,OperatingSystem* pKernal) {
    switch (command){
        case 'C':
            Create(pKernal);
            break;
        case 'F':
            Fork(pKernal);
            break;
        case 'K':
            Kill(pKernal);
            break;
        case 'E':
            Exit(pKernal);
            break;
        case 'Q':
            Quantum(pKernal);
            break;
        case 'S':
            Send(pKernal);
            break;
        case 'R':
            Receive(pKernal);
            break;
        case 'Y':
            Reply(pKernal);
            break;
        case 'N':
            New_Sem(pKernal);
            break;
        case 'P':
            Sem_P(pKernal);
            break;
        case 'V':
            Sem_V(pKernal);
            break;
        case 'I':
            Proc_Info(pKernal);
            break;
        case 'T':
            Total_Info(pKernal);
            break;
        default: //invalid command
            printf("comand not recognized, please try again\n");
    }
}