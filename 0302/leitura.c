#include <stdio.h>

int main(){
    int i, s=0;
    scanf("%d", &i);
    while (i != 0){
        s = s + i;
    }
    printf("\n soma = %d\n", s);
    return 0;
}