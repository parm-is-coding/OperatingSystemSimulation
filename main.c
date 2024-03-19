#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "list.h"
#include "helpers.h"

// global Variables
bool initProcessIsAlive;


typedef struct {
    int PID;
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



int main(){
    printf("Hello World\n");
    //Setting up InitProcess
    ProcessControlBlock initProcess;
    initProcess.PID = 0;
    initProcess.priority = initP;
    initProcess.state = Running;

    List* pAllProcesses = List_create();
    List_append(pAllProcesses,&initProcess);
    bool initProcessIsAlive = true;
    while(initProcessIsAlive){
    //runRunningProcess(pAllProcesses);
    char command;
    printf("Enter a command: ");
    scanf("%c",&command);
    printf("Run Simulaton");     
    initProcessIsAlive = false;


    //the commands are qued up and run as the user enters the Q command
    }
    printf("Simulation is Over");
    return 0;
}