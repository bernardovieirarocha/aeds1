//  Escreva um código que apresente o maior e o menor valor de um vetor de n ≥ 5
//  números lidos pelo usuário, sejam eles todos inteiros ou todos decimais. O
//  usuário primeiro fornece a quantidade n de números e, em seguida, seleciona
//  o tipo, sendo int quando apresenta o caractere ‘i’, ou decimal quando o
//  caractere ‘f’ for apresentado. Imprima de acordo com o tipo selecionado.
//  ATENÇÃO! Para isso, é OBRIGATÓRIO o uso das estruturas union, enum e struct.

#include <stdio.h>
#include <stdlib.h>

// Define os tipos de dados que podem ser armazenados
enum tipo { INT, FLOAT };
// Define a união de valores que podem ser armazenados.
union valor { int i; float f; };
// Define a estrutura que armazena o tipo e o valor
struct numero { enum tipo tipo; union valor valor; };

int main(void) {
  int n;
  char tipo;
  scanf("%d %c", &n, &tipo);
  // Verifica se o usuário inseriu pelo menos 5 números.
  if (n < 5) {
    printf("Você precisa fornecer pelo menos 5 números.\n");
    return 1;
  }
  // Aloca espaço para os números a serem lidos
  struct numero *numeros = (struct numero *)malloc(n * sizeof(struct numero));
  for (int i = 0; i < n; ++i) {
    // Lê n números e armazena o tipo e o valor
    if (tipo == 'i') {
      scanf("%d", &numeros[i].valor.i);
      (numeros + i)->tipo = INT;
    } else if (tipo == 'f') {
      scanf("%f", &numeros[i].valor.f);
      (numeros + i)->tipo = FLOAT;
    }
  }
  // Inicializa o maior e o menor valor com o primeiro número
  union valor maior = numeros->valor;
  union valor menor = numeros->valor;
  for (int i = 1; i < n; ++i) {
    // Compara os valores para encontrar o maior e o menor de acordo com o tipo
    // do numero inserido pelo usuário.
    if ((numeros + i)->tipo == INT) {
      if ((numeros + i)->valor.i > maior.i) {
        maior.i = (numeros + i)->valor.i;
      }
      if ((numeros + i)->valor.i < menor.i) {
        menor.i = (numeros + i)->valor.i;
      }
    } else if ((numeros + i)->tipo == FLOAT) {
      if ((numeros + i)->valor.f > maior.f) {
        maior.f = (numeros + i)->valor.f;
      }
      if ((numeros + i)->valor.f < menor.f) {
        menor.f = (numeros + i)->valor.f;
      }
    }
  }
  // Imprime o maior e o menor valor de acordo com o tipo inserido pelo usuário.
  if (tipo == 'i') {
    printf("Menor: %d Maior: %d\n", menor.i, maior.i);
  } else {
    printf("Menor: %.2f Maior: %.2f\n", menor.f, maior.f);
  }

  return 0;
}