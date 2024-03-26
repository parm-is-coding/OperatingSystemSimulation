#ifndef PCB_H
#define PCB_H
#define MAXMESSAGESIZE 50
typedef struct {
    int PID;
    enum State {
        Running = 0,
        Ready = 1,
        Blocked = 2,
        WaitingSender = 3,
        WaitingReceiver = 4
    } state;
    enum Priority{
        High = 0,
        Medium = 1,
        Low = 2,
        initPri = 3
    } priority;
    char messages[MAXMESSAGESIZE];
     // char proc_message[MAXMESSAGESIZE]; //for returning messages
    enum DisplayProc { //checks if we have anything to show
        NothingToShow = 0,
        ReceivedMessage = 1,
        ReceivedReply = 2
    } displayProc;
    int sourcePID;
    char messageToSend[MAXMESSAGESIZE]; //buffer if receiver is not ready

    ProcessControlBlock* waitingSender;
} ProcessControlBlock;

//Prints the contents of a processcontrolblock
void pcb_printInfo(ProcessControlBlock* pPCB);
void pcb_Constructor(ProcessControlBlock* pPCB,int priority);
void pcb_Destructor(ProcessControlBlock* pPCB);
#endif // PCB_H
