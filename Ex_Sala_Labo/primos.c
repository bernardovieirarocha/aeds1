#include <stdio.h>

int main() {
  int num, acc = 0, is_prime;
  printf("Digite um número inteiro positivo (digite 0 para sair): ");
  scanf("%d", &num);

  while (num != 0) {
    is_prime = 1; // Assumimos inicialmente que num é primo
    for (int i = 2; i * i <= num; i++) {
      if (num % i == 0) {
        is_prime = 0; // Se num for divisível por i, não é primo
        break;
      }
    }

    if (is_prime && num != 1) {
      acc += num; // Se num for primo, adiciona ao acumulador
    }

    printf("A soma parcial se encontra em: %d\n", acc);
    printf("Digite outro número inteiro positivo (digite 0 para sair): ");
    scanf("%d", &num);
  }

  printf("A soma dos números primos é: %d", acc);
  return 0;
}
