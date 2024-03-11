#include <math.h>
#include <stdio.h>

// Maneira de escrever o typeof
// #define typeof(var) _Generic( (var),\
// char: "Char",\
// int: "Integer",\
// float: "Float",\
// char *: "String",\
// void *: "Pointer",\
// default: "Undefined")
// char buffer[20];
// char horas_string = snprintf(buffer, sizeof(buffer), "%f", horas);
// printf("%d", ceil(horas)== horas);
// printf("%s", typeof(horas));

int main(void) {
  float horas;
  int sec;
  int min;
  scanf("%f", &horas);
  if (ceil(horas) == horas) {
    // Ele é integer! Portanto faça somente a representaçao disso em
    // horas/minutos/segundos.
    sec = horas * 3600;
    min = horas * 60;
    printf("A conversão disso seria: %.1f horas ou %d minutos ou %d segundos\n",
           horas, min, sec);
  } else {
    // Ele é float! Faça representação completa da hora em horas / minutos
    int parteinteira = (int)horas; // Parece que a conversão se dá dessa maneira
    float partedecimal = horas - parteinteira;
    int qtd_minutos = partedecimal * 60;
    printf(
        "Esse horário, escrito de forma extensa fica: %d horas e %d minutos\n",
        parteinteira, qtd_minutos);
    // if (ceil(qtd_minutos) == qtd_minutos) {} - Nesse caso nao vale a pena
    // pensar em segundos porque dado um valor em horas nao chega em
    // segundos 10.999999 == 10 horas e 59 minutos ou vai para 11 mesmo. Somente
    // quando você recebe um valor em segundos que pode sobrar ao dividir 60, um
    // resto em segundos.
  }
  return 0;
}

#include <stdio.h>

int main(void) {

  int lado;
  char quadrado;
  int inicio = 1;
  int fim = lado - 2;

  printf("Coloque seu lado e sua opção aqui:\n");
  scanf("%d %c", &lado, &quadrado);

  switch (quadrado) {
  case 'c':
    for (int i = 0; i < lado; i++) {
      for (int i = 0; i < lado; i++) {
        printf("*");
      }
      printf("\n");
    }
    break;

  case 'b':
    inicio = 1;
    fim = lado - 2;
    for (int linha = 0; linha < lado; linha++) {
      if (linha >= inicio && linha <= fim) {
        printf("*");
        for (int asterisco = 2; asterisco < lado; asterisco++) {
          printf(" ");
        }
        printf("*");
      } else {
        for (int asterisco = 0; asterisco < lado; asterisco++) {
          printf("*");
        }
      }
      printf("\n");
    }
    break;

  case 'p':
    inicio = 1;
    fim = lado - 2;
    int diagonal = 1;
    for (int linha = 0; linha < lado; linha++) {
      if (linha >= inicio && linha <= fim) {
        printf("*");
        for (int asterisco = 2; asterisco < lado; asterisco++) {
          if (diagonal == asterisco) {
            printf("*");
          } else {
            printf(" ");
          }
        }
        printf("*");
      } else {
        for (int asterisco = 0; asterisco < lado; asterisco++) {
          printf("*");
        }
      }
      diagonal++;
      printf("\n");
    }
    break;

  case 'd':
    inicio = 1;
    fim = lado - 2;
    diagonal = lado;
    for (int linha = 0; linha < lado; linha++) {
      if (linha >= inicio && linha <= fim) {
        printf("*");
        for (int asterisco = 2; asterisco < lado; asterisco++) {
          if (diagonal == asterisco) {
            printf("*");
          } else {
            printf(" ");
          }
        }
        printf("*");
      } else {
        for (int asterisco = 0; asterisco < lado; asterisco++) {
          printf("*");
        }
      }
      diagonal++;
      printf("\n");
    }
    break;

  case 'h':
    inicio = 1;
    fim = lado - 2;
    for (int linha = 0; linha < lado; linha++) {
      for (int linha = 0; linha < lado / 2; linha++) {
        printf("*");
      }
      if (linha >= inicio && linha <= fim) {
        printf("*");
        for (int asterisco = 2; asterisco < lado; asterisco++) {
          printf(" ");
        }
        printf("*");
      } else {
        for (int asterisco = 0; asterisco < lado; asterisco++) {
          printf("*");
        }
      }

      printf("\n");
    }
    break;
  }
  return 0;
}