#include "../HeaderFiles/baseFunctions.h"
//created processes must be dynamically allocated PCBs
void Create(){}
void Fork(){}

void Kill(OperatingSystem* pKernal){
    printf("Enter PID of Process to Kill: ");
    int PID;
    scanf("%d",&PID);
    //Kill on initProcess
    if(PID == 0){
        //Can only kill initProcess if it is the only Process in Kernal
        if(pKernal->allProcesses->count == 0){
        //initProcess is the only Process in kernal
        //therefore initProcess is the runningProcess
            Exit(pKernal);
        }else{
            printf("Failure: cannot kill PID 0\nOther Processes in system\n");
        }
    }else if(PID == pKernal->runningProcess->PID){
        //Kill on the runningProcess
        Exit(pKernal);
    }else{
        //Kill on some Process
        ProcessControlBlock* processToKill = operatingSystem_findPID(pKernal,PID);
        if(processToKill == (ProcessControlBlock*)-1){
            printf("Failure: invalid PID to kill");
        }else{
            //remove PCB from stateQueue
            switch(processToKill->state){
                case Ready:
                //Ready Queue case
                List* readyQueue = &pKernal->readyQueues[processToKill->priority]; 
                List_first(readyQueue);
                while(processToKill->PID != ((ProcessControlBlock*)List_curr(readyQueue))->PID){
                    List_next(readyQueue);
                }
                List_remove(readyQueue);
                case Blocked:
                //Semaphore case
                case WaitingSender:
                //ipc case
                case WaitingReciever:
                //ipc case
            }
            //remove PCB from allprocesses
            printf("Sucess: Removing PCB %d\n",processToKill->PID);
            List_remove(pKernal->allProcesses);
            List_first(pKernal->allProcesses);
            free(processToKill);
        }
        
    }

}
void Exit(OperatingSystem* pKernal){
    if(pKernal->runningProcess == &pKernal->initProcess){
        if(pKernal->allProcesses->count == 0){
            printf("Removing initProcesses\nEnding Simulation");
            pKernal->initProcessIsAlive = false;
            

        }else{

        }
    }
}
void Quantum(){}
void Proc_Info(){}
void Total_Info(){}