#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

int tamanhoString(char *string, int contador) {
  if (*((string + contador)) == '\0') {
    return contador;
  }
  return tamanhoString(string, contador + 1);
}

bool iguaisReversa(char *string1, char *string2, bool resp, int contador1,
                   int contador2, int tam1, int tam2) {
  if (contador1 > tam1 || contador2 < 0) {
    return resp;
  }
  if (string1[contador1] != string2[contador2] || tam1 != tam2) {
    resp = false;
  }
  return iguaisReversa(string1, string2, resp, contador1 + 1, contador2 - 1,
                       tam1, tam2);
}

int main(void) {
  char *string1 = malloc(1024 * sizeof(char));
  char *string2 = malloc(1024 * sizeof(char));

  scanf("%s", string1);
  scanf("%s", string2);
  bool resp;
  int tamS1 = tamanhoString(string1, 0);
  int tamS2 = tamanhoString(string2, 0);

  resp = iguaisReversa(string1, string2, true, 0, tamS2 - 1, tamS1, tamS2);

  printf("%s\n", resp ? "Sao iguais" : "NAO sao iguais");
  printf("%s | %s \n", string1, string2);

  return 0;
}