#include <stdio.h>

int main(void) {

  int num;
  scanf("%d", &num);

  // resto = num - quociente;
  int quociente = num / 213;
  int resto = 213 * (quociente)-num;

  if (resto == 0) {
    printf("O numero %d eh divisivel por 3 7 e 11 simultaneamente", num);
  } else {
    printf("O numero %d NAO eh divisivel por 3 7 e 11 simultaneamente", num);
  }

  return 0;
}