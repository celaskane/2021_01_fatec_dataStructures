#include "no.h"

int main(){
    t_no *no1 = cria_no(5);

    t_no no2;
    no2.dado = 7;
    no2.proximo = NULL;

    no1->proximo = &no2;
    no2.proximo = no1;

    printf("%d\n", no1->proximo->dado);
    printf("%d\n", no2.proximo->dado);

    return 0;
}