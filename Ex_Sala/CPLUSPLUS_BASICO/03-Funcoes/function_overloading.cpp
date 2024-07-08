
#include <iostream>
using namespace std;

// Funções sobrecarregadas para soma
int soma(int a, int b) {
    return a + b;
}

double soma(double a, double b) {
    return a + b;
}

int main() {
    int x = 10, y = 20;
    double p = 5.5, q = 6.5;

    cout << "Soma de inteiros: " << soma(x, y) << endl;
    cout << "Soma de doubles: " << soma(p, q) << endl;

    return 0;
}
