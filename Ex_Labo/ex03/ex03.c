// ATENÇÃO: Este é um exercício para ser feito em sala de aula. Logo, entregas
// de alunos(as) que não estiverem presentes no dia da aplicação, terão suas
// entregas desconsideradas. Além disso, códigos que não estiverem indentados,
// comentados e/ou não respeitarem as restrições também serão desconsiderados. É
// importante frisar que comentários redundantes e/ou irrelevantes para o
// entendimento da solução não serão considerados.

// ENUNCIADO:  Faça um programa que leia um inteiro positivo qualquer e um
// caractere que indica o tipo de quadrado (de lado l) a ser impresso na tela
// utilizando o caractere '*'. Se o caractere for:

// 'c', imprima um quadrado totalmente preenchido;

// 'b', imprima somente suas bordas;

// 'p', imprima suas bordas e a diagonal principal;

// 's', imprima suas bordas e a diagonal secundária;

// 'h', imprima suas bordas e sua divisão horizontal (no meio);

// 'v' imprima suas bordas e sua divisão vertical (no meio);

// caso contrário, imprima a mensagem de erro: "Não existe essa opção".

// RESTRIÇÕES: Não se pode utilizar nenhum conceito não visto em sala de aula
// (por ex., strings)
#include <stdio.h>

int main(void) {
  int lado;
  char tipo;
  int meio;
  scanf("%d %c", &lado, &tipo);
  if (tipo == 'c') {
    // Desenha um quadrado cheio ('c' de 'cheio'). Matriz completa de asteriscos
    for (int i = 0; i < lado; i++) {
      for (int i = 0; i < lado; i++) {
        printf("*");
      }
      printf("\n");
    }
  } else if (tipo == 'b') {
    for (int i = 0; i < lado; i++) {
      for (int j = 0; j < lado; j++) {
        // Verifica se a posição atual está na borda do quadrado.
        if (i == 0 || i == lado - 1 || j == 0 || j == lado - 1) {
          printf("*");
        } else {
          printf(" ");
        }
      }
      printf("\n");
    }
  } else if (tipo == 'p') {
    int inicio = 1;
    int fim = lado - 2; // Controlar a linha de fim da diagonal.
    int diagonal = 0;
    for (int linha = 0; linha < lado; linha++) {
      for (int coluna = 0; coluna < lado; coluna++) {
        // Verifica se a posição atual está na borda do quadrado.
        if (coluna == 0 && linha != 0 ||
            coluna == lado - 1 && linha != lado - 1) {
          printf("*");

        } else if (linha >= inicio && linha <= fim) {
          // O else if analise se a linha esta contida dentro do quadrado e eh
          // passivel de ter diagonal
          // Verifica se a posição da coluna está na diagonal.
          if (diagonal == coluna) {
            printf("*");
          } else {
            printf(" ");
          }
        } else {
          printf("*");
        }
      }
      // Vai percorrendo a diagonal
      diagonal++;
      printf("\n");
    }
  } else if (tipo == 's') {
    int inicio = 1;
    int fim = lado - 2;      // Controlar a linha de fim da diagonal.
    int diagonal = lado - 1; // Comecar a diagonal secundaria em baixo
    for (int linha = 0; linha < lado; linha++) {
      for (int coluna = 0; coluna < lado; coluna++) {
        // Verifica se a posição atual está na borda do quadrado.
        if (coluna == 0 && linha != 0 ||
            coluna == lado - 1 && linha != lado - 1) {
          printf("*");
        } else if (linha >= inicio && linha <= fim) {
          if (diagonal == coluna) {
            printf("*");
          } else {
            printf(" ");
          }
        } else {
          printf("*");
        }
      }
      // Vai percorrendo a de baixo pra cima
      diagonal--;
      printf("\n");
    }
  } else if (tipo == 'h') {
    int inicio = 1;
    int fim = lado - 2;
    // Calcula o meio horizontal do quadrado, atentando-se para os problemas se
    // ele for par ou impar.
    if (lado % 2 == 0) {
      meio = (lado - 2) / 2;
    } else {
      meio = lado / 2;
    }
    for (int linha = 0; linha < lado; linha++) {
      for (int coluna = 0; coluna < lado; coluna++) {
        // Verifica se a posição atual está na borda do quadrado.
        if (coluna == 0 && linha != 0 ||
            coluna == lado - 1 && linha != lado - 1) {
          printf("*");
        } else if (linha >= inicio && linha <= fim) {
          if (linha == meio) {
            // Verifica se concide com o a posicao/linha do meio horizontal.
            printf("*");
          } else {
            printf(" ");
          }
        } else {
          printf("*");
        }
      }
      printf("\n");
    }
  } else if (tipo == 'v') {
    int inicio = 1;
    int fim = lado - 2;
    if (lado % 2 == 0) {
      meio = (lado - 2) / 2;
    } else {
      meio = (lado) / 2;
    }
    for (int linha = 0; linha < lado; linha++) {
      for (int coluna = 0; coluna < lado; coluna++) {
        // Verifica se a posição atual está na borda do quadrado.
        if (coluna == 0 && linha != 0 ||
            coluna == lado - 1 && linha != lado - 1) {
          printf("*");
        } else if (linha >= inicio && linha <= fim) {
          if (coluna == meio) {
            // Verifica se concide com o a posicao/coluna do meio vertical.
            printf("*");
          } else {
            printf(" ");
          }
        } else {
          printf("*");
        }
      }
      printf("\n");
    }
  } else {
    printf("Não existe essa opção.\n");
  }
  return 0;
}
