// Este programa em C verifica se uma string fornecida é um palíndromo. Um
// palíndromo é uma palavra, frase, número ou outra sequência de caracteres que
// pode ser lida da mesma forma de trás para frente, ignorando espaços,
// pontuação e capitalização.

#include <stdio.h>

void funcao(char *v, int n, int *i, int *j) {
  if ((*i) > -1 && (*j) < n && *(v + (--(*i))) == *(v + (++(*j)))) {
    return funcao(v, n, i, j);
  }
}
// A função main começa inicializando as variáveis i, j e n com o valor 0, e um
// array de caracteres s de tamanho 100 com o caractere nulo.
int main() {
  int i = 0, j = 0, n = 0;
  char s[100] = "\0";

  // Input string
  scanf("%s", s);

  // O comprimento da string é calculado incrementando n até que o caractere
  // nulo seja encontrado.
  while (s[++n] != '\0') {
  }
  // i e j são configurados para apontar para o meio da string. Se o comprimento
  // da string for ímpar, i e j apontam para o mesmo caractere. Se o comprimento
  // for par, j aponta para o caractere anterior a i.

  i = n / 2 + 1;
  j = i - 2;

  if ((n - 1) % 2 != 0) {
    ++j;
    i--;
  }
  // A função funcao é chamada com s, n, i e j. Esta função verifica se os
  // caracteres nas posições i e j são os mesmos. Se forem, ela decrementa i e
  // incrementa j, e se chama recursivamente. Isso continua até que i seja menor
  // que 0 ou j seja maior ou igual a n, ou que os caracteres nas posições i e j
  // não sejam os mesmos.
  funcao(s, n, &i, &j);

  // Após a função funcao retornar, a função main verifica se i é menor que 0 e
  // j é igual a n. Se ambas as condições forem verdadeiras, ela imprime :),
  // indicando que a string é um palíndromo. Caso contrário, ela imprime :(,
  // indicando que a string não é um palíndromo.

  if (i < 0 && j == n) {
    printf(":)\n");
  } else {
    printf(":(\n");
  }

  return 0;
}
