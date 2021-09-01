#include "meu_cabecalho.h" 

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
    for(i=1; i<n; i++){         //i é o número de vezes que a varredura do vetor é realizada
        for(j=0; j<n-i; j++){
            if(v[j] > v[j+1]){
                troca = v[j];
                v[j] = v[j+1];
                v[j+1] = troca;
            }
        }
    }
}

int busca_simples(int x, int * v, int n){
    int i;
    for(i=0; i<n; i++){
        if(v[i] == x){
            return i;
        }
    }
    return -1;
}