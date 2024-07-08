#include <iostream>
using namespace std;

int main() {
    int numero;
    cout << "Digite um número positivo (ou negativo para sair): ";
    cin >> numero;

    while (numero >= 0) {
        cout << "Você digitou: " << numero << endl;
        cout << "Digite outro número positivo (ou negativo para sair): ";
        cin >> numero;
    }

    cout << "Número negativo digitado. Saindo..." << endl;

    return 0;
}
