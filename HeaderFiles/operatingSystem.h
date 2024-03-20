#ifndef OPERATINGSYSTEM_H
#define OPERATINGSYSTEM_H
#include "ipc.h"
#include "baseFunctions.h"
#include "pcb.h"
#include "list.h"
typedef struct {
    //currently running process
    ProcessControlBlock* runningProcess;
    // list of all processes apart from init
    List* allProcesses;
    // priority based ready queues
    List readyQueues[3];
    // initProcess
    ProcessControlBlock initProcess; 
    //semphors array[5]
    Semaphore semaphors[5];
} OperatingSystem;

void operatingSystem_Constructor(OperatingSystem* pOperatingSystem);

//O(n)
//iterates over the list of all P.C.B and returns
//the index of the of the process with the matching PID
// -1 if not found
int find(int PID); 
void runCommand(char* command);

#endif // OPERATINGSYSTEM_H