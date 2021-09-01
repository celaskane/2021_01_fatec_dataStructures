#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void gera_vetor (int *, int);
void mostra_vetor (char *, int *, int);
void bubble_sort (int *, int, long long int *);

int partition (int *, int, int, long long int *);
void quick (int *, int, int, long long int *);

int main () {
    int *v, n;
    char continua;
    int ini, fim;
    long long int contador;
    do {
        printf ("\ndigite o tamanho do vetor: ");
        scanf ("%d", &n);
        v = (int *) malloc (n * sizeof(int));
        if (v != NULL) {
            gera_vetor (v, n);
            //mostra_vetor ("primeiro vetor", v, n);
            contador = 0;
            ini = time(0);
            bubble_sort (v, n, &contador);
            fim = time(0);
            printf("\nNumero de comparacoes no Bubble: %lld", contador);
            printf ("\ntempo de ordenacao do Bubble para n = %d: %ds\n", n, fim-ini);
            //mostra_vetor ("vetor ordenado pelo Bubble", v, n);

            gera_vetor(v, n);
            //mostra_vetor("segundo vetor", v, n);
            contador = 0;
            ini = time(0);
            quick(v, 0, n-1, &contador);
            fim = time(0);
            printf("\nNumero de comparacoes no Quick: %lld", contador);
            printf ("\ntempo de ordenacao do Quick para n = %d: %ds\n", n, fim - ini);
            //mostra_vetor("vetor ordenado pelo Quick", v, n);
            
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
        v[i] = (rand() * rand());
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

void bubble_sort (int * v, int n, long long int * cont) {
    int i, j, troca;
    for (i=1; i<n; i++) { // i: número de vezes que a varredura do vetor é realizada
        for (j=0; j<n-i; j++) {
            *cont = *cont + 1;
            if (v[j] > v[j+1]) {
                troca = v[j];
                v[j] = v[j+1];
                v[j+1] = troca;
            }
        }
    }
}

int partition (int * A, int p, int r, long long int * cont) {
    int x = A[r];
    int i, j, aux;
    i = p-1;
    for (j=p; j<r; j++) {
        *cont = *cont + 1;
        if (A[j] <= x) {
            i++;
            aux = A[i];
            A[i] = A[j];
            A[j] = aux;
        }
    }
    i++;
    aux = A[r];
    A[r] = A[i];
    A[i] = aux;
    return i;
}

void quick (int * A, int p, int r, long long int * cont) {
    int q;
    //printf ("p = %d, r = %d\n", p, r);
    if (p<r) {
        q = partition (A, p, r, cont);
        //printf ("q = %d\n", q);
        quick (A, p, q-1, cont);
        quick (A, q+1, r, cont);
    }
}