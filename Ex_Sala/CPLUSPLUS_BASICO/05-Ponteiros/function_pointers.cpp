#include <iostream>
using namespace std;

void saudacao() {
    cout << "Olá, Mundo!" << endl;
}

void executarFuncao(void (*func)()) {
    func();
}

int main() {
    void (*ptrFunc)() = saudacao;
    executarFuncao(ptrFunc);

    return 0;
}
