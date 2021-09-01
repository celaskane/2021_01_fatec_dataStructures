#include "pilha.h" 

void constroi_pilha (pilha *p, int capacidade){
    p->dados = (int *) malloc (capacidade * sizeof(int));
    p->topo = 0;
    p->capacidade = capacidade; 
}
int esta_vazia(pilha p) {
    //return p.topo == 0;
    if (p.topo == 0) {
        return 1;
    }
    return 0;
}
int esta_cheia(pilha p) {
    //return p.topo == p.capacidade;
    if (p.topo == p.capacidade) {
        return 1;
    }
    return 0;
}
int tamanho(pilha p) {
    return p.topo;
}
void empilha (int valor, pilha *p) {
    //p->dados[p->topo++] = valor;
    p->dados[p->topo] = valor;
    p->topo++;
}
int desempilha (pilha *p) {
    //return p->dados[--p->topo];
    p->topo--;
    return p->dados[p->topo];
}
int consulta_topo (pilha p) {
    if (esta_vazia(p))
        return -1;
    return p.dados[p.topo-1];
}
void exibe_pilha (pilha p) {
    int i;
    if (esta_vazia(p)) {
        printf ("VAZIA");
    }
    else {
        for (i=p.topo-1; i>=0; i--) {
            printf ("%d ", p.dados[i]);
        }
    }
    printf ("\n");
}