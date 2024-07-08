// Faça um programa que crie uma classe Matriz de NxM cujos atributos são protected. Depois crie um classe vetor que herde de matriz seus atributos e funções.
#include <iostream>

using namespace std;

class Matriz {
protected:
    int nl, nc;
    int *matriz;

public:
    // Construtor que inicializa o número de linhas, colunas e a matriz
    Matriz(int nl, int nc){
        this->nl = nl;
        this->nc = nc;
        this->matriz = new int[nl * nc];
    }

    // Destrutor que libera a memória alocada
    ~Matriz(){
        delete[] matriz;
    }

    // Função para obter o elemento na posição (i, j)
    int get(int i, int j){
        return matriz[i * nc + j];
    }

    // Retorna o número de linhas
    int getNumLinhas(){
        return nl;
    }

    // Retorna o número de colunas
    int getNumColunas(){
        return nc;
    }

    // Método recursivo para ler a matriz
    void lerMatriz(int count) {
        if (count == nc * nl) {
            return;
        }
        cin >> matriz[count];
        lerMatriz(count + 1); // Chamada recursiva para o próximo elemento
    }

    // Método recursivo para imprimir a matriz
    void imprimirMatriz(int count) {
        if (count == nc * nl) {
            return;
        }
        cout << matriz[count] << " ";
        if ((count + 1) % nc == 0) { // Se for o último elemento da linha, quebre a linha
            cout << endl;
        }
        imprimirMatriz(count + 1); // Chamada recursiva para o próximo elemento
    }

    // Função para definir o valor de um elemento na posição (i, j)
    void set(int i, int j, int valor){
        matriz[i * nc + j] = valor;
    }
};

int main(){
    int a_nc, a_nl, b_nc, b_nl;
    cin >> a_nc >> a_nl >> b_nc >> b_nl;

    try {
        if (a_nc != b_nl) {
            throw 1;
        } else if (a_nc == 0) {
           throw 2;
        }

        Matriz a(a_nl, a_nc); // Cria uma matriz A de a_nl x a_nc
        Matriz b(b_nl, b_nc); // Cria uma matriz B de b_nl x b_nc
        Matriz c(a_nl, b_nc); // Cria uma matriz C de a_nl x b_nc

        a.lerMatriz(0); // Inicia a leitura da matriz A
        b.lerMatriz(0); // Inicia a leitura da matriz B

        // Multiplicar as matrizes
        for (auto i = 0 ; i < a.getNumLinhas(); i++) {
            for (auto j = 0; j < b.getNumColunas(); j++) {
                c.set(i, j, 0);
                for (auto k = 0; k < a.getNumColunas(); k++) {
                    c.set(i, j, c.get(i, j) + a.get(i, k) * b.get(k, j));
                }
            }
        }

        c.imprimirMatriz(0);


    } catch (int error) {
        if (error == 1) {
            cout << "Número de colunas da matriz A diferente do número de linhas da matriz B" << endl;
        } else if (error == 2) {
            cout << "Matriz A ou B com número de colunas igual a zero" << endl;
        }
    }

}
