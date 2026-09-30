#include <iostream>
using namespace std;

int main() {
    int angka;
    cout << "Masukkan angka: ";
    cin >> angka;
    for (int i = 0; i < angka ; i++) {
        for (int k = 0; k < i; k++) {
            cout << "  ";
        }
        for (int j = angka-i; j > 0; j--) {
            cout << j << " ";
        }
        cout << "* ";
        for (int j = 1 ; j <= angka-i; j++) {
            cout << j << " ";
        }   
        cout << '\n';
    }
    for(int i =0; i < angka; i++)
    {
        cout << "  ";
    }
    cout << "*";
    return 0;
}