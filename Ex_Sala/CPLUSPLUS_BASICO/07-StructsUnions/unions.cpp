#include <iostream>
using namespace std;

// Definição de uma união
union Dados {
    int inteiro;
    float flutuante;
    char caractere;
};

int main() {
    // Declarando e inicializando uma união
    Dados dado;
    dado.inteiro = 10;
    cout << "Inteiro: " << dado.inteiro << endl;

    dado.flutuante = 3.14;
    cout << "Flutuante: " << dado.flutuante << endl;

    dado.caractere = 'A';
    cout << "Caractere: " << dado.caractere << endl;

    // Note que apenas o último valor atribuído é válido
    cout << "Último valor atribuído (caractere): " << dado.caractere << endl;

    return 0;
}
