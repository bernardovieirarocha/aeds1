#include <math.h>
#include <stdio.h>

int main(void) {
  float x, t, theta, y;
  float vo, ay;

  printf("Distancia percorrida ate o ponto P x: ");
  scanf("%f", &x);
 
  printf("Tempo transcorrido ate o ponto P t: ");
  scanf("%f", &t);

  printf("Angulo de lancamento 0: ");
  scanf("%f", &theta);

  // Calculo da velocidade inicial do projetil
  vo = x / (t * cos(theta));

  ay = -9.8; // Assumindo que gravidade eh -9.8m/sˆ2

  // Calculo da altura maxima no ponto P
  y = vo * sin(theta) * t + 0.5 * ay * pow(t, 2);

  // Output the result
  printf("A altura máxima (h_max) no ponto P eh: %f\n", y*-1);
}
