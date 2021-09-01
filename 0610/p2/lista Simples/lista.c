#include "lista.h"

void inicia_lista (t_lista * lista) {
    lista->primeiro = NULL;
    lista->ultimo = NULL;
    lista->tamanho = 0;
}

int esta_vazia (t_lista *lista) {
    return !lista->primeiro;
} 
void insere_inicio (t_lista *lista, int i) {
    t_no * novo = cria_no(i);
    if (!esta_vazia(lista))
        novo->proximo = lista->primeiro;
    else
        lista->ultimo = novo;
    lista->primeiro = novo;
    lista->tamanho++;
}
int remove_inicio (t_lista *lista) {
    int i = lista->primeiro->dado;
    t_no * pos_liberar = lista->primeiro;

    lista->primeiro = lista->primeiro->proximo;
    if (esta_vazia(lista))
        lista->ultimo = NULL;
    free(pos_liberar);
    lista->tamanho--;
    return i;
}
void exibe_lista (char * msg,t_lista *lista) {
    t_no * aux;
    printf ("%s: ", msg);
    if (esta_vazia(lista)) {
        printf ("vazia");
    }
    else {
        aux = lista->primeiro;
        while (aux != NULL) { //até o fim da lista
            printf ("%d ", aux->dado);
            aux = aux->proximo;
        }
    }
    printf("\n");
}
/*
void insere_fim (t_lista *lista, int i) {
    t_no * novo = cria_no(i);
    t_no * aux;

    if (esta_vazia(lista)) {
        lista->primeiro = novo;
    }
    else {
        aux = lista->primeiro;
        while (aux->proximo != NULL) {
            aux = aux->proximo;
        }
        aux->proximo = novo;
    }
    lista->tamanho++;
}
*/
void insere_fim(t_lista * lista, int i){
    t_no * novo= cria_no(i);
    t_no * aux;
    if (esta_vazia(lista)){
        lista->primeiro = novo;
    }
    else{
        lista->ultimo->proximo = novo;
    }
    lista->ultimo = novo;
    lista->tamanho++;
}
int remove_fim (t_lista *lista) {
    int i = lista->ultimo->dado;
    t_no * pos_liberar = lista->ultimo;
    t_no * aux;
    if (lista->primeiro == lista->ultimo) { // tem um só
        lista->primeiro = lista->ultimo = NULL;
    }
    else {
        aux=lista->primeiro;
        while (aux->proximo != lista->ultimo) {
            aux = aux->proximo;
        }       
        aux->proximo = NULL;
        lista->ultimo = aux; 
    }
    free(pos_liberar);
    lista->tamanho--;
    return i;
}

int getPrimeiro(t_lista *lista) {
    return lista->primeiro->dado;
}
int getUltimo(t_lista *lista){
    return lista->ultimo->dado;
}
int getTamanho(t_lista *lista){
    return lista->tamanho;
}

void insere_pos_definida(t_lista *lista, int i, int pos){
    t_no * novo = cria_no(i);
    t_no * aux;
    int cont_prox = 1;
    
    if(pos <= 1 || lista->tamanho == 0){ //posição <= 1 ou lista vazia é 
        insere_inicio(lista, i);        //a mesma coisa que inserir no inicio
    }
    else if(lista->tamanho < pos){  //posição maior que tamanho é 
        insere_fim(lista, i);       //a mesma coisa que inserir no fim
    }
    else{                           //posição esta entre ultimo e primeiro
        aux=lista->primeiro;
        while ((cont_prox + 1) != pos ) {
            aux = aux->proximo;
            cont_prox ++;           // contador de ponteiros "proximos"
        }
        novo->proximo = aux->proximo;
        aux->proximo = novo;
        lista->tamanho++;
    }
}

int remove_pos_definida(t_lista *lista, int pos){
    t_no * aux;
    t_no * aux2;
    int no_aux, cont_prox = 1;

    if(pos <= 1){   //posição <= 1 é a mesma coisa 
        return remove_inicio(lista); //que remover no inicio
    }
    else if(pos >= lista->tamanho){//posição >=tamanho é a mesma
        remove_fim(lista);     //coisa que remover no fim
    }
    else{                   //posição esta entre ultimo e primeiro
        aux=lista->primeiro;
        while ((cont_prox + 1) != pos ) {
            aux = aux->proximo;
            cont_prox ++;
        }
        no_aux = aux->proximo->dado;
        aux2 = aux->proximo;
        aux->proximo = aux->proximo->proximo;
        lista->tamanho--;
        free(aux2);
        return no_aux;
    }
}

int busca_elemento(t_lista *lista, int x){
    t_no * aux=lista->primeiro;
    int i;
    if(!esta_vazia(lista)){
        int cont_prox = 1;      //contador de ponteiros "proximos"
        while (aux->dado != x && cont_prox < lista->tamanho){  
                aux = aux->proximo;
                cont_prox++;
        }
        if (aux->dado == x){
            return cont_prox;
        }
    }
    return -1;
}

int remove_elemento_definido(t_lista *lista, int x){ //x é o numero que deseja retirar
    int pos;

    pos = busca_elemento(lista, x); //utiliza a função que eu fiz para buscar elemento que
    if(pos == -1){                 //retorna uma posicao 
        return -1; 
    }
    return remove_pos_definida(lista, pos); 
}