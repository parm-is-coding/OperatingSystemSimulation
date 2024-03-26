#ifndef OPERATINGSYSTEM_H
#define OPERATINGSYSTEM_H
#include "ipc.h"

#include "pcb.h"
#include "list.h"
#include <stdbool.h>
#include "semaphore.h"

typedef struct {
    //currently running process
    ProcessControlBlock* runningProcess;
    // list of all processes apart from init
    List* allProcesses;
    // priority based ready queues
    List* readyQueues[3];
    //IPC senderProcesses waiting for acknowledge reply from recieverProcess
    List* waitingReply;
    //IPC recieverProcesses waiting for msg from senderProcesses
    List* WaitingSend;
    // initProcess
    ProcessControlBlock initProcess; 
    //semphors array[5]
    Semaphore* semaphors[5];
    //the condition in which the simulation will continue to run
    bool initProcessIsAlive;
    int numCycles;
} OperatingSystem;

void operatingSystem_Constructor(OperatingSystem* pOperatingSystem);
void operatingSystem_Destructor(OperatingSystem* pKernal);
//O(n)
//iterates over the list of all P.C.B and returns
//the address of the of the process with the matching PID
// -1 if not found
ProcessControlBlock* operatingSystem_findPID(OperatingSystem* pKernal,int PID);

void operatingSystem_runCommand(char command,OperatingSystem* pKernal);

#endif // OPERATINGSYSTEM_H