#include "Doublylist.h"

int main() {
    List L;
    CreateList(L);
    infotype data;
    address P;
    
    cout << "masukkan nomor polisi: D001\n";
    cout << "masukkan warna kendaraan: hitam\n";
    cout << "masukkan tahun kendaraan: 90\n\n";
    data.nopol = "D001"; data.warna = "hitam"; data.thnBuat = 90;
    P = alokasi(data);
    insertLast(L, P);

    cout << "masukkan nomor polisi: D003\n";
    cout << "masukkan warna kendaraan: putih\n";
    cout << "masukkan tahun kendaraan: 70\n\n";
    data.nopol = "D003"; data.warna = "putih"; data.thnBuat = 70;
    P = alokasi(data);
    insertLast(L, P);

    cout << "masukkan nomor polisi: D001\n";
    cout << "masukkan warna kendaraan: merah\n";
    cout << "masukkan tahun kendaraan: 80\n";
    if (cekDuplikat(L, "D001")) {
        cout << "nomor polisi sudah terdaftar\n\n";
    }

    cout << "masukkan nomor polisi: D004\n";
    cout << "masukkan warna kendaraan: kuning\n";
    cout << "masukkan tahun kendaraan: 90\n\n";
    data.nopol = "D004"; data.warna = "kuning"; data.thnBuat = 90;
    P = alokasi(data);
    insertLast(L, P);

    printInfo(L);

    return 0;
}