
#include "../HeaderFiles/baseFunctions.h"
#include "../HeaderFiles/ipc.h"
#include "../HeaderFiles/list.h"
#include "../HeaderFiles/operatingSystem.h"
#include "../HeaderFiles/pcb.h"
#include "../HeaderFiles/scheduler.h"
#include "../HeaderFiles/semaphore.h"
#include <stdio.h>
#include <stdbool.h>

void helper_clearStdinBuffer(){
    char c;
    while ((c = getchar()) != '\n' && c != EOF);
}
bool helper_cmpfunc(void* pItem,void* pArg ){
        ProcessControlBlock* pPcbItem = pItem;
        int* pPID = pArg;
        return pPcbItem->PID == *(pPID);
}