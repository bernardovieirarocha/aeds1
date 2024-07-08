#include <stdio.h>

int main(void) {
  int num, cubo;
  scanf("%d", &num);

  int acc = 2; // comeca com dois pois qualquer numero acima de 2 vai ter so ele

  // loop de todos os numeros menores do q ele ate o 3
  // 10 -> 9876543
  for (int i = num - 1; i > 2; --i) {
    int prox_div = i;

    // dividir i por todos os divisores menores do q ele ate achar um divisor
    do {
      prox_div--; // começa retirando ele mesmo e depois continua fazendo com os
                  // proximos
    } while (i > 1 && i % prox_div != 0);

    if (prox_div == 1) {
      acc += i;
    }
  }

  cubo = acc * acc * acc;

  printf("%d\n", cubo);

  return 0;
}