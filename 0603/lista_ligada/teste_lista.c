#include "lista.h"

int main(){
    t_lista lista;
    inicia_lista(&lista);
    if(esta_vazia(&lista)){
        printf("lista vazia, nao ha o que remover.\n");
    }
    else{
        remove_inicio(&lista);
    }

    exibe_lista(&lista);
    insere_inicio(&lista, 5);
    insere_inicio(&lista, 8);
    insere_inicio(&lista, 13);
    exibe_lista(&lista);

    if(!esta_vazia(&lista)){
        printf("%d saiu do inicio\n", remove_inicio(&lista));
        exibe_lista(&lista);
    }
    return 0;
}