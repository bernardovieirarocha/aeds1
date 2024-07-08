#include <stdio.h>
#include <stdbool.h>

// Função para verificar se um número é primo
bool ehPrimo(int num) {
    if (num <= 1) return false; // Números menores que 2 não são primos
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) return false; // Se num é divisível por i, então não é primo
    }
    return true;
}

int main() {
    int n;

    printf("Digite um numero inteiro: ");
    scanf("%d", &n);

    // Verificação se o número digitado é primo
    if (ehPrimo(n)) {
        printf("%d é um número primo.\n", n);
    } else {
        printf("%d não é um número primo.\n", n);
    }

    // Listar todos os números primos menores que n
    printf("Números primos menores que %d:\n", n);
    for (int i = 2; i < n; i++) {
        if (ehPrimo(i)) {
            printf("%d ", i);
        }
    }
    printf("\n");

    return 0;
}
