#include <stdio.h>
#include <math.h>

int main(void) {

  int soma = 0;
  int base;
  int exponente;

  // Loop para iterar pelos expoentes
  for (exponente = 20; exponente >= 1; exponente--) {
    // Loop para iterar pelas bases
    for (base = 1; base <= 20; base++) {
      int resultado = pow(base, exponente);
      soma += resultado;
    }
  }

  // Exibir o resultado da soma
  printf("O resultado da soma é: %d\n", soma);

  return 0;
}
