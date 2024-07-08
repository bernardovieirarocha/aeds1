#include <iostream>
using namespace std;

int main() {
    int array[5] = {10, 20, 30, 40, 50};
    int* ponteiro = array;

    for (int i = 0; i < 5; ++i) {
        cout << "Valor no índice " << i << ": " << *(ponteiro + i) << endl;
    }

    return 0;
}
