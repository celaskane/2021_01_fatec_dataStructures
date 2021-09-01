#include <stdio.h>
#include <stdlib.h>

int main(){
	char c;
	int i;
	float f;
	int v1[10], v2[100];
	printf("Neste compilador: \n");
	printf("Tamanho em memoria de um char: %d\n", sizeof(c));
	printf("Tamanho em memoria de um int: %d\n", sizeof(i));
	printf("Tamanho em memoria de um float: %d\n", sizeof(f));
	printf("Tamanho em memoria de v1: %d\n", sizeof(v1));
	printf("Tamanho em memoria de v2: %d\n", sizeof(v2));
	return 0;
}