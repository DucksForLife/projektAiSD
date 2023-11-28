#include <cstdlib>
#include <ctime>
#include <iostream>

using namespace std;

int main() {
  srand(static_cast<unsigned int>(time(0)));
  int N = rand() % 45 + 5;
  int M = rand() % 45 + 5;
  int tab[N][M];

  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < M; ++j) {
      tab[i][j] = rand() % 6;
      if (tab[i][j] > 1) {
        tab[i][j] = 0;
      }
    }
  }
  // Generuj plusy
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < M; ++j) {
      if (tab[i][j] == 1) {
        if (tab[i][j - 2] == 0 && tab[i][j - 1] == 0 &&
            tab[i - 1][j - 1] == 0 && tab[i + 1][j - 1] == 0 &&
            tab[i - 1][j] == 0 && tab[i + 1][j] == 0 && tab[i - 2][j] == 0 &&
            tab[i + 2][j] == 0 && tab[i - 1][j + 1] == 0 &&
            tab[i + 1][j + 1] == 0 && tab[i][j + 1] == 0 &&
            tab[i][j + 2] == 0) {
          if (i - 1 >= 0)
            tab[i - 1][j] = 1;
          if (i + 1 < N)
            tab[i + 1][j] = 1;
          if (j - 1 >= 0)
            tab[i][j - 1] = 1;
          if (j + 1 < M)
            tab[i][j + 1] = 1;
        }
      }
    }
  }

  int liczbaPlusow = 0;

  for (int i = 1; i < N - 1; ++i) {
    for (int j = 1; j < M - 1; ++j) {
      if (tab[i][j] == 1) {
        bool isValidPlus = (tab[i - 1][j]) && (tab[i][j]) && (tab[i + 1][j]) &&
                           (tab[i][j - 1]) && (tab[i][j + 1]);

        bool doesNeighboursValid = !(tab[i - 1][j - 1]) &&
                                   !(tab[i + 1][j + 1]) &&
                                   !(tab[i - 1][j + 1]) && !(tab[i + 1][j - 1]);
        if (isValidPlus) {
          if (i != 1)
            doesNeighboursValid &= !(tab[i - 2][j]);
          if (j != 1)
            doesNeighboursValid &= !(tab[i][j - 2]);
          if (j != M - 2)
            doesNeighboursValid &= !(tab[i + 2][j]);
          if (i != N - 2)
            doesNeighboursValid &= !(tab[i][j + 2]);
          if (doesNeighboursValid) {
            liczbaPlusow++;
            i += 3;
          }
        }

        // if (tab[i + 1][j] == 1 && tab[i][j - 2] == 0 && tab[i][j - 1] == 1 &&
        //     tab[i - 1][j - 1] == 0 && tab[i + 1][j - 1] == 0 &&
        //     tab[i - 1][j] == 1 && tab[i + 1][j] == 1 && tab[i - 2][j] == 0 &&
        //     tab[i + 2][j] == 0 && tab[i - 1][j + 1] == 0 &&
        //     tab[i + 1][j + 1] == 0 && tab[i][j + 1] == 1 &&
        //     tab[i][j + 2] == 0) {
        //
        //   liczbaPlusow++;
        // }
      }
    }
  }
  int i, j;
  for (i = 0; i < N; i++) {
    for (j = 0; j < M; j++) {
      cout << tab[i][j] << " ";
    }
    cout << endl;
  }
  cout << endl << "wielkosc tabeli NxM: " << N << "x" << M;
  cout << endl << "znalezione plusy: " << liczbaPlusow;

  return 0;
}
