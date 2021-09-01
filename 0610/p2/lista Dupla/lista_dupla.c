#include "lista_dupla.h"

t_lista_dupla * constroi_lista_dupla(){
    t_lista_dupla * lista = (t_lista_dupla *) malloc (sizeof(t_lista_dupla));
    if(lista != NULL){
        lista->primeiro = NULL;
        lista->tamanho =0;
    }
    return lista;
}

int esta_vazia(t_lista_dupla * l){
    return(l->primeiro == NULL);
}


void insere_inicio (int i, t_lista_dupla *l){
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

int remove_inicio (t_lista_dupla *l){
    int i = l->primeiro->dado;
    t_no_duplo * pos_liberar = l->primeiro;
    if (l->tamanho == 1){
        l->primeiro = NULL; 
    }
    else{
        //anterior do segundo deve ser o ultimo
        l->primeiro->proximo->anterior = l->primeiro->anterior;

        //proximo do ultimo deve ser o segundo
        l->primeiro->anterior->proximo = l->primeiro->proximo;
    
        l->primeiro = l->primeiro->proximo;
    }
    l->tamanho--;
    free(pos_liberar);
    return i;
}

void insere_fim (int i, t_lista_dupla *l){
    t_no_duplo * novo = constroi_no(i);

    if(!esta_vazia(l)){
        novo->anterior = l->primeiro->anterior;
        novo->proximo = l->primeiro;
        novo->proximo->anterior = novo;
        novo->anterior->proximo = novo;
    }
    else{
        l->primeiro = novo;
    }
    l->tamanho++;
}

int remove_fim(t_lista_dupla *l){
    int aux = l->primeiro->anterior->dado;
    t_no_duplo * pos_liberar = l->primeiro->anterior;
    if (l->tamanho == 1){
        remove_inicio(l); 
    } 
    else{
        //ponteiro "anterior" aponta para anterior do ultimo
        l->primeiro->anterior = l->primeiro->anterior->anterior;
        //novo elemento "ultimo" aponta ponteiro "proximo" para o primeiro
        l->primeiro->anterior->proximo = l->primeiro;
    }
    l->tamanho--;
    free(pos_liberar);
    return aux;
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

void insere_pos_definida(t_lista_dupla *l, int i, int pos){
    t_no_duplo * novo = constroi_no(i);
    t_no_duplo * aux;
    int cont_pont = 1;
    
    if(pos <= 1 || l->tamanho < 1){//posição <= 1 ou lista vazia é 
        insere_inicio(i, l); //a mesma coisa que inserir no inicio
    }
    else if(l->tamanho < pos){//posição maior que tamanho é 
        insere_fim(i, l);//a mesma coisa que inserir no fim
    }
    else{ 
        aux= l->primeiro;
        while (cont_pont < pos ) {
            aux = aux->proximo;
            cont_pont ++;
        }
        aux->anterior->proximo = novo;
        novo->anterior = aux->anterior;
        aux->anterior = novo;
        novo->proximo = aux;

        l->tamanho++;
    }
}

int remove_pos_definida(t_lista_dupla *l, int pos){
    t_no_duplo * aux;
    t_no_duplo * aux2;
    int dado_aux, cont_pont = 1;
    
    if(pos <= 1){           //posição <= 1 é 
        remove_inicio(l); //a mesma coisa que remover no inicio
    }
    else if(pos > l->tamanho){//posição maior que tamanho é 
        remove_fim(l);//a mesma coisa que remover no fim
    }
    else{
        aux= l->primeiro;
        while (cont_pont < pos ) {
            aux = aux->proximo;
            cont_pont ++;
        }
        dado_aux = aux->dado;
        aux->anterior->proximo = aux->proximo;
        aux->proximo->anterior = aux->anterior;
        free(aux);
        l->tamanho--;
        return dado_aux;
    }
}

t_no_duplo* busca_elemento(t_lista_dupla *l, int x){
    t_no_duplo * aux = l->primeiro;
    int i;
    if(!esta_vazia(l)){
        int cont_prox = 1;      //contador de ponteiros "proximos"
        while (aux->dado != x && cont_prox < l->tamanho){  
                aux = aux->proximo;
                cont_prox++;
        }
        if (aux->dado == x){
            return aux;
        }
    }
    return NULL;
}

int remove_elemento_definido(t_lista_dupla *l, int x){ 
    t_no_duplo * pos = busca_elemento(l,x);
    int dado_aux;
    if(pos == NULL){
        return -1;
    }
    if(pos == l->primeiro){
        l->primeiro = l->primeiro->proximo;
    }
    dado_aux = pos->dado;
    pos->anterior->proximo = pos->proximo;
    pos->proximo->anterior = pos->anterior;
    free(pos);
    l->tamanho--;
    return dado_aux;
}