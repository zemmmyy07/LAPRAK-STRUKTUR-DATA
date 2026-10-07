#include <iostream>
using namespace std;

void tukar(int *x, int *y, int *z) {
    int temp = *x; 
    *x = *z;       
    *z = *y;       
    *y = temp;    
}

int main() {
    int a = 4;
    int b = 6;
    int c = 8;

    cout << "Sebelum ditukar:" << endl;
    cout << "a = " << a << ", b = " << b << ", c = " << c << endl;

    tukar(&a, &b, &c);

    cout << "\nSetelah ditukar:" << endl;
    cout << "a = " << a << ", b = " << b << ", c = " << c << endl;

    return 0;
}