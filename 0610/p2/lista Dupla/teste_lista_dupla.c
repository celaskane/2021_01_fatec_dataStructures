#include "lista_dupla.h"
#include <time.h>
int main(){
    t_lista_dupla * ld = constroi_lista_dupla();
    exibe_lista_dupla("lista inicializada", ld);
    int i;
    int elemento;
    int pos;
    for(i = 1; i <=10; i++){
        insere_pos_definida(ld, i, 1);
        //exibe_lista_dupla(" ", ld);
    }
    exibe_lista_dupla("lista depois da insercao do loop\n", ld);

    printf("Digite um elemento e uma posicao: \n");
    scanf("%d %d",&elemento, &pos);
    insere_pos_definida(ld, elemento, pos);
    exibe_lista_dupla("Lista apos insercao do usuario: \n", ld);

    printf("\nQual elemento vc deseja procura?");
    scanf("%d", &pos);
    printf("\nElemento encontrado no endereco: %d\n", busca_elemento(ld, pos));

    printf("\nQual elemento vc deseja remover?");
    scanf("%d", &pos);
    printf("%d removido\n", remove_elemento_definido(ld, pos));
    exibe_lista_dupla("\nLista dps de remover: ", ld);

    printf("Digite uma posicao para remover: \n");
    scanf("%d",&pos);
    printf("%d removido\n", remove_pos_definida(ld, pos));
    exibe_lista_dupla("Lista apos remocao de posicao do usuario: \n", ld);

    printf("Digite uma posicao para remover: \n");
    scanf("%d",&pos);
    printf("%d removido\n", remove_pos_definida(ld, pos));
    exibe_lista_dupla("Lista apos remocao de posicao do usuario: \n", ld);

    printf("Digite uma posicao para remover: \n");
    scanf("%d",&pos);
    printf("%d removido\n", remove_pos_definida(ld, pos));
    exibe_lista_dupla("Lista apos remocao de posicao do usuario: \n", ld);

    return 0;
}