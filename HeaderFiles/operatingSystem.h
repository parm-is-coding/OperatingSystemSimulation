#ifndef OPERATINGSYSTEM_H
#define OPERATINGSYSTEM_H

typedef struct {
    int PID;
    int time;
    enum State {
        Ready,
        Running,
        Blocked
    } state;
    enum Priority{
        High = 0,
        Medium = 1,
        Low = 2,
        initPri = 3
    } priority;
    char* messages;
} ProcessControlBlock;

#endif // OPERATINGSYSTEM_H