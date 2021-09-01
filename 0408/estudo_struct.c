#include <stdio.h>

struct modelo{
    short i;
    float f;
    char c;
};

typedef struct {
    int i;
    float f;
    char c;
} minha_struct;

int main(){
    struct modelo variavel1;
    minha_struct variavel2;

    printf("tamanho do short: %d\n", sizeof(short));
    printf("tamanho do inteiro: %d\n", sizeof(int));
    printf("tamanho do float: %d\n", sizeof(float));
    printf("tamanho do char: %d\n", sizeof(char));

    printf("tamanho da struct modelo: %d\n", sizeof(struct modelo));
    printf("tamanho da minha_struct: %d\n", sizeof(minha_struct));
    return 0;
}