// Escreva um algoritmo que imprima um tabuleiro quadrado de xadrez cujo tamanho do lado é lido
// pelo usuário. Para os quadrados preenchidos, imprima o caractere * e, para os quadrados brancos, imprima
// o espaço em branco. Sabe-se que um tabuleiro sempre inicia com um quadrado branco.

#include <stdio.h> 

int main(void){
	
	int lado;
	scanf( "%d%*c", &lado);
	
	// Loop pela matriz quadrada
	for (int i = 0 ; i < lado ;  ++i){
		for (int j = 0 ; j < lado; ++j){
			if ( i % 2 == 0){ // linha de index par
				if (j % 2 == 0 ){ // Imprime " " nas colunas pares 
					printf(" ");
				} else {
					printf("*"); // Imprime "*" nas colunas ímpares
				}
				
			} else { // linha de índex ímpar
				if (j % 2 != 0 ){  // Imprime " " nas colunas ímpares
					printf(" ");
				} else {
					printf("*"); //  Imprime "*" nas colunas pares
				}
			}
			
			
		}
		printf("\n"); // Próxima Linha
	}
	
	return 0;
}