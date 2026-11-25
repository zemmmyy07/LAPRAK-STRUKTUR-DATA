# <h1 align="center">Laporan Praktikum Modul 8 - QUEUE</h1>
<p align="center">Azzamy Gusalim Herfino - 109082500091</p>

## Dasar Teori
Queue adalah struktur data antrean yang menerapkan prinsip FIFO (First In, First Out), yaitu elemen yang pertama masuk akan diakses/dikeluarkan terlebih dahulu.Terdapat dua operasi utama pada queue, yaitu penyisipan (enqueue / insert) dan pengambilan (dequeue / delete).Queue dapat direpresentasikan menggunakan pointer (linked list) maupun tabel (array).

## Guided 1 

### queue.h
```C++
#ifndef QUEUE_H_INCLUDE
#define QUEUE_H_INCLUDE

#include <iostream>

#define Nil NULL

typedef bool boolean;
typedef int infotype;
typedef struct elmQ *address;

struct elmQ{
   infotype info;
   address next;
};

struct queue {
   address head, tail;
};

boolean isEmpty(queue Q);
void CreateQueue(queue &Q);
address alokasi(infotype X);
void dealokasi(address P);
address findElm(queue Q, infotype X);
boolean fFindElm(queue Q, address P);
void insert(queue &Q, address P);
void deleteQueue(queue &Q, address &P);
void printInfo(queue Q);
int nbList(queue Q);
void delAll(queue &Q);

#endif

```
### queue.cpp
```C++
#include "queue.h"

boolean isEmpty(queue Q) {
    return (Q.head == Nil);
}

void CreateQueue(queue &Q) {
    Q.head = Nil;
    Q.tail = Nil;
}

address alokasi(infotype X) {
    address P = new (std::nothrow) elmQ;
    if (P != Nil) {
        P->info = X;
        P->next = Nil;
    }
    return P;
}

void dealokasi(address P) {
    delete P;
}

address findElm(queue Q, infotype X) {
    address P = Q.head;
    while (P != Nil) {
        if (P->info == X) {
            return P;
        }
        P = P->next;
    }
    return Nil;
}

boolean fFindElm(queue Q, address P) {
    address R = Q.head;
    while (R != Nil) {
        if (R == P) {
            return true;
        }
        R = R->next;
    }
    return false;
}

void insert(queue &Q, address P) { //enqueue
    if (isEmpty(Q)) {
        Q.head = P;
        Q.tail = P;
    } else {
        (Q.tail)->next = P;
        Q.tail = P;
    }
}

void deleteQueue(queue &Q, address &P) { //dequeue
    P = Q.head;
    if (Q.head == Q.tail) {
        Q.head = Nil;
        Q.tail = Nil;
    } else {
        Q.head = P->next;
    }
    P->next = Nil;
}

void printInfo(queue Q) {
    if (isEmpty(Q)) {
        std::cout << "Queue kosong" << std::endl;
    } else {
        address P = Q.head;
        while (P != Nil) {
            std::cout << P->info << " ";
            P = P->next;
        }
        std::cout << std::endl;
    }
}

int nbList(queue Q) {
    int jumlah = 0;
    address P = Q.head;
    while (P != Nil) {
        jumlah++;
        P = P->next;
    }
    return jumlah;
}

void delAll(queue &Q) {
    address P;
    while (!isEmpty(Q)) {
        deleteQueue(Q, P);
        dealokasi(P);
    }
}

```
### main.cpp
```C++
#include <iostream>
#include "queue.h"

int main() {
    queue Q;
    address P; 

    CreateQueue(Q);
    std::cout << "isEmpty : " << isEmpty(Q) << std::endl;
    printInfo(Q);

    insert(Q, alokasi(5));
    insert(Q, alokasi(2));
    insert(Q, alokasi(7));
    std::cout << "Setelah insert 5, 2, 7" << std::endl;
    printInfo(Q);
    std::cout << "nbList  : " << nbList(Q) << std::endl;

    P = findElm(Q, 2);
    if (P != Nil) {
        std::cout << "findElm(2) ketemu, info = " << P->info << std::endl;
        std::cout << "fFindElm : " << fFindElm(Q, P) << std::endl;
    }
    if (findElm(Q, 9) == Nil) {
        std::cout << "findElm(9) tidak ketemu" << std::endl;
    }

    deleteQueue(Q, P);
    std::cout << "Setelah delete, elemen yang keluar = " << P->info << std::endl;
    dealokasi(P);
    printInfo(Q);

    delAll(Q);
    std::cout << "Setelah delAll" << std::endl;
    printInfo(Q);
    std::cout << "isEmpty : " << isEmpty(Q) << std::endl;

    return 0;
}

```
#### Penjelasan Guided 1
Mengimplementasikan queue dengan linked list dan prinsip FIFO. Insert menambah elemen di belakang (tail), sedangkan deleteQueue menghapus elemen terdepan (head). Program menguji penambahan nilai 5, 2, dan 7, pencarian elemen, penghapusan elemen pertama, serta pengosongan queue dengan delAll.

