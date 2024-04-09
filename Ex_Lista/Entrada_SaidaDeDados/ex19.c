#include <stdio.h>
#include <math.h>


int main(void) {
	int n1,n2;
	float res;
	char letraopt;
	int inicio,fim;
	float base, expoente;
	
	scanf(" %c%*c",&letraopt);
	
	switch (letraopt) {
		case 'a':
			res = 0;
			n1 = 0; n2 = 0;
			scanf(" %d %d%*c",&n1, &n2);
			res = n1 % n2;
			printf("%1.f",res);
			break;
		case 'b':
			scanf(" %d %d%*c",&inicio, &fim);
			for(int i = inicio; i < fim+1; ++i)
			{
				printf("%d ", i);
			}
			break;
		case 'c':
			scanf(" %f %f%*c",&base, &expoente);
			res = 0;
			res = pow(base, expoente);
			printf("%2.f ", res);
			break;
		case 'd':
			n1=0;n2=0;res = 0;
			scanf(" %d%*c",&n1);
			res = sqrt(n1);
			printf("%.2f", res);
			break;
		default:
			printf("Burro!");
			
	
	}
	
	
	return 0;
}