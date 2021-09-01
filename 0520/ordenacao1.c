#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void gera_vetor(int *, int);
void mostra_vetor(char *, int *, int);
void bubble_sort(int *, int);

int partition(int *, int, int);
void quick(int *, int, int);

int main(){
    int *v, n;
    char continua;
    int ini, fim;
    do{
        srand(time(0));
        printf("Digite o tamanho do vetor: ");
        scanf("%d", &n);
        v = (int *) malloc (n * sizeof(int));
        if(v != NULL){
            gera_vetor(v, n);
            /*mostra_vetor("primeiro vetor", v, n);
            ini = time(0);
            bubble_sort(v, n);
            fim = time(0);
            printf("\ntempo de ordenacao para n = %d do Bubble: %d\n", n, fim-ini);
            mostra_vetor("vetor ordenado pelo Bubble: ", v, n);*/

            gera_vetor(v, n);
            //mostra_vetor("segundo vetor", v, n);
            ini = time(0);
            quick(v, 0, n-1);
            fim = time(0);
            printf("\ntempo de ordenacao para n = %d do Quick: %d\n", n, fim-ini);
            //mostra_vetor("vetor ordenado pelo Quick: ", v, n);

            free(v);
            v = NULL;
        }
        else{
            printf("falha na alocacao de memoria!\n");
        }
        printf("\nDeseja executar novamente? (s/n)\n");
        scanf(" %c", &continua);    //o espaço antes de %c ou %s é um consumidor de caracteres de sepração
        system("cls");
    } while(continua == 's' || continua == 'S');
    return 0;
}

void gera_vetor(int * v, int n){
    int i;
    srand(time(0));
    for(i=0; i<n; i++){
        v[i] = rand() % (n*10);
    }
}

void mostra_vetor(char * msg, int * v, int n){
    int i;
    printf("\n%s\n", msg);
    for(i=0; i<n; i++){
        printf("%d ", v[i]);
    }
    printf("\n");
}

void bubble_sort(int * v, int n){
    int i, j, troca;
    for(i=1; i<n; i++){         //i é o núemero de vezes que a varredura do vetor é realizada
        for(j=0; j<n-i; j++){
            if(v[j] > v[j+1]){
                troca = v[j];
                v[j] = v[j+1];
                v[j+1] = troca;
            }
        }
    }
}

int partition (int * A, int p, int r) {
    int x = A[r];
    int i, j, aux;
    i = p-1;
    for (j=p; j<r; j++) {
        if(A[j] <= x) {
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

void quick (int * A, int p, int r) {
    int q;
    printf("p = %d, r = %d\n", p, r);
    if (p<r){
        q = partition(A, p, r);
        printf("q = %d\n", q);
        quick (A, p, q-1);
        quick (A, q+1, r);
    }
}