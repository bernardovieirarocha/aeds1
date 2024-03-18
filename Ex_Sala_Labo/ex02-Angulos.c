// ATENÇÃO: Este é um exercício para ser feito em sala de aula. Logo, entregas
// de alunos(as) que não estiverem presentes no dia da aplicação, terão suas
// entregas desconsideradas.
// ENUNCIADO Faça um programa que receba a medida de um ângulo Calcule e mostre
// o quadrante em que se localiza esse ângulo.Caso esteja sobre algum eixo,
// exibir a mensagem "Este ângulo se encontra em um dos eixos".Considere s
// quadrantes da trigonometria e, para ângulos maiores que 360o ou menores que
// −360, reduzi - los, mostrando também o número de voltas e o sentido da
// volta(horário ou anti-horário).Finalmente, mostre a quantidade de graus que
// falta para aumentar a quantidade de voltas.
#include <stdio.h>

int main() {
  int angle, resto, voltas, quantofalta;
  // Input do ângulo
  printf("Digite o ângulo: ");
  scanf("%d", &angle);
  // determina se o ângulo está no eixo
  if (angle % 90 == 0) {
    printf("Este ângulo se encontra em um dos eixos.\n");
  }
  // Acha o resto da divisão do ângulo por 360, basicamente pulando as voltas
  // completas direto pra posição final, podendo assim determinar o quadrante.
  resto = angle % 360;
  // Descobrir o quanto falta para dar 360 tanto no caso de ser negativo quanto
  // no caso de ser positivo.
  if (resto < 0) {
    // Exemplo da lógica: se o angulo for negativo (-405) vai dar o resto (-45)
    // e fazendo a soma com 360 eu descubro o quanto falta para completar a
    // volta.
    quantofalta = resto + 360;
  } else {
    quantofalta = 360 - resto;
  }
  // Descobrir quantas voltas completas o ângulo deu:
  voltas = angle / 360;
  if (angle > 0 || angle == 0) {
    // se o angulo é positivo ou 0 descubra qual quadrante ele está
    if (resto >= 0 && resto <= 90) {
      printf("Primeiro quadrante.\n");
    } else if (resto > 90 && resto <= 180) {
      printf("Segundo quadrante.\n");
    } else if (resto > 180 && resto <= 270) {
      printf("Terceiro quadrante.\n");
    } else if (resto > 270 && resto <= 360) {
      printf("Quarto quadrante.\n");
    }
    printf("%d volta(s) (sentido horário).\n", voltas);
    voltas++;
    printf("Falta(m) %d graus (sentido horário) para completar %d volta(s).\n",
           quantofalta, voltas);
  } else {
    // Transforma voltas em positivo, pois o sentido já está pre-determinado no
    // printf e também porque é preciso incrementar um para dar display da
    // proxima volta transforma o resto em positivo para fazer o if com números
    // positivos porém percorrendo a lógica inversa.
    voltas *= -1;
    resto *= -1;
    // Se o angulo é negativo descubra qual quadrante ele está:
    if (resto >= 0 && resto <= 90) {
      printf("Quarto quadrante.\n");
    } else if (resto > 90 && resto <= 180) {
      printf("Terceiro quadrante.\n");
    } else if (resto > 180 && resto <= 270) {
      printf("Segundo quadrante.\n");
    } else if (resto > 270 && resto <= 360) {
      printf("Primeiro quadrante.\n");
    }
    printf("%d volta(s) (sentido anti-horário).\n", voltas);
    // incremento para poder mostra qual é a próxima volta que ele dará nesse
    // sentido já pré determinado.
    voltas++;
    printf("Falta(m) %d graus (sentido anti-horário) para completar %d "
           "volta(s).\n",
           quantofalta, voltas);
  }
  return 0;
}