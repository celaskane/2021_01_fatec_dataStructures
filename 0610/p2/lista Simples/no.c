#include "no.h"

t_no * cria_no (int i){
    t_no * aux =  (t_no *) malloc (sizeof(t_no));
    if(aux != NULL){
        aux->dado = i;
        aux->proximo = NULL; 
    }
    
    return aux;
}

