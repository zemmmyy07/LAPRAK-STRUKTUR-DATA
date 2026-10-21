# <h1 align="center">Laporan Praktikum Modul 4 - SINGLY LINKED LIST (Bagian Pertama)</h1>
<p align="center">Azzamy Gusalim Herfino - 109082500091</p>

## Dasar Teori
Linked list adalah struktur data yang terdiri dari node-node yang saling terhubung menggunakan pointer. Pada singly linked list, setiap node menyimpan data dan pointer `next` menuju node berikutnya. Pointer `First` menunjuk ke node pertama, sedangkan `NULL` menandakan akhir list[1].

Node dapat ditambahkan atau dihapus dengan mengubah pointer. Node baru dibuat menggunakan `new` dan memorinya dibebaskan menggunakan `delete` saat dihapus[2]. List juga dapat ditelusuri dari `First` hingga `NULL` untuk menampilkan atau menghitung jumlah node.

## Guided 

### 1. List.h

```C++
#ifndef LIST_H
#define LIST_H
#define Nil nullptr

#include <iostream>
#include <string>
using namespace std;

struct mahasiswa {
    string nama;
    string nim;
    int umur;
};

typedef mahasiswa dataMahasiswa;

typedef struct node* address;

struct node {
    dataMahasiswa isidata;
    address next;
};

struct LinkedList {
    address first;
};

typedef LinkedList linkedList;

bool isEmpty(linkedList List);
void createList(linkedList &List);
address alokasi(string nama, string nim, int umur);
void dealokasi(address &node);
void printList(linkedList List);
void insertFirst(linkedList &List, address nodeBaru);
void insertAfter(linkedList &List, address nodeBaru, address Prev);
void insertLast(linkedList &List, address nodeBaru);

void delFirst(linkedList &List);
void delLast(linkedList &List);
void delAfter(linkedList &List, address nodeHapus, address nodePrev);
int nbList(linkedList List);
void deleteList(linkedList &List);

#endif
```
penjelasan singkat guided 1 :
`list.h` berisi deklarasi struktur dan fungsi linked list. Struktur `mahasiswa` menyimpan nama, NIM, dan umur; `node` menyimpan data tersebut serta pointer `next`; dan `LinkedList` menyimpan pointer ke node pertama. File ini juga mendeklarasikan fungsi untuk membuat, menambah, menghapus, dan menampilkan node. `#ifndef` dan `#define` mencegah header dimuat berulang kali.

### 2. list.cpp

