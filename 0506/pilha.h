#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int * dados;
    int topo;
    int capacidade;
} pilha;

void constroi_pilha (pilha *, int);
//inicializar a pilha

void empilha (int, pilha *);
//empilha(o): insere o objeto o no topo da pilha.
//Entrada: objeto. Saída: nenhuma.

int desempilha (pilha *);
//desempilha(): retira o objeto no topo da pilha e o retorna; 
//Entrada: nenhuma. Saída: objeto.

int tamanho(pilha);
//tamanho(): retorna o número de objetos na pilha.
//Entrada: nenhuma. Saída: inteiro.

int esta_vazia(pilha);
//vazia(): Retorna um booleano indicando se a pilha está vazia.
//Entrada: nenhuma. Saída: booleano.

int esta_cheia(pilha);
//cheia(): Retorna um booleano indicando se a pilha está cheia.
//Entrada: nenhuma. Saída: booleano.

int consulta_topo (pilha);
//getTopo(): Retorna o elemento que está no "topo" da pilha
//se a pilha estiver vazia, retornar -1

void exibe_pilha (pilha);
//exibe a pilha do topo para baixo
//se a pilha estiver vazia, exibe "VAZIA"
