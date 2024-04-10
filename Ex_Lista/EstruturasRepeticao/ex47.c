// Elabore um programa em C que inicialize uma variável inteira com o valor 0
// para, então, incre- mentar seu valor de 5 em 5, até que passe a valer 100.
// Para isso, utilize a estrutura de repetição: a) for; b) while; c) do while.
#include <stdio.h>

int main(void) {

	for (int i = 0; i <=100; i+=5) {
		printf("%d\n", i);
	}

	printf("\n\n");

	int j = 0;
	while( j <= 100 ){
		printf("%d\n", j);
		j += 5;
	}

	printf("\n\n");
	
	int k = 0;
	do {
		printf("%d\n", k);
		k += 5;
	} while(k <= 100);
	
	
}