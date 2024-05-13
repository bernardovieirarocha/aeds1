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
// aula
#include <stdio.h>
const int M = 9;
const int N = 9;

int verificar_linha(int linha_user, int sudoku[M][N]) {
  // Funcao para verificar se ha numeros repetidos em uma linha especifica do
  // Sudoku
  for (int i = 0; i < 9; ++i) {
    // Percorre cada coluna na linha especificada
    for (int j = i + 1; j < 9; ++j) {
      // Verifica se os numeros nas colunas i e j são iguais
      if (sudoku[linha_user][i] == sudoku[linha_user][j]) {
        return 1; // 'S'
      }
    }
  }

  return 0; // 'N'
}

int verificar_coluna(int coluna_user, int sudoku[M][N]) {
  // Funcao para verificar se ha numeros repetidos em uma coluna especifica do
  // Sudoku

  for (int i = 0; i < 9; ++i) {
    // Percorre cada linha da coluna especificada
    for (int j = i + 1; j < 9; ++j) {
      // Verifica se os numeros nas linhas i e j são iguais
      if (sudoku[i][coluna_user] == sudoku[j][coluna_user]) {
        return 1; // 'S'
      }
    }
  }

  return 0; // 'N'
}

int verificar_quadrante(int quadrante, int sudoku[M][N]) {
  // Descobrir no Quadrante especificado qual o max e o min que devo percorrer
  // em loop
  int linha_min = 3 * (quadrante / 3);
  int coluna_min = 3 * (quadrante % 3);
  int linha_max = linha_min + 2;
  int coluna_max = coluna_min + 2;

  // Loop que transforma a matriz 3x3 em um um vetor linear de 9 posicoes, ja q
  // basta eu saber se tem repetido ou nao.
  int vet_linear[9];
  int index_contador = 0;
  for (int i = linha_min; i <= linha_max; ++i) {
    for (int j = coluna_min; j <= coluna_max; ++j) {
      vet_linear[index_contador] = sudoku[i][j];
      index_contador++;
    }
  }
  // Percorre o vetor linear criado para verificar se tem algum valor repetido
  // na matriz no quadrante
  int anterior;
  for (int i = 0; i < 9; ++i) {
    // salva o valor anterior
    anterior = vet_linear[i];
    for (int j = i + 1; j < 9; ++j) {
      // compara com todos os outros valores do vetor
      if (anterior == vet_linear[j]) {
        return 1; // 'S'
      }
    }
  }

  return 0; // 'N'
}

int main(void) {
  int sudoku[9][9];
  int opt;

  for (int i = 0; i < 9; ++i) {
    for (int j = 0; j < 9; ++j) {
      scanf("%d%*c", &sudoku[i][j]);
    }
  }

  // Digite a opcao (1-5) que deseja executar:
  scanf(" %d%*c", &opt);

  while (opt != 0) {
    if (opt == 1) {
      int linha, coluna, novo_algarismo;
      scanf("%d%*c %d%*c %d%*c", &linha, &coluna, &novo_algarismo);
      sudoku[linha][coluna] = novo_algarismo;
    } else if (opt == 2) {
      int linha;
      scanf("%d%*c", &linha);

      // Operador Ternario que avalia o que deve ser impresso.
      int tem_repetido = verificar_linha(linha, sudoku) ? 'S' : 'N';

      printf("%c\n", tem_repetido);

    } else if (opt == 3) {
      int coluna;
      scanf("%d%*c", &coluna);

      // Operador Ternario que avalia o que deve ser impresso.
      int tem_repetido = verificar_coluna(coluna, sudoku) ? 'S' : 'N';

      printf("%c\n", tem_repetido);

    } else if (opt == 4) {
      int quadrante;
      scanf("%d%*c", &quadrante);

      // Operador Ternario que avalia o que deve ser impresso.
      int tem_repetido = verificar_quadrante(quadrante, sudoku) ? 'S' : 'N';

      printf("%c\n", tem_repetido);

    } else if (opt == 5) {
      int colunas_ok = 1;
      int linhas_ok = 1;
      int quadrantes_ok = 1;
      // Loop que perpassa todas as linhas, colunas e quadrantes e da um flag
      // caso alguma delas retorne 0;
      for (int i = 0; i < 9; ++i) {
        if (verificar_coluna(i, sudoku)) {
          colunas_ok = 0;
        } else {
          colunas_ok = 1;
        }
        if (verificar_linha(i, sudoku)) {
          linhas_ok = 0;
        } else {
          colunas_ok = 1;
        }
        if (verificar_quadrante(i, sudoku)) {
          quadrantes_ok = 0;
        } else {
          colunas_ok = 1;
        }
      }

      if (linhas_ok && colunas_ok && quadrantes_ok) {
        printf("N\n"); // Matriz perfeita, jogo de sudoku ganho.
      } else {
        printf("S\n"); // tem repeticao em algum lugar
      }

    } else {
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
    }

    // Digite a opcao (1-5) que deseja executar:
    scanf(" %d%*c", &opt);
  }

  return 0;
}