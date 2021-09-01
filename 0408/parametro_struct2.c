#include <stdio.h>
struct modelo{  //tag da struct
    short i;
    float f;
    char c;
};

void exibe_struct(struct modelo);
void altera_struct(struct modelo *);
void soma_um(const int *);
int soma_dois(int);

struct modelo altera_struct2 (struct modelo);

int main(){
    struct modelo s;

    int a = 12, b=20;

    s.i = 10;
    s.f = 2.5;
    s.c = ',';
    exibe_struct(s);
    altera_struct(&s);
    exibe_struct(s);

    soma_um(&a);
    printf("veja o que aconteceu com a: %d\n", a);

    b = soma_dois(b);

    s = altera_struct2(s);
    exibe_struct(s);

    return 0;
}

void exibe_struct(struct modelo s){
    printf("short: %d\n", s.i);
    printf("float: %f\n", s.f);
    printf("char: %c\n", s.c);
}

void altera_struct(struct modelo * s){
    s->i = 0;
    s->f = 0;
    s->c = '-';
}

void soma_um (const int * pi){
    //*pi = *pi + 1;
}

int soma_dois(int i){
    return i+2;
}

struct modelo altera_struct2 (struct modelo s){
    s.i = 5;
    s.f = 0.5;
    s.c = 'a';
    return s;
}