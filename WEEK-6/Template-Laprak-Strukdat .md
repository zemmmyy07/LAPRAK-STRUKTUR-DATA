# <h1 align="center">Laporan Praktikum Modul 6 - DOUBLY LINKED LIST (BAGIAN PERTAMA)</h1>
<p align="center">Azzamy Gusalim Herfino - 109082500091</p>

## Dasar Teori
### A. Doubly Linked List<br/>
Doubly linked list adalah struktur data yang terdiri atas simpul-simpul yang saling terhubung. Setiap simpul menyimpan data serta pointer `next` menuju simpul berikutnya dan `prev` menuju simpul sebelumnya. Karena memiliki dua pointer tersebut, list dapat ditelusuri dari awal ke akhir maupun sebaliknya[1]. Pointer `First` dan `Last` digunakan untuk menandai simpul pertama dan terakhir.

### B. Operasi pada Doubly Linked List<br/>
Operasi dasar doubly linked list meliputi pembuatan list, penambahan simpul, pencarian, dan penghapusan. Penambahan atau penghapusan simpul dilakukan dengan memperbarui hubungan pointer agar urutan list tetap terjaga. Pencarian dilakukan dengan menelusuri simpul satu per satu hingga data yang sesuai ditemukan atau seluruh simpul telah diperiksa[1].

## Guided 

### 1. Doublylist.h

```C++
#ifndef DOUBLYLIST_H
#define DOUBLYLIST_H
#include <string>
using namespace std;

struct barang {
    string kode;
    string nama;
    int tahun;
};

using infotype = barang;
struct elmlist;
using address = elmlist*;
struct elmlist { infotype info; address prev; address next; };
struct List { address first; address last; };

void CreateList(List &L);
address alokasi(const infotype &x);
void dealokasi(address &P);
void insertFirst(List &L, address P);
void insertLast(List &L, address P);
void insertAfter(List &L, address R, address P);
void insertBefore(List &L, address R, address P);
void printInfo(const List &L);
address findElm(const List &L, const string &kode);
void deleteFirst(List &L, address &P);
void deleteLast(List &L, address &P);
void deleteAfter(List &L, address R, address &P);
void deleteBefore(List &L, address R, address &P);
#endif
```
penjelasan singkat guided 1 :
Program Guided 1 mendemonstrasikan operasi pada doubly linked list menggunakan data barang. Program menambahkan simpul di awal, akhir, sebelum, dan sesudah simpul tertentu; mencari barang berdasarkan kode; lalu menghapus simpul di awal, akhir, sebelum, dan sesudah posisi tertentu. Setelah setiap perubahan, isi list ditampilkan untuk memperlihatkan hasil operasi.

### 2. Doublylist.cpp

