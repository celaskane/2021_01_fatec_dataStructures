#include <time.h>
#include "pilha.h"

int main () {
    pilha p;
    int c;
    printf ("digite a capacidade da pilha: ");
    scanf ("%d", &c);
    constroi_pilha (&p, c);
    srand(time(0));
    do {
        if (rand() % 2) { //empilhar
            if (!esta_cheia(p)) {
                empilha(rand()%10, &p);
            }
        }
        else { //desempilhar
            if (!esta_vazia(p)) {
                desempilha(&p);
            }
        }
        exibe_pilha(p);
    } while (!esta_vazia(p));
    return 0;
}