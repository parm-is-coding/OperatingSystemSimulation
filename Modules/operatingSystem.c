#include "../HeaderFiles/ipc.h"
#include "../HeaderFiles/baseFunctions.h"
#include "../HeaderFiles/semaphore.h"
#include "../HeaderFiles/operatingSystem.h"
#include <stdio.h>
#include <stdbool.h>

void operatingSystem_Constructor(OperatingSystem* pOperatingSystem){
    //initialize initProcess
    pOperatingSystem->initProcess.PID = 0;
    pOperatingSystem->initProcess.priority = initPri;
    pOperatingSystem->initProcess.state = Running;
    pOperatingSystem->initProcess.messages = "";
    pOperatingSystem->initProcess.time = 0; //not sure if we need this
    pOperatingSystem->initProcessIsAlive = true;
    //initialize the first running Process as initProcess
    pOperatingSystem->runningProcess = &pOperatingSystem->initProcess;

}

void runCommand(char* command) {
    switch (*command) {
        case 'C':
            Create();
            break;
        case 'F':
            Fork();
            break;
        case 'K':
            Kill();
            break;
        case 'E':
            Exit();
            break;
        case 'Q':
            Quantum();
            break;
        case 'S':
            Send();
            break;
        case 'R':
            Receive();
            break;
        case 'Y':
            Reply();
            break;
        case 'N':
            New_Sem();
            break;
        case 'P':
            Sem_P();
            break;
        case 'V':
            Sem_V();
            break;
        case 'I':
            Proc_Info();
            break;
        case 'T':
            Total_Info();
            break;
        default: //invalid command
            printf("comand not recognized, please try again\n");
    }
}