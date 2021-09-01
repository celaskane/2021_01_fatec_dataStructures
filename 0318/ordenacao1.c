#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void gera_vetor(int *, int);
void mostra_vetor(char *, int *, int);
void bubble_sort(int *, int);
int busca_simples(int, int *, int);
//devolve a primeira posição do elemento ou -1 se não encontrar
//os parâmetros: elemento procurado, o vetor e o tamanho dele
int busca_binaria(int, int *, int);

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
            bubble_sort(v, n);
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

int busca_simples(int x, int * v, int n){
    int i;
    for(i=0; i<n; i++){
        if(v[i] == x){
            return i;
        }
    }
    return -1;
}

int busca_binaria(int x, int * v, int n){
    int ini=0, fim = n-1, meio;
    while (ini <= fim){
        meio = (ini + fim)/2;
        if(x == v[meio])
            return meio;
        if(x > v[meio])
            ini = meio + 1;
        else
            fim = meio - 1;
    }
    return -1;
}