// Crie um programa em Portugol e em C que receba, através da entrada do
// usuário, um número inteiro e um número decimal e, então, faça a soma dos
// dois, de modo a imprimir um resultado como inteiro.

#include <math.h>
#include <stdio.h>

int main(void) {
  int numero_inteiro;
  float numero_decimal;
  scanf("%d %f", &numero_inteiro, &numero_decimal);
  int soma = ceil(numero_decimal + numero_inteiro);
  printf("%d", soma);
}