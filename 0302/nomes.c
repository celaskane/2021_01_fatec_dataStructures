#include <stdio.h>
#include <stdlib.h>

int main(){
    char **nomes;
    int i;
    nomes = (char **) malloc (5 * sizeof(char *));
    printf("Crie uma lista com 5 nomes:\n");
    for(i=0; i<5; i++){
        nomes[i] = (char *) malloc (100 * sizeof(char));
        scanf("%s\n", nomes[i]);
    }
    for(i=0; i<5; i++){
        printf("Nome %d: %s\n", i+1, nomes[i]);
    }

    return 0;
}