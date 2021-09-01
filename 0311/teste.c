#include "meu_cabecalho.h"

int main(){
    int *v, n, x, posicao;
    char continua;
    do{
        printf("Digite o tamanho do vetor: ");
        scanf("%d", &n);
        v = (int *) malloc (n * sizeof(int));
        if(v != NULL){
            gera_vetor(v, n);
            mostra_vetor("vetor original", v, n);
            printf("\ndigite elemento para busca: ");
            scanf("%d", &x);
            posicao = busca_simples(x, v, n);
            if(posicao == -1){
                printf("\nelmentou nao encontrado no vetor\n");
            }
            else{
                printf("\nelemento encontrado na posicao %d\n", posicao);
            }
            free(v);
            v = NULL;
        }
        else{
            printf("falha na alocacao de memoria!\n");
        }
        printf("\nDeseja executar novamente? (s/n)\n");
        scanf(" %c", &continua);    //o espaço antes de %c ou %s é um consumidor de caracteres de sepração
        system("cls");
    } while(continua == 's' || continua == 'S');
    return 0;
}