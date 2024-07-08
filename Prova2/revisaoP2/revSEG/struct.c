#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

struct prova {
  int valor;
};

struct atividade {
  int valor;
};

struct aluno {
  char *nome;
  int *prova;
  int *atividade;
  float media;
};

// Resume (struct aluno) em somente aluno;
typedef struct aluno aluno;

int main(void) {
  int qtdAlunos;
  scanf("%d", &qtdAlunos);

  aluno *alunos = (aluno *)malloc(qtdAlunos * sizeof(aluno));

  for (int i = 0; i < qtdAlunos; ++i) {
    char *nome = malloc(1024 * sizeof(char));
    scanf("%s", nome);
    alunos[i].nome = nome;
  }

  int qtdProvas, qtdAtv;
  scanf("%d%*c %d%*c", &qtdProvas, &qtdAtv);

  for (int i = 0; i < qtdProvas; ++i) {
    for (int aluno = 0; aluno < qtdAlunos; ++aluno) {
      int *provas = malloc(qtdProvas * sizeof(int));
      alunos[aluno].prova = provas;
    }
  }
  for (int i = 0; i < qtdAtv; ++i) {
    for (int aluno = 0; aluno < qtdAlunos; ++aluno) {
      int *atividades = malloc(qtdAtv * sizeof(int));
      alunos[aluno].atividade = atividades;
    }
  }

  float mediaAluno;
  float mediaTurma = 0;

  for (int a = 0; a < qtdAlunos; ++a) {
    mediaAluno = 0;
    for (int i = 0; i < qtdProvas; ++i) {
      printf("Nota da %d prova: ", i + 1);
      scanf("%d", (alunos[a].prova + i));
      mediaAluno += (float)*(alunos[a].prova + i) / (float)(qtdProvas + qtdAtv);
      mediaTurma += (float)*(alunos[a].prova + i) / (float)qtdAlunos;
      printf("\n");
    }

    for (int j = 0; j < qtdAtv; ++j) {
      printf("Nota da %d atividade: ", j + 1);
      scanf("%d", (alunos[a].atividade + j));
      mediaAluno +=
          (float)*(alunos[a].atividade + j) / (float)(qtdProvas + qtdAtv);
      mediaTurma += (float)*(alunos[a].atividade + j) / (float)qtdAlunos;

      printf("\n");
    }
    alunos[a].media = mediaAluno;
  }

  for (int a = 0; a < qtdAlunos; ++a) {
    printf("%s: \n", alunos[a].nome);
    for (int i = 0; i < qtdProvas; ++i) {
      printf("Nota da %d prova: %d", i + 1, *(alunos[a].prova + i));
      printf("\n");
    }
    for (int j = 0; j < qtdAtv; ++j) {
      printf("Nota da %d atividade: %d ", j + 1, *(alunos[a].atividade + j));
      printf("\n");
    }
    printf("Media: %.2f\n", alunos[a].media);
  }

  printf("Media Turma: %.2f\n", mediaTurma);

  return 0;
}