## Guided 2

### queue-array.h
```C++
#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
#include <string>

const int MAKSIMAL = 5;

struct queue {
    std::string nama[MAKSIMAL];
    int head;
    int tail;
};

bool isFull(queue Q);
bool isEmpty(queue Q);
void CreateQueue(queue &Q);
void enQueue(queue &Q, std::string nama);
void deQueue(queue &Q);
void viewQueue(queue Q);

#endif
```
### queue-array.cpp
```C++
#include "queue-array.h"
#include <iostream>

bool isEmpty(queue Q){
    if(Q.head == -1 && Q.tail == -1){
        return true;
    } else {
        return false;
    }
}

bool isFull(queue Q){
    if((Q.tail + 1) % MAKSIMAL == Q.head){
        return true;
    } else {
        return false;
    }
}

void CreateQueue(queue &Q){ //terbentuk queue dengan head = -1 dan tail = -1 
    Q.head = -1;
    Q.tail = -1;
}
void enQueue(queue &Q, std::string nama){
    if(isFull(Q) == true){
        std::cout << "Queue sudah penuh!" << std::endl;
    } else {
        if(isEmpty(Q) == true){
            Q.head = Q.tail = 0;
        } else {
            Q.tail = (Q.tail + 1) % MAKSIMAL; //bergerak melingkar
        }
        Q.nama[Q.tail] = nama;
        std::cout << "nama " << nama << " berhasil ditambahkan kedalam queue!" << std::endl;
    }
}
void deQueue(queue &Q){
    if(isEmpty(Q) == true){
        std::cout << "Queue kosong!" << std::endl;
    } else {
        std::cout << "Mengahapus data " << Q.nama[Q.head] << "..." << std::endl;
        if(Q.head == Q.tail){ //kalo elemennya tinggal 1, langsungkan saja head & tail nya reset ke -1
            Q.head = -1;
            Q.tail = -1;
        } else {
            Q.head = (Q.head + 1) % MAKSIMAL; //bergerak melingkar
        }
    }
}

void viewQueue(queue Q){
    if(isEmpty(Q) == true){
        std::cout << "Queue kosong!" << std::endl;
    } else {
        int i = Q.head;
        int count = 1;
        while(true){
            std::cout << count << ". " << Q.nama[i] << std::endl;
            if(i == Q.tail){
                break;
            }
            i = (i + 1) % MAKSIMAL;
            count++;
        }   
    }
}
```
### main.cpp
```C++
#include "queue-array.h"
#include <iostream>

int main(){
    queue Q;

    CreateQueue(Q);
    enQueue(Q, "Dimas");
    enQueue(Q, "Arvin");
    enQueue(Q, "Rizal");
    enQueue(Q, "Hafizh");
    enQueue(Q, "Fathur");
    enQueue(Q, "Daffa");
    std::cout << std::endl;

    std::cout << "--- Isi Queue Setelah enQueue ---" << std::endl;
    viewQueue(Q);
    std::cout << std::endl;

    deQueue(Q);
    deQueue(Q);
    deQueue(Q);
    deQueue(Q);
    // deQueue(Q);
    // deQueue(Q);
    std::cout << std::endl;

    std::cout << "--- Isi Queue Setelah deQueue ---" << std::endl;
    viewQueue(Q);

    return 0;
}
```
#### Penjelasan Guided 2
Menggunakan queue array melingkar berkapasitas lima elemen. Enqueue menambah data di belakang dan dequeue menghapus data dari depan, dengan indeks bergerak melingkar menggunakan modulo. Saat enam nama ditambahkan, nama keenam ditolak karena queue penuh; setelah empat data dihapus, nama Fathur tersisa.

