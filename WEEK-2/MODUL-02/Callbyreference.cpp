#include <iostream>

using namespace std;

void tukar(int &x, int &y);

int main () {
    int a, b;
    a=4;  b=6;
    cout << "kondisi sebelum ditukar \n";
    cout << " a = "<<a<<" b = "<<b<<endl;
    tukar(a,b);
    cout<<"kondisi setelah ditukar \n";
    cout << " a = "<<a<<" b = "<<b<<endl;
    return 0;
}

void tukar (int &x, int &y) {
    int temp;
    temp = x;
    x = y;
    y = temp;
    cout<< "nilai akhir pada fungsi tukar \n";
    cout << " x = "<<x<<" y="<<y<<endl;
}