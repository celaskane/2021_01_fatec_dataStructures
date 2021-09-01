#include <stdio.h>

void SOMA(float a, int b){
    float result;
    result = a+b;
    printf("A soma de %6.3f com %d é %6.3f\n", a, b, result);
}
int main(){
    int a;
    float b;
    a = 10;
    b = 12.3;
    SOMA(b, a);
    return 0;
}