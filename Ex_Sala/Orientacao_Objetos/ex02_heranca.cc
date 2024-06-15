#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Veiculo {
protected:
  string placa;
  string cor;
  string renavam;

public:
  Veiculo(string p, string c, string r) {
    placa = p;
    cor = c;
    renavam = r;
  };
  ~Veiculo(){};
  string getPlaca() { return placa; };
  string getCor() { return cor; };
  string getRenavam() { return renavam; };
};

class Carro : public Veiculo {
private:
  int portas;

public:
  Carro(string p, string c, string r, int po) : Veiculo(p, c, r) {
    portas = po;
  };
  ~Carro(){};
  void setPortas(int po) {
    if (po > 0) {
      portas = po;
    }
  };
  int getPortas() { return portas; };
};

class Onibus : public Veiculo {
private:
  int npassageiros;

public:
  Onibus(string p, string c, string r, int np) : Veiculo(p, c, r) {
    npassageiros = np;
  };
  ~Onibus(){};
  void setNPassageiros(int np) {
    if (np > 0) {
      npassageiros = np;
    }
  };
  int getNPassageiros() { return npassageiros; };
};

class Caminhao : public Veiculo {
private:
  float peso;

public:
  Caminhao(string p, string c, string r, float pe) : Veiculo(p, c, r) {
    peso = pe;
  };
  ~Caminhao(){};
  void setPeso(float pe) {
    if (pe > 0) {
      peso = pe;
    }
  };
  float getPeso() { return peso; };
};

// enum TipoVeiculo {
//   CARRO = typeid(Carro),
//   ONIBUS = typeid(Onibus),
//   CAMINHAO = typeid(Caminhao)
// };

int main(void) {
  fstream file;
  string line;
  file.open("veiculos.txt");
  if (!file.is_open()) {
    cout << "Erro ao abrir o arquivo" << endl;
    return 1;
  }
  string tipo;
  string placa;
  string cor;
  string renavam;
  int extra;

  vector<Veiculo> veiculos;
  // Veiculo *veiculos = new Veiculo[];

  while (file >> tipo >> placa >> cor >> renavam >> extra) {
    if (tipo == "CARRO") {
      Carro c(placa, cor, renavam, extra);
      veiculos.push_back(c);

    } else if (tipo == "ONIBUS") {
      Onibus o(placa, cor, renavam, extra);
      veiculos.push_back(o);

    } else if (tipo == "CAMINHAO") {
      Caminhao ca(placa, cor, renavam, extra);
      veiculos.push_back(ca);
    }
  }

  // Muito Confuso essa Linguagem
  for (int i = 0; i < veiculos.size(); i++) {
    cout << veiculos[i].getPlaca() << " " << veiculos[i].getCor() << " "
         << veiculos[i].getRenavam();
    if (typeid(veiculos[i]) == typeid(Carro)) {
      Carro* CarroPTR = static_cast<Carro *>(&veiculos[i]);
      cout << " " << CarroPTR->getPortas() << endl;
    } else if (typeid(veiculos[i]) == typeid(Onibus)) {
      Onibus* OnibusPTR = static_cast<Onibus *>(&veiculos[i]);
      cout << " " << OnibusPTR->getNPassageiros() << endl;
    } else if (typeid(veiculos[i]) == typeid(Caminhao)) {
      Caminhao* CaminhaoPTR = static_cast<Caminhao *>(&veiculos[i]);
      cout << " " << CaminhaoPTR->getPeso() << endl;
    }
  }
  // char opt;
  // cout << "Deseja adicionar um veículo? (s/n)" << endl;
  // cin >> opt;
  // while (opt != 'n') {
  //   cout << "Digite o tipo do veículo (CARRO, ONIBUS, CAMINHAO): ";
  //   cin >> tipo;
  //   cout << "Digite a placa: ";
  //   cin >> placa;
  //   cout << "Digite a cor: ";
  //   cin >> cor;
  //   cout << "Digite o renavam: ";
  //   cin >> renavam;
  //   cout << "Digite o valor extra: ";
  //   cin >> extra;
  //   if (tipo == "CARRO") {
  //     Carro c(placa, cor, renavam, extra);
  //     veiculos.push_back(c);

  //   } else if (tipo == "ONIBUS") {
  //     Onibus o(placa, cor, renavam, extra);
  //     veiculos.push_back(o);

  //   } else if (tipo == "CAMINHAO") {
  //     Caminhao ca(placa, cor, renavam, extra);
  //     veiculos.push_back(ca);
  //   }
  //   cout << "Deseja adicionar um veículo? (s/n)" << endl;
  //   cin >> opt;
  // }

  file.close();
}