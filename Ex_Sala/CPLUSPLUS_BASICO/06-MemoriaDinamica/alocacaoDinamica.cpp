#include <iostream>
using namespace std;

int main() {
    int linhas, colunas;

    cout << "Digite o número de linhas: ";
    cin >> linhas;
    cout << "Digite o número de colunas: ";
    cin >> colunas;

    // Alocação dinâmica de um array bidimensional usando ponteiros de ponteiros
    int** array = new int*[linhas];
    for (int i = 0; i < linhas; ++i) {
        array[i] = new int[colunas];
    }

    // Inicialização e impressão dos valores do array bidimensional
    cout << "Inicializando array bidimensional..." << endl;
    for (int i = 0; i < linhas; ++i) {
        for (int j = 0; j < colunas; ++j) {
            array[i][j] = i * colunas + j;
        }
    }

    cout << "Elementos do array bidimensional:" << endl;
    for (int i = 0; i < linhas; ++i) {
        for (int j = 0; j < colunas; ++j) {
            cout << array[i][j] << " ";
        }
        cout << endl;
    }

    // Desalocação da memória do array bidimensional
    for (int i = 0; i < linhas; ++i) {
        delete[] array[i];
    }
    delete[] array;

    return 0;
}
