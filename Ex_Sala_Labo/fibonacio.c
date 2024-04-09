#include <stdio.h>

int main() {
  int n, i;
  int a = 0, b = 1, nextTerm, sum = 0;

  printf("Digite um número inteiro positivo: ");
  scanf("%d", &n);

  printf("Sequência de Fibonacci até %d: ", n);
  for (i = 1; i <= n; ++i) {
    if (a != 0) {
      printf("%d, ", a);
    }
    sum += a;
    nextTerm = a + b;
    a = b;
    b = nextTerm;
  }

  printf("\nSoma dos termos da sequência até %d: %d\n", n, sum);

  return 0;
}

// Somente o Display da sequencia
// #include <stdio.h>
//
//
// int main(void) {
// 	int a=0, b=1, num, nextTerm;
//
// 	scanf("%d%*c", &num);
//
// 	printf("0 ");
// 	for (int i = 1 ; i <= num; i++){
//
// 		if ( a != 0 ) {
// 			printf("%d ", a);
//
// 		}
//
// 		nextTerm = a + b;
// 		a = b;
// 		b = nextTerm;
// 	}
//
// 	return 0;
// }
