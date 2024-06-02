// Faça um programa que leia um arquivo existente chamado notas.txt e salve, em
// dois outros arquivos chamados aprovados.txt e naoaprovados.txt, os alunos(as)
// cuja soma das notas foi, e não foi, respectivamente, suficiente para serem
// aprovados(as) (i.e., maiores ou iguais a 60). Sabe-se que a primeira linha
// desse arquivo contém um inteiro indicando o número n de alunos e, em seguida,
// são definidas as notas inteiras de cada um(a) dos n alunos(as). Além disso,
// como última linha do arquivo escrito, deve constar, nessa ordem, a menor, a
// maior e a média (com no máximo 2 casas decimais) das notas dos(as) alunos(as)
// presentes com a respectiva condição.

#include <stdio.h>
#include <stdlib.h>

int main(void) {
  FILE *aprov = NULL;
  FILE *notas = NULL;
  FILE *repro = NULL;

  notas = fopen("notas.txt", "r");
  aprov = fopen("aprovados.txt", "w");
  repro = fopen("naoaprovados.txt", "w");

  int qtd_alunos, nota;
  int soma_aprovados = 0, soma_naoaprovados = 0;
  int min_aprovados = 101, min_naoaprovados = 101;
  int max_aprovados = -1, max_naoaprovados = -1;
  int count_aprovados = 0, count_naoaprovados = 0;
  char *nome = (char *)malloc(1024 * sizeof(char));

  if (aprov == NULL || notas == NULL || repro == NULL) {
    printf("Erro ao abrir os arquivos\n");
    return 1;
  }

  // Recebe a quantidade de alunos na primeira linha
  fscanf(notas, "%d", &qtd_alunos);
  // Loop pela quantidade de alunos, isto é a quantidade de notas/linhas.
  for (int i = 0; i < qtd_alunos; i++) {
    // Le as notas dos alunos e separa em aprovado ou nao aprovado.
    fscanf(notas, "%s", nome);
    fscanf(notas, "%d", &nota);
    if (nota >= 60) {
      // Se a nota for maior ou igual a 60, o aluno é aprovado. Imprime no
      // arquivo aprovados.txt
      fprintf(aprov, "%s\n", nome);
      // Soma a nota do aluno aprovado e conta quantos têm para o calculo da
      // média.
      soma_aprovados += nota;
      count_aprovados++;
      // Verifica se a nota é a menor ou a maior entre os aprovados.
      if (nota < min_aprovados) {
        min_aprovados = nota;
      }
      if (nota > max_aprovados) {
        max_aprovados = nota;
      }
    } else {
      fprintf(repro, "%s\n", nome);
      // Soma a nota do aluno nãoaprovado e conta quantos têm para o calculo
      // da média.
      soma_naoaprovados += nota;
      count_naoaprovados++;
      // Verifica se a nota é a menor ou a maior entre os aprovados.
      if (nota < min_naoaprovados)
        min_naoaprovados = nota;
      if (nota > max_naoaprovados)
        max_naoaprovados = nota;
    }
  }
  // Calcula a média dos aprovados e dos não aprovados.
  float media_aprovados = (float)soma_aprovados / count_aprovados;
  float media_naoaprovados = (float)soma_naoaprovados / count_naoaprovados;
  // Imprime no arquivo aprovados.txt a média, a menor e a maior nota.
  fprintf(aprov, "Menor: %d Maior: %d Media: %.2f\n", min_aprovados,
          max_aprovados, media_aprovados);
  // Imprime no arquivo naoaprovados.txt a média, a menor e a maior nota.
  fprintf(repro, "Menor: %d Maior: %d Media: %.2f\n", min_naoaprovados,
          max_naoaprovados, media_naoaprovados);

  // Fecha os arquivos.
  fclose(aprov);
  fclose(notas);
  fclose(repro);
  free(nome);

  return 0;
}