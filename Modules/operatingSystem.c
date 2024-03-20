#include "../HeaderFiles/ipc.h"
#include "../HeaderFiles/basefunctions.h"
#include "../HeaderFiles/semaphore.h"
#include <stdio.h>

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