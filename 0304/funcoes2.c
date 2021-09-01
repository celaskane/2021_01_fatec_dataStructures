#include <stdio.h>

void nao_altera(int x){
    x = x + 1;
    printf("x da nao_altera: %d\n", x);
}
void altera(int * x){
    *x = *x + 1;                                //*: operador derreferência;
}
int main(){
    int x = 10;
    printf("x original: %d\n", x);
    nao_altera(x);
    printf("x depois da nao_altera: %d\n", x);
    printf("referencia do x: %p\n", &x);        //0061FF1C;
    altera(&x);                                 //&: operador referência;
    printf("x depois da altera: %d\n", x);
    return 0 ;
}