```C++
// list.cpp
#include "list.h"
#include <iostream>
using namespace std;

// I.S = Initial State / kondisi awal
// F.S = Final State / kondisi akhir

// fungsi untuk cek apakah list kosong atau tidak
bool isEmpty(linkedList List) {
    if (List.first == Nil) {
        return true;
    } else {
        return false;
    }
}

// pembuatan linked list kosong
void createList(linkedList &List) {
    /* I.S. sembarang
       F.S. terbentuk list kosong */
    List.first = Nil;
}

// pembuatan node baru dengan menerapkan manajemen memori
address alokasi(string nama, string nim, int umur) {
    /*
       I.S. sembarang
       F.S. mengembalikan alamat node baru dengan isidata = sesuai parameter dan next = Nil
    */
    address nodeBaru = new node;
    nodeBaru->isidata.nama = nama;
    nodeBaru->isidata.nim = nim;
    nodeBaru->isidata.umur = umur;
    nodeBaru->next = Nil;
    return nodeBaru;
}

// penghapusan node dengan menerapkan manajemen memori
void dealokasi(address &node) {
    /*
       I.S. P terdefinisi
       F.S. memori yang digunakan node dikembalikan ke sistem
    */
    delete node;
    node = Nil;
}

// prosedur-prosedur untuk insert / menambahkan node baru ke dalam list
void insertFirst(linkedList &List, address nodeBaru) {
    /*
       I.S. sembarang, P sudah dialokasi
       F.S. menempatkan elemen list (node) pada awal list
    */
    nodeBaru->next = List.first;
    List.first = nodeBaru;
}

void insertAfter(linkedList &, address nodeBaru, address Prev) {
    /*
       I.S. sembarang, nodeBaru dan Prev adalah salah satu elemen list (node)
       F.S. menempatkan elemen (node) sesudah elemen node Prev
    */
    if (Prev != Nil) {
        nodeBaru->next = Prev->next;
        Prev->next = nodeBaru;
    } else {
        cout << "Node sebelumnya tidak valid!" << endl;
    }
}

void insertLast(linkedList &List, address nodeBaru) {
    /*
       I.S. sembarang, nodeBaru sudah dialokasi
       F.S. menempatkan elemen pada akhir list
    */
    if (isEmpty(List)) {
        List.first = nodeBaru;
    } else {
        address nodeBantu = List.first;

        while (nodeBantu->next != Nil) {
            nodeBantu = nodeBantu->next;
        }

        nodeBantu->next = nodeBaru;
    }
}

// prosedur-prosedur untuk delete / menghapus node yang ada di dalam list
void delFirst(linkedList &List) {
    /*
       I.S. list tidak kosong
       F.S. node pertama di list terhapus
    */
    address nodeHapus;

    if (isEmpty(List) == false) {
        nodeHapus = List.first;
        List.first = List.first->next;
        nodeHapus->next = Nil;
        dealokasi(nodeHapus);
    } else {
        cout << "List kosong!" << endl;
    }
}

void delLast(linkedList &List) {
    /*
       I.S. list tidak kosong
       F.S. node terakhir di list terhapus
    */
    address nodeHapus, nodePrev;

    if (isEmpty(List) == false) {
        nodeHapus = List.first;

        if (nodeHapus->next == Nil) {
            List.first = Nil;
            dealokasi(nodeHapus);
        } else {
            while (nodeHapus->next != Nil) {
                nodePrev = nodeHapus;
                nodeHapus = nodeHapus->next;
            }

            nodePrev->next = Nil;
            dealokasi(nodeHapus);
        }
    } else {
        cout << "List kosong" << endl;
    }
}

void delAfter(linkedList &List, address nodeHapus, address nodePrev) {
    /*
       I.S. list tidak kosong, Prev alamat salah satu elemen list
       F.S. nodeBantu adalah alamat dari Prev->next, menghapus Prev->next dari list
    */
    if (isEmpty(List) == true) {
        cout << "List kosong!" << endl;
    } else {
        if (nodePrev != Nil && nodePrev->next != Nil) {
            nodeHapus = nodePrev->next;
            nodePrev->next = nodeHapus->next;
            nodeHapus->next = Nil;
            dealokasi(nodeHapus);
        } else {
            cout << "Node sebelumnya (prev) tidak valid!" << endl;
        }
    }
}

// prosedur untuk menampilkan isi list
void printList(linkedList List) {
    /*
       I.S. mungkin kosong
       F.S. jika list tidak kosong menampilkan semua info yang ada pada list
    */
    if (isEmpty(List)) {
        cout << "List kosong." << endl;
    } else {
        address nodeBantu = List.first;

        while (nodeBantu != Nil) {
            cout << "Nama : " << nodeBantu->isidata.nama
                 << ", NIM : " << nodeBantu->isidata.nim
                 << ", Usia : " << nodeBantu->isidata.umur
                 << endl;

            nodeBantu = nodeBantu->next;
        }
    }
}

// function untuk menampilkan jumlah node di dalam list
int nbList(linkedList List) {
    /*
       I.S. list sudah ada
       F.S. menampilkan jumlah node di dalam list
    */
    int count = 0;
    address nodeBantu = List.first;

    while (nodeBantu != Nil) {
        count++;
        nodeBantu = nodeBantu->next;
    }

    return count;
}

// prosedur untuk menghapus list (menghapus semua node di dalam list)
void deleteList(linkedList &List) {
    /*
       I.S. list sudah ada
       F.S. menghapus semua node di dalam list
    */
    address nodeBantu, nodeHapus;
    nodeBantu = List.first;

    while (nodeBantu != Nil) {
        nodeHapus = nodeBantu;
        nodeBantu = nodeBantu->next;
        dealokasi(nodeHapus);
    }

    List.first = Nil;
    cout << "List sudah terhapus!" << endl;
}
```
penjelasan singkat guided 2 :
`list.cpp` berisi implementasi fungsi-fungsi yang dideklarasikan di `list.h`. Fungsinya mencakup membuat list, mengalokasikan node, menyisipkan dan menghapus node, menampilkan data, serta menghitung jumlah node.


