#include <iostream>
// Faça um programa que crie

using namespace std;

class Aluno {

public:
  Aluno() {
    media = 0;
    notaTrabalho = 0;
  }
  float getMedia() {
    if (media != 0) {
      return media;
    } else {
      cout << "Media não calculada" << endl;
    }
    return 0.0;
  }
  void setProvas(int provaindex, float nota) {
    if (provaindex > 0 && nota <= 30) { // nota 2 e 3
      notasProvas[provaindex] = nota;
    } else if (nota <= 20) { // nota 1
      notasProvas[provaindex] = nota;
    } else {
      cout << "Valor " << nota << " excede maximo da prova " << provaindex + 1
           << endl;
    }
  }
  void setTrabalho(int nota) { notaTrabalho = nota; }
  void calcularmedia() {
    if (notaTrabalho != 0) {
      media = notaTrabalho / 4;
      for (int i = 0; i < 3; ++i) {
        media += notasProvas[i] / 4;
      }
    } else {
      cout << "Please set value for notaTrabalho" << endl;
    }
  }

private:
  float notasProvas[3];
  float notaTrabalho; // como inicio variaveis com 0 na classe do C++??;
  float media;
};

int main(void) {
  Aluno bernardo;
  float nota;
  for (int i = 0; i < 3; ++i) {
    cin >> nota;
    bernardo.setProvas(i, nota);
  }
  cin >> nota;
  bernardo.setTrabalho(nota);
  bernardo.calcularmedia();
  float media = bernardo.getMedia();
  cout << "Sua media é: " << media << endl;
  if (media >= 24) { // 24 é 60% de 20 + 30 + 30;
    cout << "Aprovado" << endl;
  } else {
    cout << "Reprovado" << endl;
  }
}
