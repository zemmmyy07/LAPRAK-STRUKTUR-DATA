#include <iostream>
using namespace std;

struct mahasiswa
{
    char nama[50];
    int nim, uts, uas, tugas;
    float tugasakhir;
};

mahasiswa Mahasiswa[10];

int nilaiAkhir(mahasiswa *x) {
    x->tugasakhir = 0.3f * x->uts+0.4f * x->uas+0.3f * x->tugas;
    return x->tugasakhir;
}

int main () {
    int x;
    cout << "Masukan Jumlah Mahasiswa : ";
    cin >> x ;
    for (int i = 1; i <= x; i++){
        cout << "Masukan Mahasiswa Ke "<< i<< "\n";
        cout << "Masukan Nama : ";
        cin >> Mahasiswa[i].nama;
        cout << "Masukan NIM : ";
        cin >> Mahasiswa[i].nim;
        cout << "Masukan UTS : ";
        cin >> Mahasiswa[i].uts;
        cout << "Masukan UAS : ";
        cin >> Mahasiswa[i].uas;
        cout << "Masukan Tugas : ";
        cin >> Mahasiswa[i].tugas;
        Mahasiswa[i].tugasakhir = nilaiAkhir(&Mahasiswa[i]);
    }

    for (int i= 1; i <= x;i++)
    {
        cout << "Nilai Akhir " << Mahasiswa[i].nama << " : " << Mahasiswa[i].tugasakhir << "\n";
    }

    return 0;
}