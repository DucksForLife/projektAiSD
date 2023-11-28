#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    // Inicjalizacja generatora liczb pseudolosowych
    srand(static_cast<unsigned int>(time(0)));

    // Losowanie liczby wierszy i kolumn w zakresie od 10 do 30
    int N = rand() % 21 + 10;  // Losuj od 10 do 30 (w��cznie)
    int M = rand() % 21 + 10;

    // Deklaracja i inicjalizacja tablicy NxM
    int tab[N][M];

    // Wype�nienie tablicy losowymi warto�ciami
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            tab[i][j] = rand() % 100;  // Przyk�adowy zakres od 0 do 99, dostosuj wg potrzeb
        }
    }

    // Wy�wietlenie tablicy
    cout << "Wygenerowana tablica " << N << "x" << M << ":\n";
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            cout << tab[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}

