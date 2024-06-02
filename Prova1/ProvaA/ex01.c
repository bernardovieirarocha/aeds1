// Analise o código abaixo e explique o seu funcionamento indicando, de maneira
// objetiva, qual o cômputo realizado. Justifique sua resposta através das
// linhas de código apresentadas.

#include <stdio.h>
int main(void) {
  int x, y, z, ty, tz, cy, cz;
  scanf("%d%*c", &x);
  y = 5;
  ty = x;
  cy = 0; // Inicializa variáveis para divisão por 5.
  z = 7;
  cz = 0; // Inicializa variáveis para divisão por 7.

  // Loop para determinar o quociente da divisão por 5, ou seja quantas vezes o
  // número inserido é divisível 5.
  while (ty - y >= 0) {
    cy++;
    ty -= y;
  }

  // Loop para determinar o quociente da divisão por 7, ou seja quantas vezes o
  // número inserido é divisível 7.
  for (tz = x; tz > 0; tz -= z) {
    cz++;
  }

  // Verifica se o número inserido é divisível por ambos, 5 e 7.
  if (ty == tz && ty * ty == 0) {
    printf("Y:%d\tZ:%d\n", cy, cz); // Imprime o número de vezes que o número
                                    // inserido é divisível por 5 e 7.
  }
  // Verifica se o número inserido é divisível apenas por 5.
  else if (ty * ty == 0) {
    printf("Y:%d\n", cy); // Imprime o número de vezes que o número inserido é
                          // divisível por 5.
  }
  // Se não for divisível por 5 ou 7, então é divisível apenas por 7.
  else {
    printf("Z:%d\n", cz); // Imprime o número de vezes que o número inserido é
                          // divisível por 7.
  }
  return 0;
}

// Em suma, o código recebe um número inteiro do usuário e verifica se é
// divisível por 5, por 7 ou por ambos, imprimindo o quociente do resultado da
// divisão, isto é  o número de vezes que o número inserido é divisível por cada
// um deles.
