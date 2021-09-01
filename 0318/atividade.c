#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void gera_vetor(int *, int);
void mostra_vetor(char *, int *, int);
void bubble_sort(int *, int);
void insertion_sort(int *, int);
void selection_sort(int *, int);

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
            //mostra_vetor("vetor original", v, n);
            ini = time(0);
            selection_sort(v, n);
            fim = time(0);
            printf("\ntempo de ordenacao para n = %d: %d\n", n, fim-ini);
            //mostra_vetor("vetor ordenado", v, n);
            free(v);
            v = NULL; 
        }
        else{
            printf("falha na alocacao de memoria!\n");
        }
        printf("\nDeseja executar novamente? (s/n)\n");
        scanf(" %c", &continua);
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
    for(i=1; i<n; i++){
        for(j=0; j<n-i; j++){
            if(v[j] > v[j+1]){
                troca = v[j];
                v[j] = v[j+1];
                v[j+1] = troca;
            }
        }
    }
}

void insertion_sort(int * v, int n){
    int i, j, x;
    for(j=1; j<n; j++){
        x = v[j];
        for(i = j-1; i >= 0 && v[i] > x; i--){
            v[i+1] = v[i];
        }
        v[i+1] = x;
    }
}

void selection_sort(int * v, int n){
    int i, j, x;
    for(i=0; i<n-1; i++){
        int min = i;
        for(j=i+1; j<n; j++){
            if(v[j] < v[min]){
                min = j;
            }
        }
        x = v[i];
        v[i] = v[min];
        v[min] = x;
    }
}