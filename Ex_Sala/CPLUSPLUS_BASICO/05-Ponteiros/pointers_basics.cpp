#include <iostream>
using namespace std;

int main() {
    int valor = 42;
    int* ponteiro = &valor;

    cout << "Valor: " << valor << endl;
    cout << "Endereço de valor: " << &valor << endl;
    cout << "Valor do ponteiro: " << ponteiro << endl;
    cout << "Valor apontado pelo ponteiro: " << *ponteiro << endl;

    return 0;
}
