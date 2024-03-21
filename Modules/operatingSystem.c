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

// static bool pidComparator(void* pItem, void* pComparisonArg) 
// {
//     ProcessControlBlock* pcb = pItem;
//     int pid = pComparisonArg;
//     return pcb->PID == pid;
// }

//time complexity: O(N)
ProcessControlBlock* operatingSystem_findPID(OperatingSystem* pKernal,int PID){
    //List_search(pKernal->allProcesses,pidComparator,PID);
    // List_first(pKernal->allProcesses);
    // while(pKernal->allProcesses->lastOutOfBoundsReason != LIST_OOB_END){
    //     ProcessControlBlock* pcb = (ProcessControlBlock*)pKernal->allProcesses->pCurrentNode->pItem; 
    //     if(pcb->PID == PID){
    //         return pcb;
    //     }
    //     List_next(pKernal->allProcesses);
    // }
    return NULL;
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