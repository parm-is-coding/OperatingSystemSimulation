#include "../HeaderFiles/baseFunctions.h"
#include "../HeaderFiles/ipc.h"
#include "../HeaderFiles/list.h"
#include "../HeaderFiles/operatingSystem.h"
#include "../HeaderFiles/pcb.h" //includes MAX_LEN
#include "../HeaderFiles/scheduler.h"
#include "../HeaderFiles/semaphore.h"
#include <stdio.h>
#include <stdbool.h>

void getInputMessage(char* buffer) {
    //PROBLEM: shouldnt overwrite message until receive is called -> use a queue or a temp buffer
    fgets(buffer, MAX_LEN, stdin);
}

void Send(OperatingSystem* pKernal){
    //get PID:
    int PID;
    printf("Enter PID for target process:");
    scanf("%d",&PID);
    helper_clearStdinBuffer();

    //find address
    ProcessControlBlock* target = operatingSystem_findPID(pKernal, PID);
    //case: failure
    //assume: failure -> null
    if (target == NULL) {
        printf("Failure, PID does not exist\n");
        return;
    }
    //success:
    //get + send message:
    getInputMessage(target->received_message);

    //check if target is waiting for message
    if (target->state == WaitingMessage) {
        //TO DO:
        target->state == Ready;
        
        //move target to ready queue

    } else {
        //block current PID
        //TO DO
        //send current to the waiting for a reply list
    }

    //else:
    

    printf("Send command executed\n");
}

void Receive(OperatingSystem* pKernal){
    //if we have already received a message
    
    printf("Receive command executed\n");
}

void Reply(OperatingSystem* pKernal){
    printf("Reply command executed\n");
}