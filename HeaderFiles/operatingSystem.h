#ifndef OPERATINGSYSTEM_H
#define OPERATINGSYSTEM_H
#include "ipc.h"
#include "basefunctions.h"

//O(n)
//iterates over the list of all P.C.B and returns
//the index of the of the process with the matching PID
// -1 if not found
int find(int PID); 
void runCommand(char* command);

#endif // OPERATINGSYSTEM_H