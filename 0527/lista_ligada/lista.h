#include "no.h"

typedef struct{
    t_no * primeiro;
} t_lista;

void inicia_lista(t_lista *);
int esta_vazia(t_lista *);
void insere_inicio(t_lista *, int);