#include <math.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct {
  int n;
  int lado;
  int perimetro;
  float apotema;
  float area;
} poligonoregular;

int calcularPerimetro(int n, int lado) { return n * lado; }

float calcularApotema(int n, int lado) {
  float ANGULOradianos = M_PI / (float)n;
  float tangente = 2.00 * tan(ANGULOradianos);
  return (float)lado / tangente;
}

float calcularArea(float apotema, int perimetro) {
  return (perimetro * apotema) / 2;
}

int main(void) {

  poligonoregular poligono;
  scanf("%d%*c%d%*c", &poligono.n, &poligono.lado);
  poligono.perimetro = calcularPerimetro(poligono.n, poligono.lado);
  poligono.apotema = calcularApotema(poligono.n, poligono.lado);
  poligono.area = calcularArea(poligono.apotema, poligono.perimetro);

  printf("Perimetro: %d Area: %f \n", poligono.perimetro, poligono.area);
  return 0;
}