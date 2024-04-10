#include <stdio.h>



int main(void){
	
	int n, ehPrimo=1;
	
	scanf("%d%*c", &n);
	
	for (int i = 2 ; i <= n/2 ; ++i){
		if (n % i == 0){
			ehPrimo = 0;
		}
	}
	
	if(ehPrimo){
		printf("O numero %d eh primo", n);
	} else {
		printf("O numero %d NAO eh primo", n);
		
	}
	
	return 0;
}

