#include "../HeaderFiles/baseFunctions.h"
#include "../HeaderFiles/ipc.h"
#include "../HeaderFiles/list.h"
#include "../HeaderFiles/operatingSystem.h"
#include "../HeaderFiles/pcb.h"
#include "../HeaderFiles/scheduler.h"
#include "../HeaderFiles/semaphore.h"
#include <stdio.h>
#include <stdbool.h>
void Send(OperatingSystem* pKernal){
    printf("Send command executed\n");
}
void Receive(OperatingSystem* pKernal){
    printf("Receive command executed\n");
}
void Reply(OperatingSystem* pKernal){
    printf("Reply command executed\n");
}