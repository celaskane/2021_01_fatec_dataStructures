#include <stdio.h>

int main(){
    long int l;
    double d;
    unsigned long int u;
    printf("Tamanho em memoria de um longint: %d bytes\n", sizeof(l));
    printf("Tamanho em memoria de um double: %d bytes\n", sizeof(d));
    printf("Tamanho em memoria de um unsigned long int: %d bytes\n", sizeof(u));
    return 0;
}