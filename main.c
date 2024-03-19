#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "list.h"

#include "helpers.h"
#include "scheduler.h"
#include "functions.h"
#include "semaphore.h"
#include "ipc.h"

// global Variables
bool initProcessIsAlive;
ProcessControlBlock initProcess;

typedef struct {
    int PID;
    int time;
    enum State {
        Ready,
        Running,
        Blocked
    } state;
    enum Priority{
        High = 0,
        Medium = 1,
        Low = 2,
        initP = 3
    } priority;
    char* messages;
} ProcessControlBlock;

typedef struct {
    int Value;
    List* queue;
}Semaphore;


void runRunningProcess(ProcessControlBlock* test){
    //iterate over the list of all processes return the address
    //of the PCB that is in the running state
    ProcessControlBlock* pRunningProcess = test;
    printf("Running Process ID:%d\n",pRunningProcess->PID);
}

void createInitProcess() {
    initProcess->PID = 0;
    initProcess->priority = initP;
    initProcess->state = Running;
    initProcessIsAlive = true;
}


//set up
//while (initProcessIsAlive)
    //execute a command from user
        //switch statement -> function
            //exit: kills current process
                //know the current queue, the current process in that queue
                    //case: process time quantum was finished last round
                //case: if queues are empty
                    //kill initProcess -> initProcessIsAlive = false
            //q: runs a process
                //run 1 iteration of our cpu
                //case: if empty -> do nothing
                //choose our priority queue
                //current++
                //current.time -= quantum
                //if current.time == 0
                    //kill current
                        //list.pop current (frees)

//done


int main() {
    createInitProcess();

    List* pAllProcesses = List_create(); //temporary
    List_append(pAllProcesses,&initProcess);

    char command;

    while(initProcessIsAlive){
        runProcess(); //scheduler chooses and runs a process, if empty -> do nothing
        
        //get user command
        printf("Enter a command: ");
        scanf("%c",&command);
        
        runCommand(&command);
    }

    printf("Simulation is Over");
    return 0;
}

void runCommand(char* command) {
    switch (*command) {
        case 'C':
            Create();
            break;
        case 'F':
            Fork();
            break;
        case 'K':
            Kill();
            break;
        case 'E':
            Exit();
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