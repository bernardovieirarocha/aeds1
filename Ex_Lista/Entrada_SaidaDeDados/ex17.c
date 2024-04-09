#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int numero_1=0, numero_2=0, aux=0; 
	
    printf("Entre com o primeiro numero:");
	scanf("%d", &numero_1);
	
	
	printf("\nEntre com o segundo numero:");
	scanf("%d", &numero_2);
	
	numero_1 = numero_2;
	numero_2 = aux;
	printf("\nPrimeiro numero: %d // Segundo numero: %d", numero_1, numero_2);

}

// O codigo acima inverte os numeros recebidos, o 1numero se torna o 2numero e vice versa.