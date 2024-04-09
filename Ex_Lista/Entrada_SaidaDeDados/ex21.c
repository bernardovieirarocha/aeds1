#include <stdio.h>
#include <math.h>


int main (void) {
	int numero;
	int resto;
	int resultado;
	scanf(" %d", &numero);
	resto = numero % 5;
	resultado = 2 * sqrt(resto);
	printf("O resultado do dobro da raiz do resto da divisão de %d por 5: %d\n", numero, resultado );

	return 0;
}