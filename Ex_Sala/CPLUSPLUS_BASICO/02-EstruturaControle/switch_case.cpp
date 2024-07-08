#include <iostream>
using namespace std;

int main() {
    int opcao;
    cout << "Escolha uma opção (1-3): ";
    cin >> opcao;

    switch (opcao) {
        case 1:
            cout << "Opção 1 selecionada." << endl;
            break;
        case 2:
            cout << "Opção 2 selecionada." << endl;
            break;
        case 3:
            cout << "Opção 3 selecionada." << endl;
            break;
        default:
            cout << "Opção inválida." << endl;
            break;
    }

    return 0;
}
