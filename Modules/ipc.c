#include "../HeaderFiles/baseFunctions.h"
#include "../HeaderFiles/ipc.h"
#include "../HeaderFiles/list.h"
#include "../HeaderFiles/operatingSystem.h"
#include "../HeaderFiles/pcb.h" //includes MAX_LEN
#include "../HeaderFiles/scheduler.h"
#include "../HeaderFiles/semaphore.h"
#include <stdio.h>
#include <stdbool.h>

//static means priv (basically) in C
static void getInputMessage(char* buffer) {
    //PROBLEM: shouldnt overwrite message until receive is called -> use a queue or a temp buffer
    fgets(buffer, MAX_LEN, stdin);
}

static int getPIDFromUser() {
    int PID;
    printf("Enter PID for target process:");
    scanf("%d",&PID);
    helper_clearStdinBuffer();

    return PID;
}

void Send(OperatingSystem* pKernal){
    //get PID:
    int PID = getPIDFromUser();

    //find address
    ProcessControlBlock* current = pKernal->runningProcess;
    ProcessControlBlock* target = operatingSystem_findPID(pKernal, PID);
    //case: failure
    //assume: failure -> null
    if (target == NULL) {
        printf("Failure, PID does not exist\n");
        return;
    } else if (!(target->state == Ready || target->state == Running)) {
        //can only send to running/ready processes
        printf("Failure, process %d cannot receive messages right now", PID);
        return;
    } else if (target->waitingSender != NULL) {
        printf("Failure, process %d is already trying to reach process %d", target->waitingSender->PID, target->PID);
        return;
    }

    //success:
    //check if target is waiting for message
    if (target->state == WaitingMessage) {
        UnblockProcess(target, pKernal->WaitingSend); //moves target back on the ready queue, changes state as well
        
        //when unblocking we lead to proc message
        target->sourcePID = current->PID; //tells the target who sent them a message    
        getInputMessage(target->message); //can write directly
        target->displayProc = ReceivedMessage;
    } else {
        
        //writes the message to the send buffer
        getInputMessage(current->messageToSend);
        BlockProcess(current, pKernal->waitingReply); //waits for a reply
        //change state here
        current->state = WaitingReply;

        //lets the target know we are waiting
        target->waitingSender = current;
    }

    printf("Send command executed\n");
}

void Receive(OperatingSystem* pKernal){
    ProcessControlBlock* current = pKernal->runningProcess;
    ProcessControlBlock* sender = current->waitingSender;

    //we have someone already waiting to send
    if (sender != NULL) {
        strcpy(current->message, sender->messageToSend); //receives message
        current->sourcePID = sender->PID;

        printf("Received message from %d:\n%s", sender->PID, current->message); //no need to update message Proc

        //unblocks in reply, not here
        return;
    }
    
    //else (block current):
    BlockProcess(current, pKernal->WaitingSend);

    //change state here
    current->state = WaitingMessage;

    printf("Receive command executed\n");
}

void Reply(OperatingSystem* pKernal){
    //get PID from user
    int PID = getPIDFromUser();
    printf("Enter PID for target process:");
    scanf("%d",&PID);
    helper_clearStdinBuffer();

    //find PID on waiting reply
    ProcessControlBlock* sender = operatingSystem_findPID(PID);
    ProcessControlBlock* current = pKernal->runningProcess;
    //trivially, sender is blocked
    
    if (sender == NULL) {
        printf("Failure, PID does not exist\n");
        return;
    } else if (sender->state != WaitingReply) {
        printf("Failure, process %d is not waiting for a reply", PID);
        return;
    }

    //else (reply and unblock to the sender):
    UnblockProcess(sender, pKernal->waitingReply); //changes state as well
    //when unblocking we lead to proc message
    sender->sourcePID = current->PID;
    sender->displayProc = ReceivedReply;
    
    printf("Reply command executed\n");
}