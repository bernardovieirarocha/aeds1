#include <stdio.h>

int letraA(int valor_inicio_indice, int valor_parada_indice) {
  int resultado_somatorio = 0;
  int i;
  for (i = valor_inicio_indice; i <= valor_parada_indice; i++) {
    resultado_somatorio +=
        i; // como inserir a formula diferente de simplesmente i
  };
  return resultado_somatorio;
}

int letraB(int valor_inicio_indice, int valor_parada_indice) {
  int resultado_somatorio = 0;
  int i;
  for (i = valor_inicio_indice; i <= valor_parada_indice; i++) {
    resultado_somatorio +=
        i + 1; // como inserir a formula diferente de simplesmente i
  };
  return resultado_somatorio;
}
int letraC(int valor_inicio_indice, int valor_parada_indice) {
  int resultado_produtorio = 1;
  int i;
  for (i = valor_inicio_indice; i <= valor_parada_indice; i++) {
    resultado_produtorio *=
        i; // como inserir a formula diferente de simplesmente i
  };
  return resultado_produtorio;
}
int letraD(int valor_inicio_indice, int valor_parada_indice) {
  int resultado_produtorio = 1;
  int i;
  for (i = valor_inicio_indice; i <= valor_parada_indice; i++) {
    resultado_produtorio *=
        i; // como inserir a formula diferente de simplesmente i
  };
  return resultado_produtorio;
}
int main() {
  char escolha;
  printf("Digite (a-d) para calcular o problema de cada alternativa: ");
  scanf("%c", &escolha);
  switch (escolha) {
  case 'a':
    printf("Resultado é: %d\n", letraA(1, 10));
    break;
  case 'b':
    printf("Resultado é: %d\n", letraB(0, 10));
    break;
  case 'c':
    printf("Resultado é: %d\n", letraC(0, 15));
    break;
  case 'd':
    printf("Resultado é: %d\n", letraD(1, 10));
    break;
  default:
    break;
  }

  return 0;
}