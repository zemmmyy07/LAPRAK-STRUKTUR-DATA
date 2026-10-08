#include <iostream>

using std::cin;
using std::cout;

int main() {
    double angkaPertama, angkaKedua;

    cout << "Masukkan dua bilangan float: ";
    cin >> angkaPertama >> angkaKedua;

    cout << "Penjumlahan: " << angkaPertama + angkaKedua << '\n';
    cout << "Pengurangan: " << angkaPertama - angkaKedua << '\n';
    cout << "Perkalian: " << angkaPertama * angkaKedua << '\n';

    if (angkaKedua == 0.0) {
        cout << "Pembagian: tidak dapat dilakukan karena pembagi bernilai nol.\n";
    } else {
        cout << "Pembagian: " << angkaPertama / angkaKedua << '\n';
    }
    
    return 0;
}