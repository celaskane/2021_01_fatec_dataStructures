#include <stdio.h>
#include <time.h>
#include <limits.h>

int main(){
    int inicio, fim, i;
    printf("%d\n", time(0));
    inicio = time(0);
    printf("INT_MAX = %d\n", INT_MAX);
    for(i=0; i<INT_MAX; i++);
    fim = time(0);
    printf("tempo do laco = %d\n", fim - inicio);
    return 0;
}