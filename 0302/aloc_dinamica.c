#include <stdio.h>
#include <stdlib.h>

int main(){
    int * v;        //v é um ponteiro de inteiros
    float * p;      //p é um ponteiro de float
    char * str;     //str é um ponteiro de char
    int v1[4];

    p = (float *) malloc(10 * sizeof(float));
    printf("%p\n", &p);

    v = (int *) malloc(100 * sizeof(int));
    printf("%p\n", &v);

    str = (char *) malloc(40 * sizeof(char));
    printf("%p\n", &str);
    return 0;
}