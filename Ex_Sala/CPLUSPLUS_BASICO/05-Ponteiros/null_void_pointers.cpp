#include <iostream>
using namespace std;

int main() {
    int* ponteiroNulo = nullptr;
    void* ponteiroVoid;
    int valor = 10;
    
    ponteiroVoid = &valor;
    
    cout << "Ponteiro nulo: " << ponteiroNulo << endl;
    cout << "Ponteiro void apontando para valor: " << *(static_cast<int*>(ponteiroVoid)) << endl;

    return 0;
}
