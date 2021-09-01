#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void gera_vetor (int *, int);
void mostra_vetor (char *, int *, int);
void bubble_sort (int *, int);
int busca_simples (int, int *, int);
//devolve a primeira posição do elemento ou -1 se não encontrar
//os parâmetros: o elemento procurado, o vetor e o tamanho dele
int busca_binaria (int, int *, int);

int main () {
    int *v, n;
    char continua;
    int ini, fim, x, pos;
    do {
        printf ("digite o tamanho do vetor: ");
        scanf ("%d", &n);
        v = (int *) malloc (n * sizeof(int));
        if (v != NULL) {
            gera_vetor (v, n);
            //mostra_vetor ("vetor original", v, n);
            printf ("digite o valor para busca: ");
            scanf ("%d", &x);
            pos = busca_simples(x, v, n);
            if (pos==-1)
                printf("\nvalor nao encontrado pela busca simples\n");
            else
                printf("\nvalor encontrado pela busca simples na posicao %d\n", pos);
            ini = time(0);
            bubble_sort (v, n);
            fim = time(0);
            printf ("\ntempo de ordenacao para n = %d: %d\n", n, fim-ini);
            //mostra_vetor ("vetor ordenado", v, n);
            pos = busca_binaria(x, v, n);
            if (pos==-1)
                printf("\nvalor nao encontrado pela busca binaria\n");
            else
                printf("\nvalor encontrado pela busca binaria na posicao %d\n", pos);
            free(v);
            v=NULL;
        }
        else
            printf ("falha na alocacao de memoria!\n");
        printf ("\nDeseja executar novamente? (s/n)");
        scanf (" %c", &continua);
        //o espaço antes do %c ou %s é um consumidor de caracteres de separação (espaço ou enter)
        system ("cls");
    } while (continua == 's' || continua == 'S');

    return 0;
}

void gera_vetor (int * v, int n) {
    int i;
    srand(time(0));
    for (i=0; i<n; i++) {
        v[i] = rand(); //0 a 32767
    }
}
void mostra_vetor (char * msg, int * v, int n) {
    int i;
    printf ("\n%s\n", msg);
    for (i=0; i<n; i++) {
        printf ("%d ", v[i]);
    }
    printf ("\n");
}
void bubble_sort (int * v, int n) {
    int i, j, troca, cont;
    for (i=1; i<n; i++) { // i: número de vezes que a varredura do vetor é realizada
        for (j=0; j<n-i; j++) {
            cont=0;
            if (v[j] > v[j+1]) {
                troca = v[j];
                v[j] = v[j+1];
                v[j+1] = troca;
                cont++;
            }
        }
        if (cont==0)
            i=n;
    }
}
int busca_simples (int x, int *v, int n) {
    int i, cont=0;
    for (i=0; i<n; i++) {
        cont++;
        if (v[i] == x) {
            printf ("contador busca simples = %d\n", cont);
            return i;
        }
    }
    printf ("contador busca simples = %d\n", cont);
    return -1;
}
int busca_binaria (int x, int * v, int n) {
    int ini=0, fim=n-1, meio, cont=0;
    while (ini <= fim) {
        cont++;
        meio = (ini + fim) / 2;
        if (x == v[meio]) {
            printf ("contador busca binaria = %d\n", cont);
            return meio;
        }
        if (x > v[meio])
            ini = meio + 1;
        else 
            fim = meio - 1;
    }
    printf ("contador busca binaria = %d\n", cont);
    return -1;
}