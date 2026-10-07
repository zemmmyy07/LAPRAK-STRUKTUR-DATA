#include <iostream>
using namespace std;

void tukar(int &x, int &y, int &z);

int main() {
    int a = 4, b = 6, c = 8;

    cout << "kondisi sebelum ditukar \n";
    cout << " a = " << a << " b = " << b << " c = " << c << endl;

    tukar(a, b, c);

    cout << "\nkondisi setelah ditukar \n";
    cout << " a = " << a << " b = " << b << " c = " << c << endl;

    return 0;
}

void tukar(int &x, int &y, int &z) {
    int temp = x; 
    x = z;        
    z = y;      
    y = temp;     

    cout << "\nnilai akhir pada fungsi tukar \n";
    cout << " x = " << x << " y = " << y << " z = " << z << endl;
}