// ATENÇÃO: Este é um exercício para ser feito em sala de aula. Logo, entregas
// de alunos(as) que não estiverem presentes no dia da aplicação, terão suas
// entregas desconsideradas. Além disso, códigos que não estiverem indentados,
// comentados e/ou não respeitarem as restrições também serão desconsiderados. É
// importante frisar que comentários redundantes e/ou irrelevantes para o
// entendimento da solução não serão considerados.

// ENUNCIADO: Você terá de criar um programa que leia uma matriz 9x9 de números
// de 1 a 9 e, em seguida, realizar a operação desejada pelo usuário até que o
// valor 0, indicando a finalização do programa, seja apresentado. As opções
// referentes à funcionalidade do programa são:

// 1. Atualizar índice: Juntamente com a opção 1, na mesma linha, serão
// apresentadas o índice da linha (entre 0 a 8), o índice da coluna (0 a 8), e o
// novo algarismo (1 a 9) que irá substituir o algarismo antigo na posição
// indicada.

// 2. Verificar linha: Juntamente com a opção 2, na mesma linha, será
// apresentada o índice da linha (entre 0 a 8) a ser verificada. Se não houver
// repetição de números, deve-se imprimir o caractere 'N'; caso contrário,
// imprima 'S'.

// 3. Verificar coluna: Juntamente com a opção 3, na mesma linha, será
// apresentada o índice da coluna (entre 0 a 8) a ser verificada. Se não houver
// repetição de números, deve-se imprimir o caractere 'N'; caso contrário,
// imprima 'S'.

// 4. Verificar quadrante: Juntamente com a opção 4, na mesma linha, será
// apresentada o índice do quadrante (0 a 8) a ser verificado. Se não houver
// repetição de números, deve-se imprimir o caractere 'N'; caso contrário,
// imprima 'S'. Os quadrantes estão enumerados na seguinte forma:

// 0 1 2
// 3 4 5
// 6 7 8

// 5. Verificar matriz: Se não houver repetição de números, deve-se imprimir o
// caractere 'N'; caso contrário, imprima 'S'

// Qualquer outro valor que não esteja no intervalo [0,5], assume-se que o
// usuário deseja imprimir a matriz de maneira formatada, deixando claro a
// separação dos quadrantes via espaços e linhas em branco.

// RESTRIÇÕES: Não se pode utilizar nenhum conceito (ainda) não visto em sala de
// aula e TODAS as opções DEVEM ESTAR modularizadas.

#include <stdio.h>

int checarRepeticao(int coluna_min, int coluna_max, int linha_min,
                    int linha_max, int sudoku[9][9]) {
  int tem_repetido = 0;
  if (linha_min == linha_max) {
    // Checar se existe repetição na linha especificada.
    for (int i = 0; i < 9; ++i) {
      for (int j = i + 1; j < 9; ++j) {
        if (sudoku[linha_min][i] == sudoku[linha_min][j]) {
          tem_repetido = 1; // 'S'
        }
      }
    }
  } else if (coluna_min == coluna_max) {
    // Checar se existe repetição na coluna especificada.
    for (int i = 0; i < 9; ++i) {
      for (int j = i + 1; j < 9; ++j) {
        if (sudoku[i][coluna_max] == sudoku[j][coluna_max]) {
          tem_repetido = 1; // 'S'
        }
      }
    }
  } else {
    // Checar se existe repetição no quadrante especificado;
    int vet_linear[10] = {0}; // Um vetor linear de 9 posicoes, ja q basta eu
                              // saber se tem repetido ou nao.
    for (int i = linha_min; i <= linha_max; ++i) {
      for (int j = coluna_min; j <= coluna_max; ++j) {
        if (vet_linear[sudoku[i][j]] > 0) {
          tem_repetido = 1;
        } else {
          vet_linear[sudoku[i][j]] = 1;
        }
      }
    }
  }
  return tem_repetido;
}

void ler_matriz(int *matriz, int linhas, int colunas) {
  for (int i = 0; i < linhas; i++) {
    for (int j = 0; j < colunas; j++) {
      scanf("%d", matriz + i * colunas + j);
    }
  }
}

void mudarValorSudoku(int linha, int coluna, int novoValor, int sudoku[9][9]) {
  sudoku[linha][coluna] = novoValor;
}

int verificar_quadrante(int quadrante, int sudoku[9][9]) {
  int linha_min = 3 * (quadrante / 3);
  int coluna_min = 3 * (quadrante % 3);
  int linha_max = linha_min + 2;
  int coluna_max = coluna_min + 2;
  return checarRepeticao(coluna_min, coluna_max, linha_min, linha_max, sudoku);
}

int verificar_matriz(int sudoku[9][9]) {
  int colunas_ok = 1;
  int linhas_ok = 1;
  int quadrantes_ok = 1;

  for (int i = 0; i < 9; ++i) {
    if (checarRepeticao(i, i, 1, 2, sudoku)) {
      colunas_ok = 0;
    }
    if (checarRepeticao(1, 2, i, i, sudoku)) {
      linhas_ok = 0;
    }
    if (verificar_quadrante(i, sudoku)) {
      quadrantes_ok = 0;
    }
  }

  int tem_repetido = 0;
  if (linhas_ok && colunas_ok && quadrantes_ok) {
    return 0; // Matriz perfeita, jogo de sudoku ganho.
  } else {
    return 1; // Tem repeticao em algum lugar
  }
}

int desenharSudoku(int sudoku[9][9]) {
  for (int i = 0; i < 9; i++) {
    for (int j = 0; j < 9; j++) {
      printf("%d ", sudoku[i][j]);

      // Separar quadrantes com espaços e linhas em branco
      if (j == 2 || j == 5) {
        printf(" ");
      }
    }

    // Separar linhas com linhas em branco
    if (i == 2 || i == 5) {
      printf("\n\n");
    } else {
      printf("\n");
    }
  }
  return 0;
}

int main(void) {
  int sudoku[9][9];

  int opt;

  ler_matriz((int *)sudoku, 9,
             9); // Chamada da função para ler dados
  scanf(" %d%*c", &opt);

  while (opt != 0) {
    if (opt == 1) {
      int linha, coluna, novoValor;
      scanf("%d%*c %d%*c %d%*c", &linha, &coluna, &novoValor);
      mudarValorSudoku(linha, coluna, novoValor, sudoku);
    } else if (opt == 2) {
      int linha;
      scanf("%d%*c", &linha);

      int tem_repetido =
          checarRepeticao(1, 2, linha, linha, sudoku) ? 'S' : 'N';
      printf("%c\n", tem_repetido);

    } else if (opt == 3) {
      int coluna;
      scanf("%d%*c", &coluna);

      int tem_repetido =
          checarRepeticao(coluna, coluna, 1, 2, sudoku) ? 'S' : 'N';

      printf("%c\n", tem_repetido);

    } else if (opt == 4) {
      int quadrante;
      scanf("%d%*c", &quadrante);

      int tem_repetido = verificar_quadrante(quadrante, sudoku) ? 'S' : 'N';

      printf("%c\n", tem_repetido);

    } else if (opt == 5) {

      int sudokuRepetido = verificar_matriz(sudoku) ? 'S' : 'N';
      printf("%c\n", sudokuRepetido);

    } else {

      desenharSudoku(sudoku);
    }

    scanf(" %d%*c", &opt);
  }

  return 0;
}