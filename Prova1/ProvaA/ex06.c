// Escreva um algoritmo que leia um número inteiro positivo fornecido pelo usuário e mostre todos os
// números menores do que ele e são, simultaneamente, múltiplos de 2, 3, e 5 . ATENÇÃO! Não é permitido
// o uso de comandos e operadores estritamente condicionais, nem o operador de resto %.
#include <stdio.h>


int main(void){
	
	int n ;
	scanf("%d%*c", &n);

  // loop que começa no primeiro múltiplo simultaneo de 2 3 e 5 e vai de 30 em 30 de todos os números menor que ele.
  for(int i = 30; i < n; i+=30) {
    printf("%d ", i);
  }
  
	return 0;
}