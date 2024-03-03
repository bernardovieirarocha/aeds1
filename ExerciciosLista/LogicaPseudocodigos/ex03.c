// João, um aluno de ensino médio, precisa tirar 10 pontos na sua prova final
// para poder passar na etapa. Crie um programa, em Portugol e em C, que receba
// do usuário a nota de João e, caso seja menor do que 10, imprima "reprovado".
// Caso seja igual ou maior que 10, imprima "aprovado".

#include <stdio.h>

int main(void) {
  float nota;
  printf("Digite sua nota: ");
  scanf("%f", &nota); // nao pode ter nada antes do scanf, ele tentar da um
                      // match exato por onde você coloca %
  printf("Você foi: %s por ter nota: %.2f\n",
         (nota >= 10) ? "aprovado" : "reprovado", nota);
  return 0;
}