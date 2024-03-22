#ifndef SCHEDULER_H
#define SCHEDULER_H
#include "operatingSystem.h"

void scheduler_runRunningProcess(OperatingSystem* pKernal);
void scheduler_returnRunningToReady(OperatingSystem* pKernal);
void scheduler_pickNextRunningProcess(OperatingSystem* pKernal);

#endif // SCHEDULER_H