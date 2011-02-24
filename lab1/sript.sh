#!/bin/bash

# Description: Script para testes de memoria cache em software dinero
# Author: Tiago C. Silva


# Teste 1 - m2b
# Alteramos incialmente a associatividade
# Usamos uma cache unificada para Dados e Instrucao
 
for ((i=1;i<=512;i=i*2))
do
    echo -e "Associatividade:$i\nTamanho Cache:16k\nTamanho Bloco:32\n" >> ../testes/teste1_m2b.txt    
    ./dineroIV -informat s  -trname applu_m2b -maxtrace 13 -l1-uassoc $i -l1-usize 16k  -l1-ubsize 32 -l1-uccc| grep "Metrics\|-----------------\|Demand Fetches\|Fraction of total\|Demand Misses\|Demand miss rate\|Compulsory misses\|Capacity misses\|Conflict misses\|Compulsory fraction\|Capacity fraction\|Conflict fraction" | grep -v "( / Demand Fetches)"  >> ../testes/teste1_m2b.txt
    echo -e "\n"
    echo -e "\n">> ../testes/teste1_m2b.txt
done

# Teste 2 -m2b
# alteramos a associatividade 
# Usamos uma cache diferenciada para Dados e Instrucao
# Consideramos a divisao do espaco em 50%
 
for ((i=1;i<=512;i=i*2))
do
    echo -e "Associatividade:$i\nTamanho das Caches:8k\nTamanho Bloco:32\n" >> ../testes/teste2_m2b.txt    
    ./dineroIV -informat s  -trname applu_m2b -maxtrace 13 -l1-dassoc $i -l1-iassoc $i -l1-isize 8k  -l1-ibsize 32 -l1-dsize 8k  -l1-dbsize 32 -l1-dccc -l1-iccc  | grep "Metrics\|-----------------\|Demand Fetches\|Fraction of total\|Demand Misses\|Demand miss rate\|Compulsory misses\|Capacity misses\|Conflict misses\|Compulsory fraction\|Capacity fraction\|Conflict fraction" | grep -v "( / Demand Fetches)"  >> ../testes/teste2_m2b.txt
    echo -e "\n"
    echo -e "\n">> ../testes/teste2_m2b.txt
done

# Teste 3 - m2b
# Alteramos incialmente a associatividade com a politica de replacemet para fifo
# Usamos uma cache unificada para Dados e Instrucao
 
for ((i=1;i<=512;i=i*2))
do
    echo -e "Associatividade:$i\nTamanho Cache:16k\nTamanho Bloco:32\n" >> ../testes/teste3_m2b.txt    
    ./dineroIV -informat s  -trname applu_m2b -maxtrace 13 -l1-uassoc $i -l1-usize 16k  -l1-ubsize 32 -l1-uccc -l1-urepl f | grep "Metrics\|-----------------\|Demand Fetches\|Fraction of total\|Demand Misses\|Demand miss rate\|Compulsory misses\|Capacity misses\|Conflict misses\|Compulsory fraction\|Capacity fraction\|Conflict fraction" | grep -v "( / Demand Fetches)"  >> ../testes/teste3_m2b.txt
    echo -e "\n"
    echo -e "\n">> ../testes/teste3_m2b.txt
done


# Teste 1 - f2b
# Alteramos incialmente a associatividade
# Usamos uma cache unificada para Dados e Instrucao
 
for ((i=1;i<=512;i=i*2))
do
    echo -e "Associatividade:$i\nTamanho Cache:16k\nTamanho Bloco:32\n" >> ../testes/teste1_f2b.txt    
    ./dineroIV -informat s -trname applu_f2b -maxtrace 13 -l1-uassoc $i -l1-usize 16k  -l1-ubsize 32 -l1-uccc| grep "Metrics\|-----------------\|Demand Fetches\|Fraction of total\|Demand Misses\|Demand miss rate\|Compulsory misses\|Capacity misses\|Conflict misses\|Compulsory fraction\|Capacity fraction\|Conflict fraction" | grep -v "( / Demand Fetches)"  >> ../testes/teste1_f2b.txt
    echo -e "\n"
    echo -e "\n">> ../testes/teste1_f2b.txt
done

# Teste 2 -f2b
# Alteramos incialmente a politica de replacement para fifo
# Usamos uma cache diferenciada para Dados e Instrucao
# Consideramos a divisao do espaco em 50%
 
for ((i=1;i<=512;i=i*2))
do
    echo -e "Associatividade:$i\nTamanho das Caches:8k\nTamanho Bloco:32\n" >> ../testes/teste2_f2b.txt    
    ./dineroIV -informat s -trname applu_f2b -maxtrace 13 -l1-iassoc $i -l1-dassoc $i -l1-isize 8k  -l1-ibsize 32 -l1-dsize 8k  -l1-dbsize 32 -l1-dccc -l1-iccc -l1-irepl f -l1-drepl f | grep "Metrics\|-----------------\|Demand Fetches\|Fraction of total\|Demand Misses\|Demand miss rate\|Compulsory misses\|Capacity misses\|Conflict misses\|Compulsory fraction\|Capacity fraction\|Conflict fraction" | grep -v "( / Demand Fetches)"  >> ../testes/teste2_f2b.txt
    echo -e "\n"
    echo -e "\n">> ../testes/teste2_f2b.txt
done



# Teste 4 - m2b
# Alteramos incialmente a associatividade e tamanho do bloco
# Usamos uma cache unificada para Dados e Instrucao
for ((j=32;j<=4096;j=j*2))
do
for ((i=1;i<=512;i=i*2))
do
    echo -e "Associatividade:$i\nTamanho Cache:16k\nTamanho Bloco:$j\n" >> ../testes/teste4_m2b.txt    
    ./dineroIV -informat s  -trname applu_m2b -maxtrace 13 -l1-uassoc $i -l1-usize 16k  -l1-ubsize $j -l1-uccc| grep "Metrics\|-----------------\|Demand Fetches\|Fraction of total\|Demand Misses\|Demand miss rate\|Compulsory misses\|Capacity misses\|Conflict misses\|Compulsory fraction\|Capacity fraction\|Conflict fraction" | grep -v "( / Demand Fetches)"  >> ../testes/teste4_m2b.txt
    echo -e "\n"
    echo -e "\n">> ../testes/teste4_m2b.txt
done
done






# Teste 5 - f2b
# Aumentamos a cache e  incialmente a associatividade
# Usamos uma cache unificada para Dados e Instrucao
for ((j=16384;j<=8388608;j=j*2))
do
let i=$j/32;

    echo -e "Associatividade:$i\nTamanho Cache:16k\nTamanho Bloco:$j\n" >> ../testes/teste5_f2b.txt    
    ./dineroIV -informat s  -trname applu_f2b -maxtrace 13 -l1-uassoc $i -l1-usize $j  -l1-ubsize 32 -l1-uccc| grep "Metrics\|-----------------\|Demand Fetches\|Fraction of total\|Demand Misses\|Demand miss rate\|Compulsory misses\|Capacity misses\|Conflict misses\|Compulsory fraction\|Capacity fraction\|Conflict fraction" | grep -v "( / Demand Fetches)"  >> ../testes/teste5_f2b.txt
    echo -e "\n"
    echo -e "\n">> ../testes/teste5_f2b.txt
done