#include "../HeaderFiles/baseFunctions.h"
#include "../HeaderFiles/ipc.h"
#include "../HeaderFiles/list.h"
#include "../HeaderFiles/operatingSystem.h"
#include "../HeaderFiles/pcb.h"
#include "../HeaderFiles/scheduler.h"
#include "../HeaderFiles/semaphore.h"
#include "../HeaderFiles/helper.h"
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

void New_Sem(OperatingSystem* pKernal){
    printf("New_Sem command executed\n");
    int id, initVal;
    printf("Enter semaphore id value 0-4 and initial semaphore value\n");
    scanf("%d %d",&id,&initVal);
    helper_clearStdinBuffer();
    if(id < 0 || id > 4){
        printf("Failure: invalid semaphore id\n");
    }else{
        pKernal->semaphors[id] = (Semaphore*)malloc(sizeof(Semaphore));
        printf("Semaphore %d Initialized \n",id);
    }

    
}
void Sem_P(OperatingSystem* pKernal){
    printf("Sem_P command executed\n");
}
void Sem_V(OperatingSystem* pKernal){
    printf("Sem_V command executed\n");
}