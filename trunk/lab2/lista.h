#ifndef LISTA_H
#define LISTA_H 1

#include <malloc.h>

typedef struct __lista_t {
   void* conteudo;
   struct __lista_t* proximo;
} lista_t;

/**
 * cria_lista
 * Cria uma nova lista ligada com nó cabeça.
 */
lista_t* cria_lista();

/**
 * insere_no
 *
 * Parâmetros:
 * - conteudo: conteúdo a ser inserido na lista.
 * - lista: lista onde deve ser armazenado o conteúdo indicado.
 */
void insere_no(void* conteudo, lista_t* lista);

/**
 * libera_lista
 * Libera os recursos utilizados por todos os nós de uma lista ligada (não
 * libera os recursos alocados para a representação dos conteúdos).
 * 
 * Parâmetros:
 * - lista: lista a ser liberada.
 */
void libera_lista(lista_t* lista);

#endif