```C++
#include <iostream>
#include <iomanip>
#include "Doublylist.h"
using namespace std;

void CreateList(List &L) { L.first = nullptr; L.last = nullptr; }

address alokasi(const infotype &x) {
    address P = new elmlist;
    P->info = x;
    P->prev = nullptr; P->next = nullptr;
    return P;
}

void dealokasi(address &P) {
    if (P != nullptr) { delete P; P = nullptr; }
}

void insertFirst(List &L, address P) {
    if (!P) return;
    P->prev = nullptr; P->next = L.first;
    if (L.first) L.first->prev = P;
    else L.last = P;
    L.first = P;
}

void insertLast(List &L, address P) {
    if (!P) return;
    P->next = nullptr; P->prev = L.last;
    if (L.last) L.last->next = P;
    else L.first = P;
    L.last = P;
}

// Menyisipkan P tepat setelah R.
void insertAfter(List &L, address R, address P) {
    if (!R || !P) return;
    P->prev = R;
    P->next = R->next;
    if (R->next) R->next->prev = P;
    else L.last = P;
    R->next = P;
}

// Menyisipkan P tepat sebelum R.
void insertBefore(List &L, address R, address P) {
    if (!R || !P) return;
    P->next = R;
    P->prev = R->prev;
    if (R->prev) R->prev->next = P;
    else L.first = P;
    R->prev = P;
}

void printInfo(const List &L) {
    address P = L.first;
    if (!P) {
        cout << "List kosong.\n";
        return;
    }

    cout << "+------------------------------+\n";
    cout << "| Kode   | Nama        | Tahun |\n";
    cout << "+------------------------------+\n";
    while (P) {
        cout << "| " << left << setw(6) << P->info.kode
             << " | " << setw(10) << P->info.nama
             << " | " << setw(5) << P->info.tahun << " |\n";
        P = P->next;
    }
    cout << "+------------------------------+\n";
}

address findElm(const List &L, const string &kode) {
    address P = L.first;
    while (P) {
        if (P->info.kode == kode) return P;
        P = P->next;
    }
    return nullptr;
}

void deleteFirst(List &L, address &P) {
    if (!L.first) { P = nullptr; return; }
    P = L.first; L.first = P->next;
    if (L.first) L.first->prev = nullptr;
    else L.last = nullptr;
    P->prev = P->next = nullptr;
}

void deleteLast(List &L, address &P) {
    if (!L.last) { P = nullptr; return; }
    P = L.last; L.last = P->prev;
    if (L.last) L.last->next = nullptr;
    else L.first = nullptr;
    P->prev = P->next = nullptr;
}

// Menghapus node tepat setelah prec.
void deleteAfter(List &L, address prec, address &P) {
    P = nullptr;
    if (!prec || !prec->next) return;
    P = prec->next; prec->next = P->next;
    if (P->next) P->next->prev = prec;
    else L.last = prec;
    P->prev = P->next = nullptr;
}

// Menghapus node tepat sebelum succ.
void deleteBefore(List &L, address succ, address &P) {
    P = nullptr;
    if (!succ || !succ->prev) return;
    P = succ->prev; succ->prev = P->prev;
    if (P->prev) P->prev->next = succ;
    else L.first = succ;
    P->prev = P->next = nullptr;
}
```
penjelasan singkat guided 2 :
Program Guided 2 berisi implementasi fungsi-fungsi doubly linked list yang digunakan pada Guided 1. Fungsi-fungsi tersebut mengatur pembuatan list, alokasi dan dealokasi simpul, penyisipan di berbagai posisi, pencarian berdasarkan kode, serta penghapusan simpul. Setiap operasi memperbarui pointer `next`, `prev`, `first`, dan `last` agar hubungan antarsimpul tetap benar.

### 3. main.cpp

```C++
#include <iostream>
#include "Doublylist.h"
using namespace std;

void tampilkanJudul(const string &judul) {
    cout << "\n========================================\n";
    cout << judul << '\n';
    cout << "========================================\n";
}

int main() {
    List L;
    CreateList(L);

    infotype barang1 = {"B001", "Laptop", 2020};
    infotype barang2 = {"B002", "Monitor", 2022};
    infotype barang3 = {"B003", "Keyboard", 2023};
    infotype barang4 = {"B004", "Mouse", 2024};

    address P = nullptr;
    address posisi = nullptr;

    cout << "DEMONSTRASI OPERASI DOUBLY LINKED LIST\n";
    cout << "Data yang digunakan: B001, B002, B003, dan B004\n";

    tampilkanJudul("[1] INSERT FIRST");
    cout << "Menambahkan B002 di awal list.\n";
    insertFirst(L, alokasi(barang2));
    printInfo(L);

    tampilkanJudul("[2] INSERT LAST");
    cout << "Menambahkan B004 di akhir list.\n";
    insertLast(L, alokasi(barang4));
    printInfo(L);

    tampilkanJudul("[3] INSERT AFTER");
    cout << "Menambahkan B003 setelah B002.\n";
    posisi = findElm(L, "B002");
    if (posisi != nullptr) {
        insertAfter(L, posisi, alokasi(barang3));
    }
    printInfo(L);

    tampilkanJudul("[4] INSERT BEFORE");
    cout << "Menambahkan B001 sebelum B002.\n";
    posisi = findElm(L, "B002");
    if (posisi != nullptr) {
        insertBefore(L, posisi, alokasi(barang1));
    }
    printInfo(L);

    tampilkanJudul("[5] FIND ELEMENT");
    cout << "Mencari barang dengan kode B003.\n";
    posisi = findElm(L, "B003");
    if (posisi != nullptr) {
        cout << "Data ditemukan:\n";
        cout << "  Kode  : " << posisi->info.kode << '\n';
        cout << "  Nama  : " << posisi->info.nama << '\n';
        cout << "  Tahun : " << posisi->info.tahun << '\n';
    } else {
        cout << "Data tidak ditemukan.\n";
    }

    tampilkanJudul("[6] DELETE AFTER");
    cout << "Menghapus node setelah B002 (B003).\n";
    posisi = findElm(L, "B002");
    deleteAfter(L, posisi, P);
    if (P != nullptr) {
        cout << "Node yang dihapus: " << P->info.kode << '\n';
        dealokasi(P);
    } else {
        cout << "Tidak ada node yang dapat dihapus.\n";
    }
    printInfo(L);

    tampilkanJudul("[7] DELETE BEFORE");
    cout << "Menghapus node sebelum B004 (B002).\n";
    posisi = findElm(L, "B004");
    deleteBefore(L, posisi, P);
    if (P != nullptr) {
        cout << "Node yang dihapus: " << P->info.kode << '\n';
        dealokasi(P);
    } else {
        cout << "Tidak ada node yang dapat dihapus.\n";
    }
    printInfo(L);

    tampilkanJudul("[8] DELETE FIRST");
    cout << "Menghapus node pertama.\n";
    deleteFirst(L, P);
    if (P != nullptr) {
        cout << "Node yang dihapus: " << P->info.kode << '\n';
        dealokasi(P);
    } else {
        cout << "List kosong, tidak ada node yang dapat dihapus.\n";
    }
    printInfo(L);

    tampilkanJudul("[9] DELETE LAST");
    cout << "Menghapus node terakhir.\n";
    deleteLast(L, P);
    if (P != nullptr) {
        cout << "Node yang dihapus: " << P->info.kode << '\n';
        dealokasi(P);
    } else {
        cout << "List kosong, tidak ada node yang dapat dihapus.\n";
    }
    printInfo(L);

    tampilkanJudul("SELESAI");
    cout << "Kondisi list: "
         << ((L.first == nullptr && L.last == nullptr) ? "kosong.\n"
                                                       : "masih berisi data.\n");

    return 0;
}

```
penjelasan singkat guided 3 :
Program Guided 3 menggunakan data barang B001 sampai B004 untuk memperagakan operasi doubly linked list. Program menyisipkan barang di awal, akhir, sebelum, dan sesudah simpul tertentu, kemudian mencari barang berdasarkan kode B003. Setelah itu, program menghapus simpul pada beberapa posisi dan menampilkan isi list setiap kali operasi dilakukan, sehingga perubahan susunan list dapat diamati.

