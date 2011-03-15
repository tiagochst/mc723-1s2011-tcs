#ifndef LOCKER_H
#define LOCKER_H 1

#include <semaphore.h>

typedef struct {
   sem_t livre; /* = roomEmpty */
   sem_t catraca; /* = turnstile */
   sem_t mutex;
   int nreader;
} locker_t;

void barrier_unlock(locker_t *lock);
void barrier_lock(locker_t *lock);
void wunblock(locker_t *lock);
void wblock(locker_t *lock);
void runblock(locker_t *lock);
void rblock(locker_t *lock);

#endif /*LOCKER_H*/
