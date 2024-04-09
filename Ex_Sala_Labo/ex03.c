#include <stdio.h>

int main(void) {
  int lado;
  char tipo;
  int meio;
  printf("Digite o lado e tipo da impressão: ");
  scanf("%d %c", &lado, &tipo);
  if (tipo == 'c') {
    for (int i = 0; i < lado; i++) {
      for (int i = 0; i < lado; i++) {
        printf("*");
      }
      printf("\n");
    }
  } else if (tipo == 'b') {
    int inicio = 1;
    int fim = lado - 2;
    for (int linha = 0; linha < lado; linha++) {
      for (int coluna = 0; coluna < lado; coluna++) {
        if (coluna == 0 && linha != 0 ||
            coluna == lado - 1 && linha != lado - 1) {
          printf("*");
        }
        if (linha >= inicio && linha <= fim) {
          printf(" ");
        } else {
          printf("*");
        }
      }
      printf("\n");
    }
  } else if (tipo == 'p') {
    int inicio = 1;
    int fim = lado - 2;
    int diagonal = 0;
    for (int linha = 0; linha < lado; linha++) {
      for (int coluna = 0; coluna < lado; coluna++) {
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
      diagonal++;
      printf("\n");
    }
  } else if (tipo == 's') {
    int inicio = 1;
    int fim = lado - 2;
    int diagonal = lado - 1;
    for (int linha = 0; linha < lado; linha++) {
      for (int coluna = 0; coluna < lado; coluna++) {
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
      diagonal--;
      printf("\n");
    }
  } else if (tipo == 'h') {
    int inicio = 1;
    int fim = lado - 2;
    if (lado % 2 == 0) {
      meio = (lado - 2) / 2;
    } else {
      meio = lado / 2;
    }
    for (int linha = 0; linha < lado; linha++) {
      for (int coluna = 0; coluna < lado; coluna++) {
        if (coluna == 0 && linha != 0 ||
            coluna == lado - 1 && linha != lado - 1) {
          printf("*");
        } else if (linha >= inicio && linha <= fim) {
          if (linha == meio) {
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
        if (coluna == 0 && linha != 0 ||
            coluna == lado - 1 && linha != lado - 1) {
          printf("*");
        } else if (linha >= inicio && linha <= fim) {
          if (coluna == meio) {
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