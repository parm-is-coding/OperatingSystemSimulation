#ifndef semaphore_h
#define semaphore_h
#include "list.h"

typedef struct {
    int Value;
    List* queue;
}Semaphore;

void New_Sem();
void Sem_P();
void Sem_V();

#endif