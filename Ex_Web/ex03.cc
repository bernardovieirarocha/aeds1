#include <iostream>
#include <string>
#include <vector>

using namespace std;

void lerMatriz(char *matriz, int count, int *accO, int *accX) {
    if (count == 9) {
        return;
    }
    cin >> matriz[count];
    if (matriz[count] == '0') {
        (*accO)++;
    } else if (matriz[count] == 'X') {
        (*accX)++;
    }
    lerMatriz(matriz, count + 1, accO, accX);
}

void vezdeQuem(int accX, int accO) {
    if (accX > accO) {
        cout << "second" << endl;
    } else {
        cout << "first" << endl;
    }
}

bool ganhador(char *matriz, char jogador) {
    // Verificar Linhas
    for (int i = 0; i < 3; i++) {
        if (matriz[i * 3] == jogador && matriz[(i * 3) + 1] == jogador && matriz[(i * 3) + 2] == jogador) {
            return true;
        }
    }

    // Verificar Colunas
    for (int i = 0; i < 3; ++i) {
        if (matriz[i] == jogador && matriz[i + 3] == jogador && matriz[i + 6] == jogador) {
            return true;
        }
    }

    // Verificar Diagonal Principal
    if (matriz[0] == jogador && matriz[4] == jogador && matriz[8] == jogador) {
        return true;
    }

    // Verificar Diagonal Secundária
    if (matriz[2] == jogador && matriz[4] == jogador && matriz[6] == jogador) {
        return true;
    }

    return false;
}

bool empate(char *matriz) {
    if (!ganhador(matriz, 'X') && !ganhador(matriz, '0')) {
        for (int i = 0; i < 9; i++) {
            if (matriz[i] == '.') {
                return false;
            }
        }
        return true;
    } else {
        return false;
    }
}

bool ilegal(int accX, int accO, char *matriz) {
    if (accO > accX || accX > accO + 1) {
        return true;
    }

    bool xWins = ganhador(matriz, 'X');
    bool oWins = ganhador(matriz, '0');

    if (xWins && oWins) {
        return true;
    }

    if (xWins && accX == accO) {
        return true;
    }

    if (oWins && accX > accO) {
        return true;
    }

    return false;
}

int main() {
    char *matriz = new char[9];
    int accX = 0; // Inicialização do acumulador de X
    int accO = 0; // Inicialização do acumulador de O

    lerMatriz(matriz, 0, &accO, &accX); // Correção da chamada

    if (ilegal(accX, accO, matriz)) {
        cout << "illegal" << endl;
    } else {
        if (ganhador(matriz, 'X')) {
            cout << "the first player won" << endl;
        } else if (ganhador(matriz, '0')) {
            cout << "the second player won" << endl;
        } else if (empate(matriz)) {
            cout << "draw" << endl;
        } else {
            vezdeQuem(accX, accO);
        }
    }

    delete[] matriz; // Não esqueça de liberar a memória alocada
    return 0;
}
