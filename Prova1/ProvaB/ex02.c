// Escreva um algoritmo que encontre e mostre o maior e o menor número positivo dentre todos
// aqueles fornecidos pelo usuário. Sabe-se que o usuário fornece 100 números e que nenhum ultrapassa o valor
// 1000.

#include <stdio.h>


int main(void){
	
	int num;
	scanf("%d%*c", &num); // ler o primeiro número do usuário para poder atribuir esse número caso seja positivo ao máximo e o mínimo já vistos.
	
	int maior,menor;
	
	maior = 0; // o maior número começa com o menor possível
	menor = 1000; //o menor número começa com o maior possível

	for (int i = 0 ; i < 10; i++){
		scanf("%d%*c", &num);
		if(num > maior && num > 0  && num <= 1000){ // Reforça as condições de recebimento do número
			maior = num;// Se o número momentaneamente recebido for maior que o maior já visto( OU maior que o mínimo), ele se torna o novo máximo
		}
		if (num < menor && num > 0 ) { // Reforça as condições de recebimento do número
			menor = num; // Se o número momentaneamente recebido for menor que o menor já visto(OU menor que o máximo), ele se torna o novo mínimo.
		}
	}
	
	printf("Maior: %d Menor: %d", maior,menor); // Mostre ao usuário o máximo e o mínimo.
	
	return 0 ;
}