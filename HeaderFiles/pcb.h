#ifndef PCB_H
#define PCB_H

typedef struct {
    int PID;
    int time;
    enum State {
        Running = 0,
        Ready = 1,
        Blocked = 2,
        WaitingSender = 3,
        WaitingReciever = 4
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
void pcb_printInfo(ProcessControlBlock* pPCB);

#endif // PCB_H