// Faça um programa que leia um número n fornecido pelo usuário e, em seguida,
// mostre os n primeiros números da sequência de fibonnacci. ATENÇÃO! A solução
// deve ser obtida por meio de recursão.

#include <stdio.h>

void fibonacio(long long int n, long long int i, long long int j,
               int contador) {
  // Condição de parada da recursão na qual o contador é igual a n
  if (contador == n) {
    return;
  }
  // Calcula o próximo número da sequência de fibonacci
  long long int fib = i + j;
  // Atualiza os valores de i e j para o próximo cálculo
  i = j;
  j = fib;
  printf("%lld ", fib);
  // Chama a função recursiva para calcular o próximo número da sequência
  return fibonacio(n, i, j, contador + 1);
}

int main(void) {
  long long int n;
  scanf("%lld", &n);

  if (n <= 95) {
    // Imprime os dois primeiros números da sequência de fibonacci
    printf("0 1 ");
    // Chama a função recursiva para imprimir os próximos n - 2 números ao
    // considerar os dois primeiros ja impressos
    fibonacio(n - 2, 0, 1, 0);
  } else {
    printf("Você excedeu o limite do tipo (long long int) em C \n");
  }
  return 0;
}