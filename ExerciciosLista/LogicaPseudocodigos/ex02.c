// Considerando a linguagem C, determine o tipo das variáveis que armazenam os
// seguintes valores: a) 7 int b) P char c) 3.141592653 double d) 78.3 float e)
// 0 int f) 3.3333 float g) TRUE char h) FALSO char i) 128742 int j) 0.0 foat
#include <stdio.h>
// #include <string.h> biblioteca que fornece alguns metodos para lidar melhor
// com strings

int main(void) {
  int a = 7;
  char b = 'P';
  double c = 3.142593653;
  float d = 78.3;
  int e = 0;
  float f = 3.3333;
  char g[5] = "TRUE"; // existe um caractere extra de final
  char h[6] = "FALSE";
  int i = 128742;
  float j = 0.0;

  printf("a: %d\n", a);
  printf("b: %c\n", b);
  printf("c: %lf\n", c);
  printf("d: %f\n", d);
  printf("e: %d\n", e);
  printf("f: %f\n", f);
  printf("g: %s\n", g);
  printf("h: %s\n", h);
  printf("i: %d\n", i);
  printf("j: %f\n", j);

  return 0;
}