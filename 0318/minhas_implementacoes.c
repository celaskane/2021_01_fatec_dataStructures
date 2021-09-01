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

int busca_simples(int x, int * v, int n){
    int i, cont=0;
    for(i=0; i<n; i++){
        cont++;
        if(v[i] == x){
            printf("contador busca simples = %d\n", cont);
            return i;
        }
    }
    printf("contador busca simples = %d\n", cont);
    return -1;
}

int busca_binaria(int x, int * v, int n){
    int ini=0, fim = n-1, meio, cont=0;
    while (ini <= fim){
        cont++;
        meio = (ini + fim)/2;
        if(x == v[meio]){
            printf("contador busca simples = %d\n", cont);
            return meio;
        }
        if(x > v[meio])
            ini = meio + 1;
        else
            fim = meio - 1;
    }
    printf("contador busca simples = %d\n", cont);
    return -1;
}