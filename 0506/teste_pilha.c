#include "pilha.h"

int main () {
    pilha p;
    constroi_pilha(&p, 7);
    if (esta_vazia(p)) {
        printf ("pilha p inicializada com sucesso!\n");
    }
    else {
        printf ("falha na inicializacao da pilha");
        return 0;
    }
    int i=1;
    while (!esta_cheia(p)) {
        empilha(i, &p);
        printf ("%d empilhado com sucesso\n", i++);
    }
    while (!esta_vazia(p)){
        printf ("\n%d foi desempilhado", desempilha(&p));
    }
    return 0;
}