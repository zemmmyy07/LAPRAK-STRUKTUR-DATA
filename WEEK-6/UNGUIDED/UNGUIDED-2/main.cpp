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

    infotype x;
    cout << "\nMasukkan Nomor Polisi yang dicari\t: ";
    cin >> x.nopol;

    address hasilPencarian = findElm(L, x);

    if (hasilPencarian != NULL) {
        cout << "\nNomor Polisi\t: " << hasilPencarian->info.nopol << endl;
        cout << "Warna\t\t: " << hasilPencarian->info.warna << endl;
        cout << "Tahun\t\t: " << hasilPencarian->info.thnBuat << endl;
    } else {
        cout << "\nKendaraan tidak ditemukan.\n";
    }

    return 0;
}