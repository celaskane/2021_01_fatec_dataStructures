#include "lista_dupla.h"

t_lista_dupla * constroi_lista_dupla(){
    t_lista_dupla * lista = (t_lista_dupla *) malloc (sizeof(t_lista_dupla));
    if(lista != NULL){
        lista->primeiro = NULL;
        lista->tamanho = 0;
    }
    return lista;
}

int esta_vazia(t_lista_dupla * l){
    return(l->primeiro == NULL);
}

void insere_inicio(int i, t_lista_dupla * l){
    t_no_duplo * novo = constroi_no(i);
    if(!esta_vazia(l)){
        novo->proximo = l->primeiro;
        novo->anterior = l->primeiro->anterior;
        novo->proximo->anterior = novo;
        novo->anterior->proximo = novo;
    }
    l->primeiro = novo;
    l->tamanho++;
}

void insere_fim(int i, t_lista_dupla * l){
    t_no_duplo * novo = constroi_no(i);
    if(!esta_vazia(l)){
        novo->proximo = l->primeiro;
        novo->anterior = l->primeiro->anterior;
        novo->proximo->anterior = novo;
        novo->anterior->proximo = novo;
    }
    else{
        l->primeiro = novo;
    }
    l->tamanho++;
}

void exibe_lista_dupla(char * msg, t_lista_dupla * l){
    t_no_duplo * aux;
    printf("%s: ", msg);
    if(esta_vazia(l)){
        printf("vazia");
    }
    else{
        aux = l->primeiro;
        do{
            printf("%d ", aux->dado);
            aux = aux->proximo;
        } while(aux != l->primeiro);
    }
    printf("\n");
}

int remove_inicio(t_lista_dupla * l){
    int i = l->primeiro->dado;
    t_no_duplo * pos_liberar = l->primeiro;
    if(l->tamanho == 1){
        l->primeiro = NULL;
    }
    else{
        //anterior do segundo deve ser o último
        l->primeiro->proximo->anterior = l->primeiro->anterior;

        //próximo do último deve ser o segundo
        l->primeiro->anterior->proximo = l->primeiro->proximo;

        //o primeiro passa a ser o segundo
        l->primeiro = l->primeiro->proximo;
    }
    l->tamanho--;
    free(pos_liberar);
    return i;
}