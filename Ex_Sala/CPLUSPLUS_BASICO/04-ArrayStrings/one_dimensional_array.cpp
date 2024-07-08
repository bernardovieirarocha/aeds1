#include <iostream>
using namespace std;

int main() {
    // Declaração e inicialização de um array unidimensional
    int array[5] = {1, 2, 3, 4, 5};

    // Acessando e exibindo elementos do array
    cout << "Elementos do array: ";
    for (int i = 0; i < 5; ++i) {
        cout << array[i] << " ";
    }
    cout << endl;

    return 0;
}
