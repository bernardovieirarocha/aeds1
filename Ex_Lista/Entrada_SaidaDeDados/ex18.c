#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main() {
    float a, b, c, d, resultado_1, resultado_2;
    printf("entre com o valor de a:");
    scanf("%f", &a);
    printf("\nntre com o valor de b:");
    scanf("%f", &b);
    printf("\nentre com o valor de c:");
    scanf("%f", &c);
    d = pow(b,2)-4*a*c;
    resultado_1 = (-b + sqrt(d))/ (2*a);
    resultado_2 = (-b - sqrt(d))/ (2*a);
    printf("\nOs resultados sao: %f %f", resultado_1, resultado_2);
    return 0;
}

// esse codigo calcula as raizes de uma equacao de 2 grau