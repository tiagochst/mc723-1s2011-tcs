#!/bin/bash

# Description: Script para testes de memoria cache em software dinero
# Author: Tiago C. Silva


# Teste 1
# Alteramos incialmente a associatividade
# Usamos uma cache unificada para Dados e Instrucao
 
for ((i=1;i<=512;i=i*2))
do
    echo -e "Associatividade:$i\nTamanho Cache:16k\nTamanho Bloco:32\n" >> ../testes/teste1.txt    
    ./dineroIV -informat s -trname applu_f2b -trname ammp_m2b -maxtrace 13 -l1-uassoc $i -l1-usize 16k  -l1-ubsize 32 -l1-uccc| grep "Metrics\|-----------------\|Demand Fetches\|Fraction of total\|Demand Misses\|Demand miss rate\|Compulsory misses\|Capacity misses\|Conflict misses\|Compulsory fraction\|Capacity fraction\|Conflict fraction" | grep -v "( / Demand Fetches)"  >> ../testes/teste1.txt
    echo -e "\n"
    echo -e "\n">> ../testes/teste1.txt
done

# Teste 2
# Alteramos incialmente a associatividade
# Usamos uma cache diferenciada para Dados e Instrucao
# Consideramos a divisao do espaco em 50%
 
for ((i=1;i<=512;i=i*2))
do
    echo -e "Associatividade:$i\nTamanho das Caches:8k\nTamanho Bloco:32\n" >> ../testes/teste2.txt    
    ./dineroIV -informat s -trname applu_f2b -trname ammp_m2b -maxtrace 13 -l1-uassoc $i -l1-isize 8k  -l1-ibsize 32 -l1-dsize 8k  -l1-dbsize 32 -l1-uccc| grep "Metrics\|-----------------\|Demand Fetches\|Fraction of total\|Demand Misses\|Demand miss rate\|Compulsory misses\|Capacity misses\|Conflict misses\|Compulsory fraction\|Capacity fraction\|Conflict fraction" | grep -v "( / Demand Fetches)"  >> ../testes/teste2.txt
    echo -e "\n"
    echo -e "\n">> ../testes/teste2.txt
done
