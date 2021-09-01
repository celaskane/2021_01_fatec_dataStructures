#include "pilha.h"
#include <stdlib.h>

void constroi_pilha(pilha *p, int capacidade){
    p->dados = (int *) malloc (capacidade * sizeof(int));
    p->topo = 0;
    p->capacidade = capacidade; //this.capacidade = capacidade; (POO)
}

int esta_vazia(pilha p){
    //return p.topo == 0
    if(p.topo == 0) return 1;
    return 0;
}

int esta_cheia(pilha p){
    //return p.topo == 0
    if(p.topo == p.capacidade) return 1;
    return 0;
}

int tamanho(pilha p){
    return p.topo;
}

void empilha(int i, pilha *p){
    p->dados[p->topo] = i;
    p->topo++;
}

int desempilha(pilha p){

}