#ifndef PCB_H
#define PCB_H

typedef struct {
    int PID;
    int time;
    enum State {
        Ready,
        Running,
        Blocked,
        WaitingSender,
        WaitingReciever
    } state;
    enum Priority{
        High = 0,
        Medium = 1,
        Low = 2,
        initPri = 3
    } priority;
    char* messages;
} ProcessControlBlock;

//Prints the contents of a processcontrolblock
pcb_printInfo(ProcessControlBlock* pPCB);

#endif // PCB_H