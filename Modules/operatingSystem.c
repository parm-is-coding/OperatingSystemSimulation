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
    //free all the lists
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
            Create();
            break;
        case 'F':
            Fork();
            break;
        case 'K':
            Kill(pKernal);
            break;
        case 'E':
            Exit(pKernal);
            break;
        case 'Q':
            Quantum();
            break;
        case 'S':
            Send();
            break;
        case 'R':
            Receive();
            break;
        case 'Y':
            Reply();
            break;
        case 'N':
            New_Sem();
            break;
        case 'P':
            Sem_P();
            break;
        case 'V':
            Sem_V();
            break;
        case 'I':
            Proc_Info();
            break;
        case 'T':
            Total_Info();
            break;
        default: //invalid command
            printf("comand not recognized, please try again\n");
    }
}