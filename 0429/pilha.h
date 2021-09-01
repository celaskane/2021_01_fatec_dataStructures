typedef struct{
    int * dados;
    int topo;
    int capacidade;
} pilha;

void constroi_pilha(pilha *, int);
void empilha(int, pilha);
int desempilha(pilha);
int tamanho(pilha);
int esta_vazia(pilha);
int esta_cheia(pilha);