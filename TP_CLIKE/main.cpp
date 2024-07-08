#include <iostream>
using namespace std;

// Função para verificar se um número é primo
bool ehPrimo(int num) {
    if (num <= 1) return false;
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) return false;
    }
    return true;
}

int main() {
    int n;
    cout << "Digite um numero inteiro: ";
    cin >> n;

    if (ehPrimo(n)) {
        cout << n << " é um número primo." << endl;
    } else {
        cout << n << " não é um número primo." << endl;
    }

    cout << "Números primos menores que " << n << ":" << endl;
    for (int i = 2; i < n; i++) {
        if (ehPrimo(i)) {
            cout << i << " ";
        }
    }
    cout << endl;

    return 0;
}