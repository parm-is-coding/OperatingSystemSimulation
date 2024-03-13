#include <stdio.h>
#include <stdbool.h>
#include "helpers.h"
bool initProcessIsAlive;


typedef struct {
    int PID;
} ProcessControlBlock;

int find(int){
    return -1;
}

int main(){
    printf("Hello World\n");
    ProcessControlBlock initProcess;

    while(initProcessIsAlive){

       

        initProcessIsAlive = find(initProcess.PID) != -1;
    }
    printf("Simulation is Over");
    return 0;
}