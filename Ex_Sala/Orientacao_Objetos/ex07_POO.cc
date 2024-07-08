#include <iostream>
#include <cmath>

using namespace std;

class Poligono {
protected:
  int n_lados;
  int *angulos_internos = nullptr;
  int *lados = nullptr;
  int **pontos = nullptr; // Should be an array of int pointers

public:
  Poligono(int n) {
    angulos_internos = new int[n];
    lados = new int[n];
    pontos = new int *[n];
    for (int i = 0; i < n; i++) {
      pontos[i] = new int[2]; // Each point has two coordinates (x, y)
    }
  }
  ~Poligono() {}
  int getNLados() { return n_lados; }
  int *getAngulosInternos() { return angulos_internos; }
  int *getLados() { return lados; }
  int **getPontos() { return pontos; }

  void setAngulosInternos(int angulo, int index) {
    angulos_internos[index] = angulo;
  }
  void setLados(int tamanho, int index) { lados[index] = tamanho; }
  void setPontos(int x, int y, int index) {
    pontos[index][0] = x;
    pontos[index][1] = y;
  }
};

class Quadrado : public Poligono {
public:
  Quadrado(int angulos) : Poligono(4) {}
  ~Quadrado() {}
  float calculaArea() {
    cout << "Calculating area" << endl;
    cout << lados[0] << endl;
  }
  float calculaPerimetro() { return lados[0] * 4; }
  int *calcularBaricentro() {
    int *coordenadasBaricentro = new int[2]{0, 0};
    for (int i = 0; i < 4; i++) {
      coordenadasBaricentro[0] += pontos[i][0];
      coordenadasBaricentro[1] += pontos[i][1];
    }
    coordenadasBaricentro[0] /= 4;
    coordenadasBaricentro[1] /= 4;
    return coordenadasBaricentro;
  }
  void calcularLados() {
    for (int i = 0; i < 4; i++) {
      int nextIndex = (i + 1) % 4;
      lados[i] = sqrt(pow(pontos[nextIndex][0] - pontos[i][0], 2) +
                      pow(pontos[nextIndex][1] - pontos[i][1], 2));
    }
  }
};

class Triangulo : public Poligono {
public:
  Triangulo(int angulos) : Poligono(3) {}
  ~Triangulo() {}
};

int main(void) {
  Quadrado q(1);

  // Set angles
  for (int i = 0; i < 4; i++) {
    q.setAngulosInternos(90, i);
  }

  // Set points
  for (int i = 0; i < 4; i++) {
    int x, y;
    cout << "Enter coordinates for point " << i << " (format: x y): ";
    cin >> x >> y;
    q.setPontos(x, y, i);
  }

  // Calculate sides
  q.calcularLados();

  cout << "Area: " << q.calculaArea() << endl;
  cout << "Perimeter: " << q.calculaPerimetro() << endl;
  int *baricentro = q.calcularBaricentro();
  cout << "Baricentro: (" << baricentro[0] << ", " << baricentro[1] << ")"
       << endl;

  // Output angles
  for (int i = 0; i < 4; i++) {
    cout << "Angle " << i << ": " << q.getAngulosInternos()[i] << endl;
  }

  // Optionally output coordinates to verify
  for (int i = 0; i < 4; i++) {
    cout << "Point " << i << ": (" << q.getPontos()[i][0] << ", "
         << q.getPontos()[i][1] << ")" << endl;
  }

  return 0;
}
