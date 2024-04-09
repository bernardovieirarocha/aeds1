#include <stdio.h>

int main(void) {
  int num;
  scanf("%d%*c", &num);
  printf("%c%c%c", 'S' - 5 * (num % 2), 'i' - 8 * (num % 2),
         'm' + 2 * (num % 2));
  return 0;
}