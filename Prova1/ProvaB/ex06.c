// Escreva um algoritmo que leia um número inteiro positivo fornecido pelo usuário e mostre todos os
// números menores do que ele e são, simultaneamente, múltiplos de 2, 5, e 7 . ATENÇÃO! Não é permitido
// o uso de comandos e operadores estritamente condicionais, nem o operador de resto %.


#include <stdio.h>


int main(void){
	
	int n ;
	scanf("%d%*c", &n);

  // loop que começa no primeiro múltiplo simultaneo de 2 5 e 7 e vai de 70 em 70 de todos os números menor que ele.
  for(int i = 70; i < n; i+=70) {
    printf("%d ", i);
  }
  
	return 0;
}