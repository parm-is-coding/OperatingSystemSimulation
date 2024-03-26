#include "../HeaderFiles/baseFunctions.h"
#include "../HeaderFiles/ipc.h"
#include "../HeaderFiles/list.h"
#include "../HeaderFiles/operatingSystem.h"
#include "../HeaderFiles/pcb.h"
#include "../HeaderFiles/scheduler.h"
#include "../HeaderFiles/semaphore.h"
#include <stdio.h>
#include <stdbool.h>

void New_Sem(OperatingSystem* pKernal){
    printf("New_Sem command executed\n");
    
}
void Sem_P(OperatingSystem* pKernal){
    printf("Sem_P command executed\n");
}
void Sem_V(OperatingSystem* pKernal){
    printf("Sem_V command executed\n");
}