// Uma loja de brinquedos vende bolas compostas de duas cores dentre branco,
// amarelo e azul. Crie um programa em Portugol ou C que receba, através da
// entrada de usuário, as cores que compõem uma bola e imprima “true” caso essa
// bola tenha as cores azul e branco. Caso contrário, imprima "false".
#include <stdio.h>
#include <string.h>

int main(void) {
  char cor1[10];
  char cor2[10];
  printf("Escreva as cores das duas bolas: ");
  scanf("%s %s", cor1, cor2);
  int teste1_azul = !strcmp(cor1, "azul");
  int teste1_branco = !strcmp(cor2, "branco");
  int teste2_azul = !strcmp(cor1, "branco");
  int teste2_branco = !strcmp(cor2, "azul");

  if (teste1_azul == 0 && teste1_branco == 0 ||
      teste2_azul == 0 && teste2_branco == 0) {
    printf("true");
  } else {
    printf("false");
  }

  return 0;
}