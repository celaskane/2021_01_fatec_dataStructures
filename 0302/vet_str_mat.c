#include <stdio.h>
#include <stdlib.h>

int main(){
    int *v, t;
    int **m;
    char *palavra;

    printf("digite o tamanho do vetor: \n");
    scanf("%d", &t);

    v = (int *) malloc(t * sizeof(int));

    if(v != NULL){
        printf("memoria alocada com sucesso\n");
        printf("v = %p\n", v);
    }
    else{
        printf("falha na alocacao\n");
    }

    m = (int **) malloc (3 * sizeof(int *));
    printf("\nonde comeca a matriz: %p\n", m);
    for(t=0; t<3; t++){
        m[t] = (int *) malloc (4 * sizeof(int));
        printf("\nonde comeca a linha %d: %p", t, m[t]);
    }

    palavra = (char *) malloc (41 * sizeof(char));

    return 0;
}