#include <stdio.h>


int main(void){
	
	
	int n ;
	scanf("%d%*c", &n);
	
	for ( int i = n ; i >= 0 ; i--) {
		int resto = n - ((i/70) * 70);
		if(resto){
			printf("%d ", i);
		} 
	}
	
	
	return 0;
}