## Unguided 

### 1. Buatlah ADT Queue menggunakan ARRAY sebagai berikut di dalam file “queue.h”.Buatlah implementasi ADT Queue pada file “queue.cpp” dengan menerapkan mekanisme queue Alternatif 1 (head diam, tail bergerak).

### queue.h
```C++
#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
using namespace std;

typedef int infotype;

struct Queue {
    infotype info[5];
    int head;
    int tail;
};

void createQueue(Queue &Q);
bool isEmptyQueue(Queue Q);
bool isFullQueue(Queue Q);
void enqueue(Queue &Q, infotype x);
infotype dequeue(Queue &Q);
void printInfo(Queue Q);

#endif
```
### queue.cpp
```C++
#include "queue.h"

void createQueue(Queue &Q) {
    Q.head = -1;
    Q.tail = -1;
}

bool isEmptyQueue(Queue Q) {
    return (Q.head == -1 && Q.tail == -1);
}

bool isFullQueue(Queue Q) {
    return (Q.head == 0 && Q.tail == 4);
}

void enqueue(Queue &Q, infotype x) {
    if (isFullQueue(Q)) {
        cout << "Queue penuh!" << endl;
    } else {
        if (isEmptyQueue(Q)) {
            Q.head = 0;
            Q.tail = 0;
            Q.info[0] = x;
        } else {
            Q.tail++;
            Q.info[Q.tail] = x;
        }
    }
}

infotype dequeue(Queue &Q) {
    if (isEmptyQueue(Q)) {
        cout << "Queue kosong!" << endl;
        return -1;
    } else {
        infotype x = Q.info[0];
        for (int i = 0; i < Q.tail; i++) {
            Q.info[i] = Q.info[i + 1];
        }
        Q.tail--;
        if (Q.tail < 0) {
            Q.head = -1;
            Q.tail = -1;
        }
        return x;
    }
}

void printInfo(Queue Q) {
    cout << Q.head << " - " << Q.tail << "  | ";
    if (isEmptyQueue(Q)) {
        cout << "empty queue" << endl;
    } else {
        for (int i = Q.head; i <= Q.tail; i++) {
            cout << Q.info[i];
            if (i < Q.tail) {
                cout << " ";
            }
        }
        cout << endl;
    }
}
```
### main.cpp
```C++
#include <iostream>
#include "queue.h"
using namespace std;

int main() {
    cout << "Hello world!" << endl;
    Queue Q;
    createQueue(Q);

    cout << "-------------------------" << endl;
    cout << " H - T  | Queue info" << endl;
    cout << "-------------------------" << endl;
    printInfo(Q);
    enqueue(Q, 5); printInfo(Q);
    enqueue(Q, 2); printInfo(Q);
    enqueue(Q, 7); printInfo(Q);
    dequeue(Q);    printInfo(Q);
    enqueue(Q, 4); printInfo(Q);
    dequeue(Q);    printInfo(Q);
    dequeue(Q);    printInfo(Q);

    return 0;
}
```
### Output Unguided 1 :

##### Output 1
![Output Unguided 1] 
<img width="1007" height="368" alt="Screenshot 2026-11-25 222407" src="https://github.com/user-attachments/assets/d20c8312-1791-4f4c-92c8-33068bc2315b" />


#### penjelasan unguided 1 
Menggunakan array berkapasitas lima dengan head tetap di awal dan tail bergerak. Saat dequeue, elemen tersisa digeser ke depan agar ruang kosong dapat digunakan kembali. Program memasukkan 5, 2, dan 7, lalu menghapus 5; setelah 4 ditambahkan, dua dequeue berikutnya menyisakan 4.

