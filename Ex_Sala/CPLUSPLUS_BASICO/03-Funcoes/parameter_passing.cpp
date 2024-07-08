#include <iostream>
using namespace std;

// Função com parâmetros passados por valor
void porValor(int x) {
    x = 20;
}

// Função com parâmetros passados por referência
void porReferencia(int &x) {
    x = 20;
}

int main() {
    int a = 10;
    int b = 10;

    porValor(a);
    cout << "Após porValor, a = " << a << endl; // a ainda é 10

    porReferencia(b);
    cout << "Após porReferencia, b = " << b << endl; // b agora é 20

    return 0;
}
