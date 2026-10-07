#include <iostream>
using namespace std;

int main() {
    int angka = 100;
    int *pointer;
    
    pointer = &angka;

    cout << "Nilai angka = " << angka << endl;
    cout << "Alamat angka = " << &angka << endl;
    cout << "Nilai pointer = " << pointer << endl;
    cout << "Nilai yang ditunjuk pointer = " << *pointer << endl;

    return 0;
}