#include <stdio.h>

union exemplo{
    char c[2];      //vetor para 2 caracteres: 2B
    short int i;    //short int: 2B: -32768 -> 3276
};

int main(){
    union exemplo u;
    printf("tamanho da union: %d\n", sizeof(u));
    u.i = 1545;
    printf("campo x da union: %d\n", u.i);
    printf("campo c[0] da union: %d\n", u.c[0]);
    printf("campo c[1] da union: %d\n", u.c[1]);

    u.c[0] = 'a';
    u.c[1] = 'b';
    printf("campo c[0] da union: %d\n", u.c[0]);
    printf("campo c[1] da union: %d\n", u.c[1]);
    printf("campo x da union: %d\n", u.i);

    return 0;
}