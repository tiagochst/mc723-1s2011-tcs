#include "banco.h"

int wrc[MAX_REGISTROS] = {0}; /* Numero de escritores na rc */
int rrc[MAX_REGISTROS] = {0}; /* Numero de leitores na rc */

void wtest_in(int i, char *s) {
   __sync_add_and_fetch(&wrc[i], 1);
   if (wrc[i] > 1 || rrc[i] > 0) {
      fprintf(stderr, "ERRO!!!\nFuncao %s\nwrc[%d] = %d\nrrc[%d] = %d\n", s, 
              i, wrc[i], i, rrc[i]);
      exit(1);
   }
}
void wtest_out(int i) {
   __sync_sub_and_fetch(&wrc[i], 1);
}

void rtest_in(int i) {
   __sync_add_and_fetch(&rrc[i], 1);
   if (wrc[i] > 0) {
      fprintf(stderr, "ERRO!!!\nwrc[%d] = %d\n", i, wrc[i]);
      exit(1);
   }
}
void rtest_out(int i) {
   __sync_sub_and_fetch(&rrc[i], 1);
}

int insere_bd(char* nome, int idade, char sexo, float renda, char* cidade) {
   int i;

   for (i = 0; i < banco->max_registros; i++) {
      wblock(&banco->lock[i]);
      wtest_in(i, "insere");

      /* Insere no primeiro espaço vazio que encontrar. */
      if (banco->tabela[i] == NULL) {
         banco->tabela[i] = (registro_t*) malloc(sizeof(registro_t));

         banco->tabela[i]->indice = i;
         strncpy(banco->tabela[i]->nome, nome, TAM_NOME);
         banco->tabela[i]->idade = idade;
         banco->tabela[i]->sexo = sexo;
         banco->tabela[i]->renda = renda;
         strncpy(banco->tabela[i]->cidade, cidade, TAM_CIDADE);

         wtest_out(i);
         wunblock(&banco->lock[i]);
         return i;
      }

      wtest_out(i);
      wunblock(&banco->lock[i]);
   }

   return -1;

}

int remove_bd(int indice) {

   /* Confere se o registro existe. */
   if (indice < 0 || indice >= banco->max_registros)
      return 0;

   wblock(&banco->lock[indice]);
   wtest_in(indice, "remove");

   if(banco->tabela[indice] == NULL) {
      wtest_out(indice);
      wunblock(&banco->lock[indice]);
      return 0;
   }

   free(banco->tabela[indice]);
   banco->tabela[indice] = NULL;

   wtest_out(indice);
   wunblock(&banco->lock[indice]);
   return 1;

}

int altera_bd(alteracao_t* alteracao) {

   int indice = alteracao->indice;

   /* Confere se o registro existe. */
   if (indice < 0 || indice >= banco->max_registros)
      return 0;

   wblock(&banco->lock[indice]);
   wtest_in(indice, "altera");

   if(banco->tabela[indice] == NULL) {
      wtest_out(indice);
      wunblock(&banco->lock[indice]);
      return 0;
   }

   if (alteracao->nome == 1)
      strncpy(banco->tabela[indice]->nome, alteracao->r->nome, TAM_NOME);

   if (alteracao->idade == 1)
      banco->tabela[indice]->idade = alteracao->r->idade;

   if (alteracao->sexo == 1)
      banco->tabela[indice]->sexo = alteracao->r->sexo;

   if (alteracao->renda == 1)
      banco->tabela[indice]->renda = alteracao->r->renda;

   if (alteracao->cidade == 1)
      strncpy(banco->tabela[indice]->cidade, alteracao->r->cidade, TAM_CIDADE);

   wtest_out(indice);
   wunblock(&banco->lock[indice]);
   return 1;

}

/* importante: deve-se dar free() no valor devolvido por esta funcao */
lista_t* consulta_bd(consulta_t* crit) {

   int i;
   lista_t* resultados = cria_lista();

   for (i = 0; i < banco->max_registros; i++) {
      rblock(&banco->lock[i]);
      rtest_in(i);

      if (! (crit->nome == 1 && strcmp(banco->tabela[i]->nome, crit->r.nome) != 0) &&
          ! (crit->idade == 1 && (banco->tabela[i]->idade < crit->r.idade_min || banco->tabela[i]->idade > crit->r.idade_max)) &&
          ! (crit->sexo == 1 && banco->tabela[i]->sexo != crit->r.sexo) &&
          ! (crit->renda == 1 && (banco->tabela[i]->renda < crit->r.renda_min || banco->tabela[i]->renda > crit->r.renda_max)) &&
          ! (crit->cidade == 1 && strcmp(banco->tabela[i]->cidade, crit->r.cidade) != 0))
         insere_no(banco->tabela[i], resultados);

      rtest_out(i);
      runblock(&banco->lock[i]);
   }

   return resultados;

}

/* importante: deve-se dar free() no valor devolvido por esta funcao */
registro_t* le_bd(int indice) {

   registro_t* registro;

   /* Confere se o registro existe. */
   if (indice < 0 || indice >= banco->max_registros)
      return NULL;

   rblock(&banco->lock[indice]);
   rtest_in(indice);

   if(banco->tabela[indice] == NULL) {
      rtest_out(indice);
      runblock(&banco->lock[indice]);
      return NULL;
   }

   registro = (registro_t*) malloc(sizeof(registro_t));
   registro->indice = banco->tabela[indice]->indice;
   strncpy(registro->nome, banco->tabela[indice]->nome, TAM_NOME);
   registro->idade = banco->tabela[indice]->idade;
   registro->sexo = banco->tabela[indice]->sexo;
   registro->renda = banco->tabela[indice]->renda;
   strncpy(registro->cidade, banco->tabela[indice]->cidade, TAM_CIDADE);

   rtest_out(indice);
   runblock(&banco->lock[indice]);

   return registro;

}

void libera_resultados(lista_t* resultados) {

   libera_lista(resultados);

}

void inicializa_bd(int max_registros) {

   int i;

   banco = (banco_t*) malloc(sizeof(banco_t));
   banco->max_registros = max_registros;
   banco->tabela = (registro_t**) malloc(max_registros * sizeof(registro_t*));
   banco->lock = (locker_t*) malloc(max_registros * sizeof(locker_t));

   for (i = 0; i < max_registros; i++) {
      banco->tabela[i] = NULL;

      /* inicializa os locks com 1 */
      sem_init(&banco->lock[i].livre, 0, 1);
      sem_init(&banco->lock[i].catraca, 0, 1);
      sem_init(&banco->lock[i].mutex, 0, 1);
      banco->lock[i].nreader = 0;
   }

}

void libera_bd() {

   int i;

   for (i = 0; i < banco->max_registros; i++) {
      if (banco->tabela[i] != NULL)
         free(banco->tabela[i]);
   }

   free(banco->tabela);
   free(banco->lock);
   free(banco);

}
