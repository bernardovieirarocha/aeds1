#include <stdio.h>


int main(void){
	
	int num;
	scanf("%d%*c", &num);
	
	int maior,menor;
	
	maior = (num > 0) ? num:0;
	menor = (num > 0) ? num:0;
	
	for (int i = 0 ; i < 9; i++){
		scanf("%d%*c", &num);
		if(num > maior && num > 0 ){
			maior = num;
		}
		if (num < menor && num > 0 ) {
			menor = num;
		}
	}
	
	printf("Maior: %d Menor: %d", maior,menor);
	
	
	
	return 0 ;
}