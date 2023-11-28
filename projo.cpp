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
  int i, j, liczbaJedynek; // t=liczba jedynek

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

  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < M; ++j) {
      if (tab[i][j] == 1) {
        if (i + 1 < M && tab[i + 1][j] == 1) {
          {
            if (tab[i + 1][j] == 1 && tab[i][j - 2] == 0 &&
                tab[i][j - 1] == 1 && tab[i - 1][j - 1] == 0 &&
                tab[i + 1][j - 1] == 0 && tab[i - 1][j] == 1 &&
                tab[i + 1][j] == 1 && tab[i - 2][j] == 0 &&
                tab[i + 2][j] == 0 && tab[i - 1][j + 1] == 0 &&
                tab[i + 1][j + 1] == 0 && tab[i][j + 1] == 1 &&
                tab[i][j + 2] == 0) {

              liczbaJedynek++;
            }
          }
        }
      }
    }
  }

  for (i = 0; i < N; i++) {
    for (j = 0; j < M; j++) {
      cout << tab[i][j] << " ";
    }
    cout << endl;
  }
  cout << endl << "wielkosc tabeli NxM: " << N << "x" << M;
  cout << endl << "znalezione plusy: " << liczbaJedynek;

  return 0;
}
