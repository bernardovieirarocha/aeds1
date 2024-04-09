#include <math.h>
#include <stdio.h>

// Uma forma de fazer:
int main(void) {
  int num;
  scanf("%d", &num);

  // inicialmente o n eh considerado como primo;
  int flag = 1;
  double sqroot = sqrt(num);
  for (int i = 2; i <= sqroot; ++i) {

    if (num % i == 0) {
      flag = 0;
      break;
    }
  }

  if (flag && num != 1) {
    printf("EH um primo");
  }

  return 0;
}

// Essa forma funciona também
// int main(void) {
// 	int num;
// 	scanf("%d", &num);
//
// 	// inicialmente o n eh considerado como primo;
// 	int flag=1;
// 	for (int i = 2; i <= num / 2; ++i) {
//
// 		if (num % i == 0) {
// 			flag = 0;
// 			break;
// 		}
// 	}
//
// 	if(flag && num != 1){
// 		printf("EH um primo");
// 	}
//
// 	return 0;
// }
//