### 3. main.cpp

```C++
// main.cpp
#include "mahasiswa/list.h"

#include <iostream>
using namespace std;

int main() {
    linkedList List;
    address nodeA, nodeB, nodeC, nodeD, nodeE = Nil;

    createList(List);

    nodeA = alokasi("Dhimas", "2311102151", 20);
    nodeB = alokasi("Arvin", "2211100014", 21);
    nodeC = alokasi("Rizal", "2311100029", 20);
    nodeD = alokasi("Satrio", "2211102173", 21);
    nodeE = alokasi("Joshua", "2311102133", 21);

    insertFirst(List, nodeA);
    insertLast(List, nodeB);
    insertAfter(List, nodeC, nodeA);
    insertAfter(List, nodeD, nodeC);
    insertLast(List, nodeE);

    cout << "--- ISI LIST SETELAH DILAKUKAN INSERT ---" << endl;
    printList(List);
    cout << "jumlah node : " << nbList(List) << endl;
    cout << endl;

    delFirst(List);
    delLast(List);
    delAfter(List, nodeD, nodeC);

    cout << "--- ISI LIST SETELAH DILAKUKAN DELETE ---" << endl;
    printList(List);
    cout << "jumlah node : " << nbList(List) << endl;
    cout << endl;

    deleteList(List);

    cout << "--- ISI LIST SETELAH DILAKUKAN HAPUS LIST ---" << endl;
    printList(List);
    cout << "jumlah node : " << nbList(List) << endl;
    cout << endl;

    return 0;
}
```
penjelasan singkat guided 3 :
`main.cpp` menguji operasi linked list dengan membuat lima node mahasiswa, lalu menyisipkan dan menghapus beberapa node. Program menampilkan isi serta jumlah node setelah operasi, kemudian menghapus seluruh list.

## Unguided 

### 1. Buatlah ADT Singly Linked list sebagai berikut di dalam file “Singlylist.h”.Kemudian buatlah implementasi dari procedure-procedure yang digunakan didalam file “Singlylist.cpp” Kemudian buat program utama didalam file “main.cpp” dengan implementasi 

### Singlylist.h
```C++
#ifndef SINGLYLIST_H_INCLUDED
#define SINGLYLIST_H_INCLUDED

#include <iostream>
using namespace std;

typedef int infotype;
typedef struct ElmList *address;

struct ElmList {
    infotype info;
    address next;
};

struct List {
    address First;
};


void createList(List &L);
address alokasi(infotype x);
void dealokasi(address &P);
void printInfo(List L);
void insertFirst(List &L, address P);

void deleteFirst(List &L, address &P);
void deleteLast(List &L, address &P);
void deleteAfter(address Prec, address &P);
int nbList(List L);
void deleteList(List &L);

#endif 
```
### Singlylist.cpp
```C++
#include "Singlylist.h"

void createList(List &L) {
    L.First = NULL;
}

address alokasi(infotype x) {
    address P = new ElmList;
    if (P != NULL) {
        P->info = x;
        P->next = NULL;
    }
    return P;
}

void dealokasi(address &P) {
    delete P;
    P = NULL;
}

void printInfo(List L) {
    address P = L.First;
    while (P != NULL) {
        cout << P->info << " ";
        P = P->next;
    }
    cout << endl;
}

void insertFirst(List &L, address P) {
    if (P != NULL) {
        P->next = L.First;
        L.First = P;
    }
}

void deleteFirst(List &L, address &P) {
    if (L.First != NULL) {
        P = L.First;
        L.First = L.First->next;
        P->next = NULL;
    } else {
        P = NULL;
    }
}

void deleteLast(List &L, address &P) {
    if (L.First != NULL) {
        if (L.First->next == NULL) { // Jika hanya ada 1 elemen
            P = L.First;
            L.First = NULL;
        } else {
            address Q = L.First;
            while (Q->next->next != NULL) {
                Q = Q->next;
            }
            P = Q->next;
            Q->next = NULL;
        }
    } else {
        P = NULL;
    }
}

void deleteAfter(address Prec, address &P) {
    if (Prec != NULL && Prec->next != NULL) {
        P = Prec->next;
        Prec->next = P->next;
        P->next = NULL;
    } else {
        P = NULL;
    }
}

int nbList(List L) {
    int count = 0;
    address P = L.First;
    while (P != NULL) {
        count++;
        P = P->next;
    }
    return count;
}

void deleteList(List &L) {
    address P;
    while (L.First != NULL) {
        deleteFirst(L, P);
        dealokasi(P);
    }
}
```
### main1.cpp
```C++
#include <iostream>
#include "Singlylist.h"

using namespace std;

int main() {
    List L;
    address P1, P2, P3, P4, P5;

    createList(L);

    P1 = alokasi(2);
    insertFirst(L, P1);

    P2 = alokasi(0);
    insertFirst(L, P2);

    P3 = alokasi(8);
    insertFirst(L, P3);

    P4 = alokasi(12);
    insertFirst(L, P4);

    P5 = alokasi(9);
    insertFirst(L, P5);

    printInfo(L); 

    return 0;
}
```
### Output Unguided 1 :

