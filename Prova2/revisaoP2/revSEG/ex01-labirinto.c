#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

int ler_dados(char *matriz, int l, int c, int indice) {
  if (indice == l * c) {
    return 0;
  }
  scanf("%c%*c", matriz + indice);
  return ler_dados(matriz, l, c, indice + 1);
}

void imprimir_labirinto(char *matriz, int l, int c, int indice) {
  if (indice == l * c) {
    return;
  }
  printf("%c ", *(matriz + indice));
  if ((indice + 1) % c == 0) {
    printf("\n");
  }
  return imprimir_labirinto(matriz, l, c, indice + 1);
}

bool dfs(char *labirinto, int l, int c, int i, int j, bool *visitado) {
  // Verifica se a posição atual é a saída
  if (i == 0 && j == c - 2) {
    return true;
  }

  // Marca a posição atual como visitada
  *(visitado + (i * c) + j) = true;

  // Verifica todas as direções possíveis (cima, baixo, esquerda, direita)
  // Analisa se na posição atual a direcao observada(para cima) tem espaço
  // vazio e se não foi visitada. Caso SIM, avança para essa posição
  // recursivamente e tenta novamente.
  if (i > 0 && *(labirinto + (i - 1) * c + j) == ' ' &&
      !*(visitado + (i - 1) * c + j)) {
    if (dfs(labirinto, l, c, i - 1, j, visitado)) {
      return true;
    }
  }
  if (i < l - 1 && *(labirinto + (i + 1) * c + j) == ' ' &&
      !*(visitado + (i + 1) * c + j)) {
    if (dfs(labirinto, l, c, i + 1, j, visitado)) {
      return true;
    }
  }
  if (j > 0 && *(labirinto + i * c + (j - 1)) == ' ' &&
      !*(visitado + i * c + (j - 1))) {
    if (dfs(labirinto, l, c, i, j - 1, visitado)) {
      return true;
    }
  }
  if (j < c - 1 && *(labirinto + i * c + (j + 1)) == ' ' &&
      !*(visitado + i * c + (j + 1))) {
    if (dfs(labirinto, l, c, i, j + 1, visitado)) {
      return true;
    }
  }

  return false;
}

void temSaida(char *labirinto, int l, int c) {
  bool *visitado = (bool *)malloc(l * c * sizeof(bool));
  for (int i = 0; i < l * c; i++) {
    *(visitado + i) = false;
  }

  if (dfs(labirinto, l, c, 1, 0, visitado)) {
    printf("Sim\n");
  } else {
    printf("Não\n");
  }

  free(visitado);
}

int main(void) {
  int l, c;
  scanf("%d%*c %d%*c", &l, &c);
  char *labirinto1 = malloc(l * c * sizeof(char));
  ler_dados(labirinto1, l, c, 0);

  temSaida(labirinto1, l, c);

  imprimir_labirinto(labirinto1, l, c, 0);
  return 0;
}
