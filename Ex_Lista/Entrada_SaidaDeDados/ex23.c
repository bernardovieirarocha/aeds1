#include <stdio.h>

#define R 0.082 // sem ;

int main(void) {
	float pressao;
	float n_mols;
	float temp;
	float volume;
	
	printf("Bem vindo ao programa de calculo da pressao de uma gas!\n");
	printf("Digite os valores do volume, numero de mols e temperatura(em Kelvin): ");
	scanf(" %f %f %f",&volume,&n_mols,&temp);
	
	pressao = (n_mols * R * temp) / volume;
	
	printf("O valor da pressao desse gas eh: %.2f", pressao);
	
	return 0;
}