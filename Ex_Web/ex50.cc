// The maxDominoes function calculates the maximum number of 2x1 dominoes that
// can be placed on an MxN board.

// Here's how it works:

// If the number of columns N is even, each row can be fully covered by 2x1
// dominoes. Since each domino covers 2 squares, the total number of dominoes is
// M * N / 2.

// If the number of columns N is odd, each row can be covered by N / 2 dominoes,
// leaving one square uncovered in each row. This covers M * (N / 2) squares.

// Additionally, if the number of rows M is even, one additional domino can be
// placed in the last column of the first M - 1 rows. This covers an additional
// M / 2 squares.

// Therefore, the total number of dominoes is M * (N / 2) + M / 2.

#include <cstdlib>
#include <iostream>

using namespace std;

int maxDominoes(int M, int N) {
  // Check if the number of columns is even, in which case all squares can be
  // covered.
  if (N % 2 == 0) {
    return M * N / 2;
  } else {
    // If the number of columns is odd, only even rows can be covered with
    // dominoes.
    return M * (N / 2) + M / 2;
  }
}

int main(void) {
  // Read the number of rows and columns.
  int M, N;
  cin >> M;
  cin >> N;

  int maxDominos = maxDominoes(M, N);
  cout << maxDominos << endl;

  return 0;
}
