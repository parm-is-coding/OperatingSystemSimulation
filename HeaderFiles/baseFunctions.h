#ifndef functions_h
#define functions_h
#include "operatingSystem.h"
#include "semaphore.h"
#include <stdio.h>

void Create();
void Fork();
void Kill(OperatingSystem* pKernal);
void Exit();
void Quantum();
void Proc_Info();
void Total_Info();

#endif