### 2. Buatlah implementasi ADT Queue pada file “queue.cpp” dengan menerapkan mekanisme queue Alternatif 2 (head bergerak, tail bergerak).

### queue.h
```C++
#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
using namespace std;

typedef int infotype;

struct Queue {
    infotype info[5];
    int head;
    int tail;
};

void createQueue(Queue &Q);
bool isEmptyQueue(Queue Q);
bool isFullQueue(Queue Q);
void enqueue(Queue &Q, infotype x);
infotype dequeue(Queue &Q);
void printInfo(Queue Q);

#endif
```
### queue.cpp
```C++
#include "queue.h"

void createQueue(Queue &Q) {
    Q.head = -1;
    Q.tail = -1;
}

bool isEmptyQueue(Queue Q) {
    return (Q.head == -1 && Q.tail == -1);
}

bool isFullQueue(Queue Q) {
    return (Q.head == 0 && Q.tail == 4);
}

void enqueue(Queue &Q, infotype x) {
    if (isFullQueue(Q)) {
        cout << "Queue penuh!" << endl;
    } else if (isEmptyQueue(Q)) {
        Q.head = 0;
        Q.tail = 0;
        Q.info[Q.tail] = x;
    } else {
        if (Q.tail == 4 && Q.head > 0) {
            int j = 0;
            for (int i = Q.head; i <= Q.tail; i++) {
                Q.info[j] = Q.info[i];
                j++;
            }
            Q.tail = Q.tail - Q.head;
            Q.head = 0;
        }
        Q.tail++;
        Q.info[Q.tail] = x;
    }
}

infotype dequeue(Queue &Q) {
    if (isEmptyQueue(Q)) {
        cout << "Queue kosong!" << endl;
        return -1;
    } else {
        infotype x = Q.info[Q.head];
        if (Q.head == Q.tail) {
            Q.head = -1;
            Q.tail = -1;
        } else {
            Q.head++;
        }
        return x;
    }
}

void printInfo(Queue Q) {
    cout << Q.head << " - " << Q.tail << "  | ";
    if (isEmptyQueue(Q)) {
        cout << "empty queue" << endl;
    } else {
        for (int i = Q.head; i <= Q.tail; i++) {
            cout << Q.info[i];
            if (i < Q.tail) {
                cout << " ";
            }
        }
        cout << endl;
    }
}
```
### main.cpp
```C++
#include <iostream>
#include "queue.h"
using namespace std;

int main() {
    cout << "Hello world!" << endl;
    Queue Q;
    createQueue(Q);

    cout << "-------------------------" << endl;
    cout << " H - T  | Queue info" << endl;
    cout << "-------------------------" << endl;
    printInfo(Q);
    enqueue(Q, 5); printInfo(Q);
    enqueue(Q, 2); printInfo(Q);
    enqueue(Q, 7); printInfo(Q);
    dequeue(Q);    printInfo(Q);
    enqueue(Q, 4); printInfo(Q);
    dequeue(Q);    printInfo(Q);
    dequeue(Q);    printInfo(Q);

    return 0;
}
```
### Output Unguided 2 :

##### Output 1
![Output Unguided 2] 
<img width="1006" height="370" alt="Screenshot 2026-11-25 222612" src="https://github.com/user-attachments/assets/ecc32c8d-40c6-487d-8286-70cec77e1c77" />


#### penjelasan unguided 2
Menggunakan array dengan head dan tail yang bergerak. Dequeue hanya menggeser head; jika tail mencapai batas array dan masih ada ruang di depan, elemen dipindahkan ke awal sebelum enqueue. Pada program, setelah nilai 5, 2, dan 7 dimasukkan, nilai 5, 2, dan 7 dikeluarkan secara berurutan sehingga nilai 4 tersisa.

### 3. Buatlah implementasi ADT Queue pada file “queue.cpp” dengan menerapkan mekanisme queue Alternatif 3 (head dan tail berputar).

