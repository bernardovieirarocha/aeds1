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