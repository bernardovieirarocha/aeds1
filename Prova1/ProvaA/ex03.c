// Escreva um algoritmo que leia um número positivo do usuário, verifique se este é um número
// primo (i.e., divisível por ele mesmo e por 1), e em seguida imprima a resposta de acordo

#include <stdio.h>

int main(void){
	
	int n, ehPrimo=1;
	
	scanf("%d%*c", &n);
	
	// Código de Loop otimizado que dá um flag se encontra algum divisor.
	for (int i = 2 ; i <= n/2 ; ++i){ // Retira do loop o 1 que divide todo número e ele mesmo.
		if (n % i == 0 ){
			ehPrimo = 0;
		} 
	}
	
	// Verifica se se o número não foi considerado divisível por nenhum número entre 2 e n/2 e se n não é igual a 1 ou 0.
	if(ehPrimo && n != 1 && n != 0){
		printf("O numero %d eh primo", n);
	} else {
		printf("O numero %d NAO eh primo", n);
		
	}
	
	return 0;
}

