#include <stdio.h>

int main(){
	int v[10];
	int i;
	for(i=0; i<10; i++)
		printf("%p\n", v+i);	//%p retorna endere�o do ponteiro (hexa)
	return 0;
}