##### Output 1
https://github.com/zemmmyy07/LAPRAK-STRUKTUR-DATA/blob/main/WEEK-4/UNGUIDED/Screenshot%202026-10-21%20225649.png


penjelasan unguided 1 :
Program membuat list kosong, lalu menambahkan lima angka menggunakan `insertFirst`. Karena setiap angka dimasukkan di awal, urutan tampilannya menjadi terbalik dari urutan input, yaitu `9 12 8 0 2`.

### 2. Dari soal Latihan pertama, lakukan penghapusan node 9 menggunakan deleteFirst(), node 2 menggunakan deleteLast(), dan node 8 menggunakan deleteAfter(). Kemudian tampilkan jumlah node yang tersimpan menggunakan nbList() dan lakukan penghapusan seluruh node menggunakan deleteList().

```C++
#include <iostream>
#include "Singlylist.h"

using namespace std;

int main() {
    List L;
    address P1, P2, P3, P4, P5;

    createList(L);
    P1 = alokasi(2); insertFirst(L, P1);
    P2 = alokasi(0); insertFirst(L, P2);
    P3 = alokasi(8); insertFirst(L, P3);
    P4 = alokasi(12); insertFirst(L, P4);
    P5 = alokasi(9); insertFirst(L, P5);

    address PDel;

    deleteFirst(L, PDel);
    dealokasi(PDel);

    deleteLast(L, PDel);
    dealokasi(PDel);

    deleteAfter(L.First, PDel);
    dealokasi(PDel);

    printInfo(L);

    cout << "Jumlah node : " << nbList(L) << endl << endl;

    deleteList(L);
    cout << "- List Berhasil Terhapus -" << endl;

    cout << "Jumlah node : " << nbList(L) << endl;

    return 0;
}
```
### Output Unguided 2 :

##### Output 1
https://github.com/zemmmyy07/LAPRAK-STRUKTUR-DATA/blob/main/WEEK-4/UNGUIDED/Screenshot%202026-10-21%20225904.png

penjelasan unguided 2 :
Program membuat list berisi lima angka, lalu menghapus node pertama, node terakhir, dan node setelah node pertama. Sisa list adalah `12 0` dengan 2 node. Setelah itu, `deleteList` menghapus seluruh node sehingga jumlahnya menjadi 0.

## Kesimpulan
Singly linked list menyimpan data dalam node yang terhubung melalui pointer. Node dapat ditambahkan, dihapus, ditampilkan, dan dihitung jumlahnya dengan mengatur pointer secara tepat.

## Referensi
[1] Triase. (2020). Diktat Edisi Revisi : STRUKTUR DATA. Medan: UNIVERSTAS ISLAM NEGERI SUMATERA UTARA MEDAN. 
<br>[2] Indahyati, Uce., Rahmawati Yunianita. (2020). "BUKU AJAR ALGORITMA DAN PEMROGRAMAN DALAM BAHASA C++". Sidoarjo: Umsida Press. Diakses pada 10 Maret 2024 melalui https://doi.org/10.21070/2020/978-623-6833-67-4.
