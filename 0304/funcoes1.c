#include <stdio.h>

int sucessor(int a){
    int b = a + 1;      //passagem de parâmetro por valor
    return b;
}

void msg(int x){
    printf("%d\n", x);
}

int main(){
    int m, n, p;
    m = 5;
    n = sucessor(m);
    p =  sucessor(15);
    msg(p);
    return 0; 
}