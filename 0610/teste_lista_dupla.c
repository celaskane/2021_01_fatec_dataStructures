#include "lista_dupla.h"

int main(){
    t_lista_dupla * ld = constroi_lista_dupla();
    exibe_lista_dupla("lista inicializada", ld);

    insere_inicio(2, ld);
    insere_inicio(4, ld);
    insere_inicio(6, ld);
    exibe_lista_dupla("lista depois das insercoes de inicio", ld);

    insere_fim(3, ld);
    insere_fim(5, ld);
    insere_fim(7, ld);
    exibe_lista_dupla("lista depois das insercoes de fim", ld);

    if(!esta_vazia(ld)){
        printf("%d foi removido do inicio\n", remove_inicio(ld));
        exibe_lista_dupla("lista depois da remocao de fim", ld);
    }

    return 0;
}