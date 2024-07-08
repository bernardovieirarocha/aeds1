#include <iostream>
using namespace std;

// Classe base
class Veiculo {
public:
    virtual void descricao() const {
        cout << "Isto é um veículo." << endl;
    }

    // Tornando o destrutor virtual para garantir que o destrutor correto seja chamado para objetos derivados
    virtual ~Veiculo() = default;
};

// Classe derivada 1
class Carro : public Veiculo {
public:
    void descricao() const override {
        cout << "Isto é um carro." << endl;
    }
};

// Classe derivada 2
class Moto : public Veiculo {
public:
    void descricao() const override {
        cout << "Isto é uma moto." << endl;
    }
};

// Classe derivada 3
class Caminhao : public Veiculo {
public:
    void descricao() const override {
        cout << "Isto é um caminhão." << endl;
    }
};

int main() {
    // Criando objetos das classes derivadas
    Veiculo* veiculo1 = new Carro();
    Veiculo* veiculo2 = new Moto();
    Veiculo* veiculo3 = new Caminhao();

    // Usando polimorfismo para chamar a função apropriada
    veiculo1->descricao(); // Saída: Isto é um carro.
    veiculo2->descricao(); // Saída: Isto é uma moto.
    veiculo3->descricao(); // Saída: Isto é um caminhão.

    // Limpando a memória alocada
    delete veiculo1;
    delete veiculo2;
    delete veiculo3;

    return 0;
}
