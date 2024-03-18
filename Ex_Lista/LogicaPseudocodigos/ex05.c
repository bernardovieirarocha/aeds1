#include <stdio.h>
// Escreva um programa em Portugol e em C que receba dois números através da entrada do usuário e imprima:
// a) o maior deles; b) seu produto; c) a média aritmética; e d) a soma do antecessor do primeiro com o sucessor do segundo.

int main(void)
{
    float num1;
    float num2;
    scanf("%f, %f", &num1, &num2);
    float maior = (num1 > num2) ? num1 : num2 ;
    printf("O maior valor dentre os dois é: %.2f\n", maior);
    float produto = num1 * num2;
    printf("O produto dos dois números é: %.2f\n", produto);
    float media = (num1+num2) / 2;
    printf("A média aritmética dos dois números é: %.2f\n", media);
    float somaAntecessorSucessor = (num1-1) + (num2+1);
    printf("A soma do antecessor do primeiro com o sucessor do segundo é: %.2f\n", somaAntecessorSucessor);
}

// 