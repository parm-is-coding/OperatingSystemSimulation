#include "../HeaderFiles/baseFunctions.h"
#include "../HeaderFiles/ipc.h"
#include "../HeaderFiles/list.h"
#include "../HeaderFiles/operatingSystem.h"
#include "../HeaderFiles/pcb.h" //includes MAX_LEN
#include "../HeaderFiles/scheduler.h"
#include "../HeaderFiles/semaphore.h"
#include "../HeaderFiles/helper.h"
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

//static means priv (basically) in C
static void getInputMessage(char* buffer){
    //PROBLEM: shouldnt overwrite message until receive is called -> use a queue or a temp buffer
    printf("enter message: ");
    fgets(buffer, MAXMESSAGESIZE, stdin);
}

static int getPIDFromUser(){
    int PID;
    printf("Enter PID for target process: ");
    scanf("%d",&PID);
    helper_clearStdinBuffer();

    return PID;
}

// //TO DO -> consolidate
// static void List_Trade(ProcessControlBlock* pcb, List* old, List* new) {
    
// }

//moves back on ready queue and changes state
static void UnblockProcess(ProcessControlBlock* pcb, List* blocked, OperatingSystem* pKernal){
    printf("unblocking process %d\n", pcb->PID);
    //update state
    pcb->state = Ready;

    //remove current from blocked queue
    int PID = pcb->PID;
    List_first(blocked); //search from beginning
    List_search(blocked, helper_cmpfunc, &PID); //current is pointed to match, assuming blocked queue is valid
    List_remove(blocked); //removes current, does not free mem

    //add current to ready
    List* ready = pKernal->readyQueues[pcb->priority];
    List_append(ready, pcb);
}

//remove process from ready queue to blocked, does not change state
//TO DO: schedule on my own
//NOTE: running process is not in the ready queue
static void BlockProcess(ProcessControlBlock* pcb, List* blocked, OperatingSystem* pKernal) {
    printf("blocking process %d\n", pcb->PID);
    //remove current from ready queue
    int PID = pcb->PID;
    List* ready = pKernal->readyQueues[pcb->priority];

    List_first(ready); //search from beginning
    List_search(ready, helper_cmpfunc, &PID); //current is pointed to match, assuming ready is valid
    List_remove(ready); //removes current

    //add to blocked queue
    List_append(blocked, pcb);

    //update scheduler
    pKernal->runningProcess = NULL;
    scheduler_pickNextRunningProcess(pKernal);
}

void Send(OperatingSystem* pKernal){
    if (pKernal->runningProcess->PID == 0) {
        printf("init process can't send\n");
        return;
    }

    //get PID:
    int PID = getPIDFromUser();

    //cant send to self
    if (PID == pKernal->runningProcess->PID) {
        printf("can't send to self\n");
        return;
    }

    //find address
    ProcessControlBlock* current = pKernal->runningProcess;
    ProcessControlBlock* target = operatingSystem_findPID(pKernal, PID);
    //case: failure
    //assume: failure -> null
    if (target == NULL) {
        printf("Failure, PID does not exist\n");
        return;
    } else if (!(target->state == Ready || target->state == Running || target->state == WaitingReceiver)) {
        //can only send to running/ready processes
        printf("Failure, process %d cannot receive messages right now\n", PID);
        return;
    } else if (target->waitingSender != NULL) {
        printf("Failure, process %d is already trying to reach process %d\n", target->waitingSender->PID, target->PID);
        return;
    }

    //success:
    //check if target is waiting for message
    if (target->state == WaitingReceiver) {
        UnblockProcess(target, pKernal->WaitingSend, pKernal); //moves target back on the ready queue, changes state as well
        //no longer waiting for sender
        target->waitingSender = NULL;

        //when unblocking we lead to proc message
        target->sourcePID = current->PID; //tells the target who sent them a message    
        getInputMessage(target->messages); //can write directly
        target->displayProc = ReceivedMessage;
    } else {
        //writes the message to the send buffer
        getInputMessage(current->messageToSend);
        BlockProcess(current, pKernal->waitingReply, pKernal); //waits for a reply
        //change state here
        current->state = WaitingSender;

        //lets the target know we are waiting
        target->waitingSender = current;
    }

    printf("Send command executed\n");
}

void Receive(OperatingSystem* pKernal){
    if (pKernal->runningProcess->PID == 0) {
        printf("init process can't receive\n");
        return;
    }

    ProcessControlBlock* current = pKernal->runningProcess;
    ProcessControlBlock* sender = current->waitingSender;

    //we have someone already waiting to send
    if (sender != NULL) {
        strcpy(current->messages, sender->messageToSend); //receives message
        current->sourcePID = sender->PID;

        printf("Received message from %d:\n%s", sender->PID, current->messages); //no need to update message Proc

        //unlink sender from reciever
        current->waitingSender = NULL;

        //unblocks in reply, not here
        return;
    }
    
    //else (block current):
    BlockProcess(current, pKernal->WaitingSend, pKernal);

    //change state here
    current->state = WaitingReceiver;

    printf("Receive command executed\n");
}

void Reply(OperatingSystem* pKernal){
    if (pKernal->runningProcess->PID == 0) {
        printf("init process can't reply\n");
        return;
    }

    //get PID from user
    int PID = getPIDFromUser();

    //find PID on waiting reply
    ProcessControlBlock* sender = operatingSystem_findPID(pKernal, PID);
    ProcessControlBlock* current = pKernal->runningProcess;
    //trivially, sender is blocked
    
    if (sender == NULL) {
        printf("Failure, PID does not exist\n");
        return;
    } else if (sender->state != WaitingSender) {
        printf("Failure, process %d is not waiting for a reply\n", PID);
        return;
    }

    //send them a reply
    getInputMessage(sender->messages);

    //else (reply and unblock to the sender):
    UnblockProcess(sender, pKernal->waitingReply, pKernal); //changes state as well
    //when unblocking we lead to proc message
    sender->sourcePID = current->PID;
    sender->displayProc = ReceivedReply;

    printf("Reply command executed\n");
}
