#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
  FILE *numeros = NULL;
  FILE *estat = NULL;
  int ch1;
  int *sequencia = NULL;
  numeros = fopen("numeros.txt", "r");
  estat = fopen("estatisticas.txt", "w");

  if (numeros != NULL && estat != NULL) {
    int tamanhoNUMEROS = 0;
    float somaMedia = 0;
    float mediana;

    while (!feof(numeros)) {
      fscanf(numeros, "%d", &ch1);
      if (ch1 != ' ') {
        tamanhoNUMEROS++;
        somaMedia += (float)ch1;
      }
    }
    float media = somaMedia / ((float)tamanhoNUMEROS);
    sequencia = (int *)malloc(tamanhoNUMEROS * sizeof(int));

    // Recomeço a leitura de numeros.txt para poder inserir os valores no vetor
    rewind(numeros);
    int contador = 0;
    while (!feof(numeros)) {
      fscanf(numeros, "%d", sequencia + contador);
      contador++;
    }
    // Algoritmo Bubble Sort que coloca os numeros em ordem crescente
    for (int i = 0; i < tamanhoNUMEROS - 1; i++) {
      for (int j = 0; j < tamanhoNUMEROS - i - 1; j++) {
        if (*(sequencia + j) > *(sequencia + (j + 1))) {
          int temp = *(sequencia + j);
          *(sequencia + j) = *(sequencia + (j + 1));
          *(sequencia + (j + 1)) = temp;
        }
      }
    }

    for (int i = 0; i < tamanhoNUMEROS; ++i) {
      fprintf(estat, "%d ", sequencia[i]);
    }
    fprintf(estat, "%s", "\n");
    int medianapos = tamanhoNUMEROS / 2;

    if (tamanhoNUMEROS % 2 == 0) {
      mediana =
          ((sequencia[medianapos]) + (sequencia[medianapos - 1])) / (float)2;
    } else {
      mediana = sequencia[medianapos];
    }
    fprintf(estat, "media: %.2f", media);
    fprintf(estat, "%s", "\n");

    // Calculo Desvio Padrao
    float variancia = 0;
    for (int i = 0; i < tamanhoNUMEROS; ++i) {
      variancia += (pow((sequencia[i] - media), 2)) / tamanhoNUMEROS;
    }
    float desvioPadrao = sqrt(variancia);
    fprintf(estat, "desvio padrao: %.2f", desvioPadrao);
    fprintf(estat, "%s", "\n");
    fprintf(estat, "mediana: %.2f", mediana);
  }
  fclose(numeros);
  fclose(estat);
  return 0;
}