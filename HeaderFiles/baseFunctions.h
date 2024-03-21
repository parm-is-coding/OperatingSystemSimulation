#ifndef functions_h
#define functions_h
#include "operatingSystem.h"
#include "semaphore.h"
#include <stdio.h>
#include <stdlib.h>

void Create(OperatingSystem* pKernal);
void Fork(OperatingSystem* pKernal);
void Kill(OperatingSystem* pKernal);
void Exit(OperatingSystem* pKernal);
void Quantum(OperatingSystem* pKernal);
void Proc_Info(OperatingSystem* pKernal);
void Total_Info(OperatingSystem* pKernal);

#endif