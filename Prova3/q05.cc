// Basicamente a PROVA 3 era uma questão só, porém era dividida em outras questões que te pediam parte desse código, para que você montasse ele em partes.
#include <cmath>
#include <iostream>

using namespace std;

class Salao {
  int l, c;
  int **pontos;            // [[x,y] , [x,y], [x,y], [x,y]]
  double *raiosTapetes;    // [raio1, raio2.. ]
  double *areaEscritorios; // [area1, area2..]
  double areaRectInscrito; // Hall

public:
  Salao(int l, int c) {
    this->l = l;
    this->c = c;
    pontos = new int *[4];
    for (int i = 0; i < 4; i++) {
      pontos[i] = new int[2];
    }
    raiosTapetes = new double[4];
    areaEscritorios = new double[4];
  }
  void setPonto(int x, int y, int i) {
    pontos[i][0] = x;
    pontos[i][1] = y;
  }
  int getL() { return l; }
  int getC() { return c; }
  int **getPontos() { return pontos; }
  double areaSalao() { return l * c; }
  double raio_tapeteEsc(double lado1, double lado2, double lado3) {
    double s = (lado1 + lado2 + lado3) / 2.0;
    double area = sqrt(s * (s - lado1) * (s - lado2) * (s - lado3));
    return 2 * area / (lado1 + lado2 + lado3);
  }
  void calcularAreasRaios() {
    for (int i = 0; i < 4; i++) {
      int next = (i + 1) % 4;
      double lado1 = abs(c - pontos[i][0]);
      double lado2 = abs(l - pontos[next][1]);
      double hipotenusa = sqrt(pow(lado1, 2) + pow(lado2, 2));
      raiosTapetes[i] = raio_tapeteEsc(lado1, lado2, hipotenusa);
      areaEscritorios[i] = (lado1 * lado2) / 2;
    }
  }
  double calcularAreaRectInscrito() {
    double ladoA = abs(pontos[0][1] - pontos[1][1]); // PQ
    double ladoB = abs(pontos[2][0] - pontos[3][0]); // SR

    areaRectInscrito = ladoA * ladoB;
    return areaRectInscrito;
  }

  void imprimir() {
    cout << "Salao: " << l << " " << c << endl;
    cout << "Pontos: " << endl;
    for (int i = 0; i < 4; i++) {
      cout << pontos[i][0] << " " << pontos[i][1] << endl;
    }
    cout << "Raios: " << endl;
    for (int i = 0; i < 4; i++) {
      cout << raiosTapetes[i] << endl;
    }
    cout << "Areas: " << endl;
    for (int i = 0; i < 4; i++) {
      cout << areaEscritorios[i] << endl;
    }
    cout << "Área Salão: " << this->areaSalao() << endl;
    cout << "Área Rect Inscrito (HALL) " << this->calcularAreaRectInscrito()
         << endl;
  }
};

int main(void) {
  int l, c;
  cin >> l >> c;
  Salao s(l, c);

  for (int i = 0; i < 4;) {
    int x, y;
    cin >> x >> y;
    s.setPonto(x, y, i);
  }
}
