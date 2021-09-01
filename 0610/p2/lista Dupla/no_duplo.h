#include <stdlib.h>

typedef struct no_duplo{
    int dado;
    struct no_duplo * proximo;
    struct no_duplo * anterior; 
} t_no_duplo;

t_no_duplo * constroi_no(int);