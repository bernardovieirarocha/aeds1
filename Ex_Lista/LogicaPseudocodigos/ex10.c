// Para cada um dos problemas a seguir, expresse um algoritmo que possa ser
// utilizado para solucioná-lo. Utilize o Portugol e passe para a linguagem C.
// a) Leia três notas e seus respectivos pesos, calcule e mostre a média
// ponderada dessas notas. b) Receba uma temperatura dada na escala Celsius (C)
// e imprima o equivalente em Fahrenheit (F). c) Leia uma quantidade em horas e
// imprima seu valor em segundos. (Nota: Em (b) use a fórmula de conversão: F =
// 95 C + 32)

#include <stdio.h>

float letraA_notas(float nota1, float nota2, float nota3, float peso1,
                   float peso2, float peso3) {
  float media;
  media =
      (nota1 * peso1 + nota2 * peso2 + nota3 * peso3) / (peso1 + peso2 + peso3);
  return media;
}

float letraB_temperatura(float temperatura_celsius) {
  float temperatura_fahrenheit = (9 * temperatura_celsius) / 5 + 32;
  return temperatura_fahrenheit;
}

float letraC_segundos(float horas) {
  float segundos = 3600 * horas;
  return segundos;
}

int main(void) {
  char escolha;
  printf("Escreva qual opção deseja executar: (a-c) ");
  scanf("%c%*c", &escolha);
  float nota1, nota2, nota3;
  float peso1, peso2, peso3;
  float temperatura_celsius;
  float horas;
  switch (escolha) {
  case 'a':
    printf("Digite a primeira nota: ");
    scanf("%f%*c", &nota1);
    printf("Digite o peso da primeira nota: ");
    scanf("%f%*c", &peso1);

    printf("Digite a segunda nota: ");
    scanf("%f%*c", &nota2);
    printf("Digite o peso da segunda nota: ");
    scanf("%f%*c", &peso2);

    printf("Digite a terceira nota: ");
    scanf("%f%*c", &nota3);
    printf("Digite o peso da terceira nota: ");
    scanf("%f%*c", &peso3);

    printf("A média ponderada das notas é: %.2f\n",
           letraA_notas(nota1, nota2, nota3, peso1, peso2, peso3));
    break;
  case 'b':
    printf("Digite a temperatura em Celsius: ");
    scanf("%f%*c", &temperatura_celsius);
    printf("A temperatura em Fahrenheit é: %.2f",
           letraB_temperatura(temperatura_celsius));
    break;
  case 'c':
    printf("Digite quantas horas deseja converter: ");
    scanf("%f%*c", &horas);
    printf("%.1f horas são %.1f segundos. ", horas, letraC_segundos(horas));
    break;
  default:
    printf("Essa opção não existe! \n");

    break;
  }

  return 0;
}
