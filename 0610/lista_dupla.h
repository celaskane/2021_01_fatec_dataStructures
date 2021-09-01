#include <stdio.h>
#include "no_duplo.h"

typedef struct {
    int tamanho;
    t_no_duplo * primeiro;
} t_lista_dupla;

t_lista_dupla * constroi_lista_dupla();

int esta_vazia(t_lista_dupla *);

void insere_inicio(int, t_lista_dupla *);
void insere_fim(int, t_lista_dupla *);

int remove_inicio(t_lista_dupla *);
int remove_fim(t_lista_dupla *);

void exibe_lista_dupla(char *, t_lista_dupla *);