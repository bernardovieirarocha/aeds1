// Apresentar os passos necessários para encontrar as raízes de uma
//     equação do segundo grau,
//     caso exista em R.
// ax^2+bx + c

#include <math.h>
#include <stdio.h>

int calcularDelta(float a, float b, float c) {
  int delta = pow(b, 2) - 4 * a * c;
  return delta;
}

int main(void) {
  float a, b, c;
  float raiz1;
  float raiz2;
  printf("Digite o valor de a: ");
  scanf("%f", &a);
  printf("Digite o valor de b: ");
  scanf("%f", &b);
  printf("Digite o valor de c: ");
  scanf("%f", &c);

  printf("Calculando o delta...\n");
  int delta = calcularDelta(a, b, c);
  printf("O Delta é: %d\n", delta);

  if (delta >= 0) { // Possui raízes reais
    printf("Calculando raízes...\n");
    raiz1 = (-b + sqrt(delta)) / (2 * a);
    raiz2 = (-b - sqrt(delta)) /
            (2 * a); // Porque precisa dos paranteses C já opera a ordem certa?
    printf("As raízes são: %.2f e %.2f\n", raiz1, raiz2);
  } else {
    printf("Não existem raízes reais! \n");
  }
  return 0;
}