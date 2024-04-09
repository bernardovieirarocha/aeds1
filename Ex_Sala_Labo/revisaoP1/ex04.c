#include <stdio.h>

int main(void) {
  int num, esquerda, direita, i, res, iters;
  scanf("%d", &num);

  esquerda = direita = 1;
  iters = (num / 2);
  for (i = 1; i <= iters; ++i) {
    esquerda *= i;
    direita *= (num - i + 1);
    printf("1\n");
  }

  res = esquerda * direita;

  if (num % 2 == 1) {
    res *= i;
  }

  printf("%d\n", res);

  return 0;
}

// #include <stdio.h>

// int main(void) {
// 	int num;
// 	scanf("%d",&num);

// 	int ultimo = num--;
// 	int anteultimo = ultimo--;

// 	int acc= 2*(ultimo * anteultimo);

// 	for (int i = 3 ; i < ultimo--; ++i) {
// 		acc *= i;

// 	}

// 	printf("%d\n", acc);

// 	return 0;
// }