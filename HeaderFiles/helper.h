#ifndef HELPER_H
#define HELPER_H


void helper_clearStdinBuffer();
bool helper_cmpfunc(void* pItem,void* pArg );
void helper_removeFromAllProcesses(List* pAllProcesses,int PID);
#endif // HELPER_H