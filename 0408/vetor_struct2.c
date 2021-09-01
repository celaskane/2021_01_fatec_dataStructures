#include <stdio.h>

struct modelo_plus{
    int v[5];
    float f;
    char c;
};

void exibe_struct_vetor(const char *, struct modelo_plus);

int main(){
    struct modelo_plus s;
    int i;

    printf("tamanho da nova struct = %d\n", sizeof(struct modelo_plus));

    s.c = 'x';
    s.f = 0.3;
    for(i=0; i<5; i++){
        s.v[i] = i + 1;
    }

    exibe_struct_vetor("Funcionou", s);
    return 0;
}

void exibe_struct_vetor(const char * msg, struct modelo_plus s){
    printf("%s\nchar: %c\nfloat: %f\n", msg, s.c, s.f);
    for(int i=0; i<5; i++){
        printf("vetor na posicao %d = %d\n", i, s.v[i]);
    }
}