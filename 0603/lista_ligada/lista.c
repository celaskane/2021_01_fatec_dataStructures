#include "lista.h"

void inicia_lista(t_lista * lista){
    lista->primeiro = NULL;
    lista->ultimo = NULL;
    lista->tamanho = 0;
}

int esta_vazia(t_lista * lista){
    return !lista->primeiro;
}

void insere_inicio(t_lista * lista, int i){
    t_no * novo = cria_no(i);
    if(!esta_vazia(lista)){
        novo->proximo = lista->primeiro;
    }
    else{
        lista->ultimo = novo;
    }
    lista->primeiro = novo;
    lista->tamanho++;
}

void exibe_lista(t_lista * lista){
    t_no * aux;
    printf("lista: ");
    if(esta_vazia(lista)){
        printf("vazia");
    }
    else{
        aux = lista->primeiro;
        while(aux != NULL){ //até o fim da lista
            printf("%d ", aux->dado);
            aux = aux->proximo;
        }
    }
    printf("\n");
}

int remove_inicio(t_lista * lista){
    int i = lista->primeiro->dado;
    t_no * pos_liberar = lista->primeiro;

    lista->primeiro = lista->primeiro->proximo;
    if(esta_vazia(lista)){
        lista->ultimo = NULL;
    }
    free(pos_liberar);
    lista->tamanho--;
    return i;
}

/*void insere_fim(t_lista * lista, int i){
    t_no * novo = cria_no(i);
    t_no * aux;

    if(esta_vazia(lista)){
        lista->primeiro = novo;
    }
    else{
        aux = lista->primeiro;
        while(aux->proximo != NULL){
            aux = aux->proximo;
        }
        aux->proximo = novo;
    }
}*/

void insere_fim(t_lista * lista, int i){
    t_no * novo = cria_no(i);
    if(esta_vazia(lista)){
        lista->primeiro = novo;
    }
    lista->ultimo = novo;
    lista->tamanho++;
}

int remove_fim(t_lista * lista){
    int i = lista->ultimo->dado;
    t_no * pos_liberar = lista->ultimo;
    t_no * aux;
    if(lista->primeiro == lista->ultimo){   //tem um só
        lista->primeiro = lista->ultimo = NULL;
    }
    else{
        aux = lista->primeiro;
        while(aux->proximo != lista->ultimo){
            aux = aux->proximo;
        }
        aux->proximo = NULL;
        lista->ultimo = aux;
    }
    free(pos_liberar);
    lista->tamanho--;
    return i;
}

int getPrimeiro(t_lista * lista){
    return lista->primeiro->dado;
}

int getUltimo(t_lista * lista){
    return lista->ultimo->dado;
}

int getTamanho(t_lista * lista){
    return lista->tamanho;
}