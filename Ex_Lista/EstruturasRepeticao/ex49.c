//Crie um programa em C que receba um número inteiro de 1 a 10 e, então, imprima sua tabuada na tela. Utilize estruturas de repetição.
#include <stdio.h>


int main(void){
	
	int num;
	scanf("%d",&num);
	
	if (num >= 1 && num <= 10) {
		
		for (int i = 1; i <= 10; ++i){
			
			printf("%d * %d = %d\n", num, i, num*i);
			
		}
		
	}
	
	
	return 1;
}