#include <stdio.h> 


int main(void){
	
	int lado;
	scanf( "%d%*c", &lado);
	
	
	for (int i = 0 ; i < lado ;  ++i){
		for (int j = 0 ; j < lado; ++j){
			if ( i % 2 == 0){ // lina de index par
				if (j % 2 == 0 ){
					printf("*");
				} else {
					printf(" ");
				}
				
			} else {
				if (j % 2 != 0 ){
					printf("*");
				} else {
					printf(" ");
				}
			}
			
			
		}
		printf("\n");
	}
	
	return 0;
}