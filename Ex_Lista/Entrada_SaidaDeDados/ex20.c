#include <stdio.h>
#include <math.h>


int main(void) {
	
	char letraopt;
	float lado = 0;
	float res = 0;
	float base, altura;
	float raio;
	float base_maior, base_menor;
	
	printf("Escolha a opcao que deseja calcular (a-d): ");
	scanf(" %c%*c",&letraopt);
	
	while (letraopt != 's' ) {
		switch (letraopt) {
			case 'a':
				lado = 0;
				printf("Digite o valor do lado do quadrado: ");	
				scanf(" %f%*c", &lado);
				res = lado * lado;
				printf("A area do quadrado eh: %2.f", res);	
				break;
			case 'b':
				printf("Digite o valor da base e da altura: ");	
				scanf(" %f %f%*c", &base, &altura);
				res = (base * altura) / 2;
				printf("A area do triangulo eh: %2.f", res);
				break;
			case 'c':
				printf("Digite o valor do raio: ");
				scanf(" %f%*c", &raio);
				res = M_PI * pow(raio, 2);
				printf("A area do circulo eh: %2.f", res);	
				break;
		
			case 'd':
				printf("Digite o valor da base maior, da base menor e da altura: ");
				scanf(" %f %f %f%*c", &base_maior, &base_menor, &altura);
				res = ((base_maior + base_menor) * altura )/2;
				printf("A area do trapezio eh: %2.f", res);	
				break;
			default:
				printf("Essa opcao nao existe!\n");
		
		
		}
		printf("\nEscolha a opcao que deseja calcular (a-d): ");
		scanf(" %c%*c",&letraopt);
	}
	
	
	
	return 0;	
}