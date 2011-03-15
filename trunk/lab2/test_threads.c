#include "banco.h"

void* fthread_insere_bd(void *arg) {
   int i;
   registro_t reg;
   
   for(i=0 ; i<*(int*)arg ; i++) {
      insere_bd(reg.nome, reg.idade, reg.sexo, reg.renda, reg.cidade);
      puts("Inseri.");
   }
   return NULL;
}

void* fthread_remove_bd(void *arg) {
   int ind, i;

   for(i=0 ; i<*(int*)arg ; i++) {
      ind = rand() % MAX_REGISTROS;
      remove_bd(ind);
      puts("Removi.");
   }
   return NULL;
}

void* fthread_altera_bd(void *arg) {
   int i;
   alteracao_t alt;
   
   for(i=0 ; i<*(int*)arg ; i++) {
      alt.indice = rand() % MAX_REGISTROS;
      altera_bd(&alt);
      puts("Alterei.");
   }
   return NULL;
}

void* fthread_consulta_bd(void *arg) {
   int i;
   consulta_t cons;
   lista_t *lista;

   for(i=0 ; i<*(int*)arg ; i++) {
      lista = consulta_bd(&cons);
      libera_lista(lista);
      puts("Consultei.");
   }
   return NULL;
}

void* fthread_le_bd(void *arg) {
   int ind, i;
   registro_t *reg;

   for(i=0 ; i<*(int*)arg ; i++) {
      ind = rand() % MAX_REGISTROS;
      reg = le_bd(ind);
      free(reg);
      puts("Li.");
   }
   return NULL;
}
