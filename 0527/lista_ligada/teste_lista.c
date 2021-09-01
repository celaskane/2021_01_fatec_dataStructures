#include "lista.h"

int main(){
    t_lista lista;
    inicia_lista(&lista);
    insere_inicio(&lista, 5);
    insere_inicio(&lista, 8);
    insere_inicio(&lista, 13);
    return 0;
}