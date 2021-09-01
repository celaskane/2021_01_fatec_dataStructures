#include "no_duplo.h"

t_no_duplo *constroi_no(int i){

    t_no_duplo *aux = (t_no_duplo *) malloc(sizeof(t_no_duplo));
    if (aux != NULL)
    {
        aux->dado = i;
        aux->proximo = aux;
        aux->anterior = aux;
    }

    return aux;
}