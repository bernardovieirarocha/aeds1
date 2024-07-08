#include <iostream>
#include <string> // Biblioteca para manipulação de strings
using namespace std;

int main() {
    // Declaração e inicialização de strings
    string saudacao = "Olá";
    string nome = "Mundo";

    // Concatenando strings
    string mensagem = saudacao + ", " + nome + "!";

    // Exibindo a string concatenada
    cout << mensagem << endl;

    // Obtendo o comprimento da string
    cout << "Comprimento da mensagem: " << mensagem.length() << endl;

    // Acessando caracteres individuais
    cout << "Primeiro caractere da mensagem: " << mensagem[0] << endl;

    return 0;
}
