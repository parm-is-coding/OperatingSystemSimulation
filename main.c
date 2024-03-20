#include <stdio.h>
#include <stdbool.h>
#include <string.h>


#include "HeaderFiles/list.h"
#include "HeaderFiles/helpers.h"
#include "HeaderFiles/scheduler.h"
#include "HeaderFiles/functions.h"
#include "HeaderFiles/semaphore.h"
#include "HeaderFiles/ipc.h"
#include "HeaderFiles/operatingSystem.h"













//set up
//while (initProcessIsAlive)
    //execute a command from user
        //switch statement -> function
            //exit: kills current process
                //know the current queue, the current process in that queue
                    //case: process time quantum was finished last round
                //case: if queues are empty
                    //kill initProcess -> initProcessIsAlive = false
            //q: runs a process
                //run 1 iteration of our cpu
                //case: if empty -> do nothing
                //choose our priority queue
                //current++
                //current.time -= quantum
                //if current.time == 0
                    //kill current
                        //list.pop current (frees)

//done
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

int main() {
    
    bool initProcessIsAlive = true;
  

    char command;

    while(initProcessIsAlive){
        
        
        //get user command
        printf("Enter a command: ");
        scanf("%c",&command);
        
        runCommand(&command);
    }

    printf("Simulation is Over");
    return 0;
}

