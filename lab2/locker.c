#include "locker.h"

void barrier_unlock(locker_t *lock) {
   if (__sync_sub_and_fetch (&lock->nreader, 1) == 0)
      sem_post(&lock->livre);  /* abre barreira para escritor */
}

void barrier_lock(locker_t *lock) {
   sem_wait(&lock->mutex);
   if (__sync_add_and_fetch (&lock->nreader, 1) == 1)
      sem_wait(&lock->livre); /* fecha barreira escritor */
   sem_post(&lock->mutex);
}

/* writer unblock */
void wunblock(locker_t *lock) {
   sem_post(&lock->catraca);
   sem_post(&lock->livre);
}

/* writer block */
void wblock(locker_t *lock) {
   sem_wait(&lock->catraca);
   sem_wait(&lock->livre);
}

/* reader unblock */
void runblock(locker_t *lock) {
   barrier_unlock(lock);
}

/* reader block */
void rblock(locker_t *lock) {
   sem_wait(&lock->catraca);
   sem_post(&lock->catraca);
   barrier_lock(lock);
}
