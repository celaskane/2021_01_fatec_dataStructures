#include "lista.h"
#include <time.h>
int main () {
    t_lista lista;
    inicia_lista (&lista);
    exibe_lista("Lista quando criada", &lista);
    int i, ini, fim, pos;
    
    for(i = 1; i <=10; i++){
        insere_pos_definida(&lista, i, 1);
        exibe_lista(" ", &lista);
    }
    /*insere_pos_definida(&lista, 999, lista.tamanho -1); //lista, número, posição
    
    exibe_lista("\nlista apos a insercao de 999 na penultimo posicao \n", &lista);
    
    printf("%d removido", remove_pos_definida(&lista, 99));
    exibe_lista("Lista dps da remoção em 99 ", &lista);
    */
    printf("Qual elemento vc quer retirar?\n");
    scanf("%d", &i);
    printf("%d removido\n", remove_elemento_definido(&lista, i));
    exibe_lista("Lista dps da remocao do elemento", &lista);
    printf("Qual elemento vc quer retirar?\n");
    scanf("%d", &i);
    printf("%d removido\n", remove_elemento_definido(&lista, i));
    exibe_lista("Lista dps da remocao do elemento", &lista);
    printf("Qual elemento vc quer retirar?\n");
    scanf("%d", &i);
    printf("%d removido\n", remove_elemento_definido(&lista, i));
    exibe_lista("Lista dps da remocao do elemento", &lista);

    return 0;
}