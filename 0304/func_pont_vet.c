#include <stdio.h>
#include <stdlib.h>

int * f2(int n){
    //int v[n];     não pode acontecer, pois o retorno seria de uma variável local.
    int *v = (int *) malloc(n * sizeof(int));
    return v;
}
int main(){
    int *v = f2(10);
    //usar o vetor e depois liberar 
    free(v);    //Le Petit Prince
    return 0;
}