#include <iostream>
#include <queue>
using namespace std;

int main() {
  // Tipo long long pra evitar um problema de números muito grandes
  long long n, count = 0;
  cin >> n;

  queue<long long> q;
  q.push(1); // Inicia com 1, que é válido, sendo o primeiro número da sequência.

  while (!q.empty()) {
    // Pegar o número atual
    long long current = q.front();
    // Remover o número atual da fila
    q.pop();

    // Se o número atual é menor ou igual a n, é válido
    if (current <= n) {
      count++;
      // Gerar os próximos números
      q.push(current * 10);
      q.push(current * 10 + 1);
    }
  }
  // Imprimir a quantidade de números válidos
  cout << count << endl;
  return 0;
}
