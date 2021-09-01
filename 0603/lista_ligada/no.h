#include <stdio.h>
#include <stdlib.h>

typedef struct no{
    int dado;
    struct no * proximo;
} t_no;

t_no * cria_no(int);