### queue.h
```C++
#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
using namespace std;

typedef int infotype;

struct Queue {
    infotype info[5];
    int head;
    int tail;
};

void createQueue(Queue &Q);
bool isEmptyQueue(Queue Q);
bool isFullQueue(Queue Q);
void enqueue(Queue &Q, infotype x);
infotype dequeue(Queue &Q);
void printInfo(Queue Q);

#endif
```
### queue.cpp
```C++
#include "queue.h"

void createQueue(Queue &Q) {
    Q.head = -1;
    Q.tail = -1;
}

bool isEmptyQueue(Queue Q) {
    return (Q.head == -1 && Q.tail == -1);
}

bool isFullQueue(Queue Q) {
    return ((Q.tail + 1) % 5 == Q.head);
}

void enqueue(Queue &Q, infotype x) {
    if (isFullQueue(Q)) {
        cout << "Queue penuh!" << endl;
    } else {
        if (isEmptyQueue(Q)) {
            Q.head = 0;
            Q.tail = 0;
        } else {
            Q.tail = (Q.tail + 1) % 5;
        }
        Q.info[Q.tail] = x;
    }
}

infotype dequeue(Queue &Q) {
    if (isEmptyQueue(Q)) {
        cout << "Queue kosong!" << endl;
        return -1;
    } else {
        infotype x = Q.info[Q.head];
        if (Q.head == Q.tail) {
            Q.head = -1;
            Q.tail = -1;
        } else {
            Q.head = (Q.head + 1) % 5;
        }
        return x;
    }
}

void printInfo(Queue Q) {
    cout << Q.head << " - " << Q.tail << "  | ";
    if (isEmptyQueue(Q)) {
        cout << "empty queue" << endl;
    } else {
        int i = Q.head;
        while (true) {
            cout << Q.info[i];
            if (i == Q.tail) {
                break;
            }
            cout << " ";
            i = (i + 1) % 5;
        }
        cout << endl;
    }
}
```
### main.cpp
```C++
#include <iostream>
#include "queue.h"
using namespace std;

int main() {
    cout << "Hello world!" << endl;
    Queue Q;
    createQueue(Q);

    cout << "-------------------------" << endl;
    cout << " H - T  | Queue info" << endl;
    cout << "-------------------------" << endl;
    printInfo(Q);
    enqueue(Q, 5); printInfo(Q);
    enqueue(Q, 2); printInfo(Q);
    enqueue(Q, 7); printInfo(Q);
    dequeue(Q);    printInfo(Q);
    enqueue(Q, 4); printInfo(Q);
    dequeue(Q);    printInfo(Q);
    dequeue(Q);    printInfo(Q);

    return 0;
}
```
### Output Unguided 3 :

##### Output 1
![Output Unguided 3]
<img width="1007" height="377" alt="Screenshot 2026-11-25 222723" src="https://github.com/user-attachments/assets/0c0311c4-825f-45a7-bfd8-ba3582cbf878" />


#### penjelasan unguided 3
Menggunakan array melingkar berkapasitas lima. Head dan tail bergerak melingkar dengan operasi modulo, sementara queue penuh saat posisi berikutnya dari tail bertemu head. Program memasukkan 5, 2, dan 7, menghapus 5, lalu menambahkan 4; dua penghapusan berikutnya menyisakan 4.

## Kesimpulan
Queue menerapkan prinsip FIFO, yaitu elemen yang pertama masuk akan keluar lebih dahulu. Queue dapat diimplementasikan menggunakan linked list maupun array dengan mekanisme pergeseran atau melingkar.

## Referensi
[1] Triase. (2020). Diktat Edisi Revisi : STRUKTUR DATA. Medan: UNIVERSTAS ISLAM NEGERI SUMATERA UTARA MEDAN. 
<br>[2] Indahyati, Uce., Rahmawati Yunianita. (2020). "BUKU AJAR ALGORITMA DAN PEMROGRAMAN DALAM BAHASA C++". Sidoarjo: Umsida Press. Diakses pada 10 Maret 2024 melalui https://doi.org/10.21070/2020/978-623-6833-67-4.
<br>...
