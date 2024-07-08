#include <iostream>
#include <string>
using namespace std;

// Definição de estruturas aninhadas
struct Endereco {
    string rua;
    int numero;
};

struct Pessoa {
    string nome;
    int idade;
    Endereco endereco;
};

int main() {
    // Declarando e inicializando uma estrutura aninhada
    Pessoa pessoa1;
    pessoa1.nome = "Maria";
    pessoa1.idade = 25;
    pessoa1.endereco.rua = "Rua das Flores";
    pessoa1.endereco.numero = 123;

    // Acessando e exibindo membros da estrutura aninhada
    cout << "Nome: " << pessoa1.nome << endl;
    cout << "Idade: " << pessoa1.idade << endl;
    cout << "Endereço: " << pessoa1.endereco.rua << ", " << pessoa1.endereco.numero << endl;

    return 0;
}
