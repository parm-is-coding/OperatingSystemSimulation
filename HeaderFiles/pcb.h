#ifndef PCB_H
#define PCB_H

#define MAX_LEN 40

typedef struct {
    int PID;
    int time;
    enum State {
        Running = 0,
        Ready = 1,
        Blocked = 2,
        WaitingReply = 3,
        WaitingMessage = 4
    } state;
    enum Priority{
        High = 0,
        Medium = 1,
        Low = 2,
        initPri = 3
    } priority;

    char messages[MAX_LEN];
    char proc_message[MAX_LEN]; //for returning messages
    enum DisplayProc { //checks if we have anything to show
        ReceivedMessage = 0,
        ReceivedReply = 1,
        NothingToShow = 2
    } displayProc;
    char messageToSend[MAX_LEN]; //buffer if receiver is not ready

    ProcessControlBlock* waitingSender;
} ProcessControlBlock;

//Prints the contents of a processcontrolblock
void pcb_printInfo(ProcessControlBlock* pPCB);
void pcb_Constructor(ProcessControlBlock* pPCB,int priority);
void pcb_Destructor(ProcessControlBlock* pPCB);
#endif // PCB_H