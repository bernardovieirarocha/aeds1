#include <stdio.h>

int letraA(int valor_inicio_indice, int valor_parada_indice) {
  int resultado_produtorio = 1;
  int i;
  for (i = valor_inicio_indice; i <= valor_parada_indice; i++) {
    resultado_produtorio *=
        i / (i + 1); // como inserir a formula diferente de simplesmente de
                     // acordo com a vontade do usuario
  };
  return resultado_produtorio;
}

int letraB(int valor_inicio_indice, int valor_parada_indice) {
  int resultado_produtorio = 1;
  int i;
  for (i = valor_inicio_indice; i <= valor_parada_indice; i++) {
    resultado_produtorio *= i;
  };
  return resultado_produtorio;
}
int letraC(int valor_inicio_indice, int valor_parada_indice) {
  int resultado_somatorio = 0;
  int i;
  for (i = valor_inicio_indice; i <= valor_parada_indice; i++) {
    resultado_somatorio +=
        i + 1; // como inserir a formula diferente de simplesmente i
  };
  return resultado_somatorio;
}
int main() {
  char escolha;
  printf("Digite (a-d) para calcular o problema de cada alternativa: ");
  scanf("%c", &escolha);
  switch (escolha) {
  case 'a':
    printf("Resultado é: %d\n", letraA(0, 5));
    break;
  case 'b':
    printf("Resultado é: %d\n", letraB(1, 7));
    break;
  case 'c':
    printf("Resultado é: %d\n", letraC(4, 17));
    break;
  default:
    printf("Essa opção não existe! \n");
    break;
  }

  return 0;
}