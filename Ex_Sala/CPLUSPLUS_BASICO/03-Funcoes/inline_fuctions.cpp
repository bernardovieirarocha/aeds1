#include <iostream>
using namespace std;

// Função inline
inline int quadrado(int x) {
    return x * x;
}

int main() {
    int numero;
    cout << "Digite um número para calcular o quadrado: ";
    cin >> numero;

    cout << "O quadrado de " << numero << " é " << quadrado(numero) << endl;

    return 0;
}
