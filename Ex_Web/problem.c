#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

bool problem(long int *menor, long int *maior, long int *number) {
  if (*number == 1) {
    return true;
  }
  if (*number % 2 == 0) {
    *number = *number / 2;
  } else {
    *number = 3 * (*number) + 1;
  }
  if (*number > *maior) {
    *maior = *number;
  }
  if (*number < *menor) {
    *menor = *number;
  }
  return problem(menor, maior, number);
}

int main(void) {
  int limit;
  scanf("%d", &limit);
  long int *results = (long int *)malloc(limit * sizeof(long int));
  long int number = 1;
  while (number < limit) {
    long int menor = number;
    long int maior = number;
    long int temp = number;
    bool getsto1 = problem(&menor, &maior, &temp);
    *(results + number) = maior;

    if (getsto1) {
      printf("For number %ld, the sequence reached 1.\n", number);
    } else {
      printf("For number %ld, the sequence did not reach 1.\n", number);
    }
    printf("The smallest number in the sequence was %ld.\n", menor);
    printf("The largest number in the sequence was %ld.\n", maior);

    number++;
    printf("\n");
  }

  return 0;
}