//Escreva um programa em Portugol e em C que receba através da entrada do usuário, dois números a serem comparados. 
//O programa deve imprimir o maior dos dois, mas caso sejam iguais, deve imprimir "os números são iguais".
#include <stdio.h>

int main(void) {
    float num1, num2, maior;
    printf("Insira os dois valores a serem comparados: ");
    scanf("%f %f", &num1,&num2);
    if (num1 == num2) {
        printf("Os números são iguais\n");
    } else {
        maior = (num1 > num2) ? num1 : num2;
        printf("O maior número é: %f\n", maior);
    }
    return 0;
}