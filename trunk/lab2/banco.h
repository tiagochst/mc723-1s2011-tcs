#ifndef BANCO_H
#define BANCO_H 1

#include <stdlib.h>
#include <malloc.h>
#include <string.h>
#include "lista.h"
#include "locker.h"
#include "test_threads.h"

#define MAX_REGISTROS 100
#define TAM_NOME      128
#define TAM_CIDADE     32

typedef struct {
   int indice;
   char nome[TAM_NOME];
   int idade;
   char sexo;
   float renda;
   char cidade[TAM_CIDADE];
} registro_t;

typedef struct {
   int indice;
   char nome;
   char idade;
   char sexo;
   char renda;
   char cidade;

   registro_t* r;
} alteracao_t;

typedef struct {
   int indice;
   char nome;
   char idade;
   char sexo;
   char renda;
   char cidade;

   struct {
      char nome[TAM_NOME];
      int idade_min, idade_max;
      char sexo;
      float renda_min, renda_max;
      char cidade[TAM_CIDADE];
   } r;
} consulta_t;

typedef struct {
   int max_registros;
   registro_t** tabela;
   locker_t* lock;
} banco_t;

banco_t* banco;

/**
 * insere_bd
 * Insere um novo registro no banco de dados.
 * 
 * Retorna a posição no banco de dados onde os dados foram inseridos, ou -1
 * se não foi possível realizar a inserção.
 */
int insere_bd(char* nome, int idade, char sexo, float renda, char* cidade);

/**
 * remove_bd
 * Remove um registro do banco de dados.
 * 
 * Parâmetros:
 * - indice: índice do registro a ser removido.
 * 
 * Retorna 1 se conseguiu fazer a remoção e 0 caso contrário.
 */
int remove_bd(int indice);

/**
 * altera_bd
 * Realiza uma modificação em um registro existente no banco de dados.
 * 
 * Parâmetros:
 * - alteracao: uma estrutura indicando quais campos devem ser alterados
 *   e quais seus novos valores.
 *
 * Retorna 1 se conseguiu fazer a alteração e 0 caso contrário.
 */
int altera_bd(alteracao_t* alteracao);

/**
 * consulta_bd
 * Busca no banco de dados por registros que satisfaçam algum critério.
 * 
 * Parâmetros:
 * - criterio: uma estrutura indicando quais campos devem ser buscados e os
 *   parâmetros que devem ser respeitados.
 *
 * Retorna uma lista ligada (com nó cabeça) cotendo os registros que
 * satisfizeram a busca ou NULL se não foi possível realizar a pesquisa.
 */
lista_t* consulta_bd(consulta_t* criterio);

/**
 * le_bd
 * Acessa um registro do banco de dados.
 * 
 * Parâmetros:
 * - indice: índice do registro a ser acessado.
 * 
 * Retorna o registro com o índice fornecido ou NULL, se o registro não
 * existir.
 */
registro_t* le_bd(int indice);

/**
 * libera_resultados
 * Libera uma lista com resultados de uma consulta.
 *
 * Parâmetros:
 * - resultados: lista a ser liberada.
 */
void libera_resultados(lista_t* resultados);

/**
 * inicializa_bd
 * Inicializa a variável global 'banco' com um novo banco de dados.
 * 
 * Parâmetros:
 * - max_registros: número máximo de registro suportado pelo banco de
 *   dados.
 */
void inicializa_bd(int max_registros);

/**
 * libera_bd
 * Libera o banco de dados armazenado na variável global 'banco'.
 */
void libera_bd();

#endif
