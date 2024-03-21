#include "../HeaderFiles/baseFunctions.h"
#include "../HeaderFiles/ipc.h"
#include "../HeaderFiles/list.h"
#include "../HeaderFiles/operatingSystem.h"
#include "../HeaderFiles/pcb.h"
#include "../HeaderFiles/scheduler.h"
#include "../HeaderFiles/semaphore.h"
#include <stdio.h>
#include <stdbool.h>


void operatingSystem_Constructor(OperatingSystem* pOperatingSystem){
    //initialize initProcess
    pOperatingSystem->initProcess.PID = 0;
    pOperatingSystem->initProcess.priority = initPri;
    pOperatingSystem->initProcess.state = Running;
    pOperatingSystem->initProcess.messages = "";
    pOperatingSystem->initProcess.time = 0; //not sure if we need this
    pOperatingSystem->initProcessIsAlive = true;
    //initialize the first running Process as initProcess
    pOperatingSystem->runningProcess = &pOperatingSystem->initProcess;
}
void operatingSystem_Destructor(OperatingSystem* pKernal){
    free(pKernal);
}



    static bool cmpfunc(void* pItem,void* pArg ){
        ProcessControlBlock* pPcbItem = pItem;
        int* pPID = pArg;
        return pPcbItem->PID == *(pPID);
    }
ProcessControlBlock* operatingSystem_findPID(OperatingSystem* pKernal,int PID){
    return (ProcessControlBlock*)List_search(&pKernal->allProcesses,cmpfunc,&PID);
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