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

// //static means priv (basically) in C
// static void getInputMessage(char* buffer){
//     //PROBLEM: shouldnt overwrite message until receive is called -> use a queue or a temp buffer
//     fgets(buffer, MAX_LEN, stdin);
// }

// static int getPIDFromUser(){
//     int PID;
//     printf("Enter PID for target process:");
//     scanf("%d",&PID);
//     helper_clearStdinBuffer();

//     return PID;
// }

// //TO DO -> consolidate
// static void List_Trade(ProcessControlBlock* pcb, List* old, List* new) {
    
// }

// //moves back on ready queue and changes state
// static void UnblockProcess(ProcessControlBlock* pcb, List* blocked, OperatingSystem* pKernal){
//     //update state
//     pcb->state = Ready;

//     //remove current from blocked queue
//     int PID = pcb->PID;
//     List_first(blocked); //search from beginning
//     List_search(blocked, helper_cmpfunc, &PID); //current is pointed to match, assuming blocked queue is valid
//     List_remove(blocked); //removes current, does not free mem

//     //add current to ready
//     List* ready = pKernal->readyQueues[pcb->priority];
//     List_append(ready, pcb);
// }

// //remove process from ready queue to blocked, does not change state
// static void BlockProcess(ProcessControlBlock* pcb, List* blocked, OperatingSystem* pKernal) {
//     //remove current from ready queue
//     int PID = pcb->PID;
//     List* ready = pKernal->readyQueues[pcb->priority];

//     List_first(ready); //search from beginning
//     List_search(ready, helper_cmpfunc, &PID); //current is pointed to match, assuming ready is valid
//     List_remove(ready); //removes current

//     //add to blocked queue
//     List_append(blocked, pcb);
// }

void Send(OperatingSystem* pKernal){
    // //get PID:
    // int PID = getPIDFromUser();

    // //find address
    // ProcessControlBlock* current = pKernal->runningProcess;
    // ProcessControlBlock* target = operatingSystem_findPID(pKernal, PID);
    // //case: failure
    // //assume: failure -> null
    // if (target == NULL) {
    //     printf("Failure, PID does not exist\n");
    //     return;
    // } else if (!(target->state == Ready || target->state == Running)) {
    //     //can only send to running/ready processes
    //     printf("Failure, process %d cannot receive messages right now", PID);
    //     return;
    // } else if (target->waitingSender != NULL) {
    //     printf("Failure, process %d is already trying to reach process %d", target->waitingSender->PID, target->PID);
    //     return;
    // }

    // //success:
    // //check if target is waiting for message
    // if (target->state == WaitingMessage) {
    //     UnblockProcess(target, pKernal->WaitingSend, pKernal); //moves target back on the ready queue, changes state as well
        
    //     //when unblocking we lead to proc message
    //     target->sourcePID = current->PID; //tells the target who sent them a message    
    //     getInputMessage(target->message); //can write directly
    //     target->displayProc = ReceivedMessage;
    // } else {
        
    //     //writes the message to the send buffer
    //     getInputMessage(current->messageToSend);
    //     BlockProcess(current, pKernal->waitingReply, pKernal); //waits for a reply
    //     //change state here
    //     current->state = WaitingReply;

    //     //lets the target know we are waiting
    //     target->waitingSender = current;
    // }

    // printf("Send command executed\n");
}

void Receive(OperatingSystem* pKernal){
    // ProcessControlBlock* current = pKernal->runningProcess;
    // ProcessControlBlock* sender = current->waitingSender;

    // //we have someone already waiting to send
    // if (sender != NULL) {
    //     strcpy(current->message, sender->messageToSend); //receives message
    //     current->sourcePID = sender->PID;

    //     printf("Received message from %d:\n%s", sender->PID, current->message); //no need to update message Proc

    //     //unblocks in reply, not here
    //     return;
    // }
    
    // //else (block current):
    // BlockProcess(current, pKernal->WaitingSend, pKernal);

    // //change state here
    // current->state = WaitingMessage;

    // printf("Receive command executed\n");
}

void Reply(OperatingSystem* pKernal){
    // //get PID from user
    // int PID = getPIDFromUser();
    // printf("Enter PID for target process:");
    // scanf("%d",&PID);
    // helper_clearStdinBuffer();

    // //find PID on waiting reply
    // ProcessControlBlock* sender = operatingSystem_findPID(pKernal, PID);
    // ProcessControlBlock* current = pKernal->runningProcess;
    // //trivially, sender is blocked
    
    // if (sender == NULL) {
    //     printf("Failure, PID does not exist\n");
    //     return;
    // } else if (sender->state != WaitingReply) {
    //     printf("Failure, process %d is not waiting for a reply", PID);
    //     return;
    // }

    // //else (reply and unblock to the sender):
    // UnblockProcess(sender, pKernal->waitingReply, pKernal); //changes state as well
    // //when unblocking we lead to proc message
    // sender->sourcePID = current->PID;
    // sender->displayProc = ReceivedReply;
    
    // printf("Reply command executed\n");
}
