// ATENÇÃO: Este é um exercício para ser feito em sala de aula. Logo, entregas
// de alunos(as) que não estiverem presentes no dia da aplicação, terão suas
// entregas desconsideradas.

// ENUNCIADO: Você terá de fazer um programa que solicite uma nota, entre 0 e
// 100, de um(a) aluno(a) e o programa irá avaliar se este(a): (a) fora
// aprovado(a) na disciplina; (b) pegou recuperação; e (c) reprovou direto.
// Quando a resposta for positiva, imprima o caractere 'S' na tela; caso
// contrário, imprima 'N'.

// RESTRIÇÕES: É obrigatório resolver este problema SEM USO DE CONDICIONAIS, ou
// seja, somente operações e expressões aritméticas (+,-,/,%).

#include <stdio.h>

int main(void) {
  int nota;
  scanf("%d", &nota);
  int aprovado = 'N' + 5 * (nota / 60);
  printf("%c\n", aprovado);
  int recuperacao = 'N' + 5 * (nota / 45) * (1 - nota / 60);
  printf("%c\n", recuperacao);
  int reprovado = 'N' + 5 * (1 - nota / 45) * (1 - nota / 90);
  printf("%c\n", reprovado);
  return 0;
}

// O que foi enviado pelo canvas ao Felipe de Castro Belém
// #include <stdio.h>

// int main(void) {
//   int nota;
//   printf("Coloque sua nota: ");
//   scanf("%d", &nota);
//   int aprovado = 'N' + 5 * (nota / 60);
//   printf("Aprovado: %c\n", aprovado);

//   int recuperacao = 'N' + 5 * (nota / 45) * (1-nota / 60);
//   printf("Recuperação: %c\n", recuperacao);

//   int reprovou = 'N' + 5 * (1-nota / 45) * (1-nota/90);
//   printf("Reprovou: %c\n", reprovou);
//   return 0;
// }
