// Escreva um algoritmo que receba um número positivo do usuário e, como resposta, mostre o o
// cubo da soma dos algarismos ímpares . Por exemplo, caso o usuário forneça o número 1234, o cálculo a ser
// feito deverá ser (1 + 3)3 = 43 = 64 . Note que a quantidade de algarismos não é conhecida de antemão.
// ATENÇÃO! Não é permitido o uso da biblioteca math.h

#include <stdio.h>


int main(void) {

    int num, algarismo, acc=0,cuboSoma;
    scanf("%d", &num);

    // Um loop para existir até que não tenha mais dígitos
    while (num > 0) {
        int digit = num % 10; // fazer resto de 10 em um número inteiro devolve como resto o seu último algarismo.
        num /= 10; // divide por 10 pra tornar o penultimo o último e assim por diante percorrendo todo o número.

        if (digit % 2 != 0 ){ // se for ímpar faça a soma
            acc += digit;
        }  
    }

    cuboSoma = acc;

    for (int i = 1; i < 3 ; ++i ) { // exponencial 3, multiplicar a base por ela mesma 3 vezes.
        cuboSoma *= acc;
    }

    printf("Resposta: %d\n", cuboSoma);

    return 0;
}