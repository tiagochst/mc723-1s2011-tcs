#ifndef TEST_THREADS_H
#define TEST_THREADS_H 1

void* fthread_insere_bd(void *arg);
void* fthread_remove_bd(void *arg);
void* fthread_altera_bd(void *arg);
void* fthread_consulta_bd(void *arg);
void* fthread_le_bd(void *arg);

#endif /*TEST_THREADS_H*/
