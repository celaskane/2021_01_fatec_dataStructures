#include <stdio.h>

int main(){
    int i;
    int *p;
    i = 10;
    p = &i;
    *p = 27;
    printf("%d\n", i);
    return 0;
}