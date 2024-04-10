#include <stdio.h>
int main() {
  int opcao = 0;
  scanf("%d", &opcao);
  switch (opcao) {
  case 1:
    printf("\nvoce digitou 1 e escolheu a primeira opcao.\n");
    break;
  case 2:
    printf("\nvoce digitou 2 e escolheu a segunda opcao.\n");
    break;
  case 7:
    printf("\nvoce digitou 7 e escolheu a terceira opcao.\n");
    break;
  default:
    printf("\nopcao invalida\n");
  }
  return 0;
}

// 7: voce digitou 7 e escolheu a terceira opcao.
// 8: opcao invalida