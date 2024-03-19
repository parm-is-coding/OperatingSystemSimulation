#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "list.h"
#include "helpers.h"

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

void createInitProcess () {
    initProcess->PID = 0;
    initProcess->priority = initP;
    initProcess->state = Running;
    initProcessIsAlive = true;
}


//set up
//while (initProcessIsAlive)
    //run 1 iteration of our cpu
        //case: if empty -> do nothing
        //choose our priority queue
        //current++
        //current.time -= quantum
        //if current.time == 0
            //kill current
                //list.pop current (frees)
    //execute a command from user
        //switch statement -> function
            //exit: kills current process
                //know the current queue, the current process in that queue
                    //case: process time quantum was finished last round
                //case: if queues are empty
                    //kill initProcess -> initProcessIsAlive = false
//done


int main(){
    createInitProcess();

    List* pAllProcesses = List_create(); //temporary
    List_append(pAllProcesses,&initProcess);

    char command;

    while(initProcessIsAlive){
    runRunningProcess(&initProcess); //temporary
    
    printf("Enter a command: ");
    scanf("%c",&command);
    printf("Run Simulaton");     

    //the commands are qued up and run as the user enters the Q command
    }

    printf("Simulation is Over");
    return 0;
}