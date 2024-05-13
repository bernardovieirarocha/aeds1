// ATENÇÃO: Este é um exercício para ser feito em sala de aula. Logo, entregas
// de alunos(as) que não estiverem presentes no dia da aplicação, terão suas
// entregas desconsideradas. Além disso, códigos que não estiverem indentados,
// comentados e/ou não respeitarem as restrições também serão desconsiderados. É
// importante frisar que comentários redundantes e/ou irrelevantes para o
// entendimento da solução não serão considerados.

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
  // Se nota for maior que 60 que 60, o resultado da divisao sera 1
  // incrementando 5 ao char N e transforamndo em S pela tabela ASCII.
  int aprovado = 'N' + 5 * (nota / 60);
  printf("%c\n", aprovado);
  // Nesse caso a nota precisa ser maior ou igual a 45 e tambem menor que 60
  // para dar 1 e somar 5 ao char. Para tanto existe o "1 -" que inverte o
  // resultado para dar 1 para qualquer número ate 59.
  int recuperacao = 'N' + 5 * (nota / 45) * (1 - nota / 60);
  printf("%c\n", recuperacao);
  // Calcula-se se a nota eh menor que 45 e eh preciso da expressão (1 - nota /
  // 90) para imprimir o valor certo e impedir que exista um caso em que o aluno
  // ao tirar o dobro exato da nota de corte da reprovação, apareça 2 na
  // primeira divisão, indicando erroneamente que ele foi aprovado e reprovado
  // ao mesmo tempo. Para tanto, essa segunda expressao resulta em 0 em qualquer
  // nota maior ou igual a 90, impedindo o bug.
  int reprovado = 'N' + 5 * (1 - nota / 45) * (1 - nota / 90);
  printf("%c\n", reprovado);
  return 0;
}
