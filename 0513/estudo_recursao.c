#include <stdio.h>

int fatorial(int n){
    if(n==0 || n==1)
        return 1;
    return n * fatorial(n-1);
}

int fibonacci(int n){
    if(n==0 || n==1)
        return 1;
    return fibonacci(n-1) + fibonacci(n-2);
}

int main(){
    int i;
    int fat[13], fib[47];
    for(i=0; i<13; i++){
        printf("fatorial de %d = %d\n", i, fatorial(i));
    }
    fat[0] = fat[1] = 1;
    for(i=2; i<13; i++){
        fat[i] = i * fat[i-1];
    }

    for(i=0; i<46; i++){
        printf("fibonacci em %d = %d\n", i, fibonacci(i));
    }
    fib[0] = fib[1] = 1;
    for(i=2; i<46; i++){
        fib[i] = fib[i-1] + fib[i-2];
    }
    return 0;
}