## Unguided 

### 1. Buatlah ADT Doubly Linked list sebagai berikut di dalam file “Doublylist.h”.Buatlah ADT Doubly Linked list sebagai berikut di dalam file “Doublylist.h”:

### Doublylist.h
```C++
#ifndef DOUBLYLIST_H
#define DOUBLYLIST_H

#include <iostream>
#include <string>

using namespace std;

struct kendaraan {
    string nopol;
    string warna;
    int thnBuat;
};

typedef kendaraan infotype;
typedef struct ElmList *address;

struct ElmList {
    infotype info;
    address next;
    address prev;
};

struct List {
    address First;
    address Last;
};

void CreateList(List &L);
address alokasi(infotype x);
void dealokasi(address &P);
void printInfo(List L);
void insertLast(List &L, address P);

bool cekDuplikat(List L, string nopol);

#endif
```

### Doublylist.cpp
```C++
#include "Doublylist.h"

void CreateList(List &L) {
    L.First = NULL;
    L.Last = NULL;
}

address alokasi(infotype x) {
    address P = new ElmList;
    P->info = x;
    P->next = NULL;
    P->prev = NULL;
    return P;
}

void dealokasi(address &P) {
    delete P;
    P = NULL;
}

void insertLast(List &L, address P) {
    if (L.First == NULL && L.Last == NULL) {
        L.First = P;
        L.Last = P;
    } else {
        P->prev = L.Last;
        L.Last->next = P;
        L.Last = P;
    }
}

void printInfo(List L) {
    cout << "DATA LIST 1\n\n";
    address P = L.Last;
    while (P != NULL) {
        cout << "no polisi : " << P->info.nopol << endl;
        cout << "warna     : " << P->info.warna << endl;
        cout << "tahun     : " << P->info.thnBuat << endl;
        P = P->prev;
    }
}

bool cekDuplikat(List L, string nopol) {
    address P = L.First;
    while (P != NULL) {
        if (P->info.nopol == nopol) {
            return true;
        }
        P = P->next;
    }
    return false;
}

```
### main.cpp
```C++
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
```

### Output Unguided 1 :

##### Output 1

