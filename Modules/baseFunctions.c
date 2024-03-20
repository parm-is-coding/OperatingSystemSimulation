#include "../HeaderFiles/baseFunctions.h"

void Create(){}
void Fork(){}

void Kill(OperatingSystem* pKernal){
    printf("Enter PID of Process to Kill");
    int PID;
    scanf("%d",&PID);
    //Kill on initProcess
    if(PID == 0){
        //Can only kill initProcess if it is the only Process in Kernal
        if(pKernal->allProcesses->count == 0){
        //initProcess is the only Process in kernal
        //therefore initProcess is the runningProcess
            Exit();
        }else{
            printf("Failure: cannot kill PID 0\nOther Processes in system\n");
        }
    }else if(PID == pKernal->runningProcess->PID){
        //Kill on the runningProcess
        Exit();
    }else{
        //Kill on some Process
    }

}
void Exit(){}
void Quantum(){}
void Proc_Info(){}
void Total_Info(){}