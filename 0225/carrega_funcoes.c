#include <stdio.h>

void f1(int v[], int tamanho){	//void f1(int *v)
	int i;
	for(i=0; i<tamanho; i++){
		printf("%d ", v[i]);
	}
}
void f2(){
	printf("chamada funcao 2\n");
}

int main(){
	int escolha;
	int v1[10];
	int v2[100];
	printf("Digite um inteiro:");
	scanf("%d", &escolha);
	if(escolha % 2){		// escolha % 2 == 1 (par ou impar)
		f1(v1, 10);
		f2(v2, 100);
	}
	else{
		f2();
	}
	
	return 0;
}

