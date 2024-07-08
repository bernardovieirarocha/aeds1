// Faça um programa que leia uma matriz NxM de caracteres e imprima 'SIM' "NAO"
// dada a existencia das palavras AEDS, RECURSAO, PONTEIRO. ATENÇÃO! Uma palavra
// pode ser escrita de trás pra frente e em todas as direçååååå

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void lerMatriz(char *matriz, int l, int c, int i) {
  if (i == l * c) {
    return;
  }
  scanf("%c%*c", matriz + i);
  return lerMatriz(matriz, l, c, i + 1);
}

void imprimirMatriz(char *matriz, int l, int c, int i) {
  if (i == l * c) {
    return;
  }
  printf("%c ", *(matriz + i));
  if ((i + 1) % c == 0) {
    printf("\n");
  }
  return imprimirMatriz(matriz, l, c, i + 1);
}

bool testePalavraRecursiva(char *matriz, int l, int c, int i, int j,
                           int contador, bool res, char *palavra,
                           int tamPalavra) {

  if (contador > tamPalavra) {
    return res;
  }
  char *posLetraAchada = matriz + (i * c) + j;
  if (*(posLetraAchada - (c * contador)) == *(palavra + (contador))) {

    res = true;
  } else {
    res = false;
  }
  // testar pra baixo
  if (*(posLetraAchada + (c * contador)) == *(palavra + (contador))) {
    res = true;
  } else {
    res = false;
  }

  // teste pra direita
  if (*(posLetraAchada + contador) == *(palavra + (contador))) {

    res = true;
  } else {
    res = false;
  }
  // teste pra esquerda
  if (*(posLetraAchada - contador) == *(palavra + (contador))) {

    res = true;
  } else {
    res = false;
  }
  return testePalavraRecursiva(matriz, l, c, i, j, contador + 1, res, palavra,
                               tamPalavra);
}
bool procurarPrimeiraLetra(char *matriz, int l, int c, int i, int j,
                           char *palavra) {
  if (i < l) {
    if (j < c) {
      if (*(matriz + (i * c) + j) == palavra[0]) {
        // printf("Achei letra tal: %c na pos: %d %d\n", *(matriz + (i * c) +
        // j),
        //        i, j);
        return testePalavraRecursiva(matriz, l, c, i, j, 1, false, palavra,
                                     strlen(palavra));
      }
      return procurarPrimeiraLetra(matriz, l, c, i, j + 1, palavra);
    } else {
      return procurarPrimeiraLetra(matriz, l, c, i + 1, 0, palavra);
    }
  }
}

int main(void) {
  int l, c;
  scanf("%d%*c %d%*c", &l, &c);

  char *aeds = "AEDS";
  char *ponteiro = "PONTEIRO";
  char *recursao = "RECURSAO";

  char *matriz = malloc(l * c * sizeof(char));
  lerMatriz(matriz, l, c, 0);
  imprimirMatriz(matriz, l, c, 0);

  if (procurarPrimeiraLetra(matriz, l, c, 0, 0, aeds) &&
      procurarPrimeiraLetra(matriz, l, c, 0, 0, ponteiro) &&
      procurarPrimeiraLetra(matriz, l, c, 0, 0, recursao)) {
    printf("SIM\n");
  } else {
    printf("NAO\n");
  }

  return 0;
}
