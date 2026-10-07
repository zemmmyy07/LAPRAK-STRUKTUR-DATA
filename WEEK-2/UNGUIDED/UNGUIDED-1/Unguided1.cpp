#include <iostream>
using namespace std;

int main() {
    int A[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    int B[3][3] = {
        {9, 8, 7},
        {6, 5, 4},
        {3, 2, 1}
    };

    int Hasil[3][3];

    cout << "=== HASIL PENJUMLAHAN (A + B) ===" << endl;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            Hasil[i][j] = A[i][j] + B[i][j];
            cout << Hasil[i][j] << "\t";
        }
        cout << endl;
    }
    cout << endl;

    cout << "=== HASIL PENGURANGAN (A - B) ===" << endl;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            Hasil[i][j] = A[i][j] - B[i][j];
            cout << Hasil[i][j] << "\t";
        }
        cout << endl;
    }
    cout << endl;

    cout << "=== HASIL PERKALIAN (A x B) ===" << endl;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            
            Hasil[i][j] = 0;

            for (int k = 0; k < 3; k++) {
                Hasil[i][j] += A[i][k] * B[k][j];
            }

            cout << Hasil[i][j] << "\t";
        }
        cout << endl;
    }

    return 0;
}