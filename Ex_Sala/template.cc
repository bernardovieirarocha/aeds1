#include <cstdlib>
#include <iostream>
#include <string> // Add this line

using namespace std;

int dobro(int valor) { return 2 * valor; }

float dobro(float valor) { return 2 * valor; }

template <typename T> T dobro(T valor) { return 2 * valor; }

int main(void) { cout << dobro<string>("a") << endl; }
