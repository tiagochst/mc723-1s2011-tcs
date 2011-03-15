#include <stdio.h>
#include <time.h>
#include <pthread.h>
#include "banco.h"

int main() {
   pthread_t *thread;
   int nthreads = 20, ntimes = 20000;
   int i;

   srand(time(NULL));

   inicializa_bd(MAX_REGISTROS);

   thread = (pthread_t *) malloc(nthreads * sizeof(pthread_t));
   for(i=0 ; i<nthreads ;) {
      pthread_create(&thread[i++], NULL, fthread_insere_bd, &ntimes);
      pthread_create(&thread[i++], NULL, fthread_remove_bd, &ntimes);
      pthread_create(&thread[i++], NULL, fthread_altera_bd, &ntimes);
      pthread_create(&thread[i++], NULL, fthread_consulta_bd, &ntimes);
      pthread_create(&thread[i++], NULL, fthread_le_bd, &ntimes);
   }

   for(i=0 ; i<nthreads ; i++)
      pthread_join(thread[i], NULL);
   free(thread);

   libera_bd();

   return 0;
}
