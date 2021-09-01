#include <stdio.h>
struct modelo{  //tag da struct
    short i;
    float f;
    char c;
};

void exibe_struct(struct modelo);
void altera_struct(struct modelo);

int main(){
    struct modelo s;
    s.i = 10;
    s.f = 2.5;
    s.c = ',';
    exibe_struct(s);
    altera_struct(s);
    exibe_struct(s);
    return 0;
}

void exibe_struct(struct modelo s){
    printf("short: %d\n", s.i);
    printf("float: %f\n", s.f);
    printf("char: %c\n", s.c);
}

void altera_struct(struct modelo s){
    s.i = 0;
    s.f = 0;
    s.c = '-';
}