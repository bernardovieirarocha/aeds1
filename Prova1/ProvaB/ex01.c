// Analise o código abaixo e explique o seu funcionamento indicando, de maneira objetiva, qual o
// cômputo realizado. Justifique sua resposta através das linhas de código apresentadas.

#include <stdio.h>

int main(void){
    int i, x, e, y;
    float t, v;
    x = 2;
    scanf("%d%*c", &y); // Recebe o valor que será o expoente.
    e = y; v = x; // A base torna-se um valor ponto flutuante.
    if(e*e*e < 0) { e *= -1; v = 1/v; } // Caso o expoente seja negativo inverte-se a base e transforme o para positivo

    t = v; 
    if(e % 2 == 1) { --e; } // Se o expoente for ímpar decrementa-se um.
    for(i = 1; i < e; i += 2) { t *= v*v; } // A primeira interação do loop inicia com 2^3 e para cada próxima iteração agrega-se ^2 
    // Logo esse loop produz (2^3 ; 2^5 ; 2^7...)
    if(y % 2 == 0){ t /= v; } // Caso o expoente deseja pelo usuário tivesse sido par é preciso dividir pela base para voltar um expoente, pois o loop devolve os expoentes ímpares.
    
    printf("%f\n", t);

    return 0;
}