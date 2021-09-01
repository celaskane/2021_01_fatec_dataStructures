#include "no.h"

typedef struct {
    t_no * primeiro;
    t_no * ultimo;
    int tamanho;
} t_lista;

void inicia_lista (t_lista *);
int esta_vazia (t_lista *);
void insere_inicio (t_lista *, int);
int remove_inicio (t_lista *);
void exibe_lista (char *, t_lista *);
void insere_fim (t_lista *, int );
int remove_fim (t_lista *);
int getPrimeiro(t_lista *);
int getUltimo(t_lista *);
int getTamanho(t_lista *);
void insere_pos_definida(t_lista *, int, int);
int remove_pos_definida(t_lista *, int);
int busca_elemento(t_lista *, int);
int remove_elemento_definido(t_lista *, int );