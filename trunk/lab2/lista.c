#include "lista.h"

lista_t* cria_lista() {

   lista_t* aux = (lista_t*) malloc(sizeof(lista_t));

   aux->proximo = NULL;
   aux->conteudo = NULL;

   return aux;

}

void insere_no(void* conteudo, lista_t* lista) {

   lista_t* aux;

   aux = (lista_t*) malloc(sizeof(lista_t));
   aux->proximo = lista->proximo;
   aux->conteudo = conteudo;
   lista->proximo = aux;

}

void libera_lista(lista_t* lista) {

   lista_t* atual,* aux;

   for (atual = lista; atual != NULL; atual = aux) {
      aux = atual->proximo;
      free(atual);
   }

}
