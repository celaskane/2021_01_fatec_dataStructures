#include <stdio.h>
#include <stdlib.h>

int main(){
	//int v[1000000];
	int * v = (int *) malloc(1000000 * sizeof(int));
	if(v != NULL){
		printf("Memoria alocada com sucesso.\n");
		printf("v = %p\n", v);
	}
	else{
		printf("Falha na alocacao.\n");
	}

	return 0;
}