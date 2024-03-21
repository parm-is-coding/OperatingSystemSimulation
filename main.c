#include <stdio.h>
#include <stdbool.h>
#include <string.h>


#include "HeaderFiles/list.h"
#include "HeaderFiles/scheduler.h"
#include "HeaderFiles/baseFunctions.h"
#include "HeaderFiles/semaphore.h"
#include "HeaderFiles/ipc.h"
#include "HeaderFiles/operatingSystem.h"
#include "HeaderFiles/helper.h"












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


int main() {
    
    
    OperatingSystem* pKernal = malloc(sizeof(OperatingSystem));
    if (pKernal == NULL) {
        printf("Failed to allocate memory for kernal\n");
        return 1;
    }
    operatingSystem_Constructor(pKernal);


    char command;
    while(pKernal->initProcessIsAlive){
        //get user command
        printf("Enter a command: ");
        scanf("%c",&command);
        helper_clearStdinBuffer();
        operatingSystem_runCommand(command,pKernal);
    }
    operatingSystem_Destructor(pKernal);
    printf("Simulation is Over");
    return 0;
}

