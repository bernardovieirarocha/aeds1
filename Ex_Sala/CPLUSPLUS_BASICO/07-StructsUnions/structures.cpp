#include <iostream>
#include <string>
using namespace std;

// Definição de uma estrutura
struct Pessoa {
    string nome;
    int idade;
    float altura;
};

int main() {
    // Declarando e inicializando uma estrutura
    Pessoa pessoa1;
    pessoa1.nome = "João";
    pessoa1.idade = 30;
    pessoa1.altura = 1.75;

    // Acessando e exibindo membros da estrutura
    cout << "Nome: " << pessoa1.nome << endl;
    cout << "Idade: " << pessoa1.idade << endl;
    cout << "Altura: " << pessoa1.altura << endl;

    return 0;
}
