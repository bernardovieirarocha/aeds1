

/*
        EXERCICIO 1
        Faça um programa que leia uma matriz de caracteres de tamanho NxM,
        representando um labirinto ("*" sendo parede e ( " ") caminho).
        Imprima sim se houver um caminho e nao caso contrario.
        Entrada sempre no (1,0) e saída (N-2, M-1). Só pode se mover p/ esq, dir
        cima ou baixo
*/
#include <stdbool.h> // bool, true, false
#include <stdio.h>   // scanf, printf
#include <stdlib.h>  // malloc, free, NULL

bool existe_saida(char **labirinto, bool **visitado, int num_linhas,
                  int num_cols, int i, int j) {
  // Encontrou a saida?
  if ((i == num_linhas - 2) && (j == num_cols - 1)) {
    return true; // Achou a saída
  }
  // Nao e uma parede?
  else if (labirinto[i][j] != '*') {
    bool achou = false;
    visitado[i][j] = true; // Posicao ativa na procura atual da solucao

    // Olha pra cima
    if ((i > 0) && (visitado[i - 1][j] == false)) {
      achou = existe_saida(labirinto, visitado, num_linhas, num_cols, i - 1, j);
    }
    // Olha pra baixo
    if ((achou == false) && (i < (num_linhas - 1)) &&
        (visitado[i + 1][j] == false)) {
      achou = existe_saida(labirinto, visitado, num_linhas, num_cols, i + 1, j);
    }
    // Olha pra esquerda
    if ((achou == false) && (j > 0) && (visitado[i][j - 1] == false)) {
      achou = existe_saida(labirinto, visitado, num_linhas, num_cols, i, j - 1);
    }
    // Olha pra direita
    if ((achou == false) && (j < (num_cols - 1)) &&
        (visitado[i][j + 1] == false)) {
      achou = existe_saida(labirinto, visitado, num_linhas, num_cols, i, j + 1);
    }

    visitado[i][j] =
        false; // Desativa pois outro caminho pode precisar dessa posicao

    return achou; // Retorna a resposta definitiva, achado ou nao
  } else          // So pode ser parede
  {
    return false;
  }
}

int main() {
  bool **visitado = NULL;  // Auxiliar indicando os lugares ja visitados
  char **labirinto = NULL; // Labirinto
  int num_linhas = 0, num_cols = 0;

  // Allocando espaco
  scanf("%d %d", &num_linhas, &num_cols);
  labirinto = (char **)malloc(num_linhas * sizeof(char *));
  visitado = (bool **)malloc(num_linhas * sizeof(bool *));

  // Preenchendo a matriz
  for (int i = 0; i < num_linhas; ++i) {
    labirinto[i] = (char *)malloc(num_cols * sizeof(char));
    visitado[i] = (bool *)malloc(num_cols * sizeof(bool));
    for (int j = 0; j < num_cols - 1; ++j) {
      scanf("%c", &(labirinto[i][j]));
      visitado[i][j] = false; // Nenhum lugar foi visitado de inicio
    }
    scanf("%c%*c", &(labirinto[i][num_cols - 1])); // Evitando ler \n
    visitado[i][num_cols - 1] = false;
  }

  if (existe_saida(labirinto, visitado, num_linhas, num_cols, 1, 0) == true) {
    printf("SIM\n");
  } else {
    printf("NAO\n");
  }

  // Liberando memoria
  for (int i = 0; i < num_linhas; ++i) {
    free(labirinto[i]);
    free(visitado[i]);
  }
  free(labirinto);
  free(visitado);

  return 0;
}