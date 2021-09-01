#include <stdio.h>

struct modelo{
    short i;
    float f;
    char c;
};

void exibe_struct(const char *, struct modelo);
void exibe_struct_vetor(const char *, int, struct modelo);

int main(){
    struct modelo s;
    int i;
    struct modelo v[5];
    s.i = 10;
    s.f = 2.5;
    s.c = ',';
    exibe_struct("struct s", s);
    for(i=0; i<5; i++){
        v[i] = s;
        exibe_struct_vetor("estrutura na posicao ", i, v[i]);
    }
    return 0;
}

void exibe_struct (const char * msg, struct modelo s){
    printf("%s\nshort: %i\nfloat: %f\nchar: %c\n", msg, s.i, s.f, s.c);
}

void exibe_struct_vetor(const char * msg, int i, struct modelo s){
    printf("%s %d\nshort: %i\nfloat: %f\nchar: %c\n", msg, i, s.i, s.f, s.c);    
}