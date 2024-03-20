#include "../HeaderFiles/baseFunctions.h"
#include "../HeaderFiles/ipc.h"
#include "../HeaderFiles/list.h"
#include "../HeaderFiles/operatingSystem.h"
#include "../HeaderFiles/pcb.h"
#include "../HeaderFiles/scheduler.h"
#include "../HeaderFiles/semaphore.h"
#include <stdio.h>
#include <stdbool.h>

//created processes must be dynamically allocated PCBs
void Create(){
    printf("Create command executed\n");
}
void Fork(){
    printf("Fork command executed\n");
}

void Kill(OperatingSystem* pKernal){
    printf("Kill command executed\n");
}
void Exit(OperatingSystem* pKernal){
    printf("Exit command executed\n");
}
void Quantum(){
    printf("Quantum command executed\n");
}
void Proc_Info(){
    printf("ProcessInfo command executed\n");
}
void Total_Info(){
    printf("TotalInfo command executed\n");
}