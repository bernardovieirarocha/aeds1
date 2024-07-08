#include <iostream>
#include <memory>
using namespace std;

class Exemplo {
public:
    Exemplo() {
        cout << "Construtor do Exemplo chamado!" << endl;
    }
    ~Exemplo() {
        cout << "Destrutor do Exemplo chamado!" << endl;
    }
    void mostrar() {
        cout << "Método mostrar do Exemplo." << endl;
    }
};

int main() {
    // Usando unique_ptr
    unique_ptr<Exemplo> ptr1(new Exemplo());
    ptr1->mostrar();

    // Usando make_unique (C++14)
    auto ptr2 = make_unique<Exemplo>();
    ptr2->mostrar();

    // Usando shared_ptr
    shared_ptr<Exemplo> ptr3 = make_shared<Exemplo>();
    ptr3->mostrar();

    // Usando weak_ptr
    weak_ptr<Exemplo> weakPtr = ptr3;
    if (auto tempPtr = weakPtr.lock()) {
        tempPtr->mostrar();
    } else {
        cout << "O objeto já foi desalocado." << endl;
    }

    return 0;
}
