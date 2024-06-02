#include <cstdlib>
#include <iostream>

using namespace std;

namespace {
int somar(int a, int b) { return a + b; };
int subtrair(int a, int b) { return a - b; };

} // namespace

int main(void) {

  char *num = (char *)malloc(19 * sizeof(char));

  int m, n;
  cin >> m;
  cin >> n;

  int matriz[m][n];

  cin >> num;
  int qtdNumerosSorte = 0;
  int i = 0;
  while (num[i] != '\0') {
    if (num[i] == '4' || num[i] == '7') {
      qtdNumerosSorte++;
    }
    i++;
  }

  if (qtdNumerosSorte == 4 || qtdNumerosSorte == 7) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }
}
