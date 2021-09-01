#include <stdio.h>
#include <stdlib.h>

int main(){
    printf("RAND_MAX = %d\n", RAND_MAX);
    srand(10);
    printf("Primeiro valor gerado = %d\n", rand());
    printf("Sgundo valor gerado = %d\n", rand());
    return 0;
}