#### penjelasan unguided 1 
Program Unguided 1 menyimpan data kendaraan berupa nomor polisi, warna, dan tahun ke dalam doubly linked list. Data ditambahkan di akhir list, sementara fungsi `cekDuplikat` memeriksa agar nomor polisi yang sama tidak dimasukkan kembali. Setelah input selesai, program menampilkan data kendaraan dari simpul terakhir ke simpul pertama.

### 2. Carilah elemen dengan nomor polisi D001 dengan membuat fungsi baru.fungsi findElm( L : List, x : infotype ) : address

### Doublylist.h
```C++
#ifndef DOUBLYLIST_H
#define DOUBLYLIST_H

#include <iostream>
#include <string>

using namespace std;

struct kendaraan {
    string nopol;
    string warna;
    int thnBuat;
};

typedef kendaraan infotype;
typedef struct ElmList *address;

struct ElmList {
    infotype info;
    address next;
    address prev;
};

struct List {
    address First;
    address Last;
};

void CreateList(List &L);
address alokasi(infotype x);
void dealokasi(address &P);
void printInfo(List L);
void insertLast(List &L, address P);

bool cekDuplikat(List L, string nopol);
address findElm(List L, infotype x);

#endif
```
### Doublylist.cpp
```C++
#include "Doublylist.h"

void CreateList(List &L) {
    L.First = NULL;
    L.Last = NULL;
}

address alokasi(infotype x) {
    address P = new ElmList;
    P->info = x;
    P->next = NULL;
    P->prev = NULL;
    return P;
}

void dealokasi(address &P) {
    delete P;
    P = NULL;
}

void insertLast(List &L, address P) {
    if (L.First == NULL && L.Last == NULL) {
        L.First = P;
        L.Last = P;
    } else {
        P->prev = L.Last;
        L.Last->next = P;
        L.Last = P;
    }
}

void printInfo(List L) {
    cout << "DATA LIST 1\n\n";
    address P = L.Last;
    while (P != NULL) {
        cout << "no polisi : " << P->info.nopol << endl;
        cout << "warna     : " << P->info.warna << endl;
        cout << "tahun     : " << P->info.thnBuat << endl;
        P = P->prev;
    }
}

bool cekDuplikat(List L, string nopol) {
    address P = L.First;
    while (P != NULL) {
        if (P->info.nopol == nopol) {
            return true;
        }
        P = P->next;
    }
    return false;
}

address findElm(List L, infotype x) {
    address P = L.First;
    while (P != NULL) {
        if (P->info.nopol == x.nopol) {
            return P;
        }
        P = P->next;
    }
    return NULL;
}
```
### main.cpp
```C++
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
```

### Output Unguided 2 :

##### Output 1

#### penjelasan unguided 2 
Program Unguided 2 menambahkan fitur pencarian kendaraan pada doubly linked list. Setelah data kendaraan dimasukkan, program menampilkan isi list dan meminta nomor polisi yang dicari. Fungsi `findElm` menelusuri list berdasarkan nomor polisi; jika cocok, program menampilkan nomor polisi, warna, dan tahun kendaraan, sedangkan jika tidak ditemukan, program menampilkan pesan bahwa kendaraan tidak ditemukan.

### 3. Hapus elemen dengan nomor polisi D003 dengan procedure delete.

