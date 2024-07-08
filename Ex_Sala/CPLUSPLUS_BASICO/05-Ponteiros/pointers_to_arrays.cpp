#include <iostream>
using namespace std;

void imprimirArray(int* array, int tamanho) {
    for (int i = 0; i < tamanho; ++i) {
        cout << "Elemento " << i << ": " << array[i] << endl;
    }
}

int main() {
    int array[5] = {1, 2, 3, 4, 5};
    imprimirArray(array, 5);

    return 0;
}
