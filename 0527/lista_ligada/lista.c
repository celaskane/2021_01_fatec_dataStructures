#include "lista.h"

void inicia_lista(t_lista * lista){
    lista->primeiro = NULL;
}

int esta_vazia(t_lista * lista){
    return !lista->primeiro;
}

void insere_inicio(t_lista * lista, int i){
    t_no * novo = cria_no(i);
    if(!esta_vazia(lista)){
        novo->proximo = lista->primeiro;
    }
    lista->primeiro = novo;
}