### Doublylist.h
```C++
#ifndef DOUBLYLIST_H
#define DOUBLYLIST_H

#include <iostream>
#include <string>

using namespace std;

struct kendaraan {
    string nopol;
    string warna;
    int thnBuat;
};

typedef kendaraan infotype;
typedef struct ElmList *address;

struct ElmList {
    infotype info;
    address next;
    address prev;
};

struct List {
    address First;
    address Last;
};

void CreateList(List &L);
address alokasi(infotype x);
void dealokasi(address &P);
void printInfo(List L);
void insertLast(List &L, address P);

bool cekDuplikat(List L, string nopol);
address findElm(List L, infotype x);

void deleteFirst(List &L, address &P);
void deleteLast(List &L, address &P);
void deleteAfter(address Prec, address &P);

#endif
```
### Doublylist.cpp
```C++
#include "Doublylist.h"

void CreateList(List &L) {
    L.First = NULL;
    L.Last = NULL;
}

address alokasi(infotype x) {
    address P = new ElmList;
    P->info = x;
    P->next = NULL;
    P->prev = NULL;
    return P;
}

void dealokasi(address &P) {
    delete P;
    P = NULL;
}

void insertLast(List &L, address P) {
    if (L.First == NULL && L.Last == NULL) {
        L.First = P;
        L.Last = P;
    } else {
        P->prev = L.Last;
        L.Last->next = P;
        L.Last = P;
    }
}

void printInfo(List L) {
    cout << "DATA LIST 1\n\n";
    address P = L.Last;
    while (P != NULL) {
        cout << "Nomor Polisi : " << P->info.nopol << endl;
        cout << "Warna        : " << P->info.warna << endl;
        cout << "Tahun        : " << P->info.thnBuat << endl;
        P = P->prev;
    }
}

bool cekDuplikat(List L, string nopol) {
    address P = L.First;
    while (P != NULL) {
        if (P->info.nopol == nopol) {
            return true;
        }
        P = P->next;
    }
    return false;
}

address findElm(List L, infotype x) {
    address P = L.First;
    while (P != NULL) {
        if (P->info.nopol == x.nopol) {
            return P;
        }
        P = P->next;
    }
    return NULL;
}

void deleteFirst(List &L, address &P) {
    if (L.First != NULL) {
        P = L.First;
        if (L.First == L.Last) {
            L.First = NULL;
            L.Last = NULL;
        } else {
            L.First = L.First->next;
            L.First->prev = NULL;
            P->next = NULL;
        }
    }
}

void deleteLast(List &L, address &P) {
    if (L.Last != NULL) {
        P = L.Last;
        if (L.First == L.Last) {
            L.First = NULL;
            L.Last = NULL;
        } else {
            L.Last = L.Last->prev;
            L.Last->next = NULL;
            P->prev = NULL;
        }
    }
}

void deleteAfter(address Prec, address &P) {
    if (Prec != NULL && Prec->next != NULL) {
        P = Prec->next;
        Prec->next = P->next;
        if (P->next != NULL) {
            P->next->prev = Prec;
        }
        P->next = NULL;
        P->prev = NULL;
    }
}
```
### main.cpp
```C++
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

    infotype targetHapus;
    cout << "\nMasukkan Nomor Polisi yang akan dihapus : ";
    cin >> targetHapus.nopol;

    address pDel = findElm(L, targetHapus);
    if (pDel != NULL) {
        if (pDel == L.First) {
            deleteFirst(L, pDel);
        } else if (pDel == L.Last) {
            deleteLast(L, pDel);
        } else {
            deleteAfter(pDel->prev, pDel);
        }
        dealokasi(pDel);
        cout << "Data dengan nomor polisi " << targetHapus.nopol << " berhasil dihapus.\n\n";
    } else {
        cout << "Data tidak ditemukan.\n\n";
    }

    printInfo(L);

    return 0;
}
```
### Output Unguided 3 :

##### Output 1

#### penjelasan unguided 3
Program Unguided 3 menambahkan fitur penghapusan data kendaraan dari doubly linked list. Program mencari kendaraan berdasarkan nomor polisi yang dimasukkan, lalu menghapus simpul tersebut dengan operasi yang sesuai: `deleteFirst` jika berada di awal, `deleteLast` jika berada di akhir, atau `deleteAfter` jika berada di tengah. Memori simpul yang dihapus kemudian dibebaskan, dan isi list ditampilkan kembali untuk memperlihatkan hasilnya. Jika nomor polisi tidak ditemukan, program menampilkan pesan bahwa data tidak ditemukan.

## Kesimpulan
Doubly linked list merupakan struktur data dinamis yang setiap simpulnya memiliki pointer ke simpul sebelum dan sesudahnya. Melalui praktikum ini, operasi pembuatan list, penyisipan, penelusuran, pencarian, dan penghapusan dapat diterapkan dengan memperbarui hubungan pointer serta penanda simpul pertama dan terakhir. Ketelitian dalam mengatur pointer `next` dan `prev` penting agar susunan list tetap konsisten. Penerapan pada data kendaraan juga menunjukkan bahwa list dapat digunakan untuk mengelola, mencari, dan menghapus data secara terstruktur.

## Referensi
[1] Triase. (2020). Diktat Edisi Revisi : STRUKTUR DATA. Medan: UNIVERSTAS ISLAM NEGERI SUMATERA UTARA MEDAN. 
<br>[2] Indahyati, Uce., Rahmawati Yunianita. (2020). "BUKU AJAR ALGORITMA DAN PEMROGRAMAN DALAM BAHASA C++". Sidoarjo: Umsida Press. Diakses pada 10 Maret 2024 melalui https://doi.org/10.21070/2020/978-623-6833-67-4.
<br>...
