#include <iostream>
using namespace std;


void tampilkan(int array[2][3][3])
{
    for (int i = 1; i <= 2; i++)
    {
        cout << "matrik ke"<< i<<"\n";
        for (int j = 0; j < 3; j++)
        {
            for (int k = 0; k < 3; k++)
            {
                cout << array[i-1][j][k] << " ";
            }
            cout << "\n";
        }
    }
}

void ubah(int x1,int y1,int x2, int y2, int array[2][3][3])
{
    int temp = array[0][x1-1][y1-1] ;
    array[0][x1-1][y1-1] = array[1][x2-1][y2-1];
    array[1][x2-1][y2-1] = temp;
}

void ubahmatriks(int array[2][3][3])
{
    int x1,y1;
    int x2,y2;
    cout << "masukan index yang mau di tukar di array 1 baris dan kolom ke :";
    cin >> x1;
    cin >> y1;
    cout << "masukan index yang mau di tukar di array 2 baris dan kolom ke :";
    cin >> x2;
    cin >> y2;
    ubah(x1,y1,x2,y2,array);
}

int main ()
{
    int data[2][3][3] =
    {
        {
            {16,69,88},
            {20,10,11},
            {17,29,67}
        },
        {
            {54,67,89},
            {78,65,23},
            {45,12,13}
        }
    };
    cout << "sebelum \n";
    tampilkan(data);
    ubahmatriks(data);
    cout << "sesudah \n";
    tampilkan(data);
    return 0;
}