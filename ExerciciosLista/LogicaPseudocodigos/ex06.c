#include <stdio.h>

int somatorio(int valor_inicio_indice, int valor_parada_indice) {
  int resultado_somatorio = 0;
  int i;
  for (i = valor_inicio_indice; i <= valor_parada_indice; i++) {
    resultado_somatorio +=
        i + 1; // como inserir a formula diferente de simplesmente i
  };
  return resultado_somatorio;
}

int produtorio(int valor_inicio_indice, int valor_parada_indice) {
  int resultado_produtorio = 1;
  int i;
  for (i = valor_inicio_indice; i <= valor_parada_indice; i++) {
    resultado_produtorio *=
        i; // como inserir a formula diferente de simplesmente i
  };
  return resultado_produtorio;
}

int main() {
  int escolha;
  int valor_inicio_indice;
  int valor_parada_indice;
  printf("Digite 0 para SOMATÓRIO e digite 1 para PRODUTÓRIO: ");
  scanf("%d", &escolha);
  printf("Digite o valor de início do índice: ");
  scanf("%d", &valor_inicio_indice);
  printf("Digite o valor de parada do índice: ");
  scanf("%d", &valor_parada_indice);
  if (escolha == 0) {
    printf("Resultado do Somatório é: %d\n",
           somatorio(valor_inicio_indice, valor_parada_indice));
  } else if (escolha == 1) {
    printf("Resultado do Produtório é: %d\n",
           produtorio(valor_inicio_indice, valor_parada_indice));
  }

  return 0;
}
