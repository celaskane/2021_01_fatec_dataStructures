#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void gera_vetor(int *, int);
void mostra_vetor(char *, int *, int);
void bubble_sort(int *, int);
int busca_simples(int, int*, int);
//devolve a primeira posição do elemento ou -1 se não encontrar
//os parâmetros: elemento procurado, o vetor e o tamanho dele