#include <stdio.h>

int main(void) {
  int diametro_impar;
  scanf("%d%*c", &diametro_impar);

  if (diametro_impar % 2 != 0) {
    // Desenhar o circulo a partir da origem 0,0
    // (x - xc)^2 + (y-yc)^2 = Rˆ2
    // (x - 0)^2 + (y - 0)^2 = Rˆ2
    // x^2 + y^2 <= Rˆ2  menor igual para preencher e criar um disco.
    for (int i = -diametro_impar / 2; i <= diametro_impar / 2; ++i) {
      for (int j = -diametro_impar / 2; j <= diametro_impar / 2; ++j) {
        if (i * i + j * j <= (diametro_impar / 2) * (diametro_impar / 2)) {
          printf("*");
        } else {
          printf(" ");
        }
      }
      printf("\n");
    }
  }

  return 0;
}