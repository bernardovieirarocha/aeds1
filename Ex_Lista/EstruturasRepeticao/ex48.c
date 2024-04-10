// Elabore um código em C que receba um número inteiro qualquer e imprima todos os números ímpares de 1 até esse número.

#include <stdio.h>

int main(void) {
	
	int num;
	scanf("%d", &num);
	
	for (int i = 0; i <= num ; i++) {
		
		if (i % 2 != 0){
			printf("%d\n", i);
		}
	}
	
	